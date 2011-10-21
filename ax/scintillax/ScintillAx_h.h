

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Fri Oct 21 20:05:32 2011
 */
/* Compiler settings for ScintillAX.idl:
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

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ScintillAx_h_h__
#define __ScintillAx_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IScintillAxDispose_FWD_DEFINED__
#define __IScintillAxDispose_FWD_DEFINED__
typedef interface IScintillAxDispose IScintillAxDispose;
#endif 	/* __IScintillAxDispose_FWD_DEFINED__ */


#ifndef __IScintillAxProperties_FWD_DEFINED__
#define __IScintillAxProperties_FWD_DEFINED__
typedef interface IScintillAxProperties IScintillAxProperties;
#endif 	/* __IScintillAxProperties_FWD_DEFINED__ */


#ifndef __IScintillAxText_FWD_DEFINED__
#define __IScintillAxText_FWD_DEFINED__
typedef interface IScintillAxText IScintillAxText;
#endif 	/* __IScintillAxText_FWD_DEFINED__ */


#ifndef __IScintillAxPosition_FWD_DEFINED__
#define __IScintillAxPosition_FWD_DEFINED__
typedef interface IScintillAxPosition IScintillAxPosition;
#endif 	/* __IScintillAxPosition_FWD_DEFINED__ */


#ifndef __IScintillAxSelection_FWD_DEFINED__
#define __IScintillAxSelection_FWD_DEFINED__
typedef interface IScintillAxSelection IScintillAxSelection;
#endif 	/* __IScintillAxSelection_FWD_DEFINED__ */


#ifndef __IScintillAxLine_FWD_DEFINED__
#define __IScintillAxLine_FWD_DEFINED__
typedef interface IScintillAxLine IScintillAxLine;
#endif 	/* __IScintillAxLine_FWD_DEFINED__ */


#ifndef __IScintillAxAnnotation_FWD_DEFINED__
#define __IScintillAxAnnotation_FWD_DEFINED__
typedef interface IScintillAxAnnotation IScintillAxAnnotation;
#endif 	/* __IScintillAxAnnotation_FWD_DEFINED__ */


#ifndef __IScintillAxMarkers_FWD_DEFINED__
#define __IScintillAxMarkers_FWD_DEFINED__
typedef interface IScintillAxMarkers IScintillAxMarkers;
#endif 	/* __IScintillAxMarkers_FWD_DEFINED__ */


#ifndef __IScintillAx_FWD_DEFINED__
#define __IScintillAx_FWD_DEFINED__
typedef interface IScintillAx IScintillAx;
#endif 	/* __IScintillAx_FWD_DEFINED__ */


#ifndef ___IScintillAxEvents_FWD_DEFINED__
#define ___IScintillAxEvents_FWD_DEFINED__
typedef interface _IScintillAxEvents _IScintillAxEvents;
#endif 	/* ___IScintillAxEvents_FWD_DEFINED__ */


#ifndef __IScintillAxEvents_FWD_DEFINED__
#define __IScintillAxEvents_FWD_DEFINED__
typedef interface IScintillAxEvents IScintillAxEvents;
#endif 	/* __IScintillAxEvents_FWD_DEFINED__ */


#ifndef __ScintillAx_FWD_DEFINED__
#define __ScintillAx_FWD_DEFINED__

#ifdef __cplusplus
typedef class ScintillAx ScintillAx;
#else
typedef struct ScintillAx ScintillAx;
#endif /* __cplusplus */

#endif 	/* __ScintillAx_FWD_DEFINED__ */


#ifndef __ScintillAxProperties_FWD_DEFINED__
#define __ScintillAxProperties_FWD_DEFINED__

#ifdef __cplusplus
typedef class ScintillAxProperties ScintillAxProperties;
#else
typedef struct ScintillAxProperties ScintillAxProperties;
#endif /* __cplusplus */

#endif 	/* __ScintillAxProperties_FWD_DEFINED__ */


#ifndef __ScintillAxSettings_FWD_DEFINED__
#define __ScintillAxSettings_FWD_DEFINED__

#ifdef __cplusplus
typedef class ScintillAxSettings ScintillAxSettings;
#else
typedef struct ScintillAxSettings ScintillAxSettings;
#endif /* __cplusplus */

#endif 	/* __ScintillAxSettings_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IScintillAxDispose_INTERFACE_DEFINED__
#define __IScintillAxDispose_INTERFACE_DEFINED__

/* interface IScintillAxDispose */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_IScintillAxDispose;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("87084618-4FF1-4AF1-9098-7D679C6C0B86")
    IScintillAxDispose : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Dispose( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IScintillAxDisposeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IScintillAxDispose * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IScintillAxDispose * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IScintillAxDispose * This);
        
        HRESULT ( STDMETHODCALLTYPE *Dispose )( 
            IScintillAxDispose * This);
        
        END_INTERFACE
    } IScintillAxDisposeVtbl;

    interface IScintillAxDispose
    {
        CONST_VTBL struct IScintillAxDisposeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScintillAxDispose_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IScintillAxDispose_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IScintillAxDispose_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IScintillAxDispose_Dispose(This)	\
    ( (This)->lpVtbl -> Dispose(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IScintillAxDispose_INTERFACE_DEFINED__ */



#ifndef __Scintilla_LIBRARY_DEFINED__
#define __Scintilla_LIBRARY_DEFINED__

/* library Scintilla */
/* [helpstring][version][uuid] */ 


enum SCINTILLA_SYSTYPE
    {	SCINTILLA_SYSTYPE_UNIX	= 0,
	SCINTILLA_SYSTYPE_WIN32	= 1
    } ;

enum SCINTILLA_ENCODING
    {	SCINTILLA_ENCODING_ANSI	= 0,
	SCINTILLA_ENCODING_UTF8	= 65001,
	SCINTILLA_ENCODING_UTF16	= 1200
    } ;

enum SCINTILLA_SYNTAX
    {	SCINTILLA_SYNTAX_PLAIN	= 0,
	SCINTILLA_SYNTAX_HTML	= 1,
	SCINTILLA_SYNTAX_CSS	= 2,
	SCINTILLA_SYNTAX_VB	= 3,
	SCINTILLA_SYNTAX_JS	= 4,
	SCINTILLA_SYNTAX_SQL	= 5,
	SCINTILLA_SYNTAX_SHELL	= 6,
	SCINTILLA_SYNTAX_PERL	= 7,
	SCINTILLA_SYNTAX_CPP	= 8,
	SCINTILLA_SYNTAX_JAVA	= 9,
	SCINTILLA_SYNTAX_CSHARP	= 10
    } ;









EXTERN_C const IID LIBID_Scintilla;

#ifndef __IScintillAxProperties_INTERFACE_DEFINED__
#define __IScintillAxProperties_INTERFACE_DEFINED__

/* interface IScintillAxProperties */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IScintillAxProperties;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("65BC59C3-3E46-4F80-8B4A-13AADF1A58EB")
    IScintillAxProperties : public IDispatch
    {
    public:
        virtual /* [helpstring][id][requestedit][bindable][propputref] */ HRESULT STDMETHODCALLTYPE putref_Font( 
            /* [in] */ IFontDisp *fnt) = 0;
        
        virtual /* [id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Font( 
            /* [in] */ IFontDisp *fnt) = 0;
        
        virtual /* [id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Font( 
            /* [retval][out] */ IFontDisp **fnt) = 0;
        
        virtual /* [helpstring][id][requestedit][defaultbind][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Filename( 
            /* [in] */ BSTR fname) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Filename( 
            /* [retval][out] */ BSTR *fname) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_ReadOnly( 
            /* [in] */ VARIANT_BOOL vbReadOnly) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_ReadOnly( 
            /* [retval][out] */ VARIANT_BOOL *vbReadOnly) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Syntax( 
            /* [in] */ long typ) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Syntax( 
            /* [retval][out] */ long *typ) = 0;
        
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
            /* [in] */ long width) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_TabWidth( 
            /* [retval][out] */ long *w) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Overtype( 
            /* [in] */ VARIANT_BOOL over_type) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Overtype( 
            /* [retval][out] */ VARIANT_BOOL *over_type) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_UseContext( 
            /* [in] */ VARIANT_BOOL useMenu) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_UseContext( 
            /* [retval][out] */ VARIANT_BOOL *useMenu) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_WriteBOM( 
            /* [in] */ VARIANT_BOOL vb) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_WriteBOM( 
            /* [retval][out] */ VARIANT_BOOL *vb) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_ShowLineNumbers( 
            /* [in] */ VARIANT_BOOL useLineNums) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_ShowLineNumbers( 
            /* [retval][out] */ VARIANT_BOOL *useLineNums) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SyntaxDisplayName( 
            /* [retval][out] */ BSTR *syntax) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSyntaxDisplayName( 
            /* [in] */ long type,
            /* [retval][out] */ BSTR *syntax) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetIndent( 
            /* [in] */ long i) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ConvertTabs( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IScintillAxPropertiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IScintillAxProperties * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IScintillAxProperties * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IScintillAxProperties * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IScintillAxProperties * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IScintillAxProperties * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IScintillAxProperties * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IScintillAxProperties * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][requestedit][bindable][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_Font )( 
            IScintillAxProperties * This,
            /* [in] */ IFontDisp *fnt);
        
        /* [id][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Font )( 
            IScintillAxProperties * This,
            /* [in] */ IFontDisp *fnt);
        
        /* [id][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Font )( 
            IScintillAxProperties * This,
            /* [retval][out] */ IFontDisp **fnt);
        
        /* [helpstring][id][requestedit][defaultbind][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Filename )( 
            IScintillAxProperties * This,
            /* [in] */ BSTR fname);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Filename )( 
            IScintillAxProperties * This,
            /* [retval][out] */ BSTR *fname);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ReadOnly )( 
            IScintillAxProperties * This,
            /* [in] */ VARIANT_BOOL vbReadOnly);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ReadOnly )( 
            IScintillAxProperties * This,
            /* [retval][out] */ VARIANT_BOOL *vbReadOnly);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Syntax )( 
            IScintillAxProperties * This,
            /* [in] */ long typ);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Syntax )( 
            IScintillAxProperties * This,
            /* [retval][out] */ long *typ);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SysType )( 
            IScintillAxProperties * This,
            /* [in] */ long typ);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SysType )( 
            IScintillAxProperties * This,
            /* [retval][out] */ long *typ);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Encoding )( 
            IScintillAxProperties * This,
            /* [in] */ long typ);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Encoding )( 
            IScintillAxProperties * This,
            /* [retval][out] */ long *typ);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TabUsage )( 
            IScintillAxProperties * This,
            /* [in] */ VARIANT_BOOL vbTabUsage);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TabUsage )( 
            IScintillAxProperties * This,
            /* [retval][out] */ VARIANT_BOOL *vbTabUsage);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TabIndents )( 
            IScintillAxProperties * This,
            /* [in] */ VARIANT_BOOL vbTabIndents);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TabIndents )( 
            IScintillAxProperties * This,
            /* [retval][out] */ VARIANT_BOOL *vbTabIndents);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BackSpaceUnindents )( 
            IScintillAxProperties * This,
            /* [in] */ VARIANT_BOOL vbBackSpaceIndents);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BackSpaceUnindents )( 
            IScintillAxProperties * This,
            /* [retval][out] */ VARIANT_BOOL *vbBackSpaceIndents);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TabWidth )( 
            IScintillAxProperties * This,
            /* [in] */ long width);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TabWidth )( 
            IScintillAxProperties * This,
            /* [retval][out] */ long *w);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Overtype )( 
            IScintillAxProperties * This,
            /* [in] */ VARIANT_BOOL over_type);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Overtype )( 
            IScintillAxProperties * This,
            /* [retval][out] */ VARIANT_BOOL *over_type);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseContext )( 
            IScintillAxProperties * This,
            /* [in] */ VARIANT_BOOL useMenu);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseContext )( 
            IScintillAxProperties * This,
            /* [retval][out] */ VARIANT_BOOL *useMenu);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_WriteBOM )( 
            IScintillAxProperties * This,
            /* [in] */ VARIANT_BOOL vb);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_WriteBOM )( 
            IScintillAxProperties * This,
            /* [retval][out] */ VARIANT_BOOL *vb);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ShowLineNumbers )( 
            IScintillAxProperties * This,
            /* [in] */ VARIANT_BOOL useLineNums);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ShowLineNumbers )( 
            IScintillAxProperties * This,
            /* [retval][out] */ VARIANT_BOOL *useLineNums);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SyntaxDisplayName )( 
            IScintillAxProperties * This,
            /* [retval][out] */ BSTR *syntax);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSyntaxDisplayName )( 
            IScintillAxProperties * This,
            /* [in] */ long type,
            /* [retval][out] */ BSTR *syntax);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetIndent )( 
            IScintillAxProperties * This,
            /* [in] */ long i);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ConvertTabs )( 
            IScintillAxProperties * This);
        
        END_INTERFACE
    } IScintillAxPropertiesVtbl;

    interface IScintillAxProperties
    {
        CONST_VTBL struct IScintillAxPropertiesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScintillAxProperties_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IScintillAxProperties_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IScintillAxProperties_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IScintillAxProperties_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IScintillAxProperties_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IScintillAxProperties_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IScintillAxProperties_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IScintillAxProperties_putref_Font(This,fnt)	\
    ( (This)->lpVtbl -> putref_Font(This,fnt) ) 

#define IScintillAxProperties_put_Font(This,fnt)	\
    ( (This)->lpVtbl -> put_Font(This,fnt) ) 

#define IScintillAxProperties_get_Font(This,fnt)	\
    ( (This)->lpVtbl -> get_Font(This,fnt) ) 

#define IScintillAxProperties_put_Filename(This,fname)	\
    ( (This)->lpVtbl -> put_Filename(This,fname) ) 

#define IScintillAxProperties_get_Filename(This,fname)	\
    ( (This)->lpVtbl -> get_Filename(This,fname) ) 

#define IScintillAxProperties_put_ReadOnly(This,vbReadOnly)	\
    ( (This)->lpVtbl -> put_ReadOnly(This,vbReadOnly) ) 

#define IScintillAxProperties_get_ReadOnly(This,vbReadOnly)	\
    ( (This)->lpVtbl -> get_ReadOnly(This,vbReadOnly) ) 

#define IScintillAxProperties_put_Syntax(This,typ)	\
    ( (This)->lpVtbl -> put_Syntax(This,typ) ) 

#define IScintillAxProperties_get_Syntax(This,typ)	\
    ( (This)->lpVtbl -> get_Syntax(This,typ) ) 

#define IScintillAxProperties_put_SysType(This,typ)	\
    ( (This)->lpVtbl -> put_SysType(This,typ) ) 

#define IScintillAxProperties_get_SysType(This,typ)	\
    ( (This)->lpVtbl -> get_SysType(This,typ) ) 

#define IScintillAxProperties_put_Encoding(This,typ)	\
    ( (This)->lpVtbl -> put_Encoding(This,typ) ) 

#define IScintillAxProperties_get_Encoding(This,typ)	\
    ( (This)->lpVtbl -> get_Encoding(This,typ) ) 

#define IScintillAxProperties_put_TabUsage(This,vbTabUsage)	\
    ( (This)->lpVtbl -> put_TabUsage(This,vbTabUsage) ) 

#define IScintillAxProperties_get_TabUsage(This,vbTabUsage)	\
    ( (This)->lpVtbl -> get_TabUsage(This,vbTabUsage) ) 

#define IScintillAxProperties_put_TabIndents(This,vbTabIndents)	\
    ( (This)->lpVtbl -> put_TabIndents(This,vbTabIndents) ) 

#define IScintillAxProperties_get_TabIndents(This,vbTabIndents)	\
    ( (This)->lpVtbl -> get_TabIndents(This,vbTabIndents) ) 

#define IScintillAxProperties_put_BackSpaceUnindents(This,vbBackSpaceIndents)	\
    ( (This)->lpVtbl -> put_BackSpaceUnindents(This,vbBackSpaceIndents) ) 

#define IScintillAxProperties_get_BackSpaceUnindents(This,vbBackSpaceIndents)	\
    ( (This)->lpVtbl -> get_BackSpaceUnindents(This,vbBackSpaceIndents) ) 

#define IScintillAxProperties_put_TabWidth(This,width)	\
    ( (This)->lpVtbl -> put_TabWidth(This,width) ) 

#define IScintillAxProperties_get_TabWidth(This,w)	\
    ( (This)->lpVtbl -> get_TabWidth(This,w) ) 

#define IScintillAxProperties_put_Overtype(This,over_type)	\
    ( (This)->lpVtbl -> put_Overtype(This,over_type) ) 

#define IScintillAxProperties_get_Overtype(This,over_type)	\
    ( (This)->lpVtbl -> get_Overtype(This,over_type) ) 

#define IScintillAxProperties_put_UseContext(This,useMenu)	\
    ( (This)->lpVtbl -> put_UseContext(This,useMenu) ) 

#define IScintillAxProperties_get_UseContext(This,useMenu)	\
    ( (This)->lpVtbl -> get_UseContext(This,useMenu) ) 

#define IScintillAxProperties_put_WriteBOM(This,vb)	\
    ( (This)->lpVtbl -> put_WriteBOM(This,vb) ) 

#define IScintillAxProperties_get_WriteBOM(This,vb)	\
    ( (This)->lpVtbl -> get_WriteBOM(This,vb) ) 

#define IScintillAxProperties_put_ShowLineNumbers(This,useLineNums)	\
    ( (This)->lpVtbl -> put_ShowLineNumbers(This,useLineNums) ) 

#define IScintillAxProperties_get_ShowLineNumbers(This,useLineNums)	\
    ( (This)->lpVtbl -> get_ShowLineNumbers(This,useLineNums) ) 

#define IScintillAxProperties_SyntaxDisplayName(This,syntax)	\
    ( (This)->lpVtbl -> SyntaxDisplayName(This,syntax) ) 

#define IScintillAxProperties_GetSyntaxDisplayName(This,type,syntax)	\
    ( (This)->lpVtbl -> GetSyntaxDisplayName(This,type,syntax) ) 

#define IScintillAxProperties_SetIndent(This,i)	\
    ( (This)->lpVtbl -> SetIndent(This,i) ) 

#define IScintillAxProperties_ConvertTabs(This)	\
    ( (This)->lpVtbl -> ConvertTabs(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IScintillAxProperties_INTERFACE_DEFINED__ */


#ifndef __IScintillAxText_INTERFACE_DEFINED__
#define __IScintillAxText_INTERFACE_DEFINED__

/* interface IScintillAxText */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IScintillAxText;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A479AEBD-ED80-4451-8C83-8E422EBC20A1")
    IScintillAxText : public IDispatch
    {
    public:
        virtual /* [helpstring][id][requestedit][defaultbind][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Value( 
            /* [in] */ BSTR txt) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [retval][out] */ BSTR *txt) = 0;
        
        virtual /* [helpstring][id][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Modified( 
            /* [retval][out] */ VARIANT_BOOL *vbModified) = 0;
        
        virtual /* [helpstring][id][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Length( 
            /* [retval][out] */ long *len) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetText( 
            /* [in] */ BSTR txt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetText( 
            /* [retval][out] */ BSTR *txt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetTextRange( 
            /* [in] */ long pStart,
            /* [in] */ long pEnd,
            /* [retval][out] */ BSTR *rng) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Append( 
            /* [in] */ BSTR txt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Insert( 
            /* [in] */ BSTR txt,
            /* [in] */ long p) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Search( 
            /* [in] */ BSTR sWhat,
            /* [in] */ long lFlags,
            /* [retval][out] */ VARIANT_BOOL *vbFound) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Replace( 
            /* [in] */ BSTR sWhat,
            /* [in] */ BSTR w,
            /* [in] */ long lFlags,
            /* [retval][out] */ VARIANT_BOOL *vbReplaced) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IScintillAxTextVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IScintillAxText * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IScintillAxText * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IScintillAxText * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IScintillAxText * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IScintillAxText * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IScintillAxText * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IScintillAxText * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][requestedit][defaultbind][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Value )( 
            IScintillAxText * This,
            /* [in] */ BSTR txt);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            IScintillAxText * This,
            /* [retval][out] */ BSTR *txt);
        
        /* [helpstring][id][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Modified )( 
            IScintillAxText * This,
            /* [retval][out] */ VARIANT_BOOL *vbModified);
        
        /* [helpstring][id][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Length )( 
            IScintillAxText * This,
            /* [retval][out] */ long *len);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetText )( 
            IScintillAxText * This,
            /* [in] */ BSTR txt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetText )( 
            IScintillAxText * This,
            /* [retval][out] */ BSTR *txt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetTextRange )( 
            IScintillAxText * This,
            /* [in] */ long pStart,
            /* [in] */ long pEnd,
            /* [retval][out] */ BSTR *rng);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Append )( 
            IScintillAxText * This,
            /* [in] */ BSTR txt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Insert )( 
            IScintillAxText * This,
            /* [in] */ BSTR txt,
            /* [in] */ long p);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Search )( 
            IScintillAxText * This,
            /* [in] */ BSTR sWhat,
            /* [in] */ long lFlags,
            /* [retval][out] */ VARIANT_BOOL *vbFound);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Replace )( 
            IScintillAxText * This,
            /* [in] */ BSTR sWhat,
            /* [in] */ BSTR w,
            /* [in] */ long lFlags,
            /* [retval][out] */ VARIANT_BOOL *vbReplaced);
        
        END_INTERFACE
    } IScintillAxTextVtbl;

    interface IScintillAxText
    {
        CONST_VTBL struct IScintillAxTextVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScintillAxText_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IScintillAxText_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IScintillAxText_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IScintillAxText_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IScintillAxText_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IScintillAxText_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IScintillAxText_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IScintillAxText_put_Value(This,txt)	\
    ( (This)->lpVtbl -> put_Value(This,txt) ) 

#define IScintillAxText_get_Value(This,txt)	\
    ( (This)->lpVtbl -> get_Value(This,txt) ) 

#define IScintillAxText_get_Modified(This,vbModified)	\
    ( (This)->lpVtbl -> get_Modified(This,vbModified) ) 

#define IScintillAxText_get_Length(This,len)	\
    ( (This)->lpVtbl -> get_Length(This,len) ) 

#define IScintillAxText_SetText(This,txt)	\
    ( (This)->lpVtbl -> SetText(This,txt) ) 

#define IScintillAxText_GetText(This,txt)	\
    ( (This)->lpVtbl -> GetText(This,txt) ) 

#define IScintillAxText_GetTextRange(This,pStart,pEnd,rng)	\
    ( (This)->lpVtbl -> GetTextRange(This,pStart,pEnd,rng) ) 

#define IScintillAxText_Append(This,txt)	\
    ( (This)->lpVtbl -> Append(This,txt) ) 

#define IScintillAxText_Insert(This,txt,p)	\
    ( (This)->lpVtbl -> Insert(This,txt,p) ) 

#define IScintillAxText_Search(This,sWhat,lFlags,vbFound)	\
    ( (This)->lpVtbl -> Search(This,sWhat,lFlags,vbFound) ) 

#define IScintillAxText_Replace(This,sWhat,w,lFlags,vbReplaced)	\
    ( (This)->lpVtbl -> Replace(This,sWhat,w,lFlags,vbReplaced) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IScintillAxText_INTERFACE_DEFINED__ */


#ifndef __IScintillAxPosition_INTERFACE_DEFINED__
#define __IScintillAxPosition_INTERFACE_DEFINED__

/* interface IScintillAxPosition */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IScintillAxPosition;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AE7C2E4D-1AD1-48E8-A376-6C6DA26707E8")
    IScintillAxPosition : public IDispatch
    {
    public:
        virtual /* [helpstring][id][requestedit][defaultbind][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Caret( 
            /* [in] */ long p) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Caret( 
            /* [retval][out] */ long *p) = 0;
        
        virtual /* [helpstring][id][requestedit][defaultbind][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_SearchPos( 
            /* [in] */ long p) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_SearchPos( 
            /* [retval][out] */ long *p) = 0;
        
        virtual /* [helpstring][id][requestedit][defaultbind][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Anchor( 
            /* [in] */ long p) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Anchor( 
            /* [retval][out] */ long *p) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CharAt( 
            /* [in] */ long p,
            /* [retval][out] */ BSTR *ch) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Scroll( 
            /* [in] */ long cCols,
            /* [in] */ long cLines) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ScrollIntoView( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IScintillAxPositionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IScintillAxPosition * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IScintillAxPosition * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IScintillAxPosition * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IScintillAxPosition * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IScintillAxPosition * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IScintillAxPosition * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IScintillAxPosition * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][requestedit][defaultbind][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Caret )( 
            IScintillAxPosition * This,
            /* [in] */ long p);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Caret )( 
            IScintillAxPosition * This,
            /* [retval][out] */ long *p);
        
        /* [helpstring][id][requestedit][defaultbind][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SearchPos )( 
            IScintillAxPosition * This,
            /* [in] */ long p);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SearchPos )( 
            IScintillAxPosition * This,
            /* [retval][out] */ long *p);
        
        /* [helpstring][id][requestedit][defaultbind][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Anchor )( 
            IScintillAxPosition * This,
            /* [in] */ long p);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Anchor )( 
            IScintillAxPosition * This,
            /* [retval][out] */ long *p);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CharAt )( 
            IScintillAxPosition * This,
            /* [in] */ long p,
            /* [retval][out] */ BSTR *ch);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Scroll )( 
            IScintillAxPosition * This,
            /* [in] */ long cCols,
            /* [in] */ long cLines);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ScrollIntoView )( 
            IScintillAxPosition * This);
        
        END_INTERFACE
    } IScintillAxPositionVtbl;

    interface IScintillAxPosition
    {
        CONST_VTBL struct IScintillAxPositionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScintillAxPosition_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IScintillAxPosition_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IScintillAxPosition_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IScintillAxPosition_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IScintillAxPosition_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IScintillAxPosition_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IScintillAxPosition_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IScintillAxPosition_put_Caret(This,p)	\
    ( (This)->lpVtbl -> put_Caret(This,p) ) 

#define IScintillAxPosition_get_Caret(This,p)	\
    ( (This)->lpVtbl -> get_Caret(This,p) ) 

#define IScintillAxPosition_put_SearchPos(This,p)	\
    ( (This)->lpVtbl -> put_SearchPos(This,p) ) 

#define IScintillAxPosition_get_SearchPos(This,p)	\
    ( (This)->lpVtbl -> get_SearchPos(This,p) ) 

#define IScintillAxPosition_put_Anchor(This,p)	\
    ( (This)->lpVtbl -> put_Anchor(This,p) ) 

#define IScintillAxPosition_get_Anchor(This,p)	\
    ( (This)->lpVtbl -> get_Anchor(This,p) ) 

#define IScintillAxPosition_CharAt(This,p,ch)	\
    ( (This)->lpVtbl -> CharAt(This,p,ch) ) 

#define IScintillAxPosition_Scroll(This,cCols,cLines)	\
    ( (This)->lpVtbl -> Scroll(This,cCols,cLines) ) 

#define IScintillAxPosition_ScrollIntoView(This)	\
    ( (This)->lpVtbl -> ScrollIntoView(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IScintillAxPosition_INTERFACE_DEFINED__ */


#ifndef __IScintillAxSelection_INTERFACE_DEFINED__
#define __IScintillAxSelection_INTERFACE_DEFINED__

/* interface IScintillAxSelection */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IScintillAxSelection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("76D700E6-D9F1-4D92-AEEF-658773834226")
    IScintillAxSelection : public IDispatch
    {
    public:
        virtual /* [helpstring][id][requestedit][defaultbind][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Start( 
            /* [in] */ long p) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Start( 
            /* [retval][out] */ long *p) = 0;
        
        virtual /* [helpstring][id][requestedit][defaultbind][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_End( 
            /* [in] */ long p) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_End( 
            /* [retval][out] */ long *p) = 0;
        
        virtual /* [helpstring][id][requestedit][defaultbind][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Text( 
            /* [in] */ BSTR txt) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Text( 
            /* [retval][out] */ BSTR *txt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSelection( 
            /* [out] */ long *pFirst,
            /* [out] */ long *pLast) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSelection( 
            /* [in] */ long pFirst,
            /* [in] */ long pLast) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Cut( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Copy( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Paste( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IScintillAxSelectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IScintillAxSelection * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IScintillAxSelection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IScintillAxSelection * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IScintillAxSelection * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IScintillAxSelection * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IScintillAxSelection * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IScintillAxSelection * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][requestedit][defaultbind][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Start )( 
            IScintillAxSelection * This,
            /* [in] */ long p);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Start )( 
            IScintillAxSelection * This,
            /* [retval][out] */ long *p);
        
        /* [helpstring][id][requestedit][defaultbind][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_End )( 
            IScintillAxSelection * This,
            /* [in] */ long p);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_End )( 
            IScintillAxSelection * This,
            /* [retval][out] */ long *p);
        
        /* [helpstring][id][requestedit][defaultbind][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Text )( 
            IScintillAxSelection * This,
            /* [in] */ BSTR txt);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Text )( 
            IScintillAxSelection * This,
            /* [retval][out] */ BSTR *txt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSelection )( 
            IScintillAxSelection * This,
            /* [out] */ long *pFirst,
            /* [out] */ long *pLast);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSelection )( 
            IScintillAxSelection * This,
            /* [in] */ long pFirst,
            /* [in] */ long pLast);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Cut )( 
            IScintillAxSelection * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IScintillAxSelection * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Paste )( 
            IScintillAxSelection * This);
        
        END_INTERFACE
    } IScintillAxSelectionVtbl;

    interface IScintillAxSelection
    {
        CONST_VTBL struct IScintillAxSelectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScintillAxSelection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IScintillAxSelection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IScintillAxSelection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IScintillAxSelection_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IScintillAxSelection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IScintillAxSelection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IScintillAxSelection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IScintillAxSelection_put_Start(This,p)	\
    ( (This)->lpVtbl -> put_Start(This,p) ) 

#define IScintillAxSelection_get_Start(This,p)	\
    ( (This)->lpVtbl -> get_Start(This,p) ) 

#define IScintillAxSelection_put_End(This,p)	\
    ( (This)->lpVtbl -> put_End(This,p) ) 

#define IScintillAxSelection_get_End(This,p)	\
    ( (This)->lpVtbl -> get_End(This,p) ) 

#define IScintillAxSelection_put_Text(This,txt)	\
    ( (This)->lpVtbl -> put_Text(This,txt) ) 

#define IScintillAxSelection_get_Text(This,txt)	\
    ( (This)->lpVtbl -> get_Text(This,txt) ) 

#define IScintillAxSelection_GetSelection(This,pFirst,pLast)	\
    ( (This)->lpVtbl -> GetSelection(This,pFirst,pLast) ) 

#define IScintillAxSelection_SetSelection(This,pFirst,pLast)	\
    ( (This)->lpVtbl -> SetSelection(This,pFirst,pLast) ) 

#define IScintillAxSelection_Cut(This)	\
    ( (This)->lpVtbl -> Cut(This) ) 

#define IScintillAxSelection_Copy(This)	\
    ( (This)->lpVtbl -> Copy(This) ) 

#define IScintillAxSelection_Paste(This)	\
    ( (This)->lpVtbl -> Paste(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IScintillAxSelection_INTERFACE_DEFINED__ */


#ifndef __IScintillAxLine_INTERFACE_DEFINED__
#define __IScintillAxLine_INTERFACE_DEFINED__

/* interface IScintillAxLine */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IScintillAxLine;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B22C83F1-785D-4007-BE8D-DA5CE333D9D4")
    IScintillAxLine : public IDispatch
    {
    public:
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Current( 
            /* [retval][out] */ long *p) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *p) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LineFromPos( 
            /* [in] */ long p,
            /* [retval][out] */ long *l) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PosFromLine( 
            /* [in] */ long l,
            /* [retval][out] */ long *p) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LineEndPos( 
            /* [in] */ long l,
            /* [retval][out] */ long *p) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FirstVisibleLine( 
            /* [retval][out] */ long *l) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LinesOnScreen( 
            /* [retval][out] */ long *cnt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LineLength( 
            /* [in] */ long l,
            /* [retval][out] */ long *len) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LineText( 
            /* [in] */ long l,
            /* [retval][out] */ BSTR *txt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetLineText( 
            /* [in] */ long l,
            /* [in] */ BSTR txt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Goto( 
            /* [in] */ long l) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Highlite( 
            /* [in] */ long line) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IScintillAxLineVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IScintillAxLine * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IScintillAxLine * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IScintillAxLine * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IScintillAxLine * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IScintillAxLine * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IScintillAxLine * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IScintillAxLine * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Current )( 
            IScintillAxLine * This,
            /* [retval][out] */ long *p);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IScintillAxLine * This,
            /* [retval][out] */ long *p);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LineFromPos )( 
            IScintillAxLine * This,
            /* [in] */ long p,
            /* [retval][out] */ long *l);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PosFromLine )( 
            IScintillAxLine * This,
            /* [in] */ long l,
            /* [retval][out] */ long *p);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LineEndPos )( 
            IScintillAxLine * This,
            /* [in] */ long l,
            /* [retval][out] */ long *p);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FirstVisibleLine )( 
            IScintillAxLine * This,
            /* [retval][out] */ long *l);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LinesOnScreen )( 
            IScintillAxLine * This,
            /* [retval][out] */ long *cnt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LineLength )( 
            IScintillAxLine * This,
            /* [in] */ long l,
            /* [retval][out] */ long *len);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LineText )( 
            IScintillAxLine * This,
            /* [in] */ long l,
            /* [retval][out] */ BSTR *txt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetLineText )( 
            IScintillAxLine * This,
            /* [in] */ long l,
            /* [in] */ BSTR txt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Goto )( 
            IScintillAxLine * This,
            /* [in] */ long l);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Highlite )( 
            IScintillAxLine * This,
            /* [in] */ long line);
        
        END_INTERFACE
    } IScintillAxLineVtbl;

    interface IScintillAxLine
    {
        CONST_VTBL struct IScintillAxLineVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScintillAxLine_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IScintillAxLine_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IScintillAxLine_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IScintillAxLine_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IScintillAxLine_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IScintillAxLine_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IScintillAxLine_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IScintillAxLine_get_Current(This,p)	\
    ( (This)->lpVtbl -> get_Current(This,p) ) 

#define IScintillAxLine_get_Count(This,p)	\
    ( (This)->lpVtbl -> get_Count(This,p) ) 

#define IScintillAxLine_LineFromPos(This,p,l)	\
    ( (This)->lpVtbl -> LineFromPos(This,p,l) ) 

#define IScintillAxLine_PosFromLine(This,l,p)	\
    ( (This)->lpVtbl -> PosFromLine(This,l,p) ) 

#define IScintillAxLine_LineEndPos(This,l,p)	\
    ( (This)->lpVtbl -> LineEndPos(This,l,p) ) 

#define IScintillAxLine_FirstVisibleLine(This,l)	\
    ( (This)->lpVtbl -> FirstVisibleLine(This,l) ) 

#define IScintillAxLine_LinesOnScreen(This,cnt)	\
    ( (This)->lpVtbl -> LinesOnScreen(This,cnt) ) 

#define IScintillAxLine_LineLength(This,l,len)	\
    ( (This)->lpVtbl -> LineLength(This,l,len) ) 

#define IScintillAxLine_LineText(This,l,txt)	\
    ( (This)->lpVtbl -> LineText(This,l,txt) ) 

#define IScintillAxLine_SetLineText(This,l,txt)	\
    ( (This)->lpVtbl -> SetLineText(This,l,txt) ) 

#define IScintillAxLine_Goto(This,l)	\
    ( (This)->lpVtbl -> Goto(This,l) ) 

#define IScintillAxLine_Highlite(This,line)	\
    ( (This)->lpVtbl -> Highlite(This,line) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IScintillAxLine_INTERFACE_DEFINED__ */


#ifndef __IScintillAxAnnotation_INTERFACE_DEFINED__
#define __IScintillAxAnnotation_INTERFACE_DEFINED__

/* interface IScintillAxAnnotation */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IScintillAxAnnotation;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D0799D5B-E2EC-4877-99A3-03ADD1895B17")
    IScintillAxAnnotation : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetText( 
            /* [in] */ long line,
            /* [in] */ BSTR txt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( 
            /* [in] */ long line) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ClearAll( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetStyle( 
            /* [in] */ long line,
            /* [in] */ long style) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IScintillAxAnnotationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IScintillAxAnnotation * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IScintillAxAnnotation * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IScintillAxAnnotation * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IScintillAxAnnotation * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IScintillAxAnnotation * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IScintillAxAnnotation * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IScintillAxAnnotation * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetText )( 
            IScintillAxAnnotation * This,
            /* [in] */ long line,
            /* [in] */ BSTR txt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IScintillAxAnnotation * This,
            /* [in] */ long line);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearAll )( 
            IScintillAxAnnotation * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetStyle )( 
            IScintillAxAnnotation * This,
            /* [in] */ long line,
            /* [in] */ long style);
        
        END_INTERFACE
    } IScintillAxAnnotationVtbl;

    interface IScintillAxAnnotation
    {
        CONST_VTBL struct IScintillAxAnnotationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScintillAxAnnotation_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IScintillAxAnnotation_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IScintillAxAnnotation_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IScintillAxAnnotation_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IScintillAxAnnotation_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IScintillAxAnnotation_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IScintillAxAnnotation_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IScintillAxAnnotation_SetText(This,line,txt)	\
    ( (This)->lpVtbl -> SetText(This,line,txt) ) 

#define IScintillAxAnnotation_Clear(This,line)	\
    ( (This)->lpVtbl -> Clear(This,line) ) 

#define IScintillAxAnnotation_ClearAll(This)	\
    ( (This)->lpVtbl -> ClearAll(This) ) 

#define IScintillAxAnnotation_SetStyle(This,line,style)	\
    ( (This)->lpVtbl -> SetStyle(This,line,style) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IScintillAxAnnotation_INTERFACE_DEFINED__ */


#ifndef __IScintillAxMarkers_INTERFACE_DEFINED__
#define __IScintillAxMarkers_INTERFACE_DEFINED__

/* interface IScintillAxMarkers */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IScintillAxMarkers;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6F7991E0-0762-452C-A6D4-649847D136DC")
    IScintillAxMarkers : public IDispatch
    {
    public:
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_UseMarkers( 
            /* [in] */ VARIANT_BOOL vbMarkers) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_UseMarkers( 
            /* [retval][out] */ VARIANT_BOOL *vbMarkers) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToggleMarker( 
            /* [in] */ long line) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetMarker( 
            /* [in] */ long line) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ long line) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveAll( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE HasMarker( 
            /* [in] */ long line) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMarkers( 
            /* [out] */ SAFEARRAY * *markers) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IScintillAxMarkersVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IScintillAxMarkers * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IScintillAxMarkers * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IScintillAxMarkers * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IScintillAxMarkers * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IScintillAxMarkers * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IScintillAxMarkers * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IScintillAxMarkers * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseMarkers )( 
            IScintillAxMarkers * This,
            /* [in] */ VARIANT_BOOL vbMarkers);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseMarkers )( 
            IScintillAxMarkers * This,
            /* [retval][out] */ VARIANT_BOOL *vbMarkers);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ToggleMarker )( 
            IScintillAxMarkers * This,
            /* [in] */ long line);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetMarker )( 
            IScintillAxMarkers * This,
            /* [in] */ long line);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Remove )( 
            IScintillAxMarkers * This,
            /* [in] */ long line);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveAll )( 
            IScintillAxMarkers * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *HasMarker )( 
            IScintillAxMarkers * This,
            /* [in] */ long line);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetMarkers )( 
            IScintillAxMarkers * This,
            /* [out] */ SAFEARRAY * *markers);
        
        END_INTERFACE
    } IScintillAxMarkersVtbl;

    interface IScintillAxMarkers
    {
        CONST_VTBL struct IScintillAxMarkersVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScintillAxMarkers_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IScintillAxMarkers_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IScintillAxMarkers_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IScintillAxMarkers_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IScintillAxMarkers_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IScintillAxMarkers_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IScintillAxMarkers_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IScintillAxMarkers_put_UseMarkers(This,vbMarkers)	\
    ( (This)->lpVtbl -> put_UseMarkers(This,vbMarkers) ) 

#define IScintillAxMarkers_get_UseMarkers(This,vbMarkers)	\
    ( (This)->lpVtbl -> get_UseMarkers(This,vbMarkers) ) 

#define IScintillAxMarkers_ToggleMarker(This,line)	\
    ( (This)->lpVtbl -> ToggleMarker(This,line) ) 

#define IScintillAxMarkers_SetMarker(This,line)	\
    ( (This)->lpVtbl -> SetMarker(This,line) ) 

#define IScintillAxMarkers_Remove(This,line)	\
    ( (This)->lpVtbl -> Remove(This,line) ) 

#define IScintillAxMarkers_RemoveAll(This)	\
    ( (This)->lpVtbl -> RemoveAll(This) ) 

#define IScintillAxMarkers_HasMarker(This,line)	\
    ( (This)->lpVtbl -> HasMarker(This,line) ) 

#define IScintillAxMarkers_GetMarkers(This,markers)	\
    ( (This)->lpVtbl -> GetMarkers(This,markers) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IScintillAxMarkers_INTERFACE_DEFINED__ */


#ifndef __IScintillAx_INTERFACE_DEFINED__
#define __IScintillAx_INTERFACE_DEFINED__

/* interface IScintillAx */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IScintillAx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1120EC6A-130F-440e-9B1D-F02D505FB5BC")
    IScintillAx : public IDispatch
    {
    public:
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Properties( 
            /* [retval][out] */ IScintillAxProperties **d) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Text( 
            /* [retval][out] */ IScintillAxText **d) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Position( 
            /* [retval][out] */ IScintillAxPosition **d) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Selection( 
            /* [retval][out] */ IScintillAxSelection **d) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Line( 
            /* [retval][out] */ IScintillAxLine **d) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Annotation( 
            /* [retval][out] */ IScintillAxAnnotation **d) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Markers( 
            /* [retval][out] */ IScintillAxMarkers **d) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ BSTR fname) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadEncoding( 
            /* [in] */ BSTR fname,
            /* [in] */ long enc) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveAs( 
            /* [in] */ BSTR fname) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Undo( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Redo( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SavePoint( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetFocus( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ZoomIn( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ZoomOut( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Print( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ShowProperties( void) = 0;
        
        virtual /* [local][helpstring][id] */ HRESULT STDMETHODCALLTYPE InsertColorDialog( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IScintillAxVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IScintillAx * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IScintillAx * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IScintillAx * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IScintillAx * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IScintillAx * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IScintillAx * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IScintillAx * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Properties )( 
            IScintillAx * This,
            /* [retval][out] */ IScintillAxProperties **d);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Text )( 
            IScintillAx * This,
            /* [retval][out] */ IScintillAxText **d);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Position )( 
            IScintillAx * This,
            /* [retval][out] */ IScintillAxPosition **d);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Selection )( 
            IScintillAx * This,
            /* [retval][out] */ IScintillAxSelection **d);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Line )( 
            IScintillAx * This,
            /* [retval][out] */ IScintillAxLine **d);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Annotation )( 
            IScintillAx * This,
            /* [retval][out] */ IScintillAxAnnotation **d);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Markers )( 
            IScintillAx * This,
            /* [retval][out] */ IScintillAxMarkers **d);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Load )( 
            IScintillAx * This,
            /* [in] */ BSTR fname);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadEncoding )( 
            IScintillAx * This,
            /* [in] */ BSTR fname,
            /* [in] */ long enc);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IScintillAx * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveAs )( 
            IScintillAx * This,
            /* [in] */ BSTR fname);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Undo )( 
            IScintillAx * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Redo )( 
            IScintillAx * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SavePoint )( 
            IScintillAx * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetFocus )( 
            IScintillAx * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ZoomIn )( 
            IScintillAx * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ZoomOut )( 
            IScintillAx * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Print )( 
            IScintillAx * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ShowProperties )( 
            IScintillAx * This);
        
        /* [local][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InsertColorDialog )( 
            IScintillAx * This);
        
        END_INTERFACE
    } IScintillAxVtbl;

    interface IScintillAx
    {
        CONST_VTBL struct IScintillAxVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScintillAx_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IScintillAx_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IScintillAx_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IScintillAx_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IScintillAx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IScintillAx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IScintillAx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IScintillAx_get_Properties(This,d)	\
    ( (This)->lpVtbl -> get_Properties(This,d) ) 

#define IScintillAx_get_Text(This,d)	\
    ( (This)->lpVtbl -> get_Text(This,d) ) 

#define IScintillAx_get_Position(This,d)	\
    ( (This)->lpVtbl -> get_Position(This,d) ) 

#define IScintillAx_get_Selection(This,d)	\
    ( (This)->lpVtbl -> get_Selection(This,d) ) 

#define IScintillAx_get_Line(This,d)	\
    ( (This)->lpVtbl -> get_Line(This,d) ) 

#define IScintillAx_get_Annotation(This,d)	\
    ( (This)->lpVtbl -> get_Annotation(This,d) ) 

#define IScintillAx_get_Markers(This,d)	\
    ( (This)->lpVtbl -> get_Markers(This,d) ) 

#define IScintillAx_Load(This,fname)	\
    ( (This)->lpVtbl -> Load(This,fname) ) 

#define IScintillAx_LoadEncoding(This,fname,enc)	\
    ( (This)->lpVtbl -> LoadEncoding(This,fname,enc) ) 

#define IScintillAx_Save(This)	\
    ( (This)->lpVtbl -> Save(This) ) 

#define IScintillAx_SaveAs(This,fname)	\
    ( (This)->lpVtbl -> SaveAs(This,fname) ) 

#define IScintillAx_Undo(This)	\
    ( (This)->lpVtbl -> Undo(This) ) 

#define IScintillAx_Redo(This)	\
    ( (This)->lpVtbl -> Redo(This) ) 

#define IScintillAx_SavePoint(This)	\
    ( (This)->lpVtbl -> SavePoint(This) ) 

#define IScintillAx_SetFocus(This)	\
    ( (This)->lpVtbl -> SetFocus(This) ) 

#define IScintillAx_ZoomIn(This)	\
    ( (This)->lpVtbl -> ZoomIn(This) ) 

#define IScintillAx_ZoomOut(This)	\
    ( (This)->lpVtbl -> ZoomOut(This) ) 

#define IScintillAx_Print(This)	\
    ( (This)->lpVtbl -> Print(This) ) 

#define IScintillAx_ShowProperties(This)	\
    ( (This)->lpVtbl -> ShowProperties(This) ) 

#define IScintillAx_InsertColorDialog(This)	\
    ( (This)->lpVtbl -> InsertColorDialog(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IScintillAx_INTERFACE_DEFINED__ */


#ifndef ___IScintillAxEvents_DISPINTERFACE_DEFINED__
#define ___IScintillAxEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IScintillAxEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IScintillAxEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("2D33B016-176A-40fe-B665-B114A6511AC8")
    _IScintillAxEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IScintillAxEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IScintillAxEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IScintillAxEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IScintillAxEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IScintillAxEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IScintillAxEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IScintillAxEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IScintillAxEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IScintillAxEventsVtbl;

    interface _IScintillAxEvents
    {
        CONST_VTBL struct _IScintillAxEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IScintillAxEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IScintillAxEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IScintillAxEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IScintillAxEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IScintillAxEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IScintillAxEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IScintillAxEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IScintillAxEvents_DISPINTERFACE_DEFINED__ */


#ifndef __IScintillAxEvents_INTERFACE_DEFINED__
#define __IScintillAxEvents_INTERFACE_DEFINED__

/* interface IScintillAxEvents */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IScintillAxEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E3766918-A0A4-48b7-942A-BA4B4D524CD0")
    IScintillAxEvents : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnFileNameChanged( 
            /* [in] */ BSTR fname,
            /* [in] */ BSTR fPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnShowMenu( 
            /* [out] */ VARIANT_BOOL *vbShowMenue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnPosChange( 
            /* [in] */ long iLine) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnChar( 
            /* [in] */ BSTR ch) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnMarker( 
            /* [in] */ long iLine) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnSyntax( 
            /* [in] */ long s) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnSystem( 
            /* [in] */ long s) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnEncoding( 
            /* [in] */ long e) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IScintillAxEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IScintillAxEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IScintillAxEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IScintillAxEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IScintillAxEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IScintillAxEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IScintillAxEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IScintillAxEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnFileNameChanged )( 
            IScintillAxEvents * This,
            /* [in] */ BSTR fname,
            /* [in] */ BSTR fPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnShowMenu )( 
            IScintillAxEvents * This,
            /* [out] */ VARIANT_BOOL *vbShowMenue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnPosChange )( 
            IScintillAxEvents * This,
            /* [in] */ long iLine);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnChar )( 
            IScintillAxEvents * This,
            /* [in] */ BSTR ch);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnMarker )( 
            IScintillAxEvents * This,
            /* [in] */ long iLine);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnSyntax )( 
            IScintillAxEvents * This,
            /* [in] */ long s);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnSystem )( 
            IScintillAxEvents * This,
            /* [in] */ long s);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnEncoding )( 
            IScintillAxEvents * This,
            /* [in] */ long e);
        
        END_INTERFACE
    } IScintillAxEventsVtbl;

    interface IScintillAxEvents
    {
        CONST_VTBL struct IScintillAxEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScintillAxEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IScintillAxEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IScintillAxEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IScintillAxEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IScintillAxEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IScintillAxEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IScintillAxEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IScintillAxEvents_OnFileNameChanged(This,fname,fPath)	\
    ( (This)->lpVtbl -> OnFileNameChanged(This,fname,fPath) ) 

#define IScintillAxEvents_OnShowMenu(This,vbShowMenue)	\
    ( (This)->lpVtbl -> OnShowMenu(This,vbShowMenue) ) 

#define IScintillAxEvents_OnPosChange(This,iLine)	\
    ( (This)->lpVtbl -> OnPosChange(This,iLine) ) 

#define IScintillAxEvents_OnChar(This,ch)	\
    ( (This)->lpVtbl -> OnChar(This,ch) ) 

#define IScintillAxEvents_OnMarker(This,iLine)	\
    ( (This)->lpVtbl -> OnMarker(This,iLine) ) 

#define IScintillAxEvents_OnSyntax(This,s)	\
    ( (This)->lpVtbl -> OnSyntax(This,s) ) 

#define IScintillAxEvents_OnSystem(This,s)	\
    ( (This)->lpVtbl -> OnSystem(This,s) ) 

#define IScintillAxEvents_OnEncoding(This,e)	\
    ( (This)->lpVtbl -> OnEncoding(This,e) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IScintillAxEvents_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ScintillAx;

#ifdef __cplusplus

class DECLSPEC_UUID("9B5488B0-33FB-44df-8D58-672A1C1E08C1")
ScintillAx;
#endif

EXTERN_C const CLSID CLSID_ScintillAxProperties;

#ifdef __cplusplus

class DECLSPEC_UUID("C16CD143-5126-414a-AFDE-406F31E95D13")
ScintillAxProperties;
#endif

EXTERN_C const CLSID CLSID_ScintillAxSettings;

#ifdef __cplusplus

class DECLSPEC_UUID("3039CC18-067B-450F-952D-7CE2ADD79F88")
ScintillAxSettings;
#endif
#endif /* __Scintilla_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


