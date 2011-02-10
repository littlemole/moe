#ifndef MOL_JGLUE_DEF_GUARD_DEFINE_
#define MOL_JGLUE_DEF_GUARD_DEFINE_

#include "win/regkey.h"

#include <iostream>
#include <string>
#include <jni.h>
#include "ole/variant.h"

class JRE
{
public:

	typedef  jint  (__stdcall *CreateJavaVM)(JavaVM**, void**, void* );

	JRE();
	~JRE();

	void classpath(const mol::string& cpath );
	void libpath(const mol::string& lpath );

	mol::string classpath();
	mol::string libpath();

	JNIEnv* createJVM(bool debug);

	JNIEnv* operator->();
	JNIEnv* operator*() { return env_; }

	bool isLoaded();

	static mol::string getJREpath();

	void detach();

	JavaVM* jvm() { return jvm_; };

	static bool JRE::exceptionOccured( JNIEnv* jre );

private:

	JavaVM *jvm_;       
	JNIEnv *env_;       
	JavaVMInitArgs vm_args_; 
	JavaVMOption* options_;
	static HMODULE jruntime_;

	mol::string classpath_;
	mol::string libpath_;

	HMODULE loadJVM();

	static mol::string getJREpathOnce();
};



class JavaClassStore 
{
public:

	JavaClassStore( JNIEnv *env );

	jclass operator[](const std::string& name );

	JNIEnv *env() { return env_; }

private:
	JNIEnv *env_;
	std::map<std::string,jclass> map_;
};

class JavaMarshaller
{
public:

	static jobject variant2JavaObject(JavaClassStore& classes, VARIANT& var );
	static mol::variant javaObject2Variant(  JavaClassStore& classes, jobject obj );
	static mol::variant javaClass2Variant( jclass clazz );

	static jobjectArray dispArgs2JavaArray(JavaClassStore& classes, DISPPARAMS *pDisp, UINT dec = 0 );
	static DISPPARAMS* javaArray2DispArgs(JavaClassStore& classes, jobjectArray jar, jint flags, UINT dec = 0 );

private:
	static mol::variant javaArray2Variant( JavaClassStore& classes, jobject obj );
	static VARTYPE JavaMarshaller::getVarType(  JavaClassStore& classes, jobject clazz );

};

class OleStr
{
public:
	OleStr( JNIEnv *env, jstring str )
	{
		jsize len = env->GetStringLength(str);
		jboolean isCopy;
		const jchar* chars = env->GetStringChars(str,&isCopy);
		str_ = std::wstring( (wchar_t*)chars,len );
		env->ReleaseStringChars(str,chars);
	}

	const std::wstring& str()	{ return str_; }
	const wchar_t* c_str()		{ return str_.c_str(); }

private:
	std::wstring str_;
};



class DispDriver
{
public:

	DispDriver(jclass clazz)
		:clazz_(clazz)
	{}

	// class methods

	jobject Create( JRE& jre, jclass javaClass, jobjectArray args )
	{
		jmethodID mid = jre->GetStaticMethodID( clazz_, "Create", "(Ljava/lang/Class;[Ljava/lang/Object;)Ljava/lang/Object;" );
		jobject obj = jre->CallStaticObjectMethod( clazz_, mid, javaClass, args );
		return  obj;
	}
	
	jobject propertyGet( JRE& jre, jclass javaClass, const std::string& propertyName, jobjectArray args )
	{
		jstring s = jre->NewString( (const jchar*) mol::towstring(propertyName.c_str()).c_str(), propertyName.size() );
		jmethodID mid = jre->GetStaticMethodID( clazz_, "propertyGet", "(Ljava/lang/Object;Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/Object;" );
		jobject obj = jre->CallStaticObjectMethod( clazz_, mid, javaClass, s, args );
		return  obj;
	}

	jobject propertyPut( JRE& jre, jclass javaClass, const std::string& propertyName, jobjectArray args )
	{
		jstring s = jre->NewString( (const jchar*)  mol::towstring(propertyName.c_str()).c_str(), propertyName.size() );
		jmethodID mid = jre->GetStaticMethodID( clazz_, "propertyPut", "(Ljava/lang/Object;Ljava/lang/String;[Ljava/lang/Object;)" );
		jobject obj = jre->CallStaticObjectMethod( clazz_, mid, javaClass, s, args );
		return  obj;
	}


	jobject invoke( JRE& jre, jclass javaClass, const std::string& methodName, jobjectArray args )
	{
		jstring s = jre->NewString( (const jchar*)  mol::towstring(methodName.c_str()).c_str(), methodName.size() );
		jmethodID mid = jre->GetStaticMethodID( clazz_, "invoke", "(Ljava/lang/Class;Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/Object;" );
		jobject obj = jre->CallStaticObjectMethod( clazz_, mid, javaClass, s, args );
		return  obj;
	}


	// instance ( obj) methods

	jobject Create( JRE& jre, const std::string& className, jobjectArray args )
	{
		jclass c = jre->FindClass(className.c_str());
		return Create(jre, c, args);
	}

	jobject propertyGet( JRE& jre, jobject obj, const std::string& propertyName, jobjectArray args )
	{
		jstring s = jre->NewString( (const jchar*) mol::towstring(propertyName.c_str()).c_str(), propertyName.size() );
		jmethodID mid = jre->GetStaticMethodID( clazz_, "propertyGet", "(Ljava/lang/Object;Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/Object;" );
		jobject ret = jre->CallStaticObjectMethod( clazz_, mid, obj, s, args );
		return  ret;
	}

	jobject propertyPut( JRE& jre, jobject obj, const std::string& propertyName, jobjectArray args )
	{
		jstring s = jre->NewString( (const jchar*) mol::towstring(propertyName.c_str()).c_str(), propertyName.size() );
		jmethodID mid = jre->GetStaticMethodID( clazz_, "propertyPut", "(Ljava/lang/Object;Ljava/lang/String;[Ljava/lang/Object;)" );
		jobject ret = jre->CallStaticObjectMethod( clazz_, mid, obj, s, args );
		return  ret;
	}


	jobject invoke( JRE& jre, jobject obj, const std::string& methodName, jobjectArray args )
	{
		jstring s = jre->NewString( (const jchar*)  mol::towstring(methodName.c_str()).c_str(), methodName.size() );
		jmethodID mid = jre->GetStaticMethodID( clazz_, "invoke", "(Ljava/lang/Object;Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/Object;" );
		jobject ret = jre->CallStaticObjectMethod( clazz_, mid, obj, s, args );
		return  ret;
	}


	jclass operator*()
	{
		return clazz_;
	}

private:
	jclass clazz_;
};

#endif


