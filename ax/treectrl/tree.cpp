#include "stdafx.h"
#include "ole/Dll.h"

#include "TreeCtrl.h"
#include "TreeCtrl_i.c"

class treeControlDll : 
	public mol::Dll,
	public mol::exports_aggregable< treeControlDll, TreeCtrl >
{};

DLL_COCLASS_EXPORTS(treeControlDll);
