

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu May 29 00:05:51 2008
 */
/* Compiler settings for .\sql.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

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

MIDL_DEFINE_GUID(IID, LIBID_molSQL,0xD47CDF3B,0x33FC,0x4b51,0xBC,0x2D,0x4B,0xEB,0x2C,0x84,0x4F,0xD3);


MIDL_DEFINE_GUID(IID, IID_IMyRow,0x74C10BEE,0xEC77,0x49eb,0xA1,0x35,0x5A,0xEE,0x20,0x56,0xBC,0x93);


MIDL_DEFINE_GUID(IID, IID_IMyResult,0x786ECCBD,0xA692,0x4d4c,0x80,0x9B,0xEA,0x0A,0x52,0xD9,0x28,0xF8);


MIDL_DEFINE_GUID(IID, IID_IMyStatement,0xFF9E817F,0x3BD4,0x4db2,0x84,0x36,0x05,0x10,0xE7,0x3B,0xF8,0x17);


MIDL_DEFINE_GUID(IID, IID_IMySQL,0x9B225E2F,0x7D8F,0x4c30,0x93,0xC0,0xE2,0xE9,0x9C,0xDA,0xB6,0xCC);


MIDL_DEFINE_GUID(CLSID, CLSID_MySQL,0xCBAE9604,0x386B,0x4db1,0x89,0x20,0x3E,0x9E,0x59,0xCF,0x72,0x22);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



