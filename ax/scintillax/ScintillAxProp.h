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
	ScintillAxProperties()
	{
		title_  = _T("Edit Settings");
	}

	//msg_handler( WM_INITDIALOG,	OnInitDialog )
	LRESULT OnInitDialog(UINT msg, WPARAM wParam, LPARAM lParam);

	//cmd_handler( IDC_RADIO_UNIX, OnDirty )
	//cmd_handler( IDC_RADIO_WIN32, OnDirty )
	//cmd_handler( IDC_COMBO_ENCODING, OnDirty )
	//cmd_handler( IDC_CHECK_USETABS,	OnDirty )
	//cmd_handler( IDC_CHECK_TABINDENTS, OnDirty )
	//cmd_handler( IDC_EDIT_TABWIDTH,	OnDirty )
	//cmd_handler( IDC_CHECK_BACKSPACEUNINDENTS, OnDirty )
	//cmd_handler( IDC_CHECK_WRITEBOM,	OnDirty )
	LRESULT OnDirty(UINT msg, WPARAM wParam, LPARAM lParam);

	//cmd_handler( IDC_CONVERT_BUTTON, OnConvert )
	LRESULT OnConvert(UINT msg, WPARAM wParam, LPARAM lParam);

    virtual HRESULT __stdcall Apply( void);

protected:
	long systype_;
	long encoding_;
	long tabwidth_;
	VARIANT_BOOL vbUseTabs_;
	VARIANT_BOOL vbTabIndents_;
	VARIANT_BOOL vbBackSpaceUnindents_;
	VARIANT_BOOL vbWriteBOM_;
	mol::ComboBox combo_;
};


#endif