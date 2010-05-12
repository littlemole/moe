#include "http/httprequest.h"
#include <sstream>

namespace mol {

	
HttpBody::HttpBody() 
	:contentLengthIsKnown_(false)
{}

HttpBody::HttpBody(const std::string& b) 
	: contentLength_( (int) b.size()),
	  contentLengthIsKnown_(true),
	  body_(b)
{}

HttpBody::HttpBody(HttpHeaders& headers) 
	:contentLengthIsKnown_(false)
{
	if ( headers.contentLengthIsKnown() )
	{
		contentLengthIsKnown_ = true;
		contentLength_ = headers.contentLength();
	}
}

HttpBody::~HttpBody() {}

const bool HttpBody::contentLengthIsKnown()           
{ 
	if ( queryParams_.size() > 0 )
		return true;
	return contentLengthIsKnown_; 
}

const int HttpBody::contentLength()					
{ 
	if ( queryParams_.size() > 0 )
		return (int)body().size();
	return contentLength_; 
}

void  HttpBody::contentLength(const int s)			
{ 
	contentLength_ = s;  
	contentLengthIsKnown_ = true; 
}

const std::string& HttpBody::body()					
{ 
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
	contentLength_ = (int)b.size(); 
	contentLengthIsKnown_ = true; 
}


void HttpBody::addParam  ( const std::string& key, const std::string& val  )
{
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


} // end namespace mol

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

