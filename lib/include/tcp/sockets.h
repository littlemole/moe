#ifndef _DEF_MOL_SOCKETS_DEF_
#define _DEF_MOL_SOCKETS_DEF_

//! \file sockets.h
//! protable socket api definitions

#include "conf.h"
#include "util/x.h"
#include "util/str.h"
#include <vector>

namespace mol {

//! initialize socket library (win32)
class WinSockUser
{
public:
	WinSockUser();
    ~WinSockUser();
};

/////////////////////////////////////////////////////////////////////////
// encapsulates an Internet Address
/////////////////////////////////////////////////////////////////////////

class TcpEx : public mol::X
{
public:
	TcpEx() {}
	TcpEx(const char* const& what)
		: mol::X(what)
	{}
};

class IpAddressEx : public mol::TcpEx
{
public:
	IpAddressEx() {}
	IpAddressEx(const char* const& what)
		: mol::TcpEx(what)
	{}
};


class UriEx : public mol::TcpEx
{
public:
	UriEx() {}
	UriEx(const char* const& what)
		: mol::TcpEx(what)
	{}
};

class IPAddress
{

public:
    IPAddress();
    //! construct SockAddress from existing socket
    IPAddress( SOCKET sock);
    //! construct SockAddr with given hostname and port
    IPAddress(const std::string& server, int port);

    //! set hostname and port for this address
    bool set(const std::string& server, int port);
    //! set server port number
    void setServerPort(int port);

    //! get the IP in string notation
    std::string getIP();
    //! get the hostname as string
    std::string getHostName();
    //! get the port
    int getPort();

	operator sockaddr_in*() 
	{
		return &sockaddr_;
	}

	operator sockaddr*() 
	{
		return (struct sockaddr*)&sockaddr_;
	}

private:
    sockaddr_in                sockaddr_;
};

//! simple Url class
class Uri
{
public:
  Uri ();
  Uri (const std::string& url );

  bool set( const std::string& url );

  const std::string& getHost() const  { return host_;  }
  const std::string& getProto() const { return proto_; }
  const std::string& getPath() const  { return path_;  }
  const std::string& getUser() const  { return user_;  }
  const std::string& getPwd() const   { return pwd_;   }
  const std::string  getFullPath() const;
  const std::string  getParentDir() const;
  int getPort()	const			      { return port_;  }
  const std::string getQuery() const ;
  const std::string& getAnchor() const { return anchor_;  }

  void setHost     ( const std::string& host  );
  void setProto    ( const std::string& proto );
  void setPath     ( const std::string& path  );
  void setFullPath (const std::string& p );
  void setPort     ( int p );
  void setQuery    ( const std::string& query );
  void setAnchor   ( const std::string& anchor);

  void setUser (const std::string& user );
  void setPwd (const std::string& p );

  void addParam  ( const std::string& key, const std::string& val );
  std::string getParam(const std::string& key);
  std::vector<std::string> getParams(const std::string& key);
  std::string toString();

private:
  std::string   host_;
  int           port_;
  std::string   proto_;
  std::string   path_;
  std::string   anchor_;
  std::string   user_;
  std::string   pwd_;

  typedef std::pair<std::string,std::string> KeyVal;

  std::vector<KeyVal> queryParams_;
};


} // end namespace mol

#endif
