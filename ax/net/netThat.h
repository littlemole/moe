#ifndef _MOL_JSERVER_DEF_THAT_DEFINE_GUARD_
#define _MOL_JSERVER_DEF_THAT_DEFINE_GUARD_

#include "netserver.h"

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////


class ThatCall : 
	public IDispatch, 
	public mol::interfaces<
				ThatCall,
				mol::implements<IDispatch>>
{
public:

	typedef mol::com_obj<ThatCall> Instance;
	static HRESULT CreateInstance(IUnknown* clr, IDispatch* target, IDispatch** out);

	void virtual dispose() 
	{
		clr_.release();
		target_.release();
	};

	HRESULT virtual __stdcall GetTypeInfoCount (unsigned int FAR*  pctinfo ) 
    { 
        *pctinfo = 0;
        return S_OK; 
    }

    HRESULT virtual __stdcall GetTypeInfo ( unsigned int  iTInfo, LCID  lcid, ITypeInfo FAR* FAR*  ppTInfo ) 
    { 
		*ppTInfo = 0;
        return E_NOTIMPL; 
    }

    HRESULT virtual __stdcall GetIDsOfNames( REFIID  riid, OLECHAR FAR* FAR*  rgszNames, unsigned int  cNames, LCID   lcid, DISPID FAR*  rgDispId );

    HRESULT virtual __stdcall Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn, EXCEPINFO * ex, UINT * i);

private:
	mol::punk<IDispatch> target_;
	mol::punk<_Net> clr_;
};

////////////////////////////////////////////////////////////////////////

class BaseCall : 
	public IDispatch, 
	public mol::interfaces<
				BaseCall,
				mol::implements<IDispatch>>
{
public:

	typedef mol::com_obj<BaseCall> Instance;
	static HRESULT CreateInstance(IUnknown* clr, VARIANT target, IDispatch** out);

	void virtual dispose() 
	{
		clr_.release();
	};

	HRESULT virtual __stdcall GetTypeInfoCount (unsigned int FAR*  pctinfo ) 
    { 
        *pctinfo = 0;
        return S_OK; 
    }

    HRESULT virtual __stdcall GetTypeInfo ( unsigned int  iTInfo, LCID  lcid, ITypeInfo FAR* FAR*  ppTInfo ) 
    { 
		*ppTInfo = 0;
        return E_NOTIMPL; 
    }

    HRESULT virtual __stdcall GetIDsOfNames( REFIID  riid, OLECHAR FAR* FAR*  rgszNames, unsigned int  cNames, LCID   lcid, DISPID FAR*  rgDispId );

    HRESULT virtual __stdcall Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn, EXCEPINFO * ex, UINT * i);

private:
	mol::variant target_;
	mol::punk<_Net> clr_;
};

////////////////////////////////////////////////////////////////////////

#endif