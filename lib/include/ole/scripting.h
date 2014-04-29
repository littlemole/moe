#ifndef MOL_DEF_SCRIPTING_DEF_GUARD_DEFINE_
#define MOL_DEF_SCRIPTING_DEF_GUARD_DEFINE_

#pragma once
#include <map>
#include "util/uni.h"
#include "ole/aut.h"
#include "ole/punk.h"
#include <ActivScp.h>
#include <activDbg.h>

namespace mol {
namespace ole {

/////////////////////////////////////////////////////////////////////////////////////////////

class ActiveScript 
{
public:
	virtual HRESULT init(const std::wstring& engine);
	virtual HRESULT setState(SCRIPTSTATE state);
	virtual HRESULT setHost(IActiveScriptSite* host);
	virtual HRESULT close();

	virtual HRESULT addNamedObject(const std::wstring& obj, int state = SCRIPTITEM_ISVISIBLE);
	virtual HRESULT runScript(const std::wstring& script, int flag = SCRIPTTEXT_ISEXPRESSION|SCRIPTTEXT_ISVISIBLE);
	virtual HRESULT getScriptDispatch( const std::wstring& script, IDispatch **ppdisp);
	virtual HRESULT addScriptlet( std::wstring& name, const std::wstring& handler, const std::wstring& obj, const std::wstring& subobj, const std::wstring& eventname );

	variant& result();
	EXCEPINFO& errorInfo();

	punk<IActiveScript>					activeScript;


protected:
	std::wstring							engine_;
	punk<IActiveScriptParse>			asp_;

	HRESULT getScriptEngine(const std::wstring& engine, IActiveScript **ppas);

	variant varResult_;
    EXCEPINFO ei_; 

};

} // end namespace ole

/////////////////////////////////////////////////////////////////////////////////////////////

class ScriptHost : 
	public IActiveScriptSite,
	public IActiveScriptSiteWindow,
	public IActiveScriptSiteDebug,
	public interfaces< ScriptHost, 
				implements< IActiveScriptSite, 
							IActiveScriptSiteWindow,
							IActiveScriptSiteDebug> >
{
public:
	
	ScriptHost();
	virtual ~ScriptHost();

	virtual void dispose()  {};

	// init and cleanup
	virtual HRESULT init(const std::wstring& engine);
	virtual HRESULT close();
	virtual HRESULT setState(SCRIPTSTATE state);

	// parse a script
	virtual HRESULT runScript(const std::wstring& script, int flag = SCRIPTTEXT_ISVISIBLE);//SCRIPTTEXT_ISEXPRESSION
	// debug a script
	virtual HRESULT debugScript(const std::wstring& script, int flag = SCRIPTTEXT_ISVISIBLE);//SCRIPTTEXT_ISEXPRESSION

	// add a named object
	virtual HRESULT addNamedObject( IUnknown* punk, const std::wstring& obj, int state = SCRIPTITEM_ISVISIBLE| SCRIPTITEM_ISSOURCE );
	virtual HRESULT removeNamedObject( const std::wstring& obj );
	// add event handler
	virtual HRESULT addScriptlet( std::wstring& name, 
						  const std::wstring& handler,
						  const std::wstring& obj,
						  const std::wstring& subobj,
						  const std::wstring& eventname );


	// result and error info accessors
	variant& result();
	EXCEPINFO& errorInfo();

	//execute parsed scripts
	virtual HRESULT exec();

	// find dispatch pointer for parsed script
	virtual HRESULT getScript( const std::wstring& script,IDispatch **ppdisp);

	// call a script function by name
	variant call(const std::wstring& func );

	template<class V>
	variant call(const std::wstring& func, V& v )
	{
		variant ret;

		punk<IDispatch> disp;
		HRESULT hr = getScript("",&disp);
		if ( (hr == S_OK) && disp )
		{	
			std::wstring ws = mol::ansi2wstring(func);
			OLECHAR* c = (OLECHAR*)ws.c_str();
			DISPID dispid;
			hr = disp->GetIDsOfNames(IID_NULL, &(c), 1, 0, &dispid);
			if ( hr == S_OK )
			{
				return mol::disp_call( disp,dispid, v );
			}
		}
		return ret;
	}

	template<class V1, class V2>
	variant call(const std::wstring& func, V1& v1, V2& v2 )
	{
		variant ret;

		punk<IDispatch> disp;
		HRESULT hr = getScript("",&disp);
		if ( (hr == S_OK) && disp )
		{	
			std::wstring ws = mol::ansi2wstring(func);
			OLECHAR* c = (OLECHAR*)ws.c_str();
			DISPID dispid;
			hr = disp->GetIDsOfNames(IID_NULL, &(c), 1, 0, &dispid);
			if ( hr == S_OK )
			{
				return mol::disp_call( disp,dispid, v1, v2 );
			}
		}
		return ret;
	}

	template<class V1, class V2, class V3>
	variant call(const std::wstring& func, V1& v1, V2& v2, V3& v3 )
	{
		variant ret;

		punk<IDispatch> disp;
		HRESULT hr = getScript("",&disp);
		if ( (hr == S_OK) && disp )
		{	
			std::wstring ws = mol::ansi2wstring(func);
			OLECHAR* c = (OLECHAR*)ws.c_str();
			DISPID dispid;
			hr = disp->GetIDsOfNames(IID_NULL, &(c), 1, 0, &dispid);
			if ( hr == S_OK )
			{
				return mol::disp_call( disp,dispid, v1, v2, v3 );
			}
		}
		return ret;
	}


	template<class V1, class V2, class V3, class V4>
	variant call(const std::wstring& func, V1& v1, V2& v2, V3& v3, V4& v4 )
	{
		variant ret;

		punk<IDispatch> disp;
		HRESULT hr = getScript("",&disp);
		if ( (hr == S_OK) && disp )
		{	
			std::wstring ws = mol::ansi2wstring(func);
			OLECHAR* c = (OLECHAR*)ws.c_str();
			DISPID dispid;
			hr = disp->GetIDsOfNames(IID_NULL, &(c), 1, 0, &dispid);
			if ( hr == S_OK )
			{
				return mol::dispInvoke( disp,dispid, v1, v2, v3, 4 );
			}
		}
		return ret;
	}

	// IActiveScriptSiteDebug Implementation
	virtual HRESULT  __stdcall GetDocumentContextFromPosition(
#ifdef _WIN64
								  DWORDLONG dwSourceContext,	
#else
								 DWORD dwSourceContext,	
#endif
		ULONG uCharacterOffset,ULONG uNumChars,IDebugDocumentContext **ppsc);

	HRESULT virtual __stdcall GetApplication(IDebugApplication **ppda);
	HRESULT virtual __stdcall GetRootApplicationNode(IDebugApplicationNode **ppdanRoot);
	HRESULT virtual __stdcall OnScriptErrorDebug(IActiveScriptErrorDebug *pErrorDebug,BOOL*pfEnterDebugger, BOOL *pfCallOnScriptErrorWhenContinuing);


	//IActiveScriptSite
	virtual HRESULT  __stdcall GetLCID( LCID *plcid);
    virtual HRESULT  __stdcall GetItemInfo( LPCOLESTR pstrName,DWORD dwReturnMask,IUnknown **ppiunkItem,ITypeInfo **ppti);
	virtual HRESULT  __stdcall GetDocVersionString( BSTR *pbstrVersion);
    virtual HRESULT  __stdcall OnScriptTerminate( const VARIANT *pvarResult,const EXCEPINFO *pexcepinfo);
    virtual HRESULT  __stdcall OnStateChange( SCRIPTSTATE ssScriptState);
    virtual HRESULT  __stdcall OnScriptError( IActiveScriptError *pscripterror);
    virtual HRESULT  __stdcall OnEnterScript( void);
    virtual HRESULT  __stdcall OnLeaveScript( void);

	//IActiveScriptSiteWindow
	virtual HRESULT  __stdcall GetWindow(HWND *phwnd );
	virtual HRESULT  __stdcall EnableModeless(	BOOL fEnable );

protected:
	std::map<std::wstring,IUnknown*>		objectMap_;
	mol::ole::ActiveScript				activeScript_;
	mol::punk<IProcessDebugManager>		pdm_;
	mol::punk<IDebugApplication>		debugApp_;
	mol::punk<IDebugDocumentHelper>     debugDocHelper_;
	DWORD								dwAppCookie_;
	bool								debug_;
};

std::wstring engineFromExtension(const std::wstring& ext);


} // end namespace mole

#endif