#ifndef MOLEWND_DEF
#define MOLEWND_DEF

#include "win/Core.h"
#include "win/WndClass.h"
#include "win/MsgMap.h"
#include "win/Res.h"
#include "thread/fun.h"
#include "thread/thread.h"

namespace mol {

class LayoutMgr;

namespace win {

UINT invoke_msg();

#define WM_INVOKE mol::win::invoke_msg()

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
// encapsulating HWND
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

class Wnd
{
public:

    //construction/destruction

	Wnd();
    Wnd(HWND hwnd) { hWnd_ = hwnd; };

	virtual ~Wnd();
	virtual BOOL close();
    virtual BOOL destroy();

    inline void attach( HWND hwnd) { hWnd_ = hwnd; }

    // styles
    virtual int style()   { return 0; }
    virtual int exstyle() { return 0; }

    //  showing & updating
    virtual BOOL update();

    LRESULT setRedraw(bool redraw);
    int show( int nCmdShow );

    BOOL invalidateRect( const RECT* r, BOOL erase );
    inline BOOL invalidate( BOOL erase = TRUE )
	{
		return invalidateRect(0,erase);
	}

    virtual void redraw();

    BOOL validateRect( const RECT* r );

    virtual HWND setFocus();    
    virtual int  setForeGround();
	virtual bool hasFocus();
	virtual void maximize();
	virtual void minimize();
	virtual void restore();

    virtual BOOL move( int x, int y, int w, int h, BOOL bRepaint = TRUE );
    virtual BOOL move( const RECT& r, BOOL bRepaint = TRUE );

    // setText
    virtual int setText( const mol::string& s );
    virtual int setFont( HFONT font );
	virtual mol::string  getText();

	virtual HBITMAP snapshot(RECT* r = 0);
	//virtual HBITMAP createDIB(int nWidth =-1, int nHeight=-1);
	//virtual HBITMAP Wnd::createDIB2(int nWidth, int nHeight);
	//virtual HBITMAP CaptureWindow(int nWidth =-1, int nHeight =-1);
	//virtual HBITMAP BMP();

    //info
    virtual BOOL client2Screen( POINT& p );
	virtual BOOL client2Screen( RECT& r  );
	virtual BOOL screen2Client( POINT& p );
	virtual BOOL screen2Client( RECT& r  );

    int  getDlgCtrlID()             { return ::GetDlgCtrlID(hWnd_); }
	HWND getDlgItem(int id)         { return ::GetDlgItem (hWnd_,id); }
	BOOL getClientRect( RECT& r )   { return ::GetClientRect( hWnd_, &r);}
	BOOL getWindowRect( RECT& r )   { return ::GetWindowRect( hWnd_, &r);}
    BOOL isVisible()                { return ::IsWindowVisible( hWnd_ ); }
    BOOL isIconic()                 { return ::IsIconic(hWnd_); };
	bool pointInWnd(POINT& pt)		{ return hWnd_ == ::WindowFromPoint(pt); }
	bool pointInWnd()				{ POINT pt; ::GetCursorPos(&pt); return hWnd_ == ::WindowFromPoint(pt); }

    //parent handling
    HWND getParent()				{ return ::GetParent(hWnd_);}
    HWND setParent(HWND hwnd)		{ return ::SetParent(hWnd_,hwnd);}

	virtual void setMenu( HMENU newMenu, HMENU windowMenu = 0 )
	{
		::SetMenu(*this,newMenu);
	}

    //messaging
    LRESULT sendMessage(UINT msg, WPARAM wParam, LPARAM lParam );
    BOOL    postMessage(UINT msg, WPARAM wParam, LPARAM lParam );

    // convert into HWND
    operator HWND() { return hWnd_; };



protected:
    HWND	hWnd_;
	bool	isMidi_;
	//HBITMAP bmp_;
};



/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
// adding window-proc support, adding std creating shema
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////



class WndProc : public Wnd
{
friend class WndClass;
friend class CtrlResizerImpl;
friend class UIBuilder;
public:

    typedef WndProc BaseWindowType;

	// Constructor - set erasebackground policy (defaults to zero)
	WndProc() : eraseBackground_(0), layout_(0), deleteOnNCDestroy_(false), uiBuilder_(0)
	{}  // set to eraseBackground 1 if you dont want windows to erase

	// Destructor
	virtual ~WndProc();

	// public interface to construct window with title
    HWND create( mol::string windowName, HMENU id=0, const Rect& r=stdRect, HWND parent=0 );

	// public interface to construct window without title
    HWND create( HMENU id=0, const Rect& r=stdRect, HWND parent=0 );

    // helpers for window-timers
    UINT_PTR SetTimer( UINT id, UINT time)  { return ::SetTimer(  hWnd_, id, time, 0 ); }
    BOOL KillTimer( UINT id )				{ return ::KillTimer( hWnd_, id); }

    //helpers for tray icons
    BOOL addTrayIcon ( int trayID, int WMtray, HICON icon );
    BOOL freeTrayIcon( int trayID );

	UINT showContext  ( HMENU menu, HWND parent = 0 );
    UINT returnContext( HMENU menu );

	// the most basic wndproc
    virtual LRESULT wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	virtual LRESULT OnSize  ( UINT message, WPARAM wParam, LPARAM lParam);
	virtual LRESULT OnLayout( UINT message, WPARAM wParam, LPARAM lParam);
	virtual LRESULT OnInvoke( UINT message, WPARAM wParam, LPARAM lParam);

	template<class T>
	T* setLayout( T* t)
	{
		if ( layout_ )
			delete layout_;
		layout_ = t;
		return t;
	}

	LayoutMgr* getLayout()
	{
		return layout_;
	}

	template<class T>
	T* childWindow(int id) 
	{
		HWND wnd = getDlgItem(id);

		T* t = mol::wndFromHWND<T>(wnd);
		return t;
	}

protected:

	virtual void cleanup();

    static LRESULT CALLBACK windowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

    HWND virtual createWindow( const mol::string& windowName, HMENU hMenu=0,const Rect& r=stdRect , HWND parent=0 )=0;

	int	eraseBackground_;

	LayoutMgr* layout_;

	mol::Menu		menue_;
	bool deleteOnNCDestroy_;

	mol::UIBuilder* uiBuilder_;
};




} //end namespace win



/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
// frame and child windows with own wndclasses
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

class Window : public mol::win::WndProc
{
public:
    typedef Window BaseWindowType;

	virtual LRESULT wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

protected:
    virtual mol::win::WndClass& wndClass();
	virtual HWND createWindow( const mol::string& windowName, HMENU hMenu=0,const Rect& r=mol::stdRect , HWND parent=0 );
    virtual void registerClass( HMENU& hMenu );
};

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

template <class W>
W* wndFromHWND( HWND hwnd )
{
	ULONG_PTR ud = (ULONG_PTR)(::GetWindowLongPtr(hwnd, GWLP_USERDATA));
	W* w = dynamic_cast<W*>((mol::win::WndProc*)ud);
	return w;
}

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

// Frame Class 
// to generate a per class unique  member func
// wndClass(), add Window Style and ExStyle info
// and add MsgMappping Support

/////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////

template<class C, class W, int Style, int ExStyle>
class Frame : public W
{
public:
typedef W BaseWindowType;

protected:

	~Frame()
	{	
		this->cleanup();
	}

    virtual int style()   
    { 
        return Style; 
    }
    
    virtual int exstyle() 
    { 
        return ExStyle; 
    }

    virtual mol::win::WndClass& wndClass()				
    {																	
		static mol::string wc = mol::win::WndClassGenerator::createClass();	
		return mol::win::WndClassGenerator::getClass(wc);					
    }

public:
	typedef C	   ThisWindowType;														
    typedef W      BaseWindowType;		

    LRESULT virtual wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)		
    {																					
            return msgMap<C>().call((C*)(this),message,wParam,lParam);							
    }	
};

/////////////////////////////////////////////////////////////////

template<class C, class W>
class MainFrame : public Frame<C,W,WS_OVERLAPPEDWINDOW|WS_CLIPSIBLINGS|WS_CLIPCHILDREN,0>
{
};

/////////////////////////////////////////////////////////////////

template<class C, class W>
class ChildFrame : public Frame<C,W,WS_BORDER|WS_CHILD|WS_VISIBLE|WS_CLIPSIBLINGS|WS_CLIPCHILDREN,0>
{
};


} // endnamespace mol



#endif

