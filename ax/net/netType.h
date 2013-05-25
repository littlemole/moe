#ifndef _MOL_JSERVER_NETTYPE_DEF_DEFINE_GUARD_
#define _MOL_JSERVER_NETTYPE_DEF_DEFINE_GUARD_

#include "netserver.h"


////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////


class NetType : 
	public mol::com_registerobj<NetType,CLSID_DotNetType,CLSCTX_LOCAL_SERVER,mol::PROGRAMMABLE|mol::APARTMENT>,
	public INetType,  
	public IDispatchEx,
	public mol::SupportsErrorInfo<&IID_INetType,&IID_IDispatch>,
	public mol::interfaces<
				NetType,
				mol::implements< 
					mol::interface_ex<IDispatch,INetType>,
					IDispatchEx,
					INetType,
					ISupportErrorInfo
					> 
				>
{
public:


	void virtual dispose();

	HRESULT virtual __stdcall GetTypeInfoCount (unsigned int FAR*  pctinfo );
    HRESULT virtual __stdcall GetTypeInfo ( unsigned int  iTInfo, LCID  lcid, ITypeInfo FAR* FAR*  ppTInfo );
    HRESULT virtual __stdcall GetIDsOfNames( REFIID  riid, OLECHAR FAR* FAR*  rgszNames, unsigned int  cNames, LCID   lcid, DISPID FAR*  rgDispId );
    HRESULT virtual __stdcall Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn, EXCEPINFO * ex, UINT * i) ;
	HRESULT virtual __stdcall Initialize(VARIANT ptr,IUnknown* clr);
	HRESULT virtual __stdcall UnWrap(VARIANT* ptr);


    HRESULT virtual __stdcall GetDispID( BSTR bstrName, DWORD grfdex, DISPID *pid);
    HRESULT virtual __stdcall InvokeEx( DISPID id,LCID lcid, WORD wFlags, DISPPARAMS *pdp, VARIANT *pvarRes, EXCEPINFO *pei, IServiceProvider *pspCaller);
    HRESULT virtual __stdcall DeleteMemberByName( BSTR bstrName, DWORD grfdex);        
    HRESULT virtual __stdcall DeleteMemberByDispID( DISPID id);    
    HRESULT virtual __stdcall GetMemberProperties( DISPID id, DWORD grfdexFetch, DWORD *pgrfdex);       
    HRESULT virtual __stdcall GetMemberName( DISPID id, BSTR *pbstrName);       
    HRESULT virtual __stdcall GetNextDispID( DWORD grfdex, DISPID id, DISPID *pid);       
    HRESULT virtual __stdcall GetNameSpaceParent( IUnknown **ppunk);

private:
	mol::variant	v_;
	mol::punk<_Net> clr_;
};

////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////



#endif