#ifndef _UNICODE_HELP_DEF_
#define _UNICODE_HELP_DEF_

#include "conf.h"

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#ifdef WIN32
#include <tchar.h>
#endif

namespace mol {

//////////////////////////////////////////////////////////////////////
// win32 conversions support 
//////////////////////////////////////////////////////////////////////

#ifdef WIN32


std::string toUTF8( const std::string& str, long cp = CP_ACP);
std::string toUTF8( const std::wstring& str, long cp = CP_ACP);

std::wstring fromUTF8(const std::string& str, long cp = CP_ACP);

std::string  tostring( const std::string& str, long cp = CP_ACP);
std::string  tostring( const std::wstring& str, long cp = CP_ACP);
std::string  tostring( const char* str, long cp = CP_ACP);
std::string  tostring( const wchar_t* wstr, long cp = CP_ACP);

std::wstring  towstring( const std::string& str, long cp = CP_ACP);
std::wstring  towstring( const std::wstring& str, long cp = CP_ACP);
std::wstring  towstring( const char* str, long cp = CP_ACP);
std::wstring  towstring( const wchar_t* wstr, long cp = CP_ACP);

#endif

template<class T>
class Buffer
{
public:
	Buffer(size_t n)
		: buf(n+1,0)
	{
		buf[n]=0;
	}

	Buffer(size_t n, int value)
		: buf(n+1,0)
	{
		::memset(&buf[0],value,(n)*sizeof(T));
		buf[n]=0;
	}

	Buffer(const Buffer& rhs)
		: buf(rhs)
	{}

	Buffer& operator=(const Buffer& rhs)
	{
		if ( &rhs == this )
			return *this;
		buf = rhs;
		return *this;
	}

	operator T* ()
	{
		return &buf[0];
	}

	size_t size()
	{
		return buf.size()-1;
	}

	std::basic_string<T> toString(size_t len = std::basic_string<T>::npos)
	{
		if ( len != std::basic_string<T>::npos)
		{
			return std::basic_string<T>(&buf[0],len);
		}
		return std::basic_string<T>(&buf[0]);
	}

private:
	std::vector<T> buf;
};

typedef mol::Buffer<char> cbuff;
typedef mol::Buffer<wchar_t> wbuff;



} // end namespace mol

#endif


