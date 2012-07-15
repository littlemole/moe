#include "StdAfx.h"
#include "ScintillAxProp.h"
#include "win/enc.h"
#include <Windowsx.h>


ScintillAxProperties::ScintillAxProperties()
{
	title_  = _T("Tabulator Usage");
}

///////////////////////////////////////////////////////////////////////////////
// Message Handlers
///////////////////////////////////////////////////////////////////////////////
LRESULT ScintillAxProperties::OnDirty(UINT msg, WPARAM wParam, LPARAM lParam)
{
	this->setDirty();

	return 0;
}

LRESULT ScintillAxProperties::OnConvert(UINT msg, WPARAM wParam, LPARAM lParam)
{
	for ( unsigned int i = 0; i < objects_.size(); i++ )
	{	
		mol::punk<IScintillAx> sci(objects_[i]);
		if ( sci )
		{
			mol::punk<IScintillAxProperties> props;
			sci->get_Properties(&props);
			if ( props )
				props->ConvertTabs();
		}
	}
	return 0;
}


LRESULT ScintillAxProperties::OnInitDialog(UINT msg, WPARAM wParam, LPARAM lParam)
{
	if ( objects_.size() > 0 )
	{
		mol::punk<IScintillAx> sci(objects_[0]);
		if ( sci )
		{
			mol::punk<IScintillAxProperties> props;
			sci->get_Properties(&props);

			if ( props )
			{
				if ( S_OK != props->get_TabWidth(&tabwidth_) )
					return FALSE;
				if ( S_OK != props->get_ShowLineNumbers(&vbShowLineNumbers_) )
					return FALSE;

				if ( S_OK != props->get_TabUsage(&vbUseTabs_) )
					return FALSE;
				if ( S_OK != props->get_TabIndents(&vbTabIndents_) )
					return FALSE;
				if ( S_OK != props->get_BackSpaceUnindents(&vbBackSpaceUnindents_) )
				return FALSE;
			}

			this->setDlgItemInt(IDC_EDIT_TABWIDTH,tabwidth_);

			if ( vbUseTabs_ == VARIANT_TRUE )
				this->sendDlgItemMsg( IDC_CHECK_USETABS,BM_SETCHECK ,BST_CHECKED,0);
			if ( vbTabIndents_ == VARIANT_TRUE )
				this->sendDlgItemMsg( IDC_CHECK_TABINDENTS,BM_SETCHECK ,BST_CHECKED,0);
			if ( vbBackSpaceUnindents_ == VARIANT_TRUE )
				this->sendDlgItemMsg( IDC_CHECK_BACKSPACEUNINDENTS,BM_SETCHECK ,BST_CHECKED,0);			

			if ( vbShowLineNumbers_ == VARIANT_TRUE )
			{
				this->sendDlgItemMsg( IDC_CHECK_LINE_NUMBERS, BM_SETCHECK, BST_CHECKED,0);
			}
			else
			{
				this->sendDlgItemMsg( IDC_CHECK_LINE_NUMBERS, BM_SETCHECK, BST_UNCHECKED,0);
			}
		}
	}
	return FALSE; // note: false! look into PSDK!
}

///////////////////////////////////////////////////////////////////////////////
// COM Methods
///////////////////////////////////////////////////////////////////////////////

HRESULT ScintillAxProperties::Apply( void)
{
	int w;
	this->getDlgItemInt(IDC_EDIT_TABWIDTH,w,FALSE);
	tabwidth_ = w;

	if ( BST_CHECKED == this->sendDlgItemMsg( IDC_CHECK_USETABS,BM_GETCHECK ,0,0) )
		vbUseTabs_ = VARIANT_TRUE;
	else
		vbUseTabs_ = VARIANT_FALSE;

	if ( BST_CHECKED == this->sendDlgItemMsg( IDC_CHECK_TABINDENTS,BM_GETCHECK ,0,0) )
		vbTabIndents_ = VARIANT_TRUE;
	else
		vbTabIndents_ = VARIANT_FALSE;

	if ( BST_CHECKED == this->sendDlgItemMsg( IDC_CHECK_BACKSPACEUNINDENTS,BM_GETCHECK ,0,0) )
		vbBackSpaceUnindents_ = VARIANT_TRUE;
	else
		vbBackSpaceUnindents_ = VARIANT_FALSE;

	if ( BST_CHECKED == this->sendDlgItemMsg( IDC_CHECK_LINE_NUMBERS,BM_GETCHECK,0,0) )
		vbShowLineNumbers_ = VARIANT_TRUE;
	else
		vbShowLineNumbers_ = VARIANT_FALSE;

	for ( unsigned int i = 0; i < objects_.size(); i++ )
	{	
		mol::punk<IScintillAx> sci(objects_[i]);
		if ( sci )
		{
			mol::punk<IScintillAxProperties> props;
			if ( S_OK == sci->get_Properties(&props) )
			{
				if ( S_OK != props->put_TabWidth(tabwidth_) )
					continue;

				if ( S_OK != props->put_TabUsage(vbUseTabs_) )
					continue;
				if ( S_OK != props->put_TabIndents(vbTabIndents_) )
					continue;
				if ( S_OK != props->put_BackSpaceUnindents(vbBackSpaceUnindents_) )
					continue;
				if ( S_OK != props->put_ShowLineNumbers(vbShowLineNumbers_) )
					continue;
			}
		}
	}
	bDirty_ = FALSE;
	return S_OK;
}


LRESULT EncodingDialog::wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	mol::Crack msg(message,wParam,lParam);
	switch(message)
	{
		case WM_INITDIALOG :
		{
			cp_ = CP_ACP;

			HWND list = this->getDlgItem(IDC_LIST_ENCODING);
			const mol::CodePages::Entries& codePages = mol::CodePages::codePages();
			for ( mol::CodePages::Iterator it = codePages.begin(); it != codePages.end(); it++)
			{
				ListBox_AddString( list, (*it).second.second.c_str() );
			}
			break;
		}
		case WM_COMMAND :
		{
			switch(msg.id())
			{
				case IDOK :
				{
					HWND list = this->getDlgItem(IDC_LIST_ENCODING);
					int i = ListBox_GetCurSel(list);
					if ( i != LB_ERR )
					{
						const mol::CodePages::Entries& codePages = mol::CodePages::codePages();
						int c = 0;
						for ( mol::CodePages::Iterator it = codePages.begin(); it != codePages.end(); it++)
						{
							if ( c == i )
							{
								cp_ = (*it).first;
								break;
							}
						}
					}
					endDlg(0);
					break;
				}
				case IDCANCEL :
				{
					endDlg(0);
					break;
				}
			}
			break;
		}
	}
	return mol::Dlg<EncodingDialog>::wndProc(hWnd,message,wParam,lParam);
}







ScintillAxSettings::ScintillAxSettings()
{
	title_  = _T("Document Encoding");

	codePages_.push_back( CodePage(std::make_pair(CP_ACP,L"Ansi Default")) );
	codePages_.push_back( CodePage(std::make_pair(CP_UTF8,L"UTF-8")) );
	codePages_.push_back( CodePage(std::make_pair(CP_WINUNICODE,L"Unicode (UTF-16)")) );

	const mol::CodePages::Entries& cps = mol::CodePages::codePages();
	for ( mol::CodePages::Iterator it = cps.begin(); it != cps.end(); it++)
	{
		codePages_.push_back( CodePage( std::make_pair( (*it).first, (*it).second.second)) );
	}
}

///////////////////////////////////////////////////////////////////////////////
// Message Handlers
///////////////////////////////////////////////////////////////////////////////
LRESULT ScintillAxSettings::OnDirty(UINT msg, WPARAM wParam, LPARAM lParam)
{
	this->setDirty();

	long e = combo_.getCurSel();
	 
	if ( e == encoding_ )
		return 0;
	
	encoding_ = e;

	if ( e == SCINTILLA_ENCODING_ANSI )
	{
		::EnableWindow( this->getDlgItem(IDC_CHECK_WRITEBOM), FALSE );
		this->sendDlgItemMsg( IDC_CHECK_WRITEBOM, BM_SETCHECK, BST_UNCHECKED,0);
	}
	else
	{
		::EnableWindow( this->getDlgItem(IDC_CHECK_WRITEBOM), TRUE );
		if ( e == SCINTILLA_ENCODING_UTF16 )
			this->sendDlgItemMsg( IDC_CHECK_WRITEBOM, BM_SETCHECK, BST_CHECKED,0);
		else
			this->sendDlgItemMsg( IDC_CHECK_WRITEBOM, BM_SETCHECK, BST_UNCHECKED,0);
	}
	return 0;
}


LRESULT ScintillAxSettings::OnInitDialog(UINT msg, WPARAM wParam, LPARAM lParam)
{
	combo_.attach(getDlgItem(IDC_COMBO_ENCODING));

	for ( size_t i = 0; i < codePages_.size(); i++ )
	{
		combo_.addString(codePages_[i].second);
	}

	if ( objects_.size() > 0 )
	{
		mol::punk<IScintillAx> sci(objects_[0]);
		if ( sci )
		{
			mol::punk<IScintillAxProperties> props;
			sci->get_Properties(&props);

			if ( props )
			{
				if ( S_OK != props->get_SysType(&systype_) )
					return FALSE;
				if ( S_OK != props->get_Encoding(&encoding_) )
					return FALSE;
				if ( S_OK != props->get_WriteBOM(&vbWriteBOM_) )
					return FALSE;
			}
			if ( systype_ == SCINTILLA_SYSTYPE_UNIX )
				this->sendDlgItemMsg(IDC_RADIO_UNIX,BM_SETCHECK ,BST_CHECKED,0);
			if ( systype_ == SCINTILLA_SYSTYPE_WIN32 )
				this->sendDlgItemMsg(IDC_RADIO_WIN32,BM_SETCHECK ,BST_CHECKED,0);

			for ( size_t i = 0; i < codePages_.size(); i++ )
			{
				if ( codePages_[i].first == encoding_ )
				{
					combo_.setCurSel((int)i);
				}
			}

			if ( encoding_ == SCINTILLA_ENCODING_ANSI )
			{
				this->sendDlgItemMsg( IDC_CHECK_WRITEBOM, BM_SETCHECK, BST_UNCHECKED,0);
				::EnableWindow( this->getDlgItem(IDC_CHECK_WRITEBOM), FALSE );
			}
			else
			{
				::EnableWindow( this->getDlgItem(IDC_CHECK_WRITEBOM), FALSE );
				if ( vbWriteBOM_ == VARIANT_TRUE )
				{
					this->sendDlgItemMsg( IDC_CHECK_WRITEBOM, BM_SETCHECK, BST_CHECKED,0);
				}
				else
				{
					this->sendDlgItemMsg( IDC_CHECK_WRITEBOM, BM_SETCHECK, BST_UNCHECKED,0);
				}
			}
		}
	}
	return FALSE; // note: false! look into PSDK!
}

///////////////////////////////////////////////////////////////////////////////
// COM Methods
///////////////////////////////////////////////////////////////////////////////

HRESULT ScintillAxSettings::Apply( void)
{

	if ( BST_CHECKED == this->sendDlgItemMsg(IDC_RADIO_UNIX,BM_GETCHECK ,BST_CHECKED,0) )
		systype_ = SCINTILLA_SYSTYPE_UNIX;
	if ( BST_CHECKED == this->sendDlgItemMsg(IDC_RADIO_WIN32,BM_GETCHECK ,BST_CHECKED,0) )
		systype_ = SCINTILLA_SYSTYPE_WIN32;

	encoding_ = codePages_[combo_.getCurSel()].first;

	if ( BST_CHECKED == this->sendDlgItemMsg( IDC_CHECK_WRITEBOM,BM_GETCHECK,0,0) )
		vbWriteBOM_ = VARIANT_TRUE;
	else
		vbWriteBOM_ = VARIANT_FALSE;

	for ( unsigned int i = 0; i < objects_.size(); i++ )
	{	
		mol::punk<IScintillAx> sci(objects_[i]);
		if ( sci )
		{
			mol::punk<IScintillAxProperties> props;
			if ( S_OK == sci->get_Properties(&props) )
			{
				if ( S_OK != props->put_SysType(systype_) )
					continue;
				if ( S_OK != props->put_Encoding(encoding_) )
					continue;
				if ( S_OK != props->put_WriteBOM(vbWriteBOM_) )
					continue;
			}
		}
	}
	bDirty_ = FALSE;
	return S_OK;
}
