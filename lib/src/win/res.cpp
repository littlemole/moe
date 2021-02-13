#include "win/Res.h"
#include "win/Core.h"
#include "win/coctrl.h"
#include "win/file.h"
#include <docobj.h>
#include "xml/xml.h"
#include "win/v7.h"

namespace mol  {
	  

/////////////////////////////////////////////////////////////////////

HICON Icon::load( long id, int w, int h , int options)
{
    hIcon_ = (HICON) LoadImage( hinstance(), MAKEINTRESOURCE(id), IMAGE_ICON,w,h ,options);
    return hIcon_;
}

/////////////////////////////////////////////////////////////////////

HANDLE Bmp::loadRaw( long hImage, int w, int h , int options )
{
    if(bmp_)
        ::DeleteObject(bmp_);

    bmp_ = (HANDLE)::LoadImage( hinstance(), MAKEINTRESOURCE(hImage),IMAGE_BITMAP,w,h, options );

    return bmp_;
}

int Bmp::width()
{
	return w_;
}

int Bmp::height()
{
	return h_;
}

HBITMAP Bmp::load( long id )
{
	HBITMAP oldBitmap;
	
	if(bitmap_) ::DeleteObject(bitmap_);
	
	if ( bitmap_ = ::LoadBitmap( mol::hinstance(),MAKEINTRESOURCE(id)) )
	{
		mol::DC dc(::GetDesktopWindow());
		mol::DC memDC(::CreateCompatibleDC(dc));

		int width,height;
		BITMAP bmInfo;
		::GetObject(bitmap_,sizeof(bmInfo),&bmInfo);	
		width = bmInfo.bmWidth;
		height = bmInfo.bmHeight;

		oldBitmap = (HBITMAP)::SelectObject(memDC,bitmap_);

		COLORREF colorWindow = ::GetSysColor(COLOR_3DFACE);
		COLORREF sourceColor = ::GetPixel(memDC,1,1);

		int i,j;
		for(i=0; i < height; i++)
		{
			for(j=0; j < width; j++)
			{
				COLORREF c = ::GetPixel(memDC,j,i);
				if ( ::GetPixel(memDC,j,i) == sourceColor )
				{
					::SetPixel(memDC,j,i,colorWindow);
				}
			}
		}
		::SelectObject(memDC,oldBitmap);
		w_ = width;
		h_ = height;
	}
	return bitmap_;
}
/////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////

namespace win {

MenuItemInfo::MenuItemInfo(const std::wstring& txt, bool s, long i,HBITMAP b)
: text_(txt), separator_(s), icon_(i), bitmap_(b)
{}

const std::wstring& MenuItemInfo::text()
{
	return text_;
}

long MenuItemInfo::icon()
{
	return icon_;
}

bool MenuItemInfo::separator()
{
	return separator_;
}

HBITMAP MenuItemInfo::bitmap()
{
	return bitmap_;
}

LRESULT MenuItemInfo::OnMeasureItem( UINT, WPARAM wParam, LPARAM lParam)
{
	LPMEASUREITEMSTRUCT lpmis = (LPMEASUREITEMSTRUCT) lParam; 

	if ( separator_ )
	{
		lpmis->itemWidth = 50; 
		lpmis->itemHeight = 2; 
		return 0;
	}

	SIZE s = {0,0};
	mol::DC dc(::GetDesktopWindow());
	::GetTextExtentPoint32(dc,text_.c_str(), (int)text_.size(),&s);
    lpmis->itemWidth = s.cx+40; 
    lpmis->itemHeight = s.cy+10; 
	return 0;
}

LRESULT MenuItemInfo::OnDrawItem( UINT, WPARAM wParam, LPARAM lParam)
{
	LPDRAWITEMSTRUCT lpdis = (LPDRAWITEMSTRUCT) lParam; 
 
	int wCheckX = GetSystemMetrics(SM_CXMENUCHECK); 
    int nTextX = /*wCheckX +*/ lpdis->rcItem.left; 
	int nTextY = lpdis->rcItem.top; 

	COLORREF crBkgnd,crTxt;
	crBkgnd,crTxt = 0;

	if ( lpdis->itemState & ODS_GRAYED )
	{
		crTxt = ::SetTextColor( lpdis->hDC,::GetSysColor(COLOR_GRAYTEXT));
	}

    if (lpdis->itemState & ODS_SELECTED) 
    { 
        crBkgnd = SetBkColor(lpdis->hDC, ::GetSysColor(COLOR_BTNFACE)); 
    } 
	else
	{
		crBkgnd = SetBkColor(lpdis->hDC, ::GetSysColor(COLOR_WINDOW)); 
	}

	if ( separator_ )
	{
		::FillRect(lpdis->hDC,&lpdis->rcItem,(HBRUSH)::GetSysColorBrush(COLOR_BTNFACE));
	}
	else
	{
		// white bkg
		HBRUSH brush = ::GetSysColorBrush(COLOR_WINDOW);
		mol::Rect r2(lpdis->rcItem);
		r2.left=r2.left+24;
		::FillRect(lpdis->hDC,&r2,brush);

		// text
		::ExtTextOut(lpdis->hDC, nTextX + 30, nTextY+5,  ETO_OPAQUE, 
				&lpdis->rcItem, text_.c_str(), (int) text_.size(), NULL); 


		mol::Rect r(lpdis->rcItem);
		r.right = r2.left;
		::FillRect(lpdis->hDC,&r,::GetSysColorBrush(COLOR_BTNFACE));

		if ( lpdis->itemState & ODS_SELECTED )
			::FrameRect(lpdis->hDC,&lpdis->rcItem,(HBRUSH)::GetStockObject(GRAY_BRUSH));


		if ( icon_ != -1 )
		{
			mol::DC mem = ::CreateCompatibleDC(lpdis->hDC);
			HGDIOBJ def = mem.select( (HGDIOBJ)(HBITMAP)bitmap_);
			int x = icon_*16;
			COLORREF c = ::GetPixel(mem,0,0);
			::TransparentBlt(lpdis->hDC,4,nTextY+5,16,16,mem,x,0,16,16,c);
			mem.select(def);
		}

		UINT state = lpdis->itemState;
		if ( state & ODS_CHECKED )
		{
			DrawCheckMark(lpdis->hDC,5,nTextY+5,RGB(64,64,128));
		}
	}
    SetBkColor(lpdis->hDC, crBkgnd); 
	if ( crTxt)
		SetTextColor(lpdis->hDC, crTxt); 
	return 0;
}



void MenuItemInfo::DrawCheckMark(HDC dc,int x,int y,COLORREF color)
{
	HPEN pen = ::CreatePen(PS_SOLID,0,color);
	HGDIOBJ oldpen = ::SelectObject(dc, (HGDIOBJ) pen);

	x += 6;
	y += 6;

	::MoveToEx( dc,x,y+2, 0);
	::LineTo( dc,x,y+2);

	::MoveToEx( dc,x+1,y+3, 0);
	::LineTo( dc,x+1,y+6);
	
	::MoveToEx( dc,x+2,y+4, 0);
	::LineTo( dc,x+2,y+7);
	
	::MoveToEx( dc,x+3,y+3, 0);
	::LineTo( dc,x+3,y+6);
	
	::MoveToEx( dc,x+4,y+2, 0);
	::LineTo( dc,x+4,y+5);
	
	::MoveToEx( dc,x+5,y+1, 0);
	::LineTo( dc,x+5,y+4);

	::MoveToEx( dc,x+6,y, 0);
	::LineTo( dc,x+6,y+3);

	::SelectObject(dc,oldpen);
	::DeleteObject(pen);
}

}// end namespace win

Menu::Menu()
{
	hMenu_ = 0;
    atached_ = false;
}

/////////////////////////////////////////////////////////////////////

Menu::Menu( HMENU hmenu, bool a)
{
    hMenu_   = hmenu;
    atached_ = a;
}

/////////////////////////////////////////////////////////////////////

Menu::Menu(HWND hwnd, bool a)
{
    atached_ = a;
	getMenu(hwnd);
}

/////////////////////////////////////////////////////////////////////

Menu::~Menu()
{
    if ( hMenu_ && (atached_))
        ::DestroyMenu(hMenu_);
}


BOOL  Menu::addItem(UINT_PTR cmd, const std::wstring& snewItem, long iicon, long bmp, bool checked, bool enabled)
{ 
	mol::win::MenuItemInfo* inf = new mol::win::MenuItemInfo(
		snewItem,
		false,
		iicon,
		mol::UI().Bitmap(bmp)
	);

	MENUITEMINFO mi;
	::ZeroMemory(&mi, sizeof(mi));
	mi.cbSize = sizeof(mi);
	mi.wID = (int)cmd;
	mi.fType = MFT_OWNERDRAW;
	mi.dwItemData = (ULONG_PTR)inf;
	mi.fMask = MIIM_DATA | MIIM_TYPE | MIIM_ID | MIIM_STATE;

	int e = enabled ? MFS_ENABLED : MFS_DISABLED;
	mi.fState = checked ? e : MFS_CHECKED | e;

	return ::InsertMenuItem(hMenu_, ::GetMenuItemCount(hMenu_), TRUE, &mi);
}


BOOL  Menu::addSubmenu( HMENU sub, const std::wstring& snewItem, long cmd, long iicon, long bmp)
{
	mol::win::MenuItemInfo* inf = new mol::win::MenuItemInfo(
		snewItem,
		false,
		iicon,
		mol::UI().Bitmap(bmp)
	);

	return ::AppendMenu(hMenu_, MF_OWNERDRAW | MF_POPUP | MF_STRING, (UINT_PTR)sub, (wchar_t*)inf);
}

BOOL Menu::addSeparator(bool ownerDrawn)
{
	if ( ownerDrawn ) 
	{
		mol::win::MenuItemInfo* inf = new mol::win::MenuItemInfo(_T(""),true,-1,0);
		return ::AppendMenu(hMenu_, MF_SEPARATOR | MF_OWNERDRAW, (UINT_PTR)0, (wchar_t*)inf);
	}
	return ::AppendMenu(hMenu_,MF_SEPARATOR,(UINT_PTR)0,0);
}

/////////////////////////////////////////////////////////////////////

void Menu::attach( HMENU hmenu, bool a)
{
    atached_ = a;
    hMenu_   = hmenu;
}

/////////////////////////////////////////////////////////////////////

HMENU Menu::load(LONG_PTR id, bool a )
{
    atached_ = a;
    hMenu_ = ::LoadMenu( hinstance(), MAKEINTRESOURCE(id) );
    return hMenu_;
}

/////////////////////////////////////////////////////////////////////

HMENU  Menu::create()
{
    atached_ = true;
    hMenu_ = ::CreateMenu();
    return hMenu_;
}


HMENU  Menu::createPopup()
{
    atached_ = true;
    hMenu_ = ::CreatePopupMenu();
    return hMenu_;
}
/////////////////////////////////////////////////////////////////////

void  Menu::detach()
{
    atached_ = false;
}

/////////////////////////////////////////////////////////////////////

BOOL  Menu::addItem( UINT_PTR inewItem, const std::wstring& snewItem, UINT flags )
{
    return ::AppendMenu( hMenu_, flags, (UINT_PTR)inewItem, snewItem.c_str() );
}

/////////////////////////////////////////////////////////////////////

BOOL  Menu::addSubmenu( HMENU sub, const std::wstring& snewItem, UINT flags )
{
    return addItem( (UINT_PTR)sub, snewItem.c_str(),flags  );
}


/////////////////////////////////////////////////////////////////////

BOOL  Menu::remove ( UINT pos, UINT flags )
{
	if ( flags & MF_BYPOSITION )
	{
		MENUITEMINFO mi;
		::ZeroMemory( &mi, sizeof(mi) );
		mi.cbSize = sizeof(mi);
		mi.fMask = MIIM_DATA|MIIM_FTYPE|MIIM_SUBMENU;

		::GetMenuItemInfo( hMenu_, pos, TRUE, &mi );

		if ( mi.fType & MFT_OWNERDRAW )
		{
			if ( mi.hSubMenu != NULL )
			{
				Menu m(mi.hSubMenu);
				int c = ::GetMenuItemCount(m);
				for ( int i = 0; i < c; i++ )
				{
					m.remove(i,MF_BYPOSITION);
				}
				delete (mol::win::MenuItemInfo*)(mi.dwItemData);
			}
			else
			{
				delete (mol::win::MenuItemInfo*)(mi.dwItemData);
			}
		}
	}
    return ::DeleteMenu( hMenu_, pos, flags );
}

/////////////////////////////////////////////////////////////////////

HMENU Menu::getSubMenu( long pos )
{
    return ::GetSubMenu( hMenu_, pos );
}

/////////////////////////////////////////////////////////////////////

LONG_PTR Menu::trackPopup( HWND hWnd, int x, int y , int flags)
{
    return ::TrackPopupMenu(hMenu_, flags,x,y,0, hWnd,0);
}

/////////////////////////////////////////////////////////////////////

LONG_PTR Menu::returnTrackPopup( HWND hWnd, int x, int y, int flags )
{
    return ::TrackPopupMenu(hMenu_, flags,x,y,0, hWnd,0);
}

/////////////////////////////////////////////////////////////////////

DWORD Menu::checkItem  ( long i , int flags)
{
    return ::CheckMenuItem( hMenu_, i, flags|MF_CHECKED );
}

/////////////////////////////////////////////////////////////////////

DWORD Menu::unCheckItem( long i , int flags)
{
    return ::CheckMenuItem( hMenu_, i, flags|MF_UNCHECKED );
}

/////////////////////////////////////////////////////////////////////

DWORD Menu::enableItem  ( long i , int flags)
{
	int f = flags|MF_ENABLED;
	f = f & ~MF_DISABLED;
	f = f & ~MF_GRAYED;
    return (DWORD)(::EnableMenuItem( hMenu_, i, flags|MF_ENABLED));
};

/////////////////////////////////////////////////////////////////////

DWORD Menu::disableItem( long i , int flags)
{
    return (DWORD)(::EnableMenuItem( hMenu_, i, flags|MF_GRAYED));
}

/////////////////////////////////////////////////////////////////////

HMENU Menu::createContext()
{
    Menu dummy;
    dummy.create();
    create();
    addSubmenu((HMENU) dummy,_T("dummy"), MF_POPUP );
    hMenu_ = dummy;
    dummy.hMenu_=0;
    return hMenu_;
}

/////////////////////////////////////////////////////////////////////

UINT Menu::GetMenuState( UINT uId, UINT flags )
{
    return ::GetMenuState( hMenu_, uId, flags );
}

/////////////////////////////////////////////////////////////////////

HMENU Menu::getMenu( HWND hwnd )
{
    return hMenu_ = ::GetMenu( hwnd );
}

/////////////////////////////////////////////////////////////////////

namespace win  {

DCbase::~DCbase()
{
    for ( std::list<HGDIOBJ>::iterator it = obList_.begin(); it != obList_.end(); it++ )
    {
        ::SelectObject(hdc_, *it );
        //::DeleteObject(_old); note:object should delete itself!
    }
    obList_.clear();
}

/////////////////////////////////////////////////////////////////////

HGDIOBJ DCbase::select( HGDIOBJ obj)
{
    HGDIOBJ old = ::SelectObject( hdc_, obj );
    obList_.push_front( old );
    return old;
}

/////////////////////////////////////////////////////////////////////

} // endnamespace mol::win


UserInterface& UI()
{
	return mol::singleton<UserInterface>();
}

UserInterface::UserInterface()
{
}

/*
HMENU UserInterface::Menu(long id)
{
	if ( menus_.count(id) == 0 )
		return 0;
	return menus_[id];
}

HMENU UserInterface::SubMenu( long menu, long id)
{
	if ( submenus_.count(menu) == 0 )
		return 0;

	if ( submenus_[menu].count(id) == 0 )
		return 0;
	return submenus_[menu][id];
}
*/
HBITMAP UserInterface::Bitmap( long id)
{
	if ( bmps_.count(id) == 0 )
		return 0;

	return bmps_[id].hbitmap;
}

int UserInterface::BitmapCmd( long id, long index)
{
	if ( bmps_.count(id) == 0 )
		return 0;

	if ( index >= bmps_[id].index.size()  )
		return 0;

	int r = bmps_[id].index[index];

	return r;
}

int UserInterface::BitmapCmdIndex( long id, long cmd)
{
	if ( bmps_.count(id) == 0 )
		return 0;

	std::vector<long>& v = bmps_[id].index;
	for ( unsigned int i = 0; i < v.size(); i++ )
	{
		if ( v[i] == cmd )
			return i;
	}
	return -1;
}

HWND UserInterface::hWnd( long id)
{
	if ( hWnds_.count(id) == 0 )
		return 0;

	return hWnds_[id];
}


void UserInterface::addBmp( long key)
{
	mol::Bmp b;
	b.load(key);
	UserInterface::bitmapinfo bi;
	bi.hbitmap = b;
	bmps_.insert( std::make_pair( key, bi ) );
}

void UserInterface::addBmpCmd( long bmp, long cmd)
{
	if ( bmps_.count(bmp) > 0 ) {
		bmps_[bmp].index.push_back(cmd);
	}

	long index = ((long)bmps_[bmp].index.size())-1;

	HDC desk = ::GetDC(::GetDesktopWindow());
	
	HDC memDCsrc  = ::CreateCompatibleDC(desk);
	HDC memDCdest = ::CreateCompatibleDC(desk);
	
	HBITMAP oldBmpSrc = (HBITMAP)::SelectObject( memDCsrc,(HGDIOBJ)Bitmap(bmp));

	HBITMAP compatBmp  = ::CreateCompatibleBitmap(desk,16,16);
	HBITMAP oldBmpDest = (HBITMAP)::SelectObject( memDCdest,(HGDIOBJ)compatBmp);

	::BitBlt(memDCdest,0,0,16,16,memDCsrc,index*16,0,SRCCOPY);
//	::TransparentBlt( memDCdest,0,0,16,16,memDCsrc,index*16,0,16,16, ::GetPixel(memDCsrc,0,0) );

	::SelectObject( memDCsrc,(HGDIOBJ)oldBmpSrc);
	::SelectObject( memDCdest,(HGDIOBJ)oldBmpDest);

	::DeleteDC(memDCsrc);
	::DeleteDC(memDCdest);

	::ReleaseDC(::GetDesktopWindow(),desk);

	explodedBmps_.insert( std::make_pair( cmd, compatBmp ) );
}

/*
void UserInterface::addMenu( long menu)
{
	HMENU popup = ::CreateMenu();
	menus_.insert(std::make_pair(menu,popup));
	submenus_.insert(std::make_pair( menu, std::map<int,HMENU>() ) );    
}

void UserInterface::addMenuSeparator(int root, int menu)
{
	if ( mol::OS::has_uac() )
	{
		// vista++
		::AppendMenu( SubMenu(root,menu),MF_SEPARATOR,0,0);
	}
	else
	{
		// winxp
		mol::win::MenuItemInfo* inf = new mol::win::MenuItemInfo(_T(""),true,-1,0);
		::AppendMenu(SubMenu(root, menu), MF_SEPARATOR | MF_OWNERDRAW, (UINT_PTR)0, (wchar_t*)inf);
	}
}

void UserInterface::addSubMenu(int root, int menu, int subMenu)
{
	HMENU popup = ::CreateMenu();
	::AppendMenu( UI().Menu(menu),MF_POPUP|MF_STRING|MF_ENABLED,(UINT_PTR)popup,UI().CmdString(subMenu).c_str());
	submenus_[root].insert(std::make_pair(subMenu,popup));	
}

void UserInterface::addSubMenu(int root, int menu, int cmd, int bmp)
{
	HMENU popup = ::CreateMenu();
	HMENU submenu  = SubMenu(root,menu);

	int iicon = -1;
	HBITMAP b = 0;
	if ( bmps_.count(bmp) > 0 )
	{
		int c = BitmapCmdIndex(bmp,cmd);
		if ( c != -1 )
		{
			iicon = c;
			b = bmps_[bmp].hbitmap;
		}
	}

	std::wstring label = CmdString(cmd);
	
	if ( mol::OS::has_uac() )
	{
		// vista++
		::AppendMenu(submenu, MF_POPUP | MF_STRING | MF_ENABLED, (UINT_PTR)popup, (wchar_t*)label.c_str());

		int index = ::GetMenuItemCount(submenu)-1;

		MENUITEMINFO mii = { sizeof(mii) };
		mii.fMask = MIIM_BITMAP;
		mii.hbmpItem = explodedBmps_[cmd];
		::SetMenuItemInfo(submenu, index, TRUE, &mii);
	}
	else
	{
		//winxp
		mol::win::MenuItemInfo* inf = new mol::win::MenuItemInfo( label.c_str(),false,iicon,b);
		::AppendMenu(submenu, MF_OWNERDRAW | MF_POPUP | MF_STRING | MF_ENABLED, (UINT_PTR)popup, (wchar_t*)inf);
	}

	submenus_[root].insert(std::make_pair(cmd,popup));
}

void UserInterface::addMenuItem( int root, int menu, int cmd, int bmp, int index, bool checked, bool enabled )
{
	int iicon = -1;
	HBITMAP b = 0;
	if ( bmps_.count(bmp) > 0 )
	{
		int c = BitmapCmdIndex(bmp,index);
		if ( c != -1 )
		{
			iicon = c;
			b = bmps_[bmp].hbitmap;
		}
	}

	std::wstring label = CmdString(cmd);
	HMENU submenu = SubMenu(root,menu);
	int cnt = ::GetMenuItemCount( submenu );

	if ( mol::OS::has_uac() )
	{
		// vista++
		MENUITEMINFO mii = { sizeof(mii) };
		mii.fMask = MIIM_BITMAP;
		mii.hbmpItem = explodedBmps_[index];

		::InsertMenu( submenu,
					  cnt,
					  MF_STRING|MF_BYPOSITION,
					  cmd, 
					  label.c_str()
					);

		::SetMenuItemInfo(submenu, cnt, TRUE, &mii);
	}
	else
	{
		//winxp
		mol::win::MenuItemInfo* inf = new mol::win::MenuItemInfo(label.c_str(),false,iicon,b);

		MENUITEMINFO mi;
		::ZeroMemory(&mi,sizeof(mi));
		mi.cbSize = sizeof(mi);
		mi.dwItemData = (ULONG_PTR)inf;
		mi.fMask = MIIM_DATA|MIIM_TYPE|MIIM_ID|MIIM_STATE;
		int e = enabled ? MFS_ENABLED : MFS_DISABLED;
		mi.fState = checked ? MFS_CHECKED|e : e;
		mi.wID = cmd;
		mi.fType = MFT_OWNERDRAW;

		::InsertMenuItem(submenu,index,TRUE,&mi);		
	}
}

*/
//////////////////////////////////////////////////////////////




/*
void UIBuilder::addWnd(int key, HWND wnd)
{
	UI().hWnds_.insert( std::make_pair( key, wnd ) );
}
*/

} // endnamespace mol
