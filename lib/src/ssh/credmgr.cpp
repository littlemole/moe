#include "ssh/credmgr.h"

namespace mol {
namespace ssh {

///////////////////////////////////////////////////////////////////////////////
	/*
bool ScpCredentialManager::getCredentials( std::wstring host, long port, SecureCredentials** credentials)
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
*/


void ScpCredentialManager::remberSessionCredentials( std::wstring host, long port, SecureCredentials* credentials)
{
	if ( credentialsMap_.count(host) > 0 )
	{
		SecureCredentials* sc = credentialsMap_[host];
		delete sc;
	}
	credentialsMap_[host] = credentials;
}

void ScpCredentialManager::removeSessionCredentials( std::wstring host, long port)
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

bool ScpCredentialManager::Credentials::getCredentials(const std::string& host, int port,mol::ssh::string& user, mol::ssh::string& pwd)
{
	SecureCredentials* credentials = 0;

	std::wstring h = mol::fromUTF8(host);

	if ( This()->credentialsMap_.count(h) > 0 )
	{
		SecureCredentials* sc = This()->credentialsMap_[h];
		if ( sc->port == port )
		{
			credentials = sc;
		}
	}

	if ( !credentials )
	{
		SecureCredentials* sc = 0;
		if (!This()->getCredentials(h,port,&sc))
		{
			return false;
		}
		credentials = sc;
	}

	if ( !credentials )
	{
		return false;
	}

	mol::ssh::string login;
	mol::ssh::string pass;

	credentials->decrypt(login,pass);

	user = login;
	pwd = pass;

	return true;
}

} // end namespace ssh
} // end namespace mol
