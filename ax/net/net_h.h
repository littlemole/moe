

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Wed Jun 20 21:24:16 2012
 */
/* Compiler settings for net.idl:
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


#ifndef __net_h_h__
#define __net_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __INetObject_FWD_DEFINED__
#define __INetObject_FWD_DEFINED__
typedef interface INetObject INetObject;
#endif 	/* __INetObject_FWD_DEFINED__ */


#ifndef __INetType_FWD_DEFINED__
#define __INetType_FWD_DEFINED__
typedef interface INetType INetType;
#endif 	/* __INetType_FWD_DEFINED__ */


#ifndef __INetAssembly_FWD_DEFINED__
#define __INetAssembly_FWD_DEFINED__
typedef interface INetAssembly INetAssembly;
#endif 	/* __INetAssembly_FWD_DEFINED__ */


#ifndef __INet_FWD_DEFINED__
#define __INet_FWD_DEFINED__
typedef interface INet INet;
#endif 	/* __INet_FWD_DEFINED__ */


#ifndef __DotNet_FWD_DEFINED__
#define __DotNet_FWD_DEFINED__

#ifdef __cplusplus
typedef class DotNet DotNet;
#else
typedef struct DotNet DotNet;
#endif /* __cplusplus */

#endif 	/* __DotNet_FWD_DEFINED__ */


#ifndef __DotNetType_FWD_DEFINED__
#define __DotNetType_FWD_DEFINED__

#ifdef __cplusplus
typedef class DotNetType DotNetType;
#else
typedef struct DotNetType DotNetType;
#endif /* __cplusplus */

#endif 	/* __DotNetType_FWD_DEFINED__ */


#ifndef __DotNetObject_FWD_DEFINED__
#define __DotNetObject_FWD_DEFINED__

#ifdef __cplusplus
typedef class DotNetObject DotNetObject;
#else
typedef struct DotNetObject DotNetObject;
#endif /* __cplusplus */

#endif 	/* __DotNetObject_FWD_DEFINED__ */


#ifndef __DotNetAssembly_FWD_DEFINED__
#define __DotNetAssembly_FWD_DEFINED__

#ifdef __cplusplus
typedef class DotNetAssembly DotNetAssembly;
#else
typedef struct DotNetAssembly DotNetAssembly;
#endif /* __cplusplus */

#endif 	/* __DotNetAssembly_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __NET_LIBRARY_DEFINED__
#define __NET_LIBRARY_DEFINED__

/* library NET */
/* [helpstring][version][uuid] */ 






EXTERN_C const IID LIBID_NET;

#ifndef __INetObject_INTERFACE_DEFINED__
#define __INetObject_INTERFACE_DEFINED__

/* interface INetObject */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_INetObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("48CB943A-4675-4AAD-9538-2C327B3816B2")
    INetObject : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ VARIANT ptr) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnWrap( 
            /* [retval][out] */ VARIANT *ptr) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INetObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INetObject * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INetObject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INetObject * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            INetObject * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            INetObject * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            INetObject * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            INetObject * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            INetObject * This,
            /* [in] */ VARIANT ptr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnWrap )( 
            INetObject * This,
            /* [retval][out] */ VARIANT *ptr);
        
        END_INTERFACE
    } INetObjectVtbl;

    interface INetObject
    {
        CONST_VTBL struct INetObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetObject_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INetObject_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INetObject_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INetObject_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define INetObject_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define INetObject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define INetObject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define INetObject_Initialize(This,ptr)	\
    ( (This)->lpVtbl -> Initialize(This,ptr) ) 

#define INetObject_UnWrap(This,ptr)	\
    ( (This)->lpVtbl -> UnWrap(This,ptr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INetObject_INTERFACE_DEFINED__ */


#ifndef __INetType_INTERFACE_DEFINED__
#define __INetType_INTERFACE_DEFINED__

/* interface INetType */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_INetType;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A203B3FE-BEF5-4746-AEE9-F198C9F624A8")
    INetType : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ VARIANT ptr) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnWrap( 
            /* [retval][out] */ VARIANT *ptr) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INetTypeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INetType * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INetType * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INetType * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            INetType * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            INetType * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            INetType * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            INetType * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            INetType * This,
            /* [in] */ VARIANT ptr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnWrap )( 
            INetType * This,
            /* [retval][out] */ VARIANT *ptr);
        
        END_INTERFACE
    } INetTypeVtbl;

    interface INetType
    {
        CONST_VTBL struct INetTypeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetType_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INetType_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INetType_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INetType_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define INetType_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define INetType_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define INetType_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define INetType_Initialize(This,ptr)	\
    ( (This)->lpVtbl -> Initialize(This,ptr) ) 

#define INetType_UnWrap(This,ptr)	\
    ( (This)->lpVtbl -> UnWrap(This,ptr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INetType_INTERFACE_DEFINED__ */


#ifndef __INetAssembly_INTERFACE_DEFINED__
#define __INetAssembly_INTERFACE_DEFINED__

/* interface INetAssembly */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_INetAssembly;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E42528B2-547D-4427-A40A-47C46219A626")
    INetAssembly : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Type( 
            /* [in] */ BSTR typeName,
            /* [retval][out] */ INetType **type) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ VARIANT ptr) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnWrap( 
            /* [retval][out] */ VARIANT *ptr) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Connect( 
            /* [in] */ IDispatch *ptr,
            /* [in] */ BSTR event,
            /* [in] */ VARIANT target) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INetAssemblyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INetAssembly * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INetAssembly * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INetAssembly * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            INetAssembly * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            INetAssembly * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            INetAssembly * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            INetAssembly * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Type )( 
            INetAssembly * This,
            /* [in] */ BSTR typeName,
            /* [retval][out] */ INetType **type);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            INetAssembly * This,
            /* [in] */ VARIANT ptr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnWrap )( 
            INetAssembly * This,
            /* [retval][out] */ VARIANT *ptr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Connect )( 
            INetAssembly * This,
            /* [in] */ IDispatch *ptr,
            /* [in] */ BSTR event,
            /* [in] */ VARIANT target);
        
        END_INTERFACE
    } INetAssemblyVtbl;

    interface INetAssembly
    {
        CONST_VTBL struct INetAssemblyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetAssembly_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INetAssembly_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INetAssembly_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INetAssembly_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define INetAssembly_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define INetAssembly_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define INetAssembly_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define INetAssembly_Type(This,typeName,type)	\
    ( (This)->lpVtbl -> Type(This,typeName,type) ) 

#define INetAssembly_Initialize(This,ptr)	\
    ( (This)->lpVtbl -> Initialize(This,ptr) ) 

#define INetAssembly_UnWrap(This,ptr)	\
    ( (This)->lpVtbl -> UnWrap(This,ptr) ) 

#define INetAssembly_Connect(This,ptr,event,target)	\
    ( (This)->lpVtbl -> Connect(This,ptr,event,target) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INetAssembly_INTERFACE_DEFINED__ */


#ifndef __INet_INTERFACE_DEFINED__
#define __INet_INTERFACE_DEFINED__

/* interface INet */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_INet;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A0E5BB3E-03DD-4BE1-A824-2876BAEFDF8D")
    INet : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Type( 
            /* [in] */ BSTR typeName,
            /* [retval][out] */ INetType **type) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Import( 
            /* [in] */ BSTR clazzName,
            /* [retval][out] */ INetAssembly **a) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Exit( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Connect( 
            /* [in] */ IDispatch *ptr,
            /* [in] */ BSTR event,
            /* [in] */ VARIANT target) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INet * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INet * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INet * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            INet * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            INet * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            INet * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            INet * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Type )( 
            INet * This,
            /* [in] */ BSTR typeName,
            /* [retval][out] */ INetType **type);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Import )( 
            INet * This,
            /* [in] */ BSTR clazzName,
            /* [retval][out] */ INetAssembly **a);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Exit )( 
            INet * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Connect )( 
            INet * This,
            /* [in] */ IDispatch *ptr,
            /* [in] */ BSTR event,
            /* [in] */ VARIANT target);
        
        END_INTERFACE
    } INetVtbl;

    interface INet
    {
        CONST_VTBL struct INetVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INet_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INet_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INet_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INet_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define INet_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define INet_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define INet_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define INet_Type(This,typeName,type)	\
    ( (This)->lpVtbl -> Type(This,typeName,type) ) 

#define INet_Import(This,clazzName,a)	\
    ( (This)->lpVtbl -> Import(This,clazzName,a) ) 

#define INet_Exit(This)	\
    ( (This)->lpVtbl -> Exit(This) ) 

#define INet_Connect(This,ptr,event,target)	\
    ( (This)->lpVtbl -> Connect(This,ptr,event,target) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INet_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_DotNet;

#ifdef __cplusplus

class DECLSPEC_UUID("75B8C10C-696C-44E1-A039-A1331E9D5E61")
DotNet;
#endif

EXTERN_C const CLSID CLSID_DotNetType;

#ifdef __cplusplus

class DECLSPEC_UUID("542A2776-13B2-4689-A8DA-A4AB82BF4154")
DotNetType;
#endif

EXTERN_C const CLSID CLSID_DotNetObject;

#ifdef __cplusplus

class DECLSPEC_UUID("68B74204-A3CD-47B4-9741-176E74199090")
DotNetObject;
#endif

EXTERN_C const CLSID CLSID_DotNetAssembly;

#ifdef __cplusplus

class DECLSPEC_UUID("331790F2-442D-4CC3-A171-D375D2DFB133")
DotNetAssembly;
#endif
#endif /* __NET_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


