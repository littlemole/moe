#ifndef MOL_DEF_GUARD_DEFINE_SSHSHELL_CREDMGR_DEF_GUARD
#define MOL_DEF_GUARD_DEFINE_SSHSHELL_CREDMGR_DEF_GUARD


//#include "ShellFolder.h"
#include "ssh/ssh.h"
#include "ssh/sftp.h"
#include "ssh/credmgr.h"
#include "ssh/scpDataTransferObj.h"


class CredentialManager : public mol::ssh::ScpCredentialManager
{
protected:

	bool getCredentials( mol::string host, long port, mol::ssh::SecureCredentials** credentials);
	bool acceptHost( mol::string host, long port, mol::string hash );
};

CredentialManager& credentialManager();


#endif