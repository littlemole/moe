#include "util/str.h"
#include "win/core.h"
// we still build molib win2k compatible for most of the parts
// hack to upgrade to Vista for this file only - now you 
// need win7 sdk to build this!

/*
#pragma warning( disable : 4005 )

#define WINVER  _WIN32_WINNT_VISTA
#define _WIN32_WINDOWS _WIN32_WINNT_VISTA
#define _WIN32_WINNT _WIN32_WINNT_VISTA
#define _WIN32_IE _WIN32_IE_IE60 //SP2
*/

#include "Shobjidl.h"

#include "KnownFolders.h"

#define INITGUID 1

DEFINE_GUID( IID_IFileDialog,  0x42f85136, 0xdb7e, 0x439c, 0x85, 0xf1, 0xe4, 0x07, 0x5d, 0x13, 0x5f, 0xc8);
DEFINE_GUID( CLSID_IFileDialog,0xDC1C5A9C, 0xE88A, 0x4dde, 0xA5, 0xA1, 0x60, 0xF8, 0x2A, 0x20, 0xAE, 0xF7);

enum _FILEOPENDIALOGOPTIONS
    {	FOS_OVERWRITEPROMPT	= 0x2,
	FOS_STRICTFILETYPES	= 0x4,
	FOS_NOCHANGEDIR	= 0x8,
	FOS_PICKFOLDERS	= 0x20,
	FOS_FORCEFILESYSTEM	= 0x40,
	FOS_ALLNONSTORAGEITEMS	= 0x80,
	FOS_NOVALIDATE	= 0x100,
	FOS_ALLOWMULTISELECT	= 0x200,
	FOS_PATHMUSTEXIST	= 0x800,
	FOS_FILEMUSTEXIST	= 0x1000,
	FOS_CREATEPROMPT	= 0x2000,
	FOS_SHAREAWARE	= 0x4000,
	FOS_NOREADONLYRETURN	= 0x8000,
	FOS_NOTESTFILECREATE	= 0x10000,
	FOS_HIDEMRUPLACES	= 0x20000,
	FOS_HIDEPINNEDPLACES	= 0x40000,
	FOS_NODEREFERENCELINKS	= 0x100000,
	FOS_DONTADDTORECENT	= 0x2000000,
	FOS_FORCESHOWHIDDEN	= 0x10000000,
	FOS_DEFAULTNOMINIMODE	= 0x20000000,
	FOS_FORCEPREVIEWPANEON	= 0x40000000
    } ;
typedef DWORD FILEOPENDIALOGOPTIONS;


struct IModalWindow : public IUnknown
{
public:
    virtual /* [local] */ HRESULT STDMETHODCALLTYPE Show( 
        /* [annotation][unique][in] */ 
        __in_opt  HWND hwndOwner) = 0;
    
};

typedef struct _COMDLG_FILTERSPEC {
    LPCWSTR pszName;
    LPCWSTR pszSpec;
} COMDLG_FILTERSPEC;

typedef enum tagFDAP {
    FDAP_BOTTOM = 0x00000000,
    FDAP_TOP = 0x00000001
} FDAP;

struct IFileDialog : public IModalWindow
{
public:
    virtual HRESULT STDMETHODCALLTYPE SetFileTypes( 
        /* [in] */ UINT cFileTypes,
        /* [size_is][in] */ const COMDLG_FILTERSPEC *rgFilterSpec) = 0;
    
    virtual HRESULT STDMETHODCALLTYPE SetFileTypeIndex( 
        /* [in] */ UINT iFileType) = 0;
    
    virtual HRESULT STDMETHODCALLTYPE GetFileTypeIndex( 
        /* [out] */  UINT *piFileType) = 0;
    
    virtual HRESULT STDMETHODCALLTYPE Advise( 
        /* [in] */  IFileDialogEvents *pfde,
        /* [out] */  DWORD *pdwCookie) = 0;
    
    virtual HRESULT STDMETHODCALLTYPE Unadvise( 
        /* [in] */ DWORD dwCookie) = 0;
    
    virtual HRESULT STDMETHODCALLTYPE SetOptions( 
        /* [in] */ FILEOPENDIALOGOPTIONS fos) = 0;
    
    virtual HRESULT STDMETHODCALLTYPE GetOptions( 
        /* [out] */ __RPC__out FILEOPENDIALOGOPTIONS *pfos) = 0;
    
    virtual HRESULT STDMETHODCALLTYPE SetDefaultFolder( 
        /* [in] */  IShellItem *psi) = 0;
    
    virtual HRESULT STDMETHODCALLTYPE SetFolder( 
        /* [in] */  IShellItem *psi) = 0;
    
    virtual HRESULT STDMETHODCALLTYPE GetFolder( 
        /* [out] */  IShellItem **ppsi) = 0;
    
    virtual HRESULT STDMETHODCALLTYPE GetCurrentSelection( 
        /* [out] */  IShellItem **ppsi) = 0;
    
    virtual HRESULT STDMETHODCALLTYPE SetFileName( 
        /* [string][in] */  LPCWSTR pszName) = 0;
    
    virtual HRESULT STDMETHODCALLTYPE GetFileName( 
        /* [string][out] */  LPWSTR *pszName) = 0;
    
    virtual HRESULT STDMETHODCALLTYPE SetTitle( 
        /* [string][in] */  LPCWSTR pszTitle) = 0;
    
    virtual HRESULT STDMETHODCALLTYPE SetOkButtonLabel( 
        /* [string][in] */  LPCWSTR pszText) = 0;
    
    virtual HRESULT STDMETHODCALLTYPE SetFileNameLabel( 
        /* [string][in] */  LPCWSTR pszLabel) = 0;
    
    virtual HRESULT STDMETHODCALLTYPE GetResult( 
        /* [out] */  IShellItem **ppsi) = 0;
    
    virtual HRESULT STDMETHODCALLTYPE AddPlace( 
        /* [in] */  IShellItem *psi,
        /* [in] */ FDAP fdap) = 0;
    
    virtual HRESULT STDMETHODCALLTYPE SetDefaultExtension( 
        /* [string][in] */  LPCWSTR pszDefaultExtension) = 0;
    
    virtual HRESULT STDMETHODCALLTYPE Close( 
        /* [in] */ HRESULT hr) = 0;
    
    virtual HRESULT STDMETHODCALLTYPE SetClientGuid( 
        /* [in] */  REFGUID guid) = 0;
    
    virtual HRESULT STDMETHODCALLTYPE ClearClientData( void) = 0;
    
    virtual HRESULT STDMETHODCALLTYPE SetFilter( 
        /* [in] */  IShellItemFilter *pFilter) = 0;
    
};
    


namespace mol {
namespace io  {

typedef 	HRESULT SHCreateItemInKnownFolderProc( REFKNOWNFOLDERID kfid, DWORD dwKFFlags, PCWSTR pszItem, REFIID riid, void **ppv );

HRESULT SimpleFolderBrowser(HWND hwnd, mol::string& directory)
{
    IFileDialog *pfd;

	IShellItem *desktop;

	SHCreateItemInKnownFolderProc*  SHCreateItemInKnownFolder = (SHCreateItemInKnownFolderProc*)mol::dllFunc( _T("Shell32.dll"), _T("SHCreateItemInKnownFolder") );
	if ( !SHCreateItemInKnownFolder )
		return E_FAIL;
                        
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