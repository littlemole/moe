#ifndef _DEF_HTTP_HEADERS_DEFINE_GUARD_DEF_
#define _DEF_HTTP_HEADERS_DEFINE_GUARD_DEF_

#include "tcp/sockets.h"
#include "util/str.h"
#include <list>
#include <sstream>

//! for Non-Win32 Systems, assume POSIX
#ifndef WIN32
#endif

//! Win32 Systems
#ifdef WIN32
#define strcasecmp _stricmp
#endif

namespace mol {

/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////

typedef std::pair<std::string,std::string>  HttpHeader;
typedef std::list<HttpHeader>               HttpHeaderList;
typedef HttpHeaderList::iterator            HttpHiterator;

/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////

class HttpEx : public mol::X
{
public:
	HttpEx() {}
	HttpEx(const char* const& what)
		: mol::X(what)
	{}
};

/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////

class HttpHeaders
{
public:

	HttpHeaders();
	HttpHeaders( const std::string& cmd, const std::string& path);
	HttpHeaders( const std::string& cmd, const std::string& path, const std::string& proto);

    const std::string getAction();
    void  setAction( const std::string& str);
	void  setResponse( const std::string& str);
	std::string getResponse();
    std::string getHeaders();

    std::string getHeader( const std::string& str );
    void add( const HttpHeader& h );
	void add( const std::string& key, const std::string& val );
	void set( const std::string& key, const std::string& val );
    void del( HttpHiterator hit);
    bool del( const std::string& str);
    bool del( const std::string& str, const std::string& val );

    HttpHiterator iterator( const std::string& str );
    HttpHiterator begin();
    HttpHiterator end();

    bool contentLengthIsKnown();
    int  contentLength();
	void contentLength( int len );
    std::string contentType();
	void contentType(const std::string& c);
    std::string connection();
    bool wantShutDown();
	bool keepAlive();

	std::string Headers();
    std::string RequestHeaders();
	std::string ResponseHeaders();

    const std::string getCmd();
    const std::string getPath();
    const std::string getProto();

    void setCmd  ( const std::string& str );
    void setPath ( const std::string& str );
    void setProto( const std::string& str );

    bool  isConnect();

    const std::string getCode();
    const std::string getStatus();

    void setCode(  const std::string& str );
    void setStatus(const std::string& str );

protected:

    HttpHeaderList             list_;

    std::string                cmd_;
    std::string                path_;
    std::string                proto_;

    std::string                code_;
    std::string                status_;

    bool                       isconnect_;
};

/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////

template<class charT, class Traits>
std::string 
get_line_paranoid( std::basic_istream<charT,Traits>& is, const char delim = '\n' )
{
	std::ostringstream oss;

	typename std::basic_istream<charT,Traits>::char_type c = 0;

	while ( is )
	{
		c = is.get();
		if ( std::basic_istream<charT,Traits>::traits_type::eq_int_type( c, std::basic_istream<charT,Traits>::traits_type::eof() ) )
			break;
		oss << c;
		if ( c == delim )
			break;
	}
	return oss.str();
}

} // end namespace mol

/////////////////////////////////////////////////////////////////////////
// write  HttpHeaders to stream;
/////////////////////////////////////////////////////////////////////////

template<class charT, class Traits>
std::basic_ostream<charT,Traits>&
operator<< ( std::basic_ostream<charT,Traits>& os, mol::HttpHeaders& http)
{
	os << http.Headers() << "\r\n";// std::endl;
	return os;
}

/////////////////////////////////////////////////////////////////////////
// read HttpHeaders from stream
/////////////////////////////////////////////////////////////////////////

template<class charT, class Traits>
std::basic_istream<charT,Traits>&
operator>> ( std::basic_istream<charT,Traits>& is, mol::HttpHeaders& http)
{
	http = mol::HttpHeaders();

	// get Http Request command or Http responde command
	std::string line = mol::get_line_paranoid(is);
	//std::getline(is,line);

	if ( line == "" )
		throw mol::HttpEx("HTTP ex: failed to get http command line");

	line = mol::trim(line);
	if ( ( line.size() > 3 ) && ( line.substr(0,4) != "HTTP" ) )
		http.setAction(line);
	else
		http.setResponse(line);

	// get headers
	while ( is )
	{
		line = mol::get_line_paranoid(is);
		//std::getline(is,line);
		line = mol::trim (line);
		if ( line == "" )
			break;

		size_t pos = line.find(":");
		if ( pos == std::string::npos )
		{
			http.add( std::make_pair( line, "") );
		}
		else
		{
			http.add( std::make_pair( mol::trim(line.substr(0,pos)), mol::trim(line.substr(pos+1) )) );
		}
	}
	return is;
}

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////


#endif

