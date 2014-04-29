#include "stdafx.h"
#include "win/path.h"
#include "win/folder.h"
#include "ole/bstr.h"
#include "win/codlg.h"
#include "io_h.h"
#include "path.h"
#include "dir.h"


using namespace mol;

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall PathObj::Extension( BSTR f,  BSTR* ret)
{
	if ( !ret )
		return E_INVALIDARG;

	*ret = 0;
	if ( f == 0 )
		return S_OK;

	std::wstring s = bstr(f).towstring();
	if ( s.empty() )
		return S_OK;

	*ret = ::SysAllocString( mol::towstring( mol::Path::ext(s) ).c_str() );
	return S_OK;
}

HRESULT __stdcall PathObj::Filename( BSTR f, BSTR* ret)
{
	if ( !ret )
		return E_INVALIDARG;

	*ret = 0;
	if ( f == 0 )
		return S_OK;

	std::wstring s = bstr(f).towstring();
	if ( s.empty() )
		return S_OK;

	*ret = ::SysAllocString( mol::towstring( mol::Path::filename(s) ).c_str() );
	return S_OK;
}

HRESULT __stdcall PathObj::Path( BSTR f,  BSTR* ret)
{
	if ( !ret )
		return E_INVALIDARG;

	*ret = 0;
	if ( f == 0 )
		return S_OK;

	std::wstring s = bstr(f).towstring();
	if ( s.empty() )
		return S_OK;

	*ret = ::SysAllocString( mol::towstring( mol::Path::pathname(s) ).c_str() );
	return S_OK;
}


HRESULT __stdcall PathObj::StripRoot( BSTR f,  BSTR* ret)
{
	if ( !ret )
		return E_INVALIDARG;

	*ret = 0;
	if ( f == 0 )
		return S_OK;

	std::wstring s = bstr(f).towstring();
	if ( s.empty() )
		return S_OK;

	*ret = ::SysAllocString( mol::towstring( mol::Path::stripRoot(s) ).c_str() );
	return S_OK;
}

HRESULT __stdcall PathObj::Root( BSTR f,  BSTR* ret)
{
	if ( !ret )
		return E_INVALIDARG;

	*ret = 0;
	if ( f == 0 )
		return S_OK;

	std::wstring s = bstr(f).towstring();
	if ( s.empty() )
		return S_OK;

	*ret = ::SysAllocString( mol::towstring( mol::Path::stripToRoot(s) ).c_str() );
	return S_OK;
}

HRESULT __stdcall PathObj::AddBackSlash( BSTR f,  BSTR* ret)
{
	if ( !ret )
		return E_INVALIDARG;

	*ret = 0;
	if ( f == 0 )
		return S_OK;

	std::wstring s = bstr(f).towstring();
	if ( s.empty() )
		return S_OK;

	*ret = ::SysAllocString( mol::towstring( mol::Path::addBackSlash(s) ).c_str() );
	return S_OK;
}

HRESULT __stdcall PathObj::RemoveBackSlash( BSTR f,  BSTR* ret)
{
	if ( !ret )
		return E_INVALIDARG;

	*ret = 0;
	if ( f == 0 )
		return S_OK;

	std::wstring s = bstr(f).towstring();
	if ( s.empty() )
		return S_OK;

	*ret = ::SysAllocString( mol::towstring( mol::Path::removeBackSlash(s) ).c_str() );
	return S_OK;
}

HRESULT __stdcall PathObj::AddExtension( BSTR f,  BSTR e,  BSTR* ret)
{
	if ( !ret )
		return E_INVALIDARG;

	*ret = 0;
	if ( f == 0 || e == 0)
		return S_OK;

	std::wstring s = bstr(f).towstring();
	if ( s.empty() )
		return S_OK;

	std::wstring s2 = bstr(e).towstring();
	if ( s2.empty() )
		return S_OK;

	std::wstring r = mol::Path::append(s,s2);

	*ret = ::SysAllocString( mol::towstring( r ).c_str() );
	return S_OK;
}

HRESULT __stdcall PathObj::IsSubPath( BSTR p1,  BSTR p2,  VARIANT_BOOL* ret)
{
	if ( !ret )
		return E_INVALIDARG;

	*ret = VARIANT_FALSE;
	if ( p1 == 0 || p2 == 0)
		return S_OK;

	std::wstring s = bstr(p1).towstring();
	if ( s.empty() )
		return S_OK;

	std::wstring s2 = bstr(p2).towstring();
	if ( s2.empty() )
		return S_OK;

	bool r = mol::Path::isSubpath(s,s2);

	*ret = r ? VARIANT_TRUE : VARIANT_FALSE;
	return S_OK;
}

HRESULT __stdcall PathObj::Exists( BSTR f,  VARIANT_BOOL* ret)
{
	if ( !ret )
		return E_INVALIDARG;

	*ret = VARIANT_FALSE;
	if ( f == 0 )
		return S_OK;

	std::wstring s = bstr(f).towstring();
	if ( s.empty() )
		return S_OK;

	*ret = mol::Path::exists(s) ? VARIANT_TRUE : VARIANT_FALSE;
	return S_OK;
}

HRESULT __stdcall PathObj::IsDir( BSTR f,  VARIANT_BOOL* ret)
{
	if ( !ret )
		return E_INVALIDARG;

	*ret = VARIANT_FALSE;
	if ( f == 0 )
		return S_OK;

	std::wstring s = bstr(f).towstring();
	if ( s.empty() )
		return S_OK;

	*ret = mol::Path::isDir(s) ? VARIANT_TRUE : VARIANT_FALSE;
	return S_OK;
}

HRESULT __stdcall PathObj::IsRoot( BSTR f,  VARIANT_BOOL* ret)
{
	if ( !ret )
		return E_INVALIDARG;

	*ret = VARIANT_FALSE;
	if ( f == 0 )
		return S_OK;

	std::wstring s = bstr(f).towstring();
	if ( s.empty() )
		return S_OK;

	*ret = mol::Path::isRoot(s) ? VARIANT_TRUE : VARIANT_FALSE;
	return S_OK;
}

HRESULT __stdcall PathObj::IsUNC( BSTR f,  VARIANT_BOOL* ret)
{
	if ( !ret )
		return E_INVALIDARG;

	*ret = VARIANT_FALSE;
	if ( f == 0 )
		return S_OK;

	std::wstring s = bstr(f).towstring();
	if ( s.empty() )
		return S_OK;

	*ret = mol::Path::isUNC(s) ? VARIANT_TRUE : VARIANT_FALSE;
	return S_OK;
}

HRESULT __stdcall PathObj::IsNetDrive( BSTR f,  VARIANT_BOOL* ret)
{
	if ( !ret )
		return E_INVALIDARG;

	*ret = VARIANT_FALSE;
	if ( f == 0 )
		return S_OK;

	std::wstring s = bstr(f).towstring();
	if ( s.empty() )
		return S_OK;

	*ret = mol::Path::isNetDrive(s) ? VARIANT_TRUE : VARIANT_FALSE;
	return S_OK;
}

HRESULT __stdcall PathObj::ParentDir( BSTR f,  BSTR* ret)
{
	if ( !ret )
		return E_INVALIDARG;

	*ret = 0;
	if ( f == 0 )
		return S_OK;

	std::wstring s = bstr(f).towstring();
	if ( s.empty() )
		return S_OK;

	*ret = ::SysAllocString( mol::towstring( mol::Path::parentDir(s) ).c_str() );
	return S_OK;
}

HRESULT __stdcall PathObj::OpenDir( BSTR f,  IDir** ret)
{
	if ( !ret )
		return E_INVALIDARG;

	*ret = 0;
	if ( f == 0 )
		return S_OK;

	std::wstring s = bstr(f).towstring();
	if ( s.empty() )
		return S_OK;
	if (!mol::Path::isDir(s) )
	{
		return S_OK;
	}

	std::vector<std::wstring> v = mol::Directory::List(s);

	DirObj::Instance* dir = DirObj::CreateInstance(v);

	((IDir*)(dir))->QueryInterface( IID_IDir, (void**)ret );
	((IDir*)(dir))->Release();
	return S_OK;
}



HRESULT __stdcall PathObj::OpenFile( BSTR f,  IFile** ret)
{
	if ( !ret)
		return E_INVALIDARG;

	*ret = 0;

	std::wstring p = bstr(f).towstring();
	if ( !mol::Path::exists(p) )
		return S_OK;

	punk<IFile> file;
	if ( S_OK != file.createObject(CLSID_File) )
		return S_OK;

	VARIANT_BOOL vb;
	if ( S_OK != file->Open(f,&vb) || vb == VARIANT_FALSE)
		return S_OK;

	return file->QueryInterface( IID_IFile, (void**)ret );
}

HRESULT __stdcall PathObj::ChooseDir( BSTR* ret)
{
	if ( !ret )
		return E_INVALIDARG;

	mol::io::FolderBrowser fb( _T("browse for folder"), _T("FolderBrowser"));
	std::wstring p = fb.select(0,BIF_USENEWUI|BIF_STATUSTEXT|BIF_SHAREABLE|BIF_BROWSEINCLUDEURLS);
	*ret = ::SysAllocString( mol::towstring(p).c_str() );

	return S_OK;
}

HRESULT __stdcall PathObj::FileOpenDlg( BSTR* ret)
{
	if ( !ret )
		return E_INVALIDARG;

	mol::FilenameDlg ofn(0);

	if ( ofn.dlgOpen( OFN_HIDEREADONLY | OFN_EXPLORER ) )
	{
		*ret = ::SysAllocString( mol::towstring( ofn.fileName() ).c_str() );
	}
	return S_OK;
}

HRESULT __stdcall PathObj::FileSaveDlg( BSTR* ret)
{
	if ( !ret )
		return E_INVALIDARG;

	mol::FilenameDlg ofn(0);
	if ( ofn.dlgSave( OFN_OVERWRITEPROMPT ) )
	{
		*ret = ::SysAllocString( mol::towstring( ofn.fileName() ).c_str() );
	}
	return S_OK;
}