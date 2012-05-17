#ifndef MOL_DEF_SHELLTREE_VIEW_DEF_GUARDING_
#define MOL_DEF_SHELLTREE_VIEW_DEF_GUARDING_

#pragma once
#include "ole/Bstr.h"
#include "ole/Variant.h"
#include "ole/aut.h"
#include "ole/cp.h"
#include "shellctrl_h.h"

// not using namespace mol::win::ole;
// not using namespace mol::win::io;

//////////////////////////////////////////////////////////////////////////////////

class ShellTreeEvents : 
	public mol::Dispatch< IShellTreeEvents, 
					 &IID_IShellTreeEvents, 
					 &LIBID_ShellCtrls, 1, 0 >,
	public mol::interfaces< ShellTreeEvents, 
			mol::implements<IDispatch,_IShellTreeEvents> >
{
public:

	HRESULT virtual __stdcall OnTreeSelection(BSTR filename)
	{
		return S_OK;
	}

	HRESULT virtual __stdcall OnTreeDblClick(BSTR filename, VARIANT_BOOL vb)
	{
		return S_OK;
	}

	HRESULT virtual __stdcall OnTreeOpen(BSTR filename, VARIANT_BOOL vb)
	{
		return S_OK;
	}
	
	HRESULT virtual __stdcall OnContextMenu(BSTR filename, VARIANT_BOOL vb)
	{
		return S_OK;
	}

    HRESULT Advise(IUnknown* object )
    {
        return mol::advise<_IShellTreeEvents>(object,this,cookie_);
    }
    HRESULT UnAdvise(IUnknown* object )
    {
        return mol::unadvise<_IShellTreeEvents>(object,cookie_);
    }

private:
    DWORD           cookie_;
};

///////////////////////////////////////////////////////////



#endif