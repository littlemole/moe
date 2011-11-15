#include "ssh/ssh.h"
#include <libssh/libssh.h>
#include <libssh/callbacks.h>
#include <libssh/scp.h>
#include <libssh/sftp.h>
 

/* libssh calls may block an undefined amount of time */
#define SSH_SESSION_FLAG_BLOCKING 1

#define ERROR_BUFFERLEN 1024

struct error_struct_helper {
/* error handling */
    int error_code;
    char error_buffer[ERROR_BUFFERLEN];
};

struct ssh_session_struct_helper {
    struct error_struct_helper error;
    struct ssh_socket_struct *socket;
    char *serverbanner;
    char *clientbanner;
};

namespace mol {
namespace ssh {


Init::Init()
{
	cb_ = new ssh_threads_callbacks_struct;

	cb_->mutex_init = &Init::mutex_init_impl;
	cb_->mutex_lock = &Init::mutex_lock_impl;
	cb_->mutex_unlock = &Init::mutex_unlock_impl;
	cb_->mutex_destroy = &Init::mutex_destroy_impl;
	cb_->thread_id = &Init::thread_id_impl;

	ssh_threads_set_callbacks(cb_);
	ssh_init();
}

Init::~Init()
{
	delete cb_;
}

int Init::mutex_init_impl(void **lock)
{
	mol::Mutex* mutex = new mol::Mutex;
	*lock = (void*)mutex;
	return 1;
}

int Init::mutex_lock_impl(void **lock)
{
	mol::Mutex* mutex = (mol::Mutex*)(*lock);
	mutex->aquire();
	return 1;
}

int Init::mutex_unlock_impl(void **lock)
{
	mol::Mutex* mutex = (mol::Mutex*)(*lock);
	mutex->release();
	return 1;
}

int Init::mutex_destroy_impl(void **lock)
{
	mol::Mutex* mutex = (mol::Mutex*)(*lock);
	delete mutex;
	return 1;
}

unsigned long Init::thread_id_impl()
{
	return mol::Thread::self();
}

//////////////////////////////////////////////////////////////////////////////

Ex::Ex()
{}

Ex::Ex(const std::string& msg)
	: msg_(msg)
{}

std::string Ex::msg()
{
	return msg_;
}


//////////////////////////////////////////////////////////////////////////////

PasswordCredentials::PasswordCredentials()
{}

PasswordCredentials::PasswordCredentials(const std::string& host, int port, const std::string& user, const std::string& pwd)
	: host_(host),port_(port),user_(user),pwd_(pwd)
{}

bool PasswordCredentials::getCredentials(const std::string& host, int port,char** user, char** pwd)
{
	if (!user || !pwd)
		return false;

	size_t size = (user_.size()+1);
	*user = (char*)malloc( size );
	memcpy(*user, user_.data(), size );

	size = (pwd_.size()+1);
	*pwd = (char*)malloc( size );
	memcpy(*pwd, pwd_.data(), size );

	return true;
}

bool PasswordCredentials::promptCredentials(const std::string& host, int port,const std::string& prompt, const std::string& desc,char** value,bool echo)
{
	if (!value)
		return false;

	std::wstring in;
	std::wcin >> in;

	std::string s = mol::toUTF8(in);

	size_t size = (s.size()+1) ;
	*value = (char*)malloc( size );
	memcpy(*value, s.data(), size );

	return true;
}

bool PasswordCredentials::acceptHost(const std::string& host, int port,const std::string& hash)
{
	std::wcout << L"accept host " << mol::fromUTF8(host) << L":" << port << std::endl << L" hash: " << mol::fromUTF8(hash) << L" ?" << std::endl;
	std::wstring in;
	std::wcin >> in;
	if ( in == L"yes")
		return true;
	else
		return false;
}

bool PasswordCredentials::rememberHostCredentials(const std::string& host, int port, const char* user, const char* pwd)
{
	return true;
}

bool PasswordCredentials::deleteHostCredentials(const std::string& host, int port)
{
	return true;
}

//////////////////////////////////////////////////////////////////////////////

Session::Session()
	: port_(22),hostname_("localhost"),connected_(false), session_(0), cb_(0)
{
		
}

Session::Session(CredentialCallback* cb)
	: port_(22),hostname_("localhost"),connected_(false), session_(0), cb_(cb)
{
		
}

Session::~Session()
{
	dispose();
}

void Session::dispose()
{
	if ( connected_)
	{
		ssh_disconnect(session_);
		connected_ = false;
	}
	if ( session_)
	{
		ssh_free(session_);
		session_ = 0;
	}
}

void Session::setCredentialCallback( CredentialCallback* cb )
{
	cb_ = cb;
}

int Session::port()
{
	return port_;
}

void Session::port(int port)
{
	port_ = port;
}

std::string Session::hostname()
{
	return hostname_;
}

void Session::hostname(const std::string& hostname)
{
	hostname_ = hostname;
}

bool Session::open()
{
	return open(hostname_, cb_, port_);
}

bool Session::open(const std::string& host, CredentialCallback* cb , int port )
{ 
		dispose();
		session_ = ssh_new();

		hostname_ = host;

		if ( cb )
		cb_ = cb;

		if (port == 0)
			port = port_;
		else
			port_ = port;

		ssh_options_set(session_, SSH_OPTIONS_PORT, &port );
		ssh_options_set(session_, SSH_OPTIONS_HOST, mol::toUTF8(host).c_str() );

		int rc = ssh_connect(session_);
		if (rc != SSH_OK)
		{
			return false;
		}

		if (!verify_knownhost())
		{
			if(!cb_)
				return false;

			bool b = cb_->acceptHost(hostname_,port_,server_hash());
			if ( !b)
			{
				dispose();
				return false;
			}

			rememberKnownHost();
		}

		if (!auth())
		{
			return false;
		}

		connected_ = true;
		return true;
}

std::vector<int> Session::auth_methods()
{
	int method = 0;
	method = ssh_userauth_list(session_, NULL);
	std::vector<int> v;

	if (method & SSH_AUTH_METHOD_NONE)
	{ 
		v.push_back(SSH_AUTH_METHOD_NONE);
	}
	if (method & SSH_AUTH_METHOD_PUBLICKEY)
	{ 
		v.push_back(SSH_AUTH_METHOD_PUBLICKEY);
	}
	if (method & SSH_AUTH_METHOD_PASSWORD)
	{ 
		v.push_back(SSH_AUTH_METHOD_PASSWORD);
	}
	if (method & SSH_AUTH_METHOD_INTERACTIVE)
	{ 
		v.push_back(SSH_AUTH_METHOD_INTERACTIVE);
	}
	return v;
}

bool Session::auth()
{
	bool b = auth_none();
	if ( b )
		return true;

	std::vector<int> v = auth_methods();
	for ( size_t i = 0; i < v.size(); i++)
	{
		switch(v[i])
		{
			case SSH_AUTH_METHOD_NONE :
			{
				break;
			}
			case SSH_AUTH_METHOD_PASSWORD :
			{
				b = auth_password();
				if(b)
					return true;
				break;
			}
			case SSH_AUTH_METHOD_PUBLICKEY :
			{
				b = auth_pubkey();
				if(b)
					return true;
				break;
			}
			case SSH_AUTH_METHOD_INTERACTIVE :
			{
				b = auth_kbdint();
				if(b)
					return true;
				break;
			}

		}
	}
	return false;
}

bool Session::auth_none()
{
	int rc = ssh_userauth_none(session_, NULL);
	switch(rc)
	{
		case SSH_AUTH_SUCCESS:
		{
			return true;
		}
		case SSH_AUTH_ERROR:
		{
			dispose();
			throw Ex("SSH_AUTH_ERROR");
		}
		case SSH_AUTH_DENIED:
		{
			return false;
		}
		case SSH_AUTH_PARTIAL:
		{
			throw Ex("SSH_AUTH_PARTIAL");
		}
	}
	return false;
}


bool Session::auth_pubkey()
{
	int rc = ssh_userauth_autopubkey(session_,0);
	switch(rc)
	{
		case SSH_AUTH_SUCCESS:
		{
			return true;
		}
		case SSH_AUTH_ERROR:
		{
			dispose();
			throw Ex("SSH_AUTH_ERROR");
		}
		case SSH_AUTH_DENIED:
		{
			return false;
		}
		case SSH_AUTH_PARTIAL:
		{
			throw Ex("SSH_AUTH_PARTIAL");
		}
	}
	dispose();
	return false;
}
	
bool Session::auth_password()
{
	if (!cb_)
		return false;

	char* user = 0;
	char* pwd = 0;
	if(!cb_->getCredentials(hostname_,port_,&user,&pwd))
		return false;

	int rc = ssh_userauth_password(session_, user, pwd );
	if ( rc == SSH_AUTH_SUCCESS )
	{
		cb_->rememberHostCredentials(hostname_,port_,user,pwd);
	}

	if ( user )
		free(user);
	if ( pwd )
		free(pwd);

	switch(rc)
	{
		case SSH_AUTH_SUCCESS:
		{
			return true;
		}
		case SSH_AUTH_ERROR:
		{
			cb_->deleteHostCredentials(hostname_,port_);
			dispose();
			throw Ex("SSH_AUTH_ERROR");
		}
		case SSH_AUTH_DENIED:
		{
			cb_->deleteHostCredentials(hostname_,port_);
			return false;
		}
		case SSH_AUTH_PARTIAL:
		{
			throw Ex("SSH_AUTH_PARTIAL");
		}
	}
	dispose();
	return false;
}

bool Session::auth_password(const char* user, const char* pwd)
{

	int rc = ssh_userauth_password(session_, user, pwd );
	switch(rc)
	{
		case SSH_AUTH_SUCCESS:
		{
			if ( cb_)
				cb_->rememberHostCredentials(hostname_,port_,user,pwd);
			return true;
		}
		case SSH_AUTH_ERROR:
		{
			if ( cb_)
				cb_->deleteHostCredentials(hostname_,port_);
			dispose();
			throw Ex("SSH_AUTH_ERROR");
		}
		case SSH_AUTH_DENIED:
		{
			if ( cb_)
				cb_->deleteHostCredentials(hostname_,port_);

			return false;
		}
		case SSH_AUTH_PARTIAL:
		{
			throw Ex("SSH_AUTH_PARTIAL");
		}
	}
	dispose();
	return false;
}

bool Session::auth_kbdint()
{
	if (!cb_)
		return false;

	int rc = ssh_userauth_kbdint(session_, NULL, NULL);
  	while (rc == SSH_AUTH_INFO)
	{
		const char *name, *instruction;
		int nprompts, iprompt;

		name = ssh_userauth_kbdint_getname(session_);
		instruction = ssh_userauth_kbdint_getinstruction(session_);
		nprompts = ssh_userauth_kbdint_getnprompts(session_);

		for (iprompt = 0; iprompt < nprompts; iprompt++)
		{
			const char *prompt;
			char echo;

			prompt = ssh_userauth_kbdint_getprompt(session_, iprompt, &echo);

			char* value = 0;
			if ( cb_->promptCredentials(hostname_,port_,name,instruction,&value, echo ? true : false ) )
			{
				if ( ssh_userauth_kbdint_setanswer(session_,iprompt,value ) <0 )
				{
					if ( value )
						free(value);
					throw Ex("SSH_AUTH_ERROR");
				}
				if ( value )
					free(value);
			}
		}
		rc = ssh_userauth_kbdint(session_, NULL, NULL);
	}
	return rc == 0;
}


std::string Session::exec_remote(const std::string& cmd)
{
	ssh_channel channel;			

	channel = ssh_channel_new(session_);
	if (channel == NULL)
		throw Ex("SSH_ERROR new channel");

	int rc = ssh_channel_open_session(channel);
	if (rc != SSH_OK)
	{
		ssh_channel_free(channel);
		throw Ex("SSH_ERROR open channel");
	}

	rc = ssh_channel_request_exec( channel, cmd.c_str() );
	if (rc != SSH_OK)
	{
		ssh_channel_close(channel);
		ssh_channel_free(channel);
		throw Ex("SSH_ERROR exec channel");
	}

	std::ostringstream oss;
	char buffer[256];	
	unsigned int nbytes = ssh_channel_read(channel, buffer, sizeof(buffer), 0);
	while (nbytes > 0)
	{
		oss.write(buffer,nbytes);
		nbytes = ssh_channel_read(channel, buffer, sizeof(buffer), 0);
	}
    
	if (nbytes < 0)
	{
		ssh_channel_close(channel);
		ssh_channel_free(channel);
		throw Ex("SSH_ERROR read channel");
	}

	ssh_channel_send_eof(channel);
	ssh_channel_close(channel);
	ssh_channel_free(channel);

	return oss.str();
}

void Session::send_data(const std::string& cmd, const std::string& data) 
{
	ssh_channel channel = ssh_channel_new(session_);;
  	if (channel == NULL) 
	{
		dispose();
		return;
	}

	int rc = ssh_channel_open_session(channel);
	if (rc < 0) 
	{
		ssh_channel_close(channel);
		dispose();
 		return;
	}

	rc = ssh_channel_request_exec(channel, cmd.c_str() );
  	if (rc < 0) 
	{			 
		ssh_channel_close(channel);
		dispose();
		return;
	}

	rc = ssh_channel_write( channel, data.c_str(), (uint32_t)data.size() );
	if (rc < 0) 
	{
  		ssh_channel_close(channel);
		dispose();
		throw Ex("error writing channel");
   	}

	ssh_channel_send_eof(channel);
}

bool Session::verify_knownhost()
{
	unsigned char *hash = NULL;
	char *hexa;

	int hlen = ssh_get_pubkey_hash(session_, &hash);
	if (hlen < 0)
		throw Ex("unable to get pubkey hash");

	hexa = ssh_get_hexa(hash, hlen);

	pubkey_hash_ = std::string(hexa);

	free(hexa);
	free(hash);

	int state = ssh_is_server_known(session_);
	switch (state)
	{
	case SSH_SERVER_KNOWN_OK:
	{
		return true;
	}
	case SSH_SERVER_KNOWN_CHANGED:
	{
		dispose();
		throw Ex("Host key for server changed:");
	}
	case SSH_SERVER_FOUND_OTHER:
	{
		dispose();
		throw Ex("The host key for this server was not found but an other ype of key exists");
	}
	case SSH_SERVER_FILE_NOT_FOUND:
	{
	}
	case SSH_SERVER_NOT_KNOWN:
	{
		return false;
	}

	case SSH_SERVER_ERROR:
	{
		std::stringstream oss;
		oss << "Error " << ssh_get_error(session_) << std::endl;
		dispose();
		throw Ex(oss.str());
	}
	}
	  
	return false;
}

void Session::rememberKnownHost()
{
		if (ssh_write_knownhost(session_) < 0)
		{
			throw Ex("error writing to known hosts file");
		}
}

std::string Session::getServerBanner()
{
	ssh_session_struct_helper* s = (ssh_session_struct_helper*)session_;

	std::string ret(s->serverbanner);
	return ret;
}



std::string Session::getBanner()
{
	std::string ret;
	char* banner = ssh_get_issue_banner(session_);
	if (banner)
	{
		ret = std::string(banner);
		ssh_string_free_char(banner);
		return  ret;
	}
	return "";
}

std::string Session::server_hash()
{
	return pubkey_hash_;
}


std::string Session::error() 
{
	std::string s(ssh_get_error(session_));
	return  s;
}


std::string Session::username(uint32_t uid)
{
	std::stringstream oss;
	oss << "getent passwd " << uid << "|cut -d: -f1";
	std::string s = exec_remote(oss.str());
	return s;
}

uint32_t Session::userid(std::string uid)
{
	std::stringstream oss;
	oss << "getent passwd " << uid << "|cut -d: -f3";
	std::string s = exec_remote(oss.str());

	uint32_t v = 0;
	std::istringstream iss(s);
	iss >> v;
	return v;
}


std::string Session::groupname(uint32_t uid)
{
	std::stringstream oss;
	oss << "getent group " << uid << "|cut -d: -f1";
	std::string s = exec_remote(oss.str());
	return s;
}


uint32_t Session::groupid(std::string uid)
{
	std::stringstream oss;
	oss << "getent group " << uid << "|cut -d: -f3";
	std::string s = exec_remote(oss.str());

	uint32_t v = 0;
	std::istringstream iss(s);
	iss >> v;
	return v;
}

} // end namespace ssh
} // end namespace mol
