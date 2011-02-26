#ifndef MOL_JGLUE_JRE_DEF_GUARD_DEFINE_
#define MOL_JGLUE_JRE_DEF_GUARD_DEFINE_

#include "win/regkey.h"

#include <iostream>
#include <string>
#include <jni.h>
#include "ole/variant.h"
#include "thread/sync.h"

EXTERN_C const  CLSID CLSID_JavaObject;

class JRE
{
friend class mol::Singleton<JRE>;
public:

	typedef  jint  (__stdcall *CreateJavaVM)(JavaVM**, void**, void* );

	void classpath(const mol::string& cpath );
	void libpath(const mol::string& lpath );

	mol::string classpath();
	mol::string libpath();

	JNIEnv* createJVM(bool debug);

	JNIEnv* operator->();
	JNIEnv* operator*() { return this->operator->(); }

	bool isLoaded();

	static mol::string getJREpath();

	void detach();

	JavaVM* jvm() { return jvm_; };

	static bool JRE::exceptionOccured( JNIEnv *env, REFCLSID clsid = CLSID_JavaObject);

private:
	JRE();
	~JRE();

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




#endif


