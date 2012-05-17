#include "util/str.h"
#include "win/core.h"
#include "Shobjidl.h"

#include "KnownFolders.h"
#include "win/v7.h"
#include "ole/punk.h"

//#define INITGUID 1
//DEFINE_GUID( IID_IFileDialog,  0x42f85136, 0xdb7e, 0x439c, 0x85, 0xf1, 0xe4, 0x07, 0x5d, 0x13, 0x5f, 0xc8);

//DEFINE_GUID( IID_IFileDialog,  0x42f85136, 0xdb7e, 0x439c, 0x85, 0xf1, 0xe4, 0x07, 0x5d, 0x13, 0x5f, 0xc8);
//DEFINE_GUID( CLSID_IFileDialog,0xDC1C5A9C, 0xE88A, 0x4dde, 0xA5, 0xA1, 0x60, 0xF8, 0x2A, 0x20, 0xAE, 0xF7);



namespace mol {
namespace io  {

typedef 	HRESULT __stdcall SHCreateItemInKnownFolderProc( REFKNOWNFOLDERID kfid, DWORD dwKFFlags, PCWSTR pszItem, REFIID riid, void **ppv );

HRESULT SimpleFolderBrowser(HWND hwnd, mol::string& directory)
{
    mol::punk<mol::v7::IFileDialog> fd;
	mol::punk<IShellItem> desktop;

	if ( !mol::v7::SHCreateItemInKnownFolder )
		return E_FAIL;
                        
	HRESULT hr = mol::v7::SHCreateItemInKnownFolder( FOLDERID_Desktop, 0, 0, IID_IShellItem, (void**)&desktop);
	if ( hr != S_OK )
		return hr;
    
    // CoCreate the dialog object.
	hr = fd.createObject(CLSID_FileOpenDialog);

	if ( hr != S_OK )
		return hr;
    
	DWORD dwOptions;
	hr = fd->GetOptions(&dwOptions);
	if ( hr != S_OK )
		return hr;

	hr = fd->SetOptions(dwOptions | mol::v7::FOS_ALLNONSTORAGEITEMS |mol::v7::FOS_NOVALIDATE /*| mol::v7::FOS_FORCEFILESYSTEM*/ | mol::v7::FOS_PICKFOLDERS |  mol::v7::FOS_ALLOWMULTISELECT);
	if ( hr != S_OK )
		return hr;

	hr = fd->SetDefaultFolder(desktop);
	if ( hr != S_OK )
		return hr;

    // Show the dialog
    hr = fd->Show(hwnd);
        
    if (SUCCEEDED(hr))
    {
        // Obtain the result of the user's interaction with the dialog.
        mol::punk<IShellItem> siResult;
        hr = fd->GetResult(&siResult);        
        if (SUCCEEDED(hr))
        {
            // Do something with the result.

			wchar_t* buf = 0;
			hr = siResult->GetDisplayName( SIGDN_DESKTOPABSOLUTEPARSING, (wchar_t**)&buf );
			if ( S_OK == hr )
			{
				directory = mol::toString(buf);
				::CoTaskMemFree(buf);
			}
        }
    }
    return hr;
}

}
}