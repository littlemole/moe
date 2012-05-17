

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Thu May 17 14:15:38 2012
 */
/* Compiler settings for shellfolder.idl:
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


#ifndef __shellfolder_h_h__
#define __shellfolder_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IShellPane_FWD_DEFINED__
#define __IShellPane_FWD_DEFINED__
typedef interface IShellPane IShellPane;
#endif 	/* __IShellPane_FWD_DEFINED__ */


#ifndef ___IShellPaneEvents_FWD_DEFINED__
#define ___IShellPaneEvents_FWD_DEFINED__
typedef interface _IShellPaneEvents _IShellPaneEvents;
#endif 	/* ___IShellPaneEvents_FWD_DEFINED__ */


#ifndef __IShellPaneEvents_FWD_DEFINED__
#define __IShellPaneEvents_FWD_DEFINED__
typedef interface IShellPaneEvents IShellPaneEvents;
#endif 	/* __IShellPaneEvents_FWD_DEFINED__ */


#ifndef __ShellPane_FWD_DEFINED__
#define __ShellPane_FWD_DEFINED__

#ifdef __cplusplus
typedef class ShellPane ShellPane;
#else
typedef struct ShellPane ShellPane;
#endif /* __cplusplus */

#endif 	/* __ShellPane_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __ShellFolder_LIBRARY_DEFINED__
#define __ShellFolder_LIBRARY_DEFINED__

/* library ShellFolder */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ShellFolder;

#ifndef __IShellPane_INTERFACE_DEFINED__
#define __IShellPane_INTERFACE_DEFINED__

/* interface IShellPane */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IShellPane;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8E03AB4B-E12B-42a2-905D-F106854C7153")
    IShellPane : public IDispatch
    {
    public:
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_DisplayFiles( 
            /* [in] */ VARIANT_BOOL vb) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_DisplayFiles( 
            /* [retval][out] */ VARIANT_BOOL *vb) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][defaultbind][propput] */ HRESULT STDMETHODCALLTYPE put_Selection( 
            /* [in] */ VARIANT fname) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][defaultbind][propget] */ HRESULT STDMETHODCALLTYPE get_Selection( 
            /* [retval][out] */ VARIANT *fname) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HasFocus( 
            /* [retval][out] */ VARIANT_BOOL *vbHasFocus) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Update( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Cut( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Copy( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Paste( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Rename( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Properties( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Execute( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateDir( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UpDir( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IShellPaneVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IShellPane * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IShellPane * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IShellPane * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IShellPane * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IShellPane * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IShellPane * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IShellPane * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DisplayFiles )( 
            IShellPane * This,
            /* [in] */ VARIANT_BOOL vb);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DisplayFiles )( 
            IShellPane * This,
            /* [retval][out] */ VARIANT_BOOL *vb);
        
        /* [helpstring][id][requestedit][displaybind][bindable][defaultbind][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Selection )( 
            IShellPane * This,
            /* [in] */ VARIANT fname);
        
        /* [id][requestedit][displaybind][bindable][defaultbind][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Selection )( 
            IShellPane * This,
            /* [retval][out] */ VARIANT *fname);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HasFocus )( 
            IShellPane * This,
            /* [retval][out] */ VARIANT_BOOL *vbHasFocus);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Update )( 
            IShellPane * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Cut )( 
            IShellPane * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IShellPane * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Paste )( 
            IShellPane * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rename )( 
            IShellPane * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IShellPane * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Properties )( 
            IShellPane * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Execute )( 
            IShellPane * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateDir )( 
            IShellPane * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpDir )( 
            IShellPane * This);
        
        END_INTERFACE
    } IShellPaneVtbl;

    interface IShellPane
    {
        CONST_VTBL struct IShellPaneVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IShellPane_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IShellPane_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IShellPane_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IShellPane_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IShellPane_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IShellPane_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IShellPane_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IShellPane_put_DisplayFiles(This,vb)	\
    ( (This)->lpVtbl -> put_DisplayFiles(This,vb) ) 

#define IShellPane_get_DisplayFiles(This,vb)	\
    ( (This)->lpVtbl -> get_DisplayFiles(This,vb) ) 

#define IShellPane_put_Selection(This,fname)	\
    ( (This)->lpVtbl -> put_Selection(This,fname) ) 

#define IShellPane_get_Selection(This,fname)	\
    ( (This)->lpVtbl -> get_Selection(This,fname) ) 

#define IShellPane_get_HasFocus(This,vbHasFocus)	\
    ( (This)->lpVtbl -> get_HasFocus(This,vbHasFocus) ) 

#define IShellPane_Update(This)	\
    ( (This)->lpVtbl -> Update(This) ) 

#define IShellPane_Cut(This)	\
    ( (This)->lpVtbl -> Cut(This) ) 

#define IShellPane_Copy(This)	\
    ( (This)->lpVtbl -> Copy(This) ) 

#define IShellPane_Paste(This)	\
    ( (This)->lpVtbl -> Paste(This) ) 

#define IShellPane_Rename(This)	\
    ( (This)->lpVtbl -> Rename(This) ) 

#define IShellPane_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IShellPane_Properties(This)	\
    ( (This)->lpVtbl -> Properties(This) ) 

#define IShellPane_Execute(This)	\
    ( (This)->lpVtbl -> Execute(This) ) 

#define IShellPane_CreateDir(This)	\
    ( (This)->lpVtbl -> CreateDir(This) ) 

#define IShellPane_UpDir(This)	\
    ( (This)->lpVtbl -> UpDir(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IShellPane_INTERFACE_DEFINED__ */


#ifndef ___IShellPaneEvents_DISPINTERFACE_DEFINED__
#define ___IShellPaneEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IShellPaneEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IShellPaneEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("8B2BD8F4-8788-4968-AB28-C409FF1A88CF")
    _IShellPaneEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IShellPaneEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IShellPaneEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IShellPaneEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IShellPaneEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IShellPaneEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IShellPaneEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IShellPaneEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IShellPaneEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IShellPaneEventsVtbl;

    interface _IShellPaneEvents
    {
        CONST_VTBL struct _IShellPaneEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IShellPaneEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IShellPaneEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IShellPaneEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IShellPaneEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IShellPaneEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IShellPaneEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IShellPaneEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IShellPaneEvents_DISPINTERFACE_DEFINED__ */


#ifndef __IShellPaneEvents_INTERFACE_DEFINED__
#define __IShellPaneEvents_INTERFACE_DEFINED__

/* interface IShellPaneEvents */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IShellPaneEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3B3FF6F3-D0DB-4ada-A593-D99E6F79E6D1")
    IShellPaneEvents : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnListSelection( 
            /* [in] */ BSTR fname) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnListDblClick( 
            /* [in] */ BSTR fname) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnListOpen( 
            /* [in] */ BSTR fname) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnDirChanged( 
            /* [in] */ BSTR dir) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IShellPaneEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IShellPaneEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IShellPaneEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IShellPaneEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IShellPaneEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IShellPaneEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IShellPaneEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IShellPaneEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnListSelection )( 
            IShellPaneEvents * This,
            /* [in] */ BSTR fname);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnListDblClick )( 
            IShellPaneEvents * This,
            /* [in] */ BSTR fname);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnListOpen )( 
            IShellPaneEvents * This,
            /* [in] */ BSTR fname);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnDirChanged )( 
            IShellPaneEvents * This,
            /* [in] */ BSTR dir);
        
        END_INTERFACE
    } IShellPaneEventsVtbl;

    interface IShellPaneEvents
    {
        CONST_VTBL struct IShellPaneEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IShellPaneEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IShellPaneEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IShellPaneEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IShellPaneEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IShellPaneEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IShellPaneEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IShellPaneEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IShellPaneEvents_OnListSelection(This,fname)	\
    ( (This)->lpVtbl -> OnListSelection(This,fname) ) 

#define IShellPaneEvents_OnListDblClick(This,fname)	\
    ( (This)->lpVtbl -> OnListDblClick(This,fname) ) 

#define IShellPaneEvents_OnListOpen(This,fname)	\
    ( (This)->lpVtbl -> OnListOpen(This,fname) ) 

#define IShellPaneEvents_OnDirChanged(This,dir)	\
    ( (This)->lpVtbl -> OnDirChanged(This,dir) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IShellPaneEvents_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ShellPane;

#ifdef __cplusplus

class DECLSPEC_UUID("3609D58F-1D8E-437d-BA8A-11A5DBF59BAD")
ShellPane;
#endif
#endif /* __ShellFolder_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


