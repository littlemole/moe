#include "win/Wnd.h"
#include "win/msgloop.h"
#include "win/Res.h"
#include "win/Layout.h"
#include "util/X.h"
#include "boost/scoped_ptr.hpp"
#include "boost/shared_ptr.hpp"


namespace mol {
namespace win {

/////////////////////////////////////////////////////////////////

UINT invoke_msg()
{
	static UINT msg = ::RegisterWindowMessage(_T("WM_MOL_INVOKE_ASYNC"));
	return msg;
}

/////////////////////////////////////////////////////////////////

Wnd::Wnd()
	: isMidi_(false)
{}

Wnd::~Wnd()
{
}

BOOL Wnd::update()
{
    return ::UpdateWindow(hWnd_);
}

void Wnd::redraw()
{
	::RedrawWindow(*this,0,0,RDW_FRAME|RDW_INVALIDATE);	
	//::RedrawWindow( *this,NULL,NULL,RDW_FRAME|RDW_INVALIDATE|RDW_UPDATENOW|RDW_ALLCHILDREN|RDW_INTERNALPAINT);
	invalidateRect(0,TRUE);
	::UpdateWindow(*this);
}

int Wnd::show( int nCmdShow )
{
    return ::ShowWindow(hWnd_, nCmdShow );
}

BOOL Wnd::invalidateRect( const RECT* r, BOOL erase )
{
    return ::InvalidateRect(hWnd_, r, erase );
}

BOOL Wnd::validateRect( const RECT* r)
{
    return ::ValidateRect(hWnd_, r );
}

LRESULT Wnd::setRedraw(bool doRedraw)
{
    sendMessage(WM_SETREDRAW,(WPARAM)(BOOL)doRedraw,0);
	if ( doRedraw )
		redraw();
	return 0;
}

bool Wnd::hasFocus()      
{ 
    return (::GetFocus() == hWnd_); 
}

HWND Wnd::setFocus()      
{ 
    return ::SetFocus( hWnd_ ); 
}

void Wnd::maximize()
{
	show(SW_SHOWMAXIMIZED);
}

void Wnd::minimize()
{
	show(SW_SHOWMINIMIZED);
}

void Wnd::restore()
{
	show(SW_RESTORE);
}


int  Wnd::setForeGround() 
{ 
    return ::SetForegroundWindow( hWnd_ ); 
}

BOOL Wnd::move( int x, int y, int w, int h, BOOL bRepaint  )
{
    return ::MoveWindow( hWnd_, x, y, w, h, bRepaint );
}

BOOL Wnd::move( const RECT& r, BOOL bRepaint  )
{
	return ::MoveWindow( hWnd_, r.left, r.top, r.right, r.bottom, bRepaint );
}

LRESULT Wnd::sendMessage(UINT msg, WPARAM wParam, LPARAM lParam )
{
    return ::SendMessage(hWnd_, msg, wParam, lParam );
}

BOOL    Wnd::postMessage(UINT msg, WPARAM wParam, LPARAM lParam )
{
	return ::PostMessage(hWnd_, msg, wParam, lParam );
}

BOOL Wnd::destroy()
{
	::DestroyWindow(hWnd_);
    return TRUE;
}

BOOL Wnd::close()
{
	return ::CloseWindow(hWnd_);
}

int Wnd::setFont( HFONT hfont )
{
    return (int)::SendMessage(hWnd_, WM_SETFONT , (WPARAM)hfont, MAKELPARAM(TRUE,0));
}

BOOL Wnd::client2Screen( POINT& p )
{
    return ::ClientToScreen(hWnd_, &p );
}

BOOL Wnd::client2Screen( RECT& r )
{
	mol::Point p1(r.left,r.top);
	mol::Point p2(r.right,r.bottom);
	BOOL ret = ::ClientToScreen(hWnd_, &p1 );
	if ( ret != FALSE )
	{
		ret = ::ClientToScreen(hWnd_, &p2 );
		if ( ret != FALSE )
		{
			r.left   = p1.x;
			r.top    = p1.y;
			r.right  = p2.x;
			r.bottom = p2.y;
		}
	}
    return ret;
}

BOOL Wnd::screen2Client( RECT& r )
{
	mol::Point p1(r.left,r.top);
	mol::Point p2(r.right,r.bottom);
	BOOL ret = ::ScreenToClient(hWnd_, &p1 );
	if ( ret != FALSE )
	{
		ret = ::ScreenToClient(hWnd_, &p2 );
		if ( ret != FALSE )
		{
			r.left   = p1.x;
			r.top    = p1.y;
			r.right  = p2.x;
			r.bottom = p2.y;
		}
	}
    return ret;
}

BOOL Wnd::screen2Client( POINT& p )
{
    return ::ScreenToClient(hWnd_, &p );
}

int  Wnd::setText( const mol::string& s )
{
    return ::SetWindowText(hWnd_, s.c_str());
}

mol::string Wnd::getText( )
{
	int n = ::GetWindowTextLength(hWnd_);
	if ( !(n > 0) )
		return _T("");

	mol::tbuff buf(n+1);
    n = ::GetWindowText(hWnd_, buf,n+1);
	return buf.toString(n);
}

HBITMAP Wnd::snapshot( RECT* r )
{
	    RECT rc; 
		getClientRect(rc);

        HDC hdcWin = GetDC(*this);
        HDC hdcTemp = CreateCompatibleDC(hdcWin);

		HBITMAP hbm = 0;
		if ( r == 0 )
			 hbm = CreateCompatibleBitmap(hdcWin,(rc.right - rc.left), (rc.bottom - rc.top));
		else
			 hbm = CreateCompatibleBitmap(hdcWin,(r->right - r->left), (r->bottom - r->top));

        HBITMAP hbmold = (HBITMAP)SelectObject(hdcTemp, hbm);

		if ( r == 0 )
			BitBlt(hdcTemp, 0,0, (rc.right - rc.left), (rc.bottom - rc.top), hdcWin, 0,0, SRCCOPY);
		else
			BitBlt(hdcTemp, 0, 0, (r->right - r->left), (r->bottom - r->top),hdcWin, r->left,r->top, SRCCOPY);

        SelectObject(hdcTemp, hbmold);
        DeleteDC(hdcTemp);
        ReleaseDC(*this, hdcWin);

		return hbm;
}

/////////////////////////////////////////////////////////////////
//the one and only framework-windowproc
/////////////////////////////////////////////////////////////////

WndProc::~WndProc()
{	
}

void WndProc::cleanup()
{	
	if ( layout_ )
	{
		delete layout_;
		layout_ = 0;
	}
}

LRESULT CALLBACK WndProc::windowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    try
    {
        // look up WndProc-pointer stored in HWND
		WndProc* pThis = wndFromHWND<WndProc>(hwnd);

        // if we have a valid WndProc-pointer, route to wndProc
        if (pThis)
        {
			if (message == WM_CREATE)
			{
				if ( pThis->uiBuilder_)
					pThis->uiBuilder_->makeUI();
			}

			if (message == WM_NCDESTROY)
			{
				if ( pThis->deleteOnNCDestroy_ )
				{
					LRESULT lr = (pThis->wndProc( hwnd, message,wParam,lParam));
					pThis->hWnd_ = 0;
					delete pThis;
					return lr;
				}
			}
			LRESULT lr = (pThis->wndProc( hwnd, message,wParam,lParam));
			return lr;
        }
        else
        // if not, this should be the first WND-MESSAGE to arrive
        if (message == WM_NCCREATE)
        {
            if (((LPCREATESTRUCT) lParam)->lpCreateParams!=0)
            {
                // get this pointer stored in lParam from Wnd::create()
				pThis = dynamic_cast<WndProc*>( (mol::win::WndProc*)(((LPCREATESTRUCT)lParam)->lpCreateParams ));
                // set THIS _hWnd
                pThis->hWnd_ = hwnd;
                // store the this-pointer in the HWND
                ::SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR) (dynamic_cast<WndProc*>(pThis)));
                // call wndproc
                return (pThis->wndProc( hwnd, message,wParam,lParam));
            }
        }
    }
    catch (X )
    {
			ODBGS1("WndProc::windowProcedure %i",::GetLastError());
            PostQuitMessage(0);
    }

    return ::DefWindowProc(hwnd,message,wParam,lParam);
}

LRESULT WndProc::wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (!::IsWindow(hwnd))
		return 0;

	switch ( message )
	{
		case WM_PAINT :
		{
			mol::PaintDC dc(hwnd);
			return 0;
		}
		case WM_ERASEBKGND :
		{
            if ( eraseBackground_ == 0 )
                return ::DefWindowProc(hwnd,message,wParam,lParam);
			return eraseBackground_;
		}
		case WM_DESTROY :
		{
			//::PostQuitMessage(0); // do this in your main frame
			return 0;
		}
		case WM_SIZE :
		{
			return OnSize(message,wParam,lParam);
		}
		case WM_NOTIFY:
		{
			LPNMHDR lpnmhdr = (LPNMHDR) lParam;
			if ( lpnmhdr && (lpnmhdr->code == RBN_HEIGHTCHANGE) )
			{
				return OnLayout(message,wParam,lParam);
			}
			if ( lpnmhdr && (lpnmhdr->code == TTN_GETDISPINFO) )
			{
				if ( !mol::win::tabToolTips().tabToolNotify(lpnmhdr->hwndFrom,message,wParam,lParam) )
					::SendMessage(lpnmhdr->hwndFrom,message,wParam,lParam);
				return 0;
			}
			break;
		}

	}

	if ( message == WM_INVOKE  )
	{
		if ( wParam == 0 )
			return OnInvoke(message,wParam,lParam);
	}
	return ::DefWindowProc(hwnd,message,wParam,lParam);
}

LRESULT WndProc::OnSize( UINT message, WPARAM wParam, LPARAM lParam)
{
	if ( layout_ )
		layout_->OnSize(message,wParam,lParam);

	::InvalidateRect(*this,0,TRUE);
	::UpdateWindow(*this);

	return 0;
}

LRESULT WndProc::OnLayout( UINT message, WPARAM wParam, LPARAM lParam)
{
	mol::Rect r;
	getClientRect(r);

	if ( layout_ )
		layout_->OnSize(message,0,MAKELPARAM(r.right-r.left,r.bottom-r.top));

	::InvalidateRect(*this,0,TRUE);
	::UpdateWindow(*this);

	return 0;
}


LRESULT WndProc::OnInvoke( UINT message, WPARAM wParam, LPARAM lParam)
{
	boost::shared_ptr<mol::fun::task> task((mol::fun::task*)lParam);
	(*task)();

	return 0;
}

HWND WndProc::create( mol::string windowName, HMENU id, const Rect& r, HWND parent )
{
    hWnd_ = createWindow( windowName, id, r, parent);
	return hWnd_;
}

HWND WndProc::create( HMENU id, const Rect& r, HWND parent)
{
    return create( _T(""), id, r, parent);
}



/////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

BOOL WndProc::addTrayIcon( int trayID, int WMnotify, HICON icon )
{
    NOTIFYICONDATA nid;

    nid.cbSize = sizeof(NOTIFYICONDATA);
    nid.hWnd = hWnd_;
    nid.uID = trayID;
    nid.uFlags = NIF_MESSAGE | NIF_ICON ;
    nid.uCallbackMessage = WMnotify;
    nid.hIcon = icon;
    return ::Shell_NotifyIcon(NIM_ADD, &nid);
}

BOOL WndProc::freeTrayIcon( int trayID )
{
    NOTIFYICONDATA nid;

    nid.cbSize = sizeof(NOTIFYICONDATA);
    nid.hWnd = hWnd_;
    nid.uID = trayID;
    nid.uFlags = NIF_ICON ;
    return ::Shell_NotifyIcon(NIM_DELETE, &nid);
}

UINT WndProc::showContext( HMENU m, HWND parent )
{
	mol::Menu menu(m);
    if ( parent == 0 )
        parent = *this;
	
	//show context Menu
	POINT pt;
	::GetCursorPos(&pt);
	UINT res = menu.trackPopup( parent,pt.x,pt.y);

    return res;
}

UINT WndProc::returnContext( HMENU m )
{
	mol::Menu menu(m);

	//show context Menu
	POINT pt;
	::GetCursorPos(&pt);
	UINT res = menu.returnTrackPopup( *this,pt.x,pt.y);

    return res;
}




} //end namespace mol::win

/////////////////////////////////////////////////////////////////

HWND Window::createWindow( const mol::string& windowName, HMENU hMenu, const Rect& r, HWND parent )
{
	registerClass(hMenu);
	HMENU m = 0;
	if (::IsMenu((HMENU)hMenu)) {
		m = (HMENU)hMenu;
	}
	hWnd_ = ::CreateWindowEx ( exstyle(),
                                      wndClass().getClassName().c_str(),
                                      windowName.c_str(),
                                      style(),
                                      r.left, r.top, r.right, r.bottom,
                                      parent,
                                      (HMENU)m,
									  mol::hinstance(),
                                      dynamic_cast<PVOID>(this) );
	LONG_PTR id = 0;
	if (!::IsMenu((HMENU)hMenu)) {
		::SetWindowLongPtr( hWnd_, GWLP_ID, (LONG_PTR)hMenu );
		id = ::GetWindowLongPtr( hWnd_, GWLP_ID );
	}
	return hWnd_;
}

void Window::registerClass( HMENU& hMenu )
{
    if (!::IsMenu(hMenu) )
    {
        if (hMenu)
        {
            wndClass().setMenu(hMenu);
            
        }
    }
    wndClass().registerClass();
}

mol::win::WndClass& Window::wndClass()				
{																	
	static mol::string wc = mol::win::WndClassGenerator::createClass();	
	return mol::win::WndClassGenerator::getClass(wc);					
}

LRESULT Window::wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (!::IsWindow(hwnd))
		return 0;

	switch( message )
	{
		case WM_NOTIFY:
		{
			Crack msg(message,wParam,lParam);
			switch( msg.nmhdr()->code )
			{
				case TBN_GETBUTTONINFO : 
				case TBN_BEGINADJUST   :
				case TBN_RESET		   :
				case TBN_ENDADJUST     :
				case TBN_QUERYINSERT   :
				case TBN_QUERYDELETE   :
				case TCN_GETOBJECT	   :
				case RBN_GETOBJECT     :
				case TBN_DROPDOWN	   :
				case NM_RCLICK		   :
				case NM_CLICK		   :
				{
					return ::SendMessage(msg.nmhdr()->hwndFrom,message,wParam,lParam );
				}
			}
		}
		case WM_MEASUREITEM:
		{
			if ( wParam != 0 )
				return 0;

			LPMEASUREITEMSTRUCT lpmis = (LPMEASUREITEMSTRUCT) lParam; 
			if ( lpmis->CtlType == ODT_MENU )
			{

				mol::win::MenuItemInfo* item = (mol::win::MenuItemInfo*) lpmis->itemData;
				if ( item )
					return item->OnMeasureItem(message,wParam,lParam);
			}
			return 0;
		}
		case WM_DRAWITEM:
		{
			if ( wParam != 0 )
				return 0;

			LPDRAWITEMSTRUCT lpdis = (LPDRAWITEMSTRUCT) lParam; 
			if ( lpdis->CtlType == ODT_MENU )
			{

				mol::win::MenuItemInfo* item = (mol::win::MenuItemInfo*) lpdis->itemData;

				if ( item )
					return item->OnDrawItem(message,wParam,lParam);
			}
			return 0;
		}
	}
	return WndProc::wndProc(hwnd,message,wParam,lParam);
}



/////////////////////////////////////////////////////////////////


} // endnamespace mol



