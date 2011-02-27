// dispdriver.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#include "org_oha7_dispdriver_impl_Native.h"

#include "ole/punk.h"
#include "ole/variant.h"

#include "java/jglue.h"
#include "java/jmarshaler.h"
#include "win/tls.h"


class IsCoInitialized
{
public:
	IsCoInitialized() : initialized(false) {}

	bool initialized;
};


void CoInitializeIf()
{
	IsCoInitialized& isCoInitialized = mol::tls<IsCoInitialized>().get();

	if ( isCoInitialized.initialized == false )
	{
		::CoInitializeEx(0,COINIT_MULTITHREADED);
		isCoInitialized.initialized = true;
	}
}

/*
 * Class:     org_oha7_dispdriver_impl_Native
 * Method:    QueryInterface
 * Signature: (JLjava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_org_oha7_dispdriver_impl_Native_QueryInterface
  (JNIEnv * env, jclass, jlong ptr, jstring iid)
{
	CoInitializeIf();
	IDispatch* disp = (IDispatch*)ptr;

	mol::java::OleStr str( env,iid );

	IID id;
	HRESULT hr = ::IIDFromString( str.c_str(), &id);
	if ( hr != S_OK )
	{
		return 0;
	}

	void* pv = 0;
	hr = disp->QueryInterface( id, &pv );
	if ( hr != S_OK || pv == 0)
	{
		return 0;
	}

	return (jlong)pv;
}

/*
 * Class:     org_oha7_dispdriver_impl_Native
 * Method:    Addref
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_oha7_dispdriver_impl_Native_Addref
  (JNIEnv *, jclass, jlong ptr)
{
	CoInitializeIf();
	IDispatch* disp = (IDispatch*)ptr;
	disp->AddRef();
}
/*
 * Class:     org_oha7_dispdriver_impl_Native
 * Method:    Release
 * Signature: (J)V
 */


JNIEXPORT void JNICALL Java_org_oha7_dispdriver_impl_Native_Release
  (JNIEnv *, jclass, jlong ptr)
{
	CoInitializeIf();
	IDispatch* disp = (IDispatch*)ptr;
	disp->Release();
}

/*
 * Class:     org_oha7_dispdriver_impl_Native
 * Method:    CreateObject
 * Signature: (Ljava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_org_oha7_dispdriver_impl_Native_CreateObject
  (JNIEnv * env, jclass clazz, jstring str)
{
	CoInitializeIf();
	mol::java::OleStr s( env,str );

	CLSID clsid;
	HRESULT hr = ::CLSIDFromProgID( s.c_str(), &clsid );
	if ( hr != S_OK )
	{
		return 0;
	}

	IUnknown* unk = 0;
	hr = ::CoCreateInstance( clsid, 0, CLSCTX_ALL, IID_IUnknown, (void**)&unk );
	if ( hr != S_OK || unk == 0)
	{
		return 0;
	}

	void * disp = 0;
	hr = unk->QueryInterface( IID_IDispatch,&disp );
	unk->Release();
	if ( hr != S_OK || disp == 0)
	{
		return 0;
	}
	return (jlong)disp;
}

/*
 * Class:     org_oha7_dispdriver_impl_Native
 * Method:    Invoke
 * Signature: (JI[Ljava/lang/Class;[Ljava/lang/Object;)Ljava/lang/Object;
 */

JNIEXPORT jobject JNICALL Java_org_oha7_dispdriver_impl_Native_Invoke
  (JNIEnv * env, jclass clazz, jlong ptr, jint dispid, jobjectArray argTypes, jobjectArray args, jint flags)
{
	CoInitializeIf();
	IDispatch* disp = (IDispatch*)ptr;

	jsize n = 0;
	if ( args )
	{
		n = env->GetArrayLength(args);
	}

	mol::java::JavaClassStore classes(env);
	DISPPARAMS* dispParams = mol::java::JavaMarshaler::javaArray2DispArgs( classes, args, flags );

	mol::variant varResult;
	HRESULT hr = disp->Invoke( dispid, IID_NULL,0, (WORD)flags, dispParams, &varResult, 0, 0 );

	for ( jsize i = 0 ; i < n; i++ )
	{
		::VariantClear( &(dispParams->rgvarg[i]) );
	}
	
	delete dispParams->rgvarg;
	delete dispParams;


	if ( flags == DISPATCH_PROPERTYPUT || varResult.vt == VT_EMPTY )
	{
		return 0;
	}

	jobject r = mol::java::JavaMarshaler::variant2JavaObject( classes, varResult );
	return r;
}

/*
 * Class:     org_oha7_dispdriver_impl_Native
 * Method:    CoIninitalize
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_org_oha7_dispdriver_impl_Native_CoIninitalize
  (JNIEnv *, jclass)
{
	CoInitializeIf();
}

/*
 * Class:     org_oha7_dispdriver_impl_Native
 * Method:    CoUnIninitalize
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_org_oha7_dispdriver_impl_Native_CoUnIninitalize
  (JNIEnv *, jclass)

{
	::CoUninitialize();
}


/*
 * Class:     org_oha7_dispdriver_impl_Native
 * Method:    RetrieveBstr
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_oha7_dispdriver_impl_Native_RetrieveBstr
  (JNIEnv *env, jclass, jlong ptr)
{
	CoInitializeIf();

	if ( ptr == 0 )
	{
		jstring s = env->NewString( (const jchar*) "", 0 );
		return s;
	}

	BSTR bstr = (BSTR)ptr;
	jstring s = env->NewString( (const jchar*) bstr, ::SysStringLen(bstr) );
	return s;
}

/*
 * Class:     org_oha7_dispdriver_impl_Native
 * Method:    GetObject
 * Signature: (Ljava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_org_oha7_dispdriver_impl_Native_GetObject (JNIEnv * env, jclass clazz, jstring str)
{
	CoInitializeIf();
	mol::java::OleStr s( env,str );

	CLSID clsid;
	HRESULT hr = ::CLSIDFromProgID( s.c_str(), &clsid );
	if ( hr != S_OK )
	{
		return 0;
	}

	IUnknown* unk = 0;
	hr = ::GetActiveObject( clsid,0,&unk );
	if ( hr != S_OK || unk == 0)
	{
		return 0;
	}

	void * disp = 0;
	hr = unk->QueryInterface( IID_IDispatch,&disp );
	unk->Release();
	if ( hr != S_OK || disp == 0)
	{
		return 0;
	}
	return (jlong)disp;
}

