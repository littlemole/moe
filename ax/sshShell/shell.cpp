#include "stdafx.h"
#include "shell.h"
#include "win/path.h"

#if defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else 
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif

///////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall moeShellDll::RegisterServer()
{
	HRESULT hr =  mol::Dll::RegisterServer();

	TCHAR    szSubKey[MAX_PATH];
	TCHAR    szCLSID[MAX_PATH];
	TCHAR    szModule[MAX_PATH];
	mol::CoStrBuf pwsz;

	::StringFromIID(CLSID_sshShell, &pwsz);
	wcscpy(szCLSID,pwsz);

	::GetModuleFileName(mol::hinstance(), szModule, ARRAYSIZE(szModule));

	// Change this from "...Desktop..." to 	"...MyComputer..." or ?
	wsprintf(   szSubKey, 
				TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Desktop\\NameSpace\\%s"), 
				szCLSID);

	HKEY     hKey;
	DWORD    dwDisp;

	LRESULT lResult = ::RegCreateKeyEx(  
								HKEY_LOCAL_MACHINE,
								szSubKey,
								0,
								NULL,
								REG_OPTION_NON_VOLATILE,
								KEY_WRITE,
								NULL,
								&hKey,
								&dwDisp);
	if(NOERROR == lResult)
	{
		TCHAR szData[MAX_PATH];
		wcscpy(szData, TEXT("SSH Servers"));

		lResult = ::RegSetValueEx( hKey,
									NULL,
									0,
									REG_SZ,
									(LPBYTE)szData,
									(DWORD)(wcslen(szData) + 1)*sizeof(wchar_t));
   
		::RegCloseKey(hKey);
	}

	wcscpy( szSubKey, TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Shell Extensions\\Approved"));

	lResult = ::RegCreateKeyEx( HKEY_LOCAL_MACHINE,
								szSubKey,
								0,
								NULL,
								REG_OPTION_NON_VOLATILE,
								KEY_WRITE,
								NULL,
								&hKey,
								&dwDisp);

	if(NOERROR == lResult)
	{
		TCHAR szData[MAX_PATH];
		wcscpy(szData, TEXT("SSH Servers"));

		lResult = ::RegSetValueEx(  hKey,
									szCLSID,
									0,
									REG_SZ,
									(LPBYTE)szData,
									(DWORD)(wcslen(szData) + 1)*sizeof(wchar_t));
      
		::RegCloseKey(hKey);
	}
	return hr;
}

HRESULT __stdcall moeShellDll::UnregisterServer()
{
	return mol::Dll::UnregisterServer();
}

BOOL __stdcall moeShellDll::Main( HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	BOOL ret = mol::Dll::Main(hinstDLL,fdwReason,lpvReserved);

	if ( fdwReason == DLL_PROCESS_ATTACH )
	{
		int   cx = 16;
		int   cy = 16;

		imgageListSmall.createIconList(4,cx,cy,ILC_COLORDDB | ILC_MASK,0);

		imgageListSmall.addIcon(IDI_BINARY,cx,cy);
		imgageListSmall.addIcon(IDI_STRING,cx,cy);
		imgageListSmall.addIcon(IDI_FOLDER,cx,cy);
		imgageListSmall.addIcon(IDI_FOLDEROPEN,cx,cy);
		imgageListSmall.addIcon(IDI_ROOT,cx,cy);

		cx = 32;
		cy = 32;

		imgageListLarge.createIconList(4,cx,cy,ILC_COLORDDB | ILC_MASK,0);

		imgageListLarge.addIcon(IDI_BINARY,cx,cy);
		imgageListLarge.addIcon(IDI_STRING,cx,cy);
		imgageListLarge.addIcon(IDI_FOLDER,cx,cy);
		imgageListLarge.addIcon(IDI_FOLDEROPEN,cx,cy);
		imgageListLarge.addIcon(IDI_ROOT,cx,cy);
	}

	if ( fdwReason == DLL_PROCESS_DETACH )
	{
		imgageListSmall.destroy();
		imgageListLarge.destroy();
		ODBGS("DLL DETACH");
	}
	return ret;
}

