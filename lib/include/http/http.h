#ifndef POST_DEF_GUARD_DEF
#define POST_DEF_GUARD_DEF

#include "http/httprequest.h"
#include "ssl/sslstream.h"

namespace mol {



/////////////////////////////////////////////////////////////////////////
// HTTP GET request
/////////////////////////////////////////////////////////////////////////

class HttpGet : public HttpRequest
{
public:
	HttpGet();
	HttpGet( mol::Uri& u);

	void setUri( const mol::Uri& u );
	void addParam( const std::string& key, const std::string& val );
	std::string getParam(const std::string& key);
	std::vector<std::string> getParams(const std::string& key);
};

class HttpPost : public HttpRequest
{
public:
	HttpPost();
	HttpPost( mol::Uri& u);

	void setUri( const mol::Uri& u );
	void addParam( const std::string& key, const std::string& val );
	void setBody(const std::string& key);
	std::string getParam(const std::string& key);
	std::vector<std::string> getParams(const std::string& key);


};


/////////////////////////////////////////////////////////////////////////
// HTTP client object
/////////////////////////////////////////////////////////////////////////

class Http
{
public:

	enum HTTP_OPTIONS { NONE = 0, KEEP_ALIVE = 1, FOLLOW_REDIRECT = 2, VERBOSE = 4 };

	int options;

	Http();
	Http( int o);
	~Http();

	mol::HttpResponse& send( mol::HttpRequest& req );
	mol::HttpResponse& send( const mol::HttpRequest& req );
	mol::HttpResponse& send();

	int verifyCert();
	mol::Cert* peerCertificate();

	mol::HttpRequest  request;
    mol::HttpResponse response;

protected:

	void doSend();

	void doTCP();
	void doSSL();

	mol::TCPStream* tcp_;
	mol::SSLStream* ssl_;

	int verifyResult_;
	Cert* cert_;
};

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

} // end namespace mol

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////


#endif
