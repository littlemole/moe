#ifndef _MOL_DEF_GUARD_VISTA_AND_WINSEVEN_APIS_DEF_GUARD
#define _MOL_DEF_GUARD_VISTA_AND_WINSEVEN_APIS_DEF_GUARD

#include "win/wnd.h"
#include <shobjidl.h>

namespace mol {
namespace v7  {

enum _TASKDIALOG_COMMON_BUTTON_FLAGS
{
    TDCBF_OK_BUTTON            = 0x0001, // selected control return value IDOK
    TDCBF_YES_BUTTON           = 0x0002, // selected control return value IDYES
    TDCBF_NO_BUTTON            = 0x0004, // selected control return value IDNO
    TDCBF_CANCEL_BUTTON        = 0x0008, // selected control return value IDCANCEL
    TDCBF_RETRY_BUTTON         = 0x0010, // selected control return value IDRETRY
    TDCBF_CLOSE_BUTTON         = 0x0020  // selected control return value IDCLOSE
};
typedef int TASKDIALOG_COMMON_BUTTON_FLAGS;           // Note: _TASKDIALOG_COMMON_BUTTON_FLAGS is an int
	

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

typedef enum FDAP
{	FDAP_BOTTOM	= 0,
	FDAP_TOP	= 1
} 	
FDAP;


typedef struct _COMDLG_FILTERSPEC
{
    LPCWSTR pszName;
    LPCWSTR pszSpec;
} 	
COMDLG_FILTERSPEC;

typedef enum CDCONTROLSTATEF
{	CDCS_INACTIVE	= 0,
	CDCS_ENABLED	= 0x1,
	CDCS_VISIBLE	= 0x2,
	CDCS_ENABLEDVISIBLE	= 0x3
} 	
CDCONTROLSTATEF;

DEFINE_ENUM_FLAG_OPERATORS(CDCONTROLSTATEF)


MIDL_INTERFACE("42f85136-db7e-439c-85f1-e4075d135fc8")
IFileDialog : public IModalWindow
{
public:

    virtual HRESULT STDMETHODCALLTYPE SetFileTypes( UINT cFileTypes, const COMDLG_FILTERSPEC *rgFilterSpec) = 0;        
    virtual HRESULT STDMETHODCALLTYPE SetFileTypeIndex( UINT iFileType) = 0;        
    virtual HRESULT STDMETHODCALLTYPE GetFileTypeIndex( UINT *piFileType) = 0;        
    virtual HRESULT STDMETHODCALLTYPE Advise( IFileDialogEvents *pfde,DWORD *pdwCookie) = 0;        
    virtual HRESULT STDMETHODCALLTYPE Unadvise( DWORD dwCookie) = 0;        
    virtual HRESULT STDMETHODCALLTYPE SetOptions( FILEOPENDIALOGOPTIONS fos) = 0;        
    virtual HRESULT STDMETHODCALLTYPE GetOptions( FILEOPENDIALOGOPTIONS *pfos) = 0;        
    virtual HRESULT STDMETHODCALLTYPE SetDefaultFolder( IShellItem *psi) = 0;        
    virtual HRESULT STDMETHODCALLTYPE SetFolder( IShellItem *psi) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetFolder( IShellItem **ppsi) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetCurrentSelection( IShellItem **ppsi) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetFileName( LPCWSTR pszName) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetFileName( LPWSTR *pszName) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetTitle( LPCWSTR pszTitle) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetOkButtonLabel( LPCWSTR pszText) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetFileNameLabel( LPCWSTR pszLabel) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetResult( IShellItem **ppsi) = 0;
    virtual HRESULT STDMETHODCALLTYPE AddPlace( IShellItem *psi,FDAP fdap) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetDefaultExtension( LPCWSTR pszDefaultExtension) = 0;
    virtual HRESULT STDMETHODCALLTYPE Close( HRESULT hr) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetClientGuid( REFGUID guid) = 0;       
    virtual HRESULT STDMETHODCALLTYPE ClearClientData( void) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetFilter( IShellItemFilter *pFilter) = 0;
        
};



MIDL_INTERFACE("e6fdd21a-163f-4975-9c8c-a69f1ba37034")
IFileDialogCustomize : public IUnknown
{
public:

    virtual HRESULT STDMETHODCALLTYPE EnableOpenDropDown( DWORD dwIDCtl) = 0;        
    virtual HRESULT STDMETHODCALLTYPE AddMenu( DWORD dwIDCtl,LPCWSTR pszLabel) = 0;        
    virtual HRESULT STDMETHODCALLTYPE AddPushButton( DWORD dwIDCtl,LPCWSTR pszLabel) = 0;       
    virtual HRESULT STDMETHODCALLTYPE AddComboBox( DWORD dwIDCtl) = 0;
    virtual HRESULT STDMETHODCALLTYPE AddRadioButtonList( DWORD dwIDCtl) = 0;
    virtual HRESULT STDMETHODCALLTYPE AddCheckButton( DWORD dwIDCtl,LPCWSTR pszLabel,BOOL bChecked) = 0;        
    virtual HRESULT STDMETHODCALLTYPE AddEditBox( DWORD dwIDCtl,LPCWSTR pszText) = 0;
    virtual HRESULT STDMETHODCALLTYPE AddSeparator( DWORD dwIDCtl) = 0;
    virtual HRESULT STDMETHODCALLTYPE AddText( DWORD dwIDCtl,LPCWSTR pszText) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetControlLabel( DWORD dwIDCtl,LPCWSTR pszLabel) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetControlState( DWORD dwIDCtl,CDCONTROLSTATEF *pdwState) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetControlState( DWORD dwIDCtl,CDCONTROLSTATEF dwState) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetEditBoxText( DWORD dwIDCtl,WCHAR **ppszText) = 0;    
    virtual HRESULT STDMETHODCALLTYPE SetEditBoxText( DWORD dwIDCtl,LPCWSTR pszText) = 0;        
    virtual HRESULT STDMETHODCALLTYPE GetCheckButtonState( DWORD dwIDCtl,BOOL *pbChecked) = 0;        
    virtual HRESULT STDMETHODCALLTYPE SetCheckButtonState( DWORD dwIDCtl,BOOL bChecked) = 0;        
    virtual HRESULT STDMETHODCALLTYPE AddControlItem( DWORD dwIDCtl,DWORD dwIDItem,LPCWSTR pszLabel) = 0;        
    virtual HRESULT STDMETHODCALLTYPE RemoveControlItem( DWORD dwIDCtl,DWORD dwIDItem) = 0;        
    virtual HRESULT STDMETHODCALLTYPE RemoveAllControlItems( DWORD dwIDCtl) = 0;        
    virtual HRESULT STDMETHODCALLTYPE GetControlItemState( DWORD dwIDCtl,DWORD dwIDItem,CDCONTROLSTATEF *pdwState) = 0;        
    virtual HRESULT STDMETHODCALLTYPE SetControlItemState( DWORD dwIDCtl,DWORD dwIDItem,CDCONTROLSTATEF dwState) = 0;        
    virtual HRESULT STDMETHODCALLTYPE GetSelectedControlItem( DWORD dwIDCtl,DWORD *pdwIDItem) = 0;        
    virtual HRESULT STDMETHODCALLTYPE SetSelectedControlItem( DWORD dwIDCtl,DWORD dwIDItem) = 0;        
    virtual HRESULT STDMETHODCALLTYPE StartVisualGroup( DWORD dwIDCtl,LPCWSTR pszLabel) = 0;        
    virtual HRESULT STDMETHODCALLTYPE EndVisualGroup( void) = 0;        
    virtual HRESULT STDMETHODCALLTYPE MakeProminent( DWORD dwIDCtl) = 0;        
    virtual HRESULT STDMETHODCALLTYPE SetControlItemText( DWORD dwIDCtl,DWORD dwIDItem,LPCWSTR pszLabel) = 0;
        
};

MIDL_INTERFACE("d57c7288-d4ad-4768-be02-9d969532d960")
IFileOpenDialog : public IFileDialog
{
public:
    virtual HRESULT STDMETHODCALLTYPE GetResults( IShellItemArray **ppenum) = 0;        
    virtual HRESULT STDMETHODCALLTYPE GetSelectedItems( IShellItemArray **ppsai) = 0;        
};

MIDL_INTERFACE("1f76a169-f994-40ac-8fc8-0959e8874710")
IMoeApplicationAssociationRegistrationUI : public IUnknown
{
public:
    virtual HRESULT __stdcall LaunchAdvancedAssociationUI( LPCWSTR pszAppRegistryName) = 0;        
};

///////////////////////////////////////////////////////////////////////////////////////////////


typedef HRESULT __stdcall SHCreateItemFromParsingNamePtr( PCWSTR pszPath, IBindCtx *pbc, REFIID riid, void **ppv);
extern SHCreateItemFromParsingNamePtr* SHCreateItemFromParsingName;


typedef HRESULT __stdcall SHCreateItemInKnownFolderPtr( REFKNOWNFOLDERID kfid, DWORD dwKFFlags, PCWSTR pszItem, REFIID riid, void **ppv );
extern SHCreateItemInKnownFolderPtr* SHCreateItemInKnownFolder;


///////////////////////////////////////////////////////////////////////////////////////////////


int msgbox( HWND parent, const mol::string& txt, const mol::string& title, const mol::string& detail, int idIcon );

///////////////////////////////////////////////////////////////////////////////////////////////


void editFileExtensions(const std::wstring& app);

///////////////////////////////////////////////////////////////////////////////////////////////

void unlockInternetExplorer();

///////////////////////////////////////////////////////////////////////////////////////////////


typedef HRESULT __stdcall IsAppThemedPtr();
extern IsAppThemedPtr* IsAppThemed;


///////////////////////////////////////////////////////////////////////////////////////////////


} // end namespace v7
} // end namespace mol

#endif