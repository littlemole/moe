#ifndef MOL_DEF_GUARD_DEFINE_AX_SCI_SEL_DEF_GUARD_
#define MOL_DEF_GUARD_DEFINE_AX_SCI_SEL_DEF_GUARD_

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

class SciAxSelection : 
	public mol::Dispatch<IScintillAxSelection>,
	public mol::ProvideClassInfo<SciAxSelection>,
	public IScintillAxDispose,
	public mol::interfaces< SciAxSelection, 
			mol::implements< 
				IDispatch, 
				IScintillAxSelection, 
				IScintillAxDispose,
				IProvideClassInfo> >
{
public:

	virtual ~SciAxSelection();

	typedef mol::com_obj<SciAxSelection> Instance;

	static Instance* CreateInstance( ScintillAx* sci);

	virtual void dispose();

	static REFGUID getCoClassID();
	
	HRESULT virtual __stdcall GetSelection ( long* first, long* last );
	HRESULT virtual __stdcall SetSelection ( long first, long last );
	HRESULT virtual __stdcall get_Text( BSTR* text );
	HRESULT virtual __stdcall put_Text( BSTR text );

	HRESULT virtual __stdcall put_Start( long pos);
	HRESULT virtual __stdcall get_Start(  long* pos);
	HRESULT virtual __stdcall put_End( long pos);
	HRESULT virtual __stdcall get_End(  long* pos);

	// cut / copy / pasty
	HRESULT virtual __stdcall Cut();
	HRESULT virtual __stdcall Copy();
	HRESULT virtual __stdcall Paste();

	HRESULT virtual __stdcall Dispose();
private:

	ScintillAx* sci_;
};


#endif