#ifndef MOL_JGLUE_JRE_DEF_GUARD_DEFINE_
#define MOL_JGLUE_JRE_DEF_GUARD_DEFINE_

#include "java/jglue.h"

namespace mol {

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
	bool isLoaded();
	void detach();

	JNIEnv* operator->();
	JNIEnv* operator*() { return this->operator->(); }
	JavaVM* jvm() { return jvm_; };	

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

	static mol::string getJREpath();
	static mol::string getJREpathOnce();
};


} // end namespace mol



#endif


