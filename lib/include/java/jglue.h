#ifndef MOL_JGLUE_DEF_GUARD_DEFINE_
#define MOL_JGLUE_DEF_GUARD_DEFINE_

#include <map>
#include "util/uni.h"
#include "thread/sync.h"

#include <jni.h>

EXTERN_C const  CLSID CLSID_JavaObject;

namespace mol {

class JRE;

namespace java {

bool exceptionOccured( JNIEnv *env, REFCLSID clsid = CLSID_JavaObject);

class JavaClassStore 
{
public:

	JavaClassStore(JNIEnv* e)
		:env_(e)
	{}

	jclass operator[](const std::string& name );

	JNIEnv* env() {return env_;}

private:
	JNIEnv* env_;
	std::map<std::string,jclass> map_;
};

class OleStr
{
public:
	OleStr( JNIEnv* env, jstring str );

	const std::wstring& str()	{ return str_; }
	const wchar_t* c_str()		{ return str_.c_str(); }

private:
	std::wstring str_;
};

class JavaNames 
{
friend class mol::Singleton<JavaNames>;
public:

	size_t getId(const std::string& name);
	const std::string& getName(size_t id);

protected:
	~JavaNames() {}
	JavaNames() {}

private:
	std::map<size_t,std::string> id2Name_;
	std::map<std::string,size_t> name2Id_;

	mol::CriticalSection cs_;
};

class JavaClassNames : public JavaNames
{
friend class mol::Singleton<JavaClassNames>;
};


JRE& jre();
JNIEnv* java();

} // end namespace java
} // end namespace mol


#endif


