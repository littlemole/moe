#ifndef MOL_SSL_CERT_DEF_GUARD_
#define MOL_SSL_CERT_DEF_GUARD_

#include "util/x.h"
#include "tcp/sockets.h"
#include "thread/sync.h"

#include "openssl/ssl.h"
#include "openssl/bio.h"
#include "openssl/err.h"
#include "openssl/x509.h"
#include "openssl/x509v3.h"
//#include "openssl/ossl_typ.h"
#include "openssl/pem.h"



namespace mol {

class PrivateKey
{
public:
	PrivateKey();
	~PrivateKey();

	bool load(const std::string& file, const std::string& pwd );

	bool write (const std::string& filename, const std::string& pwd );
	bool append(const std::string& filename, const std::string& pwd );

	EVP_PKEY* key()        { return pKey_;   }
	const EVP_MD* digest() { return digest_; }

	std::string toString();
	std::string toString(const std::string& pwd);
	bool fromString(const std::string& key);
	bool fromString(const std::string& key,const std::string& pwd);

	bool generate(const std::string& pwd);

private:
	bool output(const std::string& filename, const std::string& mode, const std::string& pwd );

	EVP_PKEY*     pKey_;
	const EVP_MD* digest_;
};

class CertRequest
{
public:
	CertRequest();
	~CertRequest();

	EVP_PKEY* verify();

	bool sign( PrivateKey& key );

	bool write( const std::string& filename );
	bool load(const std::string& filename);

	//request properties
	std::string countryName;
	std::string stateOrProvinceName;
	std::string localityName;
	std::string organizationName;
	std::string organizationalUnitName;
	std::string commonName;
	std::string FQN;

	// raw request
	X509_REQ* req()      { return req_;  }
	X509_name_st* subj() { return subj_; }

private:
	void addEntry(const std::string& key, const std::string& val);
	void addExt(const std::string& key, const std::string& val);

	int				nid_;
	X509_name_st *  subj_;
	X509_REQ*		req_;
};

class Cert;

class CertificateBuilder
{
public:
	CertificateBuilder();
	CertificateBuilder(SSL* ssl);
	~CertificateBuilder();

	bool sign( CertRequest& req, Cert& CA, PrivateKey& key, int days);

	bool load(const std::string& filename);
	bool write( const std::string& filename);
	bool append( const std::string& filename);
	void fromString( const std::string cert );

	std::string basicConstraints;
	std::string nsComment;
	std::string subjectKeyIdentifier;
	std::string authorityKeyIdentifier;
	std::string keyUsage;

	X509* cert()		{ return cert_; }
	X509V3_CTX& ctx()	{ return ctx_;  }

	static void setSerial(long s) { serial = s; };

private:
	bool output( const std::string& filename, const std::string& mode );
	bool addExt(const std::string& key, const std::string& val);

	X509*       cert_;
	X509V3_CTX  ctx_;

	static long serial;
};



} // end namespace mol

#endif
