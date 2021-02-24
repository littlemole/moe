#include "stdafx.h"
#include "mdichild.h"
#include "moe.h"

FILETIME getLastWriteTime(const std::wstring& path)
{
	mol::filestream fs;
	FILETIME ft = {0,0};
	bool b = fs.open( mol::tostring(path),GENERIC_READ,FILE_SHARE_READ,0,OPEN_EXISTING);
	if (!b )
		return ft;

	ft = fs.fileInfo().ftLastWriteTime;
	fs.close();
	return ft;
}

MoeChildView::~MoeChildView()
{
	ODBGS("~MoeChildView dies ...");
}


bool MoeChildView::CreateInstance( mol::MdiChild* wnd, IMoeDocumentView** v )
{
	if (!v)
		return false;

	*v = 0;

	Instance* i = new Instance;
	i->wnd_ = wnd;

	HRESULT hr = i->QueryInterface( IID_IMoeDocumentView, (void**) v);
	if ( S_OK == hr )
		return true;

	*v = 0;
	delete i;
	return false;
}

void MoeChildView::dispose() 
{
}

REFGUID MoeChildView::getCoClassID()
{
	return IID_IMoeDocumentView;
}

/////////////////////////////////////////////////////////////////////
HRESULT __stdcall MoeChildView::get_Top( long* top)
{
	if ( top )
	{
		RECT r;
		wnd_->getWindowRect(r);
		mol::Point p(r.left,r.top);
		::ScreenToClient( wnd_->mdiClient(), &p);
		*top = p.y;
	}
	return S_OK;
}

HRESULT __stdcall MoeChildView::put_Top( long top)
{
	RECT r;
	wnd_->getWindowRect(r);
	int w = r.right-r.left;
	int h = r.bottom-r.top;

	mol::Point p(r.left,r.top);
	::ScreenToClient(wnd_->mdiClient(), &p);

	p.y = top;
	h  += top-p.y;

	wnd_->move(p.x,p.y,w,h);
	return S_OK;
}

/////////////////////////////////////////////////////////////////////

HRESULT __stdcall MoeChildView::get_Left( long* left)
{
	if ( left )
	{
		RECT r;
		wnd_->getWindowRect(r);
		mol::Point p(r.left,r.top);
		::ScreenToClient( wnd_->mdiClient(), &p);
		*left = p.x;
	}
	return S_OK;
}

HRESULT __stdcall MoeChildView::put_Left( long left)
{
	RECT r;
	wnd_->getWindowRect(r);
	int w = r.right-r.left;
	int h = r.bottom-r.top;

	mol::Point p(r.left,r.top);
	::ScreenToClient(wnd_->mdiClient(), &p);

	p.x = left;
	w += left-p.x;

	wnd_->move(p.x,p.y,w,h);
	return S_OK;
}

/////////////////////////////////////////////////////////////////////
HRESULT __stdcall MoeChildView::get_Width( long* width)
{
	if ( width )
	{
		RECT r;
		wnd_->getWindowRect(r);
		mol::Point p(r.left,r.top);
		*width = r.right -r.left;
	}
	return S_OK;
}

HRESULT __stdcall MoeChildView::put_Width( long width)
{
	RECT r;
	wnd_->getWindowRect(r);
	int w = width;
	int h = r.bottom-r.top;

	mol::Point p(r.left,r.top);
	::ScreenToClient(wnd_->mdiClient(), &p);

	wnd_->move(p.x, p.y, w, h);
	return S_OK;
}

/////////////////////////////////////////////////////////////////////
HRESULT __stdcall MoeChildView::get_Height( long* height)
{
	if ( height )
	{
		RECT r;
		wnd_->getWindowRect(r);
		mol::Point p(r.left,r.top);
		*height = r.bottom -r.top;
	}
	return S_OK;
}

HRESULT __stdcall MoeChildView::put_Height( long height)
{
	RECT r;
	wnd_->getWindowRect(r);
	int w = r.right-r.left;
	int h = height;

	mol::Point p(r.left,r.top);
	::ScreenToClient(wnd_->mdiClient(), &p);

	wnd_->move(p.x, p.y, w, h);
	return S_OK;
}

HRESULT __stdcall MoeChildView::Show()
{
	wnd_->show(SW_SHOW);
	return S_OK;
}

HRESULT __stdcall MoeChildView::Hide()
{
	wnd_->show(SW_HIDE);
	return S_OK;
}

HRESULT __stdcall MoeChildView::Close()
{
	LRESULT r = wnd_->sendMessage(WM_CLOSE,0,0);
	return r == 0 ? S_OK : S_FALSE;
}

HRESULT __stdcall MoeChildView::Minimize()
{
	wnd_->minimize();
	return S_OK;
}

HRESULT __stdcall MoeChildView::Maximize()
{
	wnd_->maximize();
	return S_OK;
}

HRESULT __stdcall MoeChildView::Restore()
{
	wnd_->restore();
	return S_OK;
}

HRESULT __stdcall MoeChildView::Activate()
{
	moe()->restore();
	wnd_->activate();
	return S_OK;
}

