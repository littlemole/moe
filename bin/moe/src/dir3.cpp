#include "StdAfx.h"
#include "dir3.h"
#include "moe.h"
#include "Docs.h"
#include "MoeBar.h"
#include "xmlui.h"
#include "ole/Rib.h"
#include "win/TaskBar.h"

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
	if ( !mol::Path::exists(p) && ( (dir.size() > 8) && (dir.substr(0,8) != _T("shell:::") ) ) )
        return doc;

	if ( !mol::Path::isDir(p) && (dir.substr(0,8) != _T("shell:::")) )
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
	// initial Addref
	((IMoeDocument*)this)->AddRef();

	// determine window menu
	windowMenu_ = mol::UI().SubMenu(IDM_MOE_DIR,IDM_VIEW_WINDOWS);

	// create window
	create(p,(HMENU)mol::UI().Menu(IDM_MOE_DIR),mol::Rect(0,0,500,500),*moe());			

	// advise event sink
	list = oleObject;
	if (!list)
		return false;

	HRESULT hr = events.Advise(list);
	if ( hr != S_OK )
		return false;

	// set initial dirchild dir to display
	list->put_Selection(mol::variant(p));

	show(SW_SHOW);
	maximize();

	// display winows 7 task bar thumbnail
	thumb = mol::taskbar()->addTab( *this,p );

	filename_ = p;

	return true;
}


//////////////////////////////////////////////////////////////////////////////
//
// Close & Destroy 
//
//////////////////////////////////////////////////////////////////////////////

void DirChild::OnDestroy()
{
	//mol::string filename = getText();
	docs()->Remove(mol::variant(filename_));
	events.UnAdvise(oleObject);

}

void DirChild::OnNcDestroy()
{

	::CoDisconnectObject(((IMoeDocument*)this),0);
	((IMoeDocument*)this)->Release();
}

//////////////////////////////////////////////////////////////////////////////
//
// Child gets activated
//
//////////////////////////////////////////////////////////////////////////////


void DirChild::OnMDIActivate( HWND activated )
{
	mol::bstr filename;
	get_FilePath(&filename);
	statusBar()->status(filename.toString());
	tab()->select( filename.toString() );

	mol::Ribbon::ribbon()->mode(2);
	mol::Ribbon::ribbon()->maximize();
}




//////////////////////////////////////////////////////////////////////////////
// dirlist events sink
//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall DirChild::DirChild_Events::OnListDblClick(BSTR filename)
{
	mol::punk<IShellList> list(This()->oleObject);
	if ( list )
	{
		mol::string p(mol::toString(filename));
		if ( mol::Path::exists(p) )
		{		
			if ( mol::Path::isDir(p) )
			{
				return S_OK;
			}
			bool result = docs()->open(-1,p,Docs::PREF_TXT,false,0);
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
	statusBar()->status(mol::bstr(filename).toString());
	return S_OK;
}

HRESULT __stdcall DirChild::DirChild_Events::OnListOpen(BSTR filename)
{
	mol::string p(mol::toString(filename));
	bool result = docs()->open(-1,p,Docs::PREF_TXT,false,0);
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
	mol::string filename = This()->getText();

	//docs()->Rename( mol::variant(filename),mol::variant(dir));
	This()->setText( mol::bstr(dir).toString() );
	return S_OK;
}