#include "win/CoCtrl.h"
#include "win/Res.h"
#include "crtdbg.h"

namespace mol  {
namespace win  {

//const mol::TCHAR statusbar_class[]		= _T("Status");
const mol::TCHAR toolbar_class[]		= TOOLBARCLASSNAME;
const mol::TCHAR rebar_class[]			= REBARCLASSNAME;
const mol::TCHAR tab_ctrl_class[]		= WC_TABCONTROL;
const mol::TCHAR combo_box_ex_class[]	= WC_COMBOBOXEX;
const mol::TCHAR tooltip_class[]		= TOOLTIPS_CLASS;
const mol::TCHAR tree_ctrl_class[]		= WC_TREEVIEW;
const mol::TCHAR list_ctrl_class[]		= WC_LISTVIEW;
const mol::TCHAR header_class[]			= WC_HEADER;
const mol::TCHAR progressbar_class[]    = PROGRESS_CLASS;
const mol::TCHAR statusbar_class[]		= STATUSCLASSNAME;

} // endnamespace mol::win

//////////////////////////////////////////////////////////////////////
// CommCOntrol - User support
//////////////////////////////////////////////////////////////////////

comm_ctrl_init::comm_ctrl_init( int ex )
{
    INITCOMMONCONTROLSEX icex;
    icex.dwSize = sizeof(INITCOMMONCONTROLSEX);
    icex.dwICC  = ex;
    ::InitCommonControlsEx(&icex);
}

////////////////////////////////////////////////////////////////////////////
// statusbar
////////////////////////////////////////////////////////////////////////////
int StatusBar::style()   
{ 
    return WS_CHILD|WS_VISIBLE|WS_CLIPCHILDREN|WS_CLIPSIBLINGS; 
}

int StatusBar::getHeight() 
{ 
    return height_; 
}

HWND StatusBar::createWindow( const mol::string& wndName, HMENU hMenu, const Rect& r, HWND parent )
{
//    hWnd_ = ::CreateStatusWindow( style(), wndName.c_str(), parent, (UINT_PTR)hMenu );

	hWnd_ = ::CreateWindowEx( 0, mol::win::statusbar_class, wndName.c_str(), style(), r.left, r.top, r.right-r.left, r.bottom-r.top, parent, hMenu, mol::hinstance(), 0 );

    sendMessage( SB_SIMPLE, TRUE, 0 );
    setText( wndName.c_str() );
    RECT tmp;
    ::GetWindowRect( hWnd_, &tmp );
    height_ = tmp.bottom - tmp.top;

    subClass();
    this->OnCtrlCreated();

    return hWnd_;
}



int StatusBar::setText( const mol::string& txt )
{
    return (int)sendMessage(  SB_SETTEXT, 255, (WPARAM) txt.c_str() );
}

////////////////////////////////////////////////////////////////////////////
// statusbar ex
////////////////////////////////////////////////////////////////////////////

HWND StatusBarEx::createWindow( const mol::string& wndName, HMENU hMenu, const Rect& r, HWND parent )
{
//    hWnd_ = ::CreateStatusWindow( style(), wndName.c_str(), parent, (UINT_PTR)hMenu );

	hWnd_ = ::CreateWindowEx( 0, mol::win::statusbar_class, wndName.c_str(), style(), r.left, r.top, r.right-r.left, r.bottom-r.top, parent, hMenu, mol::hinstance(), 0 );

    //sendMessage( SB_SIMPLE, TRUE, 0 );
    setText( wndName.c_str() );
    RECT tmp;
    ::GetWindowRect( hWnd_, &tmp );
    height_ = tmp.bottom - tmp.top;

    subClass();
    this->OnCtrlCreated();

    return hWnd_;
}



int StatusBarEx::setText( const mol::string& txt)
{
	parts_.clear();
	parts_.push_back(txt);
	sendMessage(  SB_SETTEXT, 0, (LPARAM) txt.c_str() );	
	resizeStatusbar();
	return 0;
}

int StatusBarEx::setText( const mol::string& txt1, const mol::string& txt2)
{
	parts_.clear();
	parts_.push_back(txt1);
	parts_.push_back(txt2);
	sendMessage(  SB_SETTEXT, 0, (LPARAM) txt1.c_str() );	
	sendMessage(  SB_SETTEXT, 1, (LPARAM) txt2.c_str() );	
	resizeStatusbar();
	return 0;
}

int StatusBarEx::setText( const mol::string& txt1, const mol::string& txt2, const mol::string& txt3)
{
	parts_.clear();
	parts_.push_back(txt1);
	parts_.push_back(txt2);
	parts_.push_back(txt3);
	sendMessage(  SB_SETTEXT, 0, (LPARAM) txt1.c_str() );	
	sendMessage(  SB_SETTEXT, 1, (LPARAM) txt2.c_str() );	
	sendMessage(  SB_SETTEXT, 2, (LPARAM) txt3.c_str() );	
	resizeStatusbar();
	return 0;
}

int StatusBarEx::setText( const mol::string& txt1, const mol::string& txt2, const mol::string& txt3, const mol::string& txt4)
{
	parts_.clear();
	parts_.push_back(txt1);
	parts_.push_back(txt2);
	parts_.push_back(txt3);
	parts_.push_back(txt4);
	sendMessage(  SB_SETTEXT, 0, (LPARAM) txt1.c_str() );	
	sendMessage(  SB_SETTEXT, 1, (LPARAM) txt2.c_str() );	
	sendMessage(  SB_SETTEXT, 2, (LPARAM) txt3.c_str() );	
	sendMessage(  SB_SETTEXT, 3, (LPARAM) txt4.c_str() );	
	resizeStatusbar();
	return 0;
}

LRESULT StatusBarEx::wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if ( message == WM_SIZE ) 
	{
		int h = HIWORD(lParam);
		int w = LOWORD(lParam) - 20;

		int * widths = new int[ parts_.size() ];
		widths[parts_.size()-1] = -1;
		mol::DC dc(hWnd_);

		for ( int i = parts_.size()-1; i >=0; i-- )
		{
			int len = parts_[i].size();
			SIZE s;
			::GetTextExtentPoint32( dc, parts_[i].c_str(), parts_[i].size(), &s);
			widths[i] = w;
			w = w - ( s.cx + 10 ); 
		}
		sendMessage( SB_SETPARTS, parts_.size(), (LPARAM)widths );
		delete[] widths;
	}
	return StatusBar::wndProc( hwnd, message, wParam, lParam );
}

void StatusBarEx::resizeStatusbar()
{
	int * widths = new int[ parts_.size() ];
	widths[parts_.size()-1] = -1;

	RECT tmp;
	::GetClientRect( hWnd_, &tmp );
	int w = tmp.right-tmp.left-20;
	mol::DC dc(hWnd_);

	for ( int i = parts_.size()-1; i >=0; i-- )
	{
		int len = parts_[i].size();
		
		SIZE s;
		::GetTextExtentPoint32( dc, parts_[i].c_str(), parts_[i].size(), &s);
		widths[i] = w;
		w = w - ( s.cx + 10 ); 
	}
	sendMessage( SB_SETPARTS, parts_.size(), (LPARAM)widths );
	delete[] widths;
}
////////////////////////////////////////////////////////////////////////////
// Toolbar
////////////////////////////////////////////////////////////////////////////

ToolBar::ToolBar()		   
: bmpId_(0)		
{}

int ToolBar::style()   
{ 
    return WS_CHILD|WS_VISIBLE|WS_CLIPCHILDREN|WS_CLIPSIBLINGS; 
}

LRESULT ToolBar::wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	Crack msg(message, wParam, lParam);
    if ( message == WM_NOTIFY )
    {
        LPNMHDR nmh   = (LPNMHDR)lParam;
        UINT code     = nmh->code;

		if ( code == TTN_GETDISPINFO )
		{
			if ( style() & TBSTYLE_TOOLTIPS )
			{
				HWND hwndFrom    = nmh->hwndFrom;
				UINT_PTR id      = nmh->idFrom;
				NMTTDISPINFO* di = (NMTTDISPINFO*)lParam;
				if ( tooltips_.count((int)id) > 0 )
				{
					di->szText[0] = 0;
					di->lpszText = (mol::TCHAR*)(tooltips_[(int)id].c_str());
				}
			}
			return 0;
		}
		if ( msg.nmhdr()->hwndFrom == hWnd_ )
			return 0;
    }
    return Ctrl::wndProc( hwnd, message, wParam, lParam );
}

LRESULT ToolBar::setBmp( int bmpId, int num, int w, int h )
{
	sendMessage( TB_SETBITMAPSIZE,(WPARAM)0,(LPARAM)(LPARAM) MAKELONG (w, h) );

    TBADDBITMAP bmp;
    bmp.hInst = hinstance(); 
    bmp.nID= bmpId;

    return sendMessage( TB_ADDBITMAP, (WPARAM)num, (LPARAM)&bmp);
}

LRESULT ToolBar::addButton(int iBmp, int iCmd,  const mol::string& txt, BYTE fsState, BYTE fsStyle , DWORD* data )
{
    TBBUTTON butt;
	ZeroMemory(&butt,sizeof(butt));
    butt.iBitmap = iBmp;
    butt.idCommand= iCmd;
    butt.fsState=fsState;
    butt.fsStyle=fsStyle;
	if ( style() & TBSTYLE_TOOLTIPS )
	{
		tooltips_.insert(std::make_pair((unsigned int)iCmd,txt));		
	}
	else 
	{
		butt.iString=(INT_PTR)(mol::TCHAR*)(txt.c_str());
	}
	butt.dwData=(DWORD_PTR)data;
    return sendMessage(TB_ADDBUTTONS,(WPARAM)1,(LPARAM)&(butt));
}

LRESULT ToolBar::addString(const mol::string& txt, int iCmd, BYTE fsState, BYTE fsStyle , DWORD* data )
{
    TBBUTTON butt;
    butt.iBitmap = I_IMAGENONE;
    butt.idCommand= iCmd;
    butt.fsState=fsState;
    butt.fsStyle=fsStyle;
    butt.dwData=(DWORD_PTR)data;
    butt.iString=(INT_PTR)(char*)(txt.c_str());

    return sendMessage(TB_ADDBUTTONS,(WPARAM)1,(LPARAM)&(butt));
}

LRESULT ToolBar::autoSize()
{
    return sendMessage( TB_AUTOSIZE, 0, 0);
}

LRESULT ToolBar::addSeperator( int iLen )
{
    TBBUTTON butt;
    butt.iBitmap = iLen;
    butt.idCommand= 0;
    butt.fsState= 0;
    butt.fsStyle=TBSTYLE_SEP;
    butt.dwData=(unsigned long)0;
    butt.iString=(int)0;

    return sendMessage(TB_ADDBUTTONS,(WPARAM)1,(LPARAM)&(butt));
}

LRESULT ToolBar::setState( int id, int state )
{
    TBBUTTONINFO ibutt;
    ibutt.cbSize=sizeof(ibutt);
    ibutt.dwMask=TBIF_COMMAND|TBIF_STATE;
    ibutt.fsState=state;
    ibutt.idCommand= id;

    return sendMessage(TB_SETBUTTONINFO,(WPARAM)id,(LPARAM)&(ibutt));
}

LRESULT ToolBar::setStd( int bmpId )
{
    return sendMessage( TB_LOADIMAGES,(WPARAM)bmpId,(LPARAM)HINST_COMMCTRL);
}

LRESULT ToolBar::setButtonSize(int w, int h)
{
    return sendMessage( TB_SETBUTTONSIZE,(WPARAM)0,(LPARAM)(LPARAM) MAKELONG (w, h)
);
}


HWND ToolBar::createWindow(  const mol::string& wndName, HMENU hMenu, const Rect& r, HWND parent )
{
    hWnd_ = ::CreateWindowEx( exstyle(),wndClassName().c_str(),
                              wndName.c_str(), style(),
                              r.left, r.top, r.right, r.bottom,
                              parent, (HMENU)hMenu, hinstance(),dynamic_cast<void*>(this) );

    sendMessage( TB_BUTTONSTRUCTSIZE, (WPARAM) sizeof(TBBUTTON), 0);
    subClass();
    setFont( (HFONT)::GetStockObject(ANSI_VAR_FONT));
    this->OnCtrlCreated();
    return hWnd_;
}

void ToolBar::embedd(Wnd* wnd) 
{ 
    wnd->setParent(*this); 
}

LRESULT ToolBar::count()
{
	return sendMessage( TB_BUTTONCOUNT,(WPARAM)0,(LPARAM)0);
}


////////////////////////////////////////////////////////////////////////////
// coolbar
////////////////////////////////////////////////////////////////////////////

CustomToolBar::CustomToolBar()
{
	def_ = true;
	reset();
}

LRESULT CustomToolBar::addButton(int iBmp, int iCmd, const mol::string& txt, BYTE fsState, BYTE fsStyle, DWORD_PTR data )
{
	if ( style() & TBSTYLE_TOOLTIPS )
	{
		tooltips_.insert(std::make_pair((unsigned int)iCmd,txt));		
	}

	buttons_.push_back( tbutton(iBmp,iCmd,txt,fsState,fsStyle,data,def_) );
	return 0;
}


LRESULT CustomToolBar::addSeperator( int iLen )
{
	buttons_.push_back( tbutton(iLen,0,_T(""),0,TBSTYLE_SEP,0,def_) );
    return 0;
}

LRESULT CustomToolBar::deleteButton(int index)
{
	if ( index > count() )
		return 0;

	int i = 0;
	for ( std::list<tbutton>::iterator it = buttons_.begin(); it != buttons_.end(); it++ )
	{
		if ( i == index )
		{
			buttons_.erase(it);
			break;
		}
		i++;
	}

	return sendMessage( TB_DELETEBUTTON,(WPARAM)index,(LPARAM)0);
}


LRESULT CustomToolBar::deleteButtonCmd(int cmd)
{
	int index = 0;
	for ( std::list<tbutton>::iterator it = buttons_.begin(); 
		  it != buttons_.end(); 
		  it++ )
	{
		if ( cmd == (*it).idCommand )
		{
			buttons_.erase(it);
			sendMessage( TB_DELETEBUTTON,(WPARAM)index,(LPARAM)0);
			break;
		}
		index++;
	}

	return 0;
}

LRESULT CustomToolBar::addButtons()
{
	def_ = false;
	int c = (int)count();
	for ( int i = c-1; i >= 0; i-- )
	{
		sendMessage( TB_DELETEBUTTON,(WPARAM)i,(LPARAM)0);
	}

	for ( std::list<tbutton>::iterator it = buttons_.begin(); it != buttons_.end(); it++ )
	{
		if ( (*it).def == false )
			continue;

		TBBUTTON butt;
		ZeroMemory(&butt,sizeof(butt));
		butt.iBitmap   = (*it).iBmp;
		butt.idCommand = (*it).idCommand;
		butt.fsState   = (*it).fsState;
		butt.fsStyle   = (*it).fsStyle;
		butt.iString   = 0;

		butt.dwData=(unsigned long)((*it).dwData);

		sendMessage(TB_ADDBUTTONS,(WPARAM)1,(LPARAM)&(butt));
	}
	return 0;
}

void CustomToolBar::reset()
{
	it_ = end();
}

int CustomToolBar::size()
{
	return (int)buttons_.size();
}

std::list<tbutton>::iterator CustomToolBar::end()
{
	return buttons_.end();
}

tbutton& CustomToolBar::at(int index)
{
	static tbutton err;
	int i = 0;
	for ( std::list<tbutton>::iterator it = buttons_.begin(); it != buttons_.end(); it++ )
	{
		if ( i == index )
		{
			return (*it);
		}
		i++;
	}
	return err;
}

std::list<tbutton>::iterator CustomToolBar::next()
{
	if ( it_ == end() )
		it_ = buttons_.begin();
	else
		it_++;
	return it_;
}

LRESULT CustomToolBar::wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if ( message == WM_NOTIFY )
	{
		Crack msg(message,wParam,lParam);
		switch( msg.nmhdr()->code )
		{
			case TBN_GETBUTTONINFO : 
			{
				
				int index = msg.nmtoolbar()->iItem;
				if ( index > size()-1 )
					return FALSE;

				tbutton& t = at(index);

				msg.nmtoolbar()->cchText = (int)(t.txt.size());
					_tcsncpy( msg.nmtoolbar()->pszText, 
					     t.txt.c_str(),
						 (int)(t.txt.size()+1)
						);
	
				msg.nmtoolbar()->tbButton.dwData    = t.dwData;
				msg.nmtoolbar()->tbButton.fsState   = t.fsState;
				msg.nmtoolbar()->tbButton.fsStyle   = t.fsStyle;
				msg.nmtoolbar()->tbButton.iBitmap   = t.iBmp;
				msg.nmtoolbar()->tbButton.idCommand = t.idCommand;
				return TRUE;
				
			}
			case TBN_BEGINADJUST : 
			{
				nResetCount_   = (int)count();
				lpSaveButtons_ = getToolbarState();
				return TRUE;
			}
			case TBN_RESET : 
			{
				setToolbarState( lpSaveButtons_, nResetCount_ );
				return TRUE;
			}
			case TBN_ENDADJUST : 
			{
				freeToolbarState(lpSaveButtons_);
				return 0;
			}
			case TBN_QUERYINSERT : 
			{
				return TRUE;
			}
			case TBN_QUERYDELETE : 
			{
				return TRUE;
			}
			default :
			{
				if ( msg.nmhdr()->hwndFrom == hwnd )
					return 0;
			}
		}// end switch
	}// end Notify Handler

	return ToolBar::wndProc( hwnd, message, wParam, lParam );
}

LPTBBUTTON CustomToolBar::getToolbarState()
{  
	int nResetCount = (int)count();
	if ( nResetCount == 0 )
	{
		return 0;
	}

	LPTBBUTTON lpSaveButtons = (LPTBBUTTON)GlobalAlloc(GPTR, sizeof(TBBUTTON) * nResetCount);  
	::ZeroMemory(lpSaveButtons,sizeof(TBBUTTON) * nResetCount);  

	for ( int i = 0; i < nResetCount; i++ )
	{
		sendMessage( TB_GETBUTTON, i, (LPARAM)&(lpSaveButtons[i]));
		//lpSaveButtons[i].fsStyle = 0;
		lpSaveButtons[i].iString = 0;
	}
	return lpSaveButtons;
}

void CustomToolBar::freeToolbarState( LPTBBUTTON state )
{
	::GlobalFree((HGLOBAL)state);
}

void CustomToolBar::setToolbarState( LPTBBUTTON state, int nResetCount )
{
	int nCount = (int)count();
	for ( int i = nCount - 1; i >= 0; i--)
	{
		sendMessage(TB_DELETEBUTTON, i, 0);
	}
	sendMessage( TB_BUTTONSTRUCTSIZE, (WPARAM)sizeof(TBBUTTON), (LPARAM)0 );
	for ( int i = 0; i < nResetCount; i++ ) 
	{
		TBBUTTON* tb = &(state[i]);
		sendMessage( TB_ADDBUTTONS, (WPARAM)1, (LPARAM)tb );
	}
}

////////////////////////////////////////////////////////////////////////////
// rebar
////////////////////////////////////////////////////////////////////////////

int ReBar::style()   
{ 
    return WS_BORDER|WS_CHILD|WS_CLIPCHILDREN|RBS_BANDBORDERS; 
}

int ReBar::exstyle() 
{ 
    return WS_EX_TOOLWINDOW; 
}


HWND ReBar::createWindow( const mol::string& wndName, HMENU hMenu, const Rect& r, HWND parent )
{
    hWnd_ = ::CreateWindowEx( exstyle(),wndClassName().c_str(),
                              wndName.c_str(), style(),
                              r.left, r.top, r.right, r.bottom,
                              parent, (HMENU)hMenu, hinstance(),dynamic_cast<void*>(this) );

    rbi.cbSize = sizeof(REBARINFO);  // Required when using this struct.
    rbi.fMask  = 0;
    rbi.himl   = (HIMAGELIST)NULL;
    sendMessage(RB_SETBARINFO, 0, (LPARAM)&rbi);

    subClass();
    setFont( (HFONT)::GetStockObject(ANSI_VAR_FONT));
    this->OnCtrlCreated();

    return hWnd_;
}

LRESULT ReBar::addBar(Wnd& bar, int cmd, int minWidth, const mol::string& txt, int fStyle,int fMask )
{
    RECT r;
	::ZeroMemory(&rbBand,sizeof(REBARBANDINFO));
    rbBand.cbSize   = sizeof(REBARBANDINFO);  // Required
    rbBand.fMask    =  fMask|RBBIM_TEXT | RBBIM_STYLE | RBBIM_CHILD  | RBBIM_CHILDSIZE | RBBIM_SIZE| RBBIM_ID;
    rbBand.fStyle   = fStyle;//RBBS_NOGRIPPER;//|RBBS_CHILDEDGE;//|RBS_BANDBORDERS;//;// | RBBS_FIXEDBMP;;//
    rbBand.hbmBack  = 0; //try this :) LoadBitmap(g_hinst, MAKEINTRESOURCE(IDB_BACKGRND));
    rbBand.wID      = cmd;

    // Set values unique to the band
    bar.getWindowRect(r);

	rbBand.lpText     = (mol::TCHAR*)(txt.c_str());
    rbBand.hwndChild  = bar;
    rbBand.cxMinChild = r.right-r.left;
    rbBand.cyMinChild = r.bottom - r.top;
    rbBand.cx         = r.right-r.left;
	rbBand.cxIdeal    = r.right-r.left;

    // Add the band
    LRESULT ret = (sendMessage(RB_INSERTBAND, (WPARAM)-1, (LPARAM)&rbBand));
	return ret;
}

bool ReBar::isBandVisible(int cmd)
{
	::ZeroMemory(&rbBand,sizeof(REBARBANDINFO));
    rbBand.cbSize   = sizeof(REBARBANDINFO);  // Required
    rbBand.fMask    =  RBBIM_STYLE|RBBIM_CHILD;

	int i = index(cmd);
	if ( i == -1 )
		return 0;

	sendMessage( RB_GETBANDINFO, (WPARAM)i, (LPARAM)&rbBand);

	if ( rbBand.hwndChild && ( ::IsWindow( rbBand.hwndChild) ) )
	{
		return ::IsWindowVisible(rbBand.hwndChild) != 0;
	}
	return (rbBand.fStyle & RBBS_HIDDEN) == 0;
}

int ReBar::width(int cmd)
{
	::ZeroMemory(&rbBand,sizeof(REBARBANDINFO));
    rbBand.cbSize   = sizeof(REBARBANDINFO);  // Required
    rbBand.fMask    =  RBBIM_SIZE;

	int i = index(cmd);
	if ( i == -1 )
		return 0;

	sendMessage( RB_GETBANDINFO, (WPARAM)i, (LPARAM)&rbBand);

	return rbBand.cx;
}


void ReBar::width(int cmd, int w)
{
	int i = index(cmd);
	if ( i == -1 )
		return;

	::ZeroMemory(&rbBand,sizeof(REBARBANDINFO));
    rbBand.cbSize   = sizeof(REBARBANDINFO);  // Required
    rbBand.fMask    = RBBIM_SIZE|RBBIM_CHILDSIZE|RBBIM_IDEALSIZE;

	sendMessage( RB_GETBANDINFO, (WPARAM)i, (LPARAM)&rbBand);

	rbBand.cx  = w;
	rbBand.cxIdeal = w;
	rbBand.cxMinChild = w;

	sendMessage( RB_SETBANDINFO, (WPARAM)i, (LPARAM)&rbBand);
}

bool ReBar::newline(int cmd)
{
	int i = index(cmd);
	if ( i == -1 )
		return 0;


	::ZeroMemory(&rbBand,sizeof(REBARBANDINFO));
    rbBand.cbSize   = sizeof(REBARBANDINFO);  // Required
    rbBand.fMask    =  RBBIM_STYLE | RBBIM_CHILD  | RBBIM_CHILDSIZE | RBBIM_SIZE| RBBIM_ID;

	sendMessage( RB_GETBANDINFO, (WPARAM)i, (LPARAM)&rbBand);

	return (rbBand.fStyle & RBBS_BREAK) != 0;
}


LRESULT ReBar::showBar(int cmd, bool dontHide)
{
	int i = index(cmd);
	if ( i == -1 )
		return 0;

    return postMessage( RB_SHOWBAND, (WPARAM)(UINT) i, (LPARAM)(BOOL) dontHide);
}


void ReBar::remove(int cmd)
{
	int i = index(cmd);
	if ( i == -1 )
		return;

    postMessage( RB_DELETEBAND, (WPARAM)(UINT) i, (LPARAM)0);
}

void ReBar::freeze(bool b)
{
	int c = count();
	for ( int i = 0; i < c ; i++ )
	{
		::ZeroMemory(&rbBand,sizeof(REBARBANDINFO));
		rbBand.cbSize   = sizeof(REBARBANDINFO);  // Required
		rbBand.fMask    =  RBBIM_STYLE;

		sendMessage( RB_GETBANDINFO, (WPARAM)i, (LPARAM)&rbBand);

		if ( b )
		{
			rbBand.fStyle |= RBBS_NOGRIPPER ;
			if ( rbBand.fStyle & RBBS_GRIPPERALWAYS )
				rbBand.fStyle ^= RBBS_GRIPPERALWAYS;
		}
		else
		{
			rbBand.fStyle |= RBBS_GRIPPERALWAYS;
			if ( rbBand.fStyle & RBBS_NOGRIPPER )
				rbBand.fStyle ^= RBBS_NOGRIPPER;
		}

		sendMessage( RB_SETBANDINFO, (WPARAM)(UINT) i, (LPARAM)&rbBand );
	}
}

int ReBar::count()
{
   return (int)sendMessage( RB_GETBANDCOUNT, (WPARAM)0, (LPARAM)0);
}

int ReBar::index(int cmd)
{
	return (int)sendMessage(RB_IDTOINDEX,cmd,0);
}

int ReBar::cmd(int index)
{
	::ZeroMemory(&rbBand,sizeof(REBARBANDINFO));
	rbBand.cbSize   = sizeof(REBARBANDINFO);  // Required
	rbBand.fMask    =  RBBIM_ID;

	sendMessage( RB_GETBANDINFO, (WPARAM)index, (LPARAM)&rbBand);
	return rbBand.wID;
}

void ReBar::newline(int cmd, bool nl)
{
	int i = index(cmd);
	if ( i == -1 )
		return;

	::ZeroMemory(&rbBand,sizeof(REBARBANDINFO));
	rbBand.cbSize   = sizeof(REBARBANDINFO);  // Required
	rbBand.fMask    =  RBBIM_STYLE;

	sendMessage( RB_GETBANDINFO, (WPARAM)i, (LPARAM)&rbBand);

	if ( nl )
		rbBand.fStyle |= RBBS_BREAK;
	else
	{
		if ( (rbBand.fStyle) & RBBS_BREAK )
		rbBand.fStyle ^= RBBS_BREAK;
	}
	sendMessage( RB_SETBANDINFO, (WPARAM)i, (LPARAM)&rbBand);
}

void ReBar::move(int cmd, int pos)
{
	int i = index(cmd);
	if ( i == -1 )
		return;

	if ( pos >= count() )
		return;

	sendMessage( RB_MOVEBAND, (WPARAM)i, (LPARAM)pos);
}



HRESULT __stdcall ReBar::Load( LPSTREAM pStm)
{
	ULONG len = 0;
	int		c = 0;

	pStm->Read( &c,	sizeof(ULONG), &len );

	for ( int i = 0; i < c; i++ )
	{
		ULONG comd        = 0;
		pStm->Read( &comd,	sizeof(ULONG), &len );

		HWND w = getDlgItem( comd );
		mol::win::WndProc* wnd = mol::wndFromHWND<mol::win::WndProc>(w);

		CustomToolBar* t = dynamic_cast<CustomToolBar*>(wnd);
		if ( 0 != t )
		{
			loadToolBarState( *t, comd, i, pStm );
		}
		else
		{
			loadReBarState( comd, i, pStm );
		}
	}
	return S_OK;
}

HRESULT __stdcall ReBar::Save( LPSTREAM pStm,BOOL fClearDirty)
{
	ULONG written    = 0;
	int		c = count();
	pStm->Write( &c,		 sizeof(ULONG),		 &written );

	for ( int i = 0; i < c; i++ )
	{
		HWND w = getDlgItem( cmd(i) );
		mol::win::WndProc* wnd = mol::wndFromHWND<mol::win::WndProc>(w);
		if ( !wnd )
			continue;

		CustomToolBar* t = dynamic_cast<CustomToolBar*>(wnd);
		if ( 0 != t )
		{
			saveToolBarState( *t, i, pStm );
		}
		else
		{
			saveReBarState( i, pStm );
		}
	}
	return S_OK;
}

HRESULT __stdcall ReBar::GetSizeMax( ULARGE_INTEGER *pCbSize)
{
	ULONG c = 0;
	int s = count();
	int result = sizeof(ULONG);

	for ( int i = 0; i < s; i++ )
	{
		HWND w = getDlgItem( cmd(c) );
		mol::win::WndProc* wnd = mol::wndFromHWND<mol::win::WndProc>(w);
		if ( !wnd )
			continue;

		CustomToolBar* t = dynamic_cast<mol::CustomToolBar*>(wnd);
		if ( 0 != t )
		{
			result += ( (sizeof(TBBUTTON) ) * ( (int)t->count()) ) + sizeof(ULONG)*3 + sizeof(BYTE)*2;
		}
		else
		{
			result += sizeof(ULONG)*2 + sizeof(BYTE)*2;
		}
	}
	pCbSize->QuadPart += result+1024;
	return S_OK;
}

void ReBar::loadToolBarState( CustomToolBar& bar, int cmd, int pos, LPSTREAM pStm )
{
	ULONG c          = 0;
	ULONG len        = 0;
	ULONG w          = 0;
	BYTE isVisible   = 0;
	BYTE isNewline   = 0;
	//LPTBBUTTON state = 0;
	
	pStm->Read( &isVisible, sizeof(BYTE),  &len );
	pStm->Read( &isNewline, sizeof(BYTE),  &len );
	pStm->Read( &w,  		sizeof(ULONG), &len );
	pStm->Read( &c,			sizeof(ULONG), &len );

	move( cmd, pos );
	showBar( cmd, isVisible != 0 );
	postMessage(RB_MAXIMIZEBAND,pos, 0 );
	//newline( cmd, isNewline != 0 );
	width( cmd, c*24 );

	//bar.setButtonSize(24,22);
	//state = (LPTBBUTTON)GlobalAlloc(GPTR, sizeof(TBBUTTON) * c);   
	TBBUTTON state[100];// = new TBBUTTON[c];
	//::ZeroMemory(state,sizeof(TBBUTTON) * c);  
	//pStm->Read( state, sizeof(TBBUTTON)*c, &len );
	::ZeroMemory(state,sizeof(TBBUTTON) * c);  
	
	pStm->Read( state, sizeof(TBBUTTON)*c, &len );
	
	bar.setToolbarState(state,c);
	//bar.freeToolbarState(state);		

}

void ReBar::saveToolBarState(CustomToolBar& bar, int index, LPSTREAM pStm)
{
	ULONG written    = 0;
	ULONG comd		 = cmd(index);
	BYTE isVisible	 = bar.isVisible() ? 1 : 0;
	BYTE isNewline	 = newline(comd) ? 1 : 0;
	ULONG c			 = (ULONG)bar.count();
	ULONG w			 = c*24;

	LPTBBUTTON state = bar.getToolbarState();

	pStm->Write( &comd,		 sizeof(ULONG),		 &written );
	pStm->Write( &isVisible, sizeof(BYTE),		 &written );
	pStm->Write( &isNewline, sizeof(BYTE),		 &written );
	pStm->Write( &w,		 sizeof(ULONG),		 &written );
	pStm->Write( &c,		 sizeof(ULONG),		 &written );
	pStm->Write( state,		 sizeof(TBBUTTON)*c, &written );
	//pStm->Commit(STGC_DEFAULT);

	bar.freeToolbarState(state);
}

void ReBar::saveReBarState(int index, LPSTREAM pStm)
{
	ULONG written    = 0;
	ULONG comd		 = cmd(index);
	BYTE isVisible	 = isBandVisible(comd);
	BYTE isNewline	 = newline(comd) ? 1 : 0;
	ULONG w			 = width(comd);
	pStm->Write( &comd,		 sizeof(ULONG),		 &written );
	pStm->Write( &isVisible, sizeof(BYTE),		 &written );
	pStm->Write( &isNewline, sizeof(BYTE),		 &written );
	pStm->Write( &w,		 sizeof(ULONG),		 &written );
	//pStm->Commit(STGC_DEFAULT);
}


void ReBar::loadReBarState( int cmd, int pos, LPSTREAM pStm )
{
	ULONG len        = 0;
	ULONG w          = 0;
	BYTE isVisible   = 0;
	BYTE isNewline   = 0;
	
	pStm->Read( &isVisible, sizeof(BYTE),  &len );
	pStm->Read( &isNewline, sizeof(BYTE),  &len );
	pStm->Read( &w,  		sizeof(ULONG), &len );

	//move( cmd, pos );
	//showBar( cmd, isVisible != 0 );

	//newline( cmd, isNewline != 0);
	//width( cmd, w );
}
////////////////////////////////////////////////////////////////////////////
// tab_ctrl
////////////////////////////////////////////////////////////////////////////

TabCtrl::~TabCtrl()
{
	mol::win::AppBase& a = mol::app<mol::win::AppBase>();
	a.OnEndTab(this->hToolTip());

	for ( int i = 0; i < count(); i++ )
	{
		char* c = (char*)getItemLPARAM(i);
		delete c;
	}
}

HWND TabCtrl::createWindow( const mol::string& wndName, HMENU hMenu, const Rect& r, HWND parent )
{
	int s = style();
	s = s | (TCS_FLATBUTTONS|TCS_BUTTONS);
    hWnd_ = ::CreateWindowEx( exstyle(),wndClassName().c_str(),
                              wndName.c_str(), s,
                              r.left, r.top, r.right, r.bottom,
                              parent, (HMENU)hMenu, hinstance(),dynamic_cast<void*>(this) );

    subClass();
	setFont( (HFONT)::GetStockObject(ANSI_VAR_FONT));
	mol::win::AppBase& a = mol::app<mol::win::AppBase>();
	a.OnCreateTab(this->hToolTip(),*this);
    this->OnCtrlCreated();

    return hWnd_;
}
LRESULT TabCtrl::wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    if ( message == WM_NOTIFY )
    {
		Crack msg( message, wParam, lParam);
        LPNMHDR nmh   = (LPNMHDR)lParam;
        UINT code     = nmh->code;

		if ( code == TTN_GETDISPINFO )
		{
			if ( style() & TCS_TOOLTIPS )
			{
				HWND hwndFrom    = nmh->hwndFrom;
				UINT_PTR id      = nmh->idFrom;
				NMTTDISPINFO* di = (NMTTDISPINFO*)lParam;
				int i = hitTest();
				if ( i != -1 )
				{
					mol::TCHAR* c = (mol::TCHAR*)getItemLPARAM(i);
					di->lpszText = c;
				}
			}
			return 0;
		}
		if ( msg.nmhdr()->hwndFrom == hwnd )
			return 0;
    }
    return Ctrl::wndProc( hwnd, message, wParam, lParam );
}

int TabCtrl::hitTest()
{
    TCHITTESTINFO tchit;
	::GetCursorPos(&(tchit.pt));
	::ScreenToClient(*this,&(tchit.pt));
	return TabCtrl_HitTest(*this,&tchit);
}

int TabCtrl::style()   
{ 
    return WS_CHILD|WS_VISIBLE|TCS_BUTTONS|WS_CLIPCHILDREN; 
}

LRESULT TabCtrl::insertItem( const mol::string& txt, const mol::string& tool, int index, int img )
{
	int c = (int)count();
    //default: add to back
    if ( index == -1 )
            index = c;

	if ( c == 0 )
	{
		int s = style();
		::SetWindowLong( *this, GWL_STYLE, s );
	}

	

    TCITEM item;
    item.mask = TCIF_TEXT| TCIF_IMAGE|TCIF_PARAM;
	item.pszText = (mol::TCHAR*)(txt.c_str());
    item.cchTextMax = (int)txt.size();
    item.iImage = img;
	item.lParam = (LPARAM)(new mol::TCHAR[tool.size()+1]);
	memcpy((char*)(item.lParam),(char*)(tool.c_str()),(tool.size()+1)*sizeof(mol::TCHAR));

    LRESULT i = sendMessage( TCM_INSERTITEM, (WPARAM)index,(LPARAM) (const LPTCITEM) (&item) );
    return i;
}

mol::string TabCtrl::getItemText(int index)
{
	mol::TCHAR  buf[2048];
    TCITEM item;
    item.mask = TCIF_TEXT| TCIF_TEXT;
    item.pszText = buf;
    item.cchTextMax = 2048;
    item.iImage = 0;

    sendMessage( TCM_GETITEM, (WPARAM)index,(LPARAM) (const LPTCITEM) (&item) );
    return item.pszText;
}

mol::string TabCtrl::getItemTooltipText(int index)
{
	return (mol::TCHAR*)(getItemLPARAM(index));
}

LPARAM TabCtrl::getItemLPARAM(int index)
{
    TCITEM item;
	ZeroMemory(&item,sizeof(item));
    item.mask = TCIF_PARAM;
    sendMessage( TCM_GETITEM, (WPARAM)index,(LPARAM) (const LPTCITEM) (&item) );
	return item.lParam;
}

LRESULT TabCtrl::renameItem( const mol::string& txt, int index, const mol::string& tool, int img )
{
	mol::TCHAR* c = (mol::TCHAR*)getItemLPARAM(index);
	if ( c )
		delete[] c;
    TCITEM item;
    item.mask = TCIF_TEXT| TCIF_IMAGE|TCIF_PARAM;
	item.pszText = (mol::TCHAR*)(txt.c_str());
    item.cchTextMax = (int)txt.size();
    item.iImage = img;
	c = new mol::TCHAR[tool.size()+1];
	memcpy(c,tool.c_str(),(tool.size()+1)*sizeof(mol::TCHAR));
	item.lParam = (LPARAM)c;

    LRESULT i = sendMessage( TCM_SETITEM, (WPARAM)index,(LPARAM) (const LPTCITEM) (&item) );
    select(index);
    return i;
}

LRESULT TabCtrl::removeItem( int index ) 
{
	mol::TCHAR* c = (mol::TCHAR*)getItemLPARAM(index);
	LRESULT lr = (LRESULT)TabCtrl_DeleteItem(hWnd_, index);

	if ( this->count() == 0 )
	{
		int s = style();
		s = s | (TCS_FLATBUTTONS|TCS_BUTTONS);
		::SetWindowLong( *this, GWL_STYLE, s );
	}

	if ( c )
		delete[] c;
    return lr; 
}

LRESULT TabCtrl::selection() 
{ 
    return (LRESULT)TabCtrl_GetCurSel(hWnd_); 
}

HWND    TabCtrl::hToolTip()  
{ 
    return TabCtrl_GetToolTips(*this); 
}

LRESULT TabCtrl::count()
{
    return sendMessage( TCM_GETITEMCOUNT, 0,0 );
}

LRESULT TabCtrl::getRect(RECT& r)
{
    return getWindowRect(r);
    return sendMessage(TCM_ADJUSTRECT, (WPARAM) (BOOL) FALSE, (LPARAM) (LPRECT) &r );
}

LRESULT TabCtrl::select(int i)
{
    return sendMessage(TCM_SETCURSEL,(WPARAM) i,0);
}

LRESULT TabCtrl::showToolTip(LPARAM& lParam, const mol::string& txt)
{
	LPNMTTDISPINFO disp = (LPNMTTDISPINFO)lParam;
	disp->lpszText = (mol::TCHAR*)(txt.c_str());
	return 0;
}

//////////////////////////////////////////////////////////////////////
// combo_box_ex
//////////////////////////////////////////////////////////////////////

int ComboCoxEx::style()   
{ 
    return WS_CHILD|WS_BORDER|WS_VISIBLE|CBS_AUTOHSCROLL|CBS_DROPDOWNLIST|WS_CLIPCHILDREN|WS_CLIPSIBLINGS ; 	
}

void ComboCoxEx::setImgList( HIMAGELIST himl )
{
    LRESULT l = sendMessage(CBEM_SETIMAGELIST,0,(LPARAM)himl);
}

void ComboCoxEx::addItem(const mol::string& str, int img, int selectedImg  )
{
    insertItem( -1, str, img, selectedImg);
}

void ComboCoxEx::insertItem(int index, const mol::string& str, int img, int selectedImg  )
{
    COMBOBOXEXITEM cbei;
    cbei.mask = CBEIF_TEXT | CBEIF_INDENT | CBEIF_IMAGE | CBEIF_SELECTEDIMAGE;
    if ( selectedImg = -1 )
        cbei.iSelectedImage = img;
    else
        cbei.iSelectedImage = selectedImg = selectedImg;

    cbei.iItem          = (index == -1 ) ? getCount() : index ;
	cbei.pszText        = (mol::TCHAR*)(str.c_str());
    cbei.cchTextMax     = (int)str.size();
    cbei.iImage         = img;
    cbei.iIndent        = 0;

    sendMessage(CBEM_INSERTITEM,0,(LPARAM)&cbei);
}

void ComboCoxEx::deleteString( int id ) 
{ 
    sendMessage( CB_DELETESTRING,(WPARAM)id,0); 
}

int ComboCoxEx::getCount() 	
{ 
    return (int)sendMessage( CB_GETCOUNT,0,0 ); 
}

int ComboCoxEx::getCurSel() 
{ 
    return (int)sendMessage( CB_GETCURSEL,0,0 ); 
}

void ComboCoxEx::setCurSel(int n) 
{ 
    sendMessage( CB_SETCURSEL,n,0 ); 
}

void ComboCoxEx::setCurSel(const mol::string& txt)
{
    for ( int i = 0; i < getCount(); i++)
        if ( txt == getString(i) )
        {
                setCurSel(i);
                break;
        }
}

mol::string ComboCoxEx::getString(int id )
{
	mol::TCHAR  buf[1024];
    ::memset(buf,32,1024);
    buf[1023] = 0;

    if ( CB_ERR == sendMessage( CB_GETLBTEXT,id,(LPARAM)buf))
            throw X(_T("getString failed"));

    return buf;
}

//////////////////////////////////////////////////////////////////////
// tree_ctrl
//////////////////////////////////////////////////////////////////////

TVHITTESTINFO&	TreeCtrl::hitTest() 
{ 
    POINT pt; 
    ::GetCursorPos(&pt); 
    screen2Client(pt); 
    return hitTest(pt); 
}

void TreeCtrl::editLabel(HTREEITEM ht)
{
	TreeView_EditLabel(*this,ht);
}	

int TreeCtrl::style()   
{ 
    return WS_CHILD|WS_BORDER|WS_VISIBLE|WS_VSCROLL|WS_HSCROLL|TVS_HASLINES|TVS_LINESATROOT|TVS_HASBUTTONS||WS_CLIPCHILDREN|WS_CLIPSIBLINGS; 	
}


TVHITTESTINFO&	TreeCtrl::hitTest		( POINT& p )
{
    tvHitTestInfo_.pt = p;
    TreeView_HitTest(hWnd_,&tvHitTestInfo_ );
    return tvHitTestInfo_;
}

HTREEITEM TreeCtrl::addNode( const mol::string& txt, HTREEITEM node,int state )
{
    TVITEM tvi;
    TVINSERTSTRUCT tvins;

	mol::TCHAR * c = (mol::TCHAR*)txt.c_str();
    tvi.mask = TVIF_TEXT | TVIF_STATE;
    tvi.pszText = c;
    tvi.cchTextMax = (int)txt.size();
    tvi.stateMask = TVIS_EXPANDED;
    tvi.state = state;

    tvins.item = tvi;
    tvins.hInsertAfter = NULL;
    tvins.hParent = node;

    return (HTREEITEM) sendMessage( TVM_INSERTITEM, 0, (LPARAM) (LPTVINSERTSTRUCT) &tvins);
}

HTREEITEM TreeCtrl::addNodeParam( const mol::string& txt, LPARAM lParam,  HTREEITEM node,int state )
{
    TVITEM tvi;
    TVINSERTSTRUCT tvins;

    mol::TCHAR* c = (mol::TCHAR*)txt.c_str();
    tvi.mask = TVIF_TEXT | TVIF_STATE|TVIF_PARAM;
    tvi.pszText = c;
    tvi.cchTextMax = (int)txt.size();
    tvi.stateMask = TVIS_EXPANDED;
    tvi.lParam = lParam;
    tvi.state = state;

    tvins.item = tvi;
    tvins.hInsertAfter = NULL;
    tvins.hParent = node;

    return (HTREEITEM) sendMessage( TVM_INSERTITEM, 0, (LPARAM) (LPTVINSERTSTRUCT) &tvins);
}

HTREEITEM TreeCtrl::addIconNode( const mol::string& txt, HTREEITEM node, int iIcon, int iSelIcon, int state )
{
    TVITEM tvi;
    TVINSERTSTRUCT tvins;

    mol::TCHAR* c = (mol::TCHAR*)txt.c_str();
    tvi.mask = TVIF_TEXT | TVIF_STATE | TVIF_IMAGE|TVIF_SELECTEDIMAGE;
    tvi.pszText = c;
    tvi.cchTextMax = (int)txt.size();
    tvi.stateMask = TVIS_EXPANDED;
    tvi.state = state;
    tvi.iImage = iIcon;
    tvi.iSelectedImage = iSelIcon;

    tvins.item = tvi;
    tvins.hInsertAfter = NULL;
    tvins.hParent = node;

    HTREEITEM hti = (HTREEITEM) sendMessage( TVM_INSERTITEM, 0, (LPARAM) (LPTVINSERTSTRUCT) &tvins);
    return hti;
}

HTREEITEM TreeCtrl::addIconNodeParam( const mol::string& txt, LPARAM lParam, HTREEITEM node, int iIcon, int iSelIcon, int state )
{
    TVITEM tvi;
    TVINSERTSTRUCT tvins;

    mol::TCHAR* c = (mol::TCHAR*)txt.c_str();
    tvi.mask = TVIF_TEXT | TVIF_STATE | TVIF_IMAGE|TVIF_SELECTEDIMAGE|TVIF_PARAM;
    tvi.pszText = c;
    tvi.cchTextMax = (int)txt.size();
    tvi.stateMask = TVIS_EXPANDED;
    tvi.state = state;
    tvi.iImage = iIcon;
    tvi.iSelectedImage = iSelIcon;
    tvi.lParam = lParam;

    tvins.item = tvi;
    tvins.hInsertAfter = NULL;
    tvins.hParent = node;

    HTREEITEM hti = (HTREEITEM) sendMessage( TVM_INSERTITEM, 0, (LPARAM) (LPTVINSERTSTRUCT) &tvins);
    return hti;
}

mol::string TreeCtrl::getItemText( HTREEITEM item )
{
    TVITEM tvi;
    tvi.mask = TVIF_TEXT | TVIF_HANDLE ;

    mol::TCHAR buf[1024];
    tvi.pszText = buf;
    tvi.cchTextMax = 1024;
    tvi.hItem = item;

    sendMessage( TVM_GETITEM, 0, (LPARAM) (LPTVITEM) &tvi);
    return buf;
}

LRESULT TreeCtrl::setItemText( HTREEITEM item, const mol::string& str )
{
    TVITEM tvi;
    tvi.mask = TVIF_TEXT | TVIF_HANDLE ;

    tvi.pszText = (mol::TCHAR*)str.c_str();
    tvi.cchTextMax = (int)str.size();
    tvi.hItem = item;

    return sendMessage( TVM_SETITEM, 0, (LPARAM) (LPTVITEM) &tvi);
}

LRESULT TreeCtrl::setItemIcon( HTREEITEM item, int icon, int selected )
{
    TVITEM tvi;
    tvi.mask = TVIF_IMAGE|TVIF_SELECTEDIMAGE|TVIF_HANDLE ;
    tvi.iImage = icon;
    tvi.iSelectedImage = selected;
    tvi.hItem = item;

    return sendMessage( TVM_SETITEM, 0, (LPARAM) (LPTVITEM) &tvi);
}

LPARAM TreeCtrl::getLPARAM( HTREEITEM item )
{
    TVITEM tvi;
    tvi.mask =  TVIF_PARAM| TVIF_HANDLE ;
    tvi.hItem = item;
	tvi.lParam = 0;
    if ( FALSE == sendMessage( TVM_GETITEM, 0, (LPARAM) (LPTVITEM) &tvi) )
		return 0;

    return tvi.lParam;
}

LPARAM TreeCtrl::setLPARAM( HTREEITEM item, LPARAM param )
{
    TVITEM tvi;
    tvi.mask =  TVIF_PARAM| TVIF_HANDLE ;
    tvi.hItem = item;
	tvi.lParam = param;
    if ( FALSE == sendMessage( TVM_SETITEM, 0, (LPARAM) (LPTVITEM) &tvi) )
		return 0;

    return tvi.lParam;
}

BOOL TreeCtrl::deleteNode( HTREEITEM node  ) 
{ 
    return TreeView_DeleteItem( hWnd_, node ); 
}

BOOL TreeCtrl::expand( HTREEITEM node  , int flags ) 
{ 
    return TreeView_Expand( hWnd_, node, flags); 
}

BOOL TreeCtrl::collapse( HTREEITEM node )  
{ 
    return expand( node, TVE_COLLAPSE); 
}

BOOL TreeCtrl::toggle( HTREEITEM node )  
{ 
    return expand( node, TVE_TOGGLE); 
}

HTREEITEM TreeCtrl::getSelection()  
{ 
    return TreeView_GetSelection(*this); 
}

BOOL TreeCtrl::setSelection( HTREEITEM item) 
{ 
    return TreeView_SelectItem(*this, item); 
}

void TreeCtrl::setItemState( HTREEITEM	hItem, UINT state, UINT stateMask ) 
{ 
    TreeView_SetItemState( hWnd_, hItem, state, stateMask ); 
}

UINT TreeCtrl::getItemState( HTREEITEM	hItem, UINT stateMask) 
{ 
    return TreeView_GetItemState( hWnd_, hItem, stateMask); 
}

HTREEITEM TreeCtrl::getParentItem( HTREEITEM item ) 
{ 
    return TreeView_GetParent( *this, item ); 
}

HTREEITEM TreeCtrl::getChildItem( HTREEITEM item ) 
{ 
    return TreeView_GetChild( *this, item ); 
}

HTREEITEM TreeCtrl::getNextItem( HTREEITEM item ) 
{ 
    return TreeView_GetNextSibling( *this, item ); 
}

LRESULT TreeCtrl:: setImageList( HIMAGELIST hil, int type  ) 
{ 
    return sendMessage( TVM_SETIMAGELIST, (WPARAM)type, (LPARAM)hil ); 
}

BOOL    TreeCtrl::getChecked( HTREEITEM item )
{
        TVITEM tvItem;
        tvItem.mask = TVIF_HANDLE | TVIF_STATE;
        tvItem.hItem = item;
        tvItem.stateMask = TVIS_STATEIMAGEMASK;
        TreeView_GetItem( hWnd_, &tvItem);
        return ((BOOL)(tvItem.state >> 12) -1);
}

BOOL    TreeCtrl::setChecked       ( HTREEITEM item, BOOL fCheck )
{
        TVITEM tvItem;
        tvItem.mask = TVIF_HANDLE | TVIF_STATE;
        tvItem.hItem = item;
        tvItem.stateMask = TVIS_STATEIMAGEMASK;
        tvItem.state = INDEXTOSTATEIMAGEMASK((fCheck ? 2 : 1));

        return TreeView_SetItem( hWnd_, &tvItem);
}

////////////////////////////////////////////////////////////////////

int Tooltip::style()   
{ 
    return WS_POPUP|TTS_NOPREFIX|TTS_ALWAYSTIP; 
}

LRESULT Tooltip::addTool( HWND tool, const mol::string& txt )
{
    TOOLINFO ti;
    Rect r;
    ::GetClientRect (tool, &r);

    ti.cbSize = sizeof(TOOLINFO);
    ti.uFlags = TTF_SUBCLASS;
    ti.hwnd = tool;
    ti.hinst = hinstance();
    ti.uId = ::GetDlgCtrlID(tool);
    ti.lpszText = (mol::TCHAR*)(txt.c_str());
    ti.rect.left = r.left;
    ti.rect.top = r.top;
    ti.rect.right = r.right;
    ti.rect.bottom = r.bottom;
    return sendMessage( TTM_ADDTOOL, 0, (LPARAM) (LPTOOLINFO) &ti);
}

LRESULT Tooltip::addTool( mol::win::Ctrl* ctrl, const mol::string& txt )
{
    //undo subclassing
    ctrl->deClass();

    HWND hwnd = *ctrl;
    LRESULT lr = addTool(hwnd,txt);
    //restore subclass windowproc
    ctrl->subClass();
    return lr;
}

HWND Tooltip::createWindow( const mol::string& wndName, HMENU hMenu, const Rect& r, HWND parent )
{
    hWnd_ = ::CreateWindowEx( exstyle(),this->wndClassName().c_str(),
                                wndName.c_str(), style(),
                                r.left, r.top, r.right, r.bottom,
                                parent,
                                (HMENU)hMenu,
								mol::hinstance(),
                                dynamic_cast<void*>(this) );

    setFont( (HFONT)::GetStockObject(ANSI_VAR_FONT));
    SetWindowPos( hWnd_,HWND_TOPMOST,0,0,0,0,SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
    subClass();
    this->OnCtrlCreated();
    return hWnd_;
}

//////////////////////////////////////////////////////////////////////
// list_ctrl
//////////////////////////////////////////////////////////////////////

void ListCtrl::deleteAllItems()
{
	ListView_DeleteAllItems(*this);
}

void ListCtrl::editLabel(int i)
{
	ListView_EditLabel(*this,i);
}

int ListCtrl::hitTest(int flags)
{
	POINT pt;
	::GetCursorPos(&pt);
	screen2Client(pt);
	return hitTest(pt.x, pt.y, flags);
}

int ListCtrl::hitTest( int x, int y, int flags)
{
	LVHITTESTINFO pinfo;
	pinfo.pt.x     = x;
	pinfo.pt.y     = y;
	pinfo.flags    = flags;
	pinfo.iItem    = 0;
	pinfo.iSubItem = 0;

	return ListView_HitTest(*this,&pinfo);
}

int ListCtrl::style()   
{ 
    return WS_CHILD|WS_BORDER|WS_VISIBLE|WS_VSCROLL|WS_HSCROLL|LVS_REPORT|LVS_SHAREIMAGELISTS|WS_CLIPCHILDREN|WS_CLIPSIBLINGS; 	
}

void ListCtrl::setView(DWORD dwView) 
{ 
	// Retrieve the current window style. 
	DWORD dwStyle = ::GetWindowLong(hWnd_, GWL_STYLE); 
	// Only set the window style if the view bits have
	// changed. 
	if ((dwStyle & LVS_TYPEMASK) != dwView) 
		::SetWindowLong(hWnd_, GWL_STYLE, (dwStyle & ~LVS_TYPEMASK) | dwView); 
}

void ListCtrl::insertColumn( const mol::string& txt, int iSubItem, int width , int mode  )
{
	LVCOLUMN lvc; 
	lvc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM; 
	lvc.fmt = mode;
	lvc.iSubItem=iSubItem;
	lvc.pszText=(mol::TCHAR*)txt.c_str();
	lvc.cx = width;
	ListView_InsertColumn(hWnd_,iSubItem,&lvc);
	
}

mol::string ListCtrl::getItemText(int index, int subitem)
{
	LVITEM lvi;
	lvi.mask = LVIF_TEXT; 
   	lvi.iItem = index;
	lvi.iImage = 0;
	lvi.iSubItem = subitem;
	lvi.state = 0;
	lvi.lParam = 0;
    lvi.pszText = _T("");
	int r = ListView_GetItem(hWnd_,&lvi);		
    return lvi.pszText;
}

LPARAM ListCtrl::getItemLPARAM(int index)
{
	LVITEM lvi;
	lvi.mask = LVIF_PARAM; 
   	lvi.iItem = index;
	lvi.iImage = 0;
	lvi.iSubItem = 0;
	lvi.state = 0;
	lvi.lParam = 0;
	lvi.pszText = _T("");
	int r = ListView_GetItem(hWnd_,&lvi);		
    return lvi.lParam;
}

UINT ListCtrl::getItemState(int index, int mask )
{
	LVITEM lvi;
	lvi.mask = LVIF_STATE; 
   	lvi.iItem = index;
	lvi.iImage = 0;
	lvi.iSubItem = 0;
	lvi.stateMask = mask;
	lvi.state = 0;
	lvi.lParam = 0;
    lvi.pszText = _T("");
	int r = ListView_GetItem(hWnd_,&lvi);		
    return lvi.state;
}

void ListCtrl::setItemState(int index, int state, int mask  )
{
	ListView_SetItemState(hWnd_,index,state,mask);		
}

int ListCtrl::getItemCount()
{
    return ListView_GetItemCount(hWnd_);
}

int ListCtrl::getNextItem(int index, int state  )
{
	return ListView_GetNextItem(hWnd_,index,state);		
}

void ListCtrl::insertItem(const mol::string& txt, int index, int state, int img, LPARAM lParam )
{
	LVITEM lvi;
	lvi.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_PARAM | LVIF_STATE; 
   	lvi.iItem = index;
	lvi.iImage = img;
	lvi.iSubItem = 0;
	lvi.state = 0;
	lvi.lParam = (LPARAM) lParam;
	lvi.pszText = (mol::TCHAR*)txt.c_str();
	int r = ListView_InsertItem(hWnd_,&lvi);		
}

void ListCtrl::insertItem(std::vector<mol::string>& txt, int index, int state, int img, LPARAM lParam )
{
	LVITEM lvi;
	lvi.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_PARAM | LVIF_STATE; 
   	lvi.iItem = index;
	lvi.iImage = img;
	lvi.iSubItem = 0;
	lvi.state = state;
	lvi.lParam = (LPARAM) lParam;
	lvi.pszText = (mol::TCHAR*)txt[0].c_str();
	int r = ListView_InsertItem(hWnd_,&lvi);		

	for ( unsigned int i = 1; i < txt.size(); i++ )
	{
		lvi.mask = LVIF_TEXT ; 
		lvi.iSubItem = i;
		lvi.pszText = (mol::TCHAR*)txt[i].c_str();
		int r = ListView_SetItem(hWnd_,&lvi);		
	}
}

void ListCtrl::insertSubItem(const mol::string& txt, int index, int subitem )
{		
	LVITEM lvi;
	lvi.mask = LVIF_TEXT ; 
   	lvi.iItem = index;
	lvi.iSubItem = subitem+1;
	lvi.pszText = (mol::TCHAR*)txt.c_str();
	ListView_SetItem(hWnd_,&lvi);
}

void ListCtrl::deleteItem(int index)
{		
    ListView_DeleteItem(*this,index);
}


////////////////////////////////////////////////////////////////
// imageList
////////////////////////////////////////////////////////////////

HWND ImageList::hWndDrag_ = 0;

ImageList::ImageList()
    :hImageList_(0),bDetached_(false)
{ }


ImageList::ImageList(HIMAGELIST hi, bool detach)
    :hImageList_(hi),bDetached_(detach)
{
}

ImageList::~ImageList()
{
	destroy();
}

void ImageList::destroy()
{
    if (hImageList_ && !bDetached_)
    {
        ::ImageList_Destroy( hImageList_);
        hImageList_ = 0;
    }
}

HIMAGELIST ImageList::create(  int num, int w, int h, int flags , int grow  )
{
    return hImageList_ = ::ImageList_Create( w, h, flags, num, grow );
}

HIMAGELIST ImageList::createIconList(  int num, int w, int h, int flags, int grow  )
{
    return hImageList_ = ::ImageList_Create( w, h, flags, num, grow );
}

int ImageList::addIcon( HICON hIcon )
{
    return ::ImageList_AddIcon( hImageList_, hIcon );
}

int ImageList::addIcon( int id , int w , int h )
{
    Icon ic(id,w,h);
    return ::ImageList_AddIcon( hImageList_, ic );
}

int ImageList::add( int ibmp, int type, int w , int h , int options ,  HBITMAP mask  )
{
    HBITMAP bmp = (HBITMAP)::LoadImage( hinstance(), MAKEINTRESOURCE(ibmp),type,w,h, options );

	int result = addBmp(bmp,mask);
//    int result = ::ImageList_Add( hImageList_, bmp, mask );
    ::DeleteObject( bmp );
    return result;
}

int ImageList::addBmp( HBITMAP bmp, HBITMAP mask  )
{
    int result = ::ImageList_Add( hImageList_, bmp, mask );
    return result;
}

BOOL ImageList::draw( int i, HDC hdc, int x, int y, UINT fStyle)
{
    return ::ImageList_Draw( hImageList_, i, hdc, x, y, fStyle );
}


bool ImageList::beginDrag(HWND hwnd, HIMAGELIST himl, int index, int x, int y)
{
    ImageList_BeginDrag(himl, index, x, y);

    POINT pt;
    ::GetCursorPos(&pt);
    RECT r;
    ::GetWindowRect(hwnd ,&r);

	hWndDrag_ = hwnd;
    return true;
}

void ImageList::doDrag(HWND hwnd)
{
	if ( hwnd != hWndDrag_ )
	{
		leaveDrag(hWndDrag_);
		hWndDrag_ = hwnd;
	}
    RECT r;
    POINT pt;
    ::GetCursorPos(&pt);
    ::GetWindowRect(hwnd,&r);
	dragShow();
    ImageList_DragMove(pt.x-r.left , pt.y-r.top ); 
}


void ImageList::dragShow(BOOL b ) 
{ 
	ImageList_DragShowNolock(b); 
}

void ImageList::enterDrag(HWND hwnd)
{
	if ( hwnd != hWndDrag_ )
	{
		leaveDrag(hWndDrag_);
		hWndDrag_ = hwnd;
	}
    RECT r;
    POINT pt;
    ::GetCursorPos(&pt);
    ::GetWindowRect(hwnd,&r);

    ImageList_DragEnter(hwnd, pt.x-r.left , pt.y-r.top ); 
}

void ImageList::leaveDrag(HWND hwnd)
{
    ImageList_DragLeave(hwnd);      
	hWndDrag_ = 0;
}

void ImageList::drop(HWND hwnd)
{
	if ( hwnd != hWndDrag_ )
	{
		leaveDrag(hWndDrag_);		
	}
	ImageList_DragLeave(hwnd);        
    ImageList_EndDrag(); 
}


////////////////////////////////////////////////////////////////
// Header Ctrl
////////////////////////////////////////////////////////////////

int HeaderCtrl::addString(const mol::string& txt, int nWidth, int indexAfter)
{
    HDITEM hdi; 
    int index = 0; 
 
    hdi.mask = HDI_TEXT | HDI_FORMAT | HDI_WIDTH; 
    hdi.pszText = (LPTSTR)(txt.c_str()); 
    hdi.cxy = nWidth; 
    hdi.cchTextMax = (int)txt.size(); 
    hdi.fmt = HDF_LEFT | HDF_STRING; 
 
	index = (int)sendMessage( HDM_INSERTITEM, (WPARAM) indexAfter, (LPARAM) &hdi); 
    return index; 
}

LRESULT HeaderCtrl::wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	return mol::win::CtrlClass< mol::win::header_class >::wndProc(hwnd,message,wParam,lParam);
}


HWND HeaderCtrl::createWindow( const mol::string& windowName, HMENU hMenu, const mol::Rect& r, HWND parent )
{
	mol::win::CtrlClass< mol::win::header_class >::createWindow( windowName, hMenu, r, parent );

	HDLAYOUT hdl; 
    WINDOWPOS wp; 
    RECT rcParent; 

	::GetClientRect( parent, &rcParent); 

	hdl.prc = &rcParent; 
    hdl.pwpos = &wp; 

	if (!sendMessage(HDM_LAYOUT, 0, (LPARAM) &hdl)) 
		return (HWND) NULL; 
 
     // Set the size, position, and visibility of the header control. 
	::SetWindowPos(*this, wp.hwndInsertAfter, wp.x, wp.y, wp.cx, wp.cy, wp.flags | SWP_SHOWWINDOW); 

    return hWnd_;
}

//////////////////////////////////////////////////////////////////////

int ProgressbarCtrl::style()   
{ 
    return WS_CHILD|WS_VISIBLE|WS_CLIPCHILDREN; 
}

void ProgressbarCtrl::setRange(int start, int end)
{
	sendMessage(PBM_SETRANGE,0,MAKELPARAM(start,end));
}

void ProgressbarCtrl::setPos(int pos)
{
	sendMessage(PBM_SETPOS ,(WPARAM)pos,0);
}


int ProgressbarCtrl::getPos()
{
	return (int)sendMessage(PBM_GETPOS ,0,0);
}

PBRANGE ProgressbarCtrl::getRange()
{
	sendMessage(PBM_GETRANGE ,0,(LPARAM)&range_);
	return range_;
}

void ProgressbarCtrl::setColor( COLORREF col )
{
	sendMessage(PBM_SETBARCOLOR ,0,(LPARAM)col);
}

void ProgressbarCtrl::setBkColor( COLORREF col )
{
	sendMessage(PBM_SETBKCOLOR ,0,(LPARAM)col);
}





} // endnamespace mol

