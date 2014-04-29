#include "win/file.h"
#include "util/x.h"

#include <iomanip>

namespace mol {

///////////////////////////////////////////////////////////////////////

Directory::Directory() 
 : hDir_(0)
{}

Directory::Directory(const std::wstring& p) 
: path_(Path::addBackSlash(p)) ,hDir_(0)
{}

Directory::~Directory() 
{}

Directory::operator bool()
{
	return Path::exists(path_) && Path::isDir(path_);
}

std::wstring Directory::path() 
{ 
	return path_; 
}

void Directory::path( const std::wstring& p ) 
{ 
	path_ = p; 
}

std::vector<std::wstring> Directory::List(const std::wstring& p)
{
	std::vector<std::wstring> v;

	Directory dir(p);

	if (!dir)
		return v;

    std::wstring entry;
    while( (entry = dir.find(_T("*.*"))) != _T("") )
    {
        if ( entry == _T(".") )
            continue;
        if ( entry == _T("..") )
            continue;
        v.push_back(entry);
    }
    return v;
}

std::wstring Directory::find(const std::wstring& filter  )
{
	if (!(*this))
        return _T("");

    if ( !hDir_ )
    {      
		std::wstring f = Path::append(path_,filter);

        std::wstring ws = mol::towstring(f);
		if ( !Path::isUNC(f) )
			ws = L"\\\\?\\" + ws;

        hDir_ = ::FindFirstFileW( ws.c_str(), &wfd_ );
        if ( hDir_ == INVALID_HANDLE_VALUE )
        {
            reset();
            return _T("");
        }
        return mol::towstring(wfd_.cFileName);
    }
    else
    {
        if (!::FindNextFileW( hDir_,&wfd_ ) )
        {
            reset();
            return _T("");
        }
		return mol::towstring(wfd_.cFileName);
    }
}

void Directory::reset()
{
    ::ZeroMemory( &wfd_, sizeof(wfd_) );
    if ( hDir_ )
        ::FindClose( hDir_ );
    hDir_ = 0;
}

///////////////////////////////////////////////////////////////////////

SYSTEMTIME FileInfo::FileTimeToSysTime(FILETIME& FileTime)
{
    SYSTEMTIME st;
    FileTimeToSystemTime( &FileTime,&st);
    return st;
}

std::wstring FileInfo::SysTime(FILETIME& FileTime)
{
    SYSTEMTIME st;
    if (!FileTimeToSystemTime( &FileTime,&st))
        return _T("");

    std::wostringstream oss;
    oss << st.wYear << _T("-") << st.wMonth << _T("-") << st.wDay << _T(" ") << st.wHour << _T(":") << st.wMinute;
    return oss.str();
}

DWORD FileInfo::attributes()
{
    return dwFileAttributes;  
}

FILETIME& FileInfo::creationTime()
{
    return ftCreationTime;  
}

std::wstring FileInfo::created()
{
    return SysTime(creationTime());
}

FILETIME& FileInfo::lastAccessTime()
{
    return ftLastAccessTime;  
}

std::wstring FileInfo::lastAccessed()
{
    return SysTime(lastAccessTime());
}
    
FILETIME& FileInfo::lastWriteTime()
{
    return ftLastWriteTime;  
}

std::wstring FileInfo::lastWritten()
{
    return SysTime(lastWriteTime());
}

DWORD FileInfo::fileSizeHigh()
{
    return nFileSizeHigh;  
}

DWORD FileInfo::fileSizeLow()
{
    return nFileSizeLow;  
}

unsigned long long FileInfo::size()
{
	ULARGE_INTEGER uli;
	uli.HighPart = nFileSizeHigh;
	uli.LowPart  = nFileSizeLow;
	return uli.QuadPart;
}

std::wstring FileInfo::fileSize()
{
    LARGE_INTEGER li;
    li.HighPart = nFileSizeHigh;
    li.LowPart  = nFileSizeLow;
    return fileSize(li);
}

std::wstring FileInfo::fileSize(DWORD hi, DWORD lo)
{
    LARGE_INTEGER li;
    li.HighPart = hi;
    li.LowPart  = lo;
    return fileSize(li);
}

std::wstring FileInfo::fileSize(LARGE_INTEGER li)
{
    std::wostringstream oss;
    oss << std::setprecision( 4 );
    if ( li.HighPart  )
    {
        oss << (li.HighPart*4) << _T("GB");
    }
    else
    {
        double i = li.LowPart;
        double max = 1024*1024;
        if ( i > max)
            oss << i/(1024*1024) << _T(" MByte");
        else
        {
            max = 1024;
            if ( i > max )
                oss << i/1024 << _T(" KByte");
            else
                oss << i << _T(" Byte");
        }
    }
    return oss.str();
}
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

filestream_buf::filestream_buf(void)
{
	handle_  = INVALID_HANDLE_VALUE;
	phandle_ = 0;
}

filestream_buf::filestream_buf(HANDLE* handle)
{
	handle_  = *handle;
	phandle_ = handle;
}

filestream_buf::~filestream_buf(void)
{
	close();
}

bool filestream_buf::open( const std::string& fn, DWORD access, DWORD share,  LPSECURITY_ATTRIBUTES sec, DWORD create, DWORD flags )
{
	filename_ = fn;
	handle_ = ::CreateFileW( 
					Path::wpath(mol::towstring(fn)).c_str(), 
					access,
					share,
					sec,
					create,
					flags,
					0);

   return ( handle_ != INVALID_HANDLE_VALUE );
}

bool filestream_buf::create(const std::string& fn, bool overwrite)
{
	return open( fn, GENERIC_READ|GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL );
}

bool filestream_buf::open(const std::string& fn, bool overwrite)
{
	return open( fn, GENERIC_READ|GENERIC_WRITE, 0, 0, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL );
}

bool filestream_buf::openReadOnly(const std::string& fn)
{
	return open( fn, GENERIC_READ, 0, 0, 0, FILE_ATTRIBUTE_NORMAL );
}

bool filestream_buf::append(const std::string& fn, bool overwrite)
{
	return open( fn, GENERIC_READ|GENERIC_WRITE, 0, 0, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL );
}

void filestream_buf::close()
{
	if ( handle_ != INVALID_HANDLE_VALUE )
	{
		if ( (!phandle_) || (*phandle_ != INVALID_HANDLE_VALUE) )
		{
			::CloseHandle(handle_);
			if ( phandle_ )
			{
				*phandle_ = INVALID_HANDLE_VALUE;
				phandle_  = 0;
			}
		}
		handle_ = INVALID_HANDLE_VALUE;
	}
}

int filestream_buf::seek()
{
	return ::SetFilePointer( handle_, 0, 0, FILE_CURRENT );
}

int filestream_buf::seek(int s)
{
	return ::SetFilePointer( handle_, s, NULL, FILE_BEGIN);
}

const std::wstring filestream_buf::path()
{
	return mol::towstring(filename_);
}

FileInfo& filestream_buf::fileInfo()
{
	::GetFileInformationByHandle( handle_, &fi_ );
	return fi_;
}

int filestream_buf::buffered_write(char* c, int n)
{
	if ( n == 0 )
		return 0;

	DWORD len = 0;
	int r = ::WriteFile( handle_, c, n, &len, 0 );
	if ( r != 0 )
		return 0;
	return -1;
}

int filestream_buf::buffered_read (char* c, int n)
{
	if ( n == 0 )
		return 0;

	DWORD len = 0;
	if ( !::ReadFile( handle_, c, n, &len, 0 ) )
		return -1;

	return len;
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
		FileInfo& fi = this->fileInfo();
		this->seek( (int)(fi.fileSizeLow() - off) );		
	}
	return off;
}

////////////////////////////////////////////////////////////////////////


FileMapping::FileMapping()
	: file_(INVALID_HANDLE_VALUE), 
	  mapping_(0), 
	  view_(0)
{}

FileMapping::~FileMapping()
{
	close();
}


unsigned long FileMapping::getPageSize()
{
	SYSTEM_INFO systemInfo;
	::GetSystemInfo( &systemInfo );
	return systemInfo.dwAllocationGranularity;
}

unsigned long FileMapping::pageSize()
{
	static unsigned long l = getPageSize();
	return l;
}

bool FileMapping::map( const std::wstring& file, DWORD access, DWORD disp)
{
	close();

	file_ = ::CreateFile( file.c_str(), access, 0, NULL, disp, FILE_ATTRIBUTE_NORMAL, NULL );
	if ( file_ == INVALID_HANDLE_VALUE )
		return false;

	mol::FileInfo fi;
	::GetFileInformationByHandle( file_, &fi );
	
	fsize_ = fi.size();

	DWORD flag = PAGE_READWRITE;
	if ( !(access & GENERIC_WRITE) )
		flag = PAGE_READONLY;
	mapping_ = ::CreateFileMapping( file_, NULL, flag, 0, 0, 0);
	if ( mapping_ == NULL )
	{
		close();
		return false;
	}

	flag_ = FILE_MAP_WRITE;
	if ( !(access & GENERIC_WRITE) )
		flag_ = FILE_MAP_READ;

	return remap(0);
}

bool FileMapping::remap( unsigned long long offset )
{
	if ( !file_)
		return false;
	if ( !mapping_ )
		return false;

	if ( offset > fsize_ )
		return false;

	if ( view_ )
		::UnmapViewOfFile(view_);

	view_ = 0;

	int s  = pageSize();

	offset_ = (offset / s) * s;

#ifdef FILEMAP_DEBUG
	char buf[256];
	wsprintf(buf,"FILEMAPPING:\r\nremapped index %lx to offset offset %lx",(unsigned long)offset,(unsigned long)offset_);
	ODBGS(buf);
#endif

	ULARGE_INTEGER uli;
	uli.QuadPart = offset_;
	unsigned long mapsize = s + offset_ > fsize_ ? (unsigned long)(fsize_ - offset_) : s;
	view_ = ::MapViewOfFile( mapping_, flag_, uli.HighPart, uli.LowPart, mapsize );
	if ( view_ == NULL )
	{
		cry();
		close();
		return false;
	}
	return true;
}

char* FileMapping::operator[]( unsigned long long index )
{
	if ( index < offset_ )
	{
			remap(index);
	}
	else
	{
		if ( index >= offset_ + pageSize() ) //upperbound_ )
		{
			remap(index);
		}
	}

	unsigned long long base = index-offset_;

	return ((char*)view_) + base;
}

FileMapping::operator bool()
{
	if ( file_ == INVALID_HANDLE_VALUE )
		return false;
	if ( !mapping_ )
		return false;
	if ( !view_ )
		return false;
	return true;
}

void FileMapping::flush()
{
	if ( view_ )
		::FlushViewOfFile( view_, NULL );
}

void FileMapping::close()
{
	if ( view_ )
	{
		::UnmapViewOfFile(view_);
		view_ = 0;
	}
	if ( mapping_ )
	{
		::CloseHandle(mapping_);
		mapping_ = 0;
	}
	if ( file_ != INVALID_HANDLE_VALUE)
	{
		::CloseHandle(file_);
		file_ = INVALID_HANDLE_VALUE;
	}
}


unsigned long long FileMapping::size()
{
	return fsize_;
}

unsigned long long FileMapping::offset()
{
	return offset_;
}

//////////////////////////////////////////////////////////////////////////


bool File::exists(const std::wstring& path)
{
	DWORD atts = File::attributes(path);
	return (atts & FILE_ATTRIBUTE_NORMAL) != 0;
}

unsigned long long File::size(const std::wstring& path)
{
	WIN32_FILE_ATTRIBUTE_DATA wfad;
	DWORD atts = File::attributes(path,&wfad);

	ULARGE_INTEGER uli;
	uli.LowPart = wfad.nFileSizeLow;
	uli.HighPart = wfad.nFileSizeHigh;

	return uli.QuadPart;
}

unsigned long File::sizeHigh(const std::wstring& path)
{
	WIN32_FILE_ATTRIBUTE_DATA wfad;
	DWORD atts = File::attributes(path,&wfad);
	return wfad.nFileSizeHigh;
}

unsigned long File::sizeLow(const std::wstring& path)
{
	WIN32_FILE_ATTRIBUTE_DATA wfad;
	DWORD atts = File::attributes(path,&wfad);
	return wfad.nFileSizeLow;
}

DWORD File::attributes(const std::wstring& path, WIN32_FILE_ATTRIBUTE_DATA* data )
{
	WIN32_FILE_ATTRIBUTE_DATA wfad;
	if ( data == 0 )
		data = &wfad;

	DWORD result = ::GetFileAttributesEx(path.c_str(),GetFileExInfoStandard,(void*)data);
	return result;
}

} // end namespace mol