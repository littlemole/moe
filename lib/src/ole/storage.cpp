#include "ole/storage.h"


namespace mol {
namespace ole {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// some dummy ole impls
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// dummy, dummy , dummy

DummyStorage::~DummyStorage()
{}

HRESULT __stdcall  DummyStorage::QueryInterface( REFIID riid, LPVOID FAR* ppvObj)
{
    return E_NOTIMPL ;
}
ULONG __stdcall  DummyStorage::AddRef()
{
    return 1;
}
ULONG __stdcall  DummyStorage::Release()
{
    return 2;
}
HRESULT __stdcall  StorageBase::CreateStream( const WCHAR *pwcsName, DWORD grfMode, DWORD reserved1, DWORD reserved2, IStream **ppstm)
{
    return E_NOTIMPL ;
}
HRESULT __stdcall  StorageBase::OpenStream( const WCHAR * pwcsName, void *reserved1, DWORD grfMode, DWORD reserved2, IStream **ppstm)
{
    return E_NOTIMPL ;
}
HRESULT __stdcall  StorageBase::CreateStorage( const WCHAR *pwcsName, DWORD grfMode, DWORD reserved1, DWORD reserved2, IStorage **ppstg)
{
    return E_NOTIMPL ;
}
HRESULT __stdcall  StorageBase::OpenStorage( const WCHAR * pwcsName, IStorage * pstgPriority, DWORD grfMode, SNB snbExclude, DWORD reserved, IStorage **ppstg)
{
    return E_NOTIMPL ;
}
HRESULT __stdcall  StorageBase::CopyTo( DWORD ciidExclude, IID const *rgiidExclude, SNB snbExclude,IStorage *pstgDest)
{
    return E_NOTIMPL ;
}
HRESULT __stdcall  StorageBase::MoveElementTo( const OLECHAR *pwcsName,IStorage * pstgDest, const OLECHAR *pwcsNewName, DWORD grfFlags)
{
    return E_NOTIMPL ;
}
HRESULT __stdcall  StorageBase::Commit( DWORD grfCommitFlags)
{
    return E_NOTIMPL ;
}
HRESULT __stdcall  StorageBase::Revert()
{
    return E_NOTIMPL ;
}
HRESULT __stdcall  StorageBase::EnumElements(DWORD reserved1, void * reserved2, DWORD reserved3, IEnumSTATSTG ** ppenum)
{
    return E_NOTIMPL ;
}
HRESULT __stdcall  StorageBase::DestroyElement( const OLECHAR *pwcsName)
{
    return E_NOTIMPL ;
}
HRESULT  __stdcall StorageBase::RenameElement( const WCHAR *pwcsOldName, const WCHAR *pwcsNewName)
{
    return E_NOTIMPL ;
}
HRESULT  __stdcall StorageBase::SetElementTimes( const WCHAR *pwcsName, FILETIME const *pctime, FILETIME const *patime, FILETIME const *pmtime)
{
    return E_NOTIMPL ;
}
HRESULT  __stdcall StorageBase::SetClass( REFCLSID clsid)
{
    return(S_OK);
}
HRESULT  __stdcall StorageBase::SetStateBits( DWORD grfStateBits, DWORD grfMask)
{
    return E_NOTIMPL ;
}
HRESULT  __stdcall StorageBase::Stat( STATSTG * pstatstg, DWORD grfStatFlag)
{
    return E_NOTIMPL ;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


} // end namespace mol::win::ole
} // end namespace mol