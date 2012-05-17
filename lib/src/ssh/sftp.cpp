#include "ssh/sftp.h"
#include <libssh/libssh.h>
#include <libssh/callbacks.h>
#include <libssh/scp.h>
#include <libssh/sftp.h>
#include <fcntl.h>

namespace mol  {
namespace sftp {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

RemoteFile::RemoteFile(	const mol::string& name, uint8_t type, 
			uint32_t perms, uint32_t uid, uint32_t gid, 
			uint32_t mtime, unsigned long long size, 
			const mol::string& owner, const mol::string& group )

			: name_(name), type_(type), 
			  permissions_(perms), uid_(uid), gid_(gid),
			  mtime_(mtime), size_(size), 
			  owner_(owner),group_(group)
{
}

RemoteFile::RemoteFile(sftp_attributes_struct* att)
	: size_(0),type_(2),mtime_(0),gid_(0),uid_(0),permissions_(0)
{
	if ( att == 0 )
	{
		return;
	}

	size_  = att->size;
	if ( att->name )
		name_  = mol::fromUTF8(att->name);

	if ( att->owner)
		owner_ = mol::fromUTF8(att->owner);

	if ( att->group)
		group_ = mol::fromUTF8(att->group);

	type_  = att->type;
	mtime_ = att->mtime;

	gid_ = att->gid;
	uid_ = att->uid;

	permissions_ = att->permissions;
}

bool RemoteFile::isDir()
{
	return (type_ & SSH_FILEXFER_TYPE_DIRECTORY) != 0;
}

mol::string RemoteFile::getName() 
{
	return name_;
}

uint8_t RemoteFile::getType() 
{		
	return type_;
}

uint32_t RemoteFile::getPermissions() 
{		
	return permissions_;
}

uint32_t RemoteFile::getUID() 
{		
	return uid_;
}

uint32_t RemoteFile::getGID() 
{		
	return gid_;
}

uint32_t RemoteFile::getMtime() 
{		
	return mtime_;
}

mol::string RemoteFile::getOwner() 
{
	return owner_;
}

mol::string RemoteFile::getGroup() 
{
	return group_;
}

unsigned long long RemoteFile::getSize() 
{		
	return size_;
}

mol::string RemoteFile::toString()
{
	mol::ostringstream oss;

	oss << getName() << _T("\t")
		<< getOwner() << _T("(")
		<< getUID() << _T(") \t")
		<< getGroup() << _T("(")
		<< getGID() << _T(") \t")
		<< getSize();

	return oss.str();
}

mol::string RemoteFile::formattedSize()
{
	if(isDir())
	{
		return _T("Directory");
	}
	LARGE_INTEGER li;
	li.QuadPart = size_;
	mol::string s = FileInfo::fileSize(li);
	return s;
}

mol::string RemoteFile::formattedPermissions()
{
	mol::ostringstream oss;
	oss << std::oct << permissions_;
	return oss.str();
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////


Session::Session()
	:sftp_(0),ssh_(0)
{}

Session::Session(mol::ssh::Session& session)
	:sftp_(0),ssh_(&session)
{
	open(session);
}


Session::~Session()
{
	dispose();
}

void Session::dispose()
{
	if ( sftp_ )
	{
		sftp_free(sftp_);
	}
	sftp_ = 0;
}

RemoteFile Session::stat( const std::wstring& file )
{
	sftp_attributes att = sftp_stat( sftp_, mol::toUTF8(file).c_str() );
	RemoteFile rf(att);
    sftp_attributes_free(att);
	return rf;
}

RemoteFile Session::lstat( const std::wstring& file )
{
	sftp_attributes att = sftp_lstat( sftp_, mol::toUTF8(file).c_str() );
	RemoteFile rf(att);
    sftp_attributes_free(att);
	return rf;
}

void Session::open(mol::ssh::Session& session)
{
	ssh_ = &session;

	if (!ssh_->is_connected() )
	{
		ssh_->dispose();
		ssh_->open();
		if (!ssh_->is_connected() )
		{
			throw mol::ssh::Ex(0,"error allocating new sftp session - failed to reopen ssh connection failed");
		}
	}

	dispose();
	sftp_ = sftp_new(session);
	if (sftp_ == NULL)
	{
		throw mol::ssh::Ex(0,"error allocating new sftp session");
	}
	open();
}

void Session::open()
{
	if (!ssh_->is_connected() )
	{
		dispose();
		ssh_->open();
		if (!ssh_->is_connected() )
		{
			return;
		}
		sftp_ = sftp_new(*ssh_);
	}

	int rc = sftp_init(sftp_);
	if (rc != SSH_OK)
	{
		dispose();
		throw mol::ssh::Ex(0,"error initializing sftp session");
	}
}

bool Session::is_connected()
{
	return ssh_->is_connected();
}


bool Session::connect()
{
	if (is_connected()) 
	{
		return true;
	}
	open();
	return is_connected();
}

bool Session::mkdir(const std::wstring& dir,int mode)
{
	if (!connect())
		return false;

	int rc = sftp_mkdir(sftp_, mol::toUTF8(dir).c_str(), mode);
	if (rc != SSH_OK)
	{
		return false;
	}
	return true;
}

bool Session::rename(const std::wstring& oldName, const std::wstring& newName)
{
	if (!connect())
		return false;

	int rc = sftp_rename( sftp_, mol::toUTF8(oldName).c_str(), mol::toUTF8(newName).c_str() );
	if (rc != SSH_OK)
	{
		return false;
	}
	return true;
}

bool Session::rmdir(const std::wstring& dir)
{
	if (!connect())
		return false;

	int rc = sftp_rmdir(sftp_, mol::toUTF8(dir).c_str());
	if (rc != SSH_OK)
	{
		return false;
	}
	return true;
}

bool Session::unlink(const std::wstring& file)
{
	if (!connect())
		return false;

	int rc = sftp_unlink(sftp_, mol::toUTF8(file).c_str());
	if (rc != SSH_OK)
	{
		return false;
	}
	return true;
}

bool Session::chown(const std::wstring& file, uint32_t owner, uint32_t group)
{
	if (!connect())
		return false;

	int rc = sftp_chown(sftp_, mol::toUTF8(file).c_str(),owner,group);
	if (rc != SSH_OK)
	{
		return false;
	}
	return true;
}

bool Session::chmod(const std::wstring& file, int mode)
{
	if (!connect())
		return false;

	int rc = sftp_chmod(sftp_, mol::toUTF8(file).c_str(),mode);
	if (rc != SSH_OK)
	{
		return false;
	}
	return true;
}

std::vector<std::wstring> Session::files( const std::wstring& dir )
{
	std::vector<std::wstring> v;

	if (!connect())
		return v;

	sftp_attributes attributes;
	sftp_dir remote_dir = sftp_opendir(sftp_,mol::toUTF8(dir).c_str());
	if ( !remote_dir)
		throw mol::ssh::Ex(0,"directory not found");

	while ((attributes = sftp_readdir(sftp_, remote_dir)) != NULL)
	{
		v.push_back( mol::fromUTF8(attributes->name) );

		sftp_attributes_free(attributes);
	}

	if (!sftp_dir_eof(remote_dir))
	{
		throw mol::ssh::Ex(0,"can't list dir");
	}

	int rc = sftp_closedir(remote_dir);
	if (rc != SSH_OK)
	{
		throw mol::ssh::Ex(0,"can't close directory");
	}
	return v;
}

std::vector<RemoteFile> Session::list( const std::wstring& dir )
{
	std::vector<RemoteFile> v;

	if (!connect())
		return v;

	sftp_attributes attributes;
	sftp_dir remote_dir = sftp_opendir(sftp_,mol::toUTF8(dir).c_str());
	if ( !remote_dir)
		throw mol::ssh::Ex(0,"directory not found");

	while ((attributes = sftp_readdir(sftp_, remote_dir)) != NULL)
	{
		RemoteFile rf(attributes);
		v.push_back(rf);
		sftp_attributes_free(attributes);
	}

	if (!sftp_dir_eof(remote_dir))
	{
		throw mol::ssh::Ex(0,"can't list dir");
	}

	int rc = sftp_closedir(remote_dir);
	if (rc != SSH_OK)
	{
		throw mol::ssh::Ex(0,"can't close directory");
	}
	return v;
}




///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

filestream_buf::filestream_buf(sftp_session_struct* session)
{
	session_ = session;
	handle_  = 0;
}


filestream_buf::~filestream_buf(void)
{
	if ( handle_)
	{
		sftp_close(handle_);
		handle_ = 0;
	}
}

bool filestream_buf::open( const std::wstring& fn, std::ios_base::openmode mode, int permissions )
{
	filename_ = fn;

	int access_type = O_RDONLY;

	if ( mode & std::ios_base::out)
	{
		access_type |= O_RDWR;
		access_type |= O_CREAT;
	}

	handle_ =  sftp_open(session_, mol::toUTF8(fn).c_str(), access_type, permissions);
	if (handle_ == NULL)
    {
		return false;
	}

    return true;
}

void filestream_buf::close()
{
	if ( handle_ != 0 )
	{
		sftp_close(handle_);
		handle_ = 0;
	}
}

int filestream_buf::seek()
{
	return sftp_tell( handle_ );
}

int filestream_buf::seek(int s)
{
	return sftp_seek( handle_, s );
}

const std::wstring filestream_buf::path()
{
	return filename_;
}


int filestream_buf::buffered_write(char* c, int n)
{
	if ( n == 0 )
		return 0;

	size_t nwritten = sftp_write(handle_, c, n);
	if ( nwritten == n )
		return 0;
	return -1;
}

int filestream_buf::buffered_read (char* c, int n)
{
	if ( n == 0 )
		return 0;

	size_t nbytes = sftp_read(handle_, c, n);
	if ( nbytes < 0 )
		return -1;
	return (int)nbytes;
}


std::ios::pos_type filestream_buf::seekpos( pos_type s, std::ios_base::openmode which )
{
  this->seek((int)s);
  return s;
}

std::ios::pos_type filestream_buf::seekoff( off_type off, std::ios_base::seekdir way, std::ios_base::openmode )
{
	if ( way == std::ios_base::beg )
		this->seek( (int)off );
	if ( way == std::ios_base::cur )
		this->seek( (int)(seek() + off) );
	if ( way == std::ios_base::end )
	{
		throw mol::ssh::Ex(0,"not implemented");
	}
	return off;
}


} // end namespace scp
} // end namespace sftp