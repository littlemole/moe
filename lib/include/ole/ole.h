#ifndef MOL_OLE_DEF_GUARD_DEFINE_
#define MOL_OLE_DEF_GUARD_DEFINE_

#pragma once

#include "util/uni.h"
#include "ole/com.h"
#include "ole/obj.h"
#include "util/x.h"
#include <list>

namespace mol {
namespace ole {

/////////////////////////////////////////////////////////////////////

void HIMETRICtoPixel(SIZE* sz, HDC hdc = 0);
void PixeltoHIMETRIC(SIZE* sz, HDC hdc = 0);

//////////////////////////////////////////////////////////////////////

} // end namespace mol

HRESULT __stdcall CreateObjectAdmin( HWND hwnd, BSTR progid, IUnknown** unk);

BOOL GetAccessPermissionsForLUAServer(SECURITY_DESCRIPTOR **ppSD);


class ole_init
{
public:
    ole_init () 
	{ 
		::OleInitialize(0);  
	}


    ~ole_init() 
	{
		for ( std::list<IUnknown*>::iterator it = singletons_.begin(); it != singletons_.end(); it++ )
		{
			(*it)->Release();
		}
		::OleUninitialize(); 
	}

	static void addRef( IUnknown* p )
	{
		p->AddRef();
		singletons_.push_back(p);
	}

private:
	static std::list<IUnknown*> singletons_;
};

namespace ole {

//////////////////////////////////////////////////////////////////////
// IMONIKER DUMMY BASE
//////////////////////////////////////////////////////////////////////

class Moniker : 
	public IMoniker,
	public interfaces< Moniker, implements< IMoniker, IPersistStream> >
{
public:

	virtual void dispose() {}

    virtual HRESULT __stdcall GetClassID(CLSID *pClassID) 
        { return E_FAIL; }

    virtual HRESULT __stdcall IsDirty() 
        { return S_FALSE; }

    virtual HRESULT __stdcall Load( IStream *pStm) 
        { return S_OK; }

    virtual HRESULT __stdcall Save( IStream *pStm, BOOL fClearDirty) 
        { return S_OK; }

    virtual HRESULT __stdcall GetSizeMax( ULARGE_INTEGER *pcbSize) 
        { return S_OK; }

    virtual HRESULT __stdcall BindToObject( IBindCtx *pbc, IMoniker *pmkToLeft, REFIID riidResult, void **ppvResult) 
        { return S_OK; }

    virtual HRESULT __stdcall BindToStorage( IBindCtx *pbc, IMoniker *pmkToLeft, REFIID riid, void **ppvObj) 
        { return S_OK; }

    virtual HRESULT __stdcall Reduce( IBindCtx *pbc, DWORD dwReduceHowFar, IMoniker **ppmkToLeft, IMoniker **ppmkReduced) 
        { return MK_S_REDUCED_TO_SELF ; }

    virtual HRESULT __stdcall ComposeWith( IMoniker *pmkRight, BOOL fOnlyIfNotGeneric, IMoniker **ppmkComposite) 
        { return S_OK; }

    virtual HRESULT __stdcall Enum( BOOL fForward, IEnumMoniker **ppenumMoniker) 
        { *ppenumMoniker=0; return S_OK; }

    virtual HRESULT __stdcall IsEqual( IMoniker *pmkOtherMoniker) 
        { return S_FALSE ; }

    virtual HRESULT __stdcall Hash( DWORD *pdwHash) 
        { return S_OK; }

    virtual HRESULT __stdcall IsRunning( IBindCtx *pbc, IMoniker *pmkToLeft, IMoniker *pmkNewlyRunning) 
        { return S_FALSE; }

    virtual HRESULT __stdcall GetTimeOfLastChange( IBindCtx *pbc, IMoniker *pmkToLeft, FILETIME *pFileTime) 
        { return MK_E_UNAVAILABLE ; }

    virtual HRESULT __stdcall Inverse( IMoniker **ppmk) 
        { return MK_E_NOINVERSE ; }

    virtual HRESULT __stdcall CommonPrefixWith( IMoniker *pmkOther, IMoniker **ppmkPrefix) 
        { return MK_E_NOTBINDABLE  ; }

    virtual HRESULT __stdcall RelativePathTo( IMoniker *pmkOther, IMoniker **ppmkRelPath) 
        { return MK_E_NOTBINDABLE ; }

    virtual HRESULT __stdcall GetDisplayName( IBindCtx *pbc, IMoniker *pmkToLeft, LPOLESTR *ppszDisplayName) 
        { return E_NOTIMPL ; }

    virtual HRESULT __stdcall ParseDisplayName( IBindCtx *pbc, IMoniker *pmkToLeft, LPOLESTR pszDisplayName, ULONG *pchEaten, IMoniker **ppmkOut) 
        { return MK_E_SYNTAX ; }

    virtual HRESULT __stdcall IsSystemMoniker( DWORD *pdwMksys) 
        { *pdwMksys = MKSYS_NONE; return S_FALSE ; }        
};

} // end namespace mol::win::ole
} // end namespace mol

#endif