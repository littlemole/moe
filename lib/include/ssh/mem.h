#ifndef _MOL_COM_DLL_SSH_MEM_DEF_DEFINE_GUARD_
#define _MOL_COM_DLL_SSH_MEM_DEF_DEFINE_GUARD_

#include "str.h"
#include <map>

namespace mol {
namespace ssh {

class EncryptedMemory
{
public:

	EncryptedMemory();
	EncryptedMemory(const EncryptedMemory& rhs);
	EncryptedMemory(EncryptedMemory&& rhs);
	~EncryptedMemory();
	void dispose();

	size_t encrypt( void* data, size_t size, DWORD flags = CRYPTPROTECTMEMORY_SAME_LOGON);
	mol::ssh::string decrypt( DWORD flags = CRYPTPROTECTMEMORY_SAME_LOGON);	

	void* data();
	size_t size();

	EncryptedMemory& operator=(const EncryptedMemory& rhs);
	EncryptedMemory& operator=(EncryptedMemory&& rhs);
private:

	size_t encryptVista( void* data, size_t size, DWORD flags = CRYPTPROTECTMEMORY_SAME_LOGON);
	mol::ssh::string decryptVista( DWORD flags = CRYPTPROTECTMEMORY_SAME_LOGON);
	size_t encryptLegacy( void* data, size_t size, DWORD flags = CRYPTPROTECTMEMORY_SAME_LOGON);
	mol::ssh::string decryptLegacy( DWORD flags = CRYPTPROTECTMEMORY_SAME_LOGON);


	void* encrypted_;
	size_t size_;
	size_t size_encrypted_;
};

class EncryptedMap
{
public:

	typedef std::map<mol::ssh::string,mol::ssh::string> MapType;

	EncryptedMap();
	EncryptedMap(const EncryptedMap& rhs);
	EncryptedMap(EncryptedMap&& rhs);

	void encrypt(const MapType& map);
	MapType decrypt();

	EncryptedMap& operator=(const EncryptedMap& rhs);
	EncryptedMap& operator=(EncryptedMap&& rhs);

private:

	EncryptedMemory secure_;
};

} // end namespace ssh
} // end namespace mol

#endif