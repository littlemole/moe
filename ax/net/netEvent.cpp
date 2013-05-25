// types.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "netevent.h"
#include "dot.h"
#include "ole/aut.h"
#include "Util.h"
#include "netType.h"


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

	HRESULT hr = S_OK;

	DispParamsBuf params(pDisp->cArgs);
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

