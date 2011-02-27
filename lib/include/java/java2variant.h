#ifndef _MOL_DEF_GUARD_JAVA_JAVA2VARIANT_DEF_GUARD_DEFINE_
#define _MOL_DEF_GUARD_JAVA_JAVA2VARIANT_DEF_GUARD_DEFINE_

#include "java/jglue.h"
#include "ole/variant.h"

////////////////////////////////////////////////////////////////////////

EXTERN_C const  CLSID CLSID_JavaClass;

namespace mol {
namespace java {
namespace impl {


////////////////////////////////////////////////////////////////////////

VARTYPE getVarType( JavaClassStore& classes, jobject clazz );

////////////////////////////////////////////////////////////////////////

jboolean isJavaArray( JNIEnv* env,jobject obj);
mol::variant javaArray2Variant(  JavaClassStore& classes, jobject obj );

////////////////////////////////////////////////////////////////////////

void wrapJavaObject( jobject obj, void ** ppv );
void wrapJavaClass( jclass clazz, void ** ppv );

////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////

template<VARTYPE VT>
class Java2Variant
{
};


template<>
class Java2Variant<VT_I4|VT_ARRAY>
{
public:

	static mol::ole::SafeArrayBase* marshal( JavaClassStore& classes,  jint len, jobjectArray joa )
	{
		JNIEnv* env = classes.env();

		jclass intClazz = classes["java/lang/Integer"];
		jmethodID mid = env->GetMethodID( intClazz, "intValue", "()I" );

		SAFEARRAYBOUND sb = { len, 0 };
		
		mol::ole::SafeArrayBase* sab = new mol::SafeArray<VT_I4>(sb);
		mol::SFAccess<int> sfa(*sab);

		for ( jsize j = 0; j < len; j++ )
		{
			jobject jae = env->GetObjectArrayElement( joa, j );
			jint value = env->CallIntMethod( jae, mid );
			if (mol::java::exceptionOccured(env))
			{
				return 0;
			}
			sfa[j] = value;
		}
		return sab;
	}

};

template<>
class Java2Variant<VT_BSTR|VT_ARRAY>
{
public:

	static mol::ole::SafeArrayBase* marshal( JavaClassStore& classes,  jint len, jobjectArray joa )
	{
		JNIEnv* env = classes.env();

		SAFEARRAYBOUND sb = { len, 0 };
		
		mol::ole::SafeArrayBase* sab = new mol::SafeArray<VT_BSTR>(sb);
		mol::SFAccess<BSTR> sfa(*sab);

		for ( jsize j = 0; j < len; j++ )
		{
			jobject jae = env->GetObjectArrayElement( joa, j );
			if (mol::java::exceptionOccured(env))
			{
				return 0;
			}
			
			OleStr str(env,(jstring)jae);
			sfa[j] = ::SysAllocString( str.c_str() );
		}
		return sab;
	}
};

template<>
class Java2Variant<VT_BOOL|VT_ARRAY>
{
public:

	static mol::ole::SafeArrayBase* marshal( JavaClassStore& classes,  jint len, jobjectArray joa )
	{
		JNIEnv* env = classes.env();

		jclass booleanClazz = classes["java/lang/Boolean"];
		jmethodID mid = env->GetMethodID( booleanClazz, "booleanValue", "()Z" );

		SAFEARRAYBOUND sb = { len, 0 };
		
		mol::ole::SafeArrayBase* sab = new mol::SafeArray<VT_BOOL>(sb);
		mol::SFAccess<VARIANT_BOOL> sfa(*sab);

		for ( jsize j = 0; j < len; j++ )
		{
			jobject jae = env->GetObjectArrayElement( joa, j );
			jboolean value = env->CallBooleanMethod( jae, mid );
			if (mol::java::exceptionOccured(env))
			{
				return 0;
			}
			sfa[j] = value;
		}
		return sab;
	}
};

template<>
class Java2Variant<VT_UNKNOWN|VT_ARRAY>
{
public:

	static mol::ole::SafeArrayBase* marshal( JavaClassStore& classes,  jint len, jobjectArray joa )
	{
		JNIEnv* env = classes.env();

		jclass RawComPtrClazz = classes["org/oha7/dispdriver/impl/RawComPtr"];
		jmethodID mid = env->GetMethodID( RawComPtrClazz, "longValue", "()J" );

		SAFEARRAYBOUND sb = { len, 0 };
		
		mol::ole::SafeArrayBase* sab = new mol::SafeArray<VT_UNKNOWN>(sb);
		mol::SFAccess<IUnknown*> sfa(*sab);

		for ( jsize j = 0; j < len; j++ )
		{
			jobject jae = env->GetObjectArrayElement( joa, j );
			jlong value = env->CallLongMethod( jae, mid );
			if (mol::java::exceptionOccured(env))
			{
				return 0;
			}
			sfa[j] = (IDispatch*)value;
		}
		return sab;
	}
};

template<>
class Java2Variant<VT_DISPATCH|VT_ARRAY>
{
public:

	static mol::ole::SafeArrayBase* marshal( JavaClassStore& classes,  jint len, jobjectArray joa )
	{
		JNIEnv* env = classes.env();

		jclass RawComPtrClazz = classes["org/oha7/dispdriver/impl/RawComPtr"];
		jmethodID mid = env->GetMethodID( RawComPtrClazz, "longValue", "()J" );

		SAFEARRAYBOUND sb = { len, 0 };
		
		mol::ole::SafeArrayBase* sab = new mol::SafeArray<VT_DISPATCH>(sb);
		mol::SFAccess<IDispatch*> sfa(*sab);

		for ( jsize j = 0; j < len; j++ )
		{
			jobject jae = env->GetObjectArrayElement( joa, j );

			wrapJavaObject(jae, (void**) &( sfa[j]) );
		}
		return sab;
	}
};


template<>
class Java2Variant<VT_VARIANT|VT_ARRAY>
{
public:

	static mol::ole::SafeArrayBase* marshal( JavaClassStore& classes,  jint len, jobjectArray joa )
	{
		JNIEnv* env = classes.env();

		SAFEARRAYBOUND sb = { len, 0 };
		
		mol::ole::SafeArrayBase* sab = new mol::SafeArray<VT_VARIANT>(sb);
		mol::SFAccess<VARIANT> sfa(*sab);

		for ( jsize j = 0; j < len; j++ )
		{
			jobject jae = env->GetObjectArrayElement( joa, j );

			mol::variant v;
			wrapJavaObject(jae, (void**) &(v.pdispVal) );

			::VariantCopy( &(sfa[j]), &v );
		}
		return sab;
	}
};





template<>
class Java2Variant<VT_BSTR>
{
public:

	static mol::variant marshall(JavaClassStore& classes, jobject obj )
	{
		OleStr str(classes.env(),(jstring)obj);
		mol::variant varRet( str.c_str() );
		return varRet;
	}
};


template<>
class Java2Variant<VT_I4>
{
public:

	static mol::variant marshall(JavaClassStore& classes, jobject obj )
	{
		mol::variant varRet;
		JNIEnv* env = classes.env();
		jclass intClazz = classes["java/lang/Integer"];
		jmethodID mid = env->GetMethodID( intClazz, "intValue", "()I" );
		jint value = env->CallIntMethod( obj, mid );
		if (mol::java::exceptionOccured(env))
		{
			varRet.vt = VT_ERROR;
			return varRet;
		}
		varRet.vt = VT_I4;
		varRet.lVal = value;
		return varRet;
	}
};


template<>
class Java2Variant<VT_BOOL>
{
public:

	static mol::variant marshall(JavaClassStore& classes, jobject obj )
	{
		mol::variant varRet;
		JNIEnv* env = classes.env();
		jclass booleanClazz =classes["java/lang/Boolean"];
		jmethodID mid = env->GetMethodID( booleanClazz, "booleanValue", "()Z" );
		jboolean value = env->CallBooleanMethod( obj, mid );
		if (mol::java::exceptionOccured(env))
		{
			varRet.vt = VT_ERROR;
			return varRet;
		}
		varRet.vt = VT_BOOL;
		varRet.lVal = value ? VARIANT_TRUE : VARIANT_FALSE;
		return varRet;
	}
};


template<>
class Java2Variant<VT_UNKNOWN>
{
public:

	static mol::variant marshall(JavaClassStore& classes, jobject obj )
	{
		mol::variant varRet;
		JNIEnv* env = classes.env();

		jclass RawComPtrClazz = classes["org/oha7/dispdriver/impl/RawComPtr"];
		jmethodID mid = env->GetMethodID( RawComPtrClazz, "longValue", "()J" );
		jlong value = env->CallLongMethod( obj, mid );
		if (mol::java::exceptionOccured(env))
		{
			varRet.vt = VT_ERROR;
			return varRet;
		}
		varRet.vt = VT_DISPATCH;
		varRet.pdispVal = (IDispatch*)value;
		return varRet;
	}
};

} // end namespace impl
} // end namespace java
} // end namespace mol


#endif