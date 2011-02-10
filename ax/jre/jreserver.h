#ifndef _MOL_JSERVER_DEF_DEFINE_GUARD_
#define _MOL_JSERVER_DEF_DEFINE_GUARD_

#include "ole/ole.h"
#include "ole/com.h"
#include "ole/obj.h"
#include "ole/Bstr.h"
#include "ole/typeinfo.h"
#include "ole/Factory.h"
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

#include "jre_h.h"
#include "jglue.h"


////////////////////////////////////////////////////////////////////////

class JREServer : 
	public mol::com_registerobj<JREServer,CLSID_Java,CLSCTX_ALL,mol::PROGRAMMABLE|mol::APARTMENT>,//,REGCLS_SINGLEUSE>,
	public mol::Dispatch<IJVM>,
	public mol::interfaces< JREServer,
			mol::implements<
				IJVM,
				IDispatch > >
{
public:

	JREServer();

	virtual void dispose();

    virtual HRESULT __stdcall put_Classpath( BSTR cp);    
    virtual HRESULT __stdcall get_Classpath( BSTR *cp);  
    virtual HRESULT __stdcall put_Libpath( BSTR lp);
	virtual HRESULT __stdcall get_Libpath( BSTR *lp); 
	virtual HRESULT __stdcall LoadClass( BSTR clazzName, IJavaClass** clazz);

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

	
};




class JavaClass : 
	public IJavaClass, 
	public mol::interfaces<
				JavaClass,
				mol::implements< IDispatch, IJavaClass> >
{
public:

	typedef mol::debug_com_instance<JavaClass> Instance;
	static Instance* instance( jclass clazz ) 
	{
		Instance* theInstance = new Instance();
		theInstance->theJavaClass_ = clazz;
		return theInstance;
	}

	void virtual dispose()
	{
	}
	
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

    HRESULT virtual __stdcall Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn, EXCEPINFO * ex, UINT * i) ;


	jclass getClass()
	{
		return theJavaClass_;
	}

private:
	std::map<size_t,std::string> idsOfNames_;
	std::map<std::string,size_t> namesOfIds_;
	jclass theJavaClass_;
};



class JavaObject : 
	public IJavaObject, 
	public mol::interfaces<
				JavaObject,
				mol::implements< IDispatch, IJavaObject> >
{
public:

	typedef mol::com_instance<JavaObject> Instance;
	static Instance* instance( jobject obj ) 
	{
		Instance* theInstance = new Instance();
		theInstance->theJavaObject_ = obj;
		return theInstance;
	}

	void virtual dispose()
	{
	}
	
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

	jobject getObject()
	{
		return theJavaObject_;
	}
private:
	std::map<size_t,std::string> idsOfNames_;
	std::map<std::string,size_t> namesOfIds_;
	jobject theJavaObject_;
};

class JREApp : 
	public mol::local_server<mol::win::Loop>,
	public mol::exports< JREApp, JREServer >
{
public:

	JREApp ()
	{}

	~JREApp()
	{}

	JRE& jre()
	{
		return jre_;
	}


private:

	// windows libraries
	mol::ole_init      oi;

	JRE jre_;

};


#endif