#include "stdafx.h"
#include "java/jglue.h"
#include "java/jre.h"
#include "java/jmarshaler.h"
#include "java/java.h"
#include "ole/ole.h"
#include "ole/com.h"
#include "ole/obj.h"
#include "ole/Bstr.h"
#include "ole/typeinfo.h"
#include "win/path.h"
#include "java/java.h"

EXTERN_C const  CLSID CLSID_JavaClass;

VARTYPE JavaMarshaller::getVarType( JavaClassStore& classes, jobject clazz )
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
			jobject o = JavaMarshaller::variant2JavaObject(classes,v);
			env->SetObjectArrayElement( jar, i, o );
			if (JRE::exceptionOccured(env))
				return 0;
		}
		return jar;
};


template<class T>
jobject new_java_object( JavaClassStore& classes, const char* clazz, const char* name, const char* sig, T t)
{
		JNIEnv* env = classes.env();
		jclass javaClazz = classes[clazz];

		
		jmethodID cid = env->GetMethodID( javaClazz, name, sig );
		jobject obj = env->NewObject( javaClazz, cid, t );
		if (JRE::exceptionOccured(env))
			return 0;
		return obj;
		
}


template<VARTYPE T>
class Variant2JavaObject
{
};



template<>
class Variant2JavaObject<VT_BSTR>
{
public:

	static jobject marshall( JavaClassStore& classes, VARIANT& var )
	{
		JNIEnv* env = classes.env();

		jstring s = env->NewString( (const jchar*) var.bstrVal, ::SysStringLen(var.bstrVal) );
		if (JRE::exceptionOccured(env))
			return 0;
		return s;
	}
};


template<>
class Variant2JavaObject<VT_BOOL>
{
public:

	static jobject marshall( JavaClassStore& classes, VARIANT& var )
	{
		JNIEnv* env = classes.env();
		//jclass booleanClazz = classes["java/lang/Boolean"];

		jboolean b = var.boolVal == VARIANT_TRUE;

		return new_java_object( classes, "java/lang/Boolean", "<init>", "(Z)V", b );

		/*
		jmethodID cid = env->GetMethodID( booleanClazz, "<init>", "(Z)V" );
		jobject i = env->NewObject(booleanClazz,cid, b );
		if (JRE::exceptionOccured())
			return 0;
		return i;
		*/
	}
};


template<>
class Variant2JavaObject<VT_I4>
{
public:

	static jobject marshall( JavaClassStore& classes, VARIANT& var )
	{
		JNIEnv* env = classes.env();

		return new_java_object( classes, "java/lang/Integer", "<init>", "(I)V", (jint) var.lVal );

		/*
		jclass intClazz = classes["java/lang/Integer"];

		jmethodID cid = env->GetMethodID( intClazz, "<init>", "(I)V" );
		jobject i = env->NewObject(intClazz,cid, (jint) var.lVal );
		if (JRE::exceptionOccured())
			return 0;
		return i;
		*/
	}
};

template<>
class Variant2JavaObject<VT_UNKNOWN>
{
public:

	static jobject marshall( JavaClassStore& classes, VARIANT& var )
	{
		jobject ret = javaVariant2java<IJavaClass>(classes,var);
		if ( ret != 0 )
			return ret;

		/*
		mol::punk<IJavaClass> javaClass;
		HRESULT hr =  var.punkVal->QueryInterface(IID_IJavaClass,(void**)&javaClass);
		if (hr == S_OK && javaClass )
		{
			long* ptr = 0;
			HRESULT hr = javaClass->RawPtr(&ptr);
			if ( hr == S_OK )
			{
				jclass c = (jclass)ptr;
				return c;
			}
		}
		*/
		
		ret = javaVariant2java<IJavaObject>(classes,var);
		if ( ret != 0 )
			return ret;

		/*
		mol::punk<IJavaObject> javaObject;
		hr =  var.punkVal->QueryInterface(IID_IJavaObject,(void**)&javaObject);
		if (hr == S_OK && javaObject )
		{
			long* ptr = 0;
			HRESULT hr = javaObject->RawPtr(&ptr);
			if ( hr == S_OK )
			{
				jobject i = (jobject)ptr;
				return i;
			}
		}
		*/

//		JNIEnv* env = java();

		IDispatch* disp = 0;
		HRESULT hr = var.punkVal->QueryInterface( IID_IDispatch, (void**)&disp );
		if ( hr == S_OK && disp )
		{
			return new_java_object( classes, "org/oha7/dispdriver/impl/RawComPtr", "<init>", "(J)V", (jlong) disp );

			/*
			jobject i = env->NewObject(RawComPtrClazz,cid, (jlong) disp);
			if (JRE::exceptionOccured())
				return 0;
			return i;
			*/
		}
		return 0;
	}
};


template<>
class Variant2JavaObject<VT_ARRAY|VT_VARIANT>
{
public:

	static jobject marshall( JavaClassStore& classes, VARIANT& var )
	{
		return variantArray2JavaArray<VT_VARIANT,VARIANT>(classes,var);
		/*
		JNIEnv* env = java();
		jclass ObjectClazz = classes["java/lang/Object"];

		mol::SafeArray<VT_VARIANT> sa(var.parray);
		mol::SFAccess<VARIANT> sfa(sa);

		jobjectArray jar = env->NewObjectArray( sfa.size(), ObjectClazz, NULL );

		for ( int i = 0; i < sfa.size(); i++ )
		{
			mol::variant v(sfa[i]);
			jobject o = JavaMarshaller::variant2JavaObject(classes,v);
			env->SetObjectArrayElement( jar, i, o );
			if (JRE::exceptionOccured())
				return 0;
		}
		return jar;
		*/
	}
};

template<>
class Variant2JavaObject<VT_ARRAY|VT_DISPATCH>
{
public:

	static jobject marshall( JavaClassStore& classes, VARIANT& var )
	{
		return variantArray2JavaArray<VT_DISPATCH,IDispatch*>(classes,var);
		/*
		JNIEnv* env = java();
		jclass ObjectClazz = classes["java/lang/Object"];

		mol::SafeArray<VT_DISPATCH> sa(var.parray);
		mol::SFAccess<IDispatch*> sfa(sa);

		jobjectArray jar = env->NewObjectArray( sfa.size(), ObjectClazz, NULL );

		for ( int i = 0; i < sfa.size(); i++ )
		{
			mol::variant v(sfa[i]);
			jobject o = JavaMarshaller::variant2JavaObject(classes,v);
			env->SetObjectArrayElement( jar, i, o );
			if (JRE::exceptionOccured())
				return 0;
		}
		return jar;
		*/
	}
};


template<>
class Variant2JavaObject<VT_ARRAY|VT_UNKNOWN>
{
public:

	static jobject marshall( JavaClassStore& classes, VARIANT& var )
	{
		return variantArray2JavaArray<VT_UNKNOWN,IUnknown*>(classes,var);

		/*
		JNIEnv* env = java();
		jclass ObjectClazz = classes["java/lang/Object"];

		mol::SafeArray<VT_UNKNOWN> sa(var.parray);
		mol::SFAccess<IUnknown*> sfa(sa);

		jobjectArray jar = env->NewObjectArray( sfa.size(), ObjectClazz, NULL );

		for ( int i = 0; i < sfa.size(); i++ )
		{
			mol::variant v(sfa[i]);
			jobject o = JavaMarshaller::variant2JavaObject(classes,v);
			env->SetObjectArrayElement( jar, i, o );
			if (JRE::exceptionOccured())
				return 0;
		}
		return jar;
		*/
	}
};

template<>
class Variant2JavaObject<VT_ARRAY|VT_BSTR>
{
public:

	static jobject marshall( JavaClassStore& classes, VARIANT& var )
	{
		return variantArray2JavaArray<VT_BSTR,BSTR*>(classes,var);

		/*
		JNIEnv* env = java();
		jclass ObjectClazz = classes["java/lang/Object"];

		mol::SafeArray<VT_BSTR> sa(var.parray);
		mol::SFAccess<BSTR*> sfa(sa);
			
		jobjectArray jar = env->NewObjectArray( sfa.size(), ObjectClazz,NULL );

		for ( int i = 0; i < sfa.size(); i++ )
		{
			mol::variant v(sfa[i]);
			jobject o = JavaMarshaller::variant2JavaObject(classes,v);
			env->SetObjectArrayElement( jar, i, o );
			if (JRE::exceptionOccured())
				return 0;
		}
		return jar;
		*/
	}
};


template<>
class Variant2JavaObject<VT_ARRAY|VT_I4>
{
public:

	static jobject marshall( JavaClassStore& classes, VARIANT& var )
	{
		return variantArray2JavaArray<VT_I4,int*>(classes,var);

		/*
		JNIEnv* env = java();
		jclass ObjectClazz = classes["java/lang/Object"];

		mol::SafeArray<VT_I4> sa(var.parray);
		mol::SFAccess<int*> sfa(sa);
			
		jobjectArray jar = env->NewObjectArray( sfa.size(), ObjectClazz,NULL );

		for ( int i = 0; i < sfa.size(); i++ )
		{
			mol::variant v(sfa[i]);
			jobject o = JavaMarshaller::variant2JavaObject(classes,v);
			env->SetObjectArrayElement( jar, i, o );
			if (JRE::exceptionOccured())
				return 0;
		}
		return jar;
		*/
	}
};

template<>
class Variant2JavaObject<VT_ARRAY|VT_BOOL>
{
public:

	static jobject marshall( JavaClassStore& classes, VARIANT& var )
	{
		return variantArray2JavaArray<VT_BOOL,VARIANT_BOOL>(classes,var);

		/*
		JNIEnv* env = java();
		jclass ObjectClazz = classes["java/lang/Object"];

		mol::SafeArray<VT_BOOL> sa(var.parray);
		mol::SFAccess<VARIANT_BOOL> sfa(sa);
			
		jobjectArray jar = env->NewObjectArray( sfa.size(), ObjectClazz,NULL );

		for ( int i = 0; i < sfa.size(); i++ )
		{
			mol::variant v(sfa[i]);
			jobject o = JavaMarshaller::variant2JavaObject(classes,v);
			env->SetObjectArrayElement( jar, i, o );
			if (JRE::exceptionOccured())
				return 0;
		}
		return jar;
		*/
	}
};

jobject JavaMarshaller::variant2JavaObject( JavaClassStore& classes, VARIANT& var )
{
	if ( var.vt == VT_EMPTY )
	{
		return 0;
	}
	JNIEnv* env = classes.env();

	jclass stringClazz = classes["java/lang/String"];
	jclass intClazz = classes["java/lang/Integer"];
	jclass booleanClazz = classes["java/lang/Boolean"];
	jclass RawComPtrClazz = classes["org/oha7/dispdriver/impl/RawComPtr"];
	jclass ObjectClazz = classes["java/lang/Object"];
	jclass ReflectArrayClazz = classes["java/lang/reflect/Array"];

	if ( var.vt == VT_EMPTY || var.vt == VT_NULL )
	{
		return NULL;
	}
	if ( var.vt == VT_BOOL )
	{
		return Variant2JavaObject<VT_BOOL>::marshall(classes,var);
		/*
		jboolean b = var.boolVal == VARIANT_TRUE;
		jmethodID cid = env->GetMethodID( booleanClazz, "<init>", "(Z)V" );
		jobject i = env->NewObject(booleanClazz,cid, b );
		if (JRE::exceptionOccured())
			return 0;
		return i;
		*/
	}
	if ( var.vt == VT_UNKNOWN )
	{
		return Variant2JavaObject<VT_UNKNOWN>::marshall(classes,var);
		/*
		mol::punk<IJavaClass> javaClass;
		HRESULT hr =  var.punkVal->QueryInterface(IID_IJavaClass,(void**)&javaClass);
		if (hr == S_OK && javaClass )
		{
			long* ptr = 0;
			HRESULT hr = javaClass->RawPtr(&ptr);
			if ( hr == S_OK )
			{
				jclass c = (jclass)ptr;
				return c;
			}
		}
		mol::punk<IJavaObject> javaObject;
		hr =  var.punkVal->QueryInterface(IID_IJavaObject,(void**)&javaObject);
		if (hr == S_OK && javaObject )
		{
			long* ptr = 0;
			HRESULT hr = javaObject->RawPtr(&ptr);
			if ( hr == S_OK )
			{
				jobject i = (jobject)ptr;
				return i;
			}
		}

		jmethodID cid = env->GetMethodID( RawComPtrClazz, "<init>", "(J)V" );
		IUnknown* unk = 0;
		hr = var.punkVal->QueryInterface( IID_IUnknown, (void**)&unk );
		if ( hr == S_OK && unk )
		{
			jobject i = env->NewObject(RawComPtrClazz,cid, (jlong) unk);
			if (JRE::exceptionOccured())
				return 0;
			return i;
		}
		return 0;
		*/
	}
	if ( var.vt == VT_DISPATCH )
	{
		return Variant2JavaObject<VT_UNKNOWN>::marshall(classes,var);
		/*
		mol::punk<IJavaClass> javaClass;
		HRESULT hr =  var.pdispVal->QueryInterface(IID_IJavaClass,(void**)&javaClass);
		if (hr == S_OK && javaClass )
		{
			long* ptr = 0;
			HRESULT hr = javaClass->RawPtr(&ptr);
			if ( hr == S_OK )
			{
				jclass c = (jclass)ptr;
				return c;
			}
		}
		mol::punk<IJavaObject> javaObject;
		hr =  var.pdispVal->QueryInterface(IID_IJavaObject,(void**)&javaObject);
		if (hr == S_OK && javaObject )
		{
			long* ptr = 0;
			HRESULT hr = javaObject->RawPtr(&ptr);
			if ( hr == S_OK )
			{
				jobject i = (jobject)ptr;
				return i;
			}
		}

		
		jmethodID cid = env->GetMethodID( RawComPtrClazz, "<init>", "(J)V" );
		IDispatch* disp = 0;
		hr = var.pdispVal->QueryInterface( IID_IDispatch, (void**)&disp );
		if ( hr == S_OK && disp ) {
			jobject i = env->NewObject(RawComPtrClazz,cid, (jlong) disp);
			if (JRE::exceptionOccured())
				return 0;
			return i;
		}

		return 0;
		*/
	}

	if ( var.vt == VT_BSTR )
	{
		return Variant2JavaObject<VT_BSTR>::marshall(classes,var);

		/*
		jstring s = env->NewString( (const jchar*) var.bstrVal, ::SysStringLen(var.bstrVal) );
		if (JRE::exceptionOccured())
			return 0;
		return s;
		*/
	}

	if ( var.vt == VT_I4 )
	{
		return Variant2JavaObject<VT_I4>::marshall(classes,var);

		/*
		jmethodID cid = env->GetMethodID( intClazz, "<init>", "(I)V" );
		jobject i = env->NewObject(intClazz,cid, (jint) var.lVal );
		if (JRE::exceptionOccured())
			return 0;
		return i;
		*/
	}
	if ( var.vt == (VT_ARRAY|VT_VARIANT) )
	{
		return Variant2JavaObject<VT_ARRAY|VT_VARIANT>::marshall(classes,var);

		/*
		mol::SafeArray<VT_VARIANT> sa(var.parray);
		mol::SFAccess<VARIANT> sfa(sa);

		jobjectArray jar = env->NewObjectArray( sfa.size(), ObjectClazz, NULL );

		for ( int i = 0; i < sfa.size(); i++ )
		{
			mol::variant v(sfa[i]);
			jobject o = JavaMarshaller::variant2JavaObject(classes,v);
			env->SetObjectArrayElement( jar, i, o );
			if (JRE::exceptionOccured())
				return 0;
		}
		return jar;
		*/
	}
	if ( var.vt == (VT_ARRAY|VT_DISPATCH) )
	{
		return Variant2JavaObject<VT_ARRAY|VT_DISPATCH>::marshall(classes,var);

		/*
		mol::SafeArray<VT_DISPATCH> sa(var.parray);
		mol::SFAccess<IDispatch*> sfa(sa);

		jobjectArray jar = env->NewObjectArray( sfa.size(), ObjectClazz, NULL );

		for ( int i = 0; i < sfa.size(); i++ )
		{
			mol::variant v(sfa[i]);
			jobject o = JavaMarshaller::variant2JavaObject(classes,v);
			env->SetObjectArrayElement( jar, i, o );
			if (JRE::exceptionOccured())
				return 0;
		}
		return jar;
		*/
	}
	if ( var.vt == (VT_ARRAY|VT_UNKNOWN) )
	{
		return Variant2JavaObject<VT_ARRAY|VT_DISPATCH>::marshall(classes,var);

		/*
		mol::SafeArray<VT_UNKNOWN> sa(var.parray);
		mol::SFAccess<IUnknown*> sfa(sa);

		jobjectArray jar = env->NewObjectArray( sfa.size(), ObjectClazz, NULL );

		for ( int i = 0; i < sfa.size(); i++ )
		{
			mol::variant v(sfa[i]);
			jobject o = JavaMarshaller::variant2JavaObject(classes,v);
			env->SetObjectArrayElement( jar, i, o );
			if (JRE::exceptionOccured())
				return 0;
		}
		return jar;
		*/
	}
	if ( var.vt == (VT_ARRAY|VT_BSTR) )
	{
		return Variant2JavaObject<VT_ARRAY|VT_BSTR>::marshall(classes,var);

		/*
		mol::SafeArray<VT_BSTR> sa(var.parray);
		mol::SFAccess<BSTR*> sfa(sa);
			
		jobjectArray jar = env->NewObjectArray( sfa.size(), ObjectClazz,NULL );

		for ( int i = 0; i < sfa.size(); i++ )
		{
			mol::variant v(sfa[i]);
			jobject o = JavaMarshaller::variant2JavaObject(classes,v);
			env->SetObjectArrayElement( jar, i, o );
			if (JRE::exceptionOccured())
				return 0;
		}
		return jar;
		*/
	}
	if ( var.vt == (VT_ARRAY|VT_I4) )
	{
		return Variant2JavaObject<VT_ARRAY|VT_I4>::marshall(classes,var);

		/*
		mol::SafeArray<VT_I4> sa(var.parray);
		mol::SFAccess<int*> sfa(sa);
			
		jobjectArray jar = env->NewObjectArray( sfa.size(), ObjectClazz,NULL );

		for ( int i = 0; i < sfa.size(); i++ )
		{
			mol::variant v(sfa[i]);
			jobject o = JavaMarshaller::variant2JavaObject(classes,v);
			env->SetObjectArrayElement( jar, i, o );
			if (JRE::exceptionOccured())
				return 0;
		}
		return jar;
		*/
	}
	if ( var.vt == (VT_ARRAY|VT_BOOL) )
	{
		return Variant2JavaObject<VT_ARRAY|VT_BOOL>::marshall(classes,var);

		/*
		mol::SafeArray<VT_BOOL> sa(var.parray);
		mol::SFAccess<VARIANT_BOOL> sfa(sa);
			
		jobjectArray jar = env->NewObjectArray( sfa.size(), ObjectClazz,NULL );

		for ( int i = 0; i < sfa.size(); i++ )
		{
			mol::variant v(sfa[i]);
			jobject o = JavaMarshaller::variant2JavaObject(classes,v);
			env->SetObjectArrayElement( jar, i, o );
			if (JRE::exceptionOccured())
				return 0;
		}
		return jar;
		*/
	}
	return 0;
}

///////////////////////////////////////////

void wrapJavaObject( jobject obj, void ** ppv )
{
	*ppv = 0;
	mol::punk<IJavaObject> instance;
	HRESULT hr = instance.createObject(CLSID_JavaObject,CLSCTX_ALL);
	if ( hr == S_OK )
	{
		hr = instance->Initialize((long*)obj);
		hr = instance->QueryInterface( IID_IDispatch, ppv );
	}
}


void wrapJavaClass( jclass clazz, void ** ppv )
{
	*ppv = 0;
	mol::punk<IJavaClass> instance;
	HRESULT hr = instance.createObject(CLSID_JavaClass,CLSCTX_ALL);
	if ( hr == S_OK )
	{
		hr = instance->Initialize((long*)clazz);
		hr = instance->QueryInterface( IID_IDispatch, ppv );
	}
}

template<VARTYPE VT>
class Java2Variant
{
};


template<>
class Java2Variant<VT_I4|VT_ARRAY>
{
public:

	static mol::ole::SafeArrayBase* marshall( JavaClassStore& classes,  jint len, jobjectArray joa )
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
			if (JRE::exceptionOccured(env))
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

	static mol::ole::SafeArrayBase* marshall( JavaClassStore& classes,  jint len, jobjectArray joa )
	{
		JNIEnv* env = classes.env();

		SAFEARRAYBOUND sb = { len, 0 };
		
		mol::ole::SafeArrayBase* sab = new mol::SafeArray<VT_BSTR>(sb);
		mol::SFAccess<BSTR> sfa(*sab);

		for ( jsize j = 0; j < len; j++ )
		{
			jobject jae = env->GetObjectArrayElement( joa, j );
			if (JRE::exceptionOccured(env))
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

	static mol::ole::SafeArrayBase* marshall( JavaClassStore& classes,  jint len, jobjectArray joa )
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
			if (JRE::exceptionOccured(env))
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

	static mol::ole::SafeArrayBase* marshall( JavaClassStore& classes,  jint len, jobjectArray joa )
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
			if (JRE::exceptionOccured(env))
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

	static mol::ole::SafeArrayBase* marshall( JavaClassStore& classes,  jint len, jobjectArray joa )
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
			/*
			mol::punk<IJavaObject> instance;
			HRESULT hr = instance.createObject(CLSID_JavaObject,CLSCTX_ALL);
			if ( hr == S_OK )
			{
				hr = instance->Initialize((long*)jae);
				hr = instance->QueryInterface( IID_IDispatch, (void**) &( sfa[j]) );
			}
			*/
		}
		return sab;
	}
};


template<>
class Java2Variant<VT_VARIANT|VT_ARRAY>
{
public:

	static mol::ole::SafeArrayBase* marshall( JavaClassStore& classes,  jint len, jobjectArray joa )
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

			/*
			mol::punk<IJavaObject> instance;
			HRESULT hr = instance.createObject(CLSID_JavaObject,CLSCTX_ALL);
			if ( hr == S_OK )
			{
				hr = instance->Initialize((long*)jae);
				hr = instance->QueryInterface( IID_IDispatch, (void**) &(v.pdispVal)  );
			}
			*/

			::VariantCopy( &(sfa[j]), &v );
		}
		return sab;
	}
};


mol::variant JavaMarshaller::javaArray2Variant(  JavaClassStore& classes, jobject obj )
{
	JNIEnv* env = classes.env();

	mol::ole::SafeArrayBase* sab = 0;
	mol::variant varRet;
	varRet.vt = VT_ERROR;

	jobjectArray joa = (jobjectArray)obj;
	jsize len = env->GetArrayLength( joa );

	if ( JRE::exceptionOccured(env) )
			return varRet;

	//SAFEARRAYBOUND sb = { len, 0 };

	jclass clazz = env->GetObjectClass(obj);
	jmethodID mid = env->GetMethodID( clazz, "getComponentType", "()Ljava/lang/Class;" );
	jobject arrayType = env->CallObjectMethod( obj, mid );
	if (JRE::exceptionOccured(env))
		return varRet;

	varRet.vt = getVarType( classes, arrayType )|VT_ARRAY;
	switch ( varRet.vt )
	{
		case VT_I4|VT_ARRAY :
		{
			sab = Java2Variant<VT_I4|VT_ARRAY>::marshall(classes,len,joa);
			/*
			mol::SFAccess<int> sfa(*sab);
			for ( jsize j = 0; j < len; j++ )
			{
				jobject jae = env->GetObjectArrayElement( joa, j );
				jint value = env->CallIntMethod( jae, mid );
				if (JRE::exceptionOccured())
				{
					varRet.vt = VT_ERROR;
					return varRet;
				}
				sfa[j] = value;
			}
			*/
			break;
		}
		case VT_BOOL|VT_ARRAY :
		{
			sab = Java2Variant<VT_BOOL|VT_ARRAY>::marshall(classes,len,joa);
			/*
			sab = new mol::SafeArray<VT_BOOL>(sb);
			mol::SFAccess<VARIANT_BOOL> sfa(*sab);
			for ( jsize j = 0; j < len; j++ )
			{
				jobject jae = env->GetObjectArrayElement( joa, j );
				jboolean value = env->CallBooleanMethod( jae, mid );
				if (JRE::exceptionOccured())
				{
					varRet.vt = VT_ERROR;
					return varRet;
				}
				sfa[j] = value;
			}
			*/
			break;
		}
		case VT_BSTR|VT_ARRAY :
		{
			sab = Java2Variant<VT_BSTR|VT_ARRAY>::marshall(classes,len,joa);
			/*
			sab = new mol::SafeArray<VT_BSTR>(sb);
			mol::SFAccess<BSTR> sfa(*sab);
			for ( jsize j = 0; j < len; j++ )
			{
				jobject jae = env->GetObjectArrayElement( joa, j );
				if (JRE::exceptionOccured())
				{
					varRet.vt = VT_ERROR;
					return varRet;
				}
				OleStr str((jstring)jae);
				sfa[j] = ::SysAllocString( str.c_str() );
			}
			*/
			break;
		}
		case VT_UNKNOWN|VT_ARRAY :
		{
			sab = Java2Variant<VT_UNKNOWN|VT_ARRAY>::marshall(classes,len,joa);
			/*
			jclass RawComPtrClazz = classes["org/oha7/dispdriver/impl/RawComPtr"];
			sab = new mol::SafeArray<VT_UNKNOWN>(sb);
			mol::SFAccess<IUnknown*> sfa(*sab);
			for ( jsize j = 0; j < len; j++ )
			{
				jobject jae = env->GetObjectArrayElement( joa, j );
				mid = env->GetMethodID( RawComPtrClazz, "longValue", "()J" );
				jlong value = env->CallLongMethod( jae, mid );
				if (JRE::exceptionOccured())
				{
					varRet.vt = VT_ERROR;
					return varRet;
				}
				sfa[0] = (IDispatch*)value;
			}
			*/
			break;
		}
		case VT_DISPATCH|VT_ARRAY :
		{
			sab = Java2Variant<VT_DISPATCH|VT_ARRAY>::marshall(classes,len,joa);
			/*
			sab = new mol::SafeArray<VT_DISPATCH>(sb);
			mol::SFAccess<IDispatch*> sfa(*sab);
			for ( jsize j = 0; j < len; j++ )
			{
				jobject jae = env->GetObjectArrayElement( joa, j );
				if (JRE::exceptionOccured())
				{
					varRet.vt = VT_ERROR;
					return varRet;
				}
				mol::punk<IJavaObject> instance;
				HRESULT hr = instance.createObject(CLSID_JavaObject,CLSCTX_ALL);
				if ( hr == S_OK )
				{
					hr = instance->Initialize((long*)jae);
					hr = instance->QueryInterface( IID_IDispatch, (void**) &( sfa[j]) );
				}
			}
			*/
			break;
		}
		case VT_VARIANT|VT_ARRAY :
		{
			sab = Java2Variant<VT_VARIANT|VT_ARRAY>::marshall(classes,len,joa);
			/*
			sab = new mol::SafeArray<VT_VARIANT>(sb);
			mol::SFAccess<VARIANT> sfa(*sab);
			for ( jsize j = 0; j < len; j++ )
			{
				jobject jae = env->GetObjectArrayElement( joa, j );
				if (JRE::exceptionOccured())
				{
					varRet.vt = VT_ERROR;
					return varRet;
				}
				mol::punk<IJavaObject> instance;
				mol::variant v;
				HRESULT hr = instance.createObject(CLSID_JavaObject,CLSCTX_ALL);
				if ( hr == S_OK )
				{
					hr = instance->Initialize((long*)jae);
					hr = instance->QueryInterface( IID_IDispatch, (void**) &(v.pdispVal)  );
				}

				::VariantCopy( &(sfa[j]), &v );
			}
			*/
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

jboolean isJavaArray( JNIEnv* env,jobject obj)
{	
	jclass clazz = env->GetObjectClass(obj);
	jclass clazzClazz = env->GetObjectClass(clazz);
	jmethodID mid = env->GetMethodID( clazzClazz, "isArray", "()Z" );
	if ( !JRE::exceptionOccured(env) )
	{
		jboolean isArray = env->CallBooleanMethod( clazz, mid );
		if ( !JRE::exceptionOccured(env) )
		{
			if ( isArray != 0 )
			{
				return 1;
			}
		}

	}
	return 0;
}
/*
template<VARTYPE VT>
class Java2Variant
{
};
*/

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
		if (JRE::exceptionOccured(env))
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
		if (JRE::exceptionOccured(env))
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
		if (JRE::exceptionOccured(env))
		{
			varRet.vt = VT_ERROR;
			return varRet;
		}
		varRet.vt = VT_DISPATCH;
		varRet.pdispVal = (IDispatch*)value;
		return varRet;
	}
};


mol::variant JavaMarshaller::javaObject2Variant( JavaClassStore& classes, jobject obj )
{
	JNIEnv* env = classes.env();

	mol::variant varRet;

	varRet.vt = VT_NULL;
	if ( obj == NULL )
	{		
		return varRet;
	}

	jboolean isArray = isJavaArray(env,obj);
	if ( isArray != 0 )
	{
		varRet = javaArray2Variant(classes,obj);
		return varRet;
	}

	VARTYPE vt = getVarType(classes, obj);
	switch ( vt )
	{
		case VT_BSTR :
		{
			varRet = Java2Variant<VT_BSTR>::marshall(classes,obj);
			return varRet;
			/*
			OleStr str((jstring)obj);
			varRet.bstrVal = ::SysAllocString( str.c_str() );
			return varRet;
			*/
		}
		case VT_I4 :
		{
			varRet =  Java2Variant<VT_I4>::marshall(classes,obj);
			return varRet;
			/*
			jclass intClazz = classes["java/lang/Integer"];
			jmethodID mid = env->GetMethodID( intClazz, "intValue", "()I" );
			jint value = env->CallIntMethod( obj, mid );
			if (JRE::exceptionOccured())
			{
				varRet.vt = VT_ERROR;
				return varRet;
			}
			varRet.lVal = value;
			return varRet;
			*/
		}
		case VT_BOOL :
		{
			varRet = Java2Variant<VT_BOOL>::marshall(classes,obj);
			return varRet;
			/*
			jclass booleanClazz =classes["java/lang/Boolean"];
			jmethodID mid = env->GetMethodID( booleanClazz, "booleanValue", "()Z" );
			jboolean value = env->CallBooleanMethod( obj, mid );
			if (JRE::exceptionOccured())
			{
				varRet.vt = VT_ERROR;
				return varRet;
			}
			varRet.lVal = value ? VARIANT_TRUE : VARIANT_FALSE;
			return varRet;
			*/
		}
		case VT_UNKNOWN :
		{
			varRet = Java2Variant<VT_UNKNOWN>::marshall(classes,obj);
			return varRet;
			/*
			jclass RawComPtrClazz = classes["org/oha7/dispdriver/impl/RawComPtr"];
			jmethodID mid = env->GetMethodID( RawComPtrClazz, "longValue", "()J" );
			jlong value = env->CallLongMethod( obj, mid );
			if (JRE::exceptionOccured())
			{
				varRet.vt = VT_ERROR;
				return varRet;
			}
			varRet.vt = VT_DISPATCH;
			varRet.pdispVal = (IDispatch*)value;
			return varRet;
			*/
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
			wrapJavaClass( (jclass)obj, (void**) &(varRet.pdispVal) );

			/*
			mol::punk<IJavaClass> instance;
			HRESULT hr = instance.createObject(CLSID_JavaClass,CLSCTX_ALL);
			if ( hr == S_OK )
			{
				hr = instance->Initialize((long*)obj);
				hr = instance->QueryInterface( IID_IDispatch, (void**) &(varRet.pdispVal));
				
			}
			*/
		}
		else 
		{
			wrapJavaObject( obj, (void**) &(varRet.pdispVal) );
			/*
			mol::punk<IJavaObject> instance;
			HRESULT hr = instance.createObject(CLSID_JavaObject,CLSCTX_ALL);
			if ( hr == S_OK )
			{
				hr = instance->Initialize((long*)obj);
				hr = instance->QueryInterface( IID_IDispatch, (void**) &(varRet.pdispVal));
				
			}
			*/
		}

	}
	return varRet;
}


mol::variant JavaMarshaller::javaClass2Variant( jclass clazz )
{
	mol::variant varRet;
	varRet.vt = VT_NULL;

	if ( clazz != 0 )
	{
		wrapJavaClass( clazz, (void**) &(varRet.pdispVal) );
		/*
		mol::punk<IJavaClass> instance;
		HRESULT hr = instance.createObject(CLSID_JavaClass,CLSCTX_ALL);
		if ( hr == S_OK )
		{
			hr = instance->QueryInterface( IID_IDispatch, (void**) &(varRet.pdispVal));
		}
		if ( hr != S_OK )
		{
			varRet.vt = VT_NULL;
			varRet.pdispVal = 0;
		}
		*/
	}
	varRet.vt = VT_DISPATCH;
	return varRet;
}

jobjectArray JavaMarshaller::dispArgs2JavaArray( JavaClassStore& classes, DISPPARAMS *pDisp, UINT dec  )
{
	JNIEnv* env = classes.env();
	jclass objectClazz = classes["java/lang/Object"];

	jobjectArray jar = env->NewObjectArray( pDisp->cArgs-dec, objectClazz, NULL );
	if (JRE::exceptionOccured(env))
	{
		return 0;
	}
	for ( UINT i = 0; i < pDisp->cArgs-dec; i++ )
	{
		jobject o = JavaMarshaller::variant2JavaObject(classes, pDisp->rgvarg[i]);
		env->SetObjectArrayElement( jar, i, o );
		if (JRE::exceptionOccured(env))
		{
			return 0;
		}
		env->DeleteLocalRef(o);
	}
	return jar;
}

DISPPARAMS* JavaMarshaller::javaArray2DispArgs(JavaClassStore& classes, jobjectArray args, jint flags, UINT dec  )
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
		if (JRE::exceptionOccured(env))
		{
			return 0;
		}
		::VariantInit( &(dispParams->rgvarg[n-i-1]) );
		mol::variant v = JavaMarshaller::javaObject2Variant(classes,obj);
		::VariantCopy( &(dispParams->rgvarg[n-i-1]),&v );		
	}

	return dispParams;
}



