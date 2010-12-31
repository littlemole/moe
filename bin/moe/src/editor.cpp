#include "stdafx.h"
#include "editor.h"
#include "moe.h"
#include "Docs.h"
#include "moebar.h"
#include "xmlui.h"
#include "ole/Rib.h"
#include "win/TaskBar.h"
#include "ribbonres.h"
#include "ThreadScript.h"
#include "ActivDbg.h"
#include "boost/function.hpp"

using namespace mol::win;
using namespace mol::ole;
using namespace mol::io;

mol::TCHAR OutFilesFilter[]   = _T("ANSI\0*.*\0UTF-8\0*.*\0UTF-16 (LE)\0*.*\0\0");

//////////////////////////////////////////////////////////////////////////////
// helpers for easy access of scintillAx members. just to save some repetition
//////////////////////////////////////////////////////////////////////////////

template<class T>
class SciMember
{};

template<class T>
struct SciMemberBase
{
	T* operator->() { return ptr_; }

	mol::punk<T> ptr_;
};

#define SciMemberImpl(Prop)																			\
template<>																							\
struct SciMember<IScintillAx##Prop> : public SciMemberBase<IScintillAx##Prop>						\
{																									\
	SciMember(IScintillAx* sci)																		\
	{																								\
		sci->get_##Prop(&ptr_);																		\
	}																								\
};																									\

SciMemberImpl(Properties);
SciMemberImpl(Position);
SciMemberImpl(Selection);
SciMemberImpl(Line);
SciMemberImpl(Annotation);
SciMemberImpl(Markers);
SciMemberImpl(Text);


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// Editor
//////////////////////////////////////////////////////////////////////////////

Editor::Editor() 
{
	ts_ = 0;
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
	//filename_ = p;

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

	statusBar()->status(50);

	sci = oleObject;

	// get default values from config and init scintilla

	moe()->moeConfig->InitializeEditorFromPreferences( (IMoeDocument*)this );

	SciMember<IScintillAxProperties> props(sci);

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

		props->put_Filename(mol::bstr(p));
	}

	statusBar()->status(80);


	// show the window
	show(SW_SHOW);

	//TODO: user config? just while debugging? UI based?
	SciMember<IScintillAxMarkers>(sci)->put_UseMarkers(VARIANT_TRUE);

	//override read only
	props->put_ReadOnly( readOnly ? VARIANT_TRUE : VARIANT_FALSE );

	// if we have a ribbon, we use our own context menu
	if ( mol::Ribbon::ribbon()->enabled() )
	{
		props->put_UseContext(VARIANT_FALSE);
	}

	statusBar()->status(100);

	// add a windows7 taskbar thumbnail
	thumb = taskbar()->addTab(* this,p );

	// now maximize the window
	maximize();
	OnLayout(0,0,0);

	return true;
}


//////////////////////////////////////////////////////////////////////////////


LRESULT Editor::OnClose()
{
	if ( ts_ )
		return 1;

	VARIANT_BOOL vb;
	SciMember<IScintillAxText>(sci)->get_Modified(&vb);

	if ( vb == VARIANT_TRUE )
	{
		mol::bstr p;
		SciMember<IScintillAxProperties>(sci)->get_Filename(&p);
		mol::ostringstream oss;
		oss << p.toString() << _T(" is modified! \r\n close without save?");
		LRESULT r = ::MessageBox( *this, oss.str().c_str(), _T("document modified!"), MB_ICONEXCLAMATION|MB_OKCANCEL );
		if ( r != IDOK )
		{
			return 1;
		}
	}

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

	ODBGS("Editor::OnDestroy()");
	

}

void Editor::OnNcDestroy()
{

		SciMember<IScintillAxProperties> props(sci);
	mol::bstr path;
	props->get_Filename(&path);

	mol::variant v(path);
	docs()->Remove(v);
	
 	events.UnAdvise(oleObject);
	sci.release();
	ODBGS("Editor::OnNcDestroy()");

	
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
		SciMember<IScintillAxProperties> props(sci);
		mol::bstr path;
		props->get_Filename(&path);

		tab()->select( path.toString() );
		updateUI();
		setFocus();
		thumb.refreshIcon(true);
	}
	return 0;
}

void Editor::OnCut()
{
	if ( !sci )
		return;

	SciMember<IScintillAxSelection>(sci)->Cut();
}

void Editor::OnCopy()
{
	if ( !sci )
		return;

	SciMember<IScintillAxSelection>(sci)->Copy();
}

void Editor::OnPaste()
{
	if ( !sci )
		return;

	SciMember<IScintillAxSelection>(sci)->Paste();
}


void Editor::OnConvertTabs()
{
	if ( !sci )
		return;

	SciMember<IScintillAxProperties>(sci)->ConvertTabs();
}

void Editor::OnEncoding()
{
	if ( !sci )
		return;

	// get chosen lexer id
	int enc = mol::Ribbon::handler(RibbonEncoding)->index();

	SciMember<IScintillAxProperties>(sci)->put_Encoding(enc);

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

	SciMember<IScintillAxProperties>(sci)->put_TabUsage(vb);
}

void Editor::OnTabWidth()
{
	if ( !sci )
		return;

	mol::variant v = mol::Ribbon::handler(RibbonTabSize)->decimal();

	DECIMAL d = v.decVal;
	long w = d.Lo32;

	SciMember<IScintillAxProperties>(sci)->put_TabWidth(w);

}

void Editor::OnTabIndents()
{
	if ( !sci )
		return;

	VARIANT_BOOL vb = mol::Ribbon::handler(RibbonTabIndents)->checked() ? VARIANT_TRUE: VARIANT_FALSE;

	SciMember<IScintillAxProperties>(sci)->put_TabIndents(vb);

}

void Editor::OnBackspaceUnindents()
{
	if ( !sci )
		return;

	VARIANT_BOOL vb = mol::Ribbon::handler(RibbonTabBackSpaceUnIndents)->checked() ? VARIANT_TRUE: VARIANT_FALSE;

	SciMember<IScintillAxProperties>(sci)->put_BackSpaceUnindents(vb);

}

void Editor::OnWriteBOM()
{
	if ( !sci )
		return;

	VARIANT_BOOL vb = mol::Ribbon::handler(RibbonWriteBOM)->checked() ? VARIANT_TRUE: VARIANT_FALSE;

	SciMember<IScintillAxProperties>(sci)->put_WriteBOM(vb);

}


//////////////////////////////////////////////////////////////////////////////

void Editor::OnReload()
{
	if ( !sci )
		return;

	SciMember<IScintillAxProperties> props(sci);
	SciMember<IScintillAxText> txt(sci);

	VARIANT_BOOL vb;
	if ( S_OK != txt->get_Modified(&vb) )
		return ;

	if ( vb == VARIANT_TRUE )
	{
		mol::bstr path;
		props->get_Filename(&path);
		if ( IDYES != ::MessageBox(*this,_T("File is modified.\r\nClose without Save?"), path.toString().c_str() ,MB_YESNO|MB_ICONEXCLAMATION) )
			return ;
	}
	mol::bstr filename;
	if ( S_OK != get_FilePath(&filename) )
	{
		return ;
	}
	if ( S_OK != props->get_ReadOnly(&vb) )
	{
		return ;
	}
	long t;
	if ( S_OK != props->get_Encoding(&t) )
	{
		return ;
	}
	if ( t == SCINTILLA_ENCODING_UTF8 )
	{

		sci->LoadUTF8(filename);
		props->put_ReadOnly(vb);
		statusBar()->status(filename.toString());
		return ;
	}
	sci->Load(filename);
	props->put_ReadOnly(vb);
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
	if ( !sci )
		return;

	SciMember<IScintillAxSelection> sel(sci);
	SciMember<IScintillAxText> txt(sci);

	long len = 0;
	txt->get_Length(&len);

	sel->SetSelection(0,len);
}

void Editor::OnUserCommand(int code, int id, HWND ctrl)
{
	if ( !sci )
		return;

	ISetting* set = shortCutMap[id];
    if ( !set ) 
		return ;

	SciMember<IScintillAxSelection> s(sci);
	SciMember<IScintillAxText> txt(sci);

	long sel;
	if ( S_OK != s->get_Start(&sel) )
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
						
	if ( S_OK != txt->Insert(mol::bstr(tmp),sel) )
		return ;

	if ( pos != std::string::npos )
	{
		s->SetSelection( (long)(sel+pos), (long)(sel+pos));
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
	if ( !sci )
		return;

	SciMember<IScintillAxText> txt(sci);
	SciMember<IScintillAxProperties> props(sci);

	long type;
	if ( S_OK != props->get_Syntax(&type) || type != SCINTILLA_SYNTAX_HTML )
		return ;

	mol::bstr b;
	if ( S_OK != txt->GetText(&b) || b.bstr_ == 0 )
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

	txt->SetText(mol::bstr(os.str()));
}

void Editor::OnSearch(FINDREPLACE* find)
{
	if ( !sci )
		return;

	SciMember<IScintillAxText> txt(sci);

    if ( (find->Flags) & FR_FINDNEXT )
    {
		std::string what( mol::tostring(find->lpstrFindWhat));
		std::string utf8what(mol::ansi2utf8(what));

		VARIANT_BOOL vb;
		txt->Search(mol::bstr(utf8what),find->Flags,&vb);
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
		txt->Replace(mol::bstr(utf8what),mol::bstr(utf8with),find->Flags,&vb);
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
			txt->Replace(mol::bstr(utf8what),mol::bstr(utf8with),find->Flags,&vb);
				
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
	if ( !sci )
		return;

	SciMember<IScintillAxProperties>(sci)->put_SysType(SCINTILLA_SYSTYPE_UNIX);
	statusBar()->status( _T("set EOL type to UNIX (\\n)"));
}


void Editor::OnWin32()
{
	if ( !sci )
		return;

	SciMember<IScintillAxProperties>(sci)->put_SysType(SCINTILLA_SYSTYPE_WIN32);
	statusBar()->status( _T("set EOL type to WIN32 (\\r\\n)"));
}

void Editor::OnSettings()
{
	if ( !sci )
		return;

	mol::punk<IUnknown> unk(oleObject);
	if ( !unk )
		return;

	CAUUID pages;
	mol::punk<ISpecifyPropertyPages> spp(unk);
	if (!spp)
		return;

	if ( S_OK != spp->GetPages(&pages) )
		return;

	SciMember<IScintillAxProperties> props(sci);

	mol::bstr filename;
	if ( S_OK == props->get_Filename(&filename) )
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

	SciMember<IScintillAxProperties> props(sci);
	props->put_Syntax(syntax);

	mol::bstr displayname;
	if ( S_OK == props->GetSyntaxDisplayName(syntax,&displayname) )
	{
		statusBar()->status(displayname.toString());
	}

}


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

void Editor::OnSaveAs()
{
	if ( !sci )
		return;

	long enc;
	mol::bstr p;

	SciMember<IScintillAxProperties> props(sci);

	mol::FilenameDlg ofn(*this);
	ofn.setFilter( OutFilesFilter );		
	if ( S_OK == props->get_Encoding(&enc) )
		ofn.index(enc+1);
	if ( S_OK == props->get_Filename(&p) )
		ofn.fileName(p.toString());

	if ( ofn.dlgSave( OFN_OVERWRITEPROMPT| OFN_NOTESTFILECREATE| OFN_NOVALIDATE) )
	{	
		if ( ofn.fileName() != p.toString() )
		{
			mol::punk<IMoeDocument> doc;
			if ( (S_OK == docs()->Item(mol::variant(ofn.fileName()),&doc)) && doc )
			{
				::MessageBox(*this, _T("File already open in other editor window!"), _T("error"),MB_ICONERROR);
				return ;
			}
		}

		if ( enc != ofn.index()-1 )
			props->put_Encoding(ofn.index()-1);
		if (sci)
		{
			mol::ostringstream oss;

			if ( S_OK == sci->SaveAs( mol::bstr(ofn.fileName() ) ) )
			{
				docs()->Rename( mol::variant(p), mol::variant(ofn.fileName()) );
				props->put_Filename(mol::bstr(ofn.fileName()));

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
	SciMember<IScintillAxProperties>(sci)->get_Filename(&filename);

	mol::ostringstream oss;

	HRESULT hr = sci->Save();
	if ( hr == S_OK )
	{
		oss << _T("saved file ") << filename.toString() ;
	}
	else
	{
		oss << _T("failed to saved file ") << filename.toString() ;
	}

	statusBar()->status(oss.str());
}

void Editor::OnExecForm()
{
	if ( !sci )
		return;

	sci->Save();

	mol::bstr filename;
	SciMember<IScintillAxProperties>(sci)->get_Filename(&filename);
		
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
	if ( !sci )
		return;

	SciMember<IScintillAxProperties> props(sci);

	VARIANT_BOOL vb;
	if ( S_OK != props->get_ShowLineNumbers(&vb) )
		return;

	vb = vb == VARIANT_FALSE ? VARIANT_TRUE : VARIANT_FALSE;
	props->put_ShowLineNumbers(vb);

	mol::Menu mode(mol::UI().SubMenu(IDM_MOE,IDM_MODE));

	if ( vb == VARIANT_TRUE )
		mode.checkItem( IDM_MODE_SHOW_LINE_NUMBERS );
	else
		mode.unCheckItem( IDM_MODE_SHOW_LINE_NUMBERS );
}

void Editor::OnDebugScriptGo()
{
	if ( !sci )
		return;

	debugDlg()->show(SW_HIDE);

	SciMember<IScintillAxProperties> props(sci);
	SciMember<IScintillAxLine> line(sci);
	SciMember<IScintillAxAnnotation> anno(sci);
	SciMember<IScintillAxText> txt(sci);
	SciMember<IScintillAxMarkers> markers(sci);

	line->Highlite(-1);
	anno->ClearAll();

	if ( remote_ )
	{		
		mol::Ribbon::ribbon()->mode(8);
	
		mol::punk<IRemoteDebugApplication> app;

		HRESULT hr = remote_->GetApplication(&app);
		if ( hr == S_OK && app ) 
		{
			hr = app->ResumeFromBreakPoint( remote_, BREAKRESUMEACTION_CONTINUE, ERRORRESUMEACTION_AbortCallAndReturnErrorToCaller );
		}

		remote_.release();
		return;
	}

	if ( ts_ )
	{
		::MessageBox( *moe(), _T("Script running already!"), _T("warning!"), MB_ICONERROR );
		return;
	}

	mol::bstr filename;
	if ( S_OK != props->get_Filename(&filename) )
		return ;

	mol::bstr script;
	if ( S_OK != txt->GetText(&script) )
		return ;

	mol::string engine = engineFromPath(filename.tostring());
	if ( engine == _T("") )
		return ;

	mol::SafeArray<VT_I4> sf;


	std::set<int> s;
	if ( S_OK == markers->GetMarkers(&sf) )
	{
		mol::SFAccess<long> sfa(sf);

		for ( int i = 0; i < sfa.size(); i++ )
		{
			s.insert(sfa[i]);
		}
	}

	ts_ = ThreadScript::CreateInstance( *moe(), script.toString(), filename.toString() );
	ts_->addNamedObject((IMoe*)moe(), _T("moe"));
	ts_->update_breakpoints(s);
	ts_->OnScriptThread = event_handler(&Editor::OnScriptThread,this);
	ts_->OnScriptThreadDone = event_handler(&Editor::OnScriptThreadDone,this);
	ts_->execute( SCRIPTTEXT_ISVISIBLE);

	mol::Ribbon::ribbon()->mode(8);
}


void Editor::OnDebugScriptStepIn()
{
	if ( !sci )
		return;

	SciMember<IScintillAxLine>(sci)->Highlite(-1);
	SciMember<IScintillAxAnnotation>(sci)->ClearAll();

	if ( !remote_)
		return;

	mol::punk<IRemoteDebugApplication> app;

	HRESULT hr = remote_->GetApplication(&app);
	if ( hr == S_OK && app ) 
	{
		hr = app->ResumeFromBreakPoint( remote_, BREAKRESUMEACTION_STEP_INTO, ERRORRESUMEACTION_AbortCallAndReturnErrorToCaller );
	}

	remote_.release();

	mol::Ribbon::ribbon()->mode(9);
}

void Editor::OnDebugScriptStepOver()
{
	if ( !sci )
		return;

	SciMember<IScintillAxLine>(sci)->Highlite(-1);
	SciMember<IScintillAxAnnotation>(sci)->ClearAll();

	if ( !remote_)
		return;

	mol::punk<IRemoteDebugApplication> app;

	HRESULT hr = remote_->GetApplication(&app);
	if ( hr == S_OK && app ) 
	{
		hr = app->ResumeFromBreakPoint( remote_, BREAKRESUMEACTION_STEP_OVER, ERRORRESUMEACTION_AbortCallAndReturnErrorToCaller );
	}

	remote_.release();

	mol::Ribbon::ribbon()->mode(9);
}

void Editor::OnDebugScriptStepOut()
{
	if ( !sci )
		return;

	SciMember<IScintillAxLine>(sci)->Highlite(-1);
	SciMember<IScintillAxAnnotation>(sci)->ClearAll();

	if ( !remote_)
		return;

	mol::punk<IRemoteDebugApplication> app;

	HRESULT hr = remote_->GetApplication(&app);
	if ( hr == S_OK && app ) 
	{
		hr = app->ResumeFromBreakPoint( remote_, BREAKRESUMEACTION_STEP_OUT, ERRORRESUMEACTION_AbortCallAndReturnErrorToCaller );
	}

	remote_.release();

	mol::Ribbon::ribbon()->mode(9);
}

void Editor::OnDebugScriptStop()
{
	if ( !sci )
		return;

	SciMember<IScintillAxLine>(sci)->Highlite(-1);
	SciMember<IScintillAxAnnotation>(sci)->ClearAll();

	if ( !ts_ )
		return;

	ts_->cause_break();

	mol::Ribbon::ribbon()->mode(9);
}

void Editor::OnDebugScriptQuit()
{
	if ( !sci )
		return;

	debugDlg()->show(SW_HIDE);

	SciMember<IScintillAxLine>(sci)->Highlite(-1);

	mol::Ribbon::ribbon()->mode(1);

	if ( !remote_)
		return;


	mol::punk<IRemoteDebugApplication> app;

	HRESULT hr = remote_->GetApplication(&app);
	if ( hr == S_OK && app ) 
	{
		hr = app->ResumeFromBreakPoint( remote_, BREAKRESUMEACTION_ABORT, ERRORRESUMEACTION_AbortCallAndReturnErrorToCaller );
	}

	remote_.release();
}

void Editor::OnScriptThreadDone()
{
	if ( mol::guithread() != mol::Thread::self() )
	{
		mol::invoke( *this, &Editor::OnScriptThreadDone);		
		return;
	}

	debugDlg()->remote.release();
	debugDlg()->show(SW_HIDE);
	ts_ = 0;

	if ( sci)
		SciMember<IScintillAxLine>(sci)->Highlite(-1);

	mol::Ribbon::ribbon()->mode(1);
}

void Editor::OnScriptThread( int line, IRemoteDebugApplicationThread* remote, IActiveScriptError* pError )
{
	if ( mol::guithread() != mol::Thread::self() )
	{
		lasterror_ = _T("");

		// get stack frame
		DebugStackFrameDescriptor	desc;
		::ZeroMemory(&desc,sizeof(DebugStackFrameDescriptor));

		mol::punk<IEnumDebugStackFrames> frames;
		HRESULT hr = remote->EnumStackFrames( &frames );
		if ( S_OK == hr && frames )
		{
			// update variable window
			debugDlg()->update_variables(frames);
		}

		mol::ostringstream oss;
		if ( pError )
		{
			oss << _T("line: ") << (line+1) << _T(" ");

			EXCEPINFO ex;
			pError->GetExceptionInfo(&ex);

			DWORD context;
			ULONG line;
			LONG pos;
			pError->GetSourcePosition(&context,&line,&pos);
		
			mol::punk<IActiveScriptErrorDebug> de(pError);
			if ( de )
			{
				mol::punk<IDebugStackFrame> f;
				de->GetStackFrame(&f);

				if ( f )
				{
					mol::bstr e;
					f->GetDescriptionString(TRUE,&e);

					if ( e )
						oss << e.toString() << std::endl;
				}
			}

			if ( ex.bstrDescription )
			{
				oss << mol::bstr(ex.bstrDescription).toString();
			}
			oss << std::endl;
			lasterror_ = oss.str();
		}

		if ( remote )
			remote->Release();
		if ( pError)
			pError->Release();

		mol::invoke( *this, &Editor::OnScriptThread, line, remote, pError );
		return;
	}

	if ( !sci )
		return;

	ODBGS1("OnScriptThread:",line);

	remote_.release();
	remote_ = remote;

	debugDlg()->remote = remote;
	debugDlg()->show( remote ? SW_SHOW : SW_HIDE );

	SciMember<IScintillAxLine> lines(sci);
	SciMember<IScintillAxAnnotation> anno(sci);

	anno->ClearAll();
	if ( !lasterror_.empty())
	{
		anno->SetText( line, mol::bstr(lasterror_) );
	}

	lines->Goto(line);
	lines->Highlite(line);

	mol::Ribbon::ribbon()->mode(9);
	/*
	std::wostringstream oss;

	if ( pError )
	{
		oss << _T("line: ") << (line+1) << _T(" ");

		EXCEPINFO ex;
		pError->GetExceptionInfo(&ex);

		DWORD context;
		ULONG line;
		LONG pos;
		pError->GetSourcePosition(&context,&line,&pos);
		
		mol::punk<IActiveScriptErrorDebug> de(pError);
		if ( de )
		{
			mol::punk<IDebugStackFrame> f;
			de->GetStackFrame(&f);

			if ( f )
			{
				mol::bstr e;
				f->GetDescriptionString(TRUE,&e);

				if ( e )
					oss << e.toString() << std::endl;
			}
		}

		if ( ex.bstrDescription )
		{
			oss << mol::bstr(ex.bstrDescription).toString();
		}
		oss << std::endl;
		anno->SetText( line, mol::bstr(oss.str()) );
	}

	if ( remote )
		remote->Release();
	if ( pError)
		pError->Release();
		*/
	ODBGS1("Leaving OnScriptThread:",line);
}


void Editor::OnExecScript()
{
	if ( !sci )
		return;

	SciMember<IScintillAxProperties> props(sci);
	SciMember<IScintillAxText> txt(sci);

	mol::bstr filename;
	if ( S_OK != props->get_Filename(&filename) )
		return ;

	mol::string engine = engineFromPath(filename.tostring());
	if ( engine == _T("") )
		return ;

	mol::bstr script;
	if ( S_OK != txt->GetText(&script) )
		return ;

	scriptlet()->eval(engine,script.toString(),sci);
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
	else
	if ( popup == mol::UI().SubMenu(IDM_MOE,IDM_EDIT_DEBUG) )
		createMenuFromConf(frameMenu,popup);
}


//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall Editor::get_FilePath( BSTR *fname)
{
	if ( fname  )
	{
		*fname = 0;
		SciMember<IScintillAxProperties> props(sci);
		mol::bstr path;
		props->get_Filename(&path);
		*fname = ::SysAllocString(path.bstr_);
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
	if ( !This()->sci )
		return S_OK;

	SciMember<IScintillAxPosition> p(This()->sci);
	SciMember<IScintillAxLine> lines(This()->sci);

	mol::ostringstream oss;
	oss << (line+1);

	long pos = 0;
	long linepos = 0;
	p->get_Caret(&pos);
	lines->PosFromLine(line,&linepos);

	long col = pos-linepos;
	mol::ostringstream oss2;
	oss2 << col << " ";

	SciMember<IScintillAxProperties> props(This()->sci);
	mol::bstr path;
	props->get_Filename(&path);

	statusBar()->setText( path.toString(), oss.str(), oss2.str());
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

	SciMember<IScintillAxMarkers> m(This()->sci);
	m->ToggleMarker(line);

	if ( This()->ts_ )
	{

		mol::SafeArray<VT_I4> sf;

		std::set<int> s;
		if ( S_OK == m->GetMarkers(&sf) )
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
	if ( !sci )
	{
		return;
	}

	SciMember<IScintillAxPosition> p(sci);
	SciMember<IScintillAxLine> lines(sci);
	SciMember<IScintillAxProperties> props(sci);

	mol::bstr path;
	HRESULT hr = props->get_Filename(&path);
	if ( hr != S_OK )
		return;

	mol::string title = path.toString();

	long line=0;
	lines->get_Current(&line);
	mol::ostringstream oss;
	oss << line;

	long pos = 0;
	long linepos = 0;
	p->get_Caret(&pos);
	lines->PosFromLine(line-1,&linepos);

	long col = pos-linepos;
	mol::ostringstream oss2;
	oss2 << col << " ";

	statusBar()->setText( path.toString(), oss.str(), oss2.str() );

	long encoding;
	if ( S_OK == props->get_Encoding(&encoding) )
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
				encoding = SCINTILLA_ENCODING_ANSI;
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
	if ( S_OK == props->get_SysType(&systype) )
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
	props->get_Syntax(&type);
	syntax()->setCurSel(type);

	if ( mol::Ribbon::ribbon()->enabled())
	{
		mol::Ribbon::handler(RibbonSelectLanguage)->select(type);
	}

	VARIANT_BOOL vb;
	if ( S_OK == props->get_ReadOnly(&vb) )
	{
		if ( vb == VARIANT_TRUE )
			title += _T(" [ReadOnly]");
	}
	setText(title);


	if ( mol::Ribbon::ribbon()->enabled())
	{
		if ( S_OK == props->get_TabUsage(&vb) )
		{
			mol::Ribbon::handler(RibbonTabUseTabs)->check(vb == VARIANT_TRUE ? true : false );
		}
		if ( S_OK == props->get_TabIndents(&vb) )
		{
			mol::Ribbon::handler(RibbonTabIndents)->check(vb == VARIANT_TRUE ? true : false );
		}
		if ( S_OK == props->get_BackSpaceUnindents(&vb) )
		{
			mol::Ribbon::handler(RibbonTabBackSpaceUnIndents)->check(vb == VARIANT_TRUE ? true : false );
		}
		long w = 0;
		if ( S_OK == props->get_TabWidth(&w) )
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
		if ( S_OK == props->get_WriteBOM(&vb) )
		{
			mol::Ribbon::handler(RibbonWriteBOM)->check(vb == VARIANT_TRUE ? true : false );
		}
	}


	if ( S_OK != props->get_ShowLineNumbers(&vb) )
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

	if ( !sci )
		return;

	SciMember<IScintillAxProperties> props(sci);

	long systype;
	if ( S_OK == props->get_SysType(&systype) )
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
	if ( S_OK == props->get_Encoding(&encoding) )
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

void Editor::updateDebugMenu( HMENU debug )
{
	mol::Menu menu(debug);
	//menu.disableItem(IDM_EDIT_DEBUG_GO);
	menu.disableItem(IDM_EDIT_DEBUG_STEPIN);
	menu.disableItem(IDM_EDIT_DEBUG_STEPOVER);
	menu.disableItem(IDM_EDIT_DEBUG_STEPOUT);
	menu.disableItem(IDM_EDIT_DEBUG_STOP);
	menu.disableItem(IDM_EDIT_DEBUG_QUIT);
	
	if ( remote_ )
	{
		menu.enableItem(IDM_EDIT_DEBUG_STEPIN);
		menu.enableItem(IDM_EDIT_DEBUG_STEPOVER);
		menu.enableItem(IDM_EDIT_DEBUG_STEPOUT);
		menu.enableItem(IDM_EDIT_DEBUG_QUIT);
		return;
	}

	if ( ts_ )
	{
		menu.enableItem(IDM_EDIT_DEBUG_STOP);
		menu.enableItem(IDM_EDIT_DEBUG_QUIT);
		return;
	}
}


void Editor::createMenuFromConf(HMENU menu,HMENU popup)
{

	HMENU frameMenu = mol::UI().Menu(IDM_MOE);

	HMENU tools =   mol::UI().SubMenu(IDM_MOE,IDM_TOOLS);
	mol::Menu mode (mol::UI().SubMenu(IDM_MOE,IDM_MODE_EOL));
	mol::Menu debug(mol::UI().SubMenu(IDM_MOE,IDM_EDIT_DEBUG));

	if ( popup == mode )
	{
		updateModeMenu(mode);
		return;
	}

	if ( popup == debug )
	{
		updateDebugMenu(debug);
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

