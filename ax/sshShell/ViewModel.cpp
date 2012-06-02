#include "StdAfx.h"
#include "ViewModel.h"
#include "ShellFolder.h"
#include <memory>

static ViewModel* rootModel = 0;

class ViewModelCacheEntry
{
public:
	ViewModelCacheEntry(ViewModel* v)
		:viewModel(v)
	{
		::GetSystemTime(&time);
	}

	SYSTEMTIME time;
	ViewModel* viewModel;
};

ViewModel* viewModelPathBuilder(LPITEMIDLIST pidl);

class ViewModelCache
{
public:

	ViewModel* get(LPITEMIDLIST pidl)
	{
		if ( cache_.count(pidl) > 0 )
		{
			return cache_[pidl]->viewModel;
		}

		for ( cachetype::iterator it = cache_.begin(); it != cache_.end(); it++)
		{
			if ( ::ILIsEqual((*it).first, pidl))
			{
				return (*it).second->viewModel;
			}
			if ( pidlManager().isEqual( (*it).first, pidl) )
			{
				return (*it).second->viewModel;
			}
		}

		ViewModel* viewModel = viewModelPathBuilder(pidl);
		if (!viewModel)
			return 0;

		cache_.insert( std::make_pair(pidlManager().copy(pidl),new ViewModelCacheEntry(viewModel)) );
		return viewModel;
	}

	void invalidate(LPITEMIDLIST pidl)
	{
		if ( cache_.count(pidl) > 0 )
		{
			ViewModel* vm = cache_[pidl]->viewModel;
			cache_.erase(pidl);
			//delete vm;
			return;
		}

		for ( cachetype::iterator it = cache_.begin(); it != cache_.end(); it++)
		{
			if ( ::ILIsEqual((*it).first, pidl))
			{
				ViewModel* vm = (*it).second->viewModel;
				pidlManager().destroy( (*it).first );
				cache_.erase( it );
				//delete vm;
				return;
			}
			if ( pidlManager().isEqual( (*it).first, pidl) )
			{
				ViewModel* vm = (*it).second->viewModel;
				pidlManager().destroy( (*it).first );
				cache_.erase( it );
				//delete vm;
				return;
			}
		}
	}

private:

	typedef std::map<LPITEMIDLIST,std::shared_ptr<ViewModelCacheEntry> > cachetype;
	cachetype cache_;
};

ViewModelCache& viewModelCache()
{
	return mol::singleton<ViewModelCache>();
}

void invalidateViewModel(LPITEMIDLIST pidl)
{
	viewModelCache().invalidate(pidl);
	LPITEMIDLIST absolutePidl = pidlManager().concat( pidlManager().getRootPidl(), pidl );
	::SHChangeNotify(SHCNE_UPDATEDIR,SHCNF_IDLIST, (void*)absolutePidl,0);
	pidlManager().destroy(absolutePidl);
}

bool validate(LPITEMIDLIST pidl)
{
	if (!pidl )
		return true;

	LPITEMIDLIST parentPidl = pidlManager().getParentItem(pidl );
	if (!parentPidl )
		return true;

	ViewModel* vm = viewModelCache().get(parentPidl);
	pidlManager().destroy(parentPidl);

	if (!vm)
		return false;

	std::wstring n = pidlManager().getSftpPath(pidlManager().getLastItem(pidl));
	if ( !n.empty() && n[0] == L'/' )
	{
		n = n.substr(1);
	}

	for( size_t i = 0; i < vm->files.size(); i++)
	{
		if ( n == vm->files[i].getName() )
		{
			return true;
		}
	}
	return false;

}

ViewModel::ViewModel(void)
{
}


ViewModel::~ViewModel(void)
{
}


mol::sftp::RemoteFile* ViewModel::remoteFile(const mol::string& name )
{
	mol::string n = name;
	if ( !n.empty() && (n[0] == L'/') )
	{
		n = n.substr(1);
	}
	for ( size_t i = 0; i < files.size(); i++ )
	{
		if (files[i].getName() == n )
		{
			return &files[i];
		}
	}
	return 0;
}

ViewModel* viewModelRootFactory()
{
	if ( rootModel )
		return rootModel;

	ViewModel* viewModel = new ViewModel;

	LPITEMIDLIST profilePidl;
	::SHGetSpecialFolderLocation(::GetDesktopWindow(),CSIDL_PROFILE,&profilePidl);

	ODBGS("build root model");
	mol::string sshFolder = mol::io::desktop().getDisplayNameOf(profilePidl) + _T("\\.ssh\\");
	mol::string knownHosts = sshFolder + _T("known_servers");
	ODBGS(knownHosts);

	std::vector<std::wstring> server;

	mol::filestream fs;
	fs.open( mol::tostring(knownHosts),GENERIC_READ,FILE_SHARE_READ,0, OPEN_EXISTING);
	if ( fs )
	{
		while ( !fs.eof() )
		{
			std::string line;
			std::getline(fs,line);

			if (!line.empty())
			{
				size_t pos = line.find(" ");
				if ( pos != std::string::npos )
				{
					std::string host = mol::trim (line.substr(0,pos));
					if ( host.empty() )
						continue;
					std::string port = mol::trim (line.substr(pos+1));
					if ( port.empty() )
						port = "22";


					viewModel->server.push_back(mol::fromUTF8(host) + L":" + mol::toString(port));
				}
			}
		}
		fs.close();
	}
	rootModel = viewModel;
	return viewModel;
}

ViewModel* viewModelPathFactory(LPITEMIDLIST pidl, bool invalidate)
{
	if ( invalidate )
	{
		viewModelCache().invalidate(pidl);
	}
	return viewModelCache().get(pidl);
}

ViewModel* viewModelPathBuilder(LPITEMIDLIST pidl)
{
	ODBGS("build view model");

	ViewModel* viewModel = new ViewModel;

	ODBGS(pidlManager().getPidlPath(pidl));

	std::wstring host = pidlManager().getSftpServerName(pidl);

	std::wstring path = L"/";
	if ( pidlManager().isPath(pidlManager().getLastItem(pidl)) )
	{
		path = pidlManager().getSftpPath(pidl);
	}

	int port = pidlManager().getSftpServerPort(pidl);


	try {
		mol::ssh::Session ssh;
		ssh.open( mol::toUTF8(host), &credentialManager().credentials, port );

		mol::sftp::Session sftp(ssh);
		std::vector<mol::sftp::RemoteFile> files = sftp.list(path);
		for ( size_t i = 0; i < files.size(); i++ )
		{
			if ( files[i].getName() == L"." )
				continue;
			if ( files[i].getName() == L".." )
				continue;

			viewModel->files.push_back(files[i]);
		}
	}
	catch( mol::ssh::Ex& ex)
	{
		ODBGS(ex.msg());
		return 0;
	}

	return viewModel;
}
