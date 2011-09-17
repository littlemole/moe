

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Sat Sep 17 13:31:37 2011
 */
/* Compiler settings for shellCtrl.idl:
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

MIDL_DEFINE_GUID(IID, LIBID_ShellCtrls,0x74618F47,0x2F2A,0x4b0f,0xBD,0xCA,0x34,0x4B,0xE3,0x20,0x8E,0xCE);


MIDL_DEFINE_GUID(IID, IID_IShellTree,0x67282F00,0x10CA,0x4540,0x92,0xB1,0x37,0xDF,0x10,0xA3,0xCD,0x7B);


MIDL_DEFINE_GUID(IID, IID_IHexCtrl,0x3F6F041B,0x6B7A,0x4465,0x95,0x42,0x46,0x52,0x52,0x8C,0x3F,0xB7);


MIDL_DEFINE_GUID(IID, IID_IShellList,0x9C93223B,0xE503,0x415a,0x81,0x1A,0xB8,0x17,0xD7,0xB1,0xBC,0x43);


MIDL_DEFINE_GUID(IID, IID_IColorPicker,0x60B3F5EC,0x7FC7,0x417a,0x9D,0x90,0xF2,0x1C,0x78,0xB3,0xFC,0x05);


MIDL_DEFINE_GUID(IID, DIID__IShellTreeEvents,0x642D2ED7,0x975F,0x4699,0xB7,0xC9,0xD9,0x5A,0xAB,0x97,0xF8,0x26);


MIDL_DEFINE_GUID(IID, DIID__IHexCtrlEvents,0xAAB8E8A1,0xA963,0x4345,0xAC,0xA6,0x38,0xDC,0x7C,0xF0,0x1A,0x78);


MIDL_DEFINE_GUID(IID, DIID__IShellListEvents,0x24165625,0xBBB8,0x404a,0xB2,0xBC,0x62,0xB9,0xF4,0x0F,0xE7,0xDD);


MIDL_DEFINE_GUID(IID, IID_IShellTreeEvents,0xD975C13F,0x537C,0x4065,0xA2,0x7A,0xD2,0x5A,0x27,0x1A,0x7A,0x6E);


MIDL_DEFINE_GUID(IID, IID_IShellListEvents,0x2ED442CD,0xE289,0x46c3,0xAB,0x7B,0x8D,0xE1,0xCE,0xF8,0x9D,0xB4);


MIDL_DEFINE_GUID(IID, IID_IHexCtrlEvents,0x2031340D,0xA1E9,0x4fcf,0x87,0x74,0xB9,0x4A,0x56,0x5D,0x62,0x25);


MIDL_DEFINE_GUID(CLSID, CLSID_ShellTree,0x22C25563,0xE185,0x4753,0x82,0x99,0x19,0x98,0xCD,0x73,0xD3,0x89);


MIDL_DEFINE_GUID(CLSID, CLSID_ShellList,0x8E6A9C86,0x2FA6,0x4d02,0xB9,0xBE,0x72,0x32,0x6A,0x7F,0x6C,0x9D);


MIDL_DEFINE_GUID(CLSID, CLSID_ColorDialog,0xADF80C5A,0x78DE,0x4317,0xBF,0x08,0x4C,0xE3,0x17,0x6D,0x34,0x22);


MIDL_DEFINE_GUID(CLSID, CLSID_HexCtrl,0xE83EC0F6,0x6AF3,0x44f8,0x90,0x1E,0xAF,0x01,0xF8,0x4F,0xE6,0xD0);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



