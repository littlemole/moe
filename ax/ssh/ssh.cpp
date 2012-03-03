#include "stdafx.h"
#include "ssh.h"
#include "ssh/sftp.h"
#include "ssh/scp.h"
#include "tcp/sockets.h"
#include "ole/dll.h"
//#include <Wincrypt.h>
//#include "Ntsecapi.h"
#include "ssh_i.c"
#include "resource.h"


#define 		STATUS_SUCCESS					0
#define RTL_ENCRYPT_MEMORY_SIZE					8
#define CRYPTPROTECTMEMORY_BLOCK_SIZE           16

typedef long RtlEncryptMemoryPtr ( PVOID mem, ULONG size, ULONG flags );
typedef long RtlDecryptMemoryPtr ( PVOID mem, ULONG size, ULONG flags );

RtlEncryptMemoryPtr* RtlEncryptMemory = (RtlEncryptMemoryPtr*)mol::dllFunc( _T("Advapi32.dll"), _T("SystemFunction040") );
RtlDecryptMemoryPtr* RtlDecryptMemory = (RtlDecryptMemoryPtr*)mol::dllFunc( _T("Advapi32.dll"), _T("SystemFunction041") );

typedef BOOL __stdcall CryptProtectMemoryPtr( LPVOID pDataIn, DWORD cbDataIn, DWORD dwFlags);
typedef BOOL __stdcall CryptUnprotectMemoryPtr( LPVOID pDataIn, DWORD cbDataIn, DWORD dwFlags);

CryptProtectMemoryPtr* MolCryptProtectMemory = (CryptProtectMemoryPtr*)mol::dllFunc( _T("Crypt32.dll"), _T("CryptProtectMemory") );
CryptUnprotectMemoryPtr* MolCryptUnprotectMemory = (CryptUnprotectMemoryPtr*)mol::dllFunc( _T("Crypt32.dll"), _T("CryptUnprotectMemory") );


////////////////////////////////////////////////////////////////////////

ScpCredentialManager& credentialManager()
{
	return mol::singleton<ScpCredentialManager>();
}

////////////////////////////////////////////////////////////////////////


EncryptedMemory::EncryptedMemory()
	:encrypted_(0),size_(0),size_encrypted_(0)
{

}

EncryptedMemory::EncryptedMemory( const EncryptedMemory& rhs)
	:encrypted_(0),size_(rhs.size_),size_encrypted_(rhs.size_encrypted_)
{
	encrypted_ = ::LocalAlloc(LPTR,size_encrypted_);
	::memcpy(encrypted_,rhs.encrypted_,size_encrypted_);
}

EncryptedMemory::EncryptedMemory( EncryptedMemory&& rhs)
	:encrypted_(rhs.encrypted_),size_(rhs.size_),size_encrypted_(rhs.size_encrypted_)
{
	rhs.encrypted_ = 0;
	rhs.size_ = 0;
	rhs.size_encrypted_ = 0;
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
		size_encrypted_ = 0;
	}
}

EncryptedMemory& EncryptedMemory::operator=(const EncryptedMemory& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}

	size_ = rhs.size_;
	size_encrypted_ = rhs.size_encrypted_;
	encrypted_ = ::LocalAlloc(LPTR,size_encrypted_);
	::memcpy(encrypted_,rhs.encrypted_,size_encrypted_);
	return *this;
}


EncryptedMemory& EncryptedMemory::operator=(EncryptedMemory&& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}

	dispose();

	size_ = rhs.size_;
	size_encrypted_ = rhs.size_encrypted_;
	encrypted_ = rhs.encrypted_;

	rhs.encrypted_ = 0;
	rhs.size_ = 0;
	rhs.size_encrypted_ = 0;

	return *this;
}

size_t EncryptedMemory::encrypt( void* data, size_t size, DWORD flags )
{
	if ( MolCryptProtectMemory )
	{
		return encryptVista(data,size,flags);
	}
	return encryptLegacy(data,size,flags);
}

size_t EncryptedMemory::encryptLegacy( void* data, size_t size, DWORD flags )
{
	static std::string padding('X',RTL_ENCRYPT_MEMORY_SIZE);

	dispose();

	size_ = size;
	size_encrypted_ = size;

	DWORD mod = size_ % RTL_ENCRYPT_MEMORY_SIZE;
	if ( mod )
	{
		size_encrypted_ = size_ + (RTL_ENCRYPT_MEMORY_SIZE-mod);
	}

	encrypted_ = ::LocalAlloc(LPTR,size_encrypted_);
	::memcpy( encrypted_, data, size_);

	long ntstat = ::RtlEncryptMemory( encrypted_, (ULONG)size_encrypted_,flags);
	if (ntstat!=STATUS_SUCCESS)
	{
		cry();
		throw mol::X("CryptProtectMemory failed!");
	}
	return size_;
}

mol::ssh::string EncryptedMemory::decryptLegacy( DWORD flags )
{
	void* v = malloc(size_encrypted_);
	if(!v)
		return "";

	::memcpy(v,encrypted_,size_encrypted_);

	if (::RtlDecryptMemory(v,(ULONG)size_encrypted_,flags) == STATUS_SUCCESS)
	{
		mol::ssh::string s( (char*)v, size_ );
		free(v);
		return s;
	}
	free(v);
	return "";
}

mol::ssh::string EncryptedMemory::decrypt( DWORD flags )
{
	if ( MolCryptUnprotectMemory )
	{
		return decryptVista(flags);
	}
	return decryptLegacy(flags);
}

size_t EncryptedMemory::encryptVista( void* data, size_t size, DWORD flags )
{
	static std::string padding('X',CRYPTPROTECTMEMORY_BLOCK_SIZE);

	dispose();

	size_ = size;
	size_encrypted_ = size;

	DWORD mod = size_ % CRYPTPROTECTMEMORY_BLOCK_SIZE;
	if ( mod )
	{
		size_encrypted_ = size_ + (CRYPTPROTECTMEMORY_BLOCK_SIZE-mod);
	}

	encrypted_ = ::LocalAlloc(LPTR,size_encrypted_);
	::memcpy( encrypted_, data, size_);

	if (!MolCryptProtectMemory( encrypted_, (DWORD)size_encrypted_,flags))
	{
		throw mol::X("CryptProtectMemory failed!");
	}
	return size_;
}

mol::ssh::string EncryptedMemory::decryptVista( DWORD flags )
{
	void* v = malloc(size_encrypted_);
	if(!v)
		return "";

	::memcpy(v,encrypted_,size_encrypted_);

	if (MolCryptUnprotectMemory(v,(DWORD)size_encrypted_,flags))
	{
		mol::ssh::string s( (char*)v, size_ );
		free(v);
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

////////////////////////////////////////////////////////////////////////


EncryptedMap::EncryptedMap()
{
}

EncryptedMap::EncryptedMap(const EncryptedMap& rhs)
	: secure_(rhs.secure_)
{
}

EncryptedMap::EncryptedMap(EncryptedMap&& rhs)
	: secure_(rhs.secure_)
{
}

void EncryptedMap::encrypt(const EncryptedMap::MapType& map)
{
	mol::ssh::stringBuffer buffer;
	for ( MapType::const_iterator it = map.begin(); it!=map.end(); it++)
	{
		buffer.append( (*it).first.data(), (*it).first.size() );
		buffer.append( "\0", 1 );
		buffer.append( (*it).second.data(), (*it).second.size() );
		buffer.append( "\0", 1 );
	}

	secure_.encrypt( (void*)buffer.data(), buffer.size() );
}

EncryptedMap::MapType EncryptedMap::decrypt()
{
	MapType map;
	mol::ssh::string plain = secure_.decrypt();
	size_t pos = 0;
	size_t p   = 0;

	char* data = (char*)plain.data();
	char* pdata = (char*)data;

	while(pdata < plain.data()+plain.size() )
	{
		while( *pdata )
		{
			pdata++;
		}

		mol::ssh::string key( data, pdata-data );
		pdata++;
		data = pdata;

		while( *pdata )
		{
			pdata++;
		}
		mol::ssh::string val( data, pdata-data );
		pdata++;
		data = pdata;

		map.insert( std::make_pair(key,val) );
	}	

	return map;
}

EncryptedMap& EncryptedMap::operator=(const EncryptedMap& rhs)
{
	if ( this == &rhs )
	{
		return *this;
	}

	secure_ = rhs.secure_;
	return *this;
}

EncryptedMap& EncryptedMap::operator=(EncryptedMap&& rhs)
{
	if ( this == &rhs )
	{
		return *this;
	}

	secure_ = rhs.secure_;
	return *this;
}

///////////////////////////////////////////////////////////////////////////////

SecureCredentials::SecureCredentials( const mol::string& h, int p, const mol::ssh::string& u, const mol::ssh::string& pass)
		: host(h),port(p)
{

	EncryptedMap::MapType map;
	map.insert( std::make_pair(mol::ssh::string("user"),u));
	map.insert( std::make_pair(mol::ssh::string("pwd"), pass));

	secure_.encrypt(map);
}

SecureCredentials::SecureCredentials( const SecureCredentials& rhs )
	: host(rhs.host), port(rhs.port), secure_(rhs.secure_)
{}

SecureCredentials::SecureCredentials( SecureCredentials&& rhs )
	: host(rhs.host), port(rhs.port), secure_(rhs.secure_)
{}


SecureCredentials::~SecureCredentials()
{
}


void SecureCredentials::decrypt( mol::ssh::string& u, mol::ssh::string& pass )
{
	EncryptedMap::MapType map = secure_.decrypt();

	if ( map.count("user") > 0 )
		u = map["user"];

	if ( map.count("pwd") > 0 )
		pass = map["pwd"];
}

SecureCredentials& SecureCredentials::operator=( const SecureCredentials& rhs )
{
	if ( this == &rhs )
	{
		return *this;
	}

	host = rhs.host;
	port = rhs.port;
	secure_ = rhs.secure_;
	return *this;
}


SecureCredentials& SecureCredentials::operator=( SecureCredentials&& rhs )
{
	if ( this == &rhs )
	{
		return *this;
	}

	host = rhs.host;
	port = rhs.port;
	secure_ = rhs.secure_;
	return *this;
}


///////////////////////////////////////////////////////////////////////////////

bool ScpCredentialManager::getCredentials( mol::string host, long port, SecureCredentials** credentials)
{
	if(!credentials)
		return false;

	*credentials = 0;

	if ( credentialsMap_.count(host) > 0 )
	{
		SecureCredentials* sc = credentialsMap_[host];
		if ( sc->port == port )
		{
			*credentials = sc;
			return true;
		}
	}
	return false;
}


void ScpCredentialManager::remberSessionCredentials( mol::string host, long port, SecureCredentials* credentials)
{
	if ( credentialsMap_.count(host) > 0 )
	{
		SecureCredentials* sc = credentialsMap_[host];
		delete sc;
	}
	credentialsMap_[host] = credentials;
}

void ScpCredentialManager::removeSessionCredentials( mol::string host, long port)
{
	if ( credentialsMap_.count(host) > 0 )
	{
		SecureCredentials* sc = credentialsMap_[host];
		delete sc;
	}
}


bool ScpCredentialManager::Credentials::promptCredentials(const std::string& host, int port,const std::string& prompt, const std::string& desc,char** value,bool echo)
{
	return false;
}

bool ScpCredentialManager::Credentials::acceptHost(const std::string& host, int port, const std::string& hash)
{
	return This()->acceptHost( mol::fromUTF8(host),port, mol::fromUTF8(hash));
}

bool ScpCredentialManager::Credentials::rememberHostCredentials(const std::string& host, int port, const mol::ssh::string& user, const mol::ssh::string& pwd)
{
	SecureCredentials* sc = new SecureCredentials( mol::fromUTF8(host),port,user,pwd);
	This()->remberSessionCredentials( mol::fromUTF8(host),port,sc);
	return true;
}

bool ScpCredentialManager::Credentials::deleteHostCredentials(const std::string& host, int port)
{
	This()->removeSessionCredentials( mol::fromUTF8(host),port);
	return true;
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


bool ScpCredentialManager::acceptHost( mol::string host, long port, mol::string hash )
{
	AccepHostDlg dlg( mol::toString(host), port, mol::toString(hash) );

	LRESULT r = dlg.doModal( IDD_DIALOG_SSH_ACCEPT_HOST, ::GetDesktopWindow() );

	return r == IDOK;
}



bool ScpCredentialManager::Credentials::getCredentials(const std::string& host, int port,mol::ssh::string& user, mol::ssh::string& pwd)
{
	SecureCredentials* sc = 0;

	if ( This()->getCredentials( mol::fromUTF8(host), port, &sc ) )
	{
		mol::ssh::string login;
		mol::ssh::string pass;
		sc->decrypt(login,pass);

		user = login;
		pwd = pass;

		return true;
	}


	PwdDlg dlg( mol::fromUTF8(host), port );
	LRESULT r = dlg.doModal( IDD_SCP_PWD_DIALOG, ::GetDesktopWindow() );
	if ( r != IDOK )
	{
		return false;
	}

	user = mol::ssh::wstring2utf8(dlg.user.data(),dlg.user.size());
	pwd = mol::ssh::wstring2utf8(dlg.pwd.data(),dlg.pwd.size());

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
