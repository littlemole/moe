

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Sat Mar 19 13:24:43 2011
 */
/* Compiler settings for src\moe.idl:
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


MIDL_DEFINE_GUID(IID, IID_IMoe,0x8C2C5817,0x4747,0x4da4,0xB5,0x88,0x75,0x61,0x2B,0x76,0x08,0xA2);


MIDL_DEFINE_GUID(IID, IID_IMoeView,0xE6F7C726,0x4A4A,0x487f,0x8D,0xEA,0x08,0x54,0x22,0x9C,0x1B,0xCB);


MIDL_DEFINE_GUID(IID, IID_IMoeScript,0x809CE6F6,0xC2DE,0x4d8b,0xA7,0xF2,0xC2,0xFF,0xD5,0x81,0xE4,0x9C);


MIDL_DEFINE_GUID(IID, IID_IMoeConfig,0x4DE6729C,0x2F79,0x471f,0x82,0xCB,0x51,0x13,0x7A,0x02,0xE4,0x90);


MIDL_DEFINE_GUID(IID, IID_IMoeDialogs,0xC82F0BDB,0x5835,0x44b4,0xB7,0x08,0x5C,0x07,0x7C,0x2D,0x3C,0xF7);


MIDL_DEFINE_GUID(IID, IID_IMoeDocumentCollection,0xB2FC978E,0x28F5,0x49e0,0xB3,0x63,0x8C,0x78,0xDE,0x7F,0xC5,0x0F);


MIDL_DEFINE_GUID(IID, IID_IMoeDocument,0xF1D065C3,0xDE27,0x45c7,0xA6,0x84,0xC0,0xEE,0xCF,0x43,0xAF,0x3E);


MIDL_DEFINE_GUID(IID, IID_IMoeDocumentView,0x9ADC66FD,0x13AB,0x4b52,0xA9,0x2B,0x51,0x55,0xEA,0x1E,0xF8,0x3C);


MIDL_DEFINE_GUID(IID, IID_IMoeHtmlFrame,0x08B6F80E,0x72E9,0x4a97,0x86,0x72,0x92,0x6F,0x8D,0x7B,0xEE,0xC0);


MIDL_DEFINE_GUID(IID, IID_IMoeDialogView,0x54E27AFE,0x3872,0x481c,0x96,0x8F,0x20,0xBF,0x61,0xB1,0x94,0x96);


MIDL_DEFINE_GUID(IID, IID_IMoeUserForm,0x0DFFAACE,0x906D,0x4545,0x85,0x3A,0xBE,0xE5,0x93,0x28,0x3B,0xDB);


MIDL_DEFINE_GUID(IID, IID_IExternalMoe,0xFC03A505,0xB887,0x4653,0x87,0x10,0xB0,0xAB,0x66,0x67,0x4F,0x96);


MIDL_DEFINE_GUID(CLSID, CLSID_Application,0xFABA1705,0x8E2D,0x48d2,0xAE,0x3C,0x33,0x3F,0xEE,0xCA,0x3F,0xBC);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



