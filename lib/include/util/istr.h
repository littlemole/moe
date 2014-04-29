#ifndef _ISTR_HELP_DEF_
#define _ISTR_HELP_DEF_

#include "conf.h"
#include "uni.h"
#include <algorithm>


namespace mol {
namespace str {


//////////////////////////////////////////////////////////////////////
// string helpers
//////////////////////////////////////////////////////////////////////

// string to lower/upper case routines. returns new strings
std::string toupper(std::string in );
std::string tolower(std::string in );

std::wstring toupper(std::wstring in );
std::wstring tolower(std::wstring in );


} // end namespace str


inline int icmp( const std::string& a, const std::string& b )
{
	return mol::stricmp( a.c_str(), b.c_str() );
}

inline int icmp( const std::wstring& a, const std::wstring& b )
{
	return mol::wcstricmp( a.c_str(), b.c_str() );
}


} // end namespace mol

#endif


