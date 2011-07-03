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

#include "net_h.h"
////////////////////////////////////////////////////////////////////////

//#import "net.tlb"  no_namespace, raw_interfaces_only, named_guids 
#include "net.tlh"

////////////////////////////////////////////////////////////////////////
class NetObject : 
	public mol::com_registerobj<NetObject,CLSID_DotNetObject,CLSCTX_LOCAL_SERVER,mol::PROGRAMMABLE|mol::MULTITHREADED>,//,REGCLS_SINGLEUSE>,
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

private:

	mol::variant v_;

};


////////////////////////////////////////////////////////////////////////
class NetType : 
	public mol::com_registerobj<NetType,CLSID_DotNetType,CLSCTX_LOCAL_SERVER,mol::PROGRAMMABLE|mol::MULTITHREADED>,
	public INetType,  
	public mol::SupportsErrorInfo<&IID_INetType,&IID_IDispatch>,
	public mol::interfaces<
				NetType,
				mol::implements< 
					IDispatch,
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

private:
	mol::variant v_;
};

////////////////////////////////////////////////////////////////////////
class NetAssembly : 
	public mol::com_registerobj<NetAssembly,CLSID_DotNetAssembly,CLSCTX_LOCAL_SERVER,mol::PROGRAMMABLE|mol::MULTITHREADED>,
	public mol::Dispatch<INetAssembly>,
	public mol::SupportsErrorInfo<&IID_INetAssembly,&IID_IDispatch>,
	public mol::interfaces<
				NetAssembly,
				mol::implements< 
					IDispatch,
					INetAssembly,
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

	HRESULT virtual __stdcall Type( BSTR clazzName, INetType** clazz);
	HRESULT virtual __stdcall Connect(IDispatch* ptr, BSTR eventName, VARIANT target);

private:
	mol::variant v_;
};


////////////////////////////////////////////////////////////////////////

class NetServer : 
	public mol::com_registerobj<NetServer,CLSID_DotNet,CLSCTX_LOCAL_SERVER,mol::PROGRAMMABLE|mol::MULTITHREADED>,
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


	HRESULT virtual __stdcall GetTypeInfoCount (unsigned int FAR*  pctinfo );
    HRESULT virtual __stdcall GetTypeInfo ( unsigned int  iTInfo, LCID  lcid, ITypeInfo FAR* FAR*  ppTInfo );
    HRESULT virtual __stdcall GetIDsOfNames( REFIID  riid, OLECHAR FAR* FAR*  rgszNames, unsigned int  cNames, LCID   lcid, DISPID FAR*  rgDispId );
    HRESULT virtual __stdcall Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn, EXCEPINFO * ex, UINT * i);
	HRESULT virtual __stdcall Exit();
	HRESULT virtual __stdcall Type( BSTR typeName, INetType** type );
	HRESULT virtual __stdcall Connect(IDispatch* ptr, BSTR eventName, VARIANT target);
	HRESULT virtual __stdcall Import(BSTR clazzName, INetAssembly** a);

};


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
												>  > >,
	public mol::exports< 
					NetApp, 
					NetAssembly, 
					mol::ole::ComCreatePolicy<
									NetApp,
									mol::ole::AggregationPolicyNonAggregable<
													NetAssembly,
													mol::com_obj<NetAssembly> 
												>  > >	
{
public:

	NetApp();

	mol::punk<_Net> dotnet;
};

#endif