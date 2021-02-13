#include "conf.h"
#include "ole/stream.h"
#include "win/mem.h"
#include <Shlwapi.h> 
#include <sstream>

namespace mol {

Stream::Stream() 
{}					

Stream::Stream( IUnknown* iUnknown)					
    : punk<IStream>(iUnknown) 
{}		

Stream::Stream( punk<IStream>& iUnknown )		
    : punk<IStream>(iUnknown) 
{}

Stream::~Stream() 
{}

Stream& Stream::operator=( Stream& c )				
{											
    if ( c == *this )                       
        return *this;                       
    release();								
    interface_ = c.interface_ ;		    
	interface_->AddRef();
    return *this;	
}

Stream::Stream(HGLOBAL glob)
{
	create(glob);
}

Stream::Stream(const char* data , size_t size, int opt )
{
	create(data,size,opt);
}

HGLOBAL Stream::global()
{
	return Global(interface_);
}

std::string Stream::toString()
{
	return ToString(interface_);
}

HRESULT Stream::copyTo( IStream* pStream )
{
	LARGE_INTEGER ll;
	ll.QuadPart = 0;
	HRESULT hr = (*this)->Seek(ll,STREAM_SEEK_SET,0);
	hr = pStream->Seek(ll,STREAM_SEEK_SET,0);

	ULARGE_INTEGER ul;
	ul.QuadPart = ULLONG_MAX;
	hr = (*this)->CopyTo( pStream, ul, NULL, NULL );

	hr = pStream->Seek(ll,STREAM_SEEK_SET,0);
	hr = (*this)->Seek(ll,STREAM_SEEK_SET,0);

	return S_OK;
}

HRESULT Stream::copyFrom( IStream* pStream )
{
	release();
	create();

	ULARGE_INTEGER ul;
	ul.QuadPart = ULLONG_MAX;
	HRESULT hr = pStream->CopyTo(*this,ul,NULL,NULL);

	LARGE_INTEGER ll;
	ll.QuadPart = 0;
	hr = pStream->Seek(ll,STREAM_SEEK_SET,0);
	hr = (*this)->Seek(ll,STREAM_SEEK_SET,0);

	return S_OK;
}

HRESULT Stream::create()
{
	release();
	return Create(&interface_);
}

HRESULT Stream::create(HGLOBAL glob)
{
	release();
	return Create(&interface_, glob);
}

HRESULT Stream::create(const char* data , size_t size, int opt  )
{
	release();
	return Create(&interface_, data, size, opt);
}

HRESULT Stream::create(IStream** pStream, const std::wstring& path, DWORD flags)
{
	release();
	return Create( &interface_, path, flags );
}

HGLOBAL Stream::Global(IStream* str)
{
	HGLOBAL glob = NULL;
	::GetHGlobalFromStream( str, &glob );
	return glob;
}

std::string Stream::ToString(IStream* Stream)
{
    std::ostringstream oss;
    const int buflen = 2048;
    char buf[buflen+1];
    ULONG nread = 0;
    do
    {
        Stream->Read(buf,buflen,&nread);
        buf[nread]=0;
        oss << buf;
    }
    while ( nread > 0 );
    return oss.str();
}

HRESULT Stream::Create(IStream** pStream)
{
	return ::CreateStreamOnHGlobal( 0, TRUE, pStream);
}

HRESULT Stream::Create(IStream** pStream, HGLOBAL glob)
{
	return ::CreateStreamOnHGlobal( glob, TRUE, pStream);
}

HRESULT Stream::reset()
{
	LARGE_INTEGER li;
	li.QuadPart = 0;
	return interface_->Seek(li,STREAM_SEEK_SET,NULL);
}

HRESULT Stream::Create( IStream** pStream, const char* data , size_t size , int opt)
{
	mol::global glob;

	if (!glob.alloc(size, opt) )
		return S_FALSE;

	char* pDest = (char*)glob.lock();

	if (!data || !pDest)
		return S_FALSE;

	memcpy( pDest, data, size );
	glob.unLock();
	
	HRESULT hr = ::CreateStreamOnHGlobal( glob, TRUE, pStream);
	glob.detach();
	return hr;
}

HRESULT Stream::Create(IStream** pStream, const std::wstring& path, DWORD flags )
{
	return ::SHCreateStreamOnFile( path.c_str(), flags, pStream);
}


REFCLSID Stream::clsid()
{
	if ( interface_ )
	{		
		if ( S_OK == ::ReadClassStm(interface_,&clsid_) )
			return clsid_;
	}
	return CLSID_NULL;
}

bool Stream::clsid( REFCLSID clsid)
{
	if ( S_OK == ::WriteClassStm(interface_,clsid) )
		return true;
	return false;
}

} // end namespace mol