#ifndef MOL_DEF_GUARD_DEFINE_AX_SCI_ANNO_DEF_GUARD_
#define MOL_DEF_GUARD_DEFINE_AX_SCI_ANNO_DEF_GUARD_

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

class SciAxAnnotation : 
	public mol::Dispatch<IScintillAxAnnotation>,
	public mol::ProvideClassInfo<SciAxAnnotation>,
	public IScintillAxDispose,
	public mol::interfaces< SciAxAnnotation, 
			mol::implements< 
				IDispatch, 
				IScintillAxAnnotation, 
				IScintillAxDispose,
				IProvideClassInfo> >
{
public:

	virtual ~SciAxAnnotation();

	typedef mol::com_obj<SciAxAnnotation> Instance;

	static Instance* CreateInstance( ScintillAx* sci );

	virtual void dispose();

	static REFGUID getCoClassID();
	

	HRESULT virtual __stdcall SetText( long line,  BSTR txt);
	HRESULT virtual __stdcall Clear( long line);
	HRESULT virtual __stdcall ClearAll();
	HRESULT virtual __stdcall SetStyle( long line, long style);

	HRESULT virtual __stdcall Dispose();

private:

	ScintillAx* sci_;
};


#endif