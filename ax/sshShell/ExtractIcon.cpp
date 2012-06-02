#include "StdAfx.h"
#include "ExtractIcon.h"

extern mol::ImageList imgageListLarge;
extern mol::ImageList imgageListSmall;

IconExtractor::IconExtractor()
	:pidl_(0)
{
	icon_.load(IDI_STRING,16,16);
}


IconExtractor::~IconExtractor()
{
	if(pidl_)
	{
		pidlManager().destroy(pidl_);
		pidl_ = NULL;
	}
}

IconExtractor::Instance* IconExtractor::createInstance(LPCITEMIDLIST pidl)
{
	Instance* instance = new Instance;
	instance->pidl_ = pidlManager().copy(pidl);
	return instance;
}

///////////////////////////////////////////////////////////////////////////
//
// IExtractIcon Implementation
//


HRESULT __stdcall IconExtractor::GetIconLocation( UINT uFlags, LPTSTR szIconFile, UINT cchMax, LPINT piIndex, LPUINT puFlags)
{
	*puFlags = GIL_NOTFILENAME|GIL_PERINSTANCE|GIL_DONTCACHE;
	
	if(pidlManager().isFile(pidlManager().getLastItem(pidl_)))
    {
		 *piIndex = ICON_INDEX_STRING;
	}
	else
	if(pidlManager().isRoot(pidlManager().getLastItem(pidl_)))
    {
		 *piIndex = ICON_INDEX_ROOT;
	}
	else
	if(pidlManager().isServer(pidlManager().getLastItem(pidl_)))
    {
		 *piIndex = ICON_INDEX_BINARY;
	}
	else
	if(!pidlManager().isDir(pidl_))
    {
		 *piIndex = ICON_INDEX_BINARY;
	}
	else
	{
		if(uFlags & GIL_OPENICON)
		{
			*piIndex = ICON_INDEX_FOLDEROPEN;
		}
		else
		{
			*piIndex = ICON_INDEX_FOLDER; 
		}
	}

	return S_OK;
}



HRESULT __stdcall IconExtractor::Extract( LPCTSTR pszFile, UINT nIconIndex, HICON *phiconLarge, HICON *phiconSmall, UINT nIconSize)
{
	*phiconLarge = ImageList_GetIcon( (HIMAGELIST) imgageListLarge, nIconIndex, ILD_TRANSPARENT);
	*phiconSmall = ImageList_GetIcon((HIMAGELIST) imgageListSmall, nIconIndex, ILD_TRANSPARENT);
	return S_OK;
}

