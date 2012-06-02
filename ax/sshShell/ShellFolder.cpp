#include "StdAfx.h"
#include "ShellFolder.h"

#include "ShellViewImpl.h"
#include "InfoTip.h"
#include "ExtractIcon.h"
#include "resource.h"
#include <sstream>
#include <string>
#include <vector>
#include "credmgr.h"
#include "ole/dataobj.h"
#include "ole/dragdrop.h"
#include "ssh/scpDataTransferObj.h"

LPITEMIDLIST rootPidl;

std::vector<std::wstring> vectorFromSshDataObj(IDataObject* dataObj)
{
	std::vector<std::wstring> v;

	if(!dataObj)
		return v;

	mol::format_etc fe( mol::scp::cfstr_isSShData() );

//	FILEGROUPDESCRIPTOR

//	format_etc_dropfile			fe;
	STGMEDIUM					sm;

	HRESULT hr = dataObj->GetData( &fe, &sm );
	if (hr != S_OK )
		return v;

	if ( sm.tymed != TYMED_HGLOBAL )
	{
		::ReleaseStgMedium(&sm);
		return v;
	}

	mol::global glob( sm.hGlobal );

	HDROP hDrop = (HDROP)glob.lock();

	if ( hDrop)
	{
		int n   = ::DragQueryFile( hDrop, 0xFFFFFFFF,0,0);
		int i = 0;
		while(true)
		{
			int len = ::DragQueryFile( hDrop, i, 0, 0 );
			if (!len )
				break;
			mol::TCHAR* fname = new mol::TCHAR[len+1];
			::DragQueryFile( hDrop, i, fname, len+1 );
			v.push_back(fname);
			delete[] fname;
			i++;
		}
		glob.unLock();
	}

	glob.detach();

	::ReleaseStgMedium(&sm);
	return v;
}

void RefreshFolderViews()
{
    LPCITEMIDLIST pidl = pidlManager().getRootPidl();
    if (pidl)
    {
        SHChangeNotify(SHCNE_UPDATEDIR, SHCNF_IDLIST, pidl, 0);
    }
}

HRESULT GetShellBrowser( IUnknown* site,  IShellBrowser** pShellBrowser)
{
	*pShellBrowser = 0;
	if (!site)
		return E_UNEXPECTED;

	mol::punk<IServiceProvider> sp(site);
	if (sp)
	{
		return sp->QueryService( SID_SShellBrowser, pShellBrowser );
	}

	return site->QueryInterface(IID_IShellBrowser, (void**)pShellBrowser);
}


SFContextMenu::SFContextMenu()
	:pidl_(0),idCmdFirst_(0)
{
	map_.insert( std::make_pair(OPEN,L"Open") );
	map_.insert( std::make_pair(CUT,L"Cut") );
	map_.insert( std::make_pair(COPY,L"Copy") );
	map_.insert( std::make_pair(PASTE,L"Paste") );
	map_.insert( std::make_pair(REFRESH,L"Refresh") );
	map_.insert( std::make_pair(ERASE,L"Delete") );
}

SFContextMenu::~SFContextMenu()
{}

SFContextMenu::Instance* SFContextMenu::createInstance(IShellFolder* parent, LPCITEMIDLIST pidl)
{
	Instance* instance = new Instance;
	instance->parentFolder_ = parent;
	instance->pidl_ = pidlManager().copy(pidl);
	return instance;
}

void SFContextMenu::dispose() 
{
	if ( pidl_ )
	{
		pidlManager().destroy(pidl_);
		pidl_ = 0;
	}
	site_.release();
}

void SFContextMenu::registerMenuCmd(SFContextMenuCommand cmd, HMENU hmenu, UINT& indexMenu, UINT& idCmd) 
{
	cmds_.push_back(cmd);
	::InsertMenu(hmenu,indexMenu,MF_BYPOSITION,idCmd,map_[cmd].c_str());
	indexMenu++;
	idCmd++;
}

HRESULT __stdcall  SFContextMenu::QueryContextMenu( HMENU hmenu, UINT indexMenu, UINT idCmdFirst, UINT idCmdLast, UINT uFlags)
{
	cmds_.clear();

	UINT idCmd = idCmdFirst;
	idCmdFirst_ = idCmd;

	registerMenuCmd( OPEN, hmenu,indexMenu, idCmd);
	registerMenuCmd( CUT, hmenu,indexMenu, idCmd);
	registerMenuCmd( COPY, hmenu,indexMenu, idCmd);
	registerMenuCmd( PASTE, hmenu,indexMenu, idCmd);
	registerMenuCmd( REFRESH, hmenu,indexMenu, idCmd);
	registerMenuCmd( ERASE, hmenu,indexMenu, idCmd);

	/*
	::InsertMenu(hmenu,indexMenu,MF_BYPOSITION,idCmd,L"Open");
	indexMenu++;
	idCmd++;

	::InsertMenu(hmenu,indexMenu,MF_BYPOSITION,idCmd,L"Cut");
	indexMenu++;
	idCmd++;

	::InsertMenu(hmenu,indexMenu,MF_BYPOSITION,idCmd,L"Copy");
	indexMenu++;
	idCmd++;

	::InsertMenu(hmenu,indexMenu,MF_BYPOSITION,idCmd,L"Paste");
	indexMenu++;
	idCmd++;

	::InsertMenu(hmenu,indexMenu,MF_BYPOSITION,idCmd,L"Refresh");
	indexMenu++;
	idCmd++;
	*/
	return MAKE_HRESULT(SEVERITY_SUCCESS, 0, idCmd-idCmdFirst);
}

void SFContextMenu::OnNavigate2(LPITEMIDLIST pidl)
{
	if ( OnUpdate(pidl) )
		return;

	std::wstring tmp(L"explorer.exe /select,ssh://");
	tmp += pidlManager().getPidlPath(pidl);
	mol::io::exec_cmdline(tmp);
}
     
bool SFContextMenu::OnUpdate(LPITEMIDLIST pidl)
{
	//RefreshFolderViews();
	mol::punk<IShellBrowser> sb;
	GetShellBrowser(site_,&sb);
	if ( sb )
	{
		//LPITEMIDLIST absolutePidl = pidlManager().concat(pidlManager().getRootPidl(),pidl);

		if ( pidl )
		{
			LPITEMIDLIST relativePidl = pidlManager().getLastItem(pidl);
			sb->BrowseObject( relativePidl, SBSP_DEFBROWSER | SBSP_RELATIVE );
		}
		else 
		{
			sb->BrowseObject( 0, SBSP_DEFBROWSER | SBSP_RELATIVE );
		}
		return true;
	}
	return false;
}

HRESULT __stdcall  SFContextMenu::InvokeCommand(  CMINVOKECOMMANDINFO *pici)
{

	CMINVOKECOMMANDINFOEX* piciEx = (CMINVOKECOMMANDINFOEX*)pici;
	if ( pici )
	{
		if ( HIWORD(pici->lpVerb) == 0 )
		{
			std::wstring p = pidlManager().getPidlPath(pidl_);

			int c = (int)(pici->lpVerb);
			SFContextMenuCommand cmd = (SFContextMenuCommand)c;
			if ( !cmds_.empty() ) 
			{
				cmd = cmds_[c];
			}

			switch(cmd)
			{
				case OPEN :
				{
					::MessageBox(0,p.c_str(),L"ctx",0);
					OnNavigate2(pidl_);
					break;
				}
				case CUT:
				{
					::MessageBox(0,L"Cut",L"ctx",0);
					OnToClipboard(true);
					break;
				}
				case COPY:
				{
					::MessageBox(0,L"Copy",L"ctx",0);
					OnToClipboard(false);
					break;
				}
				case PASTE:
				{
					::MessageBox(0,L"Paste",L"ctx",0);
					OnPaste();
					invalidateViewModel(pidl_);
					OnUpdate(0);
					break;
				}
				case REFRESH:
				{
					::MessageBox(0,L"Refresh",L"ctx",0);

					invalidateViewModel(pidl_);
					OnUpdate(0);
					break;
				}
				case ERASE:
				{
					::MessageBox(0,L"Delete",L"ctx",0);

					OnDelete();
					//OnUpdate(0);
					break;
				}
			}
		}
	}
		
	return S_OK;
}
        
HRESULT __stdcall SFContextMenu::GetCommandString( UINT_PTR idCmd, UINT uFlags, UINT *pwReserved, LPSTR pszName, UINT cchMax )
{
	if ( uFlags & GCS_HELPTEXT )
	{
		if (uFlags & GCS_UNICODE)
		{
			if ( idCmd < cmds_.size() )
			{
				SFContextMenuCommand cmd = cmds_[idCmd];
				std::wstring s = mol::towstring(map_[cmd]);
				lstrcpynW((LPWSTR)pszName, s.c_str(), cchMax);
			}
		}
		else
		{
			if ( idCmd < cmds_.size() )
			{
				SFContextMenuCommand cmd = cmds_[idCmd];
				std::string s = mol::tostring(map_[cmd]);
				lstrcpynA((LPSTR)pszName, s.c_str(), cchMax);
			}
		}
	}
	return S_OK;
}

HRESULT __stdcall  SFContextMenu::GetSite( REFIID riid,void **ppvSite)
{
	*ppvSite = 0;
	if (site_)
	{
		return site_->QueryInterface(riid,(ppvSite));
	}
	return E_NOINTERFACE;
}

HRESULT __stdcall  SFContextMenu::SetSite(  IUnknown *pUnkSite)
{
	site_ = pUnkSite;
	return S_OK;
}

void SFContextMenu::OnToClipboard(bool cut)
{
	mol::punk<mol::com_obj<mol::scp::DelayedDataTransferObj> >ido  = 
		new mol::com_obj<mol::scp::DelayedDataTransferObj>;

	std::wstring host = pidlManager().getSftpServerName(pidl_);
	int port = pidlManager().getSftpServerPort(pidl_);

	ido->connect( mol::events::event_handler( &SFContextMenu::onCutOperation, this ), (IUnknown*)(IContextMenu*)this );
	ido->init(host,port,&credentialManager().credentials,cut);

	int size = 0;
	bool isDir = pidlManager().isDir(pidlManager().getLastItem(pidl_));
	std::wstring path = pidlManager().getSftpPath( pidl_);

	if ( isDir )
	{
		ido->add( path, size, isDir );
		::OleSetClipboard(ido);	
		return;
	}

	LPITEMIDLIST pidl = pidlManager().getParentItem(pidl_);
	ViewModel* vm = viewModelPathFactory(pidl);
	if(!vm)
		return;
	pidlManager().destroy(pidl);
	size = vm->remoteFile(pidlManager().getSftpFilename(pidl_))->getSize();
	
	ido->add( path, size, isDir );
	::OleSetClipboard(ido);	
	return;
}

void SFContextMenu::onCutOperation(IDataObject* dataObj)
{
	LPITEMIDLIST pidl = pidlManager().getParentItem(pidl_);

	invalidateViewModel(pidl);	

	pidlManager().destroy(pidl);
}

bool isMoveOperation(IDataObject* dataObj)
{
	if(!dataObj)
		return false;

	mol::format_etc_pref_dropeffect		fepDe;

	STGMEDIUM sm;
	HRESULT hr = dataObj->GetData( &fepDe, &sm );
	if ( hr != S_OK )
		return false;

	if ( sm.tymed != TYMED_HGLOBAL )
	{
		::ReleaseStgMedium(&sm);
		return false;
	}

	mol::global glob(sm.hGlobal);

	DWORD* eff = (DWORD*)glob.lock();

	bool ret = false;
	if ( eff && *eff == DROPEFFECT_MOVE )
		ret = true;
		
	glob.unLock();
	glob.detach();
	::ReleaseStgMedium(&sm);

	return ret;
}

void SFContextMenu::OnPaste()
{
	mol::punk<IDataObject> dataObj;
	HRESULT hr = ::OleGetClipboard(&dataObj);
	if ( hr != S_OK || !dataObj )
		return;

	bool isDir = pidlManager().isDir(pidlManager().getLastItem(pidl_));
	if (!isDir )
		return;

	std::vector<mol::string> files = mol::vectorFromDataObject(dataObj);

	if ( files.empty() )
	{
		files = vectorFromSshDataObj(dataObj);
		if ( files.empty() )
		{
			return;
		}

		try 
		{
			mol::ssh::Session ssh;

			std::wstring host = pidlManager().getSftpServerName(pidl_);
			int port = pidlManager().getSftpServerPort(pidl_);	
			ssh.open( mol::toUTF8(host),&credentialManager().credentials ,port);
			
			std::wstring path = pidlManager().getSftpPath( pidl_);

			for ( size_t i = 0; i < files.size(); i++ )
			{
				mol::Uri url( mol::toUTF8(files[i]) );

				std::wstring host2 = mol::toString(url.getHost());
				int port2 = url.getPort();

				if ( host != host2 )
					continue;

				if ( port != port2 )
					continue;

				std::wstring filename = mol::toString(url.getPath());

				std::wostringstream oss;

				if ( isMoveOperation(dataObj ) )
				{
//					mol::sftp::Session sftp(ssh);
//					sftp.rename( filename, newpath );
					oss << L"/bin/mv '";
				}
				else
				{					
					oss << L"/bin/cp -r '";
				}

				oss	<<  filename 
					<< L"' '" 
					<< path 
					<< L"'";

				ssh.exec_remote( mol::toUTF8(oss.str()) );			
			}

			mol::format_etc_dropeffect fe;
			STGMEDIUM sm;
			::ZeroMemory(&sm,sizeof(sm));
			sm.tymed = TYMED_HGLOBAL;

			DWORD effect = DROPEFFECT_MOVE;
			mol::global glob( effect);
			sm.hGlobal = glob;
			glob.detach();
			dataObj->SetData( &fe, &sm, TRUE );
		}
		catch(...)
		{
		}

		return;
	}

	try 
	{
		mol::ssh::Session ssh;

		std::wstring host = pidlManager().getSftpServerName(pidl_);
		int port = pidlManager().getSftpServerPort(pidl_);	
		ssh.open( mol::toUTF8(host),&credentialManager().credentials ,port);

		std::wstring path = pidlManager().getSftpPath( pidl_);

		bool isMove = isMoveOperation(dataObj );

		{
			mol::scp::Session scp(ssh);		
			scp.open(mol::SSH_SCP_WRITE|mol::SSH_SCP_RECURSIVE,path);


			for ( size_t i = 0; i < files.size(); i++ )
			{
				if ( !mol::Path::exists(files[i]))
					continue;

				if ( mol::Path::isDir(files[i]))
				{
					scp.push_dir( files[i], 0777 );
					continue;
				}
				scp.push_file( files[i], 0664 );

			}
		}

			mol::format_etc_dropeffect fe;
			STGMEDIUM sm;
			::ZeroMemory(&sm,sizeof(sm));
			sm.tymed = TYMED_HGLOBAL;

			DWORD effect = DROPEFFECT_MOVE;
			mol::global glob( effect);
			sm.hGlobal = glob;
			glob.detach();
			dataObj->SetData( &fe, &sm, TRUE );
	}
	catch(...)
	{
	}
}
/*
BOOL CALLBACK RefreshShellView( HWND hWnd, LPARAM lParam )
{
    if( hWnd ) 
    {
        TCHAR szClassName[MAX_PATH]=_T("");
        DWORD dwLen=MAX_PATH;
        GetClassName(hWnd,szClassName,dwLen);
        if( (_tcscmp(szClassName,_T("ExploreWClass"))==0) ||
            (_tcscmp(szClassName,_T("CabinetWClass"))==0) )
        {
            HWND hwndShellView = 
                FindWindowEx(hWnd,NULL,_T("NSFViewClass"),NULL);
            if(hwndShellView !=NULL)
            {           
                HWND hwndExcept =(HWND)lParam;
                if((hwndExcept!=NULL && hwndExcept!=hwndShellView) ||
                    (hwndExcept==NULL))
                    ::SendMessage(hwndShellView,WM_COMMAND,
                                               ID_VIEW_REFRESH,0);
            }
        }
    }
    return( TRUE );
}

void RefreshShellViewWndsExcept(HWND hwndExcept)
{
    // continue looping until done
    for(; !EnumWindows((WNDENUMPROC) RefreshShellView,
                              (LPARAM) hwndExcept ); ); 
}
*/

void SFContextMenu::OnDelete()
{
	try 
	{
		mol::ssh::Session ssh;

		std::wstring host = pidlManager().getSftpServerName(pidl_);
		int port = pidlManager().getSftpServerPort(pidl_);	
		ssh.open( mol::toUTF8(host),&credentialManager().credentials ,port);
		
		std::wstring path = pidlManager().getSftpPath( pidl_);

		mol::sftp::Session sftp(ssh);

		if ( pidlManager().isDir(pidl_) )
		{
			sftp.rmdir(path);

			//LPITEMIDLIST pidl = pidlManager().getParentItem(pidl_);
			//invalidateViewModel(pidl);
			//pidlManager().destroy(pidl);

			LPITEMIDLIST parentPidl = pidlManager().getParentItem(pidl_);
			invalidateViewModel(parentPidl);

			//LPITEMIDLIST absolutePidl = pidlManager().concat( pidlManager().getRootPidl(), pidl_ );
			//::SHChangeNotify(SHCNE_RMDIR,SHCNF_IDLIST|SHCNF_FLUSH, absolutePidl,0);
			//::SHChangeNotify(SHCNE_UPDATEDIR,SHCNF_IDLIST|SHCNF_FLUSH, parentPidl,0);
			//pidlManager().destroy(absolutePidl);
			pidlManager().destroy(parentPidl);



			mol::punk<IShellBrowser> sb;
			GetShellBrowser(site_,&sb);
			if ( sb )
			{
				mol::punk<IOleCommandTarget> oct;
				sb.queryInterface(&oct);
				if ( oct )
				{
					oct->Exec(0,OLECMDID_REFRESH,0,0,0);
				}
			}
			//RefreshShellViewWndsExcept(0);
			//pidlManager().destroy(parentPidl);
		}
		else
		{
			sftp.unlink(path);		
		}
	}
	catch(...)
	{
	}
}



class SFDropTarget : public mol::DropTarget
{
public:
	HRESULT __stdcall Drop( IDataObject* , DWORD , POINTL  , DWORD* )
	{
		::MessageBox(0,L"drop",L"sf-dt",0);
		return S_OK;
	}
};







ShellFolder::ShellFolder()
	: pidl_(0)
{}

ShellFolder::~ShellFolder()
{
	if(pidl_)
	{
		pidlManager().destroy(pidl_);
		pidl_ = NULL;
	}
}

void ShellFolder::dispose() 
{
	std::wstring s(L"ShellFolder::dispose");
}

ShellFolder::Instance* ShellFolder::createInstance(LPCITEMIDLIST pidl)
{
	Instance* instance = new Instance();
	instance->pidl_ = pidlManager().copy(pidl);
	return instance;
}


HRESULT __stdcall ShellFolder::GetClassID(LPCLSID lpClassID)
{
	*lpClassID = CLSID_sshShell;
	return S_OK;
}

HRESULT __stdcall ShellFolder::Initialize(LPCITEMIDLIST rootPidl)
{

	pidlManager().setSftpRoot(rootPidl);

	return S_OK;
}

// IShellFolder Implementation

HRESULT __stdcall ShellFolder::BindToObject( LPCITEMIDLIST relativePidl, LPBC pbcReserved, REFIID riid, LPVOID *ppvOut)
{
	*ppvOut = NULL;

	if ( ::IsEqualGUID(riid,IID_IShellFolder) && pidlManager().isDir(relativePidl))
	{
		LPITEMIDLIST pidl = pidlManager().concat( pidl_, relativePidl);

		//ViewModel* vm = viewModelPathFactory(pidl);
		//if (!vm )
			//return HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND);

		if ( !pidlManager().isServer(pidl) )
		{
			if (!validate(pidl))
			{
				return E_INVALIDARG;
			}
		}

		mol::punk<ShellFolder::Instance> shellFolder = ShellFolder::createInstance(pidl);
		if(!shellFolder)
		   return E_OUTOFMEMORY;

		HRESULT  hr = shellFolder->QueryInterface(riid, ppvOut);
		return hr;
	}

	
	if ( ::IsEqualGUID(riid,IID_IShellFolder2) && pidlManager().isDir(relativePidl))
	{
		LPITEMIDLIST pidl = pidlManager().concat( pidl_, relativePidl);

		if ( !pidlManager().isServer(pidl) )
		{
			if (!validate(pidl))
			{
				return E_INVALIDARG;
			}
		}

		mol::punk<ShellFolder::Instance> shellFolder = ShellFolder::createInstance(pidl);
		if(!shellFolder)
		   return E_OUTOFMEMORY;

		HRESULT  hr = shellFolder->QueryInterface(riid, ppvOut);
		return hr;
	}
	
	return E_NOINTERFACE;
}

HRESULT __stdcall ShellFolder::BindToStorage( LPCITEMIDLIST pidl, LPBC pbcReserved, REFIID riid, LPVOID *ppvOut)
{
	*ppvOut = NULL;
	return E_NOTIMPL;
}

HRESULT __stdcall ShellFolder::CompareIDs( LPARAM lParam, LPCITEMIDLIST pidl1, LPCITEMIDLIST pidl2)
{

	if ( pidlManager().isRoot(pidl1) || pidlManager().isRoot(pidl2) )
	{
		if ( pidlManager().isRoot(pidl1) && pidlManager().isRoot(pidl2) )
		{
			return 0;
		}
		if ( pidlManager().isRoot(pidl1) ) 
		{
			return 1;
		}
		return -1;
	}

	bool isDir1 = pidlManager().isDir(pidlManager().getLastItem(pidl1));
	bool isDir2 = pidlManager().isDir(pidlManager().getLastItem(pidl2));

	if ( isDir1 && !isDir2)
	{
		return -1;
	}
	if ( !isDir1 && isDir2)
	{
		return 1;
	}

	std::wstring s1 = pidlManager().getPidlPath(pidl1);
	std::wstring s2 = pidlManager().getPidlPath(pidl2);

	if(s1 != s2)
	{
	   return s1.compare(s2);
	}
	return 0;
}

HRESULT __stdcall ShellFolder::CreateViewObject( HWND hwndOwner, REFIID riid, LPVOID *ppvOut)
{
	HRESULT     hr = E_NOINTERFACE;
	*ppvOut = NULL;

	if ( !pidlManager().isServer(pidl_) )
	{
		if (!validate(pidl_))
		{
			return E_FAIL;//HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND);
		}
	}

	if ( ::IsEqualGUID(riid,IID_IShellView ))
	{
		mol::punk<IShellView> shellView = ShellView::createInstance(this,pidl_);
		if(!shellView)
			return E_OUTOFMEMORY;

		hr = shellView->QueryInterface(riid, ppvOut);
		return hr;
	}
	if(IsEqualIID(riid, IID_IExtractIcon))
	{
		mol::punk<IconExtractor::Instance> iconExtractor = IconExtractor::createInstance(pidl_);

		if ( iconExtractor )
		{
			return iconExtractor->QueryInterface(IID_IExtractIcon, ppvOut);
		}  
		return E_OUTOFMEMORY;
	}
	
	if(IsEqualIID(riid, IID_IQueryInfo))
	{
		mol::punk<QueryInfo::Instance> queryInfo = QueryInfo::createInstance(pidl_);
		if ( queryInfo )
		{
			return queryInfo->QueryInterface(IID_IQueryInfo, ppvOut);
		}  
		return E_OUTOFMEMORY;
	}

	if(IsEqualIID(riid, IID_IDropTarget))
	{
		mol::punk<SFDropTarget> dt = new SFDropTarget();
		return dt->QueryInterface(IID_IDropTarget,ppvOut);
	}

	if(IsEqualIID(riid, IID_IDropSource))
	{
		mol::punk<IDropSource> ds = new mol::DropSrc();
		return ds->QueryInterface(IID_IDropSource,ppvOut);
	}

	return hr;
}

HRESULT __stdcall ShellFolder::EnumObjects( HWND hwndOwner, DWORD dwFlags, LPENUMIDLIST *ppEnumIDList)
{	
	if (!ppEnumIDList)
		return E_INVALIDARG;

	*ppEnumIDList = NULL;

	if ( !pidlManager().isServer(pidl_) )
	{
		std::wstring ws = pidlManager().getSftpPath(pidl_);
		bool b = validate(pidl_);
		if(!b)
		{
			return E_INVALIDARG;// HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND);
		}
	}

	mol::punk<EnumIDList::Instance> enumIDList = EnumIDList::createInstance(pidl_,dwFlags);
	HRESULT hr = enumIDList.queryInterface(ppEnumIDList);
	return hr;
}


HRESULT __stdcall ShellFolder::GetAttributesOf( UINT uCount, LPCITEMIDLIST aPidls[], LPDWORD pdwAttribs)
{
	UINT  i;

	DWORD a = *pdwAttribs;

	*pdwAttribs = (DWORD)-1;

	for(i = 0; i < uCount; i++)
	{
		DWORD dwAttribs = 0;
		LPITEMIDLIST pidl = pidlManager().getLastItem( aPidls[i] );

		//if ( a & SFGAO_VALIDATE )
		{
			if ( pidl_ && !pidlManager().isServer(pidlManager().getLastItem(pidl_)) )
			{
				LPITEMIDLIST pidl = pidlManager().concat( pidl_, aPidls[i] );
				std::wstring ws = pidlManager().getSftpPath(pidl);
				bool b = validate(pidl);
				pidlManager().destroy(pidl);
				if(!b)
				{
					return E_INVALIDARG;//HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND);
				}
			}
		}

		//flags common to all items
		dwAttribs |= 0;//SFGAO_ISSLOW;

		if(pidlManager().isServer(pidl))
		{
			dwAttribs |= SFGAO_FOLDER|SFGAO_HASSUBFOLDER|SFGAO_FILESYSTEM|SFGAO_BROWSABLE;
		}

		if(pidlManager().isPath(pidl))
		{
			dwAttribs |= SFGAO_FOLDER|SFGAO_HASSUBFOLDER|SFGAO_CANCOPY|SFGAO_CANRENAME|SFGAO_CANDELETE|SFGAO_FILESYSTEM|SFGAO_BROWSABLE|SFGAO_DROPTARGET;
		}

		if(pidlManager().isFile(pidl))
		{
			dwAttribs |= SFGAO_CANCOPY|SFGAO_CANRENAME|SFGAO_CANDELETE|SFGAO_FILESYSTEM|SFGAO_BROWSABLE;
		}

		*pdwAttribs &= dwAttribs;
	}
	return S_OK;
}


HRESULT __stdcall ShellFolder::GetUIObjectOf( HWND hwndOwner, UINT uCount, LPCITEMIDLIST *pPidl, REFIID riid, LPUINT puReserved, LPVOID *ppvReturn)
{
	*ppvReturn = NULL;

	if(uCount != 1)
		return E_FAIL;

	if ( !pidlManager().isServer(pPidl[0]) )
	{
		LPITEMIDLIST pidl = pidlManager().concat( pidl_, pPidl[0] );
		std::wstring ws = pidlManager().getSftpPath(pidl);
		bool b = validate(pidl);
		pidlManager().destroy(pidl);
		if(!b)
		{
			return E_INVALIDARG;//HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND);
		}
	}

	if(IsEqualIID(riid, IID_IExtractIcon))
	{
		LPITEMIDLIST pidl = pidlManager().concat(pidl_,pPidl[0]);
		mol::punk<IconExtractor::Instance> iconExtractor = IconExtractor::createInstance(pidl);
		pidlManager().destroy(pidl);

		if ( iconExtractor )
		{
			return iconExtractor->QueryInterface(IID_IExtractIcon, ppvReturn);
		}  
		return E_OUTOFMEMORY;
	}

	if(IsEqualIID(riid, IID_IQueryInfo))
	{
		LPITEMIDLIST pidl = pidlManager().concat(pidl_,pPidl[0]);
		mol::punk<QueryInfo::Instance> queryInfo = QueryInfo::createInstance(pidl);
		pidlManager().destroy(pidl);

		if ( queryInfo )
		{
			return queryInfo->QueryInterface(IID_IQueryInfo, ppvReturn);
		}  
		return E_OUTOFMEMORY;
	}

	if(IsEqualIID(riid, IID_IDataObject))
	{
		LPITEMIDLIST pidl = pidlManager().concat(pidl_,pPidl[0]);

		std::vector<mol::string> v;
		std::wstring s(L"ssh://");
		s += pidlManager().getPidlPath(pidl);
		v.push_back( s );

		pidlManager().destroy(pidl);

		mol::punk<mol::ShellDataObj> sdo = new mol::ShellDataObj(v);
		return sdo->QueryInterface(IID_IDataObject,ppvReturn);
	}
	if(IsEqualIID(riid, IID_IDropTarget))
	{
		mol::punk<SFDropTarget> dt = new SFDropTarget();
		return dt->QueryInterface(IID_IDropTarget,ppvReturn);
	}

	if(IsEqualIID(riid, IID_IDropSource))
	{
		mol::punk<IDropSource> ds = new mol::DropSrc();
		return ds->QueryInterface(IID_IDropSource,ppvReturn);
	}

	if(IsEqualIID(riid, IID_IPersistFolder))
	{
		ODBGS("GetUIObjectOf IID_IPersistFolder");
		return ((IPersistFolder*)this)->QueryInterface(IID_IPersistFolder,ppvReturn);
	}

	if(IsEqualIID(riid, IID_IPersistFolder2))
	{
		ODBGS("GetUIObjectOf IID_IPersistFolder2");
		return ((IPersistFolder2*)this)->QueryInterface(IID_IPersistFolder2,ppvReturn);
	}

	if(IsEqualIID(riid, IID_IContextMenu))
	{
		LPITEMIDLIST pidl = pidlManager().concat(pidl_,pPidl[0]);
		mol::punk<IContextMenu> ctx = SFContextMenu::createInstance( this, pidl );
		pidlManager().destroy(pidl);
		return ctx->QueryInterface(IID_IContextMenu,ppvReturn);
	}

	return E_NOINTERFACE;
}

HRESULT __stdcall ShellFolder::SetNameOf(HWND, LPCITEMIDLIST, LPCOLESTR, DWORD, LPITEMIDLIST*)
{
	return E_NOTIMPL;
}



#define GET_SHGDN_FOR(dwFlags)         ((DWORD)dwFlags & (DWORD)0x0000FF00)
#define GET_SHGDN_RELATION(dwFlags)    ((DWORD)dwFlags & (DWORD)0x000000FF)

HRESULT __stdcall ShellFolder::GetDisplayNameOf( LPCITEMIDLIST relativePidl, DWORD dwFlags, LPSTRRET lpName)
{
	std::wstring ret = L"TEST";

	if ( pidl_ )
	{
		if (!pidlManager().isServer(relativePidl))
		{
			LPITEMIDLIST pidl = pidlManager().concat(pidl_,relativePidl);
			bool b = validate(pidl);
			pidlManager().destroy(pidl);
			if(!b)
				return E_FAIL;//HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND);
		}
	}

	switch(GET_SHGDN_FOR(dwFlags))
	{
		case SHGDN_FORPARSING:
		case SHGDN_FORADDRESSBAR:
		case SHGDN_NORMAL:
		case SHGDN_FORPARSING|SHGDN_FORADDRESSBAR:
		{
			switch(GET_SHGDN_RELATION(dwFlags))
			{
				case SHGDN_NORMAL:
				{
					//get the full name
					LPITEMIDLIST pidl = pidlManager().concat( pidl_, relativePidl);
					std::wstring tmp = std::wstring(L"ssh://");
					std::wstring path = pidlManager().getPidlPath(pidl);
					if ( path.size() > 4 && path.substr(0,5) != L"ssh:/")
					{
						path = tmp + path;
					}
					ret = path;
					pidlManager().destroy(pidl);
					break;
				}
				case SHGDN_INFOLDER:
				{
					//get the relative name
					ret = pidlManager().getSftpFilename(relativePidl);
					break;
				}
				default:
				return E_INVALIDARG;
			 }
			 
			 break;
		}
		default:
			return E_INVALIDARG;
	}

	int cchOleStr = (int)(ret.size() + 1);
	lpName->pOleStr = (LPWSTR)::CoTaskMemAlloc(cchOleStr * sizeof(WCHAR));
	if(!lpName->pOleStr)
	   return E_OUTOFMEMORY;

	lpName->uType = STRRET_WSTR;
	wcscpy(lpName->pOleStr,ret.c_str());
	return S_OK;
}


HRESULT __stdcall ShellFolder::ParseDisplayName( HWND hwndOwner, LPBC pbcReserved, LPOLESTR lpDisplayName, LPDWORD pdwEaten, LPITEMIDLIST *pPidlNew, LPDWORD pdwAttributes)
{
	*pPidlNew = 0;
	if ( !lpDisplayName)
		return S_OK;

	std::wstring s(lpDisplayName);

	if ( pdwEaten )
		*pdwEaten = (DWORD)(s.size());

	if ( s.size() >= 4 )
	{
		if ( s.substr(0,4) == L"ssh:" )
		{
			s = s.substr(4);
		}
	}

	while ( s.size()>1 && (s[0] == L'/' || s[0] == L'\\') )
	{
		s = s.substr(1);
	}

	if ( s.empty() || s[0] == L'/' || s[0] == L'\\' )
	{
		return S_OK;
	}

	size_t pos = s.find(L"/");
	if (pos == std::wstring::npos)
	{
		LPITEMIDLIST pidl = pidlManager().createSftpServer(s);
		*pPidlNew = pidl;
		return S_OK;
	}

	LPITEMIDLIST pidl = pidlManager().createSftpServer(s.substr(0,pos));

	if ( pos+1 > s.size()-1 )
	{
		*pPidlNew = pidl;
		return S_OK;
	}

	std::wstring path = s.substr(pos+1);
	pos = path.find(L"/");
	while( pos != std::wstring::npos)
	{
		std::wstring item = path.substr(0,pos);
		if ( !item.empty() && item != L"/" )
		{
			LPITEMIDLIST pidlPath = pidlManager().createSftpPath(item);
			LPITEMIDLIST pidlTmp = pidlManager().concat(pidl,pidlPath);
			pidlManager().destroy(pidl);
			pidlManager().destroy(pidlPath);
			pidl = pidlTmp;
		}
		path = path.substr(pos+1);
		pos = path.find(L"/");
	}

	if ( pos+1 < path.size()-1 )
	{
		std::wstring item = path.substr(pos+1);
		if ( !item.empty() && item != L"/" )
		{
			LPITEMIDLIST pidlPath = pidlManager().createSftpPath(item);
			LPITEMIDLIST pidlTmp = pidlManager().concat(pidl,pidlPath);
			pidlManager().destroy(pidl);
			pidlManager().destroy(pidlPath);
			pidl = pidlTmp;
		}
	}

	//ViewModel* vm = viewModelPathFactory(pidl);
	//if (!vm )

	if ( pidl_ )
	{
		if (!pidlManager().isServer(pidl_))
		{
			if(!validate(pidl))
				return E_FAIL;//HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND);
		}
	}

	*pPidlNew = pidl;
	return S_OK;
}

HRESULT __stdcall ShellFolder::GetCurFolder( PIDLIST_ABSOLUTE *ppidl)
{
	if (!ppidl)
		return E_INVALIDARG;

	*ppidl = 0;

	if ( pidl_ )
	{
		if ( !pidlManager().isServer(pidl_) )
		{
			if(!validate(pidl_))
				return E_INVALIDARG;
		}
	}

	*ppidl = pidlManager().concat(pidlManager().getRootPidl(),pidl_);
	return S_OK;
}


HRESULT __stdcall  ShellFolder::GetSite( REFIID riid,void **ppvSite)
{
	*ppvSite = 0;
	if (site_)
	{
		return site_->QueryInterface(riid,(ppvSite));
	}
	return E_NOINTERFACE;
}

HRESULT __stdcall  ShellFolder::SetSite(  IUnknown *pUnkSite)
{
	site_ = pUnkSite;
	return S_OK;
}

HRESULT __stdcall  ShellFolder::EnumSearches(IEnumExtraSearch **ppEnum) 
{ 
	return E_NOINTERFACE; 
}

HRESULT __stdcall  ShellFolder::GetDefaultColumn( DWORD dwReserved, ULONG *pSort, ULONG *pDisplay) 
{ 
	if ( pSort )
		*pSort = 0;
	if ( pDisplay )
		*pDisplay = 0;
	return S_OK; 
}

HRESULT __stdcall  ShellFolder::GetDefaultColumnState( UINT iColumn, SHCOLSTATEF *pcsFlags)
{
    HRESULT hr = (iColumn < 5) ? S_OK : E_INVALIDARG;
    if (SUCCEEDED(hr))
    {
        *pcsFlags = SHCOLSTATE_ONBYDEFAULT | SHCOLSTATE_TYPE_STR;
    }
    return hr;
}

HRESULT __stdcall  ShellFolder::GetDefaultSearchGUID( GUID *pguid ) 
{ 
	return E_NOTIMPL; 
}

HRESULT __stdcall  ShellFolder::GetDetailsEx( PCUITEMID_CHILD pidl, const SHCOLUMNID *pscid, VARIANT *pv ) { return E_NOTIMPL; }
HRESULT __stdcall  ShellFolder::GetDetailsOf( PCUITEMID_CHILD pidl, UINT iColumn, SHELLDETAILS *psd) { return E_NOTIMPL; }
HRESULT __stdcall  ShellFolder::MapColumnToSCID( UINT iColumn, SHCOLUMNID *pscid) { return E_NOTIMPL; }