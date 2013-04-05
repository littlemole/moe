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



template<class S, class E>
class AsyncFile : public OverLap
{
public:

	static DWORD load(const std::wstring& path, S onSuccess)
	{
		return load(path,onSuccess,[](DWORD){});
	}

	static DWORD load(const std::wstring& path, S onSuccess, E onError)
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
		{
			return ::GetLastError();
		}


		AsyncFile<S,E>* af = new AsyncFile<S,E>(handle,onSuccess,onError);

		BOOL r = ::ReadFileEx(handle,af->buf_,af->size_.LowPart,af,&AsyncFile::onLoadAsync);
		if ( r == FALSE )
		{
			delete af;
			return ::GetLastError();
		}
		return ERROR_SUCCESS;
	}

private:

	AsyncFile(HANDLE h, S onSuccess, E onError)
		:OverLap(h),successHandler(onSuccess),errorHandler(onError)
	{}

	static void __stdcall onLoadAsync(DWORD dwErrorCode, DWORD dwNumberOfBytesTransfered, LPOVERLAPPED lpOverlapped)
	{
		boost::shared_ptr<AsyncFile> overLap((AsyncFile*)lpOverlapped);
		if ( dwErrorCode != ERROR_SUCCESS )
		{
			overLap->errorHandler(dwErrorCode);
			return;
		}

		if ( dwNumberOfBytesTransfered != overLap->size_.LowPart )
		{
			overLap->errorHandler(0);
			return;
		}
		std::string bytes( overLap->buf_, dwNumberOfBytesTransfered);
		overLap->successHandler(bytes);
	}

	S successHandler;
	E errorHandler;
};



template<class B,class E>
DWORD async_file(const std::wstring& file, B b, E e)
{
	return AsyncFile<B,E>::load(file,b,e);
}


class AsyncLoader
{
public:
	AsyncLoader(const std::wstring& file)
		:file_(file)
	{}

	template<class S>
	DWORD then( S s)
	{
		return AsyncFile<S>::load(file_,s);
	}


	template<class S,class E>
	DWORD then( S s, E e)
	{
		return AsyncFile<S,E>::load(file_,s,e);
	}

	template<class T>
	DWORD then( T* t, void (T::*fun)(const std::string&)  )
	{
		return async_file( file_, boost::bind(fun,t,_1), [](DWORD){} );
	}


	template<class T>
	DWORD then( T* t, void (T::*onSuccess)(const std::string&), void (T::*onError)(DWORD) )
	{
		return async_file( file_, boost::bind(onSuccess,t,_1), boost::bind(onError,t,_1 ) );
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