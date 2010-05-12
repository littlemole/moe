#ifndef MOL_DEF_SHELLLIST_VIEW_DEF_GUARDING_
#define MOL_DEF_SHELLLIST_VIEW_DEF_GUARDING_

#pragma once
#include "ole/Bstr.h"
#include "ole/Variant.h"
#include "ole/Aut.h"
#include "ole/cp.h"
#include "shellctrl_h.h"

// not using namespace mol::ole;
// not using namespace mol::io;

//////////////////////////////////////////////////////////////////////////////////

class ShellListEvents : 
	public mol::Dispatch< IShellListEvents, 
					 &IID_IShellListEvents, 
					 &LIBID_ShellCtrls, 1, 0 > ,
	public mol::interfaces< ShellListEvents, 
			mol::implements< IDispatch, _IShellListEvents> >
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
		return mol::advise<_IShellListEvents>(object,this,cookie_);
    }
    HRESULT UnAdvise(IUnknown* object )
    {
        return mol::unadvise<_IShellListEvents>(object,cookie_);
    }

private:
    DWORD           cookie_;
};

///////////////////////////////////////////////////////////

#endif