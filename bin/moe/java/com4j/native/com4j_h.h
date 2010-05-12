

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* at Sun Aug 03 15:23:14 2008
 */
/* Compiler settings for .\com4j.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

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


#ifndef __com4j_h_h__
#define __com4j_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IType_FWD_DEFINED__
#define __IType_FWD_DEFINED__
typedef interface IType IType;
#endif 	/* __IType_FWD_DEFINED__ */


#ifndef __ITypeDecl_FWD_DEFINED__
#define __ITypeDecl_FWD_DEFINED__
typedef interface ITypeDecl ITypeDecl;
#endif 	/* __ITypeDecl_FWD_DEFINED__ */


#ifndef __IInterfaceDecl_FWD_DEFINED__
#define __IInterfaceDecl_FWD_DEFINED__
typedef interface IInterfaceDecl IInterfaceDecl;
#endif 	/* __IInterfaceDecl_FWD_DEFINED__ */


#ifndef __IMethod_FWD_DEFINED__
#define __IMethod_FWD_DEFINED__
typedef interface IMethod IMethod;
#endif 	/* __IMethod_FWD_DEFINED__ */


#ifndef __IParam_FWD_DEFINED__
#define __IParam_FWD_DEFINED__
typedef interface IParam IParam;
#endif 	/* __IParam_FWD_DEFINED__ */


#ifndef __IConstant_FWD_DEFINED__
#define __IConstant_FWD_DEFINED__
typedef interface IConstant IConstant;
#endif 	/* __IConstant_FWD_DEFINED__ */


#ifndef __IImplementedInterfaceDecl_FWD_DEFINED__
#define __IImplementedInterfaceDecl_FWD_DEFINED__
typedef interface IImplementedInterfaceDecl IImplementedInterfaceDecl;
#endif 	/* __IImplementedInterfaceDecl_FWD_DEFINED__ */


#ifndef __ITypeLibrary_FWD_DEFINED__
#define __ITypeLibrary_FWD_DEFINED__
typedef interface ITypeLibrary ITypeLibrary;
#endif 	/* __ITypeLibrary_FWD_DEFINED__ */


#ifndef __IPtrType_FWD_DEFINED__
#define __IPtrType_FWD_DEFINED__
typedef interface IPtrType IPtrType;
#endif 	/* __IPtrType_FWD_DEFINED__ */


#ifndef __ISafeArrayType_FWD_DEFINED__
#define __ISafeArrayType_FWD_DEFINED__
typedef interface ISafeArrayType ISafeArrayType;
#endif 	/* __ISafeArrayType_FWD_DEFINED__ */


#ifndef __IPrimitiveType_FWD_DEFINED__
#define __IPrimitiveType_FWD_DEFINED__
typedef interface IPrimitiveType IPrimitiveType;
#endif 	/* __IPrimitiveType_FWD_DEFINED__ */


#ifndef __IDispInterfaceDecl_FWD_DEFINED__
#define __IDispInterfaceDecl_FWD_DEFINED__
typedef interface IDispInterfaceDecl IDispInterfaceDecl;
#endif 	/* __IDispInterfaceDecl_FWD_DEFINED__ */


#ifndef __ITypedefDecl_FWD_DEFINED__
#define __ITypedefDecl_FWD_DEFINED__
typedef interface ITypedefDecl ITypedefDecl;
#endif 	/* __ITypedefDecl_FWD_DEFINED__ */


#ifndef __IEnumDecl_FWD_DEFINED__
#define __IEnumDecl_FWD_DEFINED__
typedef interface IEnumDecl IEnumDecl;
#endif 	/* __IEnumDecl_FWD_DEFINED__ */


#ifndef __ICoClassDecl_FWD_DEFINED__
#define __ICoClassDecl_FWD_DEFINED__
typedef interface ICoClassDecl ICoClassDecl;
#endif 	/* __ICoClassDecl_FWD_DEFINED__ */


#ifndef ___ITestObjectEvents_FWD_DEFINED__
#define ___ITestObjectEvents_FWD_DEFINED__
typedef interface _ITestObjectEvents _ITestObjectEvents;
#endif 	/* ___ITestObjectEvents_FWD_DEFINED__ */


#ifndef __ITestObject_FWD_DEFINED__
#define __ITestObject_FWD_DEFINED__
typedef interface ITestObject ITestObject;
#endif 	/* __ITestObject_FWD_DEFINED__ */


#ifndef __TestObject_FWD_DEFINED__
#define __TestObject_FWD_DEFINED__

#ifdef __cplusplus
typedef class TestObject TestObject;
#else
typedef struct TestObject TestObject;
#endif /* __cplusplus */

#endif 	/* __TestObject_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 


#ifndef __com4j_LIBRARY_DEFINED__
#define __com4j_LIBRARY_DEFINED__

/* library com4j */
/* [helpstring][version][uuid] */ 








typedef /* [public][public] */ 
enum __MIDL___MIDL_itf_com4j_0000_0001
    {	TypeKind_ENUM	= 0,
	TypeKind_RECORD	= 1,
	TypeKind_MODULE	= 2,
	TypeKind_INTERFACE	= 3,
	TypeKind_DISPATCH	= 4,
	TypeKind_COCLASS	= 5,
	TypeKind_ALIAS	= 6,
	TypeKind_UNION	= 7,
	TypeKind_MAX	= 8
    } 	TypeKind;


EXTERN_C const IID LIBID_com4j;

#ifndef __IType_INTERFACE_DEFINED__
#define __IType_INTERFACE_DEFINED__

/* interface IType */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IType;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ED0810B4-3662-4fe7-8FA7-446C465B2847")
    IType : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct ITypeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IType * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IType * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IType * This);
        
        END_INTERFACE
    } ITypeVtbl;

    interface IType
    {
        CONST_VTBL struct ITypeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IType_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IType_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IType_Release(This)	\
    (This)->lpVtbl -> Release(This)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IType_INTERFACE_DEFINED__ */


#ifndef __ITypeDecl_INTERFACE_DEFINED__
#define __ITypeDecl_INTERFACE_DEFINED__

/* interface ITypeDecl */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ITypeDecl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AF7CC95D-EC5C-4904-B2ED-E1E8838A4377")
    ITypeDecl : public IType
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE getName( 
            /* [retval][out] */ BSTR *pName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getHelpString( 
            /* [retval][out] */ BSTR *pHelpString) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getKind( 
            /* [retval][out] */ TypeKind *kind) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getParent( 
            /* [retval][out] */ ITypeLibrary **ppParent) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITypeDeclVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITypeDecl * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITypeDecl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITypeDecl * This);
        
        HRESULT ( STDMETHODCALLTYPE *getName )( 
            ITypeDecl * This,
            /* [retval][out] */ BSTR *pName);
        
        HRESULT ( STDMETHODCALLTYPE *getHelpString )( 
            ITypeDecl * This,
            /* [retval][out] */ BSTR *pHelpString);
        
        HRESULT ( STDMETHODCALLTYPE *getKind )( 
            ITypeDecl * This,
            /* [retval][out] */ TypeKind *kind);
        
        HRESULT ( STDMETHODCALLTYPE *getParent )( 
            ITypeDecl * This,
            /* [retval][out] */ ITypeLibrary **ppParent);
        
        END_INTERFACE
    } ITypeDeclVtbl;

    interface ITypeDecl
    {
        CONST_VTBL struct ITypeDeclVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITypeDecl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITypeDecl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITypeDecl_Release(This)	\
    (This)->lpVtbl -> Release(This)



#define ITypeDecl_getName(This,pName)	\
    (This)->lpVtbl -> getName(This,pName)

#define ITypeDecl_getHelpString(This,pHelpString)	\
    (This)->lpVtbl -> getHelpString(This,pHelpString)

#define ITypeDecl_getKind(This,kind)	\
    (This)->lpVtbl -> getKind(This,kind)

#define ITypeDecl_getParent(This,ppParent)	\
    (This)->lpVtbl -> getParent(This,ppParent)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITypeDecl_getName_Proxy( 
    ITypeDecl * This,
    /* [retval][out] */ BSTR *pName);


void __RPC_STUB ITypeDecl_getName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITypeDecl_getHelpString_Proxy( 
    ITypeDecl * This,
    /* [retval][out] */ BSTR *pHelpString);


void __RPC_STUB ITypeDecl_getHelpString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITypeDecl_getKind_Proxy( 
    ITypeDecl * This,
    /* [retval][out] */ TypeKind *kind);


void __RPC_STUB ITypeDecl_getKind_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITypeDecl_getParent_Proxy( 
    ITypeDecl * This,
    /* [retval][out] */ ITypeLibrary **ppParent);


void __RPC_STUB ITypeDecl_getParent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITypeDecl_INTERFACE_DEFINED__ */


#ifndef __IInterfaceDecl_INTERFACE_DEFINED__
#define __IInterfaceDecl_INTERFACE_DEFINED__

/* interface IInterfaceDecl */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceDecl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EE076FF5-2E16-4a23-AE24-5DF610F6006E")
    IInterfaceDecl : public ITypeDecl
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE getGUID( 
            /* [retval][out] */ GUID *pValue) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE countMethods( 
            /* [retval][out] */ int *pValue) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE getMethod( 
            /* [in] */ int index,
            /* [retval][out] */ IMethod **ppMethod) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE countBaseInterfaces( 
            /* [retval][out] */ int *pValue) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE getBaseInterface( 
            int index,
            /* [retval][out] */ ITypeDecl **ppType) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceDeclVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceDecl * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceDecl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceDecl * This);
        
        HRESULT ( STDMETHODCALLTYPE *getName )( 
            IInterfaceDecl * This,
            /* [retval][out] */ BSTR *pName);
        
        HRESULT ( STDMETHODCALLTYPE *getHelpString )( 
            IInterfaceDecl * This,
            /* [retval][out] */ BSTR *pHelpString);
        
        HRESULT ( STDMETHODCALLTYPE *getKind )( 
            IInterfaceDecl * This,
            /* [retval][out] */ TypeKind *kind);
        
        HRESULT ( STDMETHODCALLTYPE *getParent )( 
            IInterfaceDecl * This,
            /* [retval][out] */ ITypeLibrary **ppParent);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *getGUID )( 
            IInterfaceDecl * This,
            /* [retval][out] */ GUID *pValue);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *countMethods )( 
            IInterfaceDecl * This,
            /* [retval][out] */ int *pValue);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *getMethod )( 
            IInterfaceDecl * This,
            /* [in] */ int index,
            /* [retval][out] */ IMethod **ppMethod);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *countBaseInterfaces )( 
            IInterfaceDecl * This,
            /* [retval][out] */ int *pValue);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *getBaseInterface )( 
            IInterfaceDecl * This,
            int index,
            /* [retval][out] */ ITypeDecl **ppType);
        
        END_INTERFACE
    } IInterfaceDeclVtbl;

    interface IInterfaceDecl
    {
        CONST_VTBL struct IInterfaceDeclVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceDecl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IInterfaceDecl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IInterfaceDecl_Release(This)	\
    (This)->lpVtbl -> Release(This)



#define IInterfaceDecl_getName(This,pName)	\
    (This)->lpVtbl -> getName(This,pName)

#define IInterfaceDecl_getHelpString(This,pHelpString)	\
    (This)->lpVtbl -> getHelpString(This,pHelpString)

#define IInterfaceDecl_getKind(This,kind)	\
    (This)->lpVtbl -> getKind(This,kind)

#define IInterfaceDecl_getParent(This,ppParent)	\
    (This)->lpVtbl -> getParent(This,ppParent)


#define IInterfaceDecl_getGUID(This,pValue)	\
    (This)->lpVtbl -> getGUID(This,pValue)

#define IInterfaceDecl_countMethods(This,pValue)	\
    (This)->lpVtbl -> countMethods(This,pValue)

#define IInterfaceDecl_getMethod(This,index,ppMethod)	\
    (This)->lpVtbl -> getMethod(This,index,ppMethod)

#define IInterfaceDecl_countBaseInterfaces(This,pValue)	\
    (This)->lpVtbl -> countBaseInterfaces(This,pValue)

#define IInterfaceDecl_getBaseInterface(This,index,ppType)	\
    (This)->lpVtbl -> getBaseInterface(This,index,ppType)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IInterfaceDecl_getGUID_Proxy( 
    IInterfaceDecl * This,
    /* [retval][out] */ GUID *pValue);


void __RPC_STUB IInterfaceDecl_getGUID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IInterfaceDecl_countMethods_Proxy( 
    IInterfaceDecl * This,
    /* [retval][out] */ int *pValue);


void __RPC_STUB IInterfaceDecl_countMethods_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IInterfaceDecl_getMethod_Proxy( 
    IInterfaceDecl * This,
    /* [in] */ int index,
    /* [retval][out] */ IMethod **ppMethod);


void __RPC_STUB IInterfaceDecl_getMethod_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IInterfaceDecl_countBaseInterfaces_Proxy( 
    IInterfaceDecl * This,
    /* [retval][out] */ int *pValue);


void __RPC_STUB IInterfaceDecl_countBaseInterfaces_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IInterfaceDecl_getBaseInterface_Proxy( 
    IInterfaceDecl * This,
    int index,
    /* [retval][out] */ ITypeDecl **ppType);


void __RPC_STUB IInterfaceDecl_getBaseInterface_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IInterfaceDecl_INTERFACE_DEFINED__ */


#ifndef __IMethod_INTERFACE_DEFINED__
#define __IMethod_INTERFACE_DEFINED__

/* interface IMethod */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IMethod;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7BF089F3-5C19-45f8-B95A-90D762580914")
    IMethod : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE getName( 
            /* [retval][out] */ BSTR *pName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getKind( 
            /* [retval][out] */ INVOKEKIND *pKind) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getHelpString( 
            /* [retval][out] */ BSTR *pHelpString) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getReturnType( 
            /* [retval][out] */ IType **ppType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getParamCount( 
            /* [retval][out] */ int *pOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getParam( 
            /* [in] */ int index,
            /* [retval][out] */ IParam **pOut) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE getVtableIndex( 
            /* [retval][out] */ int *pOut) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE isVarArg( 
            /* [retval][out] */ VARIANT_BOOL *pOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getDispId( 
            /* [retval][out] */ int *pDispId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getFlags( 
            /* [retval][out] */ int *pflags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMethodVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMethod * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMethod * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMethod * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *getName )( 
            IMethod * This,
            /* [retval][out] */ BSTR *pName);
        
        HRESULT ( STDMETHODCALLTYPE *getKind )( 
            IMethod * This,
            /* [retval][out] */ INVOKEKIND *pKind);
        
        HRESULT ( STDMETHODCALLTYPE *getHelpString )( 
            IMethod * This,
            /* [retval][out] */ BSTR *pHelpString);
        
        HRESULT ( STDMETHODCALLTYPE *getReturnType )( 
            IMethod * This,
            /* [retval][out] */ IType **ppType);
        
        HRESULT ( STDMETHODCALLTYPE *getParamCount )( 
            IMethod * This,
            /* [retval][out] */ int *pOut);
        
        HRESULT ( STDMETHODCALLTYPE *getParam )( 
            IMethod * This,
            /* [in] */ int index,
            /* [retval][out] */ IParam **pOut);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *getVtableIndex )( 
            IMethod * This,
            /* [retval][out] */ int *pOut);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *isVarArg )( 
            IMethod * This,
            /* [retval][out] */ VARIANT_BOOL *pOut);
        
        HRESULT ( STDMETHODCALLTYPE *getDispId )( 
            IMethod * This,
            /* [retval][out] */ int *pDispId);
        
        HRESULT ( STDMETHODCALLTYPE *getFlags )( 
            IMethod * This,
            /* [retval][out] */ int *pflags);
        
        END_INTERFACE
    } IMethodVtbl;

    interface IMethod
    {
        CONST_VTBL struct IMethodVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMethod_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IMethod_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IMethod_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IMethod_getName(This,pName)	\
    (This)->lpVtbl -> getName(This,pName)

#define IMethod_getKind(This,pKind)	\
    (This)->lpVtbl -> getKind(This,pKind)

#define IMethod_getHelpString(This,pHelpString)	\
    (This)->lpVtbl -> getHelpString(This,pHelpString)

#define IMethod_getReturnType(This,ppType)	\
    (This)->lpVtbl -> getReturnType(This,ppType)

#define IMethod_getParamCount(This,pOut)	\
    (This)->lpVtbl -> getParamCount(This,pOut)

#define IMethod_getParam(This,index,pOut)	\
    (This)->lpVtbl -> getParam(This,index,pOut)

#define IMethod_getVtableIndex(This,pOut)	\
    (This)->lpVtbl -> getVtableIndex(This,pOut)

#define IMethod_isVarArg(This,pOut)	\
    (This)->lpVtbl -> isVarArg(This,pOut)

#define IMethod_getDispId(This,pDispId)	\
    (This)->lpVtbl -> getDispId(This,pDispId)

#define IMethod_getFlags(This,pflags)	\
    (This)->lpVtbl -> getFlags(This,pflags)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IMethod_getName_Proxy( 
    IMethod * This,
    /* [retval][out] */ BSTR *pName);


void __RPC_STUB IMethod_getName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMethod_getKind_Proxy( 
    IMethod * This,
    /* [retval][out] */ INVOKEKIND *pKind);


void __RPC_STUB IMethod_getKind_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMethod_getHelpString_Proxy( 
    IMethod * This,
    /* [retval][out] */ BSTR *pHelpString);


void __RPC_STUB IMethod_getHelpString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMethod_getReturnType_Proxy( 
    IMethod * This,
    /* [retval][out] */ IType **ppType);


void __RPC_STUB IMethod_getReturnType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMethod_getParamCount_Proxy( 
    IMethod * This,
    /* [retval][out] */ int *pOut);


void __RPC_STUB IMethod_getParamCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMethod_getParam_Proxy( 
    IMethod * This,
    /* [in] */ int index,
    /* [retval][out] */ IParam **pOut);


void __RPC_STUB IMethod_getParam_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IMethod_getVtableIndex_Proxy( 
    IMethod * This,
    /* [retval][out] */ int *pOut);


void __RPC_STUB IMethod_getVtableIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IMethod_isVarArg_Proxy( 
    IMethod * This,
    /* [retval][out] */ VARIANT_BOOL *pOut);


void __RPC_STUB IMethod_isVarArg_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMethod_getDispId_Proxy( 
    IMethod * This,
    /* [retval][out] */ int *pDispId);


void __RPC_STUB IMethod_getDispId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMethod_getFlags_Proxy( 
    IMethod * This,
    /* [retval][out] */ int *pflags);


void __RPC_STUB IMethod_getFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IMethod_INTERFACE_DEFINED__ */


#ifndef __IParam_INTERFACE_DEFINED__
#define __IParam_INTERFACE_DEFINED__

/* interface IParam */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IParam;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8082BEBE-CC6C-44ee-BDF3-0A9BD5B2107B")
    IParam : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE getName( 
            /* [retval][out] */ BSTR *pName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getType( 
            /* [retval][out] */ IType **ppType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE isIn( 
            /* [retval][out] */ VARIANT_BOOL *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE isOut( 
            /* [retval][out] */ VARIANT_BOOL *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE isRetval( 
            /* [retval][out] */ VARIANT_BOOL *pValue) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IParamVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IParam * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IParam * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IParam * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *getName )( 
            IParam * This,
            /* [retval][out] */ BSTR *pName);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            IParam * This,
            /* [retval][out] */ IType **ppType);
        
        HRESULT ( STDMETHODCALLTYPE *isIn )( 
            IParam * This,
            /* [retval][out] */ VARIANT_BOOL *pValue);
        
        HRESULT ( STDMETHODCALLTYPE *isOut )( 
            IParam * This,
            /* [retval][out] */ VARIANT_BOOL *pValue);
        
        HRESULT ( STDMETHODCALLTYPE *isRetval )( 
            IParam * This,
            /* [retval][out] */ VARIANT_BOOL *pValue);
        
        END_INTERFACE
    } IParamVtbl;

    interface IParam
    {
        CONST_VTBL struct IParamVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IParam_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IParam_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IParam_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IParam_getName(This,pName)	\
    (This)->lpVtbl -> getName(This,pName)

#define IParam_getType(This,ppType)	\
    (This)->lpVtbl -> getType(This,ppType)

#define IParam_isIn(This,pValue)	\
    (This)->lpVtbl -> isIn(This,pValue)

#define IParam_isOut(This,pValue)	\
    (This)->lpVtbl -> isOut(This,pValue)

#define IParam_isRetval(This,pValue)	\
    (This)->lpVtbl -> isRetval(This,pValue)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IParam_getName_Proxy( 
    IParam * This,
    /* [retval][out] */ BSTR *pName);


void __RPC_STUB IParam_getName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IParam_getType_Proxy( 
    IParam * This,
    /* [retval][out] */ IType **ppType);


void __RPC_STUB IParam_getType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IParam_isIn_Proxy( 
    IParam * This,
    /* [retval][out] */ VARIANT_BOOL *pValue);


void __RPC_STUB IParam_isIn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IParam_isOut_Proxy( 
    IParam * This,
    /* [retval][out] */ VARIANT_BOOL *pValue);


void __RPC_STUB IParam_isOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IParam_isRetval_Proxy( 
    IParam * This,
    /* [retval][out] */ VARIANT_BOOL *pValue);


void __RPC_STUB IParam_isRetval_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IParam_INTERFACE_DEFINED__ */


#ifndef __IConstant_INTERFACE_DEFINED__
#define __IConstant_INTERFACE_DEFINED__

/* interface IConstant */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IConstant;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("579779F8-E889-43cc-9C07-F412A5374970")
    IConstant : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE getName( 
            /* [retval][out] */ BSTR *pName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE getType( 
            /* [retval][out] */ IType **ppType) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE getValue( 
            /* [retval][out] */ int *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getHelpString( 
            /* [retval][out] */ BSTR *pHelpString) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IConstantVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IConstant * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IConstant * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IConstant * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *getName )( 
            IConstant * This,
            /* [retval][out] */ BSTR *pName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *getType )( 
            IConstant * This,
            /* [retval][out] */ IType **ppType);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *getValue )( 
            IConstant * This,
            /* [retval][out] */ int *pValue);
        
        HRESULT ( STDMETHODCALLTYPE *getHelpString )( 
            IConstant * This,
            /* [retval][out] */ BSTR *pHelpString);
        
        END_INTERFACE
    } IConstantVtbl;

    interface IConstant
    {
        CONST_VTBL struct IConstantVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IConstant_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IConstant_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IConstant_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IConstant_getName(This,pName)	\
    (This)->lpVtbl -> getName(This,pName)

#define IConstant_getType(This,ppType)	\
    (This)->lpVtbl -> getType(This,ppType)

#define IConstant_getValue(This,pValue)	\
    (This)->lpVtbl -> getValue(This,pValue)

#define IConstant_getHelpString(This,pHelpString)	\
    (This)->lpVtbl -> getHelpString(This,pHelpString)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IConstant_getName_Proxy( 
    IConstant * This,
    /* [retval][out] */ BSTR *pName);


void __RPC_STUB IConstant_getName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IConstant_getType_Proxy( 
    IConstant * This,
    /* [retval][out] */ IType **ppType);


void __RPC_STUB IConstant_getType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IConstant_getValue_Proxy( 
    IConstant * This,
    /* [retval][out] */ int *pValue);


void __RPC_STUB IConstant_getValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConstant_getHelpString_Proxy( 
    IConstant * This,
    /* [retval][out] */ BSTR *pHelpString);


void __RPC_STUB IConstant_getHelpString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IConstant_INTERFACE_DEFINED__ */


#ifndef __IImplementedInterfaceDecl_INTERFACE_DEFINED__
#define __IImplementedInterfaceDecl_INTERFACE_DEFINED__

/* interface IImplementedInterfaceDecl */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IImplementedInterfaceDecl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9F6412CF-9B35-4b72-A8B9-AF83491E5B73")
    IImplementedInterfaceDecl : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE isDefault( 
            /* [retval][out] */ VARIANT_BOOL *pValue) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE isSource( 
            /* [retval][out] */ VARIANT_BOOL *pValue) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE isRestricted( 
            /* [retval][out] */ VARIANT_BOOL *pValue) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE getType( 
            /* [retval][out] */ ITypeDecl **ppType) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IImplementedInterfaceDeclVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IImplementedInterfaceDecl * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IImplementedInterfaceDecl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IImplementedInterfaceDecl * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *isDefault )( 
            IImplementedInterfaceDecl * This,
            /* [retval][out] */ VARIANT_BOOL *pValue);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *isSource )( 
            IImplementedInterfaceDecl * This,
            /* [retval][out] */ VARIANT_BOOL *pValue);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *isRestricted )( 
            IImplementedInterfaceDecl * This,
            /* [retval][out] */ VARIANT_BOOL *pValue);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *getType )( 
            IImplementedInterfaceDecl * This,
            /* [retval][out] */ ITypeDecl **ppType);
        
        END_INTERFACE
    } IImplementedInterfaceDeclVtbl;

    interface IImplementedInterfaceDecl
    {
        CONST_VTBL struct IImplementedInterfaceDeclVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IImplementedInterfaceDecl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IImplementedInterfaceDecl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IImplementedInterfaceDecl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IImplementedInterfaceDecl_isDefault(This,pValue)	\
    (This)->lpVtbl -> isDefault(This,pValue)

#define IImplementedInterfaceDecl_isSource(This,pValue)	\
    (This)->lpVtbl -> isSource(This,pValue)

#define IImplementedInterfaceDecl_isRestricted(This,pValue)	\
    (This)->lpVtbl -> isRestricted(This,pValue)

#define IImplementedInterfaceDecl_getType(This,ppType)	\
    (This)->lpVtbl -> getType(This,ppType)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IImplementedInterfaceDecl_isDefault_Proxy( 
    IImplementedInterfaceDecl * This,
    /* [retval][out] */ VARIANT_BOOL *pValue);


void __RPC_STUB IImplementedInterfaceDecl_isDefault_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IImplementedInterfaceDecl_isSource_Proxy( 
    IImplementedInterfaceDecl * This,
    /* [retval][out] */ VARIANT_BOOL *pValue);


void __RPC_STUB IImplementedInterfaceDecl_isSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IImplementedInterfaceDecl_isRestricted_Proxy( 
    IImplementedInterfaceDecl * This,
    /* [retval][out] */ VARIANT_BOOL *pValue);


void __RPC_STUB IImplementedInterfaceDecl_isRestricted_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IImplementedInterfaceDecl_getType_Proxy( 
    IImplementedInterfaceDecl * This,
    /* [retval][out] */ ITypeDecl **ppType);


void __RPC_STUB IImplementedInterfaceDecl_getType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IImplementedInterfaceDecl_INTERFACE_DEFINED__ */


#ifndef __ITypeLibrary_INTERFACE_DEFINED__
#define __ITypeLibrary_INTERFACE_DEFINED__

/* interface ITypeLibrary */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ITypeLibrary;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2CC69AC1-D228-401b-83D9-7A7C42E5DBD9")
    ITypeLibrary : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE getCount( 
            /* [retval][out] */ int *pCount) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE getLibid( 
            /* [retval][out] */ GUID *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getName( 
            /* [retval][out] */ BSTR *pName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getHelpString( 
            /* [retval][out] */ BSTR *pHelpString) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE getTypeDecl( 
            int nIndex,
            /* [retval][out] */ ITypeDecl **ppType) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITypeLibraryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITypeLibrary * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITypeLibrary * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITypeLibrary * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *getCount )( 
            ITypeLibrary * This,
            /* [retval][out] */ int *pCount);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *getLibid )( 
            ITypeLibrary * This,
            /* [retval][out] */ GUID *pValue);
        
        HRESULT ( STDMETHODCALLTYPE *getName )( 
            ITypeLibrary * This,
            /* [retval][out] */ BSTR *pName);
        
        HRESULT ( STDMETHODCALLTYPE *getHelpString )( 
            ITypeLibrary * This,
            /* [retval][out] */ BSTR *pHelpString);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *getTypeDecl )( 
            ITypeLibrary * This,
            int nIndex,
            /* [retval][out] */ ITypeDecl **ppType);
        
        END_INTERFACE
    } ITypeLibraryVtbl;

    interface ITypeLibrary
    {
        CONST_VTBL struct ITypeLibraryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITypeLibrary_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITypeLibrary_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITypeLibrary_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITypeLibrary_getCount(This,pCount)	\
    (This)->lpVtbl -> getCount(This,pCount)

#define ITypeLibrary_getLibid(This,pValue)	\
    (This)->lpVtbl -> getLibid(This,pValue)

#define ITypeLibrary_getName(This,pName)	\
    (This)->lpVtbl -> getName(This,pName)

#define ITypeLibrary_getHelpString(This,pHelpString)	\
    (This)->lpVtbl -> getHelpString(This,pHelpString)

#define ITypeLibrary_getTypeDecl(This,nIndex,ppType)	\
    (This)->lpVtbl -> getTypeDecl(This,nIndex,ppType)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ITypeLibrary_getCount_Proxy( 
    ITypeLibrary * This,
    /* [retval][out] */ int *pCount);


void __RPC_STUB ITypeLibrary_getCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ITypeLibrary_getLibid_Proxy( 
    ITypeLibrary * This,
    /* [retval][out] */ GUID *pValue);


void __RPC_STUB ITypeLibrary_getLibid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITypeLibrary_getName_Proxy( 
    ITypeLibrary * This,
    /* [retval][out] */ BSTR *pName);


void __RPC_STUB ITypeLibrary_getName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITypeLibrary_getHelpString_Proxy( 
    ITypeLibrary * This,
    /* [retval][out] */ BSTR *pHelpString);


void __RPC_STUB ITypeLibrary_getHelpString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ITypeLibrary_getTypeDecl_Proxy( 
    ITypeLibrary * This,
    int nIndex,
    /* [retval][out] */ ITypeDecl **ppType);


void __RPC_STUB ITypeLibrary_getTypeDecl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITypeLibrary_INTERFACE_DEFINED__ */


#ifndef __IPtrType_INTERFACE_DEFINED__
#define __IPtrType_INTERFACE_DEFINED__

/* interface IPtrType */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPtrType;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EB8F889F-8944-4faf-80F2-6C2457C224C4")
    IPtrType : public IType
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE getPointedAtType( 
            /* [retval][out] */ IType **ppType) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPtrTypeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPtrType * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPtrType * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPtrType * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *getPointedAtType )( 
            IPtrType * This,
            /* [retval][out] */ IType **ppType);
        
        END_INTERFACE
    } IPtrTypeVtbl;

    interface IPtrType
    {
        CONST_VTBL struct IPtrTypeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPtrType_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPtrType_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPtrType_Release(This)	\
    (This)->lpVtbl -> Release(This)



#define IPtrType_getPointedAtType(This,ppType)	\
    (This)->lpVtbl -> getPointedAtType(This,ppType)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IPtrType_getPointedAtType_Proxy( 
    IPtrType * This,
    /* [retval][out] */ IType **ppType);


void __RPC_STUB IPtrType_getPointedAtType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPtrType_INTERFACE_DEFINED__ */


#ifndef __ISafeArrayType_INTERFACE_DEFINED__
#define __ISafeArrayType_INTERFACE_DEFINED__

/* interface ISafeArrayType */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISafeArrayType;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("255C24C4-225E-4bd7-B699-A5B852C43919")
    ISafeArrayType : public IType
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE getComponentType( 
            /* [retval][out] */ IType **ppType) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISafeArrayTypeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISafeArrayType * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISafeArrayType * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISafeArrayType * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *getComponentType )( 
            ISafeArrayType * This,
            /* [retval][out] */ IType **ppType);
        
        END_INTERFACE
    } ISafeArrayTypeVtbl;

    interface ISafeArrayType
    {
        CONST_VTBL struct ISafeArrayTypeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISafeArrayType_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISafeArrayType_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISafeArrayType_Release(This)	\
    (This)->lpVtbl -> Release(This)



#define ISafeArrayType_getComponentType(This,ppType)	\
    (This)->lpVtbl -> getComponentType(This,ppType)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ISafeArrayType_getComponentType_Proxy( 
    ISafeArrayType * This,
    /* [retval][out] */ IType **ppType);


void __RPC_STUB ISafeArrayType_getComponentType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISafeArrayType_INTERFACE_DEFINED__ */


#ifndef __IPrimitiveType_INTERFACE_DEFINED__
#define __IPrimitiveType_INTERFACE_DEFINED__

/* interface IPrimitiveType */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPrimitiveType;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BA8E1931-1249-4863-A436-332FA88F645B")
    IPrimitiveType : public IType
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE getName( 
            /* [retval][out] */ BSTR *pName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE getVarType( 
            /* [retval][out] */ VARTYPE *pOut) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPrimitiveTypeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPrimitiveType * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPrimitiveType * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPrimitiveType * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *getName )( 
            IPrimitiveType * This,
            /* [retval][out] */ BSTR *pName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *getVarType )( 
            IPrimitiveType * This,
            /* [retval][out] */ VARTYPE *pOut);
        
        END_INTERFACE
    } IPrimitiveTypeVtbl;

    interface IPrimitiveType
    {
        CONST_VTBL struct IPrimitiveTypeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPrimitiveType_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPrimitiveType_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPrimitiveType_Release(This)	\
    (This)->lpVtbl -> Release(This)



#define IPrimitiveType_getName(This,pName)	\
    (This)->lpVtbl -> getName(This,pName)

#define IPrimitiveType_getVarType(This,pOut)	\
    (This)->lpVtbl -> getVarType(This,pOut)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IPrimitiveType_getName_Proxy( 
    IPrimitiveType * This,
    /* [retval][out] */ BSTR *pName);


void __RPC_STUB IPrimitiveType_getName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IPrimitiveType_getVarType_Proxy( 
    IPrimitiveType * This,
    /* [retval][out] */ VARTYPE *pOut);


void __RPC_STUB IPrimitiveType_getVarType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPrimitiveType_INTERFACE_DEFINED__ */


#ifndef __IDispInterfaceDecl_INTERFACE_DEFINED__
#define __IDispInterfaceDecl_INTERFACE_DEFINED__

/* interface IDispInterfaceDecl */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IDispInterfaceDecl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3BDCCFBF-B493-4d54-B1D0-4DE2FB1AFC78")
    IDispInterfaceDecl : public ITypeDecl
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE getGUID( 
            /* [retval][out] */ GUID *pValue) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE countMethods( 
            /* [retval][out] */ int *pValue) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE getMethod( 
            /* [in] */ int index,
            /* [retval][out] */ IMethod **ppMethod) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE isDual( 
            /* [retval][out] */ VARIANT_BOOL *pOut) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE getVtblInterface( 
            /* [retval][out] */ IInterfaceDecl **ppInterface) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDispInterfaceDeclVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDispInterfaceDecl * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDispInterfaceDecl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDispInterfaceDecl * This);
        
        HRESULT ( STDMETHODCALLTYPE *getName )( 
            IDispInterfaceDecl * This,
            /* [retval][out] */ BSTR *pName);
        
        HRESULT ( STDMETHODCALLTYPE *getHelpString )( 
            IDispInterfaceDecl * This,
            /* [retval][out] */ BSTR *pHelpString);
        
        HRESULT ( STDMETHODCALLTYPE *getKind )( 
            IDispInterfaceDecl * This,
            /* [retval][out] */ TypeKind *kind);
        
        HRESULT ( STDMETHODCALLTYPE *getParent )( 
            IDispInterfaceDecl * This,
            /* [retval][out] */ ITypeLibrary **ppParent);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *getGUID )( 
            IDispInterfaceDecl * This,
            /* [retval][out] */ GUID *pValue);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *countMethods )( 
            IDispInterfaceDecl * This,
            /* [retval][out] */ int *pValue);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *getMethod )( 
            IDispInterfaceDecl * This,
            /* [in] */ int index,
            /* [retval][out] */ IMethod **ppMethod);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *isDual )( 
            IDispInterfaceDecl * This,
            /* [retval][out] */ VARIANT_BOOL *pOut);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *getVtblInterface )( 
            IDispInterfaceDecl * This,
            /* [retval][out] */ IInterfaceDecl **ppInterface);
        
        END_INTERFACE
    } IDispInterfaceDeclVtbl;

    interface IDispInterfaceDecl
    {
        CONST_VTBL struct IDispInterfaceDeclVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDispInterfaceDecl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDispInterfaceDecl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDispInterfaceDecl_Release(This)	\
    (This)->lpVtbl -> Release(This)



#define IDispInterfaceDecl_getName(This,pName)	\
    (This)->lpVtbl -> getName(This,pName)

#define IDispInterfaceDecl_getHelpString(This,pHelpString)	\
    (This)->lpVtbl -> getHelpString(This,pHelpString)

#define IDispInterfaceDecl_getKind(This,kind)	\
    (This)->lpVtbl -> getKind(This,kind)

#define IDispInterfaceDecl_getParent(This,ppParent)	\
    (This)->lpVtbl -> getParent(This,ppParent)


#define IDispInterfaceDecl_getGUID(This,pValue)	\
    (This)->lpVtbl -> getGUID(This,pValue)

#define IDispInterfaceDecl_countMethods(This,pValue)	\
    (This)->lpVtbl -> countMethods(This,pValue)

#define IDispInterfaceDecl_getMethod(This,index,ppMethod)	\
    (This)->lpVtbl -> getMethod(This,index,ppMethod)

#define IDispInterfaceDecl_isDual(This,pOut)	\
    (This)->lpVtbl -> isDual(This,pOut)

#define IDispInterfaceDecl_getVtblInterface(This,ppInterface)	\
    (This)->lpVtbl -> getVtblInterface(This,ppInterface)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDispInterfaceDecl_getGUID_Proxy( 
    IDispInterfaceDecl * This,
    /* [retval][out] */ GUID *pValue);


void __RPC_STUB IDispInterfaceDecl_getGUID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDispInterfaceDecl_countMethods_Proxy( 
    IDispInterfaceDecl * This,
    /* [retval][out] */ int *pValue);


void __RPC_STUB IDispInterfaceDecl_countMethods_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDispInterfaceDecl_getMethod_Proxy( 
    IDispInterfaceDecl * This,
    /* [in] */ int index,
    /* [retval][out] */ IMethod **ppMethod);


void __RPC_STUB IDispInterfaceDecl_getMethod_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDispInterfaceDecl_isDual_Proxy( 
    IDispInterfaceDecl * This,
    /* [retval][out] */ VARIANT_BOOL *pOut);


void __RPC_STUB IDispInterfaceDecl_isDual_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDispInterfaceDecl_getVtblInterface_Proxy( 
    IDispInterfaceDecl * This,
    /* [retval][out] */ IInterfaceDecl **ppInterface);


void __RPC_STUB IDispInterfaceDecl_getVtblInterface_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDispInterfaceDecl_INTERFACE_DEFINED__ */


#ifndef __ITypedefDecl_INTERFACE_DEFINED__
#define __ITypedefDecl_INTERFACE_DEFINED__

/* interface ITypedefDecl */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ITypedefDecl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1FA456D6-6E48-4ff0-9BF8-300937470A02")
    ITypedefDecl : public ITypeDecl
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE getDefinition( 
            /* [retval][out] */ IType **ppType) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITypedefDeclVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITypedefDecl * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITypedefDecl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITypedefDecl * This);
        
        HRESULT ( STDMETHODCALLTYPE *getName )( 
            ITypedefDecl * This,
            /* [retval][out] */ BSTR *pName);
        
        HRESULT ( STDMETHODCALLTYPE *getHelpString )( 
            ITypedefDecl * This,
            /* [retval][out] */ BSTR *pHelpString);
        
        HRESULT ( STDMETHODCALLTYPE *getKind )( 
            ITypedefDecl * This,
            /* [retval][out] */ TypeKind *kind);
        
        HRESULT ( STDMETHODCALLTYPE *getParent )( 
            ITypedefDecl * This,
            /* [retval][out] */ ITypeLibrary **ppParent);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *getDefinition )( 
            ITypedefDecl * This,
            /* [retval][out] */ IType **ppType);
        
        END_INTERFACE
    } ITypedefDeclVtbl;

    interface ITypedefDecl
    {
        CONST_VTBL struct ITypedefDeclVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITypedefDecl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITypedefDecl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITypedefDecl_Release(This)	\
    (This)->lpVtbl -> Release(This)



#define ITypedefDecl_getName(This,pName)	\
    (This)->lpVtbl -> getName(This,pName)

#define ITypedefDecl_getHelpString(This,pHelpString)	\
    (This)->lpVtbl -> getHelpString(This,pHelpString)

#define ITypedefDecl_getKind(This,kind)	\
    (This)->lpVtbl -> getKind(This,kind)

#define ITypedefDecl_getParent(This,ppParent)	\
    (This)->lpVtbl -> getParent(This,ppParent)


#define ITypedefDecl_getDefinition(This,ppType)	\
    (This)->lpVtbl -> getDefinition(This,ppType)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ITypedefDecl_getDefinition_Proxy( 
    ITypedefDecl * This,
    /* [retval][out] */ IType **ppType);


void __RPC_STUB ITypedefDecl_getDefinition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITypedefDecl_INTERFACE_DEFINED__ */


#ifndef __IEnumDecl_INTERFACE_DEFINED__
#define __IEnumDecl_INTERFACE_DEFINED__

/* interface IEnumDecl */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEnumDecl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C99EBD48-0DF6-453d-94A8-BC004F69330F")
    IEnumDecl : public ITypeDecl
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE countConstants( 
            /* [retval][out] */ int *pNum) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE getConstant( 
            int index,
            /* [retval][out] */ IConstant **ppConstant) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumDeclVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumDecl * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumDecl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumDecl * This);
        
        HRESULT ( STDMETHODCALLTYPE *getName )( 
            IEnumDecl * This,
            /* [retval][out] */ BSTR *pName);
        
        HRESULT ( STDMETHODCALLTYPE *getHelpString )( 
            IEnumDecl * This,
            /* [retval][out] */ BSTR *pHelpString);
        
        HRESULT ( STDMETHODCALLTYPE *getKind )( 
            IEnumDecl * This,
            /* [retval][out] */ TypeKind *kind);
        
        HRESULT ( STDMETHODCALLTYPE *getParent )( 
            IEnumDecl * This,
            /* [retval][out] */ ITypeLibrary **ppParent);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *countConstants )( 
            IEnumDecl * This,
            /* [retval][out] */ int *pNum);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *getConstant )( 
            IEnumDecl * This,
            int index,
            /* [retval][out] */ IConstant **ppConstant);
        
        END_INTERFACE
    } IEnumDeclVtbl;

    interface IEnumDecl
    {
        CONST_VTBL struct IEnumDeclVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumDecl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumDecl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumDecl_Release(This)	\
    (This)->lpVtbl -> Release(This)



#define IEnumDecl_getName(This,pName)	\
    (This)->lpVtbl -> getName(This,pName)

#define IEnumDecl_getHelpString(This,pHelpString)	\
    (This)->lpVtbl -> getHelpString(This,pHelpString)

#define IEnumDecl_getKind(This,kind)	\
    (This)->lpVtbl -> getKind(This,kind)

#define IEnumDecl_getParent(This,ppParent)	\
    (This)->lpVtbl -> getParent(This,ppParent)


#define IEnumDecl_countConstants(This,pNum)	\
    (This)->lpVtbl -> countConstants(This,pNum)

#define IEnumDecl_getConstant(This,index,ppConstant)	\
    (This)->lpVtbl -> getConstant(This,index,ppConstant)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEnumDecl_countConstants_Proxy( 
    IEnumDecl * This,
    /* [retval][out] */ int *pNum);


void __RPC_STUB IEnumDecl_countConstants_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEnumDecl_getConstant_Proxy( 
    IEnumDecl * This,
    int index,
    /* [retval][out] */ IConstant **ppConstant);


void __RPC_STUB IEnumDecl_getConstant_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumDecl_INTERFACE_DEFINED__ */


#ifndef __ICoClassDecl_INTERFACE_DEFINED__
#define __ICoClassDecl_INTERFACE_DEFINED__

/* interface ICoClassDecl */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ICoClassDecl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A2F511E4-CC26-4337-A4F4-EA992190D082")
    ICoClassDecl : public ITypeDecl
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE countImplementedInterfaces( 
            /* [retval][out] */ int *pValue) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE getImplementedInterface( 
            int index,
            /* [retval][out] */ IImplementedInterfaceDecl **ppType) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE isCreatable( 
            /* [retval][out] */ VARIANT_BOOL *pOut) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE getGUID( 
            /* [retval][out] */ GUID *pValue) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICoClassDeclVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoClassDecl * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoClassDecl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoClassDecl * This);
        
        HRESULT ( STDMETHODCALLTYPE *getName )( 
            ICoClassDecl * This,
            /* [retval][out] */ BSTR *pName);
        
        HRESULT ( STDMETHODCALLTYPE *getHelpString )( 
            ICoClassDecl * This,
            /* [retval][out] */ BSTR *pHelpString);
        
        HRESULT ( STDMETHODCALLTYPE *getKind )( 
            ICoClassDecl * This,
            /* [retval][out] */ TypeKind *kind);
        
        HRESULT ( STDMETHODCALLTYPE *getParent )( 
            ICoClassDecl * This,
            /* [retval][out] */ ITypeLibrary **ppParent);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *countImplementedInterfaces )( 
            ICoClassDecl * This,
            /* [retval][out] */ int *pValue);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *getImplementedInterface )( 
            ICoClassDecl * This,
            int index,
            /* [retval][out] */ IImplementedInterfaceDecl **ppType);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *isCreatable )( 
            ICoClassDecl * This,
            /* [retval][out] */ VARIANT_BOOL *pOut);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *getGUID )( 
            ICoClassDecl * This,
            /* [retval][out] */ GUID *pValue);
        
        END_INTERFACE
    } ICoClassDeclVtbl;

    interface ICoClassDecl
    {
        CONST_VTBL struct ICoClassDeclVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoClassDecl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICoClassDecl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICoClassDecl_Release(This)	\
    (This)->lpVtbl -> Release(This)



#define ICoClassDecl_getName(This,pName)	\
    (This)->lpVtbl -> getName(This,pName)

#define ICoClassDecl_getHelpString(This,pHelpString)	\
    (This)->lpVtbl -> getHelpString(This,pHelpString)

#define ICoClassDecl_getKind(This,kind)	\
    (This)->lpVtbl -> getKind(This,kind)

#define ICoClassDecl_getParent(This,ppParent)	\
    (This)->lpVtbl -> getParent(This,ppParent)


#define ICoClassDecl_countImplementedInterfaces(This,pValue)	\
    (This)->lpVtbl -> countImplementedInterfaces(This,pValue)

#define ICoClassDecl_getImplementedInterface(This,index,ppType)	\
    (This)->lpVtbl -> getImplementedInterface(This,index,ppType)

#define ICoClassDecl_isCreatable(This,pOut)	\
    (This)->lpVtbl -> isCreatable(This,pOut)

#define ICoClassDecl_getGUID(This,pValue)	\
    (This)->lpVtbl -> getGUID(This,pValue)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ICoClassDecl_countImplementedInterfaces_Proxy( 
    ICoClassDecl * This,
    /* [retval][out] */ int *pValue);


void __RPC_STUB ICoClassDecl_countImplementedInterfaces_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ICoClassDecl_getImplementedInterface_Proxy( 
    ICoClassDecl * This,
    int index,
    /* [retval][out] */ IImplementedInterfaceDecl **ppType);


void __RPC_STUB ICoClassDecl_getImplementedInterface_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ICoClassDecl_isCreatable_Proxy( 
    ICoClassDecl * This,
    /* [retval][out] */ VARIANT_BOOL *pOut);


void __RPC_STUB ICoClassDecl_isCreatable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ICoClassDecl_getGUID_Proxy( 
    ICoClassDecl * This,
    /* [retval][out] */ GUID *pValue);


void __RPC_STUB ICoClassDecl_getGUID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICoClassDecl_INTERFACE_DEFINED__ */


#ifndef ___ITestObjectEvents_DISPINTERFACE_DEFINED__
#define ___ITestObjectEvents_DISPINTERFACE_DEFINED__

/* dispinterface _ITestObjectEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__ITestObjectEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("43863047-F4CF-4309-BCE6-7C7E2B11EE28")
    _ITestObjectEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _ITestObjectEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _ITestObjectEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _ITestObjectEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _ITestObjectEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _ITestObjectEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _ITestObjectEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _ITestObjectEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _ITestObjectEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _ITestObjectEventsVtbl;

    interface _ITestObjectEvents
    {
        CONST_VTBL struct _ITestObjectEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ITestObjectEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _ITestObjectEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _ITestObjectEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _ITestObjectEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _ITestObjectEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _ITestObjectEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _ITestObjectEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___ITestObjectEvents_DISPINTERFACE_DEFINED__ */


#ifndef __ITestObject_INTERFACE_DEFINED__
#define __ITestObject_INTERFACE_DEFINED__

/* interface ITestObject */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITestObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("55167E25-E6D1-4672-86C8-242AE001B7AB")
    ITestObject : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TestVariant( 
            /* [in] */ VARIANT v1,
            /* [out][in] */ VARIANT *v2,
            /* [retval][out] */ VARIANT *v3) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE outByteBuf( 
            /* [in] */ BSTR bstrEncodedData,
            /* [out] */ long *plSize,
            /* [out] */ unsigned char **ppbData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE echoInterface( 
            /* [in] */ IUnknown *arg,
            /* [retval][out] */ IUnknown **result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE testUI8Conv( 
            /* [in] */ VARIANT *pIn,
            /* [retval][out] */ VARIANT *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE testUI1Conv( 
            /* [in] */ VARIANT *pIn,
            /* [retval][out] */ VARIANT *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE testCurrency( 
            /* [in] */ CURRENCY *in1,
            /* [in] */ CURRENCY in2,
            /* [retval][out] */ CURRENCY *out) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITestObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITestObject * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITestObject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITestObject * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITestObject * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITestObject * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITestObject * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITestObject * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TestVariant )( 
            ITestObject * This,
            /* [in] */ VARIANT v1,
            /* [out][in] */ VARIANT *v2,
            /* [retval][out] */ VARIANT *v3);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *outByteBuf )( 
            ITestObject * This,
            /* [in] */ BSTR bstrEncodedData,
            /* [out] */ long *plSize,
            /* [out] */ unsigned char **ppbData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *echoInterface )( 
            ITestObject * This,
            /* [in] */ IUnknown *arg,
            /* [retval][out] */ IUnknown **result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *testUI8Conv )( 
            ITestObject * This,
            /* [in] */ VARIANT *pIn,
            /* [retval][out] */ VARIANT *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *testUI1Conv )( 
            ITestObject * This,
            /* [in] */ VARIANT *pIn,
            /* [retval][out] */ VARIANT *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *testCurrency )( 
            ITestObject * This,
            /* [in] */ CURRENCY *in1,
            /* [in] */ CURRENCY in2,
            /* [retval][out] */ CURRENCY *out);
        
        END_INTERFACE
    } ITestObjectVtbl;

    interface ITestObject
    {
        CONST_VTBL struct ITestObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITestObject_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITestObject_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITestObject_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITestObject_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ITestObject_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ITestObject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ITestObject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ITestObject_TestVariant(This,v1,v2,v3)	\
    (This)->lpVtbl -> TestVariant(This,v1,v2,v3)

#define ITestObject_outByteBuf(This,bstrEncodedData,plSize,ppbData)	\
    (This)->lpVtbl -> outByteBuf(This,bstrEncodedData,plSize,ppbData)

#define ITestObject_echoInterface(This,arg,result)	\
    (This)->lpVtbl -> echoInterface(This,arg,result)

#define ITestObject_testUI8Conv(This,pIn,ret)	\
    (This)->lpVtbl -> testUI8Conv(This,pIn,ret)

#define ITestObject_testUI1Conv(This,pIn,ret)	\
    (This)->lpVtbl -> testUI1Conv(This,pIn,ret)

#define ITestObject_testCurrency(This,in1,in2,out)	\
    (This)->lpVtbl -> testCurrency(This,in1,in2,out)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITestObject_TestVariant_Proxy( 
    ITestObject * This,
    /* [in] */ VARIANT v1,
    /* [out][in] */ VARIANT *v2,
    /* [retval][out] */ VARIANT *v3);


void __RPC_STUB ITestObject_TestVariant_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITestObject_outByteBuf_Proxy( 
    ITestObject * This,
    /* [in] */ BSTR bstrEncodedData,
    /* [out] */ long *plSize,
    /* [out] */ unsigned char **ppbData);


void __RPC_STUB ITestObject_outByteBuf_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITestObject_echoInterface_Proxy( 
    ITestObject * This,
    /* [in] */ IUnknown *arg,
    /* [retval][out] */ IUnknown **result);


void __RPC_STUB ITestObject_echoInterface_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITestObject_testUI8Conv_Proxy( 
    ITestObject * This,
    /* [in] */ VARIANT *pIn,
    /* [retval][out] */ VARIANT *ret);


void __RPC_STUB ITestObject_testUI8Conv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITestObject_testUI1Conv_Proxy( 
    ITestObject * This,
    /* [in] */ VARIANT *pIn,
    /* [retval][out] */ VARIANT *ret);


void __RPC_STUB ITestObject_testUI1Conv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITestObject_testCurrency_Proxy( 
    ITestObject * This,
    /* [in] */ CURRENCY *in1,
    /* [in] */ CURRENCY in2,
    /* [retval][out] */ CURRENCY *out);


void __RPC_STUB ITestObject_testCurrency_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITestObject_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_TestObject;

#ifdef __cplusplus

class DECLSPEC_UUID("E069E52A-704B-42DC-BF03-CE5C14C3B7B3")
TestObject;
#endif
#endif /* __com4j_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


