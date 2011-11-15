#ifndef MOL_LIB_STORAGE_DEF_GUARD_DEFINE_
#define MOL_LIB_STORAGE_DEF_GUARD_DEFINE_

#include "util/uni.h"
#include "win/wnd.h"
#include "ole/punk.h"
#include <vector>

namespace mol {


//////////////////////////////////////////////////////////////////////////////////

class StgMedium : public STGMEDIUM
{
public:
	StgMedium( HGLOBAL hglob, IUnknown* pUnk = 0)
	{
		this->tymed          = TYMED_HGLOBAL;
		this->pUnkForRelease = pUnk;
		this->hGlobal		 = hglob;
	}

	StgMedium( const mol::string& s, int opt = GMEM_MOVEABLE|GMEM_NODISCARD, IUnknown* pUnk = 0)
	{
		mol::global glob(s,opt);
		this->tymed          = TYMED_HGLOBAL;
		this->pUnkForRelease = pUnk;
		this->hGlobal		 = glob;
		glob.detach();
	}

	template<class T>
	StgMedium( const T& t, int opt = GMEM_MOVEABLE|GMEM_NODISCARD, IUnknown* pUnk = 0)
	{
		mol::global glob(t,opt);
		this->tymed          = TYMED_HGLOBAL;
		this->pUnkForRelease = pUnk;
		this->hGlobal		 = glob;
		glob.detach();
	}


	StgMedium( void* v, size_t size, int opt = GMEM_MOVEABLE|GMEM_NODISCARD, IUnknown* pUnk = 0)
	{
		mol::global glob( v, size, opt );
		this->tymed          = TYMED_HGLOBAL;
		this->pUnkForRelease = pUnk;
		this->hGlobal		 = glob;
		glob.detach();
	}
};


//////////////////////////////////////////////////////////////////////////////////

struct format_etc : public FORMATETC
{
	format_etc( 
			CLIPFORMAT cf, 
			DVTARGETDEVICE* dv = NULL, 
			DWORD aspect = DVASPECT_CONTENT, 
			LONG index = -1, 
			DWORD t = TYMED_HGLOBAL 
		)
	{
		cfFormat	= cf;
		ptd			= dv;
		dwAspect	= aspect;
		lindex		= index;
		tymed		= t;
	}
};

//////////////////////////////////////////////////////////////////////////////////

struct format_etc_dropfile : public format_etc
{
	format_etc_dropfile() : format_etc( CF_HDROP, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL ) 	{}
};

//////////////////////////////////////////////////////////////////////////////////

struct format_etc_text : public format_etc
{
	format_etc_text() : format_etc( CF_TEXT, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL ) 	{}
};

//////////////////////////////////////////////////////////////////////////////////

struct format_etc_unicodetext : public format_etc
{
	format_etc_unicodetext() : format_etc( CF_UNICODETEXT, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL ) 	{}
};

//////////////////////////////////////////////////////////////////////////////////

struct format_etc_dropeffect : public format_etc
{
	format_etc_dropeffect() : format_etc( format(), NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL ) 	{}
	UINT format();
};

//////////////////////////////////////////////////////////////////////////////////

struct format_etc_pref_dropeffect : public format_etc
{
	format_etc_pref_dropeffect() : format_etc( format(), NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL ) 	{}
	UINT format();
};

//////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////
// a dummy OLE storage implementation
// so we can provide a IStorage Interface
//////////////////////////////////////////////////////////////////////

namespace ole {

class StorageBase  : public IStorage
{
public:

    HRESULT virtual __stdcall CreateStream( const WCHAR *pwcsName, DWORD grfMode, DWORD reserved1, DWORD reserved2, IStream **ppstm);
    HRESULT virtual __stdcall OpenStream( const WCHAR * pwcsName, void *reserved1, DWORD grfMode, DWORD reserved2, IStream **ppstm);
    HRESULT virtual __stdcall CreateStorage( const WCHAR *pwcsName, DWORD grfMode, DWORD reserved1, DWORD reserved2, IStorage **ppstg);
    HRESULT virtual __stdcall OpenStorage( const WCHAR * pwcsName, IStorage * pstgPriority, DWORD grfMode, SNB snbExclude, DWORD reserved, IStorage **ppstg);
    HRESULT virtual __stdcall CopyTo( DWORD ciidExclude, IID const *rgiidExclude, SNB snbExclude,IStorage *pstgDest);
    HRESULT virtual __stdcall MoveElementTo( const OLECHAR *pwcsName,IStorage * pstgDest, const OLECHAR *pwcsNewName, DWORD grfFlags);
    HRESULT virtual __stdcall Commit( DWORD grfCommitFlags);
    HRESULT virtual __stdcall Revert();
    HRESULT virtual __stdcall EnumElements( DWORD reserved1, void * reserved2, DWORD reserved3, IEnumSTATSTG ** ppenum);
    HRESULT virtual __stdcall DestroyElement( const OLECHAR *pwcsName);
    HRESULT virtual __stdcall RenameElement( const WCHAR *pwcsOldName, const WCHAR *pwcsNewName);
    HRESULT virtual __stdcall SetElementTimes( const WCHAR *pwcsName, FILETIME const *pctime, FILETIME const *patime, FILETIME const *pmtime);
    HRESULT virtual __stdcall SetClass( REFCLSID clsid);
    HRESULT virtual __stdcall SetStateBits( DWORD grfStateBits, DWORD grfMask);
    HRESULT virtual __stdcall Stat( STATSTG * pstatstg, DWORD grfStatFlag);

};


//////////////////////////////////////////////////////////////////////
// this one does absolutely nothing!
//////////////////////////////////////////////////////////////////////

class DummyStorage : public StorageBase
{
public:
    virtual ~DummyStorage();

    HRESULT virtual __stdcall QueryInterface( REFIID riid, LPVOID FAR* ppvObj);
    ULONG   virtual __stdcall AddRef();
    ULONG   virtual __stdcall Release();
};

//////////////////////////////////////////////////////////////////////////////////



} // end namespace mol::win::ole
} // end namespace mol

#endif