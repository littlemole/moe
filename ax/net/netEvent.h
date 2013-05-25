#ifndef _MOL_JSERVER_EVENT_DEF_DEFINE_GUARD_
#define _MOL_JSERVER_EVENT_DEF_DEFINE_GUARD_

#include "netserver.h"

////////////////////////////////////////////////////////////////////////

class EventHandler : 
	public IDispatch, 
	public mol::interfaces<
				EventHandler,
				mol::implements<IDispatch>>
{
public:

	typedef mol::com_obj<EventHandler> Instance;
	static HRESULT CreateInstance(IUnknown* clr, IDispatch* handler, IDispatch** d);
	static HRESULT CreateInstance(IUnknown* clr, IDispatch* disp, mol::bstr handler, IDispatch** d);

	void virtual dispose() 
	{
		handler_.release();
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

	mol::punk<IDispatch> handler_;
	mol::bstr callback_;
	mol::punk<_Net> clr_;
};

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

#endif