#include "stdafx.h"
#include "ole/Dll.h"

#include "ShellFolderCtrl.h"

#include "ShellFolder_i.c"

class shellFolderDll : 
	public Dll,
	public exports_aggregable< shellFolderDll, ShellFolderCtrl >
{};

DLL_COCLASS_EXPORTS(shellFolderDll);
