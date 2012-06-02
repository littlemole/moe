#ifndef MOL_DEF_GUARD_DEFINE_SSHSHELL_SHELLFOLDER_DEF_GUARD
#define MOL_DEF_GUARD_DEFINE_SSHSHELL_SHELLFOLDER_DEF_GUARD

#include "PidlMgr.h"
#include "win/coctrl.h"
#include <shlobj.h>
#include "EnumPIDL.h"
#include "ViewModel.h"

extern mol::ImageList imgageListLarge;
extern mol::ImageList imgageListSmall;

HRESULT GetShellBrowser(   IUnknown* site, IShellBrowser** pShellBrowser);

enum SFContextMenuCommand {

	OPEN,
	CUT,
	COPY,
	PASTE,
	REFRESH,
	ERASE
};

class SFContextMenu 
	: public IContextMenu,
	  public IObjectWithSite,
	  public mol::interfaces< SFContextMenu, mol::implements<IContextMenu,IObjectWithSite>>
{
public:
	SFContextMenu();
	~SFContextMenu();

	typedef mol::com_instance<SFContextMenu> Instance;
	static Instance* createInstance(IShellFolder* parent, LPCITEMIDLIST pidl);

	void dispose() ;

	HRESULT virtual __stdcall  QueryContextMenu( HMENU hmenu, UINT indexMenu, UINT idCmdFirst, UINT idCmdLast, UINT uFlags);       
    HRESULT virtual __stdcall  InvokeCommand(  CMINVOKECOMMANDINFO *pici);
    HRESULT virtual __stdcall  GetCommandString( UINT_PTR idCmd, UINT uType, UINT *pReserved, LPSTR pszName, UINT cchMax);

	HRESULT virtual __stdcall  GetSite( REFIID riid,void **ppvSite);
	HRESULT virtual __stdcall  SetSite(  IUnknown *pUnkSite);


private:

	void OnPaste();
	void OnToClipboard(bool cut=false);
	void OnDelete();
	bool OnUpdate(LPITEMIDLIST pidl);
	void OnNavigate2(LPITEMIDLIST pidl);

	void registerMenuCmd(SFContextMenuCommand cmd, HMENU hmenu, UINT& indexMenu, UINT& idCmd);

	void onCutOperation(IDataObject* dataObj);

	LPITEMIDLIST pidl_;
	mol::punk<IShellFolder> parentFolder_;
	mol::punk<IUnknown> site_;
	UINT idCmdFirst_;

	std::vector<SFContextMenuCommand> cmds_;
	std::map<SFContextMenuCommand,std::wstring> map_;
};

class ShellFolder : public mol::com_registerobj<ShellFolder,CLSID_sshShell>,
					public mol::Dispatch<ISshShell>,
					public IShellFolder2, 
                    public IPersistFolder2,
					public IObjectWithSite,
					public mol::interfaces< ShellFolder, 
							mol::implements<IDispatch,ISshShell,IShellFolder,IShellFolder2,IPersistFolder,IPersistFolder2,IObjectWithSite>>
{
friend class ShellView;

public:
   ShellFolder();
   ~ShellFolder();

	typedef mol::com_instance<ShellFolder> Instance;
	static Instance* createInstance(LPCITEMIDLIST pidl);

	void dispose(); 

	HRESULT virtual __stdcall About()
	{
		::MessageBox(0,L"ShellFolder Dispatch",L"about",0);
		return S_OK;
	}

	//IPersist methods
	HRESULT virtual __stdcall GetClassID(LPCLSID);

	//IPersistFolder methods
	HRESULT virtual __stdcall Initialize(LPCITEMIDLIST);

	//IPersistFolder2 methods
	HRESULT virtual __stdcall GetCurFolder( PIDLIST_ABSOLUTE *ppidl);

	//IShellFolder methods
	HRESULT virtual __stdcall ParseDisplayName(HWND, LPBC, LPOLESTR, LPDWORD, LPITEMIDLIST*, LPDWORD);
	HRESULT virtual __stdcall EnumObjects(HWND, DWORD, LPENUMIDLIST*);
	HRESULT virtual __stdcall BindToObject(LPCITEMIDLIST, LPBC, REFIID, LPVOID*);
	HRESULT virtual __stdcall BindToStorage(LPCITEMIDLIST, LPBC, REFIID, LPVOID*);
	HRESULT virtual __stdcall CompareIDs(LPARAM, LPCITEMIDLIST, LPCITEMIDLIST);
	HRESULT virtual __stdcall CreateViewObject(HWND, REFIID, LPVOID* );
	HRESULT virtual __stdcall GetAttributesOf(UINT, LPCITEMIDLIST*, LPDWORD);
	HRESULT virtual __stdcall GetUIObjectOf(HWND, UINT, LPCITEMIDLIST*, REFIID, LPUINT, LPVOID*);
	HRESULT virtual __stdcall GetDisplayNameOf(LPCITEMIDLIST, DWORD, LPSTRRET);
	HRESULT virtual __stdcall SetNameOf(HWND, LPCITEMIDLIST, LPCOLESTR, DWORD, LPITEMIDLIST*);

	HRESULT virtual __stdcall  GetSite( REFIID riid,void **ppvSite);
	HRESULT virtual __stdcall  SetSite(  IUnknown *pUnkSite);

	HRESULT virtual __stdcall  EnumSearches(IEnumExtraSearch **ppEnum);
	HRESULT virtual __stdcall  GetDefaultColumn( DWORD dwReserved, ULONG *pSort, ULONG *pDisplay);
	HRESULT virtual __stdcall  GetDefaultColumnState( UINT iColumn, SHCOLSTATEF *pcsFlags);
	HRESULT virtual __stdcall  GetDefaultSearchGUID( GUID *pguid );
	HRESULT virtual __stdcall  GetDetailsEx( PCUITEMID_CHILD pidl, const SHCOLUMNID *pscid, VARIANT *pv );
	HRESULT virtual __stdcall  GetDetailsOf( PCUITEMID_CHILD pidl, UINT iColumn, SHELLDETAILS *psd);
	HRESULT virtual __stdcall  MapColumnToSCID( UINT iColumn, SHCOLUMNID *pscid) ;
        
private:
	mol::punk<IUnknown> site_;
	LPITEMIDLIST pidl_;

};


#endif