#ifndef MOL_DEF_GUARD_DEFINE_SSHSHELL_EXTRACTICON_DEF_GUARD
#define MOL_DEF_GUARD_DEFINE_SSHSHELL_EXTRACTICON_DEF_GUARD

#include "PidlMgr.h"
#include "win/coctrl.h"
#include <shlobj.h>


#define ICON_INDEX_BINARY     0
#define ICON_INDEX_STRING     1
#define ICON_INDEX_FOLDER     2
#define ICON_INDEX_FOLDEROPEN 3
#define ICON_INDEX_ROOT 4


class IconExtractor 
	: public IExtractIcon,
	  public mol::interfaces< IconExtractor, mol::implements<IExtractIcon>>
{

public:
	IconExtractor();
	~IconExtractor();

	typedef mol::com_instance<IconExtractor> Instance;
	static Instance* createInstance(LPCITEMIDLIST pidl);

	void dispose() {}

	//IExtractIcon methods
	HRESULT virtual __stdcall GetIconLocation(UINT, LPTSTR, UINT, LPINT, LPUINT);
	HRESULT virtual __stdcall Extract(LPCTSTR, UINT, HICON*, HICON*, UINT);

private:
	LPITEMIDLIST pidl_;

	mol::Icon icon_;
};




#endif