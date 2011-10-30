#include "stdafx.h"
#include "ScpListCtrl.h"
#include "ole/Bstr.h"
#include "ole/enum.h"
#include "ole/Img.h"
#include "util/str.h"
#include "ShellCtrl_Dispid.h"
#include <sstream>
#include "tcp/sockets.h"
#include "win/shell.h"
#include "ssh/scpDataTransferObj.h"
#include "Resource.h"

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


class PwdDlg  : public mol::win::Dialog
{
public:

	PwdDlg(const mol::string& host, int port)
		: host_(host), port_(port)
	{}

	mol::string user;
	mol::string pwd;

	virtual LRESULT wndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message)
		{
			case WM_INITDIALOG:
			{
				setDlgItemText(IDC_EDIT_HOST,host_.c_str());
				setDlgItemInt(IDC_EDIT_PORT,port_);
				this->center();
				return FALSE; // note: false! look into PSDK!
			}
			case WM_COMMAND:
			{
				if (LOWORD(wParam) == IDOK )
				{
					getDlgItemText(IDC_EDIT_USER,user);
					getDlgItemText(IDC_EDIT_PWD,pwd);
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

private:

	mol::string host_;
	int port_;

};

class AccepHostDlg  : public mol::win::Dialog
{
public:

	AccepHostDlg(const mol::string& host, int port, const mol::string& hash)
		: host_(host), port_(port), hash_(hash)
	{}

	virtual LRESULT wndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message)
		{
			case WM_INITDIALOG:
			{
				mol::ostringstream oss;
				oss << _T("Do you want to trust host ") << host_ << _T(" port ") << port_ << _T("?");
				setDlgItemText(IDC_STATIC_UNKNOWN_HOST_MSG,oss.str());
				setDlgItemText(IDC_EDIT_HOST_HASH,hash_);
				this->center();
				return FALSE; // note: false! look into PSDK!
			}
			case WM_COMMAND:
			{
				if (LOWORD(wParam) == IDOK )
				{
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

private:

	mol::string host_;
	int port_;
	mol::string hash_;
};



///////////////////////////////////////////////////////////////////////////////

ScpListCtrl::ScpListCtrl(void)	
{
//	sortDir_ = 1;
//    bCancel_ = FALSE;
//	displayFiles_ = true;
	sharedMenu_ = 0;
	eraseBackground_ = 1;

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

//mol::ssh::PasswordCredentials credentials("","");

void ScpListCtrl::load( const mol::string& url )
{
	clear();

	mol::string path = url;
	if ( path[path.size()-1] != _T('/') )
	{
		path = path + _T("/");
	}


	mol::Uri uri( mol::tostring(path) );
	std::string user = uri.getUser();
	std::string pwd= uri.getPwd();
	std::string host = uri.getHost();
	int port = uri.getPort();
	std::string p = uri.getPath();

    std::vector<mol::string> files;
    std::vector<mol::string> dirs;

    std::map<mol::string, ScpListEntry*> filesMap;
	std::map<mol::string, ScpListEntry*> dirsMap;

	try
	{
		std::wstringstream oss;
		oss << L"connecting to " << mol::towstring(host) << L":" << port;
		this->frame_->SetStatusText(oss.str().c_str());

		mol::ssh::Session ssh;
		if (!ssh.open(host,&credentials_,port))
		{
			return;
		}

		std::wstringstream oss2;
		oss2 << L"retrieving " << mol::towstring(p);
		this->frame_->SetStatusText(oss2.str().c_str());

		mol::sftp::Session sftp;
		if(!sftp.open(ssh))
		{
			return;
		}

		mol::string grr(path);
		if ( grr[grr.size()-1] == _T('/') )
			grr = grr.substr(0,grr.size()-1);

		mol::sftp::RemoteFile rf = sftp.stat( mol::tostring(p) );
		if ( !rf.isDir() )
			return;

		mol::TCHAR buf[MAX_PATH];
		::GetTempPath(MAX_PATH,buf);
		int dirIcon = mol::io::ShellInfo::Icon(buf);

		std::vector<mol::sftp::RemoteFile> v = sftp.list(p);

		ListView_SetItemCount(list_,v.size());

		for ( size_t i = 0; i < v.size(); i++)
		{
			if ( v[i].getName() == _T(".") )
				continue;

			if ( v[i].isDir() )
			{
				ScpListEntry* entry = new ScpListEntry(path + v[i].getName(),v[i],dirIcon);
				dirs.push_back(v[i].getName());
				dirsMap.insert( std::make_pair(v[i].getName(),entry) );
			}
			else
			{
				mol::string tmp(buf);
				tmp += v[i].getName();

				SHFILEINFO  shInfo;
				DWORD att = FILE_ATTRIBUTE_NORMAL;
				::SHGetFileInfo( tmp.c_str(),att,&shInfo,sizeof(shInfo),SHGFI_ICON|SHGFI_SMALLICON|SHGFI_USEFILEATTRIBUTES |SHGFI_TYPENAME);
				::DestroyIcon(shInfo.hIcon);
				int icon = shInfo.iIcon;

				ScpListEntry* entry = new ScpListEntry(path + v[i].getName(),v[i],icon);
				files.push_back(v[i].getName());
				filesMap.insert( std::make_pair(v[i].getName(),entry) );
			}
		}
	}
	catch(...)
	{
		return;
	}

	path_ = path;

	std::sort( files.begin(), files.end() );
	std::sort( dirs.begin(), dirs.end()   );

    int index = 0;
    list_.setRedraw(false);
	for ( std::vector<mol::string>::iterator iter = dirs.begin(); iter != dirs.end(); iter++ )
	{
		mol::string p(*iter);
        std::vector<mol::string> entries;
        ScpListEntry* entry = dirsMap[*iter];
		entries.push_back(entry->fileinfo.getName());
		entries.push_back(entry->fileinfo.formattedSize());
		entries.push_back(entry->fileinfo.formattedPermissions());
		entries.push_back(entry->fileinfo.getOwner());
		entries.push_back(entry->fileinfo.getGroup());

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
		entries.push_back(entry->fileinfo.getName());
        entries.push_back(entry->fileinfo.formattedSize());
		entries.push_back(entry->fileinfo.formattedPermissions());
		entries.push_back(entry->fileinfo.getOwner());
		entries.push_back(entry->fileinfo.getGroup());

		uint32_t t = entry->fileinfo.getMtime();
		char* ct = ctime((time_t*)&t);
		entries.push_back(mol::toString(ct));

        list_.insertItem(entries,index,0,entry->iconindex,(LPARAM)entry);
        index++;
	}

	::ShowScrollBar(list_,SB_VERT,TRUE);
	list_.setFocus();
	list_.show(SW_SHOW);
	list_.setRedraw(true);

	this->fire(DISPID_ISHELLLISTEVENTS_ONDIRCHANGED,mol::bstr(path_));
	
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
	provider_.release();
	clear();
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
			if ( entry->fileinfo.getName() == _T("..") )
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

LRESULT ScpListCtrl::OnEndRename(UINT msg, WPARAM wParam, LPARAM lParam)
{
	mol::Crack message(msg,wParam,lParam);
	if ( message.listviewDispInfo()->item.pszText)
	{
		mol::Uri uri( mol::tostring(path_) );
		std::string user = uri.getUser();
		std::string pwd= uri.getPwd();
		std::string host = uri.getHost();
		int port = uri.getPort();
		std::string p = uri.getPath();

		mol::string pFrom( mol::toString(p) ); 
		pFrom += getItemEntry(message.listviewDispInfo()->item.iItem)->fileinfo.getName();

		mol::string tmp = pFrom;
		size_t pos = pFrom.find_last_of(_T("/"));
		if ( pos != std::string::npos )
			tmp = pFrom.substr(0,pos+1);

		mol::string pTo(tmp);
		pTo += mol::string(message.listviewDispInfo()->item.pszText);

		std::wstringstream oss;
		oss << L"connecting to " << mol::towstring(host) << L":" << port;
		this->frame_->SetStatusText(oss.str().c_str());

		try {
			mol::ssh::Session ssh;
			if (!ssh.open(host,&credentials_,port))
			{
				std::wstringstream oss;
				oss << L"failed to connect to " << mol::towstring(host) << L":" << port;
				this->frame_->SetStatusText(oss.str().c_str());
				return S_FALSE;
			}

			std::wstringstream oss2;
			oss2 << L"renaming " << mol::towstring(pTo);
			this->frame_->SetStatusText(oss2.str().c_str());

			mol::sftp::Session sftp;
			if(!sftp.open(ssh))
			{
				std::wstringstream oss;
				oss << L"failed to rename " << mol::towstring(pFrom);
				this->frame_->SetStatusText(oss.str().c_str());
				return S_FALSE;
			}

			if(sftp.rename( mol::tostring(pFrom), mol::tostring(pTo) ))
			{
				load(path_);
			}
			else
			{
				std::wstringstream oss;
				oss << L"failed to rename " << mol::towstring(pFrom);
				this->frame_->SetStatusText(oss.str().c_str());
			}
		}
		catch(...)
		{
			std::wstringstream oss;
			oss << L"failed to rename " << mol::towstring(pFrom);
			this->frame_->SetStatusText(oss.str().c_str());
		}
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
		HIMAGELIST hh = ImageList_Merge(hi,0,h,0,0,20*i);
		ImageList_Destroy(hi);
		ImageList_Destroy(h);
		hi = hh;
	}

	ScpListEntry* e = getItemEntry(vi[0]);

	mol::Uri uri( mol::tostring(path_) );
	std::string user = uri.getUser();
	std::string pwd= uri.getPwd();
	std::string host = uri.getHost();
	int port = uri.getPort();
	std::string p = uri.getPath();

	mol::punk<IDropSource> drop = new mol::DropSrc;
	mol::punk<mol::com_obj<mol::scp::DelayedDataTransferObj> > ido  = 
		new mol::com_obj<mol::scp::DelayedDataTransferObj>;

	ido->init( mol::toString(host), port, &credentials_);
	ido->add( mol::toString(p) + e->fileinfo.getName() );

	for ( size_t i = 1; i < vi.size(); i++ )
	{
		e = getItemEntry(vi[i]);

		mol::Uri uri( mol::tostring(path_) );
		std::string user = uri.getUser();
		std::string pwd= uri.getPwd();
		std::string host = uri.getHost();
		int port = uri.getPort();
		std::string p = uri.getPath();

		ido->add( mol::toString(p) + e->fileinfo.getName() );
	}

	mol::ImageList::beginDrag(*this,hi);

	DWORD effect;
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
	mol::Uri uri( mol::tostring(path_) );
	std::string user = uri.getUser();
	std::string pwd= uri.getPwd();
	std::string host = uri.getHost();
	int port = uri.getPort();
	std::string p = uri.getPath();

	if ( p[p.size()-1] != '/' )
		p += "/";

	std::wstringstream oss;
	oss << L"connecting to " << mol::towstring(host) << L":" << port;
	this->frame_->SetStatusText(oss.str().c_str());

	mol::ssh::Session ssh;
	if (!ssh.open(host,&credentials_,port))
	{
		std::wstringstream oss;
		oss << L"failed to connect to " << mol::towstring(host) << L":" << port;
		this->frame_->SetStatusText(oss.str().c_str());
		return S_FALSE;
	}

	std::wstringstream oss2;
	oss2 << L"creating new dir";
	this->frame_->SetStatusText(oss2.str().c_str());

	mol::sftp::Session sftp;
	if(!sftp.open(ssh))
	{
		std::wstringstream oss;
		oss << L"failed to create new dir ";
		this->frame_->SetStatusText(oss.str().c_str());
		return S_FALSE;
	}

	std::vector<mol::sftp::RemoteFile> v = sftp.list( p );
	
	mol::string tmp = _T("newDir_");	
	int i = 0;
	while(true)
	{
		mol::stringstream oss;
		oss << tmp << i;
		mol::string newDir = oss.str();

		bool exists = false;
		for ( size_t c = 0; c < v.size(); c++)
		{
			if ( newDir == v[c].getName() )
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

		if (!sftp.mkdir( p + mol::tostring( newDir), 0700 ))
		{
			std::wstringstream oss;
			oss << L"failed to create new dir " << newDir;
			this->frame_->SetStatusText(oss.str().c_str());
			return S_FALSE;
		}

		this->Update();
		return S_OK;
	}

	return S_OK;
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
		return 0;
	}

	try 
	{
		mol::string path(v[0]->filename);

		mol::Uri uri( mol::tostring(path) );
		std::string host = uri.getHost();
		int port = uri.getPort();

		std::wstringstream oss;
		oss << L"connecting to " << mol::towstring(host) << L":" << port;
		this->frame_->SetStatusText(oss.str().c_str());

		mol::ssh::Session ssh;
		if (!ssh.open(host,&credentials_,port))
		{
			std::wstringstream oss;
			oss << L"failed to connect ";
			this->frame_->SetStatusText(oss.str().c_str());
			return S_FALSE;
		}

		mol::sftp::Session sftp;
		if(!sftp.open(ssh))
		{
			std::wstringstream oss;
			oss << L"failed to open sftp session ";
			this->frame_->SetStatusText(oss.str().c_str());
			return S_FALSE;
		}

		for ( size_t i = 0; i < v.size(); i++)
		{
			mol::string path(v[i]->filename);

			mol::Uri uri( mol::tostring(path) );
			std::string p = uri.getPath();

			mol::sftp::RemoteFile rf = sftp.stat(p);

			if ( rf.isDir() )
			{
				if (!sftp.rmdir(p))
				{
					continue;
				}
			}
			else
			{
				if(!sftp.unlink(p))
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
		this->frame_->SetStatusText(oss.str().c_str());
		return S_FALSE;
	}
	load(path_);
	return S_OK;
}

HRESULT __stdcall ScpListCtrl::Properties()
{
	/*
	std::vector<mol::string> v = selectionPaths();

	if ( v.size() > 0 )
	{
		execute_shell( v[0], _T("properties"),1,SEE_MASK_INVOKEIDLIST );		
	}
	*/
	return S_OK;
}

HRESULT __stdcall ScpListCtrl::Execute()
{
	/*
	std::vector<mol::string> v = selectionPaths();

	if ( v.size() > 0 )
	{
		execute_shell( v[0] );		
	}
	*/
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
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScpListCtrl::Copy ()
{
	std::vector<int> vi        = selectionIndexes();

	if ( vi.size() != 1 )
		return 0;

	ScpListEntry* e = getItemEntry(vi[0]);

	mol::Uri uri( mol::tostring(path_) );
	std::string host = uri.getHost();
	int port = uri.getPort();
	std::string p = uri.getPath();

	mol::punk<IDropSource> drop = new mol::DropSrc;
	mol::punk<mol::com_obj<mol::scp::DelayedDataTransferObj> >ido  = 
		new mol::com_obj<mol::scp::DelayedDataTransferObj>;

	ido->init( mol::toString(host), port, &credentials_);

	for ( size_t i = 0; i < vi.size(); i++ )
	{
		e = getItemEntry(vi[i]);
		ido->add(mol::toString(p)+e->fileinfo.getName() );
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

	mol::Uri uri( mol::tostring(path_) );
	std::string user = uri.getUser();
	std::string pwd= uri.getPwd();
	std::string host = uri.getHost();
	int port = uri.getPort();
	std::string p = uri.getPath();

	mol::string path = mol::toString(p);
	if ( e )
	{
		path += e->fileinfo.getName();
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

			std::wstringstream oss;
			oss << L"connecting to " << mol::towstring(host) << L":" << port;
			this->frame_->SetStatusText(oss.str().c_str());

			mol::ssh::Session ssh;
			if (!ssh.open(host,&credentials_,port))
				return S_OK;

			mol::scp::Session scp(ssh);
			if(!scp.open(mol::SSH_SCP_WRITE|mol::SSH_SCP_RECURSIVE,mol::tostring(path)) )
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
					if (!scp.push_dir( mol::tostring(v[i]),0700))
						break;
				}
				else
				{
					if (!scp.push_file( mol::tostring(v[i]),0600))
						break;
				}
			}
			this->Update();
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
		tmp += entry->fileinfo.getName();
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

	mol::Uri uri( mol::tostring(list_->path_) );
	std::string user = uri.getUser();
	std::string pwd= uri.getPwd();
	std::string host = uri.getHost();
	int port = uri.getPort();
	std::string p = uri.getPath();

	mol::string path = mol::toString(p);
	if ( e && (!e->isDir()) )
	{
		path += e->fileinfo.getName();
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

			std::wstringstream oss;
			oss << L"connecting to " << mol::towstring(host) << L":" << port;
			list_->frame_->SetStatusText(oss.str().c_str());

			mol::ssh::Session ssh;
			if (!ssh.open(host,&(list_->credentials_),port))
			{
				return S_OK;
			}

			mol::scp::Session scp(ssh);
			if(!scp.open(mol::SSH_SCP_WRITE|mol::SSH_SCP_RECURSIVE,mol::tostring(path)) )
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
					if (!scp.push_dir( mol::tostring(v[i]),0700))
						break;
				}
				else
				{
					if (!scp.push_file( mol::tostring(v[i]),0600))
						break;
				}
			}
			list_->Update();
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

HRESULT __stdcall ScpListCtrl::get_CredentialProvider	( IScpCredentialProvider** provider )
{
	if ( provider )
	{
		return provider_.queryInterface(provider);
	}
	return S_FALSE;
}

HRESULT __stdcall ScpListCtrl::put_CredentialProvider	( IScpCredentialProvider* provider  )
{
	if ( provider )
	{
		provider_ = provider;
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
//	pStm >> mol::property( mol::DispId(this,ShellListCtrl_Dispatch_DisplayFiles,VT_BOOL) )
//		 >> mol::property( mol::DispId(this,ShellListCtrl_Dispatch_Selection,VT_BSTR) )
//		 >> mol::property( &sizel );

	return S_OK;
}

HRESULT __stdcall ScpListCtrl::Save( LPSTREAM pStm,BOOL fClearDirty)
{
//	pStm << mol::property( mol::DispId(this,ShellListCtrl_Dispatch_DisplayFiles,VT_BOOL) )
//		 << mol::property( mol::DispId(this,ShellListCtrl_Dispatch_Selection,VT_BSTR) )
//		 << mol::property( &sizel );

	return S_OK;
}

HRESULT __stdcall ScpListCtrl::Load( IPropertyBag *pPropBag,IErrorLog *pErrorLog)
{
//	pPropBag >> mol::property( _T("displayfiles"), mol::DispId(this,ShellListCtrl_Dispatch_DisplayFiles,VT_BOOL) )
//			 >> mol::property( _T("selection"), mol::DispId(this,ShellListCtrl_Dispatch_Selection,VT_BSTR) )
//			 >> mol::property( _T("cs"), &sizel );

	return S_OK;
}

HRESULT __stdcall ScpListCtrl::Save( IPropertyBag *pPropBag,BOOL fClearDirty,BOOL fSaveAllProperties)
{
//	pPropBag << mol::property( _T("displayfiles"), mol::DispId(this,ShellListCtrl_Dispatch_DisplayFiles,VT_BOOL) )
//			 << mol::property( _T("selection"), mol::DispId(this,ShellListCtrl_Dispatch_Selection,VT_BSTR) )
//			 << mol::property( _T("cs"), &sizel );

	return S_OK;
}


bool ScpListCtrl::Credentials::getCredentials(const std::string& host, int port, std::string& user, std::string& pwd)
{
	if ( !This()->provider_ )
		return false;

	mol::punk<IScpPasswordCredentials> creds;
	HRESULT hr = This()->provider_->getCredentials( mol::bstr(host), port, &creds );
	if ( hr != S_OK )
		return false;

	mol::bstr u;
	creds->get_Username(&u);

	mol::bstr p;
	creds->get_Password(&p);

	user = mol::tostring(u);
	pwd  = mol::tostring(p);

	return true;
}

bool ScpListCtrl::Credentials::promptCredentials(const std::string& host, int port,const std::string& prompt, const std::string& desc,std::string& value,bool echo)
{
	
	return false;
}

bool ScpListCtrl::Credentials::acceptHost(const std::string& host, int port, const std::string& hash)
{
	if ( !This()->provider_ )
		return false;

	VARIANT_BOOL vb;
	HRESULT hr = This()->provider_->acceptHost( mol::bstr(host), port, mol::bstr(hash), &vb );
	if ( hr != S_OK )
		return false;

	if ( vb == VARIANT_TRUE )
		return true;

	return true;
}

bool ScpListCtrl::Credentials::rememberHostCredentials(const std::string& host, int port, const std::string& user, const std::string& pwd)
{
	if ( !This()->provider_ )
		return false;

	mol::punk<IScpPasswordCredentials> creds;
	HRESULT hr = creds.createObject(CLSID_ScpPasswordCredentials);
	if ( hr != S_OK )
		return false;

	creds->put_Username( mol::bstr(user) );
	creds->put_Password( mol::bstr(pwd) );
	
	hr = This()->provider_->remberSessionCredentials( mol::bstr(host), port, creds );
	if ( hr != S_OK )
		return false;

	return true;
}

bool ScpListCtrl::Credentials::deleteHostCredentials(const std::string& host, int port)
{
	if ( !This()->provider_ )
		return false;

	HRESULT hr = This()->provider_->removeSessionCredentials(mol::bstr(host), port);
	if ( hr != S_OK )
		return false;

	return true;
}


HRESULT __stdcall ScpCredentialProvider::getCredentials( BSTR host, long port, IScpPasswordCredentials** credentials)
{
	if (!credentials)
		return E_INVALIDARG;

	mol::string h = mol::toString(host);

	if ( credentials_.count( h ) != 0 )
	{
		Credentials* creds = credentials_[h];
		mol::punk<IScpPasswordCredentials> c;
		HRESULT hr = c.createObject(CLSID_ScpPasswordCredentials);
		if ( hr == S_OK )
		{
			c->put_Username( mol::bstr(creds->user) );
			c->put_Password( mol::bstr(creds->pwd) );
			return c.queryInterface(credentials);
		}
	}

	*credentials = 0;

	PwdDlg dlg( h, port );
	LRESULT r = dlg.doModal( IDD_SCP_PWD_DIALOG, ::GetDesktopWindow() );
	if ( r != IDOK )
	{
		return S_FALSE;
	}

	mol::punk<IScpPasswordCredentials> c;
	HRESULT hr = c.createObject(CLSID_ScpPasswordCredentials);
	if ( hr == S_OK )
	{
		c->put_Username( mol::bstr(dlg.user) );
		c->put_Password( mol::bstr(dlg.pwd) );
		return c.queryInterface(credentials);
	}

	return S_OK;
}

HRESULT __stdcall ScpCredentialProvider::acceptHost( BSTR host, long port, BSTR hash, VARIANT_BOOL* accept)
{
	if (!accept)
		return E_INVALIDARG;

	AccepHostDlg dlg( mol::toString(host), port, mol::toString(hash) );

	LRESULT r = dlg.doModal( IDD_DIALOG_SSH_ACCEPT_HOST, ::GetDesktopWindow() );

	if ( r == IDOK )
		*accept = VARIANT_TRUE;
	else
		*accept = VARIANT_FALSE;

	return S_OK;
}

