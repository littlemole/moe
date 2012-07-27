

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Fri Jul 27 22:44:44 2012
 */
/* Compiler settings for shellCtrl.idl:
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


#ifndef __shellCtrl_h_h__
#define __shellCtrl_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IShellTree_FWD_DEFINED__
#define __IShellTree_FWD_DEFINED__
typedef interface IShellTree IShellTree;
#endif 	/* __IShellTree_FWD_DEFINED__ */


#ifndef __IHexCtrl_FWD_DEFINED__
#define __IHexCtrl_FWD_DEFINED__
typedef interface IHexCtrl IHexCtrl;
#endif 	/* __IHexCtrl_FWD_DEFINED__ */


#ifndef __IShellList_FWD_DEFINED__
#define __IShellList_FWD_DEFINED__
typedef interface IShellList IShellList;
#endif 	/* __IShellList_FWD_DEFINED__ */


#ifndef __IScpList_FWD_DEFINED__
#define __IScpList_FWD_DEFINED__
typedef interface IScpList IScpList;
#endif 	/* __IScpList_FWD_DEFINED__ */


#ifndef __IColorPicker_FWD_DEFINED__
#define __IColorPicker_FWD_DEFINED__
typedef interface IColorPicker IColorPicker;
#endif 	/* __IColorPicker_FWD_DEFINED__ */


#ifndef __IPID_FWD_DEFINED__
#define __IPID_FWD_DEFINED__
typedef interface IPID IPID;
#endif 	/* __IPID_FWD_DEFINED__ */


#ifndef __IKillRoy_FWD_DEFINED__
#define __IKillRoy_FWD_DEFINED__
typedef interface IKillRoy IKillRoy;
#endif 	/* __IKillRoy_FWD_DEFINED__ */


#ifndef ___IShellTreeEvents_FWD_DEFINED__
#define ___IShellTreeEvents_FWD_DEFINED__
typedef interface _IShellTreeEvents _IShellTreeEvents;
#endif 	/* ___IShellTreeEvents_FWD_DEFINED__ */


#ifndef ___IHexCtrlEvents_FWD_DEFINED__
#define ___IHexCtrlEvents_FWD_DEFINED__
typedef interface _IHexCtrlEvents _IHexCtrlEvents;
#endif 	/* ___IHexCtrlEvents_FWD_DEFINED__ */


#ifndef ___IShellListEvents_FWD_DEFINED__
#define ___IShellListEvents_FWD_DEFINED__
typedef interface _IShellListEvents _IShellListEvents;
#endif 	/* ___IShellListEvents_FWD_DEFINED__ */


#ifndef __IShellTreeEvents_FWD_DEFINED__
#define __IShellTreeEvents_FWD_DEFINED__
typedef interface IShellTreeEvents IShellTreeEvents;
#endif 	/* __IShellTreeEvents_FWD_DEFINED__ */


#ifndef __IShellListEvents_FWD_DEFINED__
#define __IShellListEvents_FWD_DEFINED__
typedef interface IShellListEvents IShellListEvents;
#endif 	/* __IShellListEvents_FWD_DEFINED__ */


#ifndef __IHexCtrlEvents_FWD_DEFINED__
#define __IHexCtrlEvents_FWD_DEFINED__
typedef interface IHexCtrlEvents IHexCtrlEvents;
#endif 	/* __IHexCtrlEvents_FWD_DEFINED__ */


#ifndef __ShellTree_FWD_DEFINED__
#define __ShellTree_FWD_DEFINED__

#ifdef __cplusplus
typedef class ShellTree ShellTree;
#else
typedef struct ShellTree ShellTree;
#endif /* __cplusplus */

#endif 	/* __ShellTree_FWD_DEFINED__ */


#ifndef __ShellList_FWD_DEFINED__
#define __ShellList_FWD_DEFINED__

#ifdef __cplusplus
typedef class ShellList ShellList;
#else
typedef struct ShellList ShellList;
#endif /* __cplusplus */

#endif 	/* __ShellList_FWD_DEFINED__ */


#ifndef __ColorDialog_FWD_DEFINED__
#define __ColorDialog_FWD_DEFINED__

#ifdef __cplusplus
typedef class ColorDialog ColorDialog;
#else
typedef struct ColorDialog ColorDialog;
#endif /* __cplusplus */

#endif 	/* __ColorDialog_FWD_DEFINED__ */


#ifndef __HexCtrl_FWD_DEFINED__
#define __HexCtrl_FWD_DEFINED__

#ifdef __cplusplus
typedef class HexCtrl HexCtrl;
#else
typedef struct HexCtrl HexCtrl;
#endif /* __cplusplus */

#endif 	/* __HexCtrl_FWD_DEFINED__ */


#ifndef __ScpList_FWD_DEFINED__
#define __ScpList_FWD_DEFINED__

#ifdef __cplusplus
typedef class ScpList ScpList;
#else
typedef struct ScpList ScpList;
#endif /* __cplusplus */

#endif 	/* __ScpList_FWD_DEFINED__ */


#ifndef __KillRoy_FWD_DEFINED__
#define __KillRoy_FWD_DEFINED__

#ifdef __cplusplus
typedef class KillRoy KillRoy;
#else
typedef struct KillRoy KillRoy;
#endif /* __cplusplus */

#endif 	/* __KillRoy_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_shellCtrl_0000_0000 */
/* [local] */ 

#include "..\ssh\ssh_h.h" 



extern RPC_IF_HANDLE __MIDL_itf_shellCtrl_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_shellCtrl_0000_0000_v0_0_s_ifspec;


#ifndef __ShellCtrls_LIBRARY_DEFINED__
#define __ShellCtrls_LIBRARY_DEFINED__

/* library ShellCtrls */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ShellCtrls;

#ifndef __IShellTree_INTERFACE_DEFINED__
#define __IShellTree_INTERFACE_DEFINED__

/* interface IShellTree */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IShellTree;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("67282F00-10CA-4540-92B1-37DF10A3CD7B")
    IShellTree : public IDispatch
    {
    public:
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_DisplayFiles( 
            /* [in] */ VARIANT_BOOL vb) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_DisplayFiles( 
            /* [retval][out] */ VARIANT_BOOL *vb) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Selection( 
            /* [in] */ BSTR fname) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Selection( 
            /* [retval][out] */ BSTR *fname) = 0;
        
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
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddFolder( 
            /* [in] */ BSTR dname) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveFolder( 
            /* [in] */ BSTR dname) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateDir( void) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UseContext( 
            /* [in] */ VARIANT_BOOL vb) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_UseContext( 
            /* [retval][out] */ VARIANT_BOOL *vb) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsDir( 
            /* [in] */ BSTR path,
            /* [retval][out] */ VARIANT_BOOL *vb) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IShellTreeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IShellTree * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IShellTree * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IShellTree * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IShellTree * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IShellTree * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IShellTree * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IShellTree * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DisplayFiles )( 
            IShellTree * This,
            /* [in] */ VARIANT_BOOL vb);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DisplayFiles )( 
            IShellTree * This,
            /* [retval][out] */ VARIANT_BOOL *vb);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Selection )( 
            IShellTree * This,
            /* [in] */ BSTR fname);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Selection )( 
            IShellTree * This,
            /* [retval][out] */ BSTR *fname);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HasFocus )( 
            IShellTree * This,
            /* [retval][out] */ VARIANT_BOOL *vbHasFocus);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Update )( 
            IShellTree * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Cut )( 
            IShellTree * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IShellTree * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Paste )( 
            IShellTree * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rename )( 
            IShellTree * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IShellTree * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Properties )( 
            IShellTree * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Execute )( 
            IShellTree * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddFolder )( 
            IShellTree * This,
            /* [in] */ BSTR dname);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveFolder )( 
            IShellTree * This,
            /* [in] */ BSTR dname);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateDir )( 
            IShellTree * This);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseContext )( 
            IShellTree * This,
            /* [in] */ VARIANT_BOOL vb);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseContext )( 
            IShellTree * This,
            /* [retval][out] */ VARIANT_BOOL *vb);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsDir )( 
            IShellTree * This,
            /* [in] */ BSTR path,
            /* [retval][out] */ VARIANT_BOOL *vb);
        
        END_INTERFACE
    } IShellTreeVtbl;

    interface IShellTree
    {
        CONST_VTBL struct IShellTreeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IShellTree_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IShellTree_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IShellTree_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IShellTree_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IShellTree_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IShellTree_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IShellTree_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IShellTree_put_DisplayFiles(This,vb)	\
    ( (This)->lpVtbl -> put_DisplayFiles(This,vb) ) 

#define IShellTree_get_DisplayFiles(This,vb)	\
    ( (This)->lpVtbl -> get_DisplayFiles(This,vb) ) 

#define IShellTree_put_Selection(This,fname)	\
    ( (This)->lpVtbl -> put_Selection(This,fname) ) 

#define IShellTree_get_Selection(This,fname)	\
    ( (This)->lpVtbl -> get_Selection(This,fname) ) 

#define IShellTree_get_HasFocus(This,vbHasFocus)	\
    ( (This)->lpVtbl -> get_HasFocus(This,vbHasFocus) ) 

#define IShellTree_Update(This)	\
    ( (This)->lpVtbl -> Update(This) ) 

#define IShellTree_Cut(This)	\
    ( (This)->lpVtbl -> Cut(This) ) 

#define IShellTree_Copy(This)	\
    ( (This)->lpVtbl -> Copy(This) ) 

#define IShellTree_Paste(This)	\
    ( (This)->lpVtbl -> Paste(This) ) 

#define IShellTree_Rename(This)	\
    ( (This)->lpVtbl -> Rename(This) ) 

#define IShellTree_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IShellTree_Properties(This)	\
    ( (This)->lpVtbl -> Properties(This) ) 

#define IShellTree_Execute(This)	\
    ( (This)->lpVtbl -> Execute(This) ) 

#define IShellTree_AddFolder(This,dname)	\
    ( (This)->lpVtbl -> AddFolder(This,dname) ) 

#define IShellTree_RemoveFolder(This,dname)	\
    ( (This)->lpVtbl -> RemoveFolder(This,dname) ) 

#define IShellTree_CreateDir(This)	\
    ( (This)->lpVtbl -> CreateDir(This) ) 

#define IShellTree_put_UseContext(This,vb)	\
    ( (This)->lpVtbl -> put_UseContext(This,vb) ) 

#define IShellTree_get_UseContext(This,vb)	\
    ( (This)->lpVtbl -> get_UseContext(This,vb) ) 

#define IShellTree_IsDir(This,path,vb)	\
    ( (This)->lpVtbl -> IsDir(This,path,vb) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IShellTree_INTERFACE_DEFINED__ */


#ifndef __IHexCtrl_INTERFACE_DEFINED__
#define __IHexCtrl_INTERFACE_DEFINED__

/* interface IHexCtrl */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IHexCtrl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3F6F041B-6B7A-4465-9542-4652528C3FB7")
    IHexCtrl : public IDispatch
    {
    public:
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_ReadOnly( 
            /* [retval][out] */ VARIANT_BOOL *vb) = 0;
        
        virtual /* [id][hidden][restricted][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_ReadOnly( 
            /* [in] */ VARIANT_BOOL vb) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_DisplayColumns( 
            /* [retval][out] */ long *cols) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_DisplayColumns( 
            /* [in] */ long cols) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Filename( 
            /* [retval][out] */ BSTR *fname) = 0;
        
        virtual /* [id][hidden][restricted][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Filename( 
            /* [in] */ BSTR fname) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HasFocus( 
            /* [retval][out] */ VARIANT_BOOL *vbHasFocus) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_ShowToolbar( 
            /* [retval][out] */ VARIANT_BOOL *vb) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_ShowToolbar( 
            /* [in] */ VARIANT_BOOL vb) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ScrollPos( 
            /* [retval][out] */ long *pos) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_ScrollPos( 
            /* [in] */ long pos) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ScrollMax( 
            /* [retval][out] */ long *pos) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Offset( 
            /* [retval][out] */ long *off) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Offset( 
            /* [in] */ long off) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FileSize( 
            /* [retval][out] */ long *s) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SearchPos( 
            /* [retval][out] */ long *pos) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_SearchPos( 
            /* [in] */ long pos) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [in] */ BSTR file,
            /* [retval][out] */ VARIANT_BOOL *vbSuccess) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenReadOnly( 
            /* [in] */ BSTR file,
            /* [retval][out] */ VARIANT_BOOL *vbSuccess) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetOffsetDWORD( 
            /* [in] */ long offset,
            /* [in] */ BSTR val) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetOffsetByte( 
            /* [in] */ long offset,
            /* [in] */ BSTR val) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetOffsetChar( 
            /* [in] */ long offset,
            /* [in] */ long val) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Search( 
            /* [in] */ BSTR what,
            /* [in] */ long flags) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Value( 
            /* [in] */ long off,
            /* [retval][out] */ BSTR *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHexCtrlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHexCtrl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHexCtrl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHexCtrl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IHexCtrl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IHexCtrl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IHexCtrl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IHexCtrl * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ReadOnly )( 
            IHexCtrl * This,
            /* [retval][out] */ VARIANT_BOOL *vb);
        
        /* [id][hidden][restricted][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ReadOnly )( 
            IHexCtrl * This,
            /* [in] */ VARIANT_BOOL vb);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DisplayColumns )( 
            IHexCtrl * This,
            /* [retval][out] */ long *cols);
        
        /* [id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DisplayColumns )( 
            IHexCtrl * This,
            /* [in] */ long cols);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Filename )( 
            IHexCtrl * This,
            /* [retval][out] */ BSTR *fname);
        
        /* [id][hidden][restricted][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Filename )( 
            IHexCtrl * This,
            /* [in] */ BSTR fname);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HasFocus )( 
            IHexCtrl * This,
            /* [retval][out] */ VARIANT_BOOL *vbHasFocus);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ShowToolbar )( 
            IHexCtrl * This,
            /* [retval][out] */ VARIANT_BOOL *vb);
        
        /* [id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ShowToolbar )( 
            IHexCtrl * This,
            /* [in] */ VARIANT_BOOL vb);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ScrollPos )( 
            IHexCtrl * This,
            /* [retval][out] */ long *pos);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ScrollPos )( 
            IHexCtrl * This,
            /* [in] */ long pos);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ScrollMax )( 
            IHexCtrl * This,
            /* [retval][out] */ long *pos);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Offset )( 
            IHexCtrl * This,
            /* [retval][out] */ long *off);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Offset )( 
            IHexCtrl * This,
            /* [in] */ long off);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FileSize )( 
            IHexCtrl * This,
            /* [retval][out] */ long *s);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SearchPos )( 
            IHexCtrl * This,
            /* [retval][out] */ long *pos);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SearchPos )( 
            IHexCtrl * This,
            /* [in] */ long pos);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IHexCtrl * This,
            /* [in] */ BSTR file,
            /* [retval][out] */ VARIANT_BOOL *vbSuccess);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenReadOnly )( 
            IHexCtrl * This,
            /* [in] */ BSTR file,
            /* [retval][out] */ VARIANT_BOOL *vbSuccess);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetOffsetDWORD )( 
            IHexCtrl * This,
            /* [in] */ long offset,
            /* [in] */ BSTR val);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetOffsetByte )( 
            IHexCtrl * This,
            /* [in] */ long offset,
            /* [in] */ BSTR val);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetOffsetChar )( 
            IHexCtrl * This,
            /* [in] */ long offset,
            /* [in] */ long val);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Search )( 
            IHexCtrl * This,
            /* [in] */ BSTR what,
            /* [in] */ long flags);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Value )( 
            IHexCtrl * This,
            /* [in] */ long off,
            /* [retval][out] */ BSTR *value);
        
        END_INTERFACE
    } IHexCtrlVtbl;

    interface IHexCtrl
    {
        CONST_VTBL struct IHexCtrlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHexCtrl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IHexCtrl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IHexCtrl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IHexCtrl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IHexCtrl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IHexCtrl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IHexCtrl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IHexCtrl_get_ReadOnly(This,vb)	\
    ( (This)->lpVtbl -> get_ReadOnly(This,vb) ) 

#define IHexCtrl_put_ReadOnly(This,vb)	\
    ( (This)->lpVtbl -> put_ReadOnly(This,vb) ) 

#define IHexCtrl_get_DisplayColumns(This,cols)	\
    ( (This)->lpVtbl -> get_DisplayColumns(This,cols) ) 

#define IHexCtrl_put_DisplayColumns(This,cols)	\
    ( (This)->lpVtbl -> put_DisplayColumns(This,cols) ) 

#define IHexCtrl_get_Filename(This,fname)	\
    ( (This)->lpVtbl -> get_Filename(This,fname) ) 

#define IHexCtrl_put_Filename(This,fname)	\
    ( (This)->lpVtbl -> put_Filename(This,fname) ) 

#define IHexCtrl_get_HasFocus(This,vbHasFocus)	\
    ( (This)->lpVtbl -> get_HasFocus(This,vbHasFocus) ) 

#define IHexCtrl_get_ShowToolbar(This,vb)	\
    ( (This)->lpVtbl -> get_ShowToolbar(This,vb) ) 

#define IHexCtrl_put_ShowToolbar(This,vb)	\
    ( (This)->lpVtbl -> put_ShowToolbar(This,vb) ) 

#define IHexCtrl_get_ScrollPos(This,pos)	\
    ( (This)->lpVtbl -> get_ScrollPos(This,pos) ) 

#define IHexCtrl_put_ScrollPos(This,pos)	\
    ( (This)->lpVtbl -> put_ScrollPos(This,pos) ) 

#define IHexCtrl_get_ScrollMax(This,pos)	\
    ( (This)->lpVtbl -> get_ScrollMax(This,pos) ) 

#define IHexCtrl_get_Offset(This,off)	\
    ( (This)->lpVtbl -> get_Offset(This,off) ) 

#define IHexCtrl_put_Offset(This,off)	\
    ( (This)->lpVtbl -> put_Offset(This,off) ) 

#define IHexCtrl_get_FileSize(This,s)	\
    ( (This)->lpVtbl -> get_FileSize(This,s) ) 

#define IHexCtrl_get_SearchPos(This,pos)	\
    ( (This)->lpVtbl -> get_SearchPos(This,pos) ) 

#define IHexCtrl_put_SearchPos(This,pos)	\
    ( (This)->lpVtbl -> put_SearchPos(This,pos) ) 

#define IHexCtrl_Open(This,file,vbSuccess)	\
    ( (This)->lpVtbl -> Open(This,file,vbSuccess) ) 

#define IHexCtrl_OpenReadOnly(This,file,vbSuccess)	\
    ( (This)->lpVtbl -> OpenReadOnly(This,file,vbSuccess) ) 

#define IHexCtrl_SetOffsetDWORD(This,offset,val)	\
    ( (This)->lpVtbl -> SetOffsetDWORD(This,offset,val) ) 

#define IHexCtrl_SetOffsetByte(This,offset,val)	\
    ( (This)->lpVtbl -> SetOffsetByte(This,offset,val) ) 

#define IHexCtrl_SetOffsetChar(This,offset,val)	\
    ( (This)->lpVtbl -> SetOffsetChar(This,offset,val) ) 

#define IHexCtrl_Search(This,what,flags)	\
    ( (This)->lpVtbl -> Search(This,what,flags) ) 

#define IHexCtrl_Value(This,off,value)	\
    ( (This)->lpVtbl -> Value(This,off,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IHexCtrl_INTERFACE_DEFINED__ */


#ifndef __IShellList_INTERFACE_DEFINED__
#define __IShellList_INTERFACE_DEFINED__

/* interface IShellList */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IShellList;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9C93223B-E503-415a-811A-B817D7B1BC43")
    IShellList : public IDispatch
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

    typedef struct IShellListVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IShellList * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IShellList * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IShellList * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IShellList * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IShellList * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IShellList * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IShellList * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DisplayFiles )( 
            IShellList * This,
            /* [in] */ VARIANT_BOOL vb);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DisplayFiles )( 
            IShellList * This,
            /* [retval][out] */ VARIANT_BOOL *vb);
        
        /* [helpstring][id][requestedit][displaybind][bindable][defaultbind][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Selection )( 
            IShellList * This,
            /* [in] */ VARIANT fname);
        
        /* [id][requestedit][displaybind][bindable][defaultbind][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Selection )( 
            IShellList * This,
            /* [retval][out] */ VARIANT *fname);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HasFocus )( 
            IShellList * This,
            /* [retval][out] */ VARIANT_BOOL *vbHasFocus);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Update )( 
            IShellList * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Cut )( 
            IShellList * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IShellList * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Paste )( 
            IShellList * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rename )( 
            IShellList * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IShellList * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Properties )( 
            IShellList * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Execute )( 
            IShellList * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateDir )( 
            IShellList * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpDir )( 
            IShellList * This);
        
        END_INTERFACE
    } IShellListVtbl;

    interface IShellList
    {
        CONST_VTBL struct IShellListVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IShellList_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IShellList_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IShellList_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IShellList_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IShellList_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IShellList_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IShellList_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IShellList_put_DisplayFiles(This,vb)	\
    ( (This)->lpVtbl -> put_DisplayFiles(This,vb) ) 

#define IShellList_get_DisplayFiles(This,vb)	\
    ( (This)->lpVtbl -> get_DisplayFiles(This,vb) ) 

#define IShellList_put_Selection(This,fname)	\
    ( (This)->lpVtbl -> put_Selection(This,fname) ) 

#define IShellList_get_Selection(This,fname)	\
    ( (This)->lpVtbl -> get_Selection(This,fname) ) 

#define IShellList_get_HasFocus(This,vbHasFocus)	\
    ( (This)->lpVtbl -> get_HasFocus(This,vbHasFocus) ) 

#define IShellList_Update(This)	\
    ( (This)->lpVtbl -> Update(This) ) 

#define IShellList_Cut(This)	\
    ( (This)->lpVtbl -> Cut(This) ) 

#define IShellList_Copy(This)	\
    ( (This)->lpVtbl -> Copy(This) ) 

#define IShellList_Paste(This)	\
    ( (This)->lpVtbl -> Paste(This) ) 

#define IShellList_Rename(This)	\
    ( (This)->lpVtbl -> Rename(This) ) 

#define IShellList_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IShellList_Properties(This)	\
    ( (This)->lpVtbl -> Properties(This) ) 

#define IShellList_Execute(This)	\
    ( (This)->lpVtbl -> Execute(This) ) 

#define IShellList_CreateDir(This)	\
    ( (This)->lpVtbl -> CreateDir(This) ) 

#define IShellList_UpDir(This)	\
    ( (This)->lpVtbl -> UpDir(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IShellList_INTERFACE_DEFINED__ */


#ifndef __IScpList_INTERFACE_DEFINED__
#define __IScpList_INTERFACE_DEFINED__

/* interface IScpList */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IScpList;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D30F5C7F-CFAB-4D26-8FF3-0C7F67A0269D")
    IScpList : public IDispatch
    {
    public:
        virtual /* [helpstring][id][requestedit][displaybind][bindable][defaultbind][propput] */ HRESULT STDMETHODCALLTYPE put_Location( 
            /* [in] */ BSTR dir) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][defaultbind][propget] */ HRESULT STDMETHODCALLTYPE get_Location( 
            /* [retval][out] */ BSTR *dir) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HasFocus( 
            /* [retval][out] */ VARIANT_BOOL *vbHasFocus) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Selection( 
            /* [retval][out] */ BSTR *path) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Update( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Cut( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Copy( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Paste( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Rename( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Properties( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateDir( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UpDir( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CopyTo( 
            /* [in] */ BSTR dir) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Execute( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IScpListVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IScpList * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IScpList * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IScpList * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IScpList * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IScpList * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IScpList * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IScpList * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][requestedit][displaybind][bindable][defaultbind][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Location )( 
            IScpList * This,
            /* [in] */ BSTR dir);
        
        /* [id][requestedit][displaybind][bindable][defaultbind][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Location )( 
            IScpList * This,
            /* [retval][out] */ BSTR *dir);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HasFocus )( 
            IScpList * This,
            /* [retval][out] */ VARIANT_BOOL *vbHasFocus);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Selection )( 
            IScpList * This,
            /* [retval][out] */ BSTR *path);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Update )( 
            IScpList * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Cut )( 
            IScpList * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IScpList * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Paste )( 
            IScpList * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rename )( 
            IScpList * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IScpList * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Properties )( 
            IScpList * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateDir )( 
            IScpList * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpDir )( 
            IScpList * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CopyTo )( 
            IScpList * This,
            /* [in] */ BSTR dir);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Execute )( 
            IScpList * This);
        
        END_INTERFACE
    } IScpListVtbl;

    interface IScpList
    {
        CONST_VTBL struct IScpListVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScpList_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IScpList_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IScpList_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IScpList_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IScpList_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IScpList_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IScpList_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IScpList_put_Location(This,dir)	\
    ( (This)->lpVtbl -> put_Location(This,dir) ) 

#define IScpList_get_Location(This,dir)	\
    ( (This)->lpVtbl -> get_Location(This,dir) ) 

#define IScpList_get_HasFocus(This,vbHasFocus)	\
    ( (This)->lpVtbl -> get_HasFocus(This,vbHasFocus) ) 

#define IScpList_get_Selection(This,path)	\
    ( (This)->lpVtbl -> get_Selection(This,path) ) 

#define IScpList_Update(This)	\
    ( (This)->lpVtbl -> Update(This) ) 

#define IScpList_Cut(This)	\
    ( (This)->lpVtbl -> Cut(This) ) 

#define IScpList_Copy(This)	\
    ( (This)->lpVtbl -> Copy(This) ) 

#define IScpList_Paste(This)	\
    ( (This)->lpVtbl -> Paste(This) ) 

#define IScpList_Rename(This)	\
    ( (This)->lpVtbl -> Rename(This) ) 

#define IScpList_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IScpList_Properties(This)	\
    ( (This)->lpVtbl -> Properties(This) ) 

#define IScpList_CreateDir(This)	\
    ( (This)->lpVtbl -> CreateDir(This) ) 

#define IScpList_UpDir(This)	\
    ( (This)->lpVtbl -> UpDir(This) ) 

#define IScpList_CopyTo(This,dir)	\
    ( (This)->lpVtbl -> CopyTo(This,dir) ) 

#define IScpList_Execute(This)	\
    ( (This)->lpVtbl -> Execute(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IScpList_INTERFACE_DEFINED__ */


#ifndef __IColorPicker_INTERFACE_DEFINED__
#define __IColorPicker_INTERFACE_DEFINED__

/* interface IColorPicker */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IColorPicker;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("60B3F5EC-7FC7-417a-9D90-F21C78B3FC05")
    IColorPicker : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Color( 
            /* [in] */ OLE_COLOR cl) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Color( 
            /* [retval][out] */ OLE_COLOR *cl) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_HexColor( 
            /* [in] */ BSTR cl) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_HexColor( 
            /* [retval][out] */ BSTR *cl) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Show( 
            /* [retval][out] */ VARIANT_BOOL *ok) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IColorPickerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IColorPicker * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IColorPicker * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IColorPicker * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IColorPicker * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IColorPicker * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IColorPicker * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IColorPicker * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Color )( 
            IColorPicker * This,
            /* [in] */ OLE_COLOR cl);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Color )( 
            IColorPicker * This,
            /* [retval][out] */ OLE_COLOR *cl);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_HexColor )( 
            IColorPicker * This,
            /* [in] */ BSTR cl);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HexColor )( 
            IColorPicker * This,
            /* [retval][out] */ BSTR *cl);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Show )( 
            IColorPicker * This,
            /* [retval][out] */ VARIANT_BOOL *ok);
        
        END_INTERFACE
    } IColorPickerVtbl;

    interface IColorPicker
    {
        CONST_VTBL struct IColorPickerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IColorPicker_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IColorPicker_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IColorPicker_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IColorPicker_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IColorPicker_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IColorPicker_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IColorPicker_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IColorPicker_put_Color(This,cl)	\
    ( (This)->lpVtbl -> put_Color(This,cl) ) 

#define IColorPicker_get_Color(This,cl)	\
    ( (This)->lpVtbl -> get_Color(This,cl) ) 

#define IColorPicker_put_HexColor(This,cl)	\
    ( (This)->lpVtbl -> put_HexColor(This,cl) ) 

#define IColorPicker_get_HexColor(This,cl)	\
    ( (This)->lpVtbl -> get_HexColor(This,cl) ) 

#define IColorPicker_Show(This,ok)	\
    ( (This)->lpVtbl -> Show(This,ok) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IColorPicker_INTERFACE_DEFINED__ */


#ifndef __IPID_INTERFACE_DEFINED__
#define __IPID_INTERFACE_DEFINED__

/* interface IPID */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IPID;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6AAA0600-70F4-4B2A-BFAA-D808EBD2D174")
    IPID : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PID( 
            /* [retval][out] */ LONG *pid) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *processname) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TerminateProcess( 
            /* [retval][out] */ VARIANT_BOOL *ok) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPIDVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPID * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPID * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPID * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPID * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPID * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPID * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPID * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PID )( 
            IPID * This,
            /* [retval][out] */ LONG *pid);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IPID * This,
            /* [retval][out] */ BSTR *processname);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TerminateProcess )( 
            IPID * This,
            /* [retval][out] */ VARIANT_BOOL *ok);
        
        END_INTERFACE
    } IPIDVtbl;

    interface IPID
    {
        CONST_VTBL struct IPIDVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPID_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPID_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPID_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPID_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IPID_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IPID_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IPID_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IPID_get_PID(This,pid)	\
    ( (This)->lpVtbl -> get_PID(This,pid) ) 

#define IPID_get_Name(This,processname)	\
    ( (This)->lpVtbl -> get_Name(This,processname) ) 

#define IPID_TerminateProcess(This,ok)	\
    ( (This)->lpVtbl -> TerminateProcess(This,ok) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPID_INTERFACE_DEFINED__ */


#ifndef __IKillRoy_INTERFACE_DEFINED__
#define __IKillRoy_INTERFACE_DEFINED__

/* interface IKillRoy */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IKillRoy;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6CE312C4-CCD1-4F28-B06D-4137F486FCB4")
    IKillRoy : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FindPIDforFile( 
            /* [in] */ BSTR filename,
            /* [retval][out] */ IPID **pid) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IKillRoyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IKillRoy * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IKillRoy * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IKillRoy * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IKillRoy * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IKillRoy * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IKillRoy * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IKillRoy * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FindPIDforFile )( 
            IKillRoy * This,
            /* [in] */ BSTR filename,
            /* [retval][out] */ IPID **pid);
        
        END_INTERFACE
    } IKillRoyVtbl;

    interface IKillRoy
    {
        CONST_VTBL struct IKillRoyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IKillRoy_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IKillRoy_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IKillRoy_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IKillRoy_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IKillRoy_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IKillRoy_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IKillRoy_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IKillRoy_FindPIDforFile(This,filename,pid)	\
    ( (This)->lpVtbl -> FindPIDforFile(This,filename,pid) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IKillRoy_INTERFACE_DEFINED__ */


#ifndef ___IShellTreeEvents_DISPINTERFACE_DEFINED__
#define ___IShellTreeEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IShellTreeEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IShellTreeEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("642D2ED7-975F-4699-B7C9-D95AAB97F826")
    _IShellTreeEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IShellTreeEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IShellTreeEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IShellTreeEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IShellTreeEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IShellTreeEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IShellTreeEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IShellTreeEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IShellTreeEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IShellTreeEventsVtbl;

    interface _IShellTreeEvents
    {
        CONST_VTBL struct _IShellTreeEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IShellTreeEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IShellTreeEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IShellTreeEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IShellTreeEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IShellTreeEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IShellTreeEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IShellTreeEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IShellTreeEvents_DISPINTERFACE_DEFINED__ */


#ifndef ___IHexCtrlEvents_DISPINTERFACE_DEFINED__
#define ___IHexCtrlEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IHexCtrlEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IHexCtrlEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("AAB8E8A1-A963-4345-ACA6-38DC7CF01A78")
    _IHexCtrlEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IHexCtrlEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IHexCtrlEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IHexCtrlEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IHexCtrlEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IHexCtrlEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IHexCtrlEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IHexCtrlEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IHexCtrlEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IHexCtrlEventsVtbl;

    interface _IHexCtrlEvents
    {
        CONST_VTBL struct _IHexCtrlEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IHexCtrlEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IHexCtrlEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IHexCtrlEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IHexCtrlEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IHexCtrlEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IHexCtrlEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IHexCtrlEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IHexCtrlEvents_DISPINTERFACE_DEFINED__ */


#ifndef ___IShellListEvents_DISPINTERFACE_DEFINED__
#define ___IShellListEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IShellListEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IShellListEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("24165625-BBB8-404a-B2BC-62B9F40FE7DD")
    _IShellListEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IShellListEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IShellListEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IShellListEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IShellListEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IShellListEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IShellListEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IShellListEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IShellListEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IShellListEventsVtbl;

    interface _IShellListEvents
    {
        CONST_VTBL struct _IShellListEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IShellListEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IShellListEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IShellListEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IShellListEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IShellListEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IShellListEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IShellListEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IShellListEvents_DISPINTERFACE_DEFINED__ */


#ifndef __IShellTreeEvents_INTERFACE_DEFINED__
#define __IShellTreeEvents_INTERFACE_DEFINED__

/* interface IShellTreeEvents */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IShellTreeEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D975C13F-537C-4065-A27A-D25A271A7A6E")
    IShellTreeEvents : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnTreeSelection( 
            /* [in] */ BSTR fname) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnTreeDblClick( 
            /* [in] */ BSTR fname,
            /* [in] */ VARIANT_BOOL vbIsDir) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnTreeOpen( 
            /* [in] */ BSTR fname,
            /* [in] */ VARIANT_BOOL vbIsDir) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnContextMenu( 
            /* [in] */ BSTR fname,
            /* [in] */ VARIANT_BOOL vbIsDir) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IShellTreeEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IShellTreeEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IShellTreeEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IShellTreeEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IShellTreeEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IShellTreeEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IShellTreeEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IShellTreeEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnTreeSelection )( 
            IShellTreeEvents * This,
            /* [in] */ BSTR fname);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnTreeDblClick )( 
            IShellTreeEvents * This,
            /* [in] */ BSTR fname,
            /* [in] */ VARIANT_BOOL vbIsDir);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnTreeOpen )( 
            IShellTreeEvents * This,
            /* [in] */ BSTR fname,
            /* [in] */ VARIANT_BOOL vbIsDir);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnContextMenu )( 
            IShellTreeEvents * This,
            /* [in] */ BSTR fname,
            /* [in] */ VARIANT_BOOL vbIsDir);
        
        END_INTERFACE
    } IShellTreeEventsVtbl;

    interface IShellTreeEvents
    {
        CONST_VTBL struct IShellTreeEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IShellTreeEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IShellTreeEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IShellTreeEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IShellTreeEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IShellTreeEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IShellTreeEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IShellTreeEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IShellTreeEvents_OnTreeSelection(This,fname)	\
    ( (This)->lpVtbl -> OnTreeSelection(This,fname) ) 

#define IShellTreeEvents_OnTreeDblClick(This,fname,vbIsDir)	\
    ( (This)->lpVtbl -> OnTreeDblClick(This,fname,vbIsDir) ) 

#define IShellTreeEvents_OnTreeOpen(This,fname,vbIsDir)	\
    ( (This)->lpVtbl -> OnTreeOpen(This,fname,vbIsDir) ) 

#define IShellTreeEvents_OnContextMenu(This,fname,vbIsDir)	\
    ( (This)->lpVtbl -> OnContextMenu(This,fname,vbIsDir) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IShellTreeEvents_INTERFACE_DEFINED__ */


#ifndef __IShellListEvents_INTERFACE_DEFINED__
#define __IShellListEvents_INTERFACE_DEFINED__

/* interface IShellListEvents */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IShellListEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2ED442CD-E289-46c3-AB7B-8DE1CEF89DB4")
    IShellListEvents : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnListSelection( 
            /* [in] */ BSTR fname,
            /* [in] */ VARIANT_BOOL vbIsDir) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnListDblClick( 
            /* [in] */ BSTR fname,
            /* [in] */ VARIANT_BOOL vbIsDir) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnListOpen( 
            /* [in] */ BSTR fname,
            /* [in] */ VARIANT_BOOL vbIsDir) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnDirChanged( 
            /* [in] */ BSTR dir) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IShellListEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IShellListEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IShellListEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IShellListEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IShellListEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IShellListEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IShellListEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IShellListEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnListSelection )( 
            IShellListEvents * This,
            /* [in] */ BSTR fname,
            /* [in] */ VARIANT_BOOL vbIsDir);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnListDblClick )( 
            IShellListEvents * This,
            /* [in] */ BSTR fname,
            /* [in] */ VARIANT_BOOL vbIsDir);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnListOpen )( 
            IShellListEvents * This,
            /* [in] */ BSTR fname,
            /* [in] */ VARIANT_BOOL vbIsDir);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnDirChanged )( 
            IShellListEvents * This,
            /* [in] */ BSTR dir);
        
        END_INTERFACE
    } IShellListEventsVtbl;

    interface IShellListEvents
    {
        CONST_VTBL struct IShellListEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IShellListEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IShellListEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IShellListEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IShellListEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IShellListEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IShellListEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IShellListEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IShellListEvents_OnListSelection(This,fname,vbIsDir)	\
    ( (This)->lpVtbl -> OnListSelection(This,fname,vbIsDir) ) 

#define IShellListEvents_OnListDblClick(This,fname,vbIsDir)	\
    ( (This)->lpVtbl -> OnListDblClick(This,fname,vbIsDir) ) 

#define IShellListEvents_OnListOpen(This,fname,vbIsDir)	\
    ( (This)->lpVtbl -> OnListOpen(This,fname,vbIsDir) ) 

#define IShellListEvents_OnDirChanged(This,dir)	\
    ( (This)->lpVtbl -> OnDirChanged(This,dir) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IShellListEvents_INTERFACE_DEFINED__ */


#ifndef __IHexCtrlEvents_INTERFACE_DEFINED__
#define __IHexCtrlEvents_INTERFACE_DEFINED__

/* interface IHexCtrlEvents */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IHexCtrlEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2031340D-A1E9-4fcf-8774-B94A565D6225")
    IHexCtrlEvents : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnNewFile( 
            /* [in] */ BSTR fname,
            /* [in] */ VARIANT_BOOL vbReadOnly) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnNewOffset( 
            /* [in] */ BSTR address,
            /* [in] */ BSTR value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnNewValue( 
            /* [in] */ BSTR address,
            /* [in] */ BSTR value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHexCtrlEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHexCtrlEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHexCtrlEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHexCtrlEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IHexCtrlEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IHexCtrlEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IHexCtrlEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IHexCtrlEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnNewFile )( 
            IHexCtrlEvents * This,
            /* [in] */ BSTR fname,
            /* [in] */ VARIANT_BOOL vbReadOnly);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnNewOffset )( 
            IHexCtrlEvents * This,
            /* [in] */ BSTR address,
            /* [in] */ BSTR value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnNewValue )( 
            IHexCtrlEvents * This,
            /* [in] */ BSTR address,
            /* [in] */ BSTR value);
        
        END_INTERFACE
    } IHexCtrlEventsVtbl;

    interface IHexCtrlEvents
    {
        CONST_VTBL struct IHexCtrlEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHexCtrlEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IHexCtrlEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IHexCtrlEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IHexCtrlEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IHexCtrlEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IHexCtrlEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IHexCtrlEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IHexCtrlEvents_OnNewFile(This,fname,vbReadOnly)	\
    ( (This)->lpVtbl -> OnNewFile(This,fname,vbReadOnly) ) 

#define IHexCtrlEvents_OnNewOffset(This,address,value)	\
    ( (This)->lpVtbl -> OnNewOffset(This,address,value) ) 

#define IHexCtrlEvents_OnNewValue(This,address,value)	\
    ( (This)->lpVtbl -> OnNewValue(This,address,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IHexCtrlEvents_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ShellTree;

#ifdef __cplusplus

class DECLSPEC_UUID("22C25563-E185-4753-8299-1998CD73D389")
ShellTree;
#endif

EXTERN_C const CLSID CLSID_ShellList;

#ifdef __cplusplus

class DECLSPEC_UUID("8E6A9C86-2FA6-4d02-B9BE-72326A7F6C9D")
ShellList;
#endif

EXTERN_C const CLSID CLSID_ColorDialog;

#ifdef __cplusplus

class DECLSPEC_UUID("ADF80C5A-78DE-4317-BF08-4CE3176D3422")
ColorDialog;
#endif

EXTERN_C const CLSID CLSID_HexCtrl;

#ifdef __cplusplus

class DECLSPEC_UUID("E83EC0F6-6AF3-44f8-901E-AF01F84FE6D0")
HexCtrl;
#endif

EXTERN_C const CLSID CLSID_ScpList;

#ifdef __cplusplus

class DECLSPEC_UUID("CD199DC9-8BA4-4F7A-BCFA-4C3473C06F03")
ScpList;
#endif

EXTERN_C const CLSID CLSID_KillRoy;

#ifdef __cplusplus

class DECLSPEC_UUID("733EA4E5-CDA0-4900-9255-DFC136AA3401")
KillRoy;
#endif
#endif /* __ShellCtrls_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


