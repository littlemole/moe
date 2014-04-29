#include "win/net.h"

#include <sstream>
#include <shlwapi.h>

namespace mol  {

namespace win  {

namespace inet {

//////////////////////////////////////////////////////////////////////////

void Url::init ()
{
	ZeroMemory((PVOID)&components_, sizeof(components_));
	components_.dwStructSize = sizeof(components_);

	components_.dwSchemeLength=32;
	components_.dwHostNameLength=256;
	components_.dwUrlPathLength=1024;
	components_.dwExtraInfoLength=1024;
}


Url::Url(void)
{
	init();
}

Url::~Url(void)
{

}

std::string Url::dosPath()
{
	DWORD len = 1024;
	wchar_t buf[1024];
	buf[0]=0;
	PathCreateFromUrl( mol::towstring(url_).c_str(), buf, &len,0);
	return mol::tostring(buf);
}

std::string Url::dosPath(const std::string& u)
{
	DWORD len = 1024;
	wchar_t buf[1024];
	buf[0]=0;
	PathCreateFromUrl( mol::towstring(u).c_str(), buf, &len,0);
	return mol::tostring(buf);
}

Url::Url( const std::string& host,
		 const std::string& path,
		 const std::string& file,
		 const std::string& extra,
		 DWORD flags,
		 INTERNET_PORT port )
{
	init();
	makeUrl( host, path, file, extra, flags, port );
}


Url::Url(const std::string& u, DWORD flags)
{
	init();
	makeUrl( u, flags);
}

void Url::makeUrl(const std::string& u, DWORD flags)
{
	url_ = u;
	InternetCrackUrl( mol::towstring(url_).c_str(), 0, flags, &components_);
}

void Url::makeUrl( const std::string& host,
			  const std::string& path,
			  const std::string& file,
			  const std::string& extra,
			  DWORD flags,
			  INTERNET_PORT port  )
{
	url_ = host;
	if ( port != 0 )
	{
		char buf[32];
		wsprintfA(buf,"%i", this->port() );
		url_ += ":" ;
		url_ += buf;
	}
	url_ += path + file + extra;
	makeUrl( url_, flags);
}

INTERNET_SCHEME Url::htmlScheme()
{
	INTERNET_SCHEME nScheme = INTERNET_SCHEME_UNKNOWN;
	nScheme = components_.nScheme;
	return nScheme;
}

std::string Url::scheme()
{
	std::string ret = "";
	if ( components_.lpszScheme )
	{
		std::string tmp( mol::tostring(std::wstring(components_.lpszScheme, components_.dwSchemeLength)));
		ret += tmp;
	}
	return  ret;
}
std::string Url::host()
{
	std::string ret = "";

	if ( components_.lpszHostName  )
	{
		std::string tmp( mol::tostring( std::wstring(components_.lpszHostName, components_.dwHostNameLength)));
		ret += tmp;
	}
	return  ret;
}

std::string Url::path()
{
	std::string path = fullpath();
	size_t p = path.find_last_of("/\\");
	std::string file = path.substr(0,p);
	return file;
}

std::string Url::fullpath()
{
	std::string ret = "";
	if ( components_.lpszUrlPath  )
	{
		std::string tmp( mol::tostring( std::wstring( components_.lpszUrlPath, components_.dwUrlPathLength)));
		ret += tmp;
	}
	return  ret;
}

std::string Url::file()
{
	std::string path = fullpath();
	size_t p = path.find_last_of("/\\");
	std::string file = path.substr(p+1);
	return file;
}


std::string Url::extra()
{
	std::string ret = "";
	if ( components_.lpszExtraInfo   )
	{
		std::string tmp( mol::tostring( std::wstring( components_.lpszExtraInfo, components_.dwExtraInfoLength)));
		ret += tmp;
	}
	return  ret;
}

std::string Url::getUrl()
{
	return url_;
}
INTERNET_PORT Url::port()
{
	return components_.nPort;
}

std::string Url::extendRelativePath(const std::string& u, DWORD flags)
{
	DWORD len = 2048;
	wchar_t buf[2048];
	buf[0] = 0;
	::InternetCombineUrl( mol::towstring(url_).c_str(), mol::towstring(u).c_str(), buf, &len, flags );
	return mol::tostring( mol::towstring(buf));
}

//////////////////////////////////////////////////////////////////////////

Inet::Inet() :userAgent_(""), hInternet_(0)
{}

Inet::Inet(const std::string& userAgent_) : userAgent_(userAgent_), hInternet_(0)
{}

HINTERNET Inet::getHandle()
{
	return hInternet_;
}

BOOL Inet::canConnect()
{
	return ( ERROR_SUCCESS == ::InternetAttemptConnect(0) );
}

BOOL Inet::open()
{
    return ( 0 != ( hInternet_ = ::InternetOpen( mol::towstring(userAgent_).c_str(),
		INTERNET_OPEN_TYPE_DIRECT,
		0,0,0 )
		));
}

BOOL Inet::opened()
{
	return hInternet_ != 0;
}

BOOL Inet::close()
{
	if ( hInternet_)
		return ::InternetCloseHandle( hInternet_);
	return TRUE;
}

////////////////////////////////////////////////////////////

BOOL Http::open(const std::string& u, const std::string& headers_, const std::string& postdata )
{
	Url myUrl(u);
	con_ = ::InternetConnect( inet_.getHandle(),
		mol::towstring(myUrl.host()).c_str() ,
		myUrl.port(),
		0, 0, INTERNET_SERVICE_HTTP, 0, 0 );


	std::string method = "GET";
	if ( postdata != "" )
		method = "POST";

	std::string path = myUrl.fullpath()+myUrl.extra();
	url_ = ::HttpOpenRequest( con_, mol::towstring(method).c_str(),mol::towstring(path).c_str(),_T("1.1"),0,0,0,0);

	return ::HttpSendRequest( url_, mol::towstring(headers_).c_str(), (int)headers_.size(), (void*)(postdata.c_str()), (int)postdata.size() );
}

BOOL Http::open(const std::string& u)
{

	return ( 0 != ( url_ = ::InternetOpenUrl(  inet_.getHandle(),
		mol::towstring(u).c_str(),
		0,
		INTERNET_FLAG_RELOAD,
		0,0)					
		));
}

BOOL Http::eof()
{
	return bEof_;
}

BOOL Http::close()
{
	BOOL ret = FALSE;
	if ( url_ )
		ret = ::InternetCloseHandle(url_);

	if ( con_ )
		ret = ::InternetCloseHandle(con_);
	return ret;
}

int Http::read(char* c, int len )
{
	unsigned long  actual_len;
	if ( FALSE == ::InternetReadFile( url_, c, len-1, &actual_len ))
		return -1;
	if ( actual_len == 0 )
		bEof_ = true;
	c[actual_len] = '\0';
	return actual_len;
}

BOOL Http::read(std::string& s)
{
	std::stringstream str;
	while ( !eof() )
	{
		int len = 0;
		char buf[1024];

		len =  read( buf, 1024 );
		if ( len == -1 )
			return false;
		str.write( buf, len );
	}
	s = str.str();
	return true;
}

BOOL Http::getHeaders(std::string & str)
{
	unsigned long len = 4096;
	char buf[4096];
	BOOL ret = ::HttpQueryInfo( url_, HTTP_QUERY_RAW_HEADERS_CRLF,buf,&len,NULL);
	buf[len]='\0';
	str = std::string(buf);
	return ret;
}

DWORD Http::status_()
{
	DWORD stat;
	unsigned long len=sizeof(stat);

	::HttpQueryInfo( url_, HTTP_QUERY_STATUS_CODE|HTTP_QUERY_FLAG_NUMBER ,&stat,&len,NULL);

	return stat;
}

////////////////////////////////////////////

Post::Post( Inet& i )
:	inet_(i)
{
}

Post::~Post()
{}


const std::string& Post::operator()(const std::string& u, const std::string& h, const std::string& postdata)
{
	url_ = u;
	mutex_ = "";

	Http http(inet_);

	if (!http.open( url_, h, postdata))
		return mutex_;

	if (!http.read(mutex_))
	{
		http.close();
		return mutex_;
	}

	http.getHeaders(headers_);
	status_ = http.status_();

	http.close();

	return mutex_;
}

const std::string&  Post::getContent()
{
	return mutex_;
}

const std::string&  Post::getHeaders()
{
	return headers_;
}

const std::string& Post::getUrl()
{
	return url_;
}

int Post::getStatus()
{
	return status_;
}

//////////////////////////////////////////////////////////////////////////////
Get::Get( Inet& i )
	:	inet_(i)
{
}

Get::~Get()
{}

const std::string& Get::operator()(const std::string& u)
{
    url_ = u;
    mutex_ = "";

    Http http(inet_);

    if (!http.open(url_))
            return mutex_;

    if (!http.read(mutex_))
    {
            http.close();
            return mutex_;
    }

    http.getHeaders(headers_);
    status_ = http.status_();

    http.close();

    return mutex_;
}

const std::string&  Get::getContent()
{
    return mutex_;
}

const std::string&  Get::getHeaders()
{
    return headers_;
}

const std::string& Get::getUrl()
{
    return url_;
}

int Get::getStatus()
{
    return status_;
}


} // end namespace mol::win::inet

} // end namespace mol::win

} // end namespace mol