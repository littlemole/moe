#include "stdafx.h"
#include "set.h"
#include "ole/Dll.h"
#include "Setting_i.c"

class settingDll : 
	public Dll,
	public exports_aggregable< settingDll, Setting >,
	public exports_aggregable< settingDll, SettingProperties >
{};

DLL_COCLASS_EXPORTS(settingDll);
