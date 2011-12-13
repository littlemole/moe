#ifndef _MOL_COM_DLL_SSH_DEF_DEFINE_GUARD_
#define _MOL_COM_DLL_SSH_DEF_DEFINE_GUARD_

#include <list>
#include <map>
#include <set>
#include <vector>

#include "util/istr.h"
#include "thread/thread.h"
#include "tcp/sockets.h"
#include "ssh/ssh.h"
#include "ssh/sftp.h"
#include "win/path.h"
#include "win/file.h"
#include "win/CoCtrl.h"
#include "win/msghandler.h"
#include "win/msg_macro.h"
#include "win/MsgMap.h"
#include "win/dlg.h"
#include "win/IO.h"
#include "ole/ole.h"
#include "ole/com.h"
#include "ole/obj.h"
#include "ole/Bstr.h"
#include "ole/typeinfo.h"
#include "ole/Factory.h"
#include "ole/aut.h"
#include "ole/cp.h"
#include "ole/DragDrop.h"
#include "ole/Ctrl.h"

#include "ssh_h.h"

#define BOOST_BIND_ENABLE_STDCALL 
#include "boost/bind.hpp"


class EncryptedMemory
{
public:

	EncryptedMemory();
	~EncryptedMemory();
	void dispose();

	size_t encrypt( void* data, size_t size, DWORD flags = CRYPTPROTECTMEMORY_SAME_LOGON);
	std::string decrypt( DWORD flags = CRYPTPROTECTMEMORY_SAME_LOGON);

	void* data();
	size_t size();

private:

	void* encrypted_;
	size_t size_;
};

class EncryptedMap
{
public:

	typedef std::map<std::wstring,std::wstring> MapType;

	EncryptedMap();

	void encrypt(const MapType& map);
	MapType decrypt();

private:

	EncryptedMemory secure_;
};

///////////////////////////////////////////////////////////////////////////////

class ScpPasswordCredentials : 
	public mol::com_registerobj<ScpPasswordCredentials,CLSID_ScpPasswordCredentials>,
	public mol::Dispatch<IScpPasswordCredentials>,
	public mol::interfaces< ScpPasswordCredentials, mol::implements< IDispatch, IScpPasswordCredentials> >
{
public:
		HRESULT virtual __stdcall put_Username( BSTR user);
		HRESULT virtual __stdcall get_Username( BSTR* user);
		HRESULT virtual __stdcall put_Password( BSTR pwd);
		HRESULT virtual __stdcall get_Password( BSTR* pwd);
private:

	EncryptedMap secure_;
};

///////////////////////////////////////////////////////////////////////////////

struct SecureCredentials
{
	SecureCredentials( const mol::string& h, int p, const mol::string& u, const mol::string& pass);
	~SecureCredentials();

	mol::string host;
	int port;

	void decrypt( mol::string& u, mol::string& pass );

private:
	EncryptedMap secure_;

};

class ScpCredentialManager
{
public:

	~ScpCredentialManager()
	{
		dispose();
	}

	void dispose()
	{
		for ( std::map<mol::string,SecureCredentials*>::iterator it = credentialsMap_.begin(); it!=credentialsMap_.end();it++)
		{
			delete (*it).second;
		}
		credentialsMap_.clear();
	}

	class Credentials : public mol::ssh::CredentialCallback
	{
		public: 
		outer_this(ScpCredentialManager,credentials);

		virtual bool getCredentials(const std::string& host, int port,char** user, char** pwd);
		virtual bool promptCredentials(const std::string& host, int port,const std::string& prompt, const std::string& desc,char** value,bool echo);
		virtual bool acceptHost(const std::string& host, int port, const std::string& hash);
		virtual bool rememberHostCredentials(const std::string& host, int port, const char* user, const char* pwd);
		virtual bool deleteHostCredentials(const std::string& host, int port);

	} credentials;


private:

	bool getCredentials( mol::string host, long port, SecureCredentials** credentials);
	bool acceptHost( mol::string host, long port, mol::string hash );
	void remberSessionCredentials( mol::string host, long port, SecureCredentials* credentials);
	void removeSessionCredentials( mol::string host, long port);

	std::map<mol::string,SecureCredentials*> credentialsMap_;
};

ScpCredentialManager& credentialManager();


class ScpCredentialProvider : 
	public mol::com_registerobj<ScpCredentialProvider,CLSID_DefaultScpCredentialProvider>,
	public mol::Dispatch<IScpCredentialProvider>,
	public mol::interfaces< ScpCredentialProvider, mol::implements< IDispatch, IScpCredentialProvider> >
{
public:

	void dispose()
	{
	}

	HRESULT virtual __stdcall getCredentials( BSTR host, long port, IScpPasswordCredentials** credentials);
	HRESULT virtual __stdcall promptCredentials( BSTR prompt,BSTR description,VARIANT_BOOL echo, VARIANT* value);
	HRESULT virtual __stdcall acceptHost( BSTR host, long port, BSTR hash, VARIANT_BOOL* accept);
	HRESULT virtual __stdcall remberSessionCredentials( BSTR host, long port, IScpPasswordCredentials* credentials);
	HRESULT virtual __stdcall removeSessionCredentials( BSTR host, long port);

private:

};

////////////////////////////////////////////////////////////////////////
class SSHRemoteFile : 
	public mol::Dispatch<IRemoteFile>,
	public mol::SupportsErrorInfo<&IID_IRemoteFile,&IID_IDispatch>,
	public mol::interfaces<
				SSHRemoteFile,
				mol::implements< 
					IDispatch,
					IRemoteFile,
					ISupportErrorInfo
					> 
				>
{
public:

	SSHRemoteFile()
	{}

	typedef mol::com_obj<SSHRemoteFile> Instance;
	static Instance* createInstance( const mol::sftp::RemoteFile& rf);

	void dispose();

    virtual HRESULT __stdcall  get_IsDir( VARIANT_BOOL *vb);        
    virtual HRESULT __stdcall  get_Filename( BSTR *name);
    virtual HRESULT __stdcall  get_Filetype( long *type);
    virtual HRESULT __stdcall  get_Permission( long *perms);
    virtual HRESULT __stdcall  get_UID( long *id);
    virtual HRESULT __stdcall  get_GID( long *id);       
    virtual HRESULT __stdcall  get_Mtime( long *timestamp);        
    virtual HRESULT __stdcall  get_Owner( BSTR *username);        
    virtual HRESULT __stdcall  get_Group( BSTR *groupname);        
    virtual HRESULT __stdcall  get_Size( long *len);        
    virtual HRESULT __stdcall  get_FormattedSize( BSTR *len);        
    virtual HRESULT __stdcall  get_FormattedPermissions( BSTR *len);

private:

	mol::sftp::RemoteFile rf_;
};

////////////////////////////////////////////////////////////////////////
class SFTP : 
	public mol::Dispatch<ISFTP>,
	public mol::SupportsErrorInfo<&IID_ISFTP,&IID_IDispatch>,
	public mol::interfaces<
				SFTP,
				mol::implements< 
					IDispatch,
					ISFTP,
					ISupportErrorInfo
					> 
				>
{
public:

	SFTP()
	{}

	typedef mol::com_obj<SFTP> Instance;
	static Instance* createInstance(  mol::ssh::Session* session);

	void dispose();

    virtual HRESULT __stdcall  Mkdir( BSTR path, long mode);        
    virtual HRESULT __stdcall  Rmdir( BSTR path);        
    virtual HRESULT __stdcall  Rename( BSTR oldpath, BSTR newpath);        
    virtual HRESULT __stdcall  Unlink( BSTR path);        
    virtual HRESULT __stdcall  Chown( BSTR path, long owner, long group);        
    virtual HRESULT __stdcall  Stat(  BSTR path, IRemoteFile **remotefile);        
    virtual HRESULT __stdcall  Lstat( BSTR path, IRemoteFile **remotefile);        
    virtual HRESULT __stdcall  Files(  BSTR path, SAFEARRAY * *remotefiles);        
    virtual HRESULT __stdcall  List(  BSTR path, SAFEARRAY * *remotefiles);

private:

	 mol::ssh::Session* ssh_;
};

////////////////////////////////////////////////////////////////////////
class SSHConnection : 
	public mol::Dispatch<ISSHConnection>,
	public mol::SupportsErrorInfo<&IID_ISSHConnection,&IID_IDispatch>,
	public mol::interfaces<
				SSHConnection,
				mol::implements< 
					IDispatch,
					ISSHConnection,
					ISupportErrorInfo
					> 
				>
{
public:

	typedef mol::com_obj<SSHConnection> Instance;
	static Instance* createInstance( const mol::bstr& host, long port, mol::ssh::Session* session);

	void dispose();

    virtual HRESULT __stdcall get_Hostname( BSTR *host);        
    virtual HRESULT __stdcall get_Portnumber( long *port);
    virtual HRESULT __stdcall get_IsConnected( VARIANT_BOOL *connected);
    virtual HRESULT __stdcall get_ServerBanner(BSTR *banner);
    virtual HRESULT __stdcall get_Banner( BSTR *banner);
    virtual HRESULT __stdcall get_ServerHash( BSTR *hash);
    virtual HRESULT __stdcall get_Error(BSTR *err);
    virtual HRESULT __stdcall Execute( BSTR cmd,BSTR *result);
    virtual HRESULT __stdcall Send( BSTR cmd,BSTR data,BSTR *result);        
    virtual HRESULT __stdcall UsernameFromUID( long uid,BSTR *result);
    virtual HRESULT __stdcall GroupnameFromGID( long gid,BSTR *result);       
    virtual HRESULT __stdcall UIDfromUsername( BSTR name,long *result);
    virtual HRESULT __stdcall GIDfromGroupname( BSTR name,long *result);
	virtual HRESULT __stdcall Connect();
	virtual HRESULT __stdcall get_SCP( ISCP** conn);
	virtual HRESULT __stdcall get_SFTP( ISFTP** conn);

private:

	mol::bstr hostname_;
	long port_;
	mol::ssh::Session* ssh_;
};

////////////////////////////////////////////////////////////////////////
class SCP : 
	public mol::Dispatch<ISCP>,
	public mol::SupportsErrorInfo<&IID_ISCP,&IID_IDispatch>,
	public mol::interfaces<
				SCP,
				mol::implements< 
					IDispatch,
					ISCP,
					ISupportErrorInfo
					> 
				>
{
public:

	typedef mol::com_obj<SCP> Instance;
	static Instance* createInstance( mol::ssh::Session* session);

	void dispose();

    virtual HRESULT __stdcall  PushDirectory( BSTR path, BSTR remotedir);       
    virtual HRESULT __stdcall  PushFile(  BSTR path, BSTR remotedir);        
	virtual HRESULT __stdcall  WriteFile(  BSTR content, BSTR remotedir);        
	virtual HRESULT __stdcall  PutFile( SAFEARRAY * content, BSTR remotedir);
    virtual HRESULT __stdcall  PullDirectory(  BSTR remotedir, BSTR localdir);        
    virtual HRESULT __stdcall  PullFile(   BSTR remotefile, BSTR localdir);        
    virtual HRESULT __stdcall  ReadFile(  BSTR remotefile, BSTR *content);
	virtual HRESULT __stdcall  GetFile(  BSTR remotefile,SAFEARRAY * *content);

private:

	long mode_;
	mol::ssh::Session* ssh_;
};

////////////////////////////////////////////////////////////////////////
class SSH : 
	public mol::com_registerobj<SSH,CLSID_SSH>,
	public mol::Dispatch<ISSH>,
	public mol::SupportsErrorInfo<&IID_ISSH,&IID_IDispatch>,
	public mol::interfaces< SSH, mol::implements<IDispatch, ISSH, ISupportErrorInfo> >
{
public:

	SSH()
	{}

	virtual void dispose()
	{
	}

    virtual HRESULT __stdcall get_Credentials( IScpCredentialProvider **credentials);
    virtual HRESULT __stdcall put_Credentials( IScpCredentialProvider *credentials);
    virtual HRESULT __stdcall Connect( BSTR hostname, long port, ISSHConnection **conn);

};

#endif