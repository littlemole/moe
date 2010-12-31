#ifndef _MOL_MDI2_WND_DEF_
#define _MOL_MDI2_WND_DEF_

#include "conf.h"
#include "win/wnd.h"
#include "win/res.h"
#include "win/Taskbar.h"

namespace mol {

namespace win {


class MdiClient
{
friend class mol::Singleton<MdiClient>;
public:

	void set( HWND hWnd)
	{
		hWnd_ = hWnd;
	}

	HWND get()
	{
		return hWnd_;
	}

	operator HWND()
	{
		return get();
	}

private:

	MdiClient() {}
	~MdiClient() {}

	HWND hWnd_;
};

inline MdiClient& mdiClient()
{
	return mol::Singleton<MdiClient>::instance();
}

}

////////////////////////////////////////////////////////////////////////////////////////////////
//base MDI frame windows
////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////
// MDI child window base class
////////////////////////////////////////////////////////////////////////////////////////////////

class MdiChild : public mol::Window
{
public:
	typedef MdiChild BaseWindowType;

    // styles
    virtual int style()   { return WS_BORDER|WS_CHILD|WS_VISIBLE|WS_CLIPSIBLINGS|WS_CLIPCHILDREN; }

    virtual ~MdiChild();

    virtual void activate( );
    virtual void maximize( );
    virtual void minimize( );
    virtual void restore ( );
    virtual void next    ( );
	virtual BOOL destroy ( );

	void changeMenu( HMENU menu, HMENU wndMenu=0);

 	virtual UINT showContext( HMENU m );
	virtual void post2Parent( UINT msg,  WPARAM wParam, LPARAM lParam);		

	HWND mdiClient();
    HWND mdiParent();
	virtual HWND getParent(){ return mdiParent();}

    virtual LRESULT wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	int mdiMenuIndex();

	mol::TaskThumbnail thumb;

protected:

	HWND virtual createWindow( const mol::string& windowName, HMENU hMenu=0,const Rect& r=mol::stdRect , HWND parent=0 );
    void registerClass( HMENU& hMenu );
    HWND addChild(HWND parent);

    static LRESULT CALLBACK windowProcedure (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

    HWND			parent_;
	HMENU			windowMenu_;
};

class MdiFrame : public mol::Window
{
friend class MdiChild;
public:
    typedef MdiFrame BaseWindowType;

    virtual int style()   { return WS_OVERLAPPEDWINDOW|WS_CLIPSIBLINGS|WS_CLIPCHILDREN; }

    MdiFrame(int id=10000);
    virtual ~MdiFrame() {};

    virtual LRESULT OnActivate			( UINT, WPARAM, LPARAM);
    virtual LRESULT OnMaximize			( UINT, WPARAM, LPARAM);
    virtual LRESULT OnMinimize			( UINT, WPARAM, LPARAM);
    virtual LRESULT OnRestore			( UINT, WPARAM, LPARAM);
    virtual LRESULT OnNext				( UINT, WPARAM, LPARAM);
	virtual LRESULT OnCloseChild		( UINT, WPARAM, LPARAM);
	virtual LRESULT OnCloseAll			( UINT, WPARAM, LPARAM);
	virtual LRESULT OnCascade			( UINT, WPARAM, LPARAM);
	virtual LRESULT OnTileHorizontal	( UINT, WPARAM, LPARAM);
	virtual LRESULT OnTileVertical		( UINT, WPARAM, LPARAM);
	virtual LRESULT OnIconArrange		( UINT, WPARAM, LPARAM);

    virtual LRESULT wndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

    HWND getActive();
	HWND childAt(int index);
	int  index(HWND);
	int  count();

	void destroyChild(HWND wnd);

	virtual BOOL destroy( );
	virtual BOOL mdiDestroy( );

	virtual void setMenu( HMENU newMenu, HMENU windowMenu = 0  );

    virtual BOOL invalidate( BOOL erase = TRUE );

    virtual void redraw();

    void setMDIMenu(int m);
    void changeMenu( HMENU menu, HMENU wndMenu=0);
    void setFirstChildId(int id);
	int mdiMenuIndex();

	virtual LRESULT OnSize  ( UINT message, WPARAM wParam, LPARAM lParam);
	virtual LRESULT OnLayout( UINT message, WPARAM wParam, LPARAM lParam);

    HWND mdiClient();

protected:
	virtual void OnAddChild(HWND hwnd)     {};
	virtual void OnReleaseChild(HWND hwnd);

	HWND createWindow( const mol::string& windowName, HMENU hMenu=0,const Rect& r=mol::stdRect , HWND parent=0 );
    void registerClass( int& hMenu );
    void createMDIClient( LPCREATESTRUCT lpcs );

    void addChild(MdiChild* c);
    void releaseChild(MdiChild* c);

    static LRESULT CALLBACK windowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

    HWND								client_;
	std::list<mol::MdiChild*>			children_;
    int									menuIndex_;
    int                                 firstChildId_;

};

//////////////////////////////////////////////////////////////////

template<class C, class W>
class MdiChildFrame 
: public Frame<
			C,
			W,
			WS_BORDER|WS_CHILD|WS_CLIPSIBLINGS|
			WS_CLIPCHILDREN|WS_THICKFRAME|
			WS_SYSMENU|WS_CAPTION |
			WS_MAXIMIZEBOX|WS_MINIMIZEBOX ,
			WS_EX_MDICHILD >
{};

} // end namespace mol

#endif

