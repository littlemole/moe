#include "stdafx.h"
#include "jglue.h"



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
	if ( jvm_ )
	    jvm_->DestroyJavaVM();

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
	int noptions = 2 + (debug ? 1 : 0);
	options_ = new JavaVMOption[noptions];

	std::string classpath = "-Djava.class.path=" + mol::tostring(classpath_);
	std::string libpath   = "-Djava.library.path=" +  mol::tostring(libpath_);

	options_[0].optionString = (char*)classpath.c_str();
	options_[1].optionString = (char*)libpath.c_str();

	if ( debug )
		options_[2].optionString = "-verbose:jni";

	vm_args_.version             = JNI_VERSION_1_6;
	vm_args_.nOptions            = noptions;
	vm_args_.options             = options_;
	vm_args_.ignoreUnrecognized  = false;

	//jruntime_ = loadJVM();
	//if ( !jruntime_ )
	//	return false;

	if (!jruntime_)
		jruntime_ = loadJVM();
	if (!jruntime_)
		return 0;
			
	CreateJavaVM createJavaVM = (CreateJavaVM) ::GetProcAddress( jruntime_, "JNI_CreateJavaVM" );

	if (!createJavaVM)
		return false;

	//jint res = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);
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
	mol::RegKey java = soft.open(_T("JavaSoft"),KEY_READ);
	mol::RegKey jre  = java.open(_T("Java Runtime Environment"),KEY_READ);
	mol::RegKey ver  = jre.open(_T("1.6"));

	mol::string path = ver.get(_T("RuntimeLib"));
	return path;
}





