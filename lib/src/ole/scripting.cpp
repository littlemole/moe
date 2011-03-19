#include "ole/scripting.h"
#include "ole/bstr.h"
#include <sstream>

namespace mol {
namespace ole {

/////////////////////////////////////////////////////////////////////////////////////////////

HRESULT ActiveScript::init(const mol::string& engine)
{
	ODBGS("init ActiveScript");
	ODBGS(engine);

	engine_ = engine;

	activeScript.release();
	asp_.release();

	HRESULT hr;
	hr = getScriptEngine( engine_,&activeScript );
	if ( hr != S_OK || !activeScript )
	{
		ODBGS("getEngine failed!");
		return hr;
	}

	//hr = activeScript.queryInterface(IID_IActiveScriptParse,(void**)&asp_);
	hr = activeScript.queryInterface(&asp_);
	if ( hr != S_OK )
	{
		ODBGS("ActiveScriptParse failed!");
		return hr;
	}

	hr = asp_->InitNew();
	return hr;
}

HRESULT ActiveScript::setHost(IActiveScriptSite* host)
{
	if ( !host )
		return E_FAIL;

	return activeScript->SetScriptSite(host);
}

HRESULT ActiveScript::setState(SCRIPTSTATE state)
{
	if ( activeScript )
		return activeScript->SetScriptState(state);
	return E_UNEXPECTED;
}

HRESULT ActiveScript::close()
{
	if ( activeScript )
	{
		HRESULT hr = activeScript->Close();
		return hr;
	}
	return S_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////


HRESULT ActiveScript::addNamedObject(const mol::string& obj, int state)
{
	return activeScript->AddNamedItem(mol::towstring(obj).c_str(),state);
}


HRESULT ActiveScript::runScript(const mol::string& script, int flag)
{
	ODBGS("run script");

	::VariantClear(&varResult_);
	::ZeroMemory(&ei_, sizeof(ei_));

	HRESULT hr;
	if ( asp_ )
	{
		ODBGS("parse script");
		hr = asp_->ParseScriptText( mol::towstring(script).c_str(),
									  NULL,0,0,0,0,flag,//SCRIPTTEXT_ISEXPRESSION|SCRIPTTEXT_ISVISIBLE ,
									  &varResult_,&ei_);
		if ( hr == S_OK )
		{
			
			return hr;
		}
	}
	ODBGS("parse script failed");

	return E_FAIL;
}

HRESULT ActiveScript::getScriptDispatch( const mol::string& script, IDispatch **ppdisp)
{
	if ( activeScript )
		if ( script.length() > 0 )
			return activeScript->GetScriptDispatch( mol::towstring(script).c_str(),ppdisp);
		else
			return activeScript->GetScriptDispatch( 0,ppdisp);

	return E_FAIL;
}

HRESULT ActiveScript::addScriptlet( mol::string& name, 
					  const mol::string& handler,
					  const mol::string& obj,
					  const mol::string& subobj,
					  const mol::string& eventname )
{
	::VariantClear(&varResult_);
	::ZeroMemory(&ei_, sizeof(ei_));

	bstr bstrName;
	HRESULT hr = asp_->AddScriptlet( 
			mol::towstring(name).c_str(), 
			mol::towstring(handler).c_str(),
			mol::towstring(obj).c_str(),
			mol::towstring(subobj).c_str(),
			mol::towstring(eventname).c_str(),
			L"",0,0,SCRIPTTEXT_ISVISIBLE ,&bstrName,&ei_
		);

	return S_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////


variant& ActiveScript::result()
{
	return varResult_;
}

EXCEPINFO& ActiveScript::errorInfo()
{
	return ei_;
}

/////////////////////////////////////////////////////////////////////////////////////////////

 HRESULT ActiveScript::getScriptEngine(const mol::string& engine, IActiveScript **ppas)
 {
   *ppas = 0;
   CLSID clsid;

   ODBGS("getScriptEngine");
   ODBGS(engine);
   
   HRESULT hr = CLSIDFromProgID(mol::towstring(engine).c_str(), &clsid);
   if (hr != S_OK || ::IsEqualGUID(clsid,CLSID_NULL) )
   {
	   ODBGS("CLSIDFromProgID for engine failed ");
	   return hr;
   }

   mol::string s = mol::stringFromCLSID(clsid);
   ODBGS(s);
   
   ODBGS("create engine");
   hr = CoCreateInstance(clsid, 0, CLSCTX_ALL,IID_IActiveScript,(void**)ppas);
   if ( hr != S_OK )
   {
		ODBGS("CoCreateInstance for engine failed ");
   }
   
   return hr;
 }

 
} // end namespace mole::win::ole

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

 
ScriptHost::ScriptHost()
{
	debug_ = false;

	HRESULT hr;
	hr = pdm_.createObject(CLSID_ProcessDebugManager);
	if ( S_OK != hr )
		return;

	hr = pdm_->CreateApplication(&debugApp_);
	if ( S_OK != hr )
		return;

	hr = debugApp_->SetName(L"script");
	if ( S_OK != hr )
		return;

	hr = pdm_->AddApplication(debugApp_, &dwAppCookie_);
	if ( S_OK != hr )
		return;

}

ScriptHost::~ScriptHost()
{
	if ( debugApp_ )
		debugApp_->DisconnectDebugger();

	close();
	ODBGS("ScriptHost died");
}

HRESULT ScriptHost::close()
{

	for ( std::map<mol::string,IUnknown*>::iterator it = objectMap_.begin(); it != objectMap_.end(); it++)
	{
		(*it).second->Release();
	}
	objectMap_.clear();
	return activeScript_.close();
}

HRESULT ScriptHost::init(const mol::string& engine)
{
	HRESULT hr;
	hr = activeScript_.init(engine);
	if ( hr != S_OK )
	{
		ODBGS("init activescript failed");
		return hr;
	}

	hr = activeScript_.setHost((IActiveScriptSite*)this);
	if ( hr != S_OK )
	{
		ODBGS("set host failed");
		return hr;
	}

	hr = activeScript_.setState(SCRIPTSTATE_INITIALIZED);//SCRIPTSTATE_STARTED);//SCRIPTSTATE_INITIALIZED);
	if ( hr != S_OK )
	{
		ODBGS("setstate failed");
		return hr;
	}

	return hr;
}

HRESULT ScriptHost::setState(SCRIPTSTATE state)
{
	HRESULT hr = activeScript_.setState(state);//SCRIPTSTATE_STARTED);//SCRIPTSTATE_INITIALIZED);
	return hr;
}

HRESULT ScriptHost::exec()
{
	return activeScript_.setState(SCRIPTSTATE_STARTED);
}

HRESULT ScriptHost::addNamedObject( IUnknown* punk, const mol::string& obj, int state )
{
	ODBGS("addNamedObject");
	punk->AddRef();
	if ( objectMap_.count(obj) > 0 ) 
	{
		objectMap_[obj]->Release();
	}
	objectMap_[obj] = punk;

	HRESULT hr = activeScript_.addNamedObject(obj,state);
	if ( hr == S_OK )
	{
		ODBGS("addNamedObject success");
		return S_OK;
	}
	ODBGS("addNamedObject failed");
	objectMap_.erase(obj);
	punk->Release();
	return hr;
}

HRESULT ScriptHost::removeNamedObject( const mol::string& obj )
{
	if ( objectMap_[obj] > 0 )
	{
		objectMap_[obj]->Release();
		objectMap_.erase(obj);

	}
	return S_OK;
}

HRESULT ScriptHost::addScriptlet( mol::string& name, 
					  const mol::string& handler,
					  const mol::string& obj,
					  const mol::string& subobj,
					  const mol::string& eventname )
{
	debug_ = false;
	return activeScript_.addScriptlet(name, handler, obj, subobj, eventname );
}

HRESULT ScriptHost::runScript(const mol::string& script, int flag)
{
	ODBGS("runScript");
	debug_ = false;
	HRESULT hr;

	if ( pdm_ )
	{
		ODBGS("got PDM");
		hr = pdm_->CreateDebugDocumentHelper(NULL, &debugDocHelper_);
		if ( hr == S_OK && pdm_)
		{
			hr = debugDocHelper_->Init(debugApp_, L"script", L"moe script", TEXT_DOC_ATTR_READONLY);
			if ( hr == S_OK &&debugDocHelper_ )
			{
				ODBGS("got debugdochelper");
				hr = debugDocHelper_->Attach(NULL);	
				if ( hr == S_OK )
				{
#ifdef _UNICODE
					hr = debugDocHelper_->AddUnicodeText(script.c_str());
#else
					hr = debugDocHelper_->AddDBCSText(script.c_str());
#endif
					ODBGS("debugdochelper attached");
					if ( hr == S_OK )
					{

#ifdef _WIN64
						DWORDLONG dw;
#else
						DWORD dw;
#endif
						hr = debugDocHelper_->DefineScriptBlock( 0, 
																 (ULONG)script.size(),
																 activeScript_.activeScript, 
																 FALSE, 
																 &dw);
					}
				}
			}
		}
	}

	//hr = debugApp_->StartDebugSession();
	hr = activeScript_.runScript(script,flag);
	
	return hr;
}


HRESULT ScriptHost::debugScript(const mol::string& script, int flag)
{
	debug_ = true;
	HRESULT hr;

	if ( pdm_ )
	{
		hr = pdm_->CreateDebugDocumentHelper(NULL, &debugDocHelper_);
		if ( hr == S_OK && debugDocHelper_)
		{
			hr = debugDocHelper_->Init(debugApp_, L"script", L"moe script", TEXT_DOC_ATTR_READONLY);
			if ( hr == S_OK )
			{
				hr = debugDocHelper_->Attach(NULL);	
				if ( hr == S_OK )
				{
#ifdef _UNICODE
					hr = debugDocHelper_->AddUnicodeText(script.c_str());
#else
					hr = debugDocHelper_->AddDBCSText(script.c_str());
#endif
					if ( hr == S_OK )
					{

#ifdef _WIN64
						DWORDLONG dw;
#else
						DWORD dw;
#endif
						hr = debugDocHelper_->DefineScriptBlock(0, (ULONG)script.size(),activeScript_.activeScript, FALSE, &dw);
					}
				}
			}
		}
	}

	//hr = debugApp_->StartDebugSession();
	hr = activeScript_.runScript(script,flag);
	return hr;
}

HRESULT ScriptHost::getScript( const mol::string& script,IDispatch **ppdisp)
{
	return activeScript_.getScriptDispatch(script,ppdisp);
}

variant ScriptHost::call(const mol::string& func )
{
	variant ret;

	punk<IDispatch> disp;
	HRESULT hr = getScript(_T(""),&disp);
	if ( (hr == S_OK) && disp )
	{	
		std::wstring ws = mol::towstring(func);
		OLECHAR* c = (OLECHAR*)ws.c_str();
		DISPID dispid;
		hr = disp->GetIDsOfNames(IID_NULL, &(c), 1, 0, &dispid);
		if ( hr == S_OK )
		{
			return disp_call( disp,dispid );
		}
	}
	return ret;
}

variant& ScriptHost::result()
{
	return activeScript_.result();
}

EXCEPINFO& ScriptHost::errorInfo()
{
	return activeScript_.errorInfo();
}
/////////////////////////////////////////////////////////////////////////////////////////////


HRESULT __stdcall ScriptHost::GetLCID( LCID *plcid) 
{ 
	return E_NOTIMPL; 
}

HRESULT  __stdcall ScriptHost::GetItemInfo( LPCOLESTR pstrName,DWORD dwReturnMask,IUnknown **ppiunkItem,ITypeInfo **ppti)
{
	if ( SCRIPTINFO_IUNKNOWN & dwReturnMask )
	{
		for ( std::map<mol::string,IUnknown*>::iterator it = objectMap_.begin(); it != objectMap_.end(); it++)
		{
			mol::string tmp = (*it).first;
			if ( _wcsicmp(mol::towstring(tmp).c_str(),pstrName) == 0 )
			{
				IUnknown* punk = (*it).second;
				return punk->QueryInterface(IID_IUnknown,(void**)ppiunkItem);				
			}
		}
	}
	if ( SCRIPTINFO_ITYPEINFO & dwReturnMask )
	{
		for ( std::map<mol::string,IUnknown*>::iterator it = objectMap_.begin(); it != objectMap_.end(); it++)
		{
			mol::string tmp = (*it).first;
			if ( _wcsicmp(mol::towstring(tmp).c_str(),pstrName) == 0 )
			{
				IUnknown* unk = (*it).second;
				punk<IProvideClassInfo> pci(unk);
				if ( pci )
				{
					return pci->GetClassInfo(ppti);
				}
			}
		}
	}
	return TYPE_E_ELEMENTNOTFOUND;
}

HRESULT  __stdcall ScriptHost::GetDocVersionString( BSTR *pbstrVersion)
{
	return E_NOTIMPL;
}

HRESULT  __stdcall ScriptHost::OnScriptTerminate( const VARIANT *pvarResult,const EXCEPINFO *pexcepinfo)
{
	return S_OK;
}

HRESULT  __stdcall ScriptHost::OnStateChange( SCRIPTSTATE ssScriptState)
{
	return S_OK;
}

HRESULT  __stdcall ScriptHost::OnScriptError( IActiveScriptError *pscripterror)
{
	EXCEPINFO ex;
	pscripterror->GetExceptionInfo(&ex);
	bstr src;
	pscripterror->GetSourceLineText(&src);
	DWORD context;
	ULONG line;
	LONG pos;
	pscripterror->GetSourcePosition(&context,&line,&pos);
	std::ostringstream oss;
	oss << BSTR2ansi(ex.bstrDescription) << " line " << line << "\r\n";
	oss << src.tostring();
	::MessageBoxA( 0, oss.str().c_str(),BSTR2ansi(ex.bstrSource).c_str(), MB_ICONERROR);
	return S_OK;
}

HRESULT  __stdcall ScriptHost::OnEnterScript( void)
{
	ODBGS("enter script");
	((IActiveScriptSite*)this)->AddRef();

	if ( debug_  && debugApp_)
		HRESULT hr = debugApp_->CauseBreak();

	return S_OK;
}

HRESULT  __stdcall ScriptHost::OnLeaveScript( void)
{
	ODBGS("leave script");
	if ( debugDocHelper_ )
		debugDocHelper_->Detach();

	((IActiveScriptSite*)this)->Release();
	return S_OK;
}

HRESULT  __stdcall ScriptHost::GetWindow(HWND *phwnd )
{
	*phwnd = ::GetDesktopWindow();
	return S_OK;
}

HRESULT  __stdcall ScriptHost::EnableModeless(	BOOL fEnable )
{

	return S_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////

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


// IActiveScriptSiteDebug Implementation
HRESULT  __stdcall  ScriptHost::GetDocumentContextFromPosition(
#ifdef _WIN64
								  DWORDLONG dwSourceContext,	
#else
								  DWORD dwSourceContext,	
#endif
								  ULONG uCharacterOffset,	
								  ULONG uNumChars,			
								  IDebugDocumentContext **ppsc)

/**HRESULT  __stdcall ScriptHost::GetDocumentContextFromPosition(
								  DWORD dwSourceContext,	
								  ULONG uCharacterOffset,	
								  ULONG uNumChars,			
								  IDebugDocumentContext **ppsc)
								  */
{
   ULONG ulStartPos = 0;
   HRESULT hr;

   if (debugDocHelper_)
   {
      hr = debugDocHelper_->GetScriptBlockInfo(dwSourceContext, NULL, &ulStartPos, NULL);
      hr = debugDocHelper_->CreateDebugDocumentContext(ulStartPos + uCharacterOffset, uNumChars, ppsc);
   }
   else
   {
      hr = E_NOTIMPL;
   }

	return hr;
}


HRESULT  __stdcall ScriptHost::GetApplication(IDebugApplication **ppda)
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

HRESULT  __stdcall ScriptHost::GetRootApplicationNode(IDebugApplicationNode **ppdanRoot)
{
   if (!ppdanRoot)
   {
      return E_INVALIDARG;
   }

   if (debugDocHelper_)
   {
      return debugDocHelper_->GetDebugApplicationNode(ppdanRoot);
   }

   return E_NOTIMPL;
}

HRESULT  __stdcall ScriptHost::OnScriptErrorDebug(
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



} // end namespace mole
