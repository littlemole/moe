
#ifndef _MOL_DEF_GUARD_GZIP_GUNZIP_DEF_GUARD_DEFINE_
#define _MOL_DEF_GUARD_GZIP_GUNZIP_DEF_GUARD_DEFINE_

#include <string>

namespace mol {

//////////////////////////////////////////////////////////////////////////////////
// deflate
//////////////////////////////////////////////////////////////////////////////////

std::string deflate( 
	const::std::string& src, 
	const int level = -1 /*Z_DEFAULT_COMPRESSION*/
);


std::string deflate( 
	std::istream& src, 
	const int level = -1 /*Z_DEFAULT_COMPRESSION*/
);


std::string inflate( const::std::string& src, int bits = -15); //MAX_WBITS);
std::string inflate( std::istream& src, int bits = -15); //MAX_WBITS);


//////////////////////////////////////////////////////////////////////////////////
// GZIP
//////////////////////////////////////////////////////////////////////////////////

std::string gzip(
	const std::string& src, 
	const int nLevel = -1 /*Z_DEFAULT_COMPRESSION*/, 
	const int nStrategy = 0 /*Z_DEFAULT_STRATEGY*/ 
);


std::string gzip(
	std::istream& src,  
	const int nLevel = -1 /*Z_DEFAULT_COMPRESSION*/, 
	const int nStrategy = 0 /*Z_DEFAULT_STRATEGY*/ 
);

std::string gunzip(const std::string& src);
std::string gunzip(std::istream& src);

}

#endif 




