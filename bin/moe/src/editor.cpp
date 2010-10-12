#include "stdafx.h"
#include "editor.h"
#include "moe.h"
#include "Docs.h"
#include "moebar.h"
#include "xmlui.h"
#include "ole/Rib.h"
#include "TaskBar.h"
#include "ribbonres.h"

using namespace mol::win;
using namespace mol::ole;
using namespace mol::io;

mol::TCHAR OutFilesFilter[]   = _T("ANSI\0*.*\0UTF-8\0*.*\0UTF-16 (LE)\0*.*\0\0");

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// Base Child
//////////////////////////////////////////////////////////////////////////////

Editor::Editor() 
{
    eraseBackground_ = 1;
	wndClass().setIcon(moe()->icon); 
	wndClass().hIconSm(moe()->icon); 
}
//////////////////////////////////////////////////////////////////////////////

Editor::~Editor() 
{
	ODBGS("~Editor dead");
};

//////////////////////////////////////////////////////////////////////////////
Editor::Instance* Editor::CreateInstance(const mol::string& file, bool utf8, bool readOnly)
{
	statusBar()->status(20);

	mol::string p(file);
	if ( mol::Path::exists(p) && mol::Path::isDir(p) )
		return 0;

	statusBar()->status(50);

	Instance* e = new Instance;
	e->AddRef();

	if ( !e->initialize(file,utf8,readOnly) )
	{
		e->destroy();
		return 0;
	}
	return e;
}

bool Editor::initialize(const mol::string& p, bool utf8, bool readOnly)
{
	filename_ = p;

	// get client rectangle
	mol::Rect r;
	::GetClientRect(mdiClient(),&r);

	// determine window menu
	HMENU m = mol::UI().Menu(IDM_MOE);
	windowMenu_ = mol::UI().SubMenu( IDM_MOE ,IDM_VIEW_WINDOWS);

	statusBar()->status(40);

	// create the win window
	HWND hc = create(p,(HMENU)m,r,*moe());

	// hook up com event handlers
	events.Advise(oleObject);

	// show the window
	show(SW_SHOW);

	statusBar()->status(50);

	sci = oleObject;

	// if file exists, load
	if ( mol::Path::exists(p) )
	{
		if ( utf8 )
		{
			if ( S_OK != sci->LoadUTF8(mol::bstr(p)) )
				return false;
		}
		else
		{
			if ( S_OK != sci->Load(mol::bstr(p)) )
				return false;
		}
	}
	else
	{
		sci->put_Filename(mol::bstr(p));
	}

	statusBar()->status(80);

	// get default values from config and init scintilla

	moe()->moeConfig->InitializeEditorFromPreferences( (IMoeDocument*)this );


	sci->put_ReadOnly( readOnly ? VARIANT_TRUE : VARIANT_FALSE );

	if ( mol::Ribbon::ribbon()->enabled() )
	{
		sci->put_UseContext(VARIANT_FALSE);
	}
	statusBar()->status(100);

	thumb = taskbar()->addTab( this );

	// now maximize the window
	maximize();
	OnLayout(0,0,0);

	return true;
}


//////////////////////////////////////////////////////////////////////////////


LRESULT Editor::OnClose()
{
	this->destroy();
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// OnDestroy - over and out
//
//////////////////////////////////////////////////////////////////////////////

void Editor::OnDestroy()
{
	mol::variant v(filename_);
	docs()->Remove(v);
	
 	events.UnAdvise(oleObject);
	sci.release();
}

void Editor::OnNcDestroy()
{
	IMoeDocument*e = (IMoeDocument*)this;
	::CoDisconnectObject(((IMoeDocument*)this),0);
	((IMoeDocument*)this)->Release();
}

//////////////////////////////////////////////////////////////////////////////

LRESULT Editor::OnMDIActivate(WPARAM unused, HWND activated)
{
	ODBGS("Editor::OnMDIActivate");

	if ( activated != hWnd_ )
	{
		thumb.refreshIcon();
	}
	BaseWindowType::wndProc( hWnd_, WM_MDIACTIVATE, (WPARAM)unused, (LPARAM)activated );
	if ( activated == hWnd_ )
	{

		tab()->select( filename_ );
		updateUI();
		setFocus();
		thumb.refreshIcon(true);
	}
	return 0;
}

void Editor::OnConvertTabs()
{
	if ( !sci )
		return;

	sci->ConvertTabs();
}

void Editor::OnEncoding()
{
	if ( !sci )
		return;

	// get chosen lexer id
	int enc = mol::Ribbon::handler(RibbonEncoding)->index();

	HRESULT hr = sci->put_Encoding(enc);	
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

	sci->put_TabUsage(vb);	
}

void Editor::OnTabWidth()
{
	if ( !sci )
		return;

	mol::variant v = mol::Ribbon::handler(RibbonTabSize)->decimal();

	DECIMAL d = v.decVal;
	long w = d.Lo32;

	sci->put_TabWidth(w);
}

void Editor::OnTabIndents()
{
	if ( !sci )
		return;

	VARIANT_BOOL vb = mol::Ribbon::handler(RibbonTabIndents)->checked() ? VARIANT_TRUE: VARIANT_FALSE;

	sci->put_TabIndents(vb);
}

void Editor::OnBackspaceUnindents()
{
	if ( !sci )
		return;

	VARIANT_BOOL vb = mol::Ribbon::handler(RibbonTabBackSpaceUnIndents)->checked() ? VARIANT_TRUE: VARIANT_FALSE;

	sci->put_BackSpaceUnindents(vb);
}

void Editor::OnWriteBOM()
{
	if ( !sci )
		return;

	VARIANT_BOOL vb = mol::Ribbon::handler(RibbonWriteBOM)->checked() ? VARIANT_TRUE: VARIANT_FALSE;

	sci->put_WriteBOM(vb);
}


//////////////////////////////////////////////////////////////////////////////

void Editor::OnReload()
{
	VARIANT_BOOL vb;
	if ( S_OK != sci->Modified(&vb) )
		return ;

	if ( vb == VARIANT_TRUE )
	{
		mol::bstr path;
		sci->get_Filename(&path);
		if ( IDYES != ::MessageBox(*this,_T("File is modified.\r\nClose without Save?"), path.toString().c_str() ,MB_YESNO|MB_ICONEXCLAMATION) )
			return ;
	}
	mol::bstr filename;
	if ( S_OK != get_FilePath(&filename) )
	{
		return ;
	}
	if ( S_OK != sci->get_ReadOnly(&vb) )
	{
		return ;
	}
	long t;
	if ( S_OK != sci->get_Encoding(&t) )
	{
		return ;
	}
	if ( t == SCINTILLA_ENCODING_UTF8 )
	{

		sci->LoadUTF8(filename);
		sci->put_ReadOnly(vb);
		statusBar()->status(filename.toString());
		return ;
	}
	sci->Load(filename);
	sci->put_ReadOnly(vb);
	statusBar()->status(filename.toString());
}

LRESULT Editor::OnToolbarDropDown(NMTOOLBAR* toolbar)
{
	mol::Menu m(mol::UI().Menu(IDM_MOE),false);
	
	int index = toolbar->iItem;
	if ( index == IDM_MODE_EOL )
		createMenuFromConf(m,mol::UI().SubMenu(IDM_MOE,IDM_MODE_EOL));
	else
		createMenuFromConf(m,mol::UI().SubMenu(IDM_MOE,IDM_TOOLS));

	mol::Menu context( mol::UI().SubMenu(IDM_MOE,index) );
	showContext(context);

	updateUI();
	return TBDDRET_DEFAULT;
}
 
//////////////////////////////////////////////////////////////////////////////
void Editor::OnSelectAll()
{
	long len = 0;
	sci->TextLength(&len);
	sci->SetSelection(0,len);
}

void Editor::OnUserCommand(int code, int id, HWND ctrl)//(UINT msg, WPARAM wParam, LPARAM lParam)
{
	ISetting* set = shortCutMap[id];
    if ( !set ) 
		return ;

	long sel;
	if ( S_OK != sci->GetSelectionStart(&sel) )
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
						
	if ( S_OK != sci->Insert(mol::bstr(tmp),sel) )
		return ;

	if ( pos != std::string::npos )
	{
		sci->SetSelection( (long)(sel+pos), (long)(sel+pos));
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

	size_t p = path.find( _T(","));
	if ( p != mol::string::npos )
	{
		file = path.substr(0,p);
		size_t pos = 0;
		if ( (pos = path.find(_T(","),p+1)) != mol::string::npos )
		{
			l = l + atoi( mol::tostring( path.substr(p+1,pos-p-1) ).c_str() );
			p = pos;
			if ( (pos = path.find(_T(","),p+1)) != mol::string::npos )
			{
				t = t + atoi( mol::tostring( path.substr(p+1,pos-p-1) ).c_str() );
				p = pos;
				if ( (pos = path.find(_T(","),p+1)) != mol::string::npos )
				{
					if ( pos-p-1 > 0)
						w = atoi( mol::tostring( path.substr(p+1,pos-p-1) ).c_str() );
					p = pos;
					if ( (pos = path.find(_T(","),p+1)) != mol::string::npos )
					{
						if ( pos-p-1 > 0)
							h = atoi( mol::tostring( path.substr(p+1,pos-p-1) ).c_str() );
						o = atoi( mol::tostring( path.substr(pos+1) ).c_str() );
					}
					else
					{
						h = h + atoi( mol::tostring( path.substr(p+1) ).c_str() );
					}
				}
				else
				{
					w = w + atoi( mol::tostring( path.substr(p+1) ).c_str() );
				}
			}
			else
			{
				t = t + atoi( mol::tostring( path.substr(p+1) ).c_str() );
			}
		}
		else
		{
			l = l + atoi( mol::tostring( path.substr(p+1) ).c_str() );
		}
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
	long type;
	if ( S_OK != sci->get_Syntax(&type) || type != SCINTILLA_SYNTAX_HTML )
		return ;

	mol::bstr b;
	if ( S_OK != sci->GetText(&b) || b.bstr_ == 0 )
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

	sci->SetText(mol::bstr(os.str()));
}

void Editor::OnSearch(FINDREPLACE* find)
{
    if ( (find->Flags) & FR_FINDNEXT )
    {
		std::string what( mol::tostring(find->lpstrFindWhat));
		std::string utf8what(mol::ansi2utf8(what));

		VARIANT_BOOL vb;
		sci->Search(mol::bstr(utf8what),find->Flags,&vb);
		if ( VARIANT_FALSE == vb )
		{
			statusBar()->status(_T("Search: end of doc"));
		}
    }
    if ( (find->Flags) & FR_REPLACE )
    {
		std::string what (mol::tostring(find->lpstrFindWhat));
		std::string with(mol::tostring(find->lpstrReplaceWith));
		std::string utf8what(mol::ansi2utf8(what));
		std::string utf8with(mol::ansi2utf8(with));

		VARIANT_BOOL vb;
		sci->Replace(mol::bstr(utf8what),mol::bstr(utf8with),find->Flags,&vb);
		if ( VARIANT_FALSE == vb )
		{
			statusBar()->status(_T("Replace: end of doc"));
		}
    }
    if ( (find->Flags) & FR_REPLACEALL )
    {
		std::string what (mol::tostring(find->lpstrFindWhat));
		std::string with(mol::tostring(find->lpstrReplaceWith));
		std::string utf8what(mol::ansi2utf8(what));
		std::string utf8with(mol::ansi2utf8(with));

        int c = 0;

		VARIANT_BOOL vb = VARIANT_TRUE;
		while ( vb == VARIANT_TRUE )
		{
			sci->Replace(mol::bstr(utf8what),mol::bstr(utf8with),find->Flags,&vb);
				
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
	sci->put_SysType(SCINTILLA_SYSTYPE_UNIX);
	statusBar()->status( _T("set EOL type to UNIX (\\n)"));

}


void Editor::OnWin32()
{
	sci->put_SysType(SCINTILLA_SYSTYPE_WIN32);
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
	if ( S_OK == sci->get_Filename(&filename) )
	{
		mol::string p(filename.toString());
		::OleCreatePropertyFrame( *this, 10, 10,
								  mol::towstring(mol::Path::filename(p)).c_str(),
								  1, &unk, pages.cElems,
								  pages.pElems, 0, 0, 0 );

		::CoTaskMemFree(pages.pElems);
	}
}

void Editor::OnInsertColorDialog()
{
	if ( !sci )
		return;

	sci->InsertColorDialog(*this);
}


////////////////////////////////////////////////////////////////////////////// 


void Editor::OnLexer(int code, int id, HWND ctrl)
{
	int syntax = id;

	if ( syntax < IDM_LEXER_PLAIN || syntax > IDM_LEXER_CSHARP )
		return ;

	syntax -= IDM_LEXER_PLAIN;
	sci->put_Syntax(syntax);

	mol::bstr displayname;
	if ( S_OK == sci->GetSyntaxDisplayName(syntax,&displayname) )
	{
		statusBar()->status(displayname.toString());
	}

}


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

void Editor::OnSaveAs()
{
	long enc;
	mol::bstr p;

	mol::FilenameDlg ofn(*this);
	ofn.setFilter( OutFilesFilter );		
	if ( S_OK == sci->get_Encoding(&enc) )
		ofn.index(enc+1);
	if ( S_OK == sci->get_Filename(&p) )
		ofn.fileName(p.toString());

	if ( ofn.dlgSave( OFN_OVERWRITEPROMPT ) )
	{
		mol::bstr b;
		this->get_FilePath(&b);

		
		if ( ofn.fileName() != b.toString() )
		{
			mol::punk<IMoeDocument> doc;
			if ( (S_OK == docs()->Item(mol::variant(ofn.fileName()),&doc)) && doc )
			{
				::MessageBox(*this, _T("File already open in other editor window!"), _T("error"),MB_ICONERROR);
				return ;
			}
		}

		if ( enc != ofn.index()-1 )
			sci->put_Encoding(ofn.index()-1);
		if (sci)
		{
			if ( S_OK == sci->SaveAs( mol::bstr(ofn.fileName() ) ) )
			{
				docs()->Rename( mol::variant(filename_), mol::variant(ofn.fileName()) );
				mol::ostringstream oss;
				oss << _T("file saved as ") << ofn.fileName() << _T(" saved");
				statusBar()->status(oss.str());
				filename_ = ofn.fileName();
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////////

void Editor::OnSave()
{
	HRESULT hr = sci->Save();
	if ( hr == S_OK )
	{
		mol::bstr filename;
		sci->get_Filename(&filename);
		mol::ostringstream oss;
		oss << _T("saved file ") << filename.toString() ;
		statusBar()->status(oss.str());
	}
}

void Editor::OnExecForm()
{
	sci->Save();

	mol::bstr filename;
	if ( S_OK != sci->get_Filename(&filename) )
	{
		return ;
	}
		
	RECT r;
	moe()->getWindowRect(r);

	moe()->moeScript->ShowHtmlForm(
			filename, 
			r.left+50,
			r.top+50,
			r.right-r.left-100,
			r.bottom-r.top-100,
			1
	);
}

void Editor::OnShowLineNumbers()
{
	VARIANT_BOOL vb;
	if ( S_OK != sci->get_ShowLineNumbers(&vb) )
		return;

	vb = vb == VARIANT_FALSE ? VARIANT_TRUE : VARIANT_FALSE;
	sci->put_ShowLineNumbers(vb);

	mol::Menu mode(mol::UI().SubMenu(IDM_MOE,IDM_MODE));

	if ( vb == VARIANT_TRUE )
		mode.checkItem( IDM_MODE_SHOW_LINE_NUMBERS );
	else
		mode.unCheckItem( IDM_MODE_SHOW_LINE_NUMBERS );
}

void Editor::OnExecScript()
{
	mol::bstr filename;
	if ( S_OK != sci->get_Filename(&filename) )
		return ;

	mol::string engine = engineFromPath(filename.tostring());
	if ( engine == _T("") )
		return ;

	mol::bstr script;
	if ( S_OK != sci->GetText(&script) )
		return ;

	scriptlet()->eval(engine,script.toString(),sci);

	//moe()->moeScript->Eval( script, mol::bstr(engine) );
}


void Editor::OnDebugScript()
{
	mol::bstr filename;
	if ( S_OK != sci->get_Filename(&filename) )
		return ;

	mol::string engine = engineFromPath(filename.tostring());
	if ( engine == _T("") )
		return ;

	mol::bstr script;
	if ( S_OK != sci->GetText(&script) )
		return ;

	//moe()->moeScript->Debug( script, mol::bstr(engine) );
	scriptlet()->debug(engine,script.toString(),sci);
}

//////////////////////////////////////////////////////////////////////////////
//
// helpers
//
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////

void Editor::OnMenu(HMENU popup, LPARAM unused)
{
	HMENU frameMenu = mol::UI().Menu(IDM_MOE);

	if ( popup == mol::UI().SubMenu(IDM_MOE,IDM_MODE_EOL) )
		createMenuFromConf(frameMenu,popup);
	else
	if ( popup == mol::UI().SubMenu(IDM_MOE,IDM_TOOLS) )
		createMenuFromConf(frameMenu,popup);
}


//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall Editor::get_FilePath( BSTR *fname)
{
	if ( fname  )
	{
		*fname = 0;
		*fname = ::SysAllocString( mol::towstring(filename_).c_str() );
	}
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall  Editor::Sintilla_Events::OnFileNameChanged( BSTR filename, BSTR path)
{
	mol::MdiFrame* mf = mol::wndFromHWND<mol::MdiFrame>( This()->mdiParent() );
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
	mol::ostringstream oss;
	oss << (line+1);

	long pos = 0;
	long linepos = 0;
	This()->sci->GetCaretPos(&pos);
	This()->sci->PosFromLine(line,&linepos);

	long col = pos-linepos;
	mol::ostringstream oss2;
	oss2 << col << " ";

	statusBar()->setText( This()->filename_, oss.str(), oss2.str());
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

//////////////////////////////////////////////////////////////////////////////
}/////////////////////////////////////////////////////////////////////////////

void Editor::updateUI()
{
	mol::bstr path;
	mol::string title = this->getText();;
	if ( S_OK == this->get_FilePath(&path) && path)
	{
		title = path.toString();	
	}

	if ( !sci )
	{
		setText(title);
		return;
	}

	long line=0;
	sci->CurrentLine(&line);
	mol::ostringstream oss;
	oss << line;

	long pos = 0;
	long linepos = 0;
	sci->GetCaretPos(&pos);
	sci->PosFromLine(line-1,&linepos);

	long col = pos-linepos;
	mol::ostringstream oss2;
	oss2 << col << " ";

	statusBar()->setText( filename_, oss.str(), oss2.str() );

	long encoding;
	if ( S_OK == sci->get_Encoding(&encoding) )
	{
		switch ( encoding )
		{
			case SCINTILLA_ENCODING_UTF16 :
			{
				title += _T(" - UTF16-LE");
				break;
			}
			case SCINTILLA_ENCODING_UTF8 :
			{
				title += _T(" - UTF8");
				break;
			}
			default:
			{
				title += _T(" - ANSI");
				break;
			}
		}
		if ( mol::Ribbon::ribbon()->enabled())
		{
			mol::Ribbon::handler(RibbonEncoding)->select(encoding);
		}
	}
	
	long systype;
	if ( S_OK == sci->get_SysType(&systype) )
	{
		if ( systype ==  SCINTILLA_SYSTYPE_UNIX )
		{
			title += _T("/UNIX");
			if ( mol::Ribbon::ribbon()->enabled())
			{
				mol::Ribbon::handler(RibbonSelectModeUnix)->check(true); 
				mol::Ribbon::handler(RibbonSelectModeWin32)->check(false); 
			}
		}
		else
		{
			title += _T("/WIN32");
			if ( mol::Ribbon::ribbon()->enabled())
			{
				mol::Ribbon::handler(RibbonSelectModeUnix)->check(false); 
				mol::Ribbon::handler(RibbonSelectModeWin32)->check(true); 
			}
		}
	}

	LONG type = 0;
	sci->get_Syntax(&type);
	syntax()->setCurSel(type);

	if ( mol::Ribbon::ribbon()->enabled())
	{
		mol::Ribbon::handler(RibbonSelectLanguage)->select(type);
	}

	VARIANT_BOOL vb;
	if ( S_OK == sci->get_ReadOnly(&vb) )
	{
		if ( vb == VARIANT_TRUE )
			title += _T(" [ReadOnly]");
	}
	setText(title);


	if ( mol::Ribbon::ribbon()->enabled())
	{
		if ( S_OK == sci->get_TabUsage(&vb) )
		{
			mol::Ribbon::handler(RibbonTabUseTabs)->check(vb == VARIANT_TRUE ? true : false );
		}
		if ( S_OK == sci->get_TabIndents(&vb) )
		{
			mol::Ribbon::handler(RibbonTabIndents)->check(vb == VARIANT_TRUE ? true : false );
		}
		if ( S_OK == sci->get_BackSpaceUnindents(&vb) )
		{
			mol::Ribbon::handler(RibbonTabBackSpaceUnIndents)->check(vb == VARIANT_TRUE ? true : false );
		}
		long w = 0;
		if ( S_OK == sci->get_TabWidth(&w) )
		{
			DECIMAL d;
			::ZeroMemory(&d,sizeof(d));
			d.Lo32 = w;

			VARIANT v;
			::VariantInit(&v);
			v.vt = VT_DECIMAL;
			v.decVal = d;

			mol::variant var(v);

			mol::Ribbon::handler(RibbonTabSize)->decimal(var);

			::VariantClear(&v);
		}
		if ( S_OK == sci->get_WriteBOM(&vb) )
		{
			mol::Ribbon::handler(RibbonWriteBOM)->check(vb == VARIANT_TRUE ? true : false );
		}
	}


	if ( S_OK != sci->get_ShowLineNumbers(&vb) )
		return;

	if ( mol::Ribbon::ribbon()->enabled() )
	{
		bool  b = vb == VARIANT_TRUE ? true : false;
		mol::Ribbon::handler(RibbonShowLineNumbers)->check(b);
	}
	else
	{
		mol::Menu mode(mol::UI().SubMenu(IDM_MOE,IDM_MODE));

		if ( vb == VARIANT_TRUE )
			mode.checkItem( IDM_MODE_SHOW_LINE_NUMBERS );
		else
			mode.unCheckItem( IDM_MODE_SHOW_LINE_NUMBERS );
	}


	if ( mol::Ribbon::ribbon()->enabled())
	{
		mol::Ribbon::ribbon()->maximize();
		mol::Ribbon::ribbon()->mode(1);
	}
}


//////////////////////////////////////////////////////////////////////////////
void Editor::populateMenuFromConf( HMENU submenu, ISetting* set, std::map<int,ISetting*>& confMap, int& id)
{
	long l;
	if ( S_OK == set->Count(&l) )
	{
		for ( long i = 0; i < l; i++ )
		{
			mol::punk<ISetting> s;
			if ( S_OK == set->Item(mol::variant(i),&s) )
			{
				walkConf(submenu,s,confMap,id);
			}
		}
	}
}

void Editor::updateModeMenu( mol::Menu& mode )
{
	mode.enableItem(IDM_MODE_UNIX);

	long systype;
	if ( S_OK == sci->get_SysType(&systype) )
	{
		if ( systype == SCINTILLA_SYSTYPE_WIN32 )
		{
			mode.unCheckItem(IDM_MODE_UNIX);
			mode.checkItem(IDM_MODE_WIN32);
		}
		else
		{
			mode.unCheckItem(IDM_MODE_WIN32);
			mode.checkItem(IDM_MODE_UNIX);
		}
	}
	long encoding;
	if ( S_OK == sci->get_Encoding(&encoding) )
	{
		if ( encoding == SCINTILLA_ENCODING_UTF16 )
		{
			mode.disableItem(IDM_MODE_UNIX);
		}
	}
}

void Editor::updateToolMenu( HMENU tools )
{
	VARIANT_BOOL vb;
	static bool runonce = true;

	if ( runonce )
	{
		runonce = false;
	}
	else
		if ( (config()->get_IsDirty(&vb) == S_OK) && (vb == VARIANT_FALSE) )
	{
		return;
	}


	int startShortCutId_ = ID_FIRST_USER_CMD;
	int startScriptId_   = ID_FIRST_USER_SCRIPT;
	int startBatchId_    = ID_FIRST_USER_BATCH;
	int startFormId_     = ID_FIRST_USER_FORM;

	shortCutMap.clear();
	scriptMap.clear();
	batchMap.clear();
	formMap.clear();

	mol::punk<ISetting> shortCuts;
	mol::punk<ISetting> scripts;
	mol::punk<ISetting> batches;
	mol::punk<ISetting> forms;

	if ( S_OK != config()->Item(mol::variant("shortCuts"),&shortCuts) )
		return;

	if ( S_OK != config()->Item(mol::variant("scripts"),&scripts) )
		return;

	if ( S_OK != config()->Item(mol::variant("batches"),&batches) )
		return;

	if ( S_OK != config()->Item(mol::variant("forms"),&forms) )
		return;

	int n = ::GetMenuItemCount(tools);
	for ( int j = 0; j < 4; j++ )
	{
		HMENU sub = ::GetSubMenu(tools,n-j-1);
		mol::Menu subMenu(sub);
		int nsub = ::GetMenuItemCount(sub);
		for ( int k = nsub-1; k >= 0; k-- )
		{
			subMenu.remove(k,MF_BYPOSITION);
		}
	}

	HMENU ms = mol::UI().SubMenu(IDM_MOE,IDM_USER_SCRIPT);
	populateMenuFromConf( ms, scripts, scriptMap,startScriptId_);

	HMENU mb = mol::UI().SubMenu(IDM_MOE,IDM_USER_BATCH);
	populateMenuFromConf( mb, batches, batchMap,startBatchId_);			

	HMENU mf = mol::UI().SubMenu(IDM_MOE,IDM_USER_FORM);
	populateMenuFromConf( mf, forms, formMap,startFormId_);			
	
	HMENU msc = mol::UI().SubMenu(IDM_MOE,IDM_USER_SHORTCUT);
	populateMenuFromConf( msc, shortCuts, shortCutMap,startShortCutId_);			


}


void Editor::createMenuFromConf(HMENU menu,HMENU popup)
{

	HMENU frameMenu = mol::UI().Menu(IDM_MOE);

	HMENU tools = mol::UI().SubMenu(IDM_MOE,IDM_TOOLS);
	mol::Menu mode(mol::UI().SubMenu(IDM_MOE,IDM_MODE_EOL));

	if ( popup == mode )
	{
		updateModeMenu(mode);
		return;
	}

	if ( popup != tools )
		return;

	updateToolMenu(tools);

	if ( !mol::Ribbon::ribbon()->enabled())
		::DrawMenuBar(*moe()); 
	::UpdateWindow(*moe()); 
}



void Editor::walkConf(HMENU parent, ISetting* set, std::map<int,ISetting*>& confMap, int& id)
{
    if ( !set )
		return;

    long l;
	mol::bstr key;
	if ( S_OK != set->get_Key(&key) )
		return;

	if ( S_OK != set->Count(&l) )
		return;

	if ( l <= 0 ) 
	{
		mol::win::MenuItemInfo* inf = new mol::win::MenuItemInfo(key.toString().c_str(),false,-1,0);
		::AppendMenu( parent, MF_OWNERDRAW, (UINT_PTR)id, (mol::TCHAR*)inf);
		confMap[id] = (ISetting*)set;
		id++;
		return;
	}

	HMENU m = ::CreateMenu();
	mol::win::MenuItemInfo* inf = new mol::win::MenuItemInfo(key.toString().c_str(),false,-1,0);
	::AppendMenu( parent, MF_POPUP|MF_OWNERDRAW, (UINT_PTR)m, (mol::TCHAR*)inf);

	for ( long i = 0; i < l; i++ )
	{
		mol::punk<ISetting> s;
		if ( S_OK != set->Item(mol::variant(i),&s) )
			continue;

		if ( !s )
			continue;

		walkConf(m,s,confMap,id);
	}
}

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

