#include "win/Taskbar.h"
#include "win/mdi.h"
#include <dwmapi.h>


#define min std::min
#define max std::max

#include <gdiplus.h>

#undef min
#undef max

typedef BOOL __stdcall PrintWindowPtr( HWND hwnd, HDC hdcBlt, UINT nFlags );
PrintWindowPtr* PrintWindow2 = (PrintWindowPtr*)mol::dllFunc( _T("User32.dll"), _T("PrintWindow") );

namespace mol {
namespace win {



void TaskbarWnd::timer_callback()
{
	this->cacheIconicRepresentation();
	//ODBGS("refreshIcon");
	this->timer_.kill();
}


TaskbarWnd::TaskbarWnd( Taskbar* tb, HWND d, ITaskbarList4* tbl, bool disabled )
{
	tb_ = tb;
	doc = d;
	tbl_ = tbl;
	hbm_cached_ = 0;
	disabled_ = disabled;
	deleteOnNCDestroy_ = false;
}

TaskbarWnd::~TaskbarWnd()
{
	if ( tbl_ )
		tbl_.release();

    if (hbm_cached_)
    {
        DeleteObject(hbm_cached_);
    }
}



void TaskbarWnd::enableTabs(bool b)
{
	if ( disabled_ ) 
	{
		b = false;
	}

	BOOL fForceIconic = b;
    BOOL fHasIconicBitmap = b;
	BOOL fDisallowPeek = b;

	DwmSetWindowAttribute(
		*this,
		DWMWA_FORCE_ICONIC_REPRESENTATION,
		&fForceIconic,
		sizeof(fForceIconic));

		
	DwmSetWindowAttribute(
		*this,
		DWMWA_HAS_ICONIC_BITMAP,
		&fHasIconicBitmap,
		sizeof(fHasIconicBitmap));
/*
	DwmSetWindowAttribute(
		hWnd,
		DWMWA_DISALLOW_PEEK,
		&fDisallowPeek,
		sizeof(fDisallowPeek));
*/					
	this->tbl_->SetTabProperties( *this, b ? STPF_NONE : STPF_USEAPPPEEKALWAYS|STPF_USEAPPTHUMBNAILALWAYS );
}

TaskbarWnd *TaskbarWnd::Create( Taskbar * pMainDlg, HWND d, const std::wstring& title, ITaskbarList4* tbl, bool disabled)
{
    TaskbarWnd *pWnd = new TaskbarWnd( pMainDlg, d, tbl, disabled);

    if (pWnd)
    {
		HWND hwnd = pWnd->create( title.c_str(), 0, mol::Rect(-32000,-32000,10,10), 0 );//*moe() );

        if (hwnd == NULL)
        {
            delete pWnd;
            pWnd = NULL;
        }
    }

    return pWnd;
}

BOOL TaskbarWnd::destroy()
{
    if (hWnd_ != NULL)
    {
		tb_->RemoveTab(doc);
		tbl_.release();
		::DestroyWindow(hWnd_);		
		hWnd_ = NULL;
		delete this;
    }
	return TRUE;
}

LRESULT TaskbarWnd::wndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
    LRESULT lResult = 0;

    switch (message)
    {
        case WM_CREATE:
        {
			enableTabs(false);
			tbl_->RegisterTab(*this,tb_->parent());
            break;
        }

        case WM_ACTIVATE:
		{
			if (LOWORD(wParam) == WA_ACTIVE)
            {
				tbl_->ActivateTab(*this);
				tbl_->SetTabActive( *this, tb_->parent(), 0 );
				::SetForegroundWindow(tb_->parent());

				::ShowWindow(tb_->parent(),SW_RESTORE);
				::PostMessage( mol::win::mdiClient(), WM_MDIACTIVATE, (WPARAM)(HWND)(doc), 0);
            }
            break;
		}

        case WM_SYSCOMMAND:
		{
            if (wParam != SC_CLOSE)
            {
                lResult = SendMessage( tb_->parent(), WM_SYSCOMMAND, wParam, lParam);
            }
            else
            {
                lResult = ::DefWindowProc(hWnd, message, wParam, lParam);
            }
            break;
		}
        case WM_CLOSE:
		{

			LRESULT lr = ::SendMessage(doc,WM_CLOSE,0,0);
			if ( lr == 0 )
			{
				::DestroyWindow(hWnd_);	
			}
			break;
		}

        case WM_DWMSENDICONICTHUMBNAIL:
		{
			HBITMAP bmp = GetIconicRepresentation( HIWORD(lParam), LOWORD(lParam), 2 );
			DwmSetIconicThumbnail( *this, bmp, 0);
			break;
		}

        case WM_DWMSENDICONICLIVEPREVIEWBITMAP:
		{
			sendLivePreviewBitmap();
			break;
		}
        default:
		{
            lResult = ::DefWindowProc( hWnd, message, wParam, lParam );
            break;
		}
    }

    return lResult;
}

HBITMAP TaskbarWnd::GetIconicRepresentation(int nWidth, int nHeight, int scale )
{
    HRESULT hr = E_FAIL;

	Gdiplus::Bitmap* src = Gdiplus::Bitmap::FromHBITMAP( hbm_cached_,0);

	// scale
	Gdiplus::Bitmap  dest( nWidth, nHeight, PixelFormat32bppARGB);
	{
		Gdiplus::RectF rDest(0,0,(Gdiplus::REAL)nWidth, (Gdiplus::REAL)nHeight );
		Gdiplus::Graphics gScale( &dest );

		if ( scale != 1 )
		{
			nWidth  = std::min(nWidth*scale, (int)src->GetWidth());
			nHeight = std::min(nHeight*scale, (int)src->GetHeight());
		}

		gScale.DrawImage( src, rDest,0,0,(Gdiplus::REAL)nWidth,(Gdiplus::REAL)nHeight, Gdiplus::UnitPixel, NULL, NULL, NULL );

	}
	delete src;

	// retval and cleanup
	HBITMAP hBitmap = 0;
	dest.GetHBITMAP(Gdiplus::Color::Black, &hBitmap);
    return hBitmap;
}

void TaskbarWnd::cacheIconicRepresentation()
{
	if ( hbm_cached_ && !::IsZoomed(doc) ) {
		return;
	}

	RECT r;
	::GetWindowRect( mol::win::mdiClient(), &r );

	RECT cr;
	::GetClientRect(  doc, &cr );
	POINT p = {cr.right,cr.bottom};
	::ClientToScreen( doc, &p );

	if ( p.y > r.bottom ) 
	{
		p.y = r.bottom;
	}
	if ( p.x > r.right ) 
	{
		p.x = r.right;
	}

	::ScreenToClient( doc, &p );

	// snap
	Gdiplus::Bitmap src(p.x, p.y, PixelFormat32bppPARGB );
	{
		Gdiplus::Graphics gsnap( &src );
		gsnap.Clear( 0x00ffffff );

		HDC mem = gsnap.GetHDC();
		BOOL bret = PrintWindow2( doc, mem, 1 );
		gsnap.Flush();
		gsnap.ReleaseHDC(mem);
	}

	if ( hbm_cached_ ) 
	{
		::DeleteObject( (HGDIOBJ)hbm_cached_);
	}
	src.GetHBITMAP(Gdiplus::Color::Black, &hbm_cached_);

	enableTabs(true);
	DwmInvalidateIconicBitmaps(*this);

}

void TaskbarWnd::refreshIconDelayed()
{
	timer_.set(1, std::bind(&TaskbarWnd::timer_callback,this) );
}

void TaskbarWnd::sendLivePreviewBitmap( )
{
	RECT r;
	::GetWindowRect( mol::win::mdiClient(), &r );

	RECT wr;
	::GetWindowRect( tb_->parent(), &wr );

	POINT ptOffset = { r.left-wr.left, r.top-wr.top };

	HRESULT hr = DwmSetIconicLivePreviewBitmap( *this, hbm_cached_, &ptOffset, 1);
}



//////////////////////////////////////////////



Taskbar::Taskbar()
{
	if ( S_OK == tbl_.createObject( CLSID_TaskbarList ) )
	{
        tbl_->HrInit();
	}
}

Taskbar::~Taskbar()
{
}

void Taskbar::init(HWND parent)
{
	parent_ = parent;
}

TaskbarWnd* Taskbar::addTab( HWND d, const std::wstring& title, bool disabled )
{
	if ( tbl_ )
    {
		TaskbarWnd* pTabWnd = TaskbarWnd::Create( this, d, title, tbl_, disabled);
        if (pTabWnd != NULL)
        {
            tbl_->SetTabOrder( *pTabWnd, NULL);

			tabs_.insert( std::make_pair( (HWND)(d), pTabWnd ) );

			return pTabWnd;
        }
    }

	return 0;
}

void Taskbar::renameTab( HWND d, const std::wstring& title )
{
	if ( tabs_.count(d) == 0 )
		return;

	TaskbarWnd* tw  = tabs_[d];

	::SetWindowText( *tw, title.c_str() );
}


void Taskbar::moveTab( HWND d, HWND before )
{
	if ( tabs_.count(d) == 0 )
		return;

	if ( tabs_.count(before) == 0 )
		return;

	TaskbarWnd* t_what  = tabs_[d];
	TaskbarWnd* t_where = tabs_[before];

	tbl_->SetTabOrder(*t_what,*t_where);
}

void Taskbar::RemoveTab(HWND hwnd)
{
	if ( tbl_ )
	{
		tbl_->UnregisterTab(hwnd);
		if ( tabs_.count(hwnd) > 0 )
		{
			tabs_.erase(hwnd);
		}
	}
}

} // end namespace win

mol::win::Taskbar* taskbar()
{
  return &mol::singleton<mol::win::Taskbar>();
}


} // end namespace mol
