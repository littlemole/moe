#ifndef _DEF_COM_DEFINE_
#define _DEF_COM_DEFINE_

#include "util/uni.h"
#include "util/util.h"
#include "ole/punk.h"
//#include "ole/ole.h"
#include "thread/Sync.h"
#include "win/mem.h"
#include "win/app.h"
#include <objbase.h>
#include <ole2.h>
#include <OCIdl.h>
#include <list>

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



class ole_init
{
public:
	ole_init()
	{
		::OleInitialize(0);
	}


	~ole_init()
	{
		for (std::list<IUnknown*>::iterator it = singletons_.begin(); it != singletons_.end(); it++)
		{
			(*it)->Release();
		}
		::OleUninitialize();
	}

	static void addRef(IUnknown* p)
	{
		p->AddRef();
		singletons_.push_back(p);
	}

private:
	static std::list<IUnknown*> singletons_;
};

} // end namespace ole



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

std::wstring stringFromCLSID(REFGUID guid);

///////////////////////////////////////////////////////////////////////
// (B)string conversion helpers
///////////////////////////////////////////////////////////////////////

// BSTRs
std::string BSTR2ansi( BSTR bstr );
BSTR	    ansi2BSTR( const std::string& s );


//////////////////////////////////////////////////////////////////////

// BSTR to string - FREES the bstring!
std::wstring stringFromFreedBSTR( BSTR bstr );


///////////////////////////////////////////////////////////////////////////////
// COM Singletons - will be released just before ~OleUninitialize()
///////////////////////////////////////////////////////////////////////////////

/*
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
*/

template<class T, const CLSID* clsid, const CLSID* iid = &mol::uuidof<T>()>
class COMSingleton
{
public:

	static T* instance() 
	{
		if ( t_ == 0 )
		{
			punk<T> p;
			HRESULT hr = ::CoCreateInstance( *clsid, 0, CLSCTX_INPROC_SERVER, *iid, (void**)&p);
			if ( hr != S_OK )
			{
				return 0;
			}

			LONG_PTR tmp = locked_comp_ex( &t_,p.interface_,0);
			if ( tmp == 0 )
			{
				ole::ole_init::addRef((IUnknown*)t_);
			}
		}
		return (T*)t_;
	}

private:

	static  T* t_;	
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
	return COMSingleton<T, clsid,  iid>::instance();
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
		if(t_ == 0 )
		{
			T* n = new T;
			LONG_PTR tmp = locked_comp_ex( &t_,n,0);
			if ( tmp == 0 )
			{
				mol::ole::ole_init::addRef((I*)t_);
			}
			else
			{
				delete n;
			}
		}

		return (T*)t_;
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

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

template<class T>
class CoTaskMemBuf
{
public:
	CoTaskMemBuf()
		:buf_(0)
	{

	}

	~CoTaskMemBuf()
	{
		if(buf_)
		{
			::CoTaskMemFree(buf_);
			buf_ = 0;
		}
	}

	operator T*()
	{
		return buf_;
	}

	T** operator&()
	{
		return &buf_;
	}

private:
	T* buf_;
};

///////////////////////////////////////////////////////////////////////////////

template<>
class CoTaskMemBuf<CAUUID>
{
public:

	CoTaskMemBuf()
	{}

	~CoTaskMemBuf()
	{
		if(cauuid_.pElems)
		{
			::CoTaskMemFree(cauuid_.pElems);
		}
	}

	operator CAUUID()
	{
		return cauuid_;
	}

	CAUUID* operator&()
	{
		return &cauuid_;
	}

	CAUUID* operator->()
	{
		return &cauuid_;
	}

private:
	CAUUID cauuid_;
};

///////////////////////////////////////////////////////////////////////////////

template<>
class CoTaskMemBuf<STATSTG>
{
public:

	CoTaskMemBuf()
	{
		::ZeroMemory(&statstg_,sizeof(STATSTG));
	}

	~CoTaskMemBuf()
	{
		if(statstg_.pwcsName)
		{
			::CoTaskMemFree(statstg_.pwcsName);
		}
	}

	void clear()
	{
		if(statstg_.pwcsName)
		{
			::CoTaskMemFree(statstg_.pwcsName);
		}
		::ZeroMemory(&statstg_,sizeof(STATSTG));
	}

	operator STATSTG()
	{
		return statstg_;
	}

	STATSTG* operator&()
	{
		return &statstg_;
	}

	STATSTG* operator->()
	{
		return &statstg_;
	}

private:
	STATSTG statstg_;
};

///////////////////////////////////////////////////////////////////////////////

typedef CoTaskMemBuf<WCHAR> CoStrBuf;
typedef CoTaskMemBuf<CAUUID> CoCAUUIDBuf;
typedef CoTaskMemBuf<STATSTG> CoSTATSTGBuf;

///////////////////////////////////////////////////////////////////////////////


} // end namespace mol

#endif
