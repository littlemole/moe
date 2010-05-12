#include "StdAfx.h"
#include "dir.h"
#include "moe.h"
#include "Docs.h"
#include "xmlui.h"
#include "Ribbon.h"
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
	show(SW_SHOW);
	maximize();

	// advise event sink
	list = oleObject;
	//punk<IShellList> list(oleObject);
	if (!list)
		return false;

	HRESULT hr = sink.Advise(list);
	if ( hr != S_OK )
		return false;

	// set initial dirchild dir to display
	list->put_Selection(variant(p));

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

	sink.UnAdvise(oleObject);
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


void DirChild::OnMDIActivate( HWND activated )
{
	mol::bstr filename;
	get_Filename(&filename);
	moe()->SetStatus(filename);

	if ( mol::Ribbon::ribbon()->enabled())
	{
		Ribbon::ribbon()->mode(2);
		mol::Ribbon::ribbon()->maximize();
	}
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

HRESULT __stdcall DirChild::DirChild_sink::OnListDblClick(BSTR filename)
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


HRESULT __stdcall DirChild::DirChild_sink::OnListSelection(BSTR filename)
{
	moe()->SetStatus(filename);
	return S_OK;
}

HRESULT __stdcall DirChild::DirChild_sink::OnListOpen(BSTR filename)
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

HRESULT __stdcall DirChild::DirChild_sink::OnDirChanged(BSTR dir)
{
	docs()->Rename( mol::variant(This()->filename_),mol::variant(dir));
	This()->filename_ = mol::bstr(dir).toString();
	This()->setText( mol::bstr(dir).toString() );
	return S_OK;
}