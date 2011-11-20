#include "ole/factory.h"
#include "win/regkey.h"

#include "ole/bstr.h"
#include "win/app.h"
#include "util/uni.h"
#include <sstream>
#include <objsafe.h>

namespace mol {
namespace ole {


/////////////////////////////////////////////////////////////////////
// register object in registry
/////////////////////////////////////////////////////////////////////


HRESULT ComRegisterObjBase::RegisterObjectHK( TypeLib& tl, mol::RegKey& root, REFGUID guid, DWORD miscStatus, OLEVERB* oleverbs, int flags, int clsctx, REGCLS cls)
{
	mol::string path = mol::App().getModulePath();
	mol::string coClassName;
	mol::string coClassDesc;
	mol::string version_independent_progid;
	mol::string versioned_progid;
	mol::string coClass_clsid = stringFromCLSID(guid);
	mol::string typelib_guid;

	typelib_guid = stringFromCLSID(tl.getGUID());

	punk<ITypeInfo> ti;
	if ( S_OK == tl.item(guid,&ti) )
	{
		BSTR bstrCoClassName = 0;
		BSTR bstrCoClassDesc = 0;

		if ( S_OK == ti->GetDocumentation(MEMBERID_NIL,&bstrCoClassName,&bstrCoClassDesc,0,0) )
		{
			if ( bstrCoClassName )
				coClassName = stringFromFreedBSTR(bstrCoClassName);

			if ( bstrCoClassDesc )
				coClassDesc = stringFromFreedBSTR(bstrCoClassDesc);
		}
	}

	mol::ostringstream oss_version;
	oss_version << tl.major() << _T(".") << tl.minor();
	mol::string version = oss_version.str();

	mol::ostringstream oss_progid;
	oss_progid << tl.getName() << _T(".") << coClassName;
	version_independent_progid = oss_progid.str();
	oss_progid << _T(".") << tl.major() << _T(".") << tl.minor();
	versioned_progid = oss_progid.str();

	ODBGS(versioned_progid.c_str());

	//AppId entries

	mol::RegKey AppIds;
	mol::RegKey appid;

	try {
		AppIds = root.open(_T("AppID"));
	}
	catch(...)
	{
		AppIds = root.create( _T("AppID") );
	}

	if ( mol::App().getAppId() != 0 )
	{
		try 
		{
			appid = AppIds.create( mol::App().getAppId() );

			if ( flags & CAN_ELEVATE )
				appid.set(_T("CanElevate"));

			if ( flags & DLL_SURROGATE ) {
				appid.set( _T("DllSurrogate"), _T("") );
			}

		}
		catch( ... ) 
		{}
	}


	//CLSID entries

	mol::RegKey CLSIDs;
	mol::RegKey clsid;

	try
	{
		CLSIDs = root.open(_T("CLSID"));
	}
	catch(...)
	{
		CLSIDs = root.create(_T("CLSID"));
	}

	clsid = CLSIDs.create(coClass_clsid);

	clsid.set(coClassName);

	ODBGS("created CLSID key");

	if ( mol::App().getAppId() != 0 )
	{
		mol::ostringstream oss;
		oss << "@" << path << ",-" << mol::App().getElevationStringIdentifier();
		clsid.set( _T("AppId"), mol::App().getAppId() );
		clsid.set( _T("LocalizedString"), oss.str() );

		if ( ( flags & CAN_ELEVATE ) )
		{
			mol::RegKey elevation;
			elevation = clsid.create( _T("Elevation") );
			elevation.setInt( _T("Enabled"), 1 );
		}
	}

	mol::RegKey clsid_version = clsid.create(_T("Version"));
	clsid_version.set(version);

	if ( clsctx & CLSCTX_LOCAL_SERVER )
	{
		mol::RegKey server = clsid.create(_T("LocalServer32"));
		server.set(path);

		if ( flags & APARTMENT )
		{
			server.set( _T("ThreadingModel"), _T("Apartment") );
		}
		if ( flags & MULTITHREADED )
		{
			server.set( _T("ThreadingModel"), _T("Free") );
		}
	}
	else
	if ( clsctx & CLSCTX_INPROC_SERVER )
	{
		mol::RegKey server = clsid.create(_T("InprocServer32"));
		server.set(path);
		if ( flags & APARTMENT )
		{
			server.set( _T("ThreadingModel"), _T("Apartment") );
		}
		if ( flags & MULTITHREADED )
		{
			server.set( _T("ThreadingModel"), _T("Free") );
		}
	}

	// clsid to progid
	mol::RegKey clsid_progid = clsid.create(_T("ProgID"));
	clsid_progid.set(versioned_progid);

	// clsid to version independent progid
	mol::RegKey clsid_progid_vi = clsid.create(_T("VersionIndependentProgID"));
	clsid_progid_vi.set(version_independent_progid);

	// flags
	if ( flags & INSERTABLE )
		clsid.create(_T("Insertable"));
	if ( flags & CONTROL )
		clsid.create(_T("Control"));
	if ( flags & PROGRAMMABLE )
		clsid.create(_T("Programmable"));

	// TypeLib
	mol::RegKey TypeLib = clsid.create(_T("TypeLib"));
	TypeLib.set( typelib_guid );

	// misc status

	mol::RegKey misc = clsid.create(_T("MiscStatus"));
	mol::ostringstream moss;
	moss << miscStatus;
	misc.set(moss.str());
		
	// verbs

	if ( oleverbs )
	{
		mol::RegKey verbs = clsid.create(_T("verb"));
		while ( oleverbs && oleverbs->lpszVerbName )
		{
			mol::ostringstream oss_key;
			oss_key << oleverbs->lVerb ;
			
			mol::RegKey verb = verbs.create(oss_key.str());

			mol::ostringstream oss_val;


			oss_val << mol::toString(oleverbs->lpszVerbName).c_str() << _T(",") << (oleverbs->fuFlags) << _T(",") << (oleverbs->grfAttribs);

			verb.set(oss_val.str());

			oleverbs++;
		}
	}

	// auxusertype
	mol::RegKey auxType = clsid.create(_T("AuxUserType"));
	mol::RegKey auxType_2 = auxType.create(_T("2"));
	auxType_2.set(coClassName);
	mol::RegKey auxType_3 = auxType.create(_T("3"));
	auxType_3.set(version_independent_progid);

	// categories
	mol::string safe_script = stringFromCLSID(CATID_SafeForScripting);
	mol::string safe_init = stringFromCLSID(CATID_SafeForInitializing);

	mol::RegKey cat = clsid.create(_T("Implemented Categories"));
	if ( flags & SAFE_SCRIPT )
		cat.create(safe_script);
	if ( flags & SAFE_INIT )
		cat.create(safe_init);

	// defaulticon

	// dataformats

	// progid to clsid
	mol::RegKey progid = root.create(versioned_progid);
	progid.set(coClassName);
	mol::RegKey progid_clsid = progid.create(_T("CLSID"));
	progid_clsid.set(coClass_clsid);
	if ( flags & INSERTABLE )
		progid.create(_T("Insertable"));
	if ( flags & CONTROL )
		progid.create(_T("Control"));

	//version independent progid to clsid
	mol::RegKey progid_vi = root.create(version_independent_progid);
	progid_vi.set(coClassName);
	mol::RegKey progid_clsid_vi = progid_vi.create(_T("CLSID"));
	progid_clsid_vi.set(coClass_clsid);
	mol::RegKey progid_curver = progid_vi.create(_T("CurVer"));
	progid_curver.set(versioned_progid);

	ODBGS("created CLSID subkeys");

	return S_OK;
}

HRESULT ComRegisterObjBase::RegisterObject(REFGUID guid, DWORD miscStatus, OLEVERB* oleverbs, int flags, int clsctx, REGCLS cls)
{
	ODBGS("Register object - load tl");
	TypeLib tl;
	tl.load();

	mol::RegKey root;
	mol::RegKey CLSIDs;
	mol::RegKey clsid;

	// start setting reg entries, trying machine wide first
	try 
	{
		ODBGS("try to install to HKCR");
		root = HKEY_CLASSES_ROOT;
		RegisterObjectHK( tl, root, guid, miscStatus, oleverbs, flags, clsctx, cls);
	}
	catch(...)
	{
		ODBGS("try to install to HKCU");
		root = HKEY_CURRENT_USER;

		mol::RegKey software = root.open(_T("Software"));
		try
		{
			root = software.open(_T("Classes"));
		}
		catch(...)
		{
			root = software.create(_T("Classes"));
		}
		RegisterObjectHK( tl, root, guid, miscStatus, oleverbs, flags, clsctx, cls);
	}

	return S_OK;
}

/////////////////////////////////////////////////////////////////////
// unregister object from registry
/////////////////////////////////////////////////////////////////////

HRESULT ComRegisterObjBase::UnRegisterObject(REFGUID guid, DWORD miscStatus, OLEVERB* oleverbs, int flags, int clsctx, REGCLS cls)
{
	mol::string path = mol::App().getModulePath();
	mol::string coClassName;
	mol::string coClassDesc;
	mol::string version_independent_progid;
	mol::string versioned_progid;
	mol::string coClass_clsid = stringFromCLSID(guid);
	mol::string typelib_guid;

	TypeLib tl;
	if(!tl.load()) 
	{
		ODBGS("failed to load typelib");
		return S_OK;
	}

	typelib_guid = stringFromCLSID(tl.getGUID());

	punk<ITypeInfo> ti;
	if ( S_OK == tl.item(guid,&ti) )
	{
		BSTR bstrCoClassName = 0;
		BSTR bstrCoClassDesc = 0;

		if ( S_OK == ti->GetDocumentation(MEMBERID_NIL,&bstrCoClassName,&bstrCoClassDesc,0,0) )
		{
			if ( bstrCoClassName )
				coClassName = stringFromFreedBSTR(bstrCoClassName);
			if ( bstrCoClassDesc )
				coClassDesc = stringFromFreedBSTR(bstrCoClassDesc);
		}

	}

	if ( coClassName.empty() )
		return S_OK;

	mol::ostringstream oss;
	oss << tl.getName() << _T(".") << coClassName;
	version_independent_progid = oss.str();
	oss << _T(".") << tl.major() << _T(".") << tl.minor();
	versioned_progid = oss.str();

	if ( version_independent_progid.empty() )
		return S_OK;

	if ( versioned_progid.empty() )
		return S_OK;
	//::MessageBox(0,version_independent_progid.c_str(),_T("UnRegisterObject"),0);

	// start deleting reg entries

	mol::RegKey root;
	mol::RegKey CLSIDs;
	mol::RegKey clsid;
	mol::RegKey AppIds;

	// start setting reg entries, trying machine wide first
	try 
	{
		//throw(1);
		root = HKEY_CLASSES_ROOT;

		//CLSID entries
		CLSIDs = root.open(_T("CLSID"));
		AppIds = root.open(_T("AppID"));
		clsid  = CLSIDs.open(coClass_clsid);
	}
	catch(...)
	{
		try {
			mol::RegKey user = HKEY_CURRENT_USER;

			//CLSID entries
			mol::RegKey software = user.open(_T("Software"));
			root   = software.open(_T("Classes"));
			AppIds = root.open(_T("AppID"));
			CLSIDs = root.open(_T("CLSID"));
		}
		catch(...)
		{
			return S_OK;
		}
	}

	// erase AppId entries
	if ( mol::App().getAppId() != 0 )
	{
		try {
			AppIds.erase( mol::App().getAppId() );
		}
		catch(...)
		{}
	}

	// erase clsid
	CLSIDs.erase(coClass_clsid);
	
	// progid to clsid
	root.erase(versioned_progid);

	//version independent progid to clsid
	root.erase(version_independent_progid);

	return S_OK;
}

} // end namespace mole::win::ole
} // end namespace mole
