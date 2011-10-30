

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Sun Oct 30 16:03:13 2011
 */
/* Compiler settings for ScintillAX.idl:
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

MIDL_DEFINE_GUID(IID, IID_IScintillAxDispose,0x87084618,0x4FF1,0x4AF1,0x90,0x98,0x7D,0x67,0x9C,0x6C,0x0B,0x86);


MIDL_DEFINE_GUID(IID, LIBID_Scintilla,0xB353B863,0x12C3,0x45ab,0x82,0xFE,0x2F,0x8F,0x9B,0xAA,0x91,0xD6);


MIDL_DEFINE_GUID(IID, IID_IScintillAxProperties,0x65BC59C3,0x3E46,0x4F80,0x8B,0x4A,0x13,0xAA,0xDF,0x1A,0x58,0xEB);


MIDL_DEFINE_GUID(IID, IID_IScintillAxText,0xA479AEBD,0xED80,0x4451,0x8C,0x83,0x8E,0x42,0x2E,0xBC,0x20,0xA1);


MIDL_DEFINE_GUID(IID, IID_IScintillAxPosition,0xAE7C2E4D,0x1AD1,0x48E8,0xA3,0x76,0x6C,0x6D,0xA2,0x67,0x07,0xE8);


MIDL_DEFINE_GUID(IID, IID_IScintillAxSelection,0x76D700E6,0xD9F1,0x4D92,0xAE,0xEF,0x65,0x87,0x73,0x83,0x42,0x26);


MIDL_DEFINE_GUID(IID, IID_IScintillAxLine,0xB22C83F1,0x785D,0x4007,0xBE,0x8D,0xDA,0x5C,0xE3,0x33,0xD9,0xD4);


MIDL_DEFINE_GUID(IID, IID_IScintillAxAnnotation,0xD0799D5B,0xE2EC,0x4877,0x99,0xA3,0x03,0xAD,0xD1,0x89,0x5B,0x17);


MIDL_DEFINE_GUID(IID, IID_IScintillAxMarkers,0x6F7991E0,0x0762,0x452C,0xA6,0xD4,0x64,0x98,0x47,0xD1,0x36,0xDC);


MIDL_DEFINE_GUID(IID, IID_IScintillAx,0x1120EC6A,0x130F,0x440e,0x9B,0x1D,0xF0,0x2D,0x50,0x5F,0xB5,0xBC);


MIDL_DEFINE_GUID(IID, DIID__IScintillAxEvents,0x2D33B016,0x176A,0x40fe,0xB6,0x65,0xB1,0x14,0xA6,0x51,0x1A,0xC8);


MIDL_DEFINE_GUID(IID, IID_IScintillAxEvents,0xE3766918,0xA0A4,0x48b7,0x94,0x2A,0xBA,0x4B,0x4D,0x52,0x4C,0xD0);


MIDL_DEFINE_GUID(CLSID, CLSID_ScintillAx,0x9B5488B0,0x33FB,0x44df,0x8D,0x58,0x67,0x2A,0x1C,0x1E,0x08,0xC1);


MIDL_DEFINE_GUID(CLSID, CLSID_ScintillAxProperties,0xC16CD143,0x5126,0x414a,0xAF,0xDE,0x40,0x6F,0x31,0xE9,0x5D,0x13);


MIDL_DEFINE_GUID(CLSID, CLSID_ScintillAxSettings,0x3039CC18,0x067B,0x450F,0x95,0x2D,0x7C,0xE2,0xAD,0xD7,0x9F,0x88);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



