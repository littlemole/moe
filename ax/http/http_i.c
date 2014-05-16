

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Tue Apr 29 18:27:46 2014
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

MIDL_DEFINE_GUID(IID, LIBID_HTTP,0xCDCBD74D,0xE200,0x41E1,0xBD,0xA5,0x95,0x37,0x12,0x7F,0x6F,0x37);


MIDL_DEFINE_GUID(IID, IID_IHttp,0x65ECE645,0x63A0,0x422B,0x95,0x51,0x30,0xBA,0xBE,0x5C,0x0D,0x46);


MIDL_DEFINE_GUID(IID, IID_IHttpHeaders,0xE4371FB6,0x0126,0x41D1,0x8E,0x37,0xB7,0x17,0x15,0xC0,0x71,0x04);


MIDL_DEFINE_GUID(IID, IID_IHttpRequest,0x1800C704,0x0169,0x4C4A,0x96,0xBC,0xEA,0xBE,0xB2,0xDD,0x46,0x06);


MIDL_DEFINE_GUID(IID, IID_IHttpResponse,0x39171BA0,0xB240,0x428A,0x87,0xA6,0x6C,0x2D,0xC9,0x25,0xA2,0xB4);


MIDL_DEFINE_GUID(IID, IID_IHttpHeader,0x0770FB34,0x58D4,0x4417,0xB4,0x7E,0xB0,0x7D,0x2C,0xA6,0x04,0xB9);


MIDL_DEFINE_GUID(CLSID, CLSID_Client,0xE39732D8,0x7B64,0x4DC3,0x99,0x24,0x9F,0x21,0x63,0x45,0xF0,0x7A);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



