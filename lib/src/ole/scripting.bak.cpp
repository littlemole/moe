#include "ole/scripting.h"
#include "ole/bstr.h"
#include <sstream>

namespace mol {
namespace ole {

/////////////////////////////////////////////////////////////////////////////////////////////

HRESULT ActiveScript::init(const mol::string& engine)
{
	engine_ = engine;

	as_.release();
	asp_.release();

	HRESULT hr;
	hr = getScriptEngine( engine_,&as_ );
	if ( hr != S_OK || !as_ )
		return hr;

	hr = as_.queryInterface(IID_IActiveScriptParse,(void**)&asp_);
	if ( hr != S_OK )
		return hr;

	hr = asp_->InitNew();
	return hr;
}

HRESULT ActiveScript::setHost(IActiveScriptSite* host)
{
	if ( !host )
		return E_FAIL;

	return as_->SetScriptSite(host);
}

HRESULT ActiveScript::setState(SCRIPTSTATE state)
{
	if ( as_ )
		return as_->SetScriptState(state);
	return E_UNEXPECTED;
}

HRESULT ActiveScript::close()
{
	if ( as_ )
	{
		HRESULT hr = as_->Close();
		return hr;
	}
	return S_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////


HRESULT ActiveScript::addNamedObject(const mol::string& obj, int state)
{
	return as_->AddNamedItem(mol::towstring(obj).c_str(),state);
}


HRESULT ActiveScript::runScript(const mol::string& script, int flag)
{
	::VariantClear(&varResult_);
	::ZeroMemory(&ei_, sizeof(ei_));

	if ( asp_ )
		return asp_->ParseScriptText( mol::towstring(script).c_str(),
									  NULL,0,0,0,0,flag,//SCRIPTTEXT_ISEXPRESSION|SCRIPTTEXT_ISVISIBLE ,
									  &varResult_,&ei_);

	return E_FAIL;
}

HRESULT ActiveScript::getScriptDispatch( const mol::string& script, IDispatch **ppdisp)
{
	if ( as_ )
		if ( script.length() > 0 )
			return as_->GetScriptDispatch( mol::towstring(script).c_str(),ppdisp);
		else
			return as_->GetScriptDispatch( 0,ppdisp);

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
   
   HRESULT hr = CLSIDFromProgID(mol::towstring(engine).c_str(), &clsid);
   if (SUCCEEDED(hr))
     hr = CoCreateInstance(clsid, 0, CLSCTX_ALL,IID_IActiveScript,(void**)ppas);
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

}

ScriptHost::~ScriptHost()
{
	close();
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
	hr = this->close();
	hr = activeScript_.init(engine);
	if ( hr != S_OK )
		return hr;

	hr = activeScript_.setHost(this);
	if ( hr != S_OK )
		return hr;

	hr = activeScript_.setState(SCRIPTSTATE_INITIALIZED);//SCRIPTSTATE_STARTED);//SCRIPTSTATE_INITIALIZED);
	if ( hr != S_OK )
		return hr;

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
	punk->AddRef();
	objectMap_[obj] = punk;

	HRESULT hr = activeScript_.addNamedObject(obj,state);
	if ( hr == S_OK )
	{
		return S_OK;
	}
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
	return activeScript_.addScriptlet(name, handler, obj, subobj, eventname );
}

HRESULT ScriptHost::runScript(const mol::string& script, int flag)
{
	return activeScript_.runScript(script,flag);
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
	((IActiveScriptSite*)this)->AddRef();
	return S_OK;
}

HRESULT  __stdcall ScriptHost::OnLeaveScript( void)
{
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

} // end namespace mole
