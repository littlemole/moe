#ifndef _MOL_JAVACLASS_DEF_DEFINE_GUARD_
#define _MOL_JAVACLASS_DEF_DEFINE_GUARD_

#include "ole/Factory.h"
#include "java/java.h"
#include "java/jglue.h"

#include <DispEx.h>

EXTERN_C const  CLSID CLSID_JavaClass;

namespace mol {
namespace java {

////////////////////////////////////////////////////////////////////////
class JavaClass : 
	public mol::com_registerobj<JavaClass,CLSID_JavaClass,CLSCTX_LOCAL_SERVER,mol::PROGRAMMABLE|mol::MULTITHREADED>,
	public IJavaClass, 
	public IDispatchEx,
	public mol::SupportsErrorInfo<&IID_IJavaClass,&IID_IDispatch>,
	public mol::interfaces<
				JavaClass,
				mol::implements< 
					mol::interface_ex<IDispatch,IJavaClass>,
					IDispatchEx,
					IJavaClass,
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
	HRESULT virtual __stdcall Initialize(long* ptr);
	HRESULT virtual __stdcall RawPtr(long** ptr);

    HRESULT virtual __stdcall GetDispID( BSTR bstrName, DWORD grfdex, DISPID *pid);
    HRESULT virtual __stdcall InvokeEx( DISPID id,LCID lcid, WORD wFlags, DISPPARAMS *pdp, VARIANT *pvarRes, EXCEPINFO *pei, IServiceProvider *pspCaller);
    HRESULT virtual __stdcall DeleteMemberByName( BSTR bstrName, DWORD grfdex);        
    HRESULT virtual __stdcall DeleteMemberByDispID( DISPID id);    
    HRESULT virtual __stdcall GetMemberProperties( DISPID id, DWORD grfdexFetch, DWORD *pgrfdex);       
    HRESULT virtual __stdcall GetMemberName( DISPID id, BSTR *pbstrName);       
    HRESULT virtual __stdcall GetNextDispID( DWORD grfdex, DISPID id, DISPID *pid);       
    HRESULT virtual __stdcall GetNameSpaceParent( IUnknown **ppunk);

private:
	jclass theJavaClass_;
};

} // end namespace java
} // end namespace mol


#endif