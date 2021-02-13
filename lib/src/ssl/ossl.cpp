
#include "ssl/ossl.h"
#include "ssl/cert.h"
#include "thread/thread.h"

namespace mol {

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

//mol::Mutex  SSLUser::mutex_[CRYPTO_NUM_LOCKS];
std::string SSLUser::pass_    = "";
//SSLContext  SSLUser::ctx_ ;

///////////////////////////////////////////////////////////////////////////////////
// static callbacks
///////////////////////////////////////////////////////////////////////////////////

mol::Mutex* SSLUser::mutexe() 
{
	static mol::Mutex mutex_[CRYPTO_NUM_LOCKS];
    return mutex_;
}

CRYPTO_dynlock_value* SSLUser::dyn_create_function(const char* file, int line)
{
	return new CRYPTO_dynlock_value;
}

void SSLUser::dyn_lock_function(int mode, CRYPTO_dynlock_value* mutex, const char* file, int line)
{
	if ( mode & CRYPTO_LOCK )
	{
		mutex->mutex.aquire();
	}
	else
	{
		mutex->mutex.release();
	}
}

void SSLUser::dyn_destroy_function(CRYPTO_dynlock_value* mutex,const char* file, int line)
{
	delete mutex;
}

void SSLUser::locking_function(int mode, int n, const char* file, int line )
{
	if ( mode & CRYPTO_LOCK )
	{
		mutexe()[n].aquire();
	}
	else
	{
		mutexe()[n].release();
	}
}

unsigned long SSLUser::id_function()
{
	return mol::Thread::self(); //::GetCurrentThreadId();
}

///////////////////////////////////////////////////////////////////////////////////
// c'tors, d'tor
///////////////////////////////////////////////////////////////////////////////////

SSLUser::SSLUser( )
{
	//static int i = init();		

	pass_="";
	theContext().setPwd("");
}

SSLUser::~SSLUser()
{}

SSLContext& SSLUser::theContext()
{
	static SSLContext  ctx_ ;
	return ctx_;
}

int SSLUser::init()
{
	static int i = 0;
	
	if ( i == 0 )
	{
		//static mol::Mutex mutex;
		//LOCK(mutex);

		if ( i == 0 )
			i = init_();
	}
	return i;
}

int SSLUser::init_()
{
printf("init\n");


	CRYPTO_set_locking_callback(locking_function);
	CRYPTO_set_id_callback(id_function);
	CRYPTO_set_dynlock_create_callback(dyn_create_function);
	CRYPTO_set_dynlock_lock_callback(dyn_lock_function);
	CRYPTO_set_dynlock_destroy_callback(dyn_destroy_function);
	SSL_library_init(); 
	ERR_load_BIO_strings();
//	SSL_load_error_strings();
	OpenSSL_add_all_algorithms();
printf("init\n");
	return 1;
}

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////

Cert::Cert()
:cert_(0)
{
}

Cert::Cert(SSL* ssl)
:cert_(0)
{
	cert_ = SSL_get_peer_certificate(ssl);	
}

Cert::Cert(X509* x)
:cert_(x)
{}

Cert::~Cert()
{
	if ( cert_ )
	{
		X509_free(cert_);
		cert_ = 0;
	}
}

long Cert::getVersion()
{
	return X509_get_version(cert_);
}


std::string Cert::getNotBefore()
{
	return (char*)(X509_get_notBefore(cert_)->data);
}

std::string Cert::getNotAfter()
{
	return (char*)(X509_get_notAfter(cert_)->data);
}

std::string Cert::getIssuerName()
{
	char* buf = X509_NAME_oneline( X509_get_issuer_name(cert_),0,0);
	std::string ret = std::string(buf);
	delete buf;
	return ret;
}

std::string Cert::getSubjectName()
{
	char* buf = X509_NAME_oneline( X509_get_subject_name(cert_),0,0);
	std::string ret = std::string(buf);
	delete buf;
	return ret;
}

std::string Cert::toString()
{
	std::string ret;

    BIO *mem = BIO_new(BIO_s_mem());

	if(PEM_write_bio_X509(mem,cert_) != 1)
		return "";

	char* c = 0;
	int len = BIO_get_mem_data(mem,&c);
	if ( c && len )
	{
		ret = std::string(c,len);
	}
	BIO_free(mem);

	return ret;
}


void Cert::fromString( const std::string cert )
{
	BIO *mem;
	mem = BIO_new_mem_buf( (void*)(cert.c_str()), (int)cert.size() );

	if ( !PEM_read_bio_X509(mem,&cert_,0,NULL ) )
		throw mol::X("Can't read certificate from mem");

	BIO_free(mem);
}

bool Cert::load(const std::string& filename)
{
	if ( cert_ )
			X509_free(cert_);
	cert_ = 0;

	FILE* fp = 0;

	if (!(fp=fopen(filename.c_str(),"r")))
		return false;

	if (!(cert_ = PEM_read_X509(fp,NULL,NULL,NULL)))
		return false;

	fclose(fp);

	return true;
}

bool Cert::load(const std::string& filename, const std::string& pwd)
{
	if ( cert_ )
			X509_free(cert_);
	cert_ = 0;

	FILE* fp = 0;

	if (!(fp=fopen(filename.c_str(),"r")))
		return false;

	if (!(cert_ = PEM_read_X509(fp,NULL,NULL,((void*)pwd.c_str()))))
		return false;

	fclose(fp);

	return true;
}

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////


int SSLContext::password_cb(char *buf,int num, int rwflag,void *userdata)
{
	SSLContext* pThis = (SSLContext*)userdata;
	strcpy(buf,pThis->getPwd().c_str());
	return( (int)pThis->getPwd().size() );
}

SSLContext::SSLContext( )
:pass_(SSLUser::pass_),key_(0),cert_(0)
{
	static int i = SSLUser::init();		
	raw_ctx_ = SSL_CTX_new(SSLv23_method());
	SSL_CTX_set_default_passwd_cb(raw_ctx_,password_cb);
	SSL_CTX_set_default_passwd_cb_userdata(raw_ctx_,(void*)this);
}

SSLContext::SSLContext( Cert& cr, PrivateKey& key )
:pass_(SSLUser::pass_),key_(0),cert_(0)
{
	static int i = SSLUser::init();		
	raw_ctx_ = SSL_CTX_new(SSLv23_method());
	SSL_CTX_set_default_passwd_cb(raw_ctx_,password_cb);
	SSL_CTX_set_default_passwd_cb_userdata(raw_ctx_,(void*)this);
	int r = SSL_CTX_use_certificate(raw_ctx_,cr.cert());
	r = SSL_CTX_use_PrivateKey(raw_ctx_,key.key());
}

SSLContext::~SSLContext()
{
	if (key_)
		EVP_PKEY_free(key_);
	if ( cert_ )
	{
		X509_free(cert_);
		cert_ = 0;
	}
	SSL_CTX_free(raw_ctx_);
}

void SSLContext::setKey( const std::string key )
{
	BIO *mem;
	mem = BIO_new_mem_buf( (void*)(key.c_str()), (int)key.size() );

	if ( !PEM_read_bio_PrivateKey(mem,&key_,&SSLContext::password_cb,(void*)this) )
		throw mol::X("Can't read private key from mem");

	if ( !SSL_CTX_use_PrivateKey(raw_ctx_,key_) )
		throw mol::X("Can't set private key");

	BIO_free(mem);
}

void SSLContext::setCert( const std::string cert )
{
	BIO *mem;
	mem = BIO_new_mem_buf( (void*)(cert.c_str()), (int)cert.size() );

	if ( !PEM_read_bio_X509(mem,&cert_,&SSLContext::password_cb,(void*)this) )
		throw mol::X("Can't read certificate from mem");

	if ( !SSL_CTX_use_certificate(raw_ctx_,cert_) )
		throw mol::X("Can't set certificate");

	BIO_free(mem);
}

void SSLContext::loadKeys( const std::string& keyfile )
{
	if(!(SSL_CTX_use_certificate_chain_file(raw_ctx_,	keyfile.c_str())))
		throw mol::X("Can't read certificate file");

	if(!(SSL_CTX_use_PrivateKey_file(raw_ctx_,keyfile.c_str(),SSL_FILETYPE_PEM)))
		throw mol::X("Can't read key file");
}

void SSLContext::loadCAs(const std::string& store)
{
	if(!(SSL_CTX_load_verify_locations(raw_ctx_, store.c_str(),0)))
		throw mol::X("Can't read CA list");
}


void SSLContext::setCADir(const std::string& store)
{
	if(!(SSL_CTX_load_verify_locations(raw_ctx_, 0,store.c_str() )))
		throw mol::X("Can't read CA list");
}

void SSLContext::loadDH(const std::string& dh_file)
{
	DH *ret=0;
	BIO *bio;
	if ((bio=BIO_new_file(dh_file.c_str(),"r")) == NULL)
		throw mol::X("Couldn't open DH file");

	ret=PEM_read_bio_DHparams(bio,NULL,NULL,NULL);
	BIO_free(bio);
	if(SSL_CTX_set_tmp_dh(raw_ctx_,ret)<0)
		throw mol::X("Couldn't set DH parameters");
}

void SSLContext::set_session_id( const std::string& id )
{
   if (SSL_CTX_set_session_id_context(raw_ctx_, (const unsigned char*)(id.c_str()), (int)id.size() ) < 0 )
	   throw mol::X("set session id failed");
}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
/*
SSLSocket::SSLSocket()
: sbio_(0), bio_(0), ssl_(0),ctx_(&SSLUser::theContext())
{}

SSLSocket::SSLSocket(SSLContext& ctx)
: sbio_(0), bio_(0), ssl_(0),ctx_(&ctx)
{}

SSLSocket::SSLSocket(mol::TCPsocket& s)
: sbio_(0), bio_(0), ssl_(0), mol::TCPsocket(s),ctx_(&SSLUser::theContext())
{}

SSLSocket::SSLSocket(SSLContext& ctx, mol::TCPsocket& s)
: sbio_(0), bio_(0), ssl_(0), mol::TCPsocket(s),ctx_(&ctx)
{}

SSLSocket::SSLSocket(SSLContext& ctx,SOCKET s, SSL* ssl)
: sbio_(0), bio_(0), ssl_(ssl), mol::TCPsocket(s),ctx_(&ctx)
{
	bio_ = BIO_new(BIO_f_buffer());
	sbio_= BIO_new(BIO_f_ssl());
	BIO_set_ssl(sbio_, ssl_, BIO_CLOSE);
	BIO_push(bio_, sbio_);
}

SSLSocket::~SSLSocket()
{}

// do a SSL handshake over already connected socket
bool SSLSocket::SSL_connect( const std::string& host, int port  )
{
	bio_ =  BIO_new_ssl_connect(ctx_->ctx());
	BIO_set_fd(bio_,sockFd(),BIO_NOCLOSE);
	BIO_get_ssl(bio_, & ssl_);
	//SSL_set_mode(ssl_, SSL_MODE_AUTO_RETRY);
	BIO_set_conn_hostname(bio_, host.c_str() );
	BIO_set_conn_int_port(bio_,&port);

	while (true)
	{
		int r = ::SSL_connect(ssl_);
		switch(SSL_get_error(ssl_,r))
		{
			case SSL_ERROR_WANT_READ:
				continue;
			case SSL_ERROR_WANT_WRITE:
				continue;
			case SSL_ERROR_NONE:
				return true;
			case SSL_ERROR_SYSCALL:
				return false;
			case SSL_ERROR_ZERO_RETURN:
				return true;
			default:
				return false;
		}
	}
}

// Check the certificate 
int SSLSocket::SSL_verifyCert()
{		
	return SSL_get_verify_result(ssl_);
}

// do a SSL Accept on the server 
SSLSocket*  SSLSocket::SSL_accept( SOCKET s ) 
{
	sbio_ = BIO_new_socket(s,BIO_NOCLOSE);
	ssl_  = SSL_new(ctx_->ctx());
	//SSL_set_mode(ssl_, SSL_MODE_AUTO_RETRY);
	SSL_set_bio(ssl_,sbio_,sbio_);

	while (true)
	{
		int r = ::SSL_accept(ssl_);
		switch(SSL_get_error(ssl_,r))
		{
			case SSL_ERROR_WANT_READ:
				continue;
			case SSL_ERROR_WANT_WRITE:
				continue;
			case SSL_ERROR_NONE:
				return new SSLSocket(*ctx_,s,ssl_);
			case SSL_ERROR_SYSCALL:
				return false;
			case SSL_ERROR_ZERO_RETURN:
				return false;
			default:
				return false;
		}
	}
}

// i/o
int SSLSocket::read( std::string& str )
{
	str = "";
	char buf[1024];
	int r = 0;
	bEof_ = true;
	while( true )
	{
		int r = BIO_read(bio_, buf, 1023);
		switch(SSL_get_error(ssl_,r))
		{
			case SSL_ERROR_NONE: 
			{ 
				std::string tmp(buf,r);
				str += tmp;
				break;
			}
			case SSL_ERROR_WANT_READ:
				continue;
			case SSL_ERROR_WANT_WRITE:
				continue;
			case SSL_ERROR_SYSCALL: 
				return 0;
			case SSL_ERROR_ZERO_RETURN:
			default:
			{ 
				return 0;
			}
		}
	}
	return str.size();
}

int SSLSocket::read( std::string& str, int n )
{
	str = "";
	int len = 0;
	int received = 0;
	char* buf = new char[n];

	while ( received < n )
	{
		len = BIO_read( bio_, buf+received, n-received );
		switch(SSL_get_error(ssl_,len))
		{
			case SSL_ERROR_NONE: 
			{ 
				received += len;
				continue;
			}
			case SSL_ERROR_WANT_READ:
				continue;
			case SSL_ERROR_WANT_WRITE:
				continue;
			case SSL_ERROR_SYSCALL: 
				len = 0;
			case SSL_ERROR_ZERO_RETURN:
			default:
			{ 
				len = 0;
			}
		}
		break;
	}
	if ( received )
		str = std::string(buf,received);
	if ( received < n )
		bEof_ = true;
	delete[] buf;
	return len;
}

int SSLSocket::readLine( std::string& line )
{
	line = "";
	char buf[1];
	int len      = 0;
	int received = 0;

	while ( true )
	{
		len = BIO_read(bio_, buf,1);
		switch(SSL_get_error(ssl_,len))
		{
			case SSL_ERROR_NONE:
			{
				received++;
				std::string tmp(buf,1);
				line += tmp;
				if ( tmp == "\n" )
					return 1;
				continue;
			}
			case SSL_ERROR_WANT_READ:
				continue;
			case SSL_ERROR_WANT_WRITE:
				continue;
			case SSL_ERROR_SYSCALL:
			{
					unsigned int xx=::WSAGetLastError();
					char buf[256];	
					wsprintf(buf,"%i",xx);
					//::MessageBox(0,buf,"err",0);
				break;
			}
			case SSL_ERROR_ZERO_RETURN:
			default: break;
		}
		break;
	}
	bEof_ = true;
	return 0;
}

int SSLSocket::write( const std::string& c )
{
	return BIO_write(bio_, c.c_str(), c.size() );
}

void SSLSocket::sslShutdown()
{
	int r = 0;
	if( (r = BIO_flush(bio_)) < 0 )
		return;

	r=SSL_shutdown(ssl_);
	if(!r)
	{
		shutdown(SD_SEND);
		mol::Selector sel;
		sel.setRead(*this);
		sel.select(500,0);
		if (sel.isReadSet(*this))
		{
			char buf[2];
			mol::Socket::recv(buf,1);
			r=SSL_shutdown(ssl_);
		}
	}
	char buf[256];
	switch(r)
	{  
		case 1: break; // * Success * /
		default:
		{
			int x = SSL_get_error(ssl_,r);
			switch(x)
			{
				case SSL_ERROR_NONE:
				case SSL_ERROR_SYSCALL:
				{
					unsigned int xx=::WSAGetLastError();
	
					wsprintf(buf,"%i",xx);
					//::MessageBox(0,buf,"err",0);
					break;
				}
				default:
				{
					// any other error - assume bio alreday dead
					break ;
				}
			}				
		}
	}
	BIO_free_all(bio_);	
}
*/



} // end namespace mol
