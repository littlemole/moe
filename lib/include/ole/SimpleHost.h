#ifndef MOL_DEF_GUARD_SIMPLE_AX_HOST_DEF_GUARD_DEFINE
#define MOL_DEF_GUARD_SIMPLE_AX_HOST_DEF_GUARD_DEFINE

#include "ole/punk.h"
#include "ole/obj.h"

namespace mol {
namespace ole {


extern HRESULT copyStorageTemp(IStorage* src, IStorage** copy);


///////////////////////////////////////////////////////////////////////////////

class InplaceFrame :
	public IOleInPlaceFrame,
	public mol::interfaces<
			InplaceFrame,
				mol::implements<
					IOleInPlaceFrame,
					IOleInPlaceUIWindow,
					IOleWindow> >
{
private:

	HWND wnd_;

public:

	mol::punk<IOleInPlaceActiveObject> activeObject;

	typedef mol::com_obj<InplaceFrame> Instance;

	static Instance* CreateInstance( HWND w )
	{
		Instance* instance = new Instance;
		instance->wnd_ = w;
		return instance;
	}

	void dispose() 
	{
		activeObject.release();
	}


	// IOleWindow
    HRESULT virtual __stdcall GetWindow( HWND FAR* lphwnd)
	{
		*lphwnd = wnd_;
		return S_OK;
	}
    HRESULT virtual __stdcall ContextSensitiveHelp( BOOL fEnterMode)
	{
		return E_NOTIMPL;
	}

	// IOleInPlaceUIWindow
    HRESULT virtual __stdcall GetBorder( LPRECT lprectBorder)
	{
		return E_NOTIMPL;
	}
    HRESULT virtual __stdcall RequestBorderSpace( LPCBORDERWIDTHS pborderwidths)
	{
		return E_NOTIMPL;
	}
    HRESULT virtual __stdcall SetBorderSpace( LPCBORDERWIDTHS pborderwidths)
	{
		return E_NOTIMPL;
	}
    HRESULT virtual __stdcall SetActiveObject( IOleInPlaceActiveObject *pActiveObject, LPCOLESTR pszObjName)
	{
		activeObject = pActiveObject;
		return S_OK;
	}

	// IOleInPlaceFrame
    HRESULT virtual __stdcall InsertMenus( HMENU hmenuShared, LPOLEMENUGROUPWIDTHS lpMenuWidths)
	{
		return E_NOTIMPL;
	}
    HRESULT virtual __stdcall SetMenu( HMENU hmenuShared, HOLEMENU holemenu, HWND hwndActiveObject)
	{
		return E_NOTIMPL;
	}
    HRESULT virtual __stdcall RemoveMenus( HMENU hmenuShared)
	{
		return E_NOTIMPL;
	}
    HRESULT virtual __stdcall SetStatusText( LPCOLESTR pszStatusText)
	{
		return E_NOTIMPL;
	}
    HRESULT virtual __stdcall EnableModeless( BOOL fEnable)
	{
		return E_NOTIMPL;
	}

    HRESULT virtual __stdcall TranslateAccelerator( LPMSG lpmsg, WORD wID)
	{
		return S_OK;
	}
};

///////////////////////////////////////////////////////////////////////////////

class ClientSite : 
	public IOleInPlaceSite,
	public IOleClientSite,
	public mol::interfaces<ClientSite,mol::implements<IOleClientSite,IOleInPlaceSite,IOleWindow> >
{
private:

	HWND wnd_;

	mol::punk<IOleInPlaceFrame> frame_;

public:

	typedef mol::com_obj<ClientSite> Instance;

	static Instance* CreateInstance( HWND w, IOleInPlaceFrame* f )
	{
		Instance* instance = new Instance;
		instance->wnd_ = w;
		instance->frame_ = f;
		return instance;
	}

	void dispose() 
	{ 
		frame_.release(); 
	}

	// IOleInPlaceSite
    HRESULT virtual __stdcall SaveObject( )
	{
		return S_OK;
	}
    HRESULT virtual __stdcall GetMoniker( DWORD dwAssign, DWORD dwWhichMoniker, IMoniker ** ppmk )
	{
		return E_NOTIMPL;
	}
    HRESULT virtual __stdcall GetContainer( LPOLECONTAINER FAR* ppContainer )
	{
		*ppContainer = 0;
		return E_NOINTERFACE ;
	}
    HRESULT virtual __stdcall ShowObject()
	{
		return S_OK;
	}
    HRESULT virtual __stdcall OnShowWindow( BOOL fShow  )
	{
		return S_OK;
	}
    HRESULT virtual __stdcall RequestNewObjectLayout ()
	{
		return S_OK;
	}
    HRESULT virtual __stdcall ShowContextMenu( DWORD dwID, POINT *ppt, IUnknown *pcmdtReserved, IDispatch *pdispReserved)
	{
		return S_OK;
	}

	// IOleWindow
    HRESULT virtual __stdcall GetWindow( HWND FAR* lphwnd)
	{
		*lphwnd = wnd_;
		return S_OK;
	}
    HRESULT virtual __stdcall ContextSensitiveHelp( BOOL fEnterMode)
	{
		return E_NOTIMPL;
	}


	// IOleInPlaceFrame
    HRESULT virtual __stdcall CanInPlaceActivate()
	{
		return S_OK;
	}
    HRESULT virtual __stdcall OnInPlaceActivate()
	{
		return S_OK;
	}

    HRESULT virtual __stdcall OnUIActivate()
	{
		return S_OK;
	}

    HRESULT virtual __stdcall GetWindowContext( LPOLEINPLACEFRAME FAR* lplpFrame,LPOLEINPLACEUIWINDOW FAR* lplpDoc,LPRECT lprcPosRect,LPRECT lprcClipRect,LPOLEINPLACEFRAMEINFO lpFrameInfo)
	{
		frame_->QueryInterface( IID_IOleInPlaceFrame, (void**)lplpFrame );

		*lplpDoc = 0;
		lpFrameInfo->fMDIApp = FALSE;
		lpFrameInfo->hwndFrame = wnd_;
		lpFrameInfo->haccel = 0;
		lpFrameInfo->cAccelEntries = 0;

		RECT r;
		::GetClientRect(wnd_,&r);
		*lprcPosRect = r;
		*lprcClipRect = r;
		return S_OK;
	}

    HRESULT virtual __stdcall Scroll( SIZE scrollExtent)
	{
		return E_NOTIMPL;
	}

    HRESULT virtual __stdcall OnUIDeactivate( BOOL fUndoable)
	{
		return S_OK;
	}

    HRESULT virtual __stdcall OnInPlaceDeactivate()
	{
		return S_OK;
	}

    HRESULT virtual __stdcall DiscardUndoState()
	{
		return S_OK;
	}

    HRESULT virtual __stdcall DeactivateAndUndo()
	{
		return S_OK;
	}

    HRESULT virtual __stdcall OnPosRectChange( LPCRECT lprcPosRect)
	{
//		mol::punk<IOleInPlaceObject>	inplace(oleObject);
//		inplace->SetObjectRects(lprcPosRect, lprcPosRect);		
		return S_OK;
	}
};

template<class C, class W>
class SimpleAxHost : public W
{
public:

	typedef W	BaseWindowType;
	typedef C	ThisWindowType;

	SimpleAxHost::SimpleAxHost( ) 
	{
		eraseBackground_ = 1;
	}

	//////////////////////////////////////////////////////////////////////////////

	virtual SimpleAxHost::~SimpleAxHost() 
	{
		//ODBGS("~SimpleAxHost dies");
	};

	virtual void dispose() 
	{
		if ( oleObject )
		{
			oleObject->Close(0);

			if ( clientSite )
				clientSite->dispose();
		
			oleObject.release();

			if ( clientSite )
				clientSite.release();
		}

		if ( frame )
			frame.release();
	}


    virtual LRESULT wndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch(message)
		{
			case WM_CREATE:
			{
				frame = InplaceFrame::CreateInstance(*this);
				clientSite = ClientSite::CreateInstance(*this,frame);
				break;
			}
			case WM_DESTROY:
			{
				dispose();
				break;
			}
		}
		return BaseWindowType::wndProc(hWnd,message,wParam,lParam);
	}


	// override for special handling
	virtual LRESULT OnSize(UINT message, WPARAM wParam, LPARAM lParam )
	{
		BaseWindowType::OnSize(message,wParam,lParam);

		mol::Rect clientRect_ = mol::Rect(0,0,0,0);

		// get new width and height
		clientRect_.right  = LOWORD(lParam) ;
		clientRect_.bottom = HIWORD(lParam) ;

		if ( oleObject )
		{

			SIZEL s = { clientRect_.right, clientRect_.bottom };
			mol::ole::PixeltoHIMETRIC(&s);

			HRESULT hr = oleObject->SetExtent(DVASPECT_CONTENT,&s);
					
			mol::punk<IOleInPlaceObject> oip(oleObject);
			oip->SetObjectRects(&clientRect_,&clientRect_);
		}
		return 0;
	}

protected:

	bool initObject( REFCLSID clsid, IStorage* store )
	{
		HRESULT hr = createEmbeddedObject(clsid,store);
		if ( hr != S_OK )
			return false;

		mol::punk<IPersistStorage> ps(oleObject);
		if ( ps )
		{
			hr = ps->InitNew(store);
			if ( hr != S_OK )
				return false;
		}

		hr = showEmbeddedObject(clsid,store);
		if ( hr != S_OK )
			return false;
		return true;
	}

	bool loadObject( REFCLSID clsid, IStorage* store )
	{
		HRESULT hr = createEmbeddedObject(clsid,store);
		if ( hr != S_OK )
			return false;

		mol::punk<IPersistStorage> ps(oleObject);
		if ( !ps )
			return false;

		mol::punk<IStorage> s;
		hr = copyStorageTemp(store,&s);
		if ( hr != S_OK )
			return false;

		hr = ps->Load(s);
		if ( hr != S_OK )
			return false;

		hr = showEmbeddedObject(clsid,store);
		if ( hr != S_OK )
			return false;
		return true;
	}

protected:

	mol::punk<IOleObject> oleObject;
	mol::punk<ClientSite::Instance> clientSite;
	mol::punk<InplaceFrame::Instance> frame;

	HRESULT createEmbeddedObject( REFCLSID clsid, IStorage* store )
	{
		if ( oleObject )
		{
			oleObject->Close(OLECLOSE_NOSAVE);
			oleObject.release();
		}

		HRESULT hr = oleObject.createObject( clsid );
		if ( hr != S_OK )
			return hr;

		mol::punk<IOleClientSite> cs(clientSite);
		hr = oleObject->SetClientSite( cs );
		return hr;
	}

	HRESULT showEmbeddedObject( REFCLSID clsid, IStorage* store )
	{
		HRESULT hr = oleObject->SetHostNames(L"My Host Name", 0);
		if ( hr != S_OK )
			return hr;

		hr = OleSetContainedObject( oleObject,TRUE);
		if ( hr != S_OK )
			return hr;

		RECT r;
		getClientRect(r);
		mol::punk<IOleClientSite> cs(clientSite);
		hr = oleObject->DoVerb(OLEIVERB_SHOW, NULL, cs, -1, *this, &r);
		return hr;
	}

	
};


}}

#endif