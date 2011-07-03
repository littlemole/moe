// types.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "netserver.h"
#include "dot.h"
#include "ole/aut.h"




////////////////////////////////////////////////////////////////////////

HRESULT wrapNETType(mol::variant& in, INetType** out)
{
	mol::punk<INetType> c;
	HRESULT hr = c.createObject(CLSID_DotNetType);
	if ( hr != S_OK )
		return S_FALSE;

	hr = c->Initialize(in);
	if ( hr != S_OK )
		return S_FALSE;

	::CoAllowSetForegroundWindow( (IUnknown*)c, 0);

	return c.queryInterface(out);
}

HRESULT wrapNETObject(mol::variant& in, VARIANT* out)
{
	if ( !out )
		return S_OK;

	if ( in.vt != VT_DISPATCH && in.vt != VT_UNKNOWN )
	{
		return ::VariantCopy( out, &in );
	}
				
	
	mol::punk<INetObject> no;
	HRESULT hr = no.createObject(CLSID_DotNetObject);
	if ( hr != S_OK )
		return hr;

	hr = no->Initialize(in);
	if ( hr != S_OK )
		return hr;
					
	::CoAllowSetForegroundWindow( (IUnknown*)no, 0);

	out->vt = VT_DISPATCH;
	return no.queryInterface( &(out->pdispVal) );
}

HRESULT unwrapNETObject( VARIANT in, VARIANT* out)
{
	if ( !out )
		return S_OK;

	if ( in.vt == VT_DISPATCH )
	{
		mol::punk<INetType> nc;
		HRESULT hr = in.pdispVal->QueryInterface( IID_INetType, (void**)&nc);
		if ( hr == S_OK && nc)
		{
			mol::variant v;
			hr = nc->UnWrap(out);
			return hr;
		}
		mol::punk<INetObject> no;
		hr = in.pdispVal->QueryInterface( IID_INetObject, (void**)&no);
		if ( hr == S_OK && no)
		{
			mol::variant v;
			hr = no->UnWrap(out);
			return hr;
		}
	}
	return ::VariantCopy( out, &(in) );
}



////////////////////////////////////////////////////////////////////////

NetApp::NetApp()
{
	//HRESULT hr = net.createObject(CLSID_Net,CLSCTX_ALL);
}
////////////////////////////////////////////////////////////////////////


void NetObject::dispose()
{}
	
HRESULT __stdcall NetObject::GetTypeInfoCount (unsigned int FAR*  pctinfo ) 
{ 
    *pctinfo = 0;
    return S_OK; 
}

HRESULT __stdcall NetObject::GetTypeInfo ( unsigned int  iTInfo, LCID  lcid, ITypeInfo FAR* FAR*  ppTInfo ) 
{ 
	*ppTInfo = 0;
    return E_NOTIMPL; 
}


HRESULT __stdcall NetObject::Initialize(VARIANT ptr)
{
	v_ = ptr;
	return S_OK;
}

HRESULT __stdcall NetObject::UnWrap(VARIANT* ptr)
{
	if ( !ptr )
		return E_INVALIDARG;

	return ::VariantCopy(ptr,&v_);
}


HRESULT __stdcall NetObject::GetIDsOfNames( REFIID  riid, OLECHAR FAR* FAR*  rgszNames, unsigned int  cNames, LCID   lcid, DISPID FAR*  rgDispId ) 
{ 
	OLECHAR* name = rgszNames[0];
	std::string n = mol::tostring(name);

	DISPID id = (DISPID) mol::singleton<DotNetNames>().getId(n);
	rgDispId[0] = id;
	return S_OK;
}

HRESULT  __stdcall NetObject::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn, EXCEPINFO * ex, UINT * i) 
{ 
	std::string name = mol::singleton<DotNetNames>().getName(dispIdMember);

	VARIANT vnull;
	::VariantInit(&vnull);
	vnull.vt = VT_EMPTY;
	vnull.pdispVal = 0;

	mol::punk<_Net> net;
	HRESULT hr = net.createObject(CLSID_Net,CLSCTX_ALL);
	if ( hr != S_OK )
		return S_FALSE;

	mol::variant vRet;
	if (  w & DISPATCH_PROPERTYGET ) 
	{	
		if ( pDisp->cArgs == 0 )
		{
			hr = net->InvokeMethod( vnull, v_, mol::bstr(name),0, DISPATCH_PROPERTYGET, &vRet );
			if ( hr == S_OK )
			{
				return wrapNETObject(vRet,pReturn);
			}
			return hr;
		}
		return S_FALSE;
	}

	if (  w & DISPATCH_PROPERTYPUT ) 
	{	
		mol::ArrayBound ab(pDisp->cArgs);
		mol::SafeArray<VT_VARIANT> sa(ab);

		mol::SFAccess<VARIANT> sfa(sa);
		for ( UINT i = 0; i < pDisp->cArgs; i++ )
		{
			VARIANTARG varg = pDisp->rgvarg[pDisp->cArgs-1-i];
			HRESULT hr = unwrapNETObject(varg,&(sfa[i]));
		}

		hr = net->InvokeMethod( vnull, v_, mol::bstr(name),sa, DISPATCH_PROPERTYPUT, &vRet );
		if ( hr == S_OK )
		{
			return wrapNETObject(vRet,pReturn);
		}
		return hr;
	}
		
	if ( pDisp->cArgs == 0 )
	{
		hr = net->InvokeMethod( vnull, v_, mol::bstr(name),0, DISPATCH_METHOD, &vRet );
		if ( hr == S_OK )
		{
			return wrapNETObject(vRet,pReturn);
		}
		return hr;
	}

	mol::ArrayBound ab(pDisp->cArgs);
	mol::SafeArray<VT_VARIANT> sa(ab);

	mol::SFAccess<VARIANT> sfa(sa);
	for ( UINT i = 0; i < pDisp->cArgs; i++ )
	{
		VARIANTARG varg = pDisp->rgvarg[pDisp->cArgs-1-i];
		HRESULT hr = unwrapNETObject(varg,&(sfa[i]));
	}

	hr = net->InvokeMethod( vnull, v_, mol::bstr(name),sa, DISPATCH_METHOD, &vRet );
	if ( hr == S_OK )
	{
		return wrapNETObject(vRet,pReturn);
	}
	return S_OK;

}



////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////



void NetAssembly::dispose()
{

}
	
HRESULT __stdcall NetAssembly::GetTypeInfoCount (unsigned int FAR*  pctinfo ) 
{ 
    *pctinfo = 0;
    return S_OK; 
}

HRESULT __stdcall NetAssembly::GetTypeInfo ( unsigned int  iTInfo, LCID  lcid, ITypeInfo FAR* FAR*  ppTInfo ) 
{ 
	*ppTInfo = 0;
    return E_NOTIMPL; 
}

HRESULT __stdcall NetAssembly::Initialize(VARIANT ptr)
{
	v_ = ptr;
	return S_OK;
}

HRESULT __stdcall NetAssembly::UnWrap(VARIANT* ptr)
{
	if ( !ptr )
		return E_INVALIDARG;

	return ::VariantCopy(ptr,&v_);
}

HRESULT __stdcall NetAssembly::GetIDsOfNames( REFIID  riid, OLECHAR FAR* FAR*  rgszNames, unsigned int  cNames, LCID   lcid, DISPID FAR*  rgDispId ) 
{ 
	OLECHAR* name = rgszNames[0];
	std::string n = mol::tostring(name);

	if ( n == "New" )
	{
		rgDispId[0] = 6;
		return S_OK;
	}

	return mol::Dispatch<INetAssembly>::GetIDsOfNames( riid, rgszNames, cNames, lcid, rgDispId );
}



HRESULT __stdcall NetAssembly::Type( BSTR typeName, INetType** clazz)
{
	if ( !typeName )
	{
		mol::com_throw("invalid typeName",CLSID_DotNet,".NET error");
		return S_FALSE;
	}

	if ( !clazz )
	{
		return S_FALSE;
	}

	*clazz = 0;

	mol::punk<_Net> net;
	HRESULT hr = net.createObject(CLSID_Net);
	if ( hr != S_OK )
		return S_FALSE;

	mol::variant v;
	hr = net->LoadClass( v_, typeName, &v );
	if ( hr != S_OK )
		return S_FALSE;

	return wrapNETType(v,clazz);
}

HRESULT __stdcall NetAssembly::Connect(IDispatch* ptr, BSTR eventName, VARIANT target)
{
	mol::punk<_Net> net;
	HRESULT hr = net.createObject(CLSID_Net);
	if ( hr != S_OK )
		return S_FALSE;

	mol::variant v;
	hr = unwrapNETObject(target,&v);
	if ( hr != S_OK )
		return S_FALSE;

	mol::variant vptr(ptr);
	hr = net->Event( v,  eventName, vptr);
	return hr;
}

HRESULT __stdcall NetAssembly::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn, EXCEPINFO * ex, UINT * i) 
{ 
		
	VARIANT vnull;
	::VariantInit(&vnull);
	vnull.vt = VT_NULL;
	vnull.pdispVal = 0;

	mol::punk<_Net> net;
	HRESULT hr = net.createObject(CLSID_Net,CLSCTX_ALL);
	if ( hr != S_OK )
		return S_FALSE;

	// create class
	if ( dispIdMember == 6 ) 
	{		
		mol::variant v;
		if ( pDisp->cArgs == 0 )
		{
			hr =  net->CreateObject( v_, 0, &v );
			if ( hr == S_OK )
			{
				return wrapNETObject(v,pReturn);
			}
			return hr;
		}

		mol::ArrayBound ab(pDisp->cArgs);
		mol::SafeArray<VT_VARIANT> sa(ab);

		mol::SFAccess<VARIANT> sfa(sa);

		for ( UINT i = 0; i < pDisp->cArgs; i++ )
		{
			::VariantCopy( &(sfa[i]), &(pDisp->rgvarg[pDisp->cArgs-1-i]) );
		}

		hr = net->CreateObject( v_, sa, &v );
		if ( hr == S_OK )
		{
			return wrapNETObject(v,pReturn);
		}
		return hr;
	}
	
	return mol::Dispatch<INetAssembly>::Invoke(dispIdMember, riid, lcid, w, pDisp, pReturn, ex, i );
}



////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////


void NetType::dispose()
{

}
	
HRESULT __stdcall NetType::GetTypeInfoCount (unsigned int FAR*  pctinfo ) 
{ 
    *pctinfo = 0;
    return S_OK; 
}

HRESULT __stdcall NetType::GetTypeInfo ( unsigned int  iTInfo, LCID  lcid, ITypeInfo FAR* FAR*  ppTInfo ) 
{ 
	*ppTInfo = 0;
    return E_NOTIMPL; 
}

HRESULT __stdcall NetType::Initialize(VARIANT ptr)
{
	v_ = ptr;
	return S_OK;
}

HRESULT __stdcall NetType::UnWrap(VARIANT* ptr)
{
	if ( !ptr )
		return E_INVALIDARG;

	return ::VariantCopy(ptr,&v_);
}

HRESULT __stdcall NetType::GetIDsOfNames( REFIID  riid, OLECHAR FAR* FAR*  rgszNames, unsigned int  cNames, LCID   lcid, DISPID FAR*  rgDispId ) 
{ 
	OLECHAR* name = rgszNames[0];
	std::string n = mol::tostring(name);

	if ( n == "New" )
	{
		rgDispId[0] = 0;
		return S_OK;
	}

	DISPID id = (DISPID) mol::singleton<DotNetClassNames>().getId(n);
	rgDispId[0] = id;
	return S_OK;
}


HRESULT __stdcall NetType::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn, EXCEPINFO * ex, UINT * i) 
{ 
		
	VARIANT vnull;
	::VariantInit(&vnull);
	vnull.vt = VT_NULL;
	vnull.pdispVal = 0;

	mol::punk<_Net> net;
	HRESULT hr = net.createObject(CLSID_Net,CLSCTX_ALL);
	if ( hr != S_OK )
		return S_FALSE;

	mol::variant vRet;
	// create net obj via constructor
	if ( dispIdMember == 0 ) 
	{				
		if ( pDisp->cArgs == 0 )
		{			
			hr =  net->CreateObject( v_, 0, &vRet );
			if ( hr == S_OK )
			{
				return wrapNETObject(vRet,pReturn);
			}
			return hr;
		}

		mol::ArrayBound ab(pDisp->cArgs);
		mol::SafeArray<VT_VARIANT> sa(ab);

		mol::SFAccess<VARIANT> sfa(sa);

		for ( UINT i = 0; i < pDisp->cArgs; i++ )
		{
			VARIANTARG varg = pDisp->rgvarg[pDisp->cArgs-1-i];
			HRESULT hr = unwrapNETObject( varg, &(sfa[i]) );
		}

		hr = net->CreateObject( v_, sa, &vRet );
		if ( hr == S_OK )
		{
			return wrapNETObject(vRet,pReturn);
		}
		return hr;
	}
	
	// invoke a static class method
	std::string name = mol::singleton<DotNetClassNames>().getName(dispIdMember); //idsOfNames_[dispIdMember];

	if (  w & DISPATCH_PROPERTYGET ) 
	{	
		if ( pDisp->cArgs == 0 )
		{
			hr = net->InvokeMethod( v_, vnull, mol::bstr(name),0, DISPATCH_PROPERTYGET, &vRet );
			if ( hr == S_OK )
			{
				return wrapNETObject(vRet,pReturn);
			}
			return hr;
		}
		return E_FAIL;
	}

	if (  w & DISPATCH_PROPERTYPUT ) 
	{	
		if ( pDisp->cArgs == 0 )
		{
			return E_FAIL;
		}

		mol::ArrayBound ab(pDisp->cArgs);
		mol::SafeArray<VT_VARIANT> sa(ab);

		mol::SFAccess<VARIANT> sfa(sa);
		for ( UINT i = 0; i < pDisp->cArgs; i++ )
		{
			VARIANTARG varg = pDisp->rgvarg[pDisp->cArgs-1-i];
			HRESULT hr = unwrapNETObject( varg, &(sfa[i]) );
		}

		hr = net->InvokeMethod( v_, vnull, mol::bstr(name),sa, DISPATCH_PROPERTYPUT, &vRet );
		if ( hr == S_OK )
		{
			return wrapNETObject(vRet,pReturn);
		}
		return S_OK;
	}

		
	if ( pDisp->cArgs == 0 )
	{
		hr = net->InvokeMethod( v_, vnull, mol::bstr(name),0, DISPATCH_METHOD, &vRet );
		if ( hr == S_OK )
		{
			return wrapNETObject(vRet,pReturn);
		}
		return hr;
	}

	mol::ArrayBound ab(pDisp->cArgs);
	mol::SafeArray<VT_VARIANT> sa(ab);

	mol::SFAccess<VARIANT> sfa(sa);
	for ( UINT i = 0; i < pDisp->cArgs; i++ )
	{
		VARIANTARG varg = pDisp->rgvarg[pDisp->cArgs-1-i];
		HRESULT hr = unwrapNETObject( varg, &(sfa[i]) );
	}

	hr = net->InvokeMethod( v_, vnull, mol::bstr(name),sa, DISPATCH_METHOD, &vRet );
	if ( hr == S_OK )
	{
		return wrapNETObject(vRet,pReturn);
	}
	return S_OK;
}



////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////



NetServer::NetServer()
{
}

void NetServer::dispose()
{
	::PostThreadMessage(mol::guithread(),WM_QUIT,0,0);
}


HRESULT __stdcall NetServer::Exit()
{
	::PostThreadMessage(mol::guithread(),WM_QUIT,0,0);
	return S_OK;
}

HRESULT __stdcall  NetServer::Import(BSTR typeName, INetAssembly** a)
{
	
	mol::punk<_Net> net;
	HRESULT hr = net.createObject(CLSID_Net);
	if ( hr != S_OK )
		return S_FALSE;

	mol::variant v;
	hr = net->LoadAssembly(typeName,&v);

	mol::punk<INetAssembly> pa;
	hr = pa.createObject(CLSID_DotNetAssembly);
	if ( hr != S_OK )
		return S_FALSE;

	hr = pa->Initialize(v);
	if ( hr != S_OK )
		return S_FALSE;

	if (a)
	{
		hr = pa.queryInterface(a);
	}
	return hr;
}


HRESULT __stdcall NetServer::Type( BSTR typeName, INetType** clazz)
{
	if ( !typeName )
	{
		mol::com_throw("invalid typeName",CLSID_DotNet,".NET error");
		return S_FALSE;
	}

	if ( !clazz )
	{
		return S_FALSE;
	}

	*clazz = 0;

	mol::punk<_Net> net;
	HRESULT hr = net.createObject(CLSID_Net);
	if ( hr != S_OK )
		return S_FALSE;

	mol::variant empty;
	mol::variant v;
	hr = net->LoadClass( empty, typeName, &v );
	if ( hr != S_OK )
		return S_FALSE;

	mol::punk<INetType> c;
	hr = c.createObject(CLSID_DotNetType);
	if ( hr != S_OK )
		return S_FALSE;

	hr = c->Initialize(v);
	if ( hr != S_OK )
		return S_FALSE;

	::CoAllowSetForegroundWindow( (IUnknown*)c, 0);
	return c.queryInterface( clazz );	
}

HRESULT __stdcall NetServer::Connect(IDispatch* ptr, BSTR eventName, VARIANT target)
{
	mol::punk<_Net> net;
	HRESULT hr = net.createObject(CLSID_Net);
	if ( hr != S_OK )
		return S_FALSE;

	mol::variant v;
	hr = unwrapNETObject(target,&v);
	if ( hr != S_OK )
		return S_FALSE;

	mol::variant vptr(ptr);	
	hr = net->Event( v,  eventName, vptr);
	return hr;

}

///////////////////////////////////////////////////////////


HRESULT __stdcall NetServer::GetIDsOfNames( REFIID  riid, OLECHAR FAR* FAR*  rgszNames, unsigned int  cNames, LCID   lcid, DISPID FAR*  rgDispId ) 
{ 
	OLECHAR* name = rgszNames[0];
	std::string n = mol::tostring(name);

	if ( n == "New" )
	{
		rgDispId[0] = 6;
		return S_OK;
	}

	return mol::Dispatch<INet>::GetIDsOfNames( riid, rgszNames, cNames, lcid, rgDispId );
}

HRESULT  __stdcall NetServer::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn, EXCEPINFO * ex, UINT * i) 
{ 
	if ( dispIdMember == 6 )
	{
		return S_OK;
	}

	return mol::Dispatch<INet>::Invoke(dispIdMember, riid, lcid, w, pDisp, pReturn, ex, i );
}

	
HRESULT __stdcall NetServer::GetTypeInfoCount (unsigned int FAR*  pctinfo ) 
{ 
    *pctinfo = 0;
    return S_OK; 
}

HRESULT __stdcall NetServer::GetTypeInfo ( unsigned int  iTInfo, LCID  lcid, ITypeInfo FAR* FAR*  ppTInfo ) 
{ 
	*ppTInfo = 0;
    return E_NOTIMPL; 
}


////////////////////////////////////////////////////////////////////////


