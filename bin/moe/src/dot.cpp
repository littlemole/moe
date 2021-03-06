#include "stdafx.h"
#include "dot.h"

using namespace mol;

NetHost& NET()
{
	return mol::Singleton<NetHost>::instance();
}

NetHost::NetHost()
	: aware_(false)
{	
	host_ = 0;
}

bool NetHost::start(bool enable)
{
	//if ( !enable )
	//	return false;
	// dynamically try to load mscoree.dll and retrieve 
	// CorBindToRuntimeEx function ptr instead of
	// linking with mscoree.lib, so we do not have a 
	// binary dependency on .NET - if there is none
	// acceptable, we just degrade and don't allow .NET 
	// initialization. of course any .NET calls will fail, 
	// then.

	typedef HRESULT (__stdcall *CorBindToRuntimeExFunc)(LPCWSTR pwszVersion, LPCWSTR pwszBuildFlavor, DWORD startupFlags, REFCLSID rclsid, REFIID riid, LPVOID FAR *ppv);

	CorBindToRuntimeExFunc CorBindToRuntimeExFuncPtr = (CorBindToRuntimeExFunc)mol::dllFunc( _T("mscoree.dll"), _T("CorBindToRuntimeEx"));

	if ( !CorBindToRuntimeExFuncPtr )
	{
		return false;
	}

	if ( S_OK != CorBindToRuntimeExFuncPtr(
						NULL, 
						L"wks", 
						0, 
						CLSID_CorRuntimeHost , 
						IID_ICorRuntimeHost,
						(PVOID*)&host_
						))
		return false;


	if ( S_OK != host_->Start() )
		return false;

	punk<IUnknown> unk;

	if ( S_OK != host_->GetDefaultDomain ( &unk ) )
		return false;

	if ( S_OK != unk->QueryInterface( mscorlib::IID__AppDomain, (void**) &appDomain_) )
		return false;

	aware_ = true;
	return true;
}

ICorRuntimeHost* NetHost::operator->() 
{ 
	return host_; 
}

mscorlib::_AppDomain* NetHost::DefaultDomain() 
{ 
	return appDomain_.interface_; 
}


HRESULT NetHost::CreateDomain( const mol::string& name, mscorlib::_AppDomain** ad )
{
	if ( !ad )
		return E_INVALIDARG;

	punk<IUnknown> unkSetup;
	HRESULT hr = host_->CreateDomainSetup(&unkSetup);

	punk<mscorlib::IAppDomainSetup> setup(unkSetup);

	if(setup)
	{
		//bstr btrue(L"true");
		//hr = setup->put_ShadowCopyFiles(btrue);
		//if ( S_OK != hr )
		//	return hr;		

		punk<IUnknown> unkDomain;
		hr = host_->CreateDomainEx( mol::towstring(name).c_str(),0,0, &unkDomain );// (IUnknown*)(mscorlib::IAppDomainSetup*)setup, 0, &unkDomain );
		if ( S_OK != hr )
			return hr;		
		return unkDomain->QueryInterface( mscorlib::IID__AppDomain, (void**) ad);
	}

	return E_UNEXPECTED;
}

HRESULT NetHost::CreateInstance( const mol::string& assembly, const mol::string& type, IDispatch** disp)
{
	if ( !disp )
		return E_INVALIDARG;

	*disp = 0;

	if ( !appDomain_)
		return E_UNEXPECTED;

	punk<mscorlib::_ObjectHandle> object_;

	HRESULT hr = appDomain_->CreateInstance( bstr(assembly), bstr(type), &object_ );
	if ( hr != S_OK )
		return hr;

	variant var;
	hr = object_->Unwrap(&var);
	if ( hr != S_OK )
		return hr;

	return var.punkVal->QueryInterface(IID_IDispatch, (void**) disp);
	
}

NetHost::~NetHost()
{
	if ( aware_ )
		host_->Stop();
}

bool NetHost::aware()
{
	return aware_;
}


Domain::Domain()
{
	static int i = 0;
	i++;
	mol::ostringstream oss;
	oss << _T("Moe.Form.Domain.") << i;

	if ( S_OK != NET().CreateDomain( oss.str(), &domain_ ))
	{
		throw mol::X( _T("create appdomain failed"));
	}
}

Domain::~Domain()
{
	HRESULT hr = NET()->UnloadDomain(domain_);
	if ( hr != S_OK )
		throw mol::X(_T("unload appdomain failed"));
}

mscorlib::_AppDomain* Domain::operator->() 
{ 
	return domain_.interface_; 
}

Domain::operator mscorlib::_AppDomain* () 
{ 
	return domain_.interface_; 
}

HRESULT Domain::CreateInstance( const mol::string& assembly, const mol::string& type, IDispatch** disp)
{
	if ( !disp )
		return E_INVALIDARG;

	*disp = 0;

	if ( !domain_)
		return E_UNEXPECTED;

	punk<mscorlib::_ObjectHandle> object_;

	HRESULT hr = domain_->CreateInstance( bstr(assembly), bstr(type), &object_ );
	if ( hr != S_OK )
		return hr;

	variant var;
	hr = object_->Unwrap(&var);
	if ( hr != S_OK )
		return hr;

	return var.punkVal->QueryInterface(IID_IDispatch, (void**) disp);	
}


