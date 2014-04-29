#include "StdAfx.h"
#include "scpdir.h"
#include "moe.h"
#include "Docs.h"
//#include "xmlui.h"
//#include "ole/Rib.h"
#include "widgets.h"
#include "moeBar.h"
#include "xmlui.h"

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

using namespace mol::io;

ScpDirChild::ScpDirChild( ) 
{
	eraseBackground_ = 1;
	wndClass().setIcon(moe()->icon); 
	wndClass().hIconSm(moe()->icon); 
}

//////////////////////////////////////////////////////////////////////////////

ScpDirChild::~ScpDirChild() 
{
	ODBGS("~ScpDirChild dies");
};

//////////////////////////////////////////////////////////////////////////////
// initialization
//////////////////////////////////////////////////////////////////////////////

ScpDirChild::Instance* ScpDirChild::CreateInstance( ISSHConnection* conn, const std::wstring& dir )
{
	Instance* doc = 0;

	if ( dir.size() < 1 )
		return doc;
	
	doc = new Instance;
	if (!doc->initialize(dir))
	{
		doc->destroy();
		doc->Release();
		return 0;
	}
	if(conn)
	{
		mol::punk<IDispatch> disp(conn);
		if(disp)
			doc->list->put_Connection(disp);
	}
	return doc;
}

bool ScpDirChild::initialize(const std::wstring& p)
{
	filename_ = p;

	// initial Addref
	((IMoeDocument*)this)->AddRef();

	initializeMoeChild(p);

	// advise event sink
	list = oleObject;
	if (!list)
		return false;

	HRESULT hr = sink.Advise(list);
	if ( hr != S_OK )
		return false;

	// set initial dirchild dir to display
	list->put_Location(mol::bstr(p));

	return true;
}


//////////////////////////////////////////////////////////////////////////////
//
// Close & Destroy 
//
//////////////////////////////////////////////////////////////////////////////

void ScpDirChild::OnClose()
{
}


void ScpDirChild::OnDestroy()
{
	docs()->remove(this);
	sink.UnAdvise(oleObject);
}

void ScpDirChild::OnNcDestroy()
{
	::CoDisconnectObject(((IMoeDocument*)this),0);
	((IMoeDocument*)this)->Release();
}

//////////////////////////////////////////////////////////////////////////////
//
// Child gets activated
//
//////////////////////////////////////////////////////////////////////////////


void ScpDirChild::OnMDIActivate( HWND activated )
{
	mol::bstr filename;
	get_Filename(&filename);

	if ( activated == *this )
	{
		if ( mol::Ribbon::ribbon()->enabled())
		{
			mol::Ribbon::ribbon()->mode(2);
			mol::Ribbon::ribbon()->maximize();
		}
		statusBar()->status(filename.towstring());
		tab()->select( *this );
		moe()->redraw();
	}
}


//////////////////////////////////////////////////////////////////////////////
//
// COM section
//
//////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScpDirChild::get_Filename( BSTR* filename)
{
	if ( !filename )
		return E_INVALIDARG;

	*filename = 0;
	if ( !list )
		return S_OK;

	return list->get_Location(filename);
}

/////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScpDirChild::get_Path( BSTR* path)
{	
	if ( !path )
		return E_INVALIDARG;

	*path = 0;
	if ( !list )
		return S_OK;

	return list->get_Location(path);
}

/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScpDirChild::get_Type(  long* type)
{
	if ( type )
	{
		*type =  MOE_DOCTYPE_SFTP;
	}
	return S_OK;
}


HRESULT __stdcall  ScpDirChild::Close()
{
	destroy();
	return S_OK;
}

HRESULT __stdcall  ScpDirChild::Activate()
{
	activate();
	return S_OK;
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
// dirlist events sink
//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScpDirChild::DirChild_sink::OnListDblClick(BSTR filename,VARIANT_BOOL vb)
{
	docs()->open(mol::towstring(filename), MOE_DOCTYPE_SFTP, CP_ACP, false, 0);
	return S_OK;
}


HRESULT __stdcall ScpDirChild::DirChild_sink::OnListSelection(BSTR filename,VARIANT_BOOL vb)
{
	statusBar()->status(filename);
	return S_OK;
}

HRESULT __stdcall ScpDirChild::DirChild_sink::OnListOpen(BSTR filename,VARIANT_BOOL vb)
{
	docs()->open(mol::towstring(filename), MOE_DOCTYPE_SFTP, CP_ACP, false, 0);
	return S_OK;
}

HRESULT __stdcall ScpDirChild::DirChild_sink::OnDirChanged(BSTR dir)
{
	docs()->Rename( mol::variant(This()->filename_),mol::variant(dir));
	docs()->rename(This(), mol::towstring(dir));
	This()->filename_ = mol::towstring(dir);
	This()->setText(mol::towstring(dir));
	return S_OK;
}