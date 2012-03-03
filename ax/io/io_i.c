

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Sat Mar 03 12:13:40 2012
 */
/* Compiler settings for io.idl:
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

MIDL_DEFINE_GUID(IID, LIBID_IO,0xF1D70022,0x14DA,0x4344,0x9A,0x66,0xAE,0x78,0xDB,0xF2,0x1A,0xBF);


MIDL_DEFINE_GUID(IID, IID_IFile,0x5AF00596,0x158A,0x4ddd,0xBC,0x20,0x83,0xBC,0x8D,0x5E,0x43,0x2F);


MIDL_DEFINE_GUID(IID, IID_IDir,0x92AF3107,0x79EB,0x480f,0xA1,0x18,0x6A,0x3F,0xF4,0x1E,0x50,0x85);


MIDL_DEFINE_GUID(IID, IID_IPath,0xFFEB4898,0x0ECC,0x465a,0x85,0x1E,0xF5,0xF7,0xBB,0x41,0x36,0xA8);


MIDL_DEFINE_GUID(CLSID, CLSID_Path,0x44DC1E37,0xCB3D,0x4328,0xB1,0x54,0xE5,0x02,0x50,0xF0,0x7A,0x8F);


MIDL_DEFINE_GUID(CLSID, CLSID_File,0xC4E08E9A,0x0B46,0x4fd4,0xBB,0x8D,0x58,0x8A,0xBC,0x27,0xF5,0x2E);


MIDL_DEFINE_GUID(CLSID, CLSID_Dir,0x302B0FE6,0xEE9A,0x4303,0x92,0xB9,0xE6,0xB6,0x9B,0x57,0x33,0x18);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



