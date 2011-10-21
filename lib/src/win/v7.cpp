#include "win/v7.h"
#include "ole/ie.h"
#include "Uxtheme.h"

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



IsAppThemedPtr* IsAppThemed = (IsAppThemedPtr*)mol::dllFunc( _T("UxTheme.dll"), _T("IsAppThemed") );


// TODO: make them public


///////////////////////////////////////////////////////////////////////////////


typedef struct _MARGINS
{
    int cxLeftWidth;      // width of left border that retains its size
    int cxRightWidth;     // width of right border that retains its size
    int cyTopHeight;      // height of top border that retains its size
    int cyBottomHeight;   // height of bottom border that retains its size
} MARGINS, *PMARGINS;

enum THEMESIZE
{
    TS_MIN,             // minimum size
    TS_TRUE,            // size without stretching
    TS_DRAW             // size that theme mgr will use to draw part
};



typedef HRESULT __stdcall GetThemeMarginsPtr(HTHEME hTheme, HDC hdc, int iPartId, int iStateId, int iPropId, LPCRECT prc, MARGINS *pMargins );
extern GetThemeMarginsPtr* GetThemeMargins;

GetThemeMarginsPtr* GetThemeMargins = (GetThemeMarginsPtr*)mol::dllFunc( _T("UxTheme.dll"), _T("GetThemeMargins") );


typedef HRESULT __stdcall GetThemePartSizePtr(HTHEME hTheme, HDC hdc, int iPartId, int iStateId, LPCRECT prc, enum THEMESIZE eSize, SIZE *psz );
extern GetThemePartSizePtr* GetThemePartSize;

GetThemePartSizePtr* GetThemePartSize = (GetThemePartSizePtr*)mol::dllFunc( _T("UxTheme.dll"), _T("GetThemePartSize") );


typedef HRESULT __stdcall GetThemeIntPtr(HTHEME hTheme, int iPartId, int iStateId, int iPropId,int *piVal );
extern GetThemeIntPtr* GetThemeInt;

GetThemeIntPtr* GetThemeInt = (GetThemeIntPtr*)mol::dllFunc( _T("UxTheme.dll"), _T("GetThemeInt") );


typedef HTHEME __stdcall OpenThemeDataPtr( HWND hwnd, LPCWSTR pszClassList );
extern OpenThemeDataPtr* OpenThemeData;

OpenThemeDataPtr* OpenThemeData = (OpenThemeDataPtr*)mol::dllFunc( _T("UxTheme.dll"), _T("OpenThemeData") );


typedef BOOL __stdcall IsThemeBackgroundPartiallyTransparentPtr(HTHEME hTheme,int iPartId,int iStateId);
extern IsThemeBackgroundPartiallyTransparentPtr* IsThemeBackgroundPartiallyTransparent;

IsThemeBackgroundPartiallyTransparentPtr* IsThemeBackgroundPartiallyTransparent = (IsThemeBackgroundPartiallyTransparentPtr*)mol::dllFunc( _T("UxTheme.dll"), _T("IsThemeBackgroundPartiallyTransparent") );


typedef HRESULT __stdcall DrawThemeBackgroundPtr( HTHEME hTheme, HDC hdc, int iPartId, int iStateId, LPCRECT pRect, LPCRECT pClipRect );
extern DrawThemeBackgroundPtr* DrawThemeBackground;

DrawThemeBackgroundPtr* DrawThemeBackground = (DrawThemeBackgroundPtr*)mol::dllFunc( _T("UxTheme.dll"), _T("DrawThemeBackground") );


typedef HRESULT __stdcall DrawThemeTextPtr(HTHEME hTheme,HDC hdc,int iPartId,int iStateId,LPCWSTR pszText,int cchText,DWORD dwTextFlags,DWORD dwTextFlags2,LPCRECT pRect);
extern DrawThemeTextPtr* DrawThemeText;

DrawThemeTextPtr* DrawThemeText = (DrawThemeTextPtr*)mol::dllFunc( _T("UxTheme.dll"), _T("DrawThemeText") );


typedef HRESULT __stdcall GetThemeTextExtentPtr(HTHEME hTheme,HDC hdc,int iPartId,int iStateId,LPCWSTR pszText,int iCharCount,DWORD dwTextFlags,LPCRECT pBoundingRect,LPRECT pExtentRect);
extern GetThemeTextExtentPtr* GetThemeTextExtent;

GetThemeTextExtentPtr* GetThemeTextExtent = (GetThemeTextExtentPtr*)mol::dllFunc( _T("UxTheme.dll"), _T("GetThemeTextExtent") );


typedef HRESULT __stdcall CloseThemeDataPtr( HTHEME hTheme );
extern CloseThemeDataPtr* CloseThemeData;

CloseThemeDataPtr* CloseThemeData = (CloseThemeDataPtr*)mol::dllFunc( _T("UxTheme.dll"), _T("CloseThemeData") );



//typedef HRESULT __stdcall SHCreateItemFromParsingNamePtr( PCWSTR pszPath, IBindCtx *pbc, REFIID riid, void **ppv);
//extern SHCreateItemFromParsingNamePtr* SHCreateItemFromParsingName;

///////////////////////////////////////////////////////////////////////////////

#include <vssym32.h>

struct VistaMenuMetrics
{
	VistaMenuMetrics(HWND hwnd)
	{
		hwndTheme = hwnd;
    
		hTheme = OpenThemeData(hwndTheme, VSCLASS_MENU);
		if (hTheme)
		{
			GetThemePartSize(hTheme, NULL, MENU_POPUPCHECK, 0, NULL, TS_TRUE, &sizePopupCheck);
			GetThemePartSize(hTheme, NULL, MENU_POPUPSEPARATOR, 0, NULL, TS_TRUE, &sizePopupSeparator);

			GetThemeInt(hTheme, MENU_POPUPITEM, 0, TMT_BORDERSIZE, &iPopupBorderSize); 
			GetThemeInt(hTheme, MENU_POPUPBACKGROUND, 0, TMT_BORDERSIZE, &iPopupBgBorderSize); 

			GetThemeMargins(hTheme, NULL, MENU_POPUPCHECK, 0, TMT_CONTENTMARGINS, NULL, &marPopupCheck); 
			GetThemeMargins(hTheme, NULL, MENU_POPUPCHECKBACKGROUND, 0, TMT_CONTENTMARGINS, NULL, 
			&marPopupCheckBackground); 
			GetThemeMargins(hTheme, NULL, MENU_POPUPITEM, 0, TMT_CONTENTMARGINS, NULL, &marPopupItem); 

			marPopupAccelerator = marPopupItem;
			marPopupAccelerator.cxLeftWidth = 
			marPopupAccelerator.cxRightWidth = 0;

			// Popup text margins
			MARGINS margins = marPopupItem;
			margins.cxRightWidth = iPopupBorderSize;
			margins.cxLeftWidth = iPopupBgBorderSize;
			marPopupText = margins;
        
			cyMarCheckBackground = marPopupCheckBackground.cyTopHeight + 
								   marPopupCheckBackground.cyBottomHeight;

		}
	}

	~VistaMenuMetrics()
	{
		CloseThemeData(hTheme);
		hTheme = NULL;
	}

    HTHEME  hTheme;                     // Theme handle
    HWND    hwndTheme;                  // Window handle used to 
                                        // generate hTheme
    
    MARGINS marPopupCheck;              // Popup check margins
    MARGINS marPopupCheckBackground;    // Popup check background 
                                        // margins
    MARGINS marPopupItem;               // Popup item margins
    MARGINS marPopupText;               // Popup text margins
    MARGINS marPopupAccelerator;        // Popup accelerator margins

    SIZE    sizePopupCheck;             // Popup check size metric
    SIZE    sizePopupSeparator;         // Popup separator size metric
    int     iPopupBorderSize;           // Popup border space between  
                                        // item text and accelerator
    int     iPopupBgBorderSize;         // Popup border space between 
                                        // item text and gutter
    
    int     cyMarCheckBackground;       // Additional amount of 
                                        // vertical space to add to 
                                        // checkbox
};



} // end namespace v7
} // end namespace mol