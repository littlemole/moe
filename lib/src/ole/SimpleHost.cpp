#include "ole/SimpleHost.h"


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

namespace mol {
namespace ole {

HRESULT copyStorageTemp(IStorage* src, IStorage** copy)
{
	if ( !src || !copy )
		return E_POINTER;

	*copy = 0;
	mol::TCHAR  path[MAX_PATH];
	mol::TCHAR file[MAX_PATH];
	::GetTempPath(255,path);
	::GetTempFileName( path, _T("ufs_"), 0, file );

	mol::punk<IStorage> store;
	if ( S_OK == ::StgCreateDocfile( mol::towstring(file).c_str(), STGM_DELETEONRELEASE|STGM_CREATE|STGM_READWRITE|STGM_SHARE_EXCLUSIVE|STGM_TRANSACTED,0,&store) )
	{
		HRESULT hr = src->CopyTo(0,0,0,store);
		//return store->QueryInterface( IID_IStorage, (void**)copy);
		return store.queryInterface(copy);
	}
	return E_FAIL;
}

}}
