

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Sat Jun 02 14:33:36 2012
 */
/* Compiler settings for setting.idl:
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


#ifndef __setting_h_h__
#define __setting_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ISetting_FWD_DEFINED__
#define __ISetting_FWD_DEFINED__
typedef interface ISetting ISetting;
#endif 	/* __ISetting_FWD_DEFINED__ */


#ifndef ___ISettingChanged_FWD_DEFINED__
#define ___ISettingChanged_FWD_DEFINED__
typedef interface _ISettingChanged _ISettingChanged;
#endif 	/* ___ISettingChanged_FWD_DEFINED__ */


#ifndef ___ISettingChangedDual_FWD_DEFINED__
#define ___ISettingChangedDual_FWD_DEFINED__
typedef interface _ISettingChangedDual _ISettingChangedDual;
#endif 	/* ___ISettingChangedDual_FWD_DEFINED__ */


#ifndef __Setting_FWD_DEFINED__
#define __Setting_FWD_DEFINED__

#ifdef __cplusplus
typedef class Setting Setting;
#else
typedef struct Setting Setting;
#endif /* __cplusplus */

#endif 	/* __Setting_FWD_DEFINED__ */


#ifndef __SettingProperties_FWD_DEFINED__
#define __SettingProperties_FWD_DEFINED__

#ifdef __cplusplus
typedef class SettingProperties SettingProperties;
#else
typedef struct SettingProperties SettingProperties;
#endif /* __cplusplus */

#endif 	/* __SettingProperties_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __Settings_LIBRARY_DEFINED__
#define __Settings_LIBRARY_DEFINED__

/* library Settings */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_Settings;

#ifndef __ISetting_INTERFACE_DEFINED__
#define __ISetting_INTERFACE_DEFINED__

/* interface ISetting */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_ISetting;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2DD18900-95F3-46a8-98B8-03F3843DE635")
    ISetting : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Key( 
            /* [in] */ BSTR k) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Key( 
            /* [retval][out] */ BSTR *k) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Value( 
            /* [in] */ BSTR v) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [retval][out] */ BSTR *v) = 0;
        
        virtual /* [helpstring][id][restricted][propput] */ HRESULT STDMETHODCALLTYPE put_Parent( 
            /* [in] */ ISetting *s) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ ISetting **s) = 0;
        
        virtual /* [helpstring][id][restricted][propput] */ HRESULT STDMETHODCALLTYPE put_ChildrenAllowed( 
            /* [in] */ VARIANT_BOOL vb) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ChildrenAllowed( 
            /* [retval][out] */ VARIANT_BOOL *vb) = 0;
        
        virtual /* [helpstring][id][restricted][propput] */ HRESULT STDMETHODCALLTYPE put_KeyReadOnly( 
            /* [in] */ VARIANT_BOOL vb) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_KeyReadOnly( 
            /* [retval][out] */ VARIANT_BOOL *vb) = 0;
        
        virtual /* [helpstring][id][restricted][propput] */ HRESULT STDMETHODCALLTYPE put_ValueReadOnly( 
            /* [in] */ VARIANT_BOOL vb) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ValueReadOnly( 
            /* [retval][out] */ VARIANT_BOOL *vb) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsDirty( 
            /* [retval][out] */ VARIANT_BOOL *vb) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_IsDirty( 
            /* [in] */ VARIANT_BOOL vb) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE _NewEnum( 
            /* [retval][out] */ IEnumVARIANT **newEnum) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ VARIANT index,
            /* [retval][out] */ ISetting **i) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Count( 
            /* [retval][out] */ long *cnt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Root( 
            /* [retval][out] */ ISetting **r) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE KeyName( 
            /* [retval][out] */ BSTR *kName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ ISetting *s) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE New( 
            /* [in] */ BSTR k,
            /* [in] */ BSTR v,
            /* [retval][out] */ ISetting **s) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Remove( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveItem( 
            /* [in] */ VARIANT i) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ BSTR fname) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( 
            /* [in] */ BSTR fname) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clone( 
            /* [retval][out] */ ISetting **sClone) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISettingVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISetting * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISetting * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISetting * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISetting * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISetting * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISetting * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISetting * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Key )( 
            ISetting * This,
            /* [in] */ BSTR k);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Key )( 
            ISetting * This,
            /* [retval][out] */ BSTR *k);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Value )( 
            ISetting * This,
            /* [in] */ BSTR v);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            ISetting * This,
            /* [retval][out] */ BSTR *v);
        
        /* [helpstring][id][restricted][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Parent )( 
            ISetting * This,
            /* [in] */ ISetting *s);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            ISetting * This,
            /* [retval][out] */ ISetting **s);
        
        /* [helpstring][id][restricted][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ChildrenAllowed )( 
            ISetting * This,
            /* [in] */ VARIANT_BOOL vb);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ChildrenAllowed )( 
            ISetting * This,
            /* [retval][out] */ VARIANT_BOOL *vb);
        
        /* [helpstring][id][restricted][propput] */ HRESULT ( STDMETHODCALLTYPE *put_KeyReadOnly )( 
            ISetting * This,
            /* [in] */ VARIANT_BOOL vb);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_KeyReadOnly )( 
            ISetting * This,
            /* [retval][out] */ VARIANT_BOOL *vb);
        
        /* [helpstring][id][restricted][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ValueReadOnly )( 
            ISetting * This,
            /* [in] */ VARIANT_BOOL vb);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ValueReadOnly )( 
            ISetting * This,
            /* [retval][out] */ VARIANT_BOOL *vb);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsDirty )( 
            ISetting * This,
            /* [retval][out] */ VARIANT_BOOL *vb);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IsDirty )( 
            ISetting * This,
            /* [in] */ VARIANT_BOOL vb);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *_NewEnum )( 
            ISetting * This,
            /* [retval][out] */ IEnumVARIANT **newEnum);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            ISetting * This,
            /* [in] */ VARIANT index,
            /* [retval][out] */ ISetting **i);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Count )( 
            ISetting * This,
            /* [retval][out] */ long *cnt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Root )( 
            ISetting * This,
            /* [retval][out] */ ISetting **r);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *KeyName )( 
            ISetting * This,
            /* [retval][out] */ BSTR *kName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            ISetting * This,
            /* [in] */ ISetting *s);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *New )( 
            ISetting * This,
            /* [in] */ BSTR k,
            /* [in] */ BSTR v,
            /* [retval][out] */ ISetting **s);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Remove )( 
            ISetting * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveItem )( 
            ISetting * This,
            /* [in] */ VARIANT i);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            ISetting * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Load )( 
            ISetting * This,
            /* [in] */ BSTR fname);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            ISetting * This,
            /* [in] */ BSTR fname);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clone )( 
            ISetting * This,
            /* [retval][out] */ ISetting **sClone);
        
        END_INTERFACE
    } ISettingVtbl;

    interface ISetting
    {
        CONST_VTBL struct ISettingVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISetting_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISetting_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISetting_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISetting_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISetting_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISetting_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISetting_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISetting_put_Key(This,k)	\
    ( (This)->lpVtbl -> put_Key(This,k) ) 

#define ISetting_get_Key(This,k)	\
    ( (This)->lpVtbl -> get_Key(This,k) ) 

#define ISetting_put_Value(This,v)	\
    ( (This)->lpVtbl -> put_Value(This,v) ) 

#define ISetting_get_Value(This,v)	\
    ( (This)->lpVtbl -> get_Value(This,v) ) 

#define ISetting_put_Parent(This,s)	\
    ( (This)->lpVtbl -> put_Parent(This,s) ) 

#define ISetting_get_Parent(This,s)	\
    ( (This)->lpVtbl -> get_Parent(This,s) ) 

#define ISetting_put_ChildrenAllowed(This,vb)	\
    ( (This)->lpVtbl -> put_ChildrenAllowed(This,vb) ) 

#define ISetting_get_ChildrenAllowed(This,vb)	\
    ( (This)->lpVtbl -> get_ChildrenAllowed(This,vb) ) 

#define ISetting_put_KeyReadOnly(This,vb)	\
    ( (This)->lpVtbl -> put_KeyReadOnly(This,vb) ) 

#define ISetting_get_KeyReadOnly(This,vb)	\
    ( (This)->lpVtbl -> get_KeyReadOnly(This,vb) ) 

#define ISetting_put_ValueReadOnly(This,vb)	\
    ( (This)->lpVtbl -> put_ValueReadOnly(This,vb) ) 

#define ISetting_get_ValueReadOnly(This,vb)	\
    ( (This)->lpVtbl -> get_ValueReadOnly(This,vb) ) 

#define ISetting_get_IsDirty(This,vb)	\
    ( (This)->lpVtbl -> get_IsDirty(This,vb) ) 

#define ISetting_put_IsDirty(This,vb)	\
    ( (This)->lpVtbl -> put_IsDirty(This,vb) ) 

#define ISetting__NewEnum(This,newEnum)	\
    ( (This)->lpVtbl -> _NewEnum(This,newEnum) ) 

#define ISetting_Item(This,index,i)	\
    ( (This)->lpVtbl -> Item(This,index,i) ) 

#define ISetting_Count(This,cnt)	\
    ( (This)->lpVtbl -> Count(This,cnt) ) 

#define ISetting_Root(This,r)	\
    ( (This)->lpVtbl -> Root(This,r) ) 

#define ISetting_KeyName(This,kName)	\
    ( (This)->lpVtbl -> KeyName(This,kName) ) 

#define ISetting_Add(This,s)	\
    ( (This)->lpVtbl -> Add(This,s) ) 

#define ISetting_New(This,k,v,s)	\
    ( (This)->lpVtbl -> New(This,k,v,s) ) 

#define ISetting_Remove(This)	\
    ( (This)->lpVtbl -> Remove(This) ) 

#define ISetting_RemoveItem(This,i)	\
    ( (This)->lpVtbl -> RemoveItem(This,i) ) 

#define ISetting_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define ISetting_Load(This,fname)	\
    ( (This)->lpVtbl -> Load(This,fname) ) 

#define ISetting_Save(This,fname)	\
    ( (This)->lpVtbl -> Save(This,fname) ) 

#define ISetting_Clone(This,sClone)	\
    ( (This)->lpVtbl -> Clone(This,sClone) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISetting_INTERFACE_DEFINED__ */


#ifndef ___ISettingChanged_DISPINTERFACE_DEFINED__
#define ___ISettingChanged_DISPINTERFACE_DEFINED__

/* dispinterface _ISettingChanged */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__ISettingChanged;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("05CE8141-F38B-4c50-AC21-931F4D07A6A0")
    _ISettingChanged : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _ISettingChangedVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _ISettingChanged * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _ISettingChanged * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _ISettingChanged * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _ISettingChanged * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _ISettingChanged * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _ISettingChanged * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _ISettingChanged * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _ISettingChangedVtbl;

    interface _ISettingChanged
    {
        CONST_VTBL struct _ISettingChangedVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ISettingChanged_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _ISettingChanged_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _ISettingChanged_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _ISettingChanged_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _ISettingChanged_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _ISettingChanged_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _ISettingChanged_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___ISettingChanged_DISPINTERFACE_DEFINED__ */


#ifndef ___ISettingChangedDual_INTERFACE_DEFINED__
#define ___ISettingChangedDual_INTERFACE_DEFINED__

/* interface _ISettingChangedDual */
/* [object][dual][oleautomation][helpstring][uuid] */ 


EXTERN_C const IID IID__ISettingChangedDual;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0DB8CB91-F13F-4374-BDD8-FDEEED4210F6")
    _ISettingChangedDual : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnChange( 
            BSTR fullkey,
            BSTR key,
            BSTR val) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct _ISettingChangedDualVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _ISettingChangedDual * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _ISettingChangedDual * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _ISettingChangedDual * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _ISettingChangedDual * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _ISettingChangedDual * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _ISettingChangedDual * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _ISettingChangedDual * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnChange )( 
            _ISettingChangedDual * This,
            BSTR fullkey,
            BSTR key,
            BSTR val);
        
        END_INTERFACE
    } _ISettingChangedDualVtbl;

    interface _ISettingChangedDual
    {
        CONST_VTBL struct _ISettingChangedDualVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ISettingChangedDual_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _ISettingChangedDual_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _ISettingChangedDual_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _ISettingChangedDual_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _ISettingChangedDual_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _ISettingChangedDual_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _ISettingChangedDual_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define _ISettingChangedDual_OnChange(This,fullkey,key,val)	\
    ( (This)->lpVtbl -> OnChange(This,fullkey,key,val) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ___ISettingChangedDual_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Setting;

#ifdef __cplusplus

class DECLSPEC_UUID("AE500EE9-731F-47a8-8D11-634EF422A396")
Setting;
#endif

EXTERN_C const CLSID CLSID_SettingProperties;

#ifdef __cplusplus

class DECLSPEC_UUID("5754B136-D3FB-4232-B94A-92B44BE066E9")
SettingProperties;
#endif
#endif /* __Settings_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


