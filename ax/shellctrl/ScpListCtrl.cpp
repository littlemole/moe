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

/*
EncryptedMemory::EncryptedMemory()
	:encrypted_(0),size_(0)
{

}

EncryptedMemory::~EncryptedMemory()
{
	dispose();
}

void EncryptedMemory::dispose()
{
	if ( encrypted_ )
	{
		::LocalFree(encrypted_);
		encrypted_ = 0;
		size_ = 0;
	}
}

size_t EncryptedMemory::encrypt( void* data, size_t size, DWORD flags )
{
	static std::string padding('X',CRYPTPROTECTMEMORY_BLOCK_SIZE);

	dispose();

	size_ = size;

	DWORD mod = size % CRYPTPROTECTMEMORY_BLOCK_SIZE;
	if ( mod )
	{
		size_ = size_ + (CRYPTPROTECTMEMORY_BLOCK_SIZE-mod);
	}

	encrypted_ = ::LocalAlloc(LPTR,size_);
	ZeroMemory(encrypted_,size_);
	memcpy( encrypted_, data, size);

	if (!::CryptProtectMemory( encrypted_, (DWORD)size_,flags))
	{
		throw mol::X("CryptProtectMemory failed!");
	}
	return size;
}

std::string EncryptedMemory::decrypt( DWORD flags )
{
	void* v = malloc(size_);
	if(!v)
		return "";

	memcpy(v,encrypted_,size_);

	if (::CryptUnprotectMemory(v,(DWORD)size_,flags))
	{
		std::string s( (char*)v, size_ );
		return s;
	}
	free(v);
	return "";
}

void* EncryptedMemory::data()
{
	return encrypted_;
}

size_t EncryptedMemory::size()
{
	return size_;
}

EncryptedMap::EncryptedMap()
{
}

void EncryptedMap::encrypt(const EncryptedMap::MapType& map)
{
	std::wostringstream oss;
	for ( MapType::const_iterator it = map.begin(); it!=map.end(); it++)
	{
		oss << (*it).first << L'\0' << (*it).second << L'\0';
	}

	std::wstring tmp(oss.str());

	secure_.encrypt( (void*)tmp.data(), tmp.size()*sizeof(wchar_t) );
}

EncryptedMap::MapType EncryptedMap::decrypt()
{
	MapType map;
	std::string tmp = secure_.decrypt();
	// but it is really a wstr
	std::wstring plain( (wchar_t*)(tmp.data()), tmp.size()/sizeof(wchar_t));
	size_t pos = 0;
	size_t p   = 0;

	while( pos != std::wstring::npos && p < plain.size() )
	{
		pos = plain.find(L'\0',p);
		if ( pos == std::wstring::npos || pos == p)
			break;

		std::wstring key = plain.substr(p,pos-p);
		if(key.empty())
			break;

		p = plain.find(L'\0',pos+1);
		if ( p == std::wstring::npos || p == pos+1)
			break;

		std::wstring val = plain.substr(pos+1,p-pos);
		if(val.empty())
			break;

		map.insert( std::make_pair(key,val) );

		p = p + 1;
	}
	return map;
}


///////////////////////////////////////////////////////////////////////////////

SecureCredentials::SecureCredentials( const mol::string& h, int p, const mol::string& u, const mol::string& pass)
		: host(h),port(p)
{

	EncryptedMap::MapType map;
	map.insert( std::make_pair(std::wstring(L"user"),std::wstring(mol::towstring(u))));
	map.insert( std::make_pair(std::wstring(L"pwd"), std::wstring(mol::towstring(pass))));

	secure_.encrypt(map);
}

SecureCredentials::~SecureCredentials()
{
}


void SecureCredentials::decrypt( mol::string& u, mol::string& pass )
{
	EncryptedMap::MapType map = secure_.decrypt();

	if ( map.count(L"user") > 0 )
		u = map[L"user"];

	if ( map.count(L"pwd") > 0 )
		pass = map[L"pwd"];
}


///////////////////////////////////////////////////////////////////////////////


HRESULT __stdcall ScpPasswordCredentials::put_Username( BSTR user)
{
	if ( user )
	{
		EncryptedMap::MapType map = secure_.decrypt();
		map.insert( std::make_pair(L"user", mol::towstring(user)) );
		secure_.encrypt(map);
	}
	return S_OK;
}

HRESULT __stdcall ScpPasswordCredentials::get_Username( BSTR* user)
{
	if ( !user )
		return E_INVALIDARG;
	*user = 0;

	EncryptedMap::MapType map = secure_.decrypt();
	if ( map.count(L"user") > 0 )
	{
		*user = ::SysAllocString( map[L"user"].c_str() );			
	}
	return S_OK;
}

HRESULT __stdcall ScpPasswordCredentials::put_Password( BSTR pwd)
{
	if ( pwd )
	{
		EncryptedMap::MapType map = secure_.decrypt();
		map.insert( std::make_pair(L"pwd", mol::towstring(pwd)) );
		secure_.encrypt(map);
	}
	return S_OK;
}

HRESULT __stdcall ScpPasswordCredentials::get_Password( BSTR* pwd)
{
	if ( !pwd )
		return E_INVALIDARG;

	*pwd = 0;

	EncryptedMap::MapType map = secure_.decrypt();
	if ( map.count(L"pwd") > 0 )
	{
		*pwd = ::SysAllocString( map[L"pwd"].c_str() );			
	}

	return S_OK;
}

*/



class PermissionDlg  : public mol::win::Dialog
{
public:

	PermissionDlg(const mol::string& filename, int perm, int own, int grp)
		: filename_(filename), permission_(perm), owner_(own), group_(grp)
	{}

	virtual LRESULT wndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message)
		{
			case WM_INITDIALOG:
			{
				setDlgItemText(IDC_SCP_PROP_EDIT_FILENAME,filename_);
				mol::ostringstream oss;
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
					mol::string s;
					getDlgItemText(IDC_SCP_PROP_EDIT_PERMISSION,s);
					mol::istringstream iss(s);
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
	

	mol::string filename_;
	int permission_;
	int owner_;
	int group_;

};

class RemoteExecDlg  : public mol::win::Dialog
{
public:

	RemoteExecDlg(const mol::string& host, int port, mol::ssh::CredentialCallback* cb)
		: host_(host), port_(port), cb_(cb)
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
					mol::string s;
					getDlgItemText(IDC_EDIT_SSH_EXEC_CMD,s);
					if ( s.empty())
					{
						return FALSE;
					}

					mol::string o = exec_cmd(s);
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

	
	mol::string cli()
	{
		return cli_;
	}

	mol::string out()
	{
		return out_;
	}
private:

	mol::string exec_cmd( const mol::string& cmd)
	{

		try
		{
			mol::ssh::Session ssh;
			ssh.open( mol::toUTF8(host_),cb_,port_);
			return mol::fromUTF8( ssh.exec_remote(mol::toUTF8(cmd)) );			
		}
		catch(...)
		{
			return _T("");
		}
	}

	mol::string cli_;
	mol::string out_;
	mol::string host_;
	int port_;

	mol::ssh::CredentialCallback* cb_;
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



ScpDirQueueLoadAction::ScpDirQueueLoadAction( const mol::string& p, ScpListCtrl* dl )
	: path(p), scpList(dl)
{}

void ScpDirQueueLoadAction::operator()()
{
	scpList->load_async(path);
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

ScpUnlinkQueueAction::ScpUnlinkQueueAction( const std::vector<mol::string>& vec, ScpListCtrl* dl )
	: v(vec), scpList(dl)
{}

void ScpUnlinkQueueAction::operator()()
{
	scpList->unlink(v);
}

///////////////////////////////////////////////////////////////////////////////

ScpListCtrl::ScpListCtrl(void)	
{
//	sortDir_ = 1;
//    bCancel_ = FALSE;
//	displayFiles_ = true;
	sharedMenu_ = 0;
	eraseBackground_ = 1;
	gitCookie_ = 0;

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

//mol::ssh::Session&
/*
bool ScpListCtrl::connect( const mol::Uri& uri)
{
	if ( ssh_ )
	{
		VARIANT_BOOL vb;
		HRESULT hr = ssh_->get_IsConnected(&vb);
		if(hr == S_OK)
		{
			if ( vb == VARIANT_TRUE )
			{
				mol::bstr host;
				long port;
				hr = ssh_->get_Hostname(&host);
				if ( hr == S_OK )
				{
					hr = ssh_->get_Portnumber(&port);
					if ( hr == S_OK )
					{
						if ( uri.getHost() == mol::toUTF8(host.bstr_) &&
							 uri.getPort() == port )
						{
							return true;
						}
					}
				}
			}
		}
		ssh_->Release();
	}

	mol::punk<ISSH> factory;
	HRESULT hr = factory.createObject(CLSID_SSH);
	if ( hr!=S_OK)
		return false;

	hr = factory->Connect( mol::bstr(mol::fromUTF8(uri.getHost())), uri.getPort(), &ssh_ );
	if ( hr!=S_OK)
		return false;

	return true;

	if ( ssh_.is_connected() )
	{
		if ( ssh_.hostname() == uri.getHost() &&
			 ssh_.port() == uri.getPort() )
		{
			return ssh_;
		}
	}

	ssh_.dispose();

	mol::punk<IOleInPlaceFrame> oip; 
	mol::GIT git;
	HRESULT hr = git.getInterface(gitCookie_,&oip);
	if ( hr != S_OK )
		return ssh_;

	std::string host = uri.getHost();
	int port = uri.getPort();
	std::string p = uri.getPath();

	std::wstringstream oss;
	oss << L"connecting to " << mol::fromUTF8(host) << L":" << port;
	oip->SetStatusText(oss.str().c_str());

	ssh_.open( mol::toUTF8(host),&credentials_,port);

	std::wstringstream oss2;
	oss2 << L"connected to " << mol::fromUTF8(host) << L":" << port;
	oip->SetStatusText(oss2.str().c_str());

	return ssh_;
}

mol::sftp::Session& ScpListCtrl::open(const mol::Uri& uri)
{
	mol::ssh::Session& ssh = connect(uri);

	mol::punk<IOleInPlaceFrame> oip; 
	mol::GIT git;
	HRESULT hr = git.getInterface(gitCookie_,&oip);
	if ( hr != S_OK )
		return sftp_;

	oip->SetStatusText(L"establishing sftp connection");

	sftp_.dispose();
	sftp_.open(ssh);
	return sftp_;
}
*/
void ScpListCtrl::load( const mol::string& url )
{
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
					mol::toString(name), 
					type, perms, 
					uid, gid, 
					mtime, size, 
					owner.bstr_ ? mol::toString(owner) : _T("") , 
					group.bstr_ ? mol::toString(group) : _T("") 
			);
}

void ScpListCtrl::load_async( const mol::string& url )
{
	clear();

	mol::GIT git;

	mol::punk<IOleInPlaceFrame> oip; 
	HRESULT hr = git.getInterface(gitCookie_,&oip);
	if ( hr != S_OK )
		return;

	mol::punk<IUnknown> unk; 
	hr = git.getInterface(gitSSHCookie_,&unk);
	if ( hr != S_OK )
		return;

	mol::punk<ISSH> ssh(unk);
	if(!unk)
		return;

	mol::string path = url;
	if ( path[path.size()-1] != _T('/') )
	{
		path = path + _T("/");
	}

	uri_.set(mol::toUTF8(path));

    std::vector<mol::string> files;
    std::vector<mol::string> dirs;

    std::map<mol::string, ScpListEntry*> filesMap;
	std::map<mol::string, ScpListEntry*> dirsMap;

	try
	{
		//mol::sftp::Session& sftp = open(uri_);

		mol::punk<ISSHConnection> conn;
		hr = ssh->Connect( mol::bstr(mol::fromUTF8(uri_.getHost())), uri_.getPort(), &conn);
		if( hr != S_OK )
			return;

		mol::punk<ISFTP> sftp;
		hr = conn->get_SFTP(&sftp);
		if( hr != S_OK )
			return;

		mol::string grr(path);
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

		mol::TCHAR buf[MAX_PATH];
		::GetTempPath(MAX_PATH,buf);
		int dirIcon = mol::io::ShellInfo::Icon(buf);

		SAFEARRAY* sa;
		hr = sftp->List( mol::bstr( mol::fromUTF8(uri_.getPath())), &sa);
		if( hr != S_OK )
			return;

		mol::SafeArray<VT_DISPATCH> safeArray;
		safeArray.Attach(sa);

		{
			mol::SFAccess<VARIANT> sf(sa);

			ListView_SetItemCount(list_,sf.size());

			for ( size_t i = 0; i < sf.size(); i++)
			{
				mol::punk<IRemoteFile> rf(sf[i].pdispVal);

				mol::bstr n;
				hr = rf->get_Filename(&n);
				if( hr != S_OK )
				{
					return;
				}

				mol::string name = mol::toString(n.bstr_);

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
					mol::string tmp(buf);
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
		}
	}
	catch(mol::ssh::Ex& ex)
	{
		std::wstringstream oss;
		oss << L"failed to open " << mol::towstring(path) << L" " << mol::towstring(ex.msg());
		oip->SetStatusText(oss.str().c_str());

		uri_.set(mol::toUTF8(path_));
	}
	catch(...)
	{
		uri_.set(mol::toUTF8(path_));
		return;
	}

	path_ = path;
	uri_.set(mol::toUTF8(path));

	std::sort( files.begin(), files.end() );
	std::sort( dirs.begin(), dirs.end()   );

    int index = 0;
    list_.setRedraw(false);
	for ( std::vector<mol::string>::iterator iter = dirs.begin(); iter != dirs.end(); iter++ )
	{
		mol::string p(*iter);
        std::vector<mol::string> entries;
        ScpListEntry* entry = dirsMap[*iter];

		entries.push_back( entry->fileinfo.getName() );
		entries.push_back( entry->fileinfo.formattedSize() );
		entries.push_back( entry->fileinfo.formattedPermissions() );
		entries.push_back( entry->fileinfo.getOwner() );
		entries.push_back( entry->fileinfo.getGroup() );

//		uint32_t t = entry->fileinfo.getMtime();
	//	char* ct = ctime((time_t*)&t);
		entries.push_back(mol::toString(""));

        list_.insertItem(entries,index,0,entry->iconindex,(LPARAM)entry);
        index++;
	}

	for ( std::vector<mol::string>::iterator iter = files.begin(); iter != files.end(); iter++ )
	{
		mol::string p(*iter);
        std::vector<mol::string> entries;
        ScpListEntry* entry = filesMap[*iter];

		entries.push_back( entry->fileinfo.getName() );
		entries.push_back( entry->fileinfo.formattedSize() );
		entries.push_back( entry->fileinfo.formattedPermissions() );
		entries.push_back( entry->fileinfo.getOwner() );
		entries.push_back( entry->fileinfo.getGroup() );

		long t = entry->fileinfo.getMtime();
		char* ct = ctime((time_t*)&t);
		entries.push_back(mol::toString(ct));

        list_.insertItem(entries,index,0,entry->iconindex,(LPARAM)entry);
        index++;
	}

	oip->SetStatusText(mol::fromUTF8(uri_.getPath()).c_str());

	list_.setRedraw(true);
	list_.redraw();
	fire(DISPID_ISHELLLISTEVENTS_ONDIRCHANGED,mol::bstr(path_));
	
	//sortDir_ = 1;
	//sortCol_ = 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// OnDestroy - over and out
//
//////////////////////////////////////////////////////////////////////////////

LRESULT ScpListCtrl::OnDestroy(UINT msg, WPARAM wParam, LPARAM lParam)
{
	queue_.cancel();
	provider_.release();
	clear();
	mol::GIT git;
	git.revokeInterface(gitCookie_);
	git.revokeInterface(gitSSHCookie_);
	ssh_.release();
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

	provider_.createObject(CLSID_DefaultScpCredentialProvider,CLSCTX_ALL);
	::CoAllowSetForegroundWindow(provider_,0);


	//mol::punk<ISSH> ssh;
	HRESULT hr = ssh_.createObject(CLSID_SSH,CLSCTX_ALL);
	if( hr != S_OK )
		return 0;

	git.registerInterface( *ssh_, &gitSSHCookie_);
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
	//sort(message.listview()->iSubItem);
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
		mol::string p(entry->filename);
		if ( entry->isDir() )
		{
			mol::string name =entry->fileinfo.getName();
			if ( name == _T("..") )
			{
				UpDir();
				return 0;
			}			
			load(p);
		}        
		else
		{
			this->fire(DISPID_ISHELLLISTEVENTS_ONLISTDBLCLICK,mol::bstr(entry->filename));
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

void ScpListCtrl::EndRename(const mol::string& oldpath, const mol::string& newpath)
{
	mol::punk<IOleInPlaceFrame> oip; 
	mol::GIT git;
	HRESULT hr = git.getInterface(gitCookie_,&oip);
	if ( hr != S_OK )
		return;

	//mol::Uri uri( mol::toUTF8(path_) );
	//std::string host = uri.getHost();
	//int port = uri.getPort();
	//std::string p = uri.getPath();

	mol::string pFrom( mol::fromUTF8(uri_.getPath()) ); 
	pFrom += oldpath;

	mol::string tmp = pFrom;
	size_t pos = pFrom.find_last_of(_T("/"));
	if ( pos != std::string::npos )
		tmp = pFrom.substr(0,pos+1);

	mol::string pTo(tmp);
	pTo += mol::string(newpath);

	try 
	{
		//mol::sftp::Session& sftp = open(uri_);

		mol::punk<ISSH> ssh;
		HRESULT hr = ssh.createObject(CLSID_SSH);
		if( hr != S_OK )
			return;

		mol::punk<ISSHConnection> conn;
		hr = ssh->Connect( mol::bstr(mol::fromUTF8(uri_.getHost())), uri_.getPort(), &conn);
		if( hr != S_OK )
			return;

		mol::punk<ISFTP> sftp;
		hr = conn->get_SFTP(&sftp);
		if( hr != S_OK )
			return;


		if(sftp->Rename( mol::bstr(pFrom), mol::bstr(pTo) ))
		{
			load(path_);
		}
		else
		{
			std::wstringstream oss;
			oss << L"failed to rename " << mol::towstring(pFrom);
			oip->SetStatusText(oss.str().c_str());
		}
	}
	catch(mol::ssh::Ex& ex)
	{
		std::wstringstream oss;
		oss << L"failed to rename " << mol::towstring(pFrom) << L" " << mol::towstring(ex.msg());
		oip->SetStatusText(oss.str().c_str());
	}
	catch(...)
	{
		std::wstringstream oss;
		oss << L"failed to rename " << mol::towstring(pFrom);
		oip->SetStatusText(oss.str().c_str());
	}
}

LRESULT ScpListCtrl::OnEndRename(UINT msg, WPARAM wParam, LPARAM lParam)
{
	mol::Crack message(msg,wParam,lParam);
	if ( message.listviewDispInfo()->item.pszText)
	{
		mol::string displayname = message.listviewDispInfo()->item.pszText;

		mol::string path= getItemEntry(message.listviewDispInfo()->item.iItem)->fileinfo.getName();
		EndRename(path,displayname);
	}
	return 0;
}


//////////////////////////////////////////////////////////////////////////////

LRESULT ScpListCtrl::OnBeginDrag(UINT msg, WPARAM wParam, LPARAM lParam)
{	
	std::vector<mol::string> v = selectionPaths();

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

	ScpListEntry* e = getItemEntry(vi[0]);

	//mol::Uri uri( mol::toUTF8(path_) );
	//std::string host = uri.getHost();
	//int port = uri.getPort();
	//std::string p = uri.getPath();

	mol::ImageList::beginDrag(*this,hi);

	mol::punk<mol::com_obj<mol::scp::DelayedDataTransferObj> > ido  = 
		new mol::com_obj<mol::scp::DelayedDataTransferObj>;

	ido->init( mol::fromUTF8(uri_.getHost()), uri_.getPort(), &credentials_);
	unsigned long long s = e->fileinfo.getSize();
	ido->add( mol::fromUTF8(uri_.getPath()) + e->getName(),s,e->isDir() );

	for ( size_t i = 1; i < vi.size(); i++ )
	{
		e = getItemEntry(vi[i]);
		ido->add( mol::fromUTF8(uri_.getPath()) + e->getName(),e->fileinfo.getSize(),e->isDir() );
	}

	DWORD effect;
	mol::punk<IDropSource> drop = new mol::DropSrc;
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
				mol::string tmp(entry->filename);
				this->fire(DISPID_ISHELLLISTEVENTS_ONLISTOPEN,mol::bstr(tmp));
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
	mol::string tmp = path_;
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
	queue_.push(new ScpCreateDirQueueAction(this));
	return S_OK;
}

void ScpListCtrl::mkdir()
{
	mol::punk<IOleInPlaceFrame> oip; 
	mol::GIT git;
	HRESULT hr = git.getInterface(gitCookie_,&oip);
	if ( hr != S_OK )
		return;

	//mol::Uri uri( mol::toUTF8(path_) );
	//std::string host = uri.getHost();
	//int port = uri.getPort();
	std::string p = uri_.getPath();

	if ( p[p.size()-1] != '/' )
		p += "/";

	try
	{
		//mol::sftp::Session& sftp = open(uri_);

		mol::punk<ISSH> ssh;
		HRESULT hr = ssh.createObject(CLSID_SSH,CLSCTX_ALL);
		if( hr != S_OK )
			return;

		mol::punk<ISSHConnection> conn;
		hr = ssh->Connect( mol::bstr(mol::fromUTF8(uri_.getHost())), uri_.getPort(), &conn);
		if( hr != S_OK )
			return;

		mol::punk<ISFTP> sftp;
		hr = conn->get_SFTP(&sftp);
		if( hr != S_OK )
			return;

		SAFEARRAY* sa;

		hr = sftp->Files( mol::bstr(mol::fromUTF8(p)),&sa);
		if( hr != S_OK )
			return;

		mol::SafeArray<VT_BSTR> safeArray;
		safeArray.Attach(sa);

		mol::string tmp = _T("newDir_");	
		int i = 0;
		while(true)
		{
			mol::stringstream oss;
			oss << tmp << i;
			mol::string newDir = oss.str();

			bool exists = false;
			mol::SFAccess<BSTR> sf(sa);
			for ( size_t c = 0; c <sf.size(); c++)
			{
				mol::string name = mol::toString(sf[c]);
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
	catch(mol::ssh::Ex& ex)
	{
		std::wstringstream oss;
		oss << L"failed to create new dir " << mol::towstring(ex.msg());
		oip->SetStatusText(oss.str().c_str());
	}
	catch(...)
	{
		oip->SetStatusText(L"failed to create new dir");
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

	std::vector<mol::string> tmp;
	for(size_t i = 0; i < v.size(); i++)
	{
		tmp.push_back(v[i]->filename);
	}

	queue_.push( new ScpUnlinkQueueAction(tmp,this) );

	return S_OK;
}

void ScpListCtrl::unlink( const std::vector<mol::string>& v )
{
	if ( v.empty() )
		return;

	mol::punk<IOleInPlaceFrame> oip; 
	mol::GIT git;
	HRESULT hr = git.getInterface(gitCookie_,&oip);
	if ( hr != S_OK )
		return;

	try 
	{
		//mol::sftp::Session& sftp = open(uri_);

		mol::punk<ISSH> ssh;
		HRESULT hr = ssh.createObject(CLSID_SSH,CLSCTX_ALL);
		if( hr != S_OK )
			return;

		mol::punk<ISSHConnection> conn;
		hr = ssh->Connect( mol::bstr(mol::fromUTF8(uri_.getHost())), uri_.getPort(), &conn);
		if( hr != S_OK )
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

//			mol::sftp::RemoteFile rf = sftp.stat(mol::fromUTF8(p));

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
	}
	catch(...)
	{
		std::wstringstream oss;
		oss << L"failure while deleting remote files ";
		oip->SetStatusText(oss.str().c_str());
		return;
	}
	load(path_);
	return;
}

HRESULT __stdcall ScpListCtrl::Properties()
{	
	std::vector<mol::string> v = selectionPaths();

	if ( v.size() > 0 )
	{
		mol::string path = v[0];

		try 
		{
			mol::Uri uri( mol::toUTF8(path) );
			std::string host = uri.getHost();
			int port = uri.getPort();
			std::string p = uri.getPath();

			//mol::sftp::Session& sftp = open(uri_);

			mol::punk<ISSH> ssh;
			HRESULT hr = ssh.createObject(CLSID_SSH,CLSCTX_ALL);
			if( hr != S_OK )
				return hr;

			mol::punk<ISSHConnection> conn;
			hr = ssh->Connect( mol::bstr(mol::fromUTF8(uri_.getHost())), uri_.getPort(), &conn);
			if( hr != S_OK )
				return hr;

			mol::punk<ISFTP> sftp;
			hr = conn->get_SFTP(&sftp);
			if( hr != S_OK )
				return hr;

			frame_->SetStatusText(path.c_str());

			//mol::sftp::RemoteFile rf = sftp.stat(mol::fromUTF8(p));

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
					//sftp->CHM
					//sftp.chmod(mol::fromUTF8(p),perm);
				}
				if ( owner != ow|| group != gr )
				{
					hr = sftp->Chown( mol::bstr(mol::fromUTF8(p)), ow, gr );
					if( hr != S_OK )
						return hr;
					//sftp.chown(mol::fromUTF8(p),owner,group);
				}
				load(path_);
			}
		}
		catch(...)
		{
			std::wstringstream oss;
			oss << L"failure showing properties ";
			this->frame_->SetStatusText(oss.str().c_str());
			return S_FALSE;
		}		
	}
	
	return S_OK;
}

HRESULT __stdcall ScpListCtrl::Execute()
{
	mol::Uri uri( mol::toUTF8(path_) );
	std::string host = uri.getHost();
	int port = uri.getPort();

	RemoteExecDlg dlg(mol::fromUTF8(host),port,&credentials_);
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
	std::string host = uri.getHost();
	int port = uri.getPort();
	std::string p = uri.getPath();

	mol::punk<IDropSource> drop = new mol::DropSrc;
	mol::punk<mol::com_obj<mol::scp::DelayedDataTransferObj> >ido  = 
		new mol::com_obj<mol::scp::DelayedDataTransferObj>;

	ido->init( mol::fromUTF8(host), port, &credentials_);

	for ( size_t i = 0; i < vi.size(); i++ )
	{
		e = getItemEntry(vi[i]);
		unsigned long long s = e->fileinfo.getSize();
		ido->add(mol::fromUTF8(p)+e->getName(),s,e->isDir() );
	}

	HRESULT r = ::OleSetClipboard(ido);		
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

	mol::string path = mol::toString(p);
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

	std::vector<mol::string> v;
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
		try {

			this->put(v,path);

			/*
			std::wstringstream oss;
			oss << L"connecting to " << mol::fromUTF8(host) << L":" << port;
			this->frame_->SetStatusText(oss.str().c_str());

			mol::ssh::Session ssh;
			if (!ssh.open(host,&credentials_,port))
				return S_OK;

			mol::scp::Session scp(ssh);
			if(!scp.open(mol::SSH_SCP_WRITE|mol::SSH_SCP_RECURSIVE,path) )
			{
				return S_OK;
			}

			for( size_t i = 0; i < v.size(); i++)
			{

				std::wstringstream oss;
				oss << L"^writing " << mol::towstring(v[i]);
				this->frame_->SetStatusText(oss.str().c_str());

				if ( mol::Path::isDir(v[i]) )
				{
					if (!scp.push_dir(v[i], 0700))
						break;
				}
				else
				{
					if (!scp.push_file( v[i], 0600))
						break;
				}
			}
			this->Update();
			*/
		}
		catch(...)
		{
			return S_OK;
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

int ScpListCtrl::getItemByPath(const mol::string& path)
{
    int i = -1;
    while ( (i = list_.getNextItem(i,LVNI_ALL)) != -1 )
    {
        ScpListEntry* entry = getItemEntry(i);
		mol::string tmp = path_;
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

mol::string ScpListCtrl::getItemPath(int i)
{
	ScpListEntry* entry = getItemEntry(i);
	if ( entry )
	{
		mol::string tmp = path_;
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

std::vector<mol::string> ScpListCtrl::selectionPaths()
{
	int index = -1;
	std::vector<mol::string> v;
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

void ScpListCtrl::setPath(const mol::string& p)  
{ 
	path_ = p;
	setText(p); 
}

//////////////////////////////////////////////////////////////////////////////

mol::string ScpListCtrl::getPath()
{
    return path_;
}

//////////////////////////////////////////////////////////////////////////////

/*
BOOL ShellListCtrl::sort(int c)
{
	sortDir_ *= -1;
    sortCol_  = c;
    return ListView_SortItems( list_, CompareFunc, (LPARAM)this );
}
*/
//////////////////////////////////////////////////////////////////////////////

/*
int CALLBACK ShellListCtrl::CompareFunc(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
    ShellListCtrl* pThis = (ShellListCtrl*)lParamSort;
    if ( pThis )
        return pThis->compare(lParam1, lParam2);
    return 0;
}
//////////////////////////////////////////////////////////////////////////////

int ShellListCtrl::compare(LPARAM lParam1, LPARAM lParam2)
{
    DirListEntry* de1 = (DirListEntry*)lParam1;
    DirListEntry* de2 = (DirListEntry*)lParam2;
    if ( !de1 || !de2)
        return -1*sortDir_;

    if (de1->isDir() && !de2->isDir() )
        return -1;

    if (!de1->isDir() && de2->isDir() )
        return 1;

    if ( sortCol_ == 0 )
    {
		std::string s1(mol::tostring(de1->filename) );
		std::string s2(mol::tostring(de2->filename) );
        return _stricmp( s1.c_str(), s2.c_str() )*sortDir_;
        // p1 before p2
    }
    else if ( sortCol_ == 1 )
    {
        if ( de1->fileinfo.fileSizeHigh() < de2->fileinfo.fileSizeHigh() )
            return -1*sortDir_;
        if ( de1->fileinfo.fileSizeHigh() > de2->fileinfo.fileSizeHigh() )
            return 1*sortDir_;
        if ( de1->fileinfo.fileSizeLow() < de2->fileinfo.fileSizeLow() )
            return -1*sortDir_;
        if ( de1->fileinfo.fileSizeLow() > de2->fileinfo.fileSizeLow() )
            return 1*sortDir_;
        return 0;
    }
    else if ( sortCol_ == 2 )
    {
        if ( de1->fileinfo.lastWriteTime().dwHighDateTime  < de2->fileinfo.lastWriteTime().dwHighDateTime  )
            return -1*sortDir_;
        if ( de1->fileinfo.lastWriteTime().dwHighDateTime  > de2->fileinfo.lastWriteTime().dwHighDateTime  )
            return 1*sortDir_;
        if ( de1->fileinfo.lastWriteTime().dwLowDateTime  < de2->fileinfo.lastWriteTime().dwLowDateTime  )
            return -1*sortDir_;
        if ( de1->fileinfo.lastWriteTime().dwLowDateTime  > de2->fileinfo.lastWriteTime().dwLowDateTime  )
            return 1*sortDir_;
        return 0;
    }
    return -1*sortDir_;
}
*/
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

	//mol::Uri uri( mol::toUTF8(list_->path_) );
	//std::string host = uri.getHost();
	//int port = uri.getPort();
	//std::string p = uri.getPath();

	mol::string path = mol::toString(list_->uri_.getPath());
	if ( e && (!e->isDir()) )
	{
		path += e->getName();
	}

	std::vector<mol::string> v;
	v = mol::vectorFromDataObject(pDataObject);

	if ( ((*pEffect) & DROPEFFECT_MOVE ) && (keyState & MK_CONTROL) )
	{
		return S_OK;
	}
	else if ( (*pEffect) & DROPEFFECT_COPY )
	{
		try {

			list_->put(v,path);

			/*
			std::wstringstream oss;
			oss << L"connecting to " << mol::fromUTF8(host) << L":" << port;
			list_->frame_->SetStatusText(oss.str().c_str());

			mol::ssh::Session ssh;
			if (!ssh.open( host, &(list_->credentials_), port))
			{
				return S_OK;
			}

			mol::scp::Session scp(ssh);
			if(!scp.open(mol::SSH_SCP_WRITE|mol::SSH_SCP_RECURSIVE,path) )
			{
				return S_OK;
			}

			for( size_t i = 0; i < v.size(); i++)
			{
				std::wstringstream oss;
				oss << L"writing " << mol::towstring(v[i]);
				list_->frame_->SetStatusText(oss.str().c_str());

				if ( mol::Path::isDir(v[i]) )
				{
					if (!scp.push_dir( v[i],0700))
						break;
				}
				else
				{
					if (!scp.push_file( v[i],0600))
						break;
				}
			}
			list_->Update();
			*/
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

void ScpListCtrl::put( std::vector<mol::string>& v, const mol::string& path)
{
	try
	{
		//mol::Uri uri( mol::toUTF8(path_) );
		//std::string host = uri.getHost();
		//int port = uri.getPort();
		//std::string p = uri.getPath();

		//mol::ssh::Session& ssh = connect(uri_);

		mol::punk<ISSH> ssh;
		HRESULT hr = ssh.createObject(CLSID_SSH,CLSCTX_ALL);
		if( hr != S_OK )
			return;

		mol::punk<ISSHConnection> conn;
		hr = ssh->Connect( mol::bstr(mol::fromUTF8(uri_.getHost())), uri_.getPort(), &conn);
		if( hr != S_OK )
			return;

		mol::punk<ISCP> scp;
		hr = conn->get_SCP(&scp);
		if( hr != S_OK )
			return;


		//mol::scp::Session scp(ssh);
		//scp.open(mol::SSH_SCP_WRITE|mol::SSH_SCP_RECURSIVE,mol::towstring(path));
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
				//if (!scp.push_dir( v[i],0700))
					//break;
			}
			else
			{
				hr = scp->PushFile( mol::bstr( v[i]), mol::bstr(path) );
				if( hr != S_OK )
					return;

				//if (!scp.push_file( v[i],0600))
					//break;
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
	//(*pEffect) &= (DROPEFFECT_COPY|DROPEFFECT_MOVE);
	//if ( key & MK_CONTROL )
	//	*pEffect = DROPEFFECT_MOVE;
	//else
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
	//(*pEffect) &= (DROPEFFECT_COPY|DROPEFFECT_MOVE);
	//if ( key & MK_CONTROL )
	//	*pEffect = DROPEFFECT_MOVE;
	//else
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
		path_ = mol::toString(dirname);
		load(path_);
		
		this->OnChanged(2);
	}
	return S_OK;
}

///////////////////////////////////////////////////////////////////////
// displayfiles
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScpListCtrl::get_CredentialProvider	( IDispatch** provider )
{
	if ( provider )
	{
		return provider_.queryInterface(provider);
	}
	return S_FALSE;
}

HRESULT __stdcall ScpListCtrl::put_CredentialProvider	( IDispatch* provider  )
{
	if ( provider )
	{
		return provider->QueryInterface(IID_IScpCredentialProvider,(void**)&provider_);
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


bool ScpListCtrl::Credentials::getCredentials(const std::string& host, int port, char** user, char** pwd)
{
	//if ( !This()->provider_ )
//		return false;

	if(!user||!pwd)
		return false;

	mol::punk<IScpCredentialProvider> provider;
	provider.createObject(CLSID_DefaultScpCredentialProvider,CLSCTX_ALL);
	::CoAllowSetForegroundWindow(provider,0);

	mol::punk<IScpPasswordCredentials> creds;
	HRESULT hr = provider->getCredentials( mol::bstr(host), port, &creds );
	if ( hr != S_OK )
		return false;

	mol::bstr bu;
	creds->get_Username(&bu);

	mol::bstr bp;
	creds->get_Password(&bp);

	//TODO: wipe bstrs ???

	std::string u = mol::toUTF8(bu.bstr_);
	std::string p = mol::toUTF8(bp.bstr_);

	*user = (char*)malloc(u.size()+1);
	*pwd  = (char*)malloc(p.size()+1);

	memcpy( *user, u.data(), u.size()+1);
	memcpy( *pwd,  p.data(), p.size()+1);

	return true;
}

bool ScpListCtrl::Credentials::promptCredentials(const std::string& host, int port,const std::string& prompt, const std::string& desc,char** value,bool echo)
{
	
	return false;
}

bool ScpListCtrl::Credentials::acceptHost(const std::string& host, int port, const std::string& hash)
{
	//if ( !This()->provider_ )
		//return false;

	mol::punk<IScpCredentialProvider> provider;
	provider.createObject(CLSID_DefaultScpCredentialProvider,CLSCTX_ALL);
	::CoAllowSetForegroundWindow(provider,0);

	VARIANT_BOOL vb;
	HRESULT hr = provider->acceptHost( mol::bstr(mol::fromUTF8(host)), port, mol::bstr(mol::fromUTF8(hash)), &vb );
	if ( hr != S_OK )
		return false;

	if ( vb == VARIANT_TRUE )
		return true;

	return true;
}

bool ScpListCtrl::Credentials::rememberHostCredentials(const std::string& host, int port, const char* user, const char* pwd)
{
	//if ( !This()->provider_ )
		//return false;

	mol::punk<IScpCredentialProvider> provider;
	provider.createObject(CLSID_DefaultScpCredentialProvider,CLSCTX_ALL);
	::CoAllowSetForegroundWindow(provider,0);


	mol::punk<IScpPasswordCredentials> creds;
	HRESULT hr = creds.createObject(CLSID_ScpPasswordCredentials);
	if ( hr != S_OK )
		return false;

	creds->put_Username( mol::bstr(mol::fromUTF8(user)) );
	creds->put_Password( mol::bstr(mol::fromUTF8(pwd)) );
	
	hr = provider->remberSessionCredentials( mol::bstr(mol::fromUTF8(host)), port, creds );
	if ( hr != S_OK )
		return false;

	return true;
}

bool ScpListCtrl::Credentials::deleteHostCredentials(const std::string& host, int port)
{
//	if ( !This()->provider_ )
	//	return false;

	mol::punk<IScpCredentialProvider> provider;
	provider.createObject(CLSID_DefaultScpCredentialProvider,CLSCTX_ALL);
	::CoAllowSetForegroundWindow(provider,0);


	HRESULT hr = provider->removeSessionCredentials(mol::bstr(mol::fromUTF8(host)), port);
	if ( hr != S_OK )
		return false;

	return true;
}

