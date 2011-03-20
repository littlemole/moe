// types.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "ole/aut.h"
#include "java/jre.h"
#include "java/javaclass.h"
#include "java/jmarshaler.h"
#include "java/dispdriver.h"

EXTERN_C const  CLSID CLSID_SwingObject;

///////////////////////////////////////////////////////////

namespace mol {
namespace java {

void JavaClass::dispose()
{
	JNIEnv* env = java();
	env->DeleteGlobalRef((jobject)theJavaClass_);
}
	
HRESULT __stdcall JavaClass::GetTypeInfoCount (unsigned int FAR*  pctinfo ) 
{ 
    *pctinfo = 0;
    return S_OK; 
}

HRESULT __stdcall JavaClass::GetTypeInfo ( unsigned int  iTInfo, LCID  lcid, ITypeInfo FAR* FAR*  ppTInfo ) 
{ 
	*ppTInfo = 0;
    return E_NOTIMPL; 
}

HRESULT __stdcall JavaClass::Initialize(long* ptr)
{
	JNIEnv* env = java();
	jobject o = env->NewGlobalRef((jobject)ptr);
	theJavaClass_ = (jclass)o;
		
	return S_OK;
}

HRESULT __stdcall JavaClass::RawPtr(long** ptr)
{
	if ( !ptr )
		return E_INVALIDARG;

	*ptr = (long*)theJavaClass_;
	return S_OK;
}

HRESULT __stdcall JavaClass::GetIDsOfNames( REFIID  riid, OLECHAR FAR* FAR*  rgszNames, unsigned int  cNames, LCID   lcid, DISPID FAR*  rgDispId ) 
{ 
	OLECHAR* name = rgszNames[0];
	std::string n = mol::tostring(name);

	if ( n == "New" )
	{
		rgDispId[0] = 0;
		return S_OK;
	}


	if ( n == "Swing" )
	{
		rgDispId[0] = 3;
		return S_OK;
	}

	DISPID id = (DISPID) mol::singleton<JavaClassNames>().getId(n);
	rgDispId[0] = id;
	return S_OK;
}


HRESULT __stdcall JavaClass::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn, EXCEPINFO * ex, UINT * i) 
{ 
	JNIEnv* env = java();
	JavaClassStore classes(env);

	jclass objectClazz = classes["java/lang/Object"];
	DispDriver dispDriver = classes["org/oha7/dispdriver/impl/DispDriver"];

	jobjectArray args = JavaMarshaler::dispArgs2JavaArray( classes, pDisp );

	// create java obj via constructor
	if ( dispIdMember == 0 ) 
	{
		jobject obj = dispDriver.Create( theJavaClass_, args );
		if (mol::java::exceptionOccured(env))
			return S_FALSE;

		if ( obj == 0 )
		{
			mol::com_throw("could not create object",CLSID_JavaClass,"Java error");
			return S_FALSE;
		}

		if ( pReturn )
		{
			mol::variant v = JavaMarshaler::javaObject2Variant(classes,obj);
			if ( v.vt == VT_DISPATCH ) 
			{
				::CoAllowSetForegroundWindow( (IUnknown*)v.pdispVal, 0);
			}
			::VariantCopy( pReturn, &v );
		}
		return S_OK;
	}

	// create java swing obj via constructor
	if ( dispIdMember == 3 ) 
	{
		jobject obj = dispDriver.CreateSwing( theJavaClass_, args );
		if (mol::java::exceptionOccured(env))
			return S_FALSE;

		if ( obj == 0 )
		{
			mol::com_throw("could not create object",CLSID_JavaClass,"Java error");
			return S_FALSE;
		}

		if ( pReturn )
		{
			//mol::variant v = JavaMarshaler::javaObject2Variant(classes,obj);
	
			mol::punk<ISwingObject> instance;
			HRESULT hr = instance.createObject(CLSID_SwingObject,CLSCTX_ALL);
			if ( hr == S_OK )
			{
				hr = instance->Initialize((long*)obj);
				pReturn->vt = VT_DISPATCH;
				hr = instance.queryInterface( &(pReturn->pdispVal) );
				::CoAllowSetForegroundWindow( (IUnknown*)(pReturn->pdispVal), 0);
			}
		}
		return S_OK;
	}

	// invoke a static class method
	std::string name = mol::singleton<JavaClassNames>().getName(dispIdMember); //idsOfNames_[dispIdMember];

	if (  w == DISPATCH_PROPERTYGET ) 
	{
		jobject ret = dispDriver.propertyGet( theJavaClass_, name, args );
		if (mol::java::exceptionOccured(env))
			return S_FALSE;

		if ( pReturn )
		{
			mol::variant v = JavaMarshaler::javaObject2Variant(classes, ret );
			::VariantCopy( pReturn, &v );
		}

		return S_OK;
	}

	if (  w == DISPATCH_PROPERTYPUT ) 
	{
		dispDriver.propertyPut( theJavaClass_, name, args );
		if (mol::java::exceptionOccured(env))
			return S_FALSE;

		if ( pReturn )
		{
			mol::variant v;
			v.vt = VT_EMPTY;
			::VariantCopy( pReturn, &v );
		}

		return S_OK;
	}

	jobject ret = dispDriver.invoke( theJavaClass_,  name, args );
	if (mol::java::exceptionOccured(env))
		return S_FALSE;

	if ( pReturn )
	{
		mol::variant v = JavaMarshaler::javaObject2Variant(classes, ret );
		::VariantCopy( pReturn, &v );
	}

    return S_OK;
}

} // end namespace java
} // end namespace mol
