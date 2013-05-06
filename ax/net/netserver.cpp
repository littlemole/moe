// types.cpp : Definiert den Einstiegspunkt f�r die Konsolenanwendung.
//

#include "stdafx.h"
#include "netserver.h"
#include "dot.h"
#include "ole/aut.h"

DWORD DISPID_NEW = 0;
DWORD DISPID_OF  = 1;


////////////////////////////////////////////////////////////////////////


template<class T>
HRESULT wrapNETType(mol::variant& in, T** out)
{
	mol::punk<INetType> c;
	HRESULT hr = c.createObject(CLSID_DotNetType,CLSCTX_ALL);
	if ( hr != S_OK )
		return S_FALSE;

	hr = c->Initialize(in);
	if ( hr != S_OK )
		return S_FALSE;

	::CoAllowSetForegroundWindow( (IUnknown*)c, 0);

	return c.queryInterface(out);
}

HRESULT wrapNETType(mol::variant& in, VARIANT* out)
{
	if(!out)
		return E_INVALIDARG;

	mol::punk<INetType> c;
	HRESULT hr = wrapNETType(in,&c);
	if ( hr != S_OK )
		return S_FALSE;

	out->vt = VT_DISPATCH;
	return c.queryInterface(&out->pdispVal);
}

HRESULT wrapNETObject(VARIANT& in, VARIANT* out)
{
	if ( !out )
		return S_OK;

	if ( in.vt != VT_DISPATCH && in.vt != VT_UNKNOWN )
	{
		out->vt = VT_DISPATCH;
		return ::VariantCopy( out, &in );
	}
				
	
	mol::punk<INetObject> no;
	HRESULT hr = no.createObject(CLSID_DotNetObject,CLSCTX_ALL);
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
			hr = nc->UnWrap(out);
			return hr;
		}
		mol::punk<INetObject> no;
		hr = in.pdispVal->QueryInterface( IID_INetObject, (void**)&no);
		if ( hr == S_OK && no)
		{
			hr = no->UnWrap(out);
			return hr;
		}
	}
	//out->vt = in.vt;
	return ::VariantCopy( out, &(in) );
}



class DispParamsBuf : public DISPPARAMS
{
public:
	DispParamsBuf(UINT nArgs)
	{
		cArgs = nArgs;
		cNamedArgs = 0;
		rgvarg = new VARIANTARG[cArgs];
		rgdispidNamedArgs = 0;		
	}

	~DispParamsBuf()
	{
		for ( UINT i = 0; i < cArgs; i++)
		{
			if ( rgvarg[i].vt == VT_BSTR )
				::SysFreeString(rgvarg[i].bstrVal);
			if ( rgvarg[i].vt == VT_UNKNOWN )
				rgvarg[i].punkVal->Release();
			if ( rgvarg[i].vt == VT_DISPATCH )
				rgvarg[i].punkVal->Release();
		}
		delete[] rgvarg;
	}

	void set(UINT index, IDispatch* disp)
	{
		rgvarg[index].vt = VT_DISPATCH;
		rgvarg[index].pdispVal = disp;
		disp->AddRef();
	}

};

class SafeArrayFromDispParams
{
public:

	mol::SafeArray<VT_VARIANT> value;

	SafeArrayFromDispParams(DISPPARAMS* params, UINT nArgs = -1)
	{
		nArgs = nArgs == -1 ? params->cArgs - params->cNamedArgs : nArgs;

		if ( nArgs > 0 )
		{
			mol::ArrayBound ab(nArgs);
			value.Create(ab);

			mol::SFAccess<VARIANT> sfa(value);
			for ( UINT i = 0; i < nArgs; i++ )
			{
				VARIANTARG varg = params->rgvarg[params->cArgs-1-i];
				HRESULT hr = unwrapNETObject(varg,&(sfa[i]));
			}
		}
	}
};


HRESULT Namespace::CreateInstance(IDispatch** d, const std::string& path, INet* net)
{
	Instance* i = new Instance;
	i->path_ = path;
	i->lastId_ = 0;
	i->inet_ = net;
	return i->QueryInterface(IID_IDispatch,(void**)d);
}

HRESULT __stdcall Namespace::GetIDsOfNames( REFIID  riid, OLECHAR FAR* FAR*  rgszNames, unsigned int  cNames, LCID   lcid, DISPID FAR*  rgDispId )
{
	OLECHAR* name = rgszNames[0];
	std::string n = mol::tostring(name);

	if ( name2id_.count(n) == 0 )
	{
		lastId_++;
		name2id_.insert(std::make_pair(n,lastId_));
		id2name_.insert(std::make_pair(lastId_,n));
	}

	rgDispId[0] = name2id_[n];
	return S_OK;
}

HRESULT __stdcall Namespace::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn, EXCEPINFO * ex, UINT * i)
{
	if( id2name_.count(dispIdMember) == 0 )
		return E_INVALIDARG;

	mol::punk<_Net> net;
	HRESULT hr = net.createObject(CLSID_Net);
	if ( hr != S_OK )
		return S_FALSE;

	std::string name = id2name_[dispIdMember];
	std::string n = path_;

	// check for generic type binding
	if ( name == "of" )
	{
		std::ostringstream oss;
		int n = pDisp->cArgs - pDisp->cNamedArgs;
		oss << path_ << "`" << n;

		// try to load as .NET type
		mol::variant empty;
		mol::variant v;
		hr = net->LoadClass( empty, mol::bstr(oss.str()), &v );
		if ( hr == S_OK && (v.vt == VT_DISPATCH || v.vt == VT_UNKNOWN) && v.pdispVal )
		{
			SafeArrayFromDispParams sa(pDisp);
			mol::variant r;
			hr = net->MakeGeneric(v,sa.value,&r);
			if ( hr == S_OK && ( r.vt == VT_DISPATCH || r.vt == VT_UNKNOWN) && r.punkVal)
			{
				return wrapNETType(r,pReturn);
			}
		}
		return S_OK;
	}

	if(!n.empty())
	{
		n += ".";
	}
	n += name;

	if (w & DISPATCH_PROPERTYPUT)
	{
		mol::punk<IDispatch> disp;
		hr = inet_->Prototype( mol::bstr(n), pDisp->rgvarg[0],&disp);
		if ( hr != S_OK )
			return hr;

		return S_OK;
	}

	// try to load as .NET type
	mol::variant empty;
	mol::variant v;
	hr = net->LoadClass( empty, mol::bstr(n), &v );
	if ( hr == S_OK && (v.vt == VT_DISPATCH || v.vt == VT_UNKNOWN) && v.pdispVal )
	{

		mol::punk<IDispatch> disp;
		hr = wrapNETType(v,&disp);
		if ( hr != S_OK )
			return hr;

		if(pReturn)
		{
			if  (w == DISPATCH_PROPERTYGET)
			{
				if ( hr == S_OK && pReturn )
				{				
					pReturn->vt = VT_DISPATCH;
					return disp.queryInterface(&pReturn->pdispVal);
				}
				return S_OK;	
			}
			else if (w & DISPATCH_METHOD )
			{
				DWORD dispid_new = 0;
				HRESULT hr = disp->Invoke( dispid_new,riid,lcid,DISPATCH_PROPERTYGET,pDisp,pReturn,ex,i);
				return hr;
			}
		}
	}

	// no type found, produce another namespace element
	mol::punk<IDispatch> ns;
	hr = Namespace::CreateInstance(&ns,n,inet_);
	if ( hr != S_OK )
		return hr;

	if(pReturn)
	{
		pReturn->vt = VT_DISPATCH;
		return ns.queryInterface(&pReturn->pdispVal);
	}

	return S_OK;
}


HRESULT EventHandler::CreateInstance(IDispatch* handler, IDispatch** d)
{
	Instance* i = new Instance;
	i->handler_ = handler;
	return i->QueryInterface(IID_IDispatch,(void**)d);
}

HRESULT __stdcall EventHandler::GetIDsOfNames( REFIID  riid, OLECHAR FAR* FAR*  rgszNames, unsigned int  cNames, LCID   lcid, DISPID FAR*  rgDispId )
{
	OLECHAR* name = rgszNames[0];
	rgDispId[0] = 0;
	return S_OK;
}

HRESULT __stdcall EventHandler::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn, EXCEPINFO * ex, UINT * e)
{
	if( dispIdMember != 0 )
		return E_UNEXPECTED;

	DispParamsBuf params(pDisp->cArgs);
	HRESULT hr;
	for ( UINT i = 0; i < pDisp->cArgs; i++)
	{
		mol::variant v;
		hr = wrapNETObject(pDisp->rgvarg[i],&v);
		params.set(i,v.pdispVal);
	}

	hr = handler_->Invoke(0,IID_NULL,LOCALE_SYSTEM_DEFAULT,w,&params,pReturn,ex,e);
	return hr;
}


////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////

NetApp::NetApp()
{}

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

	ptr->vt = VT_DISPATCH;
	ptr->pdispVal = v_.pdispVal;
	v_.pdispVal->AddRef();
	return S_OK;

}

HRESULT __stdcall NetObject::On(BSTR eventName, IDispatch* handler)
{
	mol::punk<_Net> net;
	HRESULT hr = net.createObject(CLSID_Net);
	if ( hr != S_OK )
		return S_FALSE;

	mol::punk<IDispatch> disp;
	EventHandler::CreateInstance(handler,&disp);

	mol::variant vptr(disp);	
	hr = net->Event( v_,  eventName, vptr);
	return hr;
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

	if(name=="On")
	{
		if ( pDisp->cArgs == 2 )
		{
			return this->On(
							pDisp->rgvarg[1].bstrVal,
							pDisp->rgvarg[0].pdispVal
						);
		}
	}

	mol::vEmpty vempty;

	mol::punk<_Net> net;
	HRESULT hr = net.createObject(CLSID_Net,CLSCTX_ALL);
	if ( hr != S_OK )
		return S_FALSE;

	mol::variant vRet;
	if (  w == DISPATCH_PROPERTYGET ) 
	{	
		if ( pDisp->cArgs == 0 )
		{
			hr = net->InvokeMethod( vempty, v_, mol::bstr(name),0, DISPATCH_PROPERTYGET, &vRet );
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
		SafeArrayFromDispParams sa(pDisp,pDisp->cArgs);
		hr = net->InvokeMethod( vempty, v_, mol::bstr(name),sa.value, DISPATCH_PROPERTYPUT, &vRet );
		if ( hr != S_OK )
			return hr;
		return wrapNETObject(vRet,pReturn);		
	}
		
	if ( pDisp->cArgs == 0 )
	{
		hr = net->InvokeMethod( vempty, v_, mol::bstr(name),0, DISPATCH_METHOD, &vRet );
		if ( hr == S_OK )
		{
			return wrapNETObject(vRet,pReturn);
		}
		return hr;
	}

	SafeArrayFromDispParams sa(pDisp);
	hr = net->InvokeMethod( vempty, v_, mol::bstr(name),sa.value, DISPATCH_METHOD, &vRet );
	if ( hr != S_OK )
		return hr;
	return wrapNETObject(vRet,pReturn);
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

	ptr->vt = VT_UNKNOWN;
	ptr->punkVal = v_.punkVal;
	v_.punkVal->AddRef();
	return S_OK;
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
	if ( n == "of" )
	{
		rgDispId[0] =  3;
		return S_OK;
	}
	
	DISPID id = (DISPID) mol::singleton<DotNetClassNames>().getId(n);
	rgDispId[0] = id;
	return S_OK;
}


HRESULT __stdcall NetType::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn, EXCEPINFO * ex, UINT * i) 
{ 
	mol::vNull vnull;

	mol::punk<_Net> net;
	HRESULT hr = net.createObject(CLSID_Net,CLSCTX_ALL);
	if ( hr != S_OK )
		return hr;

	mol::variant vRet;

	// generic type 
	if ( dispIdMember == 3 ) 
	{
		SafeArrayFromDispParams sa(pDisp);
		hr = net->MakeGeneric( v_, sa.value, &vRet );
		if ( hr != S_OK )
			return hr;

		return wrapNETType(vRet,pReturn);
	}
	
	// create net obj via constructor
	if ( dispIdMember == 0 ) 
	{		
		SafeArrayFromDispParams sa(pDisp);
		hr = net->CreateObject( v_, sa.value, &vRet );
		if ( hr != S_OK )
			return hr;

		return wrapNETObject(vRet,pReturn);
	}
	
	
	// invoke a static class method

	std::string name = mol::singleton<DotNetClassNames>().getName(dispIdMember); //idsOfNames_[dispIdMember];

	if (  w & DISPATCH_PROPERTYGET ) 
	{	
		if ( pDisp->cArgs == 0 )
		{
			hr = net->InvokeMethod( v_, vnull, mol::bstr(name),0, DISPATCH_PROPERTYGET, &vRet );
			if ( hr != S_OK )
				return hr;

			return wrapNETObject(vRet,pReturn);
		}
		//return E_FAIL; // nada! -> handle it as a method instead
	}

	if (  w & DISPATCH_PROPERTYPUT ) 
	{	
		if ( pDisp->cArgs == 0 )
		{
			return E_FAIL;
		}

		SafeArrayFromDispParams sa(pDisp,pDisp->cArgs);
		hr = net->InvokeMethod( v_, vnull, mol::bstr(name),sa.value, DISPATCH_PROPERTYPUT, &vRet );
		if ( hr != S_OK )
			return hr;

		return wrapNETObject(vRet,pReturn);
	}

	SafeArrayFromDispParams sa(pDisp);
	hr = net->InvokeMethod( v_, vnull, mol::bstr(name),sa.value, DISPATCH_METHOD, &vRet );
	if ( hr != S_OK )
		return hr;
	
	return wrapNETObject(vRet,pReturn);
}

HRESULT __stdcall NetType::GetDispID( BSTR bstrName, DWORD grfdex, DISPID *pid)
{
	return GetIDsOfNames(IID_NULL,&bstrName,1,LOCALE_SYSTEM_DEFAULT,pid);
}

HRESULT __stdcall NetType::InvokeEx( DISPID id,LCID lcid, WORD wFlags, DISPPARAMS *pdp, VARIANT *pvarRes, EXCEPINFO *pei, IServiceProvider *pspCaller)
{
	return Invoke(id,IID_NULL,lcid,wFlags,pdp,pvarRes,pei,0);
}

HRESULT __stdcall NetType::DeleteMemberByName( BSTR bstrName, DWORD grfdex)
{
	return  S_FALSE ;
}

HRESULT __stdcall NetType::DeleteMemberByDispID( DISPID id)
{
	return  S_FALSE ;
}

HRESULT __stdcall NetType::GetMemberProperties( DISPID id, DWORD grfdexFetch, DWORD *pgrfdex)
{
	return S_OK;
}

HRESULT __stdcall NetType::GetMemberName( DISPID id, BSTR *pbstrName)
{
	return E_NOTIMPL;
}

HRESULT __stdcall NetType::GetNextDispID( DWORD grfdex, DISPID id, DISPID *pid)
{
	return E_NOTIMPL;
}

HRESULT __stdcall NetType::GetNameSpaceParent( IUnknown **ppunk)
{
	*ppunk = 0;
	return E_UNEXPECTED;
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

HRESULT __stdcall  NetServer::Import(BSTR typeName, IDispatch** a)
{
	
	mol::punk<_Net> net;
	HRESULT hr = net.createObject(CLSID_Net);
	if ( hr != S_OK )
		return S_FALSE;

	mol::variant v;
	hr = net->LoadAssembly(typeName,&v);

	if (a)
	{
		*a=0;
	}

	if ( hr != S_OK )
	{
		return hr;
	}

	return Namespace::CreateInstance(a,mol::tostring(typeName),this);
}

HRESULT __stdcall NetServer::get_Runtime(IDispatch** result)
{
	return Namespace::CreateInstance(result,"",this);
}

HRESULT __stdcall NetServer::Prototype( BSTR name, VARIANT obj, IDispatch** s)
{
	if(!name)
		return E_INVALIDARG;

	if(obj.vt != VT_DISPATCH)
		return E_INVALIDARG;

	if(!s)
		return E_INVALIDARG;

	mol::punk<IDispatch> disp(obj.pdispVal);
	if(!disp)
		return E_FAIL;

	mol::punk<IDispatchEx> dispEx(disp);
	if(!dispEx)
		return E_FAIL;

	DISPID dispid = 0;
	std::vector<BSTR> names;
	std::vector<VARIANT> values;

	HRESULT hr = dispEx->GetNextDispID(fdexEnumAll, DISPID_STARTENUM, &dispid);
	while (hr == NOERROR)
	{
		BSTR bstrName;
		hr = dispEx->GetMemberName(dispid, &bstrName);
		names.push_back(bstrName);

		DISPPARAMS params = {0};
		EXCEPINFO ex;
		::ZeroMemory(&ex,sizeof(EXCEPINFO));

		mol::variant result;
		hr = dispEx->InvokeEx(dispid,LOCALE_SYSTEM_DEFAULT,DISPATCH_PROPERTYGET,&params,&result,&ex,NULL);
		if(hr != S_OK )
			return hr;

		VARIANT v;
		::VariantInit(&v);
		unwrapNETObject(result,&v);
		values.push_back(v);
		/*
		if ( result.vt == VT_DISPATCH )
		{
			VARIANT v;
			unwrapNETObject(result,&v);
			values.push_back(v);
		}
		else
		{
			VARIANT v;
			::VariantInit(&v);
			v.vt = VT_NULL;
			v.pdispVal = NULL;
			values.push_back(v);
		}
		*/

		hr = dispEx->GetNextDispID(fdexEnumAll, dispid, &dispid);
	}

	if ( names.size() != values.size() )
	{
		throw new std::string("eeek");
	}

	mol::punk<_Net> net;
	hr = net.createObject(CLSID_Net);
	if ( hr != S_OK )
		return hr;


	mol::SafeArray<VT_VARIANT> saNames(mol::ArrayBound((long)names.size()));

	mol::SFAccess<VARIANT> sfbNames(saNames);
	for ( long i = 0; i < sfbNames.size(); i++)
	{
		sfbNames[i].vt = VT_BSTR;
		sfbNames[i].bstrVal = names[i];
	}

	mol::SafeArray<VT_VARIANT> saValues(mol::ArrayBound((long)values.size()));

	mol::SFAccess<VARIANT> sfbValues(saValues);
	for ( long i = 0; i < sfbValues.size(); i++)
	{
		sfbValues[i] = values[i];
	}

	mol::variant r;
	hr = net->Prototype(name, saNames, saValues, &r);
	if(hr != S_OK )
		return hr;

	if ( (r.vt == VT_DISPATCH || r.vt == VT_UNKNOWN) && r.punkVal )
	{
		mol::punk<INetType> type;
		wrapNETType(r,&type);
		return type.queryInterface(s);
	}
	return S_OK;
}

HRESULT __stdcall NetServer::String( BSTR txt, IDispatch** s)
{
	mol::punk<INetType> type;
	HRESULT hr = Type( mol::bstr("System.String"),&type);
	if(hr!=S_OK)
		return hr;

	EXCEPINFO ex;
	::ZeroMemory(&ex,sizeof(EXCEPINFO));
	UINT e = 0;

	VARIANTARG varg;
	varg.vt = VT_BSTR;
	varg.bstrVal = txt;

	DISPPARAMS params;
	::ZeroMemory(&params,sizeof(DISPPARAMS));
	params.cArgs = 1;
	params.rgvarg = &varg;

	mol::variant result;
	hr = type->Invoke(0,IID_NULL,LOCALE_SYSTEM_DEFAULT,0,&params,&result,&ex,&e);
	if ( hr == S_OK && s && (result.vt == VT_DISPATCH || result.vt == VT_UNKNOWN) && result.punkVal )
	{
		hr = result.punkVal->QueryInterface(IID_IDispatch,(void**)s);
		return hr;
	}
	return E_FAIL;
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

	return wrapNETType(v,clazz);
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

	mol::punk<IDispatch> disp;
	EventHandler::CreateInstance(ptr,&disp);

	mol::variant vptr(disp);	
	hr = net->Event( v,  eventName, vptr);
	return hr;

}

///////////////////////////////////////////////////////////


HRESULT __stdcall NetServer::GetIDsOfNames( REFIID  riid, OLECHAR FAR* FAR*  rgszNames, unsigned int  cNames, LCID   lcid, DISPID FAR*  rgDispId ) 
{ 
	OLECHAR* name = rgszNames[0];
	std::string n = mol::tostring(name);

	return mol::Dispatch<INet>::GetIDsOfNames( riid, rgszNames, cNames, lcid, rgDispId );
}

HRESULT  __stdcall NetServer::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn, EXCEPINFO * ex, UINT * i) 
{ 

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


