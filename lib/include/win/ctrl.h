#ifndef CONTROL_DEF_
#define CONTROL_DEF_

#include "win/Wnd.h"

namespace mol  {


//////////////////////////////////////////////////////////////////////
// Control Wrapper to add styles
//////////////////////////////////////////////////////////////////////

template<class Ctrl, int Style, int ExStyle>
class Control: public Ctrl
{
public:

	typedef Ctrl BaseWindowType;

protected:

    virtual int style()   
    { 
        return Style; 
    }
    
    virtual int exstyle() 
    { 
        return ExStyle; 
    }
};

//////////////////////////////////////////////////////////////////////
// Ctrl Resizer
//////////////////////////////////////////////////////////////////////

class Ctrl;

namespace win  {

class CtrlResizerImpl
{
public:
    CtrlResizerImpl( WndProc* ctrl, Point min, int flags, int cmd );

    enum { NONE = 0, RIGHT = 1, LEFT = 2, TOP = 4, BOTTOM = 8 };
    LRESULT operator() ( int, WPARAM, LPARAM, bool& handled );

private:
    WndProc*		ctrl_;
    Point			mini_;
    int				flags_;
    int				cmd_;
    int				dir_;
    bool			bTrack_;
};

} // end namespace win

//////////////////////////////////////////////////////////////////////
// Ctrl Resizer template
//////////////////////////////////////////////////////////////////////

template<class T, int X, int Y, int BORDER, int ID=0>
class CtrlResizer : public T
{
public:
	typedef T DefMap;

	CtrlResizer()
		:ctrl_(this, Point(X,Y), BORDER, ID)
	{}

	LRESULT virtual wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		bool handled;
		LRESULT r = ctrl_( message,wParam, lParam, handled);
		if ( !handled )
		{
			DefMap* t = static_cast<DefMap*>(this);
			return DefMap::wndProc(*this,message,wParam,lParam);
		}
		return r;
	}

private:
	mol::win::CtrlResizerImpl ctrl_;
};

//////////////////////////////////////////////////////////////////////
// Ctrl BaseClass with subclassing support
//////////////////////////////////////////////////////////////////////

namespace win {

class Ctrl: public WndProc
{
friend class CtrlResizerImpl;
friend class WndMapDefaultPolicy;
public:
	typedef Ctrl BaseWindowType;

	~Ctrl();

    //  subclassing the def wndproc
    void subClass();
    void subClass(HWND hwnd);
    void deClass();

    void virtual OnCtrlCreated();

    //default ctrl handling: pass back to windows
    virtual LRESULT wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

protected:

    // default window style
    virtual int style()   { return WS_CHILD|WS_BORDER|WS_VISIBLE; }

    // prepare wndclass support
    virtual const mol::string& wndClassName() ;
    virtual HWND createWindow( const mol::string& windowName, HMENU hMenu, const Rect& r, HWND parent );

    WNDPROC	oldProc;
};


template<const mol::TCHAR* classname>
struct CtrlClass : public mol::win::Ctrl 
{
    const mol::string& wndClassName() 
    { 
		static mol::string s(classname); 
        return s; 
    }
};

extern const mol::TCHAR button_class[];
extern const mol::TCHAR edit_class[];
extern const mol::TCHAR combo_box_class[];
extern const mol::TCHAR list_box_class[];
extern const mol::TCHAR scrollbar_class[];
extern const mol::TCHAR static_class[];

} // end namespace win


//////////////////////////////////////////////////////////////////////
// Button
//////////////////////////////////////////////////////////////////////

class Button : public mol::win::CtrlClass<mol::win::button_class> 
{
protected:
    virtual int style();
};

class IconButton : public Button
{
public:
    void setIcon( HICON icon );

protected:
    virtual int style();
};

//////////////////////////////////////////////////////////////////////
// EditBox
//////////////////////////////////////////////////////////////////////

class EditBox : public mol::win::CtrlClass<mol::win::edit_class>
{
public:
    void setSelection(int start, int end);
    void getSelection(int& start, int& end);
};

//////////////////////////////////////////////////////////////////////
// ComboBox and Return-aware ComboBox
//////////////////////////////////////////////////////////////////////

class ComboBox : public mol::win::CtrlClass<mol::win::combo_box_class>
{
public:
    void insertString(const mol::string& str, int index );
    void addString(const mol::string& str );
    void deleteString( int id );
    int  getCount();
    int  getCurSel();
    void setCurSel(int n);
    void setCurSel(const mol::string& txt);
    mol::string getString(int id );
    void clear();

protected:
    virtual int style();
};


typedef mol::Control< mol::ComboBox, 
					  WS_CHILD|WS_VISIBLE|WS_CLIPCHILDREN|
					  CBS_DROPDOWNLIST |CBS_HASSTRINGS,
					  0 > 
combobox;

//////////////////////////////////////////////////////////////////////
// ListBox
//////////////////////////////////////////////////////////////////////

class ListBox : public mol::win::CtrlClass<mol::win::list_box_class>
{
public:
    void addString( const mol::string& s );
    int getCurSel();
    mol::string getString(int index);
    void resetContent();
	int index(const mol::string& s );
	int count();

	void setData(int index,void* d);
	void* getData(int index);

protected:
    virtual int style();
};

////////////////////////////////////////////////////////////////////////////
// Scrollbar
////////////////////////////////////////////////////////////////////////////

class ScrollBar: public mol::win::CtrlClass< mol::win::scrollbar_class>
{};

class VScrollBar : public Control<ScrollBar,WS_CHILD|WS_VISIBLE|SBS_VERT,0>
{};

class HScrollBar : public Control<ScrollBar,WS_CHILD|WS_VISIBLE|SBS_HORZ,0>
{};

////////////////////////////////////////////////////////////////////////////
// Static control
////////////////////////////////////////////////////////////////////////////

class StaticCtrl: public mol::win::CtrlClass< mol::win::static_class >
{
public:
    HICON  setIcon( HICON hIcon );
    HANDLE setImage( HANDLE bmp );
};

class StaticIcon : public Control<StaticCtrl,WS_CHILD|WS_VISIBLE|SS_ICON,0>
{};

class StaticBmp  : public Control<StaticCtrl,WS_CHILD|WS_VISIBLE|SS_BITMAP,0>
{};

//////////////////////////////////////////////////////////////////////
// Return-Aware EditBox
//////////////////////////////////////////////////////////////////////

template <int Cmd>
class ReditBox : public EditBox
{
public:
    virtual LRESULT wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
};

template <int Cmd>
LRESULT ReditBox<Cmd>::wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    if ( ( message == WM_KEYDOWN ) && ( wParam == VK_RETURN ) )
    {
        HWND parent		= ::GetParent( hwnd );
        int id			= ::GetDlgCtrlID( hwnd );
        //::SendMessage( parent, WM_COMMAND,MAKEWPARAM(id,Cmd), 0 );//(long)this );
		::SendMessage( parent, WM_COMMAND,MAKEWPARAM(Cmd,0), 0 );//(long)this );
        return 0;
    }
    return mol::win::Ctrl::wndProc(hwnd, message, wParam, lParam);
}

//////////////////////////////////////////////////////////////////////
// Return-aware ComboBox
//////////////////////////////////////////////////////////////////////

class RcomboBox  : public ComboBox
{
public:
    EditBox& editBox();
    void subClassEdit();
private:

    virtual HWND createWindow( const mol::string& windowName, HMENU hMenu, const Rect& r, HWND parent );

    class RcomboBoxEdit : public EditBox
    {
        protected:
			LRESULT wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
    };

    RcomboBoxEdit	edit;
};

typedef  
mol::Control< mol::RcomboBox,
                      WS_CHILD|WS_VISIBLE|CBS_DROPDOWN|
					  CBS_AUTOHSCROLL,
					  WS_EX_ACCEPTFILES|
					  CBS_DISABLENOSCROLL>
rcombobox;

//////////////////////////////////////////////////////////////////////
// Scrollable window
//////////////////////////////////////////////////////////////////////

class ScrollWnd : public mol::Window
{
public:
    typedef ScrollWnd BaseWindowType;	

	ScrollWnd();

	void setVScroll(int rowHeight, unsigned int nRows);
	void setHScroll(int colWidth, unsigned int nCols);

	unsigned int  getScrollPos(int sb = SB_VERT);
	unsigned int  getScrollMax(int sb = SB_VERT);
	void setScrollPos(unsigned int p,int sb = SB_VERT);

	LRESULT virtual wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	void virtual onVScroll(unsigned int pos) {};
	void virtual onHScroll(unsigned int pos) {};

protected:

	SCROLLINFO siV_;
	SCROLLINFO siH_;
	int scrollRowHeight_;
	int scrollColWidth_;
	unsigned int scrollRows_;
	unsigned int scrollCols_;

	void scrollV(unsigned int h);
	void scrollH(unsigned int w);

	short wheelDelta_; 
};



} // endnamespace mol

#endif

