#include "conf.h"
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
	wchar_t  path[MAX_PATH];
	wchar_t file[MAX_PATH];
	::GetTempPath(255,path);
	::GetTempFileName( path, _T("ufs_"), 0, file );

	mol::punk<IStorage> store;
	if ( S_OK == ::StgCreateDocfile( mol::towstring(file).c_str(), STGM_DELETEONRELEASE|STGM_CREATE|STGM_READWRITE|STGM_SHARE_EXCLUSIVE|STGM_TRANSACTED,0,&store) )
	{
		HRESULT hr = src->CopyTo(0,0,0,store);
		return store.queryInterface(copy);
	}
	return E_FAIL;
}

}}
