#ifndef _MOL_DEF_GUARD_DEFINE_SFTP_CLIENT_DEF_GUARD_
#define _MOL_DEF_GUARD_DEFINE_SFTP_CLIENT_DEF_GUARD_

#include "ssh.h"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

struct ssh_session_struct;
struct sftp_attributes_struct;
struct sftp_session_struct;
struct sftp_file_struct;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

namespace mol  {
namespace sftp {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

class RemoteFile
{
public:

	RemoteFile(sftp_attributes_struct* att);

	mol::string getName();
	uint8_t getType();
	uint32_t getPermissions();
	uint32_t getUID();
	uint32_t getGID();
	uint32_t getMtime();
	mol::string getOwner();
	mol::string getGroup();
	unsigned long long getSize();

	mol::string toString();
	mol::string formattedSize();
	mol::string formattedPermissions();

	bool isDir();

private:

	unsigned long long size_;
	mol::string group_;
	mol::string owner_;
	mol::string name_;
	uint32_t permissions_;
	uint32_t gid_;
	uint32_t uid_;
	uint8_t type_;
	uint32_t mtime_;
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

class Session
{
public:

	Session();
	Session(ssh_session_struct* session);
	~Session();
	void dispose();

	bool open(ssh_session_struct* session);

	bool mkdir(const std::wstring& dir,int mode);
	bool rmdir(const std::wstring& dir);
	bool rename(const std::wstring& oldName, const std::wstring& newName);

	bool unlink(const std::wstring& file);
	bool chown(const std::wstring& file, uint32_t owner, uint32_t group);
	bool chmod(const std::wstring& file, int mode);

	RemoteFile stat( const std::wstring& file );
	RemoteFile lstat( const std::wstring& file );

	std::vector<std::wstring> files( const std::wstring& dir );
	std::vector<RemoteFile> list( const std::wstring& dir );

	operator sftp_session_struct*()
	{
		return sftp_;
	}

private:
	sftp_session_struct* sftp_;
};

/////////////////////////////////////////////////////////////////////////
// SFTP FileStream Buffer
/////////////////////////////////////////////////////////////////////////

class filestream_buf 
	: public mol::BufferedStreamBuf< char, std::char_traits<char> >	
{
public:
	filestream_buf(sftp_session_struct* session);
	~filestream_buf(void);

	bool open( const std::wstring& fn, std::ios_base::openmode mode = std::ios_base::in, int permissions = 0 );
	void close();

	int seek();
	int seek(int s);

	const std::wstring path();

private:

	// IOStream to SFTP File stream conversion impl
	int buffered_write(char* c, int n);
	int buffered_read (char* c, int n);

	pos_type seekpos( pos_type s, std::ios_base::openmode which = std::ios_base::in | std::ios_base::out );
	pos_type seekoff( off_type off, std::ios_base::seekdir way, std::ios_base::openmode which = std::ios_base::in | std::ios_base::out );

	sftp_file_struct* handle_;
	std::wstring filename_;

	sftp_session_struct* session_;
};

/////////////////////////////////////////////////////////////////////////
// SFTP Stream Facade
/////////////////////////////////////////////////////////////////////////

template<class T>
class basic_FileStream : public std::basic_iostream< char, std::char_traits<char> >
{
public:

    typedef std::basic_iostream< char, std::char_traits<char> >	base_type;

	basic_FileStream(sftp_session_struct* session);
	basic_FileStream(sftp_session_struct* session, const std::wstring& fn);
	basic_FileStream(T* s);

	~basic_FileStream();

	bool open( const std::wstring& fn, std::ios_base::openmode mode = std::ios_base::in, int permissions = 0 )
	{
		clear();
		return buf_->open(fn,mode,permissions);
	}

	void close()
	{
		flush();
		buf_->close();
	}

	std::string getLine()
	{
		std::string ret;
		std::getline( *this, ret );
		return ret;
	}

	std::string readAll()
	{
		std::ostringstream oss;
		char buf[1024];
		while (!eof())
		{
			read(buf,1024);
			size_t n = gcount();
			if ( n > 0 )
				oss.write(buf,n);
		}
		return oss.str();
	}

	bool put(const std::string& s)
	{
		return write( s.c_str(), s.size() ) != 0;
	}

	const std::wstring path()
	{
		return buf_->path();
	}

	void seek(int n)
	{
		buf_->seek(n);
	}

	void seek()
	{
		buf_->seek();
	}

private:


	// create buffer helpers

	T* createBuf(sftp_session_struct* session)
	{
		buf_ = new T(session);
		return buf_;
		
	}

	// the buffer
	T* buf_;
};


/////////////////////////////////////////////////////////////////////////
// File Stream Facade c'tor/d'tor
/////////////////////////////////////////////////////////////////////////

template<class T>
basic_FileStream<T>::basic_FileStream(T* s)
	: basic_FileStream<T>::base_type(s),buf_(s)
{
}

template<class T>
basic_FileStream<T>::basic_FileStream(sftp_session_struct* session)
	: basic_FileStream<T>::base_type(createBuf(session))
{
}

template<class T>
basic_FileStream<T>::basic_FileStream( sftp_session_struct* session, const std::wstring& fn )
	: basic_FileStream<T>::base_type(createBuf(session))
{
	if ( !open( fn ) )
		throw mol::ssh::Ex("File open failed");
}

template<class T>
basic_FileStream<T>::~basic_FileStream()
{
	delete buf_;
}


typedef basic_FileStream<filestream_buf> filestream;

//////////////////////////////////////////////////////////////////////////


} // end namespace scp
} // end namespace sftp

#endif