#include "tcp/sockets.h"
#include <sstream>
#include <iostream>
#include "util/x.h"


namespace mol {


//////////////////////////////////////////////////////////////////////////
// IP Adress
//////////////////////////////////////////////////////////////////////////


IPAddress::IPAddress()
{
    sockaddr_.sin_family         = AF_INET;
    sockaddr_.sin_addr.s_addr    = 0;
    sockaddr_.sin_port           = 0;
}

IPAddress::IPAddress(const std::string& server, int port)
{
    sockaddr_.sin_family = AF_INET;
    if (!set(server,port))
		throw mol::IpAddressEx("invalid host/port");
}

IPAddress::IPAddress( SOCKET sock)
{	
    socklen_t size = sizeof( sockaddr_in);
    if ( SOCKET_ERROR == getpeername( sock, (struct sockaddr*)&sockaddr_, &size ) )
		throw mol::IpAddressEx("getpeername failed for socket");
}


bool IPAddress::set(const std::string& server, int port)
{
    sockaddr_.sin_port = htons(port);

    struct hostent* h;
    h = ::gethostbyname ( server.c_str() );

    if (!h)
    {
        if ( INADDR_NONE == ( sockaddr_.sin_addr.s_addr = ::inet_addr(server.c_str()) ) )
           return false;
    }

    sockaddr_.sin_addr =  *(in_addr*)(h->h_addr_list[0]);

    return true;
}

void IPAddress::setServerPort(int port)
{
    sockaddr_.sin_port               = htons(port);
    //sockaddr_.sin_addr.s_addr        = htonl(INADDR_ANY);
}

std::string IPAddress::getIP()
{
    return ::inet_ntoa(sockaddr_.sin_addr);
}

std::string IPAddress::getHostName()
{
    struct hostent* h;
    if (!(h = gethostbyaddr ( (const char*)&(sockaddr_.sin_addr), sizeof(sockaddr_.sin_addr),AF_INET)))
		return "";

    return h->h_name;
}

int IPAddress::getPort()
{
    return ntohs(sockaddr_.sin_port);
}

/////////////////////////////////////////////////////////////////////////

Uri::Uri()
  : port_(80)
{}

Uri::Uri (const std::string& url )
  : port_(80)
{
    set(url);
}

bool Uri::set( const std::string& url )
{
    proto_  = "";
    host_   = "";
    port_   = 80;
	std::string path   = "/";

	// find proto
    size_t pos = url.find("://");
    if ( pos != std::string::npos )
	{
		proto_ = url.substr(0,pos);
		if ( mol::stricmp( proto_.c_str(), "https" ) == 0 )
		{
			port_ = 443;
		}
		if ( mol::stricmp( proto_.c_str(), "ssh" ) == 0 )
		{
			port_ = 22;
		}
		if ( mol::stricmp( proto_.c_str(), "scp" ) == 0 )
		{
			port_ = 22;
		}
		host_  = url.substr(pos+3);
	}
	else
	{
		proto_ = "http";
		host_  = url;
	}

	pos    = host_.find("/");
    if ( pos != std::string::npos )
    {
         path  = host_.substr(pos);
         host_ = host_.substr(0,pos);
		 if ( pos > 0 && host_[pos-1] == ':' )
		 {
			 host_ = host_.substr(0,host_.size()-1);
		 }
    }
	pos = host_.find("@");
    if ( pos != std::string::npos )
    {
		std::string tmp = host_.substr(0,pos);
		host_ = host_.substr(pos+1);
		pos = tmp.find(":");
		if ( pos != std::string::npos )
		{
			user_ = tmp.substr(0,pos);
			pwd_ = tmp.substr(pos+1);
		}
		else
		{
			user_ = tmp;
		}
	}
    pos = host_.find(":");
    if ( pos != std::string::npos )
    {
         std::string tmp = host_.substr(pos+1);
         port_ = atoi(tmp.c_str());
         host_ = host_.substr(0,pos);
    }
	setFullPath(path);
	return true;
}

std::string Uri::toString()
{
  std::ostringstream oss;
  oss << proto_ << "://";
  
  if ( !user_.empty() )
  {
	  oss << user_;
	  if ( !pwd_.empty() )
	  {
		oss << ":" << pwd_;
	  }
	  oss << "@";
  }
	  
  oss << host_;

  if ( port_ != 80 && port_ != 443 && port_ != 22 )
  {
	  oss << ":" << port_;
  }
  oss << path_;
  oss << getQuery();
  if ( anchor_.size() > 0 )
	  oss << "#" << anchor_;
  return oss.str();
}

void Uri::setUser   ( const std::string& u  ) 
{ 
	user_ = u;
}

void Uri::setPwd   ( const std::string& pwd  ) 
{ 
	pwd_ = pwd;
}

void Uri::setHost   ( const std::string& host  ) 
{ 
	size_t pos = host.find_first_not_of("/\\");
	if ( pos != std::string::npos )
	{
		host_ = host.substr(pos);
	}
	else
		host_   = host; 

	pos = host.find_last_not_of("/\\");
	if ( pos != std::string::npos )
	{
		host_ = host_.substr(0,pos+1);
	}
}

void Uri::setProto  ( const std::string& proto ) 
{
    size_t pos = proto.find("://");
    if ( pos != std::string::npos )
	{
		proto_ = proto.substr(0,pos);
	}
	else
		proto_  = proto; 
}

void Uri::setPath   ( const std::string& path  ) 
{ 
	if ( path.size() == 0 )
		path_ = "/";
	else
	{
		if ( path[0] != '/' )
		{
			path_ = "/" + path;
		}
		else
			path_ = path;
	}

}

void Uri::setPort   ( int p )				      
{ 
	port_   = p;  
}

const std::string Uri::getFullPath() const
{
  std::ostringstream oss;
  oss << path_;
  oss << getQuery();
  if ( anchor_.size() > 0 )
	  oss << "#" << anchor_;
  return oss.str();
}

const std::string  Uri::getParentDir() const
{
	const std::string& p = getPath();
	std::string parentdir(p);

	if ( !parentdir.empty() && parentdir[parentdir.size()-1] == '/' )
	{
		parentdir = parentdir.substr(0,parentdir.size()-1);
	}

	size_t pos = parentdir.find_last_of("/");
	if ( pos != std::string::npos && pos != 0)
	{
		parentdir = parentdir.substr(0,pos);
	}
	return parentdir;
}

void Uri::setFullPath(const std::string& p )
{   
	size_t pos = p.find("#");
	if ( pos != std::string::npos )
	{
		setAnchor(p.substr(pos));
		path_ = p.substr(0,pos);
	}
	else
	{
		path_ = p;
	}
	pos = path_.find("?");
	if ( pos != std::string::npos )
	{
		setQuery(path_.substr(pos));
		path_ = path_.substr(0,pos);
	}
}

const std::string Uri::getQuery() const
{
	std::ostringstream oss;
	if ( queryParams_.size() > 0 )
	{
		oss << "?";
		for ( size_t i = 0; i < queryParams_.size(); i++ )
		{
			if ( queryParams_[i].first.size() > 0 )
				oss << queryParams_[i].first;
			if ( queryParams_[i].second.size() > 0 )
				oss << "=" << queryParams_[i].second;
			if ( i < queryParams_.size()-1 )
				oss << "&";
		}
	}
	return oss.str();  
}

void Uri::setQuery  ( const std::string& query ) 
{ 
	queryParams_.clear();
	if ( query.size() == 0 )
	{
		return;
	}

	size_t pos = 0;
	size_t p   = 0;

	//if ( query.size() > 1 )
		if ( query[0] == '?' )
			pos = 1;

	while ( p!= std::string::npos )
	{
		std::string key;
		std::string val;
		p = query.find("=",pos);
		if ( p!= std::string::npos )
		{
			key = query.substr(pos,p-pos);
			pos = query.find("&",p+1);
			if ( pos != std::string::npos )
			{
				val = query.substr( p+1, pos-p-1 );
				pos = pos+1;
			}
			else
			{
				val = query.substr( p+1 );
				p = std::string::npos;
			}
		}
		else
		{
			key = query.substr(pos);
		}
		//std::cout << "[" << key << "] = " << val << std::endl;
		queryParams_.push_back( std::make_pair( key,val ) );
	}
}

void Uri::setAnchor ( const std::string& anchor) 
{ 
	anchor_ = "";
	if ( anchor.size() > 0 )
	{
		if ( anchor[0] == '#' )
		{
			if ( anchor.size() > 1 )
				anchor_ = anchor.substr(1);
		}
	}
}

void Uri::addParam  ( const std::string& key, const std::string& val  )
{
	queryParams_.push_back( std::make_pair( key,val ) );
}


std::string Uri::getParam(const std::string& key)
{
	for ( size_t i = 0; i < queryParams_.size(); i++ )
	{
		if ( queryParams_[i].first == key )
			return queryParams_[i].second;
	}
	return "";
}

std::vector<std::string> Uri::getParams(const std::string& key)
{
	std::vector<std::string> v;
	for ( size_t i = 0; i < queryParams_.size(); i++ )
	{
		if ( queryParams_[i].first == key )
			v.push_back(queryParams_[i].second);
	}
	return v;
}

//////////////////////////////////////////////////////////////////////
// MICROSTUFF
//////////////////////////////////////////////////////////////////////

WinSockUser::WinSockUser()
{
#ifdef WIN32
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	wVersionRequested = MAKEWORD( 2, 2 );
	err = ::WSAStartup( wVersionRequested, &wsaData );
	if ( err != 0 )
	{
		throw X( _T("WINDLL failed - winsock startup") );
	}

	if ( LOBYTE( wsaData.wVersion ) != 2 ||
		 HIBYTE( wsaData.wVersion ) != 2 )
	{
		::WSACleanup( );
		throw X( _T("WINDLL failed -winsock startup") );
	}
#endif
}

WinSockUser::~WinSockUser()
{
#ifdef WIN32
       ::WSACleanup( );
#endif
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

} // end namespace mol
