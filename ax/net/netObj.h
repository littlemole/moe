#ifndef _MOL_JSERVER_DEF_NETOBJ_DEFINE_GUARD_
#define _MOL_JSERVER_DEF_NETOBJ_DEFINE_GUARD_

#include "netserver.h"

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

class NetObject : 
	public mol::com_registerobj<NetObject,CLSID_DotNetObject,CLSCTX_LOCAL_SERVER,mol::PROGRAMMABLE|mol::APARTMENT>,
	public INetObject, 
	public mol::SupportsErrorInfo<&IID_INetObject,&IID_IDispatch>,
	public mol::interfaces<
				NetObject,
				mol::implements< 
					IDispatch,
					INetObject,
					ISupportErrorInfo
					> 
				>
{
public:

	void virtual dispose();
	
	HRESULT virtual __stdcall GetTypeInfoCount (unsigned int FAR*  pctinfo );
    HRESULT virtual __stdcall GetTypeInfo ( unsigned int  iTInfo, LCID  lcid, ITypeInfo FAR* FAR*  ppTInfo );
    HRESULT virtual __stdcall GetIDsOfNames( REFIID  riid, OLECHAR FAR* FAR*  rgszNames, unsigned int  cNames, LCID   lcid, DISPID FAR*  rgDispId );
    HRESULT virtual __stdcall Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn, EXCEPINFO * ex, UINT * i);
	HRESULT virtual __stdcall Initialize(VARIANT ptr,IUnknown* clr);
	HRESULT virtual __stdcall UnWrap(VARIANT* ptr);
	HRESULT virtual __stdcall On(BSTR e, VARIANT handler);

private:

	mol::variant	v_;
	mol::punk<_Net> clr_;
};

////////////////////////////////////////////////////////////////////////

#endif