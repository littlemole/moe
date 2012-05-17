#include "ssh/mem.h"
#include "win/core.h"
#include "util/util.h"
#include "util/X.h"
#include <thread/thread.h>
#include <thread/sync.h>

// see these for win vista++
//#include <Wincrypt.h>
//#include "Ntsecapi.h"

#define 		STATUS_SUCCESS					0
#define RTL_ENCRYPT_MEMORY_SIZE					8
#define CRYPTPROTECTMEMORY_BLOCK_SIZE           16

typedef long RtlEncryptMemoryPtr ( PVOID mem, ULONG size, ULONG flags );
typedef long RtlDecryptMemoryPtr ( PVOID mem, ULONG size, ULONG flags );

RtlEncryptMemoryPtr* RtlEncryptMemory = (RtlEncryptMemoryPtr*)mol::dllFunc( _T("Advapi32.dll"), _T("SystemFunction040") );
RtlDecryptMemoryPtr* RtlDecryptMemory = (RtlDecryptMemoryPtr*)mol::dllFunc( _T("Advapi32.dll"), _T("SystemFunction041") );

typedef BOOL __stdcall CryptProtectMemoryPtr( LPVOID pDataIn, DWORD cbDataIn, DWORD dwFlags);
typedef BOOL __stdcall CryptUnprotectMemoryPtr( LPVOID pDataIn, DWORD cbDataIn, DWORD dwFlags);

CryptProtectMemoryPtr* MolCryptProtectMemory = (CryptProtectMemoryPtr*)mol::dllFunc( _T("Crypt32.dll"), _T("CryptProtectMemory") );
CryptUnprotectMemoryPtr* MolCryptUnprotectMemory = (CryptUnprotectMemoryPtr*)mol::dllFunc( _T("Crypt32.dll"), _T("CryptUnprotectMemory") );


namespace mol {
namespace ssh {




////////////////////////////////////////////////////////////////////////


EncryptedMemory::EncryptedMemory()
	:encrypted_(0),size_(0),size_encrypted_(0)
{

}

EncryptedMemory::EncryptedMemory( const EncryptedMemory& rhs)
	:encrypted_(0),size_(rhs.size_),size_encrypted_(rhs.size_encrypted_)
{
	encrypted_ = ::LocalAlloc(LPTR,size_encrypted_);
	::memcpy(encrypted_,rhs.encrypted_,size_encrypted_);
}

EncryptedMemory::EncryptedMemory( EncryptedMemory&& rhs)
	:encrypted_(rhs.encrypted_),size_(rhs.size_),size_encrypted_(rhs.size_encrypted_)
{
	rhs.encrypted_ = 0;
	rhs.size_ = 0;
	rhs.size_encrypted_ = 0;
}

EncryptedMemory::~EncryptedMemory()
{
	dispose();
}

void EncryptedMemory::dispose()
{
	if ( encrypted_ )
	{
		::LocalFree(encrypted_);
		encrypted_ = 0;
		size_ = 0;
		size_encrypted_ = 0;
	}
}

EncryptedMemory& EncryptedMemory::operator=(const EncryptedMemory& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}

	size_ = rhs.size_;
	size_encrypted_ = rhs.size_encrypted_;
	encrypted_ = ::LocalAlloc(LPTR,size_encrypted_);
	::memcpy(encrypted_,rhs.encrypted_,size_encrypted_);
	return *this;
}


EncryptedMemory& EncryptedMemory::operator=(EncryptedMemory&& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}

	dispose();

	size_ = rhs.size_;
	size_encrypted_ = rhs.size_encrypted_;
	encrypted_ = rhs.encrypted_;

	rhs.encrypted_ = 0;
	rhs.size_ = 0;
	rhs.size_encrypted_ = 0;

	return *this;
}

size_t EncryptedMemory::encrypt( void* data, size_t size, DWORD flags )
{
	if ( MolCryptProtectMemory )
	{
		return encryptVista(data,size,flags);
	}
	return encryptLegacy(data,size,flags);
}

size_t EncryptedMemory::encryptLegacy( void* data, size_t size, DWORD flags )
{
	static std::string padding('X',RTL_ENCRYPT_MEMORY_SIZE);

	dispose();

	size_ = size;
	size_encrypted_ = size;

	DWORD mod = size_ % RTL_ENCRYPT_MEMORY_SIZE;
	if ( mod )
	{
		size_encrypted_ = size_ + (RTL_ENCRYPT_MEMORY_SIZE-mod);
	}

	encrypted_ = ::LocalAlloc(LPTR,size_encrypted_);
	::memcpy( encrypted_, data, size_);

	long ntstat = ::RtlEncryptMemory( encrypted_, (ULONG)size_encrypted_,flags);
	if (ntstat!=STATUS_SUCCESS)
	{
		cry();
		throw mol::X("CryptProtectMemory failed!");
	}
	return size_;
}

mol::ssh::string EncryptedMemory::decryptLegacy( DWORD flags )
{
	void* v = malloc(size_encrypted_);
	if(!v)
		return "";

	::memcpy(v,encrypted_,size_encrypted_);

	if (::RtlDecryptMemory(v,(ULONG)size_encrypted_,flags) == STATUS_SUCCESS)
	{
		mol::ssh::string s( (char*)v, size_ );
		free(v);
		return s;
	}
	free(v);
	return "";
}

mol::ssh::string EncryptedMemory::decrypt( DWORD flags )
{
	if ( MolCryptUnprotectMemory )
	{
		return decryptVista(flags);
	}
	return decryptLegacy(flags);
}

size_t EncryptedMemory::encryptVista( void* data, size_t size, DWORD flags )
{
	static std::string padding('X',CRYPTPROTECTMEMORY_BLOCK_SIZE);

	dispose();

	size_ = size;
	size_encrypted_ = size;

	DWORD mod = size_ % CRYPTPROTECTMEMORY_BLOCK_SIZE;
	if ( mod )
	{
		size_encrypted_ = size_ + (CRYPTPROTECTMEMORY_BLOCK_SIZE-mod);
	}

	encrypted_ = ::LocalAlloc(LPTR,size_encrypted_);
	::memcpy( encrypted_, data, size_);

	if (!MolCryptProtectMemory( encrypted_, (DWORD)size_encrypted_,flags))
	{
		throw mol::X("CryptProtectMemory failed!");
	}
	return size_;
}

mol::ssh::string EncryptedMemory::decryptVista( DWORD flags )
{
	void* v = malloc(size_encrypted_);
	if(!v)
		return "";

	::memcpy(v,encrypted_,size_encrypted_);

	if (MolCryptUnprotectMemory(v,(DWORD)size_encrypted_,flags))
	{
		mol::ssh::string s( (char*)v, size_ );
		free(v);
		return s;
	}
	free(v);
	return "";
}

void* EncryptedMemory::data()
{
	return encrypted_;
}

size_t EncryptedMemory::size()
{
	return size_;
}

////////////////////////////////////////////////////////////////////////


EncryptedMap::EncryptedMap()
{
}

EncryptedMap::EncryptedMap(const EncryptedMap& rhs)
	: secure_(rhs.secure_)
{
}

EncryptedMap::EncryptedMap(EncryptedMap&& rhs)
	: secure_(rhs.secure_)
{
}

void EncryptedMap::encrypt(const EncryptedMap::MapType& map)
{
	mol::ssh::stringBuffer buffer;
	for ( MapType::const_iterator it = map.begin(); it!=map.end(); it++)
	{
		buffer.append( (*it).first.data(), (*it).first.size() );
		buffer.append( "\0", 1 );
		buffer.append( (*it).second.data(), (*it).second.size() );
		buffer.append( "\0", 1 );
	}

	secure_.encrypt( (void*)buffer.data(), buffer.size() );
}

EncryptedMap::MapType EncryptedMap::decrypt()
{
	MapType map;
	mol::ssh::string plain = secure_.decrypt();
	size_t pos = 0;
	size_t p   = 0;

	char* data = (char*)plain.data();
	char* pdata = (char*)data;

	while(pdata < plain.data()+plain.size() )
	{
		while( *pdata )
		{
			pdata++;
		}

		mol::ssh::string key( data, pdata-data );
		pdata++;
		data = pdata;

		while( *pdata )
		{
			pdata++;
		}
		mol::ssh::string val( data, pdata-data );
		pdata++;
		data = pdata;

		map.insert( std::make_pair(key,val) );
	}	

	return map;
}

EncryptedMap& EncryptedMap::operator=(const EncryptedMap& rhs)
{
	if ( this == &rhs )
	{
		return *this;
	}

	secure_ = rhs.secure_;
	return *this;
}

EncryptedMap& EncryptedMap::operator=(EncryptedMap&& rhs)
{
	if ( this == &rhs )
	{
		return *this;
	}

	secure_ = rhs.secure_;
	return *this;
}

} // end namespace ssh
} // end namespace mol