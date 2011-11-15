#ifndef _MOL_DEF_GUARD_DEFINE_SSH_CLIENT_DEF_GUARD_
#define _MOL_DEF_GUARD_DEFINE_SSH_CLIENT_DEF_GUARD_

#include <thread/thread.h>
#include <thread/sync.h>
#include "win/file.h"
#include <util/str.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

//////////////////////////////////////////////////////////////////////////////

struct ssh_threads_callbacks_struct;
struct ssh_session_struct;

//////////////////////////////////////////////////////////////////////////////

namespace mol {

enum {
  /** Code is going to write/create remote files */
  SSH_SCP_WRITE,
  /** Code is going to read remote files */
  SSH_SCP_READ,
  SSH_SCP_RECURSIVE=0x10
};

namespace ssh {

//////////////////////////////////////////////////////////////////////////////

class Init 
{
public:

	Init();
	~Init();

	static int mutex_init_impl(void **lock);
	static int mutex_lock_impl(void **lock);
	static int mutex_unlock_impl(void **lock);
	static int mutex_destroy_impl(void **lock);
	static unsigned long thread_id_impl();

private:

	ssh_threads_callbacks_struct* cb_;
};


//////////////////////////////////////////////////////////////////////////////

class Ex
{
public:

	Ex();
	Ex(const std::string& msg);

	std::string msg();

private:
	std::string msg_;
};


//////////////////////////////////////////////////////////////////////////////

class CredentialCallback
{
public:

	virtual bool getCredentials(const std::string& host, int port,char** user, char** pwd) = 0;
	virtual bool promptCredentials(const std::string& host, int port,const std::string& prompt, const std::string& desc,char** value,bool echo) = 0;
	virtual bool acceptHost(const std::string& host, int port, const std::string& hash) = 0;
	virtual bool rememberHostCredentials(const std::string& host, int port, const char* user, const char* pwd) = 0;
	virtual bool deleteHostCredentials(const std::string& host, int port) = 0;
};


//////////////////////////////////////////////////////////////////////////////

class PasswordCredentials : public CredentialCallback
{
public:

	PasswordCredentials();	
	PasswordCredentials(const std::string& host, int port,const std::string& user, const std::string& pwd);

	virtual bool getCredentials(const std::string& host, int port,char** user, char** pwd);
	virtual bool promptCredentials(const std::string& host, int port,const std::string& prompt, const std::string& desc,char** value,bool echo);
	virtual bool acceptHost(const std::string& host, int port, const std::string& hash);
	virtual bool rememberHostCredentials(const std::string& host, int port, const char* user, const char* pwd);
	virtual bool deleteHostCredentials(const std::string& host, int port);

private:
	std::string host_;
	int port_;
	std::string user_;
	std::string pwd_;
};

//////////////////////////////////////////////////////////////////////////////

class Session
{
public:

	Session();
	Session(CredentialCallback* cb);

	~Session();
	void dispose();
	void setCredentialCallback( CredentialCallback* cb );

	int port();
	void port(int port);

	std::string hostname();
	void hostname(const std::string& hostname);

	bool open();
	bool open(const std::string& host, CredentialCallback* cb = 0, int port = 0);

	std::vector<int> auth_methods();

	bool auth();
	bool auth_none();
	bool auth_pubkey();
	bool auth_password();
	bool auth_password(const char* user, const char* pwd);
	bool auth_kbdint();

	std::string exec_remote(const std::string& cmd);
	void send_data(const std::string& cmd, const std::string& data);

	bool verify_knownhost();
	void rememberKnownHost();

	std::string getServerBanner();
	std::string getBanner();

	std::string server_hash();
	std::string error();

	std::string username(uint32_t uid);
	uint32_t userid(std::string uid);

	std::string groupname(uint32_t uid);
	uint32_t groupid(std::string uid);

	operator ssh_session_struct*()
	{
		return session_;
	}

private:

	int port_;
	std::string hostname_;
	bool connected_;
	ssh_session_struct* session_;
	std::string pubkey_hash_;
	CredentialCallback* cb_;
};

std::string permission(int mode);
int permission(const std::string& mode);

} // end namespace ssh
} // end namespace mol


#endif
