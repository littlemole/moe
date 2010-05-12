#include "stdafx.h"
#include "com4j.h"
#include "com4j_ActiveXControl.h"

JNIEXPORT void JNICALL Java_com4j_ActiveXControl_dispose0(JNIEnv* env, jobject pThis, jint nativePeer) {
	delete reinterpret_cast<CAxWindow*>(nativePeer);
}

JNIEXPORT jint JNICALL Java_com4j_ActiveXControl_initWindow(JNIEnv* env, jobject pThis, jint hWndParent, jstring clsid) {
	CAxWindow* wnd = new CAxWindow();
	wnd->Create( reinterpret_cast<HWND>(hWndParent), RECT(), "", WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN | WS_CLIPSIBLINGS);
	wnd->CreateControl(JString(env,clsid));

	return reinterpret_cast<int>(wnd);
}

JNIEXPORT jint JNICALL getControl(JNIEnv* env, jobject pThis, jint nativePeer) {
	IUnknown* pUnk = NULL;
	HRESULT hr = reinterpret_cast<CAxWindow*>(nativePeer)->QueryControl(&pUnk);
	if(FAILED(hr)) {
		error(env,__FILE__,__LINE__,hr,"Failed to get control interface");
		return 0;
	} else {
		return reinterpret_cast<jint>(pUnk);
	}
}
