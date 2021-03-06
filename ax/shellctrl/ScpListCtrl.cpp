#include "stdafx.h"
#include "ScpListCtrl.h"
#include "ole/Bstr.h"
#include "ole/enum.h"
#include "ole/Img.h"
#include "util/str.h"
#include "ShellCtrl_Dispid.h"
#include <sstream>

#include "win/shell.h"
#include "ssh/scpDataTransferObj.h"
#include "Resource.h"
#include <Wincrypt.h>



class PermissionDlg  : public mol::win::Dialog
{
public:

	PermissionDlg(const std::wstring& filename, int perm, int own, int grp)
		: filename_(filename), permission_(perm), owner_(own), group_(grp)
	{}

	virtual LRESULT wndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message)
		{
			case WM_INITDIALOG:
			{
				setDlgItemText(IDC_SCP_PROP_EDIT_FILENAME,filename_);
				std::wostringstream oss;
				oss << std::oct << permission_;
				setDlgItemText(IDC_SCP_PROP_EDIT_PERMISSION,oss.str());
				setDlgItemInt(IDC_SCP_PROP_EDIT_OWNER,owner_);
				setDlgItemInt(IDC_SCP_PROP_EDIT_GROUP,group_);
				this->center();
				return FALSE; // note: false! look into PSDK!
			}
			case WM_COMMAND:
			{
				if (LOWORD(wParam) == IDOK )
				{
					std::wstring s;
					getDlgItemText(IDC_SCP_PROP_EDIT_PERMISSION,s);
					std::wistringstream iss(s);
					iss >> std::oct >> permission_;

					getDlgItemInt(IDC_SCP_PROP_EDIT_OWNER,owner_);
					getDlgItemInt(IDC_SCP_PROP_EDIT_GROUP,group_);

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


	
	int permission()
	{
		return permission_;
	}

	int owner()
	{
		return owner_;
	}

	int group()
	{
		return group_;
	}


private:
	

	std::wstring filename_;
	int permission_;
	int owner_;
	int group_;

};

class RemoteExecDlg  : public mol::win::Dialog
{
public:

	RemoteExecDlg(const std::wstring& host, int port, DWORD cookie)
		: host_(host), port_(port), cookie_(cookie)
	{}

	virtual LRESULT wndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message)
		{
			case WM_INITDIALOG:
			{
				setDlgItemText(IDC_EDIT_SSH_EXEC_CMD,_T(""));
				setDlgItemFont(IDC_EDIT_SSH_EXEC_CMD,(HFONT)::GetStockObject(ANSI_FIXED_FONT));
				setDlgItemText(IDC_EDIT_SSH_EXEC_OUTPUT,_T("Absolute paths, honey!"));
				setDlgItemFont(IDC_EDIT_SSH_EXEC_OUTPUT,(HFONT)::GetStockObject(ANSI_FIXED_FONT));
				this->center();
				return FALSE; // note: false! look into PSDK!
			}
			case WM_COMMAND:
			{
				if (LOWORD(wParam) == IDOK )
				{
					std::wstring s;
					getDlgItemText(IDC_EDIT_SSH_EXEC_CMD,s);
					if ( s.empty())
					{
						return FALSE;
					}

					std::wstring o = exec_cmd(s);
					setDlgItemText(IDC_EDIT_SSH_EXEC_OUTPUT,mol::unix2dos(o));

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

	
	std::wstring cli()
	{
		return cli_;
	}

	std::wstring out()
	{
		return out_;
	}
private:

	std::wstring exec_cmd( const std::wstring& cmd)
	{
		mol::GIT git;
		mol::punk<ISSHConnection> ssh; 
		HRESULT hr = git.getInterface(cookie_,&ssh);
		if ( hr != S_OK )
			return _T("");

		mol::bstr result;
		hr = ssh->Execute( mol::bstr(cmd), &result);
		if ( hr != S_OK )
			return _T("");

		return result.towstring();
	}

	std::wstring cli_;
	std::wstring out_;
	std::wstring host_;
	int port_;
	DWORD cookie_;
	
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



ScpDirQueueLoadAction::ScpDirQueueLoadAction( const std::wstring& p, ScpListCtrl* dl )
	: path(p), scpList(dl)
{}

void ScpDirQueueLoadAction::operator()()
{
	scpList->load_async(path);
}



ScpDirQueueRenameAction::ScpDirQueueRenameAction( const std::wstring& oldp, const std::wstring& newp, ScpListCtrl* dl )
	: oldpath(oldp), newpath(newp),scpList(dl)
{}

void ScpDirQueueRenameAction::operator()()
{
	scpList->EndRename(oldpath,newpath);
}
///////////////////////////////////////////////////////////////////////////////

ScpCreateDirQueueAction::ScpCreateDirQueueAction( ScpListCtrl* dl )
	: scpList(dl)
{}

void ScpCreateDirQueueAction::operator()()
{
	scpList->mkdir();
}


///////////////////////////////////////////////////////////////////////////////

ScpUnlinkQueueAction::ScpUnlinkQueueAction( const std::vector<std::wstring>& vec, ScpListCtrl* dl )
	: v(vec), scpList(dl)
{}

void ScpUnlinkQueueAction::operator()()
{
	scpList->unlink(v);
}


///////////////////////////////////////////////////////////////////////////////

ScpPushFileQueueAction::ScpPushFileQueueAction( const std::wstring& p, const std::vector<std::wstring>& vec, ScpListCtrl* dl )
	: path(p),v(vec), scpList(dl)
{}

void ScpPushFileQueueAction::operator()()
{
	scpList->put(v,path);
}
///////////////////////////////////////////////////////////////////////////////

ScpListCtrl::ScpListCtrl()	
{
	sharedMenu_ = 0;
	eraseBackground_ = 1;
	gitCookie_ = 0;
	gitSSHCookie_ = 0;

/*	mol::GIT git;
	HRESULT hr = ssh_.createObject(CLSID_SSH,CLSCTX_ALL);
	if( hr == S_OK )
	{
		git.registerInterface(*ssh_, &gitSSHCookie_);
	}
	*/
	sizel.cx = 300;
	sizel.cy = 200;
	bgCol_    = RGB(255,255,255);
	foreCol_  = RGB(0,0,0);
	mol::ole::PixeltoHIMETRIC(&sizel);
}

//////////////////////////////////////////////////////////////////////////////

ScpListCtrl::~ScpListCtrl()
{
}

void ScpListCtrl::load( const std::wstring& url )
{
	std::wstring path = url;
	if ( path[path.size()-1] != _T('/') )
	{
		path = path + _T("/");
	}

	uri_.set(mol::toUTF8(path));

	if(!connect(&conn_))
		return;

	queue_.push( new ScpDirQueueLoadAction(url,this) );
}

mol::sftp::RemoteFile remoteFileFromIRemoteFile(IRemoteFile* rf)
{
	if (!rf)
		return  mol::sftp::RemoteFile();

	mol::bstr name;
	mol::bstr owner;
	mol::bstr group;
	HRESULT hr = rf->get_Filename(&name);
	if ( hr!=S_OK || !name)
		return mol::sftp::RemoteFile();

	hr = rf->get_Owner(&owner);
	hr = rf->get_Group(&group);

	long mtime = 0;
	long type = 0;
	long gid = 0;
	long uid = 0;
	long perms = 0;
	long size = 0;
	hr = rf->get_Filetype(&type);
	hr = rf->get_GID(&gid);
	hr = rf->get_UID(&uid);
	hr = rf->get_Mtime(&mtime);
	hr = rf->get_Permission(&perms);
	hr = rf->get_Size(&size);

	VARIANT_BOOL isdir = VARIANT_FALSE;
	hr = rf->get_IsDir(&isdir);

	return mol::sftp::RemoteFile( 
					mol::towstring(name), 
					(uint8_t)type, perms, 
					uid, gid, 
					mtime, size, 
					owner.bstr_ ? mol::towstring(owner) : _T("") , 
					group.bstr_ ? mol::towstring(group) : _T("") 
			);
}

bool ScpListCtrl::connect(ISSHConnection** con )
{
	mol::GIT git;
	if(!gitSSHCookie_)
	{
		HRESULT hr = ssh_.createObject(CLSID_SSH,CLSCTX_ALL);
		if( hr == S_OK )
		{
			hr = ssh_->Connect(mol::bstr(this->uri_.getHost()),this->uri_.getPort(),&conn_);
			if( hr == S_OK )
			{
				git.registerInterface(*conn_, &gitSSHCookie_);
			}
		}
	}

	if(!conn_)
		return false;

	VARIANT_BOOL vb;
	HRESULT hr = conn_->get_IsConnected(&vb);
	if ( hr != S_OK )
		return false;

	if ( vb == VARIANT_TRUE )
	{
		return true;
	}

	hr = conn_->Connect();
	if ( hr != S_OK )
		return false;

	return true;
/*
	mol::GIT git;
	mol::punk<ISSH> ssh; 
	HRESULT hr = git.getInterface(cookie,&ssh);
	if ( hr != S_OK )
		return false;

	hr = ssh->Connect( 
				mol::bstr(mol::fromUTF8(uri_.getHost())), 
				uri_.getPort(),
				con);

	if ( hr != S_OK )
		return false;

	return true;
	*/
}

void ScpListCtrl::load_async( const std::wstring& url )
{
	clear();

	mol::GIT git;

	mol::punk<IOleInPlaceFrame> oip; 
	HRESULT hr = git.getInterface(gitCookie_,&oip);
	if ( hr != S_OK )
		return;
	
	mol::punk<ISSHConnection> conn;
	hr = git.getInterface(gitSSHCookie_,&conn);
	if ( hr != S_OK )
		return;

	std::wstring path = url;
	if ( path[path.size()-1] != _T('/') )
	{
		path = path + _T("/");
	}

	uri_.set(mol::toUTF8(path));

    std::vector<std::wstring> files;
    std::vector<std::wstring> dirs;

    std::map<std::wstring, ScpListEntry*> filesMap;
	std::map<std::wstring, ScpListEntry*> dirsMap;

	mol::punk<ISFTP> sftp;
	hr = conn->get_SFTP(&sftp);
	if( hr != S_OK )
		return;

	std::wstring grr(path);
	if ( grr[grr.size()-1] == _T('/') )
		grr = grr.substr(0,grr.size()-1);

	mol::punk<IRemoteFile> rf;
	hr = sftp->Stat( mol::bstr( mol::fromUTF8(uri_.getPath())),&rf );
	if( hr != S_OK )
		return;

	VARIANT_BOOL vb;
	hr = rf->get_IsDir(&vb);
	if( hr != S_OK )
		return;

	if ( vb == VARIANT_FALSE )
	{
		uri_.set(mol::toUTF8(path_));
		return;
	}

	wchar_t buf[MAX_PATH];
	::GetTempPath(MAX_PATH,buf);
	int dirIcon = mol::io::ShellInfo::Icon(buf);

	SAFEARRAY* sa;
	hr = sftp->List( mol::bstr( mol::fromUTF8(uri_.getPath())), &sa);
	if( hr != S_OK )
		return;

	mol::SafeArray<VT_DISPATCH> safeArray;
	safeArray.Attach(sa);


	mol::SFAccess<VARIANT> sf(sa);

	ListView_SetItemCount(list_,sf.size());

	for ( size_t i = 0; i < sf.size(); i++)
	{
		mol::punk<IRemoteFile> rf(sf[(int)i].pdispVal);

		mol::bstr n;
		hr = rf->get_Filename(&n);
		if( hr != S_OK )
		{
			return;
		}

		std::wstring name = mol::towstring(n.bstr_);

		if ( name == _T(".") )
			continue;

		VARIANT_BOOL vb;
		hr = rf->get_IsDir(&vb);
		if( hr != S_OK )
			return;

		if ( vb == VARIANT_TRUE )
		{
			ScpListEntry* entry = new ScpListEntry(path + name,remoteFileFromIRemoteFile(rf),dirIcon);
			dirs.push_back(name);
			dirsMap.insert( std::make_pair(name,entry) );
		}			
		else
		{
			std::wstring tmp(buf);
			tmp += name;

			SHFILEINFO  shInfo;
			DWORD att = FILE_ATTRIBUTE_NORMAL;
			::SHGetFileInfo( tmp.c_str(),att,&shInfo,sizeof(shInfo),SHGFI_ICON|SHGFI_SMALLICON|SHGFI_USEFILEATTRIBUTES |SHGFI_TYPENAME);
			::DestroyIcon(shInfo.hIcon);
			int icon = shInfo.iIcon;

			ScpListEntry* entry = new ScpListEntry(path + name,remoteFileFromIRemoteFile(rf),icon);
			files.push_back(name);
			filesMap.insert( std::make_pair(name,entry) );
		}
	}

	path_ = path;
	uri_.set(mol::toUTF8(path));

	std::sort( files.begin(), files.end() );
	std::sort( dirs.begin(), dirs.end()   );

    int index = 0;
    list_.setRedraw(false);
	for ( std::vector<std::wstring>::iterator iter = dirs.begin(); iter != dirs.end(); iter++ )
	{
		std::wstring p(*iter);
        std::vector<std::wstring> entries;
        ScpListEntry* entry = dirsMap[*iter];

		entries.push_back( entry->fileinfo.getName() );
		entries.push_back( entry->fileinfo.formattedSize() );
		entries.push_back( entry->fileinfo.formattedPermissions() );
		entries.push_back( entry->fileinfo.getOwner() );
		entries.push_back( entry->fileinfo.getGroup() );

		entries.push_back(mol::towstring(""));

        list_.insertItem(entries,index,0,entry->iconindex,(LPARAM)entry);
        index++;
	}

	for ( std::vector<std::wstring>::iterator iter = files.begin(); iter != files.end(); iter++ )
	{
		std::wstring p(*iter);
        std::vector<std::wstring> entries;
        ScpListEntry* entry = filesMap[*iter];

		entries.push_back( entry->fileinfo.getName() );
		entries.push_back( entry->fileinfo.formattedSize() );
		entries.push_back( entry->fileinfo.formattedPermissions() );
		entries.push_back( entry->fileinfo.getOwner() );
		entries.push_back( entry->fileinfo.getGroup() );

		long t = entry->fileinfo.getMtime();
		char* ct = ctime((time_t*)&t);
		entries.push_back(mol::towstring(ct));

        list_.insertItem(entries,index,0,entry->iconindex,(LPARAM)entry);
        index++;
	}

	oip->SetStatusText(mol::fromUTF8(uri_.getPath()).c_str());

	list_.setRedraw(true);
	list_.redraw();
	fire(DISPID_ISHELLLISTEVENTS_ONDIRCHANGED,mol::bstr(path_));
	
}

//////////////////////////////////////////////////////////////////////////////
//
// OnDestroy - over and out
//
//////////////////////////////////////////////////////////////////////////////

LRESULT ScpListCtrl::OnDestroy(UINT msg, WPARAM wParam, LPARAM lParam)
{
	queue_.cancel();
	clear();
	mol::GIT git;
	git.revokeInterface(gitCookie_);
	git.revokeInterface(gitSSHCookie_);
	ssh_.release();
	conn_.release();
	::RevokeDragDrop(*this);
    return 0;
}
//////////////////////////////////////////////////////////////////////////////

LRESULT ScpListCtrl::OnCreate(UINT msg, WPARAM wParam, LPARAM lParam)
{
	listMenu_.load(IDM_LIST_DIR);

    RECT clientRect;
	getClientRect(clientRect);
    int w = clientRect.right;
    int w7 = w/7;

	list_.create((HMENU)1,clientRect,*this);
	list_.setRedraw(false);

    ListView_SetImageList(list_,mol::io::ShellFolder::SysImgList(),LVSIL_SMALL);
    list_.insertColumn( _T("filename"), 0, w7*2 );
    list_.insertColumn( _T("size"), w7 );
    list_.insertColumn( _T("permissions"), w7 );
    list_.insertColumn( _T("owner"), w7 );
    list_.insertColumn( _T("group"), w7 );
    list_.insertColumn( _T("modified"), w7 );

	Drop = new ShellListCtrl_Drop(this);
	::RegisterDragDrop(*this,Drop);

	::ShowScrollBar(list_,SB_VERT,TRUE);
	list_.setFocus();
	list_.show(SW_SHOW);
	list_.setRedraw(true);

	mol::GIT git;
	git.registerInterface( *frame_, &gitCookie_);
	return 0;
}



LRESULT ScpListCtrl::OnSize(UINT msg, WPARAM wParam, LPARAM lParam)
{
	getClientRect(clientRect_);
		
	// get new width and height
	clientRect_.right  = LOWORD (lParam);
	clientRect_.bottom = HIWORD (lParam) ;

	ODBGS1("right:",clientRect_.right);
	ODBGS1("bottom:",clientRect_.bottom);

	list_.move(clientRect_);

	::ShowScrollBar(list_,SB_VERT,TRUE);
	return 0;
}
//////////////////////////////////////////////////////////////////////////////

LRESULT ScpListCtrl::OnColumn(UINT msg, WPARAM wParam, LPARAM lParam)
{
	mol::Crack message(msg,wParam,lParam);
	return 0;
}

//////////////////////////////////////////////////////////////////////////////

LRESULT ScpListCtrl::OnClick(UINT msg, WPARAM wParam, LPARAM lParam)
{
	this->uiActivate();
	return 0;
}

//////////////////////////////////////////////////////////////////////////////

LRESULT ScpListCtrl::OnDblClick(UINT msg, WPARAM wParam, LPARAM lParam)
{
	mol::Crack message(msg,wParam,lParam);
	int it = message.listActivate()->iItem;
	
	ScpListEntry* entry = getItemEntry(it);
	if ( entry )
	{
		std::wstring p(entry->filename);
		if ( entry->isDir() )
		{
			std::wstring name =entry->fileinfo.getName();
			if ( name == _T("..") )
			{
				UpDir();
				return 0;
			}			
			load(p);
		}        
		else
		{
			this->fire(DISPID_ISHELLLISTEVENTS_ONLISTDBLCLICK,mol::bstr(entry->filename),mol::variant(entry->isDir()));
		}
	}
	
	return 0;
}


//////////////////////////////////////////////////////////////////////////////
//
// Keys
//
//////////////////////////////////////////////////////////////////////////////

LRESULT ScpListCtrl::OnKeyDown(UINT msg, WPARAM wParam, LPARAM lParam)
{
	mol::Crack message(msg,wParam,lParam);
	WORD wd = message.keydown()->wVKey;
	if (GetAsyncKeyState(VK_CONTROL) < 0) 
	{
		if ( wd == 0x43 ) // C
		{
			Copy();
			return 1;
		}
		if ( wd == 0x58 ) // X
		{
			Cut();
			return 1;
		}
		if ( wd == 0x56 ) // V
		{
			Paste();
			return 1;
		}
		if ( wd == VK_RETURN )
		{

		}
	}
	return 0;
}



//////////////////////////////////////////////////////////////////////////////

LRESULT ScpListCtrl::OnBeginLabelEdit(UINT msg, WPARAM wParam, LPARAM lParam)
{
	// FALSE to allow ... see psdk
	return FALSE;
}

void ScpListCtrl::EndRename(const std::wstring& oldpath, const std::wstring& newpath)
{
	mol::punk<IOleInPlaceFrame> oip; 
	mol::GIT git;
	HRESULT hr = git.getInterface(gitCookie_,&oip);
	if ( hr != S_OK )
		return;

	mol::punk<ISSHConnection> conn;
	hr = git.getInterface(gitSSHCookie_,&conn);
	if ( hr != S_OK )
		return;

	std::wstring pFrom( mol::fromUTF8(uri_.getPath()) ); 
	pFrom += oldpath;

	std::wstring tmp = pFrom;
	size_t pos = pFrom.find_last_of(_T("/"));
	if ( pos != std::string::npos )
		tmp = pFrom.substr(0,pos+1);

	std::wstring pTo(tmp);
	pTo += std::wstring(newpath);

	mol::punk<ISFTP> sftp;
	hr = conn->get_SFTP(&sftp);
	if( hr != S_OK )
		return;

	sftp->Rename( mol::bstr(pFrom), mol::bstr(pTo) );
	load(path_);	
}

LRESULT ScpListCtrl::OnEndRename(UINT msg, WPARAM wParam, LPARAM lParam)
{
	mol::Crack message(msg,wParam,lParam);
	if ( message.listviewDispInfo()->item.pszText)
	{
		std::wstring displayname = message.listviewDispInfo()->item.pszText;
		std::wstring path= getItemEntry(message.listviewDispInfo()->item.iItem)->fileinfo.getName();

		if(connect(&conn_))
		{
			queue_.push(new ScpDirQueueRenameAction(path,displayname,this));
		}
	}
	return 0;
}


//////////////////////////////////////////////////////////////////////////////

LRESULT ScpListCtrl::OnBeginDrag(UINT msg, WPARAM wParam, LPARAM lParam)
{	
	std::vector<std::wstring> v = selectionPaths();

	if ( v.size() != 1 )
		return 0;

	std::vector<int> vi        = selectionIndexes();

	POINT pt = {0,0};;
	
	HIMAGELIST hi = 0;
    hi = ListView_CreateDragImage( list_, vi[0], &pt );

	for ( size_t i = 1; i < vi.size(); i++ )
	{
		HIMAGELIST h  = ListView_CreateDragImage( list_, vi[i], &pt );
		HIMAGELIST hh = ImageList_Merge(hi,0,h,0,0,(int)(20*i));
		ImageList_Destroy(hi);
		ImageList_Destroy(h);
		hi = hh;
	}

	mol::ImageList::beginDrag(*this,hi);

	mol::punk<IScpDataTransferObjectFactory> idoFactory;
	HRESULT hr = idoFactory.createObject(CLSID_ScpDataTransferObjectFactory);
	if ( hr != S_OK )
		return 0;

	std::wstring wh = mol::fromUTF8(uri_.getHost());
	mol::bstr host(wh);
	hr = idoFactory->Init( host, uri_.getPort() );
	if ( hr != S_OK )
		return 0;

	for ( size_t i = 0; i < vi.size(); i++ )
	{
		ScpListEntry* e = getItemEntry(vi[i]);

		std::wstring wp = mol::fromUTF8(uri_.getPath()) + e->getName();
		mol::bstr path(wp);
		hr = idoFactory->Add( path,(long)(e->fileinfo.getSize()),e->isDir() ? VARIANT_TRUE : VARIANT_FALSE );
		if ( hr != S_OK )
			return 0;
	}

	DWORD effect;
	mol::punk<IDropSource> drop = new mol::DropSrc;
	mol::punk<IUnknown> unk;
	hr = idoFactory->ToDataObject(&unk);
	if ( hr != S_OK )
		return 0;

	mol::punk<IDataObject> ido(unk);
	if(!ido)
		return 0;

	HRESULT r = ::DoDragDrop(ido,drop,DROPEFFECT_COPY,&effect);
	if ( r != S_OK )
	{
		ODBGS("DoDragDrop Failed");
	}	
	drop();
	
	return 0;
}

//////////////////////////////////////////////////////////////////////////////

LRESULT ScpListCtrl::OnContext(UINT msg, WPARAM wParam, LPARAM lParam)
{
	mol::Crack message(msg,wParam,lParam);

	// prepare context menue
	mol::Menu m(listMenu_.getSubMenu(0));

	// get selection, if we have a hittest update selection beforehand
	int hit = this->list_.hitTest(LVHT_TOLEFT|LVHT_ONITEM);

	ScpListEntry* entry = 0 ;
	if ( hit != -1 )
	{
		entry = this->getItemEntry(hit);
	}

	m.enableItem(IDM_LIST_ENTERDIR);
	m.enableItem(IDM_LIST_RENAME);
	m.enableItem(IDM_LIST_DELETE);
	m.enableItem(IDM_LIST_OPEN);
	m.enableItem(IDM_LIST_CUT);
	m.enableItem(IDM_LIST_COPY);
	m.enableItem(IDM_LIST_PASTE);
	m.enableItem(IDM_LIST_PROPERTIES);
	m.enableItem(IDM_LIST_EXECUTE);
	if ( hit==-1 )
	{
		m.disableItem(IDM_LIST_ENTERDIR);
		m.disableItem(IDM_LIST_DELETE);
		m.disableItem(IDM_LIST_RENAME);
		m.disableItem(IDM_LIST_OPEN);
		m.disableItem(IDM_LIST_CUT);
		m.disableItem(IDM_LIST_COPY);
		//m.disableItem(IDM_LIST_PASTE);
		m.disableItem(IDM_LIST_PROPERTIES);
		m.disableItem(IDM_LIST_EXECUTE);
	}

	LRESULT res = returnContext(m);
	switch (res)
	{
		case IDM_LIST_OPEN :
		{
			if ( entry->isDir())
			{
				load(entry->filename);
			}
			else
			{
				std::wstring tmp(entry->filename);
				this->fire(DISPID_ISHELLLISTEVENTS_ONLISTOPEN,mol::bstr(tmp),mol::variant(entry->isDir()));
			}
			break;
		}
		case IDM_LIST_UPDATE :
		{
			this->Update();
			break;
		}
		case IDM_LIST_NEWDIR :
		{
			this->CreateDir();
			break;
		}
		case IDM_LIST_RENAME:
		{
			this->Rename();
			break;
		}
		case IDM_LIST_DELETE :
		{
			this->Delete();
			break;
		}
		case IDM_LIST_CUT :
		{
			this->Cut();
			break;
		}
		case IDM_LIST_COPY :
		{
			this->Copy();
			break;
		}
		case IDM_LIST_PASTE :
		{
			this->Paste();
			break;
		}
		case IDM_LIST_EXECUTE :
		{
			this->Execute();
			break;
		}
		case IDM_LIST_PROPERTIES :
		{
			this->Properties();
			break;
		}
		case IDM_LIST_UPDIR :
		{
			this->UpDir();
			break;
		}
		case IDM_LIST_ENTERDIR :
		{
			if ( entry->isDir() )
			{
				load(entry->filename);
			}
			break;
		}
	}	
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
//
//
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// Up Dir
//
//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScpListCtrl::UpDir()
{
	std::wstring tmp = path_;
	if ( tmp[tmp.size()-1] == _T('/'))
		tmp = tmp.substr(0,tmp.size()-2);

	size_t pos = tmp.find_last_of(_T("/"));
	if ( pos != std::string::npos && pos > 0)
	{
		tmp = tmp.substr(0,pos);
		load(tmp);
	}
	return false;
}

//////////////////////////////////////////////////////////////////////////////
//
// Update focused dir
//
//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScpListCtrl::Update()
{
	load(path_);
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////
HRESULT __stdcall ScpListCtrl::CreateDir()
{
	if(connect(&conn_))
	{
		queue_.push(new ScpCreateDirQueueAction(this));
	}
	return S_OK;
}

void ScpListCtrl::mkdir()
{
	mol::punk<IOleInPlaceFrame> oip; 
	mol::GIT git;
	HRESULT hr = git.getInterface(gitCookie_,&oip);
	if ( hr != S_OK )
		return;

	mol::punk<ISSHConnection> conn;
	hr = git.getInterface(gitSSHCookie_,&conn);
	if ( hr != S_OK )
		return;

	std::string p = uri_.getPath();

	if ( p[p.size()-1] != '/' )
		p += "/";


	mol::punk<ISFTP> sftp;
	hr = conn->get_SFTP(&sftp);
	if( hr != S_OK )
		return;

	SAFEARRAY* sa;

	hr = sftp->Files( mol::bstr(mol::fromUTF8(p)),&sa);
	if( hr != S_OK )
		return;

	mol::SafeArray<VT_VARIANT> safeArray;
	safeArray.Attach(sa);

	std::wstring tmp = _T("newDir_");	
	int i = 0;
	while(true)
	{
		std::wstringstream oss;
		oss << tmp << i;
		std::wstring newDir = oss.str();

		bool exists = false;
		mol::SFAccess<VARIANT> sf(sa);
		for ( size_t c = 0; c <sf.size(); c++)
		{
			mol::bstr b(sf[(int)c].bstrVal);
			std::wstring name = b.towstring();
			if ( newDir == name )
			{
				exists = true;
				break;
			}
		}

		if (exists)
		{
			i++;
			continue;
		}

		hr = sftp->Mkdir( mol::bstr(mol::fromUTF8(p) + newDir),0700 );
		if( hr != S_OK )
		{
			std::wstringstream oss;
			oss << L"failed to create new dir " << newDir;
			oip->SetStatusText(oss.str().c_str());				
			return;
		}

		load(path_);
		return;
	}
}

//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScpListCtrl::Rename()
{
	std::vector<int> v = selectionIndexes();
	if ( v.size() > 0 )
	{
		list_.editLabel(v[0]);
		return S_OK;
	}
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////
//
// delete selected tree or dir item
//
//////////////////////////////////////////////////////////////////////////////
HRESULT __stdcall ScpListCtrl::Delete()
{
	std::vector<ScpListEntry*> v = selectionEntries();
	if ( v.size() == 0 )
	{
		return S_OK;
	}

	std::vector<std::wstring> tmp;
	for(size_t i = 0; i < v.size(); i++)
	{
		tmp.push_back(v[i]->filename);
	}

	if(connect(&conn_))
	{
		queue_.push( new ScpUnlinkQueueAction(tmp,this) );
	}

	return S_OK;
}

void ScpListCtrl::unlink( const std::vector<std::wstring>& v )
{
	if ( v.empty() )
		return;

	mol::punk<IOleInPlaceFrame> oip; 
	mol::GIT git;
	HRESULT hr = git.getInterface(gitCookie_,&oip);
	if ( hr != S_OK )
		return;


	mol::punk<ISSHConnection> conn;
	hr = git.getInterface(gitSSHCookie_,&conn);
	if ( hr != S_OK )
		return;

	mol::punk<ISFTP> sftp;
	hr = conn->get_SFTP(&sftp);
	if( hr != S_OK )
		return;


	for ( size_t i = 0; i < v.size(); i++)
	{
		std::wstring path(v[i]);

		mol::Uri uri( mol::toUTF8(path) );
		std::string p = uri.getPath();

		mol::punk<IRemoteFile> rf;
		hr = sftp->Stat( mol::bstr(mol::fromUTF8(p)),&rf );
		if( hr != S_OK )
			return;

		VARIANT_BOOL vb;
		hr = rf->get_IsDir(&vb);
		if( hr != S_OK )
			return;

		if ( vb == VARIANT_TRUE )
		{
			hr = sftp->Rmdir( mol::bstr(mol::fromUTF8(p)));
			if( hr != S_OK )
			{
				continue;
			}
		}
		else
		{
			hr = sftp->Unlink(mol::bstr(mol::fromUTF8(p)));
			if( hr != S_OK )
			{
				continue;
			}
		}
	}

	load(path_);
	return;
}

HRESULT __stdcall ScpListCtrl::Properties()
{	
	std::vector<std::wstring> v = selectionPaths();

	if ( v.size() > 0 )
	{
		std::wstring path = v[0];

		mol::Uri uri( mol::toUTF8(path) );
		std::string host = uri.getHost();
		int port = uri.getPort();
		std::string p = uri.getPath();

/*		mol::punk<ISSHConnection> conn;
		if (!connect(gitSSHCookie_,&conn))
			return S_FALSE;
*/
		mol::punk<ISFTP> sftp;
		HRESULT hr = conn_->get_SFTP(&sftp);
		if( hr != S_OK )
			return hr;

		frame_->SetStatusText(path.c_str());

		mol::punk<IRemoteFile> rf;
		hr = sftp->Stat( mol::bstr(mol::fromUTF8(p)),&rf );
		if( hr != S_OK )
			return hr;
			
		long perm;
		long owner;
		long group;
			
		hr = rf->get_Permission(&perm);
		if( hr != S_OK )
			return hr;

		hr = rf->get_UID(&owner);
		if( hr != S_OK )
			return hr;

		hr = rf->get_GID(&group);
		if( hr != S_OK )
			return hr;

		PermissionDlg dlg(path,perm,owner,group);
		LRESULT r = dlg.doModal(IDD_DIALOG_SCP_PROPERTIES,*this);
		if ( r == IDOK )
		{
			long pm = dlg.permission();
			long ow = dlg.owner();
			long gr = dlg.group();
			if ( perm != pm )
			{
			}
			if ( owner != ow|| group != gr )
			{
				hr = sftp->Chown( mol::bstr(mol::fromUTF8(p)), ow, gr );
				if( hr != S_OK )
					return hr;
			}
			load(path_);
		}
	}
	
	return S_OK;
}

HRESULT __stdcall ScpListCtrl::Execute()
{
	mol::Uri uri( mol::toUTF8(path_) );
	std::string host = uri.getHost();
	int port = uri.getPort();

	RemoteExecDlg dlg(mol::fromUTF8(host),port,gitSSHCookie_);
	dlg.doModal(IDD_DIALOG_SSH_EXEC,*this);
	
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////
//
// open selected dir
//
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScpListCtrl::Cut ()
{
	return Copy();
}

//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScpListCtrl::Copy ()
{
	std::vector<int> vi        = selectionIndexes();

	if ( vi.size() != 1 )
		return 0;

	ScpListEntry* e = getItemEntry(vi[0]);

	mol::Uri uri( mol::toUTF8(path_) );
	int port = uri.getPort();
	std::string p = uri.getPath();

	mol::punk<IScpDataTransferObjectFactory> idoFactory;
	HRESULT hr = idoFactory.createObject(CLSID_ScpDataTransferObjectFactory);
	if ( hr != S_OK )
		return 0;

	std::wstring wh = mol::fromUTF8(uri_.getHost());
	mol::bstr host(wh);
	hr = idoFactory->Init( host, uri_.getPort() );
	if ( hr != S_OK )
		return 0;

	for ( size_t i = 0; i < vi.size(); i++ )
	{
		ScpListEntry* e = getItemEntry(vi[i]);

		std::wstring wp = mol::fromUTF8(uri_.getPath()) + e->getName();
		mol::bstr path(wp);
		hr = idoFactory->Add( path,(long)(e->fileinfo.getSize()),e->isDir() ? VARIANT_TRUE : VARIANT_FALSE );
		if ( hr != S_OK )
			return 0;
	}

	idoFactory->ToClipboard();

	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScpListCtrl::Paste ()
{	
	std::vector<int> vi        = selectionIndexes();
	ScpListEntry* e = 0;

	if ( vi.size() > 0 )
	{
		e = getItemEntry(vi[0]);
	}

	mol::Uri uri( mol::toUTF8(path_) );
	std::string host = uri.getHost();
	int port = uri.getPort();
	std::string p = uri.getPath();

	std::wstring path = mol::towstring(p);
	if ( e )
	{
		path += e->getName();
	}

	mol::format_etc_pref_dropeffect	fe;
	STGMEDIUM					sm;

	mol::punk<IDataObject> ido;
	::OleGetClipboard(&ido);
	if (!ido)
		return S_OK;

	std::vector<std::wstring> v;
	v = vectorFromDataObject(ido);

	if ( v.size() < 1 )
		return S_OK;

	DWORD  dw = DROPEFFECT_COPY;
	DWORD* d = &dw;

	if ( S_OK == ido->GetData( &fe, &sm ) )
	{
		if ( sm.tymed == TYMED_HGLOBAL )
		{
			mol::global glob;
			glob.attach(sm.hGlobal);
	
			*d = *((DWORD*)glob.lock());
	
			glob.unLock();
			glob.detach();
		}
	}

	// only copy for now
	
	if (*d & DROPEFFECT_COPY )
	{
		if(connect(&conn_))
		{
			queue_.push(new ScpPushFileQueueAction(path,v,this));
		}
	}
	else if (*d & DROPEFFECT_MOVE )
	{
		return S_OK;
	}
	mol::format_etc_dropeffect fede;
	mol::StgMedium stgm(*d, GHND|GMEM_SHARE);
	ido->SetData(&fede,&stgm,TRUE);
	return S_OK;
}
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////

int ScpListCtrl::getItemByPath(const std::wstring& path)
{
    int i = -1;
    while ( (i = list_.getNextItem(i,LVNI_ALL)) != -1 )
    {
        ScpListEntry* entry = getItemEntry(i);
		std::wstring tmp = path_;
		if ( path_[path_.size()-1] != _T('/') )
			tmp += _T("/");
		tmp += entry->filename;

        if ( tmp == path )
            return i;
        list_.getNextItem(i,LVNI_ALL);
    }
    return i;
}

//////////////////////////////////////////////////////////////////////////////

ScpListEntry* ScpListCtrl::getItemEntry(int i )
{
	int x = list_.getItemCount();
	if ( (i == -1) || (i < list_.getItemCount()) )
	{
		return (ScpListEntry*)list_.getItemLPARAM(i);
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////////

std::wstring ScpListCtrl::getItemPath(int i)
{
	ScpListEntry* entry = getItemEntry(i);
	if ( entry )
	{
		std::wstring tmp = path_;
		if ( path_[path_.size()-1] != _T('/') )
			tmp += _T("/");
		tmp += entry->getName();
		return tmp;
	}
	return _T("");
}

//////////////////////////////////////////////////////////////////////////////

void ScpListCtrl::clear()
{
    for ( int i = 0; i < list_.getItemCount(); i++ )
    {
		ScpListEntry* entry = getItemEntry(i);
        delete entry;
    }
	list_.deleteAllItems();
}
//////////////////////////////////////////////////////////////////////////////

std::vector<std::wstring> ScpListCtrl::selectionPaths()
{
	int index = -1;
	std::vector<std::wstring> v;
	while ( (index = list_.getNextItem(index)) != -1 )
	{
		v.push_back( getItemPath(index) );
	}
    return v;
}

//////////////////////////////////////////////////////////////////////////////

std::vector<int> ScpListCtrl::selectionIndexes()
{
	int index = -1;
	std::vector<int> v;
	while ( (index = list_.getNextItem(index)) != -1 )
	{
		v.push_back(index);
	}
    return v;
}

//////////////////////////////////////////////////////////////////////////////


std::vector<ScpListEntry*> ScpListCtrl::selectionEntries()
{
	int index = -1;
	std::vector<ScpListEntry*> v;
	while ( (index = list_.getNextItem(index)) != -1 )
	{
		v.push_back( getItemEntry(index));
	}
    return v;
}

//////////////////////////////////////////////////////////////////////////////

bool  ScpListCtrl::doHitTest()
{
	int i = list_.hitTest();
	if ( i != -1 )
	{
		list_.setItemState(-1, 0, LVIS_CUT  );
		list_.setItemState(-1, 0, LVIS_SELECTED  );
		list_.setItemState( i, LVIS_SELECTED , LVIS_SELECTED );
		return true;
	}
	return false;
}

//////////////////////////////////////////////////////////////////////////////

void ScpListCtrl::setPath(const std::wstring& p)  
{ 
	path_ = p;
	setText(p); 
}

//////////////////////////////////////////////////////////////////////////////

std::wstring ScpListCtrl::getPath()
{
    return path_;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// User drops - 
//
//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScpListCtrl::ShellListCtrl_Drop::Drop( IDataObject* pDataObject, DWORD keyState, POINTL pt , DWORD* pEffect)
{
	mol::ImageList::drop(*list_);

	ScpListEntry* e = 0;

	int i = list_->list_.hitTest();
	if ( i != -1 )
		e = list_->getItemEntry(i);

	std::wstring path = mol::towstring(list_->uri_.getPath());
	if ( e && (!e->isDir()) )
	{
		path += e->getName();
	}

	std::vector<std::wstring> v;
	v = mol::vectorFromDataObject(pDataObject);

	if ( ((*pEffect) & DROPEFFECT_MOVE ) && (keyState & MK_CONTROL) )
	{
		return S_OK;
	}
	else if ( (*pEffect) & DROPEFFECT_COPY )
	{
		try {
			if(list_->connect(&list_->conn_))
			{
				list_->queue_.push(new ScpPushFileQueueAction(path,v,list_));
			}
		}
		catch(...)
		{
			return S_OK;
		}
		return S_OK;
	}

	mol::format_etc_dropeffect fede;
	mol::StgMedium sm(*pEffect, GHND|GMEM_SHARE);
	pDataObject->SetData(&fede,&sm,TRUE);

	*pEffect = DROPEFFECT_NONE;
	
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////

void ScpListCtrl::put( std::vector<std::wstring>& v, const std::wstring& path)
{
	try
	{
		mol::GIT git;
		mol::punk<ISSHConnection> conn;
		HRESULT hr = git.getInterface(gitSSHCookie_,&conn);
		if ( hr != S_OK )
			return;

		mol::punk<ISCP> scp;
		hr = conn->get_SCP(&scp);
		if( hr != S_OK )
			return;

		for( size_t i = 0; i < v.size(); i++)
		{
			std::wstringstream oss;
			oss << L"writing " << mol::towstring(v[i]);
			frame_->SetStatusText(oss.str().c_str());

			if ( mol::Path::isDir(v[i]) )
			{
				hr = scp->PushDirectory( mol::bstr( v[i]), mol::bstr(path) );
				if( hr != S_OK )
					return;
			}
			else
			{
				hr = scp->PushFile( mol::bstr( v[i]), mol::bstr(path) );
				if( hr != S_OK )
					return;
			}
		}
		load(path_);
	}
	catch(...)
	{
		ODBGS("WTF!?");
		return;
	}
	return;
}

//////////////////////////////////////////////////////////////////////////////

HRESULT  __stdcall ScpListCtrl::ShellListCtrl_Drop::DragEnter( IDataObject* , DWORD key , POINTL , DWORD* pEffect )
{
	*pEffect = DROPEFFECT_COPY;
	mol::ImageList::enterDrag(*list_);
    return S_OK;
}

//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScpListCtrl::ShellListCtrl_Drop::DragOver( DWORD key, POINTL, DWORD* pEffect )
{
	list_->setFocus();
	mol::ImageList::doDrag(*list_);

	int i = list_->list_.hitTest();
	if ( i != -1 )
	{
		mol::ImageList::leaveDrag(*list_);
		list_->list_.setItemState(-1,0);
		list_->list_.setItemState(i,LVIS_SELECTED);
		list_->update();
		mol::ImageList::enterDrag(*list_);			
	}
	*pEffect = DROPEFFECT_COPY;
    return S_OK;
}

//////////////////////////////////////////////////////////////////////////////

HRESULT  __stdcall ScpListCtrl::ShellListCtrl_Drop::DragLeave()
{
	mol::ImageList::leaveDrag(*list_);
    return S_OK;
}
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// selection
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScpListCtrl::get_Selection		( BSTR* dirname )
{
	if ( dirname )
	{
		std::vector<ScpListEntry*>v = selectionEntries();
		if ( v.size() > 0 )
		{
			ScpListEntry* tmp = v[0];
			*dirname = ::SysAllocString(tmp->filename.c_str());
		}
	}
	return S_OK;
}

HRESULT __stdcall ScpListCtrl::get_Location		( BSTR* dirname )
{
	if ( dirname )
	{
		*dirname = ::SysAllocString(getPath().c_str());
	}
	return S_OK;
}

HRESULT __stdcall ScpListCtrl::put_Location		( BSTR  dirname )
{
	if ( dirname )
	{
		path_ = mol::towstring(dirname);
		load(path_);
		
		this->OnChanged(2);
	}
	return S_OK;
}

HRESULT __stdcall ScpListCtrl::get_Connection		( IDispatch** conn )
{
	if ( conn )
	{
		return conn_.queryInterface(conn);
	}
	return S_OK;
}

HRESULT __stdcall ScpListCtrl::put_Connection		( IDispatch* conn )
{
	if ( conn )
	{
		conn_.release();
		return conn->QueryInterface(IID_ISSHConnection,(void**)&conn_);
	}
	return S_OK;
}
HRESULT __stdcall ScpListCtrl::get_HasFocus( VARIANT_BOOL* vbHasFocus)
{
	if ( vbHasFocus )
	{
		if ( list_.hasFocus() )
		{
			*vbHasFocus = VARIANT_TRUE;
		}
		else
		{
			*vbHasFocus = VARIANT_FALSE;
		}
	}
	return S_OK;
}

HRESULT __stdcall ScpListCtrl::CopyTo(BSTR dir)
{

	return S_OK;
}


HRESULT __stdcall ScpListCtrl::Load( LPSTREAM pStm)
{
	pStm >> mol::property( &sizel );
	return S_OK;
}

HRESULT __stdcall ScpListCtrl::Save( LPSTREAM pStm,BOOL fClearDirty)
{
	pStm << mol::property( &sizel );
	return S_OK;
}

HRESULT __stdcall ScpListCtrl::Load( IPropertyBag *pPropBag,IErrorLog *pErrorLog)
{
	pPropBag >> mol::property( _T("cs"), &sizel );
	return S_OK;
}

HRESULT __stdcall ScpListCtrl::Save( IPropertyBag *pPropBag,BOOL fClearDirty,BOOL fSaveAllProperties)
{
	pPropBag << mol::property( _T("cs"), &sizel );
	return S_OK;
}


void ScpListCtrl::initAmbientProperties( IDispatch* disp)
{
	HIMAGELIST himl = ListView_GetImageList(list_,TVSIL_NORMAL);
	COLORREF col;
	mol::variant v(bgCol_);
	if ( S_OK == get(disp,DISPID_AMBIENT_BACKCOLOR,&v) )
	{
		bgCol_ = v.lVal;			
		::OleTranslateColor(bgCol_,0,&col);
		ListView_SetBkColor(list_,col);
		ImageList_SetBkColor(himl,CLR_NONE );
		ListView_SetTextBkColor(list_,col);
	}

	if ( S_OK == get(disp,DISPID_AMBIENT_FORECOLOR,&v) )
	{
		foreCol_ = v.lVal;
		::OleTranslateColor(foreCol_,0,&col);
		ListView_SetTextColor(list_,col);			
	}
}
