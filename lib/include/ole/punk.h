#ifndef MOL_LIB_PUNK_DEF_GUARD_DEFINE_
#define MOL_LIB_PUNK_DEF_GUARD_DEFINE_

#include "ole/com.h"

namespace mol {


//////////////////////////////////////////////////////////////////////
// punk : COM smart pointer 
//////////////////////////////////////////////////////////////////////

template < class I >
class punk
{
public:
    punk()  : interface_ (0) { }

    punk( const I* i )
        :interface_(0) 
    {
        if ( i )
        {
            interface_ = (I*)i;
            interface_->AddRef();
        }
    }

    punk( IUnknown* iUnknown )
        :interface_(0) 
    {
        if ( iUnknown )
        {
			HRESULT hr = iUnknown->QueryInterface( uuidof<I>(),(void**)(&interface_) );
			if ( S_OK != hr )
				interface_ = 0;
        }
    }

    virtual ~punk()
    {
        release();
    }

    HRESULT queryInterface( REFIID iid, void** iUnknown ) const
    {
        return interface_->QueryInterface( iid, iUnknown );
    }

	template<class T>
    HRESULT queryInterface( T** Unknown ) const
    {
		return interface_->QueryInterface( mol::uuidof<T>(), (void**)Unknown );
    }

    HRESULT createObject( CLSID classId, int clsctx = CLSCTX_INPROC_SERVER )
    {
        return ::CoCreateInstance( classId, NULL, clsctx, uuidof<I>(), (void**)&interface_ );
    }


    HRESULT createObject( const std::wstring& progid, int clsctx = CLSCTX_INPROC_SERVER )
    {
		CLSID classId;
		HRESULT hr = ::CLSIDFromProgID(progid.c_str(),&classId);
		if ( hr != S_OK )
			return hr;

        return createObject(classId,clsctx);
    }

    const I* operator->() const  { return interface_; }
    I* operator->()				 { return interface_; }
    operator I*()				 { return interface_; }
    operator const I*() const	 { return interface_; }
    I** operator&()				 { return &interface_; }
    bool operator()() const		 { return (interface_ != 0 ); }

    punk& operator=( I* p )
    {
        if ( p == interface_ )
            return *this;

        release();
        interface_ = p;
        if (p)
        {
            interface_->AddRef();
        }
        return *this;
    }

    punk& operator=( punk<I>& p)
    {
        if ( p == *this )
            return *this;

        release();
        interface_ = p.interface_;
        if (p)
        {
            interface_->AddRef();
        }
        return *this;
    }

	template<class T>
    punk& operator=( punk<T>& p)
    {

        release();
		p.queryInterface( uuidof<I>(), (void**)&interface_);
        return *this;
    }

    void release()
    {
        if(interface_)
        {
            interface_->Release();
        }
        interface_ = 0;
    }

    I*	interface_;
};


} // end namespace mol

#endif

