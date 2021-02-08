#ifndef MOL_DEF_GUARD_DEFINE_AX_SCI_POS_DEF_GUARD_
#define MOL_DEF_GUARD_DEFINE_AX_SCI_POS_DEF_GUARD_

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

class ScintillAx;

class SciAxPosition : 
	public mol::Dispatch<IScintillAxPosition>,
	public mol::ProvideClassInfo<SciAxPosition>,
	public IScintillAxDispose,
	public mol::interfaces< SciAxPosition, 
			mol::implements< 
				IDispatch, 
				IScintillAxPosition, 
				IScintillAxDispose,
				IProvideClassInfo> >
{
public:

	virtual ~SciAxPosition();

	typedef mol::com_obj<SciAxPosition> Instance;

	static Instance* CreateInstance( ScintillAx* sci );

	virtual void dispose();

	static REFGUID getCoClassID();
	
	HRESULT virtual __stdcall put_Caret( long pos);
	HRESULT virtual __stdcall get_Caret( long* pos);

	HRESULT virtual __stdcall put_SearchPos( long pos);
	HRESULT virtual __stdcall get_SearchPos( long* pos);

	HRESULT virtual __stdcall put_Anchor( long pos);
	HRESULT virtual __stdcall get_Anchor( long* pos);


	HRESULT virtual __stdcall CharAt( long pos, BSTR* ch);
	HRESULT virtual __stdcall ScrollIntoView();
	HRESULT virtual __stdcall Scroll( long cols, long lines);

	HRESULT virtual __stdcall Dispose();

private:

	ScintillAx* sci_;
};


#endif