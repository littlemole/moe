#ifndef _ISTR_HELP_DEF_
#define _ISTR_HELP_DEF_

#include "conf.h"
#include "uni.h"
#include <algorithm>

////////////////////////////////////////////////////////////////////////
// TODO:  move impl to ns
////////////////////////////////////////////////////////////////////////


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

// inline string to lower/upper case routines. modifies strings inplace

/*
class UpperCase 
{ 
public: 
   int operator()(int ch) { return toupper(ch);} 
}; 

class LowerCase 
{ 
public: 
    int operator()(int ch) { return tolower(ch);} 
}; 


class UpperCaseW 
{ 
public: 
   int operator()(int ch) { return towupper(ch);} 
}; 

class LowerCaseW 
{ 
public: 
    int operator()(int ch) { return towlower(ch);} 
}; 

} // end namespace str

inline void lowerString(std::string& str )
{
	std::transform( str.begin(), str.end(), str.begin(), ::mol::str::LowerCase() );
}

inline void upperString(std::string& str )
{
	std::transform( str.begin(), str.end(), str.begin(), ::mol::str::UpperCase() );
}


inline void lowerString(std::wstring& str )
{
	std::transform( str.begin(), str.end(), str.begin(), ::mol::str::LowerCaseW() );
}

inline void upperString(std::wstring& str )
{
	std::transform( str.begin(), str.end(), str.begin(), ::mol::str::UpperCaseW() );
}

*/

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


