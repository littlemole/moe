#include "stdafx.h"
#include "java/jre.h"
#include "win/regkey.h"
#include "win/app.h"
#include "win/path.h"

namespace mol {

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
	//std::string classpath = "-Djava.class.path=D:\\workspace\\dispdrivertest\\bin;" + mol::tostring(classpath_);
	//std::string libpath   = "-Djava.library.path=D:\\workspace\\dispdrivertest\\bin" +  mol::tostring(libpath_);

	mol::win::AppBase& app = mol::App();
	//JREApp& app = mol::app<JREApp>();
	mol::string path =  app.getAppPath();
	path = mol::Path::pathname(path);
	path = path + _T("\\lib");

	std::string classpath = "-Djava.class.path=" + mol::tostring(path) + "\\classes;" + mol::tostring(path) + "\\dispdriver.jar";
	if ( !classpath_.empty() )
	{
		classpath += ";" + mol::tostring(classpath_);
	}
	std::string libpath   = "-Djava.library.path=" +  mol::tostring(path) ;
	if ( !libpath_.empty() )
	{
		libpath += ";" + mol::tostring(libpath_);
	}

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
	{
		cry();
		return 0;
	}
			
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
	if ( !jvm_ )
	{
		return this->createJVM(true);
	}
	JNIEnv* env = 0;
	jvm_->AttachCurrentThread((void**)&env,0);
	return env;
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

	HMODULE module = ::LoadLibrary(path.c_str());
	if ( module != 0 )
		return module;

	size_t pos = path.find(_T("client\\jvm.dll"));
	if ( pos != mol::string::npos )
	{
		path = path.substr(0,pos) + _T("server\\jvm.dll");
	
		HMODULE module = ::LoadLibrary(path.c_str());
		if ( module != 0 )
			return module;
	}
	return 0;
}

mol::string JRE::getJREpathOnce()
{
	mol::TCHAR buf[MAX_PATH];
	if (::GetEnvironmentVariable( _T("JAVA_HOME"), buf, MAX_PATH ))
	{
		mol::string jh(buf);
		if ( !jh.empty() )
		{
			mol::string path = jh + _T("\\jre\\bin\\client\\jvm.dll");
			if ( mol::Path::exists(path) )
				return path;

			path = jh + _T("\\jre\\bin\\server\\jvm.dll");
			if ( mol::Path::exists(path) )
				return path;
		}
	}

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
	mol::RegKey ver;
	try {
		ver  = jre.open(_T("1.7"),KEY_READ);
	}
	catch(...)
	{
		ver  = jre.open(_T("1.6"),KEY_READ);
	}
	mol::string path = ver.get(_T("RuntimeLib"));
	return path;
}





} // end namespace mol
