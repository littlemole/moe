

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Wed Jun 20 21:19:07 2012
 */
/* Compiler settings for HtmlEvents.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __HtmlEvents_h_h__
#define __HtmlEvents_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IWebBrowserEvents_FWD_DEFINED__
#define __IWebBrowserEvents_FWD_DEFINED__
typedef interface IWebBrowserEvents IWebBrowserEvents;
#endif 	/* __IWebBrowserEvents_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __MOL_HtmlEventsLibrary_LIBRARY_DEFINED__
#define __MOL_HtmlEventsLibrary_LIBRARY_DEFINED__

/* library MOL_HtmlEventsLibrary */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_MOL_HtmlEventsLibrary;

#ifndef __IWebBrowserEvents_INTERFACE_DEFINED__
#define __IWebBrowserEvents_INTERFACE_DEFINED__

/* interface IWebBrowserEvents */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IWebBrowserEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F010AA89-5CF5-4bce-BABE-5ADAE3D300EB")
    IWebBrowserEvents : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StatusTextChange( 
            /* [in] */ BSTR Text) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ProgressChange( 
            /* [in] */ long Progress,
            /* [in] */ long ProgressMax) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CommandStateChange( 
            /* [in] */ long Command,
            /* [in] */ VARIANT_BOOL Enable) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DownloadBegin( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DownloadComplete( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TitleChange( 
            /* [in] */ BSTR Text) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PropertyChange( 
            /* [in] */ BSTR szProperty) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BeforeNavigate2( 
            /* [in] */ IDispatch *pDisp,
            /* [in] */ VARIANT *URL,
            /* [in] */ VARIANT *Flags,
            /* [in] */ VARIANT *TargetFrameName,
            /* [in] */ VARIANT *PostData,
            /* [in] */ VARIANT *Headers,
            /* [out][in] */ VARIANT_BOOL *Cancel) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE NewWindow2( 
            /* [out][in] */ IDispatch **ppDisp,
            /* [out][in] */ VARIANT_BOOL *Cancel) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE NavigateComplete2( 
            /* [in] */ IDispatch *pDisp,
            /* [in] */ VARIANT *URL) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DocumentComplete( 
            /* [in] */ IDispatch *pDisp,
            /* [in] */ VARIANT *URL) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnQuit( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnVisible( 
            /* [in] */ VARIANT_BOOL Visible) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnToolBar( 
            /* [in] */ VARIANT_BOOL ToolBar) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnMenuBar( 
            /* [in] */ VARIANT_BOOL MenuBar) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnStatusBar( 
            /* [in] */ VARIANT_BOOL StatusBar) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnFullScreen( 
            /* [in] */ VARIANT_BOOL FullScreen) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnTheaterMode( 
            /* [in] */ VARIANT_BOOL TheaterMode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WindowSetResizable( 
            /* [in] */ VARIANT_BOOL Resizable) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WindowSetLeft( 
            /* [in] */ long Left) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WindowSetTop( 
            /* [in] */ long Top) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WindowSetWidth( 
            /* [in] */ long Width) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WindowSetHeight( 
            /* [in] */ long Height) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WindowClosing( 
            /* [in] */ VARIANT_BOOL IsChildWindow,
            /* [out][in] */ VARIANT_BOOL *Cancel) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ClientToHostWindow( 
            /* [out][in] */ long *CX,
            /* [out][in] */ long *CY) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSecureLockIcon( 
            /* [in] */ long SecureLockIcon) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FileDownload( 
            /* [out][in] */ VARIANT_BOOL *Cancel) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE NavigateError( 
            /* [in] */ IDispatch *pDisp,
            /* [in] */ VARIANT *URL,
            /* [in] */ VARIANT *Frame,
            /* [in] */ VARIANT *StatusCode,
            /* [out][in] */ VARIANT_BOOL *Cancel) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PrintTemplateInstantiation( 
            /* [in] */ IDispatch *pDisp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PrintTemplateTeardown( 
            /* [in] */ IDispatch *pDisp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UpdatePageStatus( 
            /* [in] */ IDispatch *pDisp,
            /* [in] */ VARIANT *nPage,
            /* [in] */ VARIANT *fDone) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PrivacyImpactedStateChange( 
            /* [in] */ VARIANT_BOOL bImpacted) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWebBrowserEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWebBrowserEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWebBrowserEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWebBrowserEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IWebBrowserEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IWebBrowserEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IWebBrowserEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IWebBrowserEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StatusTextChange )( 
            IWebBrowserEvents * This,
            /* [in] */ BSTR Text);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ProgressChange )( 
            IWebBrowserEvents * This,
            /* [in] */ long Progress,
            /* [in] */ long ProgressMax);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CommandStateChange )( 
            IWebBrowserEvents * This,
            /* [in] */ long Command,
            /* [in] */ VARIANT_BOOL Enable);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DownloadBegin )( 
            IWebBrowserEvents * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DownloadComplete )( 
            IWebBrowserEvents * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TitleChange )( 
            IWebBrowserEvents * This,
            /* [in] */ BSTR Text);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PropertyChange )( 
            IWebBrowserEvents * This,
            /* [in] */ BSTR szProperty);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BeforeNavigate2 )( 
            IWebBrowserEvents * This,
            /* [in] */ IDispatch *pDisp,
            /* [in] */ VARIANT *URL,
            /* [in] */ VARIANT *Flags,
            /* [in] */ VARIANT *TargetFrameName,
            /* [in] */ VARIANT *PostData,
            /* [in] */ VARIANT *Headers,
            /* [out][in] */ VARIANT_BOOL *Cancel);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *NewWindow2 )( 
            IWebBrowserEvents * This,
            /* [out][in] */ IDispatch **ppDisp,
            /* [out][in] */ VARIANT_BOOL *Cancel);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *NavigateComplete2 )( 
            IWebBrowserEvents * This,
            /* [in] */ IDispatch *pDisp,
            /* [in] */ VARIANT *URL);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DocumentComplete )( 
            IWebBrowserEvents * This,
            /* [in] */ IDispatch *pDisp,
            /* [in] */ VARIANT *URL);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnQuit )( 
            IWebBrowserEvents * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnVisible )( 
            IWebBrowserEvents * This,
            /* [in] */ VARIANT_BOOL Visible);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnToolBar )( 
            IWebBrowserEvents * This,
            /* [in] */ VARIANT_BOOL ToolBar);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnMenuBar )( 
            IWebBrowserEvents * This,
            /* [in] */ VARIANT_BOOL MenuBar);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnStatusBar )( 
            IWebBrowserEvents * This,
            /* [in] */ VARIANT_BOOL StatusBar);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnFullScreen )( 
            IWebBrowserEvents * This,
            /* [in] */ VARIANT_BOOL FullScreen);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnTheaterMode )( 
            IWebBrowserEvents * This,
            /* [in] */ VARIANT_BOOL TheaterMode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WindowSetResizable )( 
            IWebBrowserEvents * This,
            /* [in] */ VARIANT_BOOL Resizable);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WindowSetLeft )( 
            IWebBrowserEvents * This,
            /* [in] */ long Left);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WindowSetTop )( 
            IWebBrowserEvents * This,
            /* [in] */ long Top);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WindowSetWidth )( 
            IWebBrowserEvents * This,
            /* [in] */ long Width);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WindowSetHeight )( 
            IWebBrowserEvents * This,
            /* [in] */ long Height);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WindowClosing )( 
            IWebBrowserEvents * This,
            /* [in] */ VARIANT_BOOL IsChildWindow,
            /* [out][in] */ VARIANT_BOOL *Cancel);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClientToHostWindow )( 
            IWebBrowserEvents * This,
            /* [out][in] */ long *CX,
            /* [out][in] */ long *CY);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSecureLockIcon )( 
            IWebBrowserEvents * This,
            /* [in] */ long SecureLockIcon);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FileDownload )( 
            IWebBrowserEvents * This,
            /* [out][in] */ VARIANT_BOOL *Cancel);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *NavigateError )( 
            IWebBrowserEvents * This,
            /* [in] */ IDispatch *pDisp,
            /* [in] */ VARIANT *URL,
            /* [in] */ VARIANT *Frame,
            /* [in] */ VARIANT *StatusCode,
            /* [out][in] */ VARIANT_BOOL *Cancel);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PrintTemplateInstantiation )( 
            IWebBrowserEvents * This,
            /* [in] */ IDispatch *pDisp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PrintTemplateTeardown )( 
            IWebBrowserEvents * This,
            /* [in] */ IDispatch *pDisp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdatePageStatus )( 
            IWebBrowserEvents * This,
            /* [in] */ IDispatch *pDisp,
            /* [in] */ VARIANT *nPage,
            /* [in] */ VARIANT *fDone);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PrivacyImpactedStateChange )( 
            IWebBrowserEvents * This,
            /* [in] */ VARIANT_BOOL bImpacted);
        
        END_INTERFACE
    } IWebBrowserEventsVtbl;

    interface IWebBrowserEvents
    {
        CONST_VTBL struct IWebBrowserEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWebBrowserEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWebBrowserEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWebBrowserEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWebBrowserEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IWebBrowserEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IWebBrowserEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IWebBrowserEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IWebBrowserEvents_StatusTextChange(This,Text)	\
    ( (This)->lpVtbl -> StatusTextChange(This,Text) ) 

#define IWebBrowserEvents_ProgressChange(This,Progress,ProgressMax)	\
    ( (This)->lpVtbl -> ProgressChange(This,Progress,ProgressMax) ) 

#define IWebBrowserEvents_CommandStateChange(This,Command,Enable)	\
    ( (This)->lpVtbl -> CommandStateChange(This,Command,Enable) ) 

#define IWebBrowserEvents_DownloadBegin(This)	\
    ( (This)->lpVtbl -> DownloadBegin(This) ) 

#define IWebBrowserEvents_DownloadComplete(This)	\
    ( (This)->lpVtbl -> DownloadComplete(This) ) 

#define IWebBrowserEvents_TitleChange(This,Text)	\
    ( (This)->lpVtbl -> TitleChange(This,Text) ) 

#define IWebBrowserEvents_PropertyChange(This,szProperty)	\
    ( (This)->lpVtbl -> PropertyChange(This,szProperty) ) 

#define IWebBrowserEvents_BeforeNavigate2(This,pDisp,URL,Flags,TargetFrameName,PostData,Headers,Cancel)	\
    ( (This)->lpVtbl -> BeforeNavigate2(This,pDisp,URL,Flags,TargetFrameName,PostData,Headers,Cancel) ) 

#define IWebBrowserEvents_NewWindow2(This,ppDisp,Cancel)	\
    ( (This)->lpVtbl -> NewWindow2(This,ppDisp,Cancel) ) 

#define IWebBrowserEvents_NavigateComplete2(This,pDisp,URL)	\
    ( (This)->lpVtbl -> NavigateComplete2(This,pDisp,URL) ) 

#define IWebBrowserEvents_DocumentComplete(This,pDisp,URL)	\
    ( (This)->lpVtbl -> DocumentComplete(This,pDisp,URL) ) 

#define IWebBrowserEvents_OnQuit(This)	\
    ( (This)->lpVtbl -> OnQuit(This) ) 

#define IWebBrowserEvents_OnVisible(This,Visible)	\
    ( (This)->lpVtbl -> OnVisible(This,Visible) ) 

#define IWebBrowserEvents_OnToolBar(This,ToolBar)	\
    ( (This)->lpVtbl -> OnToolBar(This,ToolBar) ) 

#define IWebBrowserEvents_OnMenuBar(This,MenuBar)	\
    ( (This)->lpVtbl -> OnMenuBar(This,MenuBar) ) 

#define IWebBrowserEvents_OnStatusBar(This,StatusBar)	\
    ( (This)->lpVtbl -> OnStatusBar(This,StatusBar) ) 

#define IWebBrowserEvents_OnFullScreen(This,FullScreen)	\
    ( (This)->lpVtbl -> OnFullScreen(This,FullScreen) ) 

#define IWebBrowserEvents_OnTheaterMode(This,TheaterMode)	\
    ( (This)->lpVtbl -> OnTheaterMode(This,TheaterMode) ) 

#define IWebBrowserEvents_WindowSetResizable(This,Resizable)	\
    ( (This)->lpVtbl -> WindowSetResizable(This,Resizable) ) 

#define IWebBrowserEvents_WindowSetLeft(This,Left)	\
    ( (This)->lpVtbl -> WindowSetLeft(This,Left) ) 

#define IWebBrowserEvents_WindowSetTop(This,Top)	\
    ( (This)->lpVtbl -> WindowSetTop(This,Top) ) 

#define IWebBrowserEvents_WindowSetWidth(This,Width)	\
    ( (This)->lpVtbl -> WindowSetWidth(This,Width) ) 

#define IWebBrowserEvents_WindowSetHeight(This,Height)	\
    ( (This)->lpVtbl -> WindowSetHeight(This,Height) ) 

#define IWebBrowserEvents_WindowClosing(This,IsChildWindow,Cancel)	\
    ( (This)->lpVtbl -> WindowClosing(This,IsChildWindow,Cancel) ) 

#define IWebBrowserEvents_ClientToHostWindow(This,CX,CY)	\
    ( (This)->lpVtbl -> ClientToHostWindow(This,CX,CY) ) 

#define IWebBrowserEvents_SetSecureLockIcon(This,SecureLockIcon)	\
    ( (This)->lpVtbl -> SetSecureLockIcon(This,SecureLockIcon) ) 

#define IWebBrowserEvents_FileDownload(This,Cancel)	\
    ( (This)->lpVtbl -> FileDownload(This,Cancel) ) 

#define IWebBrowserEvents_NavigateError(This,pDisp,URL,Frame,StatusCode,Cancel)	\
    ( (This)->lpVtbl -> NavigateError(This,pDisp,URL,Frame,StatusCode,Cancel) ) 

#define IWebBrowserEvents_PrintTemplateInstantiation(This,pDisp)	\
    ( (This)->lpVtbl -> PrintTemplateInstantiation(This,pDisp) ) 

#define IWebBrowserEvents_PrintTemplateTeardown(This,pDisp)	\
    ( (This)->lpVtbl -> PrintTemplateTeardown(This,pDisp) ) 

#define IWebBrowserEvents_UpdatePageStatus(This,pDisp,nPage,fDone)	\
    ( (This)->lpVtbl -> UpdatePageStatus(This,pDisp,nPage,fDone) ) 

#define IWebBrowserEvents_PrivacyImpactedStateChange(This,bImpacted)	\
    ( (This)->lpVtbl -> PrivacyImpactedStateChange(This,bImpacted) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWebBrowserEvents_INTERFACE_DEFINED__ */

#endif /* __MOL_HtmlEventsLibrary_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


