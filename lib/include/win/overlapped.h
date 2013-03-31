#ifndef MOL_FILE_LIB_ASYNCFILELOAD_DEF_GUARD_DEFINE_
#define MOL_FILE_LIB_ASYNCFILELOAD_DEF_GUARD_DEFINE_

#include "win/wnd.h"
#include <sstream>
#include "boost/shared_ptr.hpp"

namespace mol {
namespace win {

class OverLap : public OVERLAPPED
{
public:

	OverLap(HANDLE h)
		: handle_(h)
	{
		::ZeroMemory(this,sizeof(OVERLAPPED));

		size_.QuadPart = 0;
		::GetFileSizeEx(handle_,&size_);
		buf_ = new char[size_.LowPart];
	}

	~OverLap()
	{
		delete[] buf_;
		::CloseHandle(handle_);
	}

	char* buf_;
	HANDLE handle_;
	LARGE_INTEGER size_;
};

template<class B>
class AsyncFile : public OverLap
{
public:

	static DWORD load(const std::wstring& path, B b)
	{
		HANDLE handle = ::CreateFileW( 
					Path::wpath(path).c_str(), 
					GENERIC_READ,
					FILE_SHARE_READ|FILE_SHARE_WRITE|FILE_SHARE_DELETE,
					0,
					OPEN_EXISTING,
					FILE_FLAG_OVERLAPPED,
					0);

		if ( handle == INVALID_HANDLE_VALUE )
			return ::GetLastError();


		AsyncFile<B>* af = new AsyncFile<B>(handle,b);

		BOOL r = ::ReadFileEx(handle,af->buf_,af->size_.LowPart,af,&AsyncFile::onLoadAsync);
		if ( r == FALSE )
		{
			delete af;
			return ::GetLastError();
		}
		return ERROR_SUCCESS;
	}

private:

	AsyncFile(HANDLE h, B b)
		:OverLap(h),bound(b)
	{}

	static void __stdcall onLoadAsync(DWORD dwErrorCode, DWORD dwNumberOfBytesTransfered, LPOVERLAPPED lpOverlapped)
	{
		boost::shared_ptr<AsyncFile> overLap((AsyncFile*)lpOverlapped);
		if ( dwErrorCode != ERROR_SUCCESS )
		{
			std::ostringstream oss;
			oss << "Error reading file!";
			overLap->bound(oss.str());
			return;
		}

		if ( dwNumberOfBytesTransfered != overLap->size_.LowPart )
		{
			std::ostringstream oss;
			oss << "Error reading file! size mismatch expected (" << overLap->size_.LowPart << ") but got " << dwNumberOfBytesTransfered;
			std::string bytes( oss.str() );
			return;
		}
		std::string bytes( overLap->buf_, dwNumberOfBytesTransfered);
		overLap->bound(bytes);
	}

	B bound;
};

template<class B>
DWORD async_file(const std::wstring& file, B b)
{
	return AsyncFile<B>::load(file,b);
}

class AsyncLoader
{
public:
	AsyncLoader(const std::wstring& file)
		:file_(file)
	{}

	template<class B>
	DWORD then( B b)
	{
		return AsyncFile<B>::load(file_,b);
	}


	template<class T>
	DWORD then( void (T::*fun)(const std::string&), T* t )
	{
		return async_file( file_, boost::bind(fun,t,_1) );
	}

private:
	std::wstring file_;
};

} // end namespace win

inline mol::win::AsyncLoader load_async(const std::wstring& file)
{
	return mol::win::AsyncLoader(file);
}

} // end namespace mol

#endif