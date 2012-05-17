#ifndef MOL_DEFINE_DLL_DEF_GUARD_DEFINE_
#define MOL_DEFINE_DLL_DEF_GUARD_DEFINE_

#include "win/App.h"

namespace mol {
namespace ole {

class CreatableObjectHolderBase;

} // end namespace mol

//////////////////////////////////////////////////////////////////////////////////
// Com DLL implementation class
//////////////////////////////////////////////////////////////////////////////////

class Dll : public mol::win::AppBase
{
public:
	Dll() 
	{}

	virtual ~Dll()
	{}

	virtual HRESULT __stdcall RegisterServer();
	virtual HRESULT __stdcall UnregisterServer();

	virtual BOOL	__stdcall Main( HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved);
	virtual HRESULT __stdcall GetClassObject( const CLSID & rclsid, const IID & riid, void ** ppv); 
	virtual HRESULT __stdcall CanUnloadNow();

	std::vector<mol::ole::CreatableObjectHolderBase*> objects_;

protected:
	virtual void UnLock();


};

} // end namespace mol

//////////////////////////////////////////////////////////////////////////////////
// implement DLL exports for Inproc server
//////////////////////////////////////////////////////////////////////////////////

#define DLL_COCLASS_EXPORTS(Dll)																		\
EXTERN_C BOOL WINAPI DllMain( HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)					\
{																										\
	return mol::singleton<Dll>().Main(hinstDLL,fdwReason,lpvReserved );									\
}																										\
																										\
EXTERN_C HRESULT STDAPICALLTYPE DllGetClassObject( const CLSID & rclsid, const IID & riid, void ** ppv) \
{																										\
	return mol::singleton<Dll>().GetClassObject(rclsid,riid,ppv);										\
}																										\
																										\
EXTERN_C HRESULT __stdcall DllRegisterServer(void)														\
{																										\
	return mol::singleton<Dll>().RegisterServer();														\
}																										\
																										\
EXTERN_C HRESULT __stdcall DllUnregisterServer(void)													\
{																										\
	return mol::singleton<Dll>().UnregisterServer();													\
}																										\
																										\
EXTERN_C HRESULT __stdcall DllCanUnloadNow(void)														\
{																										\
	return mol::singleton<Dll>().CanUnloadNow();														\
}																										\


#endif