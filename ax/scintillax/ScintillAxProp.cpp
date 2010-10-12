#include "StdAfx.h"
#include "ScintillAxProp.h"

///////////////////////////////////////////////////////////////////////////////
// Message Handlers
///////////////////////////////////////////////////////////////////////////////
LRESULT ScintillAxProperties::OnDirty(UINT msg, WPARAM wParam, LPARAM lParam)
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

LRESULT ScintillAxProperties::OnConvert(UINT msg, WPARAM wParam, LPARAM lParam)
{
	for ( unsigned int i = 0; i < objects_.size(); i++ )
	{	
		mol::punk<IScintillAx> sci(objects_[i]);
		if ( sci )
		{
			sci->ConvertTabs();
		}
	}
	return 0;
}

LRESULT ScintillAxProperties::OnInitDialog(UINT msg, WPARAM wParam, LPARAM lParam)
{
	combo_.attach(getDlgItem(IDC_COMBO_ENCODING));
	combo_.addString(_T("Ansi"));
	combo_.addString(_T("UTF8"));
	combo_.addString(_T("UTF16 (LE)"));

	if ( objects_.size() > 0 )
	{
		mol::punk<IScintillAx> sci(objects_[0]);
		if ( sci )
		{
			if ( S_OK != sci->get_SysType(&systype_) )
				return FALSE;
			if ( S_OK != sci->get_Encoding(&encoding_) )
				return FALSE;
			if ( S_OK != sci->get_TabWidth(&tabwidth_) )
				return FALSE;
			if ( S_OK != sci->get_WriteBOM(&vbWriteBOM_) )
				return FALSE;
			if ( S_OK != sci->get_ShowLineNumbers(&vbShowLineNumbers_) )
				return FALSE;

			if ( S_OK != sci->get_TabUsage(&vbUseTabs_) )
				return FALSE;
			if ( S_OK != sci->get_TabIndents(&vbTabIndents_) )
				return FALSE;
			if ( S_OK != sci->get_BackSpaceUnindents(&vbBackSpaceUnindents_) )
				return FALSE;

			if ( systype_ == SCINTILLA_SYSTYPE_UNIX )
				this->sendDlgItemMsg(IDC_RADIO_UNIX,BM_SETCHECK ,BST_CHECKED,0);
			if ( systype_ == SCINTILLA_SYSTYPE_WIN32 )
				this->sendDlgItemMsg(IDC_RADIO_WIN32,BM_SETCHECK ,BST_CHECKED,0);

			combo_.setCurSel(encoding_);
			this->setDlgItemInt(IDC_EDIT_TABWIDTH,tabwidth_);

			if ( vbUseTabs_ == VARIANT_TRUE )
				this->sendDlgItemMsg( IDC_CHECK_USETABS,BM_SETCHECK ,BST_CHECKED,0);
			if ( vbTabIndents_ == VARIANT_TRUE )
				this->sendDlgItemMsg( IDC_CHECK_TABINDENTS,BM_SETCHECK ,BST_CHECKED,0);
			if ( vbBackSpaceUnindents_ == VARIANT_TRUE )
				this->sendDlgItemMsg( IDC_CHECK_BACKSPACEUNINDENTS,BM_SETCHECK ,BST_CHECKED,0);			

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

	if ( BST_CHECKED == this->sendDlgItemMsg(IDC_RADIO_UNIX,BM_GETCHECK ,BST_CHECKED,0) )
		systype_ = SCINTILLA_SYSTYPE_UNIX;
	if ( BST_CHECKED == this->sendDlgItemMsg(IDC_RADIO_WIN32,BM_GETCHECK ,BST_CHECKED,0) )
		systype_ = SCINTILLA_SYSTYPE_WIN32;

	encoding_ = combo_.getCurSel();

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

	if ( BST_CHECKED == this->sendDlgItemMsg( IDC_CHECK_WRITEBOM,BM_GETCHECK,0,0) )
		vbWriteBOM_ = VARIANT_TRUE;
	else
		vbWriteBOM_ = VARIANT_FALSE;

	if ( BST_CHECKED == this->sendDlgItemMsg( IDC_CHECK_LINE_NUMBERS,BM_GETCHECK,0,0) )
		vbShowLineNumbers_ = VARIANT_TRUE;
	else
		vbShowLineNumbers_ = VARIANT_FALSE;

	for ( unsigned int i = 0; i < objects_.size(); i++ )
	{	
		mol::punk<IScintillAx> sci(objects_[i]);
		if ( sci )
		{
			if ( S_OK != sci->put_SysType(systype_) )
				continue;
			if ( S_OK != sci->put_Encoding(encoding_) )
				continue;
			if ( S_OK != sci->put_TabWidth(tabwidth_) )
				continue;

			if ( S_OK != sci->put_TabUsage(vbUseTabs_) )
				continue;
			if ( S_OK != sci->put_TabIndents(vbTabIndents_) )
				continue;
			if ( S_OK != sci->put_BackSpaceUnindents(vbBackSpaceUnindents_) )
				continue;
			if ( S_OK != sci->put_WriteBOM(vbWriteBOM_) )
				continue;
			if ( S_OK != sci->put_ShowLineNumbers(vbShowLineNumbers_) )
				continue;
		}
	}
	bDirty_ = FALSE;
	return S_OK;
}