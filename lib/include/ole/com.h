#ifndef _DEF_COM_DEFINE_
#define _DEF_COM_DEFINE_

#include "util/uni.h"
#include "util/util.h"
#include "thread/Sync.h"
#include "win/mem.h"
#include <objbase.h>
#include <ole2.h>


namespace mol {

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
		long tmp = ::InterlockedCompareExchange ((volatile LONG*) &t_, (LONG)0,(LONG)0);
		if ( tmp == 0 )
		{
			punk<T> p;
			HRESULT hr = ::CoCreateInstance( *clsid, 0, CLSCTX_INPROC_SERVER, *iid, (void**)&p);
			if ( hr != S_OK )
			{
				return 0;
			}

			tmp = ::InterlockedCompareExchange( (volatile LONG*) &t_,(LONG)(p.interface_),(LONG)0);
			if ( tmp == 0 )
			{
				tmp = (long)(p.interface_);
				mol::ole_init::addRef((IUnknown*)t_);
			}
		}
		return (T*)tmp;
	}

private:

	static volatile T* t_;	
};

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
template<class T,const CLSID* clsid, const CLSID* iid >
volatile T* COMSingleton<T,clsid,iid>::t_ = 0;


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
		long tmp = ::InterlockedCompareExchange ((volatile LONG*) &t_, (LONG)0,(LONG)0);
		if ( tmp == 0 )
		{
			T* n = new T;
			tmp = ::InterlockedCompareExchange( (volatile LONG*) &t_,(LONG)n,(LONG)0);
			if ( tmp == 0 )
			{
				mol::ole_init::addRef((I*)t_);
				tmp = (long)n;
			}
			else
			{
				delete n;
			}
		}

		return (T*)tmp;
	}

private:

	static volatile T* t_;	
};

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
template<class T,class I >
volatile T* NonCreatableCOMSingleton<T,I>::t_ = 0;


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
