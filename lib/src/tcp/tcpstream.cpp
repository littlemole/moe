#include "tcp/tcpstream.h"

//! for Non-Win32 Systems, assume POSIX
#ifndef WIN32
#include <netdb.h>
#include <arpa/inet.h>
#include <errno.h>
#define closesocket(s) close(s)
#define WSAEMSGSIZE EMSGSIZE
#endif

// Win32 Systems
#ifdef WIN32
#include <ws2tcpip.h>
#endif

namespace mol {

//TCPStream TCPStreamInstantiation;
//TCPStreamBuf TCPStreamInstantiationBuf;
/////////////////////////////////////////////////////////////////////////
// TCP Stream Buffer
/////////////////////////////////////////////////////////////////////////

TCPStreamBuf::TCPStreamBuf() 
{}

TCPStreamBuf::TCPStreamBuf( SOCKET s) 
	: TCPStreamBufBase(s) 
{
	sock_fd_ = (s);
}

TCPStreamBuf::~TCPStreamBuf() 
{
	close();
}

//////////////////////////////////////////////////////////////////////////
// client functions
//////////////////////////////////////////////////////////////////////////

bool TCPStreamBuf::connect( const std::string& server, int port )
{
	close();

	if ( !addr_.set(server,port) )
		return false;

	bool repeat = false;

	int retry = 3;
	while(retry)
	{
		retry--;

		// open tcp socket
		if ( (sock_fd_ = ::socket( AF_INET,SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET )
			return false;

		SOCKET buf = sock_fd_;
		if ( sock_fd_ == 0 )
		{
//			int we = WSAGetLastError();
			return false;
		}

		// connect socket to address
		if ( ::connect( sock_fd_, (const sockaddr*)addr_, sizeof(sockaddr_in)) == 0 )
		{
			return true;
		}

#ifdef _WIN32
		int we = WSAGetLastError();
		if ( we == WSAETIMEDOUT )
		{
				continue;		
		}
#endif		
		break;
	}

	close();
	return false;
}


/////////////////////////////////////////////////////////////////////////
// Server functions
/////////////////////////////////////////////////////////////////////////

bool TCPStreamBuf::listen( int port, int n )
{
	close();

	// prepare server sock address
	addr_.setServerPort(port);

	// open socket
    if ( (sock_fd_ = ::socket( AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET )
    {
        sock_fd_ = 0;
        return false;
    }

	// bind socket to port
    if ( ::bind( sock_fd_, addr_, sizeof(sockaddr_in) ) != 0 )
	{
		close();
        return false;
	}

	// start listening on bound port
    if ( ::listen( sock_fd_, n ) != 0)
	{
		close();
        return false;
	}
    return true;
}

//////////////////////////////////////////////////////////////////////////

TCPStreamBuf* TCPStreamBuf::accept()
{
	// socket size
	socklen_t sock_addr_size = sizeof(sockaddr_in) ;

	// accept a new socket
    SOCKET socket;
    socket = ::accept( sock_fd_, addr_,&sock_addr_size);
	if ( !socket)
		return 0;
	return new TCPStreamBuf(socket);
}

/////////////////////////////////////////////////////////////////////////
// buffered Stream impl - translate iostream to socket stream
/////////////////////////////////////////////////////////////////////////

int TCPStreamBuf::buffered_write(char* c, int n)
{
	if ( n == 0 )
		return 0;

	int r = ::send(sock_fd_,c,n,0);

	if ( r == SOCKET_ERROR )
		return -1;//throw TcpEx("SOCKET write error");

	if ( r > 0 )
		return 0;
	return -1;

}

//////////////////////////////////////////////////////////////////////////

int TCPStreamBuf::buffered_read(char * c, int n)
{
	// make sure we want to read from device
	if ( n == 0 )
		return 0;

	// check how much we can read from TCP Buffer

	int len = ::recv( sock_fd_,c,n,MSG_PEEK );
	if ( len < 0 )
		return -1;

	if ( len == 0 )
		len = 1;//return 0;

	// adjust num of bytes to read
	int s = n;
	if ( (len > 0) && (len < n) )
		s = len;

	// actually do the read
	len = ::recv( sock_fd_,c,s,0 );
	if ( len == 0 )
		return 0;
	if ( len < 0 )
		return -1;

	return len;
/*
	// receive only 1 byte per time as this is tcp
	int l = ::recv( sock_fd_,c,1,0 );

	// handle errors and return
	if ( l == SOCKET_ERROR )
		return -1;//throw TcpEx("SOCKET read error");

	if ( l < 0 )
		return -1;

	return l;
*/
}

//////////////////////////////////////////////////////////////////////////
// socket shutdown
//////////////////////////////////////////////////////////////////////////

bool TCPStreamBuf::close()
{
	if ( !sock_fd_ )
		return true;

	sync();
	bool r  = ::closesocket(sock_fd_) == 0;
	sock_fd_ = 0;
	return r;
}

//////////////////////////////////////////////////////////////////////////

bool TCPStreamBuf::shutdown( int what )
{
	return ::shutdown(sock_fd_,what) != 0;
}


//////////////////////////////////////////////////////////////////////////
// address
//////////////////////////////////////////////////////////////////////////

IPAddress& TCPStreamBuf::addr()
{
	return addr_;
}

//////////////////////////////////////////////////////////////////////////
// socket options
//////////////////////////////////////////////////////////////////////////

int TCPStreamBufBase::setsockopt(  int level, int optname, const char* optval, int optlen )
{
	return ::setsockopt( sock_fd_, level, optname, optval, optlen );
}

//////////////////////////////////////////////////////////////////////////

#ifndef WIN32
int TCPStreamBufBase::ioctlsocket ( long cmd, u_long* argp )
{
    return ::fcntl( sock_fd_, cmd, argp );
}

//////////////////////////////////////////////////////////////////////////

bool TCPStreamBufBase::block( bool b )
{
    if ( b)
    {
		u_long argp = O_NONBLOCK;

         if ( TCPStreamBufBase::ioctlsocket( F_SETFL,&argp) <0)
              return false;
    }
    else
    {
         if ( TCPStreamBufBase::ioctlsocket( F_SETFL,0) <0)
              return false;
    }
    return true;
}
#endif

//////////////////////////////////////////////////////////////////////////

//! Win32 Systems
#ifdef WIN32

//////////////////////////////////////////////////////////////////////////

int TCPStreamBufBase::ioctlsocket ( long cmd, u_long* argp )
{
    return ::ioctlsocket( sock_fd_, cmd, argp );
}


//////////////////////////////////////////////////////////////////////////

bool TCPStreamBufBase::block( bool b )
{
    unsigned long o = (unsigned long)(!b);
	if ( TCPStreamBufBase::ioctlsocket( FIONBIO, &o )!=0)
		return false;
	return true;
}

#endif



//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

} // end namespace mol
