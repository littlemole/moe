#ifndef _MOL_DEF_GUARD_NET_SERVER_UTIL_DEFINE_GUARD_
#define _MOL_DEF_GUARD_NET_SERVER_UTIL_DEFINE_GUARD_

#include "netserver.h"

extern DWORD DISPID_NEW;
extern DWORD DISPID_OF;


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

////////////////////////////////////////////////////////////////////////

HRESULT wrapNETType(IUnknown* clr, mol::variant& in, VARIANT* out);
HRESULT wrapNETObject(IUnknown* clr, VARIANT& in, VARIANT* out);

HRESULT unwrapNETObject( VARIANT in, VARIANT* out);

////////////////////////////////////////////////////////////////////////

class DispParamsBuf : public DISPPARAMS
{
public:
	DispParamsBuf(UINT nArgs);
	DispParamsBuf(UINT nArgs,UINT nNamedArgs);

	~DispParamsBuf();

	void set(UINT index, IDispatch* disp);
	void set(UINT index, VARIANT in);
	void setName(UINT index, DISPID dispid);
};

////////////////////////////////////////////////////////////////////////

class SafeArrayFromDispParams
{
public:

	mol::SafeArray<VT_VARIANT> value;

	SafeArrayFromDispParams(DISPPARAMS* params);
	SafeArrayFromDispParams(DISPPARAMS* params, UINT nArgs);

private:

	void init(DISPPARAMS* params, UINT nArgs);
};

////////////////////////////////////////////////////////////////////////

#endif