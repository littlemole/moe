#ifndef MOL_OLE_HOSTIMPL_DEF_GUARD_
#define MOL_OLE_HOSTIMPL_DEF_GUARD_

#pragma once
#include "util/uni.h"
#include "win/Wnd.h"
#include "win/dlg.h"
#include "ole/ole.h"
#include "ole/storage.h"
#include "ole/punk.h"
#include <mshtmhst.h>
#include <servprov.h>
#include <ocidl.h>

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// ActiveX Frame
//////////////////////////////////////////////////////////////////////


namespace mol {
namespace ole {

template<class T>
class AxFrameImpl : 
	public IOleInPlaceFrame,
	public IOleCommandTarget,
	public interfaces< AxFrameImpl<T>, implements<IOleInPlaceFrame,IOleCommandTarget> >
{
public:

    void init( T* wnd)
	{
		wnd_ = wnd;
	}

    ~AxFrameImpl()
	{
		ODBGS("AxFrameImpl::~AxFrameImpl()");
	}

	virtual void dispose() {}

    // IOleInPlaceFrame
    HRESULT virtual __stdcall GetWindow( HWND FAR* lphwnd)
	{
		return wnd_->IOleInPlaceFrame_GetWindow(lphwnd);
	}
    HRESULT virtual __stdcall ContextSensitiveHelp( BOOL fEnterMode)
	{
		return wnd_->IOleInPlaceFrame_ContextSensitiveHelp( fEnterMode);
	}
    HRESULT virtual __stdcall GetBorder( LPRECT lprectBorder)
	{
		return wnd_->IOleInPlaceFrame_GetBorder( lprectBorder);
	}
    HRESULT virtual __stdcall RequestBorderSpace( LPCBORDERWIDTHS pborderwidths)
	{
		return wnd_->IOleInPlaceFrame_RequestBorderSpace( pborderwidths);
	}
    HRESULT virtual __stdcall SetBorderSpace( LPCBORDERWIDTHS pborderwidths)
	{
		return wnd_->IOleInPlaceFrame_SetBorderSpace( pborderwidths);
	}
    HRESULT virtual __stdcall SetActiveObject( IOleInPlaceActiveObject *pActiveObject, LPCOLESTR pszObjName)
	{
		return wnd_->IOleInPlaceFrame_SetActiveObject( pActiveObject, pszObjName);
	}
    HRESULT virtual __stdcall InsertMenus( HMENU hmenuShared, LPOLEMENUGROUPWIDTHS lpMenuWidths)
	{
		return wnd_->IOleInPlaceFrame_InsertMenus( hmenuShared, lpMenuWidths);
	}
    HRESULT virtual __stdcall SetMenu( HMENU hmenuShared, HOLEMENU holemenu, HWND hwndActiveObject)
	{
		return wnd_->IOleInPlaceFrame_SetMenu( hmenuShared, holemenu, hwndActiveObject);
	}
    HRESULT virtual __stdcall RemoveMenus( HMENU hmenuShared)
	{
		return wnd_->IOleInPlaceFrame_RemoveMenus( hmenuShared);
	}
    HRESULT virtual __stdcall SetStatusText( LPCOLESTR pszStatusText)
	{
		return wnd_->IOleInPlaceFrame_SetStatusText( pszStatusText);
	}
    HRESULT virtual __stdcall EnableModeless( BOOL fEnable)
	{
		return wnd_->IOleInPlaceFrame_EnableModeless( fEnable);
	}
    HRESULT virtual __stdcall TranslateAccelerator( LPMSG lpmsg, WORD wID)
	{
		return wnd_->IOleInPlaceFrame_TranslateAccelerator( lpmsg, wID);
	}

    HRESULT virtual __stdcall  QueryStatus(const GUID *pguidCmdGroup, ULONG cCmds, OLECMD prgCmds[], OLECMDTEXT *pCmdText)
	{
		return wnd_->IOleCommandTarget_QueryStatus(pguidCmdGroup, cCmds, prgCmds, pCmdText);
	}

    HRESULT virtual __stdcall  Exec(const GUID *pguidCmdGroup, DWORD nCmdID, DWORD nCmdexecopt, VARIANTARG *pvaIn, VARIANTARG *pvaOut)
	{
		return wnd_->IOleCommandTarget_Exec(pguidCmdGroup, nCmdID, nCmdexecopt, pvaIn, pvaOut);
	}

protected:
    T*                  wnd_;
};


//////////////////////////////////////////////////////////////////////
// AxClientSite 
//////////////////////////////////////////////////////////////////////

template<class C, class W>
class AxClientSiteImpl : 
	public IOleClientSite,
    public IOleInPlaceSite,
    public IDocHostUIHandler,
    public IDocHostShowUI,
    public IServiceProvider , 
	public IOleControlSite, 
	public ISimpleFrameSite,
	public IOleDocumentSite,
	public IOleInPlaceUIWindow,
	public IAdviseSink,
	public interfaces< AxClientSiteImpl<C,W>,
				implements< 
					IOleClientSite,
					IServiceProvider,
					IOleControlSite,
					IOleInPlaceSite,
					IDocHostUIHandler,
					IDocHostShowUI,
					ISimpleFrameSite,
					IOleDocumentSite,
					IOleInPlaceUIWindow,
					IAdviseSink>>
{
public:

	punk<IOleDocumentView>  documentView;

	void init(C* wnd)
	{
		wnd_  = wnd;
		ODBGS("AxClientSiteImpl::AxClientSiteImpl");
	}

    virtual ~AxClientSiteImpl()
	{
		ODBGS("AxClientSiteImpl::~AxClientSiteImpl()");
	}

	virtual void dispose() {}

    // IOleInPlaceUIWindow
    HRESULT virtual __stdcall GetWindow( HWND FAR* lphwnd)
	{
		return wnd_->IOleInPlaceUIWindow_GetWindow(lphwnd);
	}
    HRESULT virtual __stdcall ContextSensitiveHelp( BOOL fEnterMode)
	{
		return wnd_->IOleInPlaceUIWindow_ContextSensitiveHelp( fEnterMode);
	}
    HRESULT virtual __stdcall GetBorder( LPRECT lprectBorder)
	{
		return wnd_->IOleInPlaceUIWindow_GetBorder( lprectBorder);
	}
    HRESULT virtual __stdcall RequestBorderSpace( LPCBORDERWIDTHS pborderwidths)
	{
		return wnd_->IOleInPlaceUIWindow_RequestBorderSpace( pborderwidths);
	}
    HRESULT virtual __stdcall SetBorderSpace( LPCBORDERWIDTHS pborderwidths)
	{
		return wnd_->IOleInPlaceUIWindow_SetBorderSpace( pborderwidths);
	}
    HRESULT virtual __stdcall SetActiveObject( IOleInPlaceActiveObject *pActiveObject, LPCOLESTR pszObjName)
	{
		return wnd_->IOleInPlaceUIWindow_SetActiveObject( pActiveObject, pszObjName);
	}

	// IOleDocumentSite Implementation
    HRESULT virtual __stdcall  ActivateMe(IOleDocumentView* pViewToActivate)
	{
		return wnd_->IOleDocumentSite_ActivateMe(pViewToActivate);
	}

   //IOleClientSite
    HRESULT virtual __stdcall SaveObject( )
	{
		return wnd_->IOleClientSite_SaveObject();
	}
    HRESULT virtual __stdcall GetMoniker( DWORD dwAssign, DWORD dwWhichMoniker, IMoniker ** ppmk )
	{
		return wnd_->IOleClientSite_GetMoniker( dwAssign, dwWhichMoniker, ppmk );
	}
    HRESULT virtual __stdcall GetContainer( LPOLECONTAINER FAR* ppContainer )
	{
		return wnd_->IOleClientSite_GetContainer( ppContainer );
	}
    HRESULT virtual __stdcall ShowObject()
	{
		return wnd_->IOleClientSite_ShowObject();
	}
    HRESULT virtual __stdcall OnShowWindow( BOOL fShow  )
	{
		return wnd_->IOleClientSite_OnShowWindow( fShow  );
	}
    HRESULT virtual __stdcall RequestNewObjectLayout ()
	{
		return wnd_->IOleClientSite_RequestNewObjectLayout ();
	}
    HRESULT virtual __stdcall ShowContextMenu( DWORD dwID, POINT *ppt, IUnknown *pcmdtReserved, IDispatch *pdispReserved)
	{
		return wnd_->ShowContextMenu( dwID, ppt, pcmdtReserved, pdispReserved);
	}

    //IOleInPlaceSite
    HRESULT virtual __stdcall CanInPlaceActivate()
	{
		return wnd_->IOleInPlaceSite_CanInPlaceActivate();
	}
    HRESULT virtual __stdcall OnInPlaceActivate()
	{
		return wnd_->IOleInPlaceSite_OnInPlaceActivate();
	}

    HRESULT virtual __stdcall OnUIActivate()
	{
		return wnd_->IOleInPlaceSite_OnUIActivate();
	}

    HRESULT virtual __stdcall GetWindowContext( LPOLEINPLACEFRAME FAR* lplpFrame,LPOLEINPLACEUIWINDOW FAR* lplpDoc,LPRECT lprcPosRect,LPRECT lprcClipRect,LPOLEINPLACEFRAMEINFO lpFrameInfo)
	{
		return wnd_->IOleInPlaceSite_GetWindowContext( lplpFrame,lplpDoc, lprcPosRect, lprcClipRect, lpFrameInfo);
	}

    HRESULT virtual __stdcall Scroll( SIZE scrollExtent)
	{
		return wnd_->IOleInPlaceSite_Scroll( scrollExtent);
	}

    HRESULT virtual __stdcall OnUIDeactivate( BOOL fUndoable)
	{
		return wnd_->IOleInPlaceSite_OnUIDeactivate(fUndoable);
	}

    HRESULT virtual __stdcall OnInPlaceDeactivate()
	{
		return wnd_->IOleInPlaceSite_OnInPlaceDeactivate();
	}

    HRESULT virtual __stdcall DiscardUndoState()
	{
		return wnd_->IOleInPlaceSite_DiscardUndoState();
	}

    HRESULT virtual __stdcall DeactivateAndUndo()
	{
		return wnd_->IOleInPlaceSite_DeactivateAndUndo();
	}

    HRESULT virtual __stdcall OnPosRectChange( LPCRECT lprcPosRect)
	{
		return wnd_->IOleInPlaceSite_OnPosRectChange(lprcPosRect);
	}


    //DocHostUiHandler
    HRESULT virtual __stdcall GetHostInfo( DOCHOSTUIINFO *pInfo)
	{
		return wnd_->IDocHostUIHandler_GetHostInfo( pInfo);
	}
    HRESULT virtual __stdcall ShowUI( DWORD dwID, IOleInPlaceActiveObject *pActiveObject, IOleCommandTarget *pCommandTarget, IOleInPlaceFrame *pFrame, IOleInPlaceUIWindow *pDoc)
	{
		return wnd_->IDocHostUIHandler_ShowUI( dwID, pActiveObject, pCommandTarget, pFrame, pDoc);
	}

    HRESULT virtual __stdcall HideUI()
	{
		return wnd_->IDocHostUIHandler_HideUI();
	}
    HRESULT virtual __stdcall UpdateUI()
	{
		return wnd_->IDocHostUIHandler_UpdateUI();
	}

    HRESULT virtual __stdcall EnableModeless( BOOL fEnable)
	{
		return wnd_->IDocHostUIHandler_EnableModeless( fEnable);
	}
    HRESULT virtual __stdcall OnDocWindowActivate( BOOL fActivate)
	{
		return wnd_->IDocHostUIHandler_OnDocWindowActivate( fActivate);
	}
    HRESULT virtual __stdcall OnFrameWindowActivate( BOOL fActivate)
	{
		return wnd_->IDocHostUIHandler_OnFrameWindowActivate( fActivate);
	}
    HRESULT virtual __stdcall ResizeBorder( LPCRECT prcBorder, IOleInPlaceUIWindow *pUIWindow, BOOL fRameWindow)
	{
		return wnd_->IDocHostUIHandler_ResizeBorder( prcBorder, pUIWindow, fRameWindow);
	}
    HRESULT virtual __stdcall TranslateAccelerator( LPMSG lpMsg, const GUID *pguidCmdGroup, DWORD nCmdID)
	{
		return wnd_->IDocHostUIHandler_TranslateAccelerator( lpMsg, pguidCmdGroup, nCmdID);
	}
    HRESULT virtual __stdcall GetOptionKeyPath( LPOLESTR *pchKey, DWORD dw)
	{
		return wnd_->IDocHostUIHandler_GetOptionKeyPath( pchKey, dw);
	}
    HRESULT virtual __stdcall GetDropTarget( IDropTarget *pDropTarget, IDropTarget **ppDropTarget)
	{
		return wnd_->IDocHostUIHandler_GetDropTarget( pDropTarget, ppDropTarget);
	}
    HRESULT virtual __stdcall GetExternal( IDispatch **ppDispatch)
	{
		return wnd_->IDocHostUIHandler_GetExternal( ppDispatch);
	}
    HRESULT virtual __stdcall TranslateUrl( DWORD dwTranslate, OLECHAR *pchURLIn, OLECHAR **ppchURLOut)
	{
		return wnd_->IDocHostUIHandler_TranslateUrl( dwTranslate, pchURLIn, ppchURLOut);
	}
    HRESULT virtual __stdcall FilterDataObject( IDataObject *pDO, IDataObject **ppDORet)
	{
		return wnd_->IDocHostUIHandler_FilterDataObject( pDO, ppDORet);
	}

    //IDocHostShowUI Interface
    HRESULT virtual __stdcall ShowHelp( HWND hwnd, LPOLESTR pszHelpFile, UINT uCommand, DWORD dwData, POINT ptMouse, IDispatch* pDispatchObjectHit )
	{
		return wnd_->IDocHostShowUI_ShowHelp( hwnd, pszHelpFile, uCommand, dwData, ptMouse, pDispatchObjectHit );
	}
    HRESULT virtual __stdcall ShowMessage( HWND hwnd, LPOLESTR lpstrText, LPOLESTR lpstrCaption, DWORD dwType, LPOLESTR lpstrHelpFile, DWORD dwHelpContext, LRESULT* plResult )
	{
		return wnd_->IDocHostShowUI_ShowMessage( hwnd, lpstrText, lpstrCaption, dwType, lpstrHelpFile, dwHelpContext,  plResult );
	}

	// IServiceProvicer
	HRESULT virtual __stdcall QueryService( REFGUID guidService, REFIID riid, void** ppvObject)
	{
		return wnd_->IServiceProvider_QueryService( guidService, riid, ppvObject);
	}

	//IOleControlSite
    HRESULT virtual __stdcall OnControlInfoChanged( void)
	{
		return wnd_->IOleControlSite_OnControlInfoChanged( );
	}
    HRESULT virtual __stdcall LockInPlaceActive( BOOL fLock)
	{
		return wnd_->IOleControlSite_LockInPlaceActive( fLock);
	}
    HRESULT virtual __stdcall GetExtendedControl( IDispatch **ppDisp)
	{
		return wnd_->IOleControlSite_GetExtendedControl( ppDisp);
	}
    HRESULT virtual __stdcall TransformCoords( POINTL *pPtlHimetric,POINTF *pPtfContainer,DWORD dwFlags)
	{
		return wnd_->IOleControlSite_TransformCoords( pPtlHimetric,pPtfContainer,dwFlags);
	}
    HRESULT virtual __stdcall TranslateAccelerator( MSG *pMsg,DWORD grfModifiers)
	{
		return wnd_->IOleControlSite_TranslateAccelerator( pMsg,grfModifiers);
	}
    HRESULT virtual __stdcall OnFocus( BOOL fGotFocus)
	{
		return wnd_->IOleControlSite_OnFocus( fGotFocus);
	}
    HRESULT virtual __stdcall ShowPropertyFrame( void)
	{
		return wnd_->IOleControlSite_ShowPropertyFrame( );
	}

	//ISimpleFrameSite
    HRESULT virtual __stdcall PreMessageFilter( HWND hWnd, UINT msg, WPARAM wp, LPARAM lp,LRESULT *plResult, DWORD *pdwCookie)
	{
		return wnd_->ISimpleFrameSite_PreMessageFilter( hWnd, msg, wp, lp,plResult, pdwCookie);
	}
    HRESULT virtual __stdcall PostMessageFilter( HWND hWnd, UINT msg, WPARAM wp, LPARAM lp,LRESULT *plResult,DWORD dwCookie)
	{
		return wnd_->ISimpleFrameSite_PostMessageFilter( hWnd,  msg, wp, lp,plResult,dwCookie);
	}

	//IAdviseSink
	void virtual __stdcall OnDataChange( FORMATETC *pFormatetc, STGMEDIUM *pStgmed) 
	{
		wnd_->IAdviseSink_OnDataChange( pFormatetc, pStgmed);
	}
        
	void virtual __stdcall OnViewChange( DWORD dwAspect,LONG lindex)
	{
		wnd_->IAdviseSink_OnViewChange( dwAspect, lindex);
	}
        
	void virtual __stdcall OnRename( IMoniker *pmk) 
	{
		wnd_->IAdviseSink_OnRename( pmk);
	}
	        
	void virtual __stdcall OnSave( void) 
	{
		wnd_->IAdviseSink_OnSave(); 
	}
	        
	void virtual __stdcall OnClose( void)
	{
		wnd_->IAdviseSink_OnClose();
	}

protected:
   C*				wnd_;
};


} // end namespace ole
} // end namespace mol

#endif
