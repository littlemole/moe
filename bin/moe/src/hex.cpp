#include "stdafx.h"
#include "hex.h"
#include "moe.h"
#include "xmlui.h"
#include "MoeBar.h"
#include "Ribbonres.h"
#include "ole/Rib.h"

using namespace mol::io;

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// Base Child
//////////////////////////////////////////////////////////////////////////////

Hex::Hex() 
{
    eraseBackground_ = 1;
	wndClass().setIcon(moe()->icon); 
	wndClass().hIconSm(moe()->icon); 
}
//////////////////////////////////////////////////////////////////////////////

Hex::~Hex() 
{
	ODBGS("~Hex dead");
};

//////////////////////////////////////////////////////////////////////////////
Hex::Instance* Hex::CreateInstance(const mol::string& file, bool readOnly)
{
	mol::string p(file);
	if ( mol::Path::exists(p) && mol::Path::isDir(p) )
		return 0;

	Instance* e = new Instance;
	e->AddRef();

	if (!e->initialize(p,readOnly))
	{
		e->destroy();
		e->Release();
		return 0;
	}
	return e;
}

bool Hex::initialize(const mol::string& p, bool readOnly)
{
	// determine window menu
	windowMenu_ = mol::UI().SubMenu( IDM_MOE_DIR, IDM_VIEW_WINDOWS );

	HWND hc = create(p,(HMENU)mol::UI().Menu(IDM_MOE_HEX),Rect(0,0,500,500),*moe());

	// determine window menu
	HMENU m = mol::UI().Menu(IDM_MOE);
	windowMenu_ = mol::UI().SubMenu( IDM_MOE_HEX ,IDM_VIEW_WINDOWS);

	sink.Advise(oleObject);
	show(SW_SHOW);
	maximize();

	punk<IDispatch> disp;
	get_Document(&disp);
	punk<IHexCtrl> hexer(disp);
	if(!hexer)
	{
		return false;
	}

	if ( mol::Path::exists(p) )
	{
		VARIANT_BOOL vb;
		if ( readOnly )
		{
			if ( S_OK != hexer->OpenReadOnly(bstr(p),&vb) || vb != VARIANT_TRUE )
			{
				return false;
			}
		}
		else
		{
			if ( S_OK != hexer->Open(bstr(p),&vb) || vb != VARIANT_TRUE )
			{
				return false;
			}
		}
	}
	return true;
}

//////////////////////////////////////////////////////////////////////////////
//
// OnDestroy - over and out
//
//////////////////////////////////////////////////////////////////////////////
void Hex::OnClose()
{
}

void Hex::OnDestroy()
{
	mol::bstr filename;
	if ( S_OK == get_Filename(&filename) )
	{
		mol::variant v(filename);
		docs()->Remove(v);
	}

	sink.UnAdvise(oleObject);

}

void Hex::OnNcDestroy()
{
	::CoDisconnectObject(((IDoc*)this),0);
	((IDoc*)this)->Release();
}

//////////////////////////////////////////////////////////////////////////////

void Hex::OnMDIActivate(HWND activated)
{
	if ( activated == this->hWnd_ )
	{
		tab()->select( getText() );
		statusBar()->status( getText() );
		updateUI();
		setFocus();
	}
}


void Hex::OnFind()
{
	::PostMessage(mdiParent(),WM_COMMAND,IDM_EDIT_FIND,0);
}


void Hex::OnSearch(FINDREPLACE* find)
{
   punk<IHexCtrl> hexer(oleObject);
   if (hexer)
   {
		hexer->Search( bstr(find->lpstrFindWhat),find->Flags);
   }
}

void Hex::OnHexRange(int code, int id, HWND ctrl)
{
   punk<IHexCtrl> hexer(oleObject);
   if (hexer)
   {
		hexer->put_DisplayColumns( (id-IDM_EDIT_16BYTES)*4+16);
   }   
}


void Hex::OnBytesShown()
{
	punk<IHexCtrl> hexer(oleObject);
    if (!hexer)
		return;

	int bytes = mol::Ribbon::handler(RibbonBytesShown)->index();

	hexer->put_DisplayColumns(bytes*4+16);
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// helpers
//
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
void Hex::OnMenu(HMENU popup)
{
}

//////////////////////////////////////////////////////////////////////////////

void Hex::updateUI()
{
	bstr path;
	mol::string title = this->getText();;

	punk<IHexCtrl> hexer(oleObject);
	if ( hexer )
		if ( S_OK == hexer->get_Filename(&path) && path)
		{
			title = path.toString();	
		}

	setText(title);

	if ( mol::Ribbon::ribbon()->enabled())
	{
		Ribbon::ribbon()->mode(4);
		mol::Ribbon::ribbon()->maximize();

		if ( hexer )
		{
			long c = 0;
			if ( S_OK == hexer->get_DisplayColumns(&c) )
			{
				int index = (c-16)/4;
				Ribbon::handler(RibbonBytesShown)->select( index );
			}
		}
	}


}


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////
//
// COM section
//
//////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////

HRESULT __stdcall Hex::get_Filename( BSTR* filename)
{
	if ( !filename )
	{
		return E_INVALIDARG;
	}
	if ( filename )
	{
		punk<IHexCtrl> hexer(oleObject);
		if ( hexer )
		{
			HRESULT hr = hexer->get_Filename(filename);
			return hr;
		}
	}
	return S_FALSE;
}

/////////////////////////////////////////////////////////////////////
HRESULT __stdcall Hex::get_Path( BSTR* p)
{			
	if (!p)
		return E_POINTER;

	bstr bstr;
	if ( S_OK == this->get_Filename(&bstr) )
	{
		if ( bstr )
		{
			mol::string tmp(mol::Path::parentDir(bstr.toString()));
			*p = ::SysAllocString(mol::towstring(tmp).c_str());
			return S_OK;
		}
	}
	*p = 0;
	return S_OK;
}


/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////

HRESULT __stdcall Hex::get_Type(  long* type)
{
	if ( type )
	{
		*type = XMOE_DOCTYPE_HEX;
	}
	return S_OK;
}


HRESULT __stdcall  Hex::Close()
{
	postMessage(WM_CLOSE,0,0);
	return S_OK;
}


/////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall  Hex::Activate()
{
	//!!!!!!!!!!!!
	activate();
	updateUI();
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////