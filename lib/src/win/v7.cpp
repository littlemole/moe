#include "win/v7.h"
#include "ole/ie.h"
//#include "Uxtheme.h"

namespace mol {
namespace v7  {

void unlockInternetExplorer()
{
	::CoInternetSetFeatureEnabled(FEATURE_LOCALMACHINE_LOCKDOWN, SET_FEATURE_ON_PROCESS, FALSE);
}


int msgbox( HWND parent, const std::wstring& txt, const std::wstring& title, const std::wstring& detail, int idIcon )
{
	int result = 0;
	HRESULT hr = ::TaskDialog( 
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

void editFileExtensions( const std::wstring& app)
{
	mol::punk<IApplicationAssociationRegistrationUI> aaru;
	HRESULT hr = aaru.createObject(CLSID_ApplicationAssociationRegistrationUI);
	if ( hr == S_OK )
	{
		aaru->LaunchAdvancedAssociationUI(app.c_str());
	}
}


} // end namespace v7
} // end namespace mol