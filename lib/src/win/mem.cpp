#include "win/mem.h"

namespace mol {

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

global::global()
{
    hGlobal_ = 0;
}

/////////////////////////////////////////////////////////////////////

global::global( HGLOBAL glob )
{
	hGlobal_ = glob;
}

/////////////////////////////////////////////////////////////////////

global::global( const std::string& s, int opt )
{
	size_t l = s.size()+1;
	if ( alloc( l, opt ) )
	{
		char* tmp = (char*)lock();
		if ( tmp )
		{
			memcpy(tmp,(char*)s.c_str(),l);
			unLock();
		}
	}
}


global::global( const std::wstring& s, int opt )
{
	size_t l = (s.size()+1)*sizeof(wchar_t);
	if ( alloc( l, opt ) )
	{
		void* tmp = lock();
		if ( tmp )
		{
			memcpy(tmp,s.c_str(),l);
			unLock();
		}
	}
}

global::global( void* v, size_t size, int opt )
{
	if ( alloc(size,opt) )
	{
		void* tmp = lock();
		if ( tmp )
		{
			memcpy( tmp, v, size );
			unLock();
		}
	}
}


/////////////////////////////////////////////////////////////////////

global::~global()
{
    release();
}

/////////////////////////////////////////////////////////////////////

BOOL global::alloc( size_t size, int opt )
{
    return (hGlobal_ = ::GlobalAlloc( opt, size )) != 0;
}

/////////////////////////////////////////////////////////////////////

void* global::lock()
{
    return (void*)(::GlobalLock( hGlobal_ ));
}

/////////////////////////////////////////////////////////////////////

void global::unLock()
{
    ::GlobalUnlock( hGlobal_);
}

/////////////////////////////////////////////////////////////////////

void global::release()
{
	if ( hGlobal_ )
		::GlobalFree(hGlobal_);
    hGlobal_ = 0;
}

/////////////////////////////////////////////////////////////////////

void global::attach(HGLOBAL glob)
{
	release();
	hGlobal_ = glob;
}

/////////////////////////////////////////////////////////////////////

void global::detach()
{
	hGlobal_ = 0;
}

} // endnamespace mol