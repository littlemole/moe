#ifndef MOL_DEF_GUARD_DEFINE_AX_SCI_LINE_DEF_GUARD_
#define MOL_DEF_GUARD_DEFINE_AX_SCI_LINE_DEF_GUARD_

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

class SciAxLine : 
	public mol::Dispatch<IScintillAxLine>,
	public mol::ProvideClassInfo<SciAxLine>,
	public IScintillAxDispose,
	public mol::interfaces< SciAxLine, 
			mol::implements< 
				IDispatch, 
				IScintillAxLine, 
				IScintillAxDispose,
				IProvideClassInfo> >
{
public:

	virtual ~SciAxLine();

	typedef mol::com_obj<SciAxLine> Instance;

	static Instance* CreateInstance( ScintillAx* sci);

	virtual void dispose();

	static REFGUID getCoClassID();
	
	HRESULT virtual __stdcall Current( long* line);
	HRESULT virtual __stdcall get_Count( long* cnt);

	HRESULT virtual __stdcall LineFromPos( long pos, long* line );
	HRESULT virtual __stdcall PosFromLine( long line, long* pos );
	HRESULT virtual __stdcall LineEndPos( long line, long* pos );

	HRESULT virtual __stdcall FirstVisibleLine( long* line);
	HRESULT virtual __stdcall LinesOnScreen( long* line);

	HRESULT virtual __stdcall LineLength( long line, long* length);
	HRESULT virtual __stdcall LineText( long line, BSTR* text );
	HRESULT virtual __stdcall SetLineText( long line, BSTR text );
	HRESULT virtual __stdcall Goto( long pos);
	
	HRESULT virtual __stdcall Highlite( long line );

	HRESULT virtual __stdcall Dispose();
private:

	ScintillAx* sci_;
};


#endif