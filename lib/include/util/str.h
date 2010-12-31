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

mol::string tab2space(const mol::string& str );
mol::string skip2spaces(const mol::string& str );
mol::string skipNewLines(const mol::string& str);

mol::string nl2br(const mol::string& str);

void htmlWrap(mol::string& str, int wrap );

std::string URLencode( const std::string& in);
std::string URLdecode( const std::string& in );

std::string base64_encode(unsigned char const* , unsigned int len);
std::string base64_decode(mol::string const& s);


} // end namespace mol

#endif


