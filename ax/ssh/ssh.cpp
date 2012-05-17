#include "stdafx.h"
#include "ssh.h"
#include "ssh/sftp.h"
#include "ssh/scp.h"
#include "tcp/sockets.h"
#include "ole/dll.h"
#include "ssh_i.c"
#include "resource.h"


CredentialManager& credentialManager()
{
	return mol::singleton<CredentialManager>();
}

////////////////////////////////////////////////////////////////////////


SSHRemoteFile::Instance* SSHRemoteFile::createInstance( const mol::sftp::RemoteFile& rf)
{
	SSHRemoteFile::Instance* instance = new Instance;
	instance->rf_ = rf;
	return instance;
}

void SSHRemoteFile::dispose()
{
}

HRESULT __stdcall  SSHRemoteFile::get_IsDir( VARIANT_BOOL *vb)
{
	if(!vb)
		return E_INVALIDARG;

	*vb = rf_.isDir() ? VARIANT_TRUE : VARIANT_FALSE;
	return S_OK;
}

HRESULT __stdcall  SSHRemoteFile::get_Filename( BSTR *name)
{
	if(!name)
		return E_INVALIDARG;

	*name = ::SysAllocString( mol::towstring(rf_.getName()).c_str() );
	return S_OK;
}

HRESULT __stdcall  SSHRemoteFile::get_Filetype( long *type)
{
	if(!type)
		return E_INVALIDARG;

	*type = rf_.getType();
	return S_OK;
}

HRESULT __stdcall  SSHRemoteFile::get_Permission( long *perms)
{
	if(!perms)
		return E_INVALIDARG;

	*perms = rf_.getPermissions();
	return S_OK;
}

HRESULT __stdcall  SSHRemoteFile::get_UID( long *id)
{
	if(!id)
		return E_INVALIDARG;

	*id = rf_.getUID();
	return S_OK;
}

HRESULT __stdcall  SSHRemoteFile::get_GID( long *id)
{
	if(!id)
		return E_INVALIDARG;

	*id = rf_.getGID();
	return S_OK;
}

HRESULT __stdcall  SSHRemoteFile::get_Mtime( long *timestamp)
{
	if(!timestamp)
		return E_INVALIDARG;

	*timestamp = rf_.getMtime();
	return S_OK;
}

HRESULT __stdcall  SSHRemoteFile::get_Owner( BSTR *username)
{
	if(!username)
		return E_INVALIDARG;

	*username = ::SysAllocString( mol::towstring(rf_.getOwner()).c_str() );
	return S_OK;
}

HRESULT __stdcall  SSHRemoteFile::get_Group( BSTR *groupname)
{
	if(!groupname)
		return E_INVALIDARG;

	*groupname = ::SysAllocString( mol::towstring(rf_.getGroup()).c_str() );
	return S_OK;
}

HRESULT __stdcall  SSHRemoteFile::get_Size( long *len)
{
	if(!len)
		return E_INVALIDARG;

	*len = (long)rf_.getSize();
	return S_OK;
}

HRESULT __stdcall  SSHRemoteFile::get_FormattedSize( BSTR *len)
{
	if(!len)
		return E_INVALIDARG;

	*len = ::SysAllocString( mol::towstring(rf_.formattedSize()).c_str() );
	return S_OK;
}

HRESULT __stdcall  SSHRemoteFile::get_FormattedPermissions( BSTR *len)
{
	if(!len)
		return E_INVALIDARG;

	*len = ::SysAllocString( mol::towstring(rf_.formattedPermissions()).c_str() );
	return S_OK;
}


////////////////////////////////////////////////////////////////////////


SSHConnection::Instance* SSHConnection::createInstance( const mol::bstr& host, long port,mol::ssh::Session* session)
{
	SSHConnection::Instance* instance = new Instance;
	instance->hostname_ = host;
	instance->port_ = port;
	instance->ssh_ = session;
	return instance;
}

void SSHConnection::dispose()
{
	ssh_->dispose();
	delete ssh_;
}

HRESULT __stdcall SSHConnection::get_SCP( ISCP** conn)
{
	if (!conn)
		return E_INVALIDARG;

	*conn = 0;

	SCP::Instance* instance = SCP::createInstance(ssh_);
	return instance->QueryInterface(IID_ISCP,(void**)conn);
}

HRESULT __stdcall SSHConnection::get_SFTP( ISFTP** conn)
{
	if (!conn)
		return E_INVALIDARG;

	*conn = 0;

	SFTP::Instance* instance = SFTP::createInstance(ssh_);
	return instance->QueryInterface(IID_ISFTP,(void**)conn);
}


HRESULT __stdcall SSHConnection::get_Hostname( BSTR *host)
{
	if (!host)
		return E_INVALIDARG;

	*host = ::SysAllocString(hostname_.bstr_);
	return S_OK;
}

HRESULT __stdcall SSHConnection::get_Portnumber( long *port)
{
	if (!port)
		return E_INVALIDARG;

	*port = port_;
	return S_OK;
}

HRESULT __stdcall SSHConnection::get_IsConnected( VARIANT_BOOL *connected)
{
	if (!connected)
		return E_INVALIDARG;

	*connected = VARIANT_FALSE;

	if ( ssh_->is_connected() )
	{
		*connected = VARIANT_TRUE;
	}
	return S_OK;
}

HRESULT __stdcall SSHConnection::get_ServerBanner(BSTR *banner)
{
	if (!banner)
		return E_INVALIDARG;

	if ( !ssh_->is_connected() )
	{
		HRESULT hr = Connect();
		if ( hr != S_OK )
			return hr;
	}

	std::string s = ssh_->getServerBanner();
	*banner = ::SysAllocString( mol::fromUTF8(s).c_str() );

	return S_OK;
}

HRESULT __stdcall SSHConnection::get_Banner( BSTR *banner)
{
	if (!banner)
		return E_INVALIDARG;

	if ( !ssh_->is_connected() )
	{
		HRESULT hr = Connect();
		if ( hr != S_OK )
			return hr;
	}

	std::string s = ssh_->getBanner();
	*banner = ::SysAllocString( mol::fromUTF8(s).c_str() );
	return S_OK;
}

HRESULT __stdcall SSHConnection::get_ServerHash( BSTR *hash)
{
	if (!hash)
		return E_INVALIDARG;

	if ( !ssh_->is_connected() )
	{
		HRESULT hr = Connect();
		if ( hr != S_OK )
			return hr;
	}

	std::string s = ssh_->server_hash();
	*hash = ::SysAllocString( mol::fromUTF8(s).c_str() );
	return S_OK;
}

HRESULT __stdcall SSHConnection::get_Error(BSTR *err)
{
	if (!err)
		return E_INVALIDARG;

	if ( !ssh_->is_connected() )
	{
		*err = ::SysAllocString(L"not connected");
		return S_OK;
	}

	std::string s = ssh_->error();
	*err = ::SysAllocString( mol::fromUTF8(s).c_str() );
	return S_OK;
}

HRESULT __stdcall SSHConnection::Execute( BSTR cmd,BSTR *result)
{
	if (!cmd)
		return E_INVALIDARG;

	if (!result)
		return E_INVALIDARG;

	if ( !ssh_->is_connected() )
	{
		HRESULT hr = Connect();
		if ( hr != S_OK )
		{
			mol::com_throw( "could not connect", CLSID_SSH, "SSHConnection::Execute");
			return hr;
		}
	}

	try 
	{
		std::string s = ssh_->exec_remote(mol::toUTF8(cmd));
		*result = ::SysAllocString( mol::fromUTF8(s).c_str() );
		return S_OK;
	}
	catch(mol::ssh::Ex& ex)
	{
		mol::com_throw( ex.msg(), CLSID_SSH, "SSHConnection::execute");
	}
	catch(...)
	{}

	return S_FALSE;
}

HRESULT __stdcall SSHConnection::Send( BSTR cmd,BSTR data,BSTR *result)
{
	if (!cmd)
		return E_INVALIDARG;
	if (!data)
		return E_INVALIDARG;
	if (!result)
		return E_INVALIDARG;

	if ( !ssh_->is_connected() )
	{
		HRESULT hr = Connect();
		if ( hr != S_OK )
		{
			mol::com_throw( "could not connect", CLSID_SSH, "SSHConnection::Execute");
			return hr;
		}
	}

	try 
	{
		ssh_->send_data(mol::toUTF8(cmd),mol::toUTF8(data));
		*result = ::SysAllocString(L"" );
		return S_OK;
	}
	catch(mol::ssh::Ex& ex)
	{
		mol::com_throw( ex.msg(), CLSID_SSH, "SSHConnection::execute");
	}
	catch(...)
	{}

	return S_FALSE;
}

HRESULT __stdcall SSHConnection::UsernameFromUID( long uid,BSTR *result)
{
	if (!result)
		return E_INVALIDARG;

	if ( !ssh_->is_connected() )
	{
		HRESULT hr = Connect();
		if ( hr != S_OK )
		{
			mol::com_throw( "could not connect", CLSID_SSH, "SSHConnection::Execute");
			return hr;
		}
	}

	std::string s = ssh_->username(uid);
	*result = ::SysAllocString( mol::fromUTF8(s).c_str() );
	return S_OK;
}

HRESULT __stdcall SSHConnection::GroupnameFromGID( long gid,BSTR *result)
{
	if (!result)
		return E_INVALIDARG;

	if ( !ssh_->is_connected() )
	{
		HRESULT hr = Connect();
		if ( hr != S_OK )
		{
			mol::com_throw( "could not connect", CLSID_SSH, "SSHConnection::Execute");
			return hr;
		}
	}

	std::string s = ssh_->groupname(gid);
	*result = ::SysAllocString( mol::fromUTF8(s).c_str() );
	return S_OK;
}

HRESULT __stdcall SSHConnection::UIDfromUsername( BSTR name,long *result)
{
	if (!name)
		return E_INVALIDARG;

	if (!result)
		return E_INVALIDARG;

	if ( !ssh_->is_connected() )
	{
		HRESULT hr = Connect();
		if ( hr != S_OK )
		{
			mol::com_throw( "could not connect", CLSID_SSH, "SSHConnection::Execute");
			return hr;
		}
	}

	*result = ssh_->userid(mol::toUTF8(name));
	return S_OK;
}

HRESULT __stdcall SSHConnection::GIDfromGroupname( BSTR name,long *result)
{
	if (!name)
		return E_INVALIDARG;

	if (!result)
		return E_INVALIDARG;

	if ( !ssh_->is_connected() )
	{
		HRESULT hr = Connect();
		if ( hr != S_OK )
		{
			mol::com_throw( "could not connect", CLSID_SSH, "SSHConnection::Execute");
			return hr;
		}
	}

	*result = ssh_->groupid(mol::toUTF8(name));
	return S_OK;
}

HRESULT __stdcall SSHConnection::Connect()
{
	if ( ssh_->is_connected() )
	{
		return S_OK;
	}

	try
	{
		ssh_->open( mol::toUTF8(hostname_.bstr_), &credentialManager().credentials, port_ );
	}
	catch(mol::ssh::Ex& ex)
	{
		mol::com_throw(ex.msg(),CLSID_SSH,"SSHConnection::Connect");
		return S_FALSE;
	}
	catch(...)
	{
		return S_FALSE;
	}
	return S_OK;
}


////////////////////////////////////////////////////////////////

HRESULT __stdcall SSH:: Connect( BSTR hostname, long port, ISSHConnection **conn)
{
	if (!hostname)
		return E_INVALIDARG;

	if (!conn)
		return E_INVALIDARG;

	*conn = 0;

	mol::ssh::Session* session = new mol::ssh::Session;
	if(!conn)
		return S_FALSE;


	SSHConnection::Instance* c = SSHConnection::createInstance( mol::bstr(hostname), port,session );
	if (!c)
	{
		mol::com_throw(" SSHConnection::createInstance failed",CLSID_SSH,"SSH::Connect");
		return E_FAIL;
	}

	c->AddRef();

	HRESULT hr = c->Connect();
	if (hr != S_OK )
	{
		c->Release();
		mol::com_throw("failed to connection interface",CLSID_SSH,"SSH::Connect");
		return hr;
	}

	hr = c->QueryInterface(IID_ISSHConnection,(void**)conn);
	if (hr != S_OK )
	{
		c->Release();
		mol::com_throw("failed to connection interface",CLSID_SSH,"SSH::Connect");
		return hr;
	}
	c->Release();
	return S_OK;
}

////////////////////////////////////////////////////////////////

SCP::Instance* SCP::createInstance( mol::ssh::Session* session)
{
	SCP::Instance* instance = new Instance;
	instance->ssh_ = session;
	instance->mode_ = 0700;
	return instance;
}

void SCP::dispose()
{

}

HRESULT __stdcall  SCP::PushDirectory( BSTR path, BSTR remotedir)
{
	if(!path || !remotedir)
		return E_INVALIDARG;

	try
	{
		mol::scp::Session scp(*ssh_);
		scp.open(0x10,remotedir);
		scp.push_dir(path,mode_);
	}
	catch(...)
	{
		mol::com_throw("Push Directory failed",CLSID_SSH,"SCP::PushDirectory");
		return E_FAIL;
	}

	return S_OK;
}

HRESULT __stdcall  SCP::PushFile(  BSTR path, BSTR remotedir)
{
	if(!path || !remotedir)
		return E_INVALIDARG;

	try
	{
		mol::scp::Session scp(*ssh_);
		scp.open(0,remotedir);
		scp.push_file(path,mode_);
	}
	catch(...)
	{
		mol::com_throw("Push File failed",CLSID_SSH,"SCP::PushFile");
		return E_FAIL;
	}
	return S_OK;
}

HRESULT __stdcall  SCP::WriteFile(  BSTR content, BSTR remotedir)
{
	if(!content || !remotedir)
		return E_INVALIDARG;

	try
	{
		mol::scp::Session scp(*ssh_);
		scp.open(0,remotedir);
		scp.push_file( remotedir,mol::toUTF8(content),mode_);
	}
	catch(...)
	{
		mol::com_throw("Write file failed",CLSID_SSH,"SCP::WriteFile");
		return E_FAIL;
	}
	return S_OK;
}

HRESULT __stdcall   SCP::PutFile( SAFEARRAY * content, BSTR remotedir)
{
	if(!content || !remotedir)
		return E_INVALIDARG;

	try
	{
		mol::scp::Session scp(*ssh_);
		scp.open(0,remotedir);

		mol::SFAccess<BYTE> sfa(content);
		std::string s( (char*)sfa(),sfa.size());
		scp.push_file( remotedir,s,1);
	}
	catch(...)
	{
		mol::com_throw("Put file failed",CLSID_SSH,"SCP::PutFile");
		return E_FAIL;
	}
	return S_OK;
}

HRESULT __stdcall  SCP::PullDirectory(  BSTR remotedir, BSTR localdir)
{
	if(!remotedir || !localdir)
		return E_INVALIDARG;

	try
	{
		mol::scp::Session scp(*ssh_);
		scp.open(0x11,remotedir);
		scp.pull_dir(localdir);
	}
	catch(...)
	{
		mol::com_throw("Pull Directory failed",CLSID_SSH,"SCP::PullDirectory");
		return E_FAIL;
	}
	return S_OK;
}

HRESULT __stdcall  SCP::PullFile(  BSTR remotefile, BSTR localdir)
{
	if(!remotefile || !localdir)
		return E_INVALIDARG;

	try
	{
		mol::scp::Session scp(*ssh_);
		scp.open(1,remotefile);
		scp.pull_file(localdir);
	}
	catch(...)
	{
		mol::com_throw("Pull File failed",CLSID_SSH,"SCP::PullFile");
		return E_FAIL;
	}
	return S_OK;
}

HRESULT __stdcall  SCP::ReadFile(  BSTR remotefile, BSTR *content)
{
	if(!remotefile || !content)
		return E_INVALIDARG;

	*content = 0;
	try
	{
		mol::scp::Session scp(*ssh_);
		scp.open(1,remotefile);
		std::string data;
		scp.read_file(data);
		*content = ::SysAllocString( mol::fromUTF8(data).c_str() );
	}
	catch(...)
	{
		mol::com_throw("Read file failed",CLSID_SSH,"SCP::ReadFile");
		return E_FAIL;
	}
	return S_OK;
}

HRESULT __stdcall SCP::GetFile(  BSTR remotefile,SAFEARRAY * *content)
{
	if(!remotefile || !content)
		return E_INVALIDARG;

	*content = 0;
	try
	{
		mol::scp::Session scp(*ssh_);
		scp.open(1,remotefile);
		std::string data;
		scp.read_file(data);

		mol::ole::SafeArrayBase sab;
		sab.Create(VT_I1,(int)data.size());
		
		{
			mol::SFAccess<BYTE> sf(sab);
			memcpy( sf(), data.data(), data.size() );
		}
		return sab.Copy(content);
	}
	catch(...)
	{
		mol::com_throw("Get file failed",CLSID_SSH,"SCP::GetFile");
		return E_FAIL;
	}
	return S_OK;
}


////////////////////////////////////////////////////////////////

SFTP::Instance* SFTP::createInstance(  mol::ssh::Session* session)
{
	SFTP::Instance* instance = new Instance;
	instance->ssh_ = session;
	return instance;
}


void SFTP::dispose()
{

}


HRESULT __stdcall  SFTP::Mkdir( BSTR path, long mode)
{
	if(!path)
		return E_INVALIDARG;

	try
	{
		mol::sftp::Session sftp(*ssh_);
		sftp.mkdir( std::wstring(path), mode );
	}
	catch(...)
	{
		mol::com_throw("Mkdir failed",CLSID_SSH,"SFTP::Mkdir");
		return E_FAIL;
	}

	return S_OK;
}

HRESULT __stdcall  SFTP::Rmdir( BSTR path)
{
	if(!path)
		return E_INVALIDARG;

	try
	{
		mol::sftp::Session sftp(*ssh_);
		sftp.rmdir( std::wstring(path) );
	}
	catch(...)
	{
		mol::com_throw("Rmdir failed",CLSID_SSH,"SFTP::Rmdir");
		return E_FAIL;
	}
	return S_OK;
}

HRESULT __stdcall  SFTP::Rename( BSTR oldpath, BSTR newpath)
{
	if(!oldpath||!newpath)
		return E_INVALIDARG;

	try
	{
		mol::sftp::Session sftp(*ssh_);
		sftp.rename( std::wstring(oldpath),std::wstring(newpath) );
	}
	catch(...)
	{
		mol::com_throw("Rename failed",CLSID_SSH,"SFTP::Rename");
		return E_FAIL;
	}
	return S_OK;
}

HRESULT __stdcall  SFTP::Unlink( BSTR path)
{
	if(!path)
		return E_INVALIDARG;

	try
	{
		mol::sftp::Session sftp(*ssh_);
		sftp.unlink( std::wstring(path) );
	}
	catch(...)
	{
		mol::com_throw("Unlink failed",CLSID_SSH,"SFTP::Unlink");
		return E_FAIL;
	}
	return S_OK;
}

HRESULT __stdcall  SFTP::Chown( BSTR path, long owner, long group)
{
	if(!path)
		return E_INVALIDARG;

	try
	{
		mol::sftp::Session sftp(*ssh_);
		sftp.chown( std::wstring(path),owner,group );
	}
	catch(...)
	{
		mol::com_throw("Chown failed",CLSID_SSH,"SFTP::Chown");
		return E_FAIL;
	}
	return S_OK;
}


HRESULT __stdcall  SFTP::Stat(  BSTR path, IRemoteFile **remotefile)
{
	if(!path)
		return E_INVALIDARG;

	try
	{
		mol::sftp::Session sftp(*ssh_);
		mol::sftp::RemoteFile rf = sftp.stat( std::wstring(path) );

		SSHRemoteFile::Instance* instance = SSHRemoteFile::createInstance(rf);
		return instance->QueryInterface(IID_IRemoteFile,(void**)remotefile);
	}
	catch(...)
	{
		mol::com_throw("Stat failed",CLSID_SSH,"SFTP::Stat");
		return E_FAIL;
	}
	return S_OK;
}

HRESULT __stdcall  SFTP::Lstat( BSTR path, IRemoteFile **remotefile)
{
	if(!path)
		return E_INVALIDARG;

	try
	{
		mol::sftp::Session sftp(*ssh_);
		mol::sftp::RemoteFile rf = sftp.lstat( std::wstring(path) );

		SSHRemoteFile::Instance* instance = SSHRemoteFile::createInstance(rf);
		return instance->QueryInterface(IID_IRemoteFile,(void**)remotefile);
	}
	catch(...)
	{
		mol::com_throw("Lstat failed",CLSID_SSH,"SFTP::Lstat");
		return E_FAIL;
	}
	return S_OK;
}

HRESULT __stdcall  SFTP::Files(  BSTR path, SAFEARRAY * *remotefiles)
{
	if(!path)
		return E_INVALIDARG;

	try
	{
		mol::sftp::Session sftp(*ssh_);
		std::vector<std::wstring> v = sftp.files( std::wstring(path) );

		mol::ArrayBound ab((long)v.size());
		mol::SafeArray<VT_VARIANT> sa;
		sa.Create(ab);
		{
			mol::SFAccess<VARIANT> sf(sa);
			for ( size_t i = 0; i < v.size(); i++)
			{
				::VariantInit(&sf[(int)i]);
				sf[(int)i].vt = VT_BSTR;
				sf[(int)i].bstrVal = ::SysAllocString(v[i].c_str());
			}
		}
		return sa.Copy(remotefiles);
	}
	catch(...)
	{
		mol::com_throw("get directory content failed",CLSID_SSH,"SFTP::Files");
		return E_FAIL;
	}
	return S_OK;
}

HRESULT __stdcall  SFTP::List(  BSTR path, SAFEARRAY * *remotefiles)
{
	if(!path)
		return E_INVALIDARG;

	try
	{
		mol::sftp::Session sftp(*ssh_);
		std::vector<mol::sftp::RemoteFile> v = sftp.list( std::wstring(path) );

		mol::ArrayBound ab((long)v.size());
		mol::SafeArray<VT_VARIANT> sa;
		sa.Create(ab);				
		{
			mol::SFAccess<VARIANT> sf(sa);
			for ( size_t i = 0; i < v.size(); i++)
			{			
				::VariantInit(&sf[(int)i]);
				SSHRemoteFile::Instance* rf = SSHRemoteFile::createInstance(v[i]);
				sf[(int)i].vt = VT_DISPATCH;
				HRESULT hr = rf->QueryInterface( IID_IRemoteFile, (void**)&(sf[(int)i].pdispVal));
				if ( hr != S_OK )
					return hr;
			}
		}
		return sa.Copy(remotefiles);
	}
	catch(...)
	{
		mol::com_throw("get directory files failed",CLSID_SSH,"SFTP::List");
		return E_FAIL;
	}
	return S_OK;
}

///////////////////////////////////////////////////////////////////////////////


class PwdDlg  : public mol::win::Dialog
{
public:

	PwdDlg(const mol::string& host, int port)
		: host_(host), port_(port)
	{}

	mol::ssh::wstring user;
	mol::ssh::wstring pwd;

	virtual LRESULT wndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message)
		{
			case WM_INITDIALOG:
			{
				setDlgItemText(IDC_EDIT_HOST,host_.c_str());
				setDlgItemInt(IDC_EDIT_PORT,port_);
				::SetFocus(getDlgItem(IDC_EDIT_USER));
				this->center();
				this->setForeGround();
				return FALSE; // note: false! look into PSDK!
			}
			case WM_COMMAND:
			{
				if (LOWORD(wParam) == IDOK )
				{
					mol::string u;
					mol::string p;
					getDlgItemText(IDC_EDIT_USER,u);
					getDlgItemText(IDC_EDIT_PWD,p);
					user = mol::ssh::wstring( u.c_str() );
					pwd  = mol::ssh::wstring( p.c_str() );
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

////////////////////////////////////////////////////////////////

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
				this->setForeGround();
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

////////////////////////////////////////////////////////////////


bool CredentialManager::acceptHost( mol::string host, long port, mol::string hash )
{
	AccepHostDlg dlg( mol::toString(host), port, mol::toString(hash) );

	LRESULT r = dlg.doModal( IDD_DIALOG_SSH_ACCEPT_HOST, ::GetDesktopWindow() );

	return r == IDOK;
}

bool CredentialManager::getCredentials( mol::string host, long port, mol::ssh::SecureCredentials** credentials)
{
	if(!credentials)
		return false;

	*credentials = 0;

	PwdDlg dlg( host, port );
	LRESULT r = dlg.doModal( IDD_SCP_PWD_DIALOG, ::GetDesktopWindow() );
	if ( r != IDOK )
	{
		return false;
	}
	
	mol::ssh::string user = mol::ssh::wstring2utf8(dlg.user.data(),dlg.user.size());
	mol::ssh::string pwd = mol::ssh::wstring2utf8(dlg.pwd.data(),dlg.pwd.size());

	*credentials = new mol::ssh::SecureCredentials(host,port,user,pwd);

	return true;
}
////////////////////////////////////////////////////////////////////////


class sshDll : 
	public mol::Dll,
	public mol::exports_aggregable< sshDll, SSH >,
	public mol::exports_aggregable< sshDll, ScpDataTransferObjectFactory >
{};

DLL_COCLASS_EXPORTS(sshDll)

////////////////////////////////////////////////////////////////////////
