#ifndef MOL_JGLUE_DEF_GUARD_DEFINE_
#define MOL_JGLUE_DEF_GUARD_DEFINE_

#include "win/regkey.h"

#include <iostream>
#include <string>
#include <jni.h>

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

	bool isLoaded();

	static mol::string getJREpath();

	void detach();

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




#endif


