// Created by Microsoft (R) C/C++ Compiler Version 14.00.50727.762 (3af16e97).
//
// c:\dokumente und einstellungen\mike\eigene dateien\visual studio 2005\projects\types\types\debug\jit.tlh
//
// C++ source equivalent of Win32 type library C:\Dokumente und Einstellungen\mike\Eigene Dateien\Visual Studio 2005\Projects\types\Jit.tlb
// compiler-generated file created 05/28/07 at 16:20:08 - DO NOT EDIT!

#pragma once
#pragma pack(push, 8)

//#include <comdef.h>

//
// Forward references and typedefs
//

struct __declspec(uuid("a348a947-3a18-4cf3-9cdb-2901c69393d1"))
/* LIBID */ __JIT;
struct __declspec(uuid("b237a73f-7e03-402b-a4b0-5abe252ea4f8"))
/* dual interface */ ICompiler;
struct __declspec(uuid("aad393b7-f8e1-4e25-88fa-317e0e4759eb"))
/* dispinterface */ ICompilerMsg;
struct __declspec(uuid("8a5a643a-edcc-4501-8aed-3a38aa9ad19c"))
/* dual interface */ ICompilerDualMsg;
struct /* coclass */ CompilerErrorMsgDelegate;
struct /* coclass */ CompilerSuccessMsgDelegate;
struct /* coclass */ JIT;
struct __declspec(uuid("b5c98b0b-1955-31d0-8d00-c72ce4e2152a"))
/* dual interface */ _CompilerErrorMsgDelegate;
struct __declspec(uuid("c61dd7fa-f92e-3c31-8d69-8bc3a31b2e9b"))
/* dual interface */ _CompilerSuccessMsgDelegate;

//
// Type library items
//

struct __declspec(uuid("b237a73f-7e03-402b-a4b0-5abe252ea4f8"))
ICompiler : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall AddObject (
        /*[in]*/ BSTR name,
        /*[in]*/ VARIANT o ) = 0;
      virtual HRESULT __stdcall ClearObjects ( ) = 0;
      virtual HRESULT __stdcall AddSourceText (
        /*[in]*/ BSTR src ) = 0;
      virtual HRESULT __stdcall AddSourceFile (
        /*[in]*/ BSTR src ) = 0;
      virtual HRESULT __stdcall ClearSources ( ) = 0;
      virtual HRESULT __stdcall AddReference (
        /*[in]*/ BSTR r ) = 0;
      virtual HRESULT __stdcall ClearReferences ( ) = 0;
      virtual HRESULT __stdcall AddDirectory (
        /*[in]*/ BSTR d ) = 0;
      virtual HRESULT __stdcall ClearDirectories ( ) = 0;
      virtual HRESULT __stdcall get_AssemblyName (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall put_AssemblyName (
        /*[in]*/ BSTR pRetVal ) = 0;
      virtual HRESULT __stdcall get_GenerateExecutable (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall put_GenerateExecutable (
        /*[in]*/ VARIANT_BOOL pRetVal ) = 0;
      virtual HRESULT __stdcall get_Win32Target (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall put_Win32Target (
        /*[in]*/ VARIANT_BOOL pRetVal ) = 0;
      virtual HRESULT __stdcall get_Optimize (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall put_Optimize (
        /*[in]*/ VARIANT_BOOL pRetVal ) = 0;
      virtual HRESULT __stdcall get_DebugInfo (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall put_DebugInfo (
        /*[in]*/ VARIANT_BOOL pRetVal ) = 0;
      virtual HRESULT __stdcall get_Options (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall put_Options (
        /*[in]*/ BSTR pRetVal ) = 0;
      virtual HRESULT __stdcall Start ( ) = 0;
      virtual HRESULT __stdcall Compile ( ) = 0;
      virtual HRESULT __stdcall Exec ( ) = 0;
      virtual HRESULT __stdcall CompileExec ( ) = 0;
      virtual HRESULT __stdcall Run ( ) = 0;
      virtual HRESULT __stdcall Unload (
        /*[in]*/ VARIANT_BOOL clear ) = 0;
      virtual HRESULT __stdcall Reset ( ) = 0;
};

struct __declspec(uuid("aad393b7-f8e1-4e25-88fa-317e0e4759eb"))
ICompilerMsg : IDispatch
{};

struct __declspec(uuid("8a5a643a-edcc-4501-8aed-3a38aa9ad19c"))
ICompilerDualMsg : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall ErrorMsg (
        /*[in]*/ BSTR errors ) = 0;
      virtual HRESULT __stdcall Success ( ) = 0;
};

struct __declspec(uuid("dd0e7455-efc8-30d9-b8ff-23fb1d83ac42"))
CompilerErrorMsgDelegate;
    // [ default ] interface _CompilerErrorMsgDelegate
    // interface _Delegate
    // interface _Object
    // interface ICloneable
    // interface ISerializable

struct __declspec(uuid("980553ee-ea78-3bda-8141-fe6c9c4bf8d6"))
CompilerSuccessMsgDelegate;
    // [ default ] interface _CompilerSuccessMsgDelegate
    // interface _Delegate
    // interface _Object
    // interface ICloneable
    // interface ISerializable

struct __declspec(uuid("08452484-22aa-4429-b2d0-b5370712dd39"))
JIT;
    // interface _Object
    // [ default ] interface ICompiler
    // [ default, source ] dispinterface ICompilerMsg

struct __declspec(uuid("b5c98b0b-1955-31d0-8d00-c72ce4e2152a"))
_CompilerErrorMsgDelegate : IDispatch
{};

struct __declspec(uuid("c61dd7fa-f92e-3c31-8d69-8bc3a31b2e9b"))
_CompilerSuccessMsgDelegate : IDispatch
{};

//
// Named GUID constants initializations
//

extern "C" const GUID __declspec(selectany) LIBID_JIT =
    {0xa348a947,0x3a18,0x4cf3,{0x9c,0xdb,0x29,0x01,0xc6,0x93,0x93,0xd1}};
extern "C" const GUID __declspec(selectany) IID_ICompiler =
    {0xb237a73f,0x7e03,0x402b,{0xa4,0xb0,0x5a,0xbe,0x25,0x2e,0xa4,0xf8}};
extern "C" const GUID __declspec(selectany) DIID_ICompilerMsg =
    {0xaad393b7,0xf8e1,0x4e25,{0x88,0xfa,0x31,0x7e,0x0e,0x47,0x59,0xeb}};
extern "C" const GUID __declspec(selectany) IID_ICompilerDualMsg =
    {0x8a5a643a,0xedcc,0x4501,{0x8a,0xed,0x3a,0x38,0xaa,0x9a,0xd1,0x9c}};
extern "C" const GUID __declspec(selectany) CLSID_CompilerErrorMsgDelegate =
    {0xdd0e7455,0xefc8,0x30d9,{0xb8,0xff,0x23,0xfb,0x1d,0x83,0xac,0x42}};
extern "C" const GUID __declspec(selectany) CLSID_CompilerSuccessMsgDelegate =
    {0x980553ee,0xea78,0x3bda,{0x81,0x41,0xfe,0x6c,0x9c,0x4b,0xf8,0xd6}};
extern "C" const GUID __declspec(selectany) CLSID_JIT =
    {0x08452484,0x22aa,0x4429,{0xb2,0xd0,0xb5,0x37,0x07,0x12,0xdd,0x39}};
extern "C" const GUID __declspec(selectany) IID__CompilerErrorMsgDelegate =
    {0xb5c98b0b,0x1955,0x31d0,{0x8d,0x00,0xc7,0x2c,0xe4,0xe2,0x15,0x2a}};
extern "C" const GUID __declspec(selectany) IID__CompilerSuccessMsgDelegate =
    {0xc61dd7fa,0xf92e,0x3c31,{0x8d,0x69,0x8b,0xc3,0xa3,0x1b,0x2e,0x9b}};

#pragma pack(pop)
