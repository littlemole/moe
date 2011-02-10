// types.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "jreserver.h"




JREServer::JREServer()
{
}

void JREServer::dispose()
{
	::PostQuitMessage(0);
}

HRESULT __stdcall JREServer::put_Classpath( BSTR cp) 
{
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


HRESULT __stdcall JREServer::LoadClass( BSTR clazzName, IJavaClass** clazz)
{
	if ( !clazzName )
		return S_FALSE;

	if ( !clazz )
		return S_FALSE;

	JRE& jre = mol::app<JREApp>().jre();

	if ( !jre.isLoaded() )
		jre.createJVM(false);

	JNIEnv* env = 0;
	jre.jvm()->AttachCurrentThread( (void**) &env, 0 );
	
	std::string s = mol::bstr(clazzName).tostring();
	size_t pos = s.find('.');
	while ( pos != std::string::npos )
	{
		s = s.replace( pos, 1, "/" );	
		pos = s.find('.');
	}

	jclass c = env->FindClass(s.c_str());

	JavaClass::Instance* instance = JavaClass::instance(c);
	HRESULT hr = instance->QueryInterface(IID_IJavaClass,(void**)clazz);
	::CoAllowSetForegroundWindow( (IUnknown*)*clazz, 0);
	
	return hr;
}

///////////////////////////////////////////////////////////




HRESULT __stdcall JavaClass::GetIDsOfNames( REFIID  riid, OLECHAR FAR* FAR*  rgszNames, unsigned int  cNames, LCID   lcid, DISPID FAR*  rgDispId ) 
{ 
	OLECHAR* name = rgszNames[0];
	std::string n = mol::tostring(name);

	if ( n == "New" )
	{
		rgDispId[0] = 0;
		return S_OK;
	}

	if ( namesOfIds_.count(  n ) > 0 ) {
		rgDispId[0] = namesOfIds_[n];
		return S_OK;
	}

	int id = namesOfIds_.size() +1;
	namesOfIds_.insert( std::make_pair(n,id) );
	idsOfNames_.insert( std::make_pair(id,n) );
	rgDispId[0] = id;
	return S_OK;
}






HRESULT __stdcall JavaClass::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn, EXCEPINFO * ex, UINT * i) 
{ 
	JRE& jre = mol::app<JREApp>().jre();
	JavaClassStore classes(*jre);

	jclass objectClazz = classes["java/lang/Object"];
	DispDriver dispDriver = classes["org/oha7/dispdriver/impl/DispDriver"];

	jobjectArray args = JavaMarshaller::dispArgs2JavaArray( classes, pDisp );

	// create java obj via constructor
	if ( dispIdMember == 0 ) 
	{
		jobject obj = dispDriver.Create( jre, theJavaClass_, args );
		if ( pReturn )
		{
			mol::variant v = JavaMarshaller::javaObject2Variant(classes,obj);
			if ( v.vt == VT_DISPATCH ) 
			{
				::CoAllowSetForegroundWindow( (IUnknown*)v.pdispVal, 0);
			}
			::VariantCopy( pReturn, &v );
		}
		return S_OK;
	}

	// invoke a static class method
	std::string name = idsOfNames_[dispIdMember];

	if (  w == DISPATCH_PROPERTYGET ) 
	{
		jobject ret = dispDriver.propertyGet( jre, theJavaClass_, name, args );
		if ( pReturn )
		{
			mol::variant v = JavaMarshaller::javaObject2Variant(classes, ret );
			::VariantCopy( pReturn, &v );
		}

		return S_OK;
	}

	if (  w == DISPATCH_PROPERTYPUT ) 
	{
		dispDriver.propertyPut( jre,  theJavaClass_, name, args );
		if ( pReturn )
		{
			mol::variant v;
			v.vt = VT_EMPTY;
			::VariantCopy( pReturn, &v );
		}

		return S_OK;
	}

	jobject ret = dispDriver.invoke( jre, theJavaClass_,  name, args );
	if ( pReturn )
	{
		mol::variant v = JavaMarshaller::javaObject2Variant(classes, ret );
		::VariantCopy( pReturn, &v );
	}

    return S_OK;
}

HRESULT __stdcall JavaObject::GetIDsOfNames( REFIID  riid, OLECHAR FAR* FAR*  rgszNames, unsigned int  cNames, LCID   lcid, DISPID FAR*  rgDispId ) 
{ 
	OLECHAR* name = rgszNames[0];
	std::string n = mol::tostring(name);

	if ( namesOfIds_.count(  n ) > 0 ) {
		rgDispId[0] = namesOfIds_[n];
		return S_OK;
	}

	int id = namesOfIds_.size() + 1;
	namesOfIds_.insert( std::make_pair(n,id) );
	idsOfNames_.insert( std::make_pair(id,n) );
	rgDispId[0] = id;
	return S_OK;
}

HRESULT  __stdcall JavaObject::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn, EXCEPINFO * ex, UINT * i) 
{ 
	std::string name = idsOfNames_[dispIdMember];
	mol::string n = mol::toString(name);

	JRE& jre = mol::app<JREApp>().jre();
	JavaClassStore classes(*jre);

	jclass objectClazz = classes["java/lang/Object"];
	DispDriver dispDriver = classes["org/oha7/dispdriver/impl/DispDriver"];

	jobjectArray args = JavaMarshaller::dispArgs2JavaArray( classes, pDisp );

	if (  w == DISPATCH_PROPERTYGET ) 
	{
		jobject ret = dispDriver.propertyGet( jre, theJavaObject_, name, args );
		if ( pReturn )
		{
			mol::variant v = JavaMarshaller::javaObject2Variant(classes, ret );
			::VariantCopy( pReturn, &v );
		}

		return S_OK;
	}

	if (  w == DISPATCH_PROPERTYPUT ) 
	{
		dispDriver.propertyPut( jre,  theJavaObject_, name, args );
		if ( pReturn )
		{
			mol::variant v;
			v.vt = VT_EMPTY;
			::VariantCopy( pReturn, &v );
		}

		return S_OK;
	}

	jobject ret = dispDriver.invoke( jre, theJavaObject_, name , args );
	if ( pReturn )
	{
		mol::variant v = JavaMarshaller::javaObject2Variant( classes,ret );
		::VariantCopy( pReturn, &v );
	}

    return S_OK;
}

HRESULT __stdcall JREServer::GetIDsOfNames( REFIID  riid, OLECHAR FAR* FAR*  rgszNames, unsigned int  cNames, LCID   lcid, DISPID FAR*  rgDispId ) 
{ 
	OLECHAR* name = rgszNames[0];
	std::string n = mol::tostring(name);

	if ( n == "New" )
	{
		rgDispId[0] = 6;
		return S_OK;
	}

	return mol::Dispatch<IJVM>::GetIDsOfNames( riid, rgszNames, cNames, lcid, rgDispId );
}

HRESULT  __stdcall JREServer::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn, EXCEPINFO * ex, UINT * i) 
{ 
	if ( dispIdMember == 6 )
	{
		JRE& jre = mol::app<JREApp>().jre();
		if ( !jre.isLoaded() )
			jre.createJVM(false);

		JavaClassStore classes(*jre);

		jclass objectClazz = classes["java/lang/Object"];
		DispDriver dispDriver = classes["org/oha7/dispdriver/impl/DispDriver"];

		jobjectArray args = JavaMarshaller::dispArgs2JavaArray( classes, pDisp, -1 );

		mol::bstr name(pDisp->rgvarg[pDisp->cArgs-1].bstrVal);
	
		jobject obj = dispDriver.Create(jre, name.tostring(), args);
		if ( pReturn )
		{
			mol::variant v = JavaMarshaller::javaObject2Variant(classes,obj);
			if ( v.vt == VT_DISPATCH ) 
			{
				::CoAllowSetForegroundWindow( (IUnknown*)v.pdispVal, 0);
			}
			::VariantCopy( pReturn, &v );
		}
		return S_OK;
	}

	return mol::Dispatch<IJVM>::Invoke(dispIdMember, riid, lcid, w, pDisp, pReturn, ex, i );
}
