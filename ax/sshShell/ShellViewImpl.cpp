#include "StdAfx.h"
#include "ShellViewImpl.h"

#include "ShellViewImpl.h"
#include "ExtractIcon.h"
#include "resource.h"
#include <Shlwapi.h>
#include <windowsx.h>
#include "win/file.h"
#include "win/dlg.h"
#include "credmgr.h"
#include <ShlObj.h>
bool ShellView::bViewKeys = false;

mol::ImageList imgageListLarge;
mol::ImageList imgageListSmall;


class HostDlg  : public mol::win::Dialog
{
public:

	HostDlg()
		:port(L"22")
	{}

	mol::string host;
	mol::string port;

	virtual LRESULT wndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message)
		{
			case WM_INITDIALOG:
			{
				setDlgItemText(IDC_EDIT_HOST,host.c_str());
				setDlgItemText(IDC_EDIT_PORT,port);
				::SetFocus(getDlgItem(IDC_EDIT_HOST));
				this->center();
				this->setForeGround();
				return FALSE; // note: false! look into PSDK!
			}
			case WM_COMMAND:
			{
				if (LOWORD(wParam) == IDOK )
				{
					getDlgItemText(IDC_EDIT_HOST,host);
					getDlgItemText(IDC_EDIT_PORT,port);
					endDlg(LOWORD(wParam));
					return FALSE;
				}
				if (LOWORD(wParam) == IDCANCEL )
				{
					endDlg(LOWORD(wParam));
					return FALSE;
				}
			}
		}
		return mol::win::Dialog::wndProc(hDlg, message, wParam, lParam);
	}

	mol::string server()
	{
		return host + L":" + port;
	}

};



ShellView::ShellView()
	:pidl_(0)
{
	deleteOnNCDestroy_ = false;
	InitCommonControls();

	uState_ = 0;
}


ShellView::~ShellView()
{
	if(pidl_)
	{
		pidlManager().destroy(pidl_);
		pidl_ = NULL;
	}
}


ShellView::Instance* ShellView::createInstance(IShellFolder* pFolder,LPCITEMIDLIST pidl)
{
	Instance* instance = new Instance;
	instance->parentFolder_ = pFolder;
	instance->pidl_ = pidlManager().copy(pidl);
	return instance;
}


HRESULT __stdcall ShellView::GetWindow(HWND *phWnd)
{
	*phWnd = hWnd_;
	return S_OK;
}

HRESULT __stdcall ShellView::ContextSensitiveHelp(BOOL fEnterMode)
{
	return E_NOTIMPL;
}

// IOleCommandTarget Implementation

HRESULT __stdcall ShellView::QueryStatus( const GUID *pguidCmdGroup, ULONG cCmds, OLECMD prgCmds[], OLECMDTEXT *pCmdText)
{
	// TODO: do something useful here

	ULONG i;

	//only process the commands for our command group
	if(pguidCmdGroup && (*pguidCmdGroup != CLSID_CmdGrp))
	   return OLECMDERR_E_UNKNOWNGROUP;


	//make sure prgCmds is not NULL
	if(!prgCmds)
	   return E_POINTER;

	/*
	if ( pguidCmdGroup == 0 )
	{
		for(i = 0; i < cCmds;i++)
		{
			switch(prgCmds[i].cmdID)
			{
				case OLECMDID_COPY:
				case OLECMDID_PASTE:
				case OLECMDID_DELETE:
				case OLECMDID_OPEN:
				case OLECMDID_REFRESH:
				{
					prgCmds[i].cmdf = OLECMDF_SUPPORTED | OLECMDF_ENABLED;
					break;
				}
			}
		}
		return S_OK;
	}
	*/

	//run through all of the commands and supply the correct information
	for(i = 0; i < cCmds;i++)
	{
		switch(prgCmds[i].cmdID)
		{
			case IDM_VIEW_KEYS:
			{
				prgCmds[i].cmdf = OLECMDF_SUPPORTED | OLECMDF_ENABLED;
				break;
			}
		}
	}

	return S_OK;
}


HRESULT __stdcall ShellView::Exec( const GUID *pguidCmdGroup, DWORD nCmdID, DWORD nCmdExecOpt, VARIANTARG *pvaIn, VARIANTARG *pvaOut)
{
	
	//only process the commands for our command group
	if(pguidCmdGroup && (*pguidCmdGroup == CLSID_CmdGrp))
	{
		OnCommand(nCmdID, 0, NULL);
		return S_OK;
	}

	if ( !pguidCmdGroup  || (*pguidCmdGroup == CGID_Explorer) )
	{
		if ( nCmdID == OLECMDID_REFRESH )
		{
			invalidateViewModel(this->pidl_);
			this->Refresh();
		}
		if ( nCmdID == OLECMDID_DELETE )
		{
			::MessageBox(0,L"Delete",L"menu",0);
			this->Refresh();
		}
		if ( nCmdID == OLECMDID_COPY )
		{
			::MessageBox(0,L"Copy",L"menu",0);
			this->Refresh();
		}
	}

	return OLECMDERR_E_UNKNOWNGROUP;
}

// IShellView Implementation

HRESULT __stdcall ShellView::TranslateAccelerator(LPMSG pMsg)
{
	return E_NOTIMPL;
}

HRESULT __stdcall ShellView::EnableModeless(BOOL fEnable)
{
	return E_NOTIMPL;
}

HRESULT __stdcall ShellView::Refresh(void)
{
	//empty the list
	clearList();

	//refill the list
	fillList();

	return S_OK;
}

HRESULT __stdcall ShellView::CreateViewWindow( LPSHELLVIEW pPrevView, LPCFOLDERSETTINGS lpfs, LPSHELLBROWSER psb, LPRECT prcView, HWND *phWnd)
{
	*phWnd = NULL;

	//set up the member variables
	shellBrowser_   = psb;
	folderSettings_ = *lpfs;

	//get our parent window
	shellBrowser_->GetWindow(&hwndParent_);

	mol::Rect r(prcView->left,prcView->top,prcView->right - prcView->left,prcView->bottom - prcView->top);
	*phWnd = this->createWindow(_T(""),0,r,hwndParent_);

	if(!*phWnd)
		return E_FAIL;

	return S_OK;
}

HRESULT __stdcall ShellView::DestroyViewWindow(void)
{
	//Make absolutely sure all our UI is cleaned up.
	UIActivate(SVUIA_DEACTIVATE);

	if(hMergeMenu_)
	   ::DestroyMenu(hMergeMenu_);

	::DestroyWindow(hWnd_);

	//release the shell browser object
	shellBrowser_.release();

	return S_OK;
}

HRESULT __stdcall ShellView::GetCurrentInfo(LPFOLDERSETTINGS lpfs)
{
	*lpfs = folderSettings_;
	return S_OK;
}

HRESULT __stdcall ShellView::AddPropertySheetPages( DWORD dwReserved, LPFNADDPROPSHEETPAGE lpfn, LPARAM lParam)
{
	return E_NOTIMPL;
}

HRESULT __stdcall ShellView::SaveViewState(void)
{
	return S_OK;
}

HRESULT __stdcall ShellView::SelectItem(LPCITEMIDLIST pidlItem, UINT uFlags)
{
	return E_NOTIMPL;
}

HRESULT __stdcall ShellView::GetItemObject(UINT uItem, REFIID riid, LPVOID *ppvOut)
{
	*ppvOut = NULL;
	return E_NOTIMPL;
}



HRESULT __stdcall ShellView::UIActivate(UINT uState)
{
	//don't do anything if the state isn't really changing
	//if(uState_ == uState)
	//	return S_OK;

	//Activate handles the menu merging and internal state
	activate(uState);

	//only do this if we are active
	if(uState != SVUIA_DEACTIVATE)
	{
	   LRESULT  lResult;
	   int      nPartArray[1] = {-1};
     
	   std::wstring s(L"ssh://");
	   s += pidlManager().getPidlPath(pidl_);
	   
		//set the number of parts
		shellBrowser_->SendControlMsg(FCW_STATUS, SB_SETPARTS, 1, (LPARAM)nPartArray, &lResult);

		//set the text for the parts
		shellBrowser_->SendControlMsg(FCW_STATUS, SB_SETTEXT, 0, (LPARAM)(s.c_str()), &lResult);
	}
	return S_OK;
}

LRESULT ShellView::activate(UINT uState)
{
	//don't do anything if the state isn't really changing
	//if(uState_ == uState)
	//	return S_OK;

	deactivate(uState);

	//only do this if we are active
	if(uState != SVUIA_DEACTIVATE)
	//if(uState == SVUIA_ACTIVATE_FOCUS)
	{
		//merge the menus
		hMergeMenu_ = ::CreateMenu();
		if( hMergeMenu_ )
		{
   			OLEMENUGROUPWIDTHS   omw = {0, 0, 0, 0, 0, 0};
			MENUITEMINFO         mii;

			shellBrowser_->InsertMenusSB(hMergeMenu_, &omw);

			//build the top level menu
			mol::string txt(_T("SSH"));
      
			::ZeroMemory(&mii, sizeof(mii));
			mii.cbSize = sizeof(mii);
			mii.fMask = MIIM_SUBMENU | MIIM_TYPE | MIIM_STATE;
			mii.fType = MFT_STRING;
			mii.fState = MFS_ENABLED;
			mii.dwTypeData = (LPWSTR)txt.c_str();
			mii.hSubMenu = buildSSHMenu();

			//insert our menu into the menu bar
			if(mii.hSubMenu)
			{
				::InsertMenuItem(hMergeMenu_, FCIDM_MENU_HELP, FALSE, &mii);
			}

			//get the view menu so we can merge with it
			ZeroMemory(&mii, sizeof(mii));
			mii.cbSize = sizeof(mii);
			mii.fMask = MIIM_SUBMENU;
      
			if(::GetMenuItemInfo(hMergeMenu_, FCIDM_MENU_VIEW, FALSE, &mii))
			{
				mergeViewMenu(mii.hSubMenu);
			}

			//add the items that should only be added if we have the focus
			//if(SVUIA_ACTIVATE_FOCUS == uState)
			{
				//get the file menu so we can merge with it
				ZeroMemory(&mii, sizeof(mii));
				mii.cbSize = sizeof(mii);
				mii.fMask = MIIM_SUBMENU;
      
				if(GetMenuItemInfo(hMergeMenu_, FCIDM_MENU_FILE, FALSE, &mii))
				{
					mergeFileMenu(mii.hSubMenu);
				}
			}

			shellBrowser_->SetMenuSB(hMergeMenu_, NULL, hWnd_);
		}
	}

	uState_ = uState;
	return 0;
}

LRESULT ShellView::deactivate(UINT state)
{
	if(1)//uState_ != SVUIA_DEACTIVATE )//&& state == SVUIA_DEACTIVATE )
	{
		if(hMergeMenu_)
		{
			shellBrowser_->SetMenuSB(NULL, NULL, NULL);
			shellBrowser_->RemoveMenusSB(hMergeMenu_);
			::DestroyMenu(hMergeMenu_);
			hMergeMenu_ = NULL;
		}
   }
	uState_ = state;
	return 0;
}

HMENU ShellView::buildSSHMenu()
{
	HMENU hSubMenu = ::CreatePopupMenu();
	if(hSubMenu)
	{
	   MENUITEMINFO   mii;      
       ::ZeroMemory(&mii, sizeof(mii));
       mii.cbSize = sizeof(mii);
       mii.fMask = MIIM_TYPE | MIIM_ID | MIIM_STATE;
       mii.fType = MFT_STRING;
       mii.fState = MFS_ENABLED;


       mii.dwTypeData = _T("SSH menu item");
       mii.wID = IDM_VIEW_KEYS;

	   ::InsertMenuItem(hSubMenu, (UINT)-1, TRUE, &mii);      
	}
	return hSubMenu;
}

void ShellView::mergeFileMenu(HMENU hSubMenu)
{
    if(!hSubMenu)
		return;

	MENUITEMINFO   mii;
	::ZeroMemory(&mii, sizeof(mii));

	//add a separator
	mii.cbSize = sizeof(mii);
	mii.fMask = MIIM_TYPE | MIIM_ID | MIIM_STATE;
	mii.fType = MFT_SEPARATOR;
	mii.fState = MFS_ENABLED;

	::InsertMenuItem(hSubMenu, 0, TRUE, &mii);

	//add file menu items
	mii.fMask = MIIM_TYPE | MIIM_ID | MIIM_STATE;
	mii.fType = MFT_STRING;
	mii.fState = MFS_ENABLED;
	mii.dwTypeData = _T("Connect to SSH Server");
	mii.wID = IDM_CONNECT_SSH;

	::InsertMenuItem(hSubMenu, 0, TRUE, &mii);

	mii.fMask = MIIM_TYPE | MIIM_ID | MIIM_STATE;
	mii.fType = MFT_STRING;
	mii.fState = MFS_ENABLED;
	mii.dwTypeData = _T("Make Directory");
	mii.wID = IDM_MKDIR;

	::InsertMenuItem(hSubMenu, 0, TRUE, &mii);
}

void ShellView::mergeViewMenu(HMENU hSubMenu)
{
	if(!hSubMenu)
		return;

	MENUITEMINFO   mii;
	::ZeroMemory(&mii, sizeof(mii));

	mii.cbSize = sizeof(mii);
	mii.fMask = MIIM_TYPE | MIIM_ID | MIIM_STATE;
	mii.fType = MFT_SEPARATOR;
	mii.fState = MFS_ENABLED;
	::InsertMenuItem(hSubMenu, FCIDM_MENU_VIEW_SEP_OPTIONS, FALSE, &mii);

	//add view menu items
	mii.fMask = MIIM_TYPE | MIIM_ID | MIIM_STATE;
	mii.fType = MFT_STRING;
	mii.fState = MFS_ENABLED;
	mii.dwTypeData = _T("SSH ViewMenu1");
	mii.wID = IDM_VIEW_KEYS;
	::InsertMenuItem(hSubMenu, FCIDM_MENU_VIEW_SEP_OPTIONS, FALSE, &mii);
}

LRESULT ShellView::command(DWORD dwCmdID, DWORD dwCmd, HWND hwndCmd)
{
	switch(dwCmdID)
	{
		case IDM_MKDIR:
		{
			try {
				mol::ssh::Session ssh;
				std::wstring host = pidlManager().getSftpServerName(pidl_);
				int port = pidlManager().getSftpServerPort(pidl_);
				ssh.open( mol::toUTF8(host), &credentialManager().credentials, port );

				mol::sftp::Session sftp(ssh);
				std::wstring path = pidlManager().getSftpPath(pidl_);
				path += L"/new_dir";
				sftp.mkdir(path,0700);
			}
			catch( mol::ssh::Ex& ex)
			{
				ODBGS(ex.msg());
			}
			invalidateViewModel(this->pidl_);
			Refresh();
			break;
		}

		case IDM_CONNECT_SSH:
		{
			HostDlg dlg;
			if ( IDOK == dlg.doModal(IDD_SCP_SERVER_DIALOG, *this ))
			{
				viewModelRootFactory()->server.push_back(dlg.server());
				this->Refresh();
				
			}
			break;
		}
		case IDM_REFRESH :
		{
			this->Refresh();
			break;
		}
	}

return 0;
}

LRESULT ShellView::OnCommand(UINT msg, WPARAM wParam, LPARAM lParam)
{
    return command( GET_WM_COMMAND_ID(wParam, lParam), 
                    GET_WM_COMMAND_CMD(wParam, lParam), 
                    GET_WM_COMMAND_HWND(wParam, lParam));
}

LRESULT ShellView::OnActivate()
{
	return activate(SVUIA_ACTIVATE_FOCUS);
}

LRESULT ShellView::OnSetFocus(void)
{
	/*
	Tell the browser one of our windows has received the focus. This should always 
	be done before merging menus (OnActivate merges the menus) if one of our 
	windows has the focus.
	*/
	shellBrowser_->OnViewWindowActive(this);

	activate(SVUIA_ACTIVATE_FOCUS);

	return 0;
}


LRESULT ShellView::OnKillFocus(void)
{
	activate(SVUIA_ACTIVATE_NOFOCUS);
	return 0;
}


LRESULT ShellView::OnUpdateMenu(HMENU hMenu, LPARAM unused)
{
	//TODO: do something useful here
	::CheckMenuItem(hMenu, IDM_VIEW_KEYS, MF_BYCOMMAND | (bViewKeys ? MF_CHECKED: MF_UNCHECKED));
	::EnableMenuItem(hMenu, IDM_VIEW_IDW, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
	::CheckMenuItem(hMenu, IDM_VIEW_IDW, MF_BYCOMMAND | MF_UNCHECKED);
	return 0;
}

void ShellView::OnDeactivate()
{
	deactivate(SVUIA_DEACTIVATE);
}

void ShellView::OnEndTrack()
{
	//g_nColumn1 = ListView_GetColumnWidth(m_hwndList, 0);
	//g_nColumn2 = ListView_GetColumnWidth(m_hwndList, 1);
}

void ShellView::OnDeleteItem(UINT CtlID, LPNMHDR lpnmh)
{
	NM_LISTVIEW *lpnmlv = (NM_LISTVIEW*)lpnmh;
      
	//delete the pidl because we made a copy of it
	pidlManager().destroy((LPITEMIDLIST)lpnmlv->lParam);
}


void ShellView::OnActivateItem(UINT CtlID, LPNMHDR lpnmh)
{
	LPNMLISTVIEW   lpnmlv = (LPNMLISTVIEW)lpnmh;
	LPITEMIDLIST pidl = (LPITEMIDLIST)list_.getItemLPARAM(lpnmlv->iItem);
	if(pidlManager().isDir(pidl))
	{
		shellBrowser_->BrowseObject( pidl, SBSP_DEFBROWSER | SBSP_RELATIVE);
	}
}

void ShellView::OnContextMenu()
{
	int index = list_.hitTest();
	if ( index == -1 )
	{
		mol::Menu ctxMenu;
		ctxMenu.createContext();
		ctxMenu.addItem( IDM_PASTE, _T("Paste") );

		POINT pt;
		::GetCursorPos(&pt);
		ctxMenu.trackPopup(*this,pt.x,pt.y);
		return;
	}

	LPITEMIDLIST pidl = (LPITEMIDLIST)list_.getItemLPARAM(index);
	if ( pidlManager().isDir(pidl) )
	{
		mol::Menu menu;
		menu.createContext();

		mol::punk<IContextMenu> ctxMenu;
		HRESULT hr = getUIObjectOf( parentFolder_, pidl, &ctxMenu );
		if ( hr != S_OK || !ctxMenu )
			return;

		hr = ctxMenu->QueryContextMenu( menu, 0, 1, 100, 0 );

		POINT pt;
		::GetCursorPos(&pt);
		UINT cmd = menu.returnTrackPopup(*this,pt.x,pt.y);

		if ( cmd )
		{
			cmd -= 1;
			CMINVOKECOMMANDINFO ici;
			::ZeroMemory(&ici,sizeof(CMINVOKECOMMANDINFO));
			ici.cbSize = sizeof(CMINVOKECOMMANDINFO);
			ici.lpVerb = (LPCSTR)cmd;
			ctxMenu->InvokeCommand( &ici );	
		}

		return;
		/*
		mol::Menu ctxMenu;
		ctxMenu.createContext();
		ctxMenu.addItem( OPEN+1, _T("Open") );
		ctxMenu.addItem( CUT+1, _T("Cut") );
		ctxMenu.addItem( COPY+1, _T("Copy") );
		ctxMenu.addItem( PASTE+1, _T("Paste") );
		ctxMenu.addItem( ERASE+1, _T("Delete") );

		POINT pt;
		::GetCursorPos(&pt);
		UINT cmd = ctxMenu.returnTrackPopup(*this,pt.x,pt.y);
		if ( cmd != 0 )
			invokeContextMenuCmd(pidl,(SFContextMenuCommand)(cmd-1));
		return;
		*/
	}

	// file
	mol::Menu ctxMenu;
	ctxMenu.createContext();
	ctxMenu.addItem( CUT+1, _T("Cut") );
	ctxMenu.addItem( COPY+1, _T("Copy") );
	ctxMenu.addItem( PASTE+1, _T("Paste") );
	ctxMenu.addItem( ERASE+1, _T("Delete") );

	POINT pt;
	::GetCursorPos(&pt);
	UINT cmd = ctxMenu.returnTrackPopup(*this,pt.x,pt.y);
	if ( cmd != 0 )
		invokeContextMenuCmd(pidl,(SFContextMenuCommand)(cmd-1));
}

HRESULT ShellView::getUIObjectOf( IShellFolder* parent, LPCITEMIDLIST pidl, IContextMenu** ctxMenu)
{
	HRESULT hr = parent->GetUIObjectOf( *this, 1, &pidl, IID_IContextMenu, 0, (void**)ctxMenu );
	if ( hr != S_OK )
		return hr;

	if ( shellBrowser_ )
	{
		mol::punk<IObjectWithSite> site;
		hr = (*ctxMenu)->QueryInterface(IID_IObjectWithSite, (void**)&site);
		if ( hr != S_OK || !site)
			return hr;

		site->SetSite( shellBrowser_ );
	}

	return hr;
}

/*
void invokeContextMenuCmd( IContextMenu* ctxMenu, SFContextMenuCommand cmd )
{
	CMINVOKECOMMANDINFO ici;
	::ZeroMemory(&ici,sizeof(CMINVOKECOMMANDINFO));
	ici.cbSize = sizeof(CMINVOKECOMMANDINFO);
	ici.lpVerb = (LPCSTR)cmd;
	ctxMenu->InvokeCommand( &ici );	
}
*/
void ShellView::invokeContextMenuCmd( LPITEMIDLIST pidl, SFContextMenuCommand cmd )
{
	mol::punk<IContextMenu> ctxMenu;
	HRESULT hr = getUIObjectOf( parentFolder_, pidl, &ctxMenu );
	if ( hr != S_OK || !ctxMenu )
		return;

	CMINVOKECOMMANDINFO ici;
	::ZeroMemory(&ici,sizeof(CMINVOKECOMMANDINFO));
	ici.cbSize = sizeof(CMINVOKECOMMANDINFO);
	ici.lpVerb = (LPCSTR)cmd;
	ctxMenu->InvokeCommand( &ici );	
}

void ShellView::OnPaste()
{
	invokeContextMenuCmd(0,PASTE);

	invalidateViewModel(pidl_);
	//Refresh();

	/*
	mol::punk<IContextMenu> ctxMenu;
	HRESULT hr = getUIObjectOf( parentFolder_, 0, &ctxMenu );
	if ( hr != S_OK || !ctxMenu )
		return;

	invokeContextMenuCmd(ctxMenu,SFContextMenuCommand::PASTE);
	/*
	mol::punk<IContextMenu> ctxMenu;
	HRESULT hr = parentFolder_->GetUIObjectOf( *this, 1, &pidl_, IID_IContextMenu, 0, (void**)&ctxMenu );
	if ( hr != S_OK || !ctxMenu )
		return;

	CMINVOKECOMMANDINFO ici;
	::ZeroMemory(&ici,sizeof(CMINVOKECOMMANDINFO));
	ici.cbSize = sizeof(CMINVOKECOMMANDINFO);
	ici.lpVerb = (LPCSTR)SFContextMenuCommand::PASTE;
	ctxMenu->InvokeCommand( &ici );
	*/

}

LRESULT ShellView::OnSize(WPARAM wParam, LPARAM lParam)
{
	//resize the ListView to fit our window
	if ( list_ )
	{
		list_.move(0,0,LOWORD(lParam),HIWORD(lParam), TRUE);
	}
	return 0;
}

LRESULT ShellView::OnCreate(void)
{
	bool isRoot = pidlManager().isRoot(pidl_);
	std::wstring s = pidlManager().getPidlPath(pidl_);

	mol::string sshFolder = mol::io::desktop().getDisplayNameOf(pidl_);

	//create the ListView
	if(createList())
	{
		if(initList())
		{
			fillList();
		}
	}
	return 0;
}

bool ShellView::createList()
{
	list_.create( (HMENU)ID_LISTVIEW, mol::stdRect, *this);
	return true;
}

void ShellView::clearList()
{
	int index = list_.getNextItem(-1,0);
	while( index != -1 )
	{
		LPITEMIDLIST pidl = (LPITEMIDLIST)list_.getItemLPARAM(index);
		pidlManager().destroy(pidl);
		index = list_.getNextItem(index,0);
	}

	list_.deleteAllItems();
}

bool ShellView::initList()
{
	clearList();

	if (  pidlManager().isRoot(pidlManager().getLastItem(pidl_)) )
	{
		list_.insertColumn( _T("Server"), 0 );
		list_.insertColumn( _T("Port"), 1 );
	}
	else
	{
		list_.insertColumn( _T("Name"), 0 );
		list_.insertColumn( _T("Size"), 1 );
		list_.insertColumn( _T("Owner"), 2 );
		list_.insertColumn( _T("Group"), 3 );
		list_.insertColumn( _T("Permissions"), 4 );
	}

	ListView_SetImageList(list_, imgageListSmall, LVSIL_SMALL);

	return true;
}

int CALLBACK compareItems(LPARAM lParam1, LPARAM lParam2, LPARAM lpData)
{
	IShellFolder* pFolder = (IShellFolder*)lpData;
	if(!pFolder)
		return 0;

	return (int)pFolder->CompareIDs(0, (LPITEMIDLIST)lParam1, (LPITEMIDLIST)lParam2);
}

void ShellView::insertItem( mol::sftp::RemoteFile& file ) 
{
	LPITEMIDLIST pidl;
	int icon = ICON_INDEX_FOLDER;
	std::wstring size(L"Directory");
	if ( file.isDir() )
	{
		pidl = pidlManager().createSftpPath(file.getName());
	}
	else
	{
		pidl = pidlManager().createSftpFile(file.getName());
		icon = ICON_INDEX_STRING;
		size = file.formattedSize();
	}

	int index = list_.getItemCount();
	list_.insertItem( file.getName(), index, 0,icon, (LPARAM)pidl);
	list_.insertSubItem(size, index,0);
	list_.insertSubItem( file.getOwner(), index,1);
	list_.insertSubItem( file.getGroup(), index,2);
	list_.insertSubItem( file.formattedPermissions(), index,3);
}

void ShellView::fillList(void)
{
	list_.setRedraw(false);

	bool isRoot = pidlManager().isRoot(pidlManager().getLastItem(pidl_));

	if ( isRoot )
	{
		ViewModel* viewModel = viewModelRootFactory();

		for ( size_t i = 0; i < viewModel->server.size(); i++ )
		{
			std::wstring host = viewModel->server[i];
			std::vector<std::wstring> v = mol::split(host,L":");
			LPITEMIDLIST pidl = pidlManager().createSftpServer(host);
			int index = list_.getItemCount();
			list_.insertItem( v[0], index, 0, ICON_INDEX_BINARY, (LPARAM)pidl);
			list_.insertSubItem(v[1], index,0);
		}
		list_.setRedraw(true);
		list_.invalidateRect(0,TRUE);
		list_.update();
		return;
	}

	ViewModel* viewModel = viewModelPathFactory(pidl_);

	if ( viewModel )
	{
		for ( size_t i = 0; i < viewModel->files.size(); i++ )
		{
			mol::sftp::RemoteFile& file = viewModel->files[i];
			insertItem(file);
		}
	}

	//sort the items
	ListView_SortItems(list_, compareItems, (LPARAM)parentFolder_.interface_);
   
	list_.setRedraw(true);
	list_.invalidateRect(0,TRUE);
	list_.update();
}
