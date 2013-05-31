// types.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "netThat.h"
#include "dot.h"
#include "Util.h"

////////////////////////////////////////////////////////////////////////

HRESULT ThatCall::CreateInstance(IUnknown* clr,IDispatch* target, IDispatch** out)
{
	Instance* i = new Instance;
	i->target_ = target;
	HRESULT hr = clr->QueryInterface(IID__Net,(void**)&(i->clr_) );
	if ( hr != S_OK )
		return hr;

	return i->QueryInterface(IID_IDispatch,(void**)out);
}

HRESULT __stdcall ThatCall::GetIDsOfNames( REFIID  riid, OLECHAR FAR* FAR*  rgszNames, unsigned int  cNames, LCID   lcid, DISPID FAR*  rgDispId )
{
	return target_->GetIDsOfNames(riid,rgszNames,cNames,lcid,rgDispId);
}

HRESULT __stdcall ThatCall::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn, EXCEPINFO * ex, UINT * e)
{
	if ( pDisp->cNamedArgs == 0 )
	{
		DISPPARAMS params;

		params.cArgs = pDisp->cArgs;
		params.cNamedArgs = 1;
		params.rgdispidNamedArgs = new DISPID[1];
		params.rgdispidNamedArgs[0] = DISPID_THIS;
		params.rgvarg = new VARIANTARG[params.cArgs];
		for ( unsigned long i = 0; i < params.cArgs-1; i++)
		{
			wrapNETObject( clr_, pDisp->rgvarg[i], &(params.rgvarg[i+1]) );
		}
		wrapNETObject( clr_, pDisp->rgvarg[params.cArgs-1], &(params.rgvarg[0]) );

		mol::variant v;
		HRESULT hr = target_->Invoke( dispIdMember, riid, lcid, w, &params, &v, ex, e);
		delete[] params.rgdispidNamedArgs;
		delete[] params.rgvarg;
		if (hr==S_OK)
		{
			return unwrapNETObject(v,pReturn);
		}
		return hr;
	}

	HRESULT hr = target_->Invoke( dispIdMember, riid, lcid, w, pDisp, pReturn, ex, e);
	return hr;
}

////////////////////////////////////////////////////////////////////////

HRESULT BaseCall::CreateInstance(IUnknown* clr,VARIANT target, IDispatch** out)
{
	Instance* i = new Instance;
	i->target_ = target;
	HRESULT hr = clr->QueryInterface(IID__Net,(void**)&(i->clr_) );
	if ( hr != S_OK )
		return hr;

	return i->QueryInterface(IID_IDispatch,(void**)out);
}

HRESULT __stdcall BaseCall::GetIDsOfNames( REFIID  riid, OLECHAR FAR* FAR*  rgszNames, unsigned int  cNames, LCID   lcid, DISPID FAR*  rgDispId )
{
	OLECHAR* name = rgszNames[0];
	std::string n = mol::tostring(name);
	DISPID id = (DISPID) mol::singleton<DotNetClassNames>().getId(n);
	rgDispId[0] = id;
	return S_OK;
}

HRESULT __stdcall BaseCall::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn, EXCEPINFO * ex, UINT * e)
{
	std::string name = mol::singleton<DotNetClassNames>().getName(dispIdMember); 

	mol::variant vRet;
	SafeArrayFromDispParams sa(pDisp);
	HRESULT hr = clr_->InvokeBaseMethod( target_, mol::bstr(name),sa.value, DISPATCH_METHOD, &vRet );
	if ( hr != S_OK )
		return hr;
	return wrapNETObject(clr_,vRet,pReturn);
}

