

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Sat Jan 05 01:57:30 2013
 */
/* Compiler settings for src\moe.idl:
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


#ifndef __IMoe_FWD_DEFINED__
#define __IMoe_FWD_DEFINED__
typedef interface IMoe IMoe;
#endif 	/* __IMoe_FWD_DEFINED__ */


#ifndef __IMoeView_FWD_DEFINED__
#define __IMoeView_FWD_DEFINED__
typedef interface IMoeView IMoeView;
#endif 	/* __IMoeView_FWD_DEFINED__ */


#ifndef __IMoeScript_FWD_DEFINED__
#define __IMoeScript_FWD_DEFINED__
typedef interface IMoeScript IMoeScript;
#endif 	/* __IMoeScript_FWD_DEFINED__ */


#ifndef __IMoeConfig_FWD_DEFINED__
#define __IMoeConfig_FWD_DEFINED__
typedef interface IMoeConfig IMoeConfig;
#endif 	/* __IMoeConfig_FWD_DEFINED__ */


#ifndef __IMoeDialogs_FWD_DEFINED__
#define __IMoeDialogs_FWD_DEFINED__
typedef interface IMoeDialogs IMoeDialogs;
#endif 	/* __IMoeDialogs_FWD_DEFINED__ */


#ifndef __IMoeDocumentCollection_FWD_DEFINED__
#define __IMoeDocumentCollection_FWD_DEFINED__
typedef interface IMoeDocumentCollection IMoeDocumentCollection;
#endif 	/* __IMoeDocumentCollection_FWD_DEFINED__ */


#ifndef __IMoeDocument_FWD_DEFINED__
#define __IMoeDocument_FWD_DEFINED__
typedef interface IMoeDocument IMoeDocument;
#endif 	/* __IMoeDocument_FWD_DEFINED__ */


#ifndef __IMoeDocumentView_FWD_DEFINED__
#define __IMoeDocumentView_FWD_DEFINED__
typedef interface IMoeDocumentView IMoeDocumentView;
#endif 	/* __IMoeDocumentView_FWD_DEFINED__ */


#ifndef __IMoeHtmlFrame_FWD_DEFINED__
#define __IMoeHtmlFrame_FWD_DEFINED__
typedef interface IMoeHtmlFrame IMoeHtmlFrame;
#endif 	/* __IMoeHtmlFrame_FWD_DEFINED__ */


#ifndef __IMoeDialogView_FWD_DEFINED__
#define __IMoeDialogView_FWD_DEFINED__
typedef interface IMoeDialogView IMoeDialogView;
#endif 	/* __IMoeDialogView_FWD_DEFINED__ */


#ifndef __IMoeRichText_FWD_DEFINED__
#define __IMoeRichText_FWD_DEFINED__
typedef interface IMoeRichText IMoeRichText;
#endif 	/* __IMoeRichText_FWD_DEFINED__ */


#ifndef __IMoeUserForm_FWD_DEFINED__
#define __IMoeUserForm_FWD_DEFINED__
typedef interface IMoeUserForm IMoeUserForm;
#endif 	/* __IMoeUserForm_FWD_DEFINED__ */


#ifndef __IExternalMoe_FWD_DEFINED__
#define __IExternalMoe_FWD_DEFINED__
typedef interface IExternalMoe IExternalMoe;
#endif 	/* __IExternalMoe_FWD_DEFINED__ */


#ifndef __IMoeImport_FWD_DEFINED__
#define __IMoeImport_FWD_DEFINED__
typedef interface IMoeImport IMoeImport;
#endif 	/* __IMoeImport_FWD_DEFINED__ */


#ifndef __Application_FWD_DEFINED__
#define __Application_FWD_DEFINED__

#ifdef __cplusplus
typedef class Application Application;
#else
typedef struct Application Application;
#endif /* __cplusplus */

#endif 	/* __Application_FWD_DEFINED__ */


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
enum MOE_DOCTYPE
    {	MOE_DOCTYPE_NULL	= 0,
	MOE_DOCTYPE_DOC	= 1,
	MOE_DOCTYPE_DIR	= 2,
	MOE_DOCTYPE_PIC	= 3,
	MOE_DOCTYPE_HEX	= 4,
	MOE_DOCTYPE_HTML	= 5,
	MOE_DOCTYPE_OLE	= 6,
	MOE_DOCTYPE_FORM	= 7,
	MOE_DOCTYPE_RTF	= 8,
	MOE_DOCTYPE_TAIL	= 9,
	MOE_DOCTYPE_SFTP	= 10
    } 	MOE_DOCTYPE;

typedef 
enum MOE_SEARCHFLAG
    {	MOE_SEARCHFLAG_DOWN	= 0x1,
	MOE_SEARCHFLAG_WHOLEWORD	= 0x2,
	MOE_SEARCHFLAG_MATCHCASE	= 0x4,
	MOE_SEARCHFLAG_FINDNEXT	= 0x8,
	MOE_SEARCHFLAG_REPLACE	= 0x10,
	MOE_SEARCHFLAG_REPLACEALL	= 0x20,
	MOE_SEARCHFLAG_DIALOGTERM	= 0x40
    } 	MOE_SEARCHFLAG;

typedef 
enum MOE_FORMFLAG
    {	MOE_FORMFLAG_NONE	= 0,
	MOE_FORMFLAG_TITLE	= 1,
	MOE_FORMFLAG_NOSCROLL	= 2,
	MOE_FORMFLAG_DIALOG	= 4,
	MOE_FORMFLAG_STANDALONE	= 8
    } 	MOE_FORMFLAG;


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


#ifndef __IMoe_INTERFACE_DEFINED__
#define __IMoe_INTERFACE_DEFINED__

/* interface IMoe */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IMoe;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8C2C5817-4747-4da4-B588-75612B7608A2")
    IMoe : public IDispatch
    {
    public:
        virtual /* [helpstring][id][nonbrowsable][propget] */ HRESULT STDMETHODCALLTYPE get_Documents( 
            /* [retval][out] */ IMoeDocumentCollection **d) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_View( 
            /* [retval][out] */ IMoeView **d) = 0;
        
        virtual /* [helpstring][id][requestedit][nonbrowsable][propget] */ HRESULT STDMETHODCALLTYPE get_ActiveDoc( 
            /* [retval][out] */ IMoeDocument **d) = 0;
        
        virtual /* [helpstring][id][requestedit][nonbrowsable][propget] */ HRESULT STDMETHODCALLTYPE get_Config( 
            /* [retval][out] */ IMoeConfig **d) = 0;
        
        virtual /* [helpstring][id][requestedit][nonbrowsable][propget] */ HRESULT STDMETHODCALLTYPE get_Script( 
            /* [retval][out] */ IMoeScript **d) = 0;
        
        virtual /* [helpstring][id][requestedit][nonbrowsable][propget] */ HRESULT STDMETHODCALLTYPE get_Dialogs( 
            /* [retval][out] */ IMoeDialogs **d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_IDOK( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_IDCANCEL( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_IDABORT( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_IDRETRY( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_IDIGNORE( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_IDYES( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_IDNO( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_IDTRYAGAIN( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_IDCONTINUE( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ANSI( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_UNICODE( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_UTF8( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Print( 
            /* [in] */ BSTR txt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Exit( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMoeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMoe * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMoe * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMoe * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMoe * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMoe * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMoe * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMoe * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][nonbrowsable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Documents )( 
            IMoe * This,
            /* [retval][out] */ IMoeDocumentCollection **d);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_View )( 
            IMoe * This,
            /* [retval][out] */ IMoeView **d);
        
        /* [helpstring][id][requestedit][nonbrowsable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveDoc )( 
            IMoe * This,
            /* [retval][out] */ IMoeDocument **d);
        
        /* [helpstring][id][requestedit][nonbrowsable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Config )( 
            IMoe * This,
            /* [retval][out] */ IMoeConfig **d);
        
        /* [helpstring][id][requestedit][nonbrowsable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Script )( 
            IMoe * This,
            /* [retval][out] */ IMoeScript **d);
        
        /* [helpstring][id][requestedit][nonbrowsable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Dialogs )( 
            IMoe * This,
            /* [retval][out] */ IMoeDialogs **d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_IDOK )( 
            IMoe * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_IDCANCEL )( 
            IMoe * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_IDABORT )( 
            IMoe * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_IDRETRY )( 
            IMoe * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_IDIGNORE )( 
            IMoe * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_IDYES )( 
            IMoe * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_IDNO )( 
            IMoe * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_IDTRYAGAIN )( 
            IMoe * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_IDCONTINUE )( 
            IMoe * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ANSI )( 
            IMoe * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_UNICODE )( 
            IMoe * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_UTF8 )( 
            IMoe * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Print )( 
            IMoe * This,
            /* [in] */ BSTR txt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Exit )( 
            IMoe * This);
        
        END_INTERFACE
    } IMoeVtbl;

    interface IMoe
    {
        CONST_VTBL struct IMoeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMoe_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMoe_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMoe_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMoe_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMoe_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMoe_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMoe_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMoe_get_Documents(This,d)	\
    ( (This)->lpVtbl -> get_Documents(This,d) ) 

#define IMoe_get_View(This,d)	\
    ( (This)->lpVtbl -> get_View(This,d) ) 

#define IMoe_get_ActiveDoc(This,d)	\
    ( (This)->lpVtbl -> get_ActiveDoc(This,d) ) 

#define IMoe_get_Config(This,d)	\
    ( (This)->lpVtbl -> get_Config(This,d) ) 

#define IMoe_get_Script(This,d)	\
    ( (This)->lpVtbl -> get_Script(This,d) ) 

#define IMoe_get_Dialogs(This,d)	\
    ( (This)->lpVtbl -> get_Dialogs(This,d) ) 

#define IMoe_get_IDOK(This,d)	\
    ( (This)->lpVtbl -> get_IDOK(This,d) ) 

#define IMoe_get_IDCANCEL(This,d)	\
    ( (This)->lpVtbl -> get_IDCANCEL(This,d) ) 

#define IMoe_get_IDABORT(This,d)	\
    ( (This)->lpVtbl -> get_IDABORT(This,d) ) 

#define IMoe_get_IDRETRY(This,d)	\
    ( (This)->lpVtbl -> get_IDRETRY(This,d) ) 

#define IMoe_get_IDIGNORE(This,d)	\
    ( (This)->lpVtbl -> get_IDIGNORE(This,d) ) 

#define IMoe_get_IDYES(This,d)	\
    ( (This)->lpVtbl -> get_IDYES(This,d) ) 

#define IMoe_get_IDNO(This,d)	\
    ( (This)->lpVtbl -> get_IDNO(This,d) ) 

#define IMoe_get_IDTRYAGAIN(This,d)	\
    ( (This)->lpVtbl -> get_IDTRYAGAIN(This,d) ) 

#define IMoe_get_IDCONTINUE(This,d)	\
    ( (This)->lpVtbl -> get_IDCONTINUE(This,d) ) 

#define IMoe_get_ANSI(This,d)	\
    ( (This)->lpVtbl -> get_ANSI(This,d) ) 

#define IMoe_get_UNICODE(This,d)	\
    ( (This)->lpVtbl -> get_UNICODE(This,d) ) 

#define IMoe_get_UTF8(This,d)	\
    ( (This)->lpVtbl -> get_UTF8(This,d) ) 

#define IMoe_Print(This,txt)	\
    ( (This)->lpVtbl -> Print(This,txt) ) 

#define IMoe_Exit(This)	\
    ( (This)->lpVtbl -> Exit(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMoe_INTERFACE_DEFINED__ */


#ifndef __IMoeView_INTERFACE_DEFINED__
#define __IMoeView_INTERFACE_DEFINED__

/* interface IMoeView */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IMoeView;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E6F7C726-4A4A-487f-8DEA-0854229C1BCB")
    IMoeView : public IDispatch
    {
    public:
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
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Show( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Hide( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Minimize( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Maximize( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Restore( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Tile( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Cascade( void) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_ShowTreeView( 
            /* [in] */ VARIANT_BOOL vb) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_ShowTreeView( 
            /* [retval][out] */ VARIANT_BOOL *vb) = 0;
        
        virtual /* [helpstring][id][nonbrowsable][propget] */ HRESULT STDMETHODCALLTYPE get_TreeView( 
            /* [retval][out] */ IDispatch **tv) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Fullscreen( 
            /* [in] */ VARIANT_BOOL vb) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Fullscreen( 
            /* [retval][out] */ VARIANT_BOOL *vb) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMoeViewVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMoeView * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMoeView * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMoeView * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMoeView * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMoeView * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMoeView * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMoeView * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Top )( 
            IMoeView * This,
            /* [in] */ long t);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Top )( 
            IMoeView * This,
            /* [retval][out] */ long *t);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Left )( 
            IMoeView * This,
            /* [in] */ long l);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Left )( 
            IMoeView * This,
            /* [retval][out] */ long *l);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Height )( 
            IMoeView * This,
            /* [in] */ long h);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Height )( 
            IMoeView * This,
            /* [retval][out] */ long *h);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Width )( 
            IMoeView * This,
            /* [in] */ long w);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Width )( 
            IMoeView * This,
            /* [retval][out] */ long *w);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Show )( 
            IMoeView * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Hide )( 
            IMoeView * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Minimize )( 
            IMoeView * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Maximize )( 
            IMoeView * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Restore )( 
            IMoeView * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Tile )( 
            IMoeView * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Cascade )( 
            IMoeView * This);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ShowTreeView )( 
            IMoeView * This,
            /* [in] */ VARIANT_BOOL vb);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ShowTreeView )( 
            IMoeView * This,
            /* [retval][out] */ VARIANT_BOOL *vb);
        
        /* [helpstring][id][nonbrowsable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TreeView )( 
            IMoeView * This,
            /* [retval][out] */ IDispatch **tv);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Fullscreen )( 
            IMoeView * This,
            /* [in] */ VARIANT_BOOL vb);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Fullscreen )( 
            IMoeView * This,
            /* [retval][out] */ VARIANT_BOOL *vb);
        
        END_INTERFACE
    } IMoeViewVtbl;

    interface IMoeView
    {
        CONST_VTBL struct IMoeViewVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMoeView_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMoeView_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMoeView_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMoeView_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMoeView_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMoeView_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMoeView_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMoeView_put_Top(This,t)	\
    ( (This)->lpVtbl -> put_Top(This,t) ) 

#define IMoeView_get_Top(This,t)	\
    ( (This)->lpVtbl -> get_Top(This,t) ) 

#define IMoeView_put_Left(This,l)	\
    ( (This)->lpVtbl -> put_Left(This,l) ) 

#define IMoeView_get_Left(This,l)	\
    ( (This)->lpVtbl -> get_Left(This,l) ) 

#define IMoeView_put_Height(This,h)	\
    ( (This)->lpVtbl -> put_Height(This,h) ) 

#define IMoeView_get_Height(This,h)	\
    ( (This)->lpVtbl -> get_Height(This,h) ) 

#define IMoeView_put_Width(This,w)	\
    ( (This)->lpVtbl -> put_Width(This,w) ) 

#define IMoeView_get_Width(This,w)	\
    ( (This)->lpVtbl -> get_Width(This,w) ) 

#define IMoeView_Show(This)	\
    ( (This)->lpVtbl -> Show(This) ) 

#define IMoeView_Hide(This)	\
    ( (This)->lpVtbl -> Hide(This) ) 

#define IMoeView_Minimize(This)	\
    ( (This)->lpVtbl -> Minimize(This) ) 

#define IMoeView_Maximize(This)	\
    ( (This)->lpVtbl -> Maximize(This) ) 

#define IMoeView_Restore(This)	\
    ( (This)->lpVtbl -> Restore(This) ) 

#define IMoeView_Tile(This)	\
    ( (This)->lpVtbl -> Tile(This) ) 

#define IMoeView_Cascade(This)	\
    ( (This)->lpVtbl -> Cascade(This) ) 

#define IMoeView_put_ShowTreeView(This,vb)	\
    ( (This)->lpVtbl -> put_ShowTreeView(This,vb) ) 

#define IMoeView_get_ShowTreeView(This,vb)	\
    ( (This)->lpVtbl -> get_ShowTreeView(This,vb) ) 

#define IMoeView_get_TreeView(This,tv)	\
    ( (This)->lpVtbl -> get_TreeView(This,tv) ) 

#define IMoeView_put_Fullscreen(This,vb)	\
    ( (This)->lpVtbl -> put_Fullscreen(This,vb) ) 

#define IMoeView_get_Fullscreen(This,vb)	\
    ( (This)->lpVtbl -> get_Fullscreen(This,vb) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMoeView_INTERFACE_DEFINED__ */


#ifndef __IMoeScript_INTERFACE_DEFINED__
#define __IMoeScript_INTERFACE_DEFINED__

/* interface IMoeScript */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IMoeScript;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("809CE6F6-C2DE-4d8b-A7F2-C2FFD581E49C")
    IMoeScript : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Run( 
            /* [in] */ BSTR f,
            /* [in] */ BSTR engine) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Eval( 
            /* [in] */ BSTR scrpt,
            /* [in] */ BSTR scrptLanguage) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Debug( 
            /* [in] */ BSTR scrpt,
            /* [in] */ BSTR scrptLanguage) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateObjectAdmin( 
            /* [in] */ BSTR progid,
            /* [retval][out] */ IDispatch **disp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ShowHtmlForm( 
            /* [in] */ BSTR src,
            /* [in] */ long l,
            /* [in] */ int t,
            /* [in] */ int w,
            /* [in] */ int h,
            /* [in] */ int formStyle) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ShowUserForm( 
            /* [in] */ BSTR pathname,
            /* [retval][out] */ IMoeUserForm **form) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DebugUserForm( 
            /* [in] */ BSTR pathname,
            /* [retval][out] */ IMoeUserForm **form) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE System( 
            /* [in] */ BSTR f) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Picture( 
            /* [in] */ BSTR f,
            /* [retval][out] */ IDispatch **disp) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_FORM_DEFAULT( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_FORM_TITLE( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_FORM_NOSCROLL( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_FORM_DIALOG( 
            /* [retval][out] */ long *d) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMoeScriptVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMoeScript * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMoeScript * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMoeScript * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMoeScript * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMoeScript * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMoeScript * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMoeScript * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Run )( 
            IMoeScript * This,
            /* [in] */ BSTR f,
            /* [in] */ BSTR engine);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Eval )( 
            IMoeScript * This,
            /* [in] */ BSTR scrpt,
            /* [in] */ BSTR scrptLanguage);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Debug )( 
            IMoeScript * This,
            /* [in] */ BSTR scrpt,
            /* [in] */ BSTR scrptLanguage);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateObjectAdmin )( 
            IMoeScript * This,
            /* [in] */ BSTR progid,
            /* [retval][out] */ IDispatch **disp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ShowHtmlForm )( 
            IMoeScript * This,
            /* [in] */ BSTR src,
            /* [in] */ long l,
            /* [in] */ int t,
            /* [in] */ int w,
            /* [in] */ int h,
            /* [in] */ int formStyle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ShowUserForm )( 
            IMoeScript * This,
            /* [in] */ BSTR pathname,
            /* [retval][out] */ IMoeUserForm **form);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DebugUserForm )( 
            IMoeScript * This,
            /* [in] */ BSTR pathname,
            /* [retval][out] */ IMoeUserForm **form);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *System )( 
            IMoeScript * This,
            /* [in] */ BSTR f);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Picture )( 
            IMoeScript * This,
            /* [in] */ BSTR f,
            /* [retval][out] */ IDispatch **disp);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_FORM_DEFAULT )( 
            IMoeScript * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_FORM_TITLE )( 
            IMoeScript * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_FORM_NOSCROLL )( 
            IMoeScript * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_FORM_DIALOG )( 
            IMoeScript * This,
            /* [retval][out] */ long *d);
        
        END_INTERFACE
    } IMoeScriptVtbl;

    interface IMoeScript
    {
        CONST_VTBL struct IMoeScriptVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMoeScript_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMoeScript_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMoeScript_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMoeScript_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMoeScript_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMoeScript_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMoeScript_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMoeScript_Run(This,f,engine)	\
    ( (This)->lpVtbl -> Run(This,f,engine) ) 

#define IMoeScript_Eval(This,scrpt,scrptLanguage)	\
    ( (This)->lpVtbl -> Eval(This,scrpt,scrptLanguage) ) 

#define IMoeScript_Debug(This,scrpt,scrptLanguage)	\
    ( (This)->lpVtbl -> Debug(This,scrpt,scrptLanguage) ) 

#define IMoeScript_CreateObjectAdmin(This,progid,disp)	\
    ( (This)->lpVtbl -> CreateObjectAdmin(This,progid,disp) ) 

#define IMoeScript_ShowHtmlForm(This,src,l,t,w,h,formStyle)	\
    ( (This)->lpVtbl -> ShowHtmlForm(This,src,l,t,w,h,formStyle) ) 

#define IMoeScript_ShowUserForm(This,pathname,form)	\
    ( (This)->lpVtbl -> ShowUserForm(This,pathname,form) ) 

#define IMoeScript_DebugUserForm(This,pathname,form)	\
    ( (This)->lpVtbl -> DebugUserForm(This,pathname,form) ) 

#define IMoeScript_System(This,f)	\
    ( (This)->lpVtbl -> System(This,f) ) 

#define IMoeScript_Picture(This,f,disp)	\
    ( (This)->lpVtbl -> Picture(This,f,disp) ) 

#define IMoeScript_get_FORM_DEFAULT(This,d)	\
    ( (This)->lpVtbl -> get_FORM_DEFAULT(This,d) ) 

#define IMoeScript_get_FORM_TITLE(This,d)	\
    ( (This)->lpVtbl -> get_FORM_TITLE(This,d) ) 

#define IMoeScript_get_FORM_NOSCROLL(This,d)	\
    ( (This)->lpVtbl -> get_FORM_NOSCROLL(This,d) ) 

#define IMoeScript_get_FORM_DIALOG(This,d)	\
    ( (This)->lpVtbl -> get_FORM_DIALOG(This,d) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMoeScript_INTERFACE_DEFINED__ */


#ifndef __IMoeConfig_INTERFACE_DEFINED__
#define __IMoeConfig_INTERFACE_DEFINED__

/* interface IMoeConfig */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IMoeConfig;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4DE6729C-2F79-471f-82CB-51137A02E490")
    IMoeConfig : public IDispatch
    {
    public:
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_ConfigPath( 
            /* [retval][out] */ BSTR *fPath) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_ModulePath( 
            /* [retval][out] */ BSTR *fPath) = 0;
        
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
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_ShowLineNumbers( 
            /* [in] */ VARIANT_BOOL vb) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_ShowLineNumbers( 
            /* [retval][out] */ VARIANT_BOOL *vb) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EditPreferences( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EditSettings( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ExportSettings( 
            /* [in] */ BSTR f) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ImportSettings( 
            /* [in] */ BSTR f) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InitializeEditorFromPreferences( 
            /* [in] */ IMoeDocument *d) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Settings( 
            /* [retval][out] */ IDispatch **settings) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_StyleSets( 
            /* [retval][out] */ IDispatch **styles) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetStyles( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMoeConfigVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMoeConfig * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMoeConfig * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMoeConfig * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMoeConfig * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMoeConfig * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMoeConfig * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMoeConfig * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ConfigPath )( 
            IMoeConfig * This,
            /* [retval][out] */ BSTR *fPath);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ModulePath )( 
            IMoeConfig * This,
            /* [retval][out] */ BSTR *fPath);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SysType )( 
            IMoeConfig * This,
            /* [in] */ long typ);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SysType )( 
            IMoeConfig * This,
            /* [retval][out] */ long *typ);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Encoding )( 
            IMoeConfig * This,
            /* [in] */ long typ);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Encoding )( 
            IMoeConfig * This,
            /* [retval][out] */ long *typ);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TabUsage )( 
            IMoeConfig * This,
            /* [in] */ VARIANT_BOOL vbTabUsage);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TabUsage )( 
            IMoeConfig * This,
            /* [retval][out] */ VARIANT_BOOL *vbTabUsage);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TabIndents )( 
            IMoeConfig * This,
            /* [in] */ VARIANT_BOOL vbTabIndents);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TabIndents )( 
            IMoeConfig * This,
            /* [retval][out] */ VARIANT_BOOL *vbTabIndents);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BackSpaceUnindents )( 
            IMoeConfig * This,
            /* [in] */ VARIANT_BOOL vbBackSpaceIndents);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BackSpaceUnindents )( 
            IMoeConfig * This,
            /* [retval][out] */ VARIANT_BOOL *vbBackSpaceIndents);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TabWidth )( 
            IMoeConfig * This,
            /* [in] */ long w);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TabWidth )( 
            IMoeConfig * This,
            /* [retval][out] */ long *w);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ShowLineNumbers )( 
            IMoeConfig * This,
            /* [in] */ VARIANT_BOOL vb);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ShowLineNumbers )( 
            IMoeConfig * This,
            /* [retval][out] */ VARIANT_BOOL *vb);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EditPreferences )( 
            IMoeConfig * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EditSettings )( 
            IMoeConfig * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ExportSettings )( 
            IMoeConfig * This,
            /* [in] */ BSTR f);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ImportSettings )( 
            IMoeConfig * This,
            /* [in] */ BSTR f);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InitializeEditorFromPreferences )( 
            IMoeConfig * This,
            /* [in] */ IMoeDocument *d);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Settings )( 
            IMoeConfig * This,
            /* [retval][out] */ IDispatch **settings);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StyleSets )( 
            IMoeConfig * This,
            /* [retval][out] */ IDispatch **styles);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetStyles )( 
            IMoeConfig * This);
        
        END_INTERFACE
    } IMoeConfigVtbl;

    interface IMoeConfig
    {
        CONST_VTBL struct IMoeConfigVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMoeConfig_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMoeConfig_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMoeConfig_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMoeConfig_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMoeConfig_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMoeConfig_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMoeConfig_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMoeConfig_get_ConfigPath(This,fPath)	\
    ( (This)->lpVtbl -> get_ConfigPath(This,fPath) ) 

#define IMoeConfig_get_ModulePath(This,fPath)	\
    ( (This)->lpVtbl -> get_ModulePath(This,fPath) ) 

#define IMoeConfig_put_SysType(This,typ)	\
    ( (This)->lpVtbl -> put_SysType(This,typ) ) 

#define IMoeConfig_get_SysType(This,typ)	\
    ( (This)->lpVtbl -> get_SysType(This,typ) ) 

#define IMoeConfig_put_Encoding(This,typ)	\
    ( (This)->lpVtbl -> put_Encoding(This,typ) ) 

#define IMoeConfig_get_Encoding(This,typ)	\
    ( (This)->lpVtbl -> get_Encoding(This,typ) ) 

#define IMoeConfig_put_TabUsage(This,vbTabUsage)	\
    ( (This)->lpVtbl -> put_TabUsage(This,vbTabUsage) ) 

#define IMoeConfig_get_TabUsage(This,vbTabUsage)	\
    ( (This)->lpVtbl -> get_TabUsage(This,vbTabUsage) ) 

#define IMoeConfig_put_TabIndents(This,vbTabIndents)	\
    ( (This)->lpVtbl -> put_TabIndents(This,vbTabIndents) ) 

#define IMoeConfig_get_TabIndents(This,vbTabIndents)	\
    ( (This)->lpVtbl -> get_TabIndents(This,vbTabIndents) ) 

#define IMoeConfig_put_BackSpaceUnindents(This,vbBackSpaceIndents)	\
    ( (This)->lpVtbl -> put_BackSpaceUnindents(This,vbBackSpaceIndents) ) 

#define IMoeConfig_get_BackSpaceUnindents(This,vbBackSpaceIndents)	\
    ( (This)->lpVtbl -> get_BackSpaceUnindents(This,vbBackSpaceIndents) ) 

#define IMoeConfig_put_TabWidth(This,w)	\
    ( (This)->lpVtbl -> put_TabWidth(This,w) ) 

#define IMoeConfig_get_TabWidth(This,w)	\
    ( (This)->lpVtbl -> get_TabWidth(This,w) ) 

#define IMoeConfig_put_ShowLineNumbers(This,vb)	\
    ( (This)->lpVtbl -> put_ShowLineNumbers(This,vb) ) 

#define IMoeConfig_get_ShowLineNumbers(This,vb)	\
    ( (This)->lpVtbl -> get_ShowLineNumbers(This,vb) ) 

#define IMoeConfig_EditPreferences(This)	\
    ( (This)->lpVtbl -> EditPreferences(This) ) 

#define IMoeConfig_EditSettings(This)	\
    ( (This)->lpVtbl -> EditSettings(This) ) 

#define IMoeConfig_ExportSettings(This,f)	\
    ( (This)->lpVtbl -> ExportSettings(This,f) ) 

#define IMoeConfig_ImportSettings(This,f)	\
    ( (This)->lpVtbl -> ImportSettings(This,f) ) 

#define IMoeConfig_InitializeEditorFromPreferences(This,d)	\
    ( (This)->lpVtbl -> InitializeEditorFromPreferences(This,d) ) 

#define IMoeConfig_get_Settings(This,settings)	\
    ( (This)->lpVtbl -> get_Settings(This,settings) ) 

#define IMoeConfig_get_StyleSets(This,styles)	\
    ( (This)->lpVtbl -> get_StyleSets(This,styles) ) 

#define IMoeConfig_ResetStyles(This)	\
    ( (This)->lpVtbl -> ResetStyles(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMoeConfig_INTERFACE_DEFINED__ */


#ifndef __IMoeDialogs_INTERFACE_DEFINED__
#define __IMoeDialogs_INTERFACE_DEFINED__

/* interface IMoeDialogs */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IMoeDialogs;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C82F0BDB-5835-44b4-B708-5C077C2D3CF7")
    IMoeDialogs : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MsgBox( 
            /* [in] */ BSTR text,
            /* [in] */ BSTR title,
            /* [in] */ long flags,
            /* [retval][out] */ long *result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [in] */ BSTR path,
            /* [retval][out] */ IMoeDocument **d) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenDir( 
            /* [retval][out] */ IMoeDocument **d) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChooseFile( 
            /* [retval][out] */ BSTR *f) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChooseDir( 
            /* [retval][out] */ BSTR *d) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Help( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Print( void) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SEARCH_DOWN( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SEARCH_WHOLEWORD( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SEARCH_MATCHCASE( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SEARCH_FINDNEXT( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SEARCH_REPLACE( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SEARCH_REPLACEALL( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SEARCH_DIALOGTERM( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_OK( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_OKCANCEL( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ABORTRETRYIGNORE( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_YESNOCANCEL( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_YESNO( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_RETRYCANCEL( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_CANCELTRYCONTINUE( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ICONERROR( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ICONQUESTION( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ICONINFORMATION( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ICONWARNING( 
            /* [retval][out] */ long *d) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMoeDialogsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMoeDialogs * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMoeDialogs * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMoeDialogs * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMoeDialogs * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMoeDialogs * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMoeDialogs * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMoeDialogs * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MsgBox )( 
            IMoeDialogs * This,
            /* [in] */ BSTR text,
            /* [in] */ BSTR title,
            /* [in] */ long flags,
            /* [retval][out] */ long *result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IMoeDialogs * This,
            /* [in] */ BSTR path,
            /* [retval][out] */ IMoeDocument **d);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenDir )( 
            IMoeDialogs * This,
            /* [retval][out] */ IMoeDocument **d);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChooseFile )( 
            IMoeDialogs * This,
            /* [retval][out] */ BSTR *f);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChooseDir )( 
            IMoeDialogs * This,
            /* [retval][out] */ BSTR *d);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Help )( 
            IMoeDialogs * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Print )( 
            IMoeDialogs * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SEARCH_DOWN )( 
            IMoeDialogs * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SEARCH_WHOLEWORD )( 
            IMoeDialogs * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SEARCH_MATCHCASE )( 
            IMoeDialogs * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SEARCH_FINDNEXT )( 
            IMoeDialogs * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SEARCH_REPLACE )( 
            IMoeDialogs * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SEARCH_REPLACEALL )( 
            IMoeDialogs * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SEARCH_DIALOGTERM )( 
            IMoeDialogs * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_OK )( 
            IMoeDialogs * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_OKCANCEL )( 
            IMoeDialogs * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ABORTRETRYIGNORE )( 
            IMoeDialogs * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_YESNOCANCEL )( 
            IMoeDialogs * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_YESNO )( 
            IMoeDialogs * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_RETRYCANCEL )( 
            IMoeDialogs * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_CANCELTRYCONTINUE )( 
            IMoeDialogs * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ICONERROR )( 
            IMoeDialogs * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ICONQUESTION )( 
            IMoeDialogs * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ICONINFORMATION )( 
            IMoeDialogs * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ICONWARNING )( 
            IMoeDialogs * This,
            /* [retval][out] */ long *d);
        
        END_INTERFACE
    } IMoeDialogsVtbl;

    interface IMoeDialogs
    {
        CONST_VTBL struct IMoeDialogsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMoeDialogs_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMoeDialogs_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMoeDialogs_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMoeDialogs_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMoeDialogs_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMoeDialogs_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMoeDialogs_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMoeDialogs_MsgBox(This,text,title,flags,result)	\
    ( (This)->lpVtbl -> MsgBox(This,text,title,flags,result) ) 

#define IMoeDialogs_Open(This,path,d)	\
    ( (This)->lpVtbl -> Open(This,path,d) ) 

#define IMoeDialogs_OpenDir(This,d)	\
    ( (This)->lpVtbl -> OpenDir(This,d) ) 

#define IMoeDialogs_ChooseFile(This,f)	\
    ( (This)->lpVtbl -> ChooseFile(This,f) ) 

#define IMoeDialogs_ChooseDir(This,d)	\
    ( (This)->lpVtbl -> ChooseDir(This,d) ) 

#define IMoeDialogs_Help(This)	\
    ( (This)->lpVtbl -> Help(This) ) 

#define IMoeDialogs_Print(This)	\
    ( (This)->lpVtbl -> Print(This) ) 

#define IMoeDialogs_get_SEARCH_DOWN(This,d)	\
    ( (This)->lpVtbl -> get_SEARCH_DOWN(This,d) ) 

#define IMoeDialogs_get_SEARCH_WHOLEWORD(This,d)	\
    ( (This)->lpVtbl -> get_SEARCH_WHOLEWORD(This,d) ) 

#define IMoeDialogs_get_SEARCH_MATCHCASE(This,d)	\
    ( (This)->lpVtbl -> get_SEARCH_MATCHCASE(This,d) ) 

#define IMoeDialogs_get_SEARCH_FINDNEXT(This,d)	\
    ( (This)->lpVtbl -> get_SEARCH_FINDNEXT(This,d) ) 

#define IMoeDialogs_get_SEARCH_REPLACE(This,d)	\
    ( (This)->lpVtbl -> get_SEARCH_REPLACE(This,d) ) 

#define IMoeDialogs_get_SEARCH_REPLACEALL(This,d)	\
    ( (This)->lpVtbl -> get_SEARCH_REPLACEALL(This,d) ) 

#define IMoeDialogs_get_SEARCH_DIALOGTERM(This,d)	\
    ( (This)->lpVtbl -> get_SEARCH_DIALOGTERM(This,d) ) 

#define IMoeDialogs_get_OK(This,d)	\
    ( (This)->lpVtbl -> get_OK(This,d) ) 

#define IMoeDialogs_get_OKCANCEL(This,d)	\
    ( (This)->lpVtbl -> get_OKCANCEL(This,d) ) 

#define IMoeDialogs_get_ABORTRETRYIGNORE(This,d)	\
    ( (This)->lpVtbl -> get_ABORTRETRYIGNORE(This,d) ) 

#define IMoeDialogs_get_YESNOCANCEL(This,d)	\
    ( (This)->lpVtbl -> get_YESNOCANCEL(This,d) ) 

#define IMoeDialogs_get_YESNO(This,d)	\
    ( (This)->lpVtbl -> get_YESNO(This,d) ) 

#define IMoeDialogs_get_RETRYCANCEL(This,d)	\
    ( (This)->lpVtbl -> get_RETRYCANCEL(This,d) ) 

#define IMoeDialogs_get_CANCELTRYCONTINUE(This,d)	\
    ( (This)->lpVtbl -> get_CANCELTRYCONTINUE(This,d) ) 

#define IMoeDialogs_get_ICONERROR(This,d)	\
    ( (This)->lpVtbl -> get_ICONERROR(This,d) ) 

#define IMoeDialogs_get_ICONQUESTION(This,d)	\
    ( (This)->lpVtbl -> get_ICONQUESTION(This,d) ) 

#define IMoeDialogs_get_ICONINFORMATION(This,d)	\
    ( (This)->lpVtbl -> get_ICONINFORMATION(This,d) ) 

#define IMoeDialogs_get_ICONWARNING(This,d)	\
    ( (This)->lpVtbl -> get_ICONWARNING(This,d) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMoeDialogs_INTERFACE_DEFINED__ */


#ifndef __IMoeDocumentCollection_INTERFACE_DEFINED__
#define __IMoeDocumentCollection_INTERFACE_DEFINED__

/* interface IMoeDocumentCollection */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IMoeDocumentCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B2FC978E-28F5-49e0-B363-8C78DE7FC50F")
    IMoeDocumentCollection : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE _NewEnum( 
            /* [retval][out] */ IEnumVARIANT **newEnum) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ VARIANT i,
            /* [retval][out] */ IMoeDocument **docItem) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *cnt) = 0;
        
        virtual /* [helpstring][id][requestedit][nonbrowsable][propget] */ HRESULT STDMETHODCALLTYPE get_ActiveDoc( 
            /* [retval][out] */ IMoeDocument **d) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE New( 
            /* [retval][out] */ IMoeDocument **d) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [in] */ BSTR fPath,
            /* [retval][out] */ IMoeDocument **d) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenEncoding( 
            /* [in] */ BSTR fPath,
            /* [in] */ long enc,
            /* [retval][out] */ IMoeDocument **d) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenDir( 
            /* [in] */ BSTR dir,
            /* [retval][out] */ IMoeDocument **d) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenHexEditor( 
            /* [in] */ BSTR f,
            /* [in] */ VARIANT_BOOL vbReadOnly,
            /* [retval][out] */ IMoeDocument **hex) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenHtmlFrame( 
            /* [in] */ BSTR f,
            /* [retval][out] */ IMoeDocument **htmlWnd) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenUserForm( 
            /* [in] */ BSTR pathname,
            /* [retval][out] */ IMoeDocument **form) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE NewUserForm( 
            /* [retval][out] */ IMoeDocument **form) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Activate( 
            /* [in] */ VARIANT i) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveAll( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CloseAll( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ VARIANT index) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Move( 
            /* [in] */ VARIANT what,
            /* [in] */ VARIANT to) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE NewRTFDocument( 
            /* [retval][out] */ IMoeDocument **d) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenTailDocument( 
            /* [in] */ BSTR fPath,
            /* [retval][out] */ IMoeDocument **d) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenRTFDocument( 
            /* [in] */ BSTR fPath,
            /* [retval][out] */ IMoeDocument **d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DOCTYPE_NONE( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DOCTYPE_EDITOR( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DOCTYPE_DIR( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DOCTYPE_PIC( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DOCTYPE_HEX( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DOCTYPE_HTML( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DOCTYPE_OLE( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DOCTYPE_FORM( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DOCTYPE_RTF( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DOCTYPE_TAIL( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DOCTYPE_SFTP( 
            /* [retval][out] */ long *d) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMoeDocumentCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMoeDocumentCollection * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMoeDocumentCollection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMoeDocumentCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMoeDocumentCollection * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMoeDocumentCollection * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMoeDocumentCollection * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMoeDocumentCollection * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *_NewEnum )( 
            IMoeDocumentCollection * This,
            /* [retval][out] */ IEnumVARIANT **newEnum);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            IMoeDocumentCollection * This,
            /* [in] */ VARIANT i,
            /* [retval][out] */ IMoeDocument **docItem);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IMoeDocumentCollection * This,
            /* [retval][out] */ long *cnt);
        
        /* [helpstring][id][requestedit][nonbrowsable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveDoc )( 
            IMoeDocumentCollection * This,
            /* [retval][out] */ IMoeDocument **d);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *New )( 
            IMoeDocumentCollection * This,
            /* [retval][out] */ IMoeDocument **d);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IMoeDocumentCollection * This,
            /* [in] */ BSTR fPath,
            /* [retval][out] */ IMoeDocument **d);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenEncoding )( 
            IMoeDocumentCollection * This,
            /* [in] */ BSTR fPath,
            /* [in] */ long enc,
            /* [retval][out] */ IMoeDocument **d);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenDir )( 
            IMoeDocumentCollection * This,
            /* [in] */ BSTR dir,
            /* [retval][out] */ IMoeDocument **d);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenHexEditor )( 
            IMoeDocumentCollection * This,
            /* [in] */ BSTR f,
            /* [in] */ VARIANT_BOOL vbReadOnly,
            /* [retval][out] */ IMoeDocument **hex);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenHtmlFrame )( 
            IMoeDocumentCollection * This,
            /* [in] */ BSTR f,
            /* [retval][out] */ IMoeDocument **htmlWnd);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenUserForm )( 
            IMoeDocumentCollection * This,
            /* [in] */ BSTR pathname,
            /* [retval][out] */ IMoeDocument **form);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *NewUserForm )( 
            IMoeDocumentCollection * This,
            /* [retval][out] */ IMoeDocument **form);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Activate )( 
            IMoeDocumentCollection * This,
            /* [in] */ VARIANT i);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveAll )( 
            IMoeDocumentCollection * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CloseAll )( 
            IMoeDocumentCollection * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Remove )( 
            IMoeDocumentCollection * This,
            /* [in] */ VARIANT index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Move )( 
            IMoeDocumentCollection * This,
            /* [in] */ VARIANT what,
            /* [in] */ VARIANT to);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *NewRTFDocument )( 
            IMoeDocumentCollection * This,
            /* [retval][out] */ IMoeDocument **d);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenTailDocument )( 
            IMoeDocumentCollection * This,
            /* [in] */ BSTR fPath,
            /* [retval][out] */ IMoeDocument **d);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenRTFDocument )( 
            IMoeDocumentCollection * This,
            /* [in] */ BSTR fPath,
            /* [retval][out] */ IMoeDocument **d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DOCTYPE_NONE )( 
            IMoeDocumentCollection * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DOCTYPE_EDITOR )( 
            IMoeDocumentCollection * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DOCTYPE_DIR )( 
            IMoeDocumentCollection * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DOCTYPE_PIC )( 
            IMoeDocumentCollection * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DOCTYPE_HEX )( 
            IMoeDocumentCollection * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DOCTYPE_HTML )( 
            IMoeDocumentCollection * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DOCTYPE_OLE )( 
            IMoeDocumentCollection * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DOCTYPE_FORM )( 
            IMoeDocumentCollection * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DOCTYPE_RTF )( 
            IMoeDocumentCollection * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DOCTYPE_TAIL )( 
            IMoeDocumentCollection * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DOCTYPE_SFTP )( 
            IMoeDocumentCollection * This,
            /* [retval][out] */ long *d);
        
        END_INTERFACE
    } IMoeDocumentCollectionVtbl;

    interface IMoeDocumentCollection
    {
        CONST_VTBL struct IMoeDocumentCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMoeDocumentCollection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMoeDocumentCollection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMoeDocumentCollection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMoeDocumentCollection_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMoeDocumentCollection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMoeDocumentCollection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMoeDocumentCollection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMoeDocumentCollection__NewEnum(This,newEnum)	\
    ( (This)->lpVtbl -> _NewEnum(This,newEnum) ) 

#define IMoeDocumentCollection_Item(This,i,docItem)	\
    ( (This)->lpVtbl -> Item(This,i,docItem) ) 

#define IMoeDocumentCollection_get_Count(This,cnt)	\
    ( (This)->lpVtbl -> get_Count(This,cnt) ) 

#define IMoeDocumentCollection_get_ActiveDoc(This,d)	\
    ( (This)->lpVtbl -> get_ActiveDoc(This,d) ) 

#define IMoeDocumentCollection_New(This,d)	\
    ( (This)->lpVtbl -> New(This,d) ) 

#define IMoeDocumentCollection_Open(This,fPath,d)	\
    ( (This)->lpVtbl -> Open(This,fPath,d) ) 

#define IMoeDocumentCollection_OpenEncoding(This,fPath,enc,d)	\
    ( (This)->lpVtbl -> OpenEncoding(This,fPath,enc,d) ) 

#define IMoeDocumentCollection_OpenDir(This,dir,d)	\
    ( (This)->lpVtbl -> OpenDir(This,dir,d) ) 

#define IMoeDocumentCollection_OpenHexEditor(This,f,vbReadOnly,hex)	\
    ( (This)->lpVtbl -> OpenHexEditor(This,f,vbReadOnly,hex) ) 

#define IMoeDocumentCollection_OpenHtmlFrame(This,f,htmlWnd)	\
    ( (This)->lpVtbl -> OpenHtmlFrame(This,f,htmlWnd) ) 

#define IMoeDocumentCollection_OpenUserForm(This,pathname,form)	\
    ( (This)->lpVtbl -> OpenUserForm(This,pathname,form) ) 

#define IMoeDocumentCollection_NewUserForm(This,form)	\
    ( (This)->lpVtbl -> NewUserForm(This,form) ) 

#define IMoeDocumentCollection_Activate(This,i)	\
    ( (This)->lpVtbl -> Activate(This,i) ) 

#define IMoeDocumentCollection_SaveAll(This)	\
    ( (This)->lpVtbl -> SaveAll(This) ) 

#define IMoeDocumentCollection_CloseAll(This)	\
    ( (This)->lpVtbl -> CloseAll(This) ) 

#define IMoeDocumentCollection_Remove(This,index)	\
    ( (This)->lpVtbl -> Remove(This,index) ) 

#define IMoeDocumentCollection_Move(This,what,to)	\
    ( (This)->lpVtbl -> Move(This,what,to) ) 

#define IMoeDocumentCollection_NewRTFDocument(This,d)	\
    ( (This)->lpVtbl -> NewRTFDocument(This,d) ) 

#define IMoeDocumentCollection_OpenTailDocument(This,fPath,d)	\
    ( (This)->lpVtbl -> OpenTailDocument(This,fPath,d) ) 

#define IMoeDocumentCollection_OpenRTFDocument(This,fPath,d)	\
    ( (This)->lpVtbl -> OpenRTFDocument(This,fPath,d) ) 

#define IMoeDocumentCollection_get_DOCTYPE_NONE(This,d)	\
    ( (This)->lpVtbl -> get_DOCTYPE_NONE(This,d) ) 

#define IMoeDocumentCollection_get_DOCTYPE_EDITOR(This,d)	\
    ( (This)->lpVtbl -> get_DOCTYPE_EDITOR(This,d) ) 

#define IMoeDocumentCollection_get_DOCTYPE_DIR(This,d)	\
    ( (This)->lpVtbl -> get_DOCTYPE_DIR(This,d) ) 

#define IMoeDocumentCollection_get_DOCTYPE_PIC(This,d)	\
    ( (This)->lpVtbl -> get_DOCTYPE_PIC(This,d) ) 

#define IMoeDocumentCollection_get_DOCTYPE_HEX(This,d)	\
    ( (This)->lpVtbl -> get_DOCTYPE_HEX(This,d) ) 

#define IMoeDocumentCollection_get_DOCTYPE_HTML(This,d)	\
    ( (This)->lpVtbl -> get_DOCTYPE_HTML(This,d) ) 

#define IMoeDocumentCollection_get_DOCTYPE_OLE(This,d)	\
    ( (This)->lpVtbl -> get_DOCTYPE_OLE(This,d) ) 

#define IMoeDocumentCollection_get_DOCTYPE_FORM(This,d)	\
    ( (This)->lpVtbl -> get_DOCTYPE_FORM(This,d) ) 

#define IMoeDocumentCollection_get_DOCTYPE_RTF(This,d)	\
    ( (This)->lpVtbl -> get_DOCTYPE_RTF(This,d) ) 

#define IMoeDocumentCollection_get_DOCTYPE_TAIL(This,d)	\
    ( (This)->lpVtbl -> get_DOCTYPE_TAIL(This,d) ) 

#define IMoeDocumentCollection_get_DOCTYPE_SFTP(This,d)	\
    ( (This)->lpVtbl -> get_DOCTYPE_SFTP(This,d) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMoeDocumentCollection_INTERFACE_DEFINED__ */


#ifndef __IMoeDocument_INTERFACE_DEFINED__
#define __IMoeDocument_INTERFACE_DEFINED__

/* interface IMoeDocument */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IMoeDocument;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F1D065C3-DE27-45c7-A684-C0EECF43AF3E")
    IMoeDocument : public IDispatch
    {
    public:
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Object( 
            /* [retval][out] */ IDispatch **d) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_View( 
            /* [retval][out] */ IMoeDocumentView **d) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_FilePath( 
            /* [retval][out] */ BSTR *dname) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ long *typ) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveAs( 
            /* [in] */ BSTR f) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMoeDocumentVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMoeDocument * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMoeDocument * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMoeDocument * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMoeDocument * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMoeDocument * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMoeDocument * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMoeDocument * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Object )( 
            IMoeDocument * This,
            /* [retval][out] */ IDispatch **d);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_View )( 
            IMoeDocument * This,
            /* [retval][out] */ IMoeDocumentView **d);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FilePath )( 
            IMoeDocument * This,
            /* [retval][out] */ BSTR *dname);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            IMoeDocument * This,
            /* [retval][out] */ long *typ);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IMoeDocument * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveAs )( 
            IMoeDocument * This,
            /* [in] */ BSTR f);
        
        END_INTERFACE
    } IMoeDocumentVtbl;

    interface IMoeDocument
    {
        CONST_VTBL struct IMoeDocumentVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMoeDocument_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMoeDocument_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMoeDocument_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMoeDocument_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMoeDocument_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMoeDocument_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMoeDocument_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMoeDocument_get_Object(This,d)	\
    ( (This)->lpVtbl -> get_Object(This,d) ) 

#define IMoeDocument_get_View(This,d)	\
    ( (This)->lpVtbl -> get_View(This,d) ) 

#define IMoeDocument_get_FilePath(This,dname)	\
    ( (This)->lpVtbl -> get_FilePath(This,dname) ) 

#define IMoeDocument_get_Type(This,typ)	\
    ( (This)->lpVtbl -> get_Type(This,typ) ) 

#define IMoeDocument_Save(This)	\
    ( (This)->lpVtbl -> Save(This) ) 

#define IMoeDocument_SaveAs(This,f)	\
    ( (This)->lpVtbl -> SaveAs(This,f) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMoeDocument_INTERFACE_DEFINED__ */


#ifndef __IMoeDocumentView_INTERFACE_DEFINED__
#define __IMoeDocumentView_INTERFACE_DEFINED__

/* interface IMoeDocumentView */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IMoeDocumentView;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9ADC66FD-13AB-4b52-A92B-5155EA1EF83C")
    IMoeDocumentView : public IDispatch
    {
    public:
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
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Show( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Hide( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Minimize( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Maximize( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Restore( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Activate( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMoeDocumentViewVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMoeDocumentView * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMoeDocumentView * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMoeDocumentView * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMoeDocumentView * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMoeDocumentView * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMoeDocumentView * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMoeDocumentView * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Top )( 
            IMoeDocumentView * This,
            /* [in] */ long t);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Top )( 
            IMoeDocumentView * This,
            /* [retval][out] */ long *t);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Left )( 
            IMoeDocumentView * This,
            /* [in] */ long l);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Left )( 
            IMoeDocumentView * This,
            /* [retval][out] */ long *l);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Height )( 
            IMoeDocumentView * This,
            /* [in] */ long h);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Height )( 
            IMoeDocumentView * This,
            /* [retval][out] */ long *h);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Width )( 
            IMoeDocumentView * This,
            /* [in] */ long w);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Width )( 
            IMoeDocumentView * This,
            /* [retval][out] */ long *w);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Show )( 
            IMoeDocumentView * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Hide )( 
            IMoeDocumentView * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IMoeDocumentView * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Minimize )( 
            IMoeDocumentView * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Maximize )( 
            IMoeDocumentView * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Restore )( 
            IMoeDocumentView * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Activate )( 
            IMoeDocumentView * This);
        
        END_INTERFACE
    } IMoeDocumentViewVtbl;

    interface IMoeDocumentView
    {
        CONST_VTBL struct IMoeDocumentViewVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMoeDocumentView_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMoeDocumentView_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMoeDocumentView_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMoeDocumentView_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMoeDocumentView_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMoeDocumentView_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMoeDocumentView_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMoeDocumentView_put_Top(This,t)	\
    ( (This)->lpVtbl -> put_Top(This,t) ) 

#define IMoeDocumentView_get_Top(This,t)	\
    ( (This)->lpVtbl -> get_Top(This,t) ) 

#define IMoeDocumentView_put_Left(This,l)	\
    ( (This)->lpVtbl -> put_Left(This,l) ) 

#define IMoeDocumentView_get_Left(This,l)	\
    ( (This)->lpVtbl -> get_Left(This,l) ) 

#define IMoeDocumentView_put_Height(This,h)	\
    ( (This)->lpVtbl -> put_Height(This,h) ) 

#define IMoeDocumentView_get_Height(This,h)	\
    ( (This)->lpVtbl -> get_Height(This,h) ) 

#define IMoeDocumentView_put_Width(This,w)	\
    ( (This)->lpVtbl -> put_Width(This,w) ) 

#define IMoeDocumentView_get_Width(This,w)	\
    ( (This)->lpVtbl -> get_Width(This,w) ) 

#define IMoeDocumentView_Show(This)	\
    ( (This)->lpVtbl -> Show(This) ) 

#define IMoeDocumentView_Hide(This)	\
    ( (This)->lpVtbl -> Hide(This) ) 

#define IMoeDocumentView_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IMoeDocumentView_Minimize(This)	\
    ( (This)->lpVtbl -> Minimize(This) ) 

#define IMoeDocumentView_Maximize(This)	\
    ( (This)->lpVtbl -> Maximize(This) ) 

#define IMoeDocumentView_Restore(This)	\
    ( (This)->lpVtbl -> Restore(This) ) 

#define IMoeDocumentView_Activate(This)	\
    ( (This)->lpVtbl -> Activate(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMoeDocumentView_INTERFACE_DEFINED__ */


#ifndef __IMoeHtmlFrame_INTERFACE_DEFINED__
#define __IMoeHtmlFrame_INTERFACE_DEFINED__

/* interface IMoeHtmlFrame */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IMoeHtmlFrame;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("08B6F80E-72E9-4a97-8672-926F8D7BEEC0")
    IMoeHtmlFrame : public IDispatch
    {
    public:
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Object( 
            /* [retval][out] */ IDispatch **d) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_View( 
            /* [retval][out] */ IMoeDialogView **d) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Scripts( 
            /* [retval][out] */ IDispatch **s) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Eval( 
            /* [in] */ BSTR src,
            /* [in] */ BSTR scriptLanguage) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OleCmd( 
            /* [in] */ long cmd) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget][helpstring] */ HRESULT STDMETHODCALLTYPE get_FilePath( 
            /* [retval][out] */ BSTR *filename) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMoeHtmlFrameVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMoeHtmlFrame * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMoeHtmlFrame * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMoeHtmlFrame * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMoeHtmlFrame * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMoeHtmlFrame * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMoeHtmlFrame * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMoeHtmlFrame * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Object )( 
            IMoeHtmlFrame * This,
            /* [retval][out] */ IDispatch **d);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_View )( 
            IMoeHtmlFrame * This,
            /* [retval][out] */ IMoeDialogView **d);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Scripts )( 
            IMoeHtmlFrame * This,
            /* [retval][out] */ IDispatch **s);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Eval )( 
            IMoeHtmlFrame * This,
            /* [in] */ BSTR src,
            /* [in] */ BSTR scriptLanguage);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OleCmd )( 
            IMoeHtmlFrame * This,
            /* [in] */ long cmd);
        
        /* [id][requestedit][displaybind][bindable][propget][helpstring] */ HRESULT ( STDMETHODCALLTYPE *get_FilePath )( 
            IMoeHtmlFrame * This,
            /* [retval][out] */ BSTR *filename);
        
        END_INTERFACE
    } IMoeHtmlFrameVtbl;

    interface IMoeHtmlFrame
    {
        CONST_VTBL struct IMoeHtmlFrameVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMoeHtmlFrame_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMoeHtmlFrame_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMoeHtmlFrame_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMoeHtmlFrame_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMoeHtmlFrame_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMoeHtmlFrame_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMoeHtmlFrame_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMoeHtmlFrame_get_Object(This,d)	\
    ( (This)->lpVtbl -> get_Object(This,d) ) 

#define IMoeHtmlFrame_get_View(This,d)	\
    ( (This)->lpVtbl -> get_View(This,d) ) 

#define IMoeHtmlFrame_get_Scripts(This,s)	\
    ( (This)->lpVtbl -> get_Scripts(This,s) ) 

#define IMoeHtmlFrame_Eval(This,src,scriptLanguage)	\
    ( (This)->lpVtbl -> Eval(This,src,scriptLanguage) ) 

#define IMoeHtmlFrame_OleCmd(This,cmd)	\
    ( (This)->lpVtbl -> OleCmd(This,cmd) ) 

#define IMoeHtmlFrame_get_FilePath(This,filename)	\
    ( (This)->lpVtbl -> get_FilePath(This,filename) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMoeHtmlFrame_INTERFACE_DEFINED__ */


#ifndef __IMoeDialogView_INTERFACE_DEFINED__
#define __IMoeDialogView_INTERFACE_DEFINED__

/* interface IMoeDialogView */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IMoeDialogView;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("54E27AFE-3872-481c-968F-20BF61B19496")
    IMoeDialogView : public IDispatch
    {
    public:
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
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Show( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Hide( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Title( 
            /* [in] */ BSTR t) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Title( 
            /* [retval][out] */ BSTR *t) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMoeDialogViewVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMoeDialogView * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMoeDialogView * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMoeDialogView * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMoeDialogView * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMoeDialogView * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMoeDialogView * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMoeDialogView * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Top )( 
            IMoeDialogView * This,
            /* [in] */ long t);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Top )( 
            IMoeDialogView * This,
            /* [retval][out] */ long *t);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Left )( 
            IMoeDialogView * This,
            /* [in] */ long l);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Left )( 
            IMoeDialogView * This,
            /* [retval][out] */ long *l);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Height )( 
            IMoeDialogView * This,
            /* [in] */ long h);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Height )( 
            IMoeDialogView * This,
            /* [retval][out] */ long *h);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Width )( 
            IMoeDialogView * This,
            /* [in] */ long w);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Width )( 
            IMoeDialogView * This,
            /* [retval][out] */ long *w);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Show )( 
            IMoeDialogView * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Hide )( 
            IMoeDialogView * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IMoeDialogView * This);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Title )( 
            IMoeDialogView * This,
            /* [in] */ BSTR t);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Title )( 
            IMoeDialogView * This,
            /* [retval][out] */ BSTR *t);
        
        END_INTERFACE
    } IMoeDialogViewVtbl;

    interface IMoeDialogView
    {
        CONST_VTBL struct IMoeDialogViewVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMoeDialogView_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMoeDialogView_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMoeDialogView_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMoeDialogView_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMoeDialogView_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMoeDialogView_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMoeDialogView_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMoeDialogView_put_Top(This,t)	\
    ( (This)->lpVtbl -> put_Top(This,t) ) 

#define IMoeDialogView_get_Top(This,t)	\
    ( (This)->lpVtbl -> get_Top(This,t) ) 

#define IMoeDialogView_put_Left(This,l)	\
    ( (This)->lpVtbl -> put_Left(This,l) ) 

#define IMoeDialogView_get_Left(This,l)	\
    ( (This)->lpVtbl -> get_Left(This,l) ) 

#define IMoeDialogView_put_Height(This,h)	\
    ( (This)->lpVtbl -> put_Height(This,h) ) 

#define IMoeDialogView_get_Height(This,h)	\
    ( (This)->lpVtbl -> get_Height(This,h) ) 

#define IMoeDialogView_put_Width(This,w)	\
    ( (This)->lpVtbl -> put_Width(This,w) ) 

#define IMoeDialogView_get_Width(This,w)	\
    ( (This)->lpVtbl -> get_Width(This,w) ) 

#define IMoeDialogView_Show(This)	\
    ( (This)->lpVtbl -> Show(This) ) 

#define IMoeDialogView_Hide(This)	\
    ( (This)->lpVtbl -> Hide(This) ) 

#define IMoeDialogView_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IMoeDialogView_put_Title(This,t)	\
    ( (This)->lpVtbl -> put_Title(This,t) ) 

#define IMoeDialogView_get_Title(This,t)	\
    ( (This)->lpVtbl -> get_Title(This,t) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMoeDialogView_INTERFACE_DEFINED__ */


#ifndef __IMoeRichText_INTERFACE_DEFINED__
#define __IMoeRichText_INTERFACE_DEFINED__

/* interface IMoeRichText */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IMoeRichText;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B1BA1196-9BA2-44EE-A444-FEFC4EFD2950")
    IMoeRichText : public IDispatch
    {
    public:
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Text( 
            /* [retval][out] */ IDispatch **d) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Length( 
            /* [retval][out] */ long *d) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Range( 
            /* [in] */ long start,
            /* [in] */ long end,
            /* [retval][out] */ IDispatch **d) = 0;
        
        virtual /* [helpstring][id][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Selection( 
            /* [retval][out] */ IDispatch **d) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMoeRichTextVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMoeRichText * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMoeRichText * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMoeRichText * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMoeRichText * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMoeRichText * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMoeRichText * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMoeRichText * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Text )( 
            IMoeRichText * This,
            /* [retval][out] */ IDispatch **d);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Length )( 
            IMoeRichText * This,
            /* [retval][out] */ long *d);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Range )( 
            IMoeRichText * This,
            /* [in] */ long start,
            /* [in] */ long end,
            /* [retval][out] */ IDispatch **d);
        
        /* [helpstring][id][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Selection )( 
            IMoeRichText * This,
            /* [retval][out] */ IDispatch **d);
        
        END_INTERFACE
    } IMoeRichTextVtbl;

    interface IMoeRichText
    {
        CONST_VTBL struct IMoeRichTextVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMoeRichText_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMoeRichText_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMoeRichText_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMoeRichText_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMoeRichText_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMoeRichText_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMoeRichText_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMoeRichText_get_Text(This,d)	\
    ( (This)->lpVtbl -> get_Text(This,d) ) 

#define IMoeRichText_get_Length(This,d)	\
    ( (This)->lpVtbl -> get_Length(This,d) ) 

#define IMoeRichText_Range(This,start,end,d)	\
    ( (This)->lpVtbl -> Range(This,start,end,d) ) 

#define IMoeRichText_get_Selection(This,d)	\
    ( (This)->lpVtbl -> get_Selection(This,d) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMoeRichText_INTERFACE_DEFINED__ */


#ifndef __IMoeUserForm_INTERFACE_DEFINED__
#define __IMoeUserForm_INTERFACE_DEFINED__

/* interface IMoeUserForm */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IMoeUserForm;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0DFFAACE-906D-4545-853A-BEE593283BDB")
    IMoeUserForm : public IDispatch
    {
    public:
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Object( 
            /* [retval][out] */ IDispatch **d) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_View( 
            /* [retval][out] */ IMoeDialogView **d) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Script( 
            /* [retval][out] */ IDispatch **s) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Show( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Hide( void) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_FilePath( 
            /* [retval][out] */ BSTR *filename) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMoeUserFormVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMoeUserForm * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMoeUserForm * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMoeUserForm * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMoeUserForm * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMoeUserForm * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMoeUserForm * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMoeUserForm * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Object )( 
            IMoeUserForm * This,
            /* [retval][out] */ IDispatch **d);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_View )( 
            IMoeUserForm * This,
            /* [retval][out] */ IMoeDialogView **d);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Script )( 
            IMoeUserForm * This,
            /* [retval][out] */ IDispatch **s);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Show )( 
            IMoeUserForm * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IMoeUserForm * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Hide )( 
            IMoeUserForm * This);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FilePath )( 
            IMoeUserForm * This,
            /* [retval][out] */ BSTR *filename);
        
        END_INTERFACE
    } IMoeUserFormVtbl;

    interface IMoeUserForm
    {
        CONST_VTBL struct IMoeUserFormVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMoeUserForm_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMoeUserForm_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMoeUserForm_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMoeUserForm_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMoeUserForm_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMoeUserForm_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMoeUserForm_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMoeUserForm_get_Object(This,d)	\
    ( (This)->lpVtbl -> get_Object(This,d) ) 

#define IMoeUserForm_get_View(This,d)	\
    ( (This)->lpVtbl -> get_View(This,d) ) 

#define IMoeUserForm_get_Script(This,s)	\
    ( (This)->lpVtbl -> get_Script(This,s) ) 

#define IMoeUserForm_Show(This)	\
    ( (This)->lpVtbl -> Show(This) ) 

#define IMoeUserForm_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IMoeUserForm_Hide(This)	\
    ( (This)->lpVtbl -> Hide(This) ) 

#define IMoeUserForm_get_FilePath(This,filename)	\
    ( (This)->lpVtbl -> get_FilePath(This,filename) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMoeUserForm_INTERFACE_DEFINED__ */


#ifndef __IExternalMoe_INTERFACE_DEFINED__
#define __IExternalMoe_INTERFACE_DEFINED__

/* interface IExternalMoe */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IExternalMoe;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FC03A505-B887-4653-8710-B0AB66674F96")
    IExternalMoe : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Moe( 
            /* [retval][out] */ IMoe **m) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Frame( 
            /* [retval][out] */ IMoeHtmlFrame **f) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
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
            /* [retval][out] */ IMoe **m);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Frame )( 
            IExternalMoe * This,
            /* [retval][out] */ IMoeHtmlFrame **f);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IExternalMoe * This);
        
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

#define IExternalMoe_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IExternalMoe_INTERFACE_DEFINED__ */


#ifndef __IMoeImport_INTERFACE_DEFINED__
#define __IMoeImport_INTERFACE_DEFINED__

/* interface IMoeImport */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IMoeImport;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4447A58A-26E6-43E0-851E-0823C1E79CF8")
    IMoeImport : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Import( 
            BSTR filename) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMoeImportVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMoeImport * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMoeImport * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMoeImport * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMoeImport * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMoeImport * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMoeImport * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMoeImport * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Import )( 
            IMoeImport * This,
            BSTR filename);
        
        END_INTERFACE
    } IMoeImportVtbl;

    interface IMoeImport
    {
        CONST_VTBL struct IMoeImportVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMoeImport_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMoeImport_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMoeImport_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMoeImport_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMoeImport_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMoeImport_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMoeImport_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMoeImport_Import(This,filename)	\
    ( (This)->lpVtbl -> Import(This,filename) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMoeImport_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Application;

#ifdef __cplusplus

class DECLSPEC_UUID("FABA1705-8E2D-48d2-AE3C-333FEECA3FBC")
Application;
#endif
#endif /* __Moe_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


