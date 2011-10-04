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
   typedef IContextMenu uuid_type;
};



class moeShell : 
	public mol::com_registerobj<moeShell,CLSID_moeShell>,
	public mol::Dispatch<ImoeShell>,
	public IShellExtInit,
	public IContextMenu3,
	public mol::interfaces< moeShell,
			mol::implements<
				IDispatch,
				IShellExtInit,
				mol::interface_ex<IContextMenu,IContextMenu3>,
				mol::interface_ex<IContextMenu2,IContextMenu3>,
				IContextMenu3>
			>

{
public:

	moeShell();
	~moeShell();

	HRESULT __stdcall Initialize( LPCITEMIDLIST pidlFolder, IDataObject *pdtobj, HKEY hkeyProgID );
	HRESULT __stdcall GetCommandString( UINT_PTR idCmd, UINT uFlags, UINT *pwReserved, LPSTR pszName, UINT cchMax );
	HRESULT __stdcall InvokeCommand(LPCMINVOKECOMMANDINFO pici);		HRESULT __stdcall QueryContextMenu(HMENU hmenu, UINT indexMenu, UINT idCmdFirst, UINT idCmdLast, UINT uFlags);		
	HRESULT __stdcall About();

	HRESULT __stdcall HandleMenuMsg(UINT, WPARAM, LPARAM);
	HRESULT __stdcall HandleMenuMsg2(UINT, WPARAM, LPARAM, LRESULT*);
protected:

	HRESULT __stdcall HandleMenuMsgImpl(UINT uMsg,  WPARAM wParam,  LPARAM lParam,  LRESULT *plResult);
	HRESULT __stdcall OnMeasureItem ( MEASUREITEMSTRUCT* mis, LRESULT* pResult );
	HRESULT __stdcall OnDrawItem ( DRAWITEMSTRUCT* dis, LRESULT* pResult );

//	mol::TCHAR filename_[MAX_PATH];

	mol::string filepath_;

	
	UINT open_cmd;
	UINT open_open_cmd;
	UINT open_html_cmd;
	UINT open_hex_cmd;
	UINT open_tail_cmd;
	UINT open_rtf_cmd;
	UINT open_as_cmd;

	UINT open_cmd_id;
	UINT open_as_cmd_id;
	

	mol::Bmp bmp_;

	typedef std::vector<UINT> IndexVector;

	IndexVector cmd_indexes_;

	typedef std::pair<mol::string,mol::string> CmdLabel;
	typedef std::map<UINT,CmdLabel> CmdLapelMap;
	CmdLapelMap cmd_labels_;
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


class moeShellDll : 
	public mol::Dll,
	public mol::exports<moeShellDll,moeShell>
{};

#endif