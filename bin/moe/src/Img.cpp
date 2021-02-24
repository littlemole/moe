#include "stdafx.h"
#include "img.h"
#include "moe.h"
#include "Docs.h"
#include "MoeBar.h"

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

ImgViewer::ImgViewer()
{
	wndClass().setIcon(moe()->icon); 
	wndClass().hIconSm(moe()->icon); 
}

ImgViewer::~ImgViewer() 
{
	ODBGS("~ImgViewer dead");
};

ImgViewer::Instance* ImgViewer::CreateInstance( const std::wstring& file )
{
	Instance* iv = new Instance;
	iv->AddRef();

	
	statusBar()->status(30);

	if ( !iv->load(file) )
	{
		iv->Release();
		return 0;
	}
	statusBar()->status(100);
	return iv;
}

handle_msg(&ImgViewer::OnCreate,WM_CREATE)
void ImgViewer::OnCreate()
{
	show(SW_SHOW);
	activate();
}
//////////////////////////////////////////////////////////////////////////////

handle_msg(&ImgViewer::OnDestroy, WM_DESTROY)
LRESULT ImgViewer::OnDestroy()
{
	docs()->remove(this);
	return 0;
}

handle_msg(&ImgViewer::OnNcDestroy, WM_NCDESTROY)
LRESULT ImgViewer::OnNcDestroy()
{

	thumb.destroy();
	::CoDisconnectObject(((IMoeDocument*)this),0);
	((IMoeDocument*)this)->Release();
	return 0;
}


handle_cmd(&ImgViewer::OnCloseAll, IDM_VIEW_CLOSEALL)
LRESULT ImgViewer::OnCloseAll()
{
	return MoeChild<
		ImgViewer,
		mol::MdiChild,
		MOE_DOCTYPE_PIC,
		IDM_MOE_IMG
	>::OnCloseAll();
}

//////////////////////////////////////////////////////////////////////////////


handle_msg(&ImgViewer::OnPaint, WM_PAINT)
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
	thumb.refreshIcon();
}




//////////////////////////////////////////////////////////////////////////////

handle_msg(&ImgViewer::OnMDIActivate, WM_MDIACTIVATE)
void ImgViewer::OnMDIActivate( HWND activated )
{
	tab()->select( *this );
	updateUI();
}

handle_cmd(&ImgViewer::OnCloseAll, IDM_VIEW_CLOSEALL)


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// helpers
//
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

bool ImgViewer::load(const std::wstring& p)
{
	initializeMoeChild(p);
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

	statusBar()->status(80);
	move(0,0,s.cx+pt.x-rw.left,s.cy+pt.y-rw.top,TRUE);
	
	return true;
}

//////////////////////////////////////////////////////////////////////////////

void ImgViewer::updateUI()
{
	SIZE s = pic_.getSize();
	std::wostringstream oss;
	oss <<  s.cx << _T(" ");
	std::wostringstream oss2;
	oss2 << s.cy  << _T(" ");
	
	statusBar()->setText(getText(),oss.str(), oss2.str() );

	ribbon()->setAppMode("Img");
}

//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ImgViewer::get_Object( IDispatch **d)
{
	if ( !d )
		return E_INVALIDARG;
	*d = 0;
	   
	mol::punk<IPictureDisp> disp;
	HRESULT hr = pic_.copy(&disp);
	if ( hr != S_OK )
		return hr;

	return disp->QueryInterface( IID_IDispatch, (void**)d );
}