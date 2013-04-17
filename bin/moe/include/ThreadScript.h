#ifndef MOL_MOE_DEFINE_GUARD_THREAD_SCRIPT_DEF_DUARD_DEFINE_
#define MOL_MOE_DEFINE_GUARD_THREAD_SCRIPT_DEF_DUARD_DEFINE_

#include <map>
#include "util/uni.h"
#include "thread/events.h"
#include "ole/aut.h"
#include "ole/punk.h"
#include <ActivScp.h>
#include <ActivDbg.h>

class Editor;

class ScriptDebugger : 
	public IActiveScriptSite,
	public IActiveScriptSiteWindow,
	public IActiveScriptSiteDebug,
	public IApplicationDebugger,
	public IApplicationDebuggerUI,
	public IDebugDocumentTextAuthor,
	public IDebugDocumentProvider,
	public IDebugDocumentContext,
	public IDebugExpressionCallBack,
	public mol::interfaces< ScriptDebugger, 
				mol::implements< IActiveScriptSite, 
							IActiveScriptSiteWindow,
							IActiveScriptSiteDebug,
							IApplicationDebugger,
							IApplicationDebuggerUI,
							IDebugExpressionCallBack,
							mol::interface_ex<IDebugDocument,IDebugDocumentTextAuthor>,
							mol::interface_ex<IDebugDocumentInfo,IDebugDocumentTextAuthor>,
							mol::interface_ex<IDebugDocumentText,IDebugDocumentTextAuthor>,
							IDebugDocumentTextAuthor,
							IDebugDocumentProvider,
							IDebugDocumentContext
							> >
{
public:
	
	mol::events::Event<int,mol::string> OnScriptThread;
	mol::events::Event<> OnScriptThreadDone;
	mol::events::Event<mol::string> OnExpressionEvaluated;

	typedef mol::com_instance<ScriptDebugger> Instance;
	//typedef mol::debug_com_instance<ThreadScript> ScriptInstance;

	virtual void dispose()  
	{
		ODBGS("TRHEADASCRIPT dead x:");
	};

	static Instance* CreateInstance( HWND owner, const mol::string& script,  const mol::string& filename );

	void execute( int flag = SCRIPTTEXT_ISVISIBLE );	
	void cause_break();
	void resume(BREAKRESUMEACTION ba = BREAKRESUMEACTION_CONTINUE);
	void update_breakpoints(std::set<int> br);
	void eval_expression(const mol::string& expr);

	bool suspended() { return remote_.interface_ != 0; }

	HRESULT frames(IEnumDebugStackFrames** frames);

	// add a named object
	virtual HRESULT addNamedObject( IUnknown* punk, const mol::string& obj, int state = SCRIPTITEM_ISVISIBLE| SCRIPTITEM_ISSOURCE );
	virtual HRESULT removeNamedObject( const mol::string& obj );

	// IDebugExpressionCallBack
	HRESULT virtual __stdcall onComplete();

	// IActiveScriptSiteDebug Implementation
	virtual HRESULT  STDMETHODCALLTYPE GetDocumentContextFromPosition(
#ifdef _WIN64
								  DWORDLONG dwSourceContext,	
#else
								 DWORD dwSourceContext,	
#endif
		ULONG uCharacterOffset,ULONG uNumChars,IDebugDocumentContext **ppsc);

	virtual HRESULT  __stdcall GetApplication(IDebugApplication **ppda);
	virtual HRESULT  __stdcall GetRootApplicationNode(IDebugApplicationNode **ppdanRoot);
	virtual HRESULT  __stdcall OnScriptErrorDebug(IActiveScriptErrorDebug *pErrorDebug,BOOL*pfEnterDebugger, BOOL *pfCallOnScriptErrorWhenContinuing);


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

	//IApplicationDebugger
	virtual HRESULT  __stdcall  QueryAlive();
	virtual HRESULT  __stdcall  CreateInstanceAtDebugger( REFCLSID, IUnknown *, DWORD, REFIID, IUnknown **);
	virtual HRESULT  __stdcall  onDebugOutput(LPCOLESTR pstr);
	virtual HRESULT  __stdcall  onHandleBreakPoint(IRemoteDebugApplicationThread *, BREAKREASON, IActiveScriptErrorDebug *);
	virtual HRESULT  __stdcall  onClose();
	virtual HRESULT  __stdcall  onDebuggerEvent(REFIID, IUnknown *);

	virtual HRESULT  __stdcall  BringDocumentToTop(IDebugDocumentText *);
	virtual HRESULT  __stdcall  BringDocumentContextToTop( IDebugDocumentContext *);


	virtual HRESULT  __stdcall  GetName( DOCUMENTNAMETYPE, BSTR *);
	virtual HRESULT  __stdcall  GetDocumentClassId( CLSID *);
	virtual HRESULT  __stdcall  GetDocumentAttributes( TEXT_DOC_ATTR *);
	virtual HRESULT  __stdcall  GetSize( ULONG *, ULONG *);
	virtual HRESULT  __stdcall  GetPositionOfLine( ULONG, ULONG *);
	virtual HRESULT  __stdcall  GetLineOfPosition( ULONG, ULONG *, ULONG *);
	virtual HRESULT  __stdcall  GetText( ULONG, WCHAR *, SOURCE_TEXT_ATTR *, ULONG *, ULONG);
	virtual HRESULT  __stdcall  GetPositionOfContext( IDebugDocumentContext *, ULONG *, ULONG *);
	virtual HRESULT  __stdcall  GetContextOfPosition( ULONG, ULONG, IDebugDocumentContext **);
	virtual HRESULT  __stdcall  InsertText( ULONG, ULONG, OLECHAR *);
	virtual HRESULT  __stdcall  RemoveText( ULONG, ULONG);
	virtual HRESULT  __stdcall  ReplaceText( ULONG, ULONG, OLECHAR *);


	virtual HRESULT  __stdcall  GetDocument(IDebugDocument **pObj);
	virtual HRESULT  __stdcall  EnumCodeContexts(IEnumDebugCodeContexts **pObj);

	mol::punk<IMoeImport>				import;

protected:

	ScriptDebugger();
	virtual ~ScriptDebugger();

	// init and cleanup
	void init(const mol::string& engine);
	void execute_thread();
	void execute_callback();

	// helper
	HRESULT getScriptEngine(const mol::string& engine, IActiveScript **ppas);


	std::set<int>						breakpoints_;
	typedef std::pair<DWORD,DWORD>      ObjectMapItem;
 	std::map<mol::string,ObjectMapItem>	objectMap_;

	mol::punk<IProcessDebugManager>		pdm_;
	mol::punk<IDebugApplication>		debugApp_;
	mol::punk<IActiveScript>			activeScript_;
	mol::punk<IActiveScriptParse>		asp_;
	mol::punk<IDebugExpression>			exp_;

	mol::punk<IRemoteDebugApplicationThread> remote_;

	DWORD								dwAppCookie_;
	DWORD								offset_;
	DWORD								scriptFlags_;

	mol::string							filename_;
	mol::string							script_;
	mol::string							engine_;
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
 
 	static Instance* CreateInstance(IActiveScript* host);
 
 	virtual HRESULT __stdcall  Import(BSTR filename);
  	virtual HRESULT __stdcall  Sleep(long ms);
 	virtual HRESULT __stdcall  Wait(long ms,VARIANT_BOOL* vb);
 	virtual HRESULT __stdcall  Quit();

private:
	IActiveScript* host_;
	HANDLE stop_;
};


#endif