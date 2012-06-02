#pragma once

#include <string>
#include <sstream>
#include <vector>

#include "ssh/ssh.h"
#include "ssh/sftp.h"
#include "credMgr.h"

class ViewModel
{
public:
	ViewModel();
	~ViewModel();

	mol::sftp::RemoteFile* remoteFile(const mol::string& name );

	std::vector<mol::sftp::RemoteFile> files;

	std::vector<std::wstring> server;

	
};

ViewModel* viewModelRootFactory();
ViewModel* viewModelPathFactory(LPITEMIDLIST pidl, bool invalidate = false);
void invalidateViewModel(LPITEMIDLIST pidl);
bool validate(LPITEMIDLIST pidl);