#include "win/mdi.h"
#include "win/coctrl.h"
#include "win/layout.h"
#include "win/msgloop.h"
#include "ole/Rib.h"

namespace mol {

HWND MdiChild::createWindow( const mol::string& windowName, HMENU hMenu, const Rect& r, HWND p )
{
    registerClass(hMenu);
    parent_ = p;
    HWND client_ = addChild(parent_);
	mol::win::WndClass& wic = wndClass();
    hWnd_ = ::CreateMDIWindow( wic.getClassName().c_str(),
                                      windowName.c_str(),
                                      style(),
                                      r.left, r.top, r.right, r.bottom,
                                      client_,
									  mol::hinstance(),
                                      (LPARAM)(dynamic_cast<WndProc*>(this)));
    ::SetWindowLongPtr(hWnd_,GWL_EXSTYLE,(LONG_PTR)exstyle());

	show(SW_SHOW);
	return hWnd_;
}

void MdiChild::registerClass( HMENU& hMenu )
{
	if ( ::IsMenu((HMENU)hMenu) )
		menue_.attach((HMENU)hMenu,false);
	else
		menue_.load((int)hMenu);

	mol::win::WndClass& wic = wndClass();
    wic.setWndProc(MdiChild::windowProcedure);
    wic.registerClass();
}
////////////////////////////////////////////////////////////////////////////////////////////////
// MDI child windowprocedure
////////////////////////////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK MdiChild::windowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    try
    {
        // look up wnd_proc-pointer stored in HWND
		MdiChild* pThis = wndFromHWND<MdiChild>(hwnd);

        // if we have a valid wnd_proc-pointer, route to wndProc
        if (pThis && (::IsWindow(*pThis)) )
        {
            // hook WM_NCDESTROY to deregister mdi-child from framewnd
            if ( message == WM_NCDESTROY )
            {
                // get the frame
                HWND client_ = ::GetParent(hwnd);
                HWND frame = ::GetParent(client_);

				MdiFrame* mdi = wndFromHWND<MdiFrame>(frame);

                // kill child
                mdi->releaseChild(pThis);

                // call wndproc to kill the child
                pThis->wndProc( hwnd, message,wParam,lParam);
				LRESULT ret = ::DefMDIChildProc(hwnd,message,wParam,lParam);
                return  ret;
            }
            if ( message == WM_MDIACTIVATE )
            {
               ::PostMessage(pThis->mdiParent(),message,wParam,lParam);
            }
            return (pThis->wndProc( hwnd, message,wParam,lParam));
        }

        // if not, this should be the first WND-MESSAGE to arrive
        if (message == WM_CREATE)
        {
            if (( (LPCREATESTRUCT) lParam)->lpCreateParams != 0 )
            {
                LPCREATESTRUCT lpcs = (LPCREATESTRUCT)lParam;
                LPMDICREATESTRUCT lpmdics = (LPMDICREATESTRUCT)lpcs->lpCreateParams;

                // get this pointer stored in lParam from create()
				pThis = dynamic_cast<MdiChild*>( (mol::win::WndProc*)(lpmdics->lParam)  );

                // set THIS _hWnd
                pThis->hWnd_ = hwnd;

                // store the this-pointer in the HWND
                ::SetWindowLongPtr(hwnd, GWLP_USERDATA, (ULONG_PTR) dynamic_cast<WndProc*>(pThis));

                // call wndproc
                return (pThis->wndProc( hwnd, message,wParam,lParam));
            }
        }
    }
    catch (mol::X )
    {
			ODBGS1("MdiChild::windowProcedure %i",::GetLastError());
            PostQuitMessage(0);
    }
    return ::DefMDIChildProc(hwnd,message,wParam,lParam);
}
////////////////////////////////////////////////////////////////////////////////////////////////
// call this instead of defwndproc
////////////////////////////////////////////////////////////////////////////////////////////////

MdiChild::~MdiChild()
{
	windowMenu_ = 0;	
	this->cleanup();
}


int MdiChild::mdiMenuIndex()
{
	int state = ::GetMenuState(::GetMenu(mdiParent()),0,MF_BYPOSITION); //2064
	int l = LOBYTE(state);
	int h = HIBYTE(state);
	if ( l == (MF_BITMAP|MF_POPUP) )
	{
		return 1;
	}
	return 0;
}

UINT MdiChild::showContext( HMENU m )
{
	// show context and post result as WM_COMMAND to MDI parent
	return WndProc::showContext(m,mdiParent());
}

void MdiChild::post2Parent( UINT msg,  WPARAM wParam, LPARAM lParam)
{
	::PostMessage(mdiParent(),msg,wParam,lParam);
}

HWND MdiChild::mdiParent()
{
	return parent_;
}


LRESULT MdiChild::wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch ( message )
	{
		case WM_NCDESTROY :
		{
			delete this;
			return 0;
		}
		case WM_PAINT :
		{
			mol::PaintDC dc(hwnd);
			return 0;
		}
		case WM_ERASEBKGND :
		{
			if ( eraseBackground_ != 0 )
				return eraseBackground_;
		}
        case WM_MDIACTIVATE :
        {
			if ( mol::Ribbon::ribbon()->enabled() )
				break;

			//MdiFrame* mdi = wndFromHWND<MdiFrame>(mdiParent());
        	HWND newWnd = (HWND)lParam;
	        if ( newWnd == hwnd )
	        {				
				if ( menue_ )
					changeMenu(menue_,windowMenu_);
				OnLayout(0,0,0);
				break;
	        }
			break;
        }
		case WM_SIZE :
		{		
			OnSize(message,wParam,lParam);
			LRESULT ret = ::DefMDIChildProc(hwnd,message,wParam,lParam);
			return ret;
		}
		case WM_NOTIFY:
		{
			Crack msg(message,wParam,lParam);
			switch( msg.nmhdr()->code )
			{
				case RBN_HEIGHTCHANGE : 
				{
					return OnLayout(message,wParam,lParam);
				}
				case TTN_GETDISPINFO : 
				{
					::PostMessage(msg.nmhdr()->hwndFrom,message,wParam,lParam);
					return 0;
				}
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
			break;
		}
		case WM_COMMAND:
		{
			if ( wParam == 0 )
				return OnInvoke(message,wParam,lParam);
			break;
		}
		case WM_MEASUREITEM:
		{
			if ( wParam != 0 )
				return 0;

			LPMEASUREITEMSTRUCT lpmis = (LPMEASUREITEMSTRUCT) lParam; 
			mol::win::MenuItemInfo* item = (mol::win::MenuItemInfo*) lpmis->itemData;
			if ( item )
				return item->OnMeasureItem(message,wParam,lParam);
			return 0;
		}
		case WM_DRAWITEM:
		{
			if ( wParam != 0 )
				return 0;

			LPDRAWITEMSTRUCT lpdis = (LPDRAWITEMSTRUCT) lParam; 
			mol::win::MenuItemInfo* item = (mol::win::MenuItemInfo*) lpdis->itemData;

			if ( item )
				return item->OnDrawItem(message,wParam,lParam);
			return 0;
		}		
	}
	return ::DefMDIChildProc(hwnd,message,wParam,lParam);
}

HWND MdiChild::mdiClient()
{
	return ::GetParent(hWnd_);
}

HWND MdiChild::addChild(HWND parent)
{
	MdiFrame* mdi = wndFromHWND<MdiFrame>(parent);
    mdi->addChild(this);
    return mdi->mdiClient();
}

BOOL MdiChild::destroy( )
{
	return ::PostMessage( mdiClient(),  WM_MDIDESTROY , (WPARAM)(HWND)(*this), 0);
}


void MdiChild::activate( )
{
	::PostMessage( mdiClient(), WM_MDIACTIVATE, (WPARAM)(HWND)(*this), 0);
}

void MdiChild::maximize( )
{
	::PostMessage(  mdiClient(), WM_MDIMAXIMIZE, (WPARAM)(HWND)(*this), 0);
}

void MdiChild::minimize( )
{
    show(SW_MINIMIZE);
    update();
}

void MdiChild::restore ()
{
	::PostMessage(  mdiClient(), WM_MDIRESTORE, (WPARAM)(HWND)(*this), 0);
}

void MdiChild::next( )
{
	::PostMessage(  mdiClient(), WM_MDINEXT, 0, 0);
}

void MdiChild::changeMenu( HMENU hmenu, HMENU wndMenu)
{
	if ( (wndMenu == 0) && (windowMenu_ != 0 ))
		wndMenu = windowMenu_;

	mol::MdiFrame* frame = mol::wndFromHWND<MdiFrame>(mdiParent());
	frame->changeMenu(hmenu, wndMenu);
}

////////////////////////////////////////////////////////////////////////////////////////////////
//the mdi framework-windowproc
////////////////////////////////////////////////////////////////////////////////////////////////
MdiFrame::MdiFrame(int id)
: menuIndex_(-1),firstChildId_(id)
{
	eraseBackground_ = 1;
	isMidi_ = true;
}

int MdiFrame::mdiMenuIndex()
{
	int state = ::GetMenuState(::GetMenu(hWnd_),0,MF_BYPOSITION); //2064
	int l = LOBYTE(state);
	int h = HIBYTE(state);
	if ( l == (MF_BITMAP|MF_POPUP) )
	{
		return 1;
	}
	return 0;
}

HWND MdiFrame::mdiClient()
{
	return client_;
}

void MdiFrame::setFirstChildId(int id)
{
    firstChildId_ = id;
}

void MdiFrame::setMDIMenu(int m)
{
	menuIndex_ = m;
}

void MdiFrame::changeMenu( HMENU hmenu, HMENU wndMenu)
{
	setMenu(hmenu,wndMenu);

}

LRESULT MdiFrame::OnActivate( UINT, WPARAM wParam, LPARAM lParam )
{
      return ::PostMessage( client_, WM_MDIACTIVATE, wParam, lParam);
}

LRESULT MdiFrame::OnMaximize( UINT, WPARAM, LPARAM )
{
    return ::PostMessage( client_, WM_MDIMAXIMIZE, (WPARAM)getActive(), 0);
}

LRESULT MdiFrame::OnMinimize( UINT, WPARAM, LPARAM )
{
    ::ShowWindow(getActive(),SW_MINIMIZE);
    ::UpdateWindow(getActive());
    return OnNext(0,0,0);
}

LRESULT MdiFrame::OnRestore ( UINT, WPARAM, LPARAM )
{
    return ::PostMessage( client_, WM_MDIRESTORE, (WPARAM)getActive(), 0);
}

LRESULT MdiFrame::OnNext( UINT, WPARAM, LPARAM )
{
	return ::PostMessage( client_, WM_MDINEXT, 0, 0);
}

LRESULT MdiFrame::OnCascade( UINT, WPARAM, LPARAM )
{
	return ::PostMessage( client_, WM_MDICASCADE, 0, 0);
}

LRESULT MdiFrame::OnTileHorizontal(UINT, WPARAM, LPARAM )
{
	return ::PostMessage( client_, WM_MDITILE, 0, 0);
}

LRESULT MdiFrame::OnTileVertical(UINT, WPARAM, LPARAM )
{
	return ::PostMessage( client_, WM_MDITILE, MDITILE_VERTICAL, 0);
}

LRESULT MdiFrame::OnIconArrange(UINT, WPARAM, LPARAM )
{
	return ::PostMessage( client_, WM_MDIICONARRANGE, 0, 0);
}

LRESULT MdiFrame::OnCloseAll(UINT, WPARAM, LPARAM )
{
    for ( std::list<MdiChild*>::iterator it = children_.begin(); it != children_.end(); )
    {
            std::list<MdiChild*>::iterator jt = it;
            it++;
			::PostMessage(**jt,WM_CLOSE,0,0);
    }
	return 0;
}

LRESULT MdiFrame::OnCloseChild(UINT, WPARAM, LPARAM )
{
	return ::PostMessage(getActive(),WM_CLOSE,0,0);
}

HWND MdiFrame::getActive()
{
	return (HWND)(::SendMessage( client_, WM_MDIGETACTIVE, 0, 0));
}

void MdiFrame::destroyChild(HWND wnd)
{
	::PostMessage(client_,WM_MDIDESTROY,(WPARAM)(wnd),0);
}

void  MdiFrame::addChild(MdiChild* c)
{
	this->OnAddChild(*c);
    children_.push_back(c);

	if ( !mol::Ribbon::ribbon()->enabled())
		::DrawMenuBar(hWnd_);
}
int MdiFrame::count()
{
	return (int)children_.size();
}
HWND MdiFrame::childAt(int index)
{
	int i = 0;
	for ( std::list<MdiChild*>::iterator it = children_.begin(); it != children_.end(); it++ )
    {
		if ( i == index )
			return **it;
		i++;
    }
	return 0;
}

int  MdiFrame::index(HWND hwnd)
{
	int index = 0;
	for ( std::list<MdiChild*>::iterator it = children_.begin(); it != children_.end(); it++ )
    {
		if ( **it == hwnd )
			return index;
		index++;
    }
	return -1;
}

void  MdiFrame::releaseChild(MdiChild* c)
{
	this->OnReleaseChild(*c);
    for ( std::list<MdiChild*>::iterator it = children_.begin(); it != children_.end(); it++)
    {
        if ( *it == c )
        {
            children_.erase(it);
			if ( !::IsWindow( getActive()) )
			{
					changeMenu(0);
			}
			if ( !mol::Ribbon::ribbon()->enabled())
				::DrawMenuBar(hWnd_);
            return;
        }
    }
}



LRESULT CALLBACK MdiFrame::windowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    try
    {
        // look up wnd_proc-pointer stored in HWND
		MdiFrame* pThis = wndFromHWND<MdiFrame>(hwnd);

        // hook WM_CREATE to create MDI-client_
        if (message == WM_CREATE)
        {
            if (pThis)
            {
                if (((LPCREATESTRUCT) lParam)->lpCreateParams!=0)
                {
                    LPCREATESTRUCT lpcs = ((LPCREATESTRUCT)lParam);
                    pThis->createMDIClient(lpcs);
                }
				if ( pThis->uiBuilder_)
				{
					pThis->uiBuilder_->makeUI();
				}
            }
        }
        if (pThis && (::IsWindow(*pThis)) )
        {
			bool d = pThis->deleteOnNCDestroy_;
            LRESULT res = pThis->wndProc( hwnd, message,wParam,lParam);
			if (message == WM_NCDESTROY)
			{				
				if ( d )
					delete pThis;
			}
            return res;
        }
        // if not, this should be the first WND-MESSAGE we can catch incl the CreateParams
        // we're interested in
        if (message == WM_NCCREATE)
        {
            if (((LPCREATESTRUCT) lParam)->lpCreateParams != 0)
            {
                // get this pointer stored in lParam from Wnd::create()
				pThis = dynamic_cast<MdiFrame*>( (mol::win::WndProc*)(((LPCREATESTRUCT)lParam)->lpCreateParams ));

                // set THIS _hWnd
                pThis->hWnd_ = hwnd;

                // store the this-pointer in the HWND
                ::SetWindowLongPtr(hwnd, GWLP_USERDATA, (ULONG_PTR) dynamic_cast<WndProc*>(pThis));

                // call wndproc
                return (pThis->wndProc( hwnd, message,wParam,lParam));
            }
        }
    }
    catch (mol::X )
    {
			ODBGS1("MdiFrame::windowProcedure %i",::GetLastError());
            PostQuitMessage(0);
    }
    return ::DefWindowProc(hwnd,message,wParam,lParam);
}

////////////////////////////////////////////////////////////////////////////////////////////////
// call this instead of defwndproc
// also call for WM_SIZE, WM_COMMAND, WM_SETFOCUS, WM_SETMENUCHAR
////////////////////////////////////////////////////////////////////////////////////////////////

LRESULT MdiFrame::wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch ( message )
	{
		case WM_PAINT :
		{
			mol::PaintDC dc(hwnd);
			return 0;
		}
		case WM_ERASEBKGND :
		{
			return eraseBackground_;
		}
		case WM_CLOSE :
		{
			destroy();
			return 0;
		}
		case WM_NCDESTROY :
		{
			::PostQuitMessage(0);
			return 0;
		}
		case WM_SIZE :
		{
			::InvalidateRect(mdiClient(),0,FALSE);
			return OnSize(message,wParam,lParam);
		}
		case WM_NOTIFY:
		{
			Crack msg(message,wParam,lParam);
			switch( msg.nmhdr()->code )
			{
				case RBN_HEIGHTCHANGE : 
				{
					::InvalidateRect(mdiClient(),0,FALSE);
					return OnLayout(message,wParam,lParam);
				}
				case TTN_GETDISPINFO : 
				{
					if ( !mol::win::tabToolTips().tabToolNotify(msg.nmhdr()->hwndFrom,message,wParam,lParam) )
						::SendMessage(msg.nmhdr()->hwndFrom,message,wParam,lParam);
					return 0;
				}
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
			break;
		}
		case WM_COMMAND:
		{
			if ( wParam == 0 )
				return OnInvoke(message,wParam,lParam);
			break;
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
    if ( ::IsWindow(client_))
		return ::DefFrameProc(hwnd,client_,message,wParam,lParam);
    return ::DefWindowProc(hwnd,message,wParam,lParam);
}

LRESULT MdiFrame::OnSize( UINT message, WPARAM wParam, LPARAM lParam)
{
	::InvalidateRect(mdiClient(),0,FALSE);
	if ( layout_ )
		layout_->OnSize(message,wParam,lParam);

	invalidateRect(0,TRUE);
	update();
	return 0;
}

LRESULT MdiFrame::OnLayout( UINT message, WPARAM wParam, LPARAM lParam)
{
	::InvalidateRect(mdiClient(),0,FALSE);
	mol::Rect r;
	getClientRect(r);
	if ( layout_ )
		layout_->OnSize(message,0,MAKELPARAM(r.right,r.bottom));

	invalidateRect(0,TRUE);
	update();
	return 0;
}

HWND MdiFrame::createWindow( const mol::string& windowName, HMENU hMenu, const Rect& r, HWND parent )
{
		mol::win::WndClass& wic = this->wndClass();
        wic.setWndProc(MdiFrame::windowProcedure);
        wic.registerClass();
		
		if (::IsMenu((HMENU)hMenu) )
		{
			menue_ = (HMENU)hMenu;
		}
		else
			if (hMenu)
				menue_ = ::LoadMenu(mol::hinstance(),MAKEINTRESOURCE(hMenu));
			

        return this->hWnd_ = ::CreateWindowEx( exstyle(),
                                               wic.getClassName().c_str(),
                                               windowName.c_str(),
                                               style(),
                                               r.left, r.top, r.right, r.bottom,
                                               parent,
                                               (HMENU)(this->menue_),
											   mol::hinstance(),
                                               (PVOID)this );
}

void MdiFrame::registerClass( int& hMenu )
{
	mol::win::WndClass& wic = this->wndClass();
    wic.registerClass();
}

void MdiFrame::createMDIClient( LPCREATESTRUCT lpcs )
{
    CLIENTCREATESTRUCT cs;
    HMENU mainMenu = lpcs->hMenu;
    HMENU Menu;
    if ( menuIndex_ != -1 )
    {
        Menu = ::GetSubMenu(mainMenu,menuIndex_);
    }
    else
    {
        int n = ::GetMenuItemCount(mainMenu);
        if ( n > 1 )
                n--;
        n--;
        Menu = ::GetSubMenu(mainMenu,n);
    }
    cs.hWindowMenu  = Menu;
    cs.idFirstChild = firstChildId_;
	RECT r;
	getClientRect(r);

    client_ = ::CreateWindowEx( WS_EX_WINDOWEDGE, 
								_T("MDICLIENT"), 
								0, 
								WS_CHILD|WS_CLIPCHILDREN|
								WS_VISIBLE|MDIS_ALLCHILDSTYLES,
								0,0,r.right,r.bottom,
								hWnd_,
								(HMENU)1,
								mol::hinstance(),
								(PSTR)&cs);
	mol::win::mdiClient().set(client_);

}

BOOL MdiFrame::invalidate( BOOL erase )
{
	::InvalidateRect(mdiClient(),0,erase);
	return invalidateRect(0,erase);
}

void MdiFrame::OnReleaseChild(HWND hwnd) 
{
	if ( count() == 0 )
		changeMenu(0);
};

void MdiFrame::setMenu( HMENU newMenu, HMENU windowMenu   )
{
	if ( !newMenu )
		newMenu = menue_;

	if ( newMenu == ::GetMenu(*this) )
	{
		if ( !mol::Ribbon::ribbon()->enabled())
		{
			::SendMessage( mdiClient(), WM_MDIREFRESHMENU ,0,0);	

			::DrawMenuBar( *this );
		}
		return;
	}

	HMENU wm = windowMenu;
	if ( !wm || !::IsMenu(wm))
	{
			int c = ::GetMenuItemCount(newMenu);
			if ( c>1 )
				wm = ::GetSubMenu(newMenu,c-2);
			else
			if ( c > 0 )
				wm = ::GetSubMenu(newMenu,c-1);
			else
				wm = 0;
	}
	if ( !mol::Ribbon::ribbon()->enabled())
	{
	    ::SendMessage( mdiClient(),WM_MDISETMENU, (WPARAM)newMenu, (LPARAM)(wm) );

		::SendMessage( mdiClient(), WM_MDIREFRESHMENU ,0,0);	
		::DrawMenuBar( *this );
	}
}

void MdiFrame::redraw()
{
	::RedrawWindow(mdiClient(),0,0,RDW_FRAME|RDW_INVALIDATE);			
	::InvalidateRect(mdiClient(),0,TRUE);

	ODBGS("MdiFrame::redraw()");
	for ( int i = 0; i < count(); i++ )
	{
		::RedrawWindow(childAt(i),0,0,RDW_FRAME|RDW_INVALIDATE);			
		::InvalidateRect(childAt(i),0,TRUE);
	}

	::RedrawWindow(*this,0,0,RDW_FRAME|RDW_INVALIDATE);			
	::InvalidateRect(*this,0,TRUE);
}

} // end namespace mol
