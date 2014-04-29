#ifndef _STR_HELP_DEF_
#define _STR_HELP_DEF_

#include "util/uni.h"
#include <string>

namespace mol {


//////////////////////////////////////////////////////////////////////
// string helpers
//////////////////////////////////////////////////////////////////////

std::string unix2dos(const std::string& s);
std::string dos2unix(const std::string& s);

std::wstring unix2dos(const std::wstring& s);
std::wstring dos2unix(const std::wstring& s);

std::string  trim(const std::string& s );
std::wstring trim(const std::wstring& s );

std::string  xmlentities_encode(const std::string& str );
std::wstring xmlentities_encode(const std::wstring& str );
std::string  xmlentities_decode(const std::string& str );
std::wstring xmlentities_decode(const std::wstring& str );
std::string str2rtf(const std::string& str );
std::string nl2rtf( const std::string& in );
std::wstring str2rtf(const std::wstring& str );
std::wstring nl2rtf( const std::wstring& in );

std::wstring tab2space(const std::wstring& str);
std::wstring skip2spaces(const std::wstring& str);
std::wstring skipNewLines(const std::wstring& str);

std::wstring nl2br(const std::wstring& str);

void htmlWrap(std::wstring& str, int wrap);

std::string URLencode( const std::string& in);
std::string URLdecode( const std::string& in );

std::string base64_encode(unsigned char const* , unsigned int len);
std::string base64_decode(std::string const& s);

COLORREF hex2rgb( const std::string& hex );
std::string rgb2hex( COLORREF col );

} // end namespace mol

#endif


