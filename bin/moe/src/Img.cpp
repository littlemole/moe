#include "stdafx.h"
#include "img.h"
#include "moe.h"
#include "xmlui.h"
#include "ole/Rib.h"
#include "MoeBar.h"

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

ImgViewer::ImgViewer()
{
	//eraseBackground_ = 0;
	wndClass().setIcon(moe()->icon); 
	wndClass().hIconSm(moe()->icon); 
}

ImgViewer::~ImgViewer() 
{
	ODBGS("~ImgViewer dead");
};

ImgViewer::Instance* ImgViewer::CreateInstance( const mol::string& file )
{
	Instance* iv = new Instance;
	iv->AddRef();

	

	if ( !iv->load(file) )
	{
		iv->Release();
		return 0;
	}
	return iv;
}

void ImgViewer::OnCreate()
{
	show(SW_SHOW);
	activate();
}
//////////////////////////////////////////////////////////////////////////////

LRESULT ImgViewer::OnDestroy()
{
	return 0;
}

LRESULT ImgViewer::OnNcDestroy()
{
	mol::bstr filename;
	if ( S_OK == get_FilePath(&filename) )
	{
		mol::variant v(filename);
		docs()->Remove(v);
	}

	::CoDisconnectObject(((IMoeDocument*)this),0);
	((IMoeDocument*)this)->Release();
	return 0;
}
//////////////////////////////////////////////////////////////////////////////


void ImgViewer::OnPaint()
{
	static RECT clientRect;
	mol::PaintDC dc(*this);
	getClientRect(clientRect);
	if ( pic_ )
	{
		SIZE s = pic_.getSize();		
		int w = (clientRect.right - s.cx) / 2;
		int h = (clientRect.bottom - s.cy) / 2;
		mol::Rect r(w,h,w+s.cx,h+s.cy);
		pic_.render(dc,&r);
	}
}


//////////////////////////////////////////////////////////////////////////////

void ImgViewer::OnMDIActivate( HWND activated )
{
	tab()->select( getText() );
	updateUI();
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// helpers
//
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

bool ImgViewer::load(const mol::string& p)
{
	// determine window menu
	windowMenu_ = mol::UI().SubMenu(IDM_MOE_IMG,IDM_VIEW_WINDOWS );

	create(p,(HMENU)mol::UI().Menu(IDM_MOE_IMG),Rect(0,0,500,500),*moe());			
	show(SW_SHOW);
	//maximize();

	if (!pic_.load(p))
	{
		statusBar()->status(p + _T(" load failed") );
		return false;
	}

	SIZE s = pic_.getSize();
	RECT rw;
	getWindowRect(rw);
	mol::Point pt(0,0);
	client2Screen(pt);

	move(0,0,s.cx+pt.x-rw.left,s.cy+pt.y-rw.top,TRUE);
	return true;
}

//////////////////////////////////////////////////////////////////////////////

void ImgViewer::updateUI()
{
//	statusBar()->simple(false);

	SIZE s = pic_.getSize();
	mol::ostringstream oss;
	oss <<  s.cx << _T(" ");
	mol::ostringstream oss2;
	oss2 << s.cy  << _T(" ");
	
	statusBar()->setText(getText(),oss.str(), oss2.str() );

	if ( mol::Ribbon::ribbon()->enabled())
	{
		Ribbon::ribbon()->mode(3);
		mol::Ribbon::ribbon()->maximize();
	}
}


