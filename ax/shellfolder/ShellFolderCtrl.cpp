#include "stdafx.h"
#include "ShellFolderCtrl.h"
#include "ole/Bstr.h"
#include "ole/enum.h"
#include "ole/Img.h"
#include "util/str.h"
#include "shellfolder_dispid.h"
#include <sstream>


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

ShellFolderCtrl::ShellFolderCtrl(void)	
{
	displayFiles_ = true;
	eraseBackground_ = 1;

	sizel.cx = 300;
	sizel.cy = 200;
	mol::ole::PixeltoHIMETRIC(&sizel);
}

//////////////////////////////////////////////////////////////////////////////

ShellFolderCtrl::~ShellFolderCtrl()
{
	
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void ShellFolderCtrl::Folder::OnUserSelect(std::vector<std::wstring>& v)
{
	for ( size_t i = 0; i < v.size(); i++ )
	{
		This()->fire(DISPID_ISHELLPANEEVENTS_ONLISTOPEN,mol::bstr(v[i]));
	}
}


void ShellFolderCtrl::Folder::OnPathChanged( const std::wstring& p)
{
	This()->fire(DISPID_ISHELLPANEEVENTS_ONDIRCHANGED,mol::bstr(p));
}

//////////////////////////////////////////////////////////////////////////////
//
// OnDestroy - over and out
//
//////////////////////////////////////////////////////////////////////////////

LRESULT ShellFolderCtrl::OnDestroy(UINT msg, WPARAM wParam, LPARAM lParam)
{
    return 0;
}
//////////////////////////////////////////////////////////////////////////////

LRESULT ShellFolderCtrl::OnCreate(UINT msg, WPARAM wParam, LPARAM lParam)
{
	ODBGS("ShellFolderCtrl::OnCreate");
	

    RECT clientRect;
	getClientRect(clientRect); //!!!!!

	wnd_.create(0,clientRect,*this);
	wnd_.setRedraw(false);

	std::wstring s = mol::io::desktop().getDisplayNameOf(*mol::io::desktop().getSpecialFolder(CSIDL_DESKTOP));
	wnd_.path(s);
	wnd_.setFocus();	
	wnd_.show(SW_SHOW);
	wnd_.setRedraw(true);
	return 0;
}

LRESULT ShellFolderCtrl::OnSize(UINT msg, WPARAM wParam, LPARAM lParam)
{
	ODBGS("ShellFolderCtrl::OnSize");
	getClientRect(clientRect_);
		
	// get new width and height
	clientRect_.right  = LOWORD (lParam) ;
	clientRect_.bottom = HIWORD (lParam) ;

	ODBGS1("sfc right:",clientRect_.right);
	ODBGS1("sfc bottom:",clientRect_.bottom);

	//wnd_.move(clientRect_); -- no, have to be more explicit here

	::SetWindowPos( wnd_, NULL, 0,0, clientRect_.right, clientRect_.bottom,SWP_NOZORDER|SWP_DRAWFRAME|SWP_FRAMECHANGED|SWP_NOACTIVATE|SWP_NOOWNERZORDER|SWP_NOMOVE|SWP_NOCOPYBITS);
	::RedrawWindow( wnd_,NULL,NULL,RDW_FRAME|RDW_INVALIDATE|RDW_UPDATENOW|RDW_ALLCHILDREN|RDW_INTERNALPAINT);
	ODBGS("ShellFolderCtrl::OnSize END");
	return 0;
}
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// Up Dir
//
//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ShellFolderCtrl::UpDir()
{
	wnd_.updir();	
	fire(DISPID_ISHELLPANEEVENTS_ONDIRCHANGED,mol::bstr(wnd_.path()));
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////
//
// Update focused dir
//
//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ShellFolderCtrl::Update()
{
	wnd_.refresh();
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ShellFolderCtrl::CreateDir()
{
	wnd_.newdir();
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ShellFolderCtrl::Rename()
{
	wnd_.rename();
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////
//
// delete selected tree or dir item
//
//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ShellFolderCtrl::Delete()
{
	wnd_.erase();
	return S_OK;
}

HRESULT __stdcall ShellFolderCtrl::Properties()
{
	wnd_.properties();
	return S_OK;
}

HRESULT __stdcall ShellFolderCtrl::Execute()
{
	wnd_.execute();
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////
//
// open selected dir
//
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ShellFolderCtrl::Cut ()
{
	wnd_.cut();
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ShellFolderCtrl::Copy ()
{
	wnd_.copy();
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ShellFolderCtrl::Paste ()
{
	wnd_.paste();
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

void ShellFolderCtrl::setPath(const std::wstring& p)  
{ 
	setText(p); 
	wnd_.path(p);
	this->fire(DISPID_ISHELLPANEEVENTS_ONLISTSELECTION,p);
	this->fire(DISPID_ISHELLPANEEVENTS_ONDIRCHANGED,p);
	this->OnChanged(2);
}


///////////////////////////////////////////////////////////////////////
// selection
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ShellFolderCtrl::get_Selection		( VARIANT* dirname )
{
	if ( dirname )
	{
		::VariantClear(dirname);
		
		dirname->vt = VT_BSTR;
		dirname->bstrVal = ansi2BSTR(mol::tostring(wnd_.path()));
	}
	return S_OK;
}

HRESULT __stdcall ShellFolderCtrl::put_Selection		( VARIANT  dirname )
{
	if ( S_OK != OnRequestEdit(2) )
		return S_FALSE;

	if ( dirname.vt == VT_BSTR )
	{
		bstr b(dirname.bstrVal);
		if ( (b.tostring() == "")  || 
			 (b.tostring() == "/") ||
			 (b.tostring() == "\\") )
		{
			b = _T("::{20D04FE0-3AEA-1069-A2D8-08002B30309D}");
		}
		setPath(b.towstring());
	}
	return S_OK;
}

///////////////////////////////////////////////////////////////////////
// displayfiles
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ShellFolderCtrl::get_DisplayFiles	( VARIANT_BOOL* vb )
{
	if ( vb )
	{
		if ( wnd_.displayFiles() )
			*vb = VARIANT_TRUE;
		else
			*vb = VARIANT_FALSE;
	}
	return S_OK;
}

HRESULT __stdcall ShellFolderCtrl::put_DisplayFiles	( VARIANT_BOOL vb  )
{
	if ( S_OK != OnRequestEdit(1) )
		return S_FALSE;

	if ( vb == VARIANT_TRUE )
		wnd_.displayFiles(true);
	else
		wnd_.displayFiles(false);

	this->OnChanged(1);
	return S_OK;
}

HRESULT __stdcall ShellFolderCtrl::get_HasFocus( VARIANT_BOOL* vbHasFocus)
{
	if ( vbHasFocus )
	{
		if ( wnd_.hasFocus() )
		{
			*vbHasFocus = VARIANT_TRUE;
		}
		else
		{
			*vbHasFocus = VARIANT_FALSE;
		}
	}
	return S_OK;
}


HRESULT __stdcall ShellFolderCtrl::Load( LPSTREAM pStm)
{
	pStm >> mol::property( mol::DispId(this,ShellFolderCtrl_Dispatch_DisplayFiles,VT_BOOL) )
		 >> mol::property( mol::DispId(this,ShellFolderCtrl_Dispatch_Selection,VT_BSTR) )
		 >> mol::property( &sizel );

	return S_OK;
}

HRESULT __stdcall ShellFolderCtrl::Save( LPSTREAM pStm,BOOL fClearDirty)
{
	pStm << mol::property( mol::DispId(this,ShellFolderCtrl_Dispatch_DisplayFiles,VT_BOOL) )
		 << mol::property( mol::DispId(this,ShellFolderCtrl_Dispatch_Selection,VT_BSTR) )
		 << mol::property( &sizel );

	return S_OK;
}

HRESULT __stdcall ShellFolderCtrl::Load( IPropertyBag *pPropBag,IErrorLog *pErrorLog)
{
	pPropBag >> mol::property( _T("displayfiles"), mol::DispId(this,ShellFolderCtrl_Dispatch_DisplayFiles,VT_BOOL) )
			 >> mol::property( _T("selection"), mol::DispId(this,ShellFolderCtrl_Dispatch_Selection,VT_BSTR) )
			 >> mol::property( _T("cs"), &sizel );

	return S_OK;
}

HRESULT __stdcall ShellFolderCtrl::Save( IPropertyBag *pPropBag,BOOL fClearDirty,BOOL fSaveAllProperties)
{
	pPropBag << mol::property( _T("displayfiles"), mol::DispId(this,ShellFolderCtrl_Dispatch_DisplayFiles,VT_BOOL) )
			 << mol::property( _T("sSelection"), mol::DispId(this,ShellFolderCtrl_Dispatch_Selection,VT_BSTR) )
			 << mol::property( _T("cs"), &sizel );

	return S_OK;
}

