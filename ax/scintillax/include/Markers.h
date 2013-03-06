#ifndef MOL_DEF_GUARD_DEFINE_AX_SCI_MARKERS_DEF_GUARD_
#define MOL_DEF_GUARD_DEFINE_AX_SCI_MARKERS_DEF_GUARD_

#include "util/uni.h"
#include "win/enc.h"
#include "scieditor.h"
#include "win/MsgMap.h"
#include "ole/Ctrl.h"
#include "ole/Bstr.h"
#include "ole/Persist.h"
#include "ScintillAx_h.h"
#include "ShellCtrl/ShellCtrl_h.h"
#include "include/resource.h"
#include "include/xmlui.h"

class ScintillAx;

class SciAxMarkers : 
	public mol::Dispatch<IScintillAxMarkers>,
	public mol::ProvideClassInfo<SciAxMarkers>,
	public IScintillAxDispose,
	public mol::interfaces< SciAxMarkers, 
			mol::implements< 
				IDispatch, 
				IScintillAxMarkers, 
				IScintillAxDispose,
				IProvideClassInfo> >
{
public:

	SciAxMarkers();
	virtual ~SciAxMarkers();

	typedef mol::com_obj<SciAxMarkers> Instance;

	static Instance* CreateInstance( ScintillAx* sci);

	virtual void dispose();

	static REFGUID getCoClassID();
	

	HRESULT virtual __stdcall put_UseMarkers( VARIANT_BOOL vbMarkers);
	HRESULT virtual __stdcall get_UseMarkers( VARIANT_BOOL* vbMarkers);
	HRESULT virtual __stdcall ToggleMarker( long line);
	HRESULT virtual __stdcall SetMarker(long line);
	HRESULT virtual __stdcall Remove( long line);
	HRESULT virtual __stdcall RemoveAll();
	HRESULT virtual __stdcall HasMarker( long line);
	HRESULT virtual __stdcall GetMarkers( SAFEARRAY** markers );

	HRESULT virtual __stdcall Dispose();

private:
	VARIANT_BOOL			vbMarkers_;
	ScintillAx* sci_;
};


#endif