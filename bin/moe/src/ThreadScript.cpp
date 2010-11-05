#include "StdAfx.h"
#include "ThreadScript.h"

#include "ole/bstr.h"
#include "ole/cp.h"
#include <sstream>
#include "moe.h"
#include "xmlui.h"
#include "Editor.h"

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

 
ThreadScript::ThreadScript()
{
	debug_ = false;
}

ThreadScript::~ThreadScript()
{
	ODBGS("ThreadScript died");
}
/*
mol::variant& ThreadScript::result()
{
	return varResult_;
}

EXCEPINFO& ThreadScript::errorInfo()
{
	return ei_;
}
*/
void ThreadScript::close()
{
	mol::GIT git;
	for ( std::map<mol::string,DWORD>::iterator it = objectMap_.begin(); it != objectMap_.end(); it++)
	{
		git.revokeInterface((*it).second);
	}
	objectMap_.clear();

	if ( sciCookie_ )
		git.revokeInterface(sciCookie_);
	
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

	hr = activeScript_->SetScriptState(SCRIPTSTATE_INITIALIZED);//SCRIPTSTATE_STARTED);//SCRIPTSTATE_INITIALIZED);
	if ( hr != S_OK )
		return;

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
		hr = git.getInterface( objectMap_[obj], &unk );
		if ( hr == S_OK ) 
		{
			git.revokeInterface(objectMap_[obj]);
		}
	}

	DWORD cookie = 0;
	hr = git.registerInterface( punk, &cookie );
	if ( hr == S_OK )
	{
		objectMap_[obj] = cookie;
		return S_OK;
	}

	return E_FAIL;
}

HRESULT ThreadScript::removeNamedObject( const mol::string& obj )
{
	mol::GIT git;
	if ( objectMap_[obj] > 0 )
	{
		mol::punk<IUnknown> unk;
		HRESULT hr = git.getInterface( objectMap_[obj], &unk );
		if ( hr == S_OK ) 
		{
			git.revokeInterface(objectMap_[obj]);
		}
		objectMap_.erase(obj);
	}
	return S_OK;
}


mol::string engineFromExtension(const mol::string& ext)
{
	try {
		
		mol::string x = ext;
		mol::RegKey root(HKEY_CLASSES_ROOT, KEY_READ);

		if ( ext[0] != _T('.') )
		{
			mol::string tmp(_T("."));
			tmp += ext;
			x = tmp;
		}
		
		mol::RegKey extKey = root.open(x, KEY_READ);
		mol::string extFile = extKey.get();
		mol::RegKey fileKey = root.open(extFile, KEY_READ);
		mol::RegKey engineKey = fileKey.open( _T("ScriptEngine"), KEY_READ );
		return engineKey.get();
	}
	catch (...) {}
	return _T("");
}

ThreadScript* ThreadScript::execute( Editor* editor, IUnknown* obj, const mol::string& name, const mol::string& script, const mol::string& filename, int flag, std::set<int> brs  )
{

	ODBGS("ThreadScript::execute()\r\n");


	ScriptInstance* ts = new ScriptInstance;
	ts->AddRef();

	ts->sciCookie_ = 0;
	HRESULT hr;
	if ( editor->sci )
	{
		mol::GIT git;
		mol::punk<IDispatch> disp(editor->sci);
		hr = git.registerInterface( (IDispatch*)disp, &(ts->sciCookie_) );
	}

	ts->editor_ = editor;
	ts->debug_ = true;


	ts->script_ = script;
	ts->scriptFlags_ = flag;
	ts->filename_ = filename;
	ts->engine_ = engineFromPath( mol::tostring(filename));
	ts->breakpoints_ = brs;
	ts->addNamedObject(obj,name);
	
	mol::thread( boost::bind( &ThreadScript::execute_thread, ts ), boost::bind(&ThreadScript::execute_callback,ts) );
	return ts;
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
	for ( std::map<mol::string,DWORD>::iterator it = objectMap_.begin(); it != objectMap_.end(); it++) 
	{
		 hr = activeScript_->AddNamedItem(mol::towstring( (*it).first).c_str(),SCRIPTITEM_ISVISIBLE| SCRIPTITEM_ISSOURCE);
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

	mol::invoke( *editor_, &Editor::OnScriptThreadDone );

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
		for ( std::map<mol::string,DWORD>::iterator it = objectMap_.begin(); it != objectMap_.end(); it++)
		{
			mol::string tmp = (*it).first;
			if ( _wcsicmp(mol::towstring(tmp).c_str(),pstrName) == 0 )
			{
				mol::punk<IUnknown> unk;
				HRESULT hr = git.getInterface( (*it).second, &unk );
				if ( hr == S_OK )
				{
					
					return unk->QueryInterface(IID_IUnknown,(void**)ppiunkItem);
				}
			}
		}
	}
	if ( SCRIPTINFO_ITYPEINFO & dwReturnMask )
	{
		for ( std::map<mol::string,DWORD>::iterator it = objectMap_.begin(); it != objectMap_.end(); it++)
		{
			mol::string tmp = (*it).first;
			if ( _wcsicmp(mol::towstring(tmp).c_str(),pstrName) == 0 )
			{
				mol::punk<IUnknown> unk;
				HRESULT hr = git.getInterface( (*it).second, &unk );
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
	EXCEPINFO ex;
	DWORD context;
	ULONG line;
	LONG pos;

	if ( sciCookie_ )
	{
		mol::GIT git;

		mol::punk<IDispatch> disp;
		HRESULT hr = git.getInterface( sciCookie_, &disp);

		if ( hr == S_OK && disp )
		{
			pscripterror->GetExceptionInfo(&ex);
			pscripterror->GetSourcePosition(&context,&line,&pos);

			mol::ostringstream oss;
			oss << "line: " << (line+1) << std::endl << mol::bstr(ex.bstrDescription).toString();

			// setAnnotation(line,str)
			mol::disp_invoke( disp, 71, line, oss.str() );
			return S_OK;
		}
	}
		
	mol::bstr src;

	pscripterror->GetExceptionInfo(&ex);
	pscripterror->GetSourceLineText(&src);
	pscripterror->GetSourcePosition(&context,&line,&pos);

	std::ostringstream oss;
	oss << mol::BSTR2ansi(ex.bstrDescription) << " line " << line << "\r\n";
	oss << src.tostring();

	::MessageBoxA( 0, oss.str().c_str(),mol::BSTR2ansi(ex.bstrSource).c_str(), MB_ICONERROR);
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
	HWND w = *moe();
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

extern void enumProps( mol::ostringstream& oss, IDebugProperty* prop, int level = 0 );

HRESULT  __stdcall  ThreadScript::onHandleBreakPoint(IRemoteDebugApplicationThread *remote, BREAKREASON br, IActiveScriptErrorDebug *pError)
{
	ODBGS("onHandleBreakPoint");
	HRESULT						hr;
	ULONG						line = (ULONG)-1;
	DebugStackFrameDescriptor	descrip;

	// Get the IEnumStackFrames
	mol::punk<IEnumDebugStackFrames> frame1;
	mol::punk<IEnumDebugStackFrames> frame2;
	mol::punk<IDebugCodeContext>	 codeCtx;
	mol::punk<IDebugDocumentContext> docCtx;
	mol::punk<IDebugDocument>		 doc;

	descrip.pdsf = 0;
	hr = remote->EnumStackFrames( &frame1 );
	if ( S_OK == hr )
	{
		// Fill in the DebugStackFrameDescriptor with the topmost stack frame's info
		frame1->Next( 1, &descrip, &line );
	}

	if (!descrip.pdsf) 
	{
		ODBGS("!descrip.pdsf : return S_OK");
		return S_OK;
	}

	// Get the IDebugCodeContext for the topmost stack frame
	hr = descrip.pdsf->GetCodeContext( &codeCtx );
	descrip.pdsf->Release();	

	if (hr == S_OK)
	{
		// Get that IDebugCodeContext's IDebugDocumentContext
		hr = codeCtx->GetDocumentContext( &docCtx );
		if (hr == S_OK )
		{
			hr = docCtx->GetDocument( &doc );
			if ( hr == S_OK )
			{
				if ( ((IDebugDocumentTextAuthor*)(IDebugDocument*)doc) == ((IDebugDocumentTextAuthor*)(IDebugDocument*)this) )
				{
					((IDebugDocumentTextAuthor*)(IDebugDocument*)doc)->GetLineOfPosition(offset_, &line, 0);
					ODBGS1("our own debugdoc:",line);
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
						ODBGS1("other debugdoc:",line);
					}
				}
			}
		}
	}
	//mol::ostringstream oss;
	
	mol::punk<IEnumDebugStackFrames> frames;
	hr = remote->EnumStackFrames(&frames);
	if ( hr == S_OK && frames )
	{
		hr = frames->Reset();
		if ( hr == S_OK  )
		{
			while (1)
			{

				ODBGS("EnumStackFrames:");
				DebugStackFrameDescriptor d;
				ULONG fetched = 0;
				hr = frames->Next(1, &d, &fetched );
				if ( hr != S_OK || fetched == 0 )
					break;

				debugDlg()->update_variables(frames);

				/*
				mol::bstr txt;
				hr = d.pdsf->GetDescriptionString(TRUE,&txt);
				if ( hr == S_OK )
				{
					oss << txt.toString() << std::endl;
				}

				mol::punk<IDebugProperty> prop;
				hr = d.pdsf->GetDebugProperty(&prop);
				if ( hr == S_OK && prop )
				{
				
					//enumProps(oss,prop);
					

				}
				//ODBGS(oss.str());
				*/
				d.pdsf->Release();
				break;
			}
		}
	}
	
	ODBGS1("errorhandler line :",line);

	remote->AddRef();

	if ( pError )
		pError->AddRef();

	ODBGS1("invoke errorhandler line :",line);
	//mol::string s = oss.str();
	mol::invoke( *editor_, &Editor::OnScriptThread, (int)line, remote,pError  );

	return S_OK;
	
}


HRESULT  __stdcall  ThreadScript::onClose()
{

		return S_OK;
}


HRESULT  __stdcall  ThreadScript::onDebuggerEvent( REFIID, IUnknown *)
{

		return(E_NOTIMPL);
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
	register DWORD	chars;
	register DWORD	lines;
	register WCHAR	*ptr;

	chars = script_.size();
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

			goto inc;
		}

		if (*ptr == '\n')
inc:		++lines;

		++ptr;
	}

	// Count any final line that doesn't end with \r or \n
	if ( script_.size() && (*(ptr - 1) != '\r' || *(ptr - 1) != '\n')) ++lines;

	*numLines = lines;
	return S_OK;
}

HRESULT  __stdcall  ThreadScript::GetPositionOfLine( ULONG lineNum, ULONG* pos)
{
	register DWORD	lines, offset;
	register WCHAR	*ptr;

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

			goto inc;
		}

		if (*ptr == '\n')
inc:		++lines;

		++offset;
		++ptr;
	}

	*pos = offset;

	return(S_OK);

}

HRESULT  __stdcall  ThreadScript::GetLineOfPosition( ULONG position, ULONG * lineNum, ULONG * charOffset)
{
	register DWORD	lines, offset;
	register WCHAR	*ptr;
	DWORD			prevLine;

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

			goto inc;
		}

		if (*ptr == '\n')
		{
inc:		prevLine = offset + 1;
			++lines;
		}

		++offset;
		++ptr;
	}

	*lineNum = lines;
	if (charOffset) *charOffset = offset - prevLine;

	return(S_OK);

}

HRESULT  __stdcall  ThreadScript::GetText(ULONG position, WCHAR * text, SOURCE_TEXT_ATTR * attr, ULONG * numChars, ULONG max)
{
	register DWORD		offset;
	register WCHAR		*ptr;
	

	if (position >= script_.size() )
	{
		*numChars = 0;
		if (!max) goto out;
fail:	return(E_FAIL);
	}

	// Get the start of text
	ptr = (WCHAR*)script_.c_str() + position;

	// Make sure caller isn't asking for more chars than are remaining
	offset = max;
	if ((offset + position) > script_.size() ) offset = script_.size() - position;
	*numChars = offset;

	if (text) CopyMemory(text, script_.c_str() + position, offset);

	// Does caller want some attrs filled in?
	if (attr)
	{
		mol::punk<IActiveScriptDebug>	debug(activeScript_);

		if ( !debug )
			//goto fail;
			return S_OK;


		// Call its GetScriptTextAttributes to fill in the attrs array
		debug->GetScriptTextAttributes( script_.c_str() + position, offset, 0, 0, attr);

	}
out:
	return(S_OK);


}

HRESULT  __stdcall  ThreadScript::GetPositionOfContext( IDebugDocumentContext * ctx, ULONG *position, ULONG * numChars)
{
	*numChars = script_.size();
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

	hr = debug->EnumCodeContextsOfPosition( (DWORD)0,0,script_.size(),pObj);
	return hr;
}

/////////////////////////////////////////////////////////////////////////////////////////////




// IActiveScriptSiteDebug Implementation

HRESULT  __stdcall ThreadScript::GetDocumentContextFromPosition(
								  DWORD dwSourceContext,	
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

   // bugbug - should addref to this ?
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
	   if ( debug_ )
	      *pfEnterDebugger = TRUE;
   }
   if (pfCallOnScriptErrorWhenContinuing)
   {
      *pfCallOnScriptErrorWhenContinuing = TRUE;
   }
   return S_OK;
}

