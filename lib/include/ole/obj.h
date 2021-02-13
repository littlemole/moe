#ifndef MOL_DEFINE_OBJ_DEF_GUARD_DEFINE_
#define MOL_DEFINE_OBJ_DEF_GUARD_DEFINE_

#include "ole/com.h"
#include "win/regkey.h"
#include <objbase.h>
namespace mol {

//////////////////////////////////////////////////////////////////////
// AddRef/Release Impl for IUnknown 
//////////////////////////////////////////////////////////////////////

template<class COM>
class com_obj : public COM
{
public:
    com_obj()
    {
        molrefcount_ = 0;
    }
    virtual ~com_obj() {}

	HRESULT virtual __stdcall QueryInterface(REFIID iid , LPVOID* ppv)
	{
		HRESULT hr = COM::QueryInterfaceImpl(iid,ppv);
		return hr;
	}

    ULONG   virtual __stdcall AddRef()
    {
		::InterlockedIncrement((volatile long*)&molrefcount_);
		return molrefcount_;
    }

    ULONG   virtual __stdcall Release()
    {		
        if ( ::InterlockedDecrement((volatile long*)&molrefcount_) ==0 )
        {
			this->dispose();
            delete this;
            return 0;
        }
        return molrefcount_;
    }
protected:
    volatile DWORD molrefcount_;



};

template<class COM>
class debug_com_instance : public COM
{
public:
    debug_com_instance()
    {
        molrefcount_ = 0;
		mol::App().lock();        
    }
    virtual ~debug_com_instance() 
	{
		mol::App().unlock();        
	}

	HRESULT virtual __stdcall QueryInterface(REFIID iid , LPVOID* ppv)
	{
		HRESULT hr = COM::QueryInterfaceImpl(iid,ppv);
		return hr;
	}

    ULONG   virtual __stdcall AddRef()
    {
		::InterlockedIncrement((volatile long*)&molrefcount_);
		ODBGS1("AddRef",molrefcount_);
		return molrefcount_;
    }

    ULONG   virtual __stdcall Release()
    {		
        if ( ::InterlockedDecrement((volatile long*)&molrefcount_) ==0 )
        {
			this->dispose();
			ODBGS1("Release",molrefcount_);
            delete this;
            return 0;
        }
		ODBGS1("Release",molrefcount_);
        return molrefcount_;
    }
protected:
    volatile DWORD molrefcount_;

};

//////////////////////////////////////////////////////////////////////
// AddRef/Release Impl for creatable IUnknown 
// an com_instance will force a lock-count on the server, as opposed
// to a plain com_obj
//////////////////////////////////////////////////////////////////////

template<class COM>
class com_instance : public com_obj<COM>
{
public:
    com_instance()
    {
		mol::App().lock();        
    }
    virtual ~com_instance() 
	{
		mol::App().unlock();
	}

};

template<class COM>
class com_singleton : public COM
{
public:
    com_singleton()
    {
		molrefcount_ = 0;
    }

    virtual ~com_singleton() 
	{
	}

    ULONG   virtual __stdcall AddRef()
    {
		mol::App().lock();
		::InterlockedIncrement((volatile long*)&molrefcount_);
		return molrefcount_;
    }

    ULONG   virtual __stdcall Release()
    {		
		::InterlockedDecrement((volatile long*)&molrefcount_);
		mol::App().unlock();
        return 1;
    }


	HRESULT virtual __stdcall QueryInterface(REFIID iid , LPVOID* ppv)
	{
		HRESULT hr = COM::QueryInterfaceImpl(iid,ppv);
		return hr;
	}

protected:
    volatile DWORD molrefcount_;
};

// helper class for Aggregagation

namespace ole {

template<class T>
class embedded_obj : public T
{
public:
    embedded_obj(void* pv)
    {
        outerUnknown_ = (IUnknown*)pv;
		molrefcount_  = 0;
    }
    virtual ~embedded_obj() {}

	HRESULT virtual __stdcall QueryInterface(REFIID iid , LPVOID* ppv)
	{
		if ( S_OK != outerUnknown_->QueryInterface(iid,ppv) )
		{
			return T::QueryInterfaceImpl(iid,ppv);
		}
		return S_OK;
	}

    ULONG   virtual __stdcall AddRef()
    {
        return outerUnknown_->AddRef();
    }

    ULONG   virtual __stdcall Release()
    {
		return outerUnknown_->Release();
    }
    IUnknown* controllingUnknown()
	{
		return outerUnknown_;
	}
protected:
    IUnknown* outerUnknown_;
	volatile DWORD molrefcount_;
};

} // end namespace ole

// aggregatable com instance

template<class COM>
class com_instance_agg : public IUnknown
{
public:
    com_instance_agg(void* pv)
		:embedded_(pv),molrefcount_(0)
    {
		mol::App().lock();        
    }
    virtual ~com_instance_agg() 
	{
		mol::App().unlock();
	}

	HRESULT virtual __stdcall QueryInterface(REFIID iid , LPVOID* ppv)
	{
		if ( ::IsEqualIID(IID_IUnknown,iid ) )
		{
			*ppv = (void*)(IUnknown*)this;
			AddRef();
			return S_OK;
		}
		return embedded_.QueryInterfaceImpl(iid,ppv);
	}
    ULONG   virtual __stdcall AddRef()
    {
        return ::InterlockedIncrement((volatile long*)&molrefcount_);
    }

    ULONG   virtual __stdcall Release()
    {
        if ( ::InterlockedDecrement((volatile long*)&molrefcount_) ==0 )
        {
			embedded_.dispose();
            delete this;
            return 0;
        }
        return molrefcount_;
    }

protected:
	mol::ole::embedded_obj<COM>		embedded_;
	volatile DWORD					molrefcount_;
};
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// stack objects - dummy refcount
//////////////////////////////////////////////////////////////////////

template<class COM>
class stack_obj : public COM
{
public:
    stack_obj() {}
    virtual ~stack_obj() {}

	HRESULT virtual __stdcall QueryInterface(REFIID iid , LPVOID* ppv)
	{
		return COM::QueryInterfaceImpl(iid,ppv);
	}

    ULONG   virtual __stdcall AddRef()
    {
        return 1;
    }

    ULONG   virtual __stdcall Release()
    {
        return 2;
    }
};

//////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////


template<class I, class T>
struct interface_ex
{
	typedef I uuid_type;
	typedef T vtable_type;
};

namespace ole {

// adapter to use either a generic Interface or a interface_ex template in below code
template<class T>
struct interface_base
{
	typedef T uuid_type;
	typedef T vtable_type;

	template<class O>
	static bool AddRefIf( O o, REFIID iid, LPVOID* ppv )
	{
		if ( IsEqualIID( uuidof<uuid_type>(), iid) )  
		{
			*ppv = (vtable_type*)(o);
			((IUnknown*)(*ppv))->AddRef();
			return true;	
		}
		return false;
	}


};

template<class T>
struct interface_base<stack_obj<T> >
{
	typedef T uuid_type;
	typedef T vtable_type;

	template<class O>
	static bool AddRefIf( O* o, REFIID iid, LPVOID* ppv )
	{
		return true;	
	}
};

template<>
struct interface_base<mol::ole::nullInterface>
{
	typedef mol::ole::nullInterface uuid_type;
	typedef mol::ole::nullInterface vtable_type;

	template<class O>
	static bool AddRefIf( O* o, REFIID iid, LPVOID* ppv )
	{
		return false;
	}
};

template<class I, class T>
struct interface_base< interface_ex<I,T> >
{
	typedef I uuid_type;
	typedef T vtable_type;

	template<class O>
	static bool AddRefIf( O* o, REFIID iid, LPVOID* ppv )
	{
		if ( IsEqualIID( uuidof<uuid_type>(), iid) )  
		{
			*ppv = (vtable_type*)(o);
			((IUnknown*)(*ppv))->AddRef();
			return true;	
		}
		return false;
	}
};




template<class T>
struct IsNullInterface
{
	enum { True = 0, False = 1 };
};

template<>
struct IsNullInterface<mol::ole::nullInterface>
{
	enum { False = 0, True = 1 };
};

template< class T, class I1 , class I2 , class I3 , class I4 , class I5 , 
		  class I6 , class I7 , class I8 , class I9 , class I10 ,
		  class I11  , class I12  , class I13  , class I14  , class I15 ,
		  class I16  , class I17 , class  I18 , class I19 , class I20 ,
		  class I21 , class I22 , class I23 , class I24 , class I25  > 
class com_impl 
{
public:


// 
// Q: why QueryInterfaceImpl instead QueryInterface ?
// A: Aggregation support. For non-aggregable objects, 
//    QueryInterfaceImpl = QueryInterface

	HRESULT virtual __stdcall QueryInterfaceImpl(REFIID iid , LPVOID* ppv)
	{
		*ppv = (IUnknown*)(0); 

		if ( IsEqualIID( IID_IUnknown,iid) )   
		{
			*ppv = (IUnknown*)(typename interface_base<I1>::vtable_type*)(T*)(this);
			((IUnknown*)(*ppv))->AddRef();
            return S_OK;
		}

		if ( IsNullInterface<I1>::True )
			return E_NOINTERFACE;
		if ( interface_base<I1>::AddRefIf( (T*)(this), iid, ppv ) )
			return S_OK;

		if ( IsNullInterface<I2>::True )
			return E_NOINTERFACE;
		if ( interface_base<I2>::AddRefIf( (T*)(this), iid, ppv ) )
			return S_OK;

		if ( IsNullInterface<I3>::True )
			return E_NOINTERFACE;
		if ( interface_base<I3>::AddRefIf( (T*)(this), iid, ppv ) )
			return S_OK;

		if ( IsNullInterface<I4>::True )
			return E_NOINTERFACE;
		if ( interface_base<I4>::AddRefIf( (T*)(this), iid, ppv ) )
			return S_OK;

		if ( IsNullInterface<I5>::True )
			return E_NOINTERFACE;
		if ( interface_base<I5>::AddRefIf( (T*)(this), iid, ppv ) )
			return S_OK;

		if ( IsNullInterface<I6>::True )
			return E_NOINTERFACE;
		if ( interface_base<I6>::AddRefIf( (T*)(this), iid, ppv ) )
			return S_OK;

		if ( IsNullInterface<I7>::True )
			return E_NOINTERFACE;
		if ( interface_base<I7>::AddRefIf( (T*)(this), iid, ppv ) )
			return S_OK;

		if ( IsNullInterface<I8>::True )
			return E_NOINTERFACE;
		if ( interface_base<I8>::AddRefIf( (T*)(this), iid, ppv ) )
			return S_OK;

		if ( IsNullInterface<I9>::True )
			return E_NOINTERFACE;
		if ( interface_base<I9>::AddRefIf( (T*)(this), iid, ppv ) )
			return S_OK;

		if ( IsNullInterface<I10>::True )
			return E_NOINTERFACE;
		if ( interface_base<I10>::AddRefIf( (T*)(this), iid, ppv ) )
			return S_OK;

		if ( IsNullInterface<I11>::True )
			return E_NOINTERFACE;
		if ( interface_base<I11>::AddRefIf( (T*)(this), iid, ppv ) )
			return S_OK;

		if ( IsNullInterface<I1>::True )
			return E_NOINTERFACE;
		if ( interface_base<I1>::AddRefIf( (T*)(this), iid, ppv ) )
			return S_OK;

		if ( IsNullInterface<I12>::True )
			return E_NOINTERFACE;
		if ( interface_base<I12>::AddRefIf( (T*)(this), iid, ppv ) )
			return S_OK;

		if ( IsNullInterface<I13>::True )
			return E_NOINTERFACE;
		if ( interface_base<I13>::AddRefIf( (T*)(this), iid, ppv ) )
			return S_OK;

		if ( IsNullInterface<I14>::True )
			return E_NOINTERFACE;
		if ( interface_base<I14>::AddRefIf( (T*)(this), iid, ppv ) )
			return S_OK;

		if ( IsNullInterface<I14>::True )
			return E_NOINTERFACE;
		if ( interface_base<I14>::AddRefIf( (T*)(this), iid, ppv ) )
			return S_OK;

		if ( IsNullInterface<I14>::True )
			return E_NOINTERFACE;
		if ( interface_base<I14>::AddRefIf( (T*)(this), iid, ppv ) )
			return S_OK;

		if ( IsNullInterface<I15>::True )
			return E_NOINTERFACE;
		if ( interface_base<I15>::AddRefIf( (T*)(this), iid, ppv ) )
			return S_OK;

		if ( IsNullInterface<I16>::True )
			return E_NOINTERFACE;
		if ( interface_base<I16>::AddRefIf( (T*)(this), iid, ppv ) )
			return S_OK;

		if ( IsNullInterface<I17>::True )
			return E_NOINTERFACE;
		if ( interface_base<I17>::AddRefIf( (T*)(this), iid, ppv ) )
			return S_OK;

		if ( IsNullInterface<I18>::True )
			return E_NOINTERFACE;
		if ( interface_base<I18>::AddRefIf( (T*)(this), iid, ppv ) )
			return S_OK;

		if ( IsNullInterface<I19>::True )
			return E_NOINTERFACE;
		if ( interface_base<I19>::AddRefIf( (T*)(this), iid, ppv ) )
			return S_OK;

		if ( IsNullInterface<I20>::True )
			return E_NOINTERFACE;
		if ( interface_base<I20>::AddRefIf( (T*)(this), iid, ppv ) )
			return S_OK;

		if ( IsNullInterface<I21>::True )
			return E_NOINTERFACE;
		if ( interface_base<I21>::AddRefIf( (T*)(this), iid, ppv ) )
			return S_OK;

		if ( IsNullInterface<I22>::True )
			return E_NOINTERFACE;
		if ( interface_base<I22>::AddRefIf( (T*)(this), iid, ppv ) )
			return S_OK;

		if ( IsNullInterface<I23>::True )
			return E_NOINTERFACE;
		if ( interface_base<I23>::AddRefIf( (T*)(this), iid, ppv ) )
			return S_OK;

		if ( IsNullInterface<I24>::True )
			return E_NOINTERFACE;
		if ( interface_base<I24>::AddRefIf( (T*)(this), iid, ppv ) )
			return S_OK;

		if ( IsNullInterface<I25>::True )
			return E_NOINTERFACE;
		if ( interface_base<I25>::AddRefIf( (T*)(this), iid, ppv ) )
			return S_OK;

		return E_NOINTERFACE;
	}
};

} // end namespace ole


// helper template to derive from
// hidden by the next two templates
// serving as syntactic sugar

template< class T, class I1, class I2 = mol::ole::nullInterface, class I3 = mol::ole::nullInterface,  
		  class I4 = mol::ole::nullInterface , class I5 = mol::ole::nullInterface , class I6 = mol::ole::nullInterface,
		  class I7 = mol::ole::nullInterface , class I8 = mol::ole::nullInterface , class I9 = mol::ole::nullInterface, 
		  class I10 = mol::ole::nullInterface, class I11 = mol::ole::nullInterface, class I12 = mol::ole::nullInterface,
		  class I13 = mol::ole::nullInterface, class I14 = mol::ole::nullInterface, class I15 = mol::ole::nullInterface,
		  class I16 = mol::ole::nullInterface, class I17 = mol::ole::nullInterface, class I18 = mol::ole::nullInterface, 
		  class I19 = mol::ole::nullInterface, class I20 = mol::ole::nullInterface, class I21 = mol::ole::nullInterface, 
		  class I22 = mol::ole::nullInterface, class I23 = mol::ole::nullInterface, class I24 = mol::ole::nullInterface, 
		  class I25 = mol::ole::nullInterface>
class com_implements
	: public mol::ole::com_impl<T, I1,I2,I3,I4,I5,I6,I7,I8,I9,I10,I11,I12,I13,I14,I15,I16,I17,I18,I19,I20,I21,I22,I23,I24,I25>
{};

// allows to specify a list of interfaces
template< class T1, class T2 = mol::ole::nullInterface, class T3 = mol::ole::nullInterface,  
		  class T4 = mol::ole::nullInterface , class T5 = mol::ole::nullInterface , class T6 = mol::ole::nullInterface,
		  class T7 = mol::ole::nullInterface , class T8 = mol::ole::nullInterface , class T9 = mol::ole::nullInterface, 
		  class T10 = mol::ole::nullInterface, class T11 = mol::ole::nullInterface, class T12 = mol::ole::nullInterface,
		  class T13 = mol::ole::nullInterface, class T14 = mol::ole::nullInterface, class T15 = mol::ole::nullInterface,
		  class T16 = mol::ole::nullInterface, class T17 = mol::ole::nullInterface, class T18 = mol::ole::nullInterface, 
		  class T19 = mol::ole::nullInterface, class T20 = mol::ole::nullInterface, class T21 = mol::ole::nullInterface, 
		  class T22 = mol::ole::nullInterface, class T23 = mol::ole::nullInterface, class T24 = mol::ole::nullInterface, 
		  class T25 = mol::ole::nullInterface>
class implements
{
public:
	typedef T1 I1;
	typedef T2 I2;
	typedef T3 I3;
	typedef T4 I4;
	typedef T5 I5;
	typedef T6 I6;
	typedef T7 I7;
	typedef T8 I8;
	typedef T9 I9;
	typedef T10 I10;
	typedef T11 I11;
	typedef T12 I12;
	typedef T13 I13;
	typedef T14 I14;
	typedef T15 I15;
	typedef T16 I16;
	typedef T17 I17;
	typedef T18 I18;
	typedef T19 I19;
	typedef T20 I20;
	typedef T21 I21;
	typedef T22 I22;
	typedef T23 I23;
	typedef T24 I24;
	typedef T25 I25;
};

// final user template to implement QueryInterface
// usage
//
// class MyObj : public interfaces< MyObj, 
//							implements< IMyInterface, 
//										IDispatch,
//										IPersist, 
//										.. > 
//								>, 
//               ... other derivations
//

template< class T, class I>
class interfaces
	: public com_implements< T, 
							 typename I::I1,  typename I::I2,  typename I::I3,
							 typename I::I4,  typename I::I5,  typename I::I6,
							 typename I::I7,  typename I::I8,  typename I::I9,
							 typename I::I10, typename I::I11, typename I::I12,
							 typename I::I13, typename I::I14, typename I::I15,
							 typename I::I16, typename I::I17, typename I::I18,
							 typename I::I19, typename I::I20, typename I::I21,
							 typename I::I22, typename I::I23, typename I::I24,
							 typename I::I25 >
{};


} // end namespace mole

#endif