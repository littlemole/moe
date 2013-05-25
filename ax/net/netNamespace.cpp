// types.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "netnamespace.h"
#include "dot.h"
#include "Util.h"



HRESULT Namespace::CreateInstance(const std::string& path, INet* net,IDispatch** d)
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
	hr = Namespace::CreateInstance(n,inet_,&ns);
	if ( hr != S_OK )
		return hr;

	if(pReturn)
	{
		pReturn->vt = VT_DISPATCH;
		return ns.queryInterface(&pReturn->pdispVal);
	}

	return S_OK;
}

