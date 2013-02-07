

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Thu Feb 07 20:54:29 2013
 */
/* Compiler settings for net.idl:
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

MIDL_DEFINE_GUID(IID, LIBID_NET,0xFE071973,0xA01C,0x405A,0xB9,0xD0,0x8D,0xFF,0x50,0xF6,0x32,0x0E);


MIDL_DEFINE_GUID(IID, IID_INetObject,0x48CB943A,0x4675,0x4AAD,0x95,0x38,0x2C,0x32,0x7B,0x38,0x16,0xB2);


MIDL_DEFINE_GUID(IID, IID_INetType,0xA203B3FE,0xBEF5,0x4746,0xAE,0xE9,0xF1,0x98,0xC9,0xF6,0x24,0xA8);


MIDL_DEFINE_GUID(IID, IID_INetAssembly,0xE42528B2,0x547D,0x4427,0xA4,0x0A,0x47,0xC4,0x62,0x19,0xA6,0x26);


MIDL_DEFINE_GUID(IID, IID_INet,0xA0E5BB3E,0x03DD,0x4BE1,0xA8,0x24,0x28,0x76,0xBA,0xEF,0xDF,0x8D);


MIDL_DEFINE_GUID(CLSID, CLSID_DotNet,0x75B8C10C,0x696C,0x44E1,0xA0,0x39,0xA1,0x33,0x1E,0x9D,0x5E,0x61);


MIDL_DEFINE_GUID(CLSID, CLSID_DotNetType,0x542A2776,0x13B2,0x4689,0xA8,0xDA,0xA4,0xAB,0x82,0xBF,0x41,0x54);


MIDL_DEFINE_GUID(CLSID, CLSID_DotNetObject,0x68B74204,0xA3CD,0x47B4,0x97,0x41,0x17,0x6E,0x74,0x19,0x90,0x90);


MIDL_DEFINE_GUID(CLSID, CLSID_DotNetAssembly,0x331790F2,0x442D,0x4CC3,0xA1,0x71,0xD3,0x75,0xD2,0xDF,0xB1,0x33);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



