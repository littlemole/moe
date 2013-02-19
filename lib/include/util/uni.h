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
// UNICODE support
//////////////////////////////////////////////////////////////////////



#ifdef _UNICODE

typedef wchar_t TCHAR; 
extern std::wostream&  cout;
extern std::wistream&  cin;
extern std::wostream&  cerr;

#ifndef WIN32
#define _T(x) L##x
#endif

#else

typedef char TCHAR; 
extern std::ostream&  cout;
extern std::istream&  cin;
extern std::ostream&  cerr;

#ifndef WIN32
#define _T(x) x
#endif

#endif

//////////////////////////////////////////////////////////////////////
// UNICODE support
//////////////////////////////////////////////////////////////////////

typedef std::basic_string< TCHAR, 
						   std::char_traits<TCHAR>, 
						   std::allocator<TCHAR> >
	string;

typedef std::basic_ios<TCHAR, std::char_traits<TCHAR> > 
	ios;

typedef std::basic_streambuf<TCHAR, std::char_traits<TCHAR> > 
	streambuf;

typedef std::basic_istream<TCHAR, std::char_traits<TCHAR> > 
	istream;

typedef std::basic_ostream<TCHAR, std::char_traits<TCHAR> > 
	ostream;

typedef std::basic_iostream<TCHAR, std::char_traits<TCHAR> > 
	iostream;

typedef std::basic_stringbuf<TCHAR, std::char_traits<TCHAR>, std::allocator<TCHAR> > 
	stringbuf;

typedef std::basic_istringstream<TCHAR, std::char_traits<TCHAR>, std::allocator<TCHAR> > 
	istringstream;

typedef std::basic_ostringstream<TCHAR, std::char_traits<TCHAR>, std::allocator<TCHAR> > 
	ostringstream;

typedef std::basic_stringstream<TCHAR, std::char_traits<TCHAR>,	std::allocator<TCHAR> > 
	stringstream;

typedef std::basic_filebuf<TCHAR, std::char_traits<TCHAR> > 
	filebuf;

typedef std::basic_ifstream<TCHAR, std::char_traits<TCHAR> > 
	ifstream;

typedef std::basic_ofstream<TCHAR, std::char_traits<TCHAR> > 
	ofstream;

typedef std::basic_fstream<TCHAR, std::char_traits<TCHAR> > 
	fstream;

//////////////////////////////////////////////////////////////////////
// win32 conversions support (use ICV on non Win32 platforms)
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

mol::string  toString( const std::string& str, long cp = CP_ACP);
mol::string  toString( const std::wstring& str, long cp = CP_ACP);
mol::string  toString( const char* str, long cp = CP_ACP);
mol::string  toString( const wchar_t* wstr, long cp = CP_ACP);

#endif

template<class T>
class Buffer
{
public:
	Buffer(size_t n)
		: buf(n,0)
	{}

	Buffer(size_t n, int value)
		: buf(n,0)
	{
		::memset(&buf[0],value,n*sizeof(T));
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

/*	T* operator[](size_t i)
	{
		return &buf[i];
	}
*/
	size_t size()
	{
		return buf.size();
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
typedef mol::Buffer<mol::TCHAR> tbuff;



} // end namespace mol

#endif


