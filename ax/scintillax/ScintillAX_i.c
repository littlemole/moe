

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Tue Oct 12 22:12:41 2010
 */
/* Compiler settings for .\ScintillAX.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
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

MIDL_DEFINE_GUID(IID, LIBID_Scintilla,0xB353B863,0x12C3,0x45ab,0x82,0xFE,0x2F,0x8F,0x9B,0xAA,0x91,0xD6);


MIDL_DEFINE_GUID(IID, IID_IScintillAx,0x1120EC6A,0x130F,0x440e,0x9B,0x1D,0xF0,0x2D,0x50,0x5F,0xB5,0xBC);


MIDL_DEFINE_GUID(IID, DIID__IScintillAxEvents,0x2D33B016,0x176A,0x40fe,0xB6,0x65,0xB1,0x14,0xA6,0x51,0x1A,0xC8);


MIDL_DEFINE_GUID(IID, IID_IScintillAxEvents,0xE3766918,0xA0A4,0x48b7,0x94,0x2A,0xBA,0x4B,0x4D,0x52,0x4C,0xD0);


MIDL_DEFINE_GUID(CLSID, CLSID_ScintillAx,0x9B5488B0,0x33FB,0x44df,0x8D,0x58,0x67,0x2A,0x1C,0x1E,0x08,0xC1);


MIDL_DEFINE_GUID(CLSID, CLSID_ScintillAxProperties,0xC16CD143,0x5126,0x414a,0xAF,0xDE,0x40,0x6F,0x31,0xE9,0x5D,0x13);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



