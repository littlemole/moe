

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Sun Sep 11 12:48:32 2011
 */
/* Compiler settings for java.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#if defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4152 )  /* function/data pointer conversion in expression */

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif /* __RPCPROXY_H_VERSION__ */


#include "java.h"

#define TYPE_FORMAT_STRING_SIZE   15                                
#define PROC_FORMAT_STRING_SIZE   77                                
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _java_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } java_MIDL_TYPE_FORMAT_STRING;

typedef struct _java_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } java_MIDL_PROC_FORMAT_STRING;

typedef struct _java_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } java_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const java_MIDL_TYPE_FORMAT_STRING java__MIDL_TypeFormatString;
extern const java_MIDL_PROC_FORMAT_STRING java__MIDL_ProcFormatString;
extern const java_MIDL_EXPR_FORMAT_STRING java__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IJavaClass_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IJavaClass_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IJavaObject_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IJavaObject_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ISwingObject_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ISwingObject_ProxyInfo;



#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

static const java_MIDL_PROC_FORMAT_STRING java__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure Initialize */


	/* Procedure Initialize */


	/* Procedure Initialize */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
/*  8 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 10 */	NdrFcShort( 0x1c ),	/* 28 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 16 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */
/* 24 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */


	/* Parameter ptr */


	/* Parameter ptr */

/* 26 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 28 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 30 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 32 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 34 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 36 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RawPtr */


	/* Procedure RawPtr */


	/* Procedure RawPtr */

/* 38 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 40 */	NdrFcLong( 0x0 ),	/* 0 */
/* 44 */	NdrFcShort( 0x8 ),	/* 8 */
/* 46 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 48 */	NdrFcShort( 0x0 ),	/* 0 */
/* 50 */	NdrFcShort( 0x38 ),	/* 56 */
/* 52 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 54 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */
/* 58 */	NdrFcShort( 0x0 ),	/* 0 */
/* 60 */	NdrFcShort( 0x0 ),	/* 0 */
/* 62 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ptr */


	/* Parameter ptr */


	/* Parameter ptr */

/* 64 */	NdrFcShort( 0x2012 ),	/* Flags:  must free, out, srv alloc size=8 */
/* 66 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 68 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 70 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 72 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 74 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const java_MIDL_TYPE_FORMAT_STRING java__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/*  4 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/*  6 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/*  8 */	NdrFcShort( 0x2 ),	/* Offset= 2 (10) */
/* 10 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 12 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */

			0x0
        }
    };


/* Standard interface: __MIDL_itf_java_0000_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IJavaClass, ver. 0.0,
   GUID={0xEA028093,0x8B55,0x4D3B,{0x8B,0x0F,0x82,0x43,0x01,0x50,0x44,0x55}} */

#pragma code_seg(".orpc")
static const unsigned short IJavaClass_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    38
    };

static const MIDL_STUBLESS_PROXY_INFO IJavaClass_ProxyInfo =
    {
    &Object_StubDesc,
    java__MIDL_ProcFormatString.Format,
    &IJavaClass_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IJavaClass_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    java__MIDL_ProcFormatString.Format,
    &IJavaClass_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(9) _IJavaClassProxyVtbl = 
{
    &IJavaClass_ProxyInfo,
    &IID_IJavaClass,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IJavaClass::Initialize */ ,
    (void *) (INT_PTR) -1 /* IJavaClass::RawPtr */
};


static const PRPC_STUB_FUNCTION IJavaClass_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IJavaClassStubVtbl =
{
    &IID_IJavaClass,
    &IJavaClass_ServerInfo,
    9,
    &IJavaClass_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IJavaObject, ver. 0.0,
   GUID={0x1900068C,0xD7A1,0x4654,{0x90,0x19,0x4F,0x28,0xDE,0x1D,0xE8,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IJavaObject_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    38
    };

static const MIDL_STUBLESS_PROXY_INFO IJavaObject_ProxyInfo =
    {
    &Object_StubDesc,
    java__MIDL_ProcFormatString.Format,
    &IJavaObject_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IJavaObject_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    java__MIDL_ProcFormatString.Format,
    &IJavaObject_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(9) _IJavaObjectProxyVtbl = 
{
    &IJavaObject_ProxyInfo,
    &IID_IJavaObject,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IJavaObject::Initialize */ ,
    (void *) (INT_PTR) -1 /* IJavaObject::RawPtr */
};


static const PRPC_STUB_FUNCTION IJavaObject_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IJavaObjectStubVtbl =
{
    &IID_IJavaObject,
    &IJavaObject_ServerInfo,
    9,
    &IJavaObject_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: ISwingObject, ver. 0.0,
   GUID={0x26BA436D,0x6051,0x4264,{0x92,0xC6,0xBA,0xEC,0x7F,0xA4,0x00,0x50}} */

#pragma code_seg(".orpc")
static const unsigned short ISwingObject_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    38
    };

static const MIDL_STUBLESS_PROXY_INFO ISwingObject_ProxyInfo =
    {
    &Object_StubDesc,
    java__MIDL_ProcFormatString.Format,
    &ISwingObject_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ISwingObject_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    java__MIDL_ProcFormatString.Format,
    &ISwingObject_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(9) _ISwingObjectProxyVtbl = 
{
    &ISwingObject_ProxyInfo,
    &IID_ISwingObject,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* ISwingObject::Initialize */ ,
    (void *) (INT_PTR) -1 /* ISwingObject::RawPtr */
};


static const PRPC_STUB_FUNCTION ISwingObject_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _ISwingObjectStubVtbl =
{
    &IID_ISwingObject,
    &ISwingObject_ServerInfo,
    9,
    &ISwingObject_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    java__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x700022b, /* MIDL Version 7.0.555 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

const CInterfaceProxyVtbl * const _java_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_ISwingObjectProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IJavaObjectProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IJavaClassProxyVtbl,
    0
};

const CInterfaceStubVtbl * const _java_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_ISwingObjectStubVtbl,
    ( CInterfaceStubVtbl *) &_IJavaObjectStubVtbl,
    ( CInterfaceStubVtbl *) &_IJavaClassStubVtbl,
    0
};

PCInterfaceName const _java_InterfaceNamesList[] = 
{
    "ISwingObject",
    "IJavaObject",
    "IJavaClass",
    0
};

const IID *  const _java_BaseIIDList[] = 
{
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    0
};


#define _java_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _java, pIID, n)

int __stdcall _java_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _java, 3, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _java, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _java, 3, *pIndex )
    
}

const ExtendedProxyFileInfo java_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _java_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _java_StubVtblList,
    (const PCInterfaceName * ) & _java_InterfaceNamesList,
    (const IID ** ) & _java_BaseIIDList,
    & _java_IID_Lookup, 
    3,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* defined(_M_AMD64)*/

