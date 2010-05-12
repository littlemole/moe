// types.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "jreserver.h"



JREServer::JREServer()
{
	//mol::app<JREApp>().lock();
	
}

void JREServer::dispose()
{
	//mol::app<JREApp>().unlock();
	//if (!mol::app<JREApp>().Locked())
	//	::PostQuitMessage(0);
	mol::app<JREApp>().queue.cancel();
}

HRESULT __stdcall JREServer::put_Classpath( BSTR cp) 
{
	//::MessageBox(0,"hm","Hm",0);
	mol::app<JREApp>().jre().classpath( mol::bstr(cp).toString() );
	return S_OK;
}

HRESULT __stdcall JREServer::get_Classpath( BSTR *cp)
{
	if ( !cp )
		return E_INVALIDARG;

	mol::string p = mol::app<JREApp>().jre().classpath();

	*cp = ::SysAllocString( mol::towstring(p).c_str() );

	return S_OK;
}

HRESULT __stdcall JREServer::put_Libpath( BSTR lp)
{
	mol::app<JREApp>().jre().libpath( mol::bstr(lp).toString() );
	return S_OK;
}

HRESULT __stdcall JREServer::get_Libpath( BSTR *lp) 
{
	if ( !lp )
		return E_INVALIDARG;

	mol::string p = mol::app<JREApp>().jre().libpath();

	*lp = ::SysAllocString( mol::towstring(p).c_str() );

	return S_OK;
}

HRESULT __stdcall JREServer::Execute( BSTR classfile ) 
{
	if ( !classfile )
		return S_FALSE;

	std::string p = mol::BSTR2ansi(classfile);

	mol::app<JREApp>().queue.push( new JREThreadExecAction( p ) );

	return S_OK;
}

HRESULT __stdcall JREServer::Show( BSTR classfile ) 
{
	if ( !classfile )
		return S_FALSE;

	std::string p = mol::BSTR2ansi(classfile);

	mol::app<JREApp>().queue.push( new JREThreadShowAction( p ) );

	return S_OK;
}

HRESULT __stdcall JREServer::Extension( BSTR classfile, IDispatch* moe, IDispatch* frame)
{
	if ( !classfile )
		return S_FALSE;

	std::string p = mol::BSTR2ansi(classfile);

	mol::app<JREApp>().queue.push( new JREThreadExtensionAction( p, moe, frame ) );

	return S_OK;

	return S_OK;
}

///////////////////////////////////////////////////////////


JREThreadExecAction::JREThreadExecAction( const std::string& p )
: path_(p)
{
}

JREThreadExecAction::~JREThreadExecAction()
{
}

void JREThreadExecAction::operator()()
{
	for ( unsigned int i = 0; i < path_.size(); i++ )
		if ( path_[i] == '.' )
			path_[i] = '/';

	JRE& jre = mol::app<JREApp>().jre();

	if ( !jre.isLoaded() )
		jre.createJVM(false);


	jclass cls = jre->FindClass(path_.c_str());
	if ( !cls )
	{
		exit(0);
	}
	jmethodID mid = jre->GetStaticMethodID(cls, "main", "([Ljava/lang/String;)V");
	if (!mid)
	{
		exit(0);
	}
	jre->CallStaticIntMethod(cls, mid, NULL);
}




///////////////////////////////////////////////////////////


JREThreadShowAction::JREThreadShowAction( const std::string& p )
: path_(p)
{
}

JREThreadShowAction::~JREThreadShowAction()
{
}

void JREThreadShowAction::operator()()
{
	for ( unsigned int i = 0; i < path_.size(); i++ )
		if ( path_[i] == '.' )
			path_[i] = '/';

	JRE& jre = mol::app<JREApp>().jre();

	if ( !jre.isLoaded() )
		jre.createJVM(false);


	jclass cls = jre->FindClass(path_.c_str());

	if (!cls )
	{
		exit(0);
	}


	jmethodID constructorID = jre->GetMethodID( cls, "<init>", "()V" );

	if ( !constructorID )
	{
		exit(0);
	}

	jobject obj = jre->NewObject( cls, constructorID );

	if (!obj )
	{
		exit(0);
	}

	jmethodID mid = jre->GetMethodID( cls, "setVisible", "(Z)V" );
	if (!mid)
	{
		exit(0);
	}

	jre->CallVoidMethod( obj, mid, JNI_TRUE );

	mid = jre->GetMethodID( cls, "setAlwaysOnTop", "(Z)V" );
	if (!mid)
		return;

	jre->CallVoidMethod( obj, mid, JNI_TRUE );
	jre->CallVoidMethod( obj, mid, JNI_FALSE );
}

///////////////////////////////////////////////////////////


JREThreadExtensionAction::JREThreadExtensionAction( const std::string& p, IDispatch* m, IDispatch* f )
: path_(p),moeCookie(0),frameCookie(0)
{
	mol::GIT git;
	if ( m )
		git.registerInterface( m, &moeCookie );
	if ( f )
		git.registerInterface( f, &frameCookie );

}

JREThreadExtensionAction::~JREThreadExtensionAction()
{
	mol::GIT git;
	if ( moeCookie )
		git.revokeInterface(moeCookie);
	if ( frameCookie )
		git.revokeInterface(frameCookie);
}

void JREThreadExtensionAction::operator()()
{
	jobject jmoe   = NULL;
	jobject jframe = NULL;

	//::MessageBox(0,"hm","jre",0);

	for ( unsigned int i = 0; i < path_.size(); i++ )
		if ( path_[i] == '.' )
			path_[i] = '/';

	JRE& jre = mol::app<JREApp>().jre();

	if ( !jre.isLoaded() )
		jre.createJVM(false);

	jclass cls = jre->FindClass(path_.c_str());

	if (!cls )
	{
		if (jre->ExceptionCheck()) {
		jthrowable e = jre->ExceptionOccurred();

		char buf[1024];
		_strnset(buf, 0, 1024);

		// have to clear the exception before JNI will work again.
		jre->ExceptionClear();

		jclass eclass = jre->GetObjectClass(e);

		jmethodID mid = jre->GetMethodID(eclass, "toString", "()Ljava/lang/String;");

		jstring jErrorMsg = (jstring) jre->CallObjectMethod(e, mid);
		const char* cErrorMsg = jre->GetStringUTFChars(jErrorMsg, NULL);

		strcpy(buf, cErrorMsg);

		jre->ReleaseStringUTFChars(jErrorMsg, cErrorMsg);

		//JavaVM* vm;
		//jre->GetJavaVM(&vm);
		//vm->DestroyJavaVM();

		exit(0);
		//::PostQuitMessage(0);
		// you can do anything you want with error text in buf now
		}	
		return;
	}

	jmethodID constructorID = jre->GetMethodID( cls, "<init>", "()V" );

	if ( !constructorID )
	{
		exit(0);
	}

	jobject obj = jre->NewObject( cls, constructorID );

	if (!obj )
	{
		exit(0);
	}

	if ( moeCookie )
	{
		/*
		mol::GIT git;

		mol::punk<IXmoe> moe;
		mol::punk<IMoeFrame> frame;

		if ( moeCookie )
			git.getInterface(moeCookie,&moe);
		if ( frameCookie )
			git.getInterface(frameCookie,&frame);

		if ( moe() )
			moe->AddRef();
		if ( frame() )
			frame->AddRef();
		*/
		/*
		jclass wrapper = jre->FindClass("com4j/COM4J");
		if (!wrapper)
			return;

		jmethodID methodID = jre->GetStaticMethodID( wrapper, "create", "(I)Lcom4j/Com4jObject;" );

		if ( moe() )
			jmoe = jre->CallStaticObjectMethod( wrapper, methodID, (jint)(moe.interface_) );
		if ( frame() )
			jframe = jre->CallStaticObjectMethod( wrapper, methodID, (jint)(frame.interface_) );

			*/

		jmethodID methodID = jre->GetMethodID( cls, "init", "(II)V" );

		jre->CallVoidMethod( obj, methodID, (jint)(moeCookie), (jint)(frameCookie)  );
	}

	jmethodID methodID = jre->GetMethodID( cls, "setAlwaysOnTop", "(Z)V" );
	if (methodID)
	{
		jre->CallVoidMethod( obj, methodID, JNI_TRUE );
		jre->CallVoidMethod( obj, methodID, JNI_FALSE );
	}
}

////////////////////////////////////////////////////////////////

void JREThreadStartPolicy::operator()()
{
	::CoInitialize(0);
}

void JREThreadShutdownPolicy::operator()()
{
	mol::app<JREApp>().jre().detach();
	::CoUninitialize();
}




