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

class ThreadScript : 
	public IActiveScriptSite,
	public IActiveScriptSiteWindow,
	public IActiveScriptSiteDebug,
	public IApplicationDebugger,
	public IApplicationDebuggerUI,
	public IDebugDocumentTextAuthor,
	public IDebugDocumentProvider,
	public IDebugDocumentContext,
	public mol::interfaces< ThreadScript, 
				mol::implements< IActiveScriptSite, 
							IActiveScriptSiteWindow,
							IActiveScriptSiteDebug,
							IApplicationDebugger,
							IApplicationDebuggerUI,
							mol::interface_ex<IDebugDocument,IDebugDocumentTextAuthor>,
							mol::interface_ex<IDebugDocumentInfo,IDebugDocumentTextAuthor>,
							mol::interface_ex<IDebugDocumentText,IDebugDocumentTextAuthor>,
							IDebugDocumentTextAuthor,
							IDebugDocumentProvider,
							IDebugDocumentContext
							> >
{
public:
	
	mol::events::Event<int,IRemoteDebugApplicationThread*,IActiveScriptError*> OnScriptThread;
	mol::events::Event<> OnScriptThreadDone;

	typedef mol::com_instance<ThreadScript> ScriptInstance;
	//typedef mol::debug_com_instance<ThreadScript> ScriptInstance;

	virtual void dispose()  {};

	static ThreadScript* CreateInstance( HWND owner, const mol::string& script,  const mol::string& filename );

	void execute( int flag = SCRIPTTEXT_ISVISIBLE );	
	void cause_break();
	void update_breakpoints(std::set<int> br);


	// add a named object
	virtual HRESULT addNamedObject( IUnknown* punk, const mol::string& obj, int state = SCRIPTITEM_ISVISIBLE| SCRIPTITEM_ISSOURCE );
	virtual HRESULT removeNamedObject( const mol::string& obj );

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


	virtual HRESULT  __stdcall  ThreadScript::GetDocument(IDebugDocument **pObj);
	virtual HRESULT  __stdcall  ThreadScript::EnumCodeContexts(IEnumDebugCodeContexts **pObj);



protected:

	ThreadScript();
	virtual ~ThreadScript();

	// init and cleanup
	void init(const mol::string& engine);
	void execute_thread();
	void execute_callback();
	void close();

	std::set<int>						breakpoints_;
	std::map<mol::string,DWORD>			objectMap_;

	mol::punk<IProcessDebugManager>		pdm_;
	mol::punk<IDebugApplication>		debugApp_;
	mol::punk<IActiveScript>			activeScript_;
	mol::punk<IActiveScriptParse>		asp_;

	DWORD								dwAppCookie_;
	DWORD								offset_;
	DWORD								scriptFlags_;

	mol::string							filename_;
	mol::string							script_;
	mol::string							engine_;
	mol::variant						varResult_;
    EXCEPINFO							ei_; 

	HWND								owner_;

	HRESULT getScriptEngine(const mol::string& engine, IActiveScript **ppas);
};




#endif