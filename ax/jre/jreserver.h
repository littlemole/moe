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

//#include <msxml2.h>
#include <list>
#include <map>
#include <set>
#include <vector>

//#include <mshtml.h>
//#include "ScintillAx_h.h"
//#include "shellCtrl_h.h"
//#include "moe_h.h"

#include "jre_h.h"
#include "jglue.h"


////////////////////////////////////////////////////////////////////////

class JREServer : 
	public mol::com_creatable<JREServer,CLSID_JRE,CLSCTX_ALL,mol::PROGRAMMABLE|mol::APARTMENT,REGCLS_SINGLEUSE>,
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
    virtual HRESULT __stdcall Execute( BSTR classfile);
    virtual HRESULT __stdcall Show( BSTR classfile);
	virtual HRESULT __stdcall Extension( BSTR classfile, IDispatch* moe, IDispatch* frame);

};

class JREThreadAction
{
public:

	virtual void operator()() {};

};

class JREThreadExecAction : public JREThreadAction
{
public:

	JREThreadExecAction( const std::string& p );
	~JREThreadExecAction();

	virtual void operator()();

	std::string path_;

};

class JREThreadShowAction : public JREThreadAction
{
public:

	JREThreadShowAction( const std::string& p );
	~JREThreadShowAction();

	virtual void operator()();

	std::string path_;
};


class JREThreadExtensionAction : public JREThreadAction
{
public:

	JREThreadExtensionAction( const std::string& p, IDispatch* m, IDispatch* f );
	~JREThreadExtensionAction();

	virtual void operator()();

	std::string path_;

	DWORD moeCookie;
	DWORD frameCookie;
};


class JREThreadStartPolicy 
{
public:
	void operator()();
};

class JREThreadShutdownPolicy 
{
public:
	void operator()();
};


class JREApp : 
	public mol::local_server<mol::win::Loop>,
	public mol::exports< JREApp, JREServer >
{
public:

	JREApp (HINSTANCE hinst)
	:  local_server<mol::win::Loop>(hinst)
	{
		//activeObj_ = 0;
		
	}

	~JREApp()
	{

	}

	JRE& jre()
	{
		return jre_;
	}

	mol::ThreadQueue<
			JREThreadAction,
			true,
			JREThreadStartPolicy,
			JREThreadShutdownPolicy> 
		queue;

private:
	// windows libraries
	mol::ole_init      oi;

	JRE jre_;

};


#endif