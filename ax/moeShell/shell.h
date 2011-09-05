#ifndef MOL_DEF_SETTING_VIEW_DEF_GUARDING_
#define MOL_DEF_SETTING_VIEW_DEF_GUARDING_

#include "ole/aut.h"
#include "ole/factory.h"
#include "ole/bstr.h"
#include "ole/dll.h"
#include "win/shell.h"

#include "moeShell_h.h"

#include "resource.h"

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

template <> 
class mol::uuid_info<IContextMenu>
{
 public:
   static REFIID uuidof;
//   static const GUID& uuidof() { return IID_IContextMenu; }
   typedef IContextMenu uuid_type;
};



class moeShell : 
	public mol::com_registerobj<moeShell,CLSID_moeShell>,
	public mol::Dispatch<ImoeShell>,
	public IShellExtInit,
	public IContextMenu,
	public mol::interfaces< moeShell,
			mol::implements<
				IDispatch,
				IShellExtInit,
				IContextMenu>//,
				//IContextMenu2,
				//IContextMenu3>
			>

{
public:

	moeShell() ;
	~moeShell() {};

	HRESULT __stdcall Initialize( LPCITEMIDLIST pidlFolder, IDataObject *pdtobj, HKEY hkeyProgID );
	HRESULT __stdcall GetCommandString( UINT_PTR idCmd, UINT uFlags, UINT *pwReserved, LPSTR pszName, UINT cchMax );
	HRESULT __stdcall InvokeCommand(LPCMINVOKECOMMANDINFO pici);		HRESULT __stdcall QueryContextMenu(HMENU hmenu, UINT indexMenu, UINT idCmdFirst, UINT idCmdLast, UINT uFlags);		
	HRESULT __stdcall About();
	HRESULT __stdcall HandleMenuMsg(  UINT uMsg,  WPARAM wParam,  LPARAM lParam);
	HRESULT __stdcall HandleMenuMsg2(UINT uMsg,  WPARAM wParam,  LPARAM lParam,  LRESULT *plResult);


protected:


	HRESULT __stdcall HandleMenuMsgImpl(UINT uMsg,  WPARAM wParam,  LPARAM lParam,  LRESULT *plResult);

	mol::TCHAR filename_[MAX_PATH];
	UINT open_cmd;
	UINT open_utf8_cmd;
	UINT open_html_cmd;
	UINT open_hex_cmd;
	UINT open_tail_cmd;

	UINT open_id;
	UINT open_utf8_id;
	UINT open_html_id;
	UINT open_hex_id;
	UINT open_tail_id;

//	mol::Icon icon_;
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


class moeShellDll : 
	public mol::Dll,
	public mol::exports<moeShellDll,moeShell>
{};

#endif