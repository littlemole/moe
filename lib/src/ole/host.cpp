#include "ole/host.h"
#include "ole/bstr.h"
#include "ole/ie.h"
#include "win/path.h"
#include "win/shell.h"
//////////////////////////////////////////////////////////////////////

namespace mol {
namespace ole {



/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

AxClientWndBase::AxClientWndBase()
{
	frameWnd_ = 0;
	isInplaceActive_ = false;;
	isUIActive = false;
	isShuttingDown_ = false;
	tmpFile_ = _T("");
}

AxClientWndBase::~AxClientWndBase()
{
	//ODBGS("AxClientWnd died :o");
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

bool AxClientWndBase::loadObjectFromStorage( REFCLSID iid, IStorage* store )
{
	// embedd the COM server
	if ( !instantiateObject(iid) )
		return false;

	
	OnLoadProgress(1);

	// load object from structured storage
	try
	{	
		mol::punk<IPersistStorage> ps(oleObject);
		if ( ps )
		{
			HRESULT hr;
			mol::punk<IStorage> s;
			hr = copyStorageTemp(store,&s);
			OnLoadProgress(3);	
			if ( hr == S_OK && s )
			{
				hr = ps->Load(s);
				OnLoadProgress(4);
				if ( hr == S_OK )
					if (embeddObject())
					{
						OnLoadProgress(6);
						return true;
					}
			}
		}
	}
	catch (mol::X x)
	{
		oleObject->Close(OLECLOSE_NOSAVE);
		throw x;
	}
	return false;
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
// load object from stream
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

bool AxClientWndBase::loadObjectFromStream( REFCLSID iid, IStream* stream)
{
	// embedd the COM server
	if ( !instantiateObject(iid) )
		return false;

	OnLoadProgress(2);

	if (!embeddObject())
		return false;
	
	// try to load via IPersistStreamInit
	try
	{	
		mol::punk<IPersistStream> ps(oleObject);
		if ( !ps )
			return false;
		
		OnLoadProgress(4);

		if ( S_OK == ps->Load(stream) )
		{
				OnLoadProgress(6);
				return true;
		}
	}
	catch (mol::X x)
	{
		oleObject->Close(OLECLOSE_NOSAVE);
		throw x;
	}
	return false;
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
// load object from plain file
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

bool AxClientWndBase::loadObjectFromPersistFile( REFCLSID iid, const mol::string& file)
{
	// embedd the COM server
	if ( !instantiateObject(iid) )
		return false;

	OnLoadProgress(1);

	// try to load via IPersistFile
	try
	{	
		mol::punk<IPersistFile> pf(oleObject);
		if ( pf )
		{
			OnLoadProgress(3);
			HRESULT hr = pf->Load(mol::bstr(file),0);
			OnLoadProgress(4);
			if ( hr != S_OK )
				return false;

			OnLoadProgress(6);
			if (embeddObject())
				return true;
		}
		return false;
	}
	catch (mol::X x)
	{
		oleObject->Close(OLECLOSE_NOSAVE);
		throw x;
	}
	return false;
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

bool AxClientWndBase::newObjectFromStorage( REFCLSID iid )
{
	// embedd the COM server
	if ( !instantiateObject(iid) )
		return false;

	OnLoadProgress(1);

	// load object from structured storage
	try
	{	
		punk<IStorage> store;
		if ( S_OK == ::StgCreateDocfile( 0, STGM_TRANSACTED|STGM_CREATE|STGM_READWRITE|STGM_SHARE_EXCLUSIVE,0,&store) )
		{
			OnLoadProgress(3);
			mol::punk<IPersistStorage> ps(oleObject);
			if ( ps )
			{
				if ( S_OK == ps->InitNew(store) )
				{
					OnLoadProgress(4);
					if (!embeddObject())
					{
						OnLoadProgress(6);
						return false;
					}

					return true;
				}
			}
		}
	}
	catch (mol::X x)
	{
		oleObject->Close(OLECLOSE_NOSAVE);
		throw x;
	}
	return false;
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

bool AxClientWndBase::loadObjectFromShell( const mol::string& file)
{
	if ( !instantiateObject(CLSID_WebBrowser) )
		return false;

	OnLoadProgress(1);
	try
	{	
		if (!embeddObject())
			return false;

		OnLoadProgress(3);

		HRESULT hr;
		mol::punk<IWebBrowser2> wb(oleObject);
		if (!wb)
			return false;

		OnLoadProgress(4);
		mol::variant v(file);
		hr = wb->Navigate2( &v,0,0,0,0);
		OnLoadProgress(6);	
		if ( hr == S_OK )
		{
			return true;
		}
		return false;
	}
	catch (mol::X x)
	{
		oleObject->Close(OLECLOSE_NOSAVE);
		throw x;
	}
	return false;
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

bool AxClientWndBase::loadObject( REFCLSID iid )
{
	if ( instantiateObject( iid ) )
	{
		OnLoadProgress(1);
		if ( embeddObject() )
		{
			OnLoadProgress(2);
			return true;
		}
	}
	return false;
}

bool AxClientWndBase::loadObjectFromMoniker( const mol::string& path )
{
	CLSID clsid; 
	std::wstring			file(mol::towstring(path));

	if ( moniker )
		moniker.release();

	// get a file moniker
	HRESULT hr = ::CreateFileMoniker(file.c_str(), &moniker);
	if (hr != S_OK) 
		return false;

	OnLoadProgress(1);

	// get CLSID
	hr = ::GetClassFile(file.c_str(), &clsid);
	if (hr != S_OK) 
		return false;

	// instantiate but not create
	if (!instantiateObject(clsid,false))
		return false;

	OnLoadProgress(2);

	mol::io::ShellFileOp sfo;
	if ( !tmpFile_.empty() )
	{
		sfo.remove(0,tmpFile_);
		tmpFile_ = _T("");
	}
	
	// make a tmp copy of the file to work with
	mol::string ext = mol::Path::ext(path);
	mol::TCHAR  p[MAX_PATH];
	mol::TCHAR t[MAX_PATH];
	::GetTempPath(255,p);
	::GetTempFileName( p, _T("xmo_"), 0, t );
	
	mol::string tmp = t;
	tmpFile_ = tmp.substr(0,tmp.size()-4) + ext;
	
	sfo.copy(0,path,tmpFile_,FOF_SILENT|FOF_NOCONFIRMATION|FOF_NOCONFIRMMKDIR|FOF_NOERRORUI);

	file = mol::towstring(tmpFile_);

	// release moniker and get a moniker from the copy!
	moniker.release();

	OnLoadProgress(3);

	// get a file moniker, again (from the copy now)
	hr = ::CreateFileMoniker(file.c_str(), &moniker);
	if (hr != S_OK) 
		return false;

	// prepare bind ctx	
	punk<IBindCtx> ctx;
	::CreateBindCtx(0,&ctx);
	BIND_OPTS bopts = {sizeof(BIND_OPTS), BIND_MAYBOTHERUSER, 0, 10000};
    bopts.grfMode = (STGM_TRANSACTED | STGM_SHARE_EXCLUSIVE | STGM_READWRITE);
	ctx->SetBindOptions(&bopts);

	OnLoadProgress(4);

	// bind the object
	hr = moniker->BindToObject(ctx,NULL,IID_IOleObject,(void**)&oleObject);
	moniker.release();
	if ( hr != S_OK )
		return false;

	OnLoadProgress(5);

	// embedd it
	if ( !embeddObject())
	{
		OnLoadProgress(6);
		return false;
	}

	return true;
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
// COM impl
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

// IOleInPlaceUIWindow
HRESULT  __stdcall AxClientWndBase::IOleInPlaceUIWindow_GetWindow( HWND FAR* lphwnd)
{
	*lphwnd = this->getHostingWindow();
	return S_OK;
}

HRESULT  __stdcall AxClientWndBase::IOleInPlaceUIWindow_ContextSensitiveHelp( BOOL fEnterMode)
{
	return E_NOTIMPL ;
}

HRESULT  __stdcall AxClientWndBase::IOleInPlaceUIWindow_GetBorder( LPRECT lprectBorder)
{
	return E_NOTIMPL ;
}
HRESULT  __stdcall AxClientWndBase::IOleInPlaceUIWindow_RequestBorderSpace( LPCBORDERWIDTHS pborderwidths)
{
	return E_NOTIMPL ;
}
HRESULT  __stdcall AxClientWndBase::IOleInPlaceUIWindow_SetBorderSpace( LPCBORDERWIDTHS pborderwidths)
{
	return E_NOTIMPL ;
}
HRESULT  __stdcall AxClientWndBase::IOleInPlaceUIWindow_SetActiveObject( IOleInPlaceActiveObject *pActiveObject, LPCOLESTR pszObjName)
{
	//ODBGS("IOleInPlaceUIWindow_SetActiveObject");
	activeObject = pActiveObject;
	return S_OK;
}

// IOleDocumentSite Implementation
/*
HRESULT  __stdcall  AxClientWndBase::IOleDocumentSite_ActivateMe(IOleDocumentView* pViewToActivate)
{
	return E_NOTIMPL;
}
*/
// IOleDocumentSite Implementation
HRESULT __stdcall  AxClientWndBase::IOleDocumentSite_ActivateMe(IOleDocumentView* pViewToActivate)
{
	HRESULT          hr   = E_FAIL;
	IOleDocument*    piod = NULL;
	mol::Rect        rc;    

	if (pViewToActivate)
	{
		pViewToActivate->SetInPlaceSite( this->getOleInPlaceSite() );
		documentView = pViewToActivate;
	}
	else
	{
		documentView.release();
		//if ((!this->oleObject) || FAILED(this->oleObject->QueryInterface(IID_IOleDocument, (void **)&piod)))
		if ((!this->oleObject) || FAILED(this->oleObject.queryInterface(&piod)))
			return E_FAIL;

		hr = piod->CreateView( this->getOleInPlaceSite() , NULL, 0, &documentView);
		piod->Release();

		if (FAILED(hr)) return E_OUTOFMEMORY;
	}

	hr = documentView->SetInPlaceSite(this->getOleInPlaceSite());
	if ( hr != S_OK )
		return hr;

	hr = documentView->UIActivate(TRUE);
	if ( hr != S_OK )
		return hr;

	rc = this->prepareClientRect();

	hr = documentView->SetRect(&clientRect_);
	if ( hr != S_OK )
		return hr;

	// It's show time!!...
	hr = documentView->Show(TRUE);    
	return hr;
}

// styles
 int AxClientWndBase::style()   
 { 
	 return WS_CHILD | WS_CLIPSIBLINGS|WS_VISIBLE; 
 }

//IOleClientSite
HRESULT  __stdcall AxClientWndBase::IOleClientSite_SaveObject( )
{ 
	return 	S_OK ;
}

HRESULT  __stdcall AxClientWndBase::IOleClientSite_GetMoniker( DWORD dwAssign, DWORD dwWhichMoniker, IMoniker ** ppmk )
{
	return E_NOTIMPL ;
}

HRESULT  __stdcall AxClientWndBase::IOleClientSite_GetContainer( LPOLECONTAINER FAR* ppContainer )
{
	ppContainer = 0;
	return E_NOINTERFACE ;
}

HRESULT  __stdcall AxClientWndBase::IOleClientSite_ShowObject()
{
	return 	S_OK ;
}
HRESULT  __stdcall AxClientWndBase::IOleClientSite_OnShowWindow( BOOL fShow  )
{
	return 	S_OK ;
}
HRESULT  __stdcall AxClientWndBase::IOleClientSite_RequestNewObjectLayout ()
{
	return E_NOTIMPL ;
}
HRESULT  __stdcall AxClientWndBase::ShowContextMenu( DWORD dwID, POINT *ppt, IUnknown *pcmdtReserved, IDispatch *pdispReserved)
{
	return S_FALSE;
}

//IOleInPlaceSite
HRESULT  __stdcall AxClientWndBase::IOleInPlaceSite_GetWindow( HWND FAR* lphwnd)
{
	*lphwnd = this->getHostingWindow();
	return S_OK;
}

HRESULT __stdcall AxClientWndBase::IOleInPlaceSite_GetWindowContext( LPOLEINPLACEFRAME FAR* lplpFrame,
                            LPOLEINPLACEUIWINDOW FAR* lplpDoc,
                            LPRECT lprcPosRect,
                            LPRECT lprcClipRect,
                            LPOLEINPLACEFRAMEINFO lpFrameInfo)
{
		*lplpFrame   = 0;
		*lplpDoc     = 0;

		//if ( S_OK != oleFrame->QueryInterface(IID_IOleInPlaceFrame, (void**) lplpFrame) )
		if ( S_OK != oleFrame.queryInterface(lplpFrame) )
			return E_FAIL;

		bool isMidi = this->getMidiState();
		if ( !isMidi )
			lpFrameInfo->fMDIApp       = FALSE;
		else
			lpFrameInfo->fMDIApp       = TRUE;

		if ( frameWnd_ )
		{
			lpFrameInfo->hwndFrame     = frameWnd_;
		}
		else
		{
			lpFrameInfo->hwndFrame     = this->getHostingWindow();
		}

		if ( S_OK != this->getOleClientSite()->QueryInterface(IID_IOleInPlaceUIWindow, (void**) lplpDoc) )
			return E_FAIL;


		lpFrameInfo->haccel        = 0;
		lpFrameInfo->cAccelEntries = 0;

		*lprcPosRect  = clientRect_;
		*lprcClipRect = clientRect_;

		return S_OK;
}

HRESULT  __stdcall AxClientWndBase::IOleInPlaceSite_ContextSensitiveHelp( BOOL fEnterMode)
{
	return E_NOTIMPL ;
}
HRESULT  __stdcall AxClientWndBase::IOleInPlaceSite_CanInPlaceActivate()
{
	return 	S_OK ;
}
HRESULT  __stdcall AxClientWndBase::IOleInPlaceSite_OnInPlaceActivate()
{
	isInplaceActive_ = true;
	return 	S_OK ;
}
HRESULT  __stdcall AxClientWndBase::IOleInPlaceSite_OnUIActivate()
{
	//ODBGS("IOleInPlaceSite_OnUIActivate");
	isUIActive = true;
	return 	S_OK ;
}

HRESULT  __stdcall AxClientWndBase::IOleInPlaceSite_Scroll( SIZE scrollExtent)
{
	return E_NOTIMPL ;
}
HRESULT  __stdcall AxClientWndBase::IOleInPlaceSite_OnUIDeactivate( BOOL fUndoable)
{
	isUIActive = false;
	return 	S_OK ;
}
HRESULT  __stdcall AxClientWndBase::IOleInPlaceSite_OnInPlaceDeactivate()
{
	isInplaceActive_ = false;
	return 	S_OK ;
}
HRESULT  __stdcall AxClientWndBase::IOleInPlaceSite_DiscardUndoState()
{
	return E_NOTIMPL ;
}
HRESULT  __stdcall AxClientWndBase::IOleInPlaceSite_DeactivateAndUndo()
{
	return E_NOTIMPL ;
}
HRESULT  __stdcall AxClientWndBase::IOleInPlaceSite_OnPosRectChange( LPCRECT lprcPosRect)
{
	return 	S_OK ;
}

//DocHostUiHandler - meaningfull for IE explorer
HRESULT  __stdcall AxClientWndBase::IDocHostUIHandler_GetHostInfo( DOCHOSTUIINFO *pInfo)
{
	// set appeareance flags (meaningful only in hosting IE context)	
	pInfo->cbSize = sizeof(DOCHOSTUIINFO);
	pInfo->dwFlags = DOCHOSTUIFLAG_NO3DBORDER|DOCHOSTUIFLAG_DIALOG |DOCHOSTUIFLAG_FLAT_SCROLLBAR;
	pInfo->dwDoubleClick = DOCHOSTUIDBLCLK_DEFAULT;

	return S_OK;
}
HRESULT  __stdcall AxClientWndBase::IDocHostUIHandler_ShowUI( DWORD dwID, IOleInPlaceActiveObject *pActiveObject, IOleCommandTarget *pCommandTarget, IOleInPlaceFrame *pFrame, IOleInPlaceUIWindow *pDoc)
{
	return S_FALSE; // ENABLE MSHTML UI
	return 	S_OK ;
}
HRESULT  __stdcall AxClientWndBase::IDocHostUIHandler_HideUI()
{
	return 	S_OK ;
}
HRESULT  __stdcall AxClientWndBase::IDocHostUIHandler_UpdateUI()
{
	return 	S_OK ;
}
HRESULT  __stdcall AxClientWndBase::IDocHostUIHandler_EnableModeless( BOOL fEnable)
{
	return 	S_OK ;
}
HRESULT  __stdcall AxClientWndBase::IDocHostUIHandler_OnDocWindowActivate( BOOL fActivate)
{
	return 	S_OK ;
}
HRESULT  __stdcall AxClientWndBase::IDocHostUIHandler_OnFrameWindowActivate( BOOL fActivate)
{
	return 	S_OK ;
}
HRESULT  __stdcall AxClientWndBase::IDocHostUIHandler_ResizeBorder( LPCRECT prcBorder, IOleInPlaceUIWindow *pUIWindow, BOOL fRameWindow)
{
	return 	S_OK ;
}
HRESULT  __stdcall AxClientWndBase::IDocHostUIHandler_TranslateAccelerator( LPMSG lpMsg, const GUID *pguidCmdGroup, DWORD nCmdID)
{
	return 	S_FALSE ;
}
HRESULT  __stdcall AxClientWndBase::IDocHostUIHandler_GetOptionKeyPath( LPOLESTR *pchKey, DWORD dw)
{
	return 	S_FALSE ;
}
HRESULT  __stdcall AxClientWndBase::IDocHostUIHandler_GetDropTarget( IDropTarget *pDropTarget, IDropTarget **ppDropTarget)
{
	*ppDropTarget = 0;
	return 	S_FALSE ;
}
HRESULT  __stdcall AxClientWndBase::IDocHostUIHandler_GetExternal( IDispatch **ppDispatch)
{
	*ppDispatch = 0;
	return 	S_OK ;
}
HRESULT  __stdcall AxClientWndBase::IDocHostUIHandler_TranslateUrl( DWORD dwTranslate, OLECHAR *pchURLIn, OLECHAR **ppchURLOut)
{
	*ppchURLOut = 0;
	return 	S_FALSE ;
}
HRESULT  __stdcall AxClientWndBase::IDocHostUIHandler_FilterDataObject( IDataObject *pDO, IDataObject **ppDORet)
{
	*ppDORet = 0;
	return 	S_FALSE ;
}

//IDocHostShowUI Interface
HRESULT  __stdcall AxClientWndBase::IDocHostShowUI_ShowHelp( HWND hwnd, LPOLESTR pszHelpFile, UINT uCommand, DWORD dwData, POINT ptMouse, IDispatch* pDispatchObjectHit )
{
	return 	S_FALSE ;
}
HRESULT  __stdcall AxClientWndBase::IDocHostShowUI_ShowMessage( HWND hwnd, LPOLESTR lpstrText, LPOLESTR lpstrCaption, DWORD dwType, LPOLESTR lpstrHelpFile, DWORD dwHelpContext, LRESULT* plResult )
{
	return 	S_FALSE ;
}

// IServiceProvicer
HRESULT  __stdcall AxClientWndBase::IServiceProvider_QueryService( REFGUID guidService, REFIID riid, void** ppvObject)
{
	*ppvObject = 0;
	return 	E_NOINTERFACE ;
}

//IOleControlSite
HRESULT  __stdcall AxClientWndBase::IOleControlSite_OnControlInfoChanged( void)
{
	return S_OK;
}
HRESULT  __stdcall AxClientWndBase::IOleControlSite_LockInPlaceActive( BOOL fLock)
{
	return S_OK;
}
HRESULT  __stdcall AxClientWndBase::IOleControlSite_GetExtendedControl( IDispatch **ppDisp)
{
	return S_OK;
}
HRESULT  __stdcall AxClientWndBase::IOleControlSite_TransformCoords( POINTL *pPtlHimetric,POINTF *pPtfContainer,DWORD dwFlags)
{
	return S_OK;
}
HRESULT  __stdcall AxClientWndBase::IOleControlSite_TranslateAccelerator( MSG *pMsg,DWORD grfModifiers)
{
	return E_NOTIMPL;
	return S_OK;
}
HRESULT  __stdcall AxClientWndBase::IOleControlSite_OnFocus( BOOL fGotFocus)
{
	return S_OK;
}
HRESULT  __stdcall AxClientWndBase::IOleControlSite_ShowPropertyFrame( void)
{
	return S_OK;
}

//ISimpleFrameSite
HRESULT  __stdcall AxClientWndBase::ISimpleFrameSite_PreMessageFilter( HWND hWnd, UINT msg, WPARAM wp, LPARAM lp,LRESULT *plResult, DWORD *pdwCookie)
{
	return S_OK;
}
HRESULT  __stdcall AxClientWndBase::ISimpleFrameSite_PostMessageFilter( HWND hWnd, UINT msg, WPARAM wp, LPARAM lp,LRESULT *plResult,DWORD dwCookie)
{
	return S_OK;
}

//IAdviseSink
void  __stdcall AxClientWndBase::IAdviseSink_OnDataChange( FORMATETC *pFormatetc, STGMEDIUM *pStgmed) 
{
}
    
void  __stdcall AxClientWndBase::IAdviseSink_OnViewChange( DWORD dwAspect,LONG lindex)
{
}
    
void  __stdcall AxClientWndBase::IAdviseSink_OnRename( IMoniker *pmk) 
{
}
        
void  __stdcall AxClientWndBase::IAdviseSink_OnSave( void) 
{
}
        
void  __stdcall AxClientWndBase::IAdviseSink_OnClose( void)
{
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////
// called by childwindow to trigger new layout
//////////////////////////////////////////////////////////////////////


void AxClientWndBase::SetObjectSize(RECT& r)
{
	// if we have an embedded obj
	if ( oleObject )
	{
		// find inplact obj ref and set the dimension
		punk<IOleInPlaceObject> oip(oleObject);
		if ( oip )
		{
			oip->SetObjectRects(&r,&r);
		}
		else
		{
			if ( this->activeObject.interface_ )
			//if ( S_OK == activeObject->QueryInterface(IID_IOleInPlaceObject,(void**)&oip) )
			if ( S_OK == activeObject.queryInterface(&oip) )
			{
				oip->SetObjectRects(&r,&r);
			}
		}
		/*
		HWND w = 0;
		if ( S_OK == oip->GetWindow(&w) && w && ::IsWindow(w) )
		{
			::SetWindowPos( w, NULL, 0,0, r.right, r.bottom,SWP_NOZORDER|SWP_DRAWFRAME|SWP_FRAMECHANGED|SWP_NOACTIVATE|SWP_NOOWNERZORDER|SWP_NOMOVE|SWP_NOCOPYBITS);
		}
		*/
	}
}

void AxClientWndBase::updateObject()
{
	// if we have an embedded obj
	if ( oleObject )
	{
		// find inplact obj ref and set the dimension
		punk<IOleInPlaceObject> oip(oleObject);
		if ( oip )
		{
			HWND w = 0;
			if ( S_OK == oip->GetWindow(&w) && w && ::IsWindow(w) )
			{
				::InvalidateRect(w,0,TRUE);
				::UpdateWindow(w);
				//ODBGS("U.P.D.A.T.E O.L.E. W.I.N.D.O.W");
			}
		}
		else
		{
			if ( this->activeObject.interface_ )
			//if ( S_OK == activeObject->QueryInterface(IID_IOleInPlaceObject,(void**)&oip) )
			if ( S_OK == activeObject.queryInterface(&oip) )
			{
				HWND w = 0;
				if ( S_OK == oip->GetWindow(&w) && w && ::IsWindow(w) )
				{
					::InvalidateRect(w,0,TRUE);
					::UpdateWindow(w);
					//ODBGS("U.P.D.A.T.E O.L.E. W.I.N.D.O.W");
				}
			}
		}
	}
}






HRESULT AxClientWndBase::copyStorageTemp(IStorage* src, IStorage** copy)
{
	if ( !src || !copy )
		return E_POINTER;

	*copy = 0;
	mol::TCHAR  path[MAX_PATH];
	mol::TCHAR file[MAX_PATH];
	::GetTempPath(255,path);
	::GetTempFileName( path, _T("JsHost_"), 0, file );


	punk<IStorage> store;
	if ( S_OK == ::StgCreateDocfile( mol::towstring(file).c_str(), STGM_DELETEONRELEASE|STGM_CREATE|STGM_READWRITE|STGM_SHARE_EXCLUSIVE|STGM_TRANSACTED,0,&store) )
	{
		HRESULT hr = src->CopyTo(0,0,0,store);
		//return store->QueryInterface( IID_IStorage, (void**)copy);
		return store.queryInterface( copy);
	}
	return E_FAIL;
}


// inplaceactivate obj
bool AxClientWndBase::inplaceDeActivate(bool full)
{
	//ODBGS1("inplaceDeActivate ",full);
	// check if to go inactive (true) or UI-inactive only (false)
	if ( !full )
	{
		// UI deactivate only

		// if we have a view interface, use it for deactivation
		if ( this->documentView)
		{
			this->documentView->UIActivate(FALSE);
			return true;
		}
		// go the old way
		if ( this->activeObject)
		{
			punk<IOleInPlaceObject> ipo(activeObject);
			if(!ipo)
				//oleObject->QueryInterface(IID_IOleInPlaceObject,(void**)&ipo);
				oleObject.queryInterface(&ipo);
			if(ipo)
				ipo->UIDeactivate();
			return true;
		}
		return false;
	}
	// FULL deactivation

	punk<IOleDocumentView> v;
	if ( this->documentView )						
	{
		//documentView->QueryInterface(IID_IOleDocumentView,(void**)&v);
		documentView.queryInterface(&v);
		this->documentView.release();

		if ( v )
		{
			if (this->activeObject)
			{
				v->UIActivate(FALSE);
				if (this->activeObject)
				{
					punk<IOleInPlaceObject> p(activeObject);
					if ( p )
						p->InPlaceDeactivate();
				}
			}
			v->Show(FALSE);
			v->CloseView(0);
		}
	}
	return true;
}


// trap WM_SIZE events and keep clientRect_ uptodate
// then do a re-layout
LRESULT AxClientWndBase::handleOnSize( UINT message, WPARAM wParam, LPARAM lParam, mol::LayoutMgr* layout )
{
	//ODBGS("AxClient OnSize");
	if ( wParam == SIZE_MINIMIZED )
		return 0;

	/*
	HWND hwnd = this->getHostingWindow();
	mol::MdiChild* mdi = mol::wndFromHWND<mol::MdiChild>(hwnd);
	if ( mdi)
	{
		HWND parent = mdi->getParent();
		mol::MdiFrame* frame = mol::wndFromHWND<mol::MdiFrame>(parent);
		HWND active = frame->getActive();
		if ( active != hwnd )
			return 0;
	}
	*/

	clientRect_.left = clientRect_.top = 0;
	clientRect_.right  = LOWORD (lParam) ;
	clientRect_.bottom = HIWORD (lParam) ;

	//ODBGS1("AxClient OnSize r: ",clientRect_.right);
	//ODBGS1("AxClient OnSize b: ",clientRect_.bottom);

	handleDoLayout( clientRect_, layout );
	return 0;
}

// layout helper, resizes the embedded ax obj
mol::Rect AxClientWndBase:: handleDoLayout(mol::Rect r, mol::LayoutMgr* layout)
{
	//ODBGS("AxClientWndBase doLayout");

	// determine avail rect
	if ( layout )
		r = layout->availClientRect(r);

	//ODBGS1("doLayout r: ",r.right);
	//ODBGS1("doLayout b: ",r.bottom);

	// if we have an embedded obj
	this->SetObjectSize(r);
	this->updateObject();

	// do a relayout
	if ( layout )
		layout->layout(r);

	//ODBGS("<------AxClientWndBase doLayout END");
	return r;
}

bool AxClientWndBase::inplaceActivate(bool withUI )
{
	// activate it in-place!
	//ODBGS1("inplaceActivate ",withUI);

	if ( this->documentView )
		if ( S_OK == this->documentView->UIActivate(TRUE))
			return true;

	IOleDocumentSite* ods = this->getOleDocumentSite();
	if ( ods )
		if ( ods->ActivateMe(0) == S_OK )
			return true;

	HRESULT hr = S_OK;
	HWND wnd = this->getHostingWindow();

	if ( withUI )
	{
		hr = oleObject->DoVerb(OLEIVERB_UIACTIVATE, NULL, this->getOleClientSite(), (UINT)-1, wnd, &clientRect_);
		if (hr == S_OK)
			return true;
	}
		
	hr = oleObject->DoVerb(OLEIVERB_INPLACEACTIVATE, NULL, this->getOleClientSite(), (UINT)-1, wnd , &clientRect_);
	if (hr == OLEOBJ_E_INVALIDVERB)
	{
		hr = oleObject->DoVerb(OLEIVERB_SHOW, NULL, this->getOleClientSite(), (UINT)-1,wnd, &clientRect_);
		if ( hr == S_OK )
		{
			return true;
		}
	}
	return hr == S_OK;
}

bool AxClientWndBase::embeddObject()
{
	try
	{
		DWORD dwMiscStatus;
		HRESULT hr = oleObject->GetMiscStatus(DVASPECT_CONTENT, &dwMiscStatus);
		if (dwMiscStatus & OLEMISC_SETCLIENTSITEFIRST)
			hr = oleObject->SetClientSite(this->getOleClientSite());


		// set embedden obj into running state
		hr = OleRun((struct IUnknown *)oleObject);
		if ( hr != S_OK )
			throw mol::X(_T("OleRun failed"));

		// lock it
		if ( S_OK != OleLockRunning((struct IUnknown *)oleObject, TRUE, FALSE))
			throw mol::X(_T("OleLockRunning failed"));


		// set the stupid unused hostname to keep protocol compliance
		if ( S_OK != oleObject->SetHostNames( L"AxHostWnd",L"AxHostWnd"))
			throw mol::X(_T("Ole Sethostname failed"));

		// notify obj of being contained
		if (S_OK != ::OleSetContainedObject((struct IUnknown *)oleObject, TRUE) )
			throw mol::X(_T("OleSetContainedObject failed"));

		// obj creation succeeded - get client rect for activation
		RECT r = this->prepareClientRect();

		// check if obj wants clientsite now
		hr = oleObject->GetMiscStatus(DVASPECT_CONTENT, &dwMiscStatus);
		if ( OLEMISC_SETCLIENTSITEFIRST != (dwMiscStatus & OLEMISC_SETCLIENTSITEFIRST))
		{
			hr = oleObject->SetClientSite(this->getOleClientSite());

			if ( hr != S_OK )
			{
				throw mol::X(_T("OleCreate failed!"));
			}
		}

		// activate it in-place!
		this->inplaceActivate( TRUE );





		return true;
	}
	catch (mol::X x)
	{
		oleObject->Close(OLECLOSE_NOSAVE);
		throw x;
	}
	return false;
}

bool AxClientWndBase::instantiateObject( REFCLSID iid , bool create )
{
	HRESULT hr;
	try
	{	
		// check if we have an oleFrame
		if ( !oleFrame )
		{
			// prepare dummy instance (doing nothing)
			this->createDummyAxFrame();
		}

		// initialize client site
		this->initAxClientSite();

		// cleanup any existing hosted objects
		if ( oleObject )
		{
			oleObject->Close(OLECLOSE_NOSAVE);	
			oleObject.release();
		}

		// create the COM server obj
		if ( create )
		{
			hr = oleObject.createObject(iid,CLSCTX_ALL);
			if ( hr != S_OK )
			{
				throw mol::X(_T("OleCreate failed!"));
			}
			// wait a bit to give clumsy servers a chance to load
			Sleep(250);
		}
		return true;
	}
	catch (mol::X x)
	{
		oleObject->Close(OLECLOSE_NOSAVE);
		throw x;
	}
	return false;
}


LRESULT AxClientWndBase::wndProcAxImpl( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{				
		case WM_MDIACTIVATE:
		{

			activateLater(wParam,lParam);
			this->callAxDefWndProc( hWnd, message,wParam,lParam);

			//ODBGS("<----WM_MDIACTIVATE END");
			return 0;
		}
		case WM_MOVE:
		{
			//ODBGS("WM_MOVE");
			return this->callAxDefWndProc( hWnd, message,wParam,lParam);
		}
		
		case WM_CLOSE:
		{
			this->getOleClientSite()->SaveObject();
			this->callAxDefWndProc( hWnd, message,wParam,lParam);
			return 0;
		}

		case WM_DESTROY:
		{
			mol::Rect r(0,0,0,0);
			if ( moniker )
			{					
				moniker.release();
			}

			if ( oleObject )
			{	
				//ODBGS("WM_CLOSE");

				// shutdown oleobj
				HRESULT hr = oleObject->Unadvise(cookie_);
				
				this->inplaceDeActivate(TRUE);

			}
			if ( oleObject )
			{	
				//ODBGS("WM_DESTROY");

				// release active obj ref
				activeObject.release();


				HRESULT hr = oleObject->SetClientSite(0);

				hr = ::OleLockRunning(oleObject,FALSE,FALSE);

				hr = oleObject->Close(OLECLOSE_NOSAVE);//);

				// release interfaces

				theStorage.release();
				this->releaseAxClientSite();
				oleFrame.release();

				oleObject.release();	
				return 0;
			}



			this->redrawOleFrame();
			this->callAxDefWndProc( hWnd, message,wParam,lParam);

			if ( !tmpFile_.empty() )
			{
				mol::io::ShellFileOp sfo;

//				if ( 0 == sfo.copy(0,tmpFile_,filename_,FOF_SILENT|FOF_NOCONFIRMATION|FOF_NOCONFIRMMKDIR|FOF_NOERRORUI))
//				{
//					this->oleFrame->SetStatusText( mol::toString(filename_).c_str() );
//					statusBar()->status( filename_ + _T(" saved") );
//					//return S_OK;
//				}

				sfo.remove(0,tmpFile_,FOF_SILENT|FOF_NOCONFIRMATION|FOF_NOCONFIRMMKDIR|FOF_NOERRORUI);
				tmpFile_ = _T("");
			}
			return 0;
		}
		
		case WM_NCDESTROY:
		{
			//oleObject.release();	
			return 0;
		}
		
		default:
		{
			return this->callAxDefWndProc( hWnd, message,wParam,lParam);
		}
	}
	return 0;
}

LRESULT AxClientWndBase::OnMDIActivateLater(WPARAM unused, HWND activated)
{
	HWND wnd = this->getHostingWindow();

	if ( (HWND)(activated)== wnd )
	{				

		if ( oleObject )
		{
			if ( !this->isInplaceActive_)
				this->inplaceActivate(TRUE);
			else
				if ( !this->isUIActive)
					this->inplaceActivate(TRUE);
		}

		if ( activeObject.interface_ != 0 )
		{
			this->oleFrame->SetBorderSpace(0);
			oleFrame->SetActiveObject(activeObject,0);
			activeObject->OnDocWindowActivate(TRUE);												
		}

		mol::TaskThumbnail* t = this->taskthumb();
		if ( t ) 
			t->refreshIcon(true);

	}
	else // deactivate
	{
		mol::TaskThumbnail* t = this->taskthumb();
		if ( t ) 
			t->refreshIcon();

		if ( isShuttingDown_ == true )
		{
			//return 0;
		}
		else
		if ( oleObject && activeObject.interface_ )
		{
			activeObject->OnDocWindowActivate(FALSE);		
		}		
	}	

	// redraw oleframe
	this->redrawOleFrameLater();

	return 0;
}

}} // end ns