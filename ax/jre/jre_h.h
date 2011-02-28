

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Mon Feb 28 20:51:35 2011
 */
/* Compiler settings for jre.idl:
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


#ifndef __jre_h_h__
#define __jre_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

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


#ifndef __JavaClass_FWD_DEFINED__
#define __JavaClass_FWD_DEFINED__

#ifdef __cplusplus
typedef class JavaClass JavaClass;
#else
typedef struct JavaClass JavaClass;
#endif /* __cplusplus */

#endif 	/* __JavaClass_FWD_DEFINED__ */


#ifndef __JavaObject_FWD_DEFINED__
#define __JavaObject_FWD_DEFINED__

#ifdef __cplusplus
typedef class JavaObject JavaObject;
#else
typedef struct JavaObject JavaObject;
#endif /* __cplusplus */

#endif 	/* __JavaObject_FWD_DEFINED__ */


/* header files for imported files */
#include "java.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __JRE_LIBRARY_DEFINED__
#define __JRE_LIBRARY_DEFINED__

/* library JRE */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_JRE;

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
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Exit( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Cast( 
            /* [in] */ IJavaObject *jObject,
            /* [in] */ BSTR clazz,
            /* [retval][out] */ IJavaObject **__MIDL__IJVM0000) = 0;
        
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
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Exit )( 
            IJVM * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Cast )( 
            IJVM * This,
            /* [in] */ IJavaObject *jObject,
            /* [in] */ BSTR clazz,
            /* [retval][out] */ IJavaObject **__MIDL__IJVM0000);
        
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

#define IJVM_Exit(This)	\
    ( (This)->lpVtbl -> Exit(This) ) 

#define IJVM_Cast(This,jObject,clazz,__MIDL__IJVM0000)	\
    ( (This)->lpVtbl -> Cast(This,jObject,clazz,__MIDL__IJVM0000) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IJVM_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Java;

#ifdef __cplusplus

class DECLSPEC_UUID("B3ED4D8C-7FDD-4177-BF47-3680A8E225BC")
Java;
#endif

EXTERN_C const CLSID CLSID_JavaClass;

#ifdef __cplusplus

class DECLSPEC_UUID("4CCBBB37-A5F2-47A3-B67B-53AE711DEFCA")
JavaClass;
#endif

EXTERN_C const CLSID CLSID_JavaObject;

#ifdef __cplusplus

class DECLSPEC_UUID("C22704EA-3233-42BC-AA5D-56543D01AA82")
JavaObject;
#endif
#endif /* __JRE_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


