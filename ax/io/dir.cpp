#include "StdAfx.h"
#include "dir.h"

DirObj::Instance* DirObj::CreateInstance(std::vector<mol::string>& v)
{
	Instance* i = new Instance;
	i->AddRef();

	i->entries = v;
	return i;
}

void DirObj::dispose() 
{}

HRESULT __stdcall DirObj::_NewEnum(IEnumVARIANT** newEnum)
{
	return mol::make_enumVariant(entries,newEnum);
}

HRESULT __stdcall DirObj::Item( long i, BSTR* direntry)
{
	if ( !direntry )
		return E_INVALIDARG;

	*direntry = 0;
	if ( i < 0 || i >= (long)entries.size() )
		return E_INVALIDARG;

	*direntry = ::SysAllocString( mol::towstring(entries[i]).c_str() );
	return S_OK;
}

HRESULT __stdcall DirObj::Count( long* cnt)
{
	if (!cnt )
		return E_INVALIDARG;

	*cnt = (long) entries.size();
	return S_OK;
}
