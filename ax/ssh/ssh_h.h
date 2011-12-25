

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Thu Dec 22 21:04:49 2011
 */
/* Compiler settings for ssh.idl:
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


#ifndef __ssh_h_h__
#define __ssh_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IScpPasswordCredentials_FWD_DEFINED__
#define __IScpPasswordCredentials_FWD_DEFINED__
typedef interface IScpPasswordCredentials IScpPasswordCredentials;
#endif 	/* __IScpPasswordCredentials_FWD_DEFINED__ */


#ifndef __IScpCredentialProvider_FWD_DEFINED__
#define __IScpCredentialProvider_FWD_DEFINED__
typedef interface IScpCredentialProvider IScpCredentialProvider;
#endif 	/* __IScpCredentialProvider_FWD_DEFINED__ */


#ifndef __IRemoteFile_FWD_DEFINED__
#define __IRemoteFile_FWD_DEFINED__
typedef interface IRemoteFile IRemoteFile;
#endif 	/* __IRemoteFile_FWD_DEFINED__ */


#ifndef __ISFTP_FWD_DEFINED__
#define __ISFTP_FWD_DEFINED__
typedef interface ISFTP ISFTP;
#endif 	/* __ISFTP_FWD_DEFINED__ */


#ifndef __ISCP_FWD_DEFINED__
#define __ISCP_FWD_DEFINED__
typedef interface ISCP ISCP;
#endif 	/* __ISCP_FWD_DEFINED__ */


#ifndef __ISSHConnection_FWD_DEFINED__
#define __ISSHConnection_FWD_DEFINED__
typedef interface ISSHConnection ISSHConnection;
#endif 	/* __ISSHConnection_FWD_DEFINED__ */


#ifndef __ISSH_FWD_DEFINED__
#define __ISSH_FWD_DEFINED__
typedef interface ISSH ISSH;
#endif 	/* __ISSH_FWD_DEFINED__ */


#ifndef __SSH_FWD_DEFINED__
#define __SSH_FWD_DEFINED__

#ifdef __cplusplus
typedef class SSH SSH;
#else
typedef struct SSH SSH;
#endif /* __cplusplus */

#endif 	/* __SSH_FWD_DEFINED__ */


#ifndef __ScpPasswordCredentials_FWD_DEFINED__
#define __ScpPasswordCredentials_FWD_DEFINED__

#ifdef __cplusplus
typedef class ScpPasswordCredentials ScpPasswordCredentials;
#else
typedef struct ScpPasswordCredentials ScpPasswordCredentials;
#endif /* __cplusplus */

#endif 	/* __ScpPasswordCredentials_FWD_DEFINED__ */


#ifndef __DefaultScpCredentialProvider_FWD_DEFINED__
#define __DefaultScpCredentialProvider_FWD_DEFINED__

#ifdef __cplusplus
typedef class DefaultScpCredentialProvider DefaultScpCredentialProvider;
#else
typedef struct DefaultScpCredentialProvider DefaultScpCredentialProvider;
#endif /* __cplusplus */

#endif 	/* __DefaultScpCredentialProvider_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __moeSSH_LIBRARY_DEFINED__
#define __moeSSH_LIBRARY_DEFINED__

/* library moeSSH */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_moeSSH;

#ifndef __IScpPasswordCredentials_INTERFACE_DEFINED__
#define __IScpPasswordCredentials_INTERFACE_DEFINED__

/* interface IScpPasswordCredentials */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IScpPasswordCredentials;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BD96818E-5DAB-4305-B283-527D632C68D2")
    IScpPasswordCredentials : public IDispatch
    {
    public:
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Username( 
            /* [in] */ BSTR user) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Username( 
            /* [retval][out] */ BSTR *user) = 0;
        
        virtual /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Password( 
            /* [in] */ BSTR pwd) = 0;
        
        virtual /* [id][requestedit][displaybind][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Password( 
            /* [retval][out] */ BSTR *pwd) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IScpPasswordCredentialsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IScpPasswordCredentials * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IScpPasswordCredentials * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IScpPasswordCredentials * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IScpPasswordCredentials * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IScpPasswordCredentials * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IScpPasswordCredentials * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IScpPasswordCredentials * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Username )( 
            IScpPasswordCredentials * This,
            /* [in] */ BSTR user);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Username )( 
            IScpPasswordCredentials * This,
            /* [retval][out] */ BSTR *user);
        
        /* [helpstring][id][requestedit][displaybind][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Password )( 
            IScpPasswordCredentials * This,
            /* [in] */ BSTR pwd);
        
        /* [id][requestedit][displaybind][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Password )( 
            IScpPasswordCredentials * This,
            /* [retval][out] */ BSTR *pwd);
        
        END_INTERFACE
    } IScpPasswordCredentialsVtbl;

    interface IScpPasswordCredentials
    {
        CONST_VTBL struct IScpPasswordCredentialsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScpPasswordCredentials_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IScpPasswordCredentials_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IScpPasswordCredentials_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IScpPasswordCredentials_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IScpPasswordCredentials_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IScpPasswordCredentials_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IScpPasswordCredentials_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IScpPasswordCredentials_put_Username(This,user)	\
    ( (This)->lpVtbl -> put_Username(This,user) ) 

#define IScpPasswordCredentials_get_Username(This,user)	\
    ( (This)->lpVtbl -> get_Username(This,user) ) 

#define IScpPasswordCredentials_put_Password(This,pwd)	\
    ( (This)->lpVtbl -> put_Password(This,pwd) ) 

#define IScpPasswordCredentials_get_Password(This,pwd)	\
    ( (This)->lpVtbl -> get_Password(This,pwd) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IScpPasswordCredentials_INTERFACE_DEFINED__ */


#ifndef __IScpCredentialProvider_INTERFACE_DEFINED__
#define __IScpCredentialProvider_INTERFACE_DEFINED__

/* interface IScpCredentialProvider */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IScpCredentialProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6A66D47E-519D-4CA8-9B39-892E9CC7D3AF")
    IScpCredentialProvider : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getCredentials( 
            /* [in] */ BSTR host,
            /* [in] */ long port,
            /* [retval][out] */ IScpPasswordCredentials **credentials) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE promptCredentials( 
            /* [in] */ BSTR prompt,
            /* [in] */ BSTR description,
            /* [in] */ VARIANT_BOOL echo,
            /* [retval][out] */ VARIANT *value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE acceptHost( 
            /* [in] */ BSTR host,
            /* [in] */ long port,
            /* [in] */ BSTR hash,
            /* [retval][out] */ VARIANT_BOOL *accept) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE remberSessionCredentials( 
            /* [in] */ BSTR host,
            /* [in] */ long port,
            /* [in] */ IScpPasswordCredentials *credentials) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE removeSessionCredentials( 
            /* [in] */ BSTR host,
            /* [in] */ long port) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IScpCredentialProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IScpCredentialProvider * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IScpCredentialProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IScpCredentialProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IScpCredentialProvider * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IScpCredentialProvider * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IScpCredentialProvider * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IScpCredentialProvider * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getCredentials )( 
            IScpCredentialProvider * This,
            /* [in] */ BSTR host,
            /* [in] */ long port,
            /* [retval][out] */ IScpPasswordCredentials **credentials);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *promptCredentials )( 
            IScpCredentialProvider * This,
            /* [in] */ BSTR prompt,
            /* [in] */ BSTR description,
            /* [in] */ VARIANT_BOOL echo,
            /* [retval][out] */ VARIANT *value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *acceptHost )( 
            IScpCredentialProvider * This,
            /* [in] */ BSTR host,
            /* [in] */ long port,
            /* [in] */ BSTR hash,
            /* [retval][out] */ VARIANT_BOOL *accept);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *remberSessionCredentials )( 
            IScpCredentialProvider * This,
            /* [in] */ BSTR host,
            /* [in] */ long port,
            /* [in] */ IScpPasswordCredentials *credentials);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *removeSessionCredentials )( 
            IScpCredentialProvider * This,
            /* [in] */ BSTR host,
            /* [in] */ long port);
        
        END_INTERFACE
    } IScpCredentialProviderVtbl;

    interface IScpCredentialProvider
    {
        CONST_VTBL struct IScpCredentialProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScpCredentialProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IScpCredentialProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IScpCredentialProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IScpCredentialProvider_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IScpCredentialProvider_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IScpCredentialProvider_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IScpCredentialProvider_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IScpCredentialProvider_getCredentials(This,host,port,credentials)	\
    ( (This)->lpVtbl -> getCredentials(This,host,port,credentials) ) 

#define IScpCredentialProvider_promptCredentials(This,prompt,description,echo,value)	\
    ( (This)->lpVtbl -> promptCredentials(This,prompt,description,echo,value) ) 

#define IScpCredentialProvider_acceptHost(This,host,port,hash,accept)	\
    ( (This)->lpVtbl -> acceptHost(This,host,port,hash,accept) ) 

#define IScpCredentialProvider_remberSessionCredentials(This,host,port,credentials)	\
    ( (This)->lpVtbl -> remberSessionCredentials(This,host,port,credentials) ) 

#define IScpCredentialProvider_removeSessionCredentials(This,host,port)	\
    ( (This)->lpVtbl -> removeSessionCredentials(This,host,port) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IScpCredentialProvider_INTERFACE_DEFINED__ */


#ifndef __IRemoteFile_INTERFACE_DEFINED__
#define __IRemoteFile_INTERFACE_DEFINED__

/* interface IRemoteFile */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IRemoteFile;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0CAF3661-4063-416D-8548-D42144C652D3")
    IRemoteFile : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsDir( 
            /* [retval][out] */ VARIANT_BOOL *vb) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Filename( 
            /* [retval][out] */ BSTR *name) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Filetype( 
            /* [retval][out] */ long *type) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Permission( 
            /* [retval][out] */ long *perms) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UID( 
            /* [retval][out] */ long *id) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_GID( 
            /* [retval][out] */ long *id) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Mtime( 
            /* [retval][out] */ long *timestamp) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Owner( 
            /* [retval][out] */ BSTR *username) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Group( 
            /* [retval][out] */ BSTR *groupname) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Size( 
            /* [retval][out] */ long *len) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FormattedSize( 
            /* [retval][out] */ BSTR *len) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FormattedPermissions( 
            /* [retval][out] */ BSTR *len) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRemoteFileVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRemoteFile * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRemoteFile * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRemoteFile * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRemoteFile * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRemoteFile * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRemoteFile * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRemoteFile * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsDir )( 
            IRemoteFile * This,
            /* [retval][out] */ VARIANT_BOOL *vb);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Filename )( 
            IRemoteFile * This,
            /* [retval][out] */ BSTR *name);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Filetype )( 
            IRemoteFile * This,
            /* [retval][out] */ long *type);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Permission )( 
            IRemoteFile * This,
            /* [retval][out] */ long *perms);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UID )( 
            IRemoteFile * This,
            /* [retval][out] */ long *id);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_GID )( 
            IRemoteFile * This,
            /* [retval][out] */ long *id);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Mtime )( 
            IRemoteFile * This,
            /* [retval][out] */ long *timestamp);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Owner )( 
            IRemoteFile * This,
            /* [retval][out] */ BSTR *username);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Group )( 
            IRemoteFile * This,
            /* [retval][out] */ BSTR *groupname);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )( 
            IRemoteFile * This,
            /* [retval][out] */ long *len);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FormattedSize )( 
            IRemoteFile * This,
            /* [retval][out] */ BSTR *len);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FormattedPermissions )( 
            IRemoteFile * This,
            /* [retval][out] */ BSTR *len);
        
        END_INTERFACE
    } IRemoteFileVtbl;

    interface IRemoteFile
    {
        CONST_VTBL struct IRemoteFileVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRemoteFile_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRemoteFile_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRemoteFile_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRemoteFile_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IRemoteFile_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IRemoteFile_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IRemoteFile_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IRemoteFile_get_IsDir(This,vb)	\
    ( (This)->lpVtbl -> get_IsDir(This,vb) ) 

#define IRemoteFile_get_Filename(This,name)	\
    ( (This)->lpVtbl -> get_Filename(This,name) ) 

#define IRemoteFile_get_Filetype(This,type)	\
    ( (This)->lpVtbl -> get_Filetype(This,type) ) 

#define IRemoteFile_get_Permission(This,perms)	\
    ( (This)->lpVtbl -> get_Permission(This,perms) ) 

#define IRemoteFile_get_UID(This,id)	\
    ( (This)->lpVtbl -> get_UID(This,id) ) 

#define IRemoteFile_get_GID(This,id)	\
    ( (This)->lpVtbl -> get_GID(This,id) ) 

#define IRemoteFile_get_Mtime(This,timestamp)	\
    ( (This)->lpVtbl -> get_Mtime(This,timestamp) ) 

#define IRemoteFile_get_Owner(This,username)	\
    ( (This)->lpVtbl -> get_Owner(This,username) ) 

#define IRemoteFile_get_Group(This,groupname)	\
    ( (This)->lpVtbl -> get_Group(This,groupname) ) 

#define IRemoteFile_get_Size(This,len)	\
    ( (This)->lpVtbl -> get_Size(This,len) ) 

#define IRemoteFile_get_FormattedSize(This,len)	\
    ( (This)->lpVtbl -> get_FormattedSize(This,len) ) 

#define IRemoteFile_get_FormattedPermissions(This,len)	\
    ( (This)->lpVtbl -> get_FormattedPermissions(This,len) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRemoteFile_INTERFACE_DEFINED__ */


#ifndef __ISFTP_INTERFACE_DEFINED__
#define __ISFTP_INTERFACE_DEFINED__

/* interface ISFTP */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_ISFTP;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("277DC7E4-6329-4D3B-9EE3-2B198A6C8A07")
    ISFTP : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Mkdir( 
            /* [in] */ BSTR path,
            /* [in] */ long mode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Rmdir( 
            /* [in] */ BSTR path) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Rename( 
            /* [in] */ BSTR oldpath,
            /* [in] */ BSTR newpath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Unlink( 
            /* [in] */ BSTR path) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Chown( 
            /* [in] */ BSTR path,
            /* [in] */ long owner,
            /* [in] */ long group) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Stat( 
            /* [in] */ BSTR path,
            /* [retval][out] */ IRemoteFile **remotefile) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Lstat( 
            /* [in] */ BSTR path,
            /* [retval][out] */ IRemoteFile **remotefile) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Files( 
            /* [in] */ BSTR path,
            /* [retval][out] */ SAFEARRAY * *remotefiles) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE List( 
            /* [in] */ BSTR path,
            /* [retval][out] */ SAFEARRAY * *remotefiles) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISFTPVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISFTP * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISFTP * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISFTP * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISFTP * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISFTP * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISFTP * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISFTP * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Mkdir )( 
            ISFTP * This,
            /* [in] */ BSTR path,
            /* [in] */ long mode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rmdir )( 
            ISFTP * This,
            /* [in] */ BSTR path);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rename )( 
            ISFTP * This,
            /* [in] */ BSTR oldpath,
            /* [in] */ BSTR newpath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Unlink )( 
            ISFTP * This,
            /* [in] */ BSTR path);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Chown )( 
            ISFTP * This,
            /* [in] */ BSTR path,
            /* [in] */ long owner,
            /* [in] */ long group);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Stat )( 
            ISFTP * This,
            /* [in] */ BSTR path,
            /* [retval][out] */ IRemoteFile **remotefile);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Lstat )( 
            ISFTP * This,
            /* [in] */ BSTR path,
            /* [retval][out] */ IRemoteFile **remotefile);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Files )( 
            ISFTP * This,
            /* [in] */ BSTR path,
            /* [retval][out] */ SAFEARRAY * *remotefiles);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *List )( 
            ISFTP * This,
            /* [in] */ BSTR path,
            /* [retval][out] */ SAFEARRAY * *remotefiles);
        
        END_INTERFACE
    } ISFTPVtbl;

    interface ISFTP
    {
        CONST_VTBL struct ISFTPVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISFTP_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISFTP_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISFTP_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISFTP_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISFTP_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISFTP_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISFTP_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISFTP_Mkdir(This,path,mode)	\
    ( (This)->lpVtbl -> Mkdir(This,path,mode) ) 

#define ISFTP_Rmdir(This,path)	\
    ( (This)->lpVtbl -> Rmdir(This,path) ) 

#define ISFTP_Rename(This,oldpath,newpath)	\
    ( (This)->lpVtbl -> Rename(This,oldpath,newpath) ) 

#define ISFTP_Unlink(This,path)	\
    ( (This)->lpVtbl -> Unlink(This,path) ) 

#define ISFTP_Chown(This,path,owner,group)	\
    ( (This)->lpVtbl -> Chown(This,path,owner,group) ) 

#define ISFTP_Stat(This,path,remotefile)	\
    ( (This)->lpVtbl -> Stat(This,path,remotefile) ) 

#define ISFTP_Lstat(This,path,remotefile)	\
    ( (This)->lpVtbl -> Lstat(This,path,remotefile) ) 

#define ISFTP_Files(This,path,remotefiles)	\
    ( (This)->lpVtbl -> Files(This,path,remotefiles) ) 

#define ISFTP_List(This,path,remotefiles)	\
    ( (This)->lpVtbl -> List(This,path,remotefiles) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISFTP_INTERFACE_DEFINED__ */


#ifndef __ISCP_INTERFACE_DEFINED__
#define __ISCP_INTERFACE_DEFINED__

/* interface ISCP */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_ISCP;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("873F0BE6-8E22-472A-B071-AC1EA3854278")
    ISCP : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PushDirectory( 
            /* [in] */ BSTR path,
            /* [in] */ BSTR remotedir) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PushFile( 
            /* [in] */ BSTR path,
            /* [in] */ BSTR remotedir) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteFile( 
            /* [in] */ BSTR content,
            /* [in] */ BSTR remotedir) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutFile( 
            /* [in] */ SAFEARRAY * content,
            /* [in] */ BSTR remotedir) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PullDirectory( 
            /* [in] */ BSTR remotedir,
            /* [in] */ BSTR localdir) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PullFile( 
            /* [in] */ BSTR remotefile,
            /* [in] */ BSTR localdir) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadFile( 
            /* [in] */ BSTR remotefile,
            /* [retval][out] */ BSTR *content) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFile( 
            /* [in] */ BSTR remotefile,
            /* [retval][out] */ SAFEARRAY * *content) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISCPVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISCP * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISCP * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISCP * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISCP * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISCP * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISCP * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISCP * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PushDirectory )( 
            ISCP * This,
            /* [in] */ BSTR path,
            /* [in] */ BSTR remotedir);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PushFile )( 
            ISCP * This,
            /* [in] */ BSTR path,
            /* [in] */ BSTR remotedir);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteFile )( 
            ISCP * This,
            /* [in] */ BSTR content,
            /* [in] */ BSTR remotedir);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutFile )( 
            ISCP * This,
            /* [in] */ SAFEARRAY * content,
            /* [in] */ BSTR remotedir);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PullDirectory )( 
            ISCP * This,
            /* [in] */ BSTR remotedir,
            /* [in] */ BSTR localdir);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PullFile )( 
            ISCP * This,
            /* [in] */ BSTR remotefile,
            /* [in] */ BSTR localdir);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadFile )( 
            ISCP * This,
            /* [in] */ BSTR remotefile,
            /* [retval][out] */ BSTR *content);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFile )( 
            ISCP * This,
            /* [in] */ BSTR remotefile,
            /* [retval][out] */ SAFEARRAY * *content);
        
        END_INTERFACE
    } ISCPVtbl;

    interface ISCP
    {
        CONST_VTBL struct ISCPVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISCP_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISCP_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISCP_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISCP_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISCP_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISCP_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISCP_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISCP_PushDirectory(This,path,remotedir)	\
    ( (This)->lpVtbl -> PushDirectory(This,path,remotedir) ) 

#define ISCP_PushFile(This,path,remotedir)	\
    ( (This)->lpVtbl -> PushFile(This,path,remotedir) ) 

#define ISCP_WriteFile(This,content,remotedir)	\
    ( (This)->lpVtbl -> WriteFile(This,content,remotedir) ) 

#define ISCP_PutFile(This,content,remotedir)	\
    ( (This)->lpVtbl -> PutFile(This,content,remotedir) ) 

#define ISCP_PullDirectory(This,remotedir,localdir)	\
    ( (This)->lpVtbl -> PullDirectory(This,remotedir,localdir) ) 

#define ISCP_PullFile(This,remotefile,localdir)	\
    ( (This)->lpVtbl -> PullFile(This,remotefile,localdir) ) 

#define ISCP_ReadFile(This,remotefile,content)	\
    ( (This)->lpVtbl -> ReadFile(This,remotefile,content) ) 

#define ISCP_GetFile(This,remotefile,content)	\
    ( (This)->lpVtbl -> GetFile(This,remotefile,content) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISCP_INTERFACE_DEFINED__ */


#ifndef __ISSHConnection_INTERFACE_DEFINED__
#define __ISSHConnection_INTERFACE_DEFINED__

/* interface ISSHConnection */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_ISSHConnection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5DDB7A6C-4283-4A1D-A15D-FB761DD1340B")
    ISSHConnection : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Hostname( 
            /* [retval][out] */ BSTR *host) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Portnumber( 
            /* [retval][out] */ long *port) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsConnected( 
            /* [retval][out] */ VARIANT_BOOL *connected) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ServerBanner( 
            /* [retval][out] */ BSTR *banner) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Banner( 
            /* [retval][out] */ BSTR *banner) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ServerHash( 
            /* [retval][out] */ BSTR *hash) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Error( 
            /* [retval][out] */ BSTR *err) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SCP( 
            /* [retval][out] */ ISCP **conn) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SFTP( 
            /* [retval][out] */ ISFTP **conn) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Execute( 
            /* [in] */ BSTR cmd,
            /* [retval][out] */ BSTR *result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Send( 
            /* [in] */ BSTR cmd,
            /* [in] */ BSTR data,
            /* [retval][out] */ BSTR *result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UsernameFromUID( 
            /* [in] */ long uid,
            /* [retval][out] */ BSTR *result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GroupnameFromGID( 
            /* [in] */ long gid,
            /* [retval][out] */ BSTR *result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UIDfromUsername( 
            /* [in] */ BSTR name,
            /* [retval][out] */ long *result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GIDfromGroupname( 
            /* [in] */ BSTR name,
            /* [retval][out] */ long *result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Connect( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISSHConnectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISSHConnection * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISSHConnection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISSHConnection * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISSHConnection * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISSHConnection * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISSHConnection * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISSHConnection * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Hostname )( 
            ISSHConnection * This,
            /* [retval][out] */ BSTR *host);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Portnumber )( 
            ISSHConnection * This,
            /* [retval][out] */ long *port);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsConnected )( 
            ISSHConnection * This,
            /* [retval][out] */ VARIANT_BOOL *connected);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ServerBanner )( 
            ISSHConnection * This,
            /* [retval][out] */ BSTR *banner);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Banner )( 
            ISSHConnection * This,
            /* [retval][out] */ BSTR *banner);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ServerHash )( 
            ISSHConnection * This,
            /* [retval][out] */ BSTR *hash);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Error )( 
            ISSHConnection * This,
            /* [retval][out] */ BSTR *err);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SCP )( 
            ISSHConnection * This,
            /* [retval][out] */ ISCP **conn);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SFTP )( 
            ISSHConnection * This,
            /* [retval][out] */ ISFTP **conn);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Execute )( 
            ISSHConnection * This,
            /* [in] */ BSTR cmd,
            /* [retval][out] */ BSTR *result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Send )( 
            ISSHConnection * This,
            /* [in] */ BSTR cmd,
            /* [in] */ BSTR data,
            /* [retval][out] */ BSTR *result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UsernameFromUID )( 
            ISSHConnection * This,
            /* [in] */ long uid,
            /* [retval][out] */ BSTR *result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GroupnameFromGID )( 
            ISSHConnection * This,
            /* [in] */ long gid,
            /* [retval][out] */ BSTR *result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UIDfromUsername )( 
            ISSHConnection * This,
            /* [in] */ BSTR name,
            /* [retval][out] */ long *result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GIDfromGroupname )( 
            ISSHConnection * This,
            /* [in] */ BSTR name,
            /* [retval][out] */ long *result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Connect )( 
            ISSHConnection * This);
        
        END_INTERFACE
    } ISSHConnectionVtbl;

    interface ISSHConnection
    {
        CONST_VTBL struct ISSHConnectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISSHConnection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISSHConnection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISSHConnection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISSHConnection_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISSHConnection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISSHConnection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISSHConnection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISSHConnection_get_Hostname(This,host)	\
    ( (This)->lpVtbl -> get_Hostname(This,host) ) 

#define ISSHConnection_get_Portnumber(This,port)	\
    ( (This)->lpVtbl -> get_Portnumber(This,port) ) 

#define ISSHConnection_get_IsConnected(This,connected)	\
    ( (This)->lpVtbl -> get_IsConnected(This,connected) ) 

#define ISSHConnection_get_ServerBanner(This,banner)	\
    ( (This)->lpVtbl -> get_ServerBanner(This,banner) ) 

#define ISSHConnection_get_Banner(This,banner)	\
    ( (This)->lpVtbl -> get_Banner(This,banner) ) 

#define ISSHConnection_get_ServerHash(This,hash)	\
    ( (This)->lpVtbl -> get_ServerHash(This,hash) ) 

#define ISSHConnection_get_Error(This,err)	\
    ( (This)->lpVtbl -> get_Error(This,err) ) 

#define ISSHConnection_get_SCP(This,conn)	\
    ( (This)->lpVtbl -> get_SCP(This,conn) ) 

#define ISSHConnection_get_SFTP(This,conn)	\
    ( (This)->lpVtbl -> get_SFTP(This,conn) ) 

#define ISSHConnection_Execute(This,cmd,result)	\
    ( (This)->lpVtbl -> Execute(This,cmd,result) ) 

#define ISSHConnection_Send(This,cmd,data,result)	\
    ( (This)->lpVtbl -> Send(This,cmd,data,result) ) 

#define ISSHConnection_UsernameFromUID(This,uid,result)	\
    ( (This)->lpVtbl -> UsernameFromUID(This,uid,result) ) 

#define ISSHConnection_GroupnameFromGID(This,gid,result)	\
    ( (This)->lpVtbl -> GroupnameFromGID(This,gid,result) ) 

#define ISSHConnection_UIDfromUsername(This,name,result)	\
    ( (This)->lpVtbl -> UIDfromUsername(This,name,result) ) 

#define ISSHConnection_GIDfromGroupname(This,name,result)	\
    ( (This)->lpVtbl -> GIDfromGroupname(This,name,result) ) 

#define ISSHConnection_Connect(This)	\
    ( (This)->lpVtbl -> Connect(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISSHConnection_INTERFACE_DEFINED__ */


#ifndef __ISSH_INTERFACE_DEFINED__
#define __ISSH_INTERFACE_DEFINED__

/* interface ISSH */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_ISSH;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A03D1837-B2B1-486B-9A42-24D14571FCF6")
    ISSH : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Credentials( 
            /* [retval][out] */ IScpCredentialProvider **credentials) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Credentials( 
            /* [in] */ IScpCredentialProvider *credentials) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Connect( 
            /* [in] */ BSTR hostname,
            /* [in] */ long port,
            /* [retval][out] */ ISSHConnection **conn) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISSHVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISSH * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISSH * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISSH * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISSH * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISSH * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISSH * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISSH * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Credentials )( 
            ISSH * This,
            /* [retval][out] */ IScpCredentialProvider **credentials);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Credentials )( 
            ISSH * This,
            /* [in] */ IScpCredentialProvider *credentials);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Connect )( 
            ISSH * This,
            /* [in] */ BSTR hostname,
            /* [in] */ long port,
            /* [retval][out] */ ISSHConnection **conn);
        
        END_INTERFACE
    } ISSHVtbl;

    interface ISSH
    {
        CONST_VTBL struct ISSHVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISSH_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISSH_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISSH_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISSH_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISSH_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISSH_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISSH_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISSH_get_Credentials(This,credentials)	\
    ( (This)->lpVtbl -> get_Credentials(This,credentials) ) 

#define ISSH_put_Credentials(This,credentials)	\
    ( (This)->lpVtbl -> put_Credentials(This,credentials) ) 

#define ISSH_Connect(This,hostname,port,conn)	\
    ( (This)->lpVtbl -> Connect(This,hostname,port,conn) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISSH_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_SSH;

#ifdef __cplusplus

class DECLSPEC_UUID("001C9766-9D66-4554-AC40-15F3B051DE29")
SSH;
#endif

EXTERN_C const CLSID CLSID_ScpPasswordCredentials;

#ifdef __cplusplus

class DECLSPEC_UUID("46861300-31F7-44F9-B4F6-449D66F3AC77")
ScpPasswordCredentials;
#endif

EXTERN_C const CLSID CLSID_DefaultScpCredentialProvider;

#ifdef __cplusplus

class DECLSPEC_UUID("CF5BF8BD-DC91-43CA-AB1A-FF04CCACEFB6")
DefaultScpCredentialProvider;
#endif
#endif /* __moeSSH_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


