

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Sun Sep 18 21:07:27 2011
 */
/* Compiler settings for process.idl:
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


#ifndef __pipedprocess_h_h__
#define __pipedprocess_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IPipedProcess_FWD_DEFINED__
#define __IPipedProcess_FWD_DEFINED__
typedef interface IPipedProcess IPipedProcess;
#endif 	/* __IPipedProcess_FWD_DEFINED__ */


#ifndef ___IPipedProcessComplete_FWD_DEFINED__
#define ___IPipedProcessComplete_FWD_DEFINED__
typedef interface _IPipedProcessComplete _IPipedProcessComplete;
#endif 	/* ___IPipedProcessComplete_FWD_DEFINED__ */


#ifndef __IPipedProcessCompleteDual_FWD_DEFINED__
#define __IPipedProcessCompleteDual_FWD_DEFINED__
typedef interface IPipedProcessCompleteDual IPipedProcessCompleteDual;
#endif 	/* __IPipedProcessCompleteDual_FWD_DEFINED__ */


#ifndef __PipedProcessControl_FWD_DEFINED__
#define __PipedProcessControl_FWD_DEFINED__

#ifdef __cplusplus
typedef class PipedProcessControl PipedProcessControl;
#else
typedef struct PipedProcessControl PipedProcessControl;
#endif /* __cplusplus */

#endif 	/* __PipedProcessControl_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __PipedProcess_LIBRARY_DEFINED__
#define __PipedProcess_LIBRARY_DEFINED__

/* library PipedProcess */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_PipedProcess;

#ifndef __IPipedProcess_INTERFACE_DEFINED__
#define __IPipedProcess_INTERFACE_DEFINED__

/* interface IPipedProcess */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IPipedProcess;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("263ABFD3-6D9F-4c0b-861A-4D22E0AA9529")
    IPipedProcess : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Async( 
            /* [retval][out] */ VARIANT_BOOL *vb) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Async( 
            /* [in] */ VARIANT_BOOL vb) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_readyState( 
            /* [retval][out] */ long *state) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Eof( 
            /* [retval][out] */ VARIANT_BOOL *vb) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ErrEof( 
            /* [retval][out] */ VARIANT_BOOL *vb) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Create( 
            /* [in] */ BSTR cmdline,
            /* [retval][out] */ VARIANT_BOOL *vbSuccess) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Write( 
            /* [in] */ BSTR s,
            /* [retval][out] */ VARIANT_BOOL *vbSuccess) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CloseOut( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadLine( 
            /* [retval][out] */ BSTR *line) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadErrLine( 
            /* [retval][out] */ BSTR *line) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Terminate( void) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_onComplete( 
            /* [in] */ IDispatch *onCompleteHandler) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPipedProcessVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPipedProcess * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPipedProcess * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPipedProcess * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPipedProcess * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPipedProcess * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPipedProcess * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPipedProcess * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Async )( 
            IPipedProcess * This,
            /* [retval][out] */ VARIANT_BOOL *vb);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Async )( 
            IPipedProcess * This,
            /* [in] */ VARIANT_BOOL vb);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_readyState )( 
            IPipedProcess * This,
            /* [retval][out] */ long *state);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Eof )( 
            IPipedProcess * This,
            /* [retval][out] */ VARIANT_BOOL *vb);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ErrEof )( 
            IPipedProcess * This,
            /* [retval][out] */ VARIANT_BOOL *vb);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Create )( 
            IPipedProcess * This,
            /* [in] */ BSTR cmdline,
            /* [retval][out] */ VARIANT_BOOL *vbSuccess);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Write )( 
            IPipedProcess * This,
            /* [in] */ BSTR s,
            /* [retval][out] */ VARIANT_BOOL *vbSuccess);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CloseOut )( 
            IPipedProcess * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadLine )( 
            IPipedProcess * This,
            /* [retval][out] */ BSTR *line);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadErrLine )( 
            IPipedProcess * This,
            /* [retval][out] */ BSTR *line);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IPipedProcess * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Terminate )( 
            IPipedProcess * This);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_onComplete )( 
            IPipedProcess * This,
            /* [in] */ IDispatch *onCompleteHandler);
        
        END_INTERFACE
    } IPipedProcessVtbl;

    interface IPipedProcess
    {
        CONST_VTBL struct IPipedProcessVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPipedProcess_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPipedProcess_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPipedProcess_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPipedProcess_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IPipedProcess_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IPipedProcess_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IPipedProcess_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IPipedProcess_get_Async(This,vb)	\
    ( (This)->lpVtbl -> get_Async(This,vb) ) 

#define IPipedProcess_put_Async(This,vb)	\
    ( (This)->lpVtbl -> put_Async(This,vb) ) 

#define IPipedProcess_get_readyState(This,state)	\
    ( (This)->lpVtbl -> get_readyState(This,state) ) 

#define IPipedProcess_get_Eof(This,vb)	\
    ( (This)->lpVtbl -> get_Eof(This,vb) ) 

#define IPipedProcess_get_ErrEof(This,vb)	\
    ( (This)->lpVtbl -> get_ErrEof(This,vb) ) 

#define IPipedProcess_Create(This,cmdline,vbSuccess)	\
    ( (This)->lpVtbl -> Create(This,cmdline,vbSuccess) ) 

#define IPipedProcess_Write(This,s,vbSuccess)	\
    ( (This)->lpVtbl -> Write(This,s,vbSuccess) ) 

#define IPipedProcess_CloseOut(This)	\
    ( (This)->lpVtbl -> CloseOut(This) ) 

#define IPipedProcess_ReadLine(This,line)	\
    ( (This)->lpVtbl -> ReadLine(This,line) ) 

#define IPipedProcess_ReadErrLine(This,line)	\
    ( (This)->lpVtbl -> ReadErrLine(This,line) ) 

#define IPipedProcess_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IPipedProcess_Terminate(This)	\
    ( (This)->lpVtbl -> Terminate(This) ) 

#define IPipedProcess_put_onComplete(This,onCompleteHandler)	\
    ( (This)->lpVtbl -> put_onComplete(This,onCompleteHandler) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPipedProcess_INTERFACE_DEFINED__ */


#ifndef ___IPipedProcessComplete_DISPINTERFACE_DEFINED__
#define ___IPipedProcessComplete_DISPINTERFACE_DEFINED__

/* dispinterface _IPipedProcessComplete */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IPipedProcessComplete;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("2CA957E0-4A1D-4e57-AA42-94E9B0701B26")
    _IPipedProcessComplete : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IPipedProcessCompleteVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IPipedProcessComplete * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IPipedProcessComplete * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IPipedProcessComplete * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IPipedProcessComplete * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IPipedProcessComplete * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IPipedProcessComplete * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IPipedProcessComplete * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IPipedProcessCompleteVtbl;

    interface _IPipedProcessComplete
    {
        CONST_VTBL struct _IPipedProcessCompleteVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IPipedProcessComplete_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IPipedProcessComplete_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IPipedProcessComplete_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IPipedProcessComplete_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IPipedProcessComplete_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IPipedProcessComplete_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IPipedProcessComplete_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IPipedProcessComplete_DISPINTERFACE_DEFINED__ */


#ifndef __IPipedProcessCompleteDual_INTERFACE_DEFINED__
#define __IPipedProcessCompleteDual_INTERFACE_DEFINED__

/* interface IPipedProcessCompleteDual */
/* [object][dual][oleautomation][helpstring][uuid] */ 


EXTERN_C const IID IID_IPipedProcessCompleteDual;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7FBB9268-45D9-43df-BE32-A5FFED60B456")
    IPipedProcessCompleteDual : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnComplete( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPipedProcessCompleteDualVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPipedProcessCompleteDual * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPipedProcessCompleteDual * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPipedProcessCompleteDual * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPipedProcessCompleteDual * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPipedProcessCompleteDual * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPipedProcessCompleteDual * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPipedProcessCompleteDual * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnComplete )( 
            IPipedProcessCompleteDual * This);
        
        END_INTERFACE
    } IPipedProcessCompleteDualVtbl;

    interface IPipedProcessCompleteDual
    {
        CONST_VTBL struct IPipedProcessCompleteDualVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPipedProcessCompleteDual_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPipedProcessCompleteDual_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPipedProcessCompleteDual_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPipedProcessCompleteDual_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IPipedProcessCompleteDual_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IPipedProcessCompleteDual_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IPipedProcessCompleteDual_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IPipedProcessCompleteDual_OnComplete(This)	\
    ( (This)->lpVtbl -> OnComplete(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPipedProcessCompleteDual_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_PipedProcessControl;

#ifdef __cplusplus

class DECLSPEC_UUID("3E08871B-09B9-4e04-B9F7-64D2F9F4E854")
PipedProcessControl;
#endif
#endif /* __PipedProcess_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


