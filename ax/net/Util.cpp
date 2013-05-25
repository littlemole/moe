#include "StdAfx.h"
#include "Util.h"

#include "Util.h"

DWORD DISPID_NEW = 0;
DWORD DISPID_OF  = 1;

////////////////////////////////////////////////////////////////////////

DispParamsBuf::DispParamsBuf(UINT nArgs)
{
	cArgs = nArgs;
	cNamedArgs = 0;
	rgvarg = new VARIANTARG[cArgs];
	rgdispidNamedArgs = 0;		
}

DispParamsBuf::DispParamsBuf(UINT nArgs,UINT nNamedArgs)
{
	cArgs = nArgs;
	cNamedArgs = nNamedArgs;
	rgvarg = new VARIANTARG[cArgs];
	rgdispidNamedArgs = new DISPID[cNamedArgs];		
}

DispParamsBuf::~DispParamsBuf()
{
	for ( UINT i = 0; i < cArgs; i++)
	{
		::VariantClear(&rgvarg[i]);
	}
	delete[] rgvarg;
	delete[] rgdispidNamedArgs;
}

void DispParamsBuf::set(UINT index, IDispatch* disp)
{
	rgvarg[index].vt = VT_DISPATCH;
	rgvarg[index].pdispVal = disp;
	disp->AddRef();
}

void DispParamsBuf::set(UINT index, VARIANT in)
{
	rgvarg[index].vt = VT_EMPTY;
	rgvarg[index].pdispVal = 0;
		
	::VariantCopy(&rgvarg[index],&in);
}

void DispParamsBuf::setName(UINT index, DISPID dispid)
{
	rgdispidNamedArgs[index] = dispid;
}

////////////////////////////////////////////////////////////////////////


SafeArrayFromDispParams::SafeArrayFromDispParams(DISPPARAMS* params)
{
	UINT nArgs = params->cArgs - params->cNamedArgs;
	init(params,nArgs);
}

SafeArrayFromDispParams::SafeArrayFromDispParams(DISPPARAMS* params, UINT nArgs)
{
	init(params,nArgs);
}


void SafeArrayFromDispParams::init(DISPPARAMS* params, UINT nArgs)
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


////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////

HRESULT wrapNETObject(IUnknown* clr, VARIANT& in, VARIANT* out)
{
	if ( !out )
		return S_OK;

	if ( (in.vt != VT_DISPATCH) && (in.vt != VT_UNKNOWN) )
	{
		out->vt = VT_EMPTY;
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

////////////////////////////////////////////////////////////////////////

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


////////////////////////////////////////////////////////////////////////

