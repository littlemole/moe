#include "stdafx.h"

#include "ole/dll.h"
#include "win/regkey.h"

bool g_kill = false;

void delete_clsids(HKEY hkey,const std::string& guid)
{
	DWORD index = 0;
	DWORD bufsize = MAX_PATH;
	wchar_t clsid[MAX_PATH];

	std::vector<std::wstring> clsids2kill;
	std::vector<std::wstring> progids2kill;
	std::vector<std::wstring> viprogids2kill;

	int r = ::RegEnumKeyEx( hkey, index, clsid,&bufsize,0,0,0,0);
	while( r == ERROR_SUCCESS )
	{
		HKEY subkey = 0;
		r = ::RegOpenKey(hkey,clsid,&subkey);
		if ( r == ERROR_SUCCESS )
		{
			LONG valsize = MAX_PATH;
			wchar_t val[MAX_PATH];

			r = ::RegQueryValue(subkey,L"TypeLib",val,&valsize);
			if ( r == ERROR_SUCCESS )
			{
				std::wstring v(val);
				if ( v == mol::towstring(guid) ) 
				{
					clsids2kill.push_back(clsid);

					LONG progidsize = MAX_PATH;
					wchar_t progid[MAX_PATH];
					LONG viprogidsize = MAX_PATH;
					wchar_t viprogid[MAX_PATH];

					r = ::RegQueryValue(subkey,L"ProgID",progid,&progidsize);
					if ( r == ERROR_SUCCESS )
					{
						progids2kill.push_back(progid);
						r = ::RegQueryValue(subkey,L"VersionIndependentProgID",viprogid,&viprogidsize);
						if ( r == ERROR_SUCCESS )
						{
							viprogids2kill.push_back(viprogid);
						}
					}
					std::wcout << clsid << L" " << v << std::endl;
					std::wcout << "\t" << viprogid << L" " << progid << std::endl;
				}
			}
			::RegCloseKey(subkey);
		}

		index++;
		bufsize = MAX_PATH;
		r = ::RegEnumKeyEx( hkey, index, clsid,&bufsize,0,0,0,0);
	}
	
	if (!g_kill)
	{
		return;
	}

	for ( std::vector<std::wstring>::iterator it = clsids2kill.begin(); it != clsids2kill.end(); it++)
	{
		::SHDeleteKey( hkey, (*it).c_str() );
		std::wcout << L"KILL CLSID " << *it << std::endl;
	}
	for ( std::vector<std::wstring>::iterator it = progids2kill.begin(); it != progids2kill.end(); it++)
	{
		std::wcout << L"KILL PROGID " << *it << std::endl;
	}
	for ( std::vector<std::wstring>::iterator it = viprogids2kill.begin(); it != viprogids2kill.end(); it++)
	{
		std::wcout << L"KILL VI PROGID " << *it << std::endl;
	}
}

void delete_interfaces(HKEY hkey,const std::string& guid)
{
	DWORD index = 0;
	DWORD bufsize = MAX_PATH;
	wchar_t interfaceid[MAX_PATH];

	std::vector<std::wstring> interfaces2kill;

	int r = ::RegEnumKeyEx( hkey, index, interfaceid,&bufsize,0,0,0,0);
	while( r == ERROR_SUCCESS )
	{
		HKEY subkey = 0;
		r = ::RegOpenKey(hkey,interfaceid,&subkey);
		if ( r == ERROR_SUCCESS )
		{
			LONG valsize = MAX_PATH;
			wchar_t val[MAX_PATH];

			r = ::RegQueryValue(subkey,L"TypeLib",val,&valsize);
			if ( r == ERROR_SUCCESS )
			{
				std::wstring v(val);
				if ( v == mol::towstring(guid) ) 
				{
					interfaces2kill.push_back(interfaceid);
					std::wcout << interfaceid << std::endl;
				}
			}
			::RegCloseKey(subkey);
		}

		index++;
		bufsize = MAX_PATH;
		r = ::RegEnumKeyEx( hkey, index, interfaceid,&bufsize,0,0,0,0);
	}

	if (!g_kill)
	{
		return;
	}

	for ( std::vector<std::wstring>::iterator it = interfaces2kill.begin(); it != interfaces2kill.end(); it++)
	{
		std::wcout << L"KILL INTERFACE " << *it << std::endl;
		::SHDeleteKey( hkey, (*it).c_str() );
	}
}

void delete_tlbs(HKEY hkey,const std::string& guid)
{
	DWORD index = 0;
	DWORD bufsize = MAX_PATH;
	wchar_t tlbid[MAX_PATH];

	std::vector<std::wstring> tlbs2kill;

	int r = ::RegEnumKeyEx( hkey, index, tlbid,&bufsize,0,0,0,0);
	while( r == ERROR_SUCCESS )
	{
		std::wstring v(tlbid);
		if ( v == mol::towstring(guid) ) 
		{
			tlbs2kill.push_back(tlbid);
			std::wcout << v << std::endl;
		}

		index++;
		bufsize = MAX_PATH;
		r = ::RegEnumKeyEx( hkey, index, tlbid,&bufsize,0,0,0,0);
	}

	if (!g_kill)
	{
		return;
	}

	for ( std::vector<std::wstring>::iterator it = tlbs2kill.begin(); it != tlbs2kill.end(); it++)
	{
		std::wcout << L"KILL TLB " << *it << std::endl;
		::SHDeleteKey( hkey, (*it).c_str() );
	}	
}


int main( int nargs, char* args[] )
{
	//::DebugBreak();
	try {

	if ( nargs <  2)
	{
		std::wcout << L"usage: TLBPURGE.exe [{348BC203-2384-4299-A632-09187984F9CC}]" << std::endl;
		std::wcout << L"\t specify a typelib GUID << std::endl;" << std::endl;
		std::wcout.flush();
		return 0;
	}
	std::string guid(args[1]);

	if ( nargs > 2 && guid == "kill" )
	{
		guid = std::string(args[2]);
		g_kill = true;
	}

	std::cout << std::endl;
	std::cout << "##################################" << std::endl;
	std::cout << "HKEY_CLASSES_ROOT - objects under clsid" << std::endl;
	std::cout << "##################################" << std::endl;

	mol::RegKey HKR;
	HKR = HKEY_CLASSES_ROOT;

	mol::RegKey hkr_clsid;
	hkr_clsid = HKR.open(L"Clsid");


	delete_clsids(hkr_clsid,guid);

	std::cout << std::endl;
	std::cout << "##################################" << std::endl;
	std::cout << "HKEY_CLASSES_ROOT - typelib" << std::endl;
	std::cout << "##################################" << std::endl;

	mol::RegKey hkr_typelib;
	hkr_typelib = HKR.open(L"TypeLib");

	delete_tlbs(hkr_typelib,guid);

	std::cout << std::endl;
	std::cout << "##################################" << std::endl;
	std::cout << "HKEY_CLASSES_ROOT - interface" << std::endl;
	std::cout << "##################################" << std::endl;

	mol::RegKey hkr_interfaces;
	hkr_interfaces = HKR.open(L"Interface");

	delete_interfaces(hkr_interfaces,guid);


	std::cout << std::endl;
	std::cout << "##################################" << std::endl;
	std::cout << "HKEY_LOCAL_MACHINE - objects under clsid" << std::endl;
	std::cout << "##################################" << std::endl;

	mol::RegKey HKLM;
	HKLM = HKEY_LOCAL_MACHINE;

	mol::RegKey software = HKLM.open(L"Software");
	mol::RegKey classes = software.open(L"Classes");

	mol::RegKey hkr_clsid2;
	hkr_clsid2 = classes.open(L"Clsid");


	delete_clsids(hkr_clsid2,guid);


	std::cout << std::endl;
	std::cout << "##################################" << std::endl;
	std::cout << "HKEY_LOCAL_MACHINE - typelib" << std::endl;
	std::cout << "##################################" << std::endl;

	mol::RegKey hkr_typelib2;
	hkr_typelib2 = classes.open(L"TypeLib");

	delete_tlbs(hkr_typelib2,guid);


	std::cout << std::endl;
	std::cout << "##################################" << std::endl;
	std::cout << "HKEY_LOCAL_MACHINE - interface" << std::endl;
	std::cout << "##################################" << std::endl;

	mol::RegKey hkr_interfaces2;
	hkr_interfaces2 = classes.open(L"Interface");

	delete_interfaces(hkr_interfaces2,guid);



	std::cout << std::endl;
	std::cout << "##################################" << std::endl;
	std::cout << "HKEY_CURRENT_USER - objects under clsid" << std::endl;
	std::cout << "##################################" << std::endl;

	mol::RegKey HKCU;
	HKCU = HKEY_CURRENT_USER;

	mol::RegKey software3 = HKLM.open(L"Software");
	mol::RegKey classes3 = software3.open(L"Classes");

	mol::RegKey hkr_clsid3;
	hkr_clsid3 = classes3.open(L"Clsid");


	delete_clsids(hkr_clsid3,guid);


	std::cout << std::endl;
	std::cout << "##################################" << std::endl;
	std::cout << "HKEY_CURRENT_USER - typelib" << std::endl;
	std::cout << "##################################" << std::endl;

	mol::RegKey hkr_typelib3;
	hkr_typelib3 = classes3.open(L"TypeLib");

	delete_tlbs(hkr_typelib3,guid);


	std::cout << std::endl;
	std::cout << "##################################" << std::endl;
	std::cout << "HKEY_CURRENT_USER - interface" << std::endl;
	std::cout << "##################################" << std::endl;

	mol::RegKey hkr_interfaces3;
	hkr_interfaces3 = classes3.open(L"Interface");

	delete_interfaces(hkr_interfaces3,guid);


	
	std::cout << std::endl;
	std::cout << "##################################" << std::endl;
	std::cout << "HKEY_CLASSES_ROOT WOW32 - objects under clsid" << std::endl;
	std::cout << "##################################" << std::endl;

	mol::RegKey WoW6432Node;
	WoW6432Node = HKR.open(L"Wow6432Node");

	mol::RegKey hkr_interfaces4;
	hkr_interfaces4 = WoW6432Node.open(L"Interface");


	delete_interfaces(hkr_interfaces4,guid);

	}
	catch( mol::X& x)
	{
		std::cout << x.what() << std::endl;
	}
	return 0;
};