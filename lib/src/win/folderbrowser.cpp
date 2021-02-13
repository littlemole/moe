#include "util/str.h"
#include "win/core.h"
#include "Shobjidl.h"

#include "KnownFolders.h"
#include "win/v7.h"
#include "ole/punk.h"
#include "ole/com.h"

namespace mol {
namespace io  {

HRESULT SimpleFolderBrowser(HWND hwnd, std::wstring& directory)
{
    mol::punk<IFileDialog> fd;
	mol::punk<IShellItem> desktop;

	HRESULT hr = ::SHCreateItemInKnownFolder( FOLDERID_Desktop, 0, 0, IID_IShellItem, (void**)&desktop);
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

	hr = fd->SetOptions(dwOptions |FOS_ALLNONSTORAGEITEMS |FOS_NOVALIDATE /*| mol::v7::FOS_FORCEFILESYSTEM*/ | FOS_PICKFOLDERS |  FOS_ALLOWMULTISELECT);
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

			::mol::CoStrBuf buf;
			hr = siResult->GetDisplayName( SIGDN_DESKTOPABSOLUTEPARSING, &buf );
			if ( S_OK == hr )
			{
				directory = mol::towstring(buf);
			}
        }
    }
    return hr;
}

}
}