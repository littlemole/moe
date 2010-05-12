#ifndef MOL_DEF_SCINTILLAXEVENTS_VIEW_DEF_GUARDING_
#define MOL_DEF_SCINTILLAXEVENTS_VIEW_DEF_GUARDING_

#pragma once
#include "ole/Bstr.h"
#include "ole/Variant.h"
#include "ole/aut.h"
#include "ole/cp.h"
#include "ScintillAx_h.h"

///////////////////////////////////////////////////////////////////////////////
// dual event impl for scintilla (c++ clients)
///////////////////////////////////////////////////////////////////////////////

class ScintillAxEvents : 
	public mol::Dispatch< IScintillAxEvents, 
					 &IID_IScintillAxEvents, 
					 &LIBID_Scintilla, 1, 0 > ,
	public mol::interfaces< ScintillAxEvents, 
			mol::implements<IDispatch,_IScintillAxEvents> >
{
public:

	HRESULT virtual __stdcall OnFileNameChanged( BSTR filename)		{ return S_OK; }

	HRESULT virtual __stdcall OnShowMenu( VARIANT_BOOL* showMenue)	{ return S_OK; }

	HRESULT virtual __stdcall OnPosChange( long line)				{ return S_OK; }

	HRESULT virtual __stdcall OnChar( BSTR ch)						{ return S_OK; }

	HRESULT virtual __stdcall OnSyntax( long s)						{ return S_OK; }

	HRESULT virtual __stdcall OnSystem( long s)						{ return S_OK; }

	HRESULT virtual __stdcall OnEncoding( long e)						{ return S_OK; }

    HRESULT Advise(IUnknown* object )
    {
        return mol::advise<_IScintillAxEvents>(object,this,cookie_);
    }

    HRESULT UnAdvise(IUnknown* object )
    {
        return mol::unadvise<_IScintillAxEvents>(object,cookie_);
    }

    HRESULT Advise(IUnknown* object, DWORD& cookie )
    {
        return mol::advise<_IScintillAxEvents>(object,this,cookie);
    }

    HRESULT UnAdvise(IUnknown* object, DWORD cookie )
    {
        return mol::unadvise<_IScintillAxEvents>(object,cookie);
    }

private:
    DWORD           cookie_;
};

///////////////////////////////////////////////////////////


#endif