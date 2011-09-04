#include "stdafx.h"
#include "hex.h"
#include "moe.h"
#include "xmlui.h"
#include "MoeBar.h"
#include "Ribbonres.h"

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

	statusBar()->status(30);

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
	initializeMoeChild(p);

	sink.Advise(oleObject);

	punk<IDispatch> disp;
	get_Object(&disp);
	punk<IHexCtrl> hexer(disp);
	if(!hexer)
	{
		return false;
	}

	statusBar()->status(80);
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
	scriptlet()->close();
	docs()->remove(this);
	sink.UnAdvise(oleObject);
}

void Hex::OnNcDestroy()
{
	::CoDisconnectObject(((IMoeDocument*)this),0);
	((IMoeDocument*)this)->Release();
}

//////////////////////////////////////////////////////////////////////////////

void Hex::OnMDIActivate(HWND activated)
{
	if ( activated == this->hWnd_ )
	{
		tab()->select( *this );
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

