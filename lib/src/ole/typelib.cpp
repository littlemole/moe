#include "ole/TypeLib.h"
#include "ole/TypeInfo.h"
#include "util/str.h"
#include "win/app.h"
#include "win/regkey.h"
//////////////////////////////////////////////////////////////////////////
// TypeLib
//////////////////////////////////////////////////////////////////////////

namespace mol {

bool TypeLib::load(const std::wstring& lib)
{
	std::wstring ws = mol::towstring(lib);

	release();
    HRESULT hr = ::LoadTypeLibEx(ws.c_str(),REGKIND_NONE,&interface_);
    if ( hr != S_OK )
    {
        //cry();
		return false;
	}

	TLIBATTR* tla;
	hr = interface_->GetLibAttr(&tla);

	guid_ = tla->guid;
	major_ = tla->wMajorVerNum;
	minor_ = tla->wMinorVerNum;
	interface_->ReleaseTLibAttr( tla );

	count_ = interface_->GetTypeInfoCount();
	return true;
}

bool TypeLib::load()
{
	return load(mol::App().getModulePath());
}

bool TypeLib::load(REFGUID libid,int major,int minor)
{
	release();  
//	HRESULT hr;
	//ODBGS("try loading typelib via ::LoadRegTypeLib");
    HRESULT hr = ::LoadRegTypeLib(libid,major,minor,LOCALE_SYSTEM_DEFAULT,&interface_);
    if ( hr != S_OK )
    {
        //cry();

		//ODBGS("try loading typelib via HKCU");
		std::wstring lp;
		try 
		{
			std::wstring typelib_guid;
			typelib_guid = stringFromCLSID(libid);	

			mol::RegKey root;
			mol::RegKey typeLibsKey;
			mol::RegKey typeLibKey;

			root = HKEY_CURRENT_USER;

			//CLSID entries
			mol::RegKey software = root.open(_T("Software"));
			mol::RegKey classes  = software.open(_T("Classes"));

			typeLibsKey = classes.open(_T("TypeLib"));
			typeLibKey = typeLibsKey.open(typelib_guid);


			std::wostringstream oss;
			oss << major << _T(".") << minor;
			std::wstring version = oss.str();

			mol::RegKey versionKey = typeLibKey.open(version);
			mol::RegKey tlbKey = versionKey.open(_T("0"));
			mol::RegKey win32  = tlbKey.open(_T("win32"));

			lp = win32.get();
		}
		catch(...)
		{
			return false;
		}
		return load(lp);
	}

	TLIBATTR* tla;
	hr = interface_->GetLibAttr(&tla);

	guid_ = tla->guid;
	major_ = tla->wMajorVerNum;
	minor_ = tla->wMinorVerNum;
	interface_->ReleaseTLibAttr( tla );

	count_ = interface_->GetTypeInfoCount();
	return true;
}

//////////////////////////////////////////////////////////////////////////

bool TypeLib::registerTypelib()
{
	std::wstring ws = mol::towstring(mol::App().getModulePath());

	ODBGS("try register typelib in HKR");
	HRESULT hr = RegisterTypeLib(  interface_, (OLECHAR*)(ws.c_str()), 0 );
    if ( hr != S_OK )
    {
        // try using HKCU

		// no win2k ?
		/*
		hr = RegisterTypeLibForUser( interface_, (OLECHAR*)(ws.c_str()),0);
		if ( hr != S_OK )
			return false;

	}
	return true;
	*/
		try 
		{
			std::wstring typelib_guid;
			typelib_guid = stringFromCLSID(getGUID());	

			ODBGS("register typelib in HKCU");
			ODBGS(typelib_guid.c_str());

			mol::RegKey root;
			mol::RegKey typeLibsKey;
			mol::RegKey typeLibKey;

			root = HKEY_CURRENT_USER;

			//CLSID entries
			mol::RegKey software = root.open(_T("Software"));
			mol::RegKey classes;
			try 
			{
				classes  = software.open(_T("Classes"));
			}
			catch(...)
			{
				classes = software.create( _T("Classes"));
			}
			try 
			{
				typeLibsKey = classes.open(_T("TypeLib"));
			}
			catch (...)
			{
				typeLibsKey = classes.create(_T("TypeLib"));
			}
			typeLibKey = typeLibsKey.create(typelib_guid);

			std::wostringstream oss;
	//		oss << tl.getName() << _T(".") << coClassName;
	//		version_independent_progid = oss.str();
			oss << major() << _T(".") << minor();
			std::wstring version = oss.str();

			mol::RegKey versionKey = typeLibKey.create(version);
			versionKey.set(getDescription());

			mol::RegKey tlbKey = versionKey.create(_T("0"));
			mol::RegKey helpDir = tlbKey.create(_T("HELPDIR"));
			mol::RegKey win32  = tlbKey.create(_T("win32"));
			win32.set( mol::towstring(ws) );

			mol::RegKey interfaces;
			try
			{
				interfaces = classes.open(_T("Interface"));
			}
			catch(...)
			{
				interfaces = classes.create(_T("Interface"));
			}
			for ( int i = 0; i < typeInfoCount(); i++ )
			{
				mol::TypeInfo ti;
				if ( S_OK != item(i,&ti) || !ti.type_info )
					continue;

				if ( ti.getAttr()->typekind != TKIND_INTERFACE && ti.getAttr()->typekind != TKIND_DISPATCH )
					continue;

				ODBGS(stringFromCLSID(ti.getAttr()->guid).c_str());

				mol::RegKey iface = interfaces.create(stringFromCLSID(ti.getAttr()->guid));
				iface.set(ti.name());
				mol::RegKey tl = iface.create(_T("TypeLib"));
				tl.set(typelib_guid);
				mol::RegKey proxystub = iface.create(_T("ProxyStubClsid32"));
				proxystub.set(_T("{00020424-0000-0000-C0000-000000000046}"));
			}
		}
		catch(...)
		{
			return false;
		}
	}
	return true;
	
}

//////////////////////////////////////////////////////////////////////////

bool TypeLib::unRegisterTypelib()
{
	if ( S_OK == ::UnRegisterTypeLib(guid_,major_,minor_,0,SYS_WIN32) )
		return true;

	/* no win2k
	if ( S_OK == ::UnRegisterTypeLibForUser(guid_,major_,minor_,0,SYS_WIN32) )
		return true;
	return false;
	*/


		try 
		{
			std::wstring typelib_guid;
			typelib_guid = stringFromCLSID(getGUID());	

			mol::RegKey root;
			mol::RegKey typeLibsKey;
			mol::RegKey typeLibKey;

			root = HKEY_CURRENT_USER;

			//CLSID entries
			mol::RegKey software = root.open(_T("Software"));
			mol::RegKey classes  = software.open(_T("Classes"));
			typeLibsKey = classes.open(_T("TypeLib"));
			typeLibKey = typeLibsKey.open(typelib_guid);


			std::wostringstream oss;
	//		oss << tl.getName() << _T(".") << coClassName;
	//		version_independent_progid = oss.str();
			oss << major() << _T(".") << minor();
			std::wstring version = oss.str();

			mol::RegKey interfaces;
			interfaces = classes.open(_T("Interface"));
			for ( int i = 0; i < typeInfoCount(); i++ )
			{
				mol::TypeInfo ti;
				if ( S_OK != item(i,&ti) || !ti.type_info )
					continue;

				if ( ti.getAttr()->typekind != TKIND_INTERFACE  && ti.getAttr()->typekind != TKIND_DISPATCH )
					continue;


				mol::RegKey iface = interfaces.open(stringFromCLSID(ti.getAttr()->guid));

				iface.del(_T("TypeLib"));
				iface.del(_T("ProxyStubClsid32"));
				iface.close();
				interfaces.del(stringFromCLSID(ti.getAttr()->guid));
			}


			mol::RegKey versionKey = typeLibKey.open(version);

			mol::RegKey tlbKey = versionKey.open(_T("0"));
			tlbKey.del(_T("HELPDIR"));
			tlbKey.del(_T("win32"));
			tlbKey.close();

			versionKey.del(_T("0"));
			versionKey.close();


			typeLibKey.del(version);
			typeLibKey.close();
			typeLibsKey.del(typelib_guid);
		}
		catch(...)
		{
			return false;
		}

	return false;
	
}

//////////////////////////////////////////////////////////////////////////

GUID TypeLib::getGUID()
{
	return guid_;
}

std::wstring TypeLib::getName()
{
	BSTR name = 0;
	if ( S_OK == interface_->GetDocumentation(-1,&name,NULL,NULL,NULL) )
		if ( name )
		{
			std::wstring s = mol::towstring(name);
			::SysFreeString(name);
			return s;
		}
	return _T("");
}

std::wstring TypeLib::getDescription()
{
	BSTR desc = 0;
	if ( S_OK == interface_->GetDocumentation(-1,NULL,&desc,NULL,NULL) )
		if ( desc )
		{
			std::wstring s = mol::towstring(desc);
			::SysFreeString(desc);
			return s;			
		}
	return _T("");
}

int TypeLib::typeInfoCount()
{
	return count_;
}

HRESULT TypeLib::item( unsigned int index, ITypeInfo** ti )
{
	return interface_->GetTypeInfo(  index, ti );
}

HRESULT TypeLib::item( REFGUID guid, ITypeInfo** ti )
{
	return interface_->GetTypeInfoOfGuid(  guid, ti );
}

std::wstring TypeLib::getName(int index)
{
	BSTR name = 0;
	if ( S_OK == interface_->GetDocumentation(index,&name,NULL,NULL,NULL) )
		if ( name )
		{
			std::wstring s = mol::towstring(name);
			::SysFreeString(name);
			return s;
		}
	return _T("");
}

std::wstring TypeLib::getDescription( int index)
{
	BSTR desc = 0;
	if ( S_OK == interface_->GetDocumentation(index,NULL,&desc,NULL,NULL) )
		if ( desc )
		{
			std::wstring s = mol::towstring(desc);
			::SysFreeString(desc);
			return s;
		}
	return _T("");
}

GUID TypeLib::getGUID(int index)
{
	punk<ITypeInfo> ti;
	if ( S_OK == item(index,&ti) )
	{
		TYPEATTR* ta;
		HRESULT hr = ti->GetTypeAttr(&ta);
		GUID guid = ta->guid;
		ti->ReleaseTypeAttr(ta);
		return guid;
	}
	return GUID_NULL;
}

TYPEKIND TypeLib::typeKind(int index)
{
	punk<ITypeInfo> ti;
	if ( S_OK == item(index,&ti) )
	{
		TYPEATTR* ta;
		HRESULT hr = ti->GetTypeAttr(&ta);
		TYPEKIND tk = ta->typekind;
		ti->ReleaseTypeAttr(ta);
		return tk;
	}
	return TKIND_ENUM;
}

} // end namespace mol