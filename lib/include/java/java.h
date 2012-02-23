

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Thu Feb 23 19:29:17 2012
 */
/* Compiler settings for java.idl:
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

#ifndef __java_h__
#define __java_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IJavaClass_FWD_DEFINED__
#define __IJavaClass_FWD_DEFINED__
typedef interface IJavaClass IJavaClass;
#endif 	/* __IJavaClass_FWD_DEFINED__ */


#ifndef __IJavaObject_FWD_DEFINED__
#define __IJavaObject_FWD_DEFINED__
typedef interface IJavaObject IJavaObject;
#endif 	/* __IJavaObject_FWD_DEFINED__ */


#ifndef __ISwingObject_FWD_DEFINED__
#define __ISwingObject_FWD_DEFINED__
typedef interface ISwingObject ISwingObject;
#endif 	/* __ISwingObject_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_java_0000_0000 */
/* [local] */ 






extern RPC_IF_HANDLE __MIDL_itf_java_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_java_0000_0000_v0_0_s_ifspec;

#ifndef __IJavaClass_INTERFACE_DEFINED__
#define __IJavaClass_INTERFACE_DEFINED__

/* interface IJavaClass */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IJavaClass;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EA028093-8B55-4D3B-8B0F-824301504455")
    IJavaClass : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ long *ptr) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RawPtr( 
            /* [retval][out] */ long **ptr) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IJavaClassVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IJavaClass * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IJavaClass * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IJavaClass * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IJavaClass * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IJavaClass * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IJavaClass * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IJavaClass * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IJavaClass * This,
            /* [in] */ long *ptr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RawPtr )( 
            IJavaClass * This,
            /* [retval][out] */ long **ptr);
        
        END_INTERFACE
    } IJavaClassVtbl;

    interface IJavaClass
    {
        CONST_VTBL struct IJavaClassVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IJavaClass_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IJavaClass_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IJavaClass_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IJavaClass_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IJavaClass_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IJavaClass_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IJavaClass_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IJavaClass_Initialize(This,ptr)	\
    ( (This)->lpVtbl -> Initialize(This,ptr) ) 

#define IJavaClass_RawPtr(This,ptr)	\
    ( (This)->lpVtbl -> RawPtr(This,ptr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IJavaClass_INTERFACE_DEFINED__ */


#ifndef __IJavaObject_INTERFACE_DEFINED__
#define __IJavaObject_INTERFACE_DEFINED__

/* interface IJavaObject */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IJavaObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1900068C-D7A1-4654-9019-4F28DE1DE846")
    IJavaObject : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ long *ptr) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RawPtr( 
            /* [retval][out] */ long **ptr) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IJavaObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IJavaObject * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IJavaObject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IJavaObject * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IJavaObject * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IJavaObject * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IJavaObject * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IJavaObject * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IJavaObject * This,
            /* [in] */ long *ptr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RawPtr )( 
            IJavaObject * This,
            /* [retval][out] */ long **ptr);
        
        END_INTERFACE
    } IJavaObjectVtbl;

    interface IJavaObject
    {
        CONST_VTBL struct IJavaObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IJavaObject_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IJavaObject_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IJavaObject_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IJavaObject_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IJavaObject_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IJavaObject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IJavaObject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IJavaObject_Initialize(This,ptr)	\
    ( (This)->lpVtbl -> Initialize(This,ptr) ) 

#define IJavaObject_RawPtr(This,ptr)	\
    ( (This)->lpVtbl -> RawPtr(This,ptr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IJavaObject_INTERFACE_DEFINED__ */


#ifndef __ISwingObject_INTERFACE_DEFINED__
#define __ISwingObject_INTERFACE_DEFINED__

/* interface ISwingObject */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_ISwingObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("26BA436D-6051-4264-92C6-BAEC7FA40050")
    ISwingObject : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ long *ptr) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RawPtr( 
            /* [retval][out] */ long **ptr) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISwingObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISwingObject * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISwingObject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISwingObject * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISwingObject * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISwingObject * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISwingObject * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISwingObject * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            ISwingObject * This,
            /* [in] */ long *ptr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RawPtr )( 
            ISwingObject * This,
            /* [retval][out] */ long **ptr);
        
        END_INTERFACE
    } ISwingObjectVtbl;

    interface ISwingObject
    {
        CONST_VTBL struct ISwingObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISwingObject_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISwingObject_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISwingObject_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISwingObject_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISwingObject_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISwingObject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISwingObject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISwingObject_Initialize(This,ptr)	\
    ( (This)->lpVtbl -> Initialize(This,ptr) ) 

#define ISwingObject_RawPtr(This,ptr)	\
    ( (This)->lpVtbl -> RawPtr(This,ptr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISwingObject_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


