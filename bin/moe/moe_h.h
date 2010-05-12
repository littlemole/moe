

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Wed May 12 18:27:10 2010
 */
/* Compiler settings for .\src\moe.idl:
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


#ifndef __moe_h_h__
#define __moe_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IWebBrowserEvents_FWD_DEFINED__
#define __IWebBrowserEvents_FWD_DEFINED__
typedef interface IWebBrowserEvents IWebBrowserEvents;
#endif 	/* __IWebBrowserEvents_FWD_DEFINED__ */


#ifndef __IXmoe_FWD_DEFINED__
#define __IXmoe_FWD_DEFINED__
typedef interface IXmoe IXmoe;
#endif 	/* __IXmoe_FWD_DEFINED__ */


#ifndef __IDoc_FWD_DEFINED__
#define __IDoc_FWD_DEFINED__
typedef interface IDoc IDoc;
#endif 	/* __IDoc_FWD_DEFINED__ */


#ifndef __IDocs_FWD_DEFINED__
#define __IDocs_FWD_DEFINED__
typedef interface IDocs IDocs;
#endif 	/* __IDocs_FWD_DEFINED__ */


#ifndef __IMoeFrame_FWD_DEFINED__
#define __IMoeFrame_FWD_DEFINED__
typedef interface IMoeFrame IMoeFrame;
#endif 	/* __IMoeFrame_FWD_DEFINED__ */


#ifndef __IExternalMoe_FWD_DEFINED__
#define __IExternalMoe_FWD_DEFINED__
typedef interface IExternalMoe IExternalMoe;
#endif 	/* __IExternalMoe_FWD_DEFINED__ */


#ifndef ___IXmoeEvents_FWD_DEFINED__
#define ___IXmoeEvents_FWD_DEFINED__
typedef interface _IXmoeEvents _IXmoeEvents;
#endif 	/* ___IXmoeEvents_FWD_DEFINED__ */


#ifndef __Xmoe_FWD_DEFINED__
#define __Xmoe_FWD_DEFINED__

#ifdef __cplusplus
typedef class Xmoe Xmoe;
#else
typedef struct Xmoe Xmoe;
#endif /* __cplusplus */

#endif 	/* __Xmoe_FWD_DEFINED__ */


#ifndef __Docs_FWD_DEFINED__
#define __Docs_FWD_DEFINED__

#ifdef __cplusplus
typedef class Docs Docs;
#else
typedef struct Docs Docs;
#endif /* __cplusplus */

#endif 	/* __Docs_FWD_DEFINED__ */


#ifndef __Doc_FWD_DEFINED__
#define __Doc_FWD_DEFINED__

#ifdef __cplusplus
typedef class Doc Doc;
#else
typedef struct Doc Doc;
#endif /* __cplusplus */

#endif 	/* __Doc_FWD_DEFINED__ */


/* header files for imported files */
#include "ocidl.h"
#include "HtmlEvents.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __Moe_LIBRARY_DEFINED__
#define __Moe_LIBRARY_DEFINED__

/* library Moe */
/* [helpstring][version][uuid] */ 






typedef 
enum XMOE_DOCTYPE
    {	XMOE_DOCTYPE_NULL	= 0,
	XMOE_DOCTYPE_DOC	= 1,
	XMOE_DOCTYPE_DIR	= 2,
	XMOE_DOCTYPE_PIC	= 3,
	XMOE_DOCTYPE_HEX	= 4,
	XMOE_DOCTYPE_HTML	= 5,
	XMOE_DOCTYPE_OLE	= 6
    } 	XMOE_DOCTYPE;

typedef 
enum XMOE_SEARCHFLAG
    {	XMOE_SEARCHFLAG_DOWN	= 0x1,
	XMOE_SEARCHFLAG_WHOLEWORD	= 0x2,
	XMOE_SEARCHFLAG_MATCHCASE	= 0x4,
	XMOE_SEARCHFLAG_FINDNEXT	= 0x8,
	XMOE_SEARCHFLAG_REPLACE	= 0x10,
	XMOE_SEARCHFLAG_REPLACEALL	= 0x20,
	XMOE_SEARCHFLAG_DIALOGTERM	= 0x40
    } 	XMOE_SEARCHFLAG;

typedef 
enum XMOE_FORMFLAG
    {	XMOE_FORMFLAG_NONE	= 0,
	XMOE_FORMFLAG_TITLE	= 1,
	XMOE_FORMFLAG_NOSCROLL	= 2,
	XMOE_FORMFLAG_DIALOG	= 4,
	XMOE_FORMFLAG_STANDALONE	= 8
    } 	XMOE_FORMFLAG;


EXTERN_C const IID LIBID_Moe;

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



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWebBrowserEvents_StatusTextChange_Proxy( 
    IWebBrowserEvents * This,
    /* [in] */ BSTR Text);


void __RPC_STUB IWebBrowserEvents_StatusTextChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWebBrowserEvents_ProgressChange_Proxy( 
    IWebBrowserEvents * This,
    /* [in] */ long Progress,
    /* [in] */ long ProgressMax);


void __RPC_STUB IWebBrowserEvents_ProgressChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWebBrowserEvents_CommandStateChange_Proxy( 
    IWebBrowserEvents * This,
    /* [in] */ long Command,
    /* [in] */ VARIANT_BOOL Enable);


void __RPC_STUB IWebBrowserEvents_CommandStateChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWebBrowserEvents_DownloadBegin_Proxy( 
    IWebBrowserEvents * This);


void __RPC_STUB IWebBrowserEvents_DownloadBegin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWebBrowserEvents_DownloadComplete_Proxy( 
    IWebBrowserEvents * This);


void __RPC_STUB IWebBrowserEvents_DownloadComplete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWebBrowserEvents_TitleChange_Proxy( 
    IWebBrowserEvents * This,
    /* [in] */ BSTR Text);


void __RPC_STUB IWebBrowserEvents_TitleChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWebBrowserEvents_PropertyChange_Proxy( 
    IWebBrowserEvents * This,
    /* [in] */ BSTR szProperty);


void __RPC_STUB IWebBrowserEvents_PropertyChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWebBrowserEvents_BeforeNavigate2_Proxy( 
    IWebBrowserEvents * This,
    /* [in] */ IDispatch *pDisp,
    /* [in] */ VARIANT *URL,
    /* [in] */ VARIANT *Flags,
    /* [in] */ VARIANT *TargetFrameName,
    /* [in] */ VARIANT *PostData,
    /* [in] */ VARIANT *Headers,
    /* [out][in] */ VARIANT_BOOL *Cancel);


void __RPC_STUB IWebBrowserEvents_BeforeNavigate2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWebBrowserEvents_NewWindow2_Proxy( 
    IWebBrowserEvents * This,
    /* [out][in] */ IDispatch **ppDisp,
    /* [out][in] */ VARIANT_BOOL *Cancel);


void __RPC_STUB IWebBrowserEvents_NewWindow2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWebBrowserEvents_NavigateComplete2_Proxy( 
    IWebBrowserEvents * This,
    /* [in] */ IDispatch *pDisp,
    /* [in] */ VARIANT *URL);


void __RPC_STUB IWebBrowserEvents_NavigateComplete2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWebBrowserEvents_DocumentComplete_Proxy( 
    IWebBrowserEvents * This,
    /* [in] */ IDispatch *pDisp,
    /* [in] */ VARIANT *URL);


void __RPC_STUB IWebBrowserEvents_DocumentComplete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWebBrowserEvents_OnQuit_Proxy( 
    IWebBrowserEvents * This);


void __RPC_STUB IWebBrowserEvents_OnQuit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWebBrowserEvents_OnVisible_Proxy( 
    IWebBrowserEvents * This,
    /* [in] */ VARIANT_BOOL Visible);


void __RPC_STUB IWebBrowserEvents_OnVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWebBrowserEvents_OnToolBar_Proxy( 
    IWebBrowserEvents * This,
    /* [in] */ VARIANT_BOOL ToolBar);


void __RPC_STUB IWebBrowserEvents_OnToolBar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWebBrowserEvents_OnMenuBar_Proxy( 
    IWebBrowserEvents * This,
    /* [in] */ VARIANT_BOOL MenuBar);


void __RPC_STUB IWebBrowserEvents_OnMenuBar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWebBrowserEvents_OnStatusBar_Proxy( 
    IWebBrowserEvents * This,
    /* [in] */ VARIANT_BOOL StatusBar);


void __RPC_STUB IWebBrowserEvents_OnStatusBar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWebBrowserEvents_OnFullScreen_Proxy( 
    IWebBrowserEvents * This,
    /* [in] */ VARIANT_BOOL FullScreen);


void __RPC_STUB IWebBrowserEvents_OnFullScreen_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWebBrowserEvents_OnTheaterMode_Proxy( 
    IWebBrowserEvents * This,
    /* [in] */ VARIANT_BOOL TheaterMode);


void __RPC_STUB IWebBrowserEvents_OnTheaterMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWebBrowserEvents_WindowSetResizable_Proxy( 
    IWebBrowserEvents * This,
    /* [in] */ VARIANT_BOOL Resizable);


void __RPC_STUB IWebBrowserEvents_WindowSetResizable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWebBrowserEvents_WindowSetLeft_Proxy( 
    IWebBrowserEvents * This,
    /* [in] */ long Left);


void __RPC_STUB IWebBrowserEvents_WindowSetLeft_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWebBrowserEvents_WindowSetTop_Proxy( 
    IWebBrowserEvents * This,
    /* [in] */ long Top);


void __RPC_STUB IWebBrowserEvents_WindowSetTop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWebBrowserEvents_WindowSetWidth_Proxy( 
    IWebBrowserEvents * This,
    /* [in] */ long Width);


void __RPC_STUB IWebBrowserEvents_WindowSetWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWebBrowserEvents_WindowSetHeight_Proxy( 
    IWebBrowserEvents * This,
    /* [in] */ long Height);


void __RPC_STUB IWebBrowserEvents_WindowSetHeight_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWebBrowserEvents_WindowClosing_Proxy( 
    IWebBrowserEvents * This,
    /* [in] */ VARIANT_BOOL IsChildWindow,
    /* [out][in] */ VARIANT_BOOL *Cancel);


void __RPC_STUB IWebBrowserEvents_WindowClosing_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWebBrowserEvents_ClientToHostWindow_Proxy( 
    IWebBrowserEvents * This,
    /* [out][in] */ long *CX,
    /* [out][in] */ long *CY);


void __RPC_STUB IWebBrowserEvents_ClientToHostWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWebBrowserEvents_SetSecureLockIcon_Proxy( 
    IWebBrowserEvents * This,
    /* [in] */ long SecureLockIcon);


void __RPC_STUB IWebBrowserEvents_SetSecureLockIcon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWebBrowserEvents_FileDownload_Proxy( 
    IWebBrowserEvents * This,
    /* [out][in] */ VARIANT_BOOL *Cancel);


void __RPC_STUB IWebBrowserEvents_FileDownload_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWebBrowserEvents_NavigateError_Proxy( 
    IWebBrowserEvents * This,
    /* [in] */ IDispatch *pDisp,
    /* [in] */ VARIANT *URL,
    /* [in] */ VARIANT *Frame,
    /* [in] */ VARIANT *StatusCode,
    /* [out][in] */ VARIANT_BOOL *Cancel);


void __RPC_STUB IWebBrowserEvents_NavigateError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWebBrowserEvents_PrintTemplateInstantiation_Proxy( 
    IWebBrowserEvents * This,
    /* [in] */ IDispatch *pDisp);


void __RPC_STUB IWebBrowserEvents_PrintTemplateInstantiation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWebBrowserEvents_PrintTemplateTeardown_Proxy( 
    IWebBrowserEvents * This,
    /* [in] */ IDispatch *pDisp);


void __RPC_STUB IWebBrowserEvents_PrintTemplateTeardown_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWebBrowserEvents_UpdatePageStatus_Proxy( 
    IWebBrowserEvents * This,
    /* [in] */ IDispatch *pDisp,
    /* [in] */ VARIANT *nPage,
    /* [in] */ VARIANT *fDone);


void __RPC_STUB IWebBrowserEvents_UpdatePageStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWebBrowserEvents_PrivacyImpactedStateChange_Proxy( 
    IWebBrowserEvents * This,
    /* [in] */ VARIANT_BOOL bImpacted);


void __RPC_STUB IWebBrowserEvents_PrivacyImpactedStateChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWebBrowserEvents_INTERFACE_DEFINED__ */


#ifndef __IXmoe_INTERFACE_DEFINED__
#define __IXmoe_INTERFACE_DEFINED__

/* interface IXmoe */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IXmoe;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("710B3B21-654C-4c07-A062-B7287132F97D")
    IXmoe : public IDispatch
    {
    public:
        virtual /* [helpstring][id][nonbrowsable][propget] */ HRESULT STDMETHODCALLTYPE get_Docs( 
            /* [retval][out] */ IDocs **d) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Top( 
            /* [in] */ long t) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Top( 
            /* [retval][out] */ long *t) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Left( 
            /* [in] */ long l) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Left( 
            /* [retval][out] */ long *l) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Height( 
            /* [in] */ long h) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Height( 
            /* [retval][out] */ long *h) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Width( 
            /* [in] */ long w) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Width( 
            /* [retval][out] */ long *w) = 0;
        
        virtual /* [helpstring][id][requestedit][nonbrowsable][propget] */ HRESULT STDMETHODCALLTYPE get_ActiveDoc( 
            /* [retval][out] */ IDoc **d) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_ShowTreeView( 
            /* [in] */ VARIANT_BOOL vb) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_ShowTreeView( 
            /* [retval][out] */ VARIANT_BOOL *vb) = 0;
        
        virtual /* [helpstring][id][nonbrowsable][propget] */ HRESULT STDMETHODCALLTYPE get_TreeView( 
            /* [retval][out] */ IDispatch **tv) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_SysType( 
            /* [in] */ long typ) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_SysType( 
            /* [retval][out] */ long *typ) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Encoding( 
            /* [in] */ long typ) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Encoding( 
            /* [retval][out] */ long *typ) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_TabUsage( 
            /* [in] */ VARIANT_BOOL vbTabUsage) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_TabUsage( 
            /* [retval][out] */ VARIANT_BOOL *vbTabUsage) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_TabIndents( 
            /* [in] */ VARIANT_BOOL vbTabIndents) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_TabIndents( 
            /* [retval][out] */ VARIANT_BOOL *vbTabIndents) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_BackSpaceUnindents( 
            /* [in] */ VARIANT_BOOL vbBackSpaceIndents) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_BackSpaceUnindents( 
            /* [retval][out] */ VARIANT_BOOL *vbBackSpaceIndents) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_TabWidth( 
            /* [in] */ long w) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_TabWidth( 
            /* [retval][out] */ long *w) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Syntax( 
            /* [in] */ long typ) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Syntax( 
            /* [retval][out] */ long *typ) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_ConfigPath( 
            /* [retval][out] */ BSTR *fPath) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_ModulePath( 
            /* [retval][out] */ BSTR *fPath) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Compiler( 
            /* [retval][out] */ IDispatch **c) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE New( 
            /* [retval][out] */ IDoc **d) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [in] */ BSTR fPath,
            /* [retval][out] */ IDoc **d) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenUTF8( 
            /* [in] */ BSTR fPath,
            /* [retval][out] */ IDoc **d) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenDir( 
            /* [in] */ BSTR dir,
            /* [retval][out] */ IDoc **d) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenHexEditor( 
            /* [in] */ BSTR f,
            /* [in] */ VARIANT_BOOL vbReadOnly,
            /* [retval][out] */ IDoc **hex) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenHtmlFrame( 
            /* [in] */ BSTR f,
            /* [retval][out] */ IDoc **htmlWnd) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChooseDir( 
            /* [retval][out] */ BSTR *dir) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveAll( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CloseAll( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Show( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Hide( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Activate( 
            /* [in] */ VARIANT i) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Exit( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Minimize( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Maximize( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Restore( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Tile( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Cascade( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetStatus( 
            /* [in] */ BSTR StatusText) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Help( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Run( 
            /* [in] */ BSTR f,
            /* [in] */ BSTR engine) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Eval( 
            /* [in] */ BSTR scrpt,
            /* [in] */ BSTR scrptLanguage) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE System( 
            /* [in] */ BSTR f) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ShowForm( 
            /* [in] */ BSTR src,
            /* [in] */ long l,
            /* [in] */ int t,
            /* [in] */ int w,
            /* [in] */ int h,
            /* [in] */ int formStyle) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Preferences( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Settings( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ExportSettings( 
            /* [in] */ BSTR f) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ImportSettings( 
            /* [in] */ BSTR f) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MsgBox( 
            /* [in] */ BSTR text,
            /* [in] */ BSTR title,
            /* [in] */ long flags,
            /* [retval][out] */ long *result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Debug( 
            /* [in] */ BSTR scrpt,
            /* [in] */ BSTR scrptLanguage) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateObjectAdmin( 
            /* [in] */ BSTR progid,
            /* [retval][out] */ IDispatch **disp) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Fullscreen( 
            /* [in] */ VARIANT_BOOL vbTabIndents) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Fullscreen( 
            /* [retval][out] */ VARIANT_BOOL *vbTabIndents) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IXmoeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IXmoe * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IXmoe * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IXmoe * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IXmoe * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IXmoe * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IXmoe * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IXmoe * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][nonbrowsable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Docs )( 
            IXmoe * This,
            /* [retval][out] */ IDocs **d);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Top )( 
            IXmoe * This,
            /* [in] */ long t);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Top )( 
            IXmoe * This,
            /* [retval][out] */ long *t);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Left )( 
            IXmoe * This,
            /* [in] */ long l);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Left )( 
            IXmoe * This,
            /* [retval][out] */ long *l);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Height )( 
            IXmoe * This,
            /* [in] */ long h);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Height )( 
            IXmoe * This,
            /* [retval][out] */ long *h);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Width )( 
            IXmoe * This,
            /* [in] */ long w);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Width )( 
            IXmoe * This,
            /* [retval][out] */ long *w);
        
        /* [helpstring][id][requestedit][nonbrowsable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveDoc )( 
            IXmoe * This,
            /* [retval][out] */ IDoc **d);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ShowTreeView )( 
            IXmoe * This,
            /* [in] */ VARIANT_BOOL vb);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ShowTreeView )( 
            IXmoe * This,
            /* [retval][out] */ VARIANT_BOOL *vb);
        
        /* [helpstring][id][nonbrowsable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TreeView )( 
            IXmoe * This,
            /* [retval][out] */ IDispatch **tv);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SysType )( 
            IXmoe * This,
            /* [in] */ long typ);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SysType )( 
            IXmoe * This,
            /* [retval][out] */ long *typ);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Encoding )( 
            IXmoe * This,
            /* [in] */ long typ);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Encoding )( 
            IXmoe * This,
            /* [retval][out] */ long *typ);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TabUsage )( 
            IXmoe * This,
            /* [in] */ VARIANT_BOOL vbTabUsage);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TabUsage )( 
            IXmoe * This,
            /* [retval][out] */ VARIANT_BOOL *vbTabUsage);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TabIndents )( 
            IXmoe * This,
            /* [in] */ VARIANT_BOOL vbTabIndents);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TabIndents )( 
            IXmoe * This,
            /* [retval][out] */ VARIANT_BOOL *vbTabIndents);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BackSpaceUnindents )( 
            IXmoe * This,
            /* [in] */ VARIANT_BOOL vbBackSpaceIndents);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BackSpaceUnindents )( 
            IXmoe * This,
            /* [retval][out] */ VARIANT_BOOL *vbBackSpaceIndents);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TabWidth )( 
            IXmoe * This,
            /* [in] */ long w);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TabWidth )( 
            IXmoe * This,
            /* [retval][out] */ long *w);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Syntax )( 
            IXmoe * This,
            /* [in] */ long typ);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Syntax )( 
            IXmoe * This,
            /* [retval][out] */ long *typ);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ConfigPath )( 
            IXmoe * This,
            /* [retval][out] */ BSTR *fPath);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ModulePath )( 
            IXmoe * This,
            /* [retval][out] */ BSTR *fPath);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Compiler )( 
            IXmoe * This,
            /* [retval][out] */ IDispatch **c);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *New )( 
            IXmoe * This,
            /* [retval][out] */ IDoc **d);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IXmoe * This,
            /* [in] */ BSTR fPath,
            /* [retval][out] */ IDoc **d);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenUTF8 )( 
            IXmoe * This,
            /* [in] */ BSTR fPath,
            /* [retval][out] */ IDoc **d);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenDir )( 
            IXmoe * This,
            /* [in] */ BSTR dir,
            /* [retval][out] */ IDoc **d);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenHexEditor )( 
            IXmoe * This,
            /* [in] */ BSTR f,
            /* [in] */ VARIANT_BOOL vbReadOnly,
            /* [retval][out] */ IDoc **hex);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenHtmlFrame )( 
            IXmoe * This,
            /* [in] */ BSTR f,
            /* [retval][out] */ IDoc **htmlWnd);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChooseDir )( 
            IXmoe * This,
            /* [retval][out] */ BSTR *dir);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveAll )( 
            IXmoe * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CloseAll )( 
            IXmoe * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Show )( 
            IXmoe * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Hide )( 
            IXmoe * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Activate )( 
            IXmoe * This,
            /* [in] */ VARIANT i);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Exit )( 
            IXmoe * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Minimize )( 
            IXmoe * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Maximize )( 
            IXmoe * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Restore )( 
            IXmoe * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Tile )( 
            IXmoe * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Cascade )( 
            IXmoe * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetStatus )( 
            IXmoe * This,
            /* [in] */ BSTR StatusText);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Help )( 
            IXmoe * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Run )( 
            IXmoe * This,
            /* [in] */ BSTR f,
            /* [in] */ BSTR engine);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Eval )( 
            IXmoe * This,
            /* [in] */ BSTR scrpt,
            /* [in] */ BSTR scrptLanguage);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *System )( 
            IXmoe * This,
            /* [in] */ BSTR f);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ShowForm )( 
            IXmoe * This,
            /* [in] */ BSTR src,
            /* [in] */ long l,
            /* [in] */ int t,
            /* [in] */ int w,
            /* [in] */ int h,
            /* [in] */ int formStyle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Preferences )( 
            IXmoe * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Settings )( 
            IXmoe * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ExportSettings )( 
            IXmoe * This,
            /* [in] */ BSTR f);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ImportSettings )( 
            IXmoe * This,
            /* [in] */ BSTR f);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MsgBox )( 
            IXmoe * This,
            /* [in] */ BSTR text,
            /* [in] */ BSTR title,
            /* [in] */ long flags,
            /* [retval][out] */ long *result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Debug )( 
            IXmoe * This,
            /* [in] */ BSTR scrpt,
            /* [in] */ BSTR scrptLanguage);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateObjectAdmin )( 
            IXmoe * This,
            /* [in] */ BSTR progid,
            /* [retval][out] */ IDispatch **disp);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Fullscreen )( 
            IXmoe * This,
            /* [in] */ VARIANT_BOOL vbTabIndents);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Fullscreen )( 
            IXmoe * This,
            /* [retval][out] */ VARIANT_BOOL *vbTabIndents);
        
        END_INTERFACE
    } IXmoeVtbl;

    interface IXmoe
    {
        CONST_VTBL struct IXmoeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXmoe_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IXmoe_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IXmoe_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IXmoe_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IXmoe_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IXmoe_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IXmoe_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IXmoe_get_Docs(This,d)	\
    ( (This)->lpVtbl -> get_Docs(This,d) ) 

#define IXmoe_put_Top(This,t)	\
    ( (This)->lpVtbl -> put_Top(This,t) ) 

#define IXmoe_get_Top(This,t)	\
    ( (This)->lpVtbl -> get_Top(This,t) ) 

#define IXmoe_put_Left(This,l)	\
    ( (This)->lpVtbl -> put_Left(This,l) ) 

#define IXmoe_get_Left(This,l)	\
    ( (This)->lpVtbl -> get_Left(This,l) ) 

#define IXmoe_put_Height(This,h)	\
    ( (This)->lpVtbl -> put_Height(This,h) ) 

#define IXmoe_get_Height(This,h)	\
    ( (This)->lpVtbl -> get_Height(This,h) ) 

#define IXmoe_put_Width(This,w)	\
    ( (This)->lpVtbl -> put_Width(This,w) ) 

#define IXmoe_get_Width(This,w)	\
    ( (This)->lpVtbl -> get_Width(This,w) ) 

#define IXmoe_get_ActiveDoc(This,d)	\
    ( (This)->lpVtbl -> get_ActiveDoc(This,d) ) 

#define IXmoe_put_ShowTreeView(This,vb)	\
    ( (This)->lpVtbl -> put_ShowTreeView(This,vb) ) 

#define IXmoe_get_ShowTreeView(This,vb)	\
    ( (This)->lpVtbl -> get_ShowTreeView(This,vb) ) 

#define IXmoe_get_TreeView(This,tv)	\
    ( (This)->lpVtbl -> get_TreeView(This,tv) ) 

#define IXmoe_put_SysType(This,typ)	\
    ( (This)->lpVtbl -> put_SysType(This,typ) ) 

#define IXmoe_get_SysType(This,typ)	\
    ( (This)->lpVtbl -> get_SysType(This,typ) ) 

#define IXmoe_put_Encoding(This,typ)	\
    ( (This)->lpVtbl -> put_Encoding(This,typ) ) 

#define IXmoe_get_Encoding(This,typ)	\
    ( (This)->lpVtbl -> get_Encoding(This,typ) ) 

#define IXmoe_put_TabUsage(This,vbTabUsage)	\
    ( (This)->lpVtbl -> put_TabUsage(This,vbTabUsage) ) 

#define IXmoe_get_TabUsage(This,vbTabUsage)	\
    ( (This)->lpVtbl -> get_TabUsage(This,vbTabUsage) ) 

#define IXmoe_put_TabIndents(This,vbTabIndents)	\
    ( (This)->lpVtbl -> put_TabIndents(This,vbTabIndents) ) 

#define IXmoe_get_TabIndents(This,vbTabIndents)	\
    ( (This)->lpVtbl -> get_TabIndents(This,vbTabIndents) ) 

#define IXmoe_put_BackSpaceUnindents(This,vbBackSpaceIndents)	\
    ( (This)->lpVtbl -> put_BackSpaceUnindents(This,vbBackSpaceIndents) ) 

#define IXmoe_get_BackSpaceUnindents(This,vbBackSpaceIndents)	\
    ( (This)->lpVtbl -> get_BackSpaceUnindents(This,vbBackSpaceIndents) ) 

#define IXmoe_put_TabWidth(This,w)	\
    ( (This)->lpVtbl -> put_TabWidth(This,w) ) 

#define IXmoe_get_TabWidth(This,w)	\
    ( (This)->lpVtbl -> get_TabWidth(This,w) ) 

#define IXmoe_put_Syntax(This,typ)	\
    ( (This)->lpVtbl -> put_Syntax(This,typ) ) 

#define IXmoe_get_Syntax(This,typ)	\
    ( (This)->lpVtbl -> get_Syntax(This,typ) ) 

#define IXmoe_get_ConfigPath(This,fPath)	\
    ( (This)->lpVtbl -> get_ConfigPath(This,fPath) ) 

#define IXmoe_get_ModulePath(This,fPath)	\
    ( (This)->lpVtbl -> get_ModulePath(This,fPath) ) 

#define IXmoe_get_Compiler(This,c)	\
    ( (This)->lpVtbl -> get_Compiler(This,c) ) 

#define IXmoe_New(This,d)	\
    ( (This)->lpVtbl -> New(This,d) ) 

#define IXmoe_Open(This,fPath,d)	\
    ( (This)->lpVtbl -> Open(This,fPath,d) ) 

#define IXmoe_OpenUTF8(This,fPath,d)	\
    ( (This)->lpVtbl -> OpenUTF8(This,fPath,d) ) 

#define IXmoe_OpenDir(This,dir,d)	\
    ( (This)->lpVtbl -> OpenDir(This,dir,d) ) 

#define IXmoe_OpenHexEditor(This,f,vbReadOnly,hex)	\
    ( (This)->lpVtbl -> OpenHexEditor(This,f,vbReadOnly,hex) ) 

#define IXmoe_OpenHtmlFrame(This,f,htmlWnd)	\
    ( (This)->lpVtbl -> OpenHtmlFrame(This,f,htmlWnd) ) 

#define IXmoe_ChooseDir(This,dir)	\
    ( (This)->lpVtbl -> ChooseDir(This,dir) ) 

#define IXmoe_SaveAll(This)	\
    ( (This)->lpVtbl -> SaveAll(This) ) 

#define IXmoe_CloseAll(This)	\
    ( (This)->lpVtbl -> CloseAll(This) ) 

#define IXmoe_Show(This)	\
    ( (This)->lpVtbl -> Show(This) ) 

#define IXmoe_Hide(This)	\
    ( (This)->lpVtbl -> Hide(This) ) 

#define IXmoe_Activate(This,i)	\
    ( (This)->lpVtbl -> Activate(This,i) ) 

#define IXmoe_Exit(This)	\
    ( (This)->lpVtbl -> Exit(This) ) 

#define IXmoe_Minimize(This)	\
    ( (This)->lpVtbl -> Minimize(This) ) 

#define IXmoe_Maximize(This)	\
    ( (This)->lpVtbl -> Maximize(This) ) 

#define IXmoe_Restore(This)	\
    ( (This)->lpVtbl -> Restore(This) ) 

#define IXmoe_Tile(This)	\
    ( (This)->lpVtbl -> Tile(This) ) 

#define IXmoe_Cascade(This)	\
    ( (This)->lpVtbl -> Cascade(This) ) 

#define IXmoe_SetStatus(This,StatusText)	\
    ( (This)->lpVtbl -> SetStatus(This,StatusText) ) 

#define IXmoe_Help(This)	\
    ( (This)->lpVtbl -> Help(This) ) 

#define IXmoe_Run(This,f,engine)	\
    ( (This)->lpVtbl -> Run(This,f,engine) ) 

#define IXmoe_Eval(This,scrpt,scrptLanguage)	\
    ( (This)->lpVtbl -> Eval(This,scrpt,scrptLanguage) ) 

#define IXmoe_System(This,f)	\
    ( (This)->lpVtbl -> System(This,f) ) 

#define IXmoe_ShowForm(This,src,l,t,w,h,formStyle)	\
    ( (This)->lpVtbl -> ShowForm(This,src,l,t,w,h,formStyle) ) 

#define IXmoe_Preferences(This)	\
    ( (This)->lpVtbl -> Preferences(This) ) 

#define IXmoe_Settings(This)	\
    ( (This)->lpVtbl -> Settings(This) ) 

#define IXmoe_ExportSettings(This,f)	\
    ( (This)->lpVtbl -> ExportSettings(This,f) ) 

#define IXmoe_ImportSettings(This,f)	\
    ( (This)->lpVtbl -> ImportSettings(This,f) ) 

#define IXmoe_MsgBox(This,text,title,flags,result)	\
    ( (This)->lpVtbl -> MsgBox(This,text,title,flags,result) ) 

#define IXmoe_Debug(This,scrpt,scrptLanguage)	\
    ( (This)->lpVtbl -> Debug(This,scrpt,scrptLanguage) ) 

#define IXmoe_CreateObjectAdmin(This,progid,disp)	\
    ( (This)->lpVtbl -> CreateObjectAdmin(This,progid,disp) ) 

#define IXmoe_put_Fullscreen(This,vbTabIndents)	\
    ( (This)->lpVtbl -> put_Fullscreen(This,vbTabIndents) ) 

#define IXmoe_get_Fullscreen(This,vbTabIndents)	\
    ( (This)->lpVtbl -> get_Fullscreen(This,vbTabIndents) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IXmoe_INTERFACE_DEFINED__ */


#ifndef __IDoc_INTERFACE_DEFINED__
#define __IDoc_INTERFACE_DEFINED__

/* interface IDoc */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IDoc;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("25867097-B5C3-4d5e-999F-417FCBAE218C")
    IDoc : public IDispatch
    {
    public:
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Filename( 
            /* [retval][out] */ BSTR *fname) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Path( 
            /* [retval][out] */ BSTR *dname) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Top( 
            /* [in] */ long t) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Top( 
            /* [retval][out] */ long *t) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Left( 
            /* [in] */ long l) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Left( 
            /* [retval][out] */ long *l) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Height( 
            /* [in] */ long h) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Height( 
            /* [retval][out] */ long *h) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Width( 
            /* [in] */ long w) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Width( 
            /* [retval][out] */ long *w) = 0;
        
        virtual /* [helpstring][id][nonbrowsable][propget] */ HRESULT STDMETHODCALLTYPE get_App( 
            /* [retval][out] */ IXmoe **m) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ long *typ) = 0;
        
        virtual /* [helpstring][id][nonbrowsable][propget] */ HRESULT STDMETHODCALLTYPE get_Document( 
            /* [retval][out] */ IDispatch **d) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Show( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Hide( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Minimize( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Maximize( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Restore( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Activate( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDocVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDoc * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDoc * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDoc * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDoc * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDoc * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDoc * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDoc * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Filename )( 
            IDoc * This,
            /* [retval][out] */ BSTR *fname);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Path )( 
            IDoc * This,
            /* [retval][out] */ BSTR *dname);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Top )( 
            IDoc * This,
            /* [in] */ long t);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Top )( 
            IDoc * This,
            /* [retval][out] */ long *t);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Left )( 
            IDoc * This,
            /* [in] */ long l);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Left )( 
            IDoc * This,
            /* [retval][out] */ long *l);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Height )( 
            IDoc * This,
            /* [in] */ long h);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Height )( 
            IDoc * This,
            /* [retval][out] */ long *h);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Width )( 
            IDoc * This,
            /* [in] */ long w);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Width )( 
            IDoc * This,
            /* [retval][out] */ long *w);
        
        /* [helpstring][id][nonbrowsable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_App )( 
            IDoc * This,
            /* [retval][out] */ IXmoe **m);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            IDoc * This,
            /* [retval][out] */ long *typ);
        
        /* [helpstring][id][nonbrowsable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Document )( 
            IDoc * This,
            /* [retval][out] */ IDispatch **d);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Show )( 
            IDoc * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Hide )( 
            IDoc * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Minimize )( 
            IDoc * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Maximize )( 
            IDoc * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Restore )( 
            IDoc * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IDoc * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Activate )( 
            IDoc * This);
        
        END_INTERFACE
    } IDocVtbl;

    interface IDoc
    {
        CONST_VTBL struct IDocVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDoc_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDoc_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDoc_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDoc_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDoc_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDoc_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDoc_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IDoc_get_Filename(This,fname)	\
    ( (This)->lpVtbl -> get_Filename(This,fname) ) 

#define IDoc_get_Path(This,dname)	\
    ( (This)->lpVtbl -> get_Path(This,dname) ) 

#define IDoc_put_Top(This,t)	\
    ( (This)->lpVtbl -> put_Top(This,t) ) 

#define IDoc_get_Top(This,t)	\
    ( (This)->lpVtbl -> get_Top(This,t) ) 

#define IDoc_put_Left(This,l)	\
    ( (This)->lpVtbl -> put_Left(This,l) ) 

#define IDoc_get_Left(This,l)	\
    ( (This)->lpVtbl -> get_Left(This,l) ) 

#define IDoc_put_Height(This,h)	\
    ( (This)->lpVtbl -> put_Height(This,h) ) 

#define IDoc_get_Height(This,h)	\
    ( (This)->lpVtbl -> get_Height(This,h) ) 

#define IDoc_put_Width(This,w)	\
    ( (This)->lpVtbl -> put_Width(This,w) ) 

#define IDoc_get_Width(This,w)	\
    ( (This)->lpVtbl -> get_Width(This,w) ) 

#define IDoc_get_App(This,m)	\
    ( (This)->lpVtbl -> get_App(This,m) ) 

#define IDoc_get_Type(This,typ)	\
    ( (This)->lpVtbl -> get_Type(This,typ) ) 

#define IDoc_get_Document(This,d)	\
    ( (This)->lpVtbl -> get_Document(This,d) ) 

#define IDoc_Show(This)	\
    ( (This)->lpVtbl -> Show(This) ) 

#define IDoc_Hide(This)	\
    ( (This)->lpVtbl -> Hide(This) ) 

#define IDoc_Minimize(This)	\
    ( (This)->lpVtbl -> Minimize(This) ) 

#define IDoc_Maximize(This)	\
    ( (This)->lpVtbl -> Maximize(This) ) 

#define IDoc_Restore(This)	\
    ( (This)->lpVtbl -> Restore(This) ) 

#define IDoc_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IDoc_Activate(This)	\
    ( (This)->lpVtbl -> Activate(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDoc_INTERFACE_DEFINED__ */


#ifndef __IDocs_INTERFACE_DEFINED__
#define __IDocs_INTERFACE_DEFINED__

/* interface IDocs */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IDocs;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("609BCD33-CDEC-416d-9BBD-F551D452614D")
    IDocs : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE _NewEnum( 
            /* [retval][out] */ IEnumVARIANT **newEnum) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ VARIANT i,
            /* [retval][out] */ IDoc **docItem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Count( 
            /* [retval][out] */ long *cnt) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDocsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDocs * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDocs * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDocs * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDocs * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDocs * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDocs * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDocs * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *_NewEnum )( 
            IDocs * This,
            /* [retval][out] */ IEnumVARIANT **newEnum);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            IDocs * This,
            /* [in] */ VARIANT i,
            /* [retval][out] */ IDoc **docItem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Count )( 
            IDocs * This,
            /* [retval][out] */ long *cnt);
        
        END_INTERFACE
    } IDocsVtbl;

    interface IDocs
    {
        CONST_VTBL struct IDocsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDocs_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDocs_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDocs_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDocs_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDocs_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDocs_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDocs_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IDocs__NewEnum(This,newEnum)	\
    ( (This)->lpVtbl -> _NewEnum(This,newEnum) ) 

#define IDocs_Item(This,i,docItem)	\
    ( (This)->lpVtbl -> Item(This,i,docItem) ) 

#define IDocs_Count(This,cnt)	\
    ( (This)->lpVtbl -> Count(This,cnt) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDocs_INTERFACE_DEFINED__ */


#ifndef __IMoeFrame_INTERFACE_DEFINED__
#define __IMoeFrame_INTERFACE_DEFINED__

/* interface IMoeFrame */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IMoeFrame;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BF8832A5-AE58-4c26-BBC4-CECCF910149C")
    IMoeFrame : public IDispatch
    {
    public:
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Document( 
            /* [retval][out] */ IDispatch **d) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Top( 
            /* [in] */ long t) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Top( 
            /* [retval][out] */ long *t) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Left( 
            /* [in] */ long l) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Left( 
            /* [retval][out] */ long *l) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Height( 
            /* [in] */ long h) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Height( 
            /* [retval][out] */ long *h) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Width( 
            /* [in] */ long w) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Width( 
            /* [retval][out] */ long *w) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Title( 
            /* [in] */ BSTR t) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Title( 
            /* [retval][out] */ BSTR *t) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Scripts( 
            /* [retval][out] */ IDispatch **s) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CodeBehind( 
            /* [in] */ IDispatch *code) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Eval( 
            /* [in] */ BSTR src,
            /* [in] */ BSTR scrptLanguage) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OleCmd( 
            /* [in] */ long cmd) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMoeFrameVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMoeFrame * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMoeFrame * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMoeFrame * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMoeFrame * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMoeFrame * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMoeFrame * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMoeFrame * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Document )( 
            IMoeFrame * This,
            /* [retval][out] */ IDispatch **d);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Top )( 
            IMoeFrame * This,
            /* [in] */ long t);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Top )( 
            IMoeFrame * This,
            /* [retval][out] */ long *t);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Left )( 
            IMoeFrame * This,
            /* [in] */ long l);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Left )( 
            IMoeFrame * This,
            /* [retval][out] */ long *l);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Height )( 
            IMoeFrame * This,
            /* [in] */ long h);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Height )( 
            IMoeFrame * This,
            /* [retval][out] */ long *h);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Width )( 
            IMoeFrame * This,
            /* [in] */ long w);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Width )( 
            IMoeFrame * This,
            /* [retval][out] */ long *w);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Title )( 
            IMoeFrame * This,
            /* [in] */ BSTR t);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Title )( 
            IMoeFrame * This,
            /* [retval][out] */ BSTR *t);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Scripts )( 
            IMoeFrame * This,
            /* [retval][out] */ IDispatch **s);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CodeBehind )( 
            IMoeFrame * This,
            /* [in] */ IDispatch *code);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IMoeFrame * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Eval )( 
            IMoeFrame * This,
            /* [in] */ BSTR src,
            /* [in] */ BSTR scrptLanguage);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OleCmd )( 
            IMoeFrame * This,
            /* [in] */ long cmd);
        
        END_INTERFACE
    } IMoeFrameVtbl;

    interface IMoeFrame
    {
        CONST_VTBL struct IMoeFrameVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMoeFrame_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMoeFrame_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMoeFrame_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMoeFrame_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMoeFrame_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMoeFrame_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMoeFrame_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMoeFrame_get_Document(This,d)	\
    ( (This)->lpVtbl -> get_Document(This,d) ) 

#define IMoeFrame_put_Top(This,t)	\
    ( (This)->lpVtbl -> put_Top(This,t) ) 

#define IMoeFrame_get_Top(This,t)	\
    ( (This)->lpVtbl -> get_Top(This,t) ) 

#define IMoeFrame_put_Left(This,l)	\
    ( (This)->lpVtbl -> put_Left(This,l) ) 

#define IMoeFrame_get_Left(This,l)	\
    ( (This)->lpVtbl -> get_Left(This,l) ) 

#define IMoeFrame_put_Height(This,h)	\
    ( (This)->lpVtbl -> put_Height(This,h) ) 

#define IMoeFrame_get_Height(This,h)	\
    ( (This)->lpVtbl -> get_Height(This,h) ) 

#define IMoeFrame_put_Width(This,w)	\
    ( (This)->lpVtbl -> put_Width(This,w) ) 

#define IMoeFrame_get_Width(This,w)	\
    ( (This)->lpVtbl -> get_Width(This,w) ) 

#define IMoeFrame_put_Title(This,t)	\
    ( (This)->lpVtbl -> put_Title(This,t) ) 

#define IMoeFrame_get_Title(This,t)	\
    ( (This)->lpVtbl -> get_Title(This,t) ) 

#define IMoeFrame_get_Scripts(This,s)	\
    ( (This)->lpVtbl -> get_Scripts(This,s) ) 

#define IMoeFrame_put_CodeBehind(This,code)	\
    ( (This)->lpVtbl -> put_CodeBehind(This,code) ) 

#define IMoeFrame_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IMoeFrame_Eval(This,src,scrptLanguage)	\
    ( (This)->lpVtbl -> Eval(This,src,scrptLanguage) ) 

#define IMoeFrame_OleCmd(This,cmd)	\
    ( (This)->lpVtbl -> OleCmd(This,cmd) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMoeFrame_INTERFACE_DEFINED__ */


#ifndef __IExternalMoe_INTERFACE_DEFINED__
#define __IExternalMoe_INTERFACE_DEFINED__

/* interface IExternalMoe */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IExternalMoe;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5AA6374E-4995-4f49-AF45-6A047654CDD2")
    IExternalMoe : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Moe( 
            /* [retval][out] */ IDispatch **m) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Frame( 
            /* [retval][out] */ IMoeFrame **f) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Code( 
            /* [retval][out] */ IDispatch **code) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateObject( 
            /* [in] */ BSTR progid,
            /* [retval][out] */ IDispatch **disp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CodeBehind( 
            /* [in] */ BSTR fname) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IExternalMoeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IExternalMoe * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IExternalMoe * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IExternalMoe * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IExternalMoe * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IExternalMoe * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IExternalMoe * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IExternalMoe * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Moe )( 
            IExternalMoe * This,
            /* [retval][out] */ IDispatch **m);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Frame )( 
            IExternalMoe * This,
            /* [retval][out] */ IMoeFrame **f);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Code )( 
            IExternalMoe * This,
            /* [retval][out] */ IDispatch **code);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IExternalMoe * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateObject )( 
            IExternalMoe * This,
            /* [in] */ BSTR progid,
            /* [retval][out] */ IDispatch **disp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CodeBehind )( 
            IExternalMoe * This,
            /* [in] */ BSTR fname);
        
        END_INTERFACE
    } IExternalMoeVtbl;

    interface IExternalMoe
    {
        CONST_VTBL struct IExternalMoeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IExternalMoe_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IExternalMoe_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IExternalMoe_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IExternalMoe_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IExternalMoe_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IExternalMoe_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IExternalMoe_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IExternalMoe_get_Moe(This,m)	\
    ( (This)->lpVtbl -> get_Moe(This,m) ) 

#define IExternalMoe_get_Frame(This,f)	\
    ( (This)->lpVtbl -> get_Frame(This,f) ) 

#define IExternalMoe_get_Code(This,code)	\
    ( (This)->lpVtbl -> get_Code(This,code) ) 

#define IExternalMoe_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IExternalMoe_CreateObject(This,progid,disp)	\
    ( (This)->lpVtbl -> CreateObject(This,progid,disp) ) 

#define IExternalMoe_CodeBehind(This,fname)	\
    ( (This)->lpVtbl -> CodeBehind(This,fname) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IExternalMoe_INTERFACE_DEFINED__ */


#ifndef ___IXmoeEvents_DISPINTERFACE_DEFINED__
#define ___IXmoeEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IXmoeEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IXmoeEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("ABE0076F-2A48-448f-9716-7EF6550F3AB0")
    _IXmoeEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IXmoeEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IXmoeEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IXmoeEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IXmoeEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IXmoeEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IXmoeEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IXmoeEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IXmoeEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IXmoeEventsVtbl;

    interface _IXmoeEvents
    {
        CONST_VTBL struct _IXmoeEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IXmoeEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IXmoeEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IXmoeEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IXmoeEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IXmoeEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IXmoeEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IXmoeEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IXmoeEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Xmoe;

#ifdef __cplusplus

class DECLSPEC_UUID("6282C9F1-F8B8-446b-9F98-1D4B7043BB9C")
Xmoe;
#endif

EXTERN_C const CLSID CLSID_Docs;

#ifdef __cplusplus

class DECLSPEC_UUID("3BD5BD2B-A9BF-4cf0-8835-EA6462A058CF")
Docs;
#endif

EXTERN_C const CLSID CLSID_Doc;

#ifdef __cplusplus

class DECLSPEC_UUID("D3F8CB44-2FBC-4488-A4F0-378056D1FBF9")
Doc;
#endif
#endif /* __Moe_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


