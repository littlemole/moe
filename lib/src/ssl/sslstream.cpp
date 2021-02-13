#include "ssl/sslstream.h"

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

	const int maxSSLretry = 20;

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////
// SSL TCP Stream Buffer
/////////////////////////////////////////////////////////////////////////

SSLStreamBuf::SSLStreamBuf() 
	: sbio_(0), 
	  bio_(0), 
	  ssl_(0),
	  ctx_(&SSLUser::theContext())
{
}

SSLStreamBuf::SSLStreamBuf(SOCKET s, SSL* ssl)
: sbio_(0), bio_(0), ssl_(ssl),ctx_(&SSLUser::theContext())
{
	sock_fd_ = s;
	bio_ = BIO_new(BIO_f_buffer());
	BIO_set_fd(bio_,(int)sock_fd_,BIO_NOCLOSE);
	sbio_= BIO_new(BIO_f_ssl());
	BIO_set_ssl(sbio_, ssl_, BIO_CLOSE);
	BIO_push(bio_, sbio_);
}

SSLStreamBuf::SSLStreamBuf( SSLContext* ctx)
: sbio_(0), bio_(0), ssl_(0),ctx_(ctx)
{

}

SSLStreamBuf::~SSLStreamBuf() 
{
	close();
}

/////////////////////////////////////////////////////////////////////////

bool SSLStreamBuf::connect( const std::string& server, int port )
{
	close();

	bio_ =  BIO_new_ssl_connect(ctx_->ctx());
	BIO_get_ssl(bio_, & ssl_);
	SSL_set_mode(ssl_, SSL_MODE_AUTO_RETRY);
	BIO_set_conn_hostname(bio_, server.c_str() );
	BIO_set_conn_int_port(bio_,&port);

	int max = maxSSLretry;
	while (max)
	{
		max--;
		int r = ::SSL_connect(ssl_);
		switch(SSL_get_error(ssl_,r))
		{
			case SSL_ERROR_WANT_READ:
				continue;
			case SSL_ERROR_WANT_WRITE:
				continue;
			case SSL_ERROR_NONE:
			{
				BIO_get_fd(bio_,&sock_fd_);
				return true;
			}
			case SSL_ERROR_SYSCALL:
				return false;
			case SSL_ERROR_ZERO_RETURN:
			{
				BIO_get_fd(bio_,&sock_fd_);
				return true;
			}
			default:
				return false;
		}
	}
	return false;
}

/////////////////////////////////////////////////////////////////////////
// Server functions
/////////////////////////////////////////////////////////////////////////


bool SSLStreamBuf::listen( int port, int n )
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
    if ( ::bind( sock_fd_, addr_, sizeof(addr_) ) == SOCKET_ERROR )
	{
		//cry();
        return false;
	}

	// start listening on bound port
    if ( ::listen( sock_fd_, n ) != 0)
	{
        return false;
	}
    return true;
}

/////////////////////////////////////////////////////////////////////////

SSLStreamBuf* SSLStreamBuf::accept()
{
	SOCKET s = 0;

	// socket size
	socklen_t sock_addr_size = sizeof(sockaddr_in) ;

	// accept a new socket
    s = ::accept( sock_fd_, addr_,&sock_addr_size);
	if ( !s)
		return 0;

	bio_ = BIO_new_socket((int)s,BIO_NOCLOSE);
	ssl_  = SSL_new(ctx_->ctx());
	SSL_set_mode(ssl_, SSL_MODE_AUTO_RETRY);
	SSL_set_bio(ssl_,bio_,bio_);

	int max = maxSSLretry;
	while (max)
	{
		max--;
		int r = ::SSL_accept(ssl_);
		int e = SSL_get_error(ssl_,r);
		switch(e)
		{
			case SSL_ERROR_WANT_READ:
				continue;
			case SSL_ERROR_WANT_WRITE:
				continue;
			case SSL_ERROR_NONE:
			{
				return new SSLStreamBuf(s,ssl_);
			}
			case SSL_ERROR_SYSCALL:
			{
				return 0;
			}
			case SSL_ERROR_ZERO_RETURN:
			{
				return 0;
			}
			default:
			{
				return 0;
			}
		}
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////

SSLStreamBuf* SSLStreamBuf::accept(SOCKET s)
{
	sbio_ = BIO_new_socket((int)s,BIO_NOCLOSE);
	ssl_  = SSL_new(ctx_->ctx());
	SSL_set_mode(ssl_, SSL_MODE_AUTO_RETRY);
	SSL_set_bio(ssl_,sbio_,sbio_);

	int max = maxSSLretry;
	while (max)
	{
		max--;
		int r = ::SSL_accept(ssl_);
		int e = SSL_get_error(ssl_,r);

		switch(e)
		{
			case SSL_ERROR_WANT_READ:
				continue;
			case SSL_ERROR_WANT_WRITE:
				continue;
			case SSL_ERROR_NONE:
			{
				return new SSLStreamBuf(s,ssl_);
			}
			case SSL_ERROR_SYSCALL:
				break;
			case SSL_ERROR_ZERO_RETURN:
				break;
			default:
				break;
		}
	}

	return nullptr;
}


/////////////////////////////////////////////////////////////////////////

SSLStreamBuf* SSLStreamBuf::accept(mol::TCPStream& tcp)
{
	SSLStreamBuf* sslBuf = accept(tcp.sock_fd());
	if ( sslBuf )
	{
		tcp.sock_fd() = 0;
	}
	return sslBuf;
}

/////////////////////////////////////////////////////////////////////////

bool SSLStreamBuf::close()
{
	if ( sock_fd_ == 0 )
		return true;

	BIO_free_all(bio_);	
	::closesocket(sock_fd_);

	sock_fd_ = 0;
	return true;
}

bool SSLStreamBuf::shutdown( int what )
{
	if (!sock_fd_)
	{
		return true;
	}

	sync();

	int s = SSL_get_shutdown(ssl_);

	int r = 0;
    if ( s == SSL_RECEIVED_SHUTDOWN )
	{
		r = SSL_shutdown(ssl_);
	}
	else
	{
		r = SSL_shutdown(ssl_);
		if ( r == 0 )
		{
			::shutdown(sock_fd_,SD_SEND);
			r = SSL_shutdown(ssl_) == 1;
		}
	}
	return r!=0;
}


/////////////////////////////////////////////////////////////////////////

mol::Cert* SSLStreamBuf::peerCertificate()
{
	if ( ssl_ )
		return new mol::Cert(ssl_);
	return 0;
}

int SSLStreamBuf::verifyCert()
{		
	return SSL_get_verify_result(ssl_);
}

/////////////////////////////////////////////////////////////////////////

IPAddress& SSLStreamBuf::addr()
{
	return addr_;
}

/////////////////////////////////////////////////////////////////////////
// socket impl
/////////////////////////////////////////////////////////////////////////

int SSLStreamBuf::sync()
{
	int r = TCPStreamBufBase::sync();
	BIO_flush(bio_);
	return r;
}

int SSLStreamBuf::buffered_write(char* c, int n)
{
	if ( n == 0 )
		return 0;

	while ( true )
	{
		int err = BIO_write( bio_, c, n );

		if ( err > 0 )
			return 0;

		int e = SSL_get_error(ssl_,err);
		switch(e)
		{
			case SSL_ERROR_WANT_READ:
				continue;
			case SSL_ERROR_WANT_WRITE:
				continue;
			case SSL_ERROR_ZERO_RETURN:
				return 0;
		}
		break; 
	}
	return -1;
}

int SSLStreamBuf::buffered_read(char* c, int n)
{
	//std::cout << "########### buffered reading SSL" << std::endl;

	/*while(true)
	{
		std::cout << "try reading SSL" << std::endl;

		mol::Select sel;
		sel.setRead(sock_fd_);
		sel.setWrite(sock_fd_);
		sel.setEx(sock_fd_);

		if ( sel.select(0,1) < 1 )
			continue;
		if ( sel.isReadSet(sock_fd_) )
			break;
		if ( sel.isExSet(sock_fd_) )
			return 0;
	}
	*/


	int s = BIO_pending(bio_);
/*	if ( (s > 0) && (s<n) )
		n = s;
	else
	{
		if ( s == 0 )
			n = 1;
	}			
*/

	if ( s == 0 ) s = 1;
	if ( s >  n ) s = n;

	//std::cout << "read " << n << std::endl;

	while ( true )
	{
		int len = BIO_read( bio_, c, s );
		if ( len > 0 )
			return len;
		int e = SSL_get_error(ssl_,len);
		switch(e)
		{
			case SSL_ERROR_ZERO_RETURN :
			{
				//std::cout << "SSL_ERROR_ZERO_RETURN" << std::endl;
				//continue; //
				return 0;
			}
			case SSL_ERROR_NONE: 
				return len;
			case SSL_ERROR_WANT_READ:
				continue;
			case SSL_ERROR_WANT_WRITE:
				continue;
		}
		break; 
	}
	return -1;
}


} // end namespace mol
