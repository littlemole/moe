#ifndef _MOL_DEF_GUARD_JAVA_VARIANT2JAVA_DEF_GUARD_DEFINE_
#define _MOL_DEF_GUARD_JAVA_VARIANT2JAVA_DEF_GUARD_DEFINE_

#include "java/jmarshaler.h"
#include "java/javaobject.h"

namespace mol {
namespace java {
namespace impl {

template<class T>
jobject new_java_object( JavaClassStore& classes, const char* clazz, const char* name, const char* sig, T t)
{
		JNIEnv* env = classes.env();
		jclass javaClazz = classes[clazz];
		
		jmethodID cid = env->GetMethodID( javaClazz, name, sig );
		jobject obj = env->NewObject( javaClazz, cid, t );
		if (mol::java::exceptionOccured(env))
			return 0;
		return obj;
		
}

template<class I>
jobject javaVariant2java( JavaClassStore& classes, VARIANT& var )
{
		mol::punk<I> iface;
		HRESULT hr =  var.punkVal->QueryInterface( mol::uuidof<I>(), (void**)&iface );
		if (hr == S_OK && iface )
		{
			long* ptr = 0;
			HRESULT hr = iface->RawPtr(&ptr);
			if ( hr == S_OK )
			{
				jobject o = (jobject)ptr;
				return o;
			}
		}
		return 0;
}



template<VARTYPE VT, class T>
jobject variantArray2JavaArray(JavaClassStore& classes, VARIANT& var)
{
		JNIEnv* env = classes.env();
		jclass ObjectClazz = classes["java/lang/Object"];

		mol::SafeArray<VT> sa(var.parray);
		mol::SFAccess<T> sfa(sa);

		jobjectArray jar = env->NewObjectArray( sfa.size(), ObjectClazz, NULL );

		for ( int i = 0; i < sfa.size(); i++ )
		{
			mol::variant v(sfa[i]);
			jobject o = JavaMarshaler::variant2JavaObject(classes,v);
			env->SetObjectArrayElement( jar, i, o );
			if (mol::java::exceptionOccured(env))
				return 0;
		}
		return jar;
};



template<VARTYPE T>
class Variant2JavaObject
{
};



template<>
class Variant2JavaObject<VT_BSTR>
{
public:

	static jobject marshal( JavaClassStore& classes, VARIANT& var )
	{
		JNIEnv* env = classes.env();

		jstring s = env->NewString( (const jchar*) var.bstrVal, ::SysStringLen(var.bstrVal) );
		if (mol::java::exceptionOccured(env))
			return 0;
		return s;
	}
};


template<>
class Variant2JavaObject<VT_BOOL>
{
public:

	static jobject marshal( JavaClassStore& classes, VARIANT& var )
	{
		JNIEnv* env = classes.env();
		jboolean b = var.boolVal == VARIANT_TRUE;
		return new_java_object( classes, "java/lang/Boolean", "<init>", "(Z)V", b );
	}
};


template<>
class Variant2JavaObject<VT_I4>
{
public:

	static jobject marshal( JavaClassStore& classes, VARIANT& var )
	{
		JNIEnv* env = classes.env();
		return new_java_object( classes, "java/lang/Integer", "<init>", "(I)V", (jint) var.lVal );
	}
};

template<>
class Variant2JavaObject<VT_UNKNOWN>
{
public:

	static jobject marshal( JavaClassStore& classes, VARIANT& var )
	{
		jobject ret = javaVariant2java<IJavaClass>(classes,var);
		if ( ret != 0 )
			return ret;

		ret = javaVariant2java<IJavaObject>(classes,var);
		if ( ret != 0 )
			return ret;

		ret = javaVariant2java<ISwingObject>(classes,var);
		if ( ret != 0 )
			return ret;

		IDispatch* disp = 0;
		HRESULT hr = var.punkVal->QueryInterface( IID_IDispatch, (void**)&disp );
		if ( hr == S_OK && disp )
		{
			return new_java_object( 
						classes, 
						"org/oha7/dispdriver/impl/RawComPtr", 
						"<init>", 
						"(J)V", 
						(jlong) disp 
					);
		}
		return 0;
	}
};


template<>
class Variant2JavaObject<VT_ARRAY|VT_VARIANT>
{
public:

	static jobject marshal( JavaClassStore& classes, VARIANT& var )
	{
		return variantArray2JavaArray<VT_VARIANT,VARIANT>(classes,var);
	}
};

template<>
class Variant2JavaObject<VT_ARRAY|VT_DISPATCH>
{
public:

	static jobject marshal( JavaClassStore& classes, VARIANT& var )
	{
		return variantArray2JavaArray<VT_DISPATCH,IDispatch*>(classes,var);
	}
};


template<>
class Variant2JavaObject<VT_ARRAY|VT_UNKNOWN>
{
public:

	static jobject marshal( JavaClassStore& classes, VARIANT& var )
	{
		return variantArray2JavaArray<VT_UNKNOWN,IUnknown*>(classes,var);
	}
};

template<>
class Variant2JavaObject<VT_ARRAY|VT_BSTR>
{
public:

	static jobject marshal( JavaClassStore& classes, VARIANT& var )
	{
		return variantArray2JavaArray<VT_BSTR,BSTR*>(classes,var);
	}
};


template<>
class Variant2JavaObject<VT_ARRAY|VT_I4>
{
public:

	static jobject marshal( JavaClassStore& classes, VARIANT& var )
	{
		return variantArray2JavaArray<VT_I4,int*>(classes,var);
	}
};

template<>
class Variant2JavaObject<VT_ARRAY|VT_BOOL>
{
public:

	static jobject marshal( JavaClassStore& classes, VARIANT& var )
	{
		return variantArray2JavaArray<VT_BOOL,VARIANT_BOOL>(classes,var);
	}
};

} // end namespace impl
} // end namespace java
} // end namespace mol

#endif
