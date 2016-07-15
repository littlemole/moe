

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Mon Jul 11 19:14:06 2016
 */
/* Compiler settings for userform.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.00.0603 
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


#ifndef __userforms_h_h__
#define __userforms_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IMoeUserForm_FWD_DEFINED__
#define __IMoeUserForm_FWD_DEFINED__
typedef interface IMoeUserForm IMoeUserForm;

#endif 	/* __IMoeUserForm_FWD_DEFINED__ */


#ifndef __UserFormRunner_FWD_DEFINED__
#define __UserFormRunner_FWD_DEFINED__

#ifdef __cplusplus
typedef class UserFormRunner UserFormRunner;
#else
typedef struct UserFormRunner UserFormRunner;
#endif /* __cplusplus */

#endif 	/* __UserFormRunner_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __MoeUserForm_LIBRARY_DEFINED__
#define __MoeUserForm_LIBRARY_DEFINED__

/* library MoeUserForm */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_MoeUserForm;

#ifndef __IMoeUserForm_INTERFACE_DEFINED__
#define __IMoeUserForm_INTERFACE_DEFINED__

/* interface IMoeUserForm */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IMoeUserForm;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0DFFAACE-906D-4545-853A-BEE593283BDB")
    IMoeUserForm : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ VARIANT index,
            /* [retval][out] */ IDispatch **d) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Controls( 
            /* [retval][out] */ IDispatch **d) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Script( 
            /* [retval][out] */ IDispatch **s) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Show( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Hide( void) = 0;
        
        virtual /* [helpstring][id][requestedit] */ HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ IDispatch *scriptDispatch,
            /* [in] */ BSTR filename,
            VARIANT_BOOL designMode) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Top( 
            /* [in] */ long t) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Top( 
            /* [retval][out] */ long *t) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Left( 
            /* [in] */ long l) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Left( 
            /* [retval][out] */ long *l) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Height( 
            /* [in] */ long h) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Height( 
            /* [retval][out] */ long *h) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Width( 
            /* [in] */ long w) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Width( 
            /* [retval][out] */ long *w) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Title( 
            /* [in] */ BSTR t) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Title( 
            /* [retval][out] */ BSTR *t) = 0;
        
        virtual /* [id][requestedit] */ HRESULT STDMETHODCALLTYPE Save( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IMoeUserFormVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMoeUserForm * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMoeUserForm * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMoeUserForm * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMoeUserForm * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMoeUserForm * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMoeUserForm * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMoeUserForm * This,
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
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            IMoeUserForm * This,
            /* [in] */ VARIANT index,
            /* [retval][out] */ IDispatch **d);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Controls )( 
            IMoeUserForm * This,
            /* [retval][out] */ IDispatch **d);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Script )( 
            IMoeUserForm * This,
            /* [retval][out] */ IDispatch **s);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Show )( 
            IMoeUserForm * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IMoeUserForm * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Hide )( 
            IMoeUserForm * This);
        
        /* [helpstring][id][requestedit] */ HRESULT ( STDMETHODCALLTYPE *Load )( 
            IMoeUserForm * This,
            /* [in] */ IDispatch *scriptDispatch,
            /* [in] */ BSTR filename,
            VARIANT_BOOL designMode);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Top )( 
            IMoeUserForm * This,
            /* [in] */ long t);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Top )( 
            IMoeUserForm * This,
            /* [retval][out] */ long *t);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Left )( 
            IMoeUserForm * This,
            /* [in] */ long l);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Left )( 
            IMoeUserForm * This,
            /* [retval][out] */ long *l);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Height )( 
            IMoeUserForm * This,
            /* [in] */ long h);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Height )( 
            IMoeUserForm * This,
            /* [retval][out] */ long *h);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Width )( 
            IMoeUserForm * This,
            /* [in] */ long w);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Width )( 
            IMoeUserForm * This,
            /* [retval][out] */ long *w);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Title )( 
            IMoeUserForm * This,
            /* [in] */ BSTR t);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Title )( 
            IMoeUserForm * This,
            /* [retval][out] */ BSTR *t);
        
        /* [id][requestedit] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IMoeUserForm * This);
        
        END_INTERFACE
    } IMoeUserFormVtbl;

    interface IMoeUserForm
    {
        CONST_VTBL struct IMoeUserFormVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMoeUserForm_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMoeUserForm_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMoeUserForm_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMoeUserForm_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMoeUserForm_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMoeUserForm_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMoeUserForm_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMoeUserForm_Item(This,index,d)	\
    ( (This)->lpVtbl -> Item(This,index,d) ) 

#define IMoeUserForm_get_Controls(This,d)	\
    ( (This)->lpVtbl -> get_Controls(This,d) ) 

#define IMoeUserForm_get_Script(This,s)	\
    ( (This)->lpVtbl -> get_Script(This,s) ) 

#define IMoeUserForm_Show(This)	\
    ( (This)->lpVtbl -> Show(This) ) 

#define IMoeUserForm_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IMoeUserForm_Hide(This)	\
    ( (This)->lpVtbl -> Hide(This) ) 

#define IMoeUserForm_Load(This,scriptDispatch,filename,designMode)	\
    ( (This)->lpVtbl -> Load(This,scriptDispatch,filename,designMode) ) 

#define IMoeUserForm_put_Top(This,t)	\
    ( (This)->lpVtbl -> put_Top(This,t) ) 

#define IMoeUserForm_get_Top(This,t)	\
    ( (This)->lpVtbl -> get_Top(This,t) ) 

#define IMoeUserForm_put_Left(This,l)	\
    ( (This)->lpVtbl -> put_Left(This,l) ) 

#define IMoeUserForm_get_Left(This,l)	\
    ( (This)->lpVtbl -> get_Left(This,l) ) 

#define IMoeUserForm_put_Height(This,h)	\
    ( (This)->lpVtbl -> put_Height(This,h) ) 

#define IMoeUserForm_get_Height(This,h)	\
    ( (This)->lpVtbl -> get_Height(This,h) ) 

#define IMoeUserForm_put_Width(This,w)	\
    ( (This)->lpVtbl -> put_Width(This,w) ) 

#define IMoeUserForm_get_Width(This,w)	\
    ( (This)->lpVtbl -> get_Width(This,w) ) 

#define IMoeUserForm_put_Title(This,t)	\
    ( (This)->lpVtbl -> put_Title(This,t) ) 

#define IMoeUserForm_get_Title(This,t)	\
    ( (This)->lpVtbl -> get_Title(This,t) ) 

#define IMoeUserForm_Save(This)	\
    ( (This)->lpVtbl -> Save(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMoeUserForm_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_UserFormRunner;

#ifdef __cplusplus

class DECLSPEC_UUID("156CEEA7-89BF-467B-BAFE-E673219B54BE")
UserFormRunner;
#endif
#endif /* __MoeUserForm_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


