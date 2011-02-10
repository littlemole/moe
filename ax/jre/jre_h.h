

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Tue Feb 08 21:19:19 2011
 */
/* Compiler settings for jre.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
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


#ifndef __jre_h_h__
#define __jre_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IJavaObject_FWD_DEFINED__
#define __IJavaObject_FWD_DEFINED__
typedef interface IJavaObject IJavaObject;
#endif 	/* __IJavaObject_FWD_DEFINED__ */


#ifndef __IJavaClass_FWD_DEFINED__
#define __IJavaClass_FWD_DEFINED__
typedef interface IJavaClass IJavaClass;
#endif 	/* __IJavaClass_FWD_DEFINED__ */


#ifndef __IJVM_FWD_DEFINED__
#define __IJVM_FWD_DEFINED__
typedef interface IJVM IJVM;
#endif 	/* __IJVM_FWD_DEFINED__ */


#ifndef __Java_FWD_DEFINED__
#define __Java_FWD_DEFINED__

#ifdef __cplusplus
typedef class Java Java;
#else
typedef struct Java Java;
#endif /* __cplusplus */

#endif 	/* __Java_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __JRE_LIBRARY_DEFINED__
#define __JRE_LIBRARY_DEFINED__

/* library JRE */
/* [helpstring][version][uuid] */ 



EXTERN_C const IID LIBID_JRE;

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


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IJavaObject_INTERFACE_DEFINED__ */


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


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IJavaClass_INTERFACE_DEFINED__ */


#ifndef __IJVM_INTERFACE_DEFINED__
#define __IJVM_INTERFACE_DEFINED__

/* interface IJVM */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IJVM;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5607D481-5580-4eb7-8ECD-8805846D8C86")
    IJVM : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Classpath( 
            /* [in] */ BSTR cp) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Classpath( 
            /* [retval][out] */ BSTR *cp) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Libpath( 
            /* [in] */ BSTR lp) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Libpath( 
            /* [retval][out] */ BSTR *lp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadClass( 
            /* [in] */ BSTR clazzName,
            /* [retval][out] */ IJavaClass **clazz) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IJVMVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IJVM * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IJVM * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IJVM * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IJVM * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IJVM * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IJVM * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IJVM * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Classpath )( 
            IJVM * This,
            /* [in] */ BSTR cp);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Classpath )( 
            IJVM * This,
            /* [retval][out] */ BSTR *cp);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Libpath )( 
            IJVM * This,
            /* [in] */ BSTR lp);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Libpath )( 
            IJVM * This,
            /* [retval][out] */ BSTR *lp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadClass )( 
            IJVM * This,
            /* [in] */ BSTR clazzName,
            /* [retval][out] */ IJavaClass **clazz);
        
        END_INTERFACE
    } IJVMVtbl;

    interface IJVM
    {
        CONST_VTBL struct IJVMVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IJVM_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IJVM_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IJVM_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IJVM_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IJVM_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IJVM_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IJVM_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IJVM_put_Classpath(This,cp)	\
    ( (This)->lpVtbl -> put_Classpath(This,cp) ) 

#define IJVM_get_Classpath(This,cp)	\
    ( (This)->lpVtbl -> get_Classpath(This,cp) ) 

#define IJVM_put_Libpath(This,lp)	\
    ( (This)->lpVtbl -> put_Libpath(This,lp) ) 

#define IJVM_get_Libpath(This,lp)	\
    ( (This)->lpVtbl -> get_Libpath(This,lp) ) 

#define IJVM_LoadClass(This,clazzName,clazz)	\
    ( (This)->lpVtbl -> LoadClass(This,clazzName,clazz) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IJVM_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Java;

#ifdef __cplusplus

class DECLSPEC_UUID("B3ED4D8C-7FDD-4177-BF47-3680A8E225BC")
Java;
#endif
#endif /* __JRE_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


