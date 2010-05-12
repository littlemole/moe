#include "StdAfx.h"
#include "dir2.h"
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

void DirChild::refresh()
{
	oleObject.refresh();
}

void DirChild::cut()
{
	oleObject.cut();
}

void DirChild::copy()
{
	oleObject.copy();
}

void DirChild::paste()
{
	oleObject.paste();
}

void DirChild::rename()
{
	oleObject.rename();
}

void DirChild::erase()
{
	oleObject.erase();
}

void DirChild::execute()
{
	oleObject.execute();
}

void DirChild::updir()
{
	oleObject.updir();
}

void DirChild::newdir()
{

}

void DirChild::properties()
{

}



/////////////////////////////////////////////////////////////////////
 HRESULT __stdcall DirChild::get_App( IXmoe** m)
{			
	return ((IXmoe*)moe())->QueryInterface(IID_IXmoe,(void**)m);
}

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
	path_ = p;

	// initial Addref
	((IDoc*)this)->AddRef();

	// determine window menu
	windowMenu_ = mol::UI().SubMenu(IDM_MOE_DIR,IDM_VIEW_WINDOWS);

	// create window
	create(p,(HMENU)mol::UI().Menu(IDM_MOE_DIR),Rect(0,0,500,500),*moe());			

	show(SW_SHOW);
	maximize();

	return true;
}


void DirChild::OnCreate()
{
	RECT r;
	getClientRect(r);
	oleObject.create(0,r,*this);
	oleObject.path(path_);

	//mol::BorderLayout* layout = setLayout( new mol::BorderLayout );
	//layout->add(oleObject,mol::BorderLayout::FILL);
}

LRESULT DirChild::OnSize(UINT msg, WPARAM wParam, LPARAM lParam)
{
	mol::Rect clientRect_ = mol::Rect(0,0,0,0);

	// get new width and height
	clientRect_.right  = LOWORD(lParam) ;
	clientRect_.bottom = HIWORD(lParam) ;

	oleObject.move(clientRect_);
	return 0;
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
	docs()->Remove(mol::variant(path_));
	oleObject.dispose();
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
	path_ = oleObject.path();
	moe()->SetStatus(mol::bstr(path_));

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

	*filename = ::SysAllocString( mol::towstring(oleObject.path()).c_str() );
	return S_OK;
	
}

/////////////////////////////////////////////////////////////////////

HRESULT __stdcall DirChild::get_Path( BSTR* path)
{	
	*path = ::SysAllocString( mol::towstring(oleObject.path()).c_str() );
	return S_OK;
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

void DirChild::Folder::OnUserSelect(std::vector<mol::string>& v)
{
	for ( size_t i = 0; i < v.size(); i++ )
	{
		docs()->open(0,v[i],Docs::PREF_TXT,false,0);
	}
}
