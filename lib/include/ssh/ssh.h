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

// secure strings - use as short as possible.
// secure strings will overwrite the occupied character data memory with zeros
// before releasing the memory
class string 
{
public:
	string() 
		: data_(0), size_(0)
	{}

	string( const string& s) 
		: data_(0),size_(0) 
	{ 
		alloc(s.data(),s.size());
	}

	string( const char* s) 
		: data_(0),size_(0) 
	{
		alloc(s,strlen(s));
	}

	string( const char* s, size_t size) 
		: data_(0),size_(size) 
	{
		alloc(s,size);
	}

	~string() 
	{ 
		dispose();
	}

	const char* data() const { return data_; }
	const size_t size() const { return size_; };

	void clear()
	{
		if ( data_ && size_ )
		{
			::ZeroMemory((void*)data_,size_+1);
		}
	}

	void dispose()
	{
		clear();
		delete[] data_;
		data_ = 0;
		size_ = 0;
	}

	string& operator=( const string& rhs )
	{
		if ( this == &rhs )
		{
			return *this;
		}

		dispose();

		size_ = rhs.size();
		alloc(rhs.data(),rhs.size());

		return *this;
	}

	bool operator<(const string& compare)
	{
		return strcmp(data_,compare.data()) != 0;
	}

private:

	void alloc( const char* data, size_t s )
	{
		size_ = s;
		if ( data && size_ )
		{
			data_ = new char[size_+1];
			clear();
			memcpy((void*)data_,(void*)data,size_);
		}
	}

	const char* data_;
	size_t      size_;
};


bool operator<(const string& src, const string& compare);

class wstring 
{
public:
	wstring() 
		: data_(0), size_(0) 
	{}

	wstring( const wstring& s) 
		: data_(0), size_(0) 
	{ 
		alloc(s.data(),s.size());
	}

	wstring( const wchar_t* s) 
		: data_(0),size_(0) 
	{
		alloc(s,wcslen(s));
	}

	wstring( const wchar_t* s, size_t size) 
		: data_(0),size_(0) 
	{
		alloc(s,size);
	}

	~wstring() 
	{ 
		dispose();
	}

	const wchar_t* data() const { return data_; }
	const size_t size() const { return size_; };

	void clear()
	{
		if ( data_ && size_ )
		{
			::ZeroMemory((void*)data_,size_+1);
		}
	}

	void dispose()
	{
		clear();
		delete[] data_;
		data_ = 0;
		size_ = 0;
	}

	wstring& operator=( const wstring& rhs )
	{
		if ( this == &rhs )
		{
			return *this;
		}

		dispose();

		size_ = rhs.size();
		alloc(rhs.data(),rhs.size());

		return *this;
	}

private:

	void alloc( const wchar_t* data, size_t s )
	{
		size_ = s;
		if ( data && size_ )
		{
			data_ = new wchar_t[size_+1];
			clear();
			memcpy((void*)data_,(void*)data,size_*sizeof(wchar_t));
		}
	}

	const wchar_t* data_;
	size_t      size_;
};

ssh::wstring utf82wstring( const char* in, const size_t size );
ssh::string wstring2utf8( const wchar_t* in, const size_t size);

class stringBuffer
{
public:
	stringBuffer()
		:data_(0),size_(512),used_(0)
	{
		data_ = new char[size_+1];
		clear();
	}

	~stringBuffer()
	{
		clear();
		delete[] data_;
	}

	void clear()
	{
		::ZeroMemory((void*)data_,size_+1);
	}

	const char* data()  const { return data_; }
	const size_t size() const { return used_; };

	void append(char* data)
	{
		size_t s = strlen(data);
		append(data,s);
	}

	void append(const char* data, size_t s)
	{
		if ( used_ + s > size_ )
		{
			size_t newsize = ((used_ + s ) / 512) +512;
			char* tmp = new char[newsize+1];
			::ZeroMemory((void*)tmp,newsize+1);
			memcpy(tmp,data_,used_);		
			memcpy(tmp+used_,data,s);
			clear();
			delete[] data_;
			data_ = tmp;
			size_ = newsize;
			used_ = used_ + s;
		}
		else
		{
			memcpy(data_+used_,data,s);
			used_ = used_ + s;
		}
	}
private:

	stringBuffer(const stringBuffer& ) 
	{
	}

	stringBuffer& operator=(const stringBuffer& )
	{
		return *this;
	}

	char* data_;
	size_t size_;
	size_t used_;
};
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
	Ex(int code,const std::string& msg);

	std::string msg();
	int code;
private:
	std::string msg_;
};


//////////////////////////////////////////////////////////////////////////////

class CredentialCallback
{
public:

	virtual bool getCredentials(const std::string& host, int port, ssh::string& user, ssh::string& pwd) = 0;
	virtual bool promptCredentials(const std::string& host, int port,const std::string& prompt, const std::string& desc,char** value,bool echo) = 0;
	virtual bool acceptHost(const std::string& host, int port, const std::string& hash) = 0;
	virtual bool rememberHostCredentials(const std::string& host, int port, const ssh::string& user, const ssh::string& pwd) = 0;
	virtual bool deleteHostCredentials(const std::string& host, int port) = 0;
};


//////////////////////////////////////////////////////////////////////////////

class PasswordCredentials : public CredentialCallback
{
public:

	PasswordCredentials();	
	PasswordCredentials(const std::string& host, int port,const ssh::string& user, const ssh::string& pwd);

	virtual bool getCredentials(const std::string& host, int port,ssh::string& user, ssh::string& pwd);
	virtual bool promptCredentials(const std::string& host, int port,const std::string& prompt, const std::string& desc,char** value,bool echo);
	virtual bool acceptHost(const std::string& host, int port, const std::string& hash);
	virtual bool rememberHostCredentials(const std::string& host, int port, const ssh::string& user, const ssh::string& pwd);
	virtual bool deleteHostCredentials(const std::string& host, int port);

private:
	std::string host_;
	int port_;
	ssh::string user_;
	ssh::string pwd_;
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

	void open();
	void open(const std::string& host, CredentialCallback* cb = 0, int port = 0);

	std::vector<int> auth_methods();

	void auth();
	bool auth_none();
	bool auth_pubkey();
	bool auth_password();
	bool auth_password(const ssh::string& user, const ssh::string& pwd);
	bool auth_kbdint();

	std::string exec_remote(const std::string& cmd);
	void send_data(const std::string& cmd, const std::string& data);
	bool is_connected();
	bool is_error();

	void verify_knownhost();
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
	ssh_session_struct* session_;
	std::string pubkey_hash_;
	CredentialCallback* cb_;
};

std::string permission(int mode);
int permission(const std::string& mode);

} // end namespace ssh
} // end namespace mol


#endif
