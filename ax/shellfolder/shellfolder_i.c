

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Sun Jan 02 18:33:25 2011
 */
/* Compiler settings for shellfolder.idl:
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

MIDL_DEFINE_GUID(IID, LIBID_ShellFolder,0xAD81C1CC,0xB3F3,0x47e8,0xBB,0x69,0x31,0x91,0x26,0x16,0xA3,0x9F);


MIDL_DEFINE_GUID(IID, IID_IShellPane,0x8E03AB4B,0xE12B,0x42a2,0x90,0x5D,0xF1,0x06,0x85,0x4C,0x71,0x53);


MIDL_DEFINE_GUID(IID, DIID__IShellPaneEvents,0x8B2BD8F4,0x8788,0x4968,0xAB,0x28,0xC4,0x09,0xFF,0x1A,0x88,0xCF);


MIDL_DEFINE_GUID(IID, IID_IShellPaneEvents,0x3B3FF6F3,0xD0DB,0x4ada,0xA5,0x93,0xD9,0x9E,0x6F,0x79,0xE6,0xD1);


MIDL_DEFINE_GUID(CLSID, CLSID_ShellPane,0x3609D58F,0x1D8E,0x437d,0xBA,0x8A,0x11,0xA5,0xDB,0xF5,0x9B,0xAD);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



