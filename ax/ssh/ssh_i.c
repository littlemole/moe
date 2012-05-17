

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Thu May 17 14:14:47 2012
 */
/* Compiler settings for ssh.idl:
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

MIDL_DEFINE_GUID(IID, LIBID_moeSSH,0xB9AA71CC,0xED9E,0x47AB,0x90,0xB9,0x4B,0x84,0xEA,0xA3,0xF4,0xB2);


MIDL_DEFINE_GUID(IID, IID_IScpDataTransferObjectFactory,0xBC65ED29,0x6378,0x4C70,0x8E,0xED,0xCF,0xCE,0xD2,0x81,0x56,0xEF);


MIDL_DEFINE_GUID(IID, IID_IRemoteFile,0x0CAF3661,0x4063,0x416D,0x85,0x48,0xD4,0x21,0x44,0xC6,0x52,0xD3);


MIDL_DEFINE_GUID(IID, IID_ISFTP,0x277DC7E4,0x6329,0x4D3B,0x9E,0xE3,0x2B,0x19,0x8A,0x6C,0x8A,0x07);


MIDL_DEFINE_GUID(IID, IID_ISCP,0x873F0BE6,0x8E22,0x472A,0xB0,0x71,0xAC,0x1E,0xA3,0x85,0x42,0x78);


MIDL_DEFINE_GUID(IID, IID_ISSHConnection,0x5DDB7A6C,0x4283,0x4A1D,0xA1,0x5D,0xFB,0x76,0x1D,0xD1,0x34,0x0B);


MIDL_DEFINE_GUID(IID, IID_ISSH,0xA03D1837,0xB2B1,0x486B,0x9A,0x42,0x24,0xD1,0x45,0x71,0xFC,0xF6);


MIDL_DEFINE_GUID(CLSID, CLSID_SSH,0x001C9766,0x9D66,0x4554,0xAC,0x40,0x15,0xF3,0xB0,0x51,0xDE,0x29);


MIDL_DEFINE_GUID(CLSID, CLSID_ScpDataTransferObjectFactory,0x359A4EC7,0x7D01,0x4764,0xAD,0x51,0x60,0x6A,0xF6,0xAC,0x29,0x43);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



