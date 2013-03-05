#include "win/core.h"
#include "ole/Dll.h"
#include "ole/typelib.h"
#include "ole/Factory.h"

namespace mol {

void Dll::UnLock()
{
	//LOCK(mutex_);
	//lockCount_--;
	::InterlockedDecrement(&lockCount_);
}

HRESULT __stdcall  Dll::RegisterServer()
{
	TypeLib tl;
	tl.load();
	tl.registerTypelib();

	for ( unsigned int i = 0; i < objects_.size(); i++ )
	{
		objects_[i]->Register();
	}
	return S_OK;
}

HRESULT __stdcall  Dll::UnregisterServer()
{
	for ( unsigned int i = 0; i < objects_.size(); i++ )
	{
		objects_[i]->Unregister();
	}
	
	TypeLib tl;
	tl.load();
	tl.unRegisterTypelib();
	return S_OK;
}

BOOL __stdcall  Dll::Main( HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	if ( fdwReason == DLL_PROCESS_ATTACH )
	{
		//ODBGS( "ATTACH DLL" );	
		hInstance_ = hinstDLL;

	}
#ifdef _DEBUG
	if ( fdwReason == DLL_PROCESS_DETACH )
	{
		//ODBGS( "DETACH DLL" );	
	}
#endif
	return TRUE;
}
  
HRESULT __stdcall  Dll::GetClassObject( const CLSID & rclsid, const IID & riid, void ** ppv)
{
	for ( unsigned int i = 0; i < objects_.size(); i++ )
	{
		if ( ::IsEqualGUID(rclsid,objects_[i]->classId()) )
		{
			return objects_[i]->GetClassObject(riid,ppv);
		}
	}
	return E_NOINTERFACE;
}

HRESULT __stdcall  Dll::CanUnloadNow()
{
	if ( locked() )
		return S_FALSE;
	//ODBGS( "UNLOAD DLL" );	
	return S_OK;
}

} // end namespace mol

