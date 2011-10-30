#include "ssh/scp.h"
#include <libssh/libssh.h>
#include <libssh/callbacks.h>
#include <libssh/scp.h>
#include <libssh/sftp.h>

namespace mol {
namespace scp {


Session::Session()
	:scp_(0),ssh_(0)
{}

Session::Session(ssh_session_struct* session)
	:scp_(0),ssh_(session)
{}

Session::~Session()
{
	dispose();
}

void Session::dispose()
{
	if (!scp_)
		return;

	ssh_scp_close(scp_);
	ssh_scp_free(scp_);
	scp_ = 0;
}

bool Session::open( ssh_session_struct* session, int mode, const std::string& path )
{
	dispose();
	scp_ = ssh_scp_new(session, mode, path.c_str() );
	if (scp_ == NULL)
	{
		throw mol::ssh::Ex("open scp session failed");
	}

	int rc = ssh_scp_init(scp_);
	if (rc != SSH_OK)
	{
		ssh_scp_free(scp_);
		throw mol::ssh::Ex("init scp session failed");
	}
	return true;
}

bool Session::open( int mode, const std::string& path )
{
	return open( ssh_, mode, path);
}

bool Session::enter_dir(  const std::string& dir, int mode )
{
	int rc = ssh_scp_push_directory(scp_, dir.c_str(), mode );
	if (rc != SSH_OK)
	{
		dispose();
		throw mol::ssh::Ex("creater emote dir failed");
	}
	return true;
}

bool Session::leave_dir()
{
	int rc = ssh_scp_leave_directory(scp_);
	if (rc != SSH_OK)
	{
		dispose();
		throw mol::ssh::Ex("error leaving directory");
	}
	return true;
}

bool Session::push_dir(  const std::string& localdir, int mode )
{
	mol::string dir = mol::toString(localdir);
	mol::string dirname = mol::Path::filename(dir);

	if ( !mol::Path::exists(dir) )
		return false;

	if ( !mol::Path::isDir(dir) )
		return false;

	enter_dir( mol::tostring(dirname),0700);
	std::vector<mol::string> files = mol::Directory::List(dir);

	for ( size_t i = 0; i < files.size(); i++)
	{
		mol::string path = mol::Path::addBackSlash(dir) + files[i];
		if ( mol::Path::isDir(path) )
		{
			enter_dir( mol::tostring(files[i]), mode);
			push_dir(mol::tostring(path),mode);
			leave_dir();
		}
		else
		{
			push_file( mol::tostring(path), mode );
		}
	}
	leave_dir();
	return true;
}

bool Session::push_file( const std::string& file, const std::string& content, int mode )
{
	int rc = ssh_scp_push_file(scp_, file.c_str(), content.size(), mode );
	if (rc != SSH_OK)
	{
		dispose();
		throw mol::ssh::Ex("error pushing file");
	}

	rc = ssh_scp_write(scp_, content.c_str(), content.size() );
	if (rc != SSH_OK)
	{
		dispose();
		throw mol::ssh::Ex("error writing file");
	}		
	return true;
}

bool Session::push_file( const std::string& path, int mode )
{
	const std::string& file = mol::tostring(mol::Path::filename(mol::toString(path)));

	mol::filestream fs;
	if (!fs.open(mol::tostring(path)))
		throw mol::ssh::Ex("could not open file for sending");

	std::string s = fs.readAll();
	fs.close();

	int rc = ssh_scp_push_file(scp_, file.c_str(), s.size(), mode );
	if (rc != SSH_OK)
	{
		dispose();
		throw mol::ssh::Ex("error pushing file");
	}

	rc = ssh_scp_write(scp_, s.c_str(), s.size() );
	if (rc != SSH_OK)
	{
		dispose();
		throw mol::ssh::Ex("error writing file");
	}		
	return true;
}

bool Session::pull_file( const std::string& localdir)
{
	int rc = ssh_scp_pull_request(scp_);
	if (rc != SSH_SCP_REQUEST_NEWFILE)
	{
		throw mol::ssh::Ex("no file received");
	}

	size_t size = ssh_scp_request_get_size(scp_);
	const char* filename = ssh_scp_request_get_filename(scp_);//strdup(ssh_scp_request_get_filename(scp));
	int mode = ssh_scp_request_get_permissions(scp_);
	//printf("Receiving file %s, size %d, permisssions 0%o\n", filename, size, mode);
	//free(filename);

	char* buffer = (char*)malloc(size);
	if (buffer == NULL)
	{
		throw mol::ssh::Ex("out of memory");
	}

	ssh_scp_accept_request(scp_);
	rc = ssh_scp_read(scp_, buffer, size);
	if (rc == SSH_ERROR)
	{
		free(buffer);
		throw mol::ssh::Ex("error reading file");
	}

	mol::string localpath = mol::Path::addBackSlash(mol::toString(localdir)) + mol::toString(filename);
		

	mol::filestream fs;
	if (fs.open( mol::tostring(localpath)))
	{
		fs.write(buffer,size);
		fs.close();
	}
		
	free(buffer);

	rc = ssh_scp_pull_request(scp_);
	if (rc != SSH_SCP_REQUEST_EOF)
	{
		throw mol::ssh::Ex("error expecting eof");
			
	}
	return true;
}



bool Session::read_file(  std::string& content)
{
	int rc = ssh_scp_pull_request(scp_);
	if (rc != SSH_SCP_REQUEST_NEWFILE)
	{
		throw mol::ssh::Ex("no file received");
	}

	size_t size = ssh_scp_request_get_size(scp_);
	const char* filename = ssh_scp_request_get_filename(scp_);//strdup(ssh_scp_request_get_filename(scp));
	int mode = ssh_scp_request_get_permissions(scp_);
	//printf("Receiving file %s, size %d, permisssions 0%o\n", filename, size, mode);
	//free(filename);

	char* buffer = (char*)malloc(size);
	if (buffer == NULL)
	{
		throw mol::ssh::Ex("out of memory");
	}

	ssh_scp_accept_request(scp_);
	rc = ssh_scp_read(scp_, buffer, size);
	if (rc == SSH_ERROR)
	{
		free(buffer);
		throw mol::ssh::Ex("error reading file");
	}
		
	content = std::string(buffer,size);
		
	free(buffer);

	rc = ssh_scp_pull_request(scp_);
	if (rc != SSH_SCP_REQUEST_EOF)
	{
		throw mol::ssh::Ex("error expecting eof");
			
	}
	return true;
}

bool Session::pull_dir( const std::string& localdir)
{
	std::string local = localdir;

	bool eof = false;
	while(!eof)
	{
		int rc = ssh_scp_pull_request(scp_);
		switch(rc)
		{
			case SSH_SCP_REQUEST_NEWFILE :
			{
				size_t size = ssh_scp_request_get_size(scp_);
				const char* filename = ssh_scp_request_get_filename(scp_);
				int mode = ssh_scp_request_get_permissions(scp_);

				char* buffer = (char*)malloc(size);
				if (buffer == NULL)
				{
					throw mol::ssh::Ex("out of memory");
				}

				ssh_scp_accept_request(scp_);
				rc = ssh_scp_read(scp_, buffer, size);
				if (rc == SSH_ERROR)
				{
					free(buffer);
					throw mol::ssh::Ex("error reading file");
				}

				mol::string localpath = mol::Path::addBackSlash(mol::toString(local)) + mol::toString(filename);
		

				mol::filestream fs;
				if (fs.open( mol::tostring(localpath)))
				{
					fs.write(buffer,size);
					fs.close();
				}
		
				free(buffer);

				break;
			}
			case SSH_SCP_REQUEST_EOF :
			{
				eof = true;
				break;
			}
			case SSH_SCP_REQUEST_NEWDIR :
			{
				size_t size = ssh_scp_request_get_size(scp_);
				const char* filename = ssh_scp_request_get_filename(scp_);
				int mode = ssh_scp_request_get_permissions(scp_);

				ssh_scp_accept_request(scp_);

				mol::string localpath = mol::Path::addBackSlash(mol::toString(local)) + mol::toString(filename);
				local = mol::tostring(localpath);		

				if ( mol::Path::exists(localpath) && !mol::Path::isDir(localpath) )
				{
					throw mol::ssh::Ex("file already exists");
				}

				if ( !mol::Path::exists(localpath) && !mol::Path::isDir(localpath) )
				{
					::CreateDirectoryW(localpath.c_str(),0);
				}

				break;
			}
			case SSH_SCP_REQUEST_ENDDIR :
			{
				mol::string localpath = mol::Path::parentDir(mol::toString(local));

				local = mol::tostring(localpath);		
				break;
			}
			case SSH_SCP_REQUEST_WARNING :
			{
				break;
			}
			case SSH_ERROR :
			{
				throw mol::ssh::Ex("SSH_ERROR reading recursively");
				break;
			}
			default :
			{
					
			}
		}
	}

	return true;
}

/*
std::string permission(int mode)
{
	char* c = ::ssh_scp_string_mode(mode);
	std::string ret(c);
	free(c);
	return ret;
}


int permission(const std::string& mode)
{
	int c = ::ssh_scp_integer_mode(mode.c_str());
	return c;
}
*/

} // end namespace scp
} // end namespace mol
