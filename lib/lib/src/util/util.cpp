
#include "util/util.h"

namespace mol {

std::vector<std::string> split( const std::string& what, const std::string& delim )
{
	std::vector<std::string> ret;
	
	size_t p   = 0;
	size_t pos = 0;

	while ( (pos = what.find( delim, p )) != std::string::npos )
	{
		ret.push_back( what.substr( p, pos-p ) );
		p = pos + delim.length();
	}
	if ( p < what.size()-1 )
	{
		ret.push_back( what.substr( p ) );
	}

	return ret;
}

}


