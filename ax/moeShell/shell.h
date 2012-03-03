#ifndef MOL_DEF_SETTING_VIEW_DEF_GUARDING_
#define MOL_DEF_SETTING_VIEW_DEF_GUARDING_

#include "ole/aut.h"
#include "ole/factory.h"
#include "ole/bstr.h"
#include "ole/dll.h"
#include "win/shell.h"
#include <memory>
#include "moeShell_h.h"

#include "resource.h"

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

template <> 
class mol::uuid_info<IContextMenu>
{
 public:
   static REFIID uuidof;
   typedef IContextMenu uuid_type;
};

///////////////////////////////////////////////////////////////////////////////

class moeShellMenuItem
{
public:
	moeShellMenuItem(int cmd, const mol::string& p,const mol::string& desc)
		: iCmd(cmd), proto(p), description(desc)
	{}

	UINT iCmd;
	mol::string proto;
	mol::string description;

	HRESULT __stdcall InvokeCommand(const mol::string& filepath, LPCMINVOKECOMMANDINFO pici);
};

///////////////////////////////////////////////////////////////////////////////

class moeShell : 
	public mol::com_registerobj<moeShell,CLSID_moeShell>,
	public mol::Dispatch<ImoeShell>,
	public IShellExtInit,
	public IContextMenu,
	public mol::interfaces< moeShell,
			mol::implements<
				IDispatch,
				IShellExtInit,
				IContextMenu>
			>
{
public:

	moeShell();
	~moeShell();

	HRESULT __stdcall Initialize( LPCITEMIDLIST pidlFolder, IDataObject *pdtobj, HKEY hkeyProgID );
	HRESULT __stdcall GetCommandString( UINT_PTR idCmd, UINT uFlags, UINT *pwReserved, LPSTR pszName, UINT cchMax );
	HRESULT __stdcall InvokeCommand(LPCMINVOKECOMMANDINFO pici);		
	HRESULT __stdcall QueryContextMenu(HMENU hmenu, UINT indexMenu, UINT idCmdFirst, UINT idCmdLast, UINT uFlags);		
	HRESULT __stdcall About();

protected:

	void registerMenuItem( UINT& iCmd, const mol::string& proto, const mol::string& desc );

	mol::string filepath_;

	mol::Bmp bmp_;
	mol::Bmp bmp2_;

	typedef std::vector<UINT> IndexVector;
	IndexVector cmd_indexes_;

	typedef std::map<UINT,std::shared_ptr<moeShellMenuItem>> MenuCmdMap;

	MenuCmdMap menu_cmds_;

};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


class moeShellDll : 
	public mol::Dll,
	public mol::exports<moeShellDll,moeShell>
{};

///////////////////////////////////////////////////////////////////////////////


#endif