#ifndef MOL_DEF_GUARD_DEFINE_AX_SCI_TXT_DEF_GUARD_
#define MOL_DEF_GUARD_DEFINE_AX_SCI_TXT_DEF_GUARD_

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

class SciAxText : 
	public mol::Dispatch<IScintillAxText>,
	public mol::ProvideClassInfo<SciAxText>,
	public IScintillAxDispose,
	public mol::interfaces< SciAxText, 
			mol::implements< 
				IDispatch, 
				IScintillAxText, 
				IScintillAxDispose,
				IProvideClassInfo> >
{
public:

	virtual ~SciAxText();

	typedef mol::com_obj<SciAxText> Instance;

	static Instance* CreateInstance( ScintillAx* sci);

	virtual void dispose();

	static REFGUID getCoClassID();
	
	HRESULT virtual __stdcall put_Value( BSTR text);
	HRESULT virtual __stdcall get_Value( BSTR* text);

	HRESULT virtual __stdcall get_Length( long* size);
	HRESULT virtual __stdcall get_Modified( VARIANT_BOOL* vbModified );

	HRESULT virtual __stdcall SetText( BSTR text);
	HRESULT virtual __stdcall GetText( BSTR* text);
	HRESULT virtual __stdcall GetTextRange(long start, long end, BSTR* range);

	HRESULT virtual __stdcall Append( BSTR text);
	HRESULT virtual __stdcall Insert( BSTR text, long pos );

	HRESULT virtual __stdcall Search( BSTR what, long flags, VARIANT_BOOL* vbFound);
	HRESULT virtual __stdcall Replace( BSTR what, BSTR with, long flags, VARIANT_BOOL* vbReplaced);	

	HRESULT virtual __stdcall Dispose();
private:

	ScintillAx* sci_;
};


#endif