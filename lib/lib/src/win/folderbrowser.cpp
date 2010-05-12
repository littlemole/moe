#include "util/str.h"

// we still build molib win2k compatible for most of the parts
// hack to upgrade to Vista for this file only - now you 
// need win7 sdk to build this!

#pragma warning( disable : 4005 )

#define WINVER  _WIN32_WINNT_VISTA
#define _WIN32_WINDOWS _WIN32_WINNT_VISTA
#define _WIN32_WINNT _WIN32_WINNT_VISTA
#define _WIN32_IE _WIN32_IE_IE60 //SP2

#include "Shobjidl.h"
#include "KnownFolders.h"

namespace mol {
namespace io  {

HRESULT SimpleFolderBrowser(HWND hwnd, mol::string& directory)
{
    IFileDialog *pfd;

	IShellItem *desktop;
                        
	HRESULT hr = SHCreateItemInKnownFolder( FOLDERID_Desktop, 0, 0, IID_IShellItem, (void**)&desktop);
	if ( hr != S_OK )
		return hr;
    
    // CoCreate the dialog object.
    hr = CoCreateInstance(CLSID_FileOpenDialog, 
                                  NULL, 
                                  CLSCTX_INPROC_SERVER, 
								  IID_IFileDialog,
								  (void**)&pfd);
	if ( hr != S_OK )
		return hr;
    
	DWORD dwOptions;
	hr = pfd->GetOptions(&dwOptions);
	if ( hr != S_OK )
		return hr;

	hr = pfd->SetOptions(dwOptions | FOS_FORCEFILESYSTEM | FOS_PICKFOLDERS |  FOS_ALLOWMULTISELECT);
	if ( hr != S_OK )
		return hr;

	hr = pfd->SetDefaultFolder(desktop);
	if ( hr != S_OK )
		return hr;

    // Show the dialog
    hr = pfd->Show(hwnd);
        
    if (SUCCEEDED(hr))
    {
        // Obtain the result of the user's interaction with the dialog.
        IShellItem *psiResult;
        hr = pfd->GetResult(&psiResult);
        
        if (SUCCEEDED(hr))
        {
            // Do something with the result.

			wchar_t* buf = 0;
			hr = psiResult->GetDisplayName( SIGDN_DESKTOPABSOLUTEPARSING, (wchar_t**)&buf );

			if ( S_OK == hr )
			{
				directory = mol::toString(buf);
				::CoTaskMemFree(buf);
			}
            psiResult->Release();
        }
    }
    pfd->Release();
	desktop->Release();
    return hr;
}

}
}