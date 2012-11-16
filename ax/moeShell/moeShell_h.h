

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0595 */
/* at Thu Nov 15 20:36:11 2012
 */
/* Compiler settings for moeShell.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0595 
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


#ifndef __moeShell_h_h__
#define __moeShell_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ImoeShell_FWD_DEFINED__
#define __ImoeShell_FWD_DEFINED__
typedef interface ImoeShell ImoeShell;

#endif 	/* __ImoeShell_FWD_DEFINED__ */


#ifndef __moeShell_FWD_DEFINED__
#define __moeShell_FWD_DEFINED__

#ifdef __cplusplus
typedef class moeShell moeShell;
#else
typedef struct moeShell moeShell;
#endif /* __cplusplus */

#endif 	/* __moeShell_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __moeShell_LIBRARY_DEFINED__
#define __moeShell_LIBRARY_DEFINED__

/* library moeShell */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_moeShell;

#ifndef __ImoeShell_INTERFACE_DEFINED__
#define __ImoeShell_INTERFACE_DEFINED__

/* interface ImoeShell */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_ImoeShell;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B5DE89C4-B9AC-4d5a-A2EA-C472D536D36B")
    ImoeShell : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE About( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ImoeShellVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ImoeShell * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ImoeShell * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ImoeShell * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ImoeShell * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ImoeShell * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ImoeShell * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ImoeShell * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *About )( 
            ImoeShell * This);
        
        END_INTERFACE
    } ImoeShellVtbl;

    interface ImoeShell
    {
        CONST_VTBL struct ImoeShellVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ImoeShell_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ImoeShell_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ImoeShell_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ImoeShell_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ImoeShell_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ImoeShell_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ImoeShell_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ImoeShell_About(This)	\
    ( (This)->lpVtbl -> About(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ImoeShell_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_moeShell;

#ifdef __cplusplus

class DECLSPEC_UUID("AF110465-5902-4db8-8DF3-FBA079547D08")
moeShell;
#endif
#endif /* __moeShell_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


