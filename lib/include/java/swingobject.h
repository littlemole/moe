#ifndef _MOL_SWINGOBJECT_DEF_DEFINE_GUARD_
#define _MOL_SWINGOBJECT_DEF_DEFINE_GUARD_

#include "ole/Factory.h"
#include "java/java.h"
#include "java/jglue.h"

EXTERN_C const  CLSID CLSID_SwingObject;

namespace mol {
namespace java {

////////////////////////////////////////////////////////////////////////
class SwingObject : 
	public mol::com_registerobj<SwingObject,CLSID_SwingObject,CLSCTX_LOCAL_SERVER,mol::PROGRAMMABLE|mol::MULTITHREADED>,//,REGCLS_SINGLEUSE>,
	public ISwingObject, 
	public mol::SupportsErrorInfo<&IID_ISwingObject,&IID_IDispatch>,
	public mol::interfaces<
				SwingObject,
				mol::implements< 
					IDispatch,
					ISwingObject,
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
	HRESULT virtual __stdcall Initialize(long* ptr);
	HRESULT virtual __stdcall RawPtr(long** ptr);

private:

	jobject theSwingObject_;
};

} // end namespace java
} // end namespace mol

#endif
