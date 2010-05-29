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
#include "ole/Rib.h"
#include "shared.h"
#include "Ribbonres.h"

using namespace mol::io;
using namespace mol;
using namespace mol::ole;
using namespace mol::win;


mol::TCHAR  InFilesFilter[]   = _T("open text files *.*\0*.*\0open UTF-8 text files *.*\0*.*\0open HTML files *.*\0*.*\0open file in hexviewer *.*\0*.*\0\0");

//////////////////////////////////////////////////////////////////////////////
//
// MoeWnd Constructor - prepare Frame window object
// note children are constructed in OnCreate()
//
//////////////////////////////////////////////////////////////////////////////

MoeWnd::MoeWnd() 
{
	ODBGS("MoeWnd::MoeWnd()");

	// registered instance
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

	//wpPrev_= { sizeof(wpPrev_) };
	//wpPrev_ = { sizeof(wpPrev_) };

	// don't erase window background, avoid flicker
    eraseBackground_ = 0;

	// tell MDI impl where mdi child ids start (enable window menu)
    setFirstChildId(ID_FIRST_CHILD_WND);	

	// set icon
	icon.load(IDI_MOE);
	wndClass().setIcon(icon);		

	moeScript  = new MoeScript::Instance;
	moeDialogs = new MoeDialogs::Instance;
	moeView    = new MoeView::Instance;
	moeConfig  = new MoeConfig::Instance;
}

//////////////////////////////////////////////////////////////////////////////
//
// Framewindow Destructor
//
//////////////////////////////////////////////////////////////////////////////

MoeWnd::~MoeWnd()
{
	if ( NET().aware() && compiler_ )
	{
//		compilerSink()->UnAdvise(compiler_.interface_);
	}

	if ( icon )
		::DestroyIcon(icon);

	ODBGS("~MoeWnd says goodbye");
}


/////////////////////////////////////////////////////////////////////
// Create Instance
/////////////////////////////////////////////////////////////////////



MoeWnd::Instance* MoeWnd::CreateInstance()
{
	ODBGS("MoeWnd::CreateInstance()");

	Instance* moe = new Instance;
	moe->AddRef();

	build_ui<MoeWnd>(moe);

	ODBGS("MoeWnd::CreateInstance() end");
	return moe;
}

//#include <dwmapi.h>

#define MOL_DWM_BB_ENABLE                 0x00000001  // fEnable has been specified
#define MOL_DWM_BB_BLURREGION             0x00000002  // hRgnBlur has been specified
#define MOL_DWM_BB_TRANSITIONONMAXIMIZED  0x00000004  // fTransitionOnMaximized has been specified

typedef struct MOL_DWM_BLURBEHIND
{
    DWORD dwFlags;
    BOOL fEnable;
    HRGN hRgnBlur;
    BOOL fTransitionOnMaximized;
} MOL_DWM_BLURBEHIND, *MOL_PDWM_BLURBEHIND;


HRESULT EnableBlurBehind(HWND hwnd)
{
	typedef HRESULT __stdcall DwmEnableBlurBehindWindow( HWND hWnd, const MOL_DWM_BLURBEHIND* pBlurBehind );

	DwmEnableBlurBehindWindow* debbw = (DwmEnableBlurBehindWindow*)mol::dllFunc( _T("dwmapi.dll"), _T("DwmEnableBlurBehindWindow") );

	if (!debbw)
		return E_FAIL;

    // Create and populate the blur-behind structure.
    MOL_DWM_BLURBEHIND bb = {0};

    // Specify blur-behind and blur region.
    bb.dwFlags = MOL_DWM_BB_ENABLE;
    bb.fEnable = true;
    bb.hRgnBlur = NULL;

    // Enable blur-behind.
    HRESULT hr = debbw(hwnd, &bb);
    if (SUCCEEDED(hr))
    {
        // ...
    }
    return hr;
}
/////////////////////////////////////////////////////////////////////

void MoeWnd::OnCreate()
{
	// the main window and GUI elements have been created
	// initialize critical GUI parts now

	ODBGS("MoeWnd::OnCreate()");
	getClientRect(clientRect_);

	// register us as active instance
	HRESULT hr = ::RegisterActiveObject( (IMoe*)this,CLSID_Application,ACTIVEOBJECT_STRONG,&activeObj_);

	// hide the progress window
	progress()->show(SW_HIDE);

	// hook up tree window COM events
	treeWndSink()->Advise(treeWnd()->oleObject);

	// update the menu
	::DrawMenuBar(*this);

	// ------------------  //

    // load persist UI state

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
	ps->Load( store );

	//hr = EnableBlurBehind(*this);
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
	/*
    int i = index(activated);
	mol::MdiChild* mdi = mol::wndFromHWND<mol::MdiChild>(childAt(i));
	if ( mdi )
	{
		IDoc* doc = dynamic_cast<IDoc*>(mdi);
		if ( doc )
		{
			mol::bstr fn;
			if ( S_OK == doc->get_Filename(&fn) && fn.bstr_ )
			{
				tab()->select( fn.toString() );
				IOleInPlaceFrame_SetStatusText(fn);
				
			}
		}
	}
	*/
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

	if ( !NET().aware() )
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
		treeWnd()->postMessage(msg,wParam,lParam);
		return 0;
	}
    ::SendMessage(getActive(),msg,wParam,lParam);
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

//////////////////////////////////////////////////////////////////////////////
//
// Open from file and Create new child window 
//
//////////////////////////////////////////////////////////////////////////////

void MoeWnd::OnFileOpen()
{
	mol::punk<IMoeDocument> doc;
	moeDialogs->Open(&doc);
}

void MoeWnd::OnRecentItems()
{
	// click on recent items list - retrieve filename
	// and open utilizing COM api
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
	if ( dlg.dlgOpen(OFN_READONLY|OFN_EXPLORER) )
	{
		bool result = docs()->open( 0, dlg.fileName(), Docs::PREF_HEX, dlg.readOnly(), 0 );
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
			bool result = docs()->open( 0, urlDlg()->url, Docs::PREF_HTML, true, 0 );
			if (!result)
			{
				::MessageBox(*this,urlDlg()->url.c_str(),_T("failed to load"),MB_ICONERROR);
			}
			statusBar()->status(urlDlg()->url);
		}
	}
}

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


void MoeWnd::OnFind()
{
    searchDlg()->findText(*this);
}

void MoeWnd::OnReplace()
{
    searchDlg()->replaceText(*this);
}

//////////////////////////////////////////////////////////////////////////////
//
// Cancel
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



/*
LRESULT MoeWnd::OnExecNet(UINT msg, WPARAM wParam, LPARAM lParam)
{
	punk<IDoc> doc;
	if ( S_OK != ->get_ActiveDoc(&doc) )
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
//						->dotScript(script);
					}
				}
			}
		}
	}	
	return 0;
}
*/

void MoeWnd::OnFx(int code, int id, HWND ctrl)
{
	int fx =id-IDM_F1+1;

	mol::ostringstream oss;
	oss << _T("\\fx\\F") << fx << _T(".js");

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

void MoeWnd::OnTabCtrl(NMHDR* notify )
{
    if ( notify->code  == TCN_SELCHANGE )
    {
        int sel = (int)tab()->selection();
		mol::string path = (mol::TCHAR*)tab()->getItemLPARAM(sel);

		mol::punk<IMoeDocument> doc;
		if ( S_OK == docs()->Item( mol::variant(path), &doc ) )
		{
			if ( doc )
			{
				mol::punk<IMoeDocumentView> view;
				HRESULT hr = doc->get_View(&view);
				if ( hr == S_OK )
				{
					view->Activate();
				}
			}
		}
        return ;
    }		

    if ( notify->code  == NM_RCLICK   )
    {
		int i = tab()->hitTest();
		if ( i == -1 )
			return ;

		mol::string path = (mol::TCHAR*)tab()->getItemLPARAM(i);
		mol::punk<IMoeDocument> doc;
		if ( S_OK != docs()->Item(variant(path),&doc) && doc )
			return ;

		mol::MdiChild* mdi = docs()->child(path);

		long t;
		if ( !doc || (S_OK != doc->get_Type(&t) ) )
			return ;

		mol::Menu sub = mol::UI().SubMenu(IDM_MENU_TAB,IDM_TAB);

		POINT pt;
		::GetCursorPos(&pt);
		int id = sub.returnTrackPopup(*this,pt.x-10,pt.y-10);
		switch ( id )
		{
			case IDM_VIEW_CLOSE:
			{
				::PostMessage( *mdi, WM_CLOSE, 0, 0 );
				break;
			}
			case IDM_TAB_CLOSEALLBUTTHIS:
			{
				HWND m = (HWND)*mdi;
				for ( int i = 0; i < count(); i++ )
				{
					if ( childAt(i) != m )
						::PostMessage( childAt(i), WM_CLOSE, 0, 0 );
				}
				break;
			}
			case IDM_TAB_RELOADTAB:
			{
				::PostMessage( *mdi, WM_COMMAND, IDM_EDIT_UPDATE, 0 );

				break;
			}
			case IDM_FILE_SAVE:
			{
				::PostMessage( *mdi, WM_COMMAND, IDM_FILE_SAVE, 0 );
				break;
			}
			case IDM_TAB_DIRTAB:
			{
				mol::bstr dirname;
				if ( doc->get_FilePath(&dirname) == S_OK )
				{
					if ( t != 2 ) 
					{
						mol::bstr dir( mol::Path::parentDir(dirname.toString()) );
						docs()->OpenDir(dir,0);
					}
				}
				break;
			}
			case IDM_TAB_JUMPTAB:
			{
				mol::bstr fn;
				if ( doc->get_FilePath(&fn) == S_OK )
				{
					mol::bstr dir( mol::Path::parentDir(fn.toString()) );

					mol::punk<IShellTree> tree(treeWnd()->oleObject);
					if ( tree )
					{
						tree->put_Selection(dir);
					}
				}
				break;
			}
		}
		return ;
	}
	return ;
}


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

void MoeWnd::OnSyntax(int code, int id, HWND ctrl)
{
	if ( code == CBN_SELCHANGE )
	{
		int sel = syntax()->getCurSel();
		::PostMessage(getActive(),WM_COMMAND,IDM_LEXER_PLAIN+sel,(LPARAM)ctrl);
	}
}

//////////////////////////////////////////////////////////////////////////////
//
//		helpers
//
////////////////////////////////////////////////////////////////////////////// 

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

	return moeView->QueryInterface( IID_IMoeView, (void**) d );
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

	return moeConfig->QueryInterface( IID_IMoeConfig, (void**) d );
}


HRESULT __stdcall MoeWnd::get_Script( IMoeScript **d)
{
	if (!d)
		return E_INVALIDARG;
	*d = 0;

	return moeScript->QueryInterface( IID_IMoeScript, (void**) d );
}


HRESULT __stdcall MoeWnd::get_Dialogs( IMoeDialogs **d)
{
	if (!d)
		return E_INVALIDARG;
	*d = 0;

	return moeDialogs->QueryInterface( IID_IMoeDialogs, (void**) d );
}


HRESULT __stdcall MoeWnd::Exit()
{
	// tear down open documents gently
	long cnt = 0;
	HRESULT hr = docs()->get_Count(&cnt);
	if( hr != S_OK )
		return hr;

	long i = cnt;
	while ( i > 0 )
	{
		mol::punk<IMoeDocument> doc;
		hr = docs()->Item( mol::variant(0), &doc );
		if( hr != S_OK )
			return hr;

		mol::punk<IMoeDocumentView> view;
		hr = doc->get_View(&view);
		if( hr != S_OK )
			return S_FALSE;

		hr = view->Close();
		if( hr != S_OK )
			return S_FALSE;
		i--;
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

/*
/////////////////////////////////////////////////////////////////////
HRESULT __stdcall MoeWnd::get_Docs( IDocs** d)
{			
	if ( d )
	{
		return docs()->QueryInterface(IID_IDocs,(void**)d);
	}
	return S_OK;
}
/////////////////////////////////////////////////////////////////////

HRESULT __stdcall MoeWnd::get_ActiveDoc( IDoc** doc)
{			
	if ( doc )
	{
		*doc  = NULL;
		HWND wnd = getActive();
		mol::MdiChild* mdi = mol::wndFromHWND<mol::MdiChild>(wnd);
		if ( mdi )
		{
			IDoc* d = dynamic_cast<IDoc*>(mdi);
			if ( d )
			{
				return d->QueryInterface( IID_IDoc, (void**) doc );
			}
		}
	}
	return S_FALSE;
}
/////////////////////////////////////////////////////////////////////


HRESULT __stdcall MoeWnd::put_ShowTreeView(  VARIANT_BOOL vb)
{
	if ( vb == VARIANT_TRUE )
	{
		treeWnd()->show(SW_SHOW);
		::InvalidateRect(mdiClient(),0,TRUE);
		statusBar()->status(_T("Tree view visible"));
	}
	if ( vb == VARIANT_FALSE )
	{
		treeWnd()->show(SW_HIDE);
		statusBar()->status(_T("Tree view hidden"));
	}

	OnLayout(0,0,0);
	return S_OK;
}

HRESULT __stdcall MoeWnd::get_ShowTreeView(  VARIANT_BOOL* vb)
{
	if ( vb )
	{
		if ( treeWnd()->isVisible() )
			*vb = VARIANT_TRUE;
		else
			*vb = VARIANT_FALSE;
	}
	return S_OK;
}

/////////////////////////////////////////////////////////////////////

HRESULT __stdcall  MoeWnd::get_TreeView( IDispatch** tree)
{
	if ( tree  )
	{
		return treeWnd()->oleObject.queryInterface(IID_IDispatch,(void**)tree);
	}
	return S_OK;
}

/////////////////////////////////////////////////////////////////////
HRESULT __stdcall  MoeWnd::put_SysType( long type)
{
	systype_ = type;

	if ( type == 0 )
		statusBar()->status(_T("new sysmode: UNIX"));	
	else
		statusBar()->status(_T("new sysmode: Windows"));
	return S_OK;
}

HRESULT __stdcall  MoeWnd::get_SysType( long* type)
{
	if ( type )
		*type = systype_;
	return S_OK;
}

/////////////////////////////////////////////////////////////////////
HRESULT __stdcall  MoeWnd::put_Encoding( long enc)
{
	encoding_ = enc;
	switch ( enc )
	{
		case SCINTILLA_ENCODING_ANSI :
		{
			statusBar()->status(_T("new encoding: ANSI"));	
			break;
		}
		case SCINTILLA_ENCODING_UTF8 :
		{
			statusBar()->status(_T("new encoding: UTF8"));	
			break;
		}
		case SCINTILLA_ENCODING_UTF16 :
		{
			statusBar()->status(_T("new encoding: UTF16"));	
			break;
		}
	}
	return S_OK;
}

HRESULT __stdcall  MoeWnd::get_Encoding( long* enc)
{
	if ( enc )
		*enc = encoding_;
	return S_OK;
}

/////////////////////////////////////////////////////////////////////

HRESULT __stdcall  MoeWnd::put_TabUsage( VARIANT_BOOL vbTabUsage)
{
	tabUsage_ = vbTabUsage;
	if ( vbTabUsage == VARIANT_TRUE )
		statusBar()->status(_T("use tabs"));	
	else
		statusBar()->status(_T("convert tabs to spaces"));
	return S_OK;
}

HRESULT __stdcall  MoeWnd::get_TabUsage( VARIANT_BOOL* vbTabUsage)
{
	if ( vbTabUsage )
		*vbTabUsage = tabUsage_;
	return S_OK;
}
/////////////////////////////////////////////////////////////////////

HRESULT __stdcall  MoeWnd::put_TabIndents( VARIANT_BOOL vbTabIndents)
{
	tabIndents_ = vbTabIndents;
	if ( vbTabIndents == VARIANT_TRUE )
		statusBar()->status(_T("tab indents"));	
	else
		statusBar()->status(_T("tab doesn't indent"));
	return S_OK;
}

HRESULT __stdcall  MoeWnd::get_TabIndents( VARIANT_BOOL* vbTabIndents)
{
	if ( vbTabIndents )
		*vbTabIndents = tabIndents_;
	return S_OK;
}

/////////////////////////////////////////////////////////////////////

HRESULT __stdcall  MoeWnd::put_BackSpaceUnindents( VARIANT_BOOL vbBackSpaceIndents)
{
	backSpaceUnIndents_ = vbBackSpaceIndents;
	if ( vbBackSpaceIndents == VARIANT_TRUE )
		statusBar()->status(_T("backspace unindents"));	
	else
		statusBar()->status(_T("backspace doesn't unindent"));
	return S_OK;
}

HRESULT __stdcall  MoeWnd::get_BackSpaceUnindents(  VARIANT_BOOL* vbBackSpaceIndents)
{
	if ( vbBackSpaceIndents )
		*vbBackSpaceIndents = backSpaceUnIndents_;
	return S_OK;
}

/////////////////////////////////////////////////////////////////////

HRESULT __stdcall  MoeWnd::put_TabWidth( long width)
{
	tabwidth_ = width;
	return S_OK;
}

HRESULT __stdcall  MoeWnd::get_TabWidth(  long* width)
{
	if ( width )
	{
		*width = tabwidth_;
	}
	return S_OK;
}

/////////////////////////////////////////////////////////////////////
HRESULT __stdcall  MoeWnd::put_Syntax( long type)
{
	syntax_ = type;
	return S_OK;
}

HRESULT __stdcall  MoeWnd::get_Syntax( long* type)
{
	if ( type )
	{
		*type = syntax_;
	}
	return S_OK;
}


HRESULT __stdcall  MoeWnd::get_ConfigPath( BSTR* p)
{
	if ( !p ) 
		return E_POINTER;
	mol::string tmp( mol::Path::parentDir(mol::App().getAppPath()));
	*p = ::SysAllocString(mol::towstring(tmp).c_str());
	return S_OK;
}

HRESULT __stdcall  MoeWnd::get_ModulePath( BSTR* p)
{
	if ( !p ) 
		return E_POINTER;
	mol::string tmp( mol::Path::parentDir(mol::App().getModulePath()));
	*p = ::SysAllocString(mol::towstring(tmp).c_str());
	return S_OK;
}




void MoeWnd::fullScreen(HWND hwnd)
{
  DWORD dwStyle = GetWindowLong(hwnd, GWL_STYLE);
  if (dwStyle & WS_OVERLAPPEDWINDOW) {
    MONITORINFO mi = { sizeof(mi) };
    if (GetWindowPlacement(hwnd, &wpPrev_) &&
        GetMonitorInfo(MonitorFromWindow(hwnd,
                       MONITOR_DEFAULTTOPRIMARY), &mi)) {
      SetWindowLong(hwnd, GWL_STYLE,
                    dwStyle & ~WS_OVERLAPPEDWINDOW);
      SetWindowPos(hwnd, HWND_TOP,
                   mi.rcMonitor.left, mi.rcMonitor.top,
                   mi.rcMonitor.right - mi.rcMonitor.left,
                   mi.rcMonitor.bottom - mi.rcMonitor.top,
                   SWP_NOOWNERZORDER | SWP_FRAMECHANGED);
    }
  } else {
    SetWindowLong(hwnd, GWL_STYLE,
                  dwStyle | WS_OVERLAPPEDWINDOW);
    SetWindowPlacement(hwnd, &wpPrev_);
    SetWindowPos(hwnd, NULL, 0, 0, 0, 0,
                 SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER |
                 SWP_NOOWNERZORDER | SWP_FRAMECHANGED);
  }

}


HRESULT __stdcall MoeWnd::put_Fullscreen( VARIANT_BOOL vbFullScreen)
{
	fullScreen_ = vbFullScreen;
	fullScreen(*this);
	return S_OK;
}

HRESULT __stdcall MoeWnd::get_Fullscreen( VARIANT_BOOL* vbFullScreen)
{
	if ( !vbFullScreen )
		return E_INVALIDARG;

	fullScreen(*this);
	*vbFullScreen = fullScreen_;
	return S_OK;
}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////
// methods:
/////////////////////////////////////////////////////////////////////

HRESULT __stdcall  MoeWnd::New(IDoc** doc)
{
	return docs()->newFile(doc) ? S_OK : S_FALSE;
}

HRESULT __stdcall  MoeWnd::Open( BSTR p, IDoc** doc)
{
	bool result = docs()->open(0, bstr(p).toString(), Docs::PREF_TXT, false, doc );
	if (!result)
	{
		::MessageBox(*this,bstr(p).toString().c_str(),_T("failed to load"),MB_ICONERROR);
	}
	statusBar()->status(bstr(p).toString());
	return S_OK;
}

HRESULT __stdcall  MoeWnd::OpenUTF8( BSTR p, IDoc** doc)
{
	bool result = docs()->open(0, bstr(p).toString(), Docs::PREF_UTF8, false, doc );
	if (!result)
	{
		::MessageBox(*this,bstr(p).toString().c_str(),_T("failed to load"),MB_ICONERROR);
	}
	statusBar()->status(bstr(p).toString());
	return S_OK;
}

HRESULT __stdcall  MoeWnd::ChooseDir( BSTR* d)
{
	if ( !d )
		return E_INVALIDARG;

	mol::string p = browseForFolder(*this);

	*d = ::SysAllocString( mol::towstring(p).c_str() );
	if ( p != _T("") )
	{
		statusBar()->status(p);
	}
	return S_OK;
}

HRESULT __stdcall  MoeWnd::OpenDir( BSTR d, IDoc** doc)
{
	mol::string s = bstr(d).toString();
	Shit shit = desktop().parseDisplayName(s);
	if ( shit )
	{
		bool result = docs()->open(0, bstr(d).toString(), Docs::PREF_TXT, false, doc );
		if (!result)
		{
			::MessageBox(*this,s.c_str(),_T("failed to load"),MB_ICONERROR);
		}
		statusBar()->status(s);
	}
	return S_OK;
}
/////////////////////////////////////////////////////////////////////

HRESULT __stdcall  MoeWnd::SaveAll()
{
	statusBar()->status(_T("saving all open documents ..."));

	for ( int i = 0; i < count(); i++ )
	{
		punk<IDoc> doc;

		if ( S_OK == docs()->Item(variant(i),&doc) && doc )
		{
			long t;
			if ( doc->get_Type(&t) == S_OK )
			{
				if ( t == XMOE_DOCTYPE_DOC )
				{
					punk<IDispatch> disp;
					
					if ( S_OK == doc->get_Document(&disp) )
					{
						punk<IScintillAx> sci(disp);
						if ( sci )
						{
							sci->Save();
						}
					}
				}
			}
		}
	}
	return S_OK;
}

HRESULT __stdcall  MoeWnd::CloseAll()
{
	statusBar()->status(_T("closing all open documents"));
	OnCloseAll(0,0,0);
	return S_OK;
}

/////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////
HRESULT __stdcall  MoeWnd::Show()
{
	if (!::IsWindow(*this) )
	{
		// create window
		((IXmoe*)this)->AddRef();
		build_ui(this);
		return S_OK;
	}

	show(SW_SHOW);
	OnLayout(0,0,0);
	redraw();
  
	return S_OK;
}


HRESULT __stdcall  MoeWnd::Hide()
{
	show(SW_HIDE);
	return S_OK;
}

/////////////////////////////////////////////////////////////////////

HRESULT __stdcall  MoeWnd::Minimize()
{
	show(SW_MINIMIZE);
	return S_OK;
}

HRESULT __stdcall  MoeWnd::Maximize()
{
	show(SW_MAXIMIZE);
	return S_OK;
}

HRESULT __stdcall  MoeWnd::Restore()
{
	show(SW_RESTORE);
	return S_OK;
}


/////////////////////////////////////////////////////////////////////
HRESULT __stdcall  MoeWnd::Tile()
{
	OnTileHorizontal(0,0,0);
	return S_OK;
}

HRESULT __stdcall  MoeWnd::Cascade()
{
	OnCascade(0,0,0);
	return S_OK;
}
/////////////////////////////////////////////////////////////////////

HRESULT __stdcall  MoeWnd::SetStatus(BSTR stat)
{
	statusBar()->status(mol::toString(stat));
	return S_OK;
}

/////////////////////////////////////////////////////////////////////

HRESULT __stdcall  MoeWnd::Help()
{
	statusBar()->status(_T("help"));

	mol::string p( mol::app<MoeApp>().getModulePath() );
	mol::string help = mol::Path::parentDir(p) + _T("\\doc\\index.html");

	long left, top;
	get_Left(&left);
	get_Top(&top);

	this->OpenHtmlFrame( bstr(help), 0 );

	return S_OK;
}


/////////////////////////////////////////////////////////////////////

HRESULT __stdcall  MoeWnd::Exit()
{
	// tear down open documents gently
	long cnt = 0;
	HRESULT hr = docs()->Count(&cnt);
	if( hr != S_OK )
		return hr;

	long i = cnt;
	while ( i > 0 )
	{
		mol::punk<IDoc> doc;
		hr = docs()->Item( mol::variant(0), &doc );
		if( hr != S_OK )
			return hr;
		
		hr = doc->Close();
		if( hr != S_OK )
			return S_FALSE;
		i--;
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

//TODO: move to Docs
HRESULT __stdcall  MoeWnd::Activate(VARIANT index)
{
	punk<IDoc> doc;
	if ( S_OK == docs()->Item(index,&doc))
	{
		if ( doc )
		{
			bstr f;
			if ( S_OK == doc->get_Filename(&f) && f )
			{
				statusBar()->status(f.toString());
			}
			return doc->Activate();
		}
	}
	return S_OK;
}
/////////////////////////////////////////////////////////////////////

//TODO: moveto scriptlet

HRESULT __stdcall  MoeWnd::Eval(BSTR script, BSTR engine)
{
	if ( !script || !engine )
		return E_INVALIDARG;

	statusBar()->status( mol::string( _T("evaluating ")) + mol::bstr(engine).toString() );

	mol::string e = bstr(engine).toString();
	if ( e == _T("cs") )
	{
		return evalute_csharp(script);
	}

	scriptlet()->eval( mol::toString(engine),mol::toString(script) );
	return S_OK;
}

HRESULT __stdcall  MoeWnd::Debug(BSTR script, BSTR engine)
{
	if ( !script || !engine )
		return E_INVALIDARG;

	statusBar()->status( mol::string( _T("evaluating ")) + mol::bstr(engine).toString() );

	mol::string e = bstr(engine).toString();
	if ( e == _T("cs") )
	{
		return evalute_csharp(script);
	}

	scriptlet()->debug( mol::toString(engine),mol::toString(script) );
	return S_OK;
}

/////////////////////////////////////////////////////////////////////

HRESULT __stdcall  MoeWnd::ShowForm( BSTR html, long left, int top, int width, int height, int style )
{
	statusBar()->status(bstr(html).toString());

	typedef com_obj<MoeFormWnd> form;
	form* f = MoeFormWnd::CreateInstance( 
							bstr(html).toString(),
							left,top,width,height, 
							style 
						);
	return S_OK;
}

HRESULT __stdcall  MoeWnd::get_Compiler( IDispatch** disp )
{
	if ( !disp )
		return E_INVALIDARG;

	*disp = 0;

//	if ( compiler_ )
//		return compiler_->QueryInterface( IID_ICompiler, (void**) disp );

	return S_OK;
}

HRESULT __stdcall  MoeWnd::Preferences()
{
	statusBar()->status(_T("edit preferences for new documents"));
	mol::string p( mol::app<MoeApp>().getModulePath() );
	mol::string prefs = mol::Path::parentDir(p) + _T("\\forms\\prefs.html");

	long left, top;
	get_Left(&left);
	get_Top(&top);

	this->ShowForm( bstr(prefs) ,left+225,top+225,450,190,6);
	
	return S_OK;
}

HRESULT __stdcall  MoeWnd::Settings()
{
	statusBar()->status(_T("edit user settings"));

	LPUNKNOWN punks[] = { config() };
	CLSID pages[]     = { CLSID_SettingProperties };
	::OleCreatePropertyFrame(*this,100,100,L"Moe",1,punks,1,pages,0,0,0);

	return S_OK;
}

HRESULT __stdcall  MoeWnd::ExportSettings(BSTR f)
{
	if ( f )
	{
		config()->Save(f);
		statusBar()->status(_T("exported custom user settings"));
	}	
	return S_OK;
}

HRESULT __stdcall  MoeWnd::ImportSettings(BSTR f)
{
	if ( f )
	{
		config()->Load(f);
		statusBar()->status(_T("imported custom user settings"));
	}	
	return S_OK;
}

HRESULT __stdcall  MoeWnd::Run( BSTR f, BSTR engine )
{
	statusBar()->status(bstr(f).toString());
	mol::string s = findFile(bstr(f).toString());
	if ( s == _T("") )
		return E_FAIL;

	mol::filestream fi;
	if ( fi.open( mol::tostring(s), GENERIC_READ ) )
	{
		std::string txt = fi.readAll();
		fi.close();
		return Eval(bstr(txt),engine);
	}
	return S_OK;
}

HRESULT __stdcall  MoeWnd::System( BSTR f)
{
	statusBar()->status(bstr(f).toString());
	mol::string s = findFile(bstr(f).toString());
	if ( s == _T("") )
		return E_FAIL;

	exec_cmdline( s );
	return S_OK;
}

HRESULT __stdcall  MoeWnd::OpenHexEditor( BSTR f, VARIANT_BOOL vbReadOnly, IDoc** hex)
{
	if (hex)
		*hex = 0;

	bool result = docs()->open(0, bstr(f).toString(), Docs::PREF_HEX, vbReadOnly == VARIANT_TRUE ? true : false, hex );

	statusBar()->status(bstr(f).toString());
	if (!result)
	{
		::MessageBox(*this,bstr(f).toString().c_str(),_T("failed to load"),MB_ICONERROR);
		return S_FALSE;
	}
	return S_OK;
}

HRESULT __stdcall  MoeWnd::OpenHtmlFrame( BSTR f, IDoc** htmlWnd)
{
	if ( htmlWnd )
		*htmlWnd = 0;

	bool result = docs()->open(0, bstr(f).toString(), Docs::PREF_HTML, true, htmlWnd );

	statusBar()->status(bstr(f).toString());
	if (!result)
	{
		::MessageBox(*this,bstr(f).toString().c_str(),_T("failed to load"),MB_ICONERROR);
		return S_FALSE;
	}
	return S_OK;
}

HRESULT __stdcall MoeWnd::MsgBox( BSTR text,  BSTR title, long flags,  long* result)
{
	((IXmoe*)this)->AddRef();
	mol::string txt = text  ? mol::toString(text)  : _T("");
	mol::string ttl = title ? mol::toString(title) : _T("");

	long res = ::MessageBox(*this,txt.c_str(),ttl.c_str(),flags);
	if ( result )
		*result = res;
	((IXmoe*)this)->Release();
	return S_OK;
}

HRESULT __stdcall MoeWnd::CreateObjectAdmin( BSTR progid, IDispatch** disp)
{
	if (!disp )
		return E_INVALIDARG;

	*disp = 0;

	if ( !progid )
		return E_INVALIDARG;

	mol::punk<IUnknown> unk;
	HRESULT hr = mol::CreateObjectAdmin( *this, progid, &unk );
	if ( hr != S_OK )
		return hr;

	return unk->QueryInterface( IID_IDispatch, (void**)disp );
}

HRESULT __stdcall MoeWnd::EditUserForm( BSTR pathname, IDispatch** form )
{
	if ( form )
		*form = 0;

	mol::punk<IDoc> doc;

	bool r = false;

	if ( pathname )
		r = docs()->open(0,mol::bstr(pathname).toString(),Docs::PREF_TXT,false,&doc);
	else
		r = docs()->newUFSFile(&doc);

	if (!form )
		return r ? S_OK : E_FAIL;

	if ( r && doc )
	{
		HRESULT hr = doc->QueryInterface( IID_IDispatch, (void**)form );
		return hr;
	}
	return r ? S_OK : E_FAIL;
}

HRESULT __stdcall MoeWnd::ShowUserForm( BSTR pathname, IDispatch** form )
{
	if ( form )
		*form = 0;

	UserForm::Instance* userForm = UserForm::CreateInstance( mol::bstr(pathname).toString(), false );
	if ( !userForm )
		return E_FAIL;

	if ( !form )
		return S_OK;

	HRESULT hr = userForm->QueryInterface( IID_IDispatch, (void**)form );
	return hr;
}


HRESULT __stdcall MoeWnd::DebugUserForm( BSTR pathname, IDispatch** form )
{
	if ( form )
		*form = 0;

	UserForm::Instance* userForm = UserForm::CreateInstance( mol::bstr(pathname).toString(), false );
	if ( !userForm )
		return E_FAIL;

	if ( !form )
		return S_OK;

	HRESULT hr = userForm->QueryInterface( IID_IDispatch, (void**)form );
	return hr;
}
*/
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

	// save Ribbon UI state (if applicable)
	mol::Ribbon::ribbon()->save(pStgSave);
	return S_OK;
}


HRESULT __stdcall MoeWnd::Load(	 IStorage * pStgLoad)
{
	static LPCOLESTR con = OLESTR("UI");

	punk<IPersistStreamInit> ipsi(this);
	if ( !ipsi )
		return S_OK;

	// open UI stream
	punk<IStream> stream;
	HRESULT hr = pStgLoad->OpenStream( con, NULL, STGM_DIRECT|STGM_SHARE_EXCLUSIVE,0,&stream);
	if ( !stream || (hr != S_OK) )
		return S_OK;

	// load UI config
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
	ve.push_back(_T("Ansi"));
	ve.push_back(_T("UTF8"));
	ve.push_back(_T("UTF16 (LE)"));
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

HRESULT MoeWnd::getActiveEditor( IScintillAx** sci )
{
	if ( !sci )
		return E_INVALIDARG;

	*sci = 0;

	punk<IMoeDocument> doc;
	if ( S_OK != get_ActiveDoc(&doc) )
		return E_FAIL;
	if ( !doc )
		return E_FAIL;

	long type;
	if ( S_OK == doc->get_Type(&type) )
	{
		if ( type != MOE_DOCTYPE_DOC )
		{
			return E_FAIL;
		}
	}

	punk<IDispatch> disp;	
	if ( S_OK != doc->get_Object(&disp) )
		return E_FAIL;

	return disp->QueryInterface(IID_IScintillAx, (void**) sci );
}



HRESULT MoeWnd::evalute_csharp(BSTR cs)
{
	if ( NET().aware() )
	{
	/*	if ( compiler_ )
		{
			compilerSink()->UnAdvise(compiler_);
			compiler_->Unload(VARIANT_TRUE);
			compiler_.release();
		}
		NET().CreateInstance<ICompiler>( _T("JIT"), _T("mol.JIT"), &compiler_ );
		if ( compiler_ )
		{
			punk<IUnknown> unk(compiler_);
			if (unk)
				compilerSink()->Advise(compiler_);
			compiler_->Start();

			compiler_->AddDirectory(bstr(mol::Path::pathname(binPath())));
			compiler_->AddReference(bstr(L"System.Web.dll"));
			compiler_->AddReference(bstr(L"moe.dll"));
			compiler_->AddReference(bstr(L"Interop.Moe.dll"));
			compiler_->AddReference(bstr(L"Interop.Scintilla.dll"));
			compiler_->AddReference(bstr(L"Interop.ShellCtrls.dll"));

			compiler_->AddSourceText(cs);
			compiler_->AddObject(bstr("moe"), variant((IDispatch*)(IXmoe*)(this)) );
			compiler_->CompileExec();
			return S_OK;
		}
*/
	}
	return E_FAIL;
}











