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


#endif