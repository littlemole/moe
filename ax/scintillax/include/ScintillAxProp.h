#ifndef MOL_SCINTILLAX_PROP_DEF_GUARD_
#define MOL_SCINTILLAX_PROP_DEF_GUARD_

#pragma once
#include "win/CoCtrl.h"
#include "ole/Factory.h"
#include "ole/Bstr.h"
#include "ole/Persist.h"
#include "ole/PropertyPage.h"

#include <fstream>
#include "ScintillAx_h.h"
#include "include/resource.h"

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

class ScintillAxProperties : 
	public mol::com_registerobj<ScintillAxProperties,CLSID_ScintillAxProperties>,
	public mol::PropertyPage<ScintillAxProperties,IDD_DIALOG_PROP>,
	public mol::interfaces< ScintillAxProperties, 
			mol::implements<IPropertyPage> >
{
public:
	ScintillAxProperties();

	LRESULT OnInitDialog(UINT msg, WPARAM wParam, LPARAM lParam);
	LRESULT OnDirty(UINT msg, WPARAM wParam, LPARAM lParam);
	LRESULT OnConvert(UINT msg, WPARAM wParam, LPARAM lParam);

    virtual HRESULT __stdcall Apply( void);

protected:
	long tabwidth_;
	VARIANT_BOOL vbUseTabs_;
	VARIANT_BOOL vbTabIndents_;
	VARIANT_BOOL vbBackSpaceUnindents_;
	VARIANT_BOOL vbShowLineNumbers_;
	mol::ComboBox combo_;

	typedef std::pair<int,std::wstring> CodePage;
	std::vector<CodePage> codePages_;
};

class ScintillAxSettings : 
	public mol::com_registerobj<ScintillAxSettings,CLSID_ScintillAxSettings>,
	public mol::PropertyPage<ScintillAxSettings,IDD_DIALOG_SETTINGS>,
	public mol::interfaces< ScintillAxSettings, 
			mol::implements<IPropertyPage> >
{
public:
	ScintillAxSettings();

	LRESULT OnInitDialog(UINT msg, WPARAM wParam, LPARAM lParam);
	LRESULT OnDirty(UINT msg, WPARAM wParam, LPARAM lParam);
    virtual HRESULT __stdcall Apply( void);

protected:
	long systype_;
	long encoding_;
	VARIANT_BOOL vbWriteBOM_;
	mol::ComboBox combo_;

	typedef std::pair<int,std::wstring> CodePage;
	std::vector<CodePage> codePages_;
};

class EncodingDialog : public mol::Dlg<EncodingDialog>
{
public:

	LRESULT virtual wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	int getCodePage()
	{
		return cp_;
	}

private:
	int cp_;

};

#endif