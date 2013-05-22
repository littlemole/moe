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
	static HRESULT CreateInstance(IDispatch** d, const std::string& path, INet* inet);

	void virtual dispose() 
	{
		clr_.release();
		inet_.release();
		id2name_.clear();
		name2id_.clear();
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

	DWORD lastId_;
	std::string path_;
	std::map<DWORD,std::string> id2name_;
	std::map<std::string,DWORD> name2id_;
	mol::punk<INet> inet_;
	mol::punk<_Net> clr_;
};

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
	HRESULT virtual __stdcall Initialize(VARIANT ptr,IUnknown* clr);
	HRESULT virtual __stdcall UnWrap(VARIANT* ptr);
	HRESULT virtual __stdcall On(BSTR e, VARIANT handler);

private:

	mol::variant	v_;
	mol::punk<_Net> clr_;
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
	HRESULT virtual __stdcall copyTo( IDispatch* src, IDispatch* dest);
	HRESULT virtual __stdcall get_CLR( IUnknown** unk);
	HRESULT virtual __stdcall Exit();
	HRESULT virtual __stdcall Declare( BSTR name, IDispatch* def, IDispatch* handler, IDispatch** unk);
	HRESULT virtual __stdcall Array( IDispatch* type, IDispatch* values, IDispatch** s);

	HRESULT virtual __stdcall GetTypeInfoCount (unsigned int FAR*  pctinfo );
    HRESULT virtual __stdcall GetTypeInfo ( unsigned int  iTInfo, LCID  lcid, ITypeInfo FAR* FAR*  ppTInfo );
    HRESULT virtual __stdcall GetIDsOfNames( REFIID  riid, OLECHAR FAR* FAR*  rgszNames, unsigned int  cNames, LCID   lcid, DISPID FAR*  rgDispId );
    HRESULT virtual __stdcall Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn, EXCEPINFO * ex, UINT * i);

private:

	HRESULT getAttributes(IDispatch* disp, mol::SafeArray<VT_VARIANT>& result);
	HRESULT getProperties(IDispatch* def, mol::SafeArray<VT_VARIANT>& result);
	HRESULT getMethods(IDispatch* def, mol::SafeArray<VT_VARIANT>& result);
	HRESULT getInterfaces(IDispatch* def, mol::SafeArray<VT_VARIANT>& result);

	mol::punk<_Net> clr_;
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
};

////////////////////////////////////////////////////////////////////////


#endif