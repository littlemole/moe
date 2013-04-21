#include "stdafx.h"
#include "ole/aut.h"
#include "java/jglue.h"
#include "java/jre.h"

namespace mol {
namespace java {

bool exceptionOccured( JNIEnv* jre, REFCLSID clsid )
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

			java::OleStr str( jre,jErrorMsg );
			ODBGS( str.str() );
		 
			mol::com_throw( str.c_str(), clsid, _T("Java error"));

			jre->ExceptionClear();
	}
	return true;
}

JRE& jre()
{
	return mol::singleton<JRE>();
}

JNIEnv* java()
{
	mol::JRE& jre = mol::java::jre();
	return *jre;
}

size_t JavaNames::getId(const std::string& name)
{
	LOCK(cs_);
	if ( name2Id_.count(name) > 0 )
	{
		return name2Id_[name];
	}
	size_t id = name2Id_.size()+50;
	id2Name_.insert(std::make_pair(id,name));
	name2Id_.insert(std::make_pair(name,id));
	return id;
}

const std::string& JavaNames::getName(size_t id)
{
	LOCK(cs_);
	if ( id2Name_.count(id) > 0 )
	{
		return id2Name_[id];
	}

	static std::string empty = "";
	return empty;
}



jclass JavaClassStore::operator[](const std::string& name )
{
	if ( map_.count(name) > 0 )
	{
		return map_[name];
	}

	jclass clazz = env_->FindClass(name.c_str());
	if (mol::java::exceptionOccured(env_))
	{
		return 0;
	}

	if ( clazz == 0 )
	{
		return 0;
	}
	map_.insert( std::make_pair( name,clazz) );
	return clazz;
}

OleStr::OleStr( JNIEnv* env, jstring str )
{
	jsize len = env->GetStringLength(str);
	jboolean isCopy;
	const jchar* chars = env->GetStringChars(str,&isCopy);
	str_ = std::wstring( (wchar_t*)chars,len );
	env->ReleaseStringChars(str,chars);
}

} // end namespace java
} // end namespace mol
