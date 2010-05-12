#ifndef MOL_DEF_HEX_VIEW_DEF_GUARDING_
#define MOL_DEF_HEX_VIEW_DEF_GUARDING_

#pragma once
#include "ole/Bstr.h"
#include "ole/Variant.h"
#include "ole/aut.h"
#include "ole/cp.h"
#include "shellctrl_h.h"

// not using namespace mol::win::ole;
// not using namespace mol::win::io;

//////////////////////////////////////////////////////////////////////////////////

class HexCtrlEvents : 
	public mol::Dispatch< IHexCtrlEvents, 
					 &IID_IHexCtrlEvents, 
					 &LIBID_ShellCtrls, 1, 0 >,
	public mol::interfaces< HexCtrlEvents, 
			mol::implements<IDispatch,_IHexCtrlEvents> >
{
public:

	HRESULT virtual __stdcall OnNewFile( BSTR fname, VARIANT_BOOL vbReadOnly)
	{
		return S_OK;
	}

	HRESULT virtual __stdcall OnNewOffset(BSTR offset, BSTR val)
	{
		return S_OK;
	}

	HRESULT virtual __stdcall OnNewValue(BSTR offset, BSTR val)
	{
		return S_OK;
	}

    HRESULT Advise(IUnknown* object )
    {
        return mol::advise<_IHexCtrlEvents>(object,this,cookie_);
    }
    HRESULT UnAdvise(IUnknown* object )
    {
        return mol::unadvise<_IHexCtrlEvents>(object,cookie_);
    }

private:
    DWORD           cookie_;
};

///////////////////////////////////////////////////////////



#endif