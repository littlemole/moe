
#include "util/istr.h"

namespace mol {
namespace str {

std::string toupper(std::string in )
{
	for ( unsigned int i = 0; i < in.size(); i++ )
	{
		in[i] = ::toupper(in[i]);
	}
	return in;
}

std::string tolower(std::string in )
{
	for ( unsigned int i = 0; i < in.size(); i++ )
	{
		in[i] = ::tolower(in[i]);
	}
	return in;
}



std::wstring toupper(std::wstring in )
{
	for ( unsigned int i = 0; i < in.size(); i++ )
	{
		in[i] = towupper(in[i]);
	}
	return in;
}

std::wstring tolower(std::wstring in )
{
	for ( unsigned int i = 0; i < in.size(); i++ )
	{
		in[i] = towlower(in[i]);
	}
	return in;
}

}
} //end namespace mol
