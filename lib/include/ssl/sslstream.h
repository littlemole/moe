#ifndef MOL_SSL_STREAM_DEF_GUARD_DEF_
#define MOL_SSL_STREAM_DEF_GUARD_DEF_

#include "tcp/tcpstream.h"
#include "ssl/ossl.h"

namespace mol {

class Cert;
/////////////////////////////////////////////////////////////////////////
// SSL TCP StreamBuf
/////////////////////////////////////////////////////////////////////////

class SSLStreamBuf 
	: public TCPStreamBufBase
{
public:
	SSLStreamBuf();
	SSLStreamBuf(SOCKET s, SSL* ssl);
	SSLStreamBuf(SSLContext* ctx);
	~SSLStreamBuf();

	// SSL-TCP operations
	bool connect( const std::string& server, int port );
	bool close();
	bool shutdown( int what = SD_SEND);

	// get IP address
	IPAddress& addr();

	// get cert
	mol::Cert* peerCertificate();
	//verify cert
	int verifyCert();

	// server functions
	//bool loadCert( const std::string& cert, const std::string& pwd );
	bool listen( int port, int n );
	SSLStreamBuf* accept();
	SSLStreamBuf* accept(SOCKET s);
	SSLStreamBuf* accept(mol::TCPStream& tcp);
protected:

	int sync();

private:

	// openssl stuff
	BIO* bio_;
	BIO* sbio_;
	SSL* ssl_;
	SSLContext* ctx_;

	// prohibit copying and assingment
    SSLStreamBuf(const SSLStreamBuf&);
    SSLStreamBuf& operator = (const SSLStreamBuf&);

	// IOStream to socket stream conversion impl
	int buffered_write(char* c, int n );
	int buffered_read (char* c, int n);
};


/////////////////////////////////////////////////////////////////////////

typedef basic_TCPStream<SSLStreamBuf> SSLStream;

/////////////////////////////////////////////////////////////////////////

} // end namespace mol

#endif
