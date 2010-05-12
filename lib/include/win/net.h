#ifndef _DEF_MOL_INET_DEFINE_GUARD_
#define _DEF_MOL_INET_DEFINE_GUARD_

#include "util/uni.h"
#include <wininet.h>


namespace mol  {

namespace win  {

namespace inet {

//////////////////////////////////////////////////////////////////////////////

class Url
{
public:
	Url();
	Url( const std::string& u, DWORD flags = 0);
	Url( const std::string& host,
		const std::string& path,
		const std::string& file,
		const std::string& extra,
		DWORD flags = 0,
		INTERNET_PORT port = 0 );
	~Url();

	INTERNET_SCHEME htmlScheme();
	std::string scheme();
	std::string host();
	std::string path();
	std::string fullpath();
	std::string file();
	std::string extra();
	INTERNET_PORT port();
	std::string getUrl();

	std::string extendRelativePath(const std::string& u, DWORD flags = 0 );
	std::string dosPath();
	static std::string dosPath(const std::string& u);

	void makeUrl( const std::string& u, DWORD flags = 0 );
	void makeUrl( const std::string& host,
				  const std::string& path,
				  const std::string& file,
				  const std::string& extra,
				  DWORD flags=0,
				  INTERNET_PORT port=0  );
private:
	Url& operator=( const Url& url_);
	void init ();

	std::string		url_;
	URL_COMPONENTS	components_;
};

//////////////////////////////////////////////////////////////////////////////

class Inet
{
public:
	Inet();
	Inet(const std::string& userAgent_);

	BOOL canConnect();
	BOOL open();
	BOOL opened();
	BOOL close();
	void setUserAgent( const std::string& s );
	HINTERNET getHandle();
private:
	std::string		userAgent_;
	HINTERNET		hInternet_;
};

//////////////////////////////////////////////////////////////////////////////

class Http
{
public:
	Http( Inet& i ) 
		: inet_(i), 
		  bEof_(false), 
		  url_(0), 
		  con_(0)
	{}
	BOOL  open( const std::string& url_ );
	BOOL  open(const std::string& url_, const std::string& headers_, const std::string& postdata );
	BOOL  eof();
	BOOL  close();
	BOOL  getHeaders(std::string& str);
	int   read( char* c, int len  );
	BOOL  read( std::string& s );
	DWORD status_();
private:
	Inet&			inet_;
	BOOL			bEof_;
	HINTERNET		con_;
	HINTERNET		url_;
};

//////////////////////////////////////////////////////////////////////////////

class Post
{
public:
	Post( Inet& in );
	~Post();

	const std::string& operator()(const std::string& url_, const std::string& headers_, const std::string& postdata);
	const std::string& getContent();
	const std::string& getHeaders();
	const std::string& getUrl();
	int   getStatus();

private:
	Inet&		 inet_;
	std::string  url_;
	std::string  headers_;
	std::string	 mutex_;
	int			 status_;
};
//////////////////////////////////////////////////////////////////////////////

class Get
{
public:
        Get( Inet& in );
        ~Get();

        const std::string& operator()(const std::string& url_);
        const std::string& getContent();
        const std::string& getHeaders();
        const std::string& getUrl();
        int   getStatus();

private:
        Inet&		 inet_;
        std::string  url_;
        std::string  headers_;
        std::string	 mutex_;
        int			 status_;
};

} // end namespace mol::win::inet

} // end namespace mol::win

} // end namespace mol

#endif //

