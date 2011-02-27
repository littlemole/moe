// types.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "ole/aut.h"
#include "java/jre.h"
#include "java/javaobject.h"
#include "java/jmarshaler.h"
#include "java/dispdriver.h"

namespace mol {
namespace java {


void JavaObject::dispose()
{

}
	
HRESULT __stdcall JavaObject::GetTypeInfoCount (unsigned int FAR*  pctinfo ) 
{ 
    *pctinfo = 0;
    return S_OK; 
}

HRESULT __stdcall JavaObject::GetTypeInfo ( unsigned int  iTInfo, LCID  lcid, ITypeInfo FAR* FAR*  ppTInfo ) 
{ 
	*ppTInfo = 0;
    return E_NOTIMPL; 
}

HRESULT __stdcall JavaObject::Initialize(long* ptr)
{
	theJavaObject_ = (jobject)ptr;
	return S_OK;
}

HRESULT __stdcall JavaObject::RawPtr(long** ptr)
{
	if ( !ptr )
		return E_INVALIDARG;

	*ptr = (long*)theJavaObject_;
	return S_OK;
}

HRESULT __stdcall JavaObject::GetIDsOfNames( REFIID  riid, OLECHAR FAR* FAR*  rgszNames, unsigned int  cNames, LCID   lcid, DISPID FAR*  rgDispId ) 
{ 
	OLECHAR* name = rgszNames[0];
	std::string n = mol::tostring(name);

	DISPID id = (DISPID) mol::singleton<JavaNames>().getId(n);
	rgDispId[0] = id;
	return S_OK;
}

HRESULT  __stdcall JavaObject::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn, EXCEPINFO * ex, UINT * i) 
{ 
	std::string name = mol::singleton<JavaNames>().getName(dispIdMember);

	JNIEnv* env = java();
	JavaClassStore classes(env);

	jclass objectClazz = classes["java/lang/Object"];
	DispDriver dispDriver = classes["org/oha7/dispdriver/impl/DispDriver"];

	jobjectArray args = JavaMarshaler::dispArgs2JavaArray( classes, pDisp );

	if (  w == DISPATCH_PROPERTYGET ) 
	{
		jobject ret = dispDriver.propertyGet( theJavaObject_, name, args );
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
		dispDriver.propertyPut( theJavaObject_, name, args );
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

	jobject ret = dispDriver.invoke( theJavaObject_, name , args );
	if ( pReturn )
	{
		mol::variant v = JavaMarshaler::javaObject2Variant( classes,ret );
		if (mol::java::exceptionOccured(env))
			return S_FALSE;

		::VariantCopy( pReturn, &v );
	}

    return S_OK;
}

} // end namespace java
} // end namespace mol

