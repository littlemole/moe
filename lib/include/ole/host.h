#ifndef MOL_OLE_HOST_DEF_GUARD_
#define MOL_OLE_HOST_DEF_GUARD_

#pragma once
#include "ole/container.h"
#include "win/async.h"
#include "win/layout.h"
#include "win/shell.h"
#include "win/Taskbar.h"

//////////////////////////////////////////////////////////////////////

namespace mol {
namespace ole {

//////////////////////////////////////////////////////////////////////
// AX Client Wnd Base
//////////////////////////////////////////////////////////////////////

class AxClientWndBase 
{
public:

	// the ole frame
	punk<IOleInPlaceFrame> oleFrame;

	// the embedded object
    punk<IOleObject>	 oleObject;

	// the embedded objects view
	punk<IOleDocumentView> documentView;

	// active object
	punk<IOleInPlaceActiveObject> activeObject;

	punk<IMoniker>			moniker;
	punk<IStorage>			theStorage;

public:

    AxClientWndBase();
    ~AxClientWndBase();

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

public:

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	virtual bool loadObjectFromStorage( REFCLSID iid, IStorage* store );
	virtual bool loadObjectFromStream( REFCLSID iid, IStream* stream);
	virtual bool loadObjectFromPersistFile( REFCLSID iid, const std::wstring& file);
	virtual bool newObjectFromStorage( REFCLSID iid );
	virtual bool loadObjectFromShell(const std::wstring& file);
	virtual bool loadObject( REFCLSID iid );
	virtual bool loadObjectFromMoniker(const std::wstring& path);

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	// COM impl
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	// styles
    virtual int style();
	virtual LRESULT OnMDIActivateLater(WPARAM unused,HWND activated);

protected:

    // IOleInPlaceUIWindow
    HRESULT virtual __stdcall IOleInPlaceUIWindow_GetWindow( HWND FAR* lphwnd);
    HRESULT virtual __stdcall IOleInPlaceUIWindow_ContextSensitiveHelp( BOOL fEnterMode);
    HRESULT virtual __stdcall IOleInPlaceUIWindow_GetBorder( LPRECT lprectBorder);
    HRESULT virtual __stdcall IOleInPlaceUIWindow_RequestBorderSpace( LPCBORDERWIDTHS pborderwidths);
    HRESULT virtual __stdcall IOleInPlaceUIWindow_SetBorderSpace( LPCBORDERWIDTHS pborderwidths);
    HRESULT virtual __stdcall IOleInPlaceUIWindow_SetActiveObject( IOleInPlaceActiveObject *pActiveObject, LPCOLESTR pszObjName);

	// IOleDocumentSite Implementation
	HRESULT virtual __stdcall  IOleDocumentSite_ActivateMe(IOleDocumentView* pViewToActivate);

    //IOleClientSite
    HRESULT virtual __stdcall IOleClientSite_SaveObject( );
	HRESULT virtual __stdcall IOleClientSite_GetMoniker( DWORD dwAssign, DWORD dwWhichMoniker, IMoniker ** ppmk );
    HRESULT virtual __stdcall IOleClientSite_GetContainer( LPOLECONTAINER FAR* ppContainer );
    HRESULT virtual __stdcall IOleClientSite_ShowObject();
    HRESULT virtual __stdcall IOleClientSite_OnShowWindow( BOOL fShow  );
    HRESULT virtual __stdcall IOleClientSite_RequestNewObjectLayout ();
    HRESULT virtual __stdcall ShowContextMenu( DWORD dwID, POINT *ppt, IUnknown *pcmdtReserved, IDispatch *pdispReserved);

    //IOleInPlaceSite
    HRESULT virtual __stdcall IOleInPlaceSite_GetWindow( HWND FAR* lphwnd);
	HRESULT __stdcall IOleInPlaceSite_GetWindowContext( LPOLEINPLACEFRAME FAR* lplpFrame,
                                LPOLEINPLACEUIWINDOW FAR* lplpDoc,
                                LPRECT lprcPosRect,
                                LPRECT lprcClipRect,
                                LPOLEINPLACEFRAMEINFO lpFrameInfo);
    HRESULT virtual __stdcall IOleInPlaceSite_ContextSensitiveHelp( BOOL fEnterMode);
    HRESULT virtual __stdcall IOleInPlaceSite_CanInPlaceActivate();
	HRESULT virtual __stdcall IOleInPlaceSite_OnInPlaceActivate();
    HRESULT virtual __stdcall IOleInPlaceSite_OnUIActivate();
	HRESULT virtual __stdcall IOleInPlaceSite_Scroll( SIZE scrollExtent);
    HRESULT virtual __stdcall IOleInPlaceSite_OnUIDeactivate( BOOL fUndoable);
    HRESULT virtual __stdcall IOleInPlaceSite_OnInPlaceDeactivate();
    HRESULT virtual __stdcall IOleInPlaceSite_DiscardUndoState();
    HRESULT virtual __stdcall IOleInPlaceSite_DeactivateAndUndo();
    HRESULT virtual __stdcall IOleInPlaceSite_OnPosRectChange( LPCRECT lprcPosRect);

    //DocHostUiHandler - meaningfull for IE explorer
    HRESULT virtual __stdcall IDocHostUIHandler_GetHostInfo( DOCHOSTUIINFO *pInfo);
    HRESULT virtual __stdcall IDocHostUIHandler_ShowUI( DWORD dwID, IOleInPlaceActiveObject *pActiveObject, IOleCommandTarget *pCommandTarget, IOleInPlaceFrame *pFrame, IOleInPlaceUIWindow *pDoc);
    HRESULT virtual __stdcall IDocHostUIHandler_HideUI();
    HRESULT virtual __stdcall IDocHostUIHandler_UpdateUI();
    HRESULT virtual __stdcall IDocHostUIHandler_EnableModeless( BOOL fEnable);
    HRESULT virtual __stdcall IDocHostUIHandler_OnDocWindowActivate( BOOL fActivate);
    HRESULT virtual __stdcall IDocHostUIHandler_OnFrameWindowActivate( BOOL fActivate);
	HRESULT virtual __stdcall IDocHostUIHandler_ResizeBorder( LPCRECT prcBorder, IOleInPlaceUIWindow *pUIWindow, BOOL fRameWindow);
    HRESULT virtual __stdcall IDocHostUIHandler_TranslateAccelerator( LPMSG lpMsg, const GUID *pguidCmdGroup, DWORD nCmdID);
    HRESULT virtual __stdcall IDocHostUIHandler_GetOptionKeyPath( LPOLESTR *pchKey, DWORD dw);
    HRESULT virtual __stdcall IDocHostUIHandler_GetDropTarget( IDropTarget *pDropTarget, IDropTarget **ppDropTarget);
    HRESULT virtual __stdcall IDocHostUIHandler_GetExternal( IDispatch **ppDispatch);
    HRESULT virtual __stdcall IDocHostUIHandler_TranslateUrl( DWORD dwTranslate, OLECHAR *pchURLIn, OLECHAR **ppchURLOut);
    HRESULT virtual __stdcall IDocHostUIHandler_FilterDataObject( IDataObject *pDO, IDataObject **ppDORet);

    //IDocHostShowUI Interface
    HRESULT virtual __stdcall IDocHostShowUI_ShowHelp( HWND hwnd, LPOLESTR pszHelpFile, UINT uCommand, DWORD dwData, POINT ptMouse, IDispatch* pDispatchObjectHit );
    HRESULT virtual __stdcall IDocHostShowUI_ShowMessage( HWND hwnd, LPOLESTR lpstrText, LPOLESTR lpstrCaption, DWORD dwType, LPOLESTR lpstrHelpFile, DWORD dwHelpContext, LRESULT* plResult );

	// IServiceProvicer
	HRESULT virtual __stdcall IServiceProvider_QueryService( REFGUID guidService, REFIID riid, void** ppvObject);

	//IOleControlSite
    HRESULT virtual __stdcall IOleControlSite_OnControlInfoChanged( void);
    HRESULT virtual __stdcall IOleControlSite_LockInPlaceActive( BOOL fLock);
	HRESULT virtual __stdcall IOleControlSite_GetExtendedControl( IDispatch **ppDisp);
    HRESULT virtual __stdcall IOleControlSite_TransformCoords( POINTL *pPtlHimetric,POINTF *pPtfContainer,DWORD dwFlags);
    HRESULT virtual __stdcall IOleControlSite_TranslateAccelerator( MSG *pMsg,DWORD grfModifiers);
    HRESULT virtual __stdcall IOleControlSite_OnFocus( BOOL fGotFocus);
    HRESULT virtual __stdcall IOleControlSite_ShowPropertyFrame( void);

	//ISimpleFrameSite
    HRESULT virtual __stdcall ISimpleFrameSite_PreMessageFilter( HWND hWnd, UINT msg, WPARAM wp, LPARAM lp,LRESULT *plResult, DWORD *pdwCookie);
    HRESULT virtual __stdcall ISimpleFrameSite_PostMessageFilter( HWND hWnd, UINT msg, WPARAM wp, LPARAM lp,LRESULT *plResult,DWORD dwCookie);

	//IAdviseSink
	void virtual __stdcall IAdviseSink_OnDataChange( FORMATETC *pFormatetc, STGMEDIUM *pStgmed);
	void virtual __stdcall IAdviseSink_OnViewChange( DWORD dwAspect,LONG lindex);
	void virtual __stdcall IAdviseSink_OnRename( IMoniker *pmk);
	void virtual __stdcall IAdviseSink_OnSave( void);
	void virtual __stdcall IAdviseSink_OnClose( void);

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////


protected:

	// trampolines

	// object instantiation
	virtual bool instantiateObject( REFCLSID iid , bool create = true );// = 0;
	virtual bool embeddObject();// = 0;
	virtual bool inplaceActivate(bool withUI);// = 0;
	virtual bool inplaceDeActivate(bool full);

	// ctor/dtor helpers
	virtual HWND getHostingWindow() = 0;
	virtual void initAxClientSite() = 0;
	virtual void releaseAxClientSite() = 0;

	// talk to embdedding host
	virtual ole::AxFrameBase* createDummyAxFrame() = 0;
	virtual mol::TaskThumbnail* taskthumb() = 0;
	virtual void redrawOleFrame() = 0;
	virtual void redrawOleFrameLater() = 0;
	virtual bool getMidiState() = 0;
	virtual void activateLater( WPARAM wParam, LPARAM lParam) = 0;

	// acquire required OLE interfaces from derived template
	virtual IOleClientSite* getOleClientSite() = 0;
	virtual IOleDocumentSite* getOleDocumentSite() = 0;
	virtual IOleInPlaceSite* getOleInPlaceSite() = 0;

	// sizing helper
	virtual RECT prepareClientRect() = 0;

	// backtrack def window procedure	
	virtual LRESULT callAxDefWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) = 0;

	// optional
	virtual void OnLoadProgress(int n)
	{
	}

	// impl

	// window procedure impl
    virtual LRESULT wndProcAxImpl( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


	// sizing
	void SetObjectSize(RECT& r);

	// updating
	void updateObject();

	// trap WM_SIZE events
	LRESULT handleOnSize( UINT message, WPARAM wParam, LPARAM lParam, mol::LayoutMgr* layout );

	// impl handlers
	mol::Rect handleDoLayout(mol::Rect r, mol::LayoutMgr* layout);

	// tmp storage helper for OLE objects (ie office support)
	HRESULT copyStorageTemp(IStorage* src, IStorage** copy);

	//state
	HWND			frameWnd_;
    RECT			clientRect_;
	bool			isInplaceActive_;
	bool			isUIActive;
	bool			isShuttingDown_;
	DWORD			cookie_;
	std::wstring	tmpFile_;
};

}

//////////////////////////////////////////////////////////////////////
// AX Client Wnd
//////////////////////////////////////////////////////////////////////

template<class C, class W>
class AxClientWnd : public W, public ole::AxClientWndBase
{
	friend class mol::ole::AxClientSiteImpl<C,W>;
public:

	// the ole client site
	typedef com_obj<mol::ole::AxClientSiteImpl<C,W>> AxClientSite;
	punk<AxClientSite> axClientSite;

public:

    AxClientWnd()
	{
		axClientSite = new AxClientSite;
		this->eraseBackground_ = 1;
		dummyFrame_ = 0;
	}

    ~AxClientWnd()
	{
		//ODBGS("AxClientWnd died :o");
		delete dummyFrame_;
	}


	//////////////////////////////////////////////////////////////////////

	virtual bool loadObjectFromMoniker(const std::wstring& path)
	{
		if ( !mol::ole::AxClientWndBase::loadObjectFromMoniker( path ))
			return false;

		HRESULT hr = oleObject->Advise((IAdviseSink*)axClientSite,&cookie_);
		return hr == S_OK;
	}

	//////////////////////////////////////////////////////////////////////

	HRESULT __stdcall oleTargetExec(OLECMDID n, OLECMDEXECOPT flag = OLECMDEXECOPT_PROMPTUSER)
	{
		punk<IOleCommandTarget> oct(oleObject);
		if ( oct )
		{
			return oct->Exec(0,n,flag,0,0);
		}
		return E_FAIL;
	}

	//////////////////////////////////////////////////////////////////////

    virtual LRESULT wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		return mol::ole::AxClientWndBase::wndProcAxImpl(  hWnd, message, wParam, lParam );
	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

protected:

	HWND createWindow(const std::wstring& windowName, HMENU id, const mol::Rect& r, HWND frame)
	{
		W::createWindow( windowName, id, r, frame );

		this->getClientRect( clientRect_);
		frameWnd_ = frame;
		oleFrame  = 0;

		// check if the hosting frame window ISA AxFrameBase derived one
		// if so, start enabling OLE container features
		mol::ole::AxFrameBase* base = mol::wndFromHWND<mol::ole::AxFrameBase>(frame);
		if (base)
		{
			base->axFrameSite->QueryInterface(IID_IOleInPlaceFrame,(void**)&oleFrame);
		}

		return this->hWnd_;
	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	// trap WM_SIZE events and keep clientRect_ uptodate
	// then do a re-layout
	LRESULT OnSize( UINT message, WPARAM wParam, LPARAM lParam)
	{
		return mol::ole::AxClientWndBase::handleOnSize( message, wParam, lParam, this->layout_ );
	}

	//////////////////////////////////////////////////////////////////////
	// relayout request handle
	//////////////////////////////////////////////////////////////////////

	LRESULT OnLayout( UINT message, WPARAM wParam, LPARAM lParam)
	{
		//ODBGS("AxClient OnLayout");
		this->getClientRect(clientRect_);
		doLayout();
		return 0;
	}

	virtual IOleClientSite* getOleClientSite()
	{
		return (IOleClientSite*)axClientSite;
	}
private:

	// if we don't have an OLE frame, we use
	// a dummy implementation. this will disable
	// support for OLE embedding of toolbars / menus
	// and ole command targets if used

	class DummyFrame_ 
		: public AxFrame<DummyFrame_,W>
	{};

	DummyFrame_* dummyFrame_;

	virtual ole::AxFrameBase* createDummyAxFrame()
	{
		// prepare dummy instance (doing nothing)
		dummyFrame_ = new DummyFrame_;
		dummyFrame_->attach(*this);
		oleFrame = dummyFrame_->axFrameSite;
		return dummyFrame_;
	}

	// get hosting window
	virtual HWND getHostingWindow()
	{
		return (HWND)*this;
	}

	virtual mol::TaskThumbnail* taskthumb()
	{
		mol::MdiChild* mc = mol::wndFromHWND<mol::MdiChild>(*this);
		if ( mc )
		{
			mol::TaskThumbnail* t = &mc->thumb;
			return t;
		}
		return 0;
	}

	// handle ax client site c'tor/d'tor
	virtual void initAxClientSite()
	{
		axClientSite->init( (C*)this );
	}

	virtual void releaseAxClientSite()
	{
		axClientSite.release();				
	}



	// access ax client site OLE interfaces



	virtual IOleDocumentSite* getOleDocumentSite() 
	{ 
		return (IOleDocumentSite*)axClientSite; 
	}

	virtual IOleInPlaceSite* getOleInPlaceSite() 
	{ 
		return (IOleInPlaceSite*)axClientSite; 
	}

	// refresh client rect 
	virtual RECT prepareClientRect() 
	{
		this->getClientRect(clientRect_);
		return clientRect_;
	}

	// access MDI state
	virtual bool getMidiState()
	{
		return this->isMidi_; 
	}

	// delay the ax mdi activation handling until base mdi processing is done
	virtual void activateLater( WPARAM wParam, LPARAM lParam)
	{
		//if ( this->getHostingWindow() == (HWND)lParam )
		{
			mol::dispatch<AxClientWnd<C,W> >( *((AxClientWnd<C,W>*)this), &AxClientWnd<C,W>::OnMDIActivateLater, wParam, (HWND)lParam );
		}
		//OnMDIActivateLater(wParam,(HWND)lParam);
	}

	// layout helper, resizes the embedded ax obj
	mol::Rect  doLayout()
	{
		return mol::ole::AxClientWndBase::handleDoLayout( clientRect_, this->layout_ );
	}

	// route windows message to this windows base class window proc
	virtual LRESULT callAxDefWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		return W::wndProc(hWnd, message, wParam, lParam );
	}

protected:
	// redraw virtually ALL
	virtual void redrawOleFrame()
	{
		// redraw oleframe
		mol::win::WndProc* f = mol::wndFromHWND<mol::win::WndProc>(this->getParent());
		if (!f)
			return;

		f->OnLayout(0,0,0);
		f->redraw();

	}

	// hack to redraw after all OLE window messages involved in
	// re-activation are eaten before
	virtual void redrawOleFrameLater()
	{
		mol::dispatch<AxClientWnd<C,W> >( *((AxClientWnd<C,W>*)this), &AxClientWnd<C,W>::redrawOleFrame );
	}


};


//////////////////////////////////////////////////////////////////////
// AX Wnd Template
//////////////////////////////////////////////////////////////////////

template<class C, class W, const GUID* G>
class AxWnd : public AxClientWnd<C,W>
{
public:

	HWND createWindow(const std::wstring& windowName, HMENU id, const mol::Rect& r, HWND parent)
    {
		AxClientWnd<C,W>::createWindow( windowName, id, r, parent );
		this->show(SW_SHOW);
		this->getClientRect(this->clientRect_);
		this->loadObject(*G);
        return this->hWnd_;
    }
};

} // end namespace mol

#endif
