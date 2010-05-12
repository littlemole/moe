#include "ole/aut.h"
#include "win/regkey.h"

namespace mol {
	
HRESULT typeLibForInterface(REFIID iid, ITypeLib** typeLib )
{
	if ( !typeLib )
		return E_POINTER;

	*typeLib = 0;
	mol::RegKey root(HKEY_CLASSES_ROOT);
	mol::RegKey interfaces = root.open(_T("Interface"),KEY_READ);
	mol::string siid = stringFromCLSID(iid);
	mol::RegKey iface = interfaces.open(siid);
	if ( iface )
	{
		mol::RegKey lib = iface.open(_T("TypeLib"),KEY_READ);
		if ( lib )
		{
			mol::string guid = lib.get();
			mol::string version = lib.get(_T("Version"));
			size_t pos = version.find(_T("."));
			if ( pos == mol::string::npos )
				return E_FAIL;
#ifdef _UNICODE
			int major = _wtoi( version.substr(0,pos).c_str() );
			int minor = _wtoi( version.substr(pos+1).c_str() );
#else
			int major = atoi( version.substr(0,pos).c_str() );
			int minor = atoi( version.substr(pos+1).c_str() );
#endif

			CLSID clsid;
			if ( S_OK == CLSIDFromString( (LPOLESTR)(mol::towstring(guid).c_str()),&clsid) )
			{
				TypeLib tl;
				tl.load(clsid,major,minor);
				return tl->QueryInterface(IID_ITypeLib,(void**)typeLib);
			}
		}
	}
	return S_OK;
}

HRESULT typeInfoForInterface(REFIID iid, ITypeInfo** typeinfo )
{
	try {
	if ( !typeinfo )
		return E_POINTER;
	*typeinfo = 0;

	punk<ITypeLib> typelib;
	if ( S_OK == typeLibForInterface( iid, &typelib) )
	{
		return typelib->GetTypeInfoOfGuid( iid, typeinfo );
	}
	}
	catch ( ...) {}
	return E_FAIL;
}

HRESULT findSourceOnCP(IUnknown* unk, IID* piid)
{
	if ( !piid )
		return E_POINTER;
	*piid = IID_NULL;

	punk<IConnectionPointContainer> cpc(unk);
	if ( !cpc )
		return E_FAIL;

	punk<IEnumConnectionPoints> ecp;
	if ( (S_OK != cpc->EnumConnectionPoints(&ecp)) || (!ecp) )
		return E_FAIL;

	unsigned long fetched = 1;
	int index = -1;
	while ( fetched != 0 )
	{
		index++;
		punk<IConnectionPoint> cp;
		if ( S_OK != ecp->Next(1,&cp,&fetched) )
			break;
		if ( fetched )
		{
			IID iid;
			if ( S_OK != cp->GetConnectionInterface(&iid) )
				continue;

			punk<ITypeInfo> typInf;
			HRESULT hr = typeInfoForInterface(iid,&typInf);							
			if ( hr != S_OK )
				continue;
			
			TYPEATTR* ta = NULL;
			if ( S_OK == typInf->GetTypeAttr(&ta) && ta )
			{
				*piid = ta->guid;
				typInf->ReleaseTypeAttr(ta);
				return S_OK;
			}
		} // if fetched
	} // end while
			
	return E_FAIL;
}
	
//////////////////////////////////////////////////////////////////////////
// disp invokes
//////////////////////////////////////////////////////////////////////////

void disp_invoke( IDispatch* disp, DISPID dispIdMember)
{
	DISPPARAMS dispparamsNoArgs = {NULL, NULL, 0, 0};

	disp->Invoke( dispIdMember, IID_NULL, 
				  LOCALE_SYSTEM_DEFAULT, 
				  DISPATCH_METHOD, 
				  &dispparamsNoArgs, 
				  NULL, NULL, NULL 
				 );
}

variant disp_call( IDispatch* disp, DISPID dispIdMember)
{
	DISPPARAMS dispparamsNoArgs = {NULL, NULL, 0, 0};

	variant varResult;
	disp->Invoke( dispIdMember, IID_NULL, 
				  LOCALE_SYSTEM_DEFAULT, 
				  DISPATCH_METHOD, 
				  &dispparamsNoArgs, 
				  &varResult, NULL, NULL 
				 );
	return varResult;
}

//////////////////////////////////////////////////////////////////////////
// disp properties
//////////////////////////////////////////////////////////////////////////


HRESULT get( IDispatch* disp, DISPID id, variant* var )
{
	DISPPARAMS dispparamsNoArgs = {NULL, NULL, 0, 0};
	HRESULT hr = disp->Invoke( id, IID_NULL, 
							   LOCALE_SYSTEM_DEFAULT,
		                       DISPATCH_PROPERTYGET,
						       &dispparamsNoArgs,
							   var, NULL, NULL);
	return hr;
}

HRESULT put( IDispatch* disp, DISPID id, variant* var )
{
	DISPID dispidNamed    = DISPID_PROPERTYPUT;
	DISPPARAMS dispparams = { var, &dispidNamed, 1, 1};

	HRESULT hr = disp->Invoke( id, IID_NULL, 
							   LOCALE_SYSTEM_DEFAULT,
		                       DISPATCH_PROPERTYPUT,
						       &dispparams,
							   NULL, NULL, NULL);
	return hr;
}

HRESULT put_ref( IDispatch* disp, DISPID id, variant* var )
{
	DISPID dispidNamed    = DISPID_PROPERTYPUT;
	DISPPARAMS dispparams = { var, &dispidNamed, 1, 1};

	HRESULT hr = disp->Invoke( id, IID_NULL, 
							   LOCALE_SYSTEM_DEFAULT,
		                       DISPATCH_PROPERTYPUTREF,
						       &dispparams,
							   NULL, NULL, NULL);
	return hr;
}



} // end namespace mol