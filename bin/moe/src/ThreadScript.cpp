#include "StdAfx.h"
#include "ThreadScript.h"
#include "xmlui.h"
#include "widgets.h"


mol::string engineFromPath(const std::string& path)
{
	return mol::toString(mol::engineFromExtension(mol::Path::ext(mol::toString(path))));
}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

mol::string findFile(const mol::string& f);
 
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
 
 	mol::string file = findFile( mol::toString(filename) );
 
 	mol::filestream fs;
 	fs.open(mol::tostring(file),GENERIC_READ);
 	std::string s = fs.readAll();
 	fs.close();
 
 	mol::variant varResult;
 	EXCEPINFO ei;
 	::ZeroMemory(&ei,sizeof(ei));
 	hr = asp->ParseScriptText( mol::bstr(s), NULL,0,0,0,0,SCRIPTTEXT_ISPERSISTENT|SCRIPTTEXT_ISVISIBLE , &varResult,&ei);
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
		nowTick = ::GetTickCount();
  	    DWORD r = ::MsgWaitForMultipleObjectsEx(1,&stop_,100,QS_ALLINPUT,MWMO_INPUTAVAILABLE|MWMO_ALERTABLE);
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

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

 
ScriptDebugger::ScriptDebugger()
{}

ScriptDebugger::~ScriptDebugger()
{
	ODBGS("ScriptDebugger died"); 
}

void ScriptDebugger::init(const mol::string& engine)
{
	HRESULT hr;

	engine_ = engine;

	remote_.release();
	activeScript_.release();
	asp_.release();

	hr = pdm_.createObject(CLSID_ProcessDebugManager);
	if ( hr == S_OK && pdm_ )
	{
		hr = pdm_->CreateApplication(&debugApp_);
		if ( S_OK != hr )
			return;

		hr = debugApp_->SetName(L"moe script");
		if ( S_OK != hr )
			return;

	
		hr = pdm_->AddApplication(debugApp_, &dwAppCookie_);
		if ( S_OK != hr )
			return;

		hr = debugApp_->ConnectDebugger( (IApplicationDebugger*)this );
		if ( S_OK != hr )
			return;
	}
	
	hr = getScriptEngine( engine_,&activeScript_ );
	if ( hr != S_OK || !activeScript_ )
		return;

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
 	addNamedObject((IMoeImport*)(import),_T("MoeImport"),SCRIPTITEM_ISVISIBLE | SCRIPTITEM_GLOBALMEMBERS | SCRIPTITEM_ISSOURCE);

	mol::punk<IDispatch> java;
	MoeScriptObject::CreateInstance(&java, L"JRE.Java");
 	addNamedObject(java,_T("Java"),SCRIPTITEM_ISVISIBLE | SCRIPTITEM_GLOBALMEMBERS | SCRIPTITEM_ISSOURCE);

	mol::punk<IDispatch> net;
	MoeScriptObject::CreateInstance(&java, L"Net.DotNet");
 	addNamedObject(java,_T("NET"),SCRIPTITEM_ISVISIBLE | SCRIPTITEM_GLOBALMEMBERS | SCRIPTITEM_ISSOURCE);

}

//Guid("{16d51579-a30b-4c8b-a276-0ff4dc41e755}");

DEFINE_GUID( GUID_JSCRIPT9, 0x16d51579L, 0xa30b, 0x4c8b, 
    0xa2, 0x76, 0x0f,0xf4, 0xdc, 0x41, 0xe7, 0x55 );

HRESULT ScriptDebugger::getScriptEngine(const mol::string& engine, IActiveScript **ppas)
{
	*ppas = 0;
	CLSID clsid;
	HRESULT hr;

	
	if ( engine == _T("JScript") ) {
		// try loading JScript 9 dll
		clsid = GUID_JSCRIPT9;
		hr = CoCreateInstance(clsid, 0, CLSCTX_ALL,IID_IActiveScript,(void**)ppas);
		if (hr == S_OK)
			return hr;
	}
   
	hr = CLSIDFromProgID(mol::towstring(engine).c_str(), &clsid);
	if (hr == S_OK)
		hr = CoCreateInstance(clsid, 0, CLSCTX_ALL,IID_IActiveScript,(void**)ppas);
	return hr;
}


HRESULT ScriptDebugger::addNamedObject( IUnknown* punk, const mol::string& obj, int state )
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

HRESULT ScriptDebugger::removeNamedObject( const mol::string& obj )
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


ScriptDebugger::Instance* ScriptDebugger::CreateInstance( HWND owner, const mol::string& script, const mol::string& filename)
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
		HRESULT hr = sdebug->EnumCodeContextsOfPosition( 0, (*it), 40, &debugCtx );
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
		HRESULT hr = sdebug->EnumCodeContextsOfPosition( 0, (*it), 40, &debugCtx );
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
	for ( std::map<mol::string,ObjectMapItem>::iterator it = objectMap_.begin(); it != objectMap_.end(); it++) 
	{
		 hr = activeScript_->AddNamedItem(mol::towstring( (*it).first).c_str(),(*it).second.second);
	}
	ODBGS("names added");

	::VariantClear(&varResult_);
	::ZeroMemory(&ei_, sizeof(ei_));

	if ( asp_ )
	{
		hr = asp_->ParseScriptText( mol::towstring(script_).c_str(),
									  NULL,0,0,0,0,SCRIPTTEXT_ISVISIBLE ,
									  &varResult_,&ei_);
		if ( hr != S_OK )
		{
			return;
		}
	}
	

	hr = activeScript_->SetScriptState(SCRIPTSTATE_CONNECTED);
}


void ScriptDebugger::execute_callback()
{
	ODBGS("ThreadScript::callback");

	remote_.release();

	asp_.release();
	activeScript_->Close(); 
	activeScript_.release();

	mol::GIT git;	
	for ( std::map<mol::string,ObjectMapItem>::iterator it = objectMap_.begin(); it != objectMap_.end(); it++)
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

void ScriptDebugger::eval_expression(const mol::string& expr)
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
	mol::string result;
	mol::bstr txt;

	HRESULT phr = 0;
	HRESULT hr =exp_->GetResultAsString(&phr,&txt);
	if(hr == S_OK && txt)
	{
		result = txt.toString();
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
		for ( std::map<mol::string,ObjectMapItem>::iterator it = objectMap_.begin(); it != objectMap_.end(); it++)
		{
			mol::string tmp = (*it).first;
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
		for ( std::map<mol::string,ObjectMapItem>::iterator it = objectMap_.begin(); it != objectMap_.end(); it++)
		{
			mol::string tmp = (*it).first;
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

	mol::ostringstream oss;
	
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
				oss << e.toString() << std::endl;
		}
	}

	EXCEPINFO ex;
	pscripterror->GetExceptionInfo(&ex);
	if ( ex.bstrDescription )
	{
		oss << mol::bstr(ex.bstrDescription).toString();
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
		HRESULT hr = sdebug->EnumCodeContextsOfPosition( 0, (*it), 40, &debugCtx );
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
		//HRESULT hr = debugApp_->CauseBreak();

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

//extern void enumProps( mol::ostringstream& oss, IDebugProperty* prop, int level = 0 );

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
			}
		}
	}
	
	ODBGS1("errorhandler line :",line);

	remote_ = rthread;

	mol::ostringstream oss;
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
					oss << e.toString() << std::endl;
			}
		}

		if ( ex.bstrDescription )
		{
			oss << mol::bstr(ex.bstrDescription).toString();
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


HRESULT  __stdcall  ScriptDebugger::GetName( DOCUMENTNAMETYPE dnt, BSTR * str)
{
	if ( !str ) 
		return E_INVALIDARG;

	*str = ::SysAllocString( filename_.c_str() );
	return S_OK;
}

HRESULT  __stdcall  ScriptDebugger::GetDocumentClassId(CLSID * clsid)
{
	if ( !clsid ) 
		return E_INVALIDARG;
	
	memcpy(clsid, &GUID_NULL, sizeof(GUID));
	return S_OK;
}

HRESULT  __stdcall  ScriptDebugger::GetDocumentAttributes(TEXT_DOC_ATTR * attr)
{
		*attr = TEXT_DOC_ATTR_READONLY;
		return S_OK;
}

HRESULT  __stdcall  ScriptDebugger::GetSize(ULONG *  numLines, ULONG* numChars)
{
	DWORD	chars;
	DWORD	lines;
	WCHAR	*ptr;

	chars = (DWORD)script_.size();
	*numChars = chars;

	ptr = (WCHAR*)script_.c_str();
	lines = 0;
	while (chars--)
	{
		if (*ptr == '\r')
		{
			if (chars && *(ptr + 1) == '\n')
			{
				--chars;
				++ptr;
			}
		}

		if (*ptr == '\n')
			++lines;

		++ptr;
	}

	// Count any final line that doesn't end with \r or \n
	if ( script_.size() && (*(ptr - 1) != '\r' || *(ptr - 1) != '\n')) ++lines;

	*numLines = lines;
	return S_OK;
}

HRESULT  __stdcall  ScriptDebugger::GetPositionOfLine( ULONG lineNum, ULONG* pos)
{
	DWORD	lines, offset;
	WCHAR	*ptr;

	ptr = (WCHAR*)script_.c_str();
	offset = lines = 0;
	while (lineNum != lines && offset < script_.size() )
	{
		if (*ptr == '\r')
		{
			if (offset < script_.size() && *(ptr + 1) == '\n')
			{
				++offset;
				++ptr;
			}
		}

		if (*ptr == '\n')
			++lines;

		++offset;
		++ptr;
	}

	*pos = offset;

	return S_OK;
}

HRESULT  __stdcall  ScriptDebugger::GetLineOfPosition( ULONG position, ULONG * lineNum, ULONG * charOffset)
{
	DWORD	lines, offset;
	WCHAR	*ptr;
	DWORD	prevLine;

	ptr = (WCHAR*)script_.c_str();
	prevLine = offset = lines = 0;
	while (offset < script_.size() && offset < position)
	{
		if (*ptr == '\r')
		{
			if (offset < script_.size() && offset < position && *(ptr + 1) == '\n')
			{
				++offset;
				++ptr;
			}
		}

		if (*ptr == '\n')
		{
			prevLine = offset + 1;
			++lines;
		}

		++offset;
		++ptr;
	}

	*lineNum = lines;
	if (charOffset) *charOffset = offset - prevLine;

	return S_OK;

}

HRESULT  __stdcall  ScriptDebugger::GetText(ULONG position, WCHAR * text, SOURCE_TEXT_ATTR * attr, ULONG * numChars, ULONG max)
{
	register DWORD		offset;
	register WCHAR		*ptr;
	

	if (position >= script_.size() )
	{
		*numChars = 0;
		if (!max) 
			return S_OK;
		
		return E_FAIL ;
	}

	// Get the start of text
	ptr = (WCHAR*)script_.c_str() + position;

	// Make sure caller isn't asking for more chars than are remaining
	offset = max;
	if ((offset + position) > (DWORD)script_.size() ) offset = (DWORD)script_.size() - position;
	*numChars = offset;

	if (text) 
		::CopyMemory(text, script_.c_str() + position, offset);

	if (attr)
	{
		mol::punk<IActiveScriptDebug>	debug(activeScript_);

		if ( !debug )
			return S_OK;

		debug->GetScriptTextAttributes( script_.c_str() + position, offset, 0, 0, attr);
	}

	return S_OK;
}

HRESULT  __stdcall  ScriptDebugger::GetPositionOfContext( IDebugDocumentContext * ctx, ULONG *position, ULONG * numChars)
{
	*numChars = (DWORD)script_.size();
	*position = 0;
	return S_OK;
}

HRESULT  __stdcall  ScriptDebugger::GetContextOfPosition(ULONG position, ULONG numCHars, IDebugDocumentContext ** cts)
{
	return ((IActiveScriptSite*)this)->QueryInterface( IID_IDebugDocumentContext, (void**) cts );
}

HRESULT  __stdcall  ScriptDebugger::InsertText( ULONG, ULONG, OLECHAR *)
{
	return E_FAIL;
}

HRESULT  __stdcall  ScriptDebugger::RemoveText( ULONG, ULONG)
{
	return E_FAIL;
}

HRESULT  __stdcall  ScriptDebugger::ReplaceText( ULONG, ULONG, OLECHAR *)
{
	return E_FAIL;
}


HRESULT  __stdcall  ScriptDebugger::GetDocument(IDebugDocument **pObj)
{
	HRESULT hr = ((IDebugDocument*)this)->QueryInterface(IID_IDebugDocument, (void**)pObj );
	return hr;
}

HRESULT  __stdcall  ScriptDebugger::EnumCodeContexts(IEnumDebugCodeContexts **pObj)
{
	HRESULT hr;

	mol::punk<IActiveScriptDebug> debug(activeScript_);
	if ( !debug )
	{
		return E_FAIL;
	}

	hr = debug->EnumCodeContextsOfPosition( (DWORD)0,0,(ULONG)script_.size(),pObj);
	return hr;
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
   if ( script_.size() > uCharacterOffset )
   {
	   offset_ = uCharacterOffset;
	   return ((IDebugDocumentContext*)this)->QueryInterface( IID_IDebugDocumentContext, (void**)ppsc );
   }
   return E_FAIL;
}


HRESULT  __stdcall ScriptDebugger::GetApplication(IDebugApplication **ppda)
{
   if (!ppda)
   {
      return E_INVALIDARG;
   }

   if (debugApp_)
   {
      ULONG ul = debugApp_->AddRef();
	  *ppda = debugApp_;
	  return S_OK;
   }

   *ppda = 0;
	return E_FAIL;
}

HRESULT  __stdcall ScriptDebugger::GetRootApplicationNode(IDebugApplicationNode **ppdanRoot)
{
   if (!ppdanRoot)
   {
      return E_INVALIDARG;
   }

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

