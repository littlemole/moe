#ifndef MOL_JGLUE_DISPDRIVER_DEF_GUARD_DEFINE_
#define MOL_JGLUE_DISPDRIVER_DEF_GUARD_DEFINE_

#include "java/jglue.h"

namespace mol {
namespace java {


class DispDriver
{
public:

	DispDriver(jclass clazz)
		:clazz_(clazz)
	{}

	// class methods

	jobject Create( jclass javaClass, jobjectArray args )
	{
		JNIEnv* jre = java();
		jmethodID mid = jre->GetStaticMethodID( clazz_, "Create", "(Ljava/lang/Class;[Ljava/lang/Object;)Ljava/lang/Object;" );
		jobject obj = jre->CallStaticObjectMethod( clazz_, mid, javaClass, args );
		return  obj;
	}


	jobject CreateSwing( jclass javaClass, jobjectArray args )
	{
		JNIEnv* jre = java();
		jmethodID mid = jre->GetStaticMethodID( clazz_, "CreateSwing", "(Ljava/lang/Class;[Ljava/lang/Object;)Ljava/lang/Object;" );
		jobject obj = jre->CallStaticObjectMethod( clazz_, mid, javaClass, args );
		return  obj;
	}
	
	jobject propertyGet( jclass javaClass, const std::string& propertyName, jobjectArray args )
	{
		JNIEnv* jre = java();
		jstring s = jre->NewString( (const jchar*) mol::towstring(propertyName.c_str()).c_str(), (jsize)propertyName.size() );
		jmethodID mid = jre->GetStaticMethodID( clazz_, "propertyGet", "(Ljava/lang/Object;Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/Object;" );
		jobject obj = jre->CallStaticObjectMethod( clazz_, mid, javaClass, s, args );
		return  obj;
	}

	jobject propertyPut( jclass javaClass, const std::string& propertyName, jobjectArray args )
	{
		JNIEnv* jre = java();
		jstring s = jre->NewString( (const jchar*)  mol::towstring(propertyName.c_str()).c_str(), (jsize)propertyName.size() );
		jmethodID mid = jre->GetStaticMethodID( clazz_, "propertyPut", "(Ljava/lang/Object;Ljava/lang/String;[Ljava/lang/Object;)" );
		jobject obj = jre->CallStaticObjectMethod( clazz_, mid, javaClass, s, args );
		return  obj;
	}


	jobject invoke( jclass javaClass, const std::string& methodName, jobjectArray args )
	{
		JNIEnv* jre = java();
		jstring s = jre->NewString( (const jchar*)  mol::towstring(methodName.c_str()).c_str(), (jsize)methodName.size() );
		jmethodID mid = jre->GetStaticMethodID( clazz_, "invoke", "(Ljava/lang/Class;Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/Object;" );
		jobject obj = jre->CallStaticObjectMethod( clazz_, mid, javaClass, s, args );
		return  obj;
	}


	// instance ( obj) methods

	jobject Create( const std::string& className, jobjectArray args )
	{
		JNIEnv* jre = java();
		jclass c = jre->FindClass(className.c_str());
		return Create(c, args);
	}

	jobject propertyGet( jobject obj, const std::string& propertyName, jobjectArray args )
	{
		JNIEnv* jre = java();
		jstring s = jre->NewString( (const jchar*) mol::towstring(propertyName.c_str()).c_str(), (jsize)propertyName.size() );
		jmethodID mid = jre->GetStaticMethodID( clazz_, "propertyGet", "(Ljava/lang/Object;Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/Object;" );
		jobject ret = jre->CallStaticObjectMethod( clazz_, mid, obj, s, args );
		return  ret;
	}


	jobject propertyGetSwing( jobject obj, const std::string& propertyName, jobjectArray args )
	{
		JNIEnv* jre = java();
		jstring s = jre->NewString( (const jchar*) mol::towstring(propertyName.c_str()).c_str(), (jsize)propertyName.size() );
		jmethodID mid = jre->GetStaticMethodID( clazz_, "propertyGetSwing", "(Ljava/lang/Object;Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/Object;" );
		jobject ret = jre->CallStaticObjectMethod( clazz_, mid, obj, s, args );
		return  ret;
	}

	jobject propertyPut( jobject obj, const std::string& propertyName, jobjectArray args )
	{
		JNIEnv* jre = java();
		jstring s = jre->NewString( (const jchar*) mol::towstring(propertyName.c_str()).c_str(), (jsize)propertyName.size() );
		jmethodID mid = jre->GetStaticMethodID( clazz_, "propertyPut", "(Ljava/lang/Object;Ljava/lang/String;[Ljava/lang/Object;)" );
		jobject ret = jre->CallStaticObjectMethod( clazz_, mid, obj, s, args );
		return  ret;
	}


	jobject propertyPutSwing( jobject obj, const std::string& propertyName, jobjectArray args )
	{
		JNIEnv* jre = java();
		jstring s = jre->NewString( (const jchar*) mol::towstring(propertyName.c_str()).c_str(), (jsize)propertyName.size() );
		jmethodID mid = jre->GetStaticMethodID( clazz_, "propertyPutSwing", "(Ljava/lang/Object;Ljava/lang/String;[Ljava/lang/Object;)" );
		jobject ret = jre->CallStaticObjectMethod( clazz_, mid, obj, s, args );
		return  ret;
	}

	jobject invoke( jobject obj, const std::string& methodName, jobjectArray args )
	{
		JNIEnv* jre = java();
		jstring s = jre->NewString( (const jchar*)  mol::towstring(methodName.c_str()).c_str(), (jsize)methodName.size() );
		jmethodID mid = jre->GetStaticMethodID( clazz_, "invoke", "(Ljava/lang/Object;Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/Object;" );
		jobject ret = jre->CallStaticObjectMethod( clazz_, mid, obj, s, args );
		return  ret;
	}



	jobject invokeSwing( jobject obj, const std::string& methodName, jobjectArray args )
	{
		JNIEnv* jre = java();
		jstring s = jre->NewString( (const jchar*)  mol::towstring(methodName.c_str()).c_str(), (jsize)methodName.size() );
		jmethodID mid = jre->GetStaticMethodID( clazz_, "invokeSwing", "(Ljava/lang/Object;Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/Object;" );
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

} // end namespace java
} // end namespace mol

#endif