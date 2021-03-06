#ifndef MOL_FILE_LIB_DEF_GUARD_DEFINE_
#define MOL_FILE_LIB_DEF_GUARD_DEFINE_

#include "conf.h"
#include "util/str.h"
#include "tcp/streambuf.h"
#include "win/app.h"
#include "win/path.h"
#include <vector>

namespace mol {

class FileInfo : public BY_HANDLE_FILE_INFORMATION
{
public:

    DWORD attributes();
    FILETIME& creationTime();
    std::wstring created();
    FILETIME& lastAccessTime();
    std::wstring lastAccessed();
    FILETIME& lastWriteTime();
    std::wstring lastWritten();
    DWORD fileSizeHigh();
    DWORD fileSizeLow();
	unsigned long long size();
    std::wstring fileSize();

    static SYSTEMTIME FileTimeToSysTime(FILETIME& FileTime);
    static std::wstring SysTime(FILETIME& FileTime);
    static std::wstring fileSize(DWORD hi, DWORD lo);
    static std::wstring fileSize(LARGE_INTEGER li);
};

class Directory
{
public:
	Directory();
	Directory(const std::wstring& p);
	~Directory();

	operator bool();
	std::wstring path();
	void path( const std::wstring& p );

	static std::vector<std::wstring> List(const std::wstring& p);

    std::wstring find(const std::wstring& filter = _T("*.*") );
    void reset();

private:
	std::wstring         path_;
    WIN32_FIND_DATAW	wfd_;
    HANDLE				hDir_;

};

/////////////////////////////////////////////////////////////////////////
// Win32 FileStream Buffer
/////////////////////////////////////////////////////////////////////////

class filestream_buf 
	: public mol::BufferedStreamBuf< char, std::char_traits<char> >	
{
public:
	filestream_buf(void);
	filestream_buf(HANDLE* phandle);
	~filestream_buf(void);

	bool create(const std::string& fn, bool overwrite);
	bool open(const std::string& fn, bool overwrite);
	bool openReadOnly(const std::string& fn);
	bool append(const std::string& fn, bool overwrite);
	void close();

	bool open( const std::string& fn, DWORD access = GENERIC_READ|GENERIC_WRITE, DWORD share = 0,  LPSECURITY_ATTRIBUTES sec = 0, DWORD create = OPEN_ALWAYS, DWORD flags = 0 );

	int seek();
	int seek(int s);
	FileInfo& fileInfo();

	const std::wstring path();

private:

	// IOStream to Win32 File stream conversion impl
	int buffered_write(char* c, int n);
	int buffered_read (char* c, int n);


	pos_type seekpos( pos_type s, std::ios_base::openmode which = std::ios_base::in | std::ios_base::out );
	pos_type seekoff( off_type off, std::ios_base::seekdir way, std::ios_base::openmode which = std::ios_base::in | std::ios_base::out );

	HANDLE handle_;
	HANDLE* phandle_;
	std::string filename_;
	FileInfo fi_;
};

/////////////////////////////////////////////////////////////////////////
// File Stream Facade
/////////////////////////////////////////////////////////////////////////

template<class T>
class basic_FileStream : public std::basic_iostream< char, std::char_traits<char> >
{
public:

    typedef std::basic_iostream< char, std::char_traits<char> >	base_type;

	basic_FileStream();
	basic_FileStream(const std::string& fn);
	basic_FileStream(HANDLE& handle);
	basic_FileStream(T* s);

	~basic_FileStream();

	bool create(const std::string& fn, bool overwrite = true)
	{
		clear();
		return buf_->create(fn,overwrite);
	}


	// open file
	bool open( const std::string& fn, DWORD access, DWORD share = 0,  LPSECURITY_ATTRIBUTES sec = 0, DWORD create = OPEN_ALWAYS, DWORD flags = FILE_ATTRIBUTE_NORMAL )
	{
		bool result = buf_->open(fn,access,share,sec,create,flags);
		if ( !result ) 
		{
			setstate( std::ios_base::badbit | std::ios_base::failbit | std::ios_base::eofbit );
		}
		return result;
	}

	bool open( const std::string& fn )
	{
		clear();
		bool result =  buf_->open(fn,true);
		if ( !result ) 
		{
			setstate( std::ios_base::badbit | std::ios_base::failbit | std::ios_base::eofbit );
		}
		return result;
	}

	bool openReadOnly(const std::string& fn)
	{
		clear();
		bool result =   buf_->openReadOnly(fn);
		if ( !result ) 
		{
			setstate( std::ios_base::badbit | std::ios_base::failbit | std::ios_base::eofbit );
		}
		return result;
	}
	bool append(const std::string& fn)
	{
		clear();
		bool result =   buf_->append(fn,true);
		if ( !result ) 
		{
			setstate( std::ios_base::badbit | std::ios_base::failbit | std::ios_base::eofbit );
		}
		return result;
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
		while(!eof())
		{
			read(buf,1024);
			std::streamsize len = gcount();
			oss.write(buf,len);
		}

		/*
		bool firstline = true;
		while(!eof())
		{
			if (firstline) {
				firstline = false;
				std::string s = getLine();
				if ( !s.empty() )
					oss << s;
			}
			else {
				std::string s = getLine();
				if ( !s.empty() )
					oss << std::endl << s;
			}
		}
		*/
		return oss.str();
	}

	bool put(const std::string& s)
	{
		return write( s.c_str(), s.size() ).good();
	}

	FileInfo& fileInfo()
	{
		return buf_->fileInfo();
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

	T* createBuf()
	{
		buf_ = new T;
		return buf_;
		
	}

	T* createBuf(HANDLE* handle)
	{
		buf_ = new T(handle);
		return buf_;
		
	}

	// the buffer
	T* buf_;
};


/////////////////////////////////////////////////////////////////////////
// File Stream Facade c'tor/d'tor
/////////////////////////////////////////////////////////////////////////

template<class T>
basic_FileStream<T>::basic_FileStream()
	: basic_FileStream<T>::base_type(createBuf())
{
}

template<class T>
basic_FileStream<T>::basic_FileStream(T* s)
	: basic_FileStream<T>::base_type(s),buf_(s)
{
}

template<class T>
basic_FileStream<T>::basic_FileStream(HANDLE& phandle)
	: basic_FileStream<T>::base_type(createBuf(&phandle))
{
}

template<class T>
basic_FileStream<T>::basic_FileStream( const std::string& fn )
	: basic_FileStream<T>::base_type(createBuf())
{
	if ( !open( fn ) )
		throw mol::X("File open failed");
}

template<class T>
basic_FileStream<T>::~basic_FileStream()
{
	delete buf_;
}


typedef basic_FileStream<filestream_buf> filestream;

//////////////////////////////////////////////////////////////////////////

class File
{
public:

	static bool exists(const std::wstring& path);
	static unsigned long long size(const std::wstring& path);
	static unsigned long sizeHigh(const std::wstring& path);
	static unsigned long sizeLow(const std::wstring& path);
	static DWORD attributes(const std::wstring& path, WIN32_FILE_ATTRIBUTE_DATA* data = 0);

};


//////////////////////////////////////////////////////////////////////////


class FileMapping
{
public:
	FileMapping();
	~FileMapping();

	operator bool();
	bool map( const std::wstring& file, DWORD access = GENERIC_READ|GENERIC_WRITE, DWORD disp = OPEN_EXISTING );
	void close();

	unsigned long long size();
	unsigned long long offset();

	char* operator[]( unsigned long long index );
	void flush();

	static unsigned long pageSize();
private:
	
	static unsigned long getPageSize();
	bool remap( unsigned long long offset );

	HANDLE				file_;
	HANDLE				mapping_;
	DWORD				flag_;
	void*				view_;
	unsigned long long	fsize_;
	unsigned long long	offset_;
};

}

#endif