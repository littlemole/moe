#include "stdafx.h"
#include "JDispatch.h"
#include "java_id.h"
#include "variant.h"

//JClassID JClass<jstring>::clazz("java/lang/String");
JClassID com4jJDispatch("com4j/Dispatch");
JMethodID<jintArray> com4jJDispatch_getDISPIDs(com4jJDispatch,"getDISPIDs","([Ljava/lang/String;)[I");
JMethodID<jobject> com4jJDispatch_invoke(com4jJDispatch,"invoke","(II[Lcom4j/Variant;)Ljava/lang/Object;");
JStaticMethodID<jstring> com4jJDispatch_getErrorSource(com4jJDispatch,"getErrorSource","(Ljava/lang/Throwable;)Ljava/lang/String;");
JStaticMethodID<jstring> com4jJDispatch_getErrorDetail(com4jJDispatch,"getErrorDetail","(Ljava/lang/Throwable;)Ljava/lang/String;");

void CJDispatch::init( JNIEnv* pEnv, jobject obj  ) {

	dispids_  = 0;
	nDispids_ = 0;

	jdispatch.Attach(pEnv,obj);

	/*
	LockedArray<jint> r(pEnv, com4jJDispatch_getDISPIDs( pEnv, jdispatch ));

	nDispids_ = (int)cNames;
	dispids_ = new int[nDispids_];
	for( int i = 0; i < nDispids_; i++ ) {
		dispids_[i] = r[i];
	}
	*/
}

STDMETHODIMP CJDispatch::GetIDsOfNames( REFIID riid, LPOLESTR* rgszNames, UINT cNames, LCID lcid, DISPID* rgDispId ) {
	AttachThread jniScope(jniModule);
	JNIEnv* pEnv = jniScope;

	bool unknown = false;

	jobjectArray strings = jnitl::array::Array<jstring>::newArray(pEnv,(int)cNames);

	{
		LockedArray<jstring> a(pEnv, strings);

		for( int i=0; i<(int)cNames; i++ ) {
			jstring s = pEnv->NewString( rgszNames[i], wcslen(rgszNames[i]) );
			a[i] = s;
		}
	}

	LockedArray<jint> r(pEnv, com4jJDispatch_getDISPIDs( pEnv, jdispatch, strings ));
	for( int i=0; i<(int)cNames; i++ ) {
		*rgDispId++ = r[i];
		if(r[i]==DISPID_UNKNOWN)
			unknown = true;
	}

	return unknown? DISP_E_UNKNOWNNAME : S_OK;
}

STDMETHODIMP CJDispatch::Invoke( DISPID dispid, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS* pDispParams, VARIANT* pResult, EXCEPINFO* pExcepInfo, UINT* puArgErr ) {
	AttachThread jniScope(jniModule);
	JNIEnv* pEnv = jniScope;
	
	jobjectArray ar = pEnv->NewObjectArray(pDispParams->cArgs,com4j_Variant,NULL);

	{// copy arguments into com4j Variant types, since we may later change their types
		LockedArray<jobject> data(pEnv,ar);
		int len = pDispParams->cArgs;
		for( int i=0; i<len; i++ ) {
			data[len-i-1] = com4j_Variant_new(pEnv);
			::VariantCopy(com4jVariantToVARIANT(pEnv,data[len-i-1]), &pDispParams->rgvarg[i]);
		}
	}

	jobject r = com4jJDispatch_invoke(pEnv,jdispatch, (jint)dispid,(jint)wFlags,ar);
	
	// check if there was any exception
	jthrowable t = pEnv->ExceptionOccurred();
	if(t!=NULL) {
		pEnv->ExceptionClear();
		if(pExcepInfo!=NULL) {
			pExcepInfo->wCode = 1000;	// Java doesn't have any notion of 'error code'
			pExcepInfo->wReserved = 0;
			pExcepInfo->bstrSource		= SysAllocString(JString(pEnv,com4jJDispatch_getErrorSource(pEnv,t)));
			pExcepInfo->bstrDescription = SysAllocString(JString(pEnv,com4jJDispatch_getErrorDetail(pEnv,t)));
			pExcepInfo->bstrHelpFile = NULL;
			pExcepInfo->dwHelpContext = 0;
			pExcepInfo->pvReserved = NULL;
			pExcepInfo->pfnDeferredFillIn = NULL;
			pExcepInfo->scode = 0;
		}

		return DISP_E_EXCEPTION;
	}

	if(r!=NULL && pResult!=NULL) {
		VARIANT* pSrc = convertToVariant(pEnv,r);
		::VariantCopy(pResult,pSrc);
		::VariantClear(pSrc);
	}

	return S_OK;
}
