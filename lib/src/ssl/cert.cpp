#include "ssl/cert.h"
#include "ssl/ossl.h"

namespace mol {

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

PrivateKey::PrivateKey()
: pKey_(0)
{}

PrivateKey::~PrivateKey()
{
	if ( pKey_ )
		EVP_PKEY_free(pKey_);
}

bool PrivateKey::load(const std::string& file, const std::string& pwd )
{
	if ( pKey_ )
		EVP_PKEY_free(pKey_);
	pKey_ = 0;

	FILE* fp = 0;
	if (!(fp = fopen(file.c_str(),"r")))
		return false;

	if ( pwd.size() != 0 )
	{
		if (!(pKey_ = PEM_read_PrivateKey(fp,NULL,NULL,(void*)(pwd.c_str()))))
			return false;
	}
	else
	{
		if (!(pKey_ = PEM_read_PrivateKey(fp,NULL,NULL,0)) )
			return false;
	}

	fclose(fp);

	if (EVP_PKEY_type(pKey_->type)==EVP_PKEY_DSA)
		digest_ = EVP_dss1();
	else if (EVP_PKEY_type(pKey_->type)==EVP_PKEY_RSA)
		digest_ = EVP_sha1();
	else
		return false;

	return true;
}

bool PrivateKey::output(const std::string& filename, const std::string& mode,const std::string& pwd  )
{
	FILE* fp = 0;
	if (!(fp = fopen(filename.c_str(),mode.c_str())))
		return false;

	if ( pwd.size() > 0 )
	{
		if ( PEM_write_PrivateKey( fp, pKey_, EVP_des_ede3_cbc(), NULL,0,NULL,(void*)(pwd.c_str()))!=1)
			return false;
	}
	else
	{
		if ( PEM_write_PrivateKey( fp, pKey_, 0, NULL,0,NULL,0)!=1)
			return false;
	}
		
	fclose(fp);
	return true;
}

bool PrivateKey::write(const std::string& filename,const std::string& pwd )
{
	return output(filename, "w", pwd);
}

bool PrivateKey::append(const std::string& filename,const std::string& pwd )
{
	return output(filename, "a+", pwd);
}

std::string PrivateKey::toString()
{
	std::string ret;

    BIO *mem = BIO_new(BIO_s_mem());

	if ( PEM_write_bio_PrivateKey(mem,pKey_,0,0,0,0,0) != 1 )
		return false;

	char* c = 0;
	int len = BIO_get_mem_data(mem,&c);
	if ( c && len )
	{
		ret = std::string(c,len);
	}
	BIO_free(mem);

	return ret;
}

std::string PrivateKey::toString(const std::string& pwd)
{
	std::string ret;

    BIO *mem = BIO_new(BIO_s_mem());

	if ( PEM_write_bio_PrivateKey(mem,pKey_,EVP_des_ede3_cbc(),0,0,0,((void*)pwd.c_str())) != 1 )
		return false;

	char* c = 0;
	int len = BIO_get_mem_data(mem,&c);
	if ( c && len )
	{
		ret = std::string(c,len);
	}
	BIO_free(mem);

	return ret;
}

bool PrivateKey::fromString(const std::string& key,const std::string& pwd)
{
	BIO *mem;
	mem = BIO_new_mem_buf( (void*)(key.c_str()), (int)key.size() );

	EVP_PKEY* pkey = PEM_read_bio_PrivateKey(mem,0,0,((void*)pwd.c_str()) );
	if ( !pkey )
		throw mol::X("Can't read key from mem");

	pKey_ = pkey;

	BIO_free(mem);

	if (EVP_PKEY_type(pKey_->type)==EVP_PKEY_DSA)
		digest_ = EVP_dss1();
	else if (EVP_PKEY_type(pKey_->type)==EVP_PKEY_RSA)
		digest_ = EVP_sha1();
	else
		return false;

	return true;
}

bool PrivateKey::fromString(const std::string& key)
{
	BIO *mem;
	mem = BIO_new_mem_buf( (void*)(key.c_str()), (int)key.size() );

	EVP_PKEY* pkey = PEM_read_bio_PrivateKey(mem,0,0,0 );
	if ( !pkey )
		throw mol::X("Can't read key from mem");

	pKey_ = pkey;

	BIO_free(mem);

	if (EVP_PKEY_type(pKey_->type)==EVP_PKEY_DSA)
		digest_ = EVP_dss1();
	else if (EVP_PKEY_type(pKey_->type)==EVP_PKEY_RSA)
		digest_ = EVP_sha1();
	else
		return false;

	return true;
}

bool PrivateKey::generate(const std::string& pwd)
{
	if ( pKey_ )
		EVP_PKEY_free(pKey_);
	pKey_ = 0;

	pKey_ = EVP_PKEY_new();

	if (!pKey_)
		return false;

	RSA* rsa;

	rsa = RSA_generate_key(2048,3,0,0);

	if (!rsa )
		return false;

//	BIO *mem;
	BIO *mem = BIO_new(BIO_s_mem());

	int r = PEM_write_bio_RSAPrivateKey(mem,rsa,EVP_des_ede3_cbc(),0,0,0,(void*)(pwd.c_str()));

	if (!r)
		return false;

	BIO_seek(mem,0);

	EVP_PKEY* pkey = PEM_read_bio_PrivateKey(mem,0,0,(void*)(pwd.c_str()) );
	if ( !pkey )
		throw mol::X("Can't read key from mem");

	pKey_ = pkey;

	BIO_free(mem);


	if (EVP_PKEY_type(pKey_->type)==EVP_PKEY_DSA)
		digest_ = EVP_dss1();
	else if (EVP_PKEY_type(pKey_->type)==EVP_PKEY_RSA)
		digest_ = EVP_sha1();
	else
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////


CertRequest::CertRequest()
:req_(0),subj_(0)
{}

CertRequest::~CertRequest()
{
	if ( req_)
		X509_REQ_free(req_);
	if ( subj_)
		X509_NAME_free(subj_);
}

EVP_PKEY* CertRequest::verify()
{
	EVP_PKEY* pKey = 0;
	if (!(pKey = X509_REQ_get_pubkey(req_)))
		return 0;
	if (X509_REQ_verify(req_,pKey) != 1 )
		return 0;
	return pKey;
}

bool CertRequest::sign( PrivateKey& key )
{	
	if ( req_)
		X509_REQ_free(req_);
	req_ = 0;

	if ( subj_)
		X509_NAME_free(subj_);
	subj_ = 0;

	if (!(req_=X509_REQ_new()))
		return false;

	int r = X509_REQ_set_pubkey(req_, key.key() );

	subj_ = X509_NAME_new();
	if ( subj_ == 0)
		return false;

	nid_     = 0;
	if ( countryName.size() > 0 )
		addEntry("countryName",countryName);
	if ( stateOrProvinceName.size() > 0 )
		addEntry("stateOrProvinceName",stateOrProvinceName);
	if ( localityName.size() > 0 )
		addEntry("localityName",localityName);
	if ( organizationName.size() > 0 )
		addEntry("organizationName",organizationName);
	if ( organizationalUnitName.size() > 0 )
		addEntry("organizationalUnitName",organizationalUnitName);

	addEntry("commonName",commonName);
	addExt("subjectAltName",FQN);

	if ( X509_REQ_set_subject_name(req_,subj_) != 1 )
		return false;

	if ( !(X509_REQ_sign(req_, key.key(), key.digest() ))) //digest_)))
		return false;

	return true;
}

bool CertRequest::write( const std::string& filename )
{
	FILE* fp = 0;

	if (!(fp = fopen(filename.c_str(),"w")))
		return false;

	if ( PEM_write_X509_REQ(fp,req_) != 1 )
		return false;

	fclose(fp);

	return true;
}

bool CertRequest::load(const std::string& filename)
{
	if ( req_)
		X509_REQ_free(req_);
	req_ = 0;

	if ( subj_)
		X509_NAME_free(subj_);
	subj_ = 0;

	FILE* fp = 0;

	if (!(fp=fopen(filename.c_str(),"r")))
		return false;

	if (!(req_=PEM_read_X509_REQ(fp,NULL,NULL,NULL)))
		return false;

	fclose(fp);

	return true;
}

void CertRequest::addEntry(const std::string& key, const std::string& val)
{
	X509_NAME_ENTRY* ent;
	if ((nid_ = OBJ_txt2nid((char*)(key.c_str()))) == NID_undef)
		throw mol::X("error on lookup ");
			
	if (!(ent = X509_NAME_ENTRY_create_by_NID(NULL,nid_,MBSTRING_ASC,(unsigned char*)(val.c_str()),-1)))
		throw mol::X("error create name from nid ");

	if ( X509_NAME_add_entry(subj_,ent,-1,0) != 1 )
		throw mol::X("error adding entry");
	nid_++;
}

void CertRequest::addExt(const std::string& key, const std::string& val)
{
	X509_EXTENSION* ext;
	STACK_OF(X509_EXTENSION) *extlist;
	
	extlist = sk_X509_EXTENSION_new_null();

	if (!(ext = X509V3_EXT_conf(NULL,NULL,(char*)(key.c_str()),(char*)(val.c_str()))))
		throw mol::X("error create extension");

	sk_X509_EXTENSION_push(extlist,ext);

	if(!X509_REQ_add_extensions(req_,extlist))
		throw mol::X("error adding extension");

	sk_X509_EXTENSION_pop_free(extlist,X509_EXTENSION_free);
}


///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

	
CertificateBuilder::CertificateBuilder()
:cert_(0)
{}

CertificateBuilder::CertificateBuilder(SSL* ssl)
:cert_(0)
{
	cert_ = SSL_get_peer_certificate(ssl);	
}

CertificateBuilder::~CertificateBuilder()
{
	//if ( cert_ )
	//	X509_free(cert_);

	
}







bool CertificateBuilder::load(const std::string& filename)
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

bool CertificateBuilder::output( const std::string& filename, const std::string& mode )
{
	FILE* fp=0;
	if (!(fp = fopen(filename.c_str(),mode.c_str())))
		return false;
	if(PEM_write_X509(fp,cert_) != 1)
		return false;
	fclose(fp);
	return true;
}

bool CertificateBuilder::write( const std::string& filename)
{
	return output(filename,"w");
}

bool CertificateBuilder::append( const std::string& filename)
{
	return output(filename,"a+");
}

long CertificateBuilder::serial = 1;


bool CertificateBuilder::sign( CertRequest& req, Cert& CA, PrivateKey& key, int days)
{

		if ( cert_ )
			X509_free(cert_);
		cert_ = 0;

		if(!(cert_=X509_new()))
			return false;

		if( X509_set_version(cert_,2L) != 1 )
			return false;

		ASN1_INTEGER_set(X509_get_serialNumber(cert_),serial++);

		X509_name_st* name = 0;
		if (!(name = X509_REQ_get_subject_name(req.req())))
			return false;

		if(X509_set_subject_name(cert_, name) != 1 )
			return false;

		if (!(name = X509_get_subject_name(CA.cert())))
			return false;

		if(X509_set_issuer_name(cert_, name) != 1 )
			return false;

		if (!(X509_set_pubkey(cert_, req.verify() )))
			return false;

		int secs = (60*60*24*days);
		if (!(X509_gmtime_adj(X509_get_notBefore(cert_),0)))
			return false;

		if(!(X509_gmtime_adj(X509_get_notAfter(cert_),secs)))
			return false;

		X509V3_set_ctx(&ctx_,CA.cert(),cert_,NULL,NULL,0);

		addExt("basicConstraints",basicConstraints);
		addExt("nsComment",nsComment);
		addExt("subjectKeyIdentifier",subjectKeyIdentifier);
		addExt("authorityKeyIdentifier",authorityKeyIdentifier);
		addExt("keyUsage",keyUsage);

		STACK_OF(X509_EXTENSION)* req_exts;
		if (!(req_exts = X509_REQ_get_extensions(req.req())))
			return false;

		int subjAltName_pos         = X509v3_get_ext_by_NID(req_exts,OBJ_sn2nid("subjectAltName"),-1);
		X509_EXTENSION* subjAltName = X509v3_get_ext(req_exts,subjAltName_pos);

		if(!X509_add_ext(cert_,subjAltName,-1))
			return false;

		if(!X509_sign(cert_, key.key(), key.digest()))
			return false;

		return true;
}

bool CertificateBuilder::addExt(const std::string& key, const std::string& val)
{
	X509_EXTENSION* ext = 0;
	if(!(ext = X509V3_EXT_conf(NULL, &ctx_, (char*)(key.c_str()), (char*)(val.c_str()))))
		return false;
	if(!X509_add_ext(cert_, ext, -1))
		return false;
	X509_EXTENSION_free(ext);
	return true;
}



void CertificateBuilder::fromString( const std::string cert )
{
	BIO *mem;
	mem = BIO_new_mem_buf( (void*)(cert.c_str()), (int)cert.size() );

	if ( !PEM_read_bio_X509(mem,&cert_,0,NULL ) )
		throw mol::X("Can't read certificate from mem");

	BIO_free(mem);
}

} // end namespace mol
