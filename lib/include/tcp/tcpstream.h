#ifndef MOL_TCP_STREAM_DEF_GUARD_DEF_
#define MOL_TCP_STREAM_DEF_GUARD_DEF_

#include "tcp/sockets.h"
#include "tcp/streambuf.h"
#include "tcp/select.h"

namespace mol {

class Cert;
class SSLContext;

/////////////////////////////////////////////////////////////////////////
// base class for TCP and TCP/SSL streambuf impls
/////////////////////////////////////////////////////////////////////////

class TCPStreamBufBase 
	: public BufferedStreamBuf< char, std::char_traits<char> >	
{
public:

	TCPStreamBufBase() 
		: sock_fd_(0) 
	{}

	TCPStreamBufBase( SOCKET s)
		: sock_fd_(s) 
	{}

	~TCPStreamBufBase( ) 
	{}

	// get IP address
	virtual IPAddress& addr() = 0;

	// get raw socket
	SOCKET& sock_fd() { return sock_fd_; }

	// TCP operations
	virtual bool connect( const std::string& server, int port ) = 0;
	virtual bool close() = 0;
	virtual bool shutdown( int what = SD_SEND) = 0;

	// server functions
	virtual bool listen( int port, int n ) = 0;
	virtual TCPStreamBufBase* accept() = 0;

	// socket options
    bool block(bool b);
    int setsockopt(  int level, int optname, const char* optval, int optlen );
	int ioctlsocket ( long cmd, u_long* argp );

protected:

	IPAddress addr_;
	SOCKET sock_fd_;
};



/////////////////////////////////////////////////////////////////////////
// TCP StreamBuf
/////////////////////////////////////////////////////////////////////////

class TCPStreamBuf 
	: public TCPStreamBufBase  
{
public:
	TCPStreamBuf();
	TCPStreamBuf( SOCKET s);
	~TCPStreamBuf();

	// TCP operations
	bool connect( const std::string& server, int port );
	bool close();
	bool shutdown( int what = SD_SEND);

	// get IP address
	IPAddress& addr();

	// server functions
	bool listen( int port, int n );
	TCPStreamBuf* accept();


	// dummy SSL functions

	// get cert
	mol::Cert* peerCertificate() { return 0; }
	//verify cert
	int verifyCert() { return 0; }

private:

	// prohibit copying and assingment
    TCPStreamBuf(const TCPStreamBuf&);
    TCPStreamBuf& operator = (const TCPStreamBuf&);

	// IOStream to socket stream conversion impl
	int buffered_write(char* c, int n);
	int buffered_read (char* c, int n);

};

/////////////////////////////////////////////////////////////////////////
// TCP Stream Facade
/////////////////////////////////////////////////////////////////////////

template<class T>
class basic_TCPStream : public std::basic_iostream< char, std::char_traits<char> >
{
public:

    typedef std::basic_iostream< char, std::char_traits<char> >	base_type;

	basic_TCPStream();
	basic_TCPStream(const std::string& server,int port = 80);
	explicit basic_TCPStream(const mol::Uri& uri);
	explicit basic_TCPStream(SOCKET s);
	explicit basic_TCPStream(SSLContext* s);
	basic_TCPStream(T* s);

	~basic_TCPStream();

	// open / close connection
	bool connect( const std::string& server, int port )
	{
		clear();
		return buf_->connect(server,port);
	}

	bool close()
	{
		return buf_->close();
	}

	int shutdown( int what)
	{
		return buf_->shutdown(what);
	}

	// server functions
	bool listen( int port, int n )
	{
		clear();
		return buf_->listen(port,n);
	}

	basic_TCPStream<T>* accept()
	{
		clear();

		T* t = buf_->accept();
		if (!t)
			return 0;

		return new basic_TCPStream<T>(t);
	}


	basic_TCPStream<T>* accept(SOCKET s)
	{
		clear();

		T* t = buf_->accept(s);
		if (!t)
			return 0;

		return new basic_TCPStream<T>(t);
	}


	basic_TCPStream<T>* accept(basic_TCPStream<TCPStreamBuf>& tcp)
	{
		clear();

		T* t = buf_->accept(tcp);
		if (!t)
			return 0;

		return new basic_TCPStream<T>(t);
	}

	// get IP address
	IPAddress& addr()
	{
		return buf_->addr();
	}


	// block socket option
    bool block(bool b)
	{
		return buf_->block(b);
	}

	// set socket options
    int setsockopt(  int level, int optname, const char* optval, int optlen )
	{
		return buf_->setsockopt(level,optname,optval,optlen);
	}

	// set socket options
	int ioctlsocket ( long cmd, u_long* argp )
	{
		return buf_->ioctlsocket(cmd,argp);
	}

	// raw socket
	SOCKET& sock_fd() 
	{ 
		return buf_->sock_fd(); 
	}


	// SSL related stuff

	//verify cert
	int verifyCert()
	{
		return buf_->verifyCert();
	}

	// get cert
	mol::Cert* peerCertificate()
	{
		return buf_->peerCertificate();
	}

	bool graceful_shutdown()
	{
		buf_->shutdown(SD_SEND);
		std::string tmp;
		mol::Select sel;
		sel.setRead(sock_fd());
		if ( sel.select(500,0) )
			*this >> tmp;
		close();
		return true;
	}

	bool can_read( int s = 0, int ms = 0 )
	{
		mol::Select sel;
		sel.setRead(sock_fd());
		sel.select(ms,s);
		if ( !sel.isReadSet(sock_fd())  )
			return false;
		return true;
	}

private:

	// create buffer helpers

	T* createBuf()
	{
		buf_ = new T;
		return buf_;
		
	}

	T* createBuf(SSLContext* ctx)
	{
		buf_ = new T(ctx);
		return buf_;
		
	}

	// the buffer
	T* buf_;
};

/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////
// TCP Stream Facade c'tor/d'tor
/////////////////////////////////////////////////////////////////////////


template<class T>
basic_TCPStream<T>::basic_TCPStream()
	: basic_TCPStream<T>::base_type(createBuf())
{
}

template<class T>
basic_TCPStream<T>::basic_TCPStream(SOCKET s)
	: basic_TCPStream<T>::base_type(createBuf())
{
	buf_->sock_fd_ = s;
}

template<class T>
basic_TCPStream<T>::basic_TCPStream(T* s)
	: basic_TCPStream<T>::base_type(s),buf_(s)
{
}


template<class T>
basic_TCPStream<T>::basic_TCPStream(SSLContext* s)
	: basic_TCPStream<T>::base_type(createBuf(s))
{
}

template<class T>
basic_TCPStream<T>::basic_TCPStream( const std::string& server, int port )
	: basic_TCPStream<T>::base_type(createBuf())
{
	if ( !connect( server, port ) )
		throw mol::TcpEx("CONNECT failed");
}

template<class T>
basic_TCPStream<T>::basic_TCPStream( const mol::Uri& uri )
	: base_type(createBuf())
{
	if ( !connect( uri.getHost(), uri.getPort() ) )
		throw mol::TcpEx("CONNECT failed");
}

template<class T>
basic_TCPStream<T>::~basic_TCPStream()
{
	delete buf_;
}
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

typedef basic_TCPStream<TCPStreamBuf> TCPStream;

/////////////////////////////////////////////////////////////////////////

} // end namespace mol

#endif
