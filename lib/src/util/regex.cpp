#include "util/regex.h"
#include <cstdio>
#include <cstring>

namespace mol {

////////////////////////////////////////////////////////////////////////
// TODO: remvove tmp arg. class needs copy policy. move impl to ns
////////////////////////////////////////////////////////////////////////

PCRE::PCRE(int nSubstrings)
:   matchCount_(0),
	errorOffset_(0),
	error_(0),
	compiledPattern_(0),
	options_(0),
	nSubstrings_(nSubstrings)
{
	ovec_ = new int[nSubstrings_];
	lastMatch_ = std::pair<int,int>(0,0);
}

PCRE::PCRE( const std::string& pattern,int nSubstrings)
:	matchCount_(0),   
	errorOffset_(0),
	error_(0),
	compiledPattern_(0),
	options_(0),
	nSubstrings_(nSubstrings)
{
	ovec_ = new int[nSubstrings_];
	lastMatch_ = std::pair<int,int>(0,0);
	setPattern(pattern);
}

PCRE::PCRE( const std::string& pattern, int options,int nSubstrings)
:	matchCount_(0),   
	errorOffset_(0),
	error_(0),
	compiledPattern_(0),
	options_(options),
	nSubstrings_(nSubstrings)
{
	ovec_ = new int[nSubstrings_];
	lastMatch_ = std::pair<int,int>(0,0);
	setPattern(pattern);
}

PCRE::~PCRE()
{
	if ( compiledPattern_ )
		pcre_free(compiledPattern_);

	delete[] ovec_;
}

bool PCRE::setPattern(const std::string& pattern)
{
	pcre* e = pcre_compile(
	pattern.c_str(),			/* the pattern */
	options_,					/* default options */
	&error_,					/* for error message */
	&errorOffset_,				/* for error offset */
	NULL);						/* use default character tables */

	if ( e > 0 )
	{
		compiledPattern_ = e;
		return true;
	}
	else
	{
		if ( compiledPattern_ )
			pcre_free(compiledPattern_);
		compiledPattern_ = 0;
		return false;
	}
}

int PCRE::exec(const std::string& source, int offset, int options)
{
	if (compiledPattern_ == 0 )
		return 0;

	if ( options )
		options_ = options;

	matchCount_ = pcre_exec(
		compiledPattern_,			/* result of pcre_compile() */
		NULL,						/* we didn't study the pattern */
		source.c_str(),				/* the subject string */
		(int)strlen(source.c_str()),		/* the length of the subject string */
		offset,						/* start at offset 0 in the subject */
		0,							/* default options */
		ovec_,						/* vector for substring information */
		nSubstrings_);				/* number of elements in the vector */

	if ( matchCount_ > 0 )
	{
		lastMatch_ = std::pair<int,int>(ovec_[0],ovec_[1]);
	}
	else
	{
		lastMatch_  = std::pair<int,int>(0,0);
		matchCount_ = 0;
	}

	return matchCount_;
}

int PCRE::repeat(const std::string& s)
{
	if ( compiledPattern_ == 0 || s == "" )
		return 0;

	return exec( s, lastMatch_.second, options_  );
}

std::pair<int,int>& PCRE::lastMatchPos() 
{ 
	return lastMatch_; 
}

const std::string PCRE::getSubString(  const std::string& s, int n )
{
	return std::string( s.c_str()+ovec_[n*2],s.c_str()+ovec_[n*2+1] );
}

const std::string	PCRE::getError()
{
	return error_;
}

int PCRE::getErrorOffset()
{
	return errorOffset_;
}




} // end namespace mol

