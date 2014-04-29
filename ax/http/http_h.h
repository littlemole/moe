

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Sun Apr 27 23:21:59 2014
 */
/* Compiler settings for http.idl:
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


#ifndef __http_h_h__
#define __http_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IHttp_FWD_DEFINED__
#define __IHttp_FWD_DEFINED__
typedef interface IHttp IHttp;

#endif 	/* __IHttp_FWD_DEFINED__ */


#ifndef __IHttpHeaders_FWD_DEFINED__
#define __IHttpHeaders_FWD_DEFINED__
typedef interface IHttpHeaders IHttpHeaders;

#endif 	/* __IHttpHeaders_FWD_DEFINED__ */


#ifndef __IHttpRequest_FWD_DEFINED__
#define __IHttpRequest_FWD_DEFINED__
typedef interface IHttpRequest IHttpRequest;

#endif 	/* __IHttpRequest_FWD_DEFINED__ */


#ifndef __IHttpResponse_FWD_DEFINED__
#define __IHttpResponse_FWD_DEFINED__
typedef interface IHttpResponse IHttpResponse;

#endif 	/* __IHttpResponse_FWD_DEFINED__ */


#ifndef __IHttpHeader_FWD_DEFINED__
#define __IHttpHeader_FWD_DEFINED__
typedef interface IHttpHeader IHttpHeader;

#endif 	/* __IHttpHeader_FWD_DEFINED__ */


#ifndef __Client_FWD_DEFINED__
#define __Client_FWD_DEFINED__

#ifdef __cplusplus
typedef class Client Client;
#else
typedef struct Client Client;
#endif /* __cplusplus */

#endif 	/* __Client_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __HTTP_LIBRARY_DEFINED__
#define __HTTP_LIBRARY_DEFINED__

/* library HTTP */
/* [helpstring][version][uuid] */ 







EXTERN_C const IID LIBID_HTTP;

#ifndef __IHttp_INTERFACE_DEFINED__
#define __IHttp_INTERFACE_DEFINED__

/* interface IHttp */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IHttp;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("65ECE645-63A0-422B-9551-30BABE5C0D46")
    IHttp : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Get( 
            /* [in] */ BSTR url,
            /* [retval][out] */ IHttpRequest **request) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Request( 
            /* [in] */ BSTR cmd,
            /* [retval][out] */ IHttpRequest **request) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IHttpVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHttp * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHttp * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHttp * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IHttp * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IHttp * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IHttp * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IHttp * This,
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
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Get )( 
            IHttp * This,
            /* [in] */ BSTR url,
            /* [retval][out] */ IHttpRequest **request);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Request )( 
            IHttp * This,
            /* [in] */ BSTR cmd,
            /* [retval][out] */ IHttpRequest **request);
        
        END_INTERFACE
    } IHttpVtbl;

    interface IHttp
    {
        CONST_VTBL struct IHttpVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHttp_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IHttp_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IHttp_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IHttp_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IHttp_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IHttp_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IHttp_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IHttp_Get(This,url,request)	\
    ( (This)->lpVtbl -> Get(This,url,request) ) 

#define IHttp_Request(This,cmd,request)	\
    ( (This)->lpVtbl -> Request(This,cmd,request) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IHttp_INTERFACE_DEFINED__ */


#ifndef __IHttpHeaders_INTERFACE_DEFINED__
#define __IHttpHeaders_INTERFACE_DEFINED__

/* interface IHttpHeaders */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IHttpHeaders;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E4371FB6-0126-41D1-8E37-B71715C07104")
    IHttpHeaders : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE _NewEnum( 
            /* [retval][out] */ IEnumVARIANT **newEnum) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ VARIANT i,
            /* [retval][out] */ VARIANT *header) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Count( 
            /* [retval][out] */ long *cnt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ BSTR name,
            /* [in] */ BSTR value) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IHttpHeadersVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHttpHeaders * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHttpHeaders * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHttpHeaders * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IHttpHeaders * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IHttpHeaders * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IHttpHeaders * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IHttpHeaders * This,
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
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *_NewEnum )( 
            IHttpHeaders * This,
            /* [retval][out] */ IEnumVARIANT **newEnum);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            IHttpHeaders * This,
            /* [in] */ VARIANT i,
            /* [retval][out] */ VARIANT *header);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Count )( 
            IHttpHeaders * This,
            /* [retval][out] */ long *cnt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IHttpHeaders * This,
            /* [in] */ BSTR name,
            /* [in] */ BSTR value);
        
        END_INTERFACE
    } IHttpHeadersVtbl;

    interface IHttpHeaders
    {
        CONST_VTBL struct IHttpHeadersVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHttpHeaders_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IHttpHeaders_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IHttpHeaders_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IHttpHeaders_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IHttpHeaders_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IHttpHeaders_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IHttpHeaders_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IHttpHeaders__NewEnum(This,newEnum)	\
    ( (This)->lpVtbl -> _NewEnum(This,newEnum) ) 

#define IHttpHeaders_Item(This,i,header)	\
    ( (This)->lpVtbl -> Item(This,i,header) ) 

#define IHttpHeaders_Count(This,cnt)	\
    ( (This)->lpVtbl -> Count(This,cnt) ) 

#define IHttpHeaders_Add(This,name,value)	\
    ( (This)->lpVtbl -> Add(This,name,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IHttpHeaders_INTERFACE_DEFINED__ */


#ifndef __IHttpRequest_INTERFACE_DEFINED__
#define __IHttpRequest_INTERFACE_DEFINED__

/* interface IHttpRequest */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IHttpRequest;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1800C704-0169-4C4A-96BC-EABEB2DD4606")
    IHttpRequest : public IDispatch
    {
    public:
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_onResult( 
            /* [in] */ IDispatch *cb) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_onError( 
            /* [in] */ IDispatch *cb) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Url( 
            /* [in] */ BSTR m) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Url( 
            /* [retval][out] */ BSTR *m) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Method( 
            /* [in] */ BSTR m) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Method( 
            /* [retval][out] */ BSTR *m) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Version( 
            /* [in] */ BSTR m) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Version( 
            /* [retval][out] */ BSTR *m) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Headers( 
            /* [in] */ IHttpHeaders *h) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Headers( 
            /* [retval][out] */ IHttpHeaders **h) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Body( 
            /* [in] */ BSTR b) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Body( 
            /* [retval][out] */ BSTR *b) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Execute( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IHttpRequestVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHttpRequest * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHttpRequest * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHttpRequest * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IHttpRequest * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IHttpRequest * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IHttpRequest * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IHttpRequest * This,
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
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_onResult )( 
            IHttpRequest * This,
            /* [in] */ IDispatch *cb);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_onError )( 
            IHttpRequest * This,
            /* [in] */ IDispatch *cb);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Url )( 
            IHttpRequest * This,
            /* [in] */ BSTR m);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Url )( 
            IHttpRequest * This,
            /* [retval][out] */ BSTR *m);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Method )( 
            IHttpRequest * This,
            /* [in] */ BSTR m);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Method )( 
            IHttpRequest * This,
            /* [retval][out] */ BSTR *m);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Version )( 
            IHttpRequest * This,
            /* [in] */ BSTR m);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Version )( 
            IHttpRequest * This,
            /* [retval][out] */ BSTR *m);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Headers )( 
            IHttpRequest * This,
            /* [in] */ IHttpHeaders *h);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Headers )( 
            IHttpRequest * This,
            /* [retval][out] */ IHttpHeaders **h);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Body )( 
            IHttpRequest * This,
            /* [in] */ BSTR b);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Body )( 
            IHttpRequest * This,
            /* [retval][out] */ BSTR *b);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Execute )( 
            IHttpRequest * This);
        
        END_INTERFACE
    } IHttpRequestVtbl;

    interface IHttpRequest
    {
        CONST_VTBL struct IHttpRequestVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHttpRequest_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IHttpRequest_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IHttpRequest_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IHttpRequest_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IHttpRequest_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IHttpRequest_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IHttpRequest_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IHttpRequest_put_onResult(This,cb)	\
    ( (This)->lpVtbl -> put_onResult(This,cb) ) 

#define IHttpRequest_put_onError(This,cb)	\
    ( (This)->lpVtbl -> put_onError(This,cb) ) 

#define IHttpRequest_put_Url(This,m)	\
    ( (This)->lpVtbl -> put_Url(This,m) ) 

#define IHttpRequest_get_Url(This,m)	\
    ( (This)->lpVtbl -> get_Url(This,m) ) 

#define IHttpRequest_put_Method(This,m)	\
    ( (This)->lpVtbl -> put_Method(This,m) ) 

#define IHttpRequest_get_Method(This,m)	\
    ( (This)->lpVtbl -> get_Method(This,m) ) 

#define IHttpRequest_put_Version(This,m)	\
    ( (This)->lpVtbl -> put_Version(This,m) ) 

#define IHttpRequest_get_Version(This,m)	\
    ( (This)->lpVtbl -> get_Version(This,m) ) 

#define IHttpRequest_put_Headers(This,h)	\
    ( (This)->lpVtbl -> put_Headers(This,h) ) 

#define IHttpRequest_get_Headers(This,h)	\
    ( (This)->lpVtbl -> get_Headers(This,h) ) 

#define IHttpRequest_put_Body(This,b)	\
    ( (This)->lpVtbl -> put_Body(This,b) ) 

#define IHttpRequest_get_Body(This,b)	\
    ( (This)->lpVtbl -> get_Body(This,b) ) 

#define IHttpRequest_Execute(This)	\
    ( (This)->lpVtbl -> Execute(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IHttpRequest_INTERFACE_DEFINED__ */


#ifndef __IHttpResponse_INTERFACE_DEFINED__
#define __IHttpResponse_INTERFACE_DEFINED__

/* interface IHttpResponse */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IHttpResponse;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("39171BA0-B240-428A-87A6-6C2DC925A2B4")
    IHttpResponse : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Status( 
            /* [retval][out] */ LONG *s) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Status( 
            /* [in] */ LONG s) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Body( 
            /* [retval][out] */ BSTR *s) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Body( 
            /* [in] */ BSTR b) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Size( 
            /* [retval][out] */ long *s) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Size( 
            /* [in] */ long b) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Headers( 
            /* [in] */ IHttpHeaders *h) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Headers( 
            /* [retval][out] */ IHttpHeaders **h) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IHttpResponseVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHttpResponse * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHttpResponse * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHttpResponse * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IHttpResponse * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IHttpResponse * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IHttpResponse * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IHttpResponse * This,
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
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            IHttpResponse * This,
            /* [retval][out] */ LONG *s);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Status )( 
            IHttpResponse * This,
            /* [in] */ LONG s);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Body )( 
            IHttpResponse * This,
            /* [retval][out] */ BSTR *s);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Body )( 
            IHttpResponse * This,
            /* [in] */ BSTR b);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )( 
            IHttpResponse * This,
            /* [retval][out] */ long *s);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Size )( 
            IHttpResponse * This,
            /* [in] */ long b);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Headers )( 
            IHttpResponse * This,
            /* [in] */ IHttpHeaders *h);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Headers )( 
            IHttpResponse * This,
            /* [retval][out] */ IHttpHeaders **h);
        
        END_INTERFACE
    } IHttpResponseVtbl;

    interface IHttpResponse
    {
        CONST_VTBL struct IHttpResponseVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHttpResponse_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IHttpResponse_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IHttpResponse_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IHttpResponse_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IHttpResponse_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IHttpResponse_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IHttpResponse_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IHttpResponse_get_Status(This,s)	\
    ( (This)->lpVtbl -> get_Status(This,s) ) 

#define IHttpResponse_put_Status(This,s)	\
    ( (This)->lpVtbl -> put_Status(This,s) ) 

#define IHttpResponse_get_Body(This,s)	\
    ( (This)->lpVtbl -> get_Body(This,s) ) 

#define IHttpResponse_put_Body(This,b)	\
    ( (This)->lpVtbl -> put_Body(This,b) ) 

#define IHttpResponse_get_Size(This,s)	\
    ( (This)->lpVtbl -> get_Size(This,s) ) 

#define IHttpResponse_put_Size(This,b)	\
    ( (This)->lpVtbl -> put_Size(This,b) ) 

#define IHttpResponse_put_Headers(This,h)	\
    ( (This)->lpVtbl -> put_Headers(This,h) ) 

#define IHttpResponse_get_Headers(This,h)	\
    ( (This)->lpVtbl -> get_Headers(This,h) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IHttpResponse_INTERFACE_DEFINED__ */


#ifndef __IHttpHeader_INTERFACE_DEFINED__
#define __IHttpHeader_INTERFACE_DEFINED__

/* interface IHttpHeader */
/* [dual][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IHttpHeader;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0770FB34-58D4-4417-B47E-B07D2CA604B9")
    IHttpHeader : public IDispatch
    {
    public:
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR m) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *m) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Value( 
            /* [in] */ BSTR m) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [retval][out] */ BSTR *m) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IHttpHeaderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHttpHeader * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHttpHeader * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHttpHeader * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IHttpHeader * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IHttpHeader * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IHttpHeader * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IHttpHeader * This,
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
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IHttpHeader * This,
            /* [in] */ BSTR m);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IHttpHeader * This,
            /* [retval][out] */ BSTR *m);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Value )( 
            IHttpHeader * This,
            /* [in] */ BSTR m);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            IHttpHeader * This,
            /* [retval][out] */ BSTR *m);
        
        END_INTERFACE
    } IHttpHeaderVtbl;

    interface IHttpHeader
    {
        CONST_VTBL struct IHttpHeaderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHttpHeader_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IHttpHeader_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IHttpHeader_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IHttpHeader_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IHttpHeader_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IHttpHeader_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IHttpHeader_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IHttpHeader_put_Name(This,m)	\
    ( (This)->lpVtbl -> put_Name(This,m) ) 

#define IHttpHeader_get_Name(This,m)	\
    ( (This)->lpVtbl -> get_Name(This,m) ) 

#define IHttpHeader_put_Value(This,m)	\
    ( (This)->lpVtbl -> put_Value(This,m) ) 

#define IHttpHeader_get_Value(This,m)	\
    ( (This)->lpVtbl -> get_Value(This,m) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IHttpHeader_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Client;

#ifdef __cplusplus

class DECLSPEC_UUID("E39732D8-7B64-4DC3-9924-9F216345F07A")
Client;
#endif
#endif /* __HTTP_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


