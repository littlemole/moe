#ifndef MOL_DOTNET_DEF_GUARDX_DEFINE_
#define MOL_DOTNET_DEF_GUARDX_DEFINE_

#include "ole/punk.h"

// .NET native interfaces
#include <mscoree.h>

// .NET imported typelib
#include "mscorlib_tlh.h"


class NetHost;

// access to NetHost only via singleton
NetHost& NET();

class NetHost
{
SINGLETON(NetHost);
public:

	bool start(bool disable);

	bool aware();

	ICorRuntimeHost* operator->();
	mscorlib::_AppDomain* DefaultDomain();

	HRESULT CreateDomain( const mol::string& name, mscorlib::_AppDomain** ad );

	HRESULT CreateInstance( const mol::string& assembly, 
							const mol::string& type,
							IDispatch** disp);

	template<class I>
	HRESULT CreateInstance( const mol::string& assembly, 
							const mol::string& type,
							I** i)
	{
		if (!i)
			return E_INVALIDARG;
		
		*i = 0;

		mol::punk<IDispatch> disp;
		HRESULT hr = CreateInstance( assembly, type, &disp );
		if ( hr == S_OK && disp )
		{
			return disp->QueryInterface( mol::uuidof<I>(), (void**) i );
		}
		return hr;
	}

private:

	NetHost();
	~NetHost();

	bool									aware_;
	ICorRuntimeHost*						host_;
	mol::punk<mscorlib::_AppDomain>			appDomain_;
};


class Domain
{
public:

	Domain();
	~Domain();

	mscorlib::_AppDomain* operator->();
	operator mscorlib::_AppDomain* ();

	HRESULT CreateInstance( const mol::string& assembly, 
							const mol::string& type,
							IDispatch** disp);

	template<class I>
	HRESULT CreateInstance( const mol::string& assembly, 
							const mol::string& type,
							I** i)
	{
		if (!i)
			return E_INVALIDARG;
		
		*i = 0;

		mol::punk<IDispatch> disp;

		HRESULT hr = CreateInstance( assembly, type, &disp );

		if ( hr == S_OK && disp )
		{
			return disp->QueryInterface( mol::uuidof<I>(), (void**) i );
		}
		return hr;
	}

private:

	mol::punk<mscorlib::_AppDomain> domain_;
};

#endif


