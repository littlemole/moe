#ifndef _MOL_JSERVER_DEF_DEFINE_GUARD_
#define _MOL_JSERVER_DEF_DEFINE_GUARD_

#include "ole/ole.h"
#include "ole/com.h"
#include "ole/obj.h"
#include "ole/Bstr.h"
#include "ole/typeinfo.h"
#include "ole/Factory.h"
#include "ole/Factorypolicy.h"
#include "ole/aut.h"
#include "ole/cp.h"
#include "util/istr.h"
#include <DispEx.h>
#include "net_h.h"

////////////////////////////////////////////////////////////////////////

//#import "net.tlb"  no_namespace, raw_interfaces_only, named_guids 
#include "net.tlh"

////////////////////////////////////////////////////////////////////////

class Namespace : 
	public IDispatch, 
	public mol::interfaces<
				Namespace,
				mol::implements<IDispatch>>
{
public:

	typedef mol::com_obj<Namespace> Instance;
	static HRESULT CreateInstance(IDispatch** d, const std::string& path);

	void virtual dispose() {};

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

	DWORD lastId_;
	std::string path_;
	std::map<DWORD,std::string> id2name_;
	std::map<std::string,DWORD> name2id_;

};

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

class EventHandler : 
	public IDispatch, 
	public mol::interfaces<
				EventHandler,
				mol::implements<IDispatch>>
{
public:

	typedef mol::com_obj<EventHandler> Instance;
	static HRESULT CreateInstance(IDispatch* handler, IDispatch** d);

	void virtual dispose() {};

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
};

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

class NetObject : 
	public mol::com_registerobj<NetObject,CLSID_DotNetObject,CLSCTX_LOCAL_SERVER,mol::PROGRAMMABLE|mol::APARTMENT>,//,REGCLS_SINGLEUSE>,
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
	HRESULT virtual __stdcall Initialize(VARIANT ptr);
	HRESULT virtual __stdcall UnWrap(VARIANT* ptr);
	HRESULT virtual __stdcall On(BSTR e, IDispatch* handler);

private:

	mol::variant v_;

};


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
	HRESULT virtual __stdcall Initialize(VARIANT ptr);
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
	mol::variant v_;
};

////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////

class NetServer : 
	public mol::com_registerobj<NetServer,CLSID_DotNet,CLSCTX_LOCAL_SERVER,mol::PROGRAMMABLE|mol::APARTMENT>,
	public mol::Dispatch<INet>,
	public mol::SupportsErrorInfo<&IID_INet,&IID_IDispatch>,
	public mol::interfaces< NetServer,
			mol::implements<
				IDispatch,
				INet,				
				ISupportErrorInfo
				> 
			>
{
public:

	NetServer();

	virtual void dispose();

	HRESULT virtual __stdcall Type( BSTR typeName, INetType** type );
	HRESULT virtual __stdcall Connect(IDispatch* ptr, BSTR eventName, VARIANT target);
	HRESULT virtual __stdcall Import(BSTR clazzName, IDispatch** a);
	HRESULT virtual __stdcall get_Runtime(IDispatch** result);
	HRESULT virtual __stdcall String( BSTR txt, IDispatch** s);
	HRESULT virtual __stdcall Prototype( BSTR name, VARIANT obj, IDispatch** s);
	HRESULT virtual __stdcall Exit();

	HRESULT virtual __stdcall GetTypeInfoCount (unsigned int FAR*  pctinfo );
    HRESULT virtual __stdcall GetTypeInfo ( unsigned int  iTInfo, LCID  lcid, ITypeInfo FAR* FAR*  ppTInfo );
    HRESULT virtual __stdcall GetIDsOfNames( REFIID  riid, OLECHAR FAR* FAR*  rgszNames, unsigned int  cNames, LCID   lcid, DISPID FAR*  rgDispId );
    HRESULT virtual __stdcall Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn, EXCEPINFO * ex, UINT * i);


};


////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

class NetApp : 

	public mol::local_server<mol::win::Loop>,

	public mol::exports< NetApp, NetServer>,

	public mol::exports< 
					NetApp, 
					NetType, 
					mol::ole::ComCreatePolicy<
									NetApp,
									mol::ole::AggregationPolicyNonAggregable<
													NetType,
													mol::com_obj<NetType> 
												> > >,
	public mol::exports< 
					NetApp, 
					NetObject, 
					mol::ole::ComCreatePolicy<
									NetApp,
									mol::ole::AggregationPolicyNonAggregable<
													NetObject,
													mol::com_obj<NetObject> 
												>  > >
{
public:

	NetApp();

	mol::punk<_Net> dotnet;
};

////////////////////////////////////////////////////////////////////////


#endif