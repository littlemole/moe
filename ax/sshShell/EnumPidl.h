#ifndef MOL_DEF_GUARD_DEFINE_SSHSHELL_ENUMPIDL_DEF_GUARD
#define MOL_DEF_GUARD_DEFINE_SSHSHELL_ENUMPIDL_DEF_GUARD

#include "PidlMgr.h"
#include "ViewModel.h"
#include <shlobj.h>

typedef struct tagENUMLIST
{
    struct tagENUMLIST   *pNext;
    LPITEMIDLIST         pidl;
} ENUMLIST, FAR *LPENUMLIST;


class EnumIDList 
 :  public IEnumIDList,
	public mol::interfaces< EnumIDList, mol::implements<IEnumIDList>>
{  
public:
	EnumIDList();
	~EnumIDList();

	typedef mol::com_instance<EnumIDList> Instance;
	static Instance* createInstance(LPITEMIDLIST pidl, DWORD flags);

	void dispose() {}
     
	//IEnumIDList
	HRESULT virtual __stdcall  Next(DWORD, LPITEMIDLIST*, LPDWORD);
	HRESULT virtual __stdcall  Skip(DWORD);
	HRESULT virtual __stdcall  Reset(void);
	HRESULT virtual __stdcall  Clone(LPENUMIDLIST*);
   
private:

	//bool enumeratePath( DWORD dwFlags, const std::wstring& host, int port, const std::wstring& path);
	bool createEnumList(LPITEMIDLIST pidl, DWORD);
	bool addToEnumList(LPITEMIDLIST);
	void deleteList();

	//bool enumerateSshServers(LPCITEMIDLIST pidl, DWORD dwFlags);
	//bool enumerateSshServerRoot(LPCITEMIDLIST pidl, DWORD dwFlags);
	//bool enumerateSshServerPath(LPCITEMIDLIST pidl, DWORD dwFlags);


	LPENUMLIST pFirst_;
	LPENUMLIST pLast_;
	LPENUMLIST pCurrent_;
};


#endif


