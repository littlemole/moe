#include "StdAfx.h"
#include "Handler.h"


/////////////////////////////////////////////////////////////////////////////////////////////

FormScriptEventHandler::~FormScriptEventHandler()
{
	ODBGS("FormScriptEventHandler dead");
}
/////////////////////////////////////////////////////////////////////////////////////////////


void FormScriptEventHandler::init(IDispatch* s, REFIID iid, const std::wstring& on)
{
	riid = iid;
	script = s;
	objname = on;
	info.release();
	if ((S_OK == mol::typeInfoForInterface(riid, &info)) && info)
	{

	}
}

/////////////////////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall FormScriptEventHandler::QueryInterfaceImpl(REFIID iid, LPVOID* ppv)
{
	ODBGS("::QueryInterface ScriptEventHandler");
	if (ppv == (void**)0)
		return E_INVALIDARG;

	if (IsEqualIID(iid, IID_IUnknown))
	{
		*ppv = (IUnknown*)this;
		((IUnknown*)(*ppv))->AddRef();
		return S_OK;
	}
	if (IsEqualIID(iid, IID_IDispatch))
	{
		*ppv = (IDispatch*)this;
		((IDispatch*)(*ppv))->AddRef();
		return S_OK;
	}
	if (IsEqualIID(iid, riid))
	{
		*ppv = (IDispatch*)this;
		((IDispatch*)(*ppv))->AddRef();
		return S_OK;
	}
	ODBGS("ScriptEventHandler::QueryInterface E_NOINTERFACE");
	*ppv = (IUnknown*)(0);
	return E_NOINTERFACE;
}

/////////////////////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall FormScriptEventHandler::GetTypeInfoCount(unsigned int FAR*  pctinfo)
{
	*pctinfo = 1;
	return S_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall FormScriptEventHandler::GetTypeInfo(unsigned int  iTInfo, LCID  lcid, ITypeInfo FAR* FAR*  ppTInfo)
{
	return info->QueryInterface(IID_ITypeInfo, (void**)ppTInfo);
}

/////////////////////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall FormScriptEventHandler::GetIDsOfNames(REFIID  riid, OLECHAR FAR* FAR*  rgszNames, unsigned int  cNames, LCID   lcid, DISPID FAR*  rgDispId)
{
	return info->GetIDsOfNames(rgszNames, cNames, rgDispId);
}

/////////////////////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall FormScriptEventHandler::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn, EXCEPINFO * ex, UINT * i)
{
	UINT nNames = 0;
	mol::bstr name;
	if (pReturn) {
		pReturn->vt = VT_EMPTY;
	}
	if ((S_OK == info->GetNames(dispIdMember, &name, 1, &nNames)) && (nNames == 1))
	{
		std::stringstream oss;
		oss << mol::tostring(objname) << "_";
		oss << mol::tostring(name);

		// protect refcount as we might quit
		mol::punk<IDispatch> disp(script);

		DISPID dispid;
		std::wstring ws = mol::towstring(oss.str());
		mol::bstr func(ws);
		HRESULT hr = disp->GetIDsOfNames(IID_NULL, &(func), 1, 0, &dispid);
		if (hr == S_OK)
		{
			mol::variant varResult;
			hr = disp->Invoke(dispid, IID_NULL,
				LOCALE_SYSTEM_DEFAULT,
				w,
				pDisp,
				pReturn,ex,i
			);
		}
	}
	return S_OK;
}