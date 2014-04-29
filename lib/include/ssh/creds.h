#ifndef _MOL_COM_DLL_SSH_CREDS_DEF_DEFINE_GUARD_
#define _MOL_COM_DLL_SSH_CREDS_DEF_DEFINE_GUARD_

#include <util/str.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include "ssh/mem.h"

namespace mol {
namespace ssh {


struct SecureCredentials
{
	SecureCredentials( const std::wstring& h, int p, const mol::ssh::string& u, const mol::ssh::string& pass);
	SecureCredentials( const SecureCredentials& rhs );
	SecureCredentials( SecureCredentials&& rhs );
	~SecureCredentials();

	std::wstring host;
	int port;

	void decrypt( mol::ssh::string& u, mol::ssh::string& pass );

	SecureCredentials& operator=( const SecureCredentials& rhs );
	SecureCredentials& operator=( SecureCredentials&& rhs );

private:
	EncryptedMap secure_;

};



} // end namespace ssh
} // end namespace mol

#endif