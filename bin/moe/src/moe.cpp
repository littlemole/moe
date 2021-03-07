#include "stdafx.h"

#include "app.h"
#include "moe.h"
#include "Docs.h"
#include "MoeBar.h"
#include "mtree.h"
#include "commons.h"
#include "resource.h"


using namespace mol::io;
using namespace mol;
using namespace mol::ole;
using namespace mol::win;


//////////////////////////////////////////////////////////////////////////////
//
// MoeWnd Constructor - prepare Frame window object
// note children are constructed in OnCreate()
//
//////////////////////////////////////////////////////////////////////////////

MoeWnd::MoeWnd() 
	:	moeDrop(new MoeDrop),
		searchDlg(new mol::SearchDlg),
		urlDlg(new UrlDlg)
{
	ODBGS("MoeWnd::MoeWnd()");

	// registered active instance
	activeObj_			= 0;

	// don't erase window background, avoid flicker
    eraseBackground_    = 0;

	// set window icon
	icon.load(IDI_MOE);
	wndClass().setIcon(icon);		

	// create external and internal COM sub objects
	moeScript   = new MoeScript::Instance;
	moeDialogs  = new MoeDialogs::Instance;
	moeView     = new MoeView::Instance;
	moeConfig   = new MoeConfig::Instance;
	treeWndSink = new TreeWndSink::Instance;

	moeStyles.createObject(CLSID_ScintillAxStyleSets,CLSCTX_INPROC_SERVER);

	edge = ChromeEdge::CreateInstance();
}

//////////////////////////////////////////////////////////////////////////////
//
// Framewindow Destructor
//
//////////////////////////////////////////////////////////////////////////////

MoeWnd::~MoeWnd()
{
	if ( icon )
		::DestroyIcon(icon);

	ODBGS("~MoeWnd says goodbye");
}


/////////////////////////////////////////////////////////////////////
// Create Instance
/////////////////////////////////////////////////////////////////////



MoeWnd::Instance* MoeWnd::CreateInstance()
{
	Instance* moe = new Instance;
	moe->AddRef();

	::CoAllowSetForegroundWindow((IMoe*)moe,0);

	UI().makeMainWindow(moe, _T("moe"), (HMENU)0, stdRect, IDW_MOE);

	return moe;
}


/////////////////////////////////////////////////////////////////////
          
handle_msg(&MoeWnd::OnCreate,WM_CREATE)
void MoeWnd::OnCreate()
{
	// the main window and GUI elements have been created

	ODBGS("MoeWnd::OnCreate()");

	// initialize critical GUI parts now

	BorderLayout* layout = setLayout(new BorderLayout);

	// menu ribbon
	MoeHtmlRibbon* ribbon = UI().makeWindow<MoeHtmlRibbon>((HMENU)ID_MOE_HTML_RIBBON, mol::Rect(0, 0, 160, 133), hWnd_);
	ribbon->onDocumentLoad = [this](MoeHtmlRibbon*) {
		if (this->onMoeBarLoaded)
		{
			this->onMoeBarLoaded(this);
		}
	};

	ribbon->show(SW_SHOW);
	ribbon->load(edge);
	layout->add(*ribbon, BorderLayout::NORTH);

	// directory tree
	MoeTreeWnd* treeWnd = UI().makeWindow<MoeTreeWnd>((HMENU)IDW_TREE_VIEW, mol::Rect(0, 0, 160, 200), hWnd_);
	treeWnd->show(SW_SHOW);
	layout->add(*treeWnd, BorderLayout::WEST);

	mol::punk<IShellTree> tree(treeWnd->oleObject);
	tree->put_UseContext(VARIANT_FALSE);
	treeWndSink->Advise(treeWnd->oleObject);

	// MDI tabs bas
	MoeTabControl* tab = UI().makeWindow<MoeTabControl>((HMENU)IDW_TAB_CTRL, mol::Rect(0, 0, 160, 26), hWnd_);
	tab->show(SW_HIDE);
	layout->add(*tab, BorderLayout::SOUTH);

	// status bar
	MoeStatusBar* statusBar = UI().makeWindow<MoeStatusBar>((HMENU)IDW_STATUS, stdRect,hWnd_);
	statusBar->show(SW_SHOW);
	layout->addStatusBar(statusBar);
	statusBar->setText(_T(""));

	// progress bar
	mol::ProgressbarCtrl* progress = UI().makeWindow<mol::ProgressbarCtrl>((HMENU)IDW_PROGRESS_BAR, mol::Rect(3, 7, 300, 12), (HWND)*statusBar);
	progress->show(SW_SHOW);
	progress->setColor(RGB(175, 175, 175));
	progress->setBkColor(RGB(222, 222, 222));
	progress->setRange(0, 100);
	progress->setPos(10);

	// add MDI workspace to layout
	layout->add( mdiClient(), BorderLayout::FILL);

	// drag n drop    
	::RegisterDragDrop(hWnd_, moeDrop.get());

	// keybord shortcuts (accellerators)
	mol::win::accelerators().load(IDA_MOE, hWnd_);

	// declare available OLE CMD ids and map them to WM_COMMAND msgs
	addOlExecHandler(OLECMDID_NEW, IDM_FILE_NEW);
	addOlExecHandler(OLECMDID_OPEN, IDM_FILE_OPEN);
	addOlExecHandler(OLECMDID_SAVE, IDM_FILE_SAVE);
	addOlExecHandler(OLECMDID_SAVEAS, IDM_FILE_SAVE_AS);
	addOlExecHandler(OLECMDID_PRINT, IDM_FILE_PRINT);

	ODBGS("MoeWnd::OnCreate()");

	// register us as active instance
	HRESULT hr = ::RegisterActiveObject( (IMoe*)this,CLSID_Application,ACTIVEOBJECT_STRONG,&activeObj_);

	// hide the progress window
	progress->show(SW_HIDE);

	// load UI state
	loadPersistUIstate();

	// pre-init the debug dialog (hidden)
	debugDlg()->doModeless( IDD_DIALOG_DEBUG, *this );
	debugDlg()->show(SW_HIDE);

	// initialize win7 taskbar
	mol::taskbar()->init(*this);
}

void MoeWnd::loadPersistUIstate()
{
	std::wstring appPath = mol::app<AppBase>().CreateAppPath(_T("moe"));

	std::wstring settingsPath = appPath + L"\\settings.xml";

	this->moeConfig->ImportSettings(mol::bstr(settingsPath));

	std::wstring stylesPath = appPath + L"\\styles.xml";
	std::string xml = slurp(mol::tostring(stylesPath));
	this->moeStyles->put_XML(mol::bstr(xml));

	// determine ui.xmo filepath or use fallback
	std::wstring p(appPath + _T("\\ui.xmo"));
	if ( !mol::Path::exists(p) )
	{
		p = mol::Path::pathname(mol::app<mol::win::AppBase>().getModulePath()) + _T("\\ui.xmo");
	}
	if ( !mol::Path::exists(p) )
		return;

	std::wstring recentUrlsPath = appPath + L"\\recentUrls.xml";
	urlDlg->readXML(recentUrlsPath);	
}


//////////////////////////////////////////////////////////////////////////////
//
// Destruct Sequence - over and out
//
//////////////////////////////////////////////////////////////////////////////

handle_msg(&MoeWnd::OnClose,WM_CLOSE)
LRESULT MoeWnd::OnClose()
{
	int n = this->count();
	if (n == 0)
	{
		Exit();
		return 0;
	}

	for (int i = n - 1; i >= 0; i--)
	{
		HWND child = this->childAt(i);
		if (::IsWindow(child))
		{
			LRESULT r = ::SendMessage(child, WM_COMMAND, IDM_VIEW_CLOSEALL, 0);
			DWORD e = ::GetLastError();
		}
	}
	return 1;
}

handle_cmd(&MoeWnd::OnCloseAll, IDM_VIEW_CLOSEALL)
LRESULT MoeWnd::OnCloseAll()
{
	int n = this->count();
	if (n == 0)
	{
		return 0;
	}

	for (int i = n - 1; i >= 0; i--)
	{
		HWND child = this->childAt(i);
		if (::IsWindow(child))
		{
			LRESULT r = ::SendMessage(child, WM_CLOSE,0, 0);
			DWORD e = ::GetLastError();
		}
	}
	return 1;
}

handle_cmd(&MoeWnd::OnCloseAllButThis, IDM_TAB_CLOSEALLBUTTHIS)
LRESULT MoeWnd::OnCloseAllButThis()
{
	HWND m = getActive();
	if (!::IsWindow(m) )
		return 0;

	for ( int i = 0; i < count(); i++ )
	{
		if ( childAt(i) != m )
			::PostMessage( childAt(i), WM_CLOSE, 0, 0 );
	}
	return 0;
}

handle_msg(&MoeWnd::OnDestroy, WM_DESTROY)
void MoeWnd::OnDestroy()
{	
	treeWndSink->UnAdvise(treeWnd()->oleObject);
	::CoDisconnectObject(treeWnd()->oleObject,0);
	::RevokeDragDrop(*this);

	if ( activeObj_ )
		::RevokeActiveObject(activeObj_,0);	
}

handle_msg(&MoeWnd::OnNcDestroy, WM_NCDESTROY)
void MoeWnd::OnNcDestroy()
{
	::CoDisconnectObject( (IMoeDocumentCollection*)(docs()),0);
	::CoDisconnectObject(((IMoe*)this),0);
	((IMoe*)this)->Release();
}

//////////////////////////////////////////////////////////////////////////////
//
//
//////////////////////////////////////////////////////////////////////////////

handle_msg(&MoeWnd::OnMDIActivate, WM_MDIACTIVATE)
void MoeWnd::OnMDIActivate(HWND activated)
{
}


//////////////////////////////////////////////////////////////////////////////
//
// update UI - redraw menues
//
//////////////////////////////////////////////////////////////////////////////

// obsolete ?
handle_msg(&MoeWnd::OnMenu, WM_INITMENUPOPUP)
LRESULT MoeWnd::OnMenu(UINT msg, WPARAM wParam, LPARAM lParam)
{
	Menu m( (HMENU)wParam );

	m.disableItem(IDM_TOOLS_EXECUTE_NET);

	if ( !treeWnd()->isVisible() )
		m.unCheckItem(IDM_VIEW_DIRVIEW );
	else
		m.checkItem(IDM_VIEW_DIRVIEW);

	// pass to active window
	::SendMessage(getActive(),msg, wParam, lParam);

	return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// Dispatch the following to active child window
//
//////////////////////////////////////////////////////////////////////////////
 
handle_msg(&MoeWnd::OnDispatch, WM_SEARCH_MSG)
handle_cmd(&MoeWnd::OnDispatch, 
	IDM_EDIT_CUT, IDM_EDIT_COPY, IDM_EDIT_PASTE, IDM_EDIT_PASTEAS,
	IDM_FILE_PRINT, IDM_FILE_SAVE, IDM_FILE_SAVE_AS,
	IDM_MODE_UNIX, IDM_MODE_WIN32, IDM_MODE_USETABS, IDM_MODE_DONT_USE_TABS,
	IDM_MODE_SETTINGS, IDM_MODE_EOL, IDM_EDIT_COLOR, IDM_EDIT_SELECT,
	IDM_EDIT_UNDO, IDM_EDIT_REDO, IDM_EDIT_STOP, IDM_EDIT_UPDATE,
	IDM_EDIT_INDENTION, IDM_FILE_NEWDIR, IDM_FILE_UPDIR, IDM_FILE_DIREXEC,
	IDM_FILE_DIRPROP, IDM_RIBBON_TABCONVERT, IDM_EDIT_EXECUTESCRIPT,
	IDM_EDIT_DEBUG, IDM_EDIT_DEBUG_GO, IDM_EDIT_DEBUG_STEPIN,
	IDM_EDIT_DEBUG_STEPOUT, IDM_EDIT_DEBUG_STEPOVER, IDM_EDIT_DEBUG_STOP,
	IDM_EDIT_DEBUG_QUIT, IDM_EDIT_DEBUG_EVAL_EXPR, IDM_NAVIGATE_NEXT,
	IDM_NAVIGATE_BACK, IDM_MODE_EXECUTEFORM, IDM_MODE_SHOW_LINE_NUMBERS,
	IDM_USER_SHORTCUT
)
handle_cmd_range(&MoeWnd::OnDispatch, ID_FIRST_USER_CMD, ID_LAST_USER_CMD)
handle_cmd_range(&MoeWnd::OnDispatch, IDM_EDIT_16BYTES, IDM_EDIT_32BYTES)
LRESULT MoeWnd::OnDispatch(UINT msg, WPARAM wParam, LPARAM lParam)
{
	if ( treeWnd()->hasFocus() )
	{
		treeWnd()->sendMessage(msg,wParam,lParam);
		return 0;
	}
    ::SendMessage(getActive(),msg,wParam,lParam);
    return 0;
}

// obsolete ???

handle_cmd(&MoeWnd::OnDispatchTree, IDM_TREE_OPEN, IDM_TREE_UPDATE,
	IDM_TREE_RENAME, IDM_TREE_DELETE, 
	IDM_TREE_CUT, IDM_TREE_COPY, IDM_TREE_PASTE,
	IDM_TREE_PROPERTIES, IDM_TREE_EXECUTE, IDM_TREE_NEWDIR
)
LRESULT MoeWnd::OnDispatchTree(UINT msg, WPARAM wParam, LPARAM lParam)
{
	treeWnd()->sendMessage(msg,wParam,lParam);
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// Create new child window
//
//////////////////////////////////////////////////////////////////////////////

handle_cmd(&MoeWnd::OnFileNew, IDM_FILE_NEW)
void MoeWnd::OnFileNew()
{
	mol::punk<IMoeDocument> doc;
	docs()->New(&doc);
}


//////////////////////////////////////////////////////////////////////////////
//
// Open from file and Create new child window 
//
//////////////////////////////////////////////////////////////////////////////

handle_cmd(&MoeWnd::OnFileOpen, IDM_FILE_OPEN)
void MoeWnd::OnFileOpen()
{
	mol::punk<IMoeDocument> doc;
	moeDialogs->Open(0,&doc);
}

// obsolete ???
handle_cmd(&MoeWnd::OnRecentItems, IDM_RIBBON_RECENTITEMS)
void MoeWnd::OnRecentItems()
{
	// click on recent items list - retrieve filename
/*	int selected = mol::Ribbon::handler(RibbonMRUItems)->index();
	std::wstring f = mol::Ribbon::handler(RibbonMRUItems)->recent_items()[selected].first;

	mol::punk<IMoeDocument> doc;
	docs()->Open( mol::bstr(f), &doc );
	*/
}




//////////////////////////////////////////////////////////////////////////////
//
// Open new Dir from folder browser
//
//////////////////////////////////////////////////////////////////////////////

handle_cmd(&MoeWnd::OnFileOpenDir, IDM_FILE_OPEN_FOLDER)
void MoeWnd::OnFileOpenDir()
{
	mol::punk<IMoeDocument> doc;
	moeDialogs->OpenDir(&doc);
}

handle_cmd(&MoeWnd::OnFileOpenHex, IDM_FILE_OPEN_HEX)
void MoeWnd::OnFileOpenHex()
{
	mol::FilenameDlg dlg(*this);	
	if ( IDOK == dlg.dlgOpen(OFN_READONLY|OFN_EXPLORER) )
	{
		bool result = docs()->open( dlg.fileName(), MOE_DOCTYPE_HEX,-1, dlg.readOnly(), 0 );
		if (!result)
		{
			std::wostringstream oss;
			oss << _T("failed to load: ") << dlg.fileName();
			statusBar()->status(oss.str());
		}
		statusBar()->status(dlg.fileName());
	}
}

handle_cmd(&MoeWnd::OnFileOpenHtml, IDM_FILE_OPEN_HTML)
void MoeWnd::OnFileOpenHtml()
{	
	if ( IDOK == urlDlg->doModal( IDD_DIALOG_URL, *this ) )
	{
		if ( !urlDlg->url.empty() )
		{
			if (  urlDlg->url.substr(0,6) == _T("ssh://") ||  urlDlg->url.substr(0,10) == _T("moe-ssh://") )
			{
				bool result = docs()->open( urlDlg->url, MOE_DOCTYPE_DOC, -1, false, 0 );
				return;
			}
			bool result = docs()->open( urlDlg->url, MOE_DOCTYPE_HTML, -1, true, 0 );
			if (!result)
			{
				std::wostringstream oss;
				oss << _T("failed to load: ") << urlDlg->url;
				statusBar()->status(oss.str());
			}
			statusBar()->status(urlDlg->url);
		}
	}
}

//////////////////////////////////////////////////////////////////////////////
//
// User selected Exit from main Menu - kill app
//
//////////////////////////////////////////////////////////////////////////////

handle_cmd(&MoeWnd::OnFileExit, IDM_FILE_EXIT)

void MoeWnd::OnFileExit()
{
	Exit();
}


//////////////////////////////////////////////////////////////////////////////

handle_cmd(&MoeWnd::OnFind, IDM_EDIT_FIND)
void MoeWnd::OnFind()
{
    searchDlg->findText(*this);
}


//////////////////////////////////////////////////////////////////////////////

handle_cmd(&MoeWnd::OnReplace, IDM_EDIT_REPLACE)
void MoeWnd::OnReplace()
{
    searchDlg->replaceText(*this);
}

void MoeWnd::OnSysCommand(WPARAM wParam)
{
	// that did not work out as planned :-(
	/*
	if (wParam == VK_MENU)
	{
		::SetMenu(hWnd_, UI().Menu(IDM_MOE));
	}
	*/
}

// obsolete ??
handle_cmd(&MoeWnd::OnExitLoop, WM_EXITMENULOOP)
void MoeWnd::OnExitLoop()
{
//	::SetMenu(hWnd_, 0);
}

//////////////////////////////////////////////////////////////////////////////
//
// Settings
//
//////////////////////////////////////////////////////////////////////////////

handle_cmd(&MoeWnd::OnEditSettings, IDM_MODE_EDITSETTINGS)
void MoeWnd::OnEditSettings()
{
	moeConfig->EditSettings();
}

handle_cmd(&MoeWnd::OnEditPrefs, IDM_MODE_PREFERENCES)
void MoeWnd::OnEditPrefs()
{
	moeConfig->EditPreferences();
}

handle_cmd(&MoeWnd::OnEditUserStyles, IDM_MODE_USERSTYLES)
void MoeWnd::OnEditUserStyles()
{
	bool result = docs()->open( _T("forms\\styles.html"), MOE_DOCTYPE_HTML, -1, true, 0 );
	if (!result)
	{
		::MessageBox(*this,_T("err"),_T("failed to load"),MB_ICONERROR);
	}
}

//////////////////////////////////////////////////////////////////////////////

handle_cmd_range(&MoeWnd::OnFx, IDM_F1, IDM_F12)
void MoeWnd::OnFx(int code, int id, HWND ctrl)
{
	int fx =id-IDM_F1+1;

	std::wostringstream oss;
	oss << _T("fx\\F") << fx << _T(".js");

	std::wstring file = findFile(oss.str());
	if ( file == _T("") )
		return ;
	
	mol::filestream fs;
	if ( !fs.open( mol::tostring(file)) )
		return ;

	std::string src = fs.readAll();
	fs.close();

	moeScript->Eval(bstr(src),bstr(L"javascript"));
}

//////////////////////////////////////////////////////////////////////////////
//
// show/hide Tree View
//
//////////////////////////////////////////////////////////////////////////////
/*
#define connect_cmd_handler(cmd,mfp)											\
int mol_connect_cmd##cmd##__()													\
{																				\
	IMsgMapHandler* handler = make_handler(&mfp);								\
	handler->connect_cmd( cmd );												\
	return 0;																	\
}																				\
int mol_connect_cmd##cmd##__initonce__ = mol_connect_cmd##cmd##__();
*/
/*
class ConnectCmdHandler
{
public:
	template<class F>
	ConnectCmdHandler(UINT cmd, F f)
	{
		IMsgMapHandler* handler = make_handler(f);
		handler->connect_cmd( cmd );	
	}
};

#define connect_cmd_handler(cmd,mfp) \
	ConnectCmdHandler connectCmdHandler_##__LINE__(cmd,&mfp);


connect_cmd_handler(IDM_VIEW_DIRVIEW,MoeWnd::OnShowDirView)
*/

handle_cmd(&MoeWnd::OnShowFileMenue, IDM_VIEW_SHOW_FILE_MENU)
void MoeWnd::OnShowFileMenue()
{
	moeView->ShowFileMenu();
}

handle_cmd(&MoeWnd::OnHideFileMenue, IDM_VIEW_HIDE_FILE_MENU)
void MoeWnd::OnHideFileMenue()
{
}

handle_cmd(&MoeWnd::OnShowDirView, IDM_VIEW_DIRVIEW)
void MoeWnd::OnShowDirView ()
{
	Menu m(*this);
	if ( !treeWnd()->isVisible() )
	{
		moeConfig->put_ShowTreeView(VARIANT_TRUE);

		//treeWnd()->show(SW_SHOW);
		::InvalidateRect(mdiClient(),0,TRUE);
	}
	else
	{
		moeConfig->put_ShowTreeView(VARIANT_FALSE);
		//treeWnd()->show(SW_HIDE);
	}
	OnLayout(0,0,0);
}

//////////////////////////////////////////////////////////////////////////////
//
// show/hide Tool bars
//
//////////////////////////////////////////////////////////////////////////////

// obsolete
handle_cmd_range(&MoeWnd::OnShowToolBar, IDM_TOOLBARS_FILEBAR, IDM_TOOLBARS_DIRVIEW)
void MoeWnd::OnShowToolBar (int code, int id, HWND ctrl)
{
	/*
	Menu m(*this);
	switch(id)
	{
		case IDM_TOOLBARS_DIRVIEW :
		{
			if ( !treeWnd()->isVisible() )
			{
				treeWnd()->show(SW_SHOW);
				::InvalidateRect(mdiClient(),0,TRUE);
			}
			else
			{
				treeWnd()->show(SW_HIDE);
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
			int index = id-IDM_TOOLBARS_FILEBAR + IDC_TOOLBARS_FILEBAR;
			MoeToolBar* tb = mol::UI().Wnd<MoeToolBar>(index);
			bool isVisible = tb->isVisible() != 0; 
			if ( isVisible )
			{
				reBar()->showBar( index, false );
			}
			else
			{
				reBar()->showBar( index, true );
			}
			break;
		}
	}
	*/
	OnLayout(0,0,0);
}

//////////////////////////////////////////////////////////////////////////////
//
// freeze toolbars
//
//////////////////////////////////////////////////////////////////////////////

//handle_cmd(&MoeWnd::OnFreezeToolBar, IDM_TOOLBARS_FREEZE)
//void MoeWnd::OnFreezeToolBar ()
//{
	/*
	if ( toolBarFrozen_ )
	{
		toolBarFrozen_ = 0;
		reBar()->freeze(false);
	}
	else
	{
		toolBarFrozen_ = 1;
		reBar()->freeze(true);
	}
	*/
//}
//////////////////////////////////////////////////////////////////////////////
//
// OnHelpAbout - show help dialog
//
//////////////////////////////////////////////////////////////////////////////

handle_cmd(&MoeWnd::OnHelpAbout, IDM_HELP_ABOUT)
void MoeWnd::OnHelpAbout()
{
	statusBar()->status(_T("help"));

	mol::bstr configPath;
	moeConfig->get_ConfigPath(&configPath);

	std::wostringstream woss;
	woss << configPath.towstring() << L"\\doc\\index.html";

	mol::punk<IMoeDocument> doc;
	docs()->OpenHtmlFrame( bstr(woss.str()), &doc );
}





//////////////////////////////////////////////////////////////////////////////
//
// OnSyntax
//
//////////////////////////////////////////////////////////////////////////////

// obsolete ???
void MoeWnd::OnSyntax(int code, int id, HWND ctrl)
{
	/*
	if ( code == CBN_SELCHANGE )
	{
		int sel = mol::UI().Wnd<MoeComboBox>(IDW_SYNTAX_BOX)->getCurSel();
		::PostMessage(getActive(),WM_COMMAND,IDM_LEXER_PLAIN+sel,(LPARAM)ctrl);
	}
	*/
}

/////////////////////////////////////////////////////////////////////////

// where is this mapped to ???
void MoeWnd::OnScreenShot()
{
	HWND active = getActive();
	if (active)
	{
		mol::Window* win = mol::wndFromHWND<mol::Window>(active);
		if (win)
		{
			HBITMAP bmp = win->snapshot();

			mol::win::ClipBoard cb(*win);
			cb.clear();
			cb.setData(CF_BITMAP,bmp);
		}
	}
}


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall MoeWnd::IOleInPlaceFrame_SetStatusText(LPCOLESTR txt)
{
	if ( !txt )
		statusBar()->status(_T(""));
	else
		statusBar()->status( mol::towstring(txt) );
	return S_OK;
}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////
// COM section
/////////////////////////////////////////////////////////////////////

HRESULT __stdcall MoeWnd::get_Documents( IMoeDocumentCollection **d)
{
	if (!d)
		return E_INVALIDARG;
	*d = 0;

	return docs()->QueryInterface( IID_IMoeDocumentCollection, (void**) d );
}

HRESULT __stdcall MoeWnd::get_View( IMoeView **d)
{
	if (!d)
		return E_INVALIDARG;
	*d = 0;

	return moeView.queryInterface( d );
}


HRESULT __stdcall MoeWnd::get_ActiveDoc( IMoeDocument **d)
{
	if (!d)
		return E_INVALIDARG;
	*d = 0;

	return docs()->get_ActiveDoc( d );
}


HRESULT __stdcall MoeWnd::get_Config( IMoeConfig **d)
{
	if (!d)
		return E_INVALIDARG;
	*d = 0;

	return moeConfig.queryInterface( d );
}


HRESULT __stdcall MoeWnd::get_Script( IMoeScript **d)
{
	if (!d)
		return E_INVALIDARG;
	*d = 0;

	return moeScript.queryInterface( d );
}


HRESULT __stdcall MoeWnd::get_Dialogs( IMoeDialogs **d)
{
	if (!d)
		return E_INVALIDARG;
	*d = 0;

	return moeDialogs.queryInterface( d );
}


HRESULT __stdcall MoeWnd::Exit()
{
	int n = this->count();
	for (int i = n-1; i >= 0; i--)
	{
		HWND child = this->childAt(i);
		::DestroyWindow(child);
	}
	/*
	// tear down open documents gently
	long cnt = 0;
	HRESULT hr = docs()->get_Count(&cnt);
	if( hr != S_OK )
		return hr;

	long i = cnt;
	for( i = 0; i < cnt; i++ )
	{
		mol::punk<IMoeDocument> doc;
		hr = docs()->Item( mol::variant(i), &doc );
		if( hr != S_OK )
			return hr;

		mol::punk<IMoeDocumentView> view;
		hr = doc->get_View(&view);
		if( hr != S_OK )
			return S_FALSE;

		hr = view->Close();
		if( hr != S_OK )
			return S_FALSE;
	}
	*/

	// if we have ribbon, maximize it before persistence
	/*
	if ( mol::Ribbon::ribbon()->enabled())
	{
		mol::Ribbon::ribbon()->maximize();
	}
	*/

	std::wstring appPath = mol::app<AppBase>().CreateAppPath(_T("moe"));
	std::wstring p;
	/*
	// save persistent info
	std::wstring p(appPath + _T("\\ui.xmo"));
	Storage store;
	if ( store.create(p) )
	{
		store.clsid(this->getCoClassID());
		punk<IPersistStorage> ps(this);
		if ( ps )
		{
			ps->Save(store,FALSE);
		}
	}
	*/
	// save xml

	p = appPath + L"\\settings.xml";
	HRESULT hr = moeConfig->ExportSettings(mol::bstr(p));

	p = appPath + L"\\styles.xml";
	mol::bstr xml;
	hr = moeStyles->get_XML(&xml);
	std::ofstream ofs;
	ofs.open(mol::tostring(p), std::ios::binary | std::ios::out);
	if (ofs)
	{
		std::string utf8 = toUTF8(xml.towstring());
		ofs.write(utf8.c_str(),utf8.size());
		ofs.close();
	}

	p = appPath + L"\\recentUrls.xml";
	urlDlg->saveXML(p);

	// harakiri
	destroy();
	return S_OK;
}

HRESULT __stdcall MoeWnd::Cut()
{
	if (treeWnd()->hasFocus())
	{
		treeWnd()->postMessage(WM_COMMAND, IDM_EDIT_CUT, 0);
		return S_OK;
	}

	HWND active = this->getActive();

	if (!active) return S_OK;

	::PostMessage(active, WM_COMMAND, IDM_EDIT_CUT, 0);
	return S_OK;
}

HRESULT __stdcall MoeWnd::Copy()
{
	if (treeWnd()->hasFocus())
	{
		treeWnd()->postMessage(WM_COMMAND, IDM_EDIT_COPY, 0);
		return S_OK;
	}

	HWND active = this->getActive();
	if (!active) return S_OK;

	::PostMessage(active, WM_COMMAND, IDM_EDIT_COPY, 0);
	return S_OK;
}

HRESULT __stdcall MoeWnd::Paste()
{
	if (treeWnd()->hasFocus())
	{
		treeWnd()->postMessage(WM_COMMAND, IDM_EDIT_PASTE, 0);
		return S_OK;
	}

	HWND active = this->getActive();
	if (!active) return S_OK;

	::PostMessage(active, WM_COMMAND, IDM_EDIT_PASTE, 0);
	return S_OK;
}

HRESULT __stdcall MoeWnd::PasteAs()
{
	HWND active = this->getActive();
	if (!active) return S_OK;

	::PostMessage(active, WM_COMMAND, IDM_EDIT_PASTEAS, 0);
	return S_OK;
}

HRESULT __stdcall MoeWnd::InsertTemplate()
{
	HWND active = this->getActive();
	if (!active) return S_OK;

	::SendMessage(active, WM_COMMAND, IDM_USER_SHORTCUT,0);
	return S_OK;
}

HRESULT __stdcall MoeWnd::Print(BSTR txt)
{
	if ( !txt )
		return S_OK;

	std::wostringstream woss;
	if ( vttyOut_ )
		woss << vttyOut_.towstring();
	woss << txt;
	vttyOut_ = woss.str();

	return S_OK;
}

HRESULT MoeWnd::stdOut(BSTR* ret) 
{
	if ( ret == 0 )
		return E_INVALIDARG;

	if ( !vttyOut_ )
	{
		*ret = 0;
		return S_OK;
	}

	*ret = ::SysAllocString(vttyOut_.bstr_);
	vttyOut_ = 0;
	return S_OK;
}

void  MoeWnd::freezeConfig(const std::wstring& key)
{
	// freeze top level items
	mol::punk<IDispatch> disp;
	moeConfig->get_Settings(&disp);
	mol::punk<ISetting> config(disp);

	punk<ISetting> s;
	if ( S_OK == config->Item(variant(key),&s) )
	{
		if ( s )
		{
			s->put_KeyReadOnly(VARIANT_TRUE);
			s->put_ValueReadOnly(VARIANT_TRUE);
		}
	}
}


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

handle_cmd(&MoeWnd::OnMaximizeView, IDM_VIEW_MAXIMIZE)
void MoeWnd::OnMaximizeView()
{
	OnMaximize(0, 0, 0);
}

handle_cmd(&MoeWnd::OnMinimizeView, IDM_VIEW_MINIMIZE)
void MoeWnd::OnMinimizeView()
{
	OnMinimize(0, 0, 0);
}

handle_cmd(&MoeWnd::OnTileView, IDM_VIEW_TILE)
void MoeWnd::OnTileView()
{
	OnTileHorizontal(0, 0, 0);
}

handle_cmd(&MoeWnd::OnCascadeView, IDM_VIEW_CASCADE)
void MoeWnd::OnCascadeView()
{
	OnCascade(0, 0, 0);
}

handle_cmd(&MoeWnd::OnNextView, IDM_VIEW_NEXT)
void MoeWnd::OnNextView()
{
	OnNext(0, 0, 0);
}

handle_cmd(&MoeWnd::OnCloseChildView, IDM_VIEW_CLOSE)
void MoeWnd::OnCloseChildView()
{
	OnCloseChild(0, 0, 0);
}


MoeWnd* moe() 
{ 
	return mol::UI().Wnd<MoeWnd>(IDW_MOE); 
}

// should ALL be members ob moeWnd
MoeHtmlRibbon* ribbon() 
{ 
	return mol::UI().Wnd<MoeHtmlRibbon>(ID_MOE_HTML_RIBBON); 
}

MoeTreeWnd* treeWnd() 
{ 
	return mol::UI().Wnd<MoeTreeWnd>(IDW_TREE_VIEW); 
}

MoeTabControl* tab() 
{ 
	return mol::UI().Wnd<MoeTabControl>(IDW_TAB_CTRL); 
}

MoeStatusBar* statusBar() 
{ 
	return mol::UI().Wnd<MoeStatusBar>(IDW_STATUS); 
}

// KILL KILL KILL
mol::ProgressbarCtrl* progress() 
{ 
	return mol::UI().Wnd<mol::ProgressbarCtrl>(IDW_PROGRESS_BAR); 
}

Documents* docs()
{
	return &mol::singleton<Documents>();
}

Encodings* codePages()
{
	return &mol::singleton<Encodings>();
}

DebugDlg* debugDlg()
{
	return &mol::singleton<DebugDlg>();
}
