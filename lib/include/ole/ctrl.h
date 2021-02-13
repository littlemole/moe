#ifndef MOL_OLE_CTRL_DEF_GUARD_
#define MOL_OLE_CTRL_DEF_GUARD_

#pragma once
#include "util/uni.h"
#include "win/wnd.h"
#include "win/res.h"
#include "ole/factory.h"
#include "ole/ole.h"
#include "ole/cp.h"
#include "ole/persist.h"
#include "ole/stream.h"
#include "ole/dataobj.h"
#include <ocidl.h>
#include <set>

namespace mol {

///////////////////////////////////////////////////////////
// IRunnableObject - dummy Impl
///////////////////////////////////////////////////////////

class RunnableObj : public IRunnableObject
{
public:

	virtual HRESULT __stdcall GetRunningClass(LPCLSID lpClsid);
	virtual HRESULT __stdcall Run(LPBINDCTX);
	virtual BOOL    __stdcall IsRunning();
	virtual HRESULT __stdcall LockRunning(BOOL fLock, BOOL fLastUnlockCloses);
	virtual HRESULT __stdcall SetContainedObject(BOOL fContained);
};

///////////////////////////////////////////////////////////
// Basic Ole Object Impl Base
///////////////////////////////////////////////////////////

namespace ole {

class OleObjBase :
	public IOleObject,
	public DataObjBase
{
public:
	OleObjBase();
	virtual ~OleObjBase();

	//IDataObject
	virtual HRESULT __stdcall GetData( FORMATETC * pFormatetc, STGMEDIUM * pmedium );
	virtual HRESULT __stdcall GetDataHere( FORMATETC * pFormatetc, STGMEDIUM * pmedium  );
	virtual HRESULT __stdcall QueryGetData( FORMATETC * pFormatetc );
	virtual HRESULT __stdcall GetCanonicalFormatEtc( FORMATETC * pFormatetcIn, FORMATETC * pFormatetcOut );
	virtual HRESULT __stdcall SetData(  FORMATETC * pFormatetc,  STGMEDIUM * pmedium,  BOOL fRelease );
	virtual HRESULT __stdcall EnumFormatEtc(  DWORD dwDirection,  IEnumFORMATETC ** ppenumFormatetc );
	virtual HRESULT __stdcall DAdvise( FORMATETC * pFormatetc,  DWORD advf, IAdviseSink * pAdvSink, DWORD * pdwConnection );
	virtual HRESULT __stdcall DUnadvise( DWORD dwConnection );
	virtual HRESULT __stdcall EnumDAdvise( IEnumSTATDATA ** ppenumAdvise );

	//IOleObject
	virtual HRESULT __stdcall SetHostNames( LPCOLESTR szContainerApp,LPCOLESTR szContainerObj);
	virtual HRESULT __stdcall GetMiscStatus( DWORD dwAspect,DWORD *pdwStatus);

	virtual HRESULT __stdcall SetClientSite( IOleClientSite *pClientSite);
	virtual HRESULT __stdcall GetClientSite( IOleClientSite **ppClientSite);

	virtual HRESULT __stdcall Close( DWORD dwSaveOption);

	virtual HRESULT __stdcall DoVerb( LONG iVerb,LPMSG lpmsg,IOleClientSite *pActiveSite,LONG lindex,HWND hwndParent,LPCRECT lprcPosRect);
	virtual HRESULT __stdcall EnumVerbs( IEnumOLEVERB **ppEnumOleVerb);

	virtual HRESULT __stdcall Update( void);
	virtual HRESULT __stdcall IsUpToDate( void);

	virtual HRESULT __stdcall GetUserClassID( CLSID *pClsid); // <<--
	virtual HRESULT __stdcall GetUserType( DWORD dwFormOfType,LPOLESTR *pszUserType);

	virtual HRESULT __stdcall SetExtent( DWORD dwDrawAspect,SIZEL *psizel);
	virtual HRESULT __stdcall GetExtent( DWORD dwDrawAspect,SIZEL *psizel);

	virtual HRESULT __stdcall Advise(IAdviseSink *pAdvSink,DWORD *pdwConnection);
	virtual HRESULT __stdcall Unadvise( DWORD dwConnection);
	virtual HRESULT __stdcall EnumAdvise( IEnumSTATDATA **ppenumAdvise);

	virtual HRESULT __stdcall SetMoniker( DWORD dwWhichMoniker,IMoniker *pmk);
	virtual HRESULT __stdcall GetMoniker( DWORD dwAssign,DWORD dwWhichMoniker,IMoniker **ppmk);

	virtual HRESULT __stdcall InitFromData( IDataObject *pDataObject,BOOL fCreation,DWORD dwReserved);
	virtual HRESULT __stdcall GetClipboardData( DWORD dwReserved,IDataObject **ppDataObject);
	virtual HRESULT __stdcall SetColorScheme( LOGPALETTE *pLogpal);

	// OleVerb Impl
	virtual HRESULT __stdcall OleVerb( LONG iVerb,LPMSG lpmsg,IOleClientSite *pActiveSite,LONG lindex,HWND hwndParent,LPCRECT lprcPosRect);
	virtual HRESULT __stdcall OleVerb_Primary( LONG iVerb,LPMSG lpmsg,IOleClientSite *pActiveSite,LONG lindex,HWND hwndParent,LPCRECT lprcPosRect);
	virtual HRESULT __stdcall OleVerb_Open( LONG iVerb,LPMSG lpmsg,IOleClientSite *pActiveSite,LONG lindex,HWND hwndParent,LPCRECT lprcPosRect);
	virtual HRESULT __stdcall OleVerb_Show( LONG iVerb,LPMSG lpmsg,IOleClientSite *pActiveSite,LONG lindex,HWND hwndParent,LPCRECT lprcPosRect);
	virtual HRESULT __stdcall OleVerb_Hide( LONG iVerb,LPMSG lpmsg,IOleClientSite *pActiveSite,LONG lindex,HWND hwndParent,LPCRECT lprcPosRect);
	virtual HRESULT __stdcall OleVerb_InplaceActivate( LONG iVerb,LPMSG lpmsg,IOleClientSite *pActiveSite,LONG lindex,HWND hwndParent,LPCRECT lprcPosRect);
	virtual HRESULT __stdcall OleVerb_UIActivate( LONG iVerb,LPMSG lpmsg,IOleClientSite *pActiveSite,LONG lindex,HWND hwndParent,LPCRECT lprcPosRect);
	virtual HRESULT __stdcall OleVerb_Properties( LONG iVerb,LPMSG lpmsg,IOleClientSite *pActiveSite,LONG lindex,HWND hwndParent,LPCRECT lprcPosRect);

	//helpers
	BOOL isDirty()			{ return bDirty_; }
	void setDirty(BOOL d)	{ bDirty_ = d; }

	RECT*  getPosRect()		{ return &posRect_; }
	RECTL* getPosRectl()	{ return (RECTL*)&posRect_; }

	// drawing
	virtual HRESULT OnDraw( HDC hdcDraw, LPCRECTL lprcBounds, LPCRECTL lprcMFBounds);

	punk<IOleInPlaceSite>&		site() { return site_; }

	SIZEL					sizel;

protected:

	virtual void    createOleWindow( HWND hwndParent, LPCRECT lprcPosRect );
	virtual HWND    getOleWindow();

	virtual HRESULT inplaceActivate();
	virtual HRESULT inplaceDeactivate();

	virtual HRESULT uiActivate();
	virtual HRESULT uiDeactivate();

	virtual HRESULT showProperties();
	virtual void    sendOnDataChange();

	virtual void createInplaceMenu() {};
	virtual void removeInplaceMenu() {};

	virtual void setRects( const RECT& pos, const RECT& clip );

	
	// members
	punk<IOleInPlaceSite>		site_;
	punk<IOleClientSite>		clientSite_;
	punk<IOleInPlaceFrame>		frame_;
	punk<IOleInPlaceUIWindow>	uiWnd_;
	punk<IOleAdviseHolder>		adviseHolder_;
	punk<IDataAdviseHolder>		dataAdviseHolder_;

	std::wstring				appname_;
	std::wstring				docname_;
	mol::Rect				posRect_;
	HWND					hwndParent_;
	BOOL					bDirty_;
};

} // end namespace ole

///////////////////////////////////////////////////////////
// Ole Content object minimal impl for exe servers
///////////////////////////////////////////////////////////

template< class T, 
		  REFGUID I,
		  int clsctx = CLSCTX_INPROC_SERVER, 
		  REGCLS cls = REGCLS_MULTIPLEUSE 
         >

class ole_obj : 
	public com_registerobj<T,I,clsctx,cls>,
	public mol::ole::OleObjBase
{
public:

	ole_obj()
	{}

	virtual ~ole_obj()
	{

	}

	virtual void dispose()  
	{
		HWND hwnd = this->getOleWindow();
		if ( hwnd && ::IsWindow(hwnd) )
			this->Close(OLECLOSE_NOSAVE);
	}

	// static metadata
	static int getRegFlags()
	{
		return INSERTABLE|PROGRAMMABLE|APARTMENT;
	}

	static HRESULT getMiscStatus( DWORD dwAspect,DWORD *pdwStatus)	
	{																
		*pdwStatus = OLEMISC_RECOMPOSEONRESIZE|
    				 OLEMISC_CANTLINKINSIDE|
					 OLEMISC_SETCLIENTSITEFIRST;
		return S_OK;												
	}

	static OLEVERB* verbs()							
	{												
		static OLEVERB* ov = init_verbs();			
		return ov;									
	}												
												
	static OLEVERB* init_verbs()					
	{												
		static OLEVERB ov[] = {			
			{ OLEIVERB_HIDE    , L"HIDE",	 0, 0 },
			{ OLEIVERB_OPEN    , L"OPEN",	 0, 0 },
			{ OLEIVERB_SHOW    , L"SHOW",	 0, 0 },		
			{ OLEIVERB_PRIMARY , L"PRIMARY", 0, 0 },
			{ 0,0,0,0 }
		};
		return ov;
	}

	// IOleObject overrides
	virtual HRESULT __stdcall GetMiscStatus( DWORD dwAspect,DWORD *pdwStatus)
	{
		return T::getMiscStatus( dwAspect,pdwStatus);
	}

	virtual HRESULT __stdcall GetUserClassID( CLSID *pClsid) 
	{
		T* t = (T*)this;
		*pClsid = t->getCoClassID();
		return S_OK;
	}

	//registry
	static void registerObject()				
	{					
		DWORD miscStatus = 0;
		T::getMiscStatus(0,&miscStatus);
		RegisterObject( T::getCoClassID(),
						miscStatus,
						T::verbs(),
						T::getRegFlags(),				
						T::getClsctx(),			
						T::getRegCls() );			
	}

	static void unRegisterObject()				
	{									
		DWORD miscStatus = 0;
		T::getMiscStatus(0,&miscStatus);
		UnRegisterObject( T::getCoClassID(),
						miscStatus,
						T::verbs(),
						T::getRegFlags(),				
						T::getClsctx(),			
						T::getRegCls() );			
	}

	// get ole window - assumes derived class is a mol::Wnd
	virtual HWND getOleWindow()
	{
		T* t = (T*)this;
		return *t;
	}
};

/////////////////////////////////////////////////////////////////////
// Basic OleControl Impl
/////////////////////////////////////////////////////////////////////

namespace ole {

class OleCtrlBase : 
	public OleObjBase,
	public IOleControl,
	public IOleInPlaceObjectWindowless,
	public ISpecifyPropertyPages 
{
public:

	OleCtrlBase();
	virtual ~OleCtrlBase();

	// IOleWIndow
    virtual HRESULT __stdcall GetWindow( HWND *phwnd);
    virtual HRESULT __stdcall ContextSensitiveHelp( BOOL fEnterMode);

	// IOleInPlaceObject
    virtual HRESULT __stdcall InPlaceDeactivate( void);
    virtual HRESULT __stdcall UIDeactivate( void);
    virtual HRESULT __stdcall SetObjectRects( LPCRECT lprcPosRect,LPCRECT lprcClipRect);
    virtual HRESULT __stdcall ReactivateAndUndo( void);

	// IOleInPlaceObjectWindowless
	virtual HRESULT __stdcall OnWindowMessage( UINT msg,WPARAM wParam,LPARAM lParam, LRESULT *plResult);
    virtual HRESULT __stdcall GetDropTarget( IDropTarget **ppDropTarget);

    // IOleControl
    virtual HRESULT __stdcall GetControlInfo( CONTROLINFO *pCI);    
    virtual HRESULT __stdcall OnMnemonic( MSG *pMsg);
    virtual HRESULT __stdcall OnAmbientPropertyChange( DISPID dispID);
    virtual HRESULT __stdcall FreezeEvents( BOOL bFreeze);

	// ISpecifyPropertyPages
	virtual HRESULT __stdcall GetPages( CAUUID *pPages);

	// events frozen?
	virtual bool frozen();

	virtual void createInplaceMenu();
	virtual void removeInplaceMenu();

	virtual void createInplaceTools();
	virtual void removeInplaceTools();

	void addEditMenu(const std::wstring& title, HMENU menu);
	void addObjectMenu(const std::wstring& title, HMENU menu);
	void addHelpMenu(const std::wstring& title, HMENU menu);

protected:
	virtual void refreshInplaceMenu();
	virtual bool renegotiateInplaceTools();

	virtual HRESULT createPropFrame(const std::wstring& title, int x=0, int y=0);

	virtual LRESULT wndlessProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam, bool& handled) =0;
	virtual HWND    getWindowlessWindow();
	virtual void    initAmbientProperties( IDispatch* disp) {}
	virtual void    createOleWindow( HWND hwndParent, LPCRECT lprcPosRect, LPCRECT lprcClip ) {};

	virtual HRESULT inplaceActivate();
	virtual HRESULT uiActivate();
	virtual HRESULT inplaceDeactivate();
	virtual HRESULT uiDeactivate();

	virtual void freeze(bool f);
	virtual void initPropPages();

	//members
	bool					windowed_;
	bool					frozen_;
	bool					uiActive_;
	std::set<const CLSID*>  clsids_proppages_;

	punk<IOleInPlaceSiteWindowless> siteWindowless_;

	// IOleInPlaceActiveObject
	class OleInPlaceActiveObjBase : 
		public IOleInPlaceActiveObject,
		public interfaces< OleInPlaceActiveObjBase,
					implements< IOleInPlaceActiveObject,
								interface_ex<IOleInPlaceActiveObject,IOleWindow> > >
	{
	public:	

		virtual ~OleInPlaceActiveObjBase() {

		}
		virtual void dispose() {}

		virtual HRESULT __stdcall GetWindow( HWND *phwnd);
		virtual HRESULT __stdcall ContextSensitiveHelp( BOOL fEnterMode);
		virtual HRESULT __stdcall TranslateAccelerator( LPMSG lpmsg);
		virtual HRESULT __stdcall OnFrameWindowActivate( BOOL fActivate);
		virtual HRESULT __stdcall OnDocWindowActivate( BOOL fActivate);
		virtual HRESULT __stdcall ResizeBorder( LPCRECT prcBorder,IOleInPlaceUIWindow *pUIWindow,BOOL fFrameWindow);
		virtual HRESULT __stdcall EnableModeless( BOOL fEnable);

	protected:
		OleCtrlBase* ctrl_;
	};

	class OleInPlaceActiveObj : public com_obj<OleInPlaceActiveObjBase>
	{
	public:
		OleInPlaceActiveObj(OleCtrlBase* ctrl) 
		{ 
			ctrl_ = ctrl; 
		}

		virtual ~OleInPlaceActiveObj() {

		}
	};

	punk<OleInPlaceActiveObj> active_;

	mol::Menu									oleMenu_;
	HMENU										sharedMenu_;
	HOLEMENU									holemenu_;

	typedef std::pair<std::wstring,HMENU> namedMenu;
	std::vector<namedMenu> editMenus_;
	std::vector<namedMenu> objectMenus_;
	std::vector<namedMenu> helpMenus_;
};

} // end namespace ole

///////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////
// IPropertyNotifySink ConnectionPointImpl 
///////////////////////////////////////////////////////////

template<class T>
class PropertyNotifySinkCP : public mol::ole::ConnectionPointBase
{
public:
	PropertyNotifySinkCP()
	{
		T* t = (T*)this;
		((ConnectionPointContainer<T>*)t)->add(IID_IPropertyNotifySink,&inner_connection_point_);
	}

	virtual ~PropertyNotifySinkCP()
	{
	}

	virtual HRESULT getConnectionInterface( IID *pIID) 
	{
		*pIID = IID_IPropertyNotifySink;
		return S_OK;
	}
	
	virtual HRESULT getConnectionPointContainer( IConnectionPointContainer **ppCPC)		
	{							
		T* t = (T*)this;
		return t->QueryInterfaceImpl(IID_IConnectionPointContainer, (void**)ppCPC);
	}	

	virtual HRESULT advise( IUnknown *pUnkSink, DWORD *pdwCookie) 
	{
		IPropertyNotifySink* i = 0;
		if ( S_OK != pUnkSink->QueryInterface( IID_IPropertyNotifySink, (void**)&i ))
			return CONNECT_E_CANNOTCONNECT;
		*pdwCookie = cookies_.get();
		sinks_.insert( std::make_pair(*pdwCookie,i) );
		return S_OK;
	}

	virtual HRESULT unadvise( DWORD dwCookie) 
	{
		if ( sinks_.count(dwCookie) > 0 )
		{
			sinks_[dwCookie]->Release();
			sinks_.erase(dwCookie);
			cookies_.release(dwCookie);
		}
		return S_OK;
	}

	void  OnChanged( DISPID dispID)
	{
		for ( std::map<DWORD,IPropertyNotifySink*>::iterator it = sinks_.begin(); it != sinks_.end(); it++)
		{
			(*it).second->OnChanged(dispID);
		}
	}

    HRESULT OnRequestEdit( DISPID dispID)
	{
		for ( std::map<DWORD,IPropertyNotifySink*>::iterator it = sinks_.begin(); it != sinks_.end(); it++)
		{
			if ( (*it).second->OnRequestEdit(dispID) != S_OK )
				return S_FALSE ;
		}
		return S_OK;
	}

protected:
	std::map<DWORD,IPropertyNotifySink*> sinks_;
	mol::ole::Cookies cookies_;
};

template<class T>
class com_property_notifications : public PropertyNotifySinkCP<T>
{};

///////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////
// Ole Control with optional windowless support
///////////////////////////////////////////////////////////

template< class T, 
		  REFGUID I,
		  bool WINDOWLESS = false,
		  int clsctx      = CLSCTX_INPROC_SERVER, 
		  REGCLS cls      = REGCLS_MULTIPLEUSE 
         >

class ole_ctrl : 
	public com_registerobj<T, I, clsctx, cls>,
	public mol::ole::OleCtrlBase
{
public:

	// construct windowed/windowless Control
	ole_ctrl()
	{
		windowed_ = WINDOWLESS ? false : true;
	}

	virtual ~ole_ctrl()
	{
	}

	virtual void dispose()  
	{
		HWND hwnd = this->getOleWindow();
		if ( hwnd && ::IsWindow(hwnd) )
			this->Close(OLECLOSE_NOSAVE);
	}

	// static metadata 
	static int getRegFlags()
	{
		return INSERTABLE|PROGRAMMABLE|CONTROL|APARTMENT;
	}

	static HRESULT getMiscStatus( DWORD dwAspect,DWORD *pdwStatus)	
	{																
		*pdwStatus = OLEMISC_RECOMPOSEONRESIZE|
    				 OLEMISC_CANTLINKINSIDE|
					 OLEMISC_SETCLIENTSITEFIRST|
					 OLEMISC_INSIDEOUT|
					 OLEMISC_ACTIVATEWHENVISIBLE|
					 OLEMISC_ALWAYSRUN;									
		return S_OK;												
	}

	static OLEVERB* verbs()							
	{												
		static OLEVERB* ov = init_verbs();			
		return ov;									
	}												
												
	static OLEVERB* init_verbs()					
	{												
		static OLEVERB ov[] = {			
			{ OLEIVERB_INPLACEACTIVATE , (LPOLESTR)L"IPA",		 0, 0 },
			{ OLEIVERB_UIACTIVATE,		 (LPOLESTR)L"UI Activate", 0, 0 },
			{ OLEIVERB_HIDE ,			 (LPOLESTR)L"HIDE",		 0, 0 },
			{ OLEIVERB_OPEN ,			 (LPOLESTR)L"OPEN",		 0, 0 },
			{ OLEIVERB_SHOW  ,			 (LPOLESTR)L"SHOW",		 0, 0 },
			{ OLEIVERB_PRIMARY ,		 (LPOLESTR)L"PRIMARY",	 0, 0 },
			{ OLEIVERB_PROPERTIES,		 (LPOLESTR)L"PROPERTIES",  0, 0 },
			{ 0,0,0,0 }
		};
		return ov;
	}

	// IOleObject
	virtual HRESULT __stdcall GetUserClassID( CLSID *pClsid) 
	{
		T* t = (T*)this;
		*pClsid = t->getCoClassID();
		return S_OK;
	}

	virtual HRESULT __stdcall GetMiscStatus( DWORD dwAspect,DWORD *pdwStatus)
	{
		return T::getMiscStatus( dwAspect,pdwStatus);
	}


	HRESULT __stdcall InitFromData( IDataObject *pDataObject,BOOL fCreation,DWORD dwReserved)
	{
		return E_NOTIMPL;
	}

	HRESULT __stdcall GetClipboardData( DWORD dwReserved,IDataObject **ppDataObject)
	{
		T* t = (T*)this;
		*ppDataObject  = NULL;
		mol::Stream stream;
		stream.create();
		punk<IPersistStream> ps((IOleControl*)t);
		if ( ps )
		{
			if ( S_OK == ps->Save(stream,FALSE) )
			{
				stream.reset();
				com_instance<T>* t2 = new com_instance<T>();
				punk<IPersistStream> ps2((IOleControl*)t2);
				if ( ps2 )
				{
					if ( S_OK == ps2->Load(stream) )
					{
						//if ( S_OK == ps2.queryInterface(IID_IDataObject,(void**)ppDataObject) )
						if ( S_OK == ps2.queryInterface(ppDataObject) )
							return S_OK;
					}
				}			
			}
		}
		return E_FAIL ;
	}

	// IOleControl
	virtual HRESULT __stdcall OnAmbientPropertyChange( DISPID dispID)
	{
		punk<IDispatch> disp;
		//if ( S_OK == clientSite_.queryInterface(IID_IDispatch,(void**)&disp) )
		if ( S_OK == clientSite_.queryInterface(&disp) )
		//if ( disp )
		{
			T* t = (T*)this;
			t->initAmbientProperties(disp);
			t->OnLayout(0,0,0);
		}
		return S_OK;		
	}

	// create ole window if not windowless
	virtual void createOleWindow( HWND hwndParent, LPCRECT lprcPosRect, LPCRECT lprcClip )
	{
		if ( !windowed_ )
			return;

		setRects( *lprcPosRect, *lprcClip);

		RECT r = { posRect_.left,
			       posRect_.top,
				   posRect_.right-posRect_.left,
				   posRect_.bottom-posRect_.top };

		T* t = (T*)this;
		t->create((HMENU)1,r,hwndParent);

		OnAmbientPropertyChange(-1);
	}

	// get ole window - assumes derived class is a mol::Wnd
	virtual HWND getOleWindow()
	{
		T* t = (T*)this;
		return *t;
	}

	// show property pages, if any
	virtual HRESULT showProperties()
	{
		T* t = (T*)this;
		punk<ISpecifyPropertyPages> propPages(t);
		if ( propPages )
		{
			if ( clientSite_ )
			{
				punk<IOleControlSite> cs(clientSite_);
				if ( cs )
				{
					if ( S_OK == cs->ShowPropertyFrame() )
						return S_OK;
				}
			}
			t->createPropFrame(_T("Properties"));
		}
		return S_OK;
	}

	// one-time intitalize prop-pages metadata 
	// assumes T is a mol::ComObject

	virtual void initPropPages()
	{
		if ( clsids_proppages_.size() > 0 )
			return;

		T* t = (T*)this;
		/*std::vector<mol::ole::IProperty*>& props = mol::ole::properties<T>().get();
		//T::PROPERTIES& prop = t->T::properties();
		for ( unsigned int i = 0; i < props.size(); i++ )
		{
			if ( props[i]->prop_guid() != 0 )
				clsids_proppages_.insert( props[i]->prop_guid() );
		}
		*/
	}

	// actual wndProc uses mol::MsgMap
	// if your T does not have messagemap,
	// overide wndlessProc,let your
	// wndProc call wndlessProc, and
	// do all processing in wndlessProc

	virtual LRESULT wndlessProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam, bool& handled)
	{
		T* t = (T*)this;
		mol::MsgMap<T,T::BaseWindowType>& msgmap = msgMap<T>();
		return msgmap.callIf( t, message, wParam, lParam, handled);
	}

	//registry
	static void registerObject()				
	{					
		DWORD miscStatus = 0;
		T::getMiscStatus(0,&miscStatus);
		com_registerobj<T, I, clsctx, cls>::RegisterObject( T::getCoClassID(),
						miscStatus,
						T::verbs(),
						T::getRegFlags(),				
						T::getClsctx(),			
						T::getRegCls() );			
	}

	static void unRegisterObject()				
	{									
		DWORD miscStatus = 0;
		T::getMiscStatus(0,&miscStatus);
		com_registerobj<T, I, clsctx, cls>::UnRegisterObject( T::getCoClassID(),
						miscStatus,
						T::verbs(),
						T::getRegFlags(),				
						T::getClsctx(),			
						T::getRegCls() );			
	}


};


/////////////////////////////////////////////////////////////////////
// ViewObject support
/////////////////////////////////////////////////////////////////////

namespace ole {

class ViewObj2Base : public IViewObject2
{
public:

	//IViewObject2
	virtual HRESULT __stdcall Draw( DWORD dwDrawAspect, LONG lindex, void *pvAspect,DVTARGETDEVICE *ptd, HDC hdcTargetDev, HDC hdcDraw,LPCRECTL lprcBounds,LPCRECTL lprcWBounds, BOOL (__stdcall *)(ULONG_PTR), ULONG_PTR dwContinue);
    virtual HRESULT __stdcall GetColorSet( DWORD dwDrawAspect, LONG lindex, void *pvAspect, DVTARGETDEVICE *ptd, HDC hicTargetDev, LOGPALETTE **ppColorSet);      
    virtual HRESULT __stdcall Freeze( DWORD dwDrawAspect, LONG lindex,void *pvAspect,DWORD *pdwFreeze);
    virtual HRESULT __stdcall Unfreeze( DWORD dwFreeze);
    virtual HRESULT __stdcall SetAdvise( DWORD aspects, DWORD advf, IAdviseSink *pAdvSink);
    virtual HRESULT __stdcall GetAdvise( DWORD *pAspects, DWORD *pAdvf,IAdviseSink **ppAdvSink);
	virtual HRESULT __stdcall GetExtent( DWORD dwAspect, LONG lindex, DVTARGETDEVICE *ptd,  LPSIZEL lpsizel );

	//helper
	void sendOnViewChange();

protected:

	DWORD adviseAspect_;
	DWORD adviseAdvf_;
	punk<IAdviseSink> adviseSink_;
};

} // end namespace ole

/////////////////////////////////////////////////////////////////////

template<class T>
class ViewObj2 : public mol::ole::ViewObj2Base
{
public:

	HRESULT __stdcall GetExtent( DWORD dwAspect, LONG lindex, DVTARGETDEVICE *ptd,  LPSIZEL lpsizel )
	{
		T* t = (T*)this;
		return t->OleObjBase::GetExtent( dwAspect, lpsizel );
	}

	virtual HRESULT __stdcall Draw( DWORD dwDrawAspect, LONG lindex, void *pvAspect,DVTARGETDEVICE *ptd, HDC hdcTargetDev, HDC hdcDraw,LPCRECTL lprcBounds,LPCRECTL lprcWBounds, BOOL (__stdcall *)(ULONG_PTR), ULONG_PTR dwContinue)
	{
		T* t = (T*)this;
		if ( lprcBounds )
			return t->T::OnDraw( hdcDraw,lprcBounds,lprcWBounds);
		else
			if ( lprcWBounds )
				return t->T::OnDraw( hdcDraw,t->getPosRectl(),lprcWBounds);
			else
				return t->T::OnDraw( hdcDraw,t->getPosRectl(),t->getPosRectl());
	}
};


/////////////////////////////////////////////////////////////////////
// Ole capable Window
/////////////////////////////////////////////////////////////////////

template<class Class, class Win, int Style, int ExStyle>
class OleWnd : public mol::Frame<Class,Win,Style,ExStyle> 
{
public:

	typedef OleWnd<Class,Win,Style,ExStyle> OleWndType;

	virtual LRESULT wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch ( message )
		{
			case WM_PAINT :
			{
				mol::PaintDC dc(*this);
				RECT r;
				this->getClientRect(r);
				Class* c = (Class*)this; 
				c->OnDraw( (HDC)dc,(LPRECTL)&r,(LPRECTL)&r);
				return 0;
			}
		}
		return mol::Frame<Class,Win,Style,ExStyle>::wndProc(hwnd,message,wParam,lParam);
	}
};

/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////
// Ax Control shortcut
/////////////////////////////////////////////////////////////////////

template<class T, REFGUID G, bool WINDOWLESS, class Win, int Style, int ExStyle >
class ax_ctrl :
	public OleWnd< T, Win, Style, ExStyle >,
	public ole_ctrl< T, G, WINDOWLESS >,
	public ViewObj2<T>,
	public PersistStream<T>,
	public PersistStorage<T>,
	public PersistPropertybag<T>,
	public com_eventsrc<T>,
	public com_property_notifications<T>,
	public RunnableObj // dummy
	//public mol::PropertyNotifySinkConnectionPoint<T>,
	//public mol::ProvideClassInfo<T >,  //considered opt

{
};

/////////////////////////////////////////////////////////////////////


} // end namespace mol


#endif