#include "stdafx.h"
#include "MoeBar.h"
#include "moe.h"
#include "app.h"
#include "docs.h"
#include "xmlui.h"
#include "resource.h"

using namespace mol::io;

using namespace mol;
using namespace mol::ole;
using namespace mol::win;
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

// simple app-internal dragDrop passing a HWND
class TxtDragDrop
{
public:

	// start drag drop
	static int doDragDrop( CLIPFORMAT format, HWND from )
	{
		punk<IDropSource> source = new mol::DropSrc();

		size_t i = moe()->index(from);

		punk<mol::DataTransferObj> ido = new mol::DataTransferObj(true);
		ido->addData(format,(void*)&i,sizeof(size_t));

		DWORD effect;
		if ( DRAGDROP_S_DROP == ::DoDragDrop( 
									ido, 
									source, 
									DROPEFFECT_COPY|DROPEFFECT_MOVE,
									&effect) 
			)
			return effect;

		return DROPEFFECT_NONE;
	}

	// determine wether custom format is avail
	static bool isTxtDragDropFormat( IDataObject* ido, CLIPFORMAT format ) 
	{
		format_etc fe( format );
		HRESULT hr = ido->QueryGetData( &fe);
		if (hr != S_OK )
		{
			return false;
		}
		return true;
	}

	// retrieve dragDrop txt value for custom format from IDataObject
	static HWND getHWND( IDataObject* ido, CLIPFORMAT format )
	{
		format_etc fe( format );

		STGMEDIUM sm;
		HRESULT hr = ido->GetData( &fe, &sm );
		if (hr != S_OK )
			return 0;

		if ( sm.tymed != TYMED_HGLOBAL || !sm.hGlobal )
			return 0;

		HWND hwnd = 0;
		size_t i = 0;
		mol::global::get(sm.hGlobal,i);
		hwnd = moe()->childAt((int)i);

		::ReleaseStgMedium(&sm);
		return hwnd;
	}
};

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

MoeTabControl::MoeTabControl()
{
	dragTabFormat_      = ::RegisterClipboardFormat( _T("MoeTabDragDropCustomClipBoardFormat") );
	isMouseDown_ = false;
}


MoeTabControl::~MoeTabControl()
{
}


void MoeTabControl::OnCtrlCreated()
{
	// enable tab ctrl drag drop support
	TabCtrl_SetExtendedStyle(*this,TCS_EX_REGISTERDROP );
}

handle_notify_code(&MoeTabControl::OnSelect, TCN_SELCHANGE)
void MoeTabControl::OnSelect()
{
    int sel = (int)selection();
	mol::TabCtrl::TabCtrlItem* c = getTabCtrlItem(sel);
	HWND h = (HWND)(c->lparam);
	if ( !h ) 
		return;

	mol::MdiChild* mdi = mol::wndFromHWND<mol::MdiChild>(h);
	if (!mdi) 
		return;

	mdi->activate();
    return ;
}

std::wstring dirPathFromChildHWND(HWND hwnd)
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
	return mol::Path::parentDir(mol::towstring(path));
}

handle_notify_code(&MoeTabControl::OnRightClick, NM_RCLICK)
void MoeTabControl::OnRightClick()
{
	// check whether right click hit a tab
	int i = hitTest();
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

	// use moe main window as parent for ownerdrawn menus to work on XP
	int id = sub.returnTrackPopup(*moe(),pt.x-10,pt.y-10);
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
				if ( moe()->childAt(i) != m )
					::PostMessage(moe()->childAt(i), WM_CLOSE, 0, 0 );
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
	}
	return ;
}


handle_msg(&MoeTabControl::OnMouseDown, WM_LBUTTONDOWN)
void MoeTabControl::OnMouseDown()
{
	isMouseDown_ = false;

	int i = hitTest();
	if ( i!= -1 )
	{
		// wait a bit might be a drag-drop
		isMouseDown_ = true;
		SetTimer( ID_TABDRAGDROPTIMER, 500 );
	}
}

handle_msg(&MoeTabControl::OnMouseUp, WM_LBUTTONUP)
void MoeTabControl::OnMouseUp()
{
	isMouseDown_ = false;
}


handle_msg(&MoeTabControl::OnTimer, WM_TIMER)
void MoeTabControl::OnTimer(int id,int)
{
	if ( id == ID_TABDRAGDROPTIMER && isMouseDown_)
	{
		KillTimer(ID_TABDRAGDROPTIMER);
		isMouseDown_ = false;
		int i = hitTest();
		if ( i!= -1 )
		{
			// do a simple dragDrop
			mol::TabCtrl::TabCtrlItem* c = getTabCtrlItem(i);
			TxtDragDrop::doDragDrop( dragTabFormat_, (HWND)(c->lparam) );
		}
	}
}

handle_notify_code(&MoeTabControl::OnGetObject, TCN_GETOBJECT)
void MoeTabControl::OnGetObject(NMOBJECTNOTIFY* notify)
{
	// return our drop source for a drag-drop event
	notify->hResult = E_FAIL;
	IID iid = *(notify->piid);
	if ( ::IsEqualIID( IID_IDropTarget, iid) )
	{
		notify->pObject = (IUnknown*)&Drop;
		notify->hResult = S_OK;
	}
}


// helpers

int MoeTabControl::index( HWND d )
{
	for ( int i = 0; i < count(); i++ )
	{
		mol::TabCtrl::TabCtrlItem* c = getTabCtrlItem(i);
		HWND mdi = (HWND)(c->lparam);
		if ( mdi == d )
		{
			return i;
		}
	}
	return -1;
}

void MoeTabControl::select( HWND d )
{
	int i = index(d);
	if ( i == -1 )
		return;

	mol::TabCtrl::select(i);
}

void MoeTabControl::move( HWND what, HWND to )
{	
	int iwhat = index(what);
	if ( iwhat == -1 )
		return;

	int ito = index(to);
	if ( ito == -1 )
		return;

	mol::TabCtrl::TabCtrlItem* c = getTabCtrlItem(iwhat);
	mol::TabCtrl::TabCtrlItem* tiwhat = new mol::TabCtrl::TabCtrlItem(c->title,c->tooltip,c->lparam);

	removeItem(iwhat);

	ito = index(to);
	if ( ito == -1 )
		return;

	insertItem( tiwhat, ito );
}

void MoeTabControl::remove( HWND d )
{
	int i = index(d);
	if ( i == -1 )
		return;

	removeItem(i);
}

void MoeTabControl::rename( HWND d, const std::wstring& newpath, const std::wstring& name )
{
	int i = index(d);
	if ( i == -1 )
		return;

	mol::TabCtrl::TabCtrlItem* c = getTabCtrlItem(i);
	mol::TabCtrl::TabCtrlItem* nc = new mol::TabCtrl::TabCtrlItem(name,newpath,c->lparam);
	renameItem( nc, i );
}



//////////////////////////////////////////////////////////////////////////////////
// msgmap support for event handling
//////////////////////////////////////////////////////////////////////////////////


LRESULT MoeTabControl::wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return mol::msgMap<MoeTabControl>().call(this,message,wParam,lParam);	
}


//////////////////////////////////////////////////////////////////////////////
//
// Drag & Drop_ Support 
//
//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall MoeTabControl::MoeTabControl_Drop::Drop( IDataObject* pDataObject, DWORD keyState, POINTL pt , DWORD* pEffect)
{
	*pEffect = DROPEFFECT_NONE;

	ODBGS("Tab Drop");
	// get the dropped tabs path
	HWND from = TxtDragDrop::getHWND( pDataObject, tab()->dragTabFormat_ );

	if ( !from )
		return S_OK;

	if(!::IsWindow(from))
		return S_OK;

	mol::MdiChild* m = mol::wndFromHWND<mol::MdiChild>(from);
	if (!m)
		return S_OK;

	// determine drop target tab
	int index = tab()->hitTest();
	int cur = (int)tab()->selection();
	/*
	if ( index == cur )
	{
		*pEffect = DROPEFFECT_NONE;
		return S_OK;
	}
	*/
	if ( index == -1 )
		index = (int)tab()->count();
	if ( index == -1 )
		index = 0;

	if ( index == tab()->index(from) )
		return S_OK;

	docs()->move( m, index );

	// clear highlight bits from tabctrl
	for ( int i = 0; i < tab()->count(); i++ )
		tab()->postMessage(TCM_HIGHLIGHTITEM,i,false);

	*pEffect = DROPEFFECT_NONE;
	return S_OK;
}

HRESULT  __stdcall MoeTabControl::MoeTabControl_Drop::DragEnter( IDataObject* pDataObject, DWORD , POINTL , DWORD* pEffect )
{
	ODBGS("Tab Drag Enter");
	if ( !TxtDragDrop::isTxtDragDropFormat(pDataObject,tab()->dragTabFormat_) )
	{
		*pEffect = DROPEFFECT_NONE;
		 return S_OK;
	}
 
	return S_OK;
}

HRESULT __stdcall MoeTabControl::MoeTabControl_Drop::DragOver( DWORD, POINTL, DWORD* pEffect )
{
	ODBGS("Tab Drag Over");
	*pEffect &= DROPEFFECT_COPY;
    return S_OK;
}


HRESULT  __stdcall MoeTabControl::MoeTabControl_Drop::DragLeave()
{
	ODBGS("Tab Drag Leave");
    return S_OK;
}




/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/*
void MoeToolBar::OnRightClick(NMHDR* notify)
{
	if ( moe()->toolbarFrozen() )
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
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

MoeBar::~MoeBar()
{
	ODBGS("~MoeBar");
}

HRESULT __stdcall MoeBar::Load( LPSTREAM pStm)
{
	mol::ReBar::Load(pStm);
	int n = this->count();

	if ( n > 0 )
	for ( int i = 0; i < n-1; i++)
		postMessage(RB_MAXIMIZEBAND,i, 0 );

	//redraw();
	return S_OK;
}

HRESULT __stdcall MoeBar::Save( LPSTREAM pStm,BOOL fClearDirty)
{
	mol::ReBar::Save(pStm, fClearDirty);
	return S_OK;
}

LRESULT MoeBar::wndProc(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
		case WM_CREATE :
		{
			RECT r;
			::GetClientRect(*this,&r);
			postMessage(WM_SIZE,0,MAKELPARAM(r.right,r.bottom));
			redraw();
			break;
		}
	}
	return mol::ReBar::wndProc(wnd,msg,wParam,lParam);
}

*/

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

MoeHtmlRibbon::MoeHtmlRibbon()
{
	eraseBackground_ = 1;
//	wndClass().setIcon(moe()->icon);
//	wndClass().hIconSm(moe()->icon);
}


MoeHtmlRibbon::~MoeHtmlRibbon()
{
	ODBGS("~MoeHtmlRibbon() dropped dead");
}

handle_msg(&MoeHtmlRibbon::OnCreate,WM_CREATE)
void MoeHtmlRibbon::OnCreate()
{
}

void MoeHtmlRibbon::postMessageAsJSON(const Json::Value& json)
{
	std::string utf8 = JSON::flatten(json);
	oleObject->PostWebMessageAsJson(mol::fromUTF8(utf8).c_str());
}

void MoeHtmlRibbon::load(mol::punk<ChromeEdge> edge)
{
	std::wstring l = mol::app<MoeApp>().CreateAppPath(L"moe");
	location_ = l + L"\\ui\\ribbon.html";

	edge->createWebView(hWnd_, [this](HRESULT hr, ICoreWebView2Controller* controller)
	{
		this->onCreateWebView(location_, controller);
	});
}

void MoeHtmlRibbon::setAppMode(const std::string& m)
{
	std::ostringstream oss;
	oss << "{ \"appmode\" : \"" << m << "\" }";
	ribbon()->oleObject->PostWebMessageAsJson(mol::towstring(oss.str()).c_str());
}

void MoeHtmlRibbon::onCreateWebView(std::wstring target, ICoreWebView2Controller* controller)
{
	webViewController = controller;

	webViewController->get_CoreWebView2(&oleObject);

	mol::punk<IDispatch> disp(&external_);
	mol::variant obj(disp);
	oleObject->AddHostObjectToScript(L"external", &obj);

	oleObject->add_NavigationStarting(
		make_callback<ICoreWebView2NavigationStartingEventHandler>(
			[this](ICoreWebView2* webView, ICoreWebView2NavigationStartingEventArgs* args)
		{
			this->onNavigationStarted(args);
		}),
		&navigationStartingToken
	);

	oleObject->Navigate(target.c_str());
}



void MoeHtmlRibbon::onNavigationStarted(ICoreWebView2NavigationStartingEventArgs* args)
{
	/*
	LPWSTR uri = nullptr;
	args->get_Uri(&uri);
	if (mol::wcstricmp(uri, L"mol://close") == 0)
	{
		args->put_Cancel(TRUE);
		::CoTaskMemFree(uri);
		postMessage(WM_CLOSE, 0, 0);
		return;
	}

	::CoTaskMemFree(uri);
	*/
}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

handle_msg(&MoeHtmlRibbon::OnSize, WM_SIZE)
void MoeHtmlRibbon::OnSize(WPARAM wParam, LPARAM lParam)
{
	if (webViewController)
	{
		RECT bounds;
		GetClientRect(hWnd_, &bounds);
		webViewController->put_Bounds(bounds);
	};

}

handle_msg(&MoeHtmlRibbon::OnClose, WM_CLOSE)
void MoeHtmlRibbon::OnClose()
{
	ODBGS("MoeHtmlRibbon::OnClose");
}

handle_msg(&MoeHtmlRibbon::OnNcDestroy, WM_NCDESTROY)
void MoeHtmlRibbon::OnNcDestroy()
{
	ODBGS("MoeHtmlRibbon::OnNcDestroy");

	if (oleObject)
	{
		oleObject->RemoveHostObjectFromScript(L"external");
//		oleObject->remove_DocumentTitleChanged(documentTitleChangedToken);
		oleObject->remove_NavigationStarting(navigationStartingToken);
	//	oleObject->remove_PermissionRequested(permissionRequestToken);

		webViewController->Close();
		webViewController.release();
		oleObject.release();
	}

	::CoDisconnectObject(((IExternalMoe*)&external_), 0);

	//delete this;
	ODBGS("~MoeFormWnd()OnNcDestroy --");
}


/////////////////////////////////////////////////////////////////////////////////////////////


int MoeHtmlRibbon::style()
{
	static int s = WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

	return s | WS_VISIBLE | WS_CHILD;
}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////
// external events called from script inside MoeWnd
/////////////////////////////////////////////////////////////////////////////////////////////

MoeHtmlRibbon::ExternalMoe::ExternalMoe()
{
}

MoeHtmlRibbon::ExternalMoe::~ExternalMoe()
{
	ODBGS("MoeHtmlRibbon::ExternalMoe ~");
}

HRESULT __stdcall MoeHtmlRibbon::ExternalMoe::get_Moe(IDispatch** disp)
{
	if (!disp)
		return E_INVALIDARG;

	HRESULT hr = ((IMoe*)(moe()))->QueryInterface(IID_IDispatch, (void**)disp);
	if (hr != S_OK)
		*disp = 0;

	return hr;
}



HRESULT __stdcall MoeHtmlRibbon::ExternalMoe::Close()
{
	ODBGS("MoeHtmlRibbon::ExternalMoe::Close()");
	moe()->postMessage(WM_CLOSE, 0, 0);
	return S_OK;
}

HRESULT __stdcall MoeHtmlRibbon::ExternalMoe::CreateObject(BSTR progId, IDispatch** disp)
{
	if (!disp)
		return E_INVALIDARG;

	*disp = 0;
	CLSID clsid;

	if (S_OK == ::CLSIDFromProgID(progId, &clsid))
	{
		if (S_OK == ::CoCreateInstance(clsid, NULL, CLSCTX_INPROC | CLSCTX_LOCAL_SERVER, IID_IDispatch, (void**)disp))
			return S_OK;
	}
	return E_FAIL;
}

HRESULT __stdcall MoeHtmlRibbon::ExternalMoe::get_Frame(IMoeHtmlFrame** f)
{
	if (!f)
		return E_INVALIDARG;
	return E_NOTIMPL;
}


HRESULT __stdcall MoeHtmlRibbon::ExternalMoe::CodeBehind(BSTR fname)
{
	return E_NOTIMPL;
}

HRESULT __stdcall MoeHtmlRibbon::ExternalMoe::get_Code(IDispatch** code)
{
	if (!code)
		return E_INVALIDARG;

	*code = 0;
	return E_NOTIMPL;
}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
