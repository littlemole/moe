
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



std::string wstring2ansi(const std::wstring& in, long cp)
{
    int len = ::WideCharToMultiByte(cp,0,in.c_str(),(int)in.size(),0,0,0,0);
	mol::cbuff buf(len);
    int n = ::WideCharToMultiByte(cp,0,in.c_str(),(int)in.size(),buf,len,0,0);
    return buf.toString(len);
}

std::wstring ansi2wstring( const std::string& in, long cp )
{
	int len = ::MultiByteToWideChar( cp, 0, in.c_str(), (int)in.size(), 0, 0 );
	mol::wbuff buf(len);
	::MultiByteToWideChar( cp, 0, in.c_str(), (int)in.size(), buf, len );
	return buf.toString(len);
}

std::string wstring2utf8( const std::wstring& in, long cp )
{
	int len = ::WideCharToMultiByte( CP_UTF8, 0, in.c_str(), (int)in.size(), 0, 0,0,0 );
	mol::cbuff buf(len);
	int r = ::WideCharToMultiByte( CP_UTF8, 0, in.c_str(),(int)in.size(), buf, len,0,0 );
	return buf.toString(len);
}

std::string ansi2utf8( const std::string& in, long cp )
{
	std::wstring ws = ansi2wstring(in,cp);
	return wstring2utf8(ws,cp);
}

std::wstring utf82wstring( const std::string& in, long cp )
{
	int len = ::MultiByteToWideChar( CP_UTF8, 0, in.c_str(), (int)in.size(), 0, 0 );
	mol::wbuff buf(len);
	int r = ::MultiByteToWideChar( CP_UTF8, 0, in.c_str(), (int)in.size(), buf, len );
	return buf.toString(len);
}

std::string utf82ansi( const std::string& in, long cp )
{
	std::wstring ws = utf82wstring(in,cp);
	return wstring2ansi(ws,cp);
}


std::string toUTF8( const std::string& in, long cp)
{
	std::wstring ws = ansi2wstring(in,cp);
	return wstring2utf8(ws,cp);
}

std::string toUTF8( const std::wstring& str, long cp)
{
	return wstring2utf8(str,cp);
}

std::wstring fromUTF8(const std::string& in, long cp)
{
	int len = ::MultiByteToWideChar( CP_UTF8, 0, in.c_str(), (int)in.size(), 0, 0 );
	mol::wbuff buf(len);
	int r = ::MultiByteToWideChar( CP_UTF8, 0, in.c_str(), (int)in.size(), buf, len );
	return buf.toString(len);
}


std::string  tostring( const std::string& str, long cp)
{
	return str;
}

std::string  tostring( const std::wstring& str, long cp)
{
	return mol::wstring2ansi( str,cp );
}

std::string  tostring( const char* str, long cp)
{
	if (!str)
		return "";
	return std::string( str );
}

std::string  tostring( const wchar_t* wstr, long cp)
{
	if (!wstr)
		return "";
	return mol::wstring2ansi( std::wstring(wstr), cp );
}


std::wstring  towstring( const std::string& str, long cp)
{
	return mol::ansi2wstring( str,cp );
}

std::wstring  towstring( const std::wstring& str, long cp)
{
	return str;
}

std::wstring  towstring( const char* str, long cp)
{
	if (!str)
		return L"";
	return mol::ansi2wstring( std::string(str),cp );
}

std::wstring  towstring( const wchar_t* wstr, long cp)
{
	if (!wstr)
		return L"";
	return std::wstring( wstr );
}


mol::string  toString( const std::string& str, long cp)
{
#ifdef _UNICODE
	return mol::towstring(str,cp);
#else
	return str;
#endif
}

mol::string  toString( const std::wstring& str, long cp)
{
#ifdef _UNICODE
	return str;
#else
	return mol::tostring(str,cp);
#endif
}

mol::string  toString( const char* str, long cp)
{
	if (!str)
		return _T("");
#ifdef _UNICODE
	return mol::towstring(std::string(str),cp);
#else
	return std::string(str);
#endif
}

mol::string  toString( const wchar_t* wstr, long cp)
{
	if (!wstr)
		return _T("");
#ifdef _UNICODE
	return std::wstring(wstr);
#else
	return mol::tostring(std::wstring(wstr),cp);
#endif
}


#endif

} //end namespace mol
