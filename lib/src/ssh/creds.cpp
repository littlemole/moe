#include "ssh/creds.h"


namespace mol {
namespace ssh {



SecureCredentials::SecureCredentials( const std::wstring& h, int p, const mol::ssh::string& u, const mol::ssh::string& pass)
		: host(h),port(p)
{

	EncryptedMap::MapType map;
	map.insert( std::make_pair(mol::ssh::string("user"),u));
	map.insert( std::make_pair(mol::ssh::string("pwd"), pass));

	secure_.encrypt(map);
}

SecureCredentials::SecureCredentials( const SecureCredentials& rhs )
	: host(rhs.host), port(rhs.port), secure_(rhs.secure_)
{}

SecureCredentials::SecureCredentials( SecureCredentials&& rhs )
	: host(rhs.host), port(rhs.port), secure_(rhs.secure_)
{}


SecureCredentials::~SecureCredentials()
{
}


void SecureCredentials::decrypt( mol::ssh::string& u, mol::ssh::string& pass )
{
	EncryptedMap::MapType map = secure_.decrypt();

	if ( map.count("user") > 0 )
		u = map["user"];

	if ( map.count("pwd") > 0 )
		pass = map["pwd"];
}

SecureCredentials& SecureCredentials::operator=( const SecureCredentials& rhs )
{
	if ( this == &rhs )
	{
		return *this;
	}

	host = rhs.host;
	port = rhs.port;
	secure_ = rhs.secure_;
	return *this;
}


SecureCredentials& SecureCredentials::operator=( SecureCredentials&& rhs )
{
	if ( this == &rhs )
	{
		return *this;
	}

	host = rhs.host;
	port = rhs.port;
	secure_ = rhs.secure_;
	return *this;
}

} // end namespace ssh
} // end namespace mol
