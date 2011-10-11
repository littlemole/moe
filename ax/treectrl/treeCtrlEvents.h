#ifndef MOL_DEF_SHELLFOLDER_VIEW_DEF_GUARDING_
#define MOL_DEF_SHELLFOLDER_VIEW_DEF_GUARDING_

#pragma once
#include "ole/Bstr.h"
#include "ole/Variant.h"
#include "ole/Aut.h"
#include "ole/cp.h"
#include "shellfolder_h.h"

// not using namespace mol::ole;
// not using namespace mol::io;

//////////////////////////////////////////////////////////////////////////////////

class ShellFolderEvents : 
	public mol::Dispatch< IShellPaneEvents, 
					 &IID_IShellPaneEvents, 
					 &LIBID_ShellFolder, 1, 0 > ,
	public mol::interfaces< ShellFolderEvents, 
			mol::implements< IDispatch, _IShellPaneEvents> >
{
public:

	HRESULT virtual __stdcall OnListSelection(BSTR filename)
	{
		return S_OK;
	}

	HRESULT virtual __stdcall OnListDblClick(BSTR filename)
	{
		return S_OK;
	}

	HRESULT virtual __stdcall OnListOpen(BSTR filename)
	{
		return S_OK;
	}

	HRESULT virtual __stdcall OnDirChanged(BSTR dir)
	{
		return S_OK;
	}

    HRESULT Advise(IUnknown* object )
    {
		return mol::advise<_IShellPaneEvents>(object,this,cookie_);
    }
    HRESULT UnAdvise(IUnknown* object )
    {
        return mol::unadvise<_IShellPaneEvents>(object,cookie_);
    }

private:
    DWORD           cookie_;
};

///////////////////////////////////////////////////////////

#endif