#ifndef MOL_SSL_DEF_GUARD_
#define MOL_SSL_DEF_GUARD_

#include "openssl/ssl.h"
#include "openssl/bio.h"
#include "openssl/err.h"
#include "openssl/x509.h"
#include "openssl/x509v3.h"
//#include "openssl/ossl_typ.h"
#include "openssl/pem.h"
#include "util/x.h"
#include "tcp/sockets.h"
#include "thread/sync.h"

struct CRYPTO_dynlock_value
{
	mol::Mutex mutex;
};

namespace mol {

class PrivateKey;
class SSLContext;


class SSLEx : public mol::TcpEx
{
public:
	SSLEx() {}
	SSLEx(const char* const& what)
		: mol::TcpEx(what)
	{}
};

class SSLUser
{
friend class SSLContext;
public:
	SSLUser( );
	~SSLUser();

	static SSLContext&  theContext();

	static CRYPTO_dynlock_value* dyn_create_function(const char* file, int line);
	static void dyn_lock_function(int mode, CRYPTO_dynlock_value* mutex, const char* file, int line);
	static void dyn_destroy_function(CRYPTO_dynlock_value* mutex,const char* file, int line);
	static void locking_function(int mode, int n, const char* file, int line );
	static unsigned long id_function();
	static mol::Mutex* mutexe();//[CRYPTO_NUM_LOCKS];

private:
	//static SSLContext ctx_;
	static std::string pass_;
	//static mol::Mutex mutex_[CRYPTO_NUM_LOCKS];

	static int init();
	static int init_();
};

class Cert
{
public:
	Cert();
	Cert(X509* x);
	Cert(SSL* ssl);
	~Cert();


	long getVersion();
	std::string getNotBefore();
	std::string getNotAfter();
	std::string getIssuerName();
	std::string getSubjectName();

	std::string toString();
	void fromString( const std::string cert );

	bool load(const std::string& filename);
	bool load(const std::string& filename,const std::string& pwd);

	X509* cert()		{ return cert_; }

private:
	X509*       cert_;
};

class SSLContext
{
public:
	SSLContext( );
	SSLContext( Cert& cr , PrivateKey& key);
	~SSLContext();
	
	void setKey( const std::string key );
	void setCert( const std::string cert );
	void loadCAs(const std::string& store);
	void setCADir(const std::string& store);
	void loadKeys( const std::string& keyfile );
	void loadDH(const std::string& dh_file);
	void set_session_id( const std::string& id );

	SSL_CTX* ctx() { return raw_ctx_; }

	void setPwd(const std::string& pwd)	{ pass_ = pwd;	}
	const std::string& getPwd()			{ return pass_;	}

	static int password_cb(char *buf,int num, int rwflag,void *userdata);

private:
	EVP_PKEY* key_;
	SSL_CTX* raw_ctx_;
	std::string pass_;
	X509*       cert_;
};

/*
class SSLSocket : public mol::TCPsocket 
{
public:
	SSLSocket();
	SSLSocket(SSLContext& ctx);
	SSLSocket(mol::TCPsocket& s);
	SSLSocket(SSLContext& ctx, mol::TCPsocket& s);
	SSLSocket(SSLContext& ctx, SOCKET s, SSL* ssl);
	~SSLSocket();

	bool SSL_connect( const std::string& host, int port = 443 );
	int SSL_verifyCert();
	int SSL_pending() { return ::SSL_pending(ssl_); }

	SSLSocket*  SSL_accept( SOCKET s );

	virtual int read( std::string& str );
	virtual int read( std::string& str, int n );
	virtual int readLine( std::string& line );
	virtual int write( const std::string& c );

	void sslShutdown();

private:
	BIO* bio_;
	BIO* sbio_;
	SSL* ssl_;
	SSLContext* ctx_;
};
*/

} // end namespace mol
#endif

