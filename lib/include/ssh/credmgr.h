#ifndef _MOL_COM_DLL_SSH_CRED_MGR_DEF_DEFINE_GUARD_
#define _MOL_COM_DLL_SSH_CRED_MGR_DEF_DEFINE_GUARD_

#include <util/str.h>
#include <util/util.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include "ssh/creds.h"
#include "ssh/ssh.h"

namespace mol {
namespace ssh {

///////////////////////////////////////////////////////////////////////////////

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

		virtual bool getCredentials(const std::string& host, int port,mol::ssh::string& user, mol::ssh::string& pwd);
		virtual bool promptCredentials(const std::string& host, int port,const std::string& prompt, const std::string& desc,char** value,bool echo);
		virtual bool acceptHost(const std::string& host, int port, const std::string& hash);
		virtual bool rememberHostCredentials(const std::string& host, int port, const mol::ssh::string& user, const mol::ssh::string& pwd);
		virtual bool deleteHostCredentials(const std::string& host, int port);

	} credentials;


protected:

	virtual bool getCredentials( mol::string host, long port, SecureCredentials** credentials) = 0;
	virtual bool acceptHost( mol::string host, long port, mol::string hash ) = 0;

	void remberSessionCredentials( mol::string host, long port, SecureCredentials* credentials);
	void removeSessionCredentials( mol::string host, long port);

	std::map<mol::string,SecureCredentials*> credentialsMap_;
};


} // end namespace ssh
} // end namespace mol


#endif