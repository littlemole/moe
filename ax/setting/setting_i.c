

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Fri Jul 20 19:47:44 2012
 */
/* Compiler settings for setting.idl:
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

MIDL_DEFINE_GUID(IID, LIBID_Settings,0x225F997F,0xE7F5,0x422c,0x9D,0x41,0xDF,0xC9,0x5A,0x59,0xB6,0x0A);


MIDL_DEFINE_GUID(IID, IID_ISetting,0x2DD18900,0x95F3,0x46a8,0x98,0xB8,0x03,0xF3,0x84,0x3D,0xE6,0x35);


MIDL_DEFINE_GUID(IID, DIID__ISettingChanged,0x05CE8141,0xF38B,0x4c50,0xAC,0x21,0x93,0x1F,0x4D,0x07,0xA6,0xA0);


MIDL_DEFINE_GUID(IID, IID__ISettingChangedDual,0x0DB8CB91,0xF13F,0x4374,0xBD,0xD8,0xFD,0xEE,0xED,0x42,0x10,0xF6);


MIDL_DEFINE_GUID(CLSID, CLSID_Setting,0xAE500EE9,0x731F,0x47a8,0x8D,0x11,0x63,0x4E,0xF4,0x22,0xA3,0x96);


MIDL_DEFINE_GUID(CLSID, CLSID_SettingProperties,0x5754B136,0xD3FB,0x4232,0xB9,0x4A,0x92,0xB4,0x4B,0xE0,0x66,0xE9);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



