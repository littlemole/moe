#include "stdafx.h"
#include "jglue.h"
#include "jreserver.h"
#include "ole/ole.h"
#include "ole/com.h"
#include "ole/obj.h"
#include "ole/Bstr.h"
#include "ole/typeinfo.h"


HMODULE JRE::jruntime_ = 0;


JRE::JRE()
	: jvm_(0),       
	  env_(0),      
	  options_(0)
{
	classpath_ = _T(".");
	libpath_   = _T("");
}

JRE::~JRE()
{
	//if ( jvm_ )
	//    jvm_->DestroyJavaVM();

	delete[] options_;
}

void JRE::detach()
{
	if ( jvm_ )
		jvm_->DetachCurrentThread();
}

bool JRE::isLoaded()
{
	return jvm_ != 0;
}

void JRE::classpath(const mol::string& cpath )
{
	classpath_ = cpath;
}

void JRE::libpath(const mol::string& lpath )
{
	libpath_ = lpath;
}

mol::string JRE::classpath()
{
	return classpath_;
}

mol::string JRE::libpath()
{
	return libpath_;
}

JNIEnv* JRE::createJVM(bool debug)
{
	int noptions = 6 + (debug ? 1 : 0);
	options_ = new JavaVMOption[noptions];

	//C:\\Program Files (x86)\\Java\\jre6\\lib\\rt.jar
	std::string classpath = "-Djava.class.path=D:\\workspace\\dispdrivertest\\bin;" + mol::tostring(classpath_);
	std::string libpath   = "-Djava.library.path=D:\\workspace\\dispdrivertest\\bin" +  mol::tostring(libpath_);

	options_[0].optionString = (char*)classpath.c_str();
	options_[1].optionString = (char*)libpath.c_str();
	options_[2].optionString = "-Xdebug";
	options_[3].optionString = "-Xnoagent";
	options_[4].optionString = "-Djava.compiler=NONE";
	options_[5].optionString = "-Xrunjdwp:transport=dt_socket,server=y,suspend=n,address=5005";


	if ( debug )
		options_[6].optionString = "-verbose:jni";

	vm_args_.version             = JNI_VERSION_1_6;
	vm_args_.nOptions            = noptions;
	vm_args_.options             = options_;
	vm_args_.ignoreUnrecognized  = false;

	if (!jruntime_)
		jruntime_ = loadJVM();
	if (!jruntime_)
		return 0;
			
	CreateJavaVM createJavaVM = (CreateJavaVM) ::GetProcAddress( jruntime_, "JNI_CreateJavaVM" );

	if (!createJavaVM)
		return false;

	jint res = createJavaVM( &jvm_, (void**)&env_, &vm_args_ );
	if( res != 0 )
		return 0;

	jvm_->AttachCurrentThread((void**)&env_, &vm_args_);

	return env_;
}

mol::string JRE::getJREpath()
{
	static mol::string once = getJREpathOnce();
	return once;
}

JNIEnv* JRE::operator->()
{
	return env_;
}


HMODULE JRE::loadJVM()
{
	mol::string path;
	try {
		path = getJREpath();
	}
	catch(...)
	{
		return 0;
	}
	return ::LoadLibrary(path.c_str());
}

mol::string JRE::getJREpathOnce()
{
	mol::RegKey key(HKEY_LOCAL_MACHINE, KEY_READ);
	mol::RegKey soft = key.open(_T("SOFTWARE"),KEY_READ);
	mol::RegKey java;
	try {
		java = soft.open(_T("JavaSoft"),KEY_READ);
	}
	catch(...)
	{
		mol::RegKey wow = soft.open(_T("Wow6432Node"),KEY_READ);
		java = wow.open(_T("JavaSoft"),KEY_READ);
	}
	mol::RegKey jre  = java.open(_T("Java Runtime Environment"),KEY_READ);
	mol::RegKey ver  = jre.open(_T("1.6"),KEY_READ);

	mol::string path = ver.get(_T("RuntimeLib"));
	return path;
}


bool JRE::exceptionOccured( JNIEnv* jre )
{
	jboolean isExceptionOccured = jre->ExceptionCheck();
	if ( isExceptionOccured == 0 )
		return false;

	jthrowable exc = jre->ExceptionOccurred();
	if (exc) {

			jre->ExceptionDescribe();

			// have to clear the exception before JNI will work again.
			jre->ExceptionClear();

			jclass eclass = jre->GetObjectClass(exc);

			jmethodID mid = jre->GetMethodID(eclass, "toString", "()Ljava/lang/String;");

			jstring jErrorMsg = (jstring) jre->CallObjectMethod(exc, mid);

			OleStr str( jre, jErrorMsg );
			ODBGS( str.str() );
		 
			jre->ExceptionClear();
	}
	return true;
}

jobject JavaMarshaller::variant2JavaObject( JavaClassStore& classes, VARIANT& var )
{
	if ( var.vt == VT_EMPTY )
	{
		return 0;
	}

	JNIEnv *env = classes.env();

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
		jboolean b = var.boolVal == VARIANT_TRUE;
		jmethodID cid = env->GetMethodID( booleanClazz, "<init>", "(Z)V" );
		jobject i = env->NewObject(booleanClazz,cid, b );
		return i;
	}
	if ( var.vt == VT_UNKNOWN )
	{
		mol::punk<IJavaClass> javaClass;
		HRESULT hr =  var.punkVal->QueryInterface(IID_IJavaClass,(void**)&javaClass);
		if (hr == S_OK && javaClass )
		{
			jclass c = ((JavaClass::Instance*)(IJavaClass*)javaClass)->getClass();
			return c;
		}
		mol::punk<IJavaObject> javaObject;
		hr =  var.punkVal->QueryInterface(IID_IJavaObject,(void**)&javaObject);
		if (hr == S_OK && javaObject )
		{
			jobject j = ((JavaObject::Instance*)(IJavaObject*)javaObject)->getObject();
			return j;
		}

		jmethodID cid = env->GetMethodID( RawComPtrClazz, "<init>", "(J)V" );
		IUnknown* unk = 0;
		hr = var.punkVal->QueryInterface( IID_IUnknown, (void**)&unk );
		if ( hr == S_OK && unk )
		{
			jobject i = env->NewObject(RawComPtrClazz,cid, (jlong) unk);
			return i;
		}
		return 0;
	}
	if ( var.vt == VT_DISPATCH )
	{
		mol::punk<IJavaClass> javaClass;
		HRESULT hr =  var.pdispVal->QueryInterface(IID_IJavaClass,(void**)&javaClass);
		if (hr == S_OK && javaClass )
		{
			jclass c = ((JavaClass::Instance*)(IJavaClass*)javaClass)->getClass();
			return c;
		}
		mol::punk<IJavaObject> javaObject;
		hr =  var.pdispVal->QueryInterface(IID_IJavaObject,(void**)&javaObject);
		if (hr == S_OK && javaObject )
		{
			jobject j = ((JavaObject::Instance*)(IJavaObject*)javaObject)->getObject();
			return j;
		}

		
		jmethodID cid = env->GetMethodID( RawComPtrClazz, "<init>", "(J)V" );
		IDispatch* disp = 0;
		hr = var.pdispVal->QueryInterface( IID_IDispatch, (void**)&disp );
		if ( hr == S_OK && disp ) {
			jobject i = env->NewObject(RawComPtrClazz,cid, (jlong) disp);
			return i;
		}

		return 0;
	}

	if ( var.vt == VT_BSTR )
	{
		jstring s = env->NewString( (const jchar*) var.bstrVal, ::SysStringLen(var.bstrVal) );
		return s;
	}

	if ( var.vt == VT_I4 )
	{
		jmethodID cid = env->GetMethodID( intClazz, "<init>", "(I)V" );
		jobject i = env->NewObject(intClazz,cid, (jint) var.lVal );
		return i;
	}
	if ( var.vt == (VT_ARRAY|VT_VARIANT) )
	{
		mol::SafeArray<VT_VARIANT> sa(var.parray);
		mol::SFAccess<VARIANT> sfa(sa);

		jobjectArray jar = env->NewObjectArray( sfa.size(), ObjectClazz, NULL );

		for ( int i = 0; i < sfa.size(); i++ )
		{
			mol::variant v(sfa[i]);
			jobject o = JavaMarshaller::variant2JavaObject(classes,v);
			env->SetObjectArrayElement( jar, i, o );
		}
		return jar;
	}
	if ( var.vt == (VT_ARRAY|VT_DISPATCH) )
	{
		mol::SafeArray<VT_DISPATCH> sa(var.parray);
		mol::SFAccess<IDispatch*> sfa(sa);

		jobjectArray jar = env->NewObjectArray( sfa.size(), ObjectClazz, NULL );

		for ( int i = 0; i < sfa.size(); i++ )
		{
			mol::variant v(sfa[i]);
			jobject o = JavaMarshaller::variant2JavaObject(classes,v);
			env->SetObjectArrayElement( jar, i, o );
		}
		return jar;
	}
	if ( var.vt == (VT_ARRAY|VT_UNKNOWN) )
	{
		mol::SafeArray<VT_UNKNOWN> sa(var.parray);
		mol::SFAccess<IUnknown*> sfa(sa);

		jobjectArray jar = env->NewObjectArray( sfa.size(), ObjectClazz, NULL );

		for ( int i = 0; i < sfa.size(); i++ )
		{
			mol::variant v(sfa[i]);
			jobject o = JavaMarshaller::variant2JavaObject(classes,v);
			env->SetObjectArrayElement( jar, i, o );
		}
		return jar;
	}
	if ( var.vt == (VT_ARRAY|VT_BSTR) )
	{
		mol::SafeArray<VT_BSTR> sa(var.parray);
		mol::SFAccess<BSTR*> sfa(sa);
			
		jobjectArray jar = env->NewObjectArray( sfa.size(), ObjectClazz,NULL );

		for ( int i = 0; i < sfa.size(); i++ )
		{
			mol::variant v(sfa[i]);
			jobject o = JavaMarshaller::variant2JavaObject(classes,v);
			env->SetObjectArrayElement( jar, i, o );
		}
		return jar;
	}
	if ( var.vt == (VT_ARRAY|VT_I4) )
	{
		mol::SafeArray<VT_I4> sa(var.parray);
		mol::SFAccess<int*> sfa(sa);
			
		jobjectArray jar = env->NewObjectArray( sfa.size(), ObjectClazz,NULL );

		for ( int i = 0; i < sfa.size(); i++ )
		{
			mol::variant v(sfa[i]);
			jobject o = JavaMarshaller::variant2JavaObject(classes,v);
			env->SetObjectArrayElement( jar, i, o );
		}
		return jar;
	}
	if ( var.vt == (VT_ARRAY|VT_BOOL) )
	{
		mol::SafeArray<VT_BOOL> sa(var.parray);
		mol::SFAccess<VARIANT_BOOL> sfa(sa);
			
		jobjectArray jar = env->NewObjectArray( sfa.size(), ObjectClazz,NULL );

		for ( int i = 0; i < sfa.size(); i++ )
		{
			mol::variant v(sfa[i]);
			jobject o = JavaMarshaller::variant2JavaObject(classes,v);
			env->SetObjectArrayElement( jar, i, o );
		}
		return jar;
	}
	return 0;
}

VARTYPE JavaMarshaller::getVarType( JavaClassStore& classes, jobject clazz )
{
	jclass stringClazz = classes["java/lang/String"];
	jclass intClazz = classes["java/lang/Integer"];
	jclass booleanClazz = classes["java/lang/Boolean"];
	jclass RawComPtrClazz = classes["org/oha7/dispdriver/impl/RawComPtr"];
	jclass ObjectClazz = classes["java/lang/Object"];

	JNIEnv *env = classes.env();

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

mol::variant JavaMarshaller::javaArray2Variant(  JavaClassStore& classes, jobject obj )
{
	JNIEnv *env = classes.env();

	mol::ole::SafeArrayBase* sab = 0;
	mol::variant varRet;
	varRet.vt = VT_ERROR;

	jobjectArray joa = (jobjectArray)obj;
	jsize len = env->GetArrayLength( joa );

	if ( JRE::exceptionOccured(env) )
			return varRet;

	SAFEARRAYBOUND sb = { len, 0 };

	jclass clazz = env->GetObjectClass(obj);
	jmethodID mid = env->GetMethodID( clazz, "getComponentType", "()Ljava/lang/Class;" );
	jobject arrayType = env->CallObjectMethod( obj, mid );

	varRet.vt = getVarType( classes, arrayType )|VT_ARRAY;
	switch ( varRet.vt )
	{
		case VT_I4|VT_ARRAY :
		{
			sab = new mol::SafeArray<VT_I4>(sb);
			mol::SFAccess<int> sfa(*sab);
			for ( jsize j = 0; j < len; j++ )
			{
				jobject jae = env->GetObjectArrayElement( joa, j );
				jint value = env->CallIntMethod( jae, mid );
				sfa[j] = value;
			}
			break;
		}
		case VT_BOOL|VT_ARRAY :
		{
			sab = new mol::SafeArray<VT_BOOL>(sb);
			mol::SFAccess<VARIANT_BOOL> sfa(*sab);
			for ( jsize j = 0; j < len; j++ )
			{
				jobject jae = env->GetObjectArrayElement( joa, j );
				jboolean value = env->CallBooleanMethod( jae, mid );
				sfa[j] = value;
			}
			break;
		}
		case VT_BSTR|VT_ARRAY :
		{
			sab = new mol::SafeArray<VT_BSTR>(sb);
			mol::SFAccess<BSTR> sfa(*sab);
			for ( jsize j = 0; j < len; j++ )
			{
				jobject jae = env->GetObjectArrayElement( joa, j );
				OleStr str(env,(jstring)jae);
				sfa[j] = ::SysAllocString( str.c_str() );
			}
			break;
		}
		case VT_UNKNOWN|VT_ARRAY :
		{
			jclass RawComPtrClazz = classes["org/oha7/dispdriver/impl/RawComPtr"];
			sab = new mol::SafeArray<VT_UNKNOWN>(sb);
			mol::SFAccess<IUnknown*> sfa(*sab);
			for ( jsize j = 0; j < len; j++ )
			{
				jobject jae = env->GetObjectArrayElement( joa, j );
				mid = env->GetMethodID( RawComPtrClazz, "longValue", "()J" );
				jlong value = env->CallLongMethod( jae, mid );
				sfa[0] = (IDispatch*)value;
			}
			break;
		}
		case VT_DISPATCH|VT_ARRAY :
		{
			sab = new mol::SafeArray<VT_DISPATCH>(sb);
			mol::SFAccess<IDispatch*> sfa(*sab);
			for ( jsize j = 0; j < len; j++ )
			{
				jobject jae = env->GetObjectArrayElement( joa, j );
				JavaObject::Instance* instance = JavaObject::instance(obj);
				HRESULT hr = instance->QueryInterface( IID_IDispatch, (void**) &( sfa[j]) );
			}
			break;
		}
		case VT_DISPATCH|VT_VARIANT :
		{
			sab = new mol::SafeArray<VT_VARIANT>(sb);
			mol::SFAccess<VARIANT> sfa(*sab);
			for ( jsize j = 0; j < len; j++ )
			{
				jobject jae = env->GetObjectArrayElement( joa, j );
				JavaObject::Instance* instance = JavaObject::instance(obj);
				mol::variant v;
				HRESULT hr = instance->QueryInterface( IID_IDispatch, (void**) &(v.pdispVal)  );
				::VariantCopy( &(sfa[j]), &v );
			}
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


mol::variant JavaMarshaller::javaObject2Variant( JavaClassStore& classes, jobject obj )
{
	mol::variant varRet;

	if ( obj == NULL )
	{
		varRet.vt = VT_NULL;
		return varRet;
	}

	JNIEnv *env = classes.env();

	jboolean isArray = 0;

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
				varRet = javaArray2Variant(classes,obj);
				return varRet;
			}
		}

	}


	jclass stringClazz = classes["java/lang/String"];
	if ( env->IsInstanceOf( obj, stringClazz ) )
	{
		OleStr str(env,(jstring)obj);
		varRet.vt = VT_BSTR;
		varRet.bstrVal = ::SysAllocString( str.c_str() );
		return varRet;
	}

	jclass intClazz = classes["java/lang/Integer"];
	if ( env->IsInstanceOf( obj, intClazz ) )
	{
		jmethodID mid = env->GetMethodID( intClazz, "intValue", "()I" );
		jint value = env->CallIntMethod( obj, mid );
		varRet.vt = VT_I4;
		varRet.lVal = value;
		return varRet;
	}

	jclass booleanClazz =classes["java/lang/Boolean"];
	if ( env->IsInstanceOf( obj, booleanClazz ) )
	{
		jmethodID mid = env->GetMethodID( booleanClazz, "booleanValue", "()Z" );
		jboolean value = env->CallBooleanMethod( obj, mid );
		varRet.vt = VT_BOOL;
		varRet.lVal = value ? VARIANT_TRUE : VARIANT_FALSE;
		return varRet;
	}

	jclass RawComPtrClazz = classes["org/oha7/dispdriver/impl/RawComPtr"];
	if ( env->IsInstanceOf( obj, RawComPtrClazz ) )
	{
		jmethodID mid = env->GetMethodID( RawComPtrClazz, "longValue", "()J" );
		jlong value = env->CallLongMethod( obj, mid );
		varRet.vt = VT_DISPATCH;
		varRet.pdispVal = (IDispatch*)value;
		return varRet;
	}

	if ( obj != 0 )
	{
		varRet.vt = VT_DISPATCH;
		jclass clazz = classes["java/lang/Class"];
		if ( env->IsInstanceOf( obj, clazz ) )
		{
			JavaClass::Instance* instance = JavaClass::instance( (jclass)obj );
			HRESULT hr = instance->QueryInterface( IID_IDispatch, (void**) &(varRet.pdispVal));
		}
		else 
		{
			JavaObject::Instance* instance = JavaObject::instance(obj);
			HRESULT hr = instance->QueryInterface( IID_IDispatch, (void**) &(varRet.pdispVal));
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
		varRet.vt = VT_DISPATCH;
		JavaClass::Instance* instance = JavaClass::instance(clazz);
		HRESULT hr = instance->QueryInterface( IID_IDispatch, (void**) &(varRet.pdispVal));
		if ( hr != S_OK )
		{
			varRet.vt = VT_NULL;
			varRet.pdispVal = 0;
		}
	}
	return varRet;
}

jobjectArray JavaMarshaller::dispArgs2JavaArray( JavaClassStore& classes, DISPPARAMS *pDisp, UINT dec  )
{
	JNIEnv *env = classes.env();
	jclass objectClazz = classes["java/lang/Object"];

	jobjectArray jar = env->NewObjectArray( pDisp->cArgs-dec, objectClazz, NULL );
	for ( UINT i = 0; i < pDisp->cArgs-dec; i++ )
	{
		jobject o = JavaMarshaller::variant2JavaObject(classes, pDisp->rgvarg[i]);
		env->SetObjectArrayElement( jar, i, o );
		env->DeleteLocalRef(o);
	}
	return jar;
}

DISPPARAMS* JavaMarshaller::javaArray2DispArgs(JavaClassStore& classes, jobjectArray args, jint flags, UINT dec  )
{
	static DISPID dispidNamed = DISPID_PROPERTYPUT;

	JNIEnv *env = classes.env();

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
		::VariantInit( &(dispParams->rgvarg[n-i-1]) );
		mol::variant v = JavaMarshaller::javaObject2Variant(classes,obj);
		::VariantCopy( &(dispParams->rgvarg[n-i-1]),&v );		
	}

	return dispParams;
}




JavaClassStore::JavaClassStore( JNIEnv *env )
	:env_(env)
{}

jclass JavaClassStore::operator[](const std::string& name )
{
	if ( map_.count(name) > 0 )
	{
		return map_[name];
	}

	jclass clazz = env_->FindClass(name.c_str());
	if ( clazz == 0 )
	{
		return 0;
	}
	map_.insert( std::make_pair( name,clazz) );
	return clazz;
}

