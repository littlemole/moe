#ifndef HTTP_REQUEST_DEF_GUARD_DEF
#define HTTP_REQUEST_DEF_GUARD_DEF

#include "http/reader.h"

namespace mol {

/////////////////////////////////////////////////////////////////////////
// HTTP Body
/////////////////////////////////////////////////////////////////////////

class HttpBody
{
public:

	HttpBody();	
	HttpBody(AbstractBodyReader* r);
	HttpBody(const std::string& b);
	//HttpBody(HttpHeaders& headers);

	~HttpBody();

	const std::string& body();
	void body( const std::string& b );

	const std::string& raw_body();

	void addParam  ( const std::string& key, const std::string& val );
	std::string getParam(const std::string& key);
	std::vector<std::string> getParams(const std::string& key);

	HttpBody& operator=(const HttpBody& rhs )
	{
		if ( &rhs == this )
			return *this;

		if ( reader_ )
			delete reader_;
		reader_ = rhs.reader_;
		((HttpBody&)rhs).reader_ = 0;
		body_ = rhs.body_;
		queryParams_ = rhs.queryParams_;
		return *this;
	}

protected:


	AbstractBodyReader* reader_;
	std::string body_;

    typedef std::pair<std::string,std::string> KeyVal;
	std::vector<KeyVal> queryParams_;
};

/////////////////////////////////////////////////////////////////////////
// generic HTTP request
/////////////////////////////////////////////////////////////////////////

class HttpRequest
{
public:

	Uri uri;
	HttpHeaders headers;
	HttpBody body;
};

/////////////////////////////////////////////////////////////////////////
// generic HTTP response
/////////////////////////////////////////////////////////////////////////

class HttpResponse
{
public:

	HttpResponse();
	HttpResponse(const std::string& b);
	HttpResponse(const std::string& b, const std::string& content_type);
	~HttpResponse();

	HttpHeaders headers;
	HttpBody body;

	AbstractBodyReader* reader();
};


/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

} // end namespace mol

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////
// Serializiation
/////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////
// write HttpRequest to stream
/////////////////////////////////////////////////////////////////////////

template<class charT, class Traits>
std::basic_ostream<charT,Traits>&
operator<< ( std::basic_ostream<charT,Traits>& os, mol::HttpRequest& request)
{
	// write headers
	os << request.headers;

	// write body if any
	if ( request.headers.contentLengthIsKnown() )
	{
		os << request.body;
	}

	// flush the stream
	os.flush();
	return os;
}


/////////////////////////////////////////////////////////////////////////
// write http body to stream
/////////////////////////////////////////////////////////////////////////

template<class charT, class Traits>
std::basic_ostream<charT,Traits>&
operator<< ( std::basic_ostream<charT,Traits>& os, mol::HttpBody& body)
{
	os << body.body();
	return os;
}

/////////////////////////////////////////////////////////////////////////
// read http body from stream
/////////////////////////////////////////////////////////////////////////
/*
template<class charT, class Traits>
std::basic_istream<charT,Traits>&
operator>> ( std::basic_istream<charT,Traits>& is, mol::HttpBody& body)
{
	// if chunked ?
	if ( body.chunked_ )
	{
		// read chunked !
	}

	//TODO: remove redundancy

	// if content length is known, read exact content-len bytes
	if ( body.contentLengthIsKnown() )
	{
		int len = body.contentLength();
		char* buf = new char[len+1];
		is.read(buf,len);
		body.body( std::string(buf, (unsigned int)(is.gcount())) );
		delete[] buf;
		return is;
	}

	// read until eof otherwise
	std::ostringstream oss;
	char buf[1024];
	while ( is )
	{
		is.read(buf,1023);
		if ( is.gcount() == 0 )
			break;
		oss.write(buf,is.gcount());
	}	
	body.body(oss.str());
	return is;
}

*/
/////////////////////////////////////////////////////////////////////////
// get Http Request from stream
/////////////////////////////////////////////////////////////////////////

template<class charT, class Traits>
std::basic_istream<charT,Traits>&
operator>> ( std::basic_istream<charT,Traits>& is, mol::HttpRequest& request)
{
	// get Http Headers
	is >> request.headers;

	// reconstruct request uri
	request.uri = mol::Uri(request.headers.getPath());
	if ( request.headers.getHeader("host")!="" )
	{
		request.uri.setHost(request.headers.getHeader("host"));
	}

	// get body if content length known only
	if ( request.headers.contentLengthIsKnown() )
	{
		//request.body.contentLength(request.headers.contentLength());
		mol::ContentLengthBodyReader reader(request.headers.contentLength());
		size_t s = reader.read(is);

		if ( s )
		{
			request.body.body(reader.toString());
		}

		//is >> request.body;
	}
	return is;
}

/////////////////////////////////////////////////////////////////////////
// get Http Response from stream
/////////////////////////////////////////////////////////////////////////

template<class charT, class Traits>
std::basic_istream<charT,Traits>&
operator>> ( std::basic_istream<charT,Traits>& is, mol::HttpResponse& response)
{
	// get response headers
	is >> response.headers;

	// get body if any


	mol::AbstractBodyReader* reader = response.reader();

	size_t s = reader->read(is);
	
	if ( response.headers.getCode() == "304"  )
	{
		delete reader;
		return is;
	}

	if ( s )
	{
		response.body = mol::HttpBody(reader);
	}

	//delete reader;
	return is;
}

/////////////////////////////////////////////////////////////////////////
// write Http Response to stream
/////////////////////////////////////////////////////////////////////////

template<class charT, class Traits>
std::basic_ostream<charT,Traits>&
operator<< ( std::basic_ostream<charT,Traits>& os, mol::HttpResponse& response)
{
	// write headers
	os << response.headers;
	// write body
	os << response.body;
	// flush the stream
	os.flush();
	return os;
}
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////


#endif
