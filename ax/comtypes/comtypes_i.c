

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Tue Dec 13 21:53:15 2011
 */
/* Compiler settings for comtypes.idl:
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

MIDL_DEFINE_GUID(IID, LIBID_TypeToXml,0x3ECB75B2,0xE572,0x47a9,0x86,0x18,0xFE,0xE2,0x6C,0x64,0xCC,0xB5);


MIDL_DEFINE_GUID(IID, IID_ITypeLibToXml,0x2D9ABF3A,0x0013,0x4761,0x9F,0x9F,0x9A,0xFA,0x71,0xAF,0x12,0x3C);


MIDL_DEFINE_GUID(IID, DIID__IAsyncDocumentationComplete,0x7CC8CCB0,0xE258,0x4116,0x9E,0x0A,0xD7,0x28,0x73,0xC7,0x16,0x9B);


MIDL_DEFINE_GUID(CLSID, CLSID_TypeLibToXml,0x9BFB3F1F,0xE302,0x4637,0x84,0x95,0x7F,0x7F,0xDD,0x29,0xB5,0x7C);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



