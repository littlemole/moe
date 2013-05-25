// types.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "netobj.h"
#include "dot.h"
#include "Util.h"
#include "netEvent.h"


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

