#include "StdAfx.h"
#include "dir3.h"
#include "moe.h"
#include "Docs.h"
#include "MoeBar.h"
#include "xmlui.h"
#include "win/msgmap.h"

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

DirChild::Instance* DirChild::CreateInstance( const std::wstring& dir )
{
	Instance* doc = 0;

	if ( dir.size() < 1 )
		return doc;

	std::wstring p(dir);
	if ( !mol::Path::exists(p) && ( (dir.size() > 8) && (dir.substr(0,8) != _T("shell:::") ) && (dir.substr(0,2) != _T("::") ) ) )
        return doc;

	if ( !mol::Path::isDir(p) && (dir.substr(0,8) != _T("shell:::") && (dir.substr(0,2) != _T("::") )) )
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

bool DirChild::initialize(const std::wstring& p)
{
	// initial Addref
	((IMoeDocument*)this)->AddRef();

	initializeMoeChild(p);

	// advise event sink
	list = oleObject;
	if (!list)
		return false;

	HRESULT hr = events.Advise(list);
	if ( hr != S_OK )
		return false;

	// set initial dirchild dir to display
	list->put_Selection(mol::variant(p));

	location_ = p;

	OnLayout(0,0,0);
	return true;
}



//////////////////////////////////////////////////////////////////////////////
//
// Close & Destroy 
//
//////////////////////////////////////////////////////////////////////////////

handle_msg(&DirChild::OnDestroy,WM_DESTROY)
void DirChild::OnDestroy()
{
	docs()->remove(this);
	events.UnAdvise(oleObject);

}

handle_msg(&DirChild::OnNcDestroy, WM_NCDESTROY)
void DirChild::OnNcDestroy()
{
	thumb.destroy();
	::CoDisconnectObject(((IMoeDocument*)this),0);
	((IMoeDocument*)this)->Release();
}


HRESULT __stdcall DirChild::get_FilePath( BSTR *fname)
{
	if ( fname  )
	{
		*fname = 0;
		*fname = ::SysAllocString( mol::towstring(location_).c_str() );
	}
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////
//
// Child gets activated
//
//////////////////////////////////////////////////////////////////////////////

handle_msg(&DirChild::OnMDIActivate, WM_MDIACTIVATE)
void DirChild::OnMDIActivate( HWND activated )
{
	if ( activated == *this )
	{
		Json::Value json(Json::objectValue);
		json["doctype"] = MOE_DOCTYPE_DIR;
		json["appmode"] = "Directory";

		std::string utf8 = JSON::flatten(json);
		ribbon()->setAppMode("Directory");
		ribbon()->oleObject->PostWebMessageAsJson(mol::fromUTF8(utf8).c_str());
/*

		if ( mol::Ribbon::ribbon()->enabled())
		{
			mol::Ribbon::ribbon()->mode(2);
			mol::Ribbon::ribbon()->maximize();
		}
		*/
		statusBar()->status(location_);
		tab()->select( *this );
	}
	
}



//////////////////////////////////////////////////////////////////////////////
// dirlist events sink
//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall DirChild::DirChild_Events::OnListDblClick(BSTR filename)
{
	mol::punk<IShellList> list(This()->oleObject);
	if ( list )
	{
		std::wstring p(mol::towstring(filename));
		if ( mol::Path::exists(p) )
		{		
			if ( mol::Path::isDir(p) )
			{
				return S_OK;
			}
			bool result = docs()->open(p,MOE_DOCTYPE_DOC,-1,false,0);
			if (!result)
			{
				std::wostringstream oss;
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
	statusBar()->status(mol::bstr(filename).towstring());
	return S_OK;
}

HRESULT __stdcall DirChild::DirChild_Events::OnListOpen(BSTR filename)
{
	std::wstring p(mol::towstring(filename));
	bool result = docs()->open(p,MOE_DOCTYPE_DOC,-1,false,0);
	if (!result)
	{
		std::wostringstream oss;
		oss << _T("unable to open ") << p;
		statusBar()->status(oss.str());
	}
	statusBar()->status(p);
	return S_OK;
}

HRESULT __stdcall DirChild::DirChild_Events::OnDirChanged(BSTR dir)
{
	This()->location_ = mol::towstring(dir);
	docs()->rename( This(),This()->location_ );
	This()->setText( This()->location_ );
	return S_OK;
}

handle_cmd(&DirChild::OnCloseAll, IDM_VIEW_CLOSEALL)

handle_ole_cmd(DirChild, IDM_EDIT_UPDATE, &IShellPane::Update)
handle_ole_cmd(DirChild, IDM_EDIT_CUT, &IShellPane::Cut)
handle_ole_cmd(DirChild, IDM_EDIT_COPY, &IShellPane::Copy)
handle_ole_cmd(DirChild, IDM_EDIT_PASTE, &IShellPane::Paste)
handle_ole_cmd(DirChild, IDM_FILE_DIREXEC, &IShellPane::Execute)
handle_ole_cmd(DirChild, IDM_FILE_DIRPROP, &IShellPane::Properties)
handle_ole_cmd(DirChild, IDM_FILE_NEWDIR, &IShellPane::CreateDir)
handle_ole_cmd(DirChild, IDM_FILE_UPDIR, &IShellPane::UpDir)

