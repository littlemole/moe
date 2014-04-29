#ifndef _XCEPTION_MOL_DEF_
#define _XCEPTION_MOL_DEF_

#include "util/str.h"

#ifdef _WIN32
#ifdef _DEBUG

#include "Str.h"

inline void ODBGS(const std::string& s)
{
	::OutputDebugStringA("\r\n"); 
	::OutputDebugStringA(s.c_str());
}

inline void ODBGS(const std::wstring& s)
{
	::OutputDebugStringW(L"\r\n"); 
	::OutputDebugStringW(s.c_str());
}

inline void ODBGS1(const std::string& s, int i)
{
	::OutputDebugStringA("\r\n"); 
	char* buf[256]; 
	wsprintfA( (LPSTR)buf,"%s %i",s.c_str(),i); 
	::OutputDebugStringA((LPCSTR)buf);
}

inline void ODBGS1(const std::wstring& s, int i)
{
	::OutputDebugStringW(L"\r\n"); 
	wchar_t* buf[256]; 
	wsprintfW( (LPWSTR)buf,L"%s %i",s.c_str(),i); 
	::OutputDebugStringW((LPCWSTR)buf);
}


void _cry();
#define cry() _cry()

#else

#define ODBGS(f) {};
#define ODBGS1(f,i) {};

#define cry() void(0)

#endif
#else

#ifdef _DEBUG
#define ODBGS(f) { fprintf( stderr, "%s\r\n", f); };
#define ODBGS1(f,i) { fprintf( stderr, "%s\r\n", f); };
#else

#define ODBGS(f) {};
#define ODBGS1(f,i) {};

#endif
#endif

namespace mol {

#ifdef _WIN32
std::wstring WinErrorString(unsigned long err = 0);
#endif

// general exception class
class X 
{
public :
	X() {}
	X(const char* const& what)
		//: std::exception(what)
		:what_(what)
	{}

	X(const wchar_t* const& what)
		//: std::exception(what)
		:what_("")
	{}

    virtual const char* what() const throw()
	{
		return what_.c_str();
	}
private:
	std::string what_;
//	const char* what_;
};


} // end namespace mol


#endif

