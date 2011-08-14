#include "stdafx.h"
#include "set.h"
#include "ole/Dll.h"
#include "Setting_i.c"

#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

class settingDll : 
	public Dll,
	public exports_aggregable< settingDll, Setting >,
	public exports_aggregable< settingDll, SettingProperties >
{};

DLL_COCLASS_EXPORTS(settingDll);
