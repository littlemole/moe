// types.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "netserver.h"
#include "dot.h"
#include "ole/aut.h"

DWORD DISPID_NEW = 0;
DWORD DISPID_OF  = 1;


////////////////////////////////////////////////////////////////////////


template<class T>
HRESULT wrapNETType( IUnknown* clr, mol::variant& in,   T** out)
{
	mol::punk<INetType> c;
	HRESULT hr = c.createObject(CLSID_DotNetType,CLSCTX_ALL);
	if ( hr != S_OK )
		return hr;

	hr = c->Initialize(in,clr);
	if ( hr != S_OK )
		return hr;

	::CoAllowSetForegroundWindow( (IUnknown*)c, 0);

	return c.queryInterface(out);
}

HRESULT wrapNETType(IUnknown* clr, mol::variant& in, VARIANT* out)
{
	if(!out)
		return E_INVALIDARG;

	mol::punk<INetType> c;
	HRESULT hr = wrapNETType(clr,in,&c);
	if ( hr != S_OK )
		return hr;

	out->vt = VT_DISPATCH;
	return c.queryInterface(&out->pdispVal);
}

HRESULT wrapNETObject(IUnknown* clr, VARIANT& in, VARIANT* out)
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

	hr = no->Initialize(in,clr);
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
	if ( in.vt == (VT_BYREF|VT_VARIANT) )
	{
		mol::variant tmp;
		::VariantCopy(&tmp,in.pvarVal);
		return unwrapNETObject(tmp,out);
	}
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
			::VariantClear(&rgvarg[i]);
		}
		delete[] rgvarg;
	}

	void set(UINT index, IDispatch* disp)
	{
		rgvarg[index].vt = VT_DISPATCH;
		rgvarg[index].pdispVal = disp;
		disp->AddRef();
	}

	void set(UINT index, VARIANT in)
	{
		rgvarg[index].vt = VT_EMPTY;
		rgvarg[index].pdispVal = 0;
		
		::VariantCopy(&rgvarg[index],&in);
	}
};

class SafeArrayFromDispParams
{
public:

	mol::SafeArray<VT_VARIANT> value;

	SafeArrayFromDispParams(DISPPARAMS* params)
	{
		UINT nArgs = params->cArgs - params->cNamedArgs;
		init(params,nArgs);
	}

	SafeArrayFromDispParams(DISPPARAMS* params, UINT nArgs)
	{
		init(params,nArgs);
	}

private:

	void init(DISPPARAMS* params, UINT nArgs)
	{
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

	mol::punk<IUnknown> unk;
	HRESULT hr = net->get_CLR(&unk);
	if ( hr == S_OK && unk )
	{
		i->clr_ = unk;
	}

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
	HRESULT hr= S_OK;

	if( id2name_.count(dispIdMember) == 0 )
		return E_INVALIDARG;

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
		hr = clr_->LoadClass( empty, mol::bstr(oss.str()), &v );
		if ( hr == S_OK && (v.vt == VT_DISPATCH || v.vt == VT_UNKNOWN) && v.pdispVal )
		{
			SafeArrayFromDispParams sa(pDisp);
			mol::variant r;
			hr = clr_->MakeGeneric(v,sa.value,&r);
			if ( hr == S_OK && ( r.vt == VT_DISPATCH || r.vt == VT_UNKNOWN) && r.punkVal)
			{
				return wrapNETType(clr_,r,pReturn);
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
	hr = clr_->LoadClass( empty, mol::bstr(n), &v );
	if ( hr == S_OK && (v.vt == VT_DISPATCH || v.vt == VT_UNKNOWN) && v.pdispVal )
	{

		mol::punk<IDispatch> disp;
		hr = wrapNETType(clr_,v,&disp);
		if ( hr != S_OK )
			return hr;

		if(pReturn)
		{
			if ( (w & DISPATCH_PROPERTYGET) && ( pDisp->cArgs == 0 ) )
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


HRESULT EventHandler::CreateInstance(IUnknown* clr, IDispatch* handler, IDispatch** d)
{
	Instance* i = new Instance;
	i->handler_ = handler;

	HRESULT hr = clr->QueryInterface(IID__Net,(void**)&(i->clr_) );
	if ( hr != S_OK )
		return hr;

	return i->QueryInterface(IID_IDispatch,(void**)d);
}


HRESULT EventHandler::CreateInstance(IUnknown* clr, IDispatch* disp, mol::bstr handler, IDispatch** d)
{
	Instance* i = new Instance;
	i->handler_ = disp;
	i->callback_ = handler;

	HRESULT hr = clr->QueryInterface(IID__Net,(void**)&(i->clr_) );
	if ( hr != S_OK )
		return hr;

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
		hr = wrapNETObject(clr_,pDisp->rgvarg[i],&v);
		params.set(i,v.pdispVal);
	}

	if ( handler_ && callback_.bstr_ == 0)
	{
		hr = handler_->Invoke(0,IID_NULL,LOCALE_SYSTEM_DEFAULT,w,&params,pReturn,ex,e);
	}
	else if ( handler_ )
	{
		DISPID id = 0;
		hr = handler_->GetIDsOfNames(IID_NULL,&callback_.bstr_,1,LOCALE_SYSTEM_DEFAULT,&id);
		if ( hr == S_OK )
		{
			hr = handler_->Invoke(id,IID_NULL,LOCALE_SYSTEM_DEFAULT,DISPATCH_METHOD,&params,pReturn,ex,e);
		}
	}
	return hr;
}


////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////


void NetObject::dispose()
{
	clr_.release();
}
	
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


HRESULT __stdcall NetObject::Initialize(VARIANT ptr, IUnknown* clr)
{
	v_ = ptr;
	return clr->QueryInterface(IID__Net,(void**)&clr_);
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

HRESULT __stdcall NetObject::On(BSTR eventName, VARIANT handler)
{
	if ( handler.vt != VT_DISPATCH )
	{
		return E_INVALIDARG;
	}

	
	mol::punk<IDispatch> disp;
	EventHandler::CreateInstance(clr_,handler.pdispVal,&disp);

	mol::variant vptr(disp);	
	HRESULT hr = clr_->Event( v_,  eventName, vptr);
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
	HRESULT hr = S_OK;

	std::string name = mol::singleton<DotNetNames>().getName(dispIdMember);

	if(name=="On")
	{
		if ( pDisp->cArgs == 2 )
		{
			return this->On(
							pDisp->rgvarg[1].bstrVal,
							pDisp->rgvarg[0]
						);
		}
	}

	mol::vEmpty vempty;
	mol::variant vRet;

	if (  w == DISPATCH_PROPERTYGET ) 
	{	
		if ( pDisp->cArgs == 0 )
		{
			hr = clr_->InvokeMethod( vempty, v_, mol::bstr(name),0, DISPATCH_PROPERTYGET, &vRet );
			if ( hr == S_OK )
			{
				return wrapNETObject(clr_,vRet,pReturn);
			}
			if ( hr != S_OK )
				return DISP_E_MEMBERNOTFOUND;
			//	return hr;
		}
		//return S_FALSE;
	}

	if (  (w & DISPATCH_PROPERTYPUT) || (w & DISPATCH_PROPERTYPUTREF) ) 
	{	
		SafeArrayFromDispParams sa(pDisp,pDisp->cArgs);
		hr = clr_->InvokeMethod( vempty, v_, mol::bstr(name),sa.value, DISPATCH_PROPERTYPUT, &vRet );
		if ( hr != S_OK )
			return hr;
		return wrapNETObject(clr_,vRet,pReturn);		
	}

	SafeArrayFromDispParams sa(pDisp);
	hr = clr_->InvokeMethod( vempty, v_, mol::bstr(name),sa.value, DISPATCH_METHOD, &vRet );
	if ( hr != S_OK )
		return hr;
	return wrapNETObject(clr_,vRet,pReturn);
}


////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////


void NetType::dispose()
{
	clr_.release();
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

HRESULT __stdcall NetType::Initialize(VARIANT ptr, IUnknown* clr)
{
	v_ = ptr;
	return clr->QueryInterface(IID__Net,(void**)&clr_);
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
	HRESULT hr = S_OK;

	mol::vNull vnull;
	mol::variant vRet;

	// generic type 
	if ( dispIdMember == 3 ) 
	{
		SafeArrayFromDispParams sa(pDisp);
		hr = clr_->MakeGeneric( v_, sa.value, &vRet );
		if ( hr != S_OK )
			return hr;

		return wrapNETType(clr_,vRet,pReturn);
	}
	
	// create net obj via constructor
	if ( dispIdMember == 0 ) 
	{		
		SafeArrayFromDispParams sa(pDisp);
		hr = clr_->CreateObject( v_, sa.value, &vRet );
		if ( hr != S_OK )
			return hr;

		return wrapNETObject(clr_,vRet,pReturn);
	}
	
	
	// invoke a static class method

	std::string name = mol::singleton<DotNetClassNames>().getName(dispIdMember); //idsOfNames_[dispIdMember];

	if ( name == "prototype" )
	{
		mol::vEmpty vEmpty;
		if(pReturn)
			::VariantCopy(pReturn,&vEmpty);
		return S_OK;
	}
	if (  w & DISPATCH_PROPERTYGET ) 
	{	
		if ( pDisp->cArgs == 0 )
		{
			hr = clr_->InvokeMethod( v_, vnull, mol::bstr(name),0, DISPATCH_PROPERTYGET, &vRet );
			if ( hr != S_OK )
				return DISP_E_MEMBERNOTFOUND;

			return wrapNETObject(clr_,vRet,pReturn);
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
		hr = clr_->InvokeMethod( v_, vnull, mol::bstr(name),sa.value, DISPATCH_PROPERTYPUT, &vRet );
		if ( hr != S_OK )
			return hr;

		return wrapNETObject(clr_,vRet,pReturn);
	}

	SafeArrayFromDispParams sa(pDisp);
	hr = clr_->InvokeMethod( v_, vnull, mol::bstr(name),sa.value, DISPATCH_METHOD, &vRet );
	if ( hr != S_OK )
		return hr;
	
	return wrapNETObject(clr_,vRet,pReturn);
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
	HRESULT hr = clr_.createObject(CLSID_Net);
}

void NetServer::dispose()
{
	clr_.release();
	::PostThreadMessage(mol::guithread(),WM_QUIT,0,0);
}


HRESULT __stdcall NetServer::Exit()
{
	clr_.release();
	::PostThreadMessage(mol::guithread(),WM_QUIT,0,0);
	return S_OK;
}

HRESULT __stdcall  NetServer::Import(BSTR typeName, IDispatch** a)
{	
	mol::variant v;
	HRESULT hr = clr_->LoadAssembly(typeName,&v);

	if (a)
	{
		*a=0;
	}

	if ( (hr != S_OK) || (!a) )
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

	if(!s)
		return E_INVALIDARG;

	mol::punk<IDispatch> disp;

	if(obj.vt == VT_DISPATCH)
	{
		disp = obj.pdispVal;
		if(!disp)
			return E_FAIL;
	}
	else 
	{
		if ( obj.vt & VT_BYREF )
		{
			if ( obj.vt == ( VT_DISPATCH|VT_BYREF) ) 
			{
				disp = *obj.ppdispVal;
			}
			else if ( obj.vt == (VT_VARIANT|VT_BYREF) ) 
			{
				if ( obj.pvarVal->vt == VT_DISPATCH )
				{
					disp = obj.pvarVal->pdispVal;
				}
				else 
				{
					return E_FAIL;
				}
			}
			else 
			{
				return E_FAIL;
			}
		}
		else 
		{
			return E_FAIL;
		}
	}

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

		hr = dispEx->GetNextDispID(fdexEnumAll, dispid, &dispid);
	}

	if ( names.size() != values.size() )
	{
		return E_INVALIDARG;
	}


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
		if ( values[i].vt == VT_DISPATCH )
		{
			mol::punk<IDispatchEx> dispEx(values[i].pdispVal);
			if( dispEx)
			{
				mol::punk<INetType> nt(dispEx);
				if(!nt)
				{
					mol::punk<IDispatch> ret;
					std::wostringstream woss;
					woss << name << "$" << names[i];
					hr = Prototype(mol::bstr(woss.str()),values[i],&ret);
					if ( hr == S_OK && ret )
					{
						::VariantClear(&values[i]);
						mol::variant v(ret);
						hr = unwrapNETObject(v,&values[i]);
					}
				}
			}
		}

		sfbValues[i] = values[i];
	}

	mol::variant r;
	hr = clr_->Prototype(name, saNames, saValues, &r);
	if(hr != S_OK )
		return hr;

	if ( (r.vt == VT_DISPATCH || r.vt == VT_UNKNOWN) && r.punkVal )
	{
		mol::punk<INetType> type;
		wrapNETType(clr_,r,&type);
		return type.queryInterface(s);
	}
	return S_OK;
}

HRESULT __stdcall NetServer::copyTo( IDispatch* src, IDispatch* dest)
{
	mol::punk<INetType> type;
	HRESULT hr = Type( mol::bstr("org.oha7.dotnet.Prototype"),&type);
	if(hr!=S_OK)
		return hr;

	EXCEPINFO ex;
	::ZeroMemory(&ex,sizeof(EXCEPINFO));
	UINT e = 0;

	DispParamsBuf params(2);
	params.set(0,dest);
	params.set(1,src);

	OLECHAR* name = L"copyTo";
	DISPID dispid;
	hr = type->GetIDsOfNames(IID_NULL,&name,1,LOCALE_SYSTEM_DEFAULT,&dispid);
	if ( hr != S_OK)
		return hr;

	mol::variant result;
	hr = type->Invoke(dispid,IID_NULL,LOCALE_SYSTEM_DEFAULT,0,&params,&result,&ex,&e);
	return hr;

}

HRESULT __stdcall NetServer::get_CLR( IUnknown** unk)
{
	if(!unk)
		return E_INVALIDARG;

	return clr_.queryInterface(unk);
}

typedef std::vector<VARIANT> jsArray;


jsArray enumJSArray(IDispatch* disp)
{
	jsArray resultArray;

	mol::punk<IDispatchEx> dispEx(disp);
	if(!dispEx)
		return resultArray;


	DISPPARAMS empty;
	::ZeroMemory(&empty,sizeof(DISPPARAMS));

	mol::variant result;
	EXCEPINFO ex;
	::ZeroMemory(&ex,sizeof(EXCEPINFO));
	UINT e = 0;

	DISPID dispid = 0;

	LPOLESTR str = L"length";
	HRESULT hr = dispEx->GetIDsOfNames(IID_NULL,&str,1,LOCALE_SYSTEM_DEFAULT,&dispid);
	if (hr != S_OK )
		return resultArray;

	hr = dispEx->Invoke( dispid, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_PROPERTYGET,&empty,&result,&ex,&e);
	if (hr != S_OK )
		return resultArray;

	result.changeType(VT_I4);
	for ( LONG i = 0; i < result.lVal; i++ )
	{
		std::wostringstream woss;
		woss << i;
		std::wstring w(woss.str());
		LPOLESTR ole = (wchar_t*) w.c_str();

		HRESULT hr = dispEx->GetIDsOfNames(IID_NULL,&ole,1,LOCALE_SYSTEM_DEFAULT,&dispid);
		if (hr != S_OK )
			continue;

		mol::variant r;
		::VariantInit(&r);
		hr = dispEx->Invoke( dispid, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_PROPERTYGET,&empty,&r,&ex,&e);
		if (hr != S_OK )
			continue;

		VARIANT tmp;
		::VariantInit(&tmp);
		unwrapNETObject(r,&tmp);
		resultArray.push_back(tmp);
	}

	return resultArray;
}

HRESULT getMemberAsVariant( LPOLESTR name, IDispatch* def, VARIANT* result)
{
	DISPPARAMS emptyParams = {0};
	EXCEPINFO ex;
	::ZeroMemory(&ex,sizeof(EXCEPINFO));
	UINT e = 0;

	if(!def)
		return E_INVALIDARG;

	DISPID dispid = 0;
	HRESULT hr = def->GetIDsOfNames(IID_NULL,&name,1,LOCALE_SYSTEM_DEFAULT,&dispid);
	if ( hr == S_OK )
	{
		mol::variant v;
		hr = def->Invoke(dispid,IID_NULL,LOCALE_SYSTEM_DEFAULT,DISPATCH_PROPERTYGET,&emptyParams,&v,&ex,&e);
		if ( hr == S_OK )
		{
			unwrapNETObject(v,result);
		}
	}

	return S_OK;
}

HRESULT NetServer::getAttributes(IDispatch* def, mol::SafeArray<VT_VARIANT>& result) 
{
	if(!def)
		return E_INVALIDARG;

	EXCEPINFO ex;
	::ZeroMemory(&ex,sizeof(EXCEPINFO));
	UINT e = 0;

	mol::punk<INetType> attrDefType;
	HRESULT hr = Type( mol::bstr("org.oha7.dotnet.AttributeDef"), &attrDefType);
	if(hr != S_OK)
		return hr;

	mol::variant vattrDefType;
	hr = attrDefType->UnWrap(&vattrDefType);
	if(hr != S_OK)
		return hr;

	mol::variant attributes;
	hr = getMemberAsVariant( L"attributes", def, &attributes);
	if(hr != S_OK)
		return hr;

	jsArray jsa = enumJSArray(attributes.pdispVal);
	if(jsa.size()==0)
		return S_OK;

//	mol::SFAccess<VARIANT> sfaAttrs(attributes.parray);

	mol::ArrayBound abResult((long)jsa.size());
	//mol::SafeArray<VT_VARIANT> sfAttrDef(result);
	result.Create(abResult);
	{
		mol::SFAccess<VARIANT> sfaResult(result);
		for ( long i = 0; i < jsa.size(); i++)
		{
			VARIANT t;
			::VariantInit(&t);
			hr = getMemberAsVariant( L"type", jsa[i].pdispVal, &t );
			if(hr != S_OK)
				continue;

			mol::variant args;
			hr = getMemberAsVariant( L"args", jsa[i].pdispVal, &args );
			if(hr != S_OK)
				continue;

			jsArray jsargs = enumJSArray(args.pdispVal);
			mol::ArrayBound abAttrDefArgs((long)jsargs.size());
			mol::SafeArray<VT_VARIANT> sfAttrDefArgs(abAttrDefArgs);
			{
				mol::SFAccess<VARIANT> sfaAttrDefArgs(sfAttrDefArgs);
				for ( long j = 0; j < jsargs.size(); j++)
				{
					sfaAttrDefArgs[j] = jsargs[j];
				}
			}

			mol::ArrayBound abParamsDefArgs(2);
			mol::SafeArray<VT_VARIANT> sfParams(abParamsDefArgs);
			{
				mol::SFAccess<VARIANT> sfaParams(sfParams);
				sfaParams[0] = t;
				sfaParams[1].vt = VT_ARRAY|VT_VARIANT;
				::SafeArrayCopy( sfAttrDefArgs, &(sfaParams[1].parray) );
			}

			mol::vEmpty vempty;
			::VariantInit(&sfaResult[i]);
			hr = clr_->InvokeMethod( 
							vattrDefType, 
							vempty, 
							mol::bstr("instance"),
							sfParams,
							DISPATCH_METHOD,
							&sfaResult[i]
						);
		}
	}
	return S_OK;
}


HRESULT NetServer::getProperties(IDispatch* def, mol::SafeArray<VT_VARIANT>& result) 
{
	if(!def)
		return E_INVALIDARG;

	EXCEPINFO ex;
	::ZeroMemory(&ex,sizeof(EXCEPINFO));
	UINT e = 0;

	mol::punk<INetType> propDefType;
	HRESULT hr = Type( mol::bstr("org.oha7.dotnet.PropertyDef"), &propDefType);
	if(hr!=S_OK)
		return hr;

	mol::variant vpropDefType;
	hr = propDefType->UnWrap(&vpropDefType);
	if(hr!=S_OK)
		return hr;

	mol::variant properties;
	hr = getMemberAsVariant( L"properties", def, &properties);
	if(hr!=S_OK)
		return hr;

	jsArray jsa = enumJSArray(properties.pdispVal);
	if(jsa.size()==0)
		return S_OK;

//	mol::SFAccess<VARIANT> sfaAttrs(attributes.parray);

	mol::ArrayBound abResult((long)jsa.size());
	//mol::SafeArray<VT_VARIANT> sfAttrDef(result);
	result.Create(abResult);
	{
		mol::SFAccess<VARIANT> sfaResult(result);
		for ( long i = 0; i < jsa.size(); i++)
		{
			VARIANT n;
			::VariantInit(&n);
			hr = getMemberAsVariant( L"name", jsa[i].pdispVal, &n );
			if(hr != S_OK)
				continue;

			VARIANT t;
			::VariantInit(&t);
			hr = getMemberAsVariant( L"type", jsa[i].pdispVal, &t );
			if(hr != S_OK)
				continue;

			mol::SafeArray<VT_VARIANT> sfAttrDefArgs;
			mol::variant args;
			hr = getMemberAsVariant( L"args", jsa[i].pdispVal, &args );
			if(hr == S_OK && args.vt != VT_EMPTY)
			{

				jsArray jsargs = enumJSArray(args.pdispVal);
				mol::ArrayBound abAttrDefArgs((long)jsargs.size());
				//mol::SafeArray<VT_VARIANT> sfAttrDefArgs(abAttrDefArgs);
				sfAttrDefArgs.Create(abAttrDefArgs);
				{
					mol::SFAccess<VARIANT> sfaAttrDefArgs(sfAttrDefArgs);
					for ( long j = 0; j < jsargs.size(); j++)
					{
						sfaAttrDefArgs[j] = jsargs[j];
					}
				}
			}
			mol::ArrayBound abParamsDefArgs(3);
			mol::SafeArray<VT_VARIANT> sfParams(abParamsDefArgs);
			{
				mol::SFAccess<VARIANT> sfaParams(sfParams);
				sfaParams[0] = n;
				sfaParams[1] = t;
				sfaParams[2].vt = VT_ARRAY|VT_VARIANT;
				::SafeArrayCopy( sfAttrDefArgs, &(sfaParams[2].parray) );
			}

			mol::vEmpty vempty;
			::VariantInit(&sfaResult[i]);
			hr = clr_->InvokeMethod( 
							vpropDefType, 
							vempty, 
							mol::bstr("instance"),
							sfParams,
							DISPATCH_METHOD,
							&sfaResult[i]
						);
		}
	}
	return S_OK;
}

HRESULT NetServer::getMethods(IDispatch* def, mol::SafeArray<VT_VARIANT>& result) 
{
	if(!def)
		return E_INVALIDARG;

	EXCEPINFO ex;
	::ZeroMemory(&ex,sizeof(EXCEPINFO));
	UINT e = 0;

	mol::punk<INetType> methodDefType;
	HRESULT hr = Type( mol::bstr("org.oha7.dotnet.MethodHandle"), &methodDefType);
	if(hr!=S_OK)
		return hr;

	mol::variant vmethodDefType;
	hr = methodDefType->UnWrap(&vmethodDefType);
	if(hr!=S_OK)
		return hr;

	mol::variant methods;
	hr = getMemberAsVariant( L"methods", def, &methods);
	if(hr!=S_OK)
		return hr;

	jsArray jsa = enumJSArray(methods.pdispVal);
	if(jsa.size()==0)
		return S_OK;

//	mol::SFAccess<VARIANT> sfaAttrs(attributes.parray);

	mol::ArrayBound abResult((long)jsa.size());
	//mol::SafeArray<VT_VARIANT> sfAttrDef(result);
	result.Create(abResult);
	{
		mol::SFAccess<VARIANT> sfaResult(result);
		for ( long i = 0; i < jsa.size(); i++)
		{
			VARIANT n;
			::VariantInit(&n);
			hr = getMemberAsVariant( L"name", jsa[i].pdispVal, &n );
			if(hr != S_OK)
				continue;

			VARIANT t;
			::VariantInit(&t);
			hr = getMemberAsVariant( L"type", jsa[i].pdispVal, &t );
			if(hr != S_OK)
				continue;

			mol::variant args;
			hr = getMemberAsVariant( L"args", jsa[i].pdispVal, &args );
			if(hr != S_OK)
				continue;

			jsArray jsargs = enumJSArray(args.pdispVal);
			mol::ArrayBound abAttrDefArgs((long)jsargs.size());
			mol::SafeArray<VT_VARIANT> sfAttrDefArgs(abAttrDefArgs);
			{
				mol::SFAccess<VARIANT> sfaAttrDefArgs(sfAttrDefArgs);
				for ( long j = 0; j < jsargs.size(); j++)
				{
					sfaAttrDefArgs[j] = jsargs[j];
				}
			}

			mol::ArrayBound abParamsDefArgs(3);
			mol::SafeArray<VT_VARIANT> sfParams(abParamsDefArgs);
			{
				mol::SFAccess<VARIANT> sfaParams(sfParams);
				sfaParams[0] = n;
				sfaParams[1] = t;
				sfaParams[2].vt = VT_ARRAY|VT_VARIANT;
				::SafeArrayCopy( sfAttrDefArgs, &(sfaParams[2].parray) );
			}

			mol::vEmpty vempty;
			::VariantInit(&sfaResult[i]);
			hr = clr_->InvokeMethod( 
							vmethodDefType, 
							vempty, 
							mol::bstr("instance"),
							sfParams,
							DISPATCH_METHOD,
							&sfaResult[i]
						);
		}
	}
	return S_OK;
}

HRESULT NetServer::getInterfaces(IDispatch* def, mol::SafeArray<VT_VARIANT>& result) 
{
	if(!def)
		return E_INVALIDARG;

	mol::variant interfaces;
	HRESULT hr = getMemberAsVariant( L"implements", def, &interfaces);
	if(hr!=S_OK)
		return hr;

	jsArray arrayInterfaces = enumJSArray(interfaces.pdispVal);

	if(arrayInterfaces.size()==0)
		return S_OK;

	mol::ArrayBound abInterfaces((long)arrayInterfaces.size());
	//mol::SafeArray<VT_VARIANT> sfInterfaces(abInterfaces);
	result.Create(abInterfaces);
	{
		mol::SFAccess<VARIANT> sfa(result);
		for ( long i = 0; i < arrayInterfaces.size(); i++)
		{
			sfa[i] = arrayInterfaces[i];
		}
	}
	return S_OK;
}

HRESULT __stdcall NetServer::Declare( BSTR name, IDispatch* def, IDispatch* handler, IDispatch** unk)
{
	DISPPARAMS emptyParams = {0};
	EXCEPINFO ex;
	::ZeroMemory(&ex,sizeof(EXCEPINFO));
	UINT e = 0;

	mol::variant baseType;

	HRESULT hr = getMemberAsVariant( L"inherits", def, &baseType);
	if ( hr != S_OK && baseType.vt != VT_EMPTY)
	{
		mol::punk<INetType> t;
		hr = Type( mol::bstr("System.Object"), &t);
		if ( hr == S_OK && t )
		{
			hr = t->UnWrap(&baseType);
		}
	}
	

	mol::SafeArray<VT_VARIANT> sfInterfaces;
	hr = getInterfaces( def, sfInterfaces );

	mol::SafeArray<VT_VARIANT> sfAttrDef;
	hr = getAttributes( def, sfAttrDef );

	mol::SafeArray<VT_VARIANT> sfPropsDef;
	hr = getProperties( def, sfPropsDef );

	mol::SafeArray<VT_VARIANT> sfMethodDef;
	hr = getMethods( def, sfMethodDef );

	mol::variant result;
	hr = clr_->DefineClass( name, baseType,sfInterfaces,sfAttrDef,sfPropsDef,sfMethodDef,&result);
	if ( hr != S_OK )
		return hr;

	if ( (result.vt == VT_DISPATCH || result.vt == VT_UNKNOWN) && result.punkVal )
	{
		mol::variant vempty;
		mol::variant tmp;
		mol::ArrayBound ab(1);
		mol::SafeArray<VT_VARIANT> args(ab);
		{
			mol::SFAccess<VARIANT> sfa(args);
			sfa[0].vt = VT_DISPATCH;
			hr = handler->QueryInterface(IID_IDispatch, (void**) &sfa[0].pdispVal );
		}

		hr = clr_->InvokeMethod( result, vempty, mol::bstr("ScriptHandler"),args,DISPATCH_PROPERTYPUT,&tmp);

		mol::punk<INetType> type;
		wrapNETType(clr_,result,&type);
		return type.queryInterface(unk);
	}
	return E_INVALIDARG;
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
		return E_INVALIDARG;
	}

	if ( !clazz )
	{
		return E_INVALIDARG;
	}

	*clazz = 0;

	mol::variant empty;
	mol::variant v;
	HRESULT hr = clr_->LoadClass( empty, typeName, &v );
	if ( hr != S_OK )
		return hr;

	return wrapNETType(clr_,v,clazz);
}

HRESULT __stdcall NetServer::Connect(IDispatch* ptr, BSTR eventName, VARIANT target)
{
	mol::variant v;
	HRESULT hr = unwrapNETObject(target,&v);
	if ( hr != S_OK )
		return hr;

	mol::punk<IDispatch> disp;
	EventHandler::CreateInstance(clr_,ptr,&disp);

	mol::variant vptr(disp);	
	hr = clr_->Event( v,  eventName, vptr);
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

////////////////////////////////////////////////////////////////////////

NetApp::NetApp()
{}


