#include "stdafx.h"
#include "editor.h"
#include "moe.h"
#include "widgets.h"
#include "Docs.h"
#include "moebar.h"
#include "xmlui.h"
#include "ribbonres.h"
#include "ThreadScript.h"
#include "ActivDbg.h"
#include "EditorMenu.h"
#include "EditorScript.h"

using namespace mol::win;
using namespace mol::ole;
using namespace mol::io;

mol::TCHAR OutFilesFilter[]   = _T("all files (*.*)\0*.*\0\0");

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// Editor
//////////////////////////////////////////////////////////////////////////////

Editor::Editor() 
{
	ts_ = 0;
    eraseBackground_ = 1;
	lastWriteTime_.dwHighDateTime = 0;
	lastWriteTime_.dwLowDateTime = 0;
	wndClass().setIcon(moe()->icon); 
	wndClass().hIconSm(moe()->icon); 
	saving_ = false;
}

//////////////////////////////////////////////////////////////////////////////

Editor::~Editor() 
{
	ODBGS("~Editor dead");
};


//////////////////////////////////////////////////////////////////////////////
Editor::Instance* Editor::CreateInstance(const mol::string& file, long enc, bool readOnly)
{
	statusBar()->status(20);

	mol::string p(file);
	if ( mol::Path::exists(p) && mol::Path::isDir(p) )
	{
		logger(LOGINFO) << "path is directory " << mol::tostring(p);
		return 0;
	}

	statusBar()->status(50);

	Instance* e = new Instance;
	e->AddRef();

	if ( !e->initialize(file,enc,readOnly) )
	{
		e->destroy();
		return 0;
	}
	return e;
}

void Editor::prepareInterfaces()
{
	sci = oleObject;
	sci->get_Properties(&props_);
	sci->get_Annotation(&annotation_);
	sci->get_Line(&line_);
	sci->get_Markers(&markers_);
	sci->get_Position(&position_);
	sci->get_Selection(&selection_);
	sci->get_Text(&text_);
}

bool Editor::initialize(const mol::string& p, long enc, bool readOnly)
{
	initializeMoeChild(p);

	//monitor_.events += mol::events::event_handler( &Editor::OnFileChangeNotify, this );

	// init last write timestamp for p
	lastWriteTime_ = getLastWriteTime(p);

	// hook up com event handlers
	events.Advise(oleObject);

	// prepare interface pointers
	prepareInterfaces();

	// get default values from config and init scintilla

	moe()->moeConfig->InitializeEditorFromPreferences( (IMoeDocument*)this );

	// if file exists, load
	if ( mol::Path::exists(p) || (p.substr(0,6) == _T("ssh://") || p.substr(0,10) == _T("moe-ssh://")) )
	{
		if ( enc != -1 )
		{
			if ( S_OK != sci->LoadEncoding(mol::bstr(p),enc) )
			{
				return false;
			}
		}
		else
		{
			if ( S_OK != sci->Load(mol::bstr(p)) )
			{
				return false;
			}
		}
		//timer_.set( 5 * 60 * 1000, boost::bind(&Editor::checkModifiedOnDisk,this) );
	}
	else
	{

		props_->put_Filename(mol::bstr(p));
	}

	statusBar()->status(80);

	//TODO: user config? just while debugging? UI based?
	markers_->put_UseMarkers(VARIANT_TRUE);

	//override read only
	props_->put_ReadOnly( readOnly ? VARIANT_TRUE : VARIANT_FALSE );

	statusBar()->status(100);

	OnLayout(0,0,0);

	return true;
}


//////////////////////////////////////////////////////////////////////////////
//
// OnDestroy - over and out
//
//////////////////////////////////////////////////////////////////////////////

void Editor::OnDestroy()
{
	scriptlet()->close();
	ODBGS("Editor::OnDestroy()");
	
	docs()->remove(this);
	
 	events.UnAdvise(oleObject);

	props_.release();
	position_.release();
	selection_.release();
	line_.release();
	annotation_.release();
	markers_.release();
	text_.release();
	sci.release();
	if ( ts_)
	{
		// as we offer scripting, break any references to out of process clients
		::CoDisconnectObject(((IActiveScriptSite*)(ts_)),0);
		((IActiveScriptSite*)(ts_))->Release();
		ts_ = 0;
	}
	remote_.release();
}

void Editor::OnNcDestroy()
{
	ODBGS("Editor::OnNcDestroy()");
	
	IMoeDocument*e = (IMoeDocument*)this;
	::CoDisconnectObject(((IMoeDocument*)this),0);
	((IMoeDocument*)this)->Release();
	
}

//////////////////////////////////////////////////////////////////////////////

void Editor::OnMDIActivate(WPARAM unused, HWND activated)
{
	ODBGS("Editor::OnMDIActivate");

	if ( activated == hWnd_ )
	{
		mol::bstr path;
		props_->get_Filename(&path);

		tab()->select( *this );
		updateUI();
		sci->SetFocus();

		checkModifiedOnDisk();
	}
}




//////////////////////////////////////////////////////////////////////////////


LRESULT Editor::OnClose()
{
	if (saving_ )
		return 1;

	if ( ts_ )
		return 1;

	VARIANT_BOOL vb;
	text_->get_Modified(&vb);

	if ( vb == VARIANT_TRUE )
	{
		mol::bstr p;
		props_->get_Filename(&p);
		mol::ostringstream oss;
		oss << p.toString() << _T("\r\nis modified! ");
		LRESULT r = mol::v7::msgbox( *moe(), _T("close without save?"), _T("document modified!"),oss.str().c_str(), IDI_MOE );
		if ( r != IDYES )
		{
			return 1;
		}
	}

	this->destroy();
	return 0;
}

void Editor::OnCliReturn()
{

}

void Editor::OnCut()
{
	if ( !sci )
		return;

	selection_->Cut();
}

void Editor::OnCopy()
{
	if ( !sci )
		return;

	selection_->Copy();
}

void Editor::OnPaste()
{
	if ( !sci )
		return;

	selection_->Paste();
}


void Editor::OnPasteAs()
{
	if ( !sci )
		return;

	PasteAs pasteAs;

	std::wstring data = pasteAs.get();

	if ( data.empty() )
	{
		return OnPaste();
	}

	selection_->put_Text( mol::bstr(data) );
}

void Editor::OnConvertTabs()
{
	if ( !sci )
		return;

	props_->ConvertTabs();
}

void Editor::OnEncoding()
{
	if ( !sci )
		return;

	// get chosen encoding index
	int enc = mol::Ribbon::handler(RibbonEncoding)->index();
	props_->put_Encoding( moe()->codePages()[enc].first );
}


void Editor::OnLanguage()
{
	// get chosen lexer id
	int lexer = mol::Ribbon::handler(RibbonSelectLanguage)->index();

	// convert to menu message
	postMessage(WM_COMMAND,IDM_LEXER_PLAIN + lexer,0);
}

void Editor::OnTabUsage()
{
	if ( !sci )
		return;

	VARIANT_BOOL vb = mol::Ribbon::handler(RibbonTabUseTabs)->checked() ? VARIANT_TRUE: VARIANT_FALSE;
	props_->put_TabUsage(vb);
}

void Editor::OnTabWidth()
{
	if ( !sci )
		return;

	mol::variant v = mol::Ribbon::handler(RibbonTabSize)->decimal();

	DECIMAL d = v.decVal;
	long w = d.Lo32;
	props_->put_TabWidth(w);

}

void Editor::OnTabIndents()
{
	if ( !sci )
		return;

	VARIANT_BOOL vb = mol::Ribbon::handler(RibbonTabIndents)->checked() ? VARIANT_TRUE: VARIANT_FALSE;
	props_->put_TabIndents(vb);
}

void Editor::OnBackspaceUnindents()
{
	if ( !sci )
		return;

	VARIANT_BOOL vb = mol::Ribbon::handler(RibbonTabBackSpaceUnIndents)->checked() ? VARIANT_TRUE: VARIANT_FALSE;
	props_->put_BackSpaceUnindents(vb);

}

void Editor::OnWriteBOM()
{
	if ( !sci )
		return;

	VARIANT_BOOL vb = mol::Ribbon::handler(RibbonWriteBOM)->checked() ? VARIANT_TRUE: VARIANT_FALSE;
	props_->put_WriteBOM(vb);
}

 
//////////////////////////////////////////////////////////////////////////////
void Editor::OnSelectAll()
{
	if ( !sci )
		return;

	long len = 0;
	text_->get_Length(&len);

	selection_->SetSelection(0,len);
}

void Editor::OnUserCommand(int code, int id, HWND ctrl)
{
	if ( !sci )
		return;

	ISetting* set = shortCutMap[id];
    if ( !set ) 
		return ;

	long sel;
	if ( S_OK != selection_->get_Start(&sel) )
		return ;

	mol::bstr val;
	if ( S_OK != set->get_Value(&val) || val.bstr_ == 0)
		return ;

	std::string tmp = mol::BSTR2ansi(val);
	size_t pos = tmp.find("<!-- moleCursor -->");
	if ( pos != std::string::npos )
	{
		tmp = tmp.substr(0,pos)+tmp.substr(pos+19);
	}
						
	if ( S_OK != text_->Insert(mol::bstr(tmp),sel) )
		return ;

	if ( pos != std::string::npos )
	{
		selection_->SetSelection( (long)(sel+pos), (long)(sel+pos));
	}
}

void Editor::OnUserBatch(int code, int id, HWND ctrl)
{
	mol::punk<ISetting> set = batchMap[id];

    mol::bstr val;
	if ( S_OK != set->get_Value(&val) || !val.bstr_ )
		return;

	mol::string cmd = val.toString();
	if ( cmd.empty() )
		return;

	if ( cmd.find(_T("!")) == 0 )
	{
		cmd = cmd.substr(1);
		if ( mol::OS::has_uac() )
		{
			size_t p = cmd.find(_T("|"));
			mol::string args;
			if ( p != mol::string::npos )
			{
				if ( p < cmd.size() )
					args = cmd.substr(p+1);
				cmd = cmd.substr(0,p);			
			}
			execute_shell_admin( cmd, args );
			return;
		}
	}

	size_t p = cmd.find(_T("|"));
	mol::string args;
	if ( p != mol::string::npos )
	{
		if ( p < cmd.size() )
			args = cmd.substr(p+1);
		cmd = cmd.substr(0,p);	
		execute_shell_args(cmd,args);
	}
	exec_cmdline( cmd );
	return ;
}


void Editor::OnUserForm(int code, int id, HWND ctrl)
{
	mol::punk<ISetting> set = formMap[id];

    mol::bstr val;
	if ( S_OK != set->get_Value(&val) || !val.bstr_ )
		return ;

	mol::string path = val.toString();
	mol::string file = path;
	RECT r;
	moe()->getWindowRect(r);

	int l = r.left+50;
	int t = r.top+50;
	int w = r.right-r.left-100;
	int h = r.bottom-r.top-100;
	int o = 2;

	std::vector<mol::string> v = mol::split(path,_T(","));

	switch ( v.size() )
	{
		case 6 : o = atoi(mol::tostring(v[5]).c_str());
		case 5 : h = atoi(mol::tostring(v[4]).c_str());
		case 4 : w = atoi(mol::tostring(v[3]).c_str());
		case 3 : t = t + atoi(mol::tostring(v[2]).c_str());			
		case 2 : l = l + atoi(mol::tostring(v[1]).c_str());
		case 1 : file = v[0];
		default : ;
	}

	if ( mol::Path::ext(file) == _T(".ufs") ) 
	{
		moe()->moeScript->ShowUserForm( mol::bstr(file),0);
		return;
	}

	moe()->moeScript->ShowHtmlForm( mol::bstr(file), l, t, w, h, o );
}


void Editor::OnUserScript(int code, int id, HWND ctrl)
{
	mol::punk<ISetting> set = scriptMap[id];

    mol::bstr val;
	if ( S_OK != set->get_Value(&val) || !val.bstr_ )
		return ;

	mol::string file = _T("");
	mol::string func = _T("");

	mol::string tmp = mol::toString(val);
	size_t pos = tmp.find(_T("!"));
	if ( pos != std::string::npos)
	{
		file   = tmp.substr(0,pos);
		func   = tmp.substr(pos+1);
	}
	else
		file = tmp;

	file = findFile(file);

	if ( file == _T("") )
		return ;

	mol::string ext = mol::Path::ext(file);
	if ( mol::icmp(ext, _T(".bat") ) == 0 )
	{
		execute_shell( file );
		return ;
	}
	mol::string engine = engineFromPath(mol::tostring(file));

	mol::filestream fs;
	fs.open(mol::tostring(file), GENERIC_READ);
	if ( !fs )
		return ;

	std::string script = fs.readAll();
	fs.close();

	ScriptingHost scriptlet_ = new Script;
	scriptlet_->call( mol::toString(engine),func,mol::toString(script));

}

void Editor::OnBeautify()
{
	if ( !sci )
		return;

	long type;
	if ( S_OK != props_->get_Syntax(&type) || type != SCINTILLA_SYNTAX_HTML )
		return ;

	mol::bstr b;
	if ( S_OK != text_->GetText(&b) || b.bstr_ == 0 )
		return ;

	mol::HtmlDocument doc;
	doc.parse(b.tostring());
	mol::Element* e = (mol::Element*)(doc.documentElement());
	if ( !e )
		return ;

	std::ostringstream os;
	int len = e->childNodes()->length();
	for ( int i = 0; i < len; i++ )
	{
		mol::Node* n = e->childNodes()->item(i);
		PrettyNode pn( (mol::Element*)n );
		pn.toString(os,"");
		os << "\r\n";
	}

	text_->SetText(mol::bstr(os.str()));
}

void Editor::OnSearch(FINDREPLACE* find)
{
	if ( !sci )
		return;

    if ( (find->Flags) & FR_FINDNEXT )
    {
		std::string what( mol::tostring(find->lpstrFindWhat));
		std::string utf8what(mol::toUTF8(what));

		VARIANT_BOOL vb;
		text_->Search(mol::bstr(utf8what),find->Flags,&vb);
		if ( VARIANT_FALSE == vb )
		{
			statusBar()->status(_T("Search: end of doc"));
		}
    }
    if ( (find->Flags) & FR_REPLACE )
    {
		std::string what (mol::tostring(find->lpstrFindWhat));
		std::string with(mol::tostring(find->lpstrReplaceWith));
		std::string utf8what(mol::toUTF8(what));
		std::string utf8with(mol::toUTF8(with));

		VARIANT_BOOL vb;
		text_->Replace(mol::bstr(utf8what),mol::bstr(utf8with),find->Flags,&vb);
		if ( VARIANT_FALSE == vb )
		{
			statusBar()->status(_T("Replace: end of doc"));
		}
    }
    if ( (find->Flags) & FR_REPLACEALL )
    {
		std::string what (mol::tostring(find->lpstrFindWhat));
		std::string with(mol::tostring(find->lpstrReplaceWith));
		std::string utf8what(mol::toUTF8(what));
		std::string utf8with(mol::toUTF8(with));

        int c = 0;

		VARIANT_BOOL vb = VARIANT_TRUE;
		while ( vb == VARIANT_TRUE )
		{
			text_->Replace(mol::bstr(utf8what),mol::bstr(utf8with),find->Flags,&vb);
				
			if ( VARIANT_FALSE == vb )
			{
				mol::ostringstream oss;
				oss << _T("Replace All: ") << c << _T(" replaces");
				statusBar()->status(oss.str());
			}
			c++;
		}
    }
}

//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////


void Editor::OnUnix()
{
	props_->put_SysType(SCINTILLA_SYSTYPE_UNIX);
}


void Editor::OnWin32()
{
	props_->put_SysType(SCINTILLA_SYSTYPE_WIN32);
	statusBar()->status( _T("set EOL type to WIN32 (\\r\\n)"));
}

void Editor::OnSettings()
{
	mol::punk<IUnknown> unk(oleObject);
	if ( !unk )
		return;
	
	CAUUID pages;
	mol::punk<ISpecifyPropertyPages> spp(unk);
	if (!spp)
		return;

	if ( S_OK != spp->GetPages(&pages) )
		return;

	mol::bstr filename;
	if ( S_OK == props_->get_Filename(&filename) )
	{
		LPUNKNOWN unks[2] = { (IUnknown*)unk, (IUnknown*)unk };
		mol::string p(filename.toString());
		::OleCreatePropertyFrame( *this, 10, 10,
								  mol::towstring(mol::Path::filename(p)).c_str(),
								  1, unks, pages.cElems,
								  pages.pElems, 0, 0, 0 );

		::CoTaskMemFree(pages.pElems);
	}
	
}

void Editor::OnInsertColorDialog()
{
	sci->InsertColorDialog();
}


////////////////////////////////////////////////////////////////////////////// 


void Editor::OnLexer(int code, int id, HWND ctrl)
{
	if ( !sci )
		return;

	int syntax = id;

	if ( syntax < IDM_LEXER_PLAIN || syntax > IDM_LEXER_CSHARP )
		return ;

	syntax -= IDM_LEXER_PLAIN;

	props_->put_Syntax(syntax);

	mol::bstr displayname;
	if ( S_OK == props_->GetSyntaxDisplayName(syntax,&displayname) )
	{
		statusBar()->status(displayname.toString());
	}

}


//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////


void Editor::OnReload()
{
	if ( !sci )
		return;

	VARIANT_BOOL vb;
	if ( S_OK != text_->get_Modified(&vb) )
		return ;

	if ( vb == VARIANT_TRUE )
	{
		mol::bstr path;
		props_->get_Filename(&path);
		LRESULT r = mol::v7::msgbox(*moe(), _T("you have unsaved changes."), _T("document modified!"),_T("discard all changes and proceed."),IDI_MOE );
		if ( r != IDYES )
			return ;
	}
	mol::bstr filename;
	if ( S_OK != get_FilePath(&filename) )
	{
		return ;
	}

	if ( S_OK != props_->get_ReadOnly(&vb) )
	{
		return ;
	}
	long t;
	if ( S_OK != props_->get_Encoding(&t) )
	{
		return ;
	}

	if ( mol::toString(filename).substr(0,6) == _T("ssh://") || mol::toString(filename).substr(0,6) == _T("moe-ssh://") )
	{
		sci->LoadEncoding(filename,CP_UTF8);
		props_->put_ReadOnly(vb);
		statusBar()->status(filename.toString());
		scrollDown();
		return ;
	}

	lastWriteTime_ = getLastWriteTime(filename.toString());

	if ( t == SCINTILLA_ENCODING_UTF8 )
	{

		sci->LoadEncoding(filename,CP_UTF8);
		props_->put_ReadOnly(vb);
		statusBar()->status(filename.toString());
		scrollDown();
		return ;
	}
	sci->Load(filename);
	props_->put_ReadOnly(vb);
	statusBar()->status(filename.toString());
	scrollDown();
}



//////////////////////////////////////////////////////////////////////////////

void Editor::OnSaveAs()
{
	if ( !sci )
		return;

	long enc;
	mol::bstr p;

	if ( S_OK != props_->get_Encoding(&enc) )
	{
		return;
	}

	if ( S_OK != props_->get_Filename(&p) )
	{
		return;
	}

	if ( mol::Ribbon::ribbon()->enabled() )
	{
		const mol::v7::COMDLG_FILTERSPEC c_rgSaveTypes[] =
		{
			{ L"all files (*.*)",       L"*.*"}
		};

		MoeVistaFileDialog fd(*moe());
		fd.setFilter((mol::v7::COMDLG_FILTERSPEC*)&c_rgSaveTypes,ARRAYSIZE(c_rgSaveTypes));
		fd.encoding( enc );
		fd.path(mol::towstring(p));
		HRESULT hr = fd.save(mol::v7::FOS_NOVALIDATE);
		if ( hr != S_OK )
			return;

		enc = fd.encoding();
		props_->put_Encoding(enc);

		mol::ostringstream oss;
		if ( S_OK == sci->SaveAs( mol::bstr(fd.path() ) ) )
		{
			lastWriteTime_ = getLastWriteTime( fd.path() );
			docs()->rename( this, fd.path() );
			props_->put_Filename(mol::bstr(fd.path()));

			oss << _T("file saved as ") << fd.path() << _T(" saved");
		}
		else
		{
			oss << _T("failed to saved file ") << fd.path() ;
		}
		statusBar()->status(oss.str());
		return;
	}

	//mol::FilenameDlg ofn(*this);
	MolFileFialog ofn(*this);

	ofn.setFilter( OutFilesFilter );		
	ofn.index(0);
	ofn.codePage(enc);
	ofn.fileName(p.toString());

	if ( ofn.dlgSave( OFN_OVERWRITEPROMPT| OFN_NOTESTFILECREATE| OFN_NOVALIDATE |OFN_EXPLORER | OFN_ENABLEHOOK | OFN_ENABLETEMPLATE ) )
	{	
		if ( enc != ofn.index()-1 )
			props_->put_Encoding(ofn.index()-1);
		if (sci)
		{
			mol::ostringstream oss;

			if ( S_OK == sci->SaveAs( mol::bstr(ofn.fileName() ) ) )
			{
				lastWriteTime_ = getLastWriteTime( ofn.fileName() );
				docs()->rename( this, ofn.fileName() );
				props_->put_Filename(mol::bstr(ofn.fileName()));

				oss << _T("file saved as ") << ofn.fileName() << _T(" saved");
			}
			else
			{
				oss << _T("failed to saved file ") << ofn.fileName() ;
			}
			statusBar()->status(oss.str());
		}
	}
}

//////////////////////////////////////////////////////////////////////////////

void Editor::OnSave()
{
	if ( !sci )
		return;

	mol::bstr filename;
	props_->get_Filename(&filename);

	mol::string path = mol::toString(filename);

	saving_ = true;
	mol::ostringstream oss;

	HRESULT hr = sci->Save();
	if ( hr == S_OK )
	{
		lastWriteTime_ = getLastWriteTime( path );
		oss << _T("saved file ") << path ;
	}
	else
	{
		oss << _T("failed to saved file ") << path ;
	}

	statusBar()->status(oss.str());

	saving_ = false;
}


void Editor::OnShowLineNumbers()
{
	if ( !sci )
		return;	

	VARIANT_BOOL vb;
	if ( S_OK != props_->get_ShowLineNumbers(&vb) )
		return;

	vb = vb == VARIANT_FALSE ? VARIANT_TRUE : VARIANT_FALSE;
	props_->put_ShowLineNumbers(vb);

	mol::Menu mode(mol::UI().SubMenu(IDM_MOE,IDM_MODE));

	if ( vb == VARIANT_TRUE )
		mode.checkItem( IDM_MODE_SHOW_LINE_NUMBERS );
	else
		mode.unCheckItem( IDM_MODE_SHOW_LINE_NUMBERS );
}


void Editor::OnMenu(HMENU popup, LPARAM unused)
{
	EditorMenu em(this);
	em.onMenu(popup,unused);
}

LRESULT Editor::OnToolbarDropDown(NMTOOLBAR* toolbar)
{
	mol::Menu m(mol::UI().Menu(IDM_MOE),false);

	EditorMenu em(this);
	
	int index = toolbar->iItem;
	if ( index == IDM_MODE_EOL )
		em.createMenuFromConf(m,mol::UI().SubMenu(IDM_MOE,IDM_MODE_EOL));
	else 
		em.createMenuFromConf(m,mol::UI().SubMenu(IDM_MOE,IDM_TOOLS));

	mol::Menu context( mol::UI().SubMenu(IDM_MOE,index) );
	showContext(context);

	updateUI();
	return TBDDRET_DEFAULT;
}

void Editor::OnExecScript()
{
	EditorScript es(this);
	es.execScript();
}

void Editor::OnExecForm()
{
	EditorScript es(this);
	es.execForm();
}


void Editor::OnDebugScriptGo()
{
	EditorScript es(this);
	es.debugScriptGo();
}


void Editor::OnDebugScriptStepIn()
{
	EditorScript es(this);
	es.debugScriptStepIn();
}

void Editor::OnDebugScriptStepOver()
{
	EditorScript es(this);
	es.debugScriptStepOver();
}

void Editor::OnDebugScriptStepOut()
{
	EditorScript es(this);
	es.debugScriptStepOut();
}

void Editor::OnDebugScriptStop()
{
	EditorScript es(this);
	es.debugScriptStop();
}

void Editor::OnDebugScriptQuit()
{
	EditorScript es(this);
	es.debugScriptQuit();
}

void Editor::OnScriptThreadDone()
{
	if ( mol::guithread() != mol::Thread::self() )
	{
		mol::invoke( boost::bind( &Editor::OnScriptThreadDone, this) );		
		return;
	}

	EditorScript es(this);
	es.scriptThreadDone();
}

void Editor::OnScriptThread( int line, IRemoteDebugApplicationThread* remote, IActiveScriptError* pError )
{
	if ( mol::guithread() != mol::Thread::self() )
	{
		EditorScript es(this);
		es.scriptThread(line,remote,pError);
		return;
	}

	EditorScript es(this);
	es.scriptThread2(line,remote,pError);
}



//////////////////////////////////////////////////////////////////////////////
//
// helpers
//
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall Editor::get_FilePath( BSTR *fname)
{
	if ( fname  )
	{
		*fname = 0;
		mol::bstr path;
		props_->get_Filename(&path);
		*fname = ::SysAllocString(path.bstr_);
	}
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall  Editor::Sintilla_Events::OnFileNameChanged( BSTR filename, BSTR path)
{
	This()->updateUI();
	return S_OK;
}

HRESULT __stdcall  Editor::Sintilla_Events::OnShowMenu( VARIANT_BOOL* showMenue)
{
	if ( mol::Ribbon::ribbon()->enabled() )
	{
		*showMenue = VARIANT_FALSE;
		POINT p;
		::GetCursorPos(&p);
		mol::Ribbon::ribbon()->showContextualUI( RibbonDocumentContextMap, p.x, p.y);
	}
	return S_OK;
}

HRESULT __stdcall  Editor::Sintilla_Events::OnPosChange( long line )
{
	if ( !This()->sci )
		return S_OK;

	mol::ostringstream oss;
	oss << (line+1);

	long pos = 0;
	long linepos = 0;
	This()->position_->get_Caret(&pos);
	This()->line_->PosFromLine(line,&linepos);

	long col = pos-linepos;
	mol::ostringstream oss2;
	oss2 << col << " "; 

	mol::bstr path;
	This()->props_->get_Filename(&path);

	mol::string dirty(_T(""));
	VARIANT_BOOL vb = VARIANT_FALSE;
	HRESULT hr = This()->text_->get_Modified(&vb);
	if ( vb == VARIANT_TRUE )
	{
		dirty = _T("modified");
	}
	else
	{
		dirty = _T("not modified");
	}

	statusBar()->setText( path.toString(), dirty, oss.str(), oss2.str());
	return S_OK;
}

HRESULT __stdcall  Editor::Sintilla_Events::OnChar( BSTR ch )
{
	return S_OK;
}

HRESULT __stdcall Editor::Sintilla_Events::OnSyntax( long s)						
{ 
	This()->updateUI();
	return S_OK; 
}

HRESULT __stdcall Editor::Sintilla_Events::OnSystem( long s)						
{ 
	This()->updateUI();
	return S_OK; 
}

HRESULT __stdcall Editor::Sintilla_Events::OnEncoding( long e)						
{ 
	This()->updateUI();
	return S_OK; 
}


HRESULT __stdcall Editor::Sintilla_Events::OnMarker( long line)						
{ 
	if ( !This()->sci )
		return S_OK;

	This()->markers_->ToggleMarker(line);

	if ( This()->ts_ )
	{

		mol::SafeArray<VT_I4> sf;

		std::set<int> s;
		if ( S_OK == This()->markers_->GetMarkers(&sf) )
		{
			mol::SFAccess<long> sfa(sf);

			for ( int i = 0; i < sfa.size(); i++ )
			{
				s.insert(sfa[i]);
			}
		}
		This()->ts_->update_breakpoints(s);
	}
	return S_OK; 
}


//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

void Editor::updateUI()
{
	EditorMenu em(this);
	em.updateUI();

}


void Editor::scrollDown()
{
	LONG len = 0;
	text_->get_Length(&len);

	position_->put_Anchor((long)len);
	position_->put_Caret((long)len);
	position_->ScrollIntoView();
}


void Editor::checkModifiedOnDisk()
{
	if ( saving_)
		return;

	mol::bstr path;
	if(!props_)
		return;

	props_->get_Filename(&path);

	if ( moe()->getActive() != (HWND)*this || saving_ )
	{
		return;
	}

	FILETIME ft = getLastWriteTime( path.toString() );


	if ( (ft.dwHighDateTime != lastWriteTime_.dwHighDateTime) || (ft.dwLowDateTime != lastWriteTime_.dwLowDateTime) )
	{
		lastWriteTime_ = ft;
		if ( IDYES == mol::v7::msgbox( *moe(),_T("reload file?"),_T("file is modified!"),_T("file has been modified on disk, reload?"),IDI_MOE) )
		{
			OnReload();
		}
	}
}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// pretty node helper for formatting HTML
//////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////
//
// Construdction /destruction
//
///////////////////////////////////////////////////////////////////////

PrettyNode::PrettyNode ( mol::Element* n )
: node_(n)
{}

///////////////////////////////////////////////////////////////////////
//
// tree to string (formatted)
//
///////////////////////////////////////////////////////////////////////

std::string PrettyNode::nl2indent( const std::string& input, const std::string& indention )
{
	std::string in = input;
    std::ostringstream out;
    size_t len = in.size();
    size_t p   = 0;
    while( ( p < len ) )
    {
        if ( in[p] == '\n' )
        {
            out << "\n";
			out << indention ;
        }
        else
        {
            out << in[p];
        }
        p++;
    }
    return out.str();
}

void PrettyNode::toString( std::ostringstream& str, std::string indent)
{
	if ( (node_->nodeType() ==mol::Node::COMMENT)  )
	{		
		std::string tmp = mol::trim(node_->nodeValue()); 
		str << tmp;
		return;
	}
	if ( node_->nodeType() == mol::Node::TEXT  )
	{		
		std::string tmp = mol::trim(node_->nodeValue()); 
		str << indent << nl2indent(tmp,indent);
		return;
	}
	str << indent << "<";

	std::string tmp = node_->nodeName();
	unsigned int p = 0;
	str << nl2indent(tmp,indent);

	if ( node_->attributes()->length() > 0 )
		str << "" << node_->atts();
	str << ">";
	int len = node_->childNodes()->length();
	for ( int i = 0; i < len; i++ )
	{
		str << "\r\n";
		PrettyNode n((mol::Element*)node_->childNodes()->item(i));
		n.toString( str, indent+" ");
	}
	if ( !node_->isAlone() )
		str << "\r\n" << indent << "</" << node_->nodeName() << ">";
}

