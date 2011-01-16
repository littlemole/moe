#include "http/httprequest.h"
#include <sstream>

namespace mol {

	
HttpBody::HttpBody() 	
{}

HttpBody::HttpBody(AbstractBodyReader* r)
	:reader_(r)
{}

HttpBody::HttpBody(const std::string& b) 
	:body_(b)
{}


HttpBody::HttpBody(const HttpBody& rhs) 
	:reader_(rhs.reader_), body_(rhs.body_)
{
}

HttpBody::~HttpBody() 
{}

HttpBody& HttpBody::operator=(const HttpBody& rhs )
{
	if ( &rhs == this )
		return *this;

	reader_ = rhs.reader_;
	body_ = rhs.body_;
	queryParams_ = rhs.queryParams_;
	return *this;
}

const std::string& HttpBody::raw_body()		
{
	if ( !reader_ )
	{
		return body();
	}
	return reader_->raw();
}

const std::string& HttpBody::body()					
{ 
	if ( !body_.empty() )
		return body_;

	if ( reader_ )
	{
		body_ = reader_->toString();
		return body_;
	}

	if ( queryParams_.size() > 0 )
	{
		std::ostringstream oss;
		for ( unsigned int i = 0; i < queryParams_.size(); i++ )
		{
			if ( queryParams_[i].first.size() > 0 )
				oss << queryParams_[i].first;
			if ( queryParams_[i].second.size() > 0 )
				oss << "=" << queryParams_[i].second;
			if ( i < queryParams_.size()-1 )
				oss << "&";
		}
		body_ = oss.str();  
	}
	return body_; 
}

void HttpBody::body( const std::string& b )			
{ 
	body_ = b; 
	reader_.reset();
}


void HttpBody::addParam  ( const std::string& key, const std::string& val  )
{
	body("");
	queryParams_.push_back( std::make_pair( key,val ) );
}


std::string HttpBody::getParam(const std::string& key)
{
	for ( unsigned int i = 0; i < queryParams_.size(); i++ )
	{
		if ( queryParams_[i].first == key )
			return queryParams_[i].second;
	}
	return "";
}

std::vector<std::string> HttpBody::getParams(const std::string& key)
{
	std::vector<std::string> v;
	for ( unsigned int i = 0; i < queryParams_.size(); i++ )
	{
		if ( queryParams_[i].first == key )
			v.push_back(queryParams_[i].second);
	}
	return v;
}


/////////////////////////////////////////////////////////////////////////
// generic HTTP response
/////////////////////////////////////////////////////////////////////////

HttpResponse::HttpResponse() 
{
	headers.setResponse("HTTP 200 OK");
}

HttpResponse::HttpResponse(const HttpResponse& rhs) 
	: headers(rhs.headers),body(rhs.body)
{}

HttpResponse::HttpResponse(const std::string& b) 
{
	headers.setResponse("HTTP 200 OK");
	headers.contentType("text/html");
	headers.contentLength((int)b.size());
	body.body(b);
}

HttpResponse::HttpResponse(const std::string& b, const std::string& content_type) 
{
	headers.setResponse("HTTP 200 OK");
	headers.contentType(content_type);
	headers.contentLength((int)b.size());
	body.body(b);
}

HttpResponse::~HttpResponse() 
{}

HttpResponse& HttpResponse::operator=(const HttpResponse& rhs)
{
	if ( &rhs == this )
		return *this;

	headers = rhs.headers;
	body = rhs.body;
	return *this;
}


AbstractBodyReader* HttpResponse::reader()
{
	std::string enc = headers.contentEncoding();
	size_t gzip = enc.find("gzip");

	size_t deflate = enc.find("deflate");

	std::string te = headers.transferEncoding();
	size_t chunked = te.find("chunked");


	if ( chunked != std::string::npos )
	{
		if ( gzip != std::string::npos )
		{
			return new ChunkedBodyReader( new GzipBodyReader );
		}
		if ( deflate != std::string::npos )
		{
			return new ChunkedBodyReader( new DeflateBodyReader );
		}
		return new ChunkedBodyReader();
	}

	if ( gzip != std::string::npos )
	{
		if ( headers.contentLengthIsKnown() )
		{
			size_t s = headers.contentLength();
			return new ContentLengthBodyReader( new GzipBodyReader,s );
		}
		return new EofBodyReader( new GzipBodyReader );
	}


	if ( deflate != std::string::npos )
	{
		if ( headers.contentLengthIsKnown() )
		{
			size_t s = headers.contentLength();
			return new ContentLengthBodyReader( new DeflateBodyReader , s );
		}
		return new EofBodyReader( new DeflateBodyReader );
	}

	if ( headers.contentLengthIsKnown() )
	{
		size_t s = headers.contentLength();
		return new ContentLengthBodyReader(s);
	}
	return new EofBodyReader();
}

} // end namespace mol

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

