#ifndef MOL_DEF_SETTING_VIEW_DEF_GUARDING_
#define MOL_DEF_SETTING_VIEW_DEF_GUARDING_

#include "win/ole/aut.h"
#include "win/ole/factory.h"
#include "win/ole/bstr.h"
#include "win/ole/dll.h"
#include "win/io/shell.h"

#include "moeShell_h.h"

#include "resource.h"

///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

template <> 
class mol::uuid_info<IContextMenu>
{
 public:
   static const GUID& uuidof() { return IID_IContextMenu; }
   typedef IContextMenu uuid_type;
};


class moeShell : 
	public mol::com_creatable<moeShell,CLSID_moeShell>,
	public mol::Dispatch<ImoeShell>,
	public IShellExtInit,
	public IContextMenu,
	public mol::interfaces< moeShell,
			mol::implements<
				ImoeShell,
				IDispatch,
				IShellExtInit,
				IContextMenu>
			>

{
public:

	moeShell(void) {};
	~moeShell() {};

	HRESULT __stdcall Initialize( LPCITEMIDLIST pidlFolder, IDataObject *pdtobj, HKEY hkeyProgID );
	HRESULT __stdcall GetCommandString( UINT_PTR idCmd, UINT uFlags, UINT *pwReserved, LPSTR pszName, UINT cchMax );
	HRESULT __stdcall InvokeCommand(LPCMINVOKECOMMANDINFO pici);		HRESULT __stdcall QueryContextMenu(HMENU hmenu, UINT indexMenu, UINT idCmdFirst, UINT idCmdLast, UINT uFlags);		
	HRESULT __stdcall About();

protected:

	mol::TCHAR filename_[MAX_PATH];
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


class moeShellDll : 
	public mol::Dll,
	public mol::exports<moeShellDll,moeShell>
{};

#endif