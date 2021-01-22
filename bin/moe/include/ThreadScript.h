#ifndef MOL_MOE_DEFINE_GUARD_THREAD_SCRIPT_DEF_DUARD_DEFINE_
#define MOL_MOE_DEFINE_GUARD_THREAD_SCRIPT_DEF_DUARD_DEFINE_


#include "commons.h"
#include <ActivScp.h>
#include <ActivDbg.h>

class Editor;

class ScriptDebugger : 
	public IActiveScriptSite,
	public IActiveScriptSiteWindow,
	public IActiveScriptSiteDebug,
	public IApplicationDebugger,
	public IApplicationDebuggerUI,
	public IDebugSessionProvider,
	public IDebugExpressionCallBack,
	public mol::interfaces< ScriptDebugger, 
				mol::implements< IActiveScriptSite, 
							IActiveScriptSiteWindow,
							IActiveScriptSiteDebug,
							IApplicationDebugger,
							IApplicationDebuggerUI,
							IDebugExpressionCallBack,
							IDebugSessionProvider
							> >
{
public:
	
	// IDebugExpressionCallBack
	HRESULT virtual __stdcall onComplete();

	// IActiveScriptSiteDebug Implementation
	virtual HRESULT  STDMETHODCALLTYPE GetDocumentContextFromPosition(
#ifdef _WIN64
		DWORDLONG dwSourceContext,
#else
		DWORD dwSourceContext,
#endif
		ULONG uCharacterOffset, ULONG uNumChars, IDebugDocumentContext **ppsc);

	virtual HRESULT  __stdcall GetApplication(IDebugApplication **ppda);
	virtual HRESULT  __stdcall GetRootApplicationNode(IDebugApplicationNode **ppdanRoot);
	virtual HRESULT  __stdcall OnScriptErrorDebug(IActiveScriptErrorDebug *pErrorDebug, BOOL*pfEnterDebugger, BOOL *pfCallOnScriptErrorWhenContinuing);


	//IActiveScriptSite
	virtual HRESULT  __stdcall GetLCID(LCID *plcid);
	virtual HRESULT  __stdcall GetItemInfo(LPCOLESTR pstrName, DWORD dwReturnMask, IUnknown **ppiunkItem, ITypeInfo **ppti);
	virtual HRESULT  __stdcall GetDocVersionString(BSTR *pbstrVersion);
	virtual HRESULT  __stdcall OnScriptTerminate(const VARIANT *pvarResult, const EXCEPINFO *pexcepinfo);
	virtual HRESULT  __stdcall OnStateChange(SCRIPTSTATE ssScriptState);
	virtual HRESULT  __stdcall OnScriptError(IActiveScriptError *pscripterror);
	virtual HRESULT  __stdcall OnEnterScript(void);
	virtual HRESULT  __stdcall OnLeaveScript(void);

	//IActiveScriptSiteWindow
	virtual HRESULT  __stdcall GetWindow(HWND *phwnd);
	virtual HRESULT  __stdcall EnableModeless(BOOL fEnable);

	//IApplicationDebugger
	virtual HRESULT  __stdcall  QueryAlive();
	virtual HRESULT  __stdcall  CreateInstanceAtDebugger(REFCLSID, IUnknown *, DWORD, REFIID, IUnknown **);
	virtual HRESULT  __stdcall  onDebugOutput(LPCOLESTR pstr);
	virtual HRESULT  __stdcall  onHandleBreakPoint(IRemoteDebugApplicationThread *, BREAKREASON, IActiveScriptErrorDebug *);
	virtual HRESULT  __stdcall  onClose();
	virtual HRESULT  __stdcall  onDebuggerEvent(REFIID, IUnknown *);

	virtual HRESULT  __stdcall  BringDocumentToTop(IDebugDocumentText *);
	virtual HRESULT  __stdcall  BringDocumentContextToTop(IDebugDocumentContext *);

	virtual HRESULT  __stdcall StartDebugSession( IRemoteDebugApplication* pApp)
	{
		IApplicationDebugger* ad = (IApplicationDebugger*)this;
		return pApp->ConnectDebugger(ad);
	}

	mol::events::Event<int,std::wstring> OnScriptThread;
	mol::events::Event<> OnScriptThreadDone;
	mol::events::Event<std::wstring> OnExpressionEvaluated;

	typedef mol::com_instance<ScriptDebugger> Instance;

	virtual void dispose()  
	{
		ODBGS("TRHEADASCRIPT dead x:");
	};

	static Instance* CreateInstance( HWND owner, const std::wstring& script,  const std::wstring& filename );

	void execute( int flag = SCRIPTTEXT_ISVISIBLE );	
	void cause_break();
	void resume(BREAKRESUMEACTION ba = BREAKRESUMEACTION_CONTINUE);
	void update_breakpoints(std::set<int> br);
	void eval_expression(const std::wstring& expr);

	bool suspended() { return remote_.interface_ != 0; }

	HRESULT frames(IEnumDebugStackFrames** frames);

	// add a named object
	virtual HRESULT addNamedObject( IUnknown* punk, const std::wstring& obj, int state = SCRIPTITEM_ISVISIBLE| SCRIPTITEM_ISSOURCE );
	virtual HRESULT removeNamedObject( const std::wstring& obj );



	mol::punk<IMoeImport>				import;

	void quit();
	void wait();
	bool done()
	{
		return quit_;
	}

	mol::punk<IActiveScript>			activeScript_;

protected:

	ScriptDebugger();
	virtual ~ScriptDebugger();

	// init and cleanup
	void init(const std::wstring& engine);
	void execute_thread();
	void execute_callback();

	// helper
	HRESULT getScriptEngine(const std::wstring& engine, IActiveScript **ppas);

	bool								quit_ = true;
	bool								break_ = false;
	bool								stepping_;
	bool								chakra_;
	std::set<int>						breakpoints_;
	typedef std::pair<DWORD,DWORD>      ObjectMapItem;
 	std::map<std::wstring,ObjectMapItem>	objectMap_;

	mol::punk<IProcessDebugManager>		pdm_;
	mol::punk<IDebugApplication>		debugApp_;
	mol::punk<IActiveScriptParse>		asp_;
	mol::punk<IDebugExpression>			exp_;
	mol::punk<IDebugDocumentHelper>     debugHelper_;

	mol::punk<IRemoteDebugApplicationThread> remote_;

	DWORD_PTR						    debugCookie_;
	DWORD								dwAppCookie_;
	DWORD								offset_;
	DWORD								scriptFlags_;

	std::wstring							filename_;
	std::wstring							script_;
	std::wstring							engine_;
	mol::variant						varResult_;
    EXCEPINFO							ei_; 

	HWND								owner_;

};

class MoeDebugImport : 
 	public mol::Dispatch<IMoeImport>,
 	public mol::interfaces< MoeDebugImport, 
 				mol::implements< IDispatch, IMoeImport> >
{
public:
 	typedef mol::com_obj<MoeDebugImport> Instance;
 
 	void dispose();
 
 	static Instance* CreateInstance(ScriptDebugger::Instance* host);
 
 	virtual HRESULT __stdcall  Import(BSTR filename);
  	virtual HRESULT __stdcall  Sleep(long ms);
 	virtual HRESULT __stdcall  Wait(VARIANT_BOOL* vb);
 	virtual HRESULT __stdcall  Quit();
	virtual HRESULT __stdcall  get_Dispatch(IDispatch** disp);
	virtual HRESULT __stdcall  Callback(BSTR name,IDispatch** disp);
	virtual HRESULT __stdcall  setTimeout( VARIANT f, VARIANT d, VARIANT* retval);
	virtual HRESULT __stdcall  clearTimeout( VARIANT t);

private:
	ScriptDebugger::Instance* host_;
};


#endif
