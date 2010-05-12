#ifndef MOL_DEF_GUARD_PCRE_DEFINE_
#define MOL_DEF_GUARD_PCRE_DEFINE_

#include <pcre.h>
#include <utility>
#include <string>

namespace mol {

////////////////////////////////////////////////////////////////////////
// PCRE base impl
////////////////////////////////////////////////////////////////////////

class PCRE
{
public:
	PCRE(int nSubstrings);
	PCRE(const std::string& pattern, int nSubstrings);
	PCRE(const std::string& pattern, int options, int nSubstrings );
	~PCRE();

	bool setPattern(const std::string& pattern);
	int  exec(const std::string& source, int offset=0, int options=0);
	int  repeat( const std::string& s);

	const std::string getSubString( const std::string& s, int n );
	std::pair<int,int>& lastMatchPos();
	const std::string	getError();
	int getErrorOffset();

protected:	

	int						matchCount_;
	std::pair<int,int>		lastMatch_;
	int						errorOffset_;
	const char*				error_;	
	pcre*					compiledPattern_;
	int						options_;
	int						nSubstrings_;
	int*					ovec_;

private:
	PCRE(const PCRE&);
	PCRE& operator=(const PCRE&);
};

////////////////////////////////////////////////////////////////////////
// RegExp impl
////////////////////////////////////////////////////////////////////////


class RegExp : private PCRE
{
public:

	RegExp( const std::string& p, int nSubStrings = 10 ): PCRE(p,(nSubStrings+1)*3) {};
	RegExp( int o, const std::string& p, int nSubStrings = 10) : PCRE(p,o,(nSubStrings+1)*3) {};

	int match( const std::string& s )
	{
		return exec( s, 0, 0 );
	}

	int nextMatch( const std::string& s )
	{
		return exec( s, matchPos().second, 0 );
	}

	std::string replace( const std::string& s, const std::string& with )
	{
		if ( exec( s, 0, 0 ) )
		{
			std::string ret = s.substr(0,matchPos().first) + with;
			if ( matchPos().second < (int)s.size() )
				ret += s.substr(matchPos().second);
			return ret;
		}
		return s;
	}

	std::string nextReplace( const std::string& s, const std::string& with )
	{
		if ( exec( s, matchPos().second, 0 ) )
		{
			std::string ret = s.substr(0,matchPos().first) + with;
			if ( matchPos().second < (int)s.size() )
				ret += s.substr(matchPos().second);
			return ret;
		}
		return s;
	}

	std::string replaceAll( const std::string& s, const std::string& with )
	{
		std::string ret = s;
		reset();
		while ( exec( ret, matchPos().second, 0 ) )
		{
			std::string tmp = ret.substr(0,matchPos().first) + with;
			if ( matchPos().second < (int)ret.size() )
				tmp += ret.substr(matchPos().second);
			ret = tmp;
		}
		return ret;
	}

	bool operator== ( const std::string& s )
	{
		return match(s) != 0;
	}

	bool operator^= ( const std::string& s )
	{
		return nextMatch(s) != 0;
	}

	int imatch( const std::string& s )
	{
		return exec( s, 0, PCRE_CASELESS );
	}

	int nextImatch( const std::string& s )
	{
		return exec( s, matchPos().second, PCRE_CASELESS );
	}

	const std::string subString( const std::string& s, int n = 0 )
	{
		return getSubString( s, n );
	}

	const std::string operator() ( const std::string& s, int n = 0 )
	{
		return getSubString( s, n );
	}

	const std::pair<int,int>& matchPos()
	{
		return lastMatchPos();
	}

	const std::string error()
	{
		return getError();
	}

	int errorPos()
	{
		return getErrorOffset();
	}

	void reset()
	{
		lastMatchPos() = std::make_pair(0,0);
	}
};





} // end namespace mol

#endif
