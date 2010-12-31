#include "http/http.h"
#include <sstream>

namespace mol {

/////////////////////////////////////////////////////////////////////////
// HTTP GET request
/////////////////////////////////////////////////////////////////////////

HttpGet::HttpGet()
{}

HttpGet::HttpGet( mol::Uri& u)
{
	setUri(u);
}

void HttpGet::setUri( const mol::Uri& u )
{
	uri = u;
	headers.setCmd("GET");
	headers.setProto("HTTP/1.1");
	headers.setPath(uri.getFullPath());
}

void HttpGet::addParam( const std::string& key, const std::string& val )
{
	uri.addParam( key, val );
}

std::string HttpGet::getParam(const std::string& key)
{
	return uri.getParam(key);
}

std::vector<std::string> HttpGet::getParams(const std::string& key)
{
	return uri.getParams(key);
}


/////////////////////////////////////////////////////////////////////////
// HTTP POST request
/////////////////////////////////////////////////////////////////////////

HttpPost::HttpPost()
{}

HttpPost::HttpPost( mol::Uri& u)
{
	setUri(u);
}

void HttpPost::setUri( const mol::Uri& u )
{
	uri = u;
	headers.setCmd("POST");
	headers.setProto("HTTP/1.1");
	headers.setPath(uri.getFullPath());
}

void HttpPost::setBody(const std::string& b)
{
	body.body(b);
	std::ostringstream oss;
	oss << b.size();
	headers.add("content-length",oss.str());
}

void HttpPost::addParam( const std::string& key, const std::string& val )
{
	headers.set("content-type","application/x-www-form-urlencoded");
	body.addParam(key,val);
}

std::string HttpPost::getParam(const std::string& key)
{
	return body.getParam(key);
}

std::vector<std::string> HttpPost::getParams(const std::string& key)
{
	return body.getParams(key);
}



/////////////////////////////////////////////////////////////////////////
// HTTP client object
/////////////////////////////////////////////////////////////////////////


Http::Http()
	: tcp_(0),
	  ssl_(0),
	  options(0),
	  verifyResult_(0),
	  cert_(0)
{}

Http::Http( int o)
	: tcp_(0),
	  ssl_(0),
	  options(o),
	  verifyResult_(0),
	  cert_(0)
{}

Http::~Http()
{
	delete tcp_;
	delete ssl_;
	delete cert_;
}

mol::HttpResponse& Http::send( mol::HttpRequest& req )
{
	request = req;
	return send();
}

mol::HttpResponse& Http::send( const mol::HttpRequest& req )
{
	request = req;
	return send();
}

mol::HttpResponse& Http::send()
{
	doSend();

	if ( ! ( options & FOLLOW_REDIRECT ) )
	{
		return response;
	}
	
	int maxfollow = 7;
	std::string code = response.headers.getCode();
	while ( code.size() > 0 && code[0]=='3' )
	{
		std::string loc = response.headers.getHeader("location");
		if ( loc.size() == 0 )
			break;

		if ( options & VERBOSE )
			std::cout << response << std::endl;

		mol::Uri uri(loc);

		if ( uri.getHost() != request.uri.getHost() )
		{
			delete tcp_;
			delete ssl_;
			tcp_ = 0;
			ssl_ = 0;
		}
		request.uri = uri;
		request.headers.setPath(uri.getPath());//loc);

		if ( options & VERBOSE )
			std::cout << request << std::endl;

		doSend();

		maxfollow--;
		if (maxfollow == 0 )
			break;

		code = response.headers.getCode();
	}
	return response;
}

int Http::verifyCert()
{
	return verifyResult_;
}

mol::Cert* Http::peerCertificate()
{
	return cert_;
}

void Http::doSend()
{
	request.headers.del("host");
	request.headers.add( mol::HttpHeader("Host", request.uri.getHost()) );

	if ( options & KEEP_ALIVE )
	{
		request.headers.del("connection");
		request.headers.add( mol::HttpHeader("Connection","Keep-Alive") );			
	}

	if ( options & VERBOSE )
		std::cout << request << std::endl;

	response = mol::HttpResponse();
	if ( request.uri.getProto() == "https" )
	{
		doSSL();
	}
	else
	{
		doTCP();
	}
	if ( options & VERBOSE )
		std::cout << response << std::endl;
}

void Http::doTCP()
{
	if ( !tcp_ )
	{
		tcp_ = new mol::TCPStream;
		tcp_->connect(request.uri.getHost(),request.uri.getPort());
	}

	if ( request.headers.getCmd() == "POST" )
		request.headers.contentLength(request.body.body().size());

	*tcp_ << request;

	*tcp_ >> response;

	if ( !(options & KEEP_ALIVE) || response.headers.wantShutDown() )
	{
		delete tcp_;
		tcp_ = 0;
	}
}

void Http::doSSL()
{
	if ( !ssl_ )
	{
		ssl_ = new mol::SSLStream;
		ssl_->connect(request.uri.getHost(),request.uri.getPort());
	}

	*ssl_ << request;
	*ssl_ >> response;

	verifyResult_ = ssl_->verifyCert();
	
	delete cert_;
	cert_ = ssl_->peerCertificate();

	if ( !(options & KEEP_ALIVE) || response.headers.wantShutDown() )
	{
		delete ssl_;
		ssl_ = 0;
	}
}

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

} // end namespace mol

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////



/*
const std::string& Post::send(const std::string& location, const std::string& postdata)
{
  url = Uri(location);
  return send( postdata );
}

const std::string& Post::send(const std::string& postdata)
{
    content_ = "";

    TCPsocket   socket;
    SockAddress addr( url.getHost(), url.getPort() );
    if ( !socket.open() )
         return content_;
    if ( !socket.connect(addr) )
         return content_;

    request.setCmd("POST");
    request.setPath(url.getPath());
    request.setProto("HTTP/1.0");
    std::ostringstream oss;
    oss << postdata.size();
    request.add(Header("Content-Length",oss.str()));

	if ( request.send(socket) < 0 )
		return content_;

    if ( socket.send( postdata.c_str(), postdata.size()) < 0 )
         return content_;

    response = ResponseHeaders() ;
    response.read(socket);

    status_  = atoi(response.getStatus().c_str());
    int len = 0;

    if ( response.contentLengthIsKnown() )
    {
         int contentLength = response.contentLength();
         if ( contentLength > 0 )
         {
                len = socket.read( content_, contentLength );
         }
    }
    else
    {
       len = socket.read(content_);
    }
    socket.close();
    return content_;
}

const std::string&  Post::getContent()
{
    return content_;
}

int Post::getStatus()
{
    return status_;
}

//////////////////////////////////////////////////////////////////////////////

const std::string& Get::send(const std::string& location)
{
  url = Uri(location);
  return send();
}

const std::string& Get::send()
{
    content_ = "";

    TCPsocket   socket;
    SockAddress addr( url.getHost(), url.getPort() );
    if ( !socket.open())
         return content_;
    if ( !socket.connect(addr))
         return content_;

    request.setCmd("GET");
    request.setPath(url.getPath());
    request.setProto("HTTP/1.0");
    request.add( Header("Host",url.getHost()) );

	if ( request.send(socket) < 0 )
		return content_;

    response = ResponseHeaders() ;
    response.read(socket);

    status_  = atoi(response.getStatus().c_str());
    int len = 0;

    if ( response.contentLengthIsKnown() )
    {
         int contentLength = response.contentLength();
         if ( contentLength > 0 )
         {
                len = socket.read( content_, contentLength );
         }
    }
    else
    {
       len = socket.read(content_);
    }
    socket.close();
    return content_;
}

const std::string& Get::getContent()
{
    return content_;
}

int Get::getStatus()
{
    return status_;
}
*/

//} //end namespace mol

/*
mol::HttpResponse& operator <<( mol::HttpResponse& response, mol::Get& get )
{
	response = get.send();
	return response;
}
*/

