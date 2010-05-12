#include "ole/persist.h"

/////////////////////////////////////////////////////////////////////

namespace mol {
namespace ole {

GetPutProperty::GetPutProperty( const char* k, DISPID i, VARTYPE v, const GUID* g )
	: diid(i), key(k), vt(v)
{
	guid = g;
}

GetPutProperty::~GetPutProperty()
{}

HRESULT __stdcall GetPutProperty::Load( IDispatch* disp, LPSTREAM pStm) 
{
	variant v((BSTR)0);
	v.vt = vt;
	v.fromStream(pStm);
	put(disp,diid,&v);
	return S_OK;
}

HRESULT __stdcall GetPutProperty::Save( IDispatch* disp, LPSTREAM pStm)
{
	variant v;
	get(disp,diid,&v);
	v.toStream(pStm);
	return S_OK;
}

HRESULT __stdcall GetPutProperty::GetSizeMax( IDispatch* disp, ULARGE_INTEGER *pCbSize)
{
	pCbSize->QuadPart += sizeof(variant);
	return S_OK;
}

HRESULT __stdcall GetPutProperty::InitNew(IDispatch* disp) 
{
	return S_OK;
}

HRESULT __stdcall GetPutProperty::Load( IDispatch* disp, IPropertyBag *pPropBag) 
{
	variant v((BSTR)0);
	if ( S_OK == pPropBag->Read( mol::ansi2wstring(key).c_str(), &v, NULL ) )
	{
		v.changeType(vt);
		put(disp,diid,&v);
	}
	return S_OK;
}

HRESULT __stdcall GetPutProperty::Save( IDispatch* disp, IPropertyBag *pPropBag) 
{
	variant v;
	get(disp,diid,&v);
	v.changeType(VT_BSTR);
	pPropBag->Write( mol::ansi2wstring(key).c_str(), &v );
	return S_OK;
}

/////////////////////////////////////////////////////////////////////

GetPutProperty* make_property( const char* key, DISPID d, VARTYPE v, const GUID* g )
{
	return new GetPutProperty( key, d, v, g );
}

} // end namespace mol::win::ole
} // end namespace mol