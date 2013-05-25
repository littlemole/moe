// types.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "nettype.h"
#include "util.h"
#include "dot.h"

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
			{
				hr = clr_->GetSubType( v_, mol::bstr(name),&vRet );
				if ( hr != S_OK || vRet.vt == VT_EMPTY)
				{
					return DISP_E_MEMBERNOTFOUND;
				}
				return wrapNETType(clr_,vRet,pReturn);
			}

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


