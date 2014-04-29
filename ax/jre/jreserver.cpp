// types.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "jreserver.h"
#include "java/jglue.h"
#include "java/dispdriver.h"
#include "java/jmarshaler.h"

HRESULT Namespace::CreateInstance(IDispatch** d, const std::string& path)
{
	Instance* i = new Instance;
	i->path_ = path;
	i->lastId_ = 0;
	return i->QueryInterface(IID_IDispatch,(void**)d);
}

HRESULT __stdcall Namespace::GetIDsOfNames( REFIID  riid, OLECHAR FAR* FAR*  rgszNames, unsigned int  cNames, LCID   lcid, DISPID FAR*  rgDispId )
{
	OLECHAR* name = rgszNames[0];
	std::string n = mol::tostring(name);

	if ( name2id_.count(n) == 0 )
	{
		lastId_++;
		name2id_.insert(std::make_pair(n,lastId_));
		id2name_.insert(std::make_pair(lastId_,n));
	}

	rgDispId[0] = name2id_[n];
	return S_OK;
}

HRESULT __stdcall Namespace::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn, EXCEPINFO * ex, UINT * i)
{
	if( id2name_.count(dispIdMember) == 0 )
		return E_INVALIDARG;

	std::string name = id2name_[dispIdMember];
	std::string n = path_;
	if(!n.empty())
	{
		n += "/";
	}
	n += name;

	mol::JRE& env = mol::java::jre();
	mol::java::JavaClassStore classes(*env);

	jclass objectClazz = classes[n];
	if ( objectClazz )
	{
		mol::punk<IJavaClass> instance;
		HRESULT hr = instance.createObject(CLSID_JavaClass,CLSCTX_ALL);
		if ( hr == S_OK && pReturn )
		{
			hr = instance->Initialize( (long*)objectClazz);

			if  (w == DISPATCH_PROPERTYGET)
			{
				if ( hr == S_OK && pReturn )
				{
					mol::variant v((IDispatch*)(instance.interface_));
					::VariantCopy( pReturn, &v );		
				}
			}
			else if (w & DISPATCH_METHOD )
			{
				DWORD dispid_new = 0;
				HRESULT hr = instance->Invoke( dispid_new,riid,lcid,DISPATCH_PROPERTYGET,pDisp,pReturn,ex,i);
				return hr;
			}
		}
		return S_OK;
	}

	mol::punk<IDispatch> ns;
	HRESULT hr = Namespace::CreateInstance(&ns,n);
	if ( hr != S_OK )
		return hr;

	if(pReturn)
	{
		mol::variant v((IDispatch*)(ns.interface_));
		::VariantCopy( pReturn, &v );	
	}
	return S_OK;
}


JREServer::JREServer()
{
}

void JREServer::dispose()
{
	::PostThreadMessage(mol::guithread(),WM_QUIT,0,0);
}

HRESULT __stdcall JREServer::Exit()
{
	::PostThreadMessage(mol::guithread(),WM_QUIT,0,0);
	return S_OK;
}

HRESULT __stdcall JREServer::put_Classpath( BSTR cp) 
{
	mol::java::jre().classpath( mol::bstr(cp).towstring() );
	return S_OK;
}

HRESULT __stdcall JREServer::get_Classpath( BSTR *cp)
{
	if ( !cp )
		return E_INVALIDARG;

	std::wstring p = mol::java::jre().classpath();
	*cp = ::SysAllocString( mol::towstring(p).c_str() );
	return S_OK;
}

HRESULT __stdcall JREServer::put_Libpath( BSTR lp)
{
	mol::java::jre().libpath( mol::bstr(lp).towstring() );
	return S_OK;
}

HRESULT __stdcall JREServer::get_Libpath( BSTR *lp) 
{
	if ( !lp )
		return E_INVALIDARG;

	std::wstring p = mol::java::jre().libpath();

	*lp = ::SysAllocString( mol::towstring(p).c_str() );

	return S_OK;
}


HRESULT __stdcall JREServer::LoadClass( BSTR clazzName, IJavaClass** clazz)
{
	if ( !clazzName )
	{
		mol::com_throw("invalid classname",CLSID_Java,"Java error");
		return S_FALSE;
	}

	if ( !clazz )
	{
		return S_FALSE;
	}

	mol::JRE& env = mol::java::jre();
	
	std::string s = mol::bstr(clazzName).tostring();
	size_t pos = s.find('.');
	while ( pos != std::string::npos )
	{
		s = s.replace( pos, 1, "/" );	
		pos = s.find('.');
	}

	jclass c = env->FindClass(s.c_str());

	if (mol::java::exceptionOccured(*env))
		return E_FAIL;

	mol::punk<IJavaClass> instance;
	HRESULT hr = instance.createObject(CLSID_JavaClass,CLSCTX_ALL);
	if ( hr == S_OK )
	{
		hr = instance->Initialize( (long*)c);
		hr = instance.queryInterface(clazz);
		
	}

	::CoAllowSetForegroundWindow( (IUnknown*)*clazz, 0);
	
	if ( hr != S_OK || !clazz )
	{
		mol::com_throw("class not found",CLSID_Java,"");
	}
	return hr;
}

HRESULT __stdcall JREServer::get_Runtime( IDispatch** ns )
{
	return Namespace::CreateInstance(ns,"");
}

///////////////////////////////////////////////////////////


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
		mol::JRE& env = mol::java::jre();
		mol::java::JavaClassStore classes(*env);

		jclass objectClazz = classes["java/lang/Object"];
		mol::java::DispDriver dispDriver = classes["org/oha7/dispdriver/impl/DispDriver"];

		jobjectArray args = mol::java::JavaMarshaler::dispArgs2JavaArray( classes, pDisp, -1 );

		mol::bstr name(pDisp->rgvarg[pDisp->cArgs-1].bstrVal);
	
		jobject obj = dispDriver.Create(name.tostring(), args);
		if (mol::java::exceptionOccured(*env))
			return S_FALSE;

		if ( pReturn )
		{
			mol::variant v = mol::java::JavaMarshaler::javaObject2Variant(classes,obj);
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

HRESULT __stdcall JREServer::Cast( IJavaObject* javaObject, BSTR clazzName, IJavaObject** retObject )
{
	mol::JRE& env = mol::java::jre();
	mol::java::JavaClassStore classes(*env);

	jclass objectClazz = classes["java/lang/Object"];
	mol::java::DispDriver dispDriver = classes["org/oha7/dispdriver/impl/DispDriver"];

	//jclass objectClazz = classes["java/lang/Object"];
	
	std::string s = mol::bstr(clazzName).tostring();

	long* ptr = 0;
	HRESULT hr = javaObject->RawPtr(&ptr);

	jobject o = dispDriver.Cast( (jobject)ptr, s );

	if (mol::java::exceptionOccured(*env))
		return E_FAIL;

	mol::punk<IJavaObject> instance;
	hr = instance.createObject(CLSID_JavaObject,CLSCTX_ALL);
	if ( hr == S_OK )
	{
		hr = instance->Initialize( (long*)o);
		hr = instance.queryInterface( retObject);
		
	}

	::CoAllowSetForegroundWindow( (IUnknown*)*retObject, 0);
	
	if ( hr != S_OK || !retObject )
	{
		mol::com_throw("class not cast object",CLSID_JavaObject,"");
	}
	return S_OK;
}