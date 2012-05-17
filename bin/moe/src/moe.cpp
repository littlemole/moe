#include "stdafx.h"
#include "UserForm.h"
#include "app.h"
#include "Img.h"
#include "Dir3.h"
#include "Form.h"
#include "Editor.h"
#include "hex.h"
#include "html.h"
#include "ole.h"
#include "MoeBar.h"
#include "Docs.h"
#include "xmlui.h"
#include "tree.h"
#include "Ribbonres.h"
#include "ax/sshShell/sshShell_h.h"

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
{
	ODBGS("MoeWnd::MoeWnd()");

	// registered active instance
	activeObj_			= 0;

	// default settings for new editor documents
	systype_			= SCINTILLA_SYSTYPE_WIN32;
	encoding_			= SCINTILLA_ENCODING_ANSI;
	syntax_				= SCINTILLA_SYNTAX_PLAIN;
	tabwidth_			= 4;
	tabUsage_			= VARIANT_TRUE;
	tabIndents_			= VARIANT_TRUE;
	backSpaceUnIndents_	= VARIANT_FALSE;
	fullScreen_			= VARIANT_FALSE;

	// don't erase window background, avoid flicker
    eraseBackground_    = 0;

	// tell MDI impl where mdi child ids start (enable window menu - XP style only)
    setFirstChildId(ID_FIRST_CHILD_WND);	

	// set window icon
	icon.load(IDI_MOE);
	wndClass().setIcon(icon);		

	// create sub objects
	moeScript  = new MoeScript::Instance;
	moeDialogs = new MoeDialogs::Instance;
	moeView    = new MoeView::Instance;
	moeConfig  = new MoeConfig::Instance;

	//capture supported codepages. we add three pretty well-known to the list
	codePages_.push_back( CodePage(std::make_pair(CP_ACP,L"Default CodePage")) );
	codePages_.push_back( CodePage(std::make_pair(CP_UTF8,L"UTF-8")) );
	codePages_.push_back( CodePage(std::make_pair(CP_WINUNICODE,L"Unicode (UTF-16)")) );

	const mol::CodePages::Entries& cps = mol::CodePages::codePages();
	for ( mol::CodePages::Iterator it = cps.begin(); it != cps.end(); it++)
	{
		codePages_.push_back( CodePage( std::make_pair( (*it).first, (*it).second.second)) );
	}

	
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

	// create the generated UI widgets
	build_ui<MoeWnd>(moe);
	return moe;
}


/////////////////////////////////////////////////////////////////////

void MoeWnd::OnCreate()
{
	// the main window and GUI elements have been created
	// initialize critical GUI parts now

	this->layout_->hasRibbon(true);

	ODBGS("MoeWnd::OnCreate()");

	// register us as active instance
	HRESULT hr = ::RegisterActiveObject( (IMoe*)this,CLSID_Application,ACTIVEOBJECT_STRONG,&activeObj_);

	// hide the progress window
	progress()->show(SW_HIDE);

	// initialize tree child window and hook up tree window COM events
	mol::punk<IShellTree> tree(treeWnd()->oleObject);
	tree->put_UseContext(VARIANT_FALSE);
	treeWndSink()->Advise(treeWnd()->oleObject);

	// update the menu
	::DrawMenuBar(*this);

	// pre-init the debug dialog (hidden)
	debugDlg()->doModeless( IDD_DIALOG_DEBUG, *this );
	debugDlg()->show(SW_HIDE);

	// initialize win7 taskbar
	mol::taskbar()->init(*this);

	// load UI state
	loadPersistUIstate();

    // update ribbon's recent documents
	mol::Ribbon::ribbon()->updateRecentDocs(RibbonMRUItems);

	

}

void MoeWnd::loadPersistUIstate()
{
	// determine ui.xmo filepath or use fallback
	mol::string p(appPath() + _T("\\ui.xmo"));
	if ( !mol::Path::exists(p) )
	{
		p = mol::Path::pathname(binPath()) + _T("\\ui.xmo");
	}
	if ( !mol::Path::exists(p) )
		return;

	// open the storage
	Storage store;
	if ( !store.open(p, STGM_READ | STGM_SHARE_EXCLUSIVE ))
		return;

	// load moe config data from storage
	mol::punk<IPersistStorage> ps;
	((IMoe*)this)->QueryInterface( IID_IPersistStorage, (void**)&ps);
	HRESULT hr = ps->Load( store );
}


//////////////////////////////////////////////////////////////////////////////
//
// Destruct Sequence - over and out
//
//////////////////////////////////////////////////////////////////////////////

LRESULT MoeWnd::OnClose()
{
	Exit();
	return 0;
}


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

void MoeWnd::OnDestroy()
{	
	Ribbon::ribbon()->tearDown();

	treeWndSink()->UnAdvise(treeWnd()->oleObject);
	::CoDisconnectObject(treeWnd()->oleObject,0);
	scriptlet()->close();
	::RevokeDragDrop(*this);

	if ( activeObj_ )
		::RevokeActiveObject(activeObj_,0);
	
}

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

void MoeWnd::OnMDIActivate(HWND activated)
{
}


//////////////////////////////////////////////////////////////////////////////
//
// update UI - redraw menues
//
//////////////////////////////////////////////////////////////////////////////

LRESULT MoeWnd::OnMenu(UINT msg, WPARAM wParam, LPARAM lParam)
{
	if ( mol::Ribbon::ribbon()->enabled())
		return 0;

	Menu m( (HMENU)wParam );

	m.disableItem(IDM_TOOLS_EXECUTE_NET);

	if ( !treeWnd()->isVisible() )
		m.unCheckItem(IDM_VIEW_DIRVIEW );
	else
		m.checkItem(IDM_VIEW_DIRVIEW);

	for ( int i = IDC_TOOLBARS_FILEBAR; i <= IDC_TOOLBARS_USERBAR; i++ )
	{
		int index = i-IDC_TOOLBARS_FILEBAR + IDM_TOOLBARS_FILEBAR;
		MoeToolBar* tb = mol::UI().Wnd<MoeToolBar>(i);
		if ( tb->isVisible() )
		{
			m.checkItem( index );
		}
		else
		{
			m.unCheckItem( index );
		}
	}

	if ( toolBarFrozen_ )
		m.checkItem(IDM_TOOLBARS_FREEZE);
	else
		m.unCheckItem(IDM_TOOLBARS_FREEZE);

	// pass to active window
	::SendMessage(getActive(),msg, wParam, lParam);

	return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
//
//////////////////////////////////////////////////////////////////////////////

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

void MoeWnd::OnFileNew()
{
	mol::punk<IMoeDocument> doc;
	docs()->New(&doc);
}


void MoeWnd::OnFileNewUFS()
{
	mol::punk<IMoeDocument> doc;
	docs()->NewUserForm(&doc);
}


void MoeWnd::OnFileNewRTF()
{
	mol::punk<IMoeDocument> doc;
	docs()->NewRTFDocument(&doc);
}
//////////////////////////////////////////////////////////////////////////////
//
// Open from file and Create new child window 
//
//////////////////////////////////////////////////////////////////////////////

void MoeWnd::OnFileOpen()
{
	mol::punk<IMoeDocument> doc;
	moeDialogs->Open(0,&doc);
}

void MoeWnd::OnRecentItems()
{
	// click on recent items list - retrieve filename
	int selected = mol::Ribbon::handler(RibbonMRUItems)->index();
	mol::string f = mol::Ribbon::handler(RibbonMRUItems)->recent_items()[selected].first;

	mol::punk<IMoeDocument> doc;
	docs()->Open( mol::bstr(f), &doc );
}




//////////////////////////////////////////////////////////////////////////////
//
// Open new Dir from folder browser
//
//////////////////////////////////////////////////////////////////////////////

void MoeWnd::OnFileOpenDir()
{
	mol::punk<IMoeDocument> doc;
	moeDialogs->OpenDir(&doc);
}

void MoeWnd::OnFileOpenHex()
{
	mol::FilenameDlg dlg(*this);	
	if ( IDOK == dlg.dlgOpen(OFN_READONLY|OFN_EXPLORER) )
	{
		bool result = docs()->open( dlg.fileName(), MOE_DOCTYPE_HEX,-1, dlg.readOnly(), 0 );
		if (!result)
		{
			::MessageBox(*this,dlg.fileName().c_str(),_T("failed to load"),MB_ICONERROR);
		}
		statusBar()->status(dlg.fileName());
	}
}


void MoeWnd::OnFileOpenHtml()
{	
	if ( IDOK == urlDlg()->doModal( IDD_DIALOG_URL, *this ) )
	{
		if ( !urlDlg()->url.empty() )
		{
			if (  urlDlg()->url.substr(0,6) == _T("ssh://") ||  urlDlg()->url.substr(0,10) == _T("moe-ssh://") )
			{
				bool result = docs()->open( urlDlg()->url, MOE_DOCTYPE_DOC, -1, false, 0 );
				return;
			}
			bool result = docs()->open( urlDlg()->url, MOE_DOCTYPE_HTML, -1, true, 0 );
			if (!result)
			{
				::MessageBox(*this,urlDlg()->url.c_str(),_T("failed to load"),MB_ICONERROR);
			}
			statusBar()->status(urlDlg()->url);
		}
	}
}

/*
void MoeWnd::OnTreeOpen()
{
	mol::punk<IShellTree> tree(treeWnd()->oleObject);
	if ( tree )
	{
		mol::bstr path;
		tree->get_Selection(&path);
		mol::string fn = path.toString();
		if ( mol::Path::isDir( fn) || fn.substr(0,2) == _T("::") )
		{
			statusBar()->status(fn);
			bool result = ::docs()->open(0,fn,Docs::PREF_TXT,false,0);

			if (!result)
			{
				statusBar()->status( mol::string(_T("failed to load ")) + fn);
				return;
			}
			return;
		}
		mol::FilenameDlg dlg(*moe());
		dlg.setFilter( InFilesFilter );	
		dlg.fileName(fn);
		if ( IDOK != dlg.dlgOpen(OFN_ALLOWMULTISELECT | OFN_EXPLORER) )
			return;

		int s = dlg.selections();
		int p = dlg.index();
		for ( int i = 0; i < s; i++ )
		{
			mol::string f = dlg.fileName(i);
			statusBar()->status(f);


			bool result = ::docs()->open(0,f,(Docs::InFiles)(p-1 >=0 ? p-1 :0),false,0);

			if (!result)
			{
				statusBar()->status( mol::string(_T("failed to load ")) + f);
				return;
			}
		}
	}
	return;

}
*/
//////////////////////////////////////////////////////////////////////////////
//
// User selected Exit from main Menu - kill app
//
//////////////////////////////////////////////////////////////////////////////

void MoeWnd::OnFileExit()
{
	Exit();
}


//////////////////////////////////////////////////////////////////////////////
//
//
//////////////////////////////////////////////////////////////////////////////

LRESULT MoeWnd::OnEditCut(UINT msg, WPARAM wParam, LPARAM lParam)
{
	if ( treeWnd()->hasFocus() )
	{
		punk<IShellTree> tree(treeWnd()->oleObject);
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

LRESULT MoeWnd::OnEditCopy(UINT msg, WPARAM wParam, LPARAM lParam)
{
	if ( treeWnd()->hasFocus() )
	{
		punk<IShellTree> tree(treeWnd()->oleObject);
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
LRESULT MoeWnd::OnEditPaste(UINT msg, WPARAM wParam, LPARAM lParam)
{
	if ( treeWnd()->hasFocus() )
	{
		punk<IShellTree> tree(treeWnd()->oleObject);
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

void MoeWnd::OnFind()
{
    searchDlg()->findText(*this);
}


//////////////////////////////////////////////////////////////////////////////

void MoeWnd::OnReplace()
{
    searchDlg()->replaceText(*this);
}

//////////////////////////////////////////////////////////////////////////////
//
// Settings
//
//////////////////////////////////////////////////////////////////////////////

void MoeWnd::OnEditSettings()
{
	moeConfig->EditSettings();
}

void MoeWnd::OnEditPrefs()
{
	moeConfig->EditPreferences();
}


//////////////////////////////////////////////////////////////////////////////

void MoeWnd::OnFx(int code, int id, HWND ctrl)
{
	int fx =id-IDM_F1+1;

	mol::ostringstream oss;
	oss << _T("fx\\F") << fx << _T(".js");

	mol::string file = findFile(oss.str());
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

#define connect_cmd_handler(cmd,mfp)											\
int mol_connect_cmd##cmd##__()													\
{																				\
	IMsgMapHandler* handler = make_handler(&mfp);								\
	handler->connect_cmd( cmd );												\
	return 0;																	\
}																				\
int mol_connect_cmd##cmd##__initonce__ = mol_connect_cmd##cmd##__();


connect_cmd_handler(IDM_VIEW_DIRVIEW,MoeWnd::OnShowDirView)
void MoeWnd::OnShowDirView ()
{
	Menu m(*this);
	if ( !treeWnd()->isVisible() )
	{
		treeWnd()->show(SW_SHOW);
		::InvalidateRect(mdiClient(),0,TRUE);
	}
	else
	{
		treeWnd()->show(SW_HIDE);
	}
	OnLayout(0,0,0);
}

//////////////////////////////////////////////////////////////////////////////
//
// show/hide Tool bars
//
//////////////////////////////////////////////////////////////////////////////

void MoeWnd::OnShowToolBar (int code, int id, HWND ctrl)
{
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
	OnLayout(0,0,0);
}

//////////////////////////////////////////////////////////////////////////////
//
// freeze toolbars
//
//////////////////////////////////////////////////////////////////////////////

void MoeWnd::OnFreezeToolBar ()
{
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
}
//////////////////////////////////////////////////////////////////////////////
//
// OnHelpAbout - show help dialog
//
//////////////////////////////////////////////////////////////////////////////

void MoeWnd::OnHelpAbout()
{
	statusBar()->status(_T("help"));

	mol::string p( mol::app<MoeApp>().getModulePath() );
	mol::string help = mol::Path::parentDir(p) + _T("\\doc\\index.html");

	long left, top;
	moeView->get_Left(&left);
	moeView->get_Top(&top);

	mol::punk<IMoeDocument> doc;
	docs()->OpenHtmlFrame( bstr(help), &doc );
}





//////////////////////////////////////////////////////////////////////////////
//
// TabControl Events
//
//////////////////////////////////////////////////////////////////////////////

mol::string dirPathFromChildHWND(HWND hwnd)
{
	// get mdi child from HWND
	mol::MdiChild* mdi = mol::wndFromHWND<mol::MdiChild>(hwnd);
	if (!mdi) 
		return _T("");

	// cast mdi child to IMoeDocument
	IMoeDocument* doc = dynamic_cast<IMoeDocument*>(mdi);
	if (!doc)
		return _T("");

	mol::bstr path;
	if ( doc->get_FilePath(&path) != S_OK )
		return _T("");
	return mol::Path::parentDir(mol::toString(path));
}

void MoeWnd::OnTabCtrl(NMHDR* notify )
{
    if ( notify->code  == TCN_SELCHANGE )
    {
        int sel = (int)tab()->selection();
		mol::TabCtrl::TabCtrlItem* c = tab()->getTabCtrlItem(sel);
		HWND h = (HWND)(c->lparam);
		if ( !h ) 
			return;

		mol::MdiChild* mdi = mol::wndFromHWND<mol::MdiChild>(h);
		if (!mdi) 
			return;

		mdi->activate();
        return ;
    }		

    if ( notify->code  == NM_RCLICK   )
    {
		// check whether right click hit a tab
		int i = tab()->hitTest();
		if ( i == -1 )
			return ;

		// get right click tab item and retrieve HWND
		mol::TabCtrl::TabCtrlItem* c = (mol::TabCtrl::TabCtrlItem*)tab()->getTabCtrlItem(i);
		HWND h = (HWND)c->lparam;
		if ( !h ) 
			return;

		// current mouse pos
		POINT pt;
		::GetCursorPos(&pt);

		// display context menut
		mol::Menu sub = mol::UI().SubMenu(IDM_MENU_TAB,IDM_TAB);
		int id = sub.returnTrackPopup(*this,pt.x-10,pt.y-10);
		switch ( id )
		{
			case IDM_VIEW_CLOSE:
			{
				::PostMessage( h, WM_CLOSE, 0, 0 );
				break;
			}
			case IDM_TAB_CLOSEALLBUTTHIS:
			{
				HWND m = h;
				for ( int i = 0; i < count(); i++ )
				{
					if ( childAt(i) != m )
						::PostMessage( childAt(i), WM_CLOSE, 0, 0 );
				}
				break;
			}
			case IDM_TAB_RELOADTAB:
			{
				::PostMessage( h, WM_COMMAND, IDM_EDIT_UPDATE, 0 );

				break;
			}
			case IDM_FILE_SAVE:
			{
				::PostMessage( h, WM_COMMAND, IDM_FILE_SAVE, 0 );
				break;
			}
			case IDM_TAB_DIRTAB:
			{
				docs()->OpenDir( mol::bstr(dirPathFromChildHWND(h)), 0 );
				break;
			}
			case IDM_TAB_JUMPTAB:
			{
				mol::punk<IShellTree> tree(treeWnd()->oleObject);
				if ( tree )
				{
					tree->put_Selection( mol::bstr(dirPathFromChildHWND(h)) );
				}
				break;
			}
		}
		return ;
	}
	return ;
}

//////////////////////////////////////////////////////////////////////////////
//
// OnToolbarRightClick
//
//////////////////////////////////////////////////////////////////////////////

void MoeWnd::OnToolbarRightClick(NMHDR* notify )
{
	if ( toolBarFrozen_ )
		return ;

	switch ( notify ->idFrom )
	{
		case IDC_TOOLBARS_FILEBAR    :
		case IDC_TOOLBARS_EDITBAR    :
		case IDC_TOOLBARS_TOOLBAR    :
		case IDC_TOOLBARS_SETTINGBAR :
		case IDC_TOOLBARS_VIEWBAR    :
		case IDC_TOOLBARS_USERBAR    :
			::SendMessage( mol::UI().hWnd((unsigned int)notify->idFrom), TB_CUSTOMIZE, 0,0 );
	}
}

//////////////////////////////////////////////////////////////////////////////
//
// OnSyntax
//
//////////////////////////////////////////////////////////////////////////////

void MoeWnd::OnSyntax(int code, int id, HWND ctrl)
{
	if ( code == CBN_SELCHANGE )
	{
		int sel = syntax()->getCurSel();
		::PostMessage(getActive(),WM_COMMAND,IDM_LEXER_PLAIN+sel,(LPARAM)ctrl);
	}
}

/////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall MoeWnd::IOleInPlaceFrame_SetStatusText(LPCOLESTR txt)
{
	if ( !txt )
		statusBar()->status(_T(""));
	else
		statusBar()->status( mol::toString(txt) );
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

	// if we have ribbon, maximize it before persistence
	if ( mol::Ribbon::ribbon()->enabled())
	{
		mol::Ribbon::ribbon()->maximize();
	}

	// save persistent info
	mol::string p(appPath() + _T("\\") + _T("ui.xmo"));
	Storage store;
	if ( store.create(p) )
	{
		store.clsid(this->getCoClassID());
		punk<IPersistStorage> ps(this);
		if ( ps )
		{
			ps->Save(store,FALSE);
			destroy();
			return S_OK;
		}
	}

	// harakiri
	destroy();
	return S_OK;
}


//////////////////////////////////////////////////////////////////////////////
// Persistence
//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall MoeWnd::Save(	 IStorage * pStgSave, BOOL fSameAsLoad )
{
	// save moe UI settings
	punk<IStream> stream;
	if ( S_OK == pStgSave->CreateStream( L"UI", STGM_CREATE|STGM_READWRITE|STGM_SHARE_EXCLUSIVE,0,0,&stream) )
	{
		this->Save(stream,FALSE);

		punk<IPersistStorage> ps(config());
		if ( ps )
		{
			HRESULT hr = ps->Save(pStgSave,fSameAsLoad);
			if ( hr != S_OK )
				return hr;
		}
	}
	stream.release();

	// save moe default settings
	if ( S_OK == pStgSave->CreateStream( L"DEFAULTS", STGM_CREATE|STGM_READWRITE|STGM_SHARE_EXCLUSIVE,0,0,&stream) )
	{
		mol::punk<IPersistStream> ps;

		if ( S_OK == moeConfig.queryInterface(&ps))
		if ( ps )
		{
			ps->Save(stream,TRUE);
		}
	}

	// save Ribbon UI state (if applicable)
	mol::Ribbon::ribbon()->save(pStgSave);
	return S_OK;
}


HRESULT __stdcall MoeWnd::Load(	 IStorage * pStgLoad)
{
	static LPCOLESTR con = OLESTR("UI");
	static LPCOLESTR def = OLESTR("DEFAULTS");

	// open defaults stream
	punk<IStream> stream;
	HRESULT hr = pStgLoad->OpenStream( def, NULL, STGM_DIRECT|STGM_SHARE_EXCLUSIVE,0,&stream);
	if ( stream && hr == S_OK )
	{
		mol::punk<IMoeConfig> moeConf;
		if ( S_OK == this->get_Config(&moeConf) )
		{
			mol::punk<IPersistStream> ps(moeConf);
			if ( ps )
			{
				ps->Load(stream);
			}
		}		
	}

	stream.release();

	// open UI stream
	hr = pStgLoad->OpenStream( con, NULL, STGM_DIRECT|STGM_SHARE_EXCLUSIVE,0,&stream);
	if ( !stream || (hr != S_OK) )
		return S_OK;

	// load UI config
	punk<IPersistStreamInit> ipsi(this);
	if ( !ipsi )
		return S_OK;

	setDirty(FALSE);
	hr = ipsi->Load(stream);
	if ( hr != S_OK )
		return S_OK;
	
	stream.release();

	// load user settings stream
	punk<IPersistStorage> ps(config());
	if ( !ps )
		return S_OK;

	hr = ps->Load(pStgLoad);
	if ( hr != S_OK )
		return S_OK;

	// DEBUG: enable/disable creation of new top level user setting items
	//config()->put_ChildrenAllowed(VARIANT_FALSE);

	// freeze top level items
	freezeConfig(_T("shortcuts"));
	freezeConfig(_T("scripts"));
	freezeConfig(_T("batches"));
	freezeConfig(_T("forms"));

	config()->put_IsDirty(VARIANT_FALSE);

	////////////////////////////////////////////

	// show Ribbon UI ?
	bool showRibbon = false;

	// look at config data for ribbon display
	mol::punk<ISetting> set;
	hr = config()->Item( mol::variant("Ribbon"), &set);
	if ( hr == S_OK )
	{
		mol::bstr val;
		hr = set->get_Value(&val);
		if ( hr == S_OK )
		{
			if ( val.tostring() == "On" )
			{
				showRibbon = true;
			}
		}
	}

	if ( !showRibbon ) 
		return S_OK;

	// show the ribbon if avail and load persistent ribbon settings from store
	initRibbon(pStgLoad);
	return S_OK;
}

void  MoeWnd::freezeConfig(const mol::string& key)
{
	// freeze top level items
	punk<ISetting> s;
	if ( S_OK == config()->Item(variant(key),&s) )
	{
		if ( s )
		{
			s->put_KeyReadOnly(VARIANT_TRUE);
			s->put_ValueReadOnly(VARIANT_TRUE);
		}
	}
}

void  MoeWnd::initRibbon(IStorage* store)
{
	// show the Ribbon
	Ribbon::ribbon()->show(*this);

	if ( !Ribbon::ribbon()->enabled() )
		return;

	// load persist Ribbon state
	mol::Ribbon::ribbon()->load(store);

	// setup handlers with special handling

	// syntax select dropdown handler - populate from toolbar combobox values 
	std::vector<mol::string> vs;
	for ( int i = 0; i < syntax()->getCount(); i++ )
	{
		vs.push_back( syntax()->getString(i)  );
	}
	mol::Ribbon::handler(RibbonSelectLanguage)->items(vs);

	// encoding dropdown handler
	std::vector<mol::string> ve;

	for ( size_t i = 0; i < codePages_.size(); i++)
	{
		ve.push_back(codePages_[i].second );
	}

	mol::Ribbon::handler(RibbonEncoding)->items(ve);

	// tab size spinner
	mol::Ribbon::handler(RibbonTabSize)->decimalPlaces(0);

	// bytes shown dropdown handler for hex view	
	std::vector<mol::string> vb;
	vb.push_back(_T("16 bytes"));
	vb.push_back(_T("20 bytes"));
	vb.push_back(_T("24 bytes"));
	vb.push_back(_T("28 bytes"));
	vb.push_back(_T("32 bytes"));
	mol::Ribbon::handler(RibbonBytesShown)->items(vb);

	// Check the Show Dir View Handler
	mol::Ribbon::handler(RibbonShowDirView)->check(true);

	reBar()->show(SW_HIDE);
	// default Ribbon mode
	Ribbon::ribbon()->mode(0);
	Ribbon::ribbon()->flush();
}

HRESULT __stdcall MoeWnd::Load( LPSTREAM pStm) 
{
	data_.copyFrom(pStm);

	urlDlg()->Load(pStm);
	reBar()->Load(pStm);

	ULONG len = 0;
	pStm->Read( &toolBarFrozen_, sizeof(BYTE),  &len );
	reBar()->freeze(toolBarFrozen_!= 0);

	return S_OK;
}



HRESULT __stdcall MoeWnd::Save( LPSTREAM pStm,BOOL fClearDirty)
{
	if ( mol::Ribbon::ribbon()->enabled() )
	{
		// if we have ribbon, write url dlg config to data_
		data_.reset();
		urlDlg()->Save(data_,fClearDirty);
		data_.reset();
		// and keep all the old school toolbar state as is
		HRESULT hr = data_.copyTo( pStm );		
		return S_OK;
	}

	// no ribbon - save urldlg and toolbar state
	urlDlg()->Save(pStm,fClearDirty);
	reBar()->Save(pStm, fClearDirty);

	ULONG written = 0;
	pStm->Write( &toolBarFrozen_, sizeof(BYTE),		 &written );

	return S_OK;
}



HRESULT __stdcall MoeWnd::GetSizeMax( ULARGE_INTEGER *pCbSize)
{
	urlDlg()->GetSizeMax(pCbSize);
	reBar()->GetSizeMax(pCbSize);
	pCbSize->QuadPart += sizeof(ULONG)*2 + sizeof(BYTE)*3;
	punk<IPersistStream> ps(config());
	if ( ps )
	{
		ULARGE_INTEGER s;
		s.QuadPart = 0;
		if ( S_OK == ps->GetSizeMax(&s) )
			pCbSize->QuadPart += s.QuadPart;
	}
	return S_OK;
}

HRESULT __stdcall MoeWnd::InitNew() 
{
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
