#ifndef MOL_DEF_GUARD_DEFINE_SSHSHELL_TOOLTIP_DEF_GUARD
#define MOL_DEF_GUARD_DEFINE_SSHSHELL_TOOLTIP_DEF_GUARD

#include "PidlMgr.h"
#include "win/coctrl.h"
#include <shlobj.h>


class QueryInfo 
	: public IQueryInfo,
	  public mol::interfaces< QueryInfo, mol::implements<IQueryInfo>>
{

public:
	QueryInfo();
	~QueryInfo();

	typedef mol::com_instance<QueryInfo> Instance;
	static Instance* createInstance(LPCITEMIDLIST pidl);

	void dispose() {}

	//IQueryInfo methods
	HRESULT virtual __stdcall GetInfoTip(DWORD dwFlags, WCHAR **ppwszTip);
	HRESULT virtual __stdcall GetInfoFlags(LPDWORD pdwFlags);


private:
	LPITEMIDLIST pidl_;
};




#endif