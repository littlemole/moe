#include "java/java2variant.h"
#include "java/javaobject.h"

namespace mol {
namespace java {
namespace impl {

VARTYPE getVarType( JavaClassStore& classes, jobject clazz )
{
	jclass stringClazz    = classes["java/lang/String"];
	jclass intClazz       = classes["java/lang/Integer"];
	jclass booleanClazz   = classes["java/lang/Boolean"];
	jclass RawComPtrClazz = classes["org/oha7/dispdriver/impl/RawComPtr"];
	jclass ObjectClazz    = classes["java/lang/Object"];

	JNIEnv* env = classes.env();

	if ( clazz == 0 )
	{
		return VT_NULL;
	}

	if ( env->IsInstanceOf( clazz, intClazz ) ) 
	{
		return VT_I4;
	}
	if ( env->IsInstanceOf( clazz, stringClazz ) ) 
	{
		return VT_BSTR;
	}
	if ( env->IsInstanceOf( clazz, booleanClazz ) ) 
	{
		return VT_BOOL;
	}
	if ( env->IsInstanceOf( clazz, RawComPtrClazz ) ) 
	{
		return VT_UNKNOWN;
	}
	if ( env->IsSameObject( clazz, ObjectClazz ) ) 
	{
		return VT_VARIANT;
	}
	if ( env->IsInstanceOf( clazz, ObjectClazz ) ) 
	{
		return VT_DISPATCH;
	}
	return VT_EMPTY;
}

mol::variant javaArray2Variant(  JavaClassStore& classes, jobject obj )
{
	JNIEnv* env = classes.env();

	mol::ole::SafeArrayBase* sab = 0;
	mol::variant varRet;
	varRet.vt = VT_ERROR;

	jobjectArray joa = (jobjectArray)obj;
	jsize len = env->GetArrayLength( joa );

	if ( mol::java::exceptionOccured(env) )
			return varRet;

	jclass clazz = env->GetObjectClass(obj);
	jmethodID mid = env->GetMethodID( clazz, "getComponentType", "()Ljava/lang/Class;" );
	jobject arrayType = env->CallObjectMethod( obj, mid );
	if (mol::java::exceptionOccured(env))
		return varRet;

	varRet.vt = getVarType( classes, arrayType )|VT_ARRAY;
	switch ( varRet.vt )
	{
		case VT_I4|VT_ARRAY :
		{
			sab = Java2Variant<VT_I4|VT_ARRAY>::marshal(classes,len,joa);
			break;
		}
		case VT_BOOL|VT_ARRAY :
		{
			sab = Java2Variant<VT_BOOL|VT_ARRAY>::marshal(classes,len,joa);
			break;
		}
		case VT_BSTR|VT_ARRAY :
		{
			sab = Java2Variant<VT_BSTR|VT_ARRAY>::marshal(classes,len,joa);
			break;
		}
		case VT_UNKNOWN|VT_ARRAY :
		{
			sab = Java2Variant<VT_UNKNOWN|VT_ARRAY>::marshal(classes,len,joa);
			break;
		}
		case VT_DISPATCH|VT_ARRAY :
		{
			sab = Java2Variant<VT_DISPATCH|VT_ARRAY>::marshal(classes,len,joa);
			break;
		}
		case VT_VARIANT|VT_ARRAY :
		{
			sab = Java2Variant<VT_VARIANT|VT_ARRAY>::marshal(classes,len,joa);
			break;
		}
		case VT_NULL|VT_ARRAY :
		{
			varRet.vt = VT_NULL;
			varRet.pdispVal = 0;
			break;
		}
		default : 
		{
			varRet.vt = VT_ERROR;
			varRet.pdispVal = 0;
		}
	}

	if ( sab )
		::SafeArrayCopy( *sab, &varRet.parray );

	delete sab;

	return varRet;
}




void wrapJavaObject( jobject obj, IDispatch ** ppv )
{
	*ppv = 0;
	mol::punk<IJavaObject> instance;
	HRESULT hr = instance.createObject(CLSID_JavaObject,CLSCTX_ALL);
	if ( hr == S_OK )
	{
		hr = instance->Initialize((long*)obj);
		hr = instance.queryInterface( ppv );
	}
}

void wrapSwingObject( jobject obj, IDispatch ** ppv )
{
	*ppv = 0;
	mol::punk<ISwingObject> instance;
	HRESULT hr = instance.createObject(CLSID_SwingObject,CLSCTX_ALL);
	if ( hr == S_OK )
	{
		hr = instance->Initialize((long*)obj);
		hr = instance.queryInterface( ppv );
	}
}

void wrapJavaClass( jclass clazz, IDispatch ** ppv )
{
	*ppv = 0;
	mol::punk<IJavaClass> instance;
	HRESULT hr = instance.createObject(CLSID_JavaClass,CLSCTX_ALL);
	if ( hr == S_OK )
	{
		hr = instance->Initialize((long*)clazz);
		hr = instance.queryInterface( ppv );
	}
}


jboolean isJavaArray( JNIEnv* env,jobject obj)
{	
	jclass clazz = env->GetObjectClass(obj);
	jclass clazzClazz = env->GetObjectClass(clazz);
	jmethodID mid = env->GetMethodID( clazzClazz, "isArray", "()Z" );
	if ( !mol::java::exceptionOccured(env) )
	{
		jboolean isArray = env->CallBooleanMethod( clazz, mid );
		if ( !mol::java::exceptionOccured(env) )
		{
			if ( isArray != 0 )
			{
				return 1;
			}
		}

	}
	return 0;
}

} // end namespace impl
} // end namespace java
} // end namespace mol
