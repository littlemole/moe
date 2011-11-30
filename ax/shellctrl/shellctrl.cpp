#include "stdafx.h"
#include "ole/Dll.h"

#include "ColorPickerDlg.h"
#include "ShellTreeCtrl.h"
#include "ShellListCtrl.h"
#include "ScpListCtrl.h"
#include "HexCtrl.h"

#include "ShellCtrl_i.c"
#include "../ssh/ssh_i.c"

class shellCtrlDll : 
	public Dll,
	public exports_aggregable< shellCtrlDll, ShellTree >,
	public exports_aggregable< shellCtrlDll, ShellListCtrl >,
	public exports_aggregable< shellCtrlDll, ColorDlg >,
	public exports_aggregable< shellCtrlDll, HexCtrl >,
	public exports_aggregable< shellCtrlDll, ScpListCtrl >
{};

DLL_COCLASS_EXPORTS(shellCtrlDll);
