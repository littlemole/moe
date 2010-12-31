#include "win/Ctrl.h"
#include "win/Layout.h"

namespace mol  {
namespace win  {

const mol::TCHAR button_class[]			= _T("Button");
const mol::TCHAR edit_class[]			= _T("Edit");
const mol::TCHAR combo_box_class[]		= _T("ComboBox");
const mol::TCHAR list_box_class[]		= _T("ListBox");
const mol::TCHAR scrollbar_class[]		= _T("ScrollBar");
const mol::TCHAR static_class[]			= _T("Static");


Ctrl::~Ctrl()
{
	ODBGS("~Ctrl");
}

const mol::string& Ctrl::wndClassName() 
{
    static mol::string s(_T(""));
    return s;
}


void Ctrl::subClass()
{
    ::SetWindowLongPtr( hWnd_, GWLP_USERDATA, (LONG_PTR)dynamic_cast<void*>(this));
    oldProc = (WNDPROC)(::SetWindowLongPtr( hWnd_, GWLP_WNDPROC, (LONG_PTR)(windowProcedure) ));
}

void Ctrl::subClass(HWND hwnd)
{
    attach(hwnd);
    subClass();
}

void Ctrl::deClass()
{
    ::SetWindowLongPtr( hWnd_, GWLP_WNDPROC, (LONG_PTR)(oldProc) );
}

LRESULT Ctrl::wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch ( message )
	{
		case WM_COMMAND:
		{
			if ( wParam == 0 )
				return OnInvoke(message,wParam,lParam);
			break;
		}
		case WM_NOTIFY:
		{
			Crack msg(message, wParam, lParam);
			if ( msg.nmhdr()->hwndFrom == hwnd )
					return 0;
		}
	}
	
    return ::CallWindowProc( oldProc, hwnd, message, wParam, lParam );
}

HWND Ctrl::createWindow( const mol::string& windowName, HMENU hMenu, const Rect& r, HWND parent )
{
    hWnd_ = ::CreateWindowEx( exstyle(),wndClassName().c_str(),
                              windowName.c_str(), style(),
                              r.left, r.top, r.right, r.bottom,
                              parent, (HMENU)hMenu, hinstance(),(PVOID)dynamic_cast<void*>(this) );
    subClass();

	NONCLIENTMETRICS nm;
	nm.cbSize = sizeof (NONCLIENTMETRICS);

	SystemParametersInfo (SPI_GETNONCLIENTMETRICS,0,&nm,0);
	LOGFONT fl = nm.lfMenuFont;

	static HFONT font_ = ::CreateFontIndirect(&fl);

    //setFont( (HFONT)::GetStockObject(ANSI_VAR_FONT));
	setFont( font_);

    this->OnCtrlCreated();
    return hWnd_;
}

void Ctrl::OnCtrlCreated()
{}

} // end namespace win

/////////////////////////////////////////////////////////////////////////////////

int Button::style()   
{ 
    return WS_CHILD|WS_BORDER|WS_VISIBLE|BS_PUSHBUTTON; 
}

void IconButton::setIcon( HICON icon ) 
{ 
    sendMessage(BM_SETIMAGE,IMAGE_ICON,(LPARAM)icon); 
}

int IconButton::style()   
{ 
    return WS_CHILD|WS_BORDER|WS_VISIBLE|BS_PUSHBUTTON|BS_ICON; 
}
/////////////////////////////////////////////////////////////////////////////////


int ComboBox::style()   
{ 
    return WS_CHILD|WS_BORDER|WS_VISIBLE|CBS_AUTOHSCROLL; 
}

/////////////////////////////////////////////////////////////////////////////////


int ListBox::style()   
{ 
    return WS_CHILD|WS_BORDER|WS_VISIBLE|WS_VSCROLL|WS_HSCROLL|LBS_STANDARD; 
}
/////////////////////////////////////////////////////////////////////////////////

void ComboBox::insertString(const mol::string& str, int index ) 
{ 
    sendMessage( CB_INSERTSTRING,index,(LPARAM)(str.c_str())  ); 	
}

void ComboBox::addString(const mol::string& str ) 
{ 
    sendMessage( CB_ADDSTRING,0,(LPARAM)(str.c_str()) ); 
}

void ComboBox::deleteString( int id ) 
{ 
    sendMessage( CB_DELETESTRING,(WPARAM)id,0); 
}

void ComboBox::clear() 
{ 
    sendMessage( CB_RESETCONTENT ,0,0); 
}

int  ComboBox::getCount()  
{ 
    return (int)sendMessage( CB_GETCOUNT,0,0 ); 
}

int  ComboBox::getCurSel() 
{ 
    return (int)sendMessage( CB_GETCURSEL,0,0 ); 
}

void ComboBox::setCurSel(int n) 
{ 
    sendMessage( CB_SETCURSEL,n,0 ); 
}

void ComboBox::setCurSel(const mol::string& txt)
{
    for ( int i = 0; i < getCount(); i++)
        if ( txt == getString(i) )
        {
            setCurSel(i);
            break;
        }
}
mol::string ComboBox::getString(int id )
{
	mol::TCHAR buf[1024];
	::memset(buf,32,1024*sizeof(mol::TCHAR));
    buf[1023] = 0;

    if ( CB_ERR == sendMessage( CB_GETLBTEXT,id,(LPARAM)buf))
       throw X( _T("getString failed"));

    return buf;
}
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

void ListBox::addString( const mol::string& s ) 
{ 
    sendMessage( LB_ADDSTRING,0,(LPARAM)s.c_str() ); 
}

int ListBox::getCurSel() 
{ 
    return (int) sendMessage( LB_GETCURSEL,0,0); 
}

mol::string ListBox::getString(int index)
{
	mol::TCHAR* buf = 0;
    int   len = 0;

    len = (int)sendMessage(LB_GETTEXTLEN, (WPARAM)index,(LPARAM)0);
    if ( len == -1)
            return _T("");

	buf = new mol::TCHAR[len+1];
    buf[len] = 0;
    sendMessage( LB_GETTEXT,(WPARAM)index,(LPARAM)buf);
    mol::string ret(buf);
    delete[] buf;
    return ret;
}

void ListBox::resetContent() 
{ 
    sendMessage( LB_RESETCONTENT,0,0 ) ; 
}

int ListBox::index(const mol::string& s )
{
	LRESULT r = sendMessage( LB_FINDSTRING,-1, (LPARAM)s.c_str() ) ; 
	return (int)r;
}

int ListBox::count()
{
	LRESULT r = sendMessage( LB_GETCOUNT,0, 0 ) ; 
	return (int)r;
}


void ListBox::setData(int index, void* d )
{
	sendMessage( LB_SETITEMDATA,(WPARAM)index, (LPARAM)d ) ; 
}

void* ListBox::getData(int index)
{
	LRESULT r = sendMessage( LB_GETITEMDATA,(WPARAM)index, (LPARAM)0 ) ;
	if ( r == LB_ERR )
		return 0;

	return (void*)r;
}


/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

void EditBox::setSelection(int start, int end)
{
    postMessage(EM_SETSEL,(WPARAM)start,(LPARAM)end);
}

void EditBox::getSelection(int& start, int& end)
{
    postMessage(EM_GETSEL,(WPARAM)&start,(LPARAM)&end);
}
/////////////////////////////////////////////////////////////////////////////////

HICON  StaticCtrl::setIcon( HICON hIcon )
{
    return (HICON) sendMessage(STM_SETICON, (WPARAM)(hIcon),(LPARAM)(0) );
}

HANDLE StaticCtrl::setImage( HANDLE bmp )
{
    if (bmp)
        return (HANDLE)sendMessage( STM_SETIMAGE,(WPARAM)(IMAGE_BITMAP),(LPARAM)bmp );
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

EditBox& RcomboBox::editBox() 
{ 
    return edit; 
}

void RcomboBox::subClassEdit()
{
    POINT pt = { 3, 3 };
    HWND child = ::ChildWindowFromPoint(hWnd_, pt);

    edit.attach(child);
    edit.subClass();
}
HWND RcomboBox::createWindow( const mol::string& windowName, HMENU hMenu, const Rect& r, HWND parent )
{
    ComboBox::createWindow( windowName, hMenu, r, parent );
    subClassEdit();
    return hWnd_;
}

LRESULT RcomboBox::RcomboBoxEdit::wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    if ( (message == WM_KEYDOWN ) && ( wParam == VK_RETURN ) )
    {
        HWND parent		= ::GetParent( hWnd_ );
        int id			= ::GetDlgCtrlID(parent);
        parent			= ::GetParent( parent );
        ::PostMessage( parent, WM_COMMAND,MAKEWPARAM(id,CBN_SELENDOK), (LPARAM)dynamic_cast<void*>(this) );
        return 0;
    }
    // prevent message beep for illegal VK_RETURN char
    if ( wParam == VK_RETURN ) 
        return 0;
    return Ctrl::wndProc(  hwnd, message, wParam, lParam);
}
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

namespace win {

CtrlResizerImpl::CtrlResizerImpl( WndProc* bc, Point m, int f, int c )
: ctrl_(bc), mini_(m), flags_(f), cmd_(c), dir_(NONE), bTrack_(false)
{}

LRESULT CtrlResizerImpl::operator() ( int msg, WPARAM wParam, LPARAM lParam, bool& handled)
{
	handled = true;
    switch (msg)
    {
        case WM_NCLBUTTONDOWN:
        {
            if (!bTrack_)
            {
                dir_ = NONE;

                if ( wParam == HTRIGHT  ) dir_ |= RIGHT;
                if ( wParam == HTLEFT   ) dir_ |= LEFT;
                if ( wParam == HTTOP    ) dir_ |= TOP;
                if ( wParam == HTBOTTOM ) dir_ |= BOTTOM;

                if ( wParam == HTTOPLEFT     ) dir_ |= TOP|LEFT;
                if ( wParam == HTTOPRIGHT    ) dir_ |= TOP|RIGHT;
                if ( wParam == HTBOTTOMLEFT  ) dir_ |= BOTTOM|LEFT;
                if ( wParam == HTBOTTOMRIGHT ) dir_ |= BOTTOM|RIGHT;


                if (dir_ != NONE )
                {
                    ::SetCapture( *ctrl_ );
                    bTrack_ = true;
                    return 0;
                }
            }
            break;
        }
        case WM_MOUSEMOVE:
        {
            if (bTrack_)
            {
                Point pm; //mouse position
                pm.x = LOWORD(lParam);
                pm.y = HIWORD(lParam);

                RECT rc,rw,rp,dest;
                ctrl_->getClientRect(rc);
                ctrl_->getWindowRect(rw);
                ::GetWindowRect(ctrl_->getParent(),&rp);

                Point tl(rw.left, rw.top);
                ::ScreenToClient( ctrl_->getParent(), &tl );

                dest.right  = rw.right  - rw.left;
                dest.bottom = rw.bottom - rw.top;
                dest.left   = tl.x;
                dest.top    = tl.y;

                if ( dir_ & RIGHT )
                {
                    if (flags_ & RIGHT)
                    {
                        if ( (signed short int)pm.x > 0 )
                            if ( pm.x > mini_.x )
                                dest.right = pm.x;
                    }
                }
                if ( dir_ & BOTTOM )
                {
                    if (flags_ & BOTTOM)
                    {
                        if ( (signed short int)pm.y > 0 )
                            if ( pm.y > mini_.y )
                                dest.bottom = pm.y;
                    }
                }
                if ( dir_ & LEFT )
                {
                    if (flags_ & LEFT)
                    {
                        Point tmp(pm.x, pm.y);
                        ctrl_->client2Screen(tmp);
                        ::ScreenToClient(ctrl_->getParent(),&tmp);
                        signed short int x = (signed short int)pm.x;

                        if ( x <= 0 )
                        {
                            if (tl.x == 0 )
                                break;

                            dest.left  += x;
                            signed short int l = (signed short int)dest.left;
                            if ( l < 0 )
                            {
                                dest.left = 0;
                                dest.right += l-x;
                            }
                            else
                                dest.right -= x;
                        }
                        else
                        {
                            if ( rc.right <= mini_.x )
                                break;
                            signed short int d = (signed short int)( tmp.x - dest.left);
                            int newx = tmp.x;
                            if ( newx-dest.left >= mini_.x )
                            {
                                dest.right -= newx-dest.left;
                                dest.left  = newx;
                            }
                            else
                            {
                                dest.left = dest.left+dest.right-mini_.x;
                                dest.right = mini_.x;
                            }
                        }
                    }
                }//endifif LEFT
                if ( dir_ & TOP )
                {
                    if (flags_ & TOP)
                    {
                        if ( (signed short int)pm.y > 0 )
						{
                            //if ( pm.y > mini_.y )
							{
								dest.top += (signed short int)pm.y;
								dest.bottom -= (signed short int)pm.y;
							}
						}
						else
						{
							dest.top += (signed short int)pm.y;
							dest.bottom -= (signed short int)pm.y;
						}
                    }
                }
                ctrl_->move( dest.left, dest.top, dest.right, dest.bottom );
				mol::win::WndProc* wbp = mol::wndFromHWND<mol::win::WndProc>(ctrl_->getParent());
				if ( wbp->layout_ )
				{
					wbp->OnLayout(0,0,0);
				}
				else
					::PostMessage( ctrl_->getParent(), WM_COMMAND, cmd_, 0 );
                return 0;
            }//endif bTrack_
            break;
        }
        case WM_LBUTTONUP:
        {
            if (bTrack_)
            {
                ::ReleaseCapture();
                bTrack_ = false;
                return 0;
            }
            break;
        }
    }//endswitch	
	handled = false;
	return 0;
}

} // end namespace win

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

ScrollWnd::ScrollWnd()
{
	::ZeroMemory(&siH_,sizeof(SCROLLINFO));
	 siH_.cbSize = sizeof (siH_);
	 siH_.fMask  = SIF_ALL;

	::ZeroMemory(&siV_,sizeof(SCROLLINFO));
	 siV_.cbSize = sizeof (siV_);
	 siV_.fMask  = SIF_ALL|SIF_DISABLENOSCROLL;

}

void ScrollWnd::setVScroll(int rowHeight, unsigned int nRows)
{
	scrollRowHeight_ = rowHeight;
	scrollRows_		 = nRows;
	
	RECT r;
	getClientRect(r);

	scrollV(r.bottom);
}

void ScrollWnd::setHScroll(int colWidth, unsigned int nCols)
{
	scrollColWidth_  = colWidth;
	scrollCols_		 = nCols;
	
	RECT r;
	getClientRect(r);

	scrollH(r.right);
}

unsigned int ScrollWnd::getScrollPos(int sb)
{
	if ( sb == SB_HORZ )
	{
		::GetScrollInfo( *this, sb, &siH_ );		
		return siH_.nPos;
	}

	::GetScrollInfo( *this, sb, &siV_ );		
	return siV_.nPos;
}

unsigned int ScrollWnd::getScrollMax(int sb)
{
	if ( sb == SB_HORZ )
	{
		::GetScrollInfo( *this, sb, &siH_ );		
		return siH_.nMax;
	}
	
	::GetScrollInfo( *this, sb, &siV_ );		
	return siV_.nMax;
}


void ScrollWnd::setScrollPos(unsigned int p,int sb)
{
	RECT r;
	getClientRect(r);

	if ( sb == SB_HORZ )
	{
		int xPos = getScrollPos(SB_HORZ);
		if ( xPos == p )
			return;
		
		siH_.nPos = p;
		::SetScrollInfo( *this, sb, &siH_, TRUE );	
		::GetScrollInfo( *this, sb, &siH_ );		

		int width = r.right / siH_.nPage;
		::ScrollWindow(*this, 0, width * (xPos - siH_.nPos), NULL, NULL);
	}
	else
	{
		int yPos = getScrollPos();
		if ( yPos == p )
			return;

		//siV_.fMask  = SIF_ALL|SIF_DISABLENOSCROLL;
		siV_.nPos = p;
		::SetScrollInfo( *this, sb, &siV_, TRUE );	
		::GetScrollInfo( *this, sb, &siV_ );	

		int height = r.bottom / siV_.nPage;
		::ScrollWindow(*this, 0, height * (yPos - siV_.nPos), NULL, NULL);
	}

	::UpdateWindow(*this);
}


LRESULT ScrollWnd::wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static UINT wheelScrollLines=0;//number of lines to scroll 
	static BOOL b = ::SystemParametersInfo(SPI_GETWHEELSCROLLLINES, 0, &wheelScrollLines, 0);

	switch(message)
	{
		case WM_VSCROLL:
		{
			// Save the posi_tion for comparison later on
  		    int yPos = getScrollPos(SB_VERT);
			switch (LOWORD (wParam))
			{
				// user clicked the HOME keyboard key
				case SB_TOP:
					siV_.nPos = siV_.nMin;
				break;
              
				// user clicked the END keyboard key
				case SB_BOTTOM:
					siV_.nPos = siV_.nMax;
				break;
              
				// user clicked the top arrow
				case SB_LINEUP:
				{
						siV_.nPos -= 1;
					break;
				}
              
				// user clicked the bottom arrow
				case SB_LINEDOWN:
				{
					siV_.nPos += 1;
					break;
				}
              
				// user clicked the scroll bar shaft above the scroll box
				case SB_PAGEUP:
					siV_.nPos -= siV_.nPage;
				break;
              
				// user clicked the scroll bar shaft below the scroll box
				case SB_PAGEDOWN:
					siV_.nPos += siV_.nPage;
				break;
              
				// user dragged the scroll box
				case SB_THUMBTRACK:
					siV_.nPos = siV_.nTrackPos;
				break;
              
				default:
				break; 
			}
			// Set the posi_tion and then retrieve it.  Due to adjustments
			//   by Windows it may not be the same as the value set.
			//si_.fMask = SIF_ALL ;
			//siV_.fMask = SIF_ALL;
			::SetScrollInfo (*this, SB_VERT, &siV_, TRUE);
			::GetScrollInfo (*this, SB_VERT, &siV_);

			// If the position has changed, scroll window and update it
			if (siV_.nPos != yPos)
			{                
				RECT r;
				getClientRect(r);
				int height = r.bottom / siV_.nPage;

				::ScrollWindow(*this, 0, height * (yPos - siV_.nPos), NULL, NULL);
				::UpdateWindow(*this);
				this->onVScroll(siV_.nPos);
			}		
			return 0;
		}
		case WM_HSCROLL:
		{
			int xPos = getScrollPos(SB_HORZ);
			switch (LOWORD (wParam))
			{
				// user clicked the HOME keyboard key
				case SB_TOP:
					siH_.nPos = siH_.nMin;
				break;
              
				// user clicked the END keyboard key
				case SB_BOTTOM:
					siH_.nPos = siH_.nMax;
				break;
              
				// user clicked the top arrow
				case SB_LINEUP:
					siH_.nPos -= 1;
				break;
              
				// user clicked the bottom arrow
				case SB_LINEDOWN:
					siH_.nPos += 1;
				break;
              
				// user clicked the scroll bar shaft above the scroll box
				case SB_PAGEUP:
					siH_.nPos -= siH_.nPage;
				break;
              
				// user clicked the scroll bar shaft below the scroll box
				case SB_PAGEDOWN:
					siH_.nPos += siH_.nPage;
				break;
              
				// user dragged the scroll box
				case SB_THUMBTRACK:
					siH_.nPos = siH_.nTrackPos;
				break;
              
				default:
				break; 
			}
			// Set the posi_tion and then retrieve it.  Due to adjustments
			//   by Windows it may not be the same as the value set.
			//si_.fMask = SIF_POS;
			//siH_.fMask = SIF_ALL;
			//siH_.fMask  = SIF_ALL|SIF_DISABLENOSCROLL;
			::SetScrollInfo (*this, SB_HORZ, &siH_, TRUE);
			::GetScrollInfo (*this, SB_HORZ, &siH_);
			// If the position has changed, scroll window and update it
			if (siH_.nPos != xPos)
			{                
				RECT r;
				getClientRect(r);
				int width = r.right / siH_.nPage;

				::ScrollWindow(*this, width * (xPos-siH_.nPos), 0, NULL, NULL);
				::UpdateWindow(*this);
				this->onHScroll(siH_.nPos);
			}		
			return 0;
		}
		case WM_MOUSEWHEEL:
		{
		    if (wParam & (MK_SHIFT | MK_CONTROL)) 
			{
				break;
			}
			wheelDelta_ -= (short) HIWORD(wParam);
		    if ( abs(wheelDelta_) >= WHEEL_DELTA && wheelScrollLines > 0) 
			{
				int cLineScroll = (int) std::min( (UINT) scrollRows_ - 1, wheelScrollLines);
				if (cLineScroll == 0) 
					cLineScroll++;

				cLineScroll *= (wheelDelta_ / WHEEL_DELTA);

				wheelDelta_ = wheelDelta_ % WHEEL_DELTA;
				
				setScrollPos(getScrollPos()+cLineScroll);
				//invalidateRect(0,TRUE);
			}
			break;
		}
		case WM_SIZE:
		{
			scrollV( HIWORD(lParam) );
			scrollH( LOWORD(lParam) );
			invalidateRect(0,TRUE);
			return mol::Window::wndProc(hWnd, message, wParam, lParam);
			return 0;
		}
	} // end switch
	return mol::Window::wndProc(hWnd, message, wParam, lParam);
}

void ScrollWnd::scrollV(unsigned int h)
{	
	siV_.nMax   = scrollRows_;//max
	siV_.nMin   = 0;
	siV_.nPage  = 1;
	if ( scrollRowHeight_ > 0 )
		siV_.nPage  = h/scrollRowHeight_;//pagesize
	siV_.nPos   = 0;
		
	::SetScrollInfo( *this, SB_VERT, &siV_, TRUE );
	::GetScrollInfo( *this, SB_VERT, &siV_ );
}

void ScrollWnd::scrollH(unsigned int w)
{	
	siH_.nMax   = scrollCols_;//max
	siH_.nMin   = 0;
	siH_.nPage  = 1;
	if ( scrollColWidth_>0 )
		siH_.nPage = w/scrollColWidth_;//pagesize
	siH_.nPos   = 0;
		
	::SetScrollInfo( *this, SB_HORZ, &siH_, TRUE );
	::GetScrollInfo( *this, SB_HORZ, &siH_ );
}



} // endnamespace mol
