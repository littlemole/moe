

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Tue Apr 29 18:27:26 2014
 */
/* Compiler settings for treectrl.idl:
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


#ifndef __treectrl_h_h__
#define __treectrl_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ITreeElement_FWD_DEFINED__
#define __ITreeElement_FWD_DEFINED__
typedef interface ITreeElement ITreeElement;

#endif 	/* __ITreeElement_FWD_DEFINED__ */


#ifndef __ITreeCtrl_FWD_DEFINED__
#define __ITreeCtrl_FWD_DEFINED__
typedef interface ITreeCtrl ITreeCtrl;

#endif 	/* __ITreeCtrl_FWD_DEFINED__ */


#ifndef ___ITreeCtrlEvents_FWD_DEFINED__
#define ___ITreeCtrlEvents_FWD_DEFINED__
typedef interface _ITreeCtrlEvents _ITreeCtrlEvents;

#endif 	/* ___ITreeCtrlEvents_FWD_DEFINED__ */


#ifndef __ITreeCtrlEvents_FWD_DEFINED__
#define __ITreeCtrlEvents_FWD_DEFINED__
typedef interface ITreeCtrlEvents ITreeCtrlEvents;

#endif 	/* __ITreeCtrlEvents_FWD_DEFINED__ */


#ifndef __TreeControl_FWD_DEFINED__
#define __TreeControl_FWD_DEFINED__

#ifdef __cplusplus
typedef class TreeControl TreeControl;
#else
typedef struct TreeControl TreeControl;
#endif /* __cplusplus */

#endif 	/* __TreeControl_FWD_DEFINED__ */


#ifndef __TreeElement_FWD_DEFINED__
#define __TreeElement_FWD_DEFINED__

#ifdef __cplusplus
typedef class TreeElement TreeElement;
#else
typedef struct TreeElement TreeElement;
#endif /* __cplusplus */

#endif 	/* __TreeElement_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __TreeCtrl_LIBRARY_DEFINED__
#define __TreeCtrl_LIBRARY_DEFINED__

/* library TreeCtrl */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_TreeCtrl;

#ifndef __ITreeElement_INTERFACE_DEFINED__
#define __ITreeElement_INTERFACE_DEFINED__

/* interface ITreeElement */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_ITreeElement;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5295C21C-760F-4EB9-AA4C-29ED6EA710C9")
    ITreeElement : public IDispatch
    {
    public:
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Label( 
            /* [in] */ BSTR txt) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Label( 
            /* [retval][out] */ BSTR *txt) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Value( 
            /* [in] */ VARIANT v) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [retval][out] */ VARIANT *v) = 0;
        
        virtual /* [helpstring][id][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *cnt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Element( 
            /* [in] */ long index,
            /* [retval][out] */ ITreeElement **el) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ ITreeElement *el) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ long index) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITreeElementVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITreeElement * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITreeElement * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITreeElement * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITreeElement * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITreeElement * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITreeElement * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITreeElement * This,
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
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Label )( 
            ITreeElement * This,
            /* [in] */ BSTR txt);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Label )( 
            ITreeElement * This,
            /* [retval][out] */ BSTR *txt);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Value )( 
            ITreeElement * This,
            /* [in] */ VARIANT v);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            ITreeElement * This,
            /* [retval][out] */ VARIANT *v);
        
        /* [helpstring][id][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            ITreeElement * This,
            /* [retval][out] */ long *cnt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Element )( 
            ITreeElement * This,
            /* [in] */ long index,
            /* [retval][out] */ ITreeElement **el);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            ITreeElement * This,
            /* [in] */ ITreeElement *el);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Remove )( 
            ITreeElement * This,
            /* [in] */ long index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            ITreeElement * This);
        
        END_INTERFACE
    } ITreeElementVtbl;

    interface ITreeElement
    {
        CONST_VTBL struct ITreeElementVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITreeElement_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITreeElement_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITreeElement_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITreeElement_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITreeElement_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITreeElement_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITreeElement_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITreeElement_put_Label(This,txt)	\
    ( (This)->lpVtbl -> put_Label(This,txt) ) 

#define ITreeElement_get_Label(This,txt)	\
    ( (This)->lpVtbl -> get_Label(This,txt) ) 

#define ITreeElement_put_Value(This,v)	\
    ( (This)->lpVtbl -> put_Value(This,v) ) 

#define ITreeElement_get_Value(This,v)	\
    ( (This)->lpVtbl -> get_Value(This,v) ) 

#define ITreeElement_get_Count(This,cnt)	\
    ( (This)->lpVtbl -> get_Count(This,cnt) ) 

#define ITreeElement_Element(This,index,el)	\
    ( (This)->lpVtbl -> Element(This,index,el) ) 

#define ITreeElement_Add(This,el)	\
    ( (This)->lpVtbl -> Add(This,el) ) 

#define ITreeElement_Remove(This,index)	\
    ( (This)->lpVtbl -> Remove(This,index) ) 

#define ITreeElement_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITreeElement_INTERFACE_DEFINED__ */


#ifndef __ITreeCtrl_INTERFACE_DEFINED__
#define __ITreeCtrl_INTERFACE_DEFINED__

/* interface ITreeCtrl */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_ITreeCtrl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("43D7B7ED-68B6-402E-B703-F6699C059C73")
    ITreeCtrl : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Root( 
            /* [retval][out] */ ITreeElement **el) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Create( 
            /* [in] */ ITreeElement *parent,
            /* [in] */ BSTR txt,
            /* [in] */ VARIANT value,
            /* [retval][out] */ ITreeElement **el) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ScrollIntoView( 
            /* [in] */ ITreeElement *el) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITreeCtrlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITreeCtrl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITreeCtrl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITreeCtrl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITreeCtrl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITreeCtrl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITreeCtrl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITreeCtrl * This,
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
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Root )( 
            ITreeCtrl * This,
            /* [retval][out] */ ITreeElement **el);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Create )( 
            ITreeCtrl * This,
            /* [in] */ ITreeElement *parent,
            /* [in] */ BSTR txt,
            /* [in] */ VARIANT value,
            /* [retval][out] */ ITreeElement **el);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            ITreeCtrl * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ScrollIntoView )( 
            ITreeCtrl * This,
            /* [in] */ ITreeElement *el);
        
        END_INTERFACE
    } ITreeCtrlVtbl;

    interface ITreeCtrl
    {
        CONST_VTBL struct ITreeCtrlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITreeCtrl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITreeCtrl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITreeCtrl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITreeCtrl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITreeCtrl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITreeCtrl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITreeCtrl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITreeCtrl_get_Root(This,el)	\
    ( (This)->lpVtbl -> get_Root(This,el) ) 

#define ITreeCtrl_Create(This,parent,txt,value,el)	\
    ( (This)->lpVtbl -> Create(This,parent,txt,value,el) ) 

#define ITreeCtrl_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define ITreeCtrl_ScrollIntoView(This,el)	\
    ( (This)->lpVtbl -> ScrollIntoView(This,el) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITreeCtrl_INTERFACE_DEFINED__ */


#ifndef ___ITreeCtrlEvents_DISPINTERFACE_DEFINED__
#define ___ITreeCtrlEvents_DISPINTERFACE_DEFINED__

/* dispinterface _ITreeCtrlEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__ITreeCtrlEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("F27F6A86-58C6-40FD-AEE3-E7FB9F0BB37B")
    _ITreeCtrlEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _ITreeCtrlEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _ITreeCtrlEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _ITreeCtrlEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _ITreeCtrlEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _ITreeCtrlEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _ITreeCtrlEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _ITreeCtrlEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _ITreeCtrlEvents * This,
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
        
        END_INTERFACE
    } _ITreeCtrlEventsVtbl;

    interface _ITreeCtrlEvents
    {
        CONST_VTBL struct _ITreeCtrlEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ITreeCtrlEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _ITreeCtrlEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _ITreeCtrlEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _ITreeCtrlEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _ITreeCtrlEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _ITreeCtrlEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _ITreeCtrlEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___ITreeCtrlEvents_DISPINTERFACE_DEFINED__ */


#ifndef __ITreeCtrlEvents_INTERFACE_DEFINED__
#define __ITreeCtrlEvents_INTERFACE_DEFINED__

/* interface ITreeCtrlEvents */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_ITreeCtrlEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7216C1FA-5960-4F88-86EF-168DD83ACFAB")
    ITreeCtrlEvents : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnTreeClick( 
            /* [in] */ ITreeElement *el) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnTreeDblClick( 
            /* [in] */ ITreeElement *el) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnTreeRightClick( 
            /* [in] */ ITreeElement *el) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITreeCtrlEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITreeCtrlEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITreeCtrlEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITreeCtrlEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITreeCtrlEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITreeCtrlEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITreeCtrlEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITreeCtrlEvents * This,
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
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnTreeClick )( 
            ITreeCtrlEvents * This,
            /* [in] */ ITreeElement *el);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnTreeDblClick )( 
            ITreeCtrlEvents * This,
            /* [in] */ ITreeElement *el);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnTreeRightClick )( 
            ITreeCtrlEvents * This,
            /* [in] */ ITreeElement *el);
        
        END_INTERFACE
    } ITreeCtrlEventsVtbl;

    interface ITreeCtrlEvents
    {
        CONST_VTBL struct ITreeCtrlEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITreeCtrlEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITreeCtrlEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITreeCtrlEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITreeCtrlEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITreeCtrlEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITreeCtrlEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITreeCtrlEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITreeCtrlEvents_OnTreeClick(This,el)	\
    ( (This)->lpVtbl -> OnTreeClick(This,el) ) 

#define ITreeCtrlEvents_OnTreeDblClick(This,el)	\
    ( (This)->lpVtbl -> OnTreeDblClick(This,el) ) 

#define ITreeCtrlEvents_OnTreeRightClick(This,el)	\
    ( (This)->lpVtbl -> OnTreeRightClick(This,el) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITreeCtrlEvents_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_TreeControl;

#ifdef __cplusplus

class DECLSPEC_UUID("876266EE-AE01-402B-845F-5852E7CB32EA")
TreeControl;
#endif

EXTERN_C const CLSID CLSID_TreeElement;

#ifdef __cplusplus

class DECLSPEC_UUID("29737AFE-9748-4762-B661-49F157C16085")
TreeElement;
#endif
#endif /* __TreeCtrl_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


