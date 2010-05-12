#include "stdafx.h"
#include "ole/Dll.h"

#include "ColorPickerDlg.h"
#include "ShellTreeCtrl.h"
#include "ShellListCtrl.h"
//#include "WorkSpaceCtrl.h"
#include "HexCtrl.h"

#include "ShellCtrl_i.c"

class shellCtrlDll : 
	public Dll,
	public exports_aggregable< shellCtrlDll, ShellTree >,
	public exports_aggregable< shellCtrlDll, ShellListCtrl >,
	public exports_aggregable< shellCtrlDll, ColorDlg >,
	public exports_aggregable< shellCtrlDll, HexCtrl >
{};

DLL_COCLASS_EXPORTS(shellCtrlDll);
