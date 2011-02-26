#ifndef _MOL_JAVACLASS_DEF_DEFINE_GUARD_
#define _MOL_JAVACLASS_DEF_DEFINE_GUARD_

#include "ole/ole.h"
#include "ole/com.h"
#include "ole/obj.h"
#include "ole/Bstr.h"
#include "ole/typeinfo.h"
#include "ole/Factory.h"
#include "ole/Factorypolicy.h"
#include "ole/aut.h"
#include "ole/cp.h"
#include "win/path.h"
#include "win/file.h"
#include "util/istr.h"
#include "thread/thread.h"
#include "thread/threadqueue.h"

#include <list>
#include <map>
#include <set>
#include <vector>
#include <cstring>

#include "java/java.h"
#include "java/jglue.h"
#include "ole/com.h"

EXTERN_C const  CLSID CLSID_JavaClass;

////////////////////////////////////////////////////////////////////////
class JavaClass : 
	public mol::com_registerobj<JavaClass,CLSID_JavaClass,CLSCTX_LOCAL_SERVER,mol::PROGRAMMABLE|mol::MULTITHREADED>,
	public IJavaClass, 
	public mol::SupportsErrorInfo<&IID_IJavaClass,&IID_IDispatch>,
	public mol::interfaces<
				JavaClass,
				mol::implements< 
					IDispatch,
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

private:
	jclass theJavaClass_;
};


#endif