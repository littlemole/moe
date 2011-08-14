#ifndef DEF_CO_CONTROL_
#define DEF_CO_CONTROL_

#include "conf.h"
#include "win/Ctrl.h"
#include <commctrl.h>
#include <vector>
#include <objidl.h>

namespace mol  {

//////////////////////////////////////////////////////////////////////
// CommControl - User support
//////////////////////////////////////////////////////////////////////

class comm_ctrl_init
{
public:
    comm_ctrl_init( int ex = ICC_WIN95_CLASSES | ICC_COOL_CLASSES |ICC_TAB_CLASSES|ICC_USEREX_CLASSES  );
};

namespace win  {

//extern const mol::TCHAR statusbar_class[];
extern const mol::TCHAR toolbar_class[];
extern const mol::TCHAR rebar_class[];
extern const mol::TCHAR tab_ctrl_class[];
extern const mol::TCHAR combo_box_ex_class[];
extern const mol::TCHAR tooltip_class[];
extern const mol::TCHAR tree_ctrl_class[];
extern const mol::TCHAR list_ctrl_class[];
extern const mol::TCHAR header_class[];
extern const mol::TCHAR progressbar_class[];
extern const mol::TCHAR statusbar_class[];
} // end namespace win

////////////////////////////////////////////////////////////////////////////
// StatusBar
////////////////////////////////////////////////////////////////////////////

class StatusBar : public mol::win::CtrlClass< mol::win::statusbar_class >
{
public:
    int getHeight();
    virtual int setText( const mol::string& txt );
	
protected:
    virtual int style();
    HWND createWindow(  const mol::string& wndName, HMENU hMenu, const Rect& r, HWND parent );
    int height_;
};


class StatusBarEx : public StatusBar
{
public:

	virtual int setText( const mol::string& txt);
	virtual int setText( const mol::string& txt1, const mol::string& txt2);
	virtual int setText( const mol::string& txt1, const mol::string& txt2, const mol::string& txt3);
	virtual int setText( const mol::string& txt1, const mol::string& txt2, const mol::string& txt3, const mol::string& txt4);


	virtual LRESULT wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

protected:
    HWND createWindow(  const mol::string& wndName, HMENU hMenu, const Rect& r, HWND parent );
	std::vector<mol::string> parts_;

	void resizeStatusbar();
};

////////////////////////////////////////////////////////////////////////////
// Toolbar
////////////////////////////////////////////////////////////////////////////

class ToolBar : public mol::win::CtrlClass< mol::win::toolbar_class>
{
public:
    ToolBar();

    LRESULT setBmp( int bmpId, int num, int w = 16, int h = 15 );
    LRESULT setStd( int bmpId = IDB_STD_SMALL_COLOR );
	LRESULT addButton(int iBmp, int iCmd, const mol::string& txt = _T(""), BYTE fsState = TBSTATE_ENABLED, BYTE fsStyle = TBSTYLE_BUTTON /*BTNS_BUTTON*/ , DWORD* data = 0 );
    LRESULT addString(const mol::string& txt, int iCmd, BYTE fsState = TBSTATE_ENABLED, BYTE fsStyle = TBSTYLE_BUTTON /*BTNS_BUTTON*/ , DWORD* data = 0);
    LRESULT addSeperator(int ilen);
	LRESULT setButtonSize(int w, int h);

	LRESULT count();

    LRESULT autoSize();
    LRESULT setState(int id, int state);
    void embedd(Wnd* wnd);

	virtual LRESULT wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

protected:
    virtual int style();
    HWND createWindow(  const mol::string& wndName, HMENU hMenu, const Rect& r, HWND parent );

	std::map<UINT,mol::string> tooltips_;

    int				 bmpId_;
};

////////////////////////////////////////////////////////////////////////////

typedef mol::Control< mol::ToolBar,
					  WS_CHILD|CCS_NODIVIDER|//TBSTYLE_FLAT |
					  WS_CLIPCHILDREN|TBSTYLE_TOOLTIPS,//|CCS_ADJUSTABLE ,
					  TBSTYLE_EX_MIXEDBUTTONS  >
toolbar;

////////////////////////////////////////////////////////////////////////////

typedef mol::Control< mol::ToolBar,
					  WS_CHILD|CCS_NORESIZE |CCS_NOPARENTALIGN|
					  CCS_NODIVIDER|TBSTYLE_FLAT |
					  WS_CLIPCHILDREN|TBSTYLE_TOOLTIPS,//|CCS_ADJUSTABLE ,
					  TBSTYLE_EX_MIXEDBUTTONS  >
rebar_tbar;


////////////////////////////////////////////////////////////////////////////
// custom_toolbar
////////////////////////////////////////////////////////////////////////////

class tbutton 
{
public: 
	tbutton()
	{}

	tbutton(int Bmp, int iCmd, const mol::string& t = _T(""), BYTE State = TBSTATE_ENABLED, BYTE Style = TBSTYLE_BUTTON, DWORD_PTR data = 0, bool d = true )
	{
		iBmp      = Bmp;
		idCommand = iCmd;
		fsState   = State;
		fsStyle   = Style;
		dwData    = data;
		txt       = t;
		def		  = d;
	}

	int iBmp;
	int idCommand;
	BYTE fsState;
	BYTE fsStyle;
	DWORD_PTR dwData;
	mol::string txt;
	bool def;
};

////////////////////////////////////////////////////////////////////////////


class CustomToolBar : 
	public mol::ToolBar
{
public:

	CustomToolBar();
	LRESULT addButton(int iBmp, int iCmd, const mol::string& txt = _T(""), BYTE fsState = TBSTATE_ENABLED, BYTE fsStyle = BTNS_BUTTON , DWORD_PTR data = 0 );
	LRESULT addSeperator( int iLen );
	LRESULT deleteButton(int index);
	LRESULT deleteButtonCmd(int cmd);
	LRESULT addButtons();

	void reset();
	int size();
	std::list<tbutton>::iterator end();
	tbutton& at(int index);
	std::list<tbutton>::iterator next();

	LRESULT wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	LPTBBUTTON getToolbarState();
	void freeToolbarState( LPTBBUTTON state );
	void setToolbarState( LPTBBUTTON state, int nResetCount );

	HRESULT __stdcall Load( LPSTREAM pStm) 
	{
		ULONG len = 0;
		ULONG c = 0;
		LPTBBUTTON state = 0;
		pStm->Read( &c,			sizeof(ULONG), &len );
		if ( c > 0 )
		{
			state = (LPTBBUTTON)GlobalAlloc(GPTR, sizeof(TBBUTTON) * c);   
			pStm->Read( state, sizeof(TBBUTTON)*c, &len );
			setToolbarState(state,c);
			freeToolbarState(state);		
			setButtonSize(24,22); // ?
		}
	}

    HRESULT __stdcall Save( LPSTREAM pStm,BOOL fClearDirty)
	{
		ULONG written    = 0;
		ULONG c			 = (ULONG)count();
		ULONG w			 = c*24;
		LPTBBUTTON state = getToolbarState();

		pStm->Write( &w,		 sizeof(ULONG),		 &written );
		pStm->Write( &c,		 sizeof(ULONG),		 &written );
		pStm->Write( state,		 sizeof(TBBUTTON)*c, &written );

		freeToolbarState(state);
	}

    HRESULT __stdcall GetSizeMax( ULARGE_INTEGER *pCbSize)
	{
		int c = (int)count();
		pCbSize->QuadPart += sizeof(BYTE)*2 + (sizeof(TBBUTTON)*c);
		return S_OK;
	}

protected:

	bool							def_;
	std::list<tbutton>				buttons_;
	std::list<tbutton>::iterator	it_;
	int								nResetCount_;
	LPTBBUTTON						lpSaveButtons_;
};


////////////////////////////////////////////////////////////////////////////

typedef mol::Control< mol::CustomToolBar,
					  WS_CHILD|CCS_NODIVIDER|TBSTYLE_FLAT |
					  WS_CLIPCHILDREN|TBSTYLE_TOOLTIPS|CCS_ADJUSTABLE ,
					  TBSTYLE_EX_MIXEDBUTTONS  >
coolbar;

////////////////////////////////////////////////////////////////////////////

typedef mol::Control< mol::CustomToolBar,
					  WS_CHILD|CCS_NORESIZE |CCS_NOPARENTALIGN|
					  CCS_NODIVIDER|TBSTYLE_FLAT |
					  WS_CLIPCHILDREN|TBSTYLE_TOOLTIPS|CCS_ADJUSTABLE ,
					  TBSTYLE_EX_MIXEDBUTTONS  >
rebar_coolbar;

////////////////////////////////////////////////////////////////////////////
// ReBar
////////////////////////////////////////////////////////////////////////////

class ReBar  : public mol::win::CtrlClass<mol::win::rebar_class>
{
public:
        LRESULT addBar(Wnd& bar, int cmd, int minWidth , const mol::string& txt=_T(""), int fStyle=0, int fMask=0 );
        LRESULT showBar(int cmd, bool dontHide = true );

		bool isBandVisible(int cmd);
        int count();
		int index(int cmd);
		int cmd(int index);

		int  width(int cmd);
		void width(int cmd, int w);
		bool newline(int cmd);
		void newline(int cmd, bool nl);

		void move(int cmd, int pos);
		void remove( int cmd );
		void freeze( bool b );

		virtual HRESULT __stdcall Load( LPSTREAM pStm);
		virtual HRESULT __stdcall Save( LPSTREAM pStm,BOOL fClearDirty);
		virtual HRESULT __stdcall GetSizeMax( ULARGE_INTEGER *pCbSize);

private:
		void saveToolBarState( CustomToolBar& bar, int index, LPSTREAM pStm);
		void loadToolBarState( CustomToolBar& bar, int cmd, int pos, LPSTREAM pStm );
		void saveReBarState( int index, LPSTREAM pStm);
		void loadReBarState( int cmd, int pos, LPSTREAM pStm );

protected:
        virtual int style();
        virtual int exstyle();
        HWND createWindow( const mol::string& wndName, HMENU hMenu, const Rect& r, HWND parent );
        REBARINFO     rbi;
        REBARBANDINFO rbBand;
};


////////////////////////////////////////////////////////////////////////////
// TabCtrl
////////////////////////////////////////////////////////////////////////////

class TabCtrl : public mol::win::CtrlClass<mol::win::tab_ctrl_class>
{
public:

		class TabCtrlItem 
		{
		public:
			TabCtrlItem() 
				: title(_T("")),tooltip(_T("")),lparam(0)
			{}

			TabCtrlItem(const mol::string& t) 
				: title(t),tooltip(_T("")),lparam(0)
			{}

			TabCtrlItem(const mol::string& t,const mol::string& tt) 
				: title(t),tooltip(tt),lparam(0)
			{}

			TabCtrlItem(const mol::string& t,const mol::string& tt, LPARAM p) 
				: title(t),tooltip(tt),lparam(p)
			{}

			mol::string title;
			mol::string tooltip;
			LPARAM lparam;

		};


		~TabCtrl();

        LRESULT insertItem( TabCtrlItem* item, int index = -1, int img = -1);
		LRESULT renameItem( TabCtrlItem* titem,int index, const mol::string& tool = _T(""), int img = -1 );
        LRESULT removeItem( int index = -1);
        LRESULT count();
        LRESULT select(int i);
		LRESULT selection();
        LRESULT getRect(RECT& r);
        mol::string getItemText(int i);
		mol::string getItemTooltipText(int i);
		TabCtrlItem* getTabCtrlItem(int i);
		HWND    hToolTip();
		LRESULT showToolTip( LPARAM& lParam,const mol::string& txt);
        int hitTest();

		virtual LRESULT wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

protected:
        virtual int style();
		HWND createWindow( const mol::string& wndName, HMENU hMenu, const Rect& r, HWND parent );
};


typedef mol::Control< mol::TabCtrl, 
					  WS_CHILD|WS_VISIBLE|WS_CLIPCHILDREN|
					  TCS_FLATBUTTONS|TCS_BUTTONS|
					  TCS_TOOLTIPS,
					  0 > 
tabcontrol;

//////////////////////////////////////////////////////////////////////
// ComboBoxEx
//////////////////////////////////////////////////////////////////////

class ComboCoxEx : public mol::win::CtrlClass<mol::win::combo_box_ex_class>
{
public:
    void setImgList( HIMAGELIST himl );
    void addItem(const mol::string& str, int img, int selectedImg = -1 );
    void insertItem(int index, const mol::string& str, int img, int selectedImg = -1 );
    void deleteString( int id );
    int  getCount();
    int  getCurSel();
    void setCurSel(int n);
    void setCurSel(const mol::string& txt);
    mol::string getString(int id );

protected:
    virtual int style();
};

////////////////////////////////////////////////////////////////////

class Tooltip : public mol::win::CtrlClass<mol::win::tooltip_class>
{
public:
	LRESULT addTool( mol::win::Ctrl* ctrl, const mol::string& txt );

protected:
    LRESULT addTool( HWND tool, const mol::string& txt );

    virtual int style();
    HWND createWindow(  const mol::string& wndName, HMENU hMenu, const Rect& r, HWND parent );
};


//////////////////////////////////////////////////////////////////////
// TreeCtrl
//////////////////////////////////////////////////////////////////////

class TreeCtrl : public mol::win::CtrlClass<mol::win::tree_ctrl_class>
{
public:
    HTREEITEM addNode		            ( const mol::string& txt, HTREEITEM node = TVI_ROOT, int state = TVIS_EXPANDED );
    HTREEITEM addNodeParam		        ( const mol::string& txt, LPARAM lParam, HTREEITEM node = TVI_ROOT, int state = TVIS_EXPANDED );
    HTREEITEM addIconNode		        ( const mol::string& txt, HTREEITEM node = TVI_ROOT, int iIcon = 0, int iSelIcon = 0, int state = TVIS_EXPANDED);
    HTREEITEM addIconNodeParam	        ( const mol::string& txt, LPARAM lParam, HTREEITEM node = TVI_ROOT, int iIcon = 0, int iSelIcon = 0, int state = TVIS_EXPANDED);


    BOOL deleteNode		        ( HTREEITEM node = TVI_ROOT );
    BOOL expand	                ( HTREEITEM node = TVI_ROOT , int flags = TVE_EXPAND);
    BOOL collapse		        ( HTREEITEM node = TVI_ROOT );
    BOOL toggle		            ( HTREEITEM node = TVI_ROOT );
    HTREEITEM getSelection      ();
    BOOL setSelection	        ( HTREEITEM item);
    void setItemState	        ( HTREEITEM	hItem, UINT state, UINT stateMask );
    UINT getItemState	        ( HTREEITEM	hItem, UINT stateMask);
    HTREEITEM getParentItem     ( HTREEITEM item );
    HTREEITEM getChildItem      ( HTREEITEM item );
    HTREEITEM getNextItem       ( HTREEITEM item );
    LRESULT setImageList	    ( HIMAGELIST hil, int type = TVSIL_NORMAL );
    BOOL    getChecked          ( HTREEITEM item );
    BOOL    setChecked          ( HTREEITEM item, BOOL fCheck );
    mol::string getItemText	    ( HTREEITEM item );
    LRESULT setItemText		    ( HTREEITEM item , const mol::string& str);
    LRESULT setItemIcon		    ( HTREEITEM item , int icon, int selected );
    LPARAM  getLPARAM		    ( HTREEITEM item );
	LPARAM  setLPARAM		    ( HTREEITEM item, LPARAM param );

    TVHITTESTINFO&	hitTest		( POINT& p );
	TVHITTESTINFO&	hitTest		();
	void editLabel(HTREEITEM ht);

protected:
    virtual int style();
    TVHITTESTINFO	tvHitTestInfo_;
};



//////////////////////////////////////////////////////////////////////
// ListCtrl
//////////////////////////////////////////////////////////////////////

class ListCtrl : public mol::win::CtrlClass<mol::win::list_ctrl_class>
{
public:

    void setView(DWORD dwView);
    void insertColumn( const mol::string& txt, int iSubItem, int width = 100, int mode = LVCFMT_LEFT );
    mol::string getItemText(int index, int subitem=0);
    LPARAM getItemLPARAM(int index);
    UINT getItemState(int index, int mask = LVIS_SELECTED);
    void setItemState(int index, int state, int mask = LVIS_SELECTED );
    int  getItemCount();
    int  getNextItem(int index = -1, int state = LVNI_SELECTED );
    void insertItem(const mol::string& txt, int index, int state=0, int img=0, LPARAM lParam=0 );
    void insertItem(std::vector<mol::string>& txt, int index, int state=0, int img=0, LPARAM lParam=0 );
    void insertSubItem(const mol::string& txt, int index, int subitem );
    void deleteItem(int index);
	void deleteAllItems();
	void editLabel(int i);
	int hitTest(int flags = LVHT_ONITEM);
	int hitTest( int x, int y, int flags = LVHT_ONITEM );

protected:
    virtual int style();
};


////////////////////////////////////////////////////////////////////////////
// Image List
////////////////////////////////////////////////////////////////////////////

class ImageList
{
public:
	ImageList();
	ImageList(HIMAGELIST hi, bool detached = true);
    ~ImageList();

	void destroy();
    HIMAGELIST create(  int num, int w=16, int h=16, int flags= ILC_COLOR , int grow = 9 );
    HIMAGELIST createIconList(  int num, int w=16, int h=16, int flags= ILC_COLOR|ILC_MASK , int grow = 9 );
    int addBmp( HBITMAP bmp, HBITMAP mask = 0 );
    int addIcon( HICON hIcon );
    int addIcon( int id , int w = 16, int h = 16 );
    int add( int ibmp, int type = IMAGE_BITMAP, int w = 16, int h = 16 , int options = LR_DEFAULTCOLOR,  HBITMAP mask = 0 );
    BOOL draw( int i, HDC hdc, int x, int y, UINT fStyle = 0);
    operator HIMAGELIST() { return hImageList_; }

	static bool beginDrag(HWND hwnd, HIMAGELIST himl, int index=0, int x=0, int y=0);
	static void doDrag(HWND hwnd);
	static void enterDrag(HWND hwnd);
	static void leaveDrag(HWND hwnd);
	static void drop(HWND hwnd);
	static void dragShow(BOOL b = TRUE);

	void detach() { bDetached_ = true; }

private:

    HIMAGELIST	hImageList_;
	bool bDetached_;
	static HWND	hWndDrag_;
};


////////////////////////////////////////////////////////////////////////////
// Header Ctrl
////////////////////////////////////////////////////////////////////////////


class HeaderCtrl : public mol::win::CtrlClass< mol::win::header_class >
{
public:

  int addString(const mol::string& txt, int mWidth, int indexAfter = 0);

  virtual LRESULT wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

protected:
	virtual HWND createWindow( const mol::string& windowName, HMENU hMenu, const mol::Rect& r, HWND parent );

};

////////////////////////////////////////////////////////////////////////////
// Progress bar Ctrl
////////////////////////////////////////////////////////////////////////////


class ProgressbarCtrl : public mol::win::CtrlClass< mol::win::progressbar_class >
{
public:
  int style();

  void setRange(int start, int end);
  void setPos(int pos);

  int getPos();
  PBRANGE getRange();

  void setColor( COLORREF col );
  void setBkColor( COLORREF col );
 
protected:

	PBRANGE	range_;
};

} // endnamespace mol

#endif



