

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0595 */
/* at Sat Nov 17 22:27:20 2012
 */
/* Compiler settings for sshShell.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.00.0595 
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


#ifndef __sshShell_h_h__
#define __sshShell_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ISshShell_FWD_DEFINED__
#define __ISshShell_FWD_DEFINED__
typedef interface ISshShell ISshShell;

#endif 	/* __ISshShell_FWD_DEFINED__ */


#ifndef __sshShell_FWD_DEFINED__
#define __sshShell_FWD_DEFINED__

#ifdef __cplusplus
typedef class sshShell sshShell;
#else
typedef struct sshShell sshShell;
#endif /* __cplusplus */

#endif 	/* __sshShell_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __sshShell_LIBRARY_DEFINED__
#define __sshShell_LIBRARY_DEFINED__

/* library sshShell */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_sshShell;

#ifndef __ISshShell_INTERFACE_DEFINED__
#define __ISshShell_INTERFACE_DEFINED__

/* interface ISshShell */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_ISshShell;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("60895968-A3DA-46FF-A72F-05243361B8E3")
    ISshShell : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE About( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISshShellVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISshShell * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISshShell * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISshShell * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISshShell * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISshShell * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISshShell * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISshShell * This,
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
            ISshShell * This);
        
        END_INTERFACE
    } ISshShellVtbl;

    interface ISshShell
    {
        CONST_VTBL struct ISshShellVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISshShell_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISshShell_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISshShell_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISshShell_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISshShell_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISshShell_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISshShell_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISshShell_About(This)	\
    ( (This)->lpVtbl -> About(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISshShell_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_sshShell;

#ifdef __cplusplus

class DECLSPEC_UUID("6E8A9382-C824-45F4-9744-EC075876AAAB")
sshShell;
#endif
#endif /* __sshShell_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


