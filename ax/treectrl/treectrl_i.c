

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.00.0595 */
/* at Sat Feb 23 19:54:51 2013
 */
/* Compiler settings for treectrl.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.00.0595 
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

MIDL_DEFINE_GUID(IID, LIBID_TreeCtrl,0xB260A11D,0xA05C,0x4B63,0x8D,0x53,0xAB,0xA9,0xFA,0xB7,0x4B,0x29);


MIDL_DEFINE_GUID(IID, IID_ITreeElement,0x5295C21C,0x760F,0x4EB9,0xAA,0x4C,0x29,0xED,0x6E,0xA7,0x10,0xC9);


MIDL_DEFINE_GUID(IID, IID_ITreeCtrl,0x43D7B7ED,0x68B6,0x402E,0xB7,0x03,0xF6,0x69,0x9C,0x05,0x9C,0x73);


MIDL_DEFINE_GUID(IID, DIID__ITreeCtrlEvents,0xF27F6A86,0x58C6,0x40FD,0xAE,0xE3,0xE7,0xFB,0x9F,0x0B,0xB3,0x7B);


MIDL_DEFINE_GUID(IID, IID_ITreeCtrlEvents,0x7216C1FA,0x5960,0x4F88,0x86,0xEF,0x16,0x8D,0xD8,0x3A,0xCF,0xAB);


MIDL_DEFINE_GUID(CLSID, CLSID_TreeControl,0x876266EE,0xAE01,0x402B,0x84,0x5F,0x58,0x52,0xE7,0xCB,0x32,0xEA);


MIDL_DEFINE_GUID(CLSID, CLSID_TreeElement,0x29737AFE,0x9748,0x4762,0xB6,0x61,0x49,0xF1,0x57,0xC1,0x60,0x85);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



