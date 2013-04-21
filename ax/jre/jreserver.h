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
#include "java/javaclass.h"
#include "java/javaobject.h"
#include "java/swingobject.h"
#include "java/jre.h"
#include "jre_h.h"

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

class JREServer : 
	public mol::com_registerobj<JREServer,CLSID_Java,CLSCTX_LOCAL_SERVER,mol::PROGRAMMABLE|mol::MULTITHREADED>,
	public mol::Dispatch<IJVM>,
	public mol::SupportsErrorInfo<&IID_IJVM,&IID_IDispatch>,
	public mol::interfaces< JREServer,
			mol::implements<
				IDispatch,
				IJVM,				
				ISupportErrorInfo
				> 
			>
{
public:

	JREServer();

	virtual void dispose();

    virtual HRESULT __stdcall put_Classpath( BSTR cp);    
    virtual HRESULT __stdcall get_Classpath( BSTR *cp);  
    virtual HRESULT __stdcall put_Libpath( BSTR lp);
	virtual HRESULT __stdcall get_Libpath( BSTR *lp); 
	virtual HRESULT __stdcall LoadClass( BSTR clazzName, IJavaClass** clazz);
	virtual HRESULT __stdcall get_Runtime( IDispatch** ns );

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

	HRESULT virtual __stdcall Exit();

	HRESULT virtual __stdcall Cast( IJavaObject* javaObject, BSTR clazz, IJavaObject** );
};


////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

class JREApp : 

	public mol::local_server<mol::win::Loop>,

	public mol::exports< JREApp, JREServer>,

	public mol::exports< 
					JREApp, 
					mol::java::JavaClass, 
					mol::ole::ComCreatePolicy<
									JREApp,
									mol::ole::AggregationPolicyNonAggregable<
													mol::java::JavaClass,
													mol::com_obj<mol::java::JavaClass> 
												> > >,
	public mol::exports< 
					JREApp, 
					mol::java::JavaObject, 
					mol::ole::ComCreatePolicy<
									JREApp,
									mol::ole::AggregationPolicyNonAggregable<
													mol::java::JavaObject,
													mol::com_obj<mol::java::JavaObject> 
												>  > >,
	public mol::exports< 
					JREApp, 
					mol::java::SwingObject, 
					mol::ole::ComCreatePolicy<
									JREApp,
									mol::ole::AggregationPolicyNonAggregable<
													mol::java::SwingObject,
													mol::com_obj<mol::java::SwingObject> 
												>  > >	
{
public:

	JREApp ()
	{}

	~JREApp()
	{}

};


#endif