

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Wed May 12 18:27:10 2010
 */
/* Compiler settings for .\src\moe.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_Moe,0xE5769EB9,0xADD9,0x41e5,0x8D,0x3D,0xD9,0x25,0xC7,0xFC,0x0C,0x29);


MIDL_DEFINE_GUID(IID, IID_IWebBrowserEvents,0xF010AA89,0x5CF5,0x4bce,0xBA,0xBE,0x5A,0xDA,0xE3,0xD3,0x00,0xEB);


MIDL_DEFINE_GUID(IID, IID_IXmoe,0x710B3B21,0x654C,0x4c07,0xA0,0x62,0xB7,0x28,0x71,0x32,0xF9,0x7D);


MIDL_DEFINE_GUID(IID, IID_IDoc,0x25867097,0xB5C3,0x4d5e,0x99,0x9F,0x41,0x7F,0xCB,0xAE,0x21,0x8C);


MIDL_DEFINE_GUID(IID, IID_IDocs,0x609BCD33,0xCDEC,0x416d,0x9B,0xBD,0xF5,0x51,0xD4,0x52,0x61,0x4D);


MIDL_DEFINE_GUID(IID, IID_IMoeFrame,0xBF8832A5,0xAE58,0x4c26,0xBB,0xC4,0xCE,0xCC,0xF9,0x10,0x14,0x9C);


MIDL_DEFINE_GUID(IID, IID_IExternalMoe,0x5AA6374E,0x4995,0x4f49,0xAF,0x45,0x6A,0x04,0x76,0x54,0xCD,0xD2);


MIDL_DEFINE_GUID(IID, DIID__IXmoeEvents,0xABE0076F,0x2A48,0x448f,0x97,0x16,0x7E,0xF6,0x55,0x0F,0x3A,0xB0);


MIDL_DEFINE_GUID(CLSID, CLSID_Xmoe,0x6282C9F1,0xF8B8,0x446b,0x9F,0x98,0x1D,0x4B,0x70,0x43,0xBB,0x9C);


MIDL_DEFINE_GUID(CLSID, CLSID_Docs,0x3BD5BD2B,0xA9BF,0x4cf0,0x88,0x35,0xEA,0x64,0x62,0xA0,0x58,0xCF);


MIDL_DEFINE_GUID(CLSID, CLSID_Doc,0xD3F8CB44,0x2FBC,0x4488,0xA4,0xF0,0x37,0x80,0x56,0xD1,0xFB,0xF9);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



