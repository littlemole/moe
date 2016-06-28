#ifndef USERFORM_HANDLER_DEF_GUARD_
#define USERFORM_HANDLER_DEF_GUARD_

#include "common.h"

/////////////////////////////////////////////////////////////////////

class FormScriptEventHandler : public IDispatch
{
public:
	~FormScriptEventHandler();

	void init(IDispatch* s, REFIID iid, const std::wstring& on);
	virtual void dispose() {}

	HRESULT virtual __stdcall QueryInterfaceImpl(REFIID iid, LPVOID* ppv);
	HRESULT virtual __stdcall GetTypeInfoCount(unsigned int FAR*  pctinfo);
	HRESULT virtual __stdcall GetTypeInfo(unsigned int  iTInfo, LCID  lcid, ITypeInfo FAR* FAR*  ppTInfo);
	HRESULT virtual __stdcall GetIDsOfNames(REFIID  riid, OLECHAR FAR* FAR*  rgszNames, unsigned int  cNames, LCID   lcid, DISPID FAR*  rgDispId);
	HRESULT virtual __stdcall Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn, EXCEPINFO * ex, UINT * i);

private:
	IID riid;
	mol::punk<IDispatch> script;
	mol::punk< ITypeInfo> info;
	std::wstring objname;
};


///////////////////////////////////////////////////////////////////////////////

#endif