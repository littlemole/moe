#include "stdafx.h"
#include "java/jmarshaler.h"
#include "java/java2variant.h"
#include "java/variant2java.h"

namespace mol {
namespace java {

jobject JavaMarshaler::variant2JavaObject( JavaClassStore& classes, VARIANT& var )
{
	if ( var.vt == VT_EMPTY )
	{
		return 0;
	}

	switch( var.vt )
	{
		case VT_EMPTY		:  return NULL;
		case VT_NULL		:  return NULL;
		case VT_I4			:  return impl::Variant2JavaObject<VT_I4>::marshal(classes,var);
		case VT_BSTR		:  return impl::Variant2JavaObject<VT_BSTR>::marshal(classes,var);
		case VT_BOOL		:  return impl::Variant2JavaObject<VT_BOOL>::marshal(classes,var);
		case VT_DISPATCH	:  return impl::Variant2JavaObject<VT_UNKNOWN>::marshal(classes,var);
		case VT_UNKNOWN		:  return impl::Variant2JavaObject<VT_UNKNOWN>::marshal(classes,var);
		
		case VT_ARRAY|VT_BOOL     : return impl::Variant2JavaObject<VT_ARRAY|VT_BOOL>::marshal(classes,var);
		case VT_ARRAY|VT_BSTR     : return impl::Variant2JavaObject<VT_ARRAY|VT_BSTR>::marshal(classes,var);
		case VT_ARRAY|VT_I4       : return impl::Variant2JavaObject<VT_ARRAY|VT_I4>::marshal(classes,var);
		case VT_ARRAY|VT_VARIANT  : return impl::Variant2JavaObject<VT_ARRAY|VT_VARIANT>::marshal(classes,var);
		case VT_ARRAY|VT_DISPATCH : return impl::Variant2JavaObject<VT_ARRAY|VT_DISPATCH>::marshal(classes,var);
		case VT_ARRAY|VT_UNKNOWN  : return impl::Variant2JavaObject<VT_ARRAY|VT_DISPATCH>::marshal(classes,var);
		default : return NULL;
	}
}


mol::variant JavaMarshaler::javaObject2Variant( JavaClassStore& classes, jobject obj )
{
	JNIEnv* env = classes.env();

	mol::variant varRet;

	varRet.vt = VT_NULL;
	if ( obj == NULL )
	{		
		return varRet;
	}

	jboolean isArray = impl::isJavaArray(env,obj);
	if ( isArray != 0 )
	{
		varRet = impl::javaArray2Variant(classes,obj);
		return varRet;
	}

	VARTYPE vt = impl::getVarType(classes, obj);
	switch ( vt )
	{
		case VT_BSTR :
		{
			varRet = impl::Java2Variant<VT_BSTR>::marshall(classes,obj);
			return varRet;
		}
		case VT_I4 :
		{
			varRet =  impl::Java2Variant<VT_I4>::marshall(classes,obj);
			return varRet;
		}
		case VT_BOOL :
		{
			varRet = impl::Java2Variant<VT_BOOL>::marshall(classes,obj);
			return varRet;
		}
		case VT_UNKNOWN :
		{
			varRet = impl::Java2Variant<VT_UNKNOWN>::marshall(classes,obj);
			return varRet;
		}
		case VT_EMPTY :
		{
			return varRet;
		}
		case VT_NULL:
		{
			return varRet;
		}
	}

	if ( obj != 0 )
	{
		varRet.vt = VT_DISPATCH;
		jclass clazz = classes["java/lang/Class"];
		if ( env->IsInstanceOf( obj, clazz ) )
		{
			impl::wrapJavaClass( (jclass)obj, (void**) &(varRet.pdispVal) );
		}
		else 
		{
			impl::wrapJavaObject( obj, (void**) &(varRet.pdispVal) );
		}

	}
	return varRet;
}


//////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////


jobjectArray JavaMarshaler::dispArgs2JavaArray( JavaClassStore& classes, DISPPARAMS *pDisp, UINT dec  )
{
	JNIEnv* env = classes.env();
	jclass objectClazz = classes["java/lang/Object"];

	jobjectArray jar = env->NewObjectArray( pDisp->cArgs-dec, objectClazz, NULL );
	if (java::exceptionOccured(env))
	{
		return 0;
	}
	for ( UINT i = 0; i < pDisp->cArgs-dec; i++ )
	{
		jobject o = JavaMarshaler::variant2JavaObject(classes, pDisp->rgvarg[i]);
		env->SetObjectArrayElement( jar, i, o );
		if (exceptionOccured(env))
		{
			return 0;
		}
		env->DeleteLocalRef(o);
	}
	return jar;
}



///////////////////////////////////////////


DISPPARAMS* JavaMarshaler::javaArray2DispArgs(JavaClassStore& classes, jobjectArray args, jint flags, UINT dec  )
{
	static DISPID dispidNamed = DISPID_PROPERTYPUT;

	JNIEnv* env = classes.env();

	jsize n = 0;
	if ( args )
	{
		n = env->GetArrayLength(args);
	}

	DISPPARAMS* dispParams = new DISPPARAMS;
	::ZeroMemory(dispParams,sizeof(DISPPARAMS));
	dispParams->cArgs = n;
	dispParams->cNamedArgs = 0;
	dispParams->rgdispidNamedArgs = 0;

	if ( flags == DISPATCH_PROPERTYPUT )
	{
		dispParams->cNamedArgs = 1;
		dispParams->rgdispidNamedArgs = &dispidNamed;
	}

	if ( args )
		dispParams->rgvarg = new VARIANTARG[n];

	for ( jsize i = 0; i < n; i++ )
	{
		jobject obj = env->GetObjectArrayElement( args, i );
		if (exceptionOccured(env))
		{
			return 0;
		}
		::VariantInit( &(dispParams->rgvarg[n-i-1]) );
		mol::variant v = JavaMarshaler::javaObject2Variant(classes,obj);
		::VariantCopy( &(dispParams->rgvarg[n-i-1]),&v );		
	}

	return dispParams;
}


} // end namespace java
} // end namespace mol

