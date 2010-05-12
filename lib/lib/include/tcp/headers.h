#ifndef _DEF_HEADERS_DEFINE_GUARD_DEF_
#define _DEF_HEADERS_DEFINE_GUARD_DEF_

#include "sockets.h"
#include <string>
#include <list>

namespace mol {

/*! \file Headers.h
  Helpers to deal with HTTP Headers

*/

typedef std::pair<std::string,std::string>  Header;
typedef std::list<Header>                   HeaderList;
typedef HeaderList::iterator                Hiterator;

//! HTPP Headers
class Headers
{
public:
    int read(TCPsocket& socket);

    const std::string& getAction();
    void  setAction( const std::string& str);
    std::string getHeaders();

    std::string getHeader( const std::string& str );
    void add( const Header& h );
    void del( Hiterator hit);
    bool del( const std::string& str);
    bool del( const std::string& str, const std::string& val );

    Hiterator iterator( const std::string& str );
    Hiterator begin();
    Hiterator end();

    bool contentLengthIsKnown();
    int  contentLength();
    std::string contentType();
    std::string connection();
    bool wantShutDown();
	bool keepAlive();
protected:
    std::string               action_;
    HeaderList                list_;
};

class RequestHeaders : public Headers
{
public:
    int read(TCPsocket& socket);
	int send(TCPsocket& socket);

    std::string toString();

    const std::string& getAction();
    const std::string getCmd();
    const std::string getHost();
    const std::string getPath();
    const std::string getProto();
    int   getPort();

    void setCmd( const std::string& str );
    void setHost( const std::string& str );
    void setPath( const std::string& str );
    void setProto( const std::string& str );
    void setPort(int p);

    bool  isConnect();

private:
    std::string                cmd_;
    std::string                host_;
    std::string                path_;
    std::string                proto_;
    int                        port_;
    bool                       isconnect_;
};

class ResponseHeaders : public Headers
{
public:
    int read(TCPsocket& socket);
	int send(TCPsocket& socket);
    std::string toString();

    const std::string getProto();
    const std::string getCode();
    const std::string getStatus();

    void setProto( const std::string& str );
    void setCode(  const std::string& str );
    void setStatus(const std::string& str );

private:
    std::string                proto_;
    std::string                code_;
    std::string                status_;

};

}

#endif