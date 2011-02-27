

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Sun Feb 27 19:49:28 2011
 */
/* Compiler settings for jre.idl:
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

MIDL_DEFINE_GUID(IID, LIBID_JRE,0x0E681FCF,0x0286,0x4e02,0xB9,0x5E,0x9A,0x41,0xBE,0x38,0x4F,0xE7);


MIDL_DEFINE_GUID(IID, IID_IJVM,0x5607D481,0x5580,0x4eb7,0x8E,0xCD,0x88,0x05,0x84,0x6D,0x8C,0x86);


MIDL_DEFINE_GUID(CLSID, CLSID_Java,0xB3ED4D8C,0x7FDD,0x4177,0xBF,0x47,0x36,0x80,0xA8,0xE2,0x25,0xBC);


MIDL_DEFINE_GUID(CLSID, CLSID_JavaClass,0x4CCBBB37,0xA5F2,0x47A3,0xB6,0x7B,0x53,0xAE,0x71,0x1D,0xEF,0xCA);


MIDL_DEFINE_GUID(CLSID, CLSID_JavaObject,0xC22704EA,0x3233,0x42BC,0xAA,0x5D,0x56,0x54,0x3D,0x01,0xAA,0x82);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



