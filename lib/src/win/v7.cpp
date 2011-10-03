#include "win/v7.h"
#include "ole/ie.h"

namespace mol {
namespace v7  {


SHCreateItemFromParsingNamePtr* SHCreateItemFromParsingName = (SHCreateItemFromParsingNamePtr*)mol::dllFunc( _T("Shell32.dll"), _T("SHCreateItemFromParsingName") );
SHCreateItemInKnownFolderPtr*  SHCreateItemInKnownFolder = (SHCreateItemInKnownFolderPtr*)mol::dllFunc( _T("Shell32.dll"), _T("SHCreateItemInKnownFolder") );

void unlockInternetExplorer()
{
	// call this only if avail (naked IE6 on win2k will not have this)
	//const DWORD SET_FEATURE_ON_PROCESS = 0x00000002;
	typedef HRESULT  (__stdcall *CoInternetSetFeatureEnabledImpl)( mol::ie::INTERNETFEATURELIST FeatureEntry, DWORD dwFlags, BOOL fEnable );
	CoInternetSetFeatureEnabledImpl impl = (CoInternetSetFeatureEnabledImpl)mol::dllFunc( _T("urlmon.dll"), _T("CoInternetSetFeatureEnabled"));
	if ( impl )
		impl(mol::ie::FEATURE_LOCALMACHINE_LOCKDOWN, SET_FEATURE_ON_PROCESS, FALSE); 
}

typedef 
WINCOMMCTRLAPI HRESULT WINAPI 
TaskDialogPtr( 
	HWND hwndParent, 
	HINSTANCE hInstance, 
	PCWSTR pszWindowTitle, 
	PCWSTR pszMainInstruction, 
	PCWSTR pszContent, 
	TASKDIALOG_COMMON_BUTTON_FLAGS dwCommonButtons, 
	PCWSTR pszIcon, 
	int *pnButton
);

extern TaskDialogPtr* TaskDialog;
TaskDialogPtr* TaskDialog = (TaskDialogPtr*)mol::dllFunc( _T("Comctl32.dll"), _T("TaskDialog") );



int msgbox( HWND parent, const mol::string& txt, const mol::string& title, const mol::string& detail, int idIcon )
{
	if ( TaskDialog )
	{
		int result = 0;
		HRESULT hr = TaskDialog( 
						parent, 
						mol::hinstance(), 
						title.c_str(), 
						txt.c_str(), 
						detail.c_str(), 
						TDCBF_YES_BUTTON|TDCBF_NO_BUTTON,
						MAKEINTRESOURCE(idIcon),
						&result
					);
		return result;
	}
	else
	{
		return ::MessageBox( parent, txt.c_str(), title.c_str(), MB_YESNO|MB_ICONINFORMATION );
	}
}

void editFileExtensions( const std::wstring& app)
{
	mol::punk<IMoeApplicationAssociationRegistrationUI> aaru;
	HRESULT hr = aaru.createObject(CLSID_ApplicationAssociationRegistrationUI);
	if ( hr == S_OK )
	{
		aaru->LaunchAdvancedAssociationUI(app.c_str());
	}
}

} // end namespace v7
} // end namespace mol