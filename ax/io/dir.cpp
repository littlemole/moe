#include "StdAfx.h"
#include "dir.h"

DirObj::Instance* DirObj::CreateInstance(std::vector<mol::string>& v)
{
	Instance* i = new Instance;
	i->AddRef();

	for ( unsigned int c = 0; c < v.size(); c++ )
	{
		i->collection.Add( variant(bstr(v[c])) );
	}
	return i;
}

void DirObj::dispose() 
{}

HRESULT __stdcall DirObj::_NewEnum(IEnumVARIANT** newEnum)
{
	return collection._NewEnum(newEnum);
}

HRESULT __stdcall DirObj::Item( long i, BSTR* direntry)
{
	if ( !direntry )
		return E_INVALIDARG;

	*direntry = 0;
	variant v(i);
	variant ret;
	if ( S_OK == collection.Item(v,&ret) )
	{
		if ( ret.vt == VT_BSTR )
		{
			*direntry = ::SysAllocString(ret.bstrVal);
			return S_OK;
		}
	}
	return S_FALSE;
}

HRESULT __stdcall DirObj::Count( long* cnt)
{
	if (!cnt )
		return E_INVALIDARG;
	*cnt = 0;
	variant v;
	if ( S_OK == collection.Count(&v))
	{
		*cnt = v.lVal;
	}
	return S_OK;
}
