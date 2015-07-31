#include "StdAfx.h"
#include "ThreadScript.h"
#include "xmlui.h"
#include "widgets.h"


std::wstring engineFromPath(const std::string& path)
{
	return mol::towstring(mol::engineFromExtension(mol::Path::ext(mol::towstring(path))));
}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

struct ThreadedTimeout
{
	ThreadedTimeout(IDispatch* f, long t, bool i = false)
		: fun(f), timeout(t), interval(i)
	{}

	mol::punk<IDispatch> fun;
	long timeout;
	bool interval;
};

class ThreadedTimeouts
{
public:
	ThreadedTimeouts() : count_(0) {}
	~ThreadedTimeouts() {}

	HRESULT setTimeout( mol::variant f, mol::variant t);
	void remove( int i );
	bool fire();

private:
	int count_;
	std::list<ThreadedTimeout*> timeouts_;
};

ThreadedTimeouts& threadedTimeouts();

HRESULT ThreadedTimeouts::setTimeout( mol::variant f, mol::variant t)
{
	long tick = ::GetTickCount();
	if (f.vt != VT_DISPATCH )
	{
		return E_INVALIDARG;
	}
	if ( t.vt != VT_I4 ) 
	{
		t.changeType(VT_I4);
	}
	timeouts_.push_back( new ThreadedTimeout(f.pdispVal,t.llVal+tick) );
	return S_OK;
}

bool ThreadedTimeouts::fire()
{
	long now = ::GetTickCount();
	std::list<ThreadedTimeout*> newList;
	for ( std::list<ThreadedTimeout*>::iterator it = timeouts_.begin(); it != timeouts_.end(); it++)
	{
		if ( (*it)->timeout < now ) 
		{
			EXCEPINFO ex;
			::ZeroMemory(&ex,sizeof(EXCEPINFO));
			UINT e = 0;
			DISPPARAMS p = {0,0};

			HRESULT hr = (*it)->fun->Invoke(0,IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_METHOD,&p,0,&ex,&e);
			delete *it;
		}
		else
		{
			newList.push_back(*it);
		}
	}
	timeouts_ = newList;
	return timeouts_.empty();
}


ThreadedTimeouts& threadedTimeouts()
{
	return mol::singleton<ThreadedTimeouts>();
}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

std::wstring findFile(const std::wstring& f);
 
void MoeDebugImport::dispose() 
{
	if(stop_)
	{
		::CloseHandle(stop_);
		stop_ = 0;
	}
}
 
MoeDebugImport::Instance* MoeDebugImport::CreateInstance(IActiveScript* host)
{
 	Instance* i = new Instance();
 	i->host_ = host;
	i->stop_ = 0;
 	return i;
}
 
HRESULT __stdcall  MoeDebugImport::Import(BSTR filename)
{
 	mol::punk<IActiveScriptParse> asp;
 	HRESULT hr = host_->QueryInterface(IID_IActiveScriptParse,(void**)&asp);
 	if ( hr != S_OK )
 		return E_FAIL;
 
 	std::wstring file = findFile( mol::towstring(filename) );
 
 	mol::filestream fs;
 	fs.open(mol::tostring(file),GENERIC_READ);
 	std::string s = fs.readAll();
 	fs.close();
 
 	mol::variant varResult;
 	EXCEPINFO ei;
 	::ZeroMemory(&ei,sizeof(ei));
 	hr = asp->ParseScriptText( mol::bstr(s), NULL,0,0,1,0,SCRIPTTEXT_ISPERSISTENT|SCRIPTTEXT_ISVISIBLE , &varResult,&ei);
 	return hr;
}

HRESULT __stdcall  MoeDebugImport::Sleep(long ms)
{
	::SleepEx(ms,TRUE);
	return S_OK;
}

HRESULT __stdcall  MoeDebugImport::Wait(long ms,VARIANT_BOOL* vb)
{
	DWORD startTick = ::GetTickCount();
	DWORD nowTick = startTick;

	if(vb)
	{
		*vb = VARIANT_FALSE;
	}

	if(stop_)
	{
		::CloseHandle(stop_);
	}
	stop_ = ::CreateEvent(NULL,FALSE,FALSE,NULL);

	MSG msg;
	while( (ms == 0) || ((nowTick-startTick)<(unsigned long)ms) )
	{
		threadedTimeouts().fire();
		nowTick = ::GetTickCount();
  	    DWORD r = ::MsgWaitForMultipleObjectsEx(1,&stop_,10,QS_ALLINPUT,MWMO_INPUTAVAILABLE|MWMO_ALERTABLE);
		if ( r == WAIT_IO_COMPLETION || r == WAIT_TIMEOUT) 
		{
			continue;
		}

		if ( r == WAIT_OBJECT_0 )
		{
			if(vb)
			{
				*vb = VARIANT_TRUE;
			}
			break;
		}

		if(!::GetMessage(&msg,0,0,0) || msg.message == WM_QUIT)
		{
			if(vb)
			{
				*vb = VARIANT_TRUE;
			}
			
			break;
		}

		if ( mol::win::dialogs().isDialogMessage(msg) )
			continue;

		if ( mol::win::accelerators().translate(msg) )
			continue;

		::TranslateMessage(&msg);
		::DispatchMessage(&msg);
	}
	if(stop_)
	{
		::CloseHandle(stop_);
		stop_ = 0;
	}
	return S_OK;
}

HRESULT __stdcall  MoeDebugImport::Quit()
{
	if(stop_)
	{
		::SetEvent(stop_);
	}
	return S_OK;
}

HRESULT __stdcall  MoeDebugImport::get_Dispatch(IDispatch** disp)
{
	return host_->GetScriptDispatch(L"",disp);
}

HRESULT __stdcall  MoeDebugImport::Callback(BSTR name,IDispatch** disp)
{
	mol::punk<IDispatch> d;
	HRESULT hr = host_->GetScriptDispatch(L"",&d);
	if ( hr == S_OK && d )
	{
		return EventWrapper::CreateInstance(d,mol::bstr(name),disp);
	}
	return S_OK;
}


HRESULT __stdcall  MoeDebugImport::setTimeout( VARIANT f, VARIANT d, VARIANT* retval)
{
	if ( f.vt != VT_DISPATCH )
		return E_INVALIDARG;

	threadedTimeouts().setTimeout( mol::variant(f), mol::variant(d) );
	return S_OK;
}

HRESULT __stdcall  MoeDebugImport::clearTimeout( VARIANT t)
{
	return S_OK;
}


/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

 
ScriptDebugger::ScriptDebugger()
{
	debugCookie_ = 10;

}

ScriptDebugger::~ScriptDebugger()
{
	ODBGS("ScriptDebugger died"); 
}

void ScriptDebugger::init(const std::wstring& engine)
{
	HRESULT hr;

	engine_ = engine;
	stepping_ = false;
	chakra_ = false;

	remote_.release();
	activeScript_.release();
	asp_.release();

	hr = pdm_.createObject(CLSID_ProcessDebugManager);
	if (hr == S_OK && pdm_)
	{
		hr = pdm_->CreateApplication(&debugApp_);
		if (S_OK != hr)
			return;

		hr = debugApp_->SetName(L"moe script");
		if (S_OK != hr)
			return;



		hr = pdm_->AddApplication(debugApp_, &dwAppCookie_);
		if (S_OK != hr)
			return;

		hr = debugApp_->ConnectDebugger((IApplicationDebugger*)this);
		if (S_OK != hr)
			return;

	}


	hr = getScriptEngine( engine_,&activeScript_ );
	if ( hr != S_OK || !activeScript_ )
		return;

	hr = pdm_->CreateDebugDocumentHelper(0, &debugHelper_);
	if (hr == S_OK)
	{
		hr = debugHelper_->Init(debugApp_, L"moed", L"moe debug helper", TEXT_DOC_ATTR_READONLY | TEXT_DOC_ATTR_TYPE_SCRIPT);
	}
	if (hr == S_OK)
	{
		hr = debugHelper_->Attach(NULL);
	}
	if (hr == S_OK)
	{
		hr = debugHelper_->AddUnicodeText(script_.c_str());
	}
	if (hr == S_OK)
	{
		hr = debugHelper_->DefineScriptBlock(0, script_.size(), activeScript_, false, &debugCookie_);
	}

	mol::punk<IActiveScriptProperty> asprop(activeScript_);
	if (asprop)
	{
		mol::variant v(SCRIPTLANGUAGEVERSION_5_8);
		hr = asprop->SetProperty(SCRIPTPROP_INVOKEVERSIONING,NULL,&v);
	}

	hr = activeScript_.queryInterface(IID_IActiveScriptParse,(void**)&asp_);
	if ( hr != S_OK )
		return;

	hr = asp_->InitNew();
	if ( hr != S_OK )
		return;



	hr = activeScript_->SetScriptSite((IActiveScriptSite*)this);
	if ( hr != S_OK )
		return;

	hr = activeScript_->SetScriptState(SCRIPTSTATE_INITIALIZED);//SCRIPTSTATE_STARTED);
	if ( hr != S_OK )
		return;


	

	

 	import = MoeDebugImport::CreateInstance(activeScript_);
 	addNamedObject((IMoeImport*)(import),_T("Importer"),SCRIPTITEM_ISVISIBLE | SCRIPTITEM_GLOBALMEMBERS | SCRIPTITEM_ISSOURCE);

	mol::punk<IDispatch> java;
	MoeScriptObject::CreateInstance(&java, L"JRE.Java");
 	addNamedObject(java,_T("Java"),SCRIPTITEM_ISVISIBLE | SCRIPTITEM_ISSOURCE);

	mol::punk<IDispatch> net;
	MoeScriptObject::CreateInstance(&net, L"Net.DotNet");
 	addNamedObject(net,_T("NET"),SCRIPTITEM_ISVISIBLE | SCRIPTITEM_ISSOURCE);

}

//Guid("{16d51579-a30b-4c8b-a276-0ff4dc41e755}");

DEFINE_GUID( GUID_JSCRIPT9, 0x16d51579L, 0xa30b, 0x4c8b, 
    0xa2, 0x76, 0x0f,0xf4, 0xdc, 0x41, 0xe7, 0x55 );

HRESULT ScriptDebugger::getScriptEngine(const std::wstring& engine, IActiveScript **ppas)
{
	*ppas = 0;
	CLSID clsid;
	HRESULT hr;

	
	if ( engine == _T("JScript") ) {
		// try loading JScript 9 dll
		clsid = GUID_JSCRIPT9;
		hr = CoCreateInstance(clsid, 0, CLSCTX_ALL,IID_IActiveScript,(void**)ppas);
		if (hr == S_OK)
		{
			chakra_ = true;
			return hr;
		}
	}
   
	hr = CLSIDFromProgID(mol::towstring(engine).c_str(), &clsid);
	if (hr == S_OK)
		hr = CoCreateInstance(clsid, 0, CLSCTX_ALL,IID_IActiveScript,(void**)ppas);
	return hr;
}


HRESULT ScriptDebugger::addNamedObject( IUnknown* punk, const std::wstring& obj, int state )
{
	mol::GIT git;
	HRESULT hr;

	if ( objectMap_.count(obj) > 0 ) 
	{
		mol::punk<IUnknown> unk;
		hr = git.getInterface( objectMap_[obj].first, &unk );
		if ( hr == S_OK ) 
		{
			git.revokeInterface(objectMap_[obj].first);
		}
	}

	DWORD cookie = 0;
	hr = git.registerInterface( punk, &cookie );
	if ( hr == S_OK )
	{
		objectMap_[obj] = std::make_pair(cookie,state);
		return S_OK;
	}

	return E_FAIL;
}

HRESULT ScriptDebugger::removeNamedObject( const std::wstring& obj )
{
	mol::GIT git;
	if ( objectMap_[obj].first > 0 )
	{
		mol::punk<IUnknown> unk;
		HRESULT hr = git.getInterface( objectMap_[obj].first, &unk );
		if ( hr == S_OK ) 
		{
			unk->Release();
			git.revokeInterface(objectMap_[obj].first);
		}
		objectMap_.erase(obj);
	}
	return S_OK;
}


ScriptDebugger::Instance* ScriptDebugger::CreateInstance( HWND owner, const std::wstring& script, const std::wstring& filename)
{
	ODBGS("ThreadScript::execute()\r\n");

	Instance* ts = new Instance;
	ts->AddRef();

	ts->owner_ = owner;
	ts->script_ = script;
	ts->filename_ = filename;
	ts->engine_ = engineFromPath( mol::tostring(filename));
	
	return ts;
}

void ScriptDebugger::execute( int flag )
{
	scriptFlags_ = flag;

	mol::thread( 
		boost::bind( &ScriptDebugger::execute_thread, this ), 
		boost::bind(&ScriptDebugger::execute_callback,this) 
	);	
}

void ScriptDebugger::cause_break()
{
	if ( !debugApp_ )
		return;

	debugApp_->CauseBreak();
}

void ScriptDebugger::resume(BREAKRESUMEACTION ba)
{
	if ( !remote_ )
		return;
	
	mol::punk<IRemoteDebugApplication> app;

	if (chakra_)
	{
		switch (ba)
		{
		case BREAKRESUMEACTION_ABORT:
		{
			stepping_ = false;
			break;
		}
		case BREAKRESUMEACTION_CONTINUE:
		{
			stepping_ = false;
			ba = BREAKRESUMEACTION_STEP_INTO;
			break;
		}
		case BREAKRESUMEACTION_STEP_INTO:
		case BREAKRESUMEACTION_STEP_OVER:
		case BREAKRESUMEACTION_STEP_OUT:
		{
			stepping_ = true;
			ba = BREAKRESUMEACTION_STEP_INTO;
			break;
		}
		}
	}

	HRESULT hr = remote_->GetApplication(&app);
	if ( hr == S_OK && app ) 
	{
		hr = app->ResumeFromBreakPoint( 
						remote_, 
						ba, /*default BREAKRESUMEACTION_CONTINUE*/
						ERRORRESUMEACTION_AbortCallAndReturnErrorToCaller 
			);
	}

	remote_.release();
}

HRESULT ScriptDebugger::frames(IEnumDebugStackFrames** frames)
{
	if(!frames)
		return E_INVALIDARG;

	if(!remote_)
		return E_UNEXPECTED;

	return remote_->EnumStackFrames( frames );
}

void  ScriptDebugger::update_breakpoints(std::set<int> br)
{
	mol::punk<IActiveScriptDebug> sdebug(activeScript_);

	if ( sdebug )	
	for ( std::set<int>::iterator it = breakpoints_.begin(); it != breakpoints_.end(); it++ )
	{
		mol::punk<IEnumDebugCodeContexts> debugCtx;
		HRESULT hr = sdebug->EnumCodeContextsOfPosition(debugCookie_, (*it), (ULONG)(script_.size() / 2), &debugCtx);
		if ( hr == S_OK && debugCtx )
		{
			ULONG numFetched = 0;
			mol::punk<IDebugCodeContext> codeCtx;
			hr = debugCtx->Next( 1, &codeCtx, &numFetched );
			if ( hr == S_OK && numFetched )
			{
				codeCtx->SetBreakPoint( BREAKPOINT_DELETED );
			}
		}
	}

	breakpoints_ = br;

	if ( sdebug )	
	for ( std::set<int>::iterator it = breakpoints_.begin(); it != breakpoints_.end(); it++ )
	{
		mol::punk<IEnumDebugCodeContexts> debugCtx;
		HRESULT hr = sdebug->EnumCodeContextsOfPosition(debugCookie_, (*it), (ULONG)(script_.size() / 2), &debugCtx);
		if ( hr == S_OK && debugCtx )
		{
			ULONG numFetched = 0;
			mol::punk<IDebugCodeContext> codeCtx;
			hr = debugCtx->Next( 1, &codeCtx, &numFetched );
			if ( hr == S_OK && numFetched )
			{
				codeCtx->SetBreakPoint( BREAKPOINT_ENABLED );
			}
		}
	}

}

void ScriptDebugger::execute_thread( )
{
	ODBGS("ScriptDebugger::execute()\r\n");

	::CoInitialize(0);

	HRESULT hr;

	init(engine_);

	ODBGS("engine initialized");
	for ( std::map<std::wstring,ObjectMapItem>::iterator it = objectMap_.begin(); it != objectMap_.end(); it++) 
	{
		 hr = activeScript_->AddNamedItem(mol::towstring( (*it).first).c_str(),(*it).second.second);
	}
	ODBGS("names added");

	::VariantClear(&varResult_);
	::ZeroMemory(&ei_, sizeof(ei_));

	if ( asp_ )
	{
		hr = asp_->ParseScriptText( mol::towstring(script_).c_str(),
									  NULL,0,0,debugCookie_,0,SCRIPTTEXT_ISVISIBLE ,
									  &varResult_,&ei_);
		if ( hr != S_OK )
		{
			return;
		}
	}
	
	hr = activeScript_->SetScriptState(SCRIPTSTATE_CONNECTED);

	// execute any outstanding timeouts
	while ( !threadedTimeouts().fire() )
	{
		mol::Sleep(10);
	}
}


void ScriptDebugger::execute_callback()
{
	ODBGS("ThreadScript::callback");

	remote_.release();

	asp_.release();
	activeScript_->Close(); 
	activeScript_.release();

	mol::GIT git;	
	for ( std::map<std::wstring,ObjectMapItem>::iterator it = objectMap_.begin(); it != objectMap_.end(); it++)
	{
		git.revokeInterface((*it).second.first);
	}
	objectMap_.clear();

	import->Quit();
	import.release();


	if ( debugApp_ )
		debugApp_->DisconnectDebugger();

	if(pdm_)
	{
		pdm_->RemoveApplication(dwAppCookie_);
	}

	OnScriptThreadDone.fire();

	((IActiveScriptSite*)this)->Release();
	::CoUninitialize();

}

void ScriptDebugger::eval_expression(const std::wstring& expr)
{
	exp_.release();

	if ( expr.empty() )
		return;

	if ( !remote_ )
		return;

	mol::punk<IRemoteDebugApplicationThread> r(remote_);
	if ( !r )
		return;

	mol::punk<IEnumDebugStackFrames> frames;
	HRESULT hr = r->EnumStackFrames(&frames);
	if ( hr != S_OK)
		return;
	if (!frames)
		return;

	ULONG fetched = 0;							
	DebugStackFrameDescriptor dsfd;
	hr = frames->Next(1,&dsfd,&fetched);
	if ( hr != S_OK)
		return;
	if (! fetched )
		return;

	if ( !dsfd.pdsf )
		return;

	mol::punk<IDebugStackFrame> frame(dsfd.pdsf);
	dsfd.pdsf->Release();

	mol::punk<IDebugExpressionContext> ctx(frame);
	if (!ctx)
		return;

	hr = ctx->ParseLanguageText( mol::towstring(expr).c_str(), 10, 0, DEBUG_TEXT_ISEXPRESSION|DEBUG_TEXT_RETURNVALUE,&exp_);
	if ( hr != S_OK)
		return;
	if ( !exp_ )
		return;

	hr = exp_->Start(this);

}

HRESULT __stdcall ScriptDebugger::onComplete()
{
	std::wstring result;
	mol::bstr txt;

	HRESULT phr = 0;
	HRESULT hr =exp_->GetResultAsString(&phr,&txt);
	if(hr == S_OK && txt)
	{
		result = txt.towstring();
		OnExpressionEvaluated.fire(result);
	}

	exp_.release();
	return S_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////


HRESULT __stdcall ScriptDebugger::GetLCID( LCID *plcid) 
{ 
	*plcid = LOCALE_USER_DEFAULT;
	return S_OK; 
}

HRESULT  __stdcall ScriptDebugger::GetItemInfo( LPCOLESTR pstrName,DWORD dwReturnMask,IUnknown **ppiunkItem,ITypeInfo **ppti)
{
	mol::GIT git;
	if ( SCRIPTINFO_IUNKNOWN & dwReturnMask )
	{
		for ( std::map<std::wstring,ObjectMapItem>::iterator it = objectMap_.begin(); it != objectMap_.end(); it++)
		{
			std::wstring tmp = (*it).first;
			if ( _wcsicmp(mol::towstring(tmp).c_str(),pstrName) == 0 )
			{
				mol::punk<IUnknown> unk;
				HRESULT hr = git.getInterface( (*it).second.first, &unk );
				if ( hr == S_OK )
				{
					
					return unk->QueryInterface(IID_IUnknown,(void**)ppiunkItem);
				}
			}
		}
	}
	if ( SCRIPTINFO_ITYPEINFO & dwReturnMask )
	{
		for ( std::map<std::wstring,ObjectMapItem>::iterator it = objectMap_.begin(); it != objectMap_.end(); it++)
		{
			std::wstring tmp = (*it).first;
			if ( _wcsicmp(mol::towstring(tmp).c_str(),pstrName) == 0 )
			{
				mol::punk<IUnknown> unk;
				HRESULT hr = git.getInterface( (*it).second.first, &unk );
				if ( hr == S_OK )
				{
					mol::punk<IProvideClassInfo> pci(unk);
					if ( pci )
					{
						return pci->GetClassInfo(ppti);
					}
				}
			}
		}
	}
	return TYPE_E_ELEMENTNOTFOUND;
}

HRESULT  __stdcall ScriptDebugger::GetDocVersionString( BSTR *pbstrVersion)
{
	*pbstrVersion = SysAllocString(L"");
	return(S_OK);
}

HRESULT  __stdcall ScriptDebugger::OnScriptTerminate( const VARIANT *pvarResult,const EXCEPINFO *pexcepinfo)
{
	return S_OK;
}

HRESULT  __stdcall ScriptDebugger::OnStateChange( SCRIPTSTATE ssScriptState)
{
	return S_OK;
}

HRESULT  __stdcall ScriptDebugger::OnScriptError( IActiveScriptError *pscripterror)
{
	remote_.release();

	std::wostringstream oss;
	
	DWORD context;
	ULONG line;
	LONG pos;
	pscripterror->GetSourcePosition(&context,&line,&pos);
			
	mol::punk<IActiveScriptErrorDebug> errorDebug(pscripterror);
	if ( errorDebug )
	{
		mol::punk<IDebugStackFrame> f;
		errorDebug->GetStackFrame(&f);

		if ( f )
		{
			mol::bstr e;
			f->GetDescriptionString(TRUE,&e);

			if ( e )
				oss << e.towstring() << std::endl;
		}
	}

	EXCEPINFO ex;
	pscripterror->GetExceptionInfo(&ex);
	if ( ex.bstrDescription )
	{
		oss << mol::bstr(ex.bstrDescription).towstring();
	}

	OnScriptThread.fire( line, oss.str()  );
	return S_OK;
}

HRESULT  __stdcall ScriptDebugger::OnEnterScript( void)
{
	((IActiveScriptSite*)this)->AddRef();

	mol::punk<IActiveScriptDebug> sdebug(activeScript_);

	if ( sdebug )
	for ( std::set<int>::iterator it = breakpoints_.begin(); it != breakpoints_.end(); it++ )
	{
		mol::punk<IEnumDebugCodeContexts> debugCtx;
		HRESULT hr = sdebug->EnumCodeContextsOfPosition(debugCookie_, (*it),(ULONG)(script_.size() ), &debugCtx);
		if ( hr == S_OK && debugCtx )
		{
			ULONG numFetched = 0;
			mol::punk<IDebugCodeContext> codeCtx;
			hr = debugCtx->Next( 1, &codeCtx, &numFetched );
			if ( hr == S_OK && numFetched )
			{
				codeCtx->SetBreakPoint( BREAKPOINT_ENABLED );
			}
		}
	}

//	if ( debug_  && debugApp_)
	if (chakra_)
	{
		HRESULT hr = debugApp_->CauseBreak();
	}

	return S_OK;
}

HRESULT  __stdcall ScriptDebugger::OnLeaveScript( void)
{

	((IActiveScriptSite*)this)->Release();
	return S_OK;
}

HRESULT  __stdcall ScriptDebugger::GetWindow(HWND *phwnd )
{
	HWND w = owner_;
	*phwnd = w;	
	return S_OK;
}

HRESULT  __stdcall ScriptDebugger::EnableModeless(	BOOL fEnable )
{

	return S_OK;
}

//IApplicationDebugger
HRESULT  __stdcall  ScriptDebugger::QueryAlive()
{
		return S_OK;
}

HRESULT  __stdcall  ScriptDebugger::CreateInstanceAtDebugger( REFCLSID rclsid, IUnknown * pUnkOuter, DWORD dwClsContext, REFIID riid, IUnknown ** pObj)
{
		return ::CoCreateInstance(rclsid, pUnkOuter, dwClsContext, riid, (void **)pObj);
}


HRESULT  __stdcall  ScriptDebugger::onDebugOutput(LPCOLESTR pstr)
{
		MessageBoxW(0, pstr, 0, MB_SETFOREGROUND|MB_OK|MB_ICONEXCLAMATION);
		return S_OK;
}

//extern void enumProps( std::wostringstream& oss, IDebugProperty* prop, int level = 0 );

HRESULT  __stdcall  ScriptDebugger::onHandleBreakPoint(IRemoteDebugApplicationThread *rthread, BREAKREASON br, IActiveScriptErrorDebug *pError)
{
	ODBGS("onHandleBreakPoint");
	ULONG						line = (ULONG)-1;

	// get stack frame
	DebugStackFrameDescriptor	desc;
	::ZeroMemory(&desc,sizeof(DebugStackFrameDescriptor));

	mol::punk<IEnumDebugStackFrames> frames;
	HRESULT hr = rthread->EnumStackFrames( &frames );
	if ( S_OK != hr || !frames )
		return S_OK;

	// reset frame enumerator
	hr = frames->Reset();
	if ( S_OK != hr )
		return S_OK;

	// get topmost frame desc
	hr = frames->Next( 1, &desc, &line );
	if ( S_OK != hr )
		return S_OK;

	if (!desc.pdsf) 
	{
		ODBGS("!descrip.pdsf : return S_OK");
		return S_OK;
	}

	// fetch doc from ctx from ctx ...
	mol::punk<IDebugCodeContext>	 codeCtx;
	hr = desc.pdsf->GetCodeContext( &codeCtx );
	desc.pdsf->Release();	

	if (hr != S_OK)
		return S_OK;

	mol::punk<IDebugDocumentContext> docCtx;
	hr = codeCtx->GetDocumentContext( &docCtx );
	if (hr != S_OK)
		return S_OK;

	mol::punk<IDebugDocument>		 doc;
	hr = docCtx->GetDocument( &doc );
	if (hr != S_OK)
		return S_OK;

	// determine line
	if ( ((IDebugDocumentTextAuthor*)(IDebugDocument*)doc) == ((IDebugDocumentTextAuthor*)(IDebugDocument*)this) )
	{
		((IDebugDocumentTextAuthor*)(IDebugDocument*)doc)->GetLineOfPosition(offset_, &line, 0);
	}
	else
	{
		mol::punk<IDebugDocumentText> docText(doc);
		if ( docText)
		{
			ULONG		position;
			ULONG		offset;
			hr = docText->GetPositionOfContext( docCtx, &position, &offset );
			if ( hr == S_OK )
			{
				hr = docText->GetLineOfPosition( position, &line, &offset );
				hr = docText->GetPositionOfLine(line, &position);

				if (chakra_)
				{
					if (stepping_ == false && !pError) {
						if (breakpoints_.find(position) == breakpoints_.end()) {
							remote_ = rthread;
							resume(BREAKRESUMEACTION_CONTINUE);
							return S_OK;
						}
					}
				}
			}
		}
	}
	
	ODBGS1("errorhandler line :",line);

	remote_ = rthread;

	std::wostringstream oss;
	if ( pError )
	{
		EXCEPINFO ex;
		pError->GetExceptionInfo(&ex);

		
		
		mol::punk<IActiveScriptErrorDebug> errorDebug(pError);
		if ( errorDebug )
		{
			mol::punk<IDebugStackFrame> f;
			errorDebug->GetStackFrame(&f);

			if ( f )
			{
				mol::bstr e;
				f->GetDescriptionString(TRUE,&e);

				if ( e )
					oss << e.towstring() << std::endl;
			}
		}

		if ( ex.bstrDescription )
		{
			oss << mol::bstr(ex.bstrDescription).towstring();
		}
	}

	OnScriptThread.fire( (int)line, oss.str() );
	return S_OK;	
}


HRESULT  __stdcall  ScriptDebugger::onClose()
{
		return S_OK;
}


HRESULT  __stdcall  ScriptDebugger::onDebuggerEvent( REFIID, IUnknown *)
{
		return E_NOTIMPL;
}



/////////////////////////////////////////////////////////////////////////////////////////////

HRESULT  __stdcall  ScriptDebugger::BringDocumentToTop(IDebugDocumentText *)
{
	return S_OK;
}

HRESULT  __stdcall  ScriptDebugger::BringDocumentContextToTop( IDebugDocumentContext *)
{
	return S_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////

// IActiveScriptSiteDebug Implementation
HRESULT  STDMETHODCALLTYPE  ScriptDebugger::GetDocumentContextFromPosition(
#ifdef _WIN64
								  DWORDLONG dwSourceContext,	
#else
								  DWORD dwSourceContext,	
#endif
								  ULONG uCharacterOffset,	
								  ULONG uNumChars,			
								  IDebugDocumentContext **ppsc)
{

	if (!ppsc) return E_POINTER;
	*ppsc = NULL;
	if (!debugHelper_) return E_UNEXPECTED;

	// every running document has a special "cookie" associated with it. 
	// this code assumes only 1 document with a cookie value stored in 
	// m_dwDocCookie. It then asks the helper interface IDebugDocumentHelper 
	// to convert from a character offset to a document context interface. 
	ULONG ulStartPos = 0;
	HRESULT hr = debugHelper_->GetScriptBlockInfo(debugCookie_, NULL, &ulStartPos, NULL);

	if (SUCCEEDED(hr))
		return debugHelper_->CreateDebugDocumentContext(ulStartPos + uCharacterOffset, uNumChars, ppsc);
	return hr;

}


HRESULT  __stdcall ScriptDebugger::GetApplication(IDebugApplication **ppda)
{
	if (!ppda) return E_POINTER;
	*ppda = NULL;
	if (!debugApp_) return E_UNEXPECTED;

	// return the IDebugApplication interface we created earlier.
	return debugApp_.queryInterface(ppda);
}

HRESULT  __stdcall ScriptDebugger::GetRootApplicationNode(IDebugApplicationNode **ppdanRoot)
{
   if (!ppdanRoot)
   {
      return E_INVALIDARG;
   }

   *ppdanRoot = NULL;
   return S_OK;

   if (debugApp_)
   {
	   return debugApp_->GetRootNode( ppdanRoot );
   }

   return E_NOTIMPL;
}

HRESULT  __stdcall ScriptDebugger::OnScriptErrorDebug(
								  IActiveScriptErrorDebug *pErrorDebug,
								  BOOL*pfEnterDebugger,
								  BOOL *pfCallOnScriptErrorWhenContinuing)
{
   if (pfEnterDebugger)
   {
	  *pfEnterDebugger = TRUE;
   }
   if (pfCallOnScriptErrorWhenContinuing)
   {
      *pfCallOnScriptErrorWhenContinuing = TRUE;
   }
   return S_OK;
}

