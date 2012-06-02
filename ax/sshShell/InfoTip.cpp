#include "StdAfx.h"
#include "InfoTip.h"



QueryInfo::QueryInfo()
{
}


QueryInfo::~QueryInfo()
{
	if(pidl_)
	{
		pidlManager().destroy(pidl_);
		pidl_ = NULL;
	}
}

QueryInfo::Instance* QueryInfo::createInstance(LPCITEMIDLIST pidl)
{
	Instance* instance = new Instance;
	instance->pidl_ = pidlManager().copy(pidl);
	return instance;
}

HRESULT __stdcall QueryInfo::GetInfoTip(DWORD dwFlags, WCHAR **ppwszTip)
{
	*ppwszTip = NULL;

	//get the entire text for the item
	std::wstring s = pidlManager().getPidlPath(pidl_);

	//get the number of characters required
	int   cchOleStr = (int)s.size() + 1;

	//allocate the wide character string
	*ppwszTip = (LPWSTR)::CoTaskMemAlloc(cchOleStr * sizeof(WCHAR));
	if(!*ppwszTip)
	   return E_OUTOFMEMORY;

	wcscpy(*ppwszTip,s.c_str());
	return S_OK;
}

HRESULT __stdcall QueryInfo::GetInfoFlags(LPDWORD pdwFlags)
{
	return E_NOTIMPL;
}