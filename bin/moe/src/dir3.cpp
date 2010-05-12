#include "StdAfx.h"
#include "dir3.h"
#include "moe.h"
#include "Docs.h"
#include "MoeBar.h"
#include "xmlui.h"
#include "ole/Rib.h"

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

using namespace mol::io;

DirChild::DirChild( ) 
{
	eraseBackground_ = 1;
	wndClass().setIcon(moe()->icon); 
	wndClass().hIconSm(moe()->icon); 
}

//////////////////////////////////////////////////////////////////////////////

DirChild::~DirChild() 
{
	ODBGS("~DirChild dies");
};
/*
LRESULT DirChild::OnSize(UINT msg, WPARAM wParam, LPARAM lParam)
{
	mol::Rect clientRect_ = mol::Rect(0,0,0,0);

	// get new width and height
	clientRect_.right  = LOWORD(lParam) ;
	clientRect_.bottom = HIWORD(lParam) ;

	list->
	oleObject->
	oleObject->move(clientRect_);
	return 0;
}
*/
//////////////////////////////////////////////////////////////////////////////
// initialization
//////////////////////////////////////////////////////////////////////////////

DirChild::Instance* DirChild::CreateInstance( const mol::string& dir )
{
	Instance* doc = 0;

	if ( dir.size() < 1 )
		return doc;

	mol::string p(dir);
	if ( !mol::Path::exists(p) )
        return doc;

	if ( !mol::Path::isDir(p) )
		return doc;

	
	doc = new Instance;
	if (!doc->initialize(p))
	{
		doc->destroy();
		doc->Release();
		return 0;
	}


	return doc;
}

bool DirChild::initialize(const mol::string& p)
{
	filename_ = p;

	// initial Addref
	((IDoc*)this)->AddRef();

	// determine window menu
	windowMenu_ = mol::UI().SubMenu(IDM_MOE_DIR,IDM_VIEW_WINDOWS);

	// create window
	create(p,(HMENU)mol::UI().Menu(IDM_MOE_DIR),Rect(0,0,500,500),*moe());			

	// advise event sink
	list = oleObject;
	//punk<IShellList> list(oleObject);
	if (!list)
		return false;

	HRESULT hr = events.Advise(list);
	if ( hr != S_OK )
		return false;

	// set initial dirchild dir to display
	list->put_Selection(variant(p));

	show(SW_SHOW);
	maximize();

	this->redrawOleFrameLater();

	//this->OnLayout(0,0,0);
	//this->redraw();
	//mol::invoke<MoeWnd,LRESULT,UINT,WPARAM,LPARAM>( *moe(), &MoeWnd::OnLayout,(UINT)0,(WPARAM)0,(LPARAM)0 );
	//mol::invoke<MoeWnd,void>( *moe(), &MoeWnd::redraw);
	return true;
}


//////////////////////////////////////////////////////////////////////////////
//
// Close & Destroy 
//
//////////////////////////////////////////////////////////////////////////////

void DirChild::OnClose()
{
}


void DirChild::OnDestroy()
{
	docs()->Remove(mol::variant(filename_));
	events.UnAdvise(oleObject);
}

void DirChild::OnNcDestroy()
{
	::CoDisconnectObject(((IDoc*)this),0);
	((IDoc*)this)->Release();
}

//////////////////////////////////////////////////////////////////////////////
//
// Child gets activated
//
//////////////////////////////////////////////////////////////////////////////


LRESULT DirChild::OnMDIActivate( HWND activated )
{
	BaseWindowType::wndProc( hWnd_, WM_MDIACTIVATE, (WPARAM)0, (LPARAM)activated );

	//this->redrawOleFrame();

	if ( *this != activated )
		return 0;

	if ( activeObject.interface_ != 0 )
	{
		activeObject->OnDocWindowActivate(FALSE);												
	}

	mol::bstr filename;
	get_Filename(&filename);
	moe()->SetStatus(filename);
	tab()->select( filename.toString() );

	if ( mol::Ribbon::ribbon()->enabled())
	{
		Ribbon::ribbon()->mode(2);
		mol::Ribbon::ribbon()->maximize();
	}

    return 0;
}



//////////////////////////////////////////////////////////////////////////////
//
// COM section
//
//////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////

HRESULT __stdcall DirChild::get_Filename( BSTR* filename)
{
	if ( !filename )
		return E_INVALIDARG;

	*filename = 0;
	if ( !list )
		return S_OK;

	variant var;
	if ( S_OK == list->get_Selection(&var) )
	{
		if ( var.vt != VT_BSTR )
			var.changeType(VT_BSTR);
		if ( var.bstrVal != 0 )
			*filename = ::SysAllocString(var.bstrVal);
	}
	return S_OK;
}

/////////////////////////////////////////////////////////////////////

HRESULT __stdcall DirChild::get_Path( BSTR* path)
{	
	return get_Filename(path);
}

/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////

HRESULT __stdcall DirChild::get_Type(  long* type)
{
	if ( type )
	{
		*type = XMOE_DOCTYPE_DIR;
	}
	return S_OK;
}


HRESULT __stdcall  DirChild::Close()
{
	destroy();
	return S_OK;
}

HRESULT __stdcall  DirChild::Activate()
{
	activate();
	return S_OK;
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
// dirlist events sink
//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall DirChild::DirChild_Events::OnListDblClick(BSTR filename)
{
	punk<IShellList> list(This()->oleObject);
	if ( list )
	{
		mol::string p(mol::toString(filename));
		if ( mol::Path::exists(p) )
		{		
			if ( mol::Path::isDir(p) )
			{
				return S_OK;
			}
			bool result = docs()->open(0,p,Docs::PREF_TXT,false,0);
			if (!result)
			{
				mol::ostringstream oss;
				oss << _T("unable to open ") << p;
				statusBar()->status(oss.str());
			}
			else
			{
			}
			statusBar()->status(p);
		}
	}
	return S_OK;
}


HRESULT __stdcall DirChild::DirChild_Events::OnListSelection(BSTR filename)
{
	moe()->SetStatus(filename);
	return S_OK;
}

HRESULT __stdcall DirChild::DirChild_Events::OnListOpen(BSTR filename)
{
	mol::string p(mol::toString(filename));
	bool result = docs()->open(0,p,Docs::PREF_TXT,false,0);
	if (!result)
	{
		mol::ostringstream oss;
		oss << _T("unable to open ") << p;
		statusBar()->status(oss.str());
	}
	statusBar()->status(p);
	return S_OK;
}

HRESULT __stdcall DirChild::DirChild_Events::OnDirChanged(BSTR dir)
{
	docs()->Rename( mol::variant(This()->filename_),mol::variant(dir));
	This()->filename_ = mol::bstr(dir).toString();
	This()->setText( mol::bstr(dir).toString() );
	return S_OK;
}