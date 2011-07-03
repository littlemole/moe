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
friend class mol::Singleton<NetHost>;

public:

	~NetHost();

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

class DotNetNames 
{
friend class mol::Singleton<DotNetNames>;
public:

	size_t getId(const std::string& name);
	const std::string& getName(size_t id);

protected:
	~DotNetNames() {}
	DotNetNames() {}

private:
	std::map<size_t,std::string> id2Name_;
	std::map<std::string,size_t> name2Id_;

	mol::CriticalSection cs_;
};

class DotNetClassNames : public DotNetNames
{
friend class mol::Singleton<DotNetClassNames>;
};


#endif


