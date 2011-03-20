#ifndef _MOL_DEF_GUARD_TLS_WIN_DEFINE_DEF_
#define _MOL_DEF_GUARD_TLS_WIN_DEFINE_DEF_

#include "conf.h"
#include "thread/sync.h"

namespace mol {

template<class T>
class TLS
{
friend class mol::Singleton< TLS<T> >;
public:

	T& get() 
	{
		LPVOID pv = ::TlsGetValue(index_);
		if ( !pv )
		{
			T* t = new T;
			set( *t );
			return *t;
		}
		return *((T*)pv);
	}

	void set(T& t)
	{
		::TlsSetValue(index_, (void*)&t );
	}

private:

	TLS()
	{
		index_ = ::TlsAlloc();
		T* t = new T;
		set( *t );
	}

	~TLS()
	{
		T& t = get();
		delete &t;
		::TlsFree(index_);
	}

	DWORD index_;
};

template<class T>
TLS<T>& tls()
{
	return mol::singleton< TLS<T> >();
}

} // end namespace mol


#endif