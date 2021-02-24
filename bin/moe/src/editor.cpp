#include "stdafx.h"
#include "editor.h"
#include "moe.h"
#include "widgets.h"
#include "Docs.h"
#include "moebar.h"

#include "ThreadScript.h"
#include "EditorMenu.h"
#include "EditorScript.h"

using namespace mol::win;
using namespace mol::ole;
using namespace mol::io;

wchar_t OutFilesFilter[]   = _T("all files (*.*)\0*.*\0\0");

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// Editor
//////////////////////////////////////////////////////////////////////////////

Editor::Editor() 
{
	debugger_ = 0;
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
Editor::Instance* Editor::CreateInstance(const std::wstring& file, long enc, bool readOnly)
{
	statusBar()->status(20);

	std::wstring p(file);
	if ( mol::Path::exists(p) && mol::Path::isDir(p) )
	{
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

bool Editor::initialize(const std::wstring& p, long enc, bool readOnly)
{
	initializeMoeChild(p);

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
		if ( enc == -1 )
			enc = 0;

		if ( S_OK != sci->LoadAsync(mol::bstr(p),enc) )
		{
			return false;
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

handle_msg(&Editor::OnDestroy,WM_DESTROY)
void Editor::OnDestroy()
{
	ODBGS("Editor::OnDestroy()");

	if (this->onCloseHandler)
	{
		EXCEPINFO ex;
		::ZeroMemory(&ex, sizeof(EXCEPINFO));
		UINT e = 0;
		DISPPARAMS p = { 0,0 };
		this->onCloseHandler->Invoke(DISPID_VALUE, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_METHOD, &p, NULL, &ex, &e);
	}
	
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
	if ( debugger_)
	{
		debugger_->moeImport->Quit();
		debugger_ = 0;
	}
}

handle_msg(&Editor::OnNcDestroy, WM_NCDESTROY)
void Editor::OnNcDestroy()
{
	ODBGS("Editor::OnNcDestroy()");

	thumb.destroy();
	
	IMoeDocument*e = (IMoeDocument*)this;
	::CoDisconnectObject(((IMoeDocument*)this),0);
	((IMoeDocument*)this)->Release();
	
}

//////////////////////////////////////////////////////////////////////////////

handle_msg(&Editor::OnMDIActivate, WM_MDIACTIVATE)
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
		ribbon()->setAppMode("Scintilla");
	}
}




//////////////////////////////////////////////////////////////////////////////

handle_msg(&Editor::OnClose, WM_CLOSE)
LRESULT Editor::OnClose()
{
	if (saving_ )
		return 1;

	VARIANT_BOOL vb;
	text_->get_Modified(&vb);

	if ( vb == VARIANT_TRUE )
	{
		mol::bstr p;
		props_->get_Filename(&p);
		std::wostringstream oss;
		oss << p.towstring() << _T("\r\nis modified! ");
		LRESULT r = mol::v7::msgbox( *moe(), _T("close without save?"), _T("document modified!"),oss.str().c_str(), IDI_MOE );
		if ( r != IDYES )
		{
			return 1;
		}
	}

	this->destroy();
	return 0;
}

handle_cmd(&Editor::OnCliReturn, IDM_CLI_RETURN)
void Editor::OnCliReturn()
{

}

handle_cmd(&Editor::OnCut, IDM_EDIT_CUT)
void Editor::OnCut()
{
	if ( !sci )
		return;

	selection_->Cut();
}

handle_cmd(&Editor::OnCopy, IDM_EDIT_COPY)
void Editor::OnCopy()
{
	if ( !sci )
		return;

	selection_->Copy();
}

handle_cmd(&Editor::OnPaste, IDM_EDIT_PASTE)
void Editor::OnPaste()
{
	if ( !sci )
		return;

	selection_->Paste();
}

handle_cmd(&Editor::OnPasteAs, IDM_EDIT_PASTEAS)
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

handle_cmd(&Editor::OnConvertTabs, IDM_RIBBON_TABCONVERT)
void Editor::OnConvertTabs()
{
	if ( !sci )
		return;

	props_->ConvertTabs();
}


 
//////////////////////////////////////////////////////////////////////////////

handle_cmd(&Editor::OnSelectAll, IDM_EDIT_SELECT)
void Editor::OnSelectAll()
{
	if ( !sci )
		return;

	long len = 0;
	text_->get_Length(&len);

	selection_->SetSelection(0,len);
}

handle_cmd_range(&Editor::OnUserCommand, ID_FIRST_USER_CMD, ID_LAST_USER_CMD)
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

handle_cmd_range(&Editor::OnUserBatch, ID_FIRST_USER_BATCH, ID_LAST_USER_BATCH)
void Editor::OnUserBatch(int code, int id, HWND ctrl)
{
	mol::punk<ISetting> set = batchMap[id];

    mol::bstr val;
	if ( S_OK != set->get_Value(&val) || !val.bstr_ )
		return;

	std::wstring cmd = val.towstring();
	if ( cmd.empty() )
		return;

	if ( cmd.find(_T("!")) == 0 )
	{
		cmd = cmd.substr(1);
		if ( mol::OS::has_uac() )
		{
			size_t p = cmd.find(_T("|"));
			std::wstring args;
			if ( p != std::wstring::npos )
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
	std::wstring args;
	if ( p != std::wstring::npos )
	{
		if ( p < cmd.size() )
			args = cmd.substr(p+1);
		cmd = cmd.substr(0,p);	
	}
	execute_shell_args(cmd, args);
//	exec_cmdline( cmd );
	return ;
}

handle_cmd_range(&Editor::OnUserForm, ID_FIRST_USER_FORM, ID_LAST_USER_FORM)
void Editor::OnUserForm(int code, int id, HWND ctrl)
{
	mol::punk<ISetting> set = formMap[id];

    mol::bstr val;
	if ( S_OK != set->get_Value(&val) || !val.bstr_ )
		return ;

	std::wstring path = val.towstring();
	std::wstring file = path;
	RECT r;
	moe()->getWindowRect(r);

	int l = r.left+50;
	int t = r.top+50;
	int w = r.right-r.left-100;
	int h = r.bottom-r.top-100;
	int o = 2;

	std::vector<std::wstring> v = mol::split(path,_T(","));

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
	/*
	if ( mol::Path::ext(file) == _T(".ufs") ) 
	{
		moe()->moeScript->ShowUserForm( mol::bstr(file),0);
		return;
	}
	*/
	moe()->moeScript->ShowHtmlForm( mol::bstr(file), l, t, w, h, o );
}

handle_cmd_range(&Editor::OnUserScript, ID_FIRST_USER_SCRIPT, ID_LAST_USER_SCRIPT)
void Editor::OnUserScript(int code, int id, HWND ctrl)
{
	mol::punk<ISetting> set = scriptMap[id];

    mol::bstr val;
	if ( S_OK != set->get_Value(&val) || !val.bstr_ )
		return ;

	std::wstring file = _T("");
	std::wstring func = _T("");

	std::wstring tmp = mol::towstring(val);
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

	std::wstring ext = mol::Path::ext(file);
	if ( mol::icmp(ext, _T(".bat") ) == 0 )
	{
		execute_shell( file );
		return ;
	}
	std::wstring engine = engineFromPath(mol::tostring(file));

	mol::filestream fs;
	fs.open(mol::tostring(file), GENERIC_READ);
	if ( !fs )
		return ;

	std::string script = fs.readAll();
	fs.close();

	Script::CreateInstance()->call(mol::towstring(engine), func, mol::towstring(script));

}

handle_cmd(&Editor::OnBeautify, IDM_EDIT_INDENTION)
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


handle_msg(&Editor::OnSearch, WM_SEARCH_MSG)
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
				std::wostringstream oss;
				oss << _T("Replace All: ") << c << _T(" replaces");
				statusBar()->status(oss.str());
			}
			c++;
		}
    }
}

//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////

handle_cmd(&Editor::OnUnix, IDM_MODE_UNIX)
void Editor::OnUnix()
{
	props_->put_SysType(SCINTILLA_SYSTYPE_UNIX);
}


handle_cmd(&Editor::OnWin32, IDM_MODE_WIN32)
void Editor::OnWin32()
{
	props_->put_SysType(SCINTILLA_SYSTYPE_WIN32);
	statusBar()->status( _T("set EOL type to WIN32 (\\r\\n)"));
}


handle_cmd(&Editor::OnSettings, IDM_MODE_SETTINGS)
void Editor::OnSettings()
{
	mol::punk<IUnknown> unk(oleObject);
	if ( !unk )
		return;
	
	mol::punk<ISpecifyPropertyPages> spp(unk);
	if (!spp)
		return;

	mol::CoCAUUIDBuf pages;
	if ( S_OK != spp->GetPages(&pages) )
		return;

	mol::bstr path;
	if ( S_OK == props_->get_Filename(&path) )
	{
		LPUNKNOWN unks[2] = { (IUnknown*)unk, (IUnknown*)unk };
		std::wstring filename(mol::Path::filename(path.towstring()));

		::OleCreatePropertyFrame( *this, 10, 10,
								  filename.c_str(),
								  1, unks, pages->cElems,
								  pages->pElems, 0, 0, 0 );
	}
	
}

handle_cmd(&Editor::OnInsertColorDialog, IDM_EDIT_COLOR)
void Editor::OnInsertColorDialog()
{
	sci->InsertColorDialog();
}


////////////////////////////////////////////////////////////////////////////// 

handle_cmd_range(&Editor::OnLexer, IDM_LEXER_PLAIN, IDM_LEXER_PYTHON)
void Editor::OnLexer(int code, int id, HWND ctrl)
{
	if ( !sci )
		return;

	int syntax = id;

	if ( syntax < IDM_LEXER_PLAIN || syntax > IDM_LEXER_PYTHON )
		return ;

	syntax -= IDM_LEXER_PLAIN;

	props_->put_Syntax(syntax);

	mol::bstr displayname;
	if ( S_OK == props_->GetSyntaxDisplayName(syntax,&displayname) )
	{
		statusBar()->status(displayname.towstring());
	}

}


//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////

handle_cmd(&Editor::OnReload, IDM_EDIT_UPDATE)
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
	long syntax;
	if (S_OK != props_->get_Syntax(&syntax))
	{
		return;
	}

	if (mol::towstring(filename).substr(0, 6) == _T("ssh://") || mol::towstring(filename).substr(0, 6) == _T("moe-ssh://"))
	{
		sci->LoadEncoding(filename,CP_UTF8);
		props_->put_ReadOnly(vb);
		statusBar()->status(filename.towstring());
		scrollDown();
		return ;
	}

	lastWriteTime_ = getLastWriteTime(filename.towstring());


	sci->LoadEncoding(filename,t);
	props_->put_ReadOnly(vb);
	props_->put_Syntax(syntax);
	statusBar()->status(filename.towstring());
	scrollDown();
}



//////////////////////////////////////////////////////////////////////////////

handle_cmd(&Editor::OnSaveAs, IDM_FILE_SAVE_AS)
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

	const COMDLG_FILTERSPEC c_rgSaveTypes[] =
	{
		{ L"all files (*.*)",       L"*.*"}
	};

	MoeVistaFileDialog fd(*moe());
	fd.setFilter((COMDLG_FILTERSPEC*)&c_rgSaveTypes,ARRAYSIZE(c_rgSaveTypes));
	fd.encoding( enc );
	fd.path(mol::towstring(p));
	HRESULT hr = fd.save(FOS_NOVALIDATE);
	if ( hr != S_OK )
		return;

	enc = fd.encoding();
	props_->put_Encoding(enc);

	std::wostringstream oss;
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

//////////////////////////////////////////////////////////////////////////////

handle_cmd(&Editor::OnSave, IDM_FILE_SAVE)
void Editor::OnSave()
{
	if ( !sci )
		return;

	mol::bstr filename;
	props_->get_Filename(&filename);

	std::wstring path = mol::towstring(filename);

	saving_ = true;
	std::wostringstream oss;

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

handle_cmd(&Editor::OnShowLineNumbers, IDM_MODE_SHOW_LINE_NUMBERS)
void Editor::OnShowLineNumbers()
{
	if ( !sci )
		return;	

	VARIANT_BOOL vb;
	if ( S_OK != props_->get_ShowLineNumbers(&vb) )
		return;

	vb = vb == VARIANT_FALSE ? VARIANT_TRUE : VARIANT_FALSE;
	props_->put_ShowLineNumbers(vb);
}


void walkConf(mol::Menu& parent, ISetting* set, std::map<int, ISetting*>& confMap, int& id)
{
	if (!set)
		return;

	long l;
	mol::bstr key;
	if (S_OK != set->get_Key(&key))
		return;

	if (S_OK != set->Count(&l))
		return;

	if (l <= 0)
	{
		parent.addItem(id, key.towstring(), MF_STRING);
		confMap[id] = set;
		id++;
		return;
	}

	mol::Menu m;
	m.create();

	parent.addSubmenu(m, key.towstring(), MF_POPUP | MF_STRING);

	m.detach();

	for (long i = 0; i < l; i++)
	{
		mol::punk<ISetting> s;
		if (S_OK != set->Item(mol::variant(i), &s))
			continue;

		if (!s)
			continue;

		walkConf(m, s, confMap, id);
	}
}

handle_cmd(&Editor::OnTemplate, IDM_USER_SHORTCUT)
void Editor::OnTemplate()
{
	this->shortCutMap.clear();

	mol::Menu m;
	m.createContext();

	mol::punk<IDispatch> disp;
	moe()->moeConfig->get_Settings(&disp);
	mol::punk<ISetting> config(disp);

	mol::punk<ISetting> shortCuts;

	if (S_OK != config->Item(mol::variant("shortCuts"), &shortCuts))
		return;

	int id = ID_FIRST_USER_CMD;

	long l;
	if (S_OK == shortCuts->Count(&l))
	{
		for (long i = 0; i < l; i++)
		{
			mol::punk<ISetting> set;
			if (S_OK == shortCuts->Item(mol::variant(i), &set))
			{
				walkConf(m, set, shortCutMap,id);
			}
		}
	}

	showContext(m);
}


handle_cmd(&Editor::OnExecScript, IDM_EDIT_EXECUTESCRIPT)
void Editor::OnExecScript()
{
	EditorScript es(this);
	es.execScript();
}

handle_cmd(&Editor::OnExecForm, IDM_MODE_EXECUTEFORM)
void Editor::OnExecForm()
{
	EditorScript es(this);
	es.execForm();
}

handle_cmd(&Editor::OnDebugScriptGo, IDM_EDIT_DEBUG_GO)
void Editor::OnDebugScriptGo()
{
	EditorScript es(this);
	es.debugScriptGo();
}

handle_cmd(&Editor::OnDebugScriptStepIn, IDM_EDIT_DEBUG_STEPIN)
void Editor::OnDebugScriptStepIn()
{
	EditorScript es(this);
	es.debugScriptStepIn();
}

handle_cmd(&Editor::OnDebugScriptStepOver, IDM_EDIT_DEBUG_STEPOVER)
void Editor::OnDebugScriptStepOver()
{
	EditorScript es(this);
	es.debugScriptStepOver();
}

handle_cmd(&Editor::OnDebugScriptStepOut, IDM_EDIT_DEBUG_STEPOUT)
void Editor::OnDebugScriptStepOut()
{
	EditorScript es(this);
	es.debugScriptStepOut();
}

handle_cmd(&Editor::OnDebugScriptStop, IDM_EDIT_DEBUG_STOP)
void Editor::OnDebugScriptStop()
{
	EditorScript es(this);
	es.debugScriptStop();
}

handle_cmd(&Editor::OnDebugScriptQuit, IDM_EDIT_DEBUG_QUIT)
void Editor::OnDebugScriptQuit()
{
	EditorScript es(this);
	es.debugScriptQuit();
}

handle_cmd(&Editor::OnDebugScriptEval, IDM_EDIT_DEBUG_EVAL_EXPR)
void Editor::OnDebugScriptEval()
{
	EditorScript es(this);
	es.debugScriptEval();
}

handle_cmd( &Editor::OnCloseAll, IDM_VIEW_CLOSEALL)
LRESULT Editor::OnCloseAll()
{
	return MoeAxChild<
		Editor,
		MOE_DOCTYPE_DOC,
		&CLSID_ScintillAx,
		IDM_MOE
	>::OnCloseAll();
}



handle_ole_cmd(Editor, IDM_EDIT_UNDO, &IScintillAx::Undo)
handle_ole_cmd(Editor, IDM_EDIT_REDO, &IScintillAx::Redo)
handle_ole_cmd(Editor, IDM_FILE_PRINT, &IScintillAx::Print)


void Editor::OnScriptThreadDone()
{
	if ( mol::guithread() != mol::Thread::self() )
	{
		mol::invoke( std::bind( &Editor::OnScriptThreadDone, this) );		
		return;
	}

	EditorScript es(this);
	es.scriptThreadDone();
}

void Editor::OnScriptThread( int line, std::wstring error )
{
	if ( mol::guithread() != mol::Thread::self() )
	{
		EditorScript es(this);
		es.scriptThread(line,error);
		return;
	}

	EditorScript es(this);
	es.scriptThread2(line,error);
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

HRESULT __stdcall Editor::SaveAsDialog()
{
	this->OnSaveAs();
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
	{
		*showMenue = VARIANT_FALSE;
		moe()->moeView->ShowContextMenu();
	}
	return S_OK;
}

HRESULT __stdcall  Editor::Sintilla_Events::OnPosChange( long line )
{
	if ( !This()->sci )
		return S_OK;

	std::wostringstream oss;
	oss << (line+1);

	long pos = 0;
	long linepos = 0;
	This()->position_->get_Caret(&pos);
	This()->line_->PosFromLine(line,&linepos);

	long col = pos-linepos;
	std::wostringstream oss2;
	oss2 << col << " "; 

	mol::bstr path;
	This()->props_->get_Filename(&path);

	std::wstring dirty(_T(""));
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

	statusBar()->setText(path.towstring(), dirty, oss.str(), oss2.str());
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

	if ( This()->debugger_ )
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
		This()->debugger_->update_breakpoints(s);
	}
	return S_OK; 
}

HRESULT __stdcall Editor::Sintilla_Events::OnTabUsage(VARIANT_BOOL vb)
{
	This()->updateUI();
	return S_OK;
}

HRESULT __stdcall Editor::Sintilla_Events::OnTabIndents(VARIANT_BOOL vb)
{
	This()->updateUI();
	return S_OK;
}

HRESULT __stdcall Editor::Sintilla_Events::OnBackspaceUnindents(VARIANT_BOOL vb)
{
	This()->updateUI();
	return S_OK;
}

HRESULT __stdcall Editor::Sintilla_Events::OnShowLineNumbers(VARIANT_BOOL vb)
{
	This()->updateUI();
	return S_OK;
}

HRESULT __stdcall Editor::Sintilla_Events::OnWriteBOM(VARIANT_BOOL vb)
{
	This()->updateUI();
	return S_OK;
}

HRESULT __stdcall Editor::Sintilla_Events::OnTabWidth(long w)
{
	This()->updateUI();
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

	FILETIME ft = getLastWriteTime(path.towstring());


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

