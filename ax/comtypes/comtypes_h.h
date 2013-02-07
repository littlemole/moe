

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Thu Feb 07 20:50:14 2013
 */
/* Compiler settings for comtypes.idl:
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


#ifndef __comtypes_h_h__
#define __comtypes_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ITypeLibToXml_FWD_DEFINED__
#define __ITypeLibToXml_FWD_DEFINED__
typedef interface ITypeLibToXml ITypeLibToXml;
#endif 	/* __ITypeLibToXml_FWD_DEFINED__ */


#ifndef ___IAsyncDocumentationComplete_FWD_DEFINED__
#define ___IAsyncDocumentationComplete_FWD_DEFINED__
typedef interface _IAsyncDocumentationComplete _IAsyncDocumentationComplete;
#endif 	/* ___IAsyncDocumentationComplete_FWD_DEFINED__ */


#ifndef __TypeLibToXml_FWD_DEFINED__
#define __TypeLibToXml_FWD_DEFINED__

#ifdef __cplusplus
typedef class TypeLibToXml TypeLibToXml;
#else
typedef struct TypeLibToXml TypeLibToXml;
#endif /* __cplusplus */

#endif 	/* __TypeLibToXml_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __TypeToXml_LIBRARY_DEFINED__
#define __TypeToXml_LIBRARY_DEFINED__

/* library TypeToXml */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_TypeToXml;

#ifndef __ITypeLibToXml_INTERFACE_DEFINED__
#define __ITypeLibToXml_INTERFACE_DEFINED__

/* interface ITypeLibToXml */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_ITypeLibToXml;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2D9ABF3A-0013-4761-9F9F-9AFA71AF123C")
    ITypeLibToXml : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ BSTR filename,
            /* [retval][out] */ VARIANT_BOOL *vbSuccess) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_XML( 
            /* [retval][out] */ BSTR *xmlDoc) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Transform( 
            /* [in] */ VARIANT xsltDoc,
            /* [retval][out] */ BSTR *resultDoc) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AsyncDocumentation( 
            /* [in] */ BSTR filename,
            /* [in] */ BSTR filter,
            /* [in] */ VARIANT xsltDoc) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_onComplete( 
            /* [in] */ IDispatch *onCompleteHandler) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_onComplete( 
            /* [retval][out] */ IDispatch **onCompleteHandler) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_onStatus( 
            /* [in] */ IDispatch *onStatusHandler) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_onStatus( 
            /* [retval][out] */ IDispatch **onStatusHandler) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Error( 
            /* [retval][out] */ VARIANT_BOOL *vbIsError) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Result( 
            /* [retval][out] */ BSTR *resultDoc) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITypeLibToXmlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITypeLibToXml * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITypeLibToXml * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITypeLibToXml * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITypeLibToXml * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITypeLibToXml * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITypeLibToXml * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITypeLibToXml * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Load )( 
            ITypeLibToXml * This,
            /* [in] */ BSTR filename,
            /* [retval][out] */ VARIANT_BOOL *vbSuccess);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_XML )( 
            ITypeLibToXml * This,
            /* [retval][out] */ BSTR *xmlDoc);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Transform )( 
            ITypeLibToXml * This,
            /* [in] */ VARIANT xsltDoc,
            /* [retval][out] */ BSTR *resultDoc);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AsyncDocumentation )( 
            ITypeLibToXml * This,
            /* [in] */ BSTR filename,
            /* [in] */ BSTR filter,
            /* [in] */ VARIANT xsltDoc);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_onComplete )( 
            ITypeLibToXml * This,
            /* [in] */ IDispatch *onCompleteHandler);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_onComplete )( 
            ITypeLibToXml * This,
            /* [retval][out] */ IDispatch **onCompleteHandler);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_onStatus )( 
            ITypeLibToXml * This,
            /* [in] */ IDispatch *onStatusHandler);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_onStatus )( 
            ITypeLibToXml * This,
            /* [retval][out] */ IDispatch **onStatusHandler);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Error )( 
            ITypeLibToXml * This,
            /* [retval][out] */ VARIANT_BOOL *vbIsError);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Result )( 
            ITypeLibToXml * This,
            /* [retval][out] */ BSTR *resultDoc);
        
        END_INTERFACE
    } ITypeLibToXmlVtbl;

    interface ITypeLibToXml
    {
        CONST_VTBL struct ITypeLibToXmlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITypeLibToXml_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITypeLibToXml_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITypeLibToXml_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITypeLibToXml_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITypeLibToXml_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITypeLibToXml_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITypeLibToXml_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITypeLibToXml_Load(This,filename,vbSuccess)	\
    ( (This)->lpVtbl -> Load(This,filename,vbSuccess) ) 

#define ITypeLibToXml_get_XML(This,xmlDoc)	\
    ( (This)->lpVtbl -> get_XML(This,xmlDoc) ) 

#define ITypeLibToXml_Transform(This,xsltDoc,resultDoc)	\
    ( (This)->lpVtbl -> Transform(This,xsltDoc,resultDoc) ) 

#define ITypeLibToXml_AsyncDocumentation(This,filename,filter,xsltDoc)	\
    ( (This)->lpVtbl -> AsyncDocumentation(This,filename,filter,xsltDoc) ) 

#define ITypeLibToXml_put_onComplete(This,onCompleteHandler)	\
    ( (This)->lpVtbl -> put_onComplete(This,onCompleteHandler) ) 

#define ITypeLibToXml_get_onComplete(This,onCompleteHandler)	\
    ( (This)->lpVtbl -> get_onComplete(This,onCompleteHandler) ) 

#define ITypeLibToXml_put_onStatus(This,onStatusHandler)	\
    ( (This)->lpVtbl -> put_onStatus(This,onStatusHandler) ) 

#define ITypeLibToXml_get_onStatus(This,onStatusHandler)	\
    ( (This)->lpVtbl -> get_onStatus(This,onStatusHandler) ) 

#define ITypeLibToXml_get_Error(This,vbIsError)	\
    ( (This)->lpVtbl -> get_Error(This,vbIsError) ) 

#define ITypeLibToXml_get_Result(This,resultDoc)	\
    ( (This)->lpVtbl -> get_Result(This,resultDoc) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITypeLibToXml_INTERFACE_DEFINED__ */


#ifndef ___IAsyncDocumentationComplete_DISPINTERFACE_DEFINED__
#define ___IAsyncDocumentationComplete_DISPINTERFACE_DEFINED__

/* dispinterface _IAsyncDocumentationComplete */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IAsyncDocumentationComplete;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("7CC8CCB0-E258-4116-9E0A-D72873C7169B")
    _IAsyncDocumentationComplete : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IAsyncDocumentationCompleteVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IAsyncDocumentationComplete * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IAsyncDocumentationComplete * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IAsyncDocumentationComplete * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IAsyncDocumentationComplete * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IAsyncDocumentationComplete * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IAsyncDocumentationComplete * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IAsyncDocumentationComplete * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IAsyncDocumentationCompleteVtbl;

    interface _IAsyncDocumentationComplete
    {
        CONST_VTBL struct _IAsyncDocumentationCompleteVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IAsyncDocumentationComplete_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IAsyncDocumentationComplete_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IAsyncDocumentationComplete_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IAsyncDocumentationComplete_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IAsyncDocumentationComplete_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IAsyncDocumentationComplete_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IAsyncDocumentationComplete_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IAsyncDocumentationComplete_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_TypeLibToXml;

#ifdef __cplusplus

class DECLSPEC_UUID("9BFB3F1F-E302-4637-8495-7F7FDD29B57C")
TypeLibToXml;
#endif
#endif /* __TypeToXml_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


