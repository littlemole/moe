
#include "util/istr.h"

namespace mol {
namespace str {
std::string string2upper(std::string in )
{
	for ( unsigned int i = 0; i < in.size(); i++ )
	{
		in[i] = toupper(in[i]);
	}
	return in;
}

std::string string2lower(std::string in )
{
	for ( unsigned int i = 0; i < in.size(); i++ )
	{
		in[i] = tolower(in[i]);
	}
	return in;
}



std::wstring string2upper(std::wstring in )
{
	for ( unsigned int i = 0; i < in.size(); i++ )
	{
		in[i] = towupper(in[i]);
	}
	return in;
}

std::wstring string2lower(std::wstring in )
{
	for ( unsigned int i = 0; i < in.size(); i++ )
	{
		in[i] = towlower(in[i]);
	}
	return in;
}

}
} //end namespace mol
