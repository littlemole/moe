#ifndef MOL_DEF_GUARD_DEFINE_SSHSHELL_SHELLVIEW_DEF_GUARD
#define MOL_DEF_GUARD_DEFINE_SSHSHELL_SHELLVIEW_DEF_GUARD

#include "PidlMgr.h"
#include "win/coctrl.h"
#include <shlobj.h>

#include <objbase.h>
#include <shlobj.h>
#include <ServProv.h>
#include <DocObj.h>
#include "ShellFolder.h"
#include "PidlMgr.h"
#include "win/coctrl.h"
#include "win/msgmap.h"
#include "win/msghandler.h"
#include "win/msg_macro.h"

#define NS_CLASS_NAME   (TEXT("RegViewNSClass"))

//menu items
#define IDM_VIEW_KEYS   (FCIDM_SHVIEWFIRST + 0x500)
#define IDM_VIEW_IDW    (FCIDM_SHVIEWFIRST + 0x501)
#define IDM_MYFILEITEM  (FCIDM_SHVIEWFIRST + 0x502)
#define IDM_CONNECT_SSH (FCIDM_SHVIEWFIRST + 0x503)
#define IDM_MKDIR		(FCIDM_SHVIEWFIRST + 0x504)

//control IDs
#define ID_LISTVIEW     2000


class ShellView : 
	public mol::Frame<ShellView,mol::Window,WS_CHILD|WS_VISIBLE|WS_CLIPSIBLINGS|WS_CLIPCHILDREN,0>,
	public IShellView, 
	public IOleCommandTarget,
	public mol::interfaces< ShellView, mol::implements<IShellView,IOleWindow,IOleCommandTarget>>
{  
public:
	ShellView();
	~ShellView();
   
	typedef mol::com_instance<ShellView> Instance;
	static Instance* createInstance(IShellFolder* parent, LPCITEMIDLIST pidl);

	void dispose() 
	{
		ODBGS("dispose ShellView");
		parentFolder_.release();
	}
   
	//IOleWindow methods
	HRESULT virtual __stdcall GetWindow (HWND*);
	HRESULT virtual __stdcall ContextSensitiveHelp (BOOL);

	//IShellView methods
	HRESULT virtual __stdcall TranslateAccelerator(LPMSG);
	HRESULT virtual __stdcall EnableModeless(BOOL);
	HRESULT virtual __stdcall UIActivate(UINT);
	HRESULT virtual __stdcall Refresh(void);
	HRESULT virtual __stdcall CreateViewWindow(LPSHELLVIEW, LPCFOLDERSETTINGS, LPSHELLBROWSER, LPRECT, HWND*);
	HRESULT virtual __stdcall DestroyViewWindow(void);
	HRESULT virtual __stdcall GetCurrentInfo(LPFOLDERSETTINGS);
	HRESULT virtual __stdcall AddPropertySheetPages(DWORD, LPFNADDPROPSHEETPAGE, LPARAM);
	HRESULT virtual __stdcall SaveViewState(void);
	HRESULT virtual __stdcall SelectItem(LPCITEMIDLIST, UINT);
	HRESULT virtual __stdcall GetItemObject(UINT, REFIID, LPVOID*);

	//IOleCommandTarget methods
	HRESULT virtual __stdcall QueryStatus(const GUID *pguidCmdGroup, ULONG cCmds, OLECMD prgCmds[], OLECMDTEXT *pCmdText);
	HRESULT virtual __stdcall Exec(const GUID *pguidCmdGroup, DWORD nCmdID, DWORD nCmdExecOpt, VARIANTARG *pvaIn, VARIANTARG *pvaOut);

private:

	UINT uState_;
	LPITEMIDLIST pidl_;
	FOLDERSETTINGS folderSettings_;

	mol::punk<IShellBrowser> shellBrowser_;
	mol::punk<IShellFolder> parentFolder_;

	HWND hwndParent_;
	HMENU hMergeMenu_;

	mol::Control<
				mol::ListCtrl,
				WS_TABSTOP | 
				WS_VISIBLE |
				WS_CHILD | 
				LVS_SINGLESEL |
				LVS_REPORT | 
				LVS_NOSORTHEADER |
				LVS_SHAREIMAGELISTS,
				0
				>
	list_;

	msg_handler(WM_INITMENUPOPUP,OnUpdateMenu)
	LRESULT OnUpdateMenu(HMENU hMenu, LPARAM unused);

	msg_handler(WM_ACTIVATE,OnActivate)
	LRESULT OnActivate();

	msg_handler(WM_SETFOCUS,OnSetFocus)
	notify_code_handler(NM_SETFOCUS,OnSetFocus)
	LRESULT OnSetFocus();

	msg_handler(WM_KILLFOCUS,OnKillFocus)
	LRESULT OnKillFocus();

	//msg_handler(WM_NOTIFY,OnNotify)
	//LRESULT OnNotify(UINT, LPNMHDR);

	msg_handler(WM_SIZE,OnSize)
	LRESULT OnSize(WPARAM wParam, LPARAM lParam);

	msg_handler(WM_CREATE,OnCreate)
	LRESULT OnCreate();

	msg_handler(WM_COMMAND,OnCommand)
	LRESULT OnCommand(UINT msg, WPARAM wParam, LPARAM lParam);

	notify_code_handler(NM_KILLFOCUS,OnDeactivate)
	void OnDeactivate();

	notify_code_handler(HDN_ENDTRACK,OnEndTrack)
	void OnEndTrack();

	notify_code_handler(NM_RCLICK,OnContextMenu)
	void OnContextMenu();

	//notify_code_handler(LVN_DELETEITEM,OnDeleteItem)
	void OnDeleteItem(UINT CtlID, LPNMHDR lpnmh);

	notify_code_handler(LVN_ITEMACTIVATE,OnActivateItem)
	void OnActivateItem(UINT CtlID, LPNMHDR lpnmh);


	cmd_handler(IDM_PASTE,OnPaste)
	void OnPaste();

	LRESULT activate(UINT);
	LRESULT deactivate(UINT);
	LRESULT command(DWORD, DWORD, HWND);

	bool createList();
	bool initList();
	void fillList();
	void clearList();

	HMENU buildSSHMenu();
	void mergeFileMenu(HMENU);
	void mergeViewMenu(HMENU);

    static bool bViewKeys;

	void insertItem( mol::sftp::RemoteFile& file );


	HRESULT getUIObjectOf( IShellFolder* parent, LPCITEMIDLIST pidl, IContextMenu** ctx);
	void invokeContextMenuCmd( LPITEMIDLIST pidl, SFContextMenuCommand cmd );
};



#endif