#ifndef _DEF_COM_DEFINE_
#define _DEF_COM_DEFINE_

#include "util/uni.h"
#include "util/util.h"
#include "thread/Sync.h"
#include "win/mem.h"
#include <objbase.h>
#include <ole2.h>

// outer this for embedded class 
//#define outer_this(Outer,Member) Outer* This() { return (Outer*) (((char*)this)-(size_t)&(((Outer*)0)->Member)); }
//#define outer_this_ptr(Outer,Member) (Outer*) (((char*)this)-(size_t)&(((Outer*)0)->Member))

// base this pointer for mi IUnknows
// #define BASE_OFFSET(Cls,Base) (DWORD(((Base*)((Cls*)(0x10000000))))-0x10000000)


// thanx to dan box :)

namespace mol {

//template<class C, class Base>
//DWORD base_offset()
//{
//	return (DWORD(((Base*)((C*)(0x10000000))))-0x10000000);
//}


//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Init COM
//////////////////////////////////////////////////////////////////////

class com_init
{
public:
	com_init ()  { ::CoInitialize(0);  }
    ~com_init()  { ::CoUninitialize(); }
};

namespace ole {

struct emptyType {};

struct nullInterface {};

} // end namespace ole

// uuid_info is a template to hide ms specific __uuidof(x)

template <class I> 
class uuid_info
{
 public:
   //static const GUID& uuidof() { return __uuidof(I); }
	 static REFIID uuidof;
   typedef I uuid_type;
};

template <class I> 
REFIID uuid_info<I>::uuidof = __uuidof(I);


template <> 
class uuid_info<mol::ole::nullInterface>
{
 public:
   //static const GUID& uuidof() { return CLSID_NULL; }
	 static REFIID uuidof;// = CLSID_NULL;
   typedef mol::ole::nullInterface uuid_type;
};



// uuidof is a generic function template to replace __uuidof(x)

template <typename I> 
const GUID& uuidof() 
{ 
	return uuid_info<I>::uuidof;//(); 
}

template <typename I> 
const GUID& uuidof(I*) 
{ 
	return uuid_info<I>::uuidof;//(); 
}

template <typename I> 
const GUID& uuidof(I**) 
{ 
	return uuid_info<I>::uuidof;//(); 
}

template<const IID* I1, const IID* I2 = &IID_NULL, const IID* I3 = &IID_NULL, const IID* I4 = &IID_NULL, const IID* I5 = &IID_NULL>
class SupportsErrorInfo : public ISupportErrorInfo 
{
public:

	HRESULT virtual __stdcall InterfaceSupportsErrorInfo( REFIID  riid )
	{
		if ( ::IsEqualIID( riid, IID_NULL ) )
			return S_FALSE;

		if ( ::IsEqualIID( riid, *I1 ) )
			return S_OK;
		if ( ::IsEqualIID( riid, *I2 ) )
			return S_OK;
		if ( ::IsEqualIID( riid, *I3 ) )
			return S_OK;
		if ( ::IsEqualIID( riid, *I4 ) )
			return S_OK;
		if ( ::IsEqualIID( riid, *I5 ) )
			return S_OK;

		return S_FALSE;
	}
};





/////////////////////////////////////////////////////////////////////
// convert clsid to string
/////////////////////////////////////////////////////////////////////

mol::string stringFromCLSID(REFGUID guid);

///////////////////////////////////////////////////////////////////////
// (B)string conversion helpers
///////////////////////////////////////////////////////////////////////

// BSTRs
std::string BSTR2ansi( BSTR bstr );
BSTR	    ansi2BSTR( const std::string& s );


//////////////////////////////////////////////////////////////////////

// BSTR to string - FREES the bstring!
mol::string stringFromFreedBSTR( BSTR bstr );


///////////////////////////////////////////////////////////////////////////////
// COM Singletons - will be released just before ~OleUninitialize()
///////////////////////////////////////////////////////////////////////////////
template<class T>
class ComShim : public T
{
public:

	virtual long AddRef()
	{
		debug_refcount_++;
	}
	virtual long Release()
	{
		debug_refcount_--;
	}

	virtual long comshim_internal_AddRef()
	{
		return T::AddRef();
	}

	virtual long comshim_internal_Release()
	{
		if ( debug_refcount_ != 0 )
			cry();

		return T::Release();
	}

private:
	int debug_refcount_;
};


template<class T, const CLSID* clsid, const CLSID* iid = &mol::uuidof<T>()>
class COMSingleton
{
public:

	static T* instance() 
	{
		LOCK(mutex());
		if (!t_)
		{
			punk<T> p;
			HRESULT hr = ::CoCreateInstance( *clsid, 0, CLSCTX_INPROC_SERVER, *iid, (void**)&p);
			if ( hr != S_OK )
			{
				return 0;
			}
			t_ = p;
			mol::ole_init::addRef(t_);
		}
		return t_;
	}

private:

	static mol::IMutex& mutex()
	{
		static mol::CriticalSection cs_;
		return cs_;
	}


	static T* t_;	
};

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
template<class T,const CLSID* clsid, const CLSID* iid >
T* COMSingleton<T,clsid,iid>::t_ = 0;


///////////////////////////////////////////////////////////////////////////////
// 


template<class T,const CLSID* clsid, const CLSID* iid>
T* comSingleton()
{
	return COMSingleton<T,REFCLSID clsid, REFCLSID iid>::instance();
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

template<class T,const CLSID* clsid>
T* comSingleton()
{
	return COMSingleton<T,clsid,&mol::uuid_info<T>::uuidof >::instance();
}

// NonCreatableCOMSingleton - creates non-registered COM object
// using new and calls release on them just before ::OleUninitialize()


template<class T, class I = T>
class NonCreatableCOMSingleton
{
public:

	static T* instance() 
	{
		LOCK(mutex());
		if (!t_)
		{
			t_ = new T;
			mol::ole_init::addRef((I*)t_);
		}
		return (T*)t_;
	}

private:

	static mol::IMutex& mutex()
	{
		static mol::CriticalSection cs_;
		return cs_;
	}

	static T* t_;	
};

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
template<class T,class I >
T* NonCreatableCOMSingleton<T,I>::t_ = 0;


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

template<class T, class I>
T* nonCreatableCOMSingleton()
{
	return NonCreatableCOMSingleton<T,I>::instance();
}

template<class T>
T* nonCreatableCOMSingleton()
{
	return NonCreatableCOMSingleton<T,T>::instance();
}

} // end namespace mol

#endif
