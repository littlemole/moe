#include "stdafx.h"
#include "moe.h"
#include "moewnd.h"
#include "app.h"
#include "dir.h"
#include "img.h"
#include "hex.h"
#include "html.h"
#include "editor.h"
#include "ole.h"

using namespace mol::io;

static int MoeWndOleCmds[] = 
{
	OLECMDID_NEW,		IDM_FILE_NEW,
	OLECMDID_OPEN,		IDM_FILE_OPEN
};

// for open/file dialog: filefilters

mol::TCHAR  InFilesFilter[]   = _T("open text files *.*\0*.*\0open UTF-8 text files *.*\0*.*\0open HTML files *.*\0*.*\0open file in hexviewer *.*\0*.*\0\0");

// static counter to generate somewhat unique formnames
int MoeWndImpl::form_cnt_ = 0;

//////////////////////////////////////////////////////////////////////////////
//
// Message Map - connects Messages to OnMsg-Handlers
//
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//
// MoeWnd Constructor - prepare Frame window object
// note children are constructed in OnCreate()
//
//////////////////////////////////////////////////////////////////////////////

MoeWndImpl::MoeWndImpl(MoeWnd* mwnd) 
{
	moeWnd_ = mwnd;
    eraseBackground_ = 1;
    setFirstChildId(ID_FIRST_CHILD_WND);	
	icon_.load(IDI_MOE);
	wndClass().setIcon(icon_);	
}

//////////////////////////////////////////////////////////////////////////////
//
// Framewindow Destructor
//
//////////////////////////////////////////////////////////////////////////////

MoeWndImpl::~MoeWndImpl()
{
	ODBGS("~MoeWndImpl down the sink");
}

//////////////////////////////////////////////////////////////////////////////
//
// OnCreate - init child Windows and UI
//
//////////////////////////////////////////////////////////////////////////////

LRESULT MoeWndImpl::OnCreate(UINT msg, WPARAM wParam, LPARAM lParam)
{
	BorderLayout* layout = setLayout(new BorderLayout);

	// tree window
	treeWnd_.create( IDC_TREE_VIEW,Rect(0,0,160,200),(HWND)*this);
	treeWnd_.show(SW_SHOW);
	layout->add(treeWnd_, BorderLayout::WEST);
	treeSink.Advise(treeWnd_.oleObject);

	//create toolbars
	initToolbars(layout);

	//status bar
	statusBar_.create( IDC_STATUS,stdRect,*this);
	statusBar_.setText(_T("moe says: Scintilla rulez!"));
	layout->addStatusBar(&statusBar_);

	// prepare MDI Client Workbench
	layout->add(mdiClient(),BorderLayout::FILL);

	// register drag drop
	::RegisterDragDrop(*this,&Drop);

	HMENU menu = ::GetMenu(*this);
	this->addFileMenu(::GetSubMenu(menu, 0),"&File");
	//this->addFileMenu(::GetSubMenu(menu, 1),"&Preferences");
	this->addWindowMenu(::GetSubMenu(menu, 1),"&Window");
	this->addHelpMenu(::GetSubMenu(menu, 2),"&Help");

	this->addOlExecHandler(OLECMDID_NEW,IDM_FILE_NEW);
	this->addOlExecHandler(OLECMDID_OPEN,IDM_FILE_OPEN);

    return 0;
}

void MoeWndImpl::initToolbars(BorderLayout* layout)
{
	reBar_.create( IDC_REBAR, Rect(0,0,200,300), *this);

	// open close toolbar
	int id = 0;
	toolBars_[id].create( IDM_TOOLBARS_FILEBAR, Rect(0,0,90,24), reBar_); //24 instead of 48
	//fileBar_.setStd();
	toolBars_[id].setBmp(IDB_TOOLBAR,38,16,16);
	toolBars_[id].setButtonSize(16,16);

	toolBars_[id].addButton(0,IDM_FILE_NEW,_T("new file"));
	toolBars_[id].addButton(1,IDM_FILE_OPEN,_T("open file"));
	toolBars_[id].addButton(4,IDM_FILE_SAVE_AS,_T("save as"));
	toolBars_[id].addButton(3,IDM_FILE_SAVE,_T("save file"));

	toolBars_[id].addButtons();

	toolBars_[id].addButton(35,IDM_VIEW_DIRVIEW, _T("toggle dirview"));
	toolBars_[id].addButton(2,IDM_FILE_OPENDIR,_T("open directory"));
	toolBars_[id].addButton(5,IDM_FILE_PRINT,_T("print"));
	toolBars_[id].addButton(6,IDM_FILE_EXIT,_T("exit"));

	toolBars_[id].setButtonSize(16,16);

	id = 1;
	toolBars_[id].create( IDM_TOOLBARS_EDITBAR, Rect(0,0,32,24), reBar_);
	toolBars_[id].setBmp(IDB_TOOLBAR,38,16,16);
	toolBars_[id].setButtonSize(24,22);

	toolBars_[id].addButton(7,IDM_EDIT_UNDO,_T("undo"));
	toolBars_[id].addButtons();

	toolBars_[id].addButton(8,IDM_EDIT_REDO,_T("redo"));
	toolBars_[id].addButton(9,IDM_EDIT_CUT,_T("cut"));
	toolBars_[id].addButton(10,IDM_EDIT_COPY,_T("copy"));
	toolBars_[id].addButton(11,IDM_EDIT_PASTE,_T("paste"));
	toolBars_[id].addButton(12,IDM_EDIT_FIND,_T("find"));
	toolBars_[id].addButton(13,IDM_EDIT_REPLACE,_T("replace"));
	

	id = 2;
	toolBars_[id].create( IDM_TOOLBARS_TOOLBAR, Rect(0,0,32,24), reBar_);
	toolBars_[id].setBmp(IDB_TOOLBAR,38,16,16);
	toolBars_[id].setButtonSize(24,22);

	toolBars_[id].addButton(20,IDM_EDIT_COLOR,_T("insert color"));
	toolBars_[id].addButton(14,IDM_EDIT_EXECUTESCRIPT,_T("exec script"));
	toolBars_[id].addButton(19,IDM_USER_SHORTCUT,_T("shortcut"),TBSTATE_ENABLED,BTNS_DROPDOWN);

	toolBars_[id].addButtons();

	toolBars_[id].addButton(15,IDM_MODE_EXECUTEFORM,_T("exec form"));
	toolBars_[id].addButton(16,IDM_USER_SCRIPT,_T("user script"),TBSTATE_ENABLED,BTNS_DROPDOWN);
	toolBars_[id].addButton(17,IDM_USER_BATCH,_T("user batch"),TBSTATE_ENABLED,BTNS_DROPDOWN);
	toolBars_[id].addButton(18,IDM_USER_FORM,_T("user form"),TBSTATE_ENABLED,BTNS_DROPDOWN);

	id = 3;
	toolBars_[id].create( IDM_TOOLBARS_SETTINGBAR, Rect(0,0,64,24), reBar_);
	toolBars_[id].setBmp(IDB_TOOLBAR,38,16,16);
	toolBars_[id].setButtonSize(24,22);

	toolBars_[id].addButton(21,IDM_SETTINGS_MODE,_T("mode"),TBSTATE_ENABLED,BTNS_DROPDOWN );
	toolBars_[id].addButtons();

	toolBars_[id].addButton(22,IDM_SETTINGS_LANG,_T("language"),TBSTATE_ENABLED,BTNS_DROPDOWN);
	toolBars_[id].addButton(23,IDM_MODE_SETTINGS,_T("document settings"));
	toolBars_[id].addButton(24,IDM_MODE_PREFERENCES,_T("preferences"));
	toolBars_[id].addButton(25,IDM_MODE_EDITSETTINGS,_T("user settings"));


	id = 4;
	toolBars_[id].create( IDM_TOOLBARS_VIEWBAR, Rect(0,0,100,24), reBar_);
	toolBars_[id].setBmp(IDB_TOOLBAR,38,16,16);
	toolBars_[id].setButtonSize(24,22);

	toolBars_[id].addButton(28,IDM_VIEW_MAXIMIZE,_T("maximize"));
	toolBars_[id].addButton(29,IDM_VIEW_MINIMIZE,_T("minimize"));
	toolBars_[id].addButton(30,IDM_VIEW_CASCADE,_T("cascade"));
	toolBars_[id].addButton(31,IDM_VIEW_TILE,_T("tile"));
	toolBars_[id].addButtons();
	toolBars_[id].addButton(33,IDM_VIEW_NEXT,_T("next window"));
	toolBars_[id].addButton(34,IDM_VIEW_CLOSE,_T("close window"));

	id = 5;
	toolBars_[id].create( IDM_TOOLBARS_USERBAR, Rect(0,0,100,24), reBar_);
	toolBars_[id].setBmp(IDB_TOOLBAR,38,16,16);
	toolBars_[id].setButtonSize(24,22);

	toolBars_[id].addButton(37,IDM_HELP_ABOUT,_T("about"));
	toolBars_[id].addButtons();

	toolBars_[id].addButton(0,IDM_FILE_NEW,_T("new file"));
	toolBars_[id].addButton(1,IDM_FILE_OPEN,_T("open file"));
	toolBars_[id].addButton(4,IDM_FILE_SAVE_AS,_T("save as"));
	toolBars_[id].addButton(35,IDM_VIEW_DIRVIEW, _T("toggle dirview"));
	toolBars_[id].addButton(2,IDM_FILE_OPENDIR,_T("open directory"));
	toolBars_[id].addButton(3,IDM_FILE_SAVE,_T("save file"));
	toolBars_[id].addButton(5,IDM_FILE_PRINT,_T("print"));
	toolBars_[id].addButton(6,IDM_FILE_EXIT,_T("exit"));

	toolBars_[id].addButton(7,IDM_EDIT_UNDO,_T("undo"));
	toolBars_[id].addButton(8,IDM_EDIT_REDO,_T("redo"));
	toolBars_[id].addButton(9,IDM_EDIT_CUT,_T("cut"));
	toolBars_[id].addButton(10,IDM_EDIT_COPY,_T("copy"));
	toolBars_[id].addButton(11,IDM_EDIT_PASTE,_T("paste"));
	toolBars_[id].addButton(12,IDM_EDIT_FIND,_T("find"));
	toolBars_[id].addButton(13,IDM_EDIT_REPLACE,_T("replace"));

	toolBars_[id].addButton(20,IDM_EDIT_COLOR,_T("insert color"));
	toolBars_[id].addButton(14,IDM_EDIT_EXECUTESCRIPT,_T("exec script"));
	toolBars_[id].addButton(15,IDM_MODE_EXECUTEFORM,_T("exec form"));
	toolBars_[id].addButton(16,IDM_USER_SCRIPT,_T("user script"),TBSTATE_ENABLED,BTNS_DROPDOWN);
	toolBars_[id].addButton(17,IDM_USER_BATCH,_T("user batch"),TBSTATE_ENABLED,BTNS_DROPDOWN);
	toolBars_[id].addButton(18,IDM_USER_FORM,_T("user form"),TBSTATE_ENABLED,BTNS_DROPDOWN);
	toolBars_[id].addButton(19,IDM_USER_SHORTCUT,_T("shortcut"),TBSTATE_ENABLED,BTNS_DROPDOWN);

	toolBars_[id].addButton(21,IDM_SETTINGS_MODE,_T("mode"),TBSTATE_ENABLED,BTNS_DROPDOWN );
	toolBars_[id].addButton(22,IDM_SETTINGS_LANG,_T("language"),TBSTATE_ENABLED,BTNS_DROPDOWN);
	toolBars_[id].addButtons();

	toolBars_[id].addButton(23,IDM_MODE_SETTINGS,_T("document settings"));
	toolBars_[id].addButton(24,IDM_MODE_PREFERENCES,_T("preferences"));
	toolBars_[id].addButton(25,IDM_MODE_EDITSETTINGS,_T("user settings"));

	toolBars_[id].addButton(28,IDM_VIEW_MAXIMIZE,_T("maximize"));
	toolBars_[id].addButton(29,IDM_VIEW_MINIMIZE,_T("minimize"));
	toolBars_[id].addButton(30,IDM_VIEW_CASCADE,_T("cascade"));
	toolBars_[id].addButton(31,IDM_VIEW_TILE,_T("tile"));
	toolBars_[id].addButton(33,IDM_VIEW_NEXT,_T("next window"));
	toolBars_[id].addButton(34,IDM_VIEW_CLOSE,_T("close window"));

	reBar_.addBar( toolBars_[0],IDM_TOOLBARS_FILEBAR,32,_T(""));
	reBar_.addBar( toolBars_[1],IDM_TOOLBARS_EDITBAR,32,_T(""));
	reBar_.addBar( toolBars_[2],IDM_TOOLBARS_TOOLBAR,32,_T(""));
	reBar_.addBar( toolBars_[3],IDM_TOOLBARS_SETTINGBAR,32,_T(""));
	reBar_.addBar( toolBars_[4],IDM_TOOLBARS_VIEWBAR,32,_T(""));
	reBar_.showBar(IDM_TOOLBARS_VIEWBAR,false);
	reBar_.addBar( toolBars_[5],IDM_TOOLBARS_USERBAR,32,_T(""));
	reBar_.showBar(IDM_TOOLBARS_USERBAR,false);

    // view switch toolbar
    tabCtrl_.create( IDC_TAB_CTRL, Rect(0,0,64,26),*this);
	reBar_.addBar( tabCtrl_,IDC_TAB_CTRL, 80);

	// syntax cobox
	syntaxBox_.create( IDC_SYNTAX_BOX, Rect(0,0,44,10*24), *this );
	syntaxBox_.addString( "txt" );
	syntaxBox_.addString( "html" );
	syntaxBox_.addString( "css" );
	syntaxBox_.addString( "vb" );
	syntaxBox_.addString( "js" );
	syntaxBox_.addString( "sql" );
	syntaxBox_.addString( "shell" );
	syntaxBox_.addString( "perl" );
	syntaxBox_.addString( "c++" );
	syntaxBox_.addString( "java" );
	syntaxBox_.addString( "c#" );
	syntaxBox_.setCurSel(0);
	reBar_.addBar( syntaxBox_,IDC_SYNTAX_BOX, 80);

	static MoeApp& a = app<MoeApp>();
	mol::string p(a.appPath + "\\" + "ui.xmo");

	if ( mol::Path::exists(p) )
	{
		punk<IPersistFile> pf(moeWnd_);
		pf->Load( mol::towstring(p).c_str(),FALSE );
	}

	layout->addRebar(&reBar_);
}
//////////////////////////////////////////////////////////////////////////////
//
// OnDestroy - over and out
//
//////////////////////////////////////////////////////////////////////////////

LRESULT MoeWndImpl::OnClose(UINT msg, WPARAM wParam, LPARAM lParam)
{
	treeSink.UnAdvise(treeWnd_.oleObject);
	::CoDisconnectObject(treeWnd_.oleObject,0);
	moeWnd_->Exit();
    return 0;
}

LRESULT MoeWndImpl::OnNcDestroy(UINT msg, WPARAM wParam, LPARAM lParam)
{
	::RevokeDragDrop(*this);
	punk<IDocs> docs;
	if ( (S_OK == moeWnd_->get_Docs(&docs)) && docs )
	{
		::CoDisconnectObject(docs,0);
	}
	::CoDisconnectObject(((IXmoe*)moeWnd_),0);
	((IXmoe*)moeWnd_)->Release();
	::PostQuitMessage(0);
    return 0;
}
//////////////////////////////////////////////////////////////////////////////
//
// User selected Exit from main Menu - kill app
//
//////////////////////////////////////////////////////////////////////////////

LRESULT MoeWndImpl::OnFileExit(UINT msg, WPARAM wParam, LPARAM lParam)
{
	moeWnd_->Exit();
    return 0;
}
//////////////////////////////////////////////////////////////////////////////
//
//
//////////////////////////////////////////////////////////////////////////////

LRESULT MoeWndImpl::OnMDIActivate(UINT msg, WPARAM wParam, LPARAM lParam)
{
	HWND newWnd = (HWND)lParam;
    int i = index(newWnd);
    tabCtrl_.select(i);
	return BASE::wndProc(*this,msg,wParam,lParam);
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
//
//////////////////////////////////////////////////////////////////////////////

LRESULT MoeWndImpl::OnDispatch(UINT msg, WPARAM wParam, LPARAM lParam)
{
	if ( treeWnd_.hasFocus() )
	{
		treeWnd_.postMessage(msg,wParam,lParam);
		return 0;
	}
    ::PostMessage(getActive(),msg,wParam,lParam);
    return 0;
}

LRESULT MoeWndImpl::OnSyntax(UINT msg, WPARAM wParam, LPARAM lParam)
{
	if ( HIWORD(wParam) == CBN_SELCHANGE )
	{
		int sel = syntaxBox_.getCurSel();
		::PostMessage(getActive(),WM_COMMAND,IDM_LEXER_PLAIN+sel,lParam);
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// Create new child window
//
//////////////////////////////////////////////////////////////////////////////

LRESULT MoeWndImpl::OnFileNew(UINT msg, WPARAM wParam, LPARAM lParam)
{
	moeWnd_->New(0);
    return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// Open from file and Create new child window 
//
//////////////////////////////////////////////////////////////////////////////

LRESULT MoeWndImpl::OnFileOpen(UINT msg, WPARAM wParam, LPARAM lParam)
{
	FilenameDlg ofn(*this);
	ofn.setFilter( InFilesFilter );			

	if ( ofn.dlgOpen( OFN_NOVALIDATE | OFN_ALLOWMULTISELECT | OFN_EXPLORER ) )
	{
		// open html
		if ( ofn.index() == 3 )
		{
			for ( int i = 0; i < ofn.selections(); i++ )
				openPathHtml(ofn.fileName(i),0);
		}
		// open hex
		else if ( ofn.index() == 4 )
		{
			for ( int i = 0; i < ofn.selections(); i++ )
				openPathHex( ofn.fileName(i), ofn.readOnly(),0);
		}
		// open text
		else
		{
			for ( int i = 0; i < ofn.selections(); i++ )
				openPath( ofn.fileName(i), ofn.index() == 1 ? false : true, ofn.readOnly(),0);
		}
	}	
    return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// Open new Dir from folder browser
//
//////////////////////////////////////////////////////////////////////////////

LRESULT MoeWndImpl::OnFileOpenDir(UINT msg, WPARAM wParam, LPARAM lParam)
{
	bstr d;
	if ( S_OK == moeWnd_->ChooseDir(&d) && d)
	{
		mol::string s = d.toString();
		if ( s != "" )
		{
			if ( mol::Path::exists(s) )
				moeWnd_->OpenDir(d,0);
		}

	}
    return 0;
}


LRESULT MoeWndImpl::OnFileOpenHex(UINT msg, WPARAM wParam, LPARAM lParam)
{
	mol::FilenameDlg dlg(*this);
	
	if ( dlg.dlgOpen(OFN_READONLY|OFN_EXPLORER) )
	{
		this->openPathHex( dlg.fileName(), dlg.readOnly(), 0 );
	}

    return 0;
}


LRESULT MoeWndImpl::OnFileOpenHtml(UINT msg, WPARAM wParam, LPARAM lParam)
{	
	if ( IDOK == urlDlg_.doModal( IDD_DIALOG_URL, *this ) )
	{
		if ( !urlDlg_.url.empty() )
			openPathHtml( urlDlg_.url,0 );
	}

    return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
//
//////////////////////////////////////////////////////////////////////////////

LRESULT MoeWndImpl::OnEditCut(UINT msg, WPARAM wParam, LPARAM lParam)
{
	if ( treeWnd_.hasFocus() )
	{
		punk<IShellTree> tree(treeWnd_.oleObject);
		if ( tree )
		{
			tree->Cut();
		}
		return 0;
	}
    ::PostMessage(getActive(),msg,wParam,lParam);
	return 0;
}

//////////////////////////////////////////////////////////////////////////////

LRESULT MoeWndImpl::OnEditCopy(UINT msg, WPARAM wParam, LPARAM lParam)
{
	if ( treeWnd_.hasFocus() )
	{
		punk<IShellTree> tree(treeWnd_.oleObject);
		if ( tree )
		{
			tree->Copy();
		}
		return 0;
	}
    ::PostMessage(getActive(),msg,wParam,lParam);
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
LRESULT MoeWndImpl::OnEditPaste(UINT msg, WPARAM wParam, LPARAM lParam)
{
	if ( treeWnd_.hasFocus() )
	{
		punk<IShellTree> tree(treeWnd_.oleObject);
		if ( tree )
		{
			tree->Paste();
		}
		return 0;
	}
    ::PostMessage(getActive(),msg,wParam,lParam);
	return 0;
}
//////////////////////////////////////////////////////////////////////////////
//
// Cancel
//
//////////////////////////////////////////////////////////////////////////////

LRESULT MoeWndImpl::OnEditSettings(UINT msg, WPARAM wParam, LPARAM lParam)
{
	moeWnd_->Settings();
    return 0;
}

LRESULT MoeWndImpl::OnEditPrefs(UINT msg, WPARAM wParam, LPARAM lParam)
{
	moeWnd_->Preferences();

	return 0;
}

LRESULT MoeWndImpl::OnExecForm(UINT msg, WPARAM wParam, LPARAM lParam)
{
	punk<IDoc> doc;
	if ( S_OK != moeWnd_->get_ActiveDoc(&doc) )
		return 0;
	if ( !doc )
		return 0;

	punk<IDispatch> disp;	
	if ( S_OK != doc->get_Document(&disp) )
		return 0;

	punk<IScintillAx> sci(disp);
	if ( !sci )
		return 0;

	if ( sci )
	{
		sci->Save();
		bstr filename;
		if ( S_OK != sci->get_Filename(&filename) )
		{
			return 0;
		}
		
		RECT r;
		this->getWindowRect(r);

		moeWnd_->ShowForm( 
					filename, 
					r.left+50,
					r.top+50,
					r.right-r.left-100,
					r.bottom-r.top-100,
					1
		);
	}
	return 0;
}

/*
LRESULT MoeWndImpl::OnExecNet(UINT msg, WPARAM wParam, LPARAM lParam)
{
	punk<IDoc> doc;
	if ( S_OK != moeWnd_->get_ActiveDoc(&doc) )
		return 0;
	if ( !doc )
		return 0;

	long type;
	if ( S_OK == doc->get_Type(&type) )
	{
		if ( type == XMOE_DOCTYPE_DOC )
		{
			punk<IScintillAx> sci;
			if ( S_OK == doc->get_Document(&sci) )
			{
				bstr script;
				if ( S_OK == sci->GetText(&script) )
				{
					if ( script )
					{
//						moeWnd_->dotScript(script);
					}
				}
			}
		}
	}	
	return 0;
}
*/

LRESULT MoeWndImpl::OnExecScript(UINT msg, WPARAM wParam, LPARAM lParam)
{
	punk<IDoc> doc;
	if ( S_OK != moeWnd_->get_ActiveDoc(&doc) )
		return 0;
	if ( !doc )
		return 0;

	bstr filename;
	if ( S_OK != doc->get_Filename(&filename) )
	{
		return 0;
	}

	mol::string p(filename.toString());
	mol::string engine = engineFromExtension(mol::Path::ext(p));
	if ( engine == _T("") )
	{
		if ( mol::Path::ext(p) == ".cs" )
			engine = _T("cs");
		else
			return 0;
	}

	long type;
	if ( S_OK == doc->get_Type(&type) )
	{
		if ( type == XMOE_DOCTYPE_DOC )
		{
			punk<IDispatch> disp;
			if ( S_OK == doc->get_Document(&disp) )
			{
				punk<IScintillAx> sci(disp);

				if (sci)
				{
					bstr script;
					if ( S_OK == sci->GetText(&script) )
					{
						if ( script )
						{
							moeWnd_->Eval(script, bstr(engine) );
						}
					}
				}
			}
		}
	}
    return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// show/hide Tree View
//
//////////////////////////////////////////////////////////////////////////////


LRESULT MoeWndImpl::OnShowDirView (UINT msg, WPARAM wParam, LPARAM lParam)
{
	Menu m(*this);
	if ( !treeWnd_.isVisible() )
	{
		treeWnd_.show(SW_SHOW);
		::InvalidateRect(mdiClient(),0,TRUE);
	}
	else
	{
		treeWnd_.show(SW_HIDE);
	}
	OnLayout(0,0,0);
	
	return 0;
}

LRESULT MoeWndImpl::OnShowToolBar (UINT msg, WPARAM wParam, LPARAM lParam)
{
	Crack Msg(msg,wParam,lParam);
	Menu m(*this);
	switch(Msg.id())
	{
		case IDM_TOOLBARS_DIRVIEW :
		{
			if ( !treeWnd_.isVisible() )
			{
				treeWnd_.show(SW_SHOW);
				::InvalidateRect(mdiClient(),0,TRUE);
			}
			else
			{
				treeWnd_.show(SW_HIDE);
			}			
			break;
		}
		case IDM_TOOLBARS_FILEBAR    :
		case IDM_TOOLBARS_EDITBAR    :
		case IDM_TOOLBARS_TOOLBAR    :
		case IDM_TOOLBARS_SETTINGBAR :
		case IDM_TOOLBARS_VIEWBAR    :
		case IDM_TOOLBARS_USERBAR    :
		{
			bool isVisible = toolBars_[Msg.id()-IDM_TOOLBARS_FILEBAR].isVisible() != 0; //reBar_.isBandVisible(Msg.id());
			if ( isVisible )
			{
				reBar_.showBar( Msg.id(), false );
			}
			else
			{
				reBar_.showBar( Msg.id(), true );
			}
			break;
		}
	}
	OnLayout(0,0,0);
	return 0;
}

LRESULT MoeWndImpl::OnFreezeToolBar (UINT msg, WPARAM wParam, LPARAM lParam)
{
	Crack Msg(msg,wParam,lParam);
	if ( toolBarFrozen_ )
	{
		toolBarFrozen_ = 0;
		reBar_.freeze(false);
	}
	else
	{
		toolBarFrozen_ = 1;
		reBar_.freeze(true);
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////////
//
// TabControl Events
//
//////////////////////////////////////////////////////////////////////////////

LRESULT MoeWndImpl::OnTabCtrl(UINT msg, WPARAM wParam, LPARAM lParam)
{
   Crack message(msg,wParam,lParam);

    if ( message.nmhdr()->code  == TCN_SELCHANGE )
    {
        int sel = tabCtrl_.selection();
        MdiChild* mdc = wndFromHWND<MdiChild>(childAt(sel));
		if (mdc)
			mdc->activate();
        return 0;
    }		

    if ( message.nmhdr()->code  == NM_RCLICK   )
    {
		int i = tabCtrl_.hitTest();
		if ( i == -1 )
			return 0;

		variant v;
		if ( S_OK != moeWnd_->docs()->collection.Item(variant(i),&v) || ( v.vt==VT_EMPTY) )
			return 0;

		long t;
		punk<IDoc> doc(v.pdispVal);
		if ( !doc || (S_OK != doc->get_Type(&t) ) )
			return 0;

		mol::Menu menu;
		menu.load(IDR_MENU_TAB);
		mol::Menu sub(menu.getSubMenu(0));

		if ( t != XMOE_DOCTYPE_HTML )
		{
			sub.remove(ID_TAB_RELOADTAB,MF_BYCOMMAND );
			sub.remove(2,MF_BYPOSITION); // remove seperator, too
		}

		POINT pt;
		::GetCursorPos(&pt);
		int id = sub.returnTrackPopup(*this,pt.x-10,pt.y-10);
		switch ( id )
		{
			case ID_TAB_CLOSETAB:
			{
				::PostMessage( childAt(i), WM_CLOSE, 0, 0 );
				break;
			}
			case ID_TAB_CLOSEALLBUTTHIS:
			{
				for ( int c = 0; c < count(); c++ )
				{
					if ( c != i )
						::PostMessage( childAt(c), WM_CLOSE, 0, 0 );
				}
				break;
			}
			case ID_TAB_RELOADTAB:
			{
				::PostMessage( childAt(i), WM_COMMAND, IDM_EDIT_UPDATE, 0 );
				break;
			}
		}
		return 0;
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////////
//
// OnHelpAbout - show help dialog
//
//////////////////////////////////////////////////////////////////////////////

LRESULT MoeWndImpl::OnHelpAbout(UINT msg, WPARAM wParam, LPARAM lParam)
{
	moeWnd_->Help();
    return 0;
}


LRESULT MoeWndImpl::OnFx(UINT msg, WPARAM wParam, LPARAM lParam)
{
	Crack message(msg,wParam,lParam);
	int fx = message.id()-ID_F1+1;

	static MoeApp& a = app<MoeApp>();

	std::ostringstream oss;
	oss << mol::tostring(mol::Path::pathname(a.prefPath)) 
		<< "\\fx\\F" 
		<< fx 
		<< ".js";

	mol::string p(oss.str());

	if ( !mol::Path::exists(p) )
	{
		std::ostringstream oss;
		oss << mol::tostring(mol::Path::pathname(a.getModulePath())) 
			<< "\\fx\\F" 
			<< fx 
			<< ".js";

		p = oss.str();

		if ( !mol::Path::exists(p) )
		{
			return 0;
		}
	}
	
	mol::filestream fs;
	if ( fs.open(p) )
	{
		mol::string src = fs.readAll();
		moeWnd_->Eval(bstr(src),bstr(L"javascript"));
	}
    return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// update UI - redraw menues
//
//////////////////////////////////////////////////////////////////////////////

LRESULT MoeWndImpl::OnMenu(UINT msg, WPARAM wParam, LPARAM lParam)
{
	Menu m( (HMENU)wParam );

	if ( !NET().aware() )
		m.disableItem(IDM_TOOLS_EXECUTE_NET);

	if ( !treeWnd_.isVisible() )
		m.unCheckItem(IDM_VIEW_DIRVIEW );
	else
		m.checkItem(IDM_VIEW_DIRVIEW);

	for ( int i = IDM_TOOLBARS_FILEBAR; i <= IDM_TOOLBARS_USERBAR; i++ )
	{
		if ( toolBars_[i-IDM_TOOLBARS_FILEBAR].isVisible() )
		{
			m.checkItem( i );
		}
		else
		{
			m.unCheckItem( i );
		}
	}

	if ( toolBarFrozen_ )
		m.checkItem(IDM_TOOLBARS_FREEZE);
	else
		m.unCheckItem(IDM_TOOLBARS_FREEZE);

	::SendMessage(getActive(),msg,wParam,lParam);

	return 0;
}


LRESULT MoeWndImpl::OnFind(UINT msg, WPARAM wParam, LPARAM lParam)
{
    searchDlg_.findText(*this);
	return 0;
}

LRESULT MoeWndImpl::OnReplace(UINT msg, WPARAM wParam, LPARAM lParam)
{
    searchDlg_.replaceText(*this);
	return 0;
}

//////////////////////////////////////////////////////////////////////////////

LRESULT MoeWndImpl::OnUserBatch(UINT msg, WPARAM wParam, LPARAM lParam)
{
    static MoeApp& a = app<MoeApp>();
    Crack Msg(msg,wParam,lParam);

	ISetting* set = a.batchMap[Msg.lo()];
    if ( !set )
		return 0;

    bstr val;
	if ( S_OK != set->get_Value(&val) || !val.bstr_ )
		return 0;

	exec_cmdline( val.toString() );
	return 0;
}

//////////////////////////////////////////////////////////////////////////////

LRESULT MoeWndImpl::OnUserForm(UINT msg, WPARAM wParam, LPARAM lParam)
{
    static MoeApp& a = app<MoeApp>();
    Crack Msg(msg,wParam,lParam);

	ISetting* set = a.formMap[Msg.lo()];
    if ( !set )
		return 0;

    bstr val;
	if ( S_OK != set->get_Value(&val) || !val.bstr_ )
		return 0;

	mol::string path = val.toString();
	mol::string file = path;
	RECT r;
	this->getWindowRect(r);

	int l = r.left+50;
	int t = r.top+50;
	int w = r.right-r.left-100;
	int h = r.bottom-r.top-100;
	int o = 2;

	int p = path.find(",");
	if ( p != mol::string::npos )
	{
		file = path.substr(0,p);
		int pos = 0;
		if ( (pos = path.find(",",p+1)) != mol::string::npos )
		{
			l = l + atoi( mol::tostring( path.substr(p+1,pos-p-1) ).c_str() );
			p = pos;
			if ( (pos = path.find(",",p+1)) != mol::string::npos )
			{
				t = t + atoi( mol::tostring( path.substr(p+1,pos-p-1) ).c_str() );
				p = pos;
				if ( (pos = path.find(",",p+1)) != mol::string::npos )
				{
					if ( pos-p-1 > 0)
						w = atoi( mol::tostring( path.substr(p+1,pos-p-1) ).c_str() );
					p = pos;
					if ( (pos = path.find(",",p+1)) != mol::string::npos )
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

	moeWnd_->ShowForm( bstr(file), l, t, w, h, o );
	return 0;
}

LRESULT MoeWndImpl::OnUserScript(UINT msg, WPARAM wParam, LPARAM lParam)
{
    static MoeApp& a = app<MoeApp>();
    Crack Msg(msg,wParam,lParam);

	ISetting* set = a.scriptMap[Msg.lo()];
    if ( !set )
		return 0;

    bstr val;
	if ( S_OK != set->get_Value(&val) || !val.bstr_ )
		return 0;

	mol::string file = _T("");
	mol::string func = _T("");

	mol::string tmp = mol::toString(val);
	unsigned int pos = tmp.find(_T("!"));
	if ( pos != std::string::npos)
	{
		file   = tmp.substr(0,pos);
		func   = tmp.substr(pos+1);
	}
	else
		file = tmp;

	mol::string ext = mol::Path::ext(file);
	if ( mol::cistring(ext.c_str()) == _T(".bat") )
	{
		execute_shell( file );
		return 0;
	}
	mol::string engine = engineFromExtension(ext);
	if ( engine == _T("") )
	{
		if ( ext == ".cs" )
			engine = _T("cs");
		else
			return 0;
	}

	std::ifstream in;
	in.open(mol::tostring(file).c_str());
	if ( !in )
	{
		std::string p = a.getAppPath();
		p = mol::Path::pathname(p) + "\\" + mol::tostring(file).c_str();
		in.clear();
		in.open(p.c_str());
		if ( !in )
		  return 0;
	}

	std::string script;
	std::string line;
	while ( std::getline( in, line ) )
	{
		script += line;
	}
	in.close();

	ScriptingHost scriptlet = new Script;
	scriptlet->call( engine,func,mol::toString(script));

	return 0;

}


LRESULT MoeWndImpl::OnToolbarRightClick(UINT msg, WPARAM wParam, LPARAM lParam)
{
	if ( toolBarFrozen_ )
		return 0;

	Crack Msg(msg,wParam,lParam);
	switch ( Msg.nmhdr()->idFrom )
	{
		case IDM_TOOLBARS_FILEBAR    :
		case IDM_TOOLBARS_EDITBAR    :
		case IDM_TOOLBARS_TOOLBAR    :
		case IDM_TOOLBARS_SETTINGBAR :
		case IDM_TOOLBARS_VIEWBAR    :
		case IDM_TOOLBARS_USERBAR    :
			return ::SendMessage( toolBars_[Msg.nmhdr()->idFrom - IDM_TOOLBARS_FILEBAR ], TB_CUSTOMIZE, 0,0 );
	}
	return 0;
}

LRESULT MoeWndImpl::OnToolbarDropDown(UINT msg, WPARAM wParam, LPARAM lParam)
{
	return ::SendMessage(getActive(),msg,wParam,lParam);
}

//////////////////////////////////////////////////////////////////////////////
//
//		helpers
//
////////////////////////////////////////////////////////////////////////////// 

void MoeWndImpl::OnReleaseChild(HWND hwnd)
{
	int i = index(hwnd);
	tabCtrl_.removeItem(i);
    if ( count() == 0 )
        changeMenu(0);

	moeWnd_->docs()->collection.Remove(variant(i));
}

//////////////////////////////////////////////////////////////////////////////
// load a path, create MDI child
//////////////////////////////////////////////////////////////////////////////


bool MoeWndImpl::openPath( const mol::string& dir, bool utf8, bool readOnly, IDoc** doc )
{
	if ( doc )
		*doc = 0;

	if ( dir.size() < 1 )
		return false;

	mol::string p(dir);
	if ( !mol::Path::exists(p) )
        return false;

	// already open?
	punk<IDoc> d;
	if ( S_OK == moeWnd_->docs()->Item(variant(bstr(p)),&d) )
	{
		if ( IDYES != ::MessageBox( 0, _T("close file?"), _T("file already open!"), MB_ICONEXCLAMATION|MB_YESNO ) )
			return false;
 
		if (d)
		{
			d->Close();
			d.release();
		}
		return false;
	}

	if ( S_OK == ::StgIsStorageFile(mol::bstr(p)) )
	{
		OleChild::Instance* oc = OleChild::CreateInstance(p);
		if ( oc && doc )
			return S_OK == oc->QueryInterface(IID_IDoc,(void**)doc);
		return oc != 0;
	}

	// if path is directory, create dir view
	if ( mol::Path::isDir(p) )
	{
		DirChild::Instance* dc = DirChild::CreateInstance(p);
		if ( dc && doc )
			return S_OK == dc->QueryInterface(IID_IDoc,(void**)doc);
		return dc != 0;
	}			

	// if path is file, check filextension
	mol::string ext = mol::Path::ext(p);
    if ( ext.size() > 0 )
	    if ( ext[0] == _T('.') )
		    ext = ext.substr(1);

    mol::cistring cis(ext.c_str());

    // is image?
    if ( cis == _T("gif") || cis == _T("jpg") || cis == _T("jpeg") || cis == _T("bmp") )
    {
		ImgViewer::Instance* iv = ImgViewer::CreateInstance(p);
		if ( iv && doc )
			return S_OK == iv->QueryInterface(IID_IDoc,(void**)doc);
	    return iv != 0;
    }

	// no dir, no image, so try open in text editor
	Editor::Instance* edit = Editor::CreateInstance( p, utf8, readOnly );
	if ( doc && edit )
		return S_OK == edit->QueryInterface(IID_IDoc,(void**)doc);

	return edit != 0;
}
			

//////////////////////////////////////////////////////////////////////////////
//
// Drag & Drop Support 
//
//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall MoeWndImpl::MoeWnd_Drop::Drop( IDataObject* pDataObject, DWORD keyState, POINTL pt , DWORD* pEffect)
{
	std::vector<mol::string> v;
    v = vectorFromDataObject(pDataObject);
	ImageList::drop(*This());
	for ( unsigned int i = 0; i < v.size(); i++ )
	{
		This()->openPath(v[i],false,false,0);
	}
	*pEffect = DROPEFFECT_NONE;
	return S_OK;
}

HRESULT  __stdcall MoeWndImpl::MoeWnd_Drop::DragEnter( IDataObject* , DWORD , POINTL , DWORD* pEffect )
{
	ImageList::enterDrag(*This());
    return S_OK;
}

HRESULT __stdcall MoeWndImpl::MoeWnd_Drop::DragOver( DWORD, POINTL, DWORD* pEffect )
{
	ImageList::doDrag(*This());
	*pEffect &= DROPEFFECT_COPY;
    return S_OK;
}


HRESULT  __stdcall MoeWndImpl::MoeWnd_Drop::DragLeave()
{
	ImageList::leaveDrag(*This());
    return S_OK;
}

//////////////////////////////////////////////////////////////////////////////
// tree events sink
//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall MoeWndImpl::TreeWnd_sink::OnTreeSelection(BSTR filename)
{
	return This()->moeWnd_->SetStatus(filename);
}

HRESULT __stdcall MoeWndImpl::TreeWnd_sink::OnTreeDblClick(BSTR filename)
{
	mol::string p(mol::toString(filename));
	if ( !mol::Path::exists(p) || mol::Path::isDir(p) )
		return S_OK;
	punk<IShellTree> tree(This()->treeWnd_.oleObject);
	if ( tree )
	{
		This()->openPath(mol::toString(filename),false,false,0);
	}
	return S_OK;
}

HRESULT __stdcall MoeWndImpl::TreeWnd_sink::OnTreeOpen(BSTR filename)
{
	punk<IShellTree> tree(This()->treeWnd_.oleObject);
	if ( tree )
	{
		This()->openPath(mol::toString(filename),false,false,0);
	}
	return S_OK;
}


//////////////////////////////////////////////////////////////////////////////
// Persistence
//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall MoeWndImpl::Load( LPSTREAM pStm) 
{
	urlDlg_.Load(pStm);
	for ( int i = 0; i < 7; i++ )
	{
		ULONG len        = 0;
		ULONG cmd        = 0;

		pStm->Read( &cmd, sizeof(ULONG), &len );
		if ( cmd != IDC_TAB_CTRL )
			loadToolBarState( toolBars_[cmd - IDM_TOOLBARS_FILEBAR ], cmd, i, pStm );
		else
			loadReBarState( cmd, i, pStm );

	}

	reBar_.postMessage(RB_MAXIMIZEBAND, reBar_.index(IDC_TAB_CTRL), 0 );

	ULONG len = 0;
	pStm->Read( &toolBarFrozen_, sizeof(BYTE),  &len );
	reBar_.freeze(toolBarFrozen_ != 0);
	return S_OK;
}



HRESULT __stdcall MoeWndImpl::Save( LPSTREAM pStm,BOOL fClearDirty)
{
	urlDlg_.Save(pStm,fClearDirty);

	for ( int i = 0; i < 8; i++ )
	{
		int cmd = reBar_.cmd(i);
		if ( cmd == IDC_SYNTAX_BOX )
			continue;

		if ( cmd != IDC_TAB_CTRL )
			saveToolBarState( toolBars_[cmd - IDM_TOOLBARS_FILEBAR ], i, pStm );
		else
			saveReBarState( i, pStm );
	}

	ULONG written = 0;
	pStm->Write( &toolBarFrozen_, sizeof(BYTE),		 &written );

	return S_OK;
}



HRESULT __stdcall MoeWndImpl::GetSizeMax( ULARGE_INTEGER *pCbSize)
{
	urlDlg_.GetSizeMax(pCbSize);
	ULONG c = 0;
	for ( int i = 0; i < 6; i++ )
	{
		c = toolBars_[i].count();
		pCbSize->QuadPart += sizeof(ULONG)*3 + sizeof(BYTE)*2 + (sizeof(TBBUTTON)*c);
	}
	pCbSize->QuadPart += sizeof(ULONG)*2 + sizeof(BYTE)*3;
	return S_OK;
}

HRESULT __stdcall MoeWndImpl::InitNew() 
{
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////
// toolbar serialization
//////////////////////////////////////////////////////////////////////////////

void MoeWndImpl::loadToolBarState( MoeToolBar& bar, int cmd, int pos, LPSTREAM pStm )
{
	ULONG c          = 0;
	ULONG len        = 0;
	ULONG w          = 0;
	BYTE isVisible   = 0;
	BYTE isNewline   = 0;
	LPTBBUTTON state = 0;
	
	pStm->Read( &isVisible, sizeof(BYTE),  &len );
	pStm->Read( &isNewline, sizeof(BYTE),  &len );
	pStm->Read( &w,  		sizeof(ULONG), &len );
	pStm->Read( &c,			sizeof(ULONG), &len );

	reBar_.move( cmd, pos );
	reBar_.showBar( cmd, isVisible != 0 );
	reBar_.newline( cmd, isNewline != 0 );
	reBar_.width( cmd, w );

	state = (LPTBBUTTON)GlobalAlloc(GPTR, sizeof(TBBUTTON) * c);   
	pStm->Read( state, sizeof(TBBUTTON)*c, &len );
	
	bar.setToolbarState(state,c);
	bar.freeToolbarState(state);		
	bar.setButtonSize(24,22);
}

void MoeWndImpl::saveToolBarState(MoeToolBar& bar, int index, LPSTREAM pStm)
{
	ULONG written    = 0;
	ULONG cmd		 = reBar_.cmd(index);
	BYTE isVisible	 = bar.isVisible() ? 1 : 0;
	BYTE isNewline	 = reBar_.newline(cmd) ? 1 : 0;
	ULONG c			 = bar.count();
	ULONG w			 = c*24;

	LPTBBUTTON state = bar.getToolbarState();

	pStm->Write( &cmd,		 sizeof(ULONG),		 &written );
	pStm->Write( &isVisible, sizeof(BYTE),		 &written );
	pStm->Write( &isNewline, sizeof(BYTE),		 &written );
	pStm->Write( &w,		 sizeof(ULONG),		 &written );
	pStm->Write( &c,		 sizeof(ULONG),		 &written );
	pStm->Write( state,		 sizeof(TBBUTTON)*c, &written );
	pStm->Commit(STGC_DEFAULT);

	bar.freeToolbarState(state);
}

void MoeWndImpl::saveReBarState(int index, LPSTREAM pStm)
{
	ULONG written    = 0;
	ULONG cmd		 = reBar_.cmd(index);
	BYTE isVisible	 = tabCtrl_.isVisible();
	BYTE isNewline	 = reBar_.newline(cmd) ? 1 : 0;
	ULONG w			 = reBar_.width(cmd);
	pStm->Write( &cmd,		 sizeof(ULONG),		 &written );
	pStm->Write( &isVisible, sizeof(BYTE),		 &written );
	pStm->Write( &isNewline, sizeof(BYTE),		 &written );
	pStm->Write( &w,		 sizeof(ULONG),		 &written );
	pStm->Commit(STGC_DEFAULT);
}


void MoeWndImpl::loadReBarState( int cmd, int pos, LPSTREAM pStm )
{
	ULONG len        = 0;
	ULONG w          = 0;
	BYTE isVisible   = 0;
	BYTE isNewline   = 0;
	
	pStm->Read( &isVisible, sizeof(BYTE),  &len );
	pStm->Read( &isNewline, sizeof(BYTE),  &len );
	pStm->Read( &w,  		sizeof(ULONG), &len );

	reBar_.move( cmd, pos );
	reBar_.showBar( cmd, isVisible != 0 );

	reBar_.newline( cmd, isNewline != 0);
	reBar_.width( cmd, w );
}

bool MoeWndImpl::openPathHex( const mol::string& file, bool readOnly, IDoc** doc )
{
	if ( doc )
		*doc = 0;

	if ( file.size() < 1 )
		return false;

	mol::string p(file);
	if ( !mol::Path::exists(p) )
        return false;

	// already open?
	punk<IDoc> d;
	if ( S_OK == moeWnd_->docs()->Item(variant(bstr(p)),&d) )
	{
		if ( IDYES != ::MessageBox( 0, _T("close file?"), _T("file already open!"), MB_ICONEXCLAMATION|MB_YESNO ) )
			return false;

		if (d)
		{
			d->Close();
			d.release();
		}
		return false;
	}		

	// open in hexedit
	Hex::Instance* hexer = Hex::CreateInstance( p, readOnly );
	if ( doc && hexer )
		return S_OK == hexer->QueryInterface(IID_IDoc,(void**)doc);

	return hexer != 0;
}

bool MoeWndImpl::openPathHtml( const mol::string& file, IDoc** doc )
{
	if ( doc )
		*doc = 0;

	if ( file.size() < 1 )
		return false;

	mol::string p(file);

	unsigned int pos1 = 0;
	while ( (pos1 = p.find("\\",pos1)) != std::string::npos ) 
	{
		p.replace(pos1,1,"/");
	}
	if ( (p.substr(0,4) != "file") &&
		 (p.substr(0,4) != "http")    )
	{
		p = "file://" + p;
	}
	// already open?
	punk<IDoc> d;
	if ( S_OK == moeWnd_->docs()->Item(variant(bstr(p)),&d) )
	{
		if ( IDYES != ::MessageBox( 0, _T("close file?"), _T("file already open!"), MB_ICONEXCLAMATION|MB_YESNO ) )
			return false;

		if (d)
		{
			d->Close();
			d.release();
		}
		return false;
	}		

	// open in hexedit
	MoeHtmlWnd::Instance* html = MoeHtmlWnd::CreateInstance(file);
	if ( doc && html )
		return S_OK == html->QueryInterface(IID_IDoc,(void**)doc);

	return html != 0;
}