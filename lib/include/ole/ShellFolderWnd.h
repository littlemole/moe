#ifndef _MOL_DEF_GUARD_SHELL_FOLDER_WND_DEF_GUARD_DEFINE_
#define _MOL_DEF_GUARD_SHELL_FOLDER_WND_DEF_GUARD_DEFINE_

#include "ole/ole.h"
#include "ole/ole.h"
#include "ole/obj.h"
#include "ole/cp.h"
#include "ole/Bstr.h"
#include "ole/typeinfo.h"
#include "ole/Factory.h"
#include "ole/aut.h"
#include "win/path.h"
#include "win/file.h"
#include "util/istr.h"
#include <list>
#include <map>
#include <set>
#include <vector>
#include "win/wnd.h"
#include "win/msgmap.h"
#include "win/shell.h"
#include "win/layout.h"
#include "util/util.h"
#include "util/str.h"
#include <shobjidl.h>

namespace mol  {
namespace ole  {

class ShellFolderWnd :
	public mol::Frame<ShellFolderWnd,mol::Window,WS_CHILD|WS_VISIBLE|WS_CLIPSIBLINGS|WS_CLIPCHILDREN,0>,
	public IShellBrowser,
	public IServiceProvider,
	public ICommDlgBrowser2,
	public IContextMenuSite,
	public mol::interfaces< ShellFolderWnd,
		mol::implements<
			IOleWindow,
			IShellBrowser,
			IServiceProvider,
			ICommDlgBrowser,
			ICommDlgBrowser2,
			IContextMenuSite> 
		>

{
public:
	ShellFolderWnd(void);
	~ShellFolderWnd(void);

	void dispose();

	LRESULT wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	bool displayFiles();
	void displayFiles(bool b);
	void path( const mol::string& p);
	mol::string path();
	bool hasFocus();

	std::vector<mol::string> selected();

	void refresh();
	void cut();
	void copy();
	void paste();
	void rename();
	void erase();
	void execute();
	void updir();
	void newdir();
	void properties();

	virtual HRESULT __stdcall GetWindow( HWND *phwnd);
    virtual HRESULT __stdcall ContextSensitiveHelp( BOOL fEnterMode);
    virtual HRESULT __stdcall InsertMenusSB(  HMENU hmenuShared, LPOLEMENUGROUPWIDTHS lpMenuWidths);
	virtual HRESULT __stdcall SetMenuSB( HMENU hmenuShared, HOLEMENU holemenuRes, HWND hwndActiveObject);
	virtual HRESULT __stdcall RemoveMenusSB( HMENU hmenuShared);
    virtual HRESULT __stdcall SetStatusTextSB( LPCWSTR pszStatusText);
    virtual HRESULT __stdcall EnableModelessSB( BOOL fEnable);
    virtual HRESULT __stdcall TranslateAcceleratorSB( MSG *pmsg,WORD wID);
    virtual HRESULT __stdcall BrowseObject( PCUIDLIST_RELATIVE pidl,UINT wFlags);
    virtual HRESULT __stdcall GetViewStateStream( DWORD grfMode,IStream **ppStrm);
    virtual HRESULT __stdcall GetControlWindow( UINT id, HWND *phwnd);
    virtual HRESULT __stdcall SendControlMsg( UINT id, UINT uMsg,  WPARAM wParam, LPARAM lParam, LRESULT *pret);
    virtual HRESULT __stdcall QueryActiveShellView( IShellView **ppshv);
    virtual HRESULT __stdcall OnViewWindowActive( IShellView *pshv);
    virtual HRESULT __stdcall SetToolbarItems( LPTBBUTTONSB lpButtons, UINT nButtons, UINT uFlags);
	virtual HRESULT __stdcall QueryService( REFGUID guidService, REFIID riid, void **ppv);
	virtual HRESULT __stdcall IncludeObject( IShellView *ppshv, LPCITEMIDLIST pidl );
	virtual HRESULT __stdcall OnDefaultCommand( IShellView *ppshv);
	virtual HRESULT __stdcall OnStateChange(IShellView *ppshv, ULONG uChange);
	virtual HRESULT __stdcall GetDefaultMenuText( IShellView *pshv, WCHAR *pszText, int cchMax);
	virtual HRESULT __stdcall GetViewFlags( DWORD *pdwFlags );
	virtual HRESULT __stdcall Notify( IShellView *pshv, DWORD dwNotifyType);
	virtual HRESULT __stdcall DoContextMenuPopup( IUnknown *punkContextMenu, UINT fFlags, POINT pt);

	HWND viewWnd_;


	virtual void OnUserSelect(std::vector<mol::string>& v) {};
	virtual void OnPathChanged(const mol::string& p) {};

protected:

	bool showPath( const mol::string& path);

	mol::punk<IShellView> sv_;
	mol::string path_;
	bool displayFiles_;
};

} // end namespace ole  
} // end namespace mol  


#endif
