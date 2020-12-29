#ifndef RESOURCES_DEF_
#define RESOURCES_DEF_

#include "win/app.h"
#include "win/mem.h"
#include "win/core.h"
#include <set>


extern "C" void load_codegen_metadata();

namespace mol  {

class ToolbarInfo;
class Element;

//////////////////////////////////////////////////////////////////////
// Icons
//////////////////////////////////////////////////////////////////////

class Icon
{
public:
    Icon() : hIcon_(0) {};
    Icon(int id, int w=16, int h=16) {  load(id, w, h); }
    operator HICON() { return hIcon_; };

    HICON load( int id, int w=16, int h=16, int options = LR_DEFAULTCOLOR );

private:
    HICON hIcon_;
};

//////////////////////////////////////////////////////////////////////
// Bitmaps
//////////////////////////////////////////////////////////////////////

class Bmp
{
public:
    Bmp() : bmp_(0),bitmap_(0) {}
    Bmp( int id): bmp_(0),bitmap_(0)  { load(id); }
	HBITMAP load( int hImage) ;
    HANDLE loadRaw( int hImage, int w = 16, int h = 16 , int options = LR_DEFAULTCOLOR ) ;
    operator HANDLE() { return bmp_; };
	operator HBITMAP() { return bitmap_; };

	int width();
	int height();
private:
	int w_;
	int h_;
    HANDLE bmp_;
	HBITMAP bitmap_;
};

//////////////////////////////////////////////////////////////////////
// Menues
//////////////////////////////////////////////////////////////////////

namespace win {

class MenuItemInfo
{
public:
	MenuItemInfo(const std::wstring& txt, bool s, int i,HBITMAP b);

private:
	std::wstring text_;
	int icon_;
	bool separator_;
	HBITMAP bitmap_;

public:
	const std::wstring& text();
	int icon();
	bool separator();
	HBITMAP bitmap();

	LRESULT OnMeasureItem( UINT, WPARAM wParam, LPARAM lParam);
	LRESULT OnDrawItem( UINT, WPARAM wParam, LPARAM lParam);

private: 
	void DrawCheckMark(HDC dc,int x,int y,COLORREF color);
};


} // end namespace win


class Menu
{
public:
    Menu();
    Menu( Menu& m ) : atached_(false), hMenu_(m) {}
	Menu(HWND hwnd, bool atached = false );
    Menu( HMENU hMenu, bool atached = false );
    virtual ~Menu();

    HMENU create();
    HMENU createPopup();

	void attach( HMENU hMenu, bool atached = true );
    HMENU load( int id, bool atached = true  );

    BOOL  addItem   ( UINT_PTR cmd, const std::wstring& snewItem, UINT flags = MF_STRING);
	
	BOOL  addItem   ( UINT_PTR cmd, int iicon, int bmp, bool checked = false, bool enabled = true );

    BOOL  addSubmenu( HMENU sub, const std::wstring& snewItem, UINT flags = MF_POPUP|MF_STRING );

    BOOL  addSubmenu( HMENU sub, int cmd);

	BOOL  addSubmenu( HMENU sub, int cmd, int iicon, int bmp);

	BOOL addSeparator(bool ownerDrawn = true);

    BOOL  remove ( UINT pos, UINT flags );

    HMENU getSubMenu( int pos );
    HMENU getMenu(HWND wnd );

    DWORD checkItem  ( int i , int flags = MF_BYCOMMAND);
    DWORD unCheckItem( int i , int flags = MF_BYCOMMAND);
    DWORD enableItem ( int i , int flags = MF_BYCOMMAND);
    DWORD disableItem( int i , int flags = MF_BYCOMMAND);

    UINT  GetMenuState( UINT uId, UINT flags =MF_BYCOMMAND);
    int   trackPopup( HWND hWnd, int x, int y, int flags = TPM_LEFTALIGN|TPM_RIGHTBUTTON );
    int   returnTrackPopup( HWND hWnd, int x, int y , int flags = TPM_RETURNCMD|TPM_LEFTALIGN|TPM_RIGHTBUTTON);
    HMENU createContext();

    operator HMENU() { return hMenu_; };

    void detach();

protected:
    bool	atached_;
    HMENU   hMenu_;
};

class PopupMenu : public Menu
{
public:
	 PopupMenu()
	 {
		 createPopup();
	 }
};

//////////////////////////////////////////////////////////////////////
// resources
//////////////////////////////////////////////////////////////////////

namespace win  {

class restype_text
{
public:	static wchar_t* type() { return _T("TXT"); }
};
class restype_html
{
public:	static wchar_t* type(){ return RT_HTML; } //"HTML"; }
};
class restype_img
{
public:	static wchar_t* type() { return _T("IMAGE"); }
};

} // end namespace win


template<class R = mol::win::restype_text>
class Resource
{
public:
    Resource()
    {
        res_  = 0;
        len_  = 0;
        data_ = 0;
    }

    Resource(int id)
    {
        res_  = 0;
        len_  = 0;
        data_ = 0;
        load(id);
    }

    ~Resource()
    {
        if ( res_)
                ::FreeResource(res_);
    }

    BOOL load(int id)
    {
        return load( id, mol::hinstance() );
    }

    BOOL load(const std::wstring& id)
    {
        return load( id, mol::hinstance() );
    }

    BOOL load(int id, HINSTANCE hinst)
    {
        res_  = 0;
        len_  = 0;
        data_ = 0;

        HRSRC hRsrc = ::FindResource(hinst, MAKEINTRESOURCE(id), R::type() );
        if ( !hRsrc )
            return FALSE;

        len_ = ::SizeofResource( hinst, hRsrc );
        res_  = ::LoadResource(  hinst, hRsrc );

        if (!res_)
            return FALSE;

		data_ = (char*)::LockResource(res_);

        return (BOOL)(res_!=0);
    }

	BOOL load(const std::wstring& id, HINSTANCE hinst)
    {
        res_  = 0;
        len_  = 0;
        data_ = 0;

        HRSRC hRsrc = ::FindResource(hinst, id.c_str(), R::type() );
        if ( !hRsrc )
            return FALSE;

        len_ = ::SizeofResource( hinst, hRsrc );
        res_  = ::LoadResource(  hinst, hRsrc );

        if (!res_)
            return FALSE;

		data_ = (char*)::LockResource(res_);

        return (BOOL)(res_);
    }

    int size()
    {
        return len_;
    }

	const char* operator()()
    {
        return data_;
    }

	std::wstring toString()
	{
		return std::wstring( (wchar_t*)data_,len_/sizeof(wchar_t) );
	}

	std::string tostring()
	{
		return std::string(data_,len_);
	}

private:
    int		     len_;
	char*		 data_;
    HGLOBAL		 res_;
};

typedef Resource<mol::win::restype_html>	html_resource;
typedef Resource<mol::win::restype_img>		img_resource;

//////////////////////////////////////////////////////////////////////
// Windows HDC class
//////////////////////////////////////////////////////////////////////

namespace win  {

class DCbase
{
public:

    DCbase() : hdc_(0), attached_(false) {};
    DCbase (HDC hdc) : hdc_(hdc), attached_(true) {};
    virtual ~DCbase();

    int  setBkMode(int i)							{ return ::SetBkMode( hdc_, i ); }
    int fillRect ( const RECT& r, HBRUSH hbr )		{ return ::FillRect ( hdc_, &r, hbr );}
    int frameRect( const RECT& r, HBRUSH hbr )		{ return ::FrameRect( hdc_, &r, hbr );}
    COLORREF setBkColor( COLORREF crColor )			{ return ::SetBkColor( hdc_, crColor); }
    COLORREF setTextColor( COLORREF crColor )		{ return ::SetTextColor( hdc_, crColor); }
    BOOL textOut( int x, int y, std::wstring t )		{ return ::TextOut(hdc_,x,y, t.c_str(), (int)t.size());}

	void createMetaFile()							{ attached_ = true; hdc_ = ::CreateMetaFile(NULL); }
	void save()										{ ::SaveDC(hdc_); }
	void setWindowOrgEx ( int x = 0, int y = 0 )	{ ::SetWindowOrgEx(hdc_, x, y, NULL); }
	void setWindowExtEx ( int x = 0, int y = 0 ) 	{ ::SetWindowExtEx(hdc_, x, y, NULL); }

	void restore( int i = -1)						{ ::RestoreDC(hdc_, i); }

	HMETAFILE closeMetaFile()						{ attached_ = false; return ::CloseMetaFile(hdc_); }

    HGDIOBJ select( HGDIOBJ obj);
    operator HDC () {return hdc_; }
    
	void detach() { attached_ = false; }

protected:
    std::list<HGDIOBJ>	obList_;
    HDC		hdc_;
    bool	attached_;
};

} // end namespace win

//////////////////////////////////////////////////////////////////////
//std PAINT DC
//////////////////////////////////////////////////////////////////////

class PaintDC : public mol::win::DCbase
{
public:
    PaintDC( HWND hwnd) 
		: hWnd_(hwnd)	
	{
		hdc_ = ::BeginPaint( hWnd_, &ps_ ); 
	}

    ~PaintDC() 
	{ 
		::EndPaint( hWnd_, &ps_ ); 
	}

private:
    HWND			hWnd_;
    PAINTSTRUCT		ps_;
};

//////////////////////////////////////////////////////////////////////
// STD GET DC
//////////////////////////////////////////////////////////////////////

class DC : public mol::win::DCbase
{
public:
	DC() : hWnd_(0)					{ hdc_ = 0; }
    DC( HWND hwnd) :hWnd_(hwnd)		{ attached_ = true;hdc_ = ::GetDC( hWnd_ ); }
    DC( HDC dc) :hWnd_(0)			{ attached_ = false; hdc_ = dc; }
    ~DC()							{ if (attached_) ::ReleaseDC( hWnd_, hdc_); }

private:
    HWND			hWnd_;
};

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////


class UserInterface
{
friend class UIBuilder;
friend void ::load_codegen_metadata();
public:

	UserInterface();

	std::wstring CmdString(unsigned int id);
	HMENU Menu(unsigned int id);
	HMENU SubMenu(unsigned int menu,unsigned int id);
	HBITMAP Bitmap(unsigned int id);
	int BitmapCmd(unsigned int id, unsigned int index);
	int BitmapCmdIndex(unsigned int id, unsigned int cmd);
	HWND hWnd(unsigned int id);

	template<class T>
	T* Wnd(unsigned int id)
	{
		return mol::wndFromHWND<T>(hWnd(id));
	}

	struct bitmapinfo
	{
		HBITMAP hbitmap;
		std::vector<int> index;
	};


	void addCmd(int key, const std::wstring& title);
	void addBmp(int key);
	void addBmpCmd(int bmp, int cmd);
	void addMenu(int menu);
	void addMenuSeparator(int root, int menu);
	void addSubMenu(int root, int menu, int cmd);
	void addSubMenu(int root, int menu, int cmd, int bmp);
	void addMenuItem( int root, int menu, int cmd, int bmp, int idx, bool checked = false, bool enabled = true);

private:

	std::map<int,std::wstring> cmdStrings_;
	std::map<int,HMENU> menus_;
	std::map<int,std::map<int,HMENU>> submenus_;
	std::map<int,bitmapinfo> bmps_;
	std::map<int,HWND> hWnds_;
	std::map<int,HBITMAP> explodedBmps_;

};

UserInterface& UI();

//////////////////////////////////////////////////////////////////////

namespace win {
class WndProc;
}

class UIBuilder
{
public:

	UIBuilder(mol::win::WndProc* wnd) : wnd_(wnd) {};
	virtual ~UIBuilder() {};

	virtual void loadUI() {}
	virtual void makeUI() {}
	virtual void initRibbon(mol::win::WndProc* wnd) {}

protected:
	template<class T>
	T* makeWindow(HMENU id, const mol::Rect& r, HWND parent )
	{
		T* t= new T;
		t->deleteOnNCDestroy_ = true;
		t->create( id, r, parent );
		addWnd((int)id,*t);
		return t;
	}

	template<class T>
	void makeMainWindow( T* t, const std::wstring& name, HMENU menu, const mol::Rect& r, int id )
	{
		t->uiBuilder_ = this;
		t->create( name, (HMENU)mol::UI().Menu((unsigned int)menu), r );
		addWnd(id,*t);
	}


	template<class T>
	void makeMdiWindow( T* t, const std::wstring& name, HMENU menu, const mol::Rect& r )
	{
		t->uiBuilder_ = this;
		t->create( name, (HMENU)mol::UI().Menu(menu), r );
		//addWnd(id,*t);
	}

	void addWnd(int key, HWND wnd);

	mol::win::WndProc* wnd_;
};

//////////////////////////////////////////////////////////////////////

template<class T>
class GUIBuilder : public UIBuilder
{
public:

	GUIBuilder(mol::win::WndProc* wnd) : UIBuilder(wnd) {};
	virtual ~GUIBuilder() {};

	virtual void loadUI() {}
	virtual void makeUI() {}

};

template<class T>
void build_ui(T* t)
{
	GUIBuilder<T>* builder = new GUIBuilder<T>(t);
	builder->loadUI();
}


template<class T>
void make_ui(T* t)
{
	GUIBuilder<T>* builder = new GUIBuilder<T>(t);
	builder->makeUI();
}

//////////////////////////////////////////////////////////////////////

} // endnamespace mol


#endif

