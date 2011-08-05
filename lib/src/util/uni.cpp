
#include "util/uni.h"

namespace mol {

#ifdef _UNICODE

std::wostream&  cout = std::wcout;
std::wistream&  cin  = std::wcin;
std::wostream&  cerr = std::wcerr;
#else
std::ostream&  cout  = std::cout;
std::istream&  cin   = std::cin;
std::ostream&  cerr  = std::cerr;
#endif


#ifdef _WIN32



std::string wstring2ansi(const std::wstring& in)
{
    int len = ::WideCharToMultiByte(CP_ACP,0,in.c_str(),(int)in.size(),0,0,0,0);
    char* buf = new char[len];
    int n = ::WideCharToMultiByte(CP_ACP,0,in.c_str(),(int)in.size(),buf,len,0,0);
    std::string ret(buf,len);
    delete[] buf;
    return ret;
}

std::wstring ansi2wstring( const std::string& in )
{
	int len = ::MultiByteToWideChar( CP_ACP, 0, in.c_str(), (int)in.size(), 0, 0 );
	wchar_t* buf = new wchar_t[len];
	::MultiByteToWideChar( CP_ACP, 0, in.c_str(), (int)in.size(), buf, len );
	std::wstring out(buf,len);
	delete[] buf;
	return out;
}

std::string wstring2utf8( const std::wstring& in )
{
	int len = ::WideCharToMultiByte( CP_UTF8, 0, in.c_str(), (int)in.size(), 0, 0,0,0 );
	char* buf = new char[len];
	int r = ::WideCharToMultiByte( CP_UTF8, 0, in.c_str(),(int)in.size(), buf, len,0,0 );
	std::string out(buf,len);
	delete[] buf;
	return out;
}

std::string ansi2utf8( const std::string& in )
{
	std::wstring ws = ansi2wstring(in);
	return wstring2utf8(ws);
}

std::wstring utf82wstring( const std::string& in )
{
	int len = ::MultiByteToWideChar( CP_UTF8, 0, in.c_str(), (int)in.size(), 0, 0 );
	wchar_t* buf = new wchar_t[len];
	int r = ::MultiByteToWideChar( CP_UTF8, 0, in.c_str(), (int)in.size(), buf, len );
	std::wstring out(buf,len);
	delete[] buf;
	return out;
}

std::string utf82ansi( const std::string& in )
{
	std::wstring ws = utf82wstring(in);
	return wstring2ansi(ws);
}

#endif

std::string toUTF8( const std::string& in)
{
	std::wstring ws = ansi2wstring(in);
	return wstring2utf8(ws);
}

std::string toUTF8( const std::wstring& str)
{
	return wstring2utf8(str);
}

std::wstring fromUTF8(const std::string& in)
{
	int len = ::MultiByteToWideChar( CP_UTF8, 0, in.c_str(), (int)in.size(), 0, 0 );
	wchar_t* buf = new wchar_t[len];
	int r = ::MultiByteToWideChar( CP_UTF8, 0, in.c_str(), (int)in.size(), buf, len );
	std::wstring out(buf,len);
	delete[] buf;
	return out;
}


std::string  tostring( const std::string& str)
{
	return str;
}

std::string  tostring( const std::wstring& str)
{
	return mol::wstring2ansi( str );
}

std::string  tostring( const char* str)
{
	if (!str)
		return "";
	return std::string( str );
}

std::string  tostring( const wchar_t* wstr)
{
	if (!wstr)
		return "";
	return mol::wstring2ansi( std::wstring(wstr) );
}


std::wstring  towstring( const std::string& str)
{
	return mol::ansi2wstring( str );
}

std::wstring  towstring( const std::wstring& str)
{
	return str;
}

std::wstring  towstring( const char* str)
{
	if (!str)
		return L"";
	return mol::ansi2wstring( std::string(str) );
}

std::wstring  towstring( const wchar_t* wstr)
{
	if (!wstr)
		return L"";
	return std::wstring( wstr );
}


mol::string  toString( const std::string& str)
{
#ifdef _UNICODE
	return mol::towstring(str);
#else
	return str;
#endif
}

mol::string  toString( const std::wstring& str)
{
#ifdef _UNICODE
	return str;
#else
	return mol::tostring(str);
#endif
}

mol::string  toString( const char* str)
{
	if (!str)
		return _T("");
#ifdef _UNICODE
	return mol::towstring(std::string(str));
#else
	return std::string(str);
#endif
}

mol::string  toString( const wchar_t* wstr)
{
	if (!wstr)
		return _T("");
#ifdef _UNICODE
	return std::wstring(wstr);
#else
	return mol::tostring(std::wstring(wstr));
#endif
}


} //end namespace mol
