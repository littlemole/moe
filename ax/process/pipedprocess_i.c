

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Wed Jun 20 21:20:24 2012
 */
/* Compiler settings for process.idl:
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

MIDL_DEFINE_GUID(IID, LIBID_PipedProcess,0x9E61E3FC,0xFC64,0x4164,0xA9,0xAC,0xBD,0xED,0xC3,0x11,0x6B,0xA7);


MIDL_DEFINE_GUID(IID, IID_IPipedProcess,0x263ABFD3,0x6D9F,0x4c0b,0x86,0x1A,0x4D,0x22,0xE0,0xAA,0x95,0x29);


MIDL_DEFINE_GUID(IID, DIID__IPipedProcessComplete,0x2CA957E0,0x4A1D,0x4e57,0xAA,0x42,0x94,0xE9,0xB0,0x70,0x1B,0x26);


MIDL_DEFINE_GUID(IID, IID_IPipedProcessCompleteDual,0x7FBB9268,0x45D9,0x43df,0xBE,0x32,0xA5,0xFF,0xED,0x60,0xB4,0x56);


MIDL_DEFINE_GUID(CLSID, CLSID_PipedProcessControl,0x3E08871B,0x09B9,0x4e04,0xB9,0xF7,0x64,0xD2,0xF9,0xF4,0xE8,0x54);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



