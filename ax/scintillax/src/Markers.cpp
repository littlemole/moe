#include "StdAfx.h"
#include "Markers.h"
#include "ScintillAx_dispid.h"
#include "ScintillaCtrl.h"

SciAxMarkers::SciAxMarkers()
{
	vbMarkers_			  = VARIANT_FALSE;
}


SciAxMarkers::~SciAxMarkers()
{
	vbMarkers_			  = VARIANT_FALSE;
	ODBGS("~SciAxPosition");
}

SciAxMarkers::Instance* SciAxMarkers::CreateInstance( ScintillAx* sci )
{
	Instance* instance = new Instance;
	instance->sci_ = sci;
	return instance;
}

void SciAxMarkers::dispose()
{
	sci_ = 0;
}

REFGUID SciAxMarkers::getCoClassID()
{
	return IID_IScintillAxMarkers;
}
	


HRESULT __stdcall SciAxMarkers::put_UseMarkers( VARIANT_BOOL vbMarkers)
{
	if (!sci_)
		return E_FAIL;

	if ( vbMarkers_ == vbMarkers )
		return S_OK;

	if ( vbMarkers == VARIANT_TRUE )
	{
		sci_->edit()->useMarkers(true);
		return S_OK;
	}
	sci_->edit()->useMarkers(false);
	return S_OK;
}

HRESULT __stdcall SciAxMarkers::get_UseMarkers( VARIANT_BOOL* vbMarkers)
{
	if ( !vbMarkers )
		return E_INVALIDARG;

	*vbMarkers = vbMarkers_;
	return S_OK;
}

HRESULT __stdcall SciAxMarkers::ToggleMarker( long line)
{
	if (!sci_)
		return E_FAIL;

	sci_->edit()->toggleMarker(line);
	return S_OK;
}

HRESULT __stdcall SciAxMarkers::SetMarker(long line)
{
	if (!sci_)
		return E_FAIL;

	sci_->edit()->setMarker(line);
	return S_OK;
}

HRESULT __stdcall SciAxMarkers::Remove( long line)
{
	if (!sci_)
		return E_FAIL;

	sci_->edit()->removeMarker(line);
	return S_OK;
}

HRESULT __stdcall SciAxMarkers::RemoveAll()
{
	if (!sci_)
		return E_FAIL;

	sci_->edit()->clearAllMarkers();
	return S_OK;
}

HRESULT __stdcall SciAxMarkers::HasMarker( long line)
{
	if (!sci_)
		return E_FAIL;

	sci_->edit()->hasMarker(line);
	return S_OK;
}

HRESULT __stdcall SciAxMarkers::GetMarkers( SAFEARRAY** markers )
{
	if (!sci_)
		return E_FAIL;

	if ( !markers )
		return E_INVALIDARG;

	std::set<int> lines = sci_->edit()->getMarkers();

	mol::ArrayBound ab((long)lines.size());
	mol::SafeArray<VT_I4> sf(ab);
	{
		mol::SFAccess<long> sfa(sf);
	
		int i = 0;
		for ( std::set<int>::iterator it = lines.begin(); it != lines.end(); it++ )
		{
			sfa[i] = (*it);
			i++;
		}
	}
	return ::SafeArrayCopy(sf,markers);
}



HRESULT __stdcall SciAxMarkers::Dispose()
{
	dispose();
	return S_OK;
}