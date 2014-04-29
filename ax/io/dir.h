#ifndef MOL_DEF_DIR_IO_DEF_GUARDING_AX
#define MOL_DEF_DIR_IO_DEF_GUARDING_AX

#include "ole/aut.h"
#include "ole/factory.h"
#include "ole/bstr.h"
#include "ole/variant.h"
#include "ole/dll.h"
#include "win/file.h"
#include "win/enc.h"
#include "io_h.h"

#include "resource.h"

using namespace mol;

class DirObj : 
	public mol::com_registerobj<
						DirObj,
						CLSID_Dir,
						CLSCTX_INPROC_SERVER,
						PROGRAMMABLE|APARTMENT|DLL_SURROGATE|CAN_ELEVATE>,
	public mol::Dispatch<IDir>,
	public mol::interfaces< 
			DirObj,
				mol::implements<
					IDir,
					IDispatch > 
			>
{
public:

	typedef com_instance<DirObj> Instance;

	static Instance* CreateInstance(std::vector<std::wstring>& v);
	virtual void dispose();

	HRESULT __stdcall _NewEnum( IEnumVARIANT** newEnum);
	HRESULT __stdcall Item( long i,  BSTR* direntry);
	HRESULT __stdcall Count( long* cnt);

	std::vector<std::wstring> entries;
};

#endif