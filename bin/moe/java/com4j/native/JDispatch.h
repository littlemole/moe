#pragma once
#include "com4j.h"

class ATL_NO_VTABLE CJDispatch :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CJDispatch>,
	public IDispatch
{
private:
	// peer in the Java world
	GlobalRef<jobject>  jdispatch;

	int* dispids_;
	int nDispids_;

public:

	void FinalRelease() 
	{
		if ( dispids_ )
			delete[] dispids_;
	}

	static CJDispatch* create( JNIEnv* pEnv, jobject obj ) {

		CComObject<CJDispatch>* pObj;
		CComObject<CJDispatch>::CreateInstance(&pObj);
		pObj->AddRef();
		pObj->init(pEnv,obj);
		return pObj;
	}

	void init( JNIEnv* pEnv, jobject obj  );

DECLARE_PROTECT_FINAL_CONSTRUCT()
	
BEGIN_COM_MAP(CJDispatch)
	COM_INTERFACE_ENTRY(IUnknown)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

public:
	STDMETHOD(GetTypeInfoCount)(UINT *pctinfo) {
		*pctinfo = 0;
		return S_OK;
	}

	STDMETHOD(GetTypeInfo)( UINT iTInfo, LCID lcid, ITypeInfo** ppTInfo ) {
		*ppTInfo = NULL;
		return E_NOTIMPL;
	}
    
	STDMETHOD(GetIDsOfNames)( REFIID riid, LPOLESTR* rgszNames, UINT cNames, LCID lcid, DISPID* rgDispId );
   	STDMETHOD(Invoke)( DISPID dispid, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS* pDispParams, VARIANT* pResult, EXCEPINFO* pExcepInfo, UINT* puArgErr ); 
};
