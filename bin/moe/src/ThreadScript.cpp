#include "StdAfx.h"
#include "ThreadScript.h"

#include "ole/bstr.h"
#include "ole/cp.h"
#include <sstream>
#include "xmlui.h"


mol::string engineFromPath(const std::string& path)
{
	return mol::toString(mol::engineFromExtension(mol::Path::ext(mol::toString(path))));
}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

mol::string findFile(const mol::string& f);
 
void MoeDebugImport::dispose() {}
 
MoeDebugImport::Instance* MoeDebugImport::CreateInstance(IActiveScript* host)
{
 	Instance* i = new Instance();
 	i->host_ = host;
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

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

 
ThreadScript::ThreadScript()
{}

ThreadScript::~ThreadScript()
{
	ODBGS("ThreadScript died");
}

void ThreadScript::close()
{
	mol::GIT git;	
	for ( std::map<mol::string,ObjectMapItem>::iterator it = objectMap_.begin(); it != objectMap_.end(); it++)
	{
		git.revokeInterface((*it).second.first);
	}
	objectMap_.clear();

	activeScript_->Close();
}

void ThreadScript::init(const mol::string& engine)
{
	HRESULT hr;

	engine_ = engine;

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

	mol::punk<IMoeImport> import;
 	import = MoeDebugImport::CreateInstance(activeScript_);
 	addNamedObject((IMoeImport*)(import),_T("MoeImport"),SCRIPTITEM_ISVISIBLE | SCRIPTITEM_GLOBALMEMBERS | SCRIPTITEM_ISSOURCE);
}

HRESULT ThreadScript::getScriptEngine(const mol::string& engine, IActiveScript **ppas)
{
	*ppas = 0;
	CLSID clsid;
   
	HRESULT hr = CLSIDFromProgID(mol::towstring(engine).c_str(), &clsid);
	if (hr == S_OK)
		hr = CoCreateInstance(clsid, 0, CLSCTX_ALL,IID_IActiveScript,(void**)ppas);
	return hr;
}


HRESULT ThreadScript::addNamedObject( IUnknown* punk, const mol::string& obj, int state )
{
	punk->AddRef();

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

HRESULT ThreadScript::removeNamedObject( const mol::string& obj )
{
	mol::GIT git;
	if ( objectMap_[obj].first > 0 )
	{
		mol::punk<IUnknown> unk;
		HRESULT hr = git.getInterface( objectMap_[obj].first, &unk );
		if ( hr == S_OK ) 
		{
			git.revokeInterface(objectMap_[obj].first);
		}
		objectMap_.erase(obj);
	}
	return S_OK;
}


ThreadScript* ThreadScript::CreateInstance( HWND owner, const mol::string& script, const mol::string& filename)
{
	ODBGS("ThreadScript::execute()\r\n");

	ScriptInstance* ts = new ScriptInstance;
	ts->AddRef();

	ts->owner_ = owner;
	ts->script_ = script;
	ts->filename_ = filename;
	ts->engine_ = engineFromPath( mol::tostring(filename));
	
	return ts;
}

void ThreadScript::execute( int flag )
{
	scriptFlags_ = flag;

	mol::thread( 
		boost::bind( &ThreadScript::execute_thread, this ), 
		boost::bind(&ThreadScript::execute_callback,this) 
	);	
}

void ThreadScript::cause_break()
{
	if ( !debugApp_ )
		return;

	debugApp_->CauseBreak();
}

void  ThreadScript::update_breakpoints(std::set<int> br)
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

void ThreadScript::execute_thread( )
{
	ODBGS("ThreadScript::execute()\r\n");

	mol::com_init ci;
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
									  NULL,0,0,0,0,SCRIPTTEXT_ISPERSISTENT|SCRIPTTEXT_ISVISIBLE ,
									  &varResult_,&ei_);
		if ( hr != S_OK )
		{
			return;
		}
	}
	

	hr = activeScript_->SetScriptState(SCRIPTSTATE_CONNECTED);
}


void ThreadScript::execute_callback()
{
	ODBGS("ThreadScript::callback");

	if ( debugApp_ )
		debugApp_->DisconnectDebugger();

	close();

	OnScriptThreadDone.fire();

	((IActiveScriptSite*)this)->Release();
}

/////////////////////////////////////////////////////////////////////////////////////////////


HRESULT __stdcall ThreadScript::GetLCID( LCID *plcid) 
{ 
	*plcid = LOCALE_USER_DEFAULT;
	return S_OK; 
}

HRESULT  __stdcall ThreadScript::GetItemInfo( LPCOLESTR pstrName,DWORD dwReturnMask,IUnknown **ppiunkItem,ITypeInfo **ppti)
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

HRESULT  __stdcall ThreadScript::GetDocVersionString( BSTR *pbstrVersion)
{
	*pbstrVersion = SysAllocString(L"");
	return(S_OK);
}

HRESULT  __stdcall ThreadScript::OnScriptTerminate( const VARIANT *pvarResult,const EXCEPINFO *pexcepinfo)
{
	return S_OK;
}

HRESULT  __stdcall ThreadScript::OnStateChange( SCRIPTSTATE ssScriptState)
{
	return S_OK;
}

HRESULT  __stdcall ThreadScript::OnScriptError( IActiveScriptError *pscripterror)
{
	pscripterror->AddRef();
	OnScriptThread.fire( -1, (IRemoteDebugApplicationThread*) 0,pscripterror  );
	return S_OK;
}

HRESULT  __stdcall ThreadScript::OnEnterScript( void)
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

HRESULT  __stdcall ThreadScript::OnLeaveScript( void)
{

	((IActiveScriptSite*)this)->Release();
	return S_OK;
}

HRESULT  __stdcall ThreadScript::GetWindow(HWND *phwnd )
{
	HWND w = owner_;
	*phwnd = w;	
	return S_OK;
}

HRESULT  __stdcall ThreadScript::EnableModeless(	BOOL fEnable )
{

	return S_OK;
}

//IApplicationDebugger
HRESULT  __stdcall  ThreadScript::QueryAlive()
{
		return S_OK;
}

HRESULT  __stdcall  ThreadScript::CreateInstanceAtDebugger( REFCLSID rclsid, IUnknown * pUnkOuter, DWORD dwClsContext, REFIID riid, IUnknown ** pObj)
{
		return ::CoCreateInstance(rclsid, pUnkOuter, dwClsContext, riid, (void **)pObj);
}


HRESULT  __stdcall  ThreadScript::onDebugOutput(LPCOLESTR pstr)
{
		MessageBoxW(0, pstr, 0, MB_SETFOREGROUND|MB_OK|MB_ICONEXCLAMATION);
		return S_OK;
}

//extern void enumProps( mol::ostringstream& oss, IDebugProperty* prop, int level = 0 );

HRESULT  __stdcall  ThreadScript::onHandleBreakPoint(IRemoteDebugApplicationThread *remote, BREAKREASON br, IActiveScriptErrorDebug *pError)
{
	ODBGS("onHandleBreakPoint");
	ULONG						line = (ULONG)-1;

	// get stack frame
	DebugStackFrameDescriptor	desc;
	::ZeroMemory(&desc,sizeof(DebugStackFrameDescriptor));

	mol::punk<IEnumDebugStackFrames> frames;
	HRESULT hr = remote->EnumStackFrames( &frames );
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

	// pass control to UI thread

	remote->AddRef();

	if ( pError )
		pError->AddRef();

	OnScriptThread.fire( (int)line, remote, (IActiveScriptError*)pError );
	return S_OK;	
}


HRESULT  __stdcall  ThreadScript::onClose()
{
		return S_OK;
}


HRESULT  __stdcall  ThreadScript::onDebuggerEvent( REFIID, IUnknown *)
{
		return E_NOTIMPL;
}



/////////////////////////////////////////////////////////////////////////////////////////////

HRESULT  __stdcall  ThreadScript::BringDocumentToTop(IDebugDocumentText *)
{
	return S_OK;
}

HRESULT  __stdcall  ThreadScript::BringDocumentContextToTop( IDebugDocumentContext *)
{
	return S_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////


HRESULT  __stdcall  ThreadScript::GetName( DOCUMENTNAMETYPE dnt, BSTR * str)
{
	if ( !str ) 
		return E_INVALIDARG;

	*str = ::SysAllocString( filename_.c_str() );
	return S_OK;
}

HRESULT  __stdcall  ThreadScript::GetDocumentClassId(CLSID * clsid)
{
	if ( !clsid ) 
		return E_INVALIDARG;
	
	memcpy(clsid, &GUID_NULL, sizeof(GUID));
	return S_OK;
}

HRESULT  __stdcall  ThreadScript::GetDocumentAttributes(TEXT_DOC_ATTR * attr)
{
		*attr = TEXT_DOC_ATTR_READONLY;
		return S_OK;
}

HRESULT  __stdcall  ThreadScript::GetSize(ULONG *  numLines, ULONG* numChars)
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

HRESULT  __stdcall  ThreadScript::GetPositionOfLine( ULONG lineNum, ULONG* pos)
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

HRESULT  __stdcall  ThreadScript::GetLineOfPosition( ULONG position, ULONG * lineNum, ULONG * charOffset)
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

HRESULT  __stdcall  ThreadScript::GetText(ULONG position, WCHAR * text, SOURCE_TEXT_ATTR * attr, ULONG * numChars, ULONG max)
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

HRESULT  __stdcall  ThreadScript::GetPositionOfContext( IDebugDocumentContext * ctx, ULONG *position, ULONG * numChars)
{
	*numChars = (DWORD)script_.size();
	*position = 0;
	return S_OK;
}

HRESULT  __stdcall  ThreadScript::GetContextOfPosition(ULONG position, ULONG numCHars, IDebugDocumentContext ** cts)
{
	return ((IActiveScriptSite*)this)->QueryInterface( IID_IDebugDocumentContext, (void**) cts );
}

HRESULT  __stdcall  ThreadScript::InsertText( ULONG, ULONG, OLECHAR *)
{
	return E_FAIL;
}

HRESULT  __stdcall  ThreadScript::RemoveText( ULONG, ULONG)
{
	return E_FAIL;
}

HRESULT  __stdcall  ThreadScript::ReplaceText( ULONG, ULONG, OLECHAR *)
{
	return E_FAIL;
}


HRESULT  __stdcall  ThreadScript::GetDocument(IDebugDocument **pObj)
{
	HRESULT hr = ((IDebugDocument*)this)->QueryInterface(IID_IDebugDocument, (void**)pObj );
	return hr;
}

HRESULT  __stdcall  ThreadScript::EnumCodeContexts(IEnumDebugCodeContexts **pObj)
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
HRESULT  STDMETHODCALLTYPE  ThreadScript::GetDocumentContextFromPosition(
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


HRESULT  __stdcall ThreadScript::GetApplication(IDebugApplication **ppda)
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

HRESULT  __stdcall ThreadScript::GetRootApplicationNode(IDebugApplicationNode **ppdanRoot)
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

HRESULT  __stdcall ThreadScript::OnScriptErrorDebug(
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

