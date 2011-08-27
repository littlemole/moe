#include "StdAfx.h"
#include "HexCtrl.h"
#include "ole/Bstr.h"
#include "ole/com.h"
#include "util/Str.h"
#include <sstream>
#include <iomanip>

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////


HexToolBar::HexToolBar(HexCtrl* wnd)
	:hexCtrl_(wnd),updating_(false)
{}

HexToolBar::~HexToolBar()
{}

///////////////////////////////////////////////////////////////////////////////////
// enable / disable edit boxes for inline edit
///////////////////////////////////////////////////////////////////////////////////

void HexToolBar::enable(bool b)
{
	::EnableWindow(hexEdit_,b);

	::EnableWindow(byteEdit1_,b);
	::EnableWindow(byteEdit2_,b);
	::EnableWindow(byteEdit3_,b);
	::EnableWindow(byteEdit4_,b);

	::EnableWindow(charEdit1_,b);
	::EnableWindow(charEdit2_,b);
	::EnableWindow(charEdit3_,b);
	::EnableWindow(charEdit4_,b);
}

///////////////////////////////////////////////////////////////////////////////////
// set a byte value given as hex string for one of the byte edit boxes
///////////////////////////////////////////////////////////////////////////////////

void HexToolBar::setByteValue( ToolEditLc& edit, const mol::string& byte )
{
	unsigned int i = 0;
	mol::istringstream iss(byte);
	iss >> std::hex >> i;

	i = i < 256 ? i : 255;

	std::ostringstream oss;
	oss.fill(_T('0'));
	oss << std::setw(3) << i;

	updating_ = true;
	DWORD start = 0;
	DWORD end   = 0;
	edit.sendMessage(EM_GETSEL, (WPARAM)&start,(LPARAM)&end);
	edit.setText(mol::toString(oss.str()));
	edit.sendMessage(EM_SETSEL, (WPARAM)&start,(LPARAM)&end);
	updating_ = false;
}

///////////////////////////////////////////////////////////////////////////////////
// set a char value given as hex string for one of the char edit boxes
///////////////////////////////////////////////////////////////////////////////////

void HexToolBar::setCharValue( ToolEdit& edit, const mol::string& byte )
{
	unsigned int i = 0;
	mol::istringstream iss(byte);
	iss >> std::hex >> i;

	i = i < 256 ? i : 255;

	char c = (char)i;

	updating_ = true;
	edit.setText(mol::toString(std::string(1,(char)i)));
	updating_ = false;
}


///////////////////////////////////////////////////////////////////////////////////
// set new offset and value in toolbar edit boxes
///////////////////////////////////////////////////////////////////////////////////

void HexToolBar::setValue( const mol::string& address, const mol::string& val )
{
	DWORD start = 0;
	DWORD end   = 0;

	updating_ = true;
	offsetEdit_.sendMessage(EM_GETSEL, (WPARAM)&start,(LPARAM)&end);
	offsetEdit_.setText(address);
	offsetEdit_.postMessage(EM_SETSEL, (WPARAM)start,(LPARAM)end);
	
	hexEdit_.sendMessage(EM_GETSEL, (WPARAM)&start,(LPARAM)&end);
	hexEdit_.setText(val);
	hexEdit_.sendMessage(EM_SETSEL, (WPARAM)start,(LPARAM)end);
	updating_ = false;

	mol::string byteVal1 = val.substr(0,2);
	mol::string byteVal2 = val.substr(2,2);
	mol::string byteVal3 = val.substr(4,2);
	mol::string byteVal4 = val.substr(6,2);

	setByteValue( byteEdit1_, byteVal1 );
	setByteValue( byteEdit2_, byteVal2 );
	setByteValue( byteEdit3_, byteVal3 );
	setByteValue( byteEdit4_, byteVal4 );

	setCharValue( charEdit1_, byteVal1 );
	setCharValue( charEdit2_, byteVal2 );
	setCharValue( charEdit3_, byteVal3 );
	setCharValue( charEdit4_, byteVal4 );
}

///////////////////////////////////////////////////////////////////////////////////
// create new toolbar window
///////////////////////////////////////////////////////////////////////////////////

HWND HexToolBar::createWindow(  const mol::string& wndName, HMENU hMenu, const mol::Rect& r, HWND parent )
{
	//create tool bar
	HWND hWnd = mol::ToolBar::createWindow( wndName, hMenu, r, parent );

	//create child widgets: static labels with text and edit boxes
	//one edit box for address and hex value each, 4 boxes each for
	//single decimal byte and char display

	mol::string tmp(_T("value at offset"));

	mol::DC dc(*this);			

	HFONT font = (HFONT)::GetStockObject(ANSI_FIXED_FONT);
	dc.select(font);
	TEXTMETRIC tt;
	::GetTextMetrics( dc,  &tt);

	dc.select((HFONT)::GetStockObject(ANSI_VAR_FONT));
	SIZE s;
	::GetTextExtentPoint32( dc, tmp.c_str(), (int)tmp.size(), &s );

	offsetLabel1_.create(tmp,(HMENU)IDC_LABEL1,mol::Rect(4,6,s.cx,22),*this);
	offsetLabel1_.setFont((HFONT)::GetStockObject(ANSI_VAR_FONT));

	mol::Rect rc(s.cx + tt.tmMaxCharWidth + 4, 3 , tt.tmMaxCharWidth*8 + 8 + 4, tt.tmHeight+7 );
	offsetEdit_.create((HMENU)IDC_OFFSET, rc, *this);
	offsetEdit_.setFont( font );
	offsetEdit_.sendMessage(EM_SETLIMITTEXT,(WPARAM)8,0);

	int w = rc.right;

	tmp =_T( "hex:");
	::GetTextExtentPoint32( dc, tmp.c_str(), (int)tmp.size(), &s );
	rc.left  += w + 4;
	rc.right = s.cx;
	offsetLabel2_.create(tmp,(HMENU)IDC_LABEL2,mol::Rect(rc.left,6,rc.right,rc.bottom),*this);


	rc.left  += rc.right+4;
	rc.right =  w+4;

	hexEdit_.create((HMENU)IDC_HEXEDIT, rc, *this);
	hexEdit_.setFont( font );
	hexEdit_.sendMessage(EM_SETLIMITTEXT,(WPARAM)8,0);

	tmp = _T("decimal:");
	::GetTextExtentPoint32( dc, tmp.c_str(), (int)tmp.size(), &s );
	rc.left  += rc.right+4;
	rc.right = s.cx + 5 + 6;
	offsetLabel3_.create(tmp,(HMENU)IDC_LABEL3,mol::Rect(rc.left,6,rc.right,rc.bottom),*this);

	w = rc.right;
	rc.left  += w+4;
	rc.right = tt.tmMaxCharWidth*3 + 8 + 4;

	byteEdit1_.create((HMENU)IDC_BYTEEDIT1,rc, *this);
	byteEdit1_.setFont( font );
	byteEdit1_.sendMessage(EM_SETLIMITTEXT,(WPARAM)3,0);

	rc.left  += rc.right+4;
	byteEdit2_.create((HMENU)IDC_BYTEEDIT2,rc, *this);
	byteEdit2_.setFont( font );
	byteEdit2_.sendMessage(EM_SETLIMITTEXT,(WPARAM)3,0);

	rc.left  += rc.right+4;
	byteEdit3_.create((HMENU)IDC_BYTEEDIT3,rc, *this);
	byteEdit3_.setFont( font );
	byteEdit3_.sendMessage(EM_SETLIMITTEXT,(WPARAM)3,0);

	rc.left  += rc.right+4;
	byteEdit4_.create((HMENU)IDC_BYTEEDIT4,rc, *this);
	byteEdit4_.setFont( font );
	byteEdit4_.sendMessage(EM_SETLIMITTEXT,(WPARAM)3,0);

	rc.left  += rc.right+4;
	tmp = _T("ascii:");
	::GetTextExtentPoint32( dc, tmp.c_str(), (int)tmp.size(), &s );
	rc.right = s.cx + 5 + 6;
	offsetLabel4_.create(tmp,(HMENU)IDC_LABEL4,mol::Rect(rc.left,6,rc.right,rc.bottom),*this);

	rc.left  += rc.right+4;
	rc.right  = tt.tmMaxCharWidth*1 + 8;
	charEdit1_.create((HMENU)IDC_CHAREDIT1,rc, *this);

	rc.left  += rc.right+4;
	charEdit2_.create((HMENU)IDC_CHAREDIT2,rc, *this);

	rc.left  += rc.right+4;
	charEdit3_.create((HMENU)IDC_CHAREDIT3,rc, *this);

	rc.left  += rc.right+4;
	charEdit4_.create((HMENU)IDC_CHAREDIT4,rc, *this);

	return hWnd;
}

///////////////////////////////////////////////////////////////////////////////////
// wndproc
///////////////////////////////////////////////////////////////////////////////////

LRESULT HexToolBar::wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static COLORREF col = RGB(255,255,255);
	static COLORREF grey_col = ::GetSysColor(COLOR_BTNFACE);

	static HBRUSH brush = (HBRUSH)::GetStockObject(WHITE_BRUSH);
	static HBRUSH greyBrush = (HBRUSH)::CreateSolidBrush(grey_col);

	switch(message)
	{
		// overide grey bkgd for disabled edit boxes:
		
		case WM_CTLCOLORSTATIC:
		{
			HDC dc = (HDC)(wParam);			 
			if ( (HWND) lParam == (HWND)offsetLabel1_ )
			{
				::SetBkColor(dc,grey_col);
				return (LRESULT)greyBrush;
			}
			if ( (HWND) lParam == (HWND)offsetLabel2_ )
			{
				::SetBkColor(dc,grey_col);
				return (LRESULT)greyBrush;
			}
			if ( (HWND) lParam == (HWND)offsetLabel3_ )
			{
				::SetBkColor(dc,grey_col);
				return (LRESULT)greyBrush;
			}
			if ( (HWND) lParam == (HWND)offsetLabel4_ )
			{
				::SetBkColor(dc,grey_col);
				return (LRESULT)greyBrush;
			}
			::SetBkColor(dc,col);
			return (LRESULT)brush;
		}
		// handle notification change messages from edit boxes
		case WM_COMMAND:
		{
			// user changed edit box value
			if ( HIWORD(wParam) == EN_CHANGE )
			{
				if ( LOWORD(wParam) == IDC_OFFSET )
				{
					if ( updating_ )
						return 0;

					mol::string addr = offsetEdit_.getText();

					// make sure value jas changed, is exact 8 chars
					// and has only valid hex chars

					hexCtrl_->hex_.scrollTo(addr);
				}

				if ( LOWORD(wParam) == IDC_HEXEDIT )
				{
					if ( updating_ )
						return 0;

					mol::string val = hexEdit_.getText();

					// make sure value jas changed, is exact 8 chars
					// and has only valid hex chars

					if ( val.size() != 8 )
						return 0;

					size_t pos = val.find_first_not_of(_T("0123456789abcdef"));
					if ( pos != mol::string::npos )
						return 0;

					// set value at current offset
					hexCtrl_->hex_.setOffsetValue(val);
					hexCtrl_->hex_.invalidateRect(0,TRUE);
					hexCtrl_->hex_.updateOffset();
				}

				if ( LOWORD(wParam) >= IDC_BYTEEDIT1 && LOWORD(wParam) <= IDC_BYTEEDIT4 )
				{
					if ( updating_ )
						return 0;

					mol::TCHAR bytes[4];
					::GetDlgItemText( *this, LOWORD(wParam), bytes, 4 );

					mol::string val(bytes);

					if ( val.size() != 3 )
						return 0;

					size_t pos = val.find_first_not_of(_T("0123456789"));
					if ( pos != std::string::npos )
						return 0;

					// set value at current offset
					hexCtrl_->hex_.setByteOffsetValue(val,LOWORD(wParam)-IDC_BYTEEDIT1,false);
					hexCtrl_->hex_.invalidateRect(0,TRUE);
					hexCtrl_->hex_.updateOffset();
				}
				if ( LOWORD(wParam) >= IDC_CHAREDIT1 && LOWORD(wParam) <= IDC_CHAREDIT4 )
				{
					if ( updating_ )
						return 0;

					char bytes[2];
					::GetDlgItemTextA( *this, LOWORD(wParam), bytes, 2 );

					std::string val(bytes);

					if ( val.size() != 1 )
						return 0;

					// set value at current offset
					hexCtrl_->hex_.setCharOffsetValue(val[0],LOWORD(wParam)-IDC_CHAREDIT1);
					hexCtrl_->hex_.invalidateRect(0,TRUE);
					hexCtrl_->hex_.updateOffset();
				}
			}
		}
	}
	return mol::ToolBar::wndProc(hWnd,message,wParam,lParam);
}




///////////////////////////////////////////////////////////////////////////////////
// Hex Display Window
///////////////////////////////////////////////////////////////////////////////////

HexWnd::HexWnd(HexCtrl* wnd)
{
	hexCtrl_     = wnd;
	offset_      = 0;
	fsize_       = 0;
	readOnly_    = false;
	cols_        = 24;
	searchPos_   = 0;
	showToolBar_ = true;

	col_  = RGB(238,236,238);
	br_   = ::CreateSolidBrush(col_);
}

HexWnd::~HexWnd()
{
	::DeleteObject( br_ );
}

///////////////////////////////////////////////////////////////////////////////////
// set number of DWORD (4 bytes) cols to display for each row
///////////////////////////////////////////////////////////////////////////////////

void HexWnd::setCols(unsigned int c)
{
	cols_ = (c / 4) * 4;
	if ( (cols_ < 4) || (cols_ > 32) )
		cols_ = 4;

	// update scroll info
	setVScroll(ttheight_+4, fsize_ / cols_ + 1);
	setHScroll(ttwidth_, 11 + (cols_*2) + (cols_/4) + 2 + cols_);

	// redraw all
	caretX_ = 0;
	caretY_ = 0;

	if ( !readOnly_)
		::SetCaretPos((caretX_+11)*ttwidth_,0);

	scrollTo(0);
	invalidateRect(0,TRUE);
}

unsigned int HexWnd::getCols()
{
	return cols_;
}

const mol::string& HexWnd::getFilename()
{
	return filename_;
}


///////////////////////////////////////////////////////////////////////////////////
// load file and map it to memory
///////////////////////////////////////////////////////////////////////////////////

bool HexWnd::load(const mol::string& filename, bool readOnly)
{
	if ( map_)
		map_.close();

	readOnly_ = readOnly;
	filename_ = filename;

	// get file size
	//mol::filestream fs;
	//if (!fs.open(filename.c_str()))
	//	return false;

	//mol::FileInfo fi = fs.fileInfo();
	//fs.close();

	// map file, if necessary RO
	if ( readOnly )
		map_.map(filename,GENERIC_READ);
	else
		map_.map(filename);

	fsize_ = (unsigned int) map_.size();

	// set new main window text
	mol::stringstream oss;
	oss << filename;
	if ( readOnly )
		oss << _T(" [readonly]");

	hexCtrl_->setText(mol::Path::filename(oss.str()));

	// remember filesize
	offset_ = 0;
	//fsize_  = fi.fileSizeLow();

	// caret, if not RO
	caretX_ = 0;
	caretY_ = 0;

	// set scroll info
	setVScroll(ttheight_+4, fsize_ / cols_ + 1);
	setHScroll(ttwidth_, 11 + (cols_*2) + (cols_/4) + 2 + cols_);
	scrollTo(0);

	hexCtrl_->toolBar_.enable(!readOnly);

	setFocus();
	invalidateRect(0,TRUE);
	return true;
}

unsigned int HexWnd::getFileSize()
{
	return (unsigned int)(map_.size());
}

unsigned int HexWnd::getOffset()
{
	return (unsigned int)offset_;
}

///////////////////////////////////////////////////////////////////////////////////
// set value at current offset (from statusbar)
///////////////////////////////////////////////////////////////////////////////////

void HexWnd::setOffsetValue( const mol::string& val)
{
	if (!map_)
		return;

	if ( readOnly_ )
		return;

	if ( fsize_ < 1 )
		return;

	setByteOffsetValue( val.substr(0,2), 0, true );
	setByteOffsetValue( val.substr(2,2), 1, true );
	setByteOffsetValue( val.substr(4,2), 2, true );
	setByteOffsetValue( val.substr(6,2), 3, true );
}

///////////////////////////////////////////////////////////////////////////////////
// set a single byte value at current offset (from statusbar)
///////////////////////////////////////////////////////////////////////////////////

void HexWnd::setByteOffsetValue( const mol::string& val, int off, bool hex)
{
	if (!map_)
		return;

	if ( readOnly_ )
		return;

	if ( fsize_ <= (unsigned int)off + offset_ )
		return;

	if ( off > 3 )
		return;

	mol::string byte( val.c_str(), hex ? 2 : 3 );
	mol::istringstream iss(byte);

	if ( hex )
		iss >> std::hex;

	int v = 0;
	iss >> v;
	*map_[offset_+off] = (char)v;
	map_.flush();
}

///////////////////////////////////////////////////////////////////////////////////
// set value single byte value given as char at current offset (from statusbar)
///////////////////////////////////////////////////////////////////////////////////

void HexWnd::setCharOffsetValue( const char& c, int off)
{
	if (!map_)
		return;

	if ( readOnly_ )
		return;

	if ( fsize_ <= (unsigned int)off + offset_ )
		return;

	if ( off > 3 )
		return;

	int v = 0;
	*map_[offset_+off] = (char)c;
	map_.flush();
}

///////////////////////////////////////////////////////////////////////////////////
// set new current offset (from mouse click)
///////////////////////////////////////////////////////////////////////////////////

void HexWnd::setOffsetByMousePos(unsigned int mx, unsigned int my)
{
	if ( !map_ )
		return;

	// get scroll pos
	int y = siV_.nPos;
	int x = siH_.nPos;

	// determine row
	y += my / (ttheight_+4);

	// determine col
	mx = mx + x*ttwidth_;

	// check if address got clicked
	if ( mx <= (ttwidth_*11) )
	{
		caretX_ = 0;
		caretY_ = y;
		if (!readOnly_)
			::SetCaretPos( (caretX_+11-siH_.nPos)*ttwidth_,(caretY_-siV_.nPos)*(ttheight_+4));

		// offset determined by rows (y)
		unsigned int off = y*cols_;
		if ( off >= fsize_ )
			return;
		updateOffset( off );
		return;
	}

	// adjust mx for address cols
	mx  = mx - 11*ttwidth_;

	// check if out of bounds
	if ( mx >= ttwidth_*( (cols_*2) + cols_/4 ) ) 
		return;

	// offset of DWORD clicked
	//int off = (mx / (ttwidth_*9)) * 4 + y*cols_;


	caretX_ = ( mx / (ttwidth_) );
	caretX_ = caretX_ - (caretX_/9);
	caretY_ = y;

	// offset of DWORD clicked
	unsigned int off = (caretX_/8)*4 + y*cols_;

	if ( off >= fsize_ )
		return;

	if (!readOnly_)
		::SetCaretPos( (caretX_+11-siH_.nPos+caretX_/8)*ttwidth_,(caretY_-siV_.nPos)*(ttheight_+4));

	
	updateOffset(off);
}

///////////////////////////////////////////////////////////////////////////////////
// update current offset
///////////////////////////////////////////////////////////////////////////////////

void HexWnd::updateOffset()
{
	updateOffset(offset_);
}

///////////////////////////////////////////////////////////////////////////////////
// get hex value at given offset, highlite and update statusbar
///////////////////////////////////////////////////////////////////////////////////

void HexWnd::updateOffset(unsigned int offset)
{
	if (!readOnly_)
		::HideCaret(*this);

	// get DC to highlight
	mol::DC dc(*this);
	dc.select((HFONT)::GetStockObject(ANSI_FIXED_FONT));
	
	//remove old highlite
	drawOffset(dc,offset_,true);

	//change offset value
	offset_ = offset;

	//prepare offset addres as hex string for toolbar
	mol::ostringstream ossAddr;
	ossAddr.fill(_T('0'));
	ossAddr << std::hex 
			<< std::setw( 8 ) 
			<< (offset);

	//prepare offset value as hex string
	unsigned char c = 0;
	unsigned int  i = 0;
	mol::ostringstream ossVal;
	ossVal.fill(_T('0'));
	ossVal << std::hex << std::setw( 2 );
	
	c = *map_[offset];
	i = c;
	ossVal << i << std::setw( 2 );
	
	c = *map_[offset+1];
	i = c;
	ossVal << i << std::setw( 2 );
	
	c = *map_[offset+2];
	i = c;
	ossVal << i << std::setw( 2 );
	
	c = *map_[offset+3];
	i = c;
	ossVal << i;

	currentOffsetValue_ = ossVal.str();

	dc.setBkColor(RGB(238,236,238));
	drawOffset(dc,offset_,false);

	if (!readOnly_)
		::ShowCaret(*this);

	// set toolbar info
	hexCtrl_->toolBar_.setValue(ossAddr.str(), currentOffsetValue_);
	hexCtrl_->fire(2,bstr(ossAddr.str()), bstr(currentOffsetValue_) );
}

///////////////////////////////////////////////////////////////////////////////////
// draw new highlite
///////////////////////////////////////////////////////////////////////////////////

void HexWnd::drawOffset(mol::win::DCbase& dc, unsigned int off, bool erase )
{
	if (!map_)
		return;

	if ( off >= fsize_ )
		return;

	if ( off < map_.offset() || off > ( map_.offset() + map_.pageSize() ) )
		return;

	RECT r;
	getClientRect(r);

	int y = off / cols_;
	int x = off % cols_;

	int tab = (1 + x/4);
	x = x*2;
	x = x + 10 - siH_.nPos + tab;
	x = x * ttwidth_;

	y = y - siV_.nPos;
	y = y * (ttheight_+4);

	mol::Rect rf(x-2,y-2,x+4+ttwidth_*8,y+ttheight_+4);
	if ( erase )
		::FillRect(dc,&rf,(HBRUSH)::GetStockObject(WHITE_BRUSH));
	else
		::FillRect(dc,&rf,br_);

	if ( fsize_ - offset_ >= 4 )
		dc.textOut(x,y,currentOffsetValue_.c_str());
	else
	{		
		dc.textOut(x,y,currentOffsetValue_.substr(0,(fsize_-offset_)*2).c_str());
	}
	/*

	char buf[4];
	for ( int i = 0; i < 4; i++ )
	{
		if ( off + i >= fsize_ )
			break;

		// get current char from map and convert to uint
		unsigned char v = *map_[off+i];
		unsigned int iv = (unsigned int)v;

		// print this char hex value
		wsprintf(buf,"%02x",iv);
		dc.textOut(x+i*ttwidth_*2,y,buf);
	}
	*/
	if ( !erase )
		::DrawEdge(dc,&rf,EDGE_ETCHED,BF_RECT);
}

///////////////////////////////////////////////////////////////////////////////////
// search in hex view
///////////////////////////////////////////////////////////////////////////////////

size_t HexWnd::getSearchPos()
{
	return searchPos_;
}

void HexWnd::setSearchPos(unsigned int p)
{
	if ( p >= map_.size() )
		p = 0;
	searchPos_ = p;
}

bool HexWnd::search(const mol::string& txt, DWORD flags)
{
	if (!map_)
		return false;

	if ( !(flags & FR_DOWN) )
		return searchUp(txt,flags);

	size_t s = txt.size();
	size_t p = searchPos_;
	//char* c = map_[p];

	while( p < fsize_ )
	{
		char* c = map_[p];
		if ( (*c == txt[0]) || ( !(flags & FR_MATCHCASE) && (tolower(txt[0]) == tolower(*c) ) ) )
		{			
			if ( p + s >= fsize_ )
				break;

			int result = 0;
			if ( flags & FR_MATCHCASE )
				result = _tcsncmp(txt.c_str(),(const mol::TCHAR*)c, s );
			else
				result = _tcsncicmp(txt.c_str(),(const mol::TCHAR*)c, s );

			if ( result == 0 )
			{
				size_t tmp = p / 4;
				tmp = tmp * 4;
				searchPos_ = p + s;
	
				scrollTo((unsigned int)tmp);
				return true;
			}
		}
		p++;
	}
	searchPos_ = 0;
	::MessageBox(0, _T("end of file"), _T("searching..."), 0);
	return false;
}

///////////////////////////////////////////////////////////////////////////////////
// search in hex view (upwards)
///////////////////////////////////////////////////////////////////////////////////

bool HexWnd::searchUp(const mol::string& txt, int flags)
{
	if (!map_)
		return false;

	size_t s = txt.size();
	size_t p = searchPos_;
	//char* c = map_[p];

	while( p != 0 )
	{
		p--;
		if ( p < s )
			break;

		char* c = map_[p-s];
		if ( (*c == txt[0]) || ( !(flags & FR_MATCHCASE) && (tolower(txt[0]) == tolower(*c) ) ) )
		{			
			int result = 0;
			if ( flags & FR_MATCHCASE )
				result = _tcsncmp(txt.c_str(),(const mol::TCHAR*)c, s );
			else
				result = _tcsncicmp(txt.c_str(),(const mol::TCHAR*)c, s );

			if ( result == 0 )
			{
				size_t tmp = (p-s) / 4;
				tmp = tmp * 4;
				searchPos_ = p - s + 1;

				scrollTo( (unsigned int) tmp );
				return true;
			}
		}
		
	}
	searchPos_ = fsize_;
	::MessageBox(0, _T("start of file"), _T("searching..."), 0);
	return false;
}



///////////////////////////////////////////////////////////////////////////////////
// scroll to offset given as hex string
///////////////////////////////////////////////////////////////////////////////////


void HexWnd::scrollTo(const mol::string& off)
{
	if ( off.size() != 8 )
		return;

	size_t pos = off.find_first_not_of(_T("0123456789abcdef"));
	if ( pos != std::string::npos )
		return;

	unsigned int ui = 0;
	mol::istringstream iss(off);
	iss >> std::hex >> ui;

	scrollTo(ui);
}

///////////////////////////////////////////////////////////////////////////////////
// scroll to offset
///////////////////////////////////////////////////////////////////////////////////

void HexWnd::scrollTo(unsigned int off,bool adjust)
{
	if ( !map_ )
		return;
	if ( fsize_ <= off )
		return;

	off = off / 4;
	off = off * 4;

	updateOffset(off);

	if ( adjust)
	{
		off = off/cols_;
		if ( off > 10 )
			off -= 10;
		else
			off = 0;
	}

	setScrollPos( off );
}

bool HexWnd::getReadOnly()
{
	return readOnly_;
}

mol::string HexWnd::value(unsigned int index)
{
	index = ( index / 4 ) * 4;

	if ( index >= fsize_ )
		return _T("");

	unsigned int  i = 0;
	unsigned char c = 0;
	mol::ostringstream oss;
	oss.fill(_T('0'));
	oss << std::hex << std::setw( 2 );
	
	c = *map_[index];
	i = c;
	oss << i << std::setw( 2 );
	if ( index+1 >= fsize_ )
		return oss.str();

	c = *map_[index+1];
	i = c;
	oss << i << std::setw( 2 );
	if ( index+2 >= fsize_ )
		return oss.str();

	c = *map_[index+2];
	i = c;
	oss << i << std::setw( 2 );
	if ( index+3 >= fsize_ )
		return oss.str();

	c = *map_[index+3];
	i = c;
	oss << i;

	return oss.str();
}

void HexWnd::onHScroll(unsigned int pos)
{
	int posY = siV_.nPos;
	if (!readOnly_)
		::SetCaretPos( (caretX_+11-pos+caretX_/8)*ttwidth_,(caretY_-posY)*(ttheight_+4));
}

void HexWnd::onVScroll(unsigned int pos)
{
	int posX = siH_.nPos;
	if (!readOnly_)
		::SetCaretPos( (caretX_+11-posX+caretX_/8)*ttwidth_,(caretY_-pos)*(ttheight_+4));
}

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

LRESULT HexWnd::wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)		
{				
	static HFONT		font = (HFONT)::GetStockObject(ANSI_FIXED_FONT);

	switch (message)
	{
		case WM_CREATE:
		{
			// determine text metrics
			TEXTMETRIC tt;
			mol::DC dc(*this);			
			dc.select(font);
			::GetTextMetrics( dc,  &tt );
			ttwidth_  = tt.tmMaxCharWidth;
			ttheight_ = tt.tmHeight;

			caretX_ = 0;
			caretY_ = 0;
			return 0;
		}
		case WM_DESTROY:
		{
			return 0;
		}
		case WM_LBUTTONDOWN:
		{
			// determine mouse click pos
			int mx = LOWORD(lParam);
			int my = HIWORD(lParam);

			// determine offset to set statusbar value
			setOffsetByMousePos(mx,my);
			setFocus();
			return 0;
		}
		case WM_PAINT:
		{
			//prepare paint DC and set font
			mol::PaintDC dc(*this);
			dc.select(font);
			
			// get dimensions
			RECT r;
			getClientRect(r);

			// fill offset background if necessary
			if ( siH_.nPos < 9 )
			{
				RECT rc = r;
				rc.right = (9-siH_.nPos)*ttwidth_;
				::FillRect(dc,&rc,br_);
				::MoveToEx(dc,rc.right,0,0);
				::LineTo(dc,rc.right,r.bottom);
			}

			// draw ascii bkg rect
			int lx = ttwidth_ * ( (cols_*2) + (cols_/4) + 13 - siH_.nPos );
			RECT rc = r;
			rc.left = lx;
			::FillRect(dc,&rc,br_);

			rc.left += ttwidth_;
			RECT tr = rc;
			for ( unsigned int i = 0; i < cols_; i+=8 )
			{
				if ( i > cols_ )
					break;

				tr.left = rc.left + ttwidth_ * (i);
				tr.right = tr.left + ttwidth_ * 4;
				::FillRect(dc,&tr,(HBRUSH)::GetStockObject(WHITE_BRUSH));
			}

			// draw ascii seperator line
			
			::MoveToEx(dc,lx,0,0);
			::LineTo(dc,lx,r.bottom);

			if (!map_)
				return 0;

			// start drawing output determined by y scrollpos
			unsigned int c = siV_.nPos*cols_;
			while ( c < fsize_ )
			{
				int  x   = 0;
				int  y   = 0;
				int  tab = 0;
				static mol::TCHAR buf[32];

				// determine y offset
				y = (c/cols_-siV_.nPos)*(ttheight_+4);

				// print offset
				wsprintf(buf,_T("%08X:"),c);				
				x = -siH_.nPos*ttwidth_;

				dc.setBkColor(col_);
				dc.textOut(x,y,buf);
				dc.setBkColor(RGB(255,255,255));

				// now print binary AND ascii values for this row
				for ( unsigned int i = 0; i < cols_; i++ )
				{
					// determine proper x offset
					x = i *( ttwidth_*2) + tab + (ttwidth_*11);

					// make sure we haven't reached end of mapping
					if ( c > fsize_-1 )
						break;

					// get current char from map and convert to uint
					unsigned char v = *map_[c];
					unsigned int iv = (unsigned int)v;

					// add tab every 4 (DWORD) cols
					if ( (i+1) % 4 == 0 )
						tab += ttwidth_;			
					
					// print this char hex value
					dc.setBkColor(RGB(255,255,255));
					wsprintf(buf,_T("%02x"),iv);
					y = (c/cols_-siV_.nPos)*(ttheight_+4);
					dc.textOut(x-siH_.nPos*ttwidth_,y,buf);

					// print ascii value
					wsprintf(buf,_T("%c"),v);
					if ( (i % 8) > 3 )
						dc.setBkColor(col_);
					else
						dc.setBkColor(RGB(255,255,255));

					// determine x offset for ascii display
					x = (cols_*2) + (cols_/4) + i + 14;

					x = x * ttwidth_;// * ( (cols_*2) + (cols_/4) + i + 14 );
					
					dc.textOut(x-siH_.nPos*ttwidth_,y,buf);

					// next char value
					c++;

					// boil out if outside display
					if ( (c/cols_-siV_.nPos)*ttheight_ > (unsigned int)r.bottom)
						break;
				}
				// boil out if outside display
				if ( (c/cols_-siV_.nPos)*ttheight_ > (unsigned int)r.bottom)
					break;
			}

			drawOffset(dc,offset_,RGB(0,0,0));
			return 0;
		}
		case WM_SETFOCUS :
		{
			if ( !readOnly_ )
			{
				::CreateCaret(*this,NULL,ttwidth_,ttheight_);
				::SetCaretPos( (caretX_+11-siH_.nPos+caretX_/8)*ttwidth_,(caretY_-siV_.nPos)*(ttheight_+4));
				::ShowCaret(*this);
			}			
			return 0;
		}
		case WM_KILLFOCUS :
		{
			if ( !readOnly_ )
			{
				::HideCaret(*this);
				::DestroyCaret();
			}
			return 0;
		}
		case WM_KEYDOWN :
		{
			switch( wParam )
			{
				case VK_HOME:
				{
					caretX_ = 0;
					caretY_ = 0;
					break;
				}
				case VK_END:
				{
					caretX_ = (fsize_ % cols_) * 2;// -1;
					caretY_ = (fsize_ / cols_);
					if ( caretY_ > 0 )
						--caretY_;

					break;
				}
				case VK_PRIOR:
				{					
					if ( caretY_ >= siV_.nPage )
						caretY_ -= siV_.nPage;
					else
						caretY_ = 0;
					break;
				}
				case VK_NEXT:
				{
					if ( caretY_ + siV_.nPage < scrollRows_ )
						caretY_ += siV_.nPage;
					else
						caretY_ = scrollRows_-1;
					break;
				}
				case VK_RIGHT:
				{
					if ( readOnly_ )
						caretX_ += 8;
					else
						caretX_ ++;
					if ( caretX_ >= cols_*2 )
					{
						caretX_ = 0;
						if ( (caretY_+1)*cols_ < fsize_ )
							caretY_++;
					}
					break;
				}
				case VK_DELETE:
				case VK_LEFT:
				{
					if ( caretX_ == 0 )
					{
						caretX_ = cols_*2-1;
						if ( caretY_ > 0 )
							caretY_--;
					}
					else
					{
						if ( readOnly_ )
						{
							if ( caretX_ <= 8 )
								caretX_ = 0;
							else
								caretX_ -= 8;
						}
						else
						{
							caretX_--;
						}
					}
					break;
				}
				case VK_UP:
				{
					if ( caretY_ > 0 )
						caretY_--;
					break;
				}
				case VK_DOWN:
				{
					if ( (caretY_+1)*cols_ < fsize_ )
					{
						caretY_++;
					}
					
					break;
				}
			}
			unsigned int off = (caretX_/8)*4 + caretY_*cols_;
			if ( (caretY_< (unsigned int)(siV_.nPos)) || (caretY_-(unsigned int)(siV_.nPos) > (unsigned int)(siV_.nPage) ))
			{
				scrollTo(off);
			}
			updateOffset(off);
			if ( !readOnly_ )
				::SetCaretPos( (caretX_+11-siH_.nPos+caretX_/8)*ttwidth_,(caretY_-siV_.nPos)*(ttheight_+4));
			return 0;
		}
		case WM_CHAR :
		{
			for (int i = 0; i < (int) LOWORD(lParam); i++ )
			{
				switch (wParam)
				{
					case '\b' : //backspace
					{
						sendMessage(WM_KEYDOWN,WPARAM(VK_DELETE),0);
						return 0;
					}
					case '\t' : //tab
					{
						break;
					}
					case '\n' : //linefeed
					{
						if ( (caretY_+1)*cols_ < fsize_ )
							caretY_++;
						break;
					}
					case '\r' : //return
					{
						caretX_ = 0;
						if ( (caretY_+1)*cols_ < fsize_ )
							caretY_++;
						break;
					}
					case '\x1B' : //escape
					{
						break;
					}
					default : // characters
					{
						if ( readOnly_ )
							break;

						::HideCaret(*this);
						mol::DC dc(*this);

						mol::string s(1,(wchar_t)wParam);

						size_t p = s.find_first_not_of(_T("0123456789abcdef"));
						if ( p == mol::string::npos )
						{			
							int f = caretX_ % 2;							
							int off = (caretX_/2) + ( caretY_ * cols_ );
							off = off - offset_;
							if ( off >= 0 && off <= 3 )
							{
								mol::string currVal = currentOffsetValue_.substr(off*2,2);
								mol::string tmp(_T(""));
								if ( f == 1 )
									tmp = currVal.substr(0,1);
								tmp.append( s );
								if ( f == 0 )
									tmp.append(currVal.substr(1,1));
								
								setByteOffsetValue(tmp,off,true);
								invalidateRect(0,TRUE);
							}
						}

						caretX_++;
						if ( caretX_ >= cols_*2 )
						{
							caretX_ = 0;
							if ( (caretY_+1)*cols_ < fsize_ )
								caretY_++;
						}
						::ShowCaret(*this);			
						break;
					}
				} // switch wParam
			}
			
			unsigned int off = (caretX_/8)*4 + caretY_*cols_;
			if ( (caretY_< (unsigned int)(siV_.nPos)) || (caretY_-(unsigned int)(siV_.nPos) > (unsigned int)(siV_.nPage )))
			{				
				scrollTo(off);
			}
			if ( !readOnly_ )
				::SetCaretPos( (caretX_+11-siH_.nPos+caretX_/8)*ttwidth_,(caretY_-siV_.nPos)*(ttheight_+4));
			updateOffset(off);
			return 0;
		}		

	}

	return mol::ScrollWnd::wndProc(hWnd, message, wParam, lParam);
}

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

HexCtrl::HexCtrl()
 : toolBar_(this),
   hex_(this)
{
	vbShowToolBar_  = VARIANT_TRUE;
	vbReadOnly_		= VARIANT_TRUE;
	sizel.cx = 800;
	sizel.cy = 600;

	this->eraseBackground_ = 1;
	
	clientRect_ = mol::Rect(0,0,0,0);
}

HexCtrl::~HexCtrl()
{

}

LRESULT HexCtrl::OnCreate( UINT, WPARAM, LPARAM )
{
	RECT r;
	getClientRect(r);
	toolBar_.create((HMENU)IDC_HEXTOOLBAR,r,*this);
	if ( vbShowToolBar_ == VARIANT_FALSE )
	{
		toolBar_.show(SW_HIDE);
	}
	hex_.create((HMENU) IDC_HEXEDIT, r, *this );			
	return 0;
}

HRESULT __stdcall HexCtrl::get_Filename		( BSTR* fn )
{
	if ( !fn )
		return E_INVALIDARG;

	*fn = ::SysAllocString( mol::towstring(hex_.getFilename()).c_str());
	return S_OK;
}

HRESULT __stdcall HexCtrl::put_Filename		( BSTR  fn )
{
	if ( S_OK != OnRequestEdit(3) )
		return S_FALSE;

	if ( hex_.load( bstr(fn).toString(), vbReadOnly_ == VARIANT_TRUE ? true : false ))
	{
		this->OnChanged(3);
		this->fire( 1, fn, vbReadOnly_ );
		return S_OK;
	}
	return S_FALSE;
}

HRESULT __stdcall HexCtrl::get_HasFocus	( VARIANT_BOOL* vb )
{
	if ( !vb )
		return E_INVALIDARG;

	*vb = hex_.hasFocus() ? VARIANT_TRUE : VARIANT_FALSE;
	return S_OK;
}


HRESULT __stdcall HexCtrl::get_ShowToolbar	( VARIANT_BOOL* vb )
{
	if ( !vb )
		return E_INVALIDARG;

	*vb = vbShowToolBar_;
	return S_OK;
}

HRESULT __stdcall HexCtrl::put_ShowToolbar	( VARIANT_BOOL vb  )
{
	if ( S_OK != OnRequestEdit(5) )
		return S_FALSE;

	vbShowToolBar_ = vb;
	toolBar_.show( vb == VARIANT_TRUE ? SW_SHOW : SW_HIDE );
	toolBar_.invalidateRect(0,TRUE);
	invalidateRect(0,TRUE);
	this->OnChanged(5);
	return S_OK;
}


HRESULT __stdcall HexCtrl::get_ReadOnly	( VARIANT_BOOL* vb )
{
	if ( !vb )
		return E_INVALIDARG;

	vbReadOnly_ = hex_.getReadOnly() ? VARIANT_TRUE : VARIANT_FALSE;
	*vb = vbReadOnly_;
	return S_OK;	
}

HRESULT __stdcall HexCtrl::put_ReadOnly	( VARIANT_BOOL vb  )
{
	if ( S_OK != OnRequestEdit(1) )
		return S_FALSE;

	vbReadOnly_ = vb;

	this->OnChanged(5);
	return S_OK;
}


HRESULT __stdcall HexCtrl::get_ScrollPos	( long* p )
{
	if ( !p )
		return E_INVALIDARG;

	*p = (long)hex_.getScrollPos();
	return S_OK;
}

HRESULT __stdcall HexCtrl::put_ScrollPos	( long  p )
{
	hex_.setScrollPos(p);
	return S_OK;
}


HRESULT __stdcall HexCtrl::get_DisplayColumns( long* c )
{
	if ( !c )
		return E_INVALIDARG;

	*c = (long) hex_.getCols();
	return S_OK;
}

HRESULT __stdcall HexCtrl::put_DisplayColumns( long  c )
{
	if ( S_OK != OnRequestEdit(2) )
		return S_FALSE;

	hex_.setCols(c);
	invalidateRect(0,TRUE);
	this->OnChanged(2);
	return S_OK;
}


HRESULT __stdcall HexCtrl::get_ScrollMax	( long* p )
{
	if ( !p )
		return E_INVALIDARG;

	*p = (long) hex_.getScrollMax();
	return S_OK;
}


HRESULT __stdcall HexCtrl::get_Offset( long* o )
{
	if ( !o )
		return E_INVALIDARG;

	*o = (long) hex_.getOffset();
	return S_OK;
}

HRESULT __stdcall HexCtrl::put_Offset( long  o )
{
	hex_.scrollTo(o,true);	
	return S_OK;
}


HRESULT __stdcall HexCtrl::get_FileSize( long* s )
{
	if ( !s )
		return E_INVALIDARG;

	*s = (long) hex_.getFileSize();
	return S_OK;
}


HRESULT __stdcall HexCtrl::get_SearchPos( long* s )
{
	if ( !s )
		return E_INVALIDARG;

	*s = (long) hex_.getSearchPos();
	return S_OK;
}

HRESULT __stdcall HexCtrl::put_SearchPos( long  o )
{
	hex_.setSearchPos(o);
	return S_OK;
}


// COM methods

HRESULT __stdcall HexCtrl::Open( BSTR file, VARIANT_BOOL* vbSuccess)
{
	if ( !vbSuccess )
		return E_INVALIDARG;

	bool b = hex_.load( bstr(file).toString(), false );
	*vbSuccess = b ? VARIANT_TRUE : VARIANT_FALSE;
	
	clientRect_ = mol::Rect(0,0,0,0);
	return S_OK;
}


HRESULT __stdcall HexCtrl::OpenReadOnly( BSTR file, VARIANT_BOOL* vbSuccess )
{
	if ( !vbSuccess )
		return E_INVALIDARG;

	bool b = hex_.load( bstr(file).toString(), true );
	*vbSuccess = b ? VARIANT_TRUE : VARIANT_FALSE;

	clientRect_ = mol::Rect(0,0,0,0);
	return S_OK;
}


HRESULT __stdcall HexCtrl::SetOffsetDWORD( long offset, BSTR val )
{
	unsigned int off = (offset / 4) * 4;
	if ( offset != off )
		return E_INVALIDARG;

	mol::string s = bstr(val).toString();
	if ( s.size() < 2 )
		return E_INVALIDARG;

	if ( (s[0] == '0') && ( s[1] == 'x' || s[1] == 'X') )
		s = s.substr(2);

	if ( s.size() != 8 )
		return E_INVALIDARG;

	size_t p = s.find_first_not_of(_T("0123456789ABCDEFabcdef"));
	if ( p != mol::string::npos )
		return E_INVALIDARG;

	hex_.scrollTo(offset);
	hex_.setOffsetValue( s );
	return S_OK;
}


HRESULT __stdcall HexCtrl::SetOffsetByte( long offset, BSTR val )
{
	mol::string s = bstr(val).toString();
	if ( s.size() < 2 )
		return E_INVALIDARG;

	if ( (s[0] == '0') && ( s[1] == 'x' || s[1] == 'X') )
		s = s.substr(2);

	if ( s.size() != 2 )
		return E_INVALIDARG;

	size_t p = s.find_first_not_of(_T("0123456789ABCDEFabcdef"));
	if ( p != mol::string::npos )
		return E_INVALIDARG;

	unsigned int off = (offset / 4) * 4;
	hex_.scrollTo(off);
	hex_.setByteOffsetValue( s, offset-off, true );
	return S_OK;
}


HRESULT __stdcall HexCtrl::SetOffsetChar( long offset, long val )
{
	if ( (val < 0) || (val > 255) )
		return E_INVALIDARG;

	unsigned int off = (offset / 4) * 4;

	hex_.scrollTo(off);
	hex_.setCharOffsetValue( (char)val, offset-off );
	return S_OK;
}

HRESULT __stdcall HexCtrl::Search( BSTR what, long flags)
{
	hex_.search( bstr(what).toString(), flags );
	return S_OK;
}

HRESULT __stdcall HexCtrl::Value( long off, BSTR* value)
{
	if (!value)
		return E_INVALIDARG;

	*value = ::SysAllocString( mol::towstring(hex_.value(off)).c_str() );
	return S_OK;
}

HRESULT HexCtrl::OnDraw( HDC hdcDraw, LPCRECTL lprcBounds, LPCRECTL lprcMFBounds)
{
	RECT r = {
		lprcBounds->left,
		lprcBounds->top,
		lprcBounds->right  - lprcBounds->left,
		lprcBounds->bottom - lprcBounds->top 
	};

	if ( (clientRect_.right  == r.right) &&
		 (clientRect_.bottom == r.bottom) )
	{
		return S_OK;
	}

	clientRect_ = r;

	if ( toolBar_.isVisible() )
	{
		toolBar_.sendMessage(WM_SIZE,0,MAKELPARAM(r.right-r.left,r.bottom-r.top));

		RECT rt;
		toolBar_.getWindowRect(rt);
		r.top    += rt.bottom - rt.top;
		r.bottom -= rt.bottom - rt.top;
	}

	hex_.move( r, TRUE );			
	return S_OK;
}

HRESULT __stdcall HexCtrl::Load( LPSTREAM pStm)
{
	pStm >> mol::property( mol::DispId(this,DISPID_HexCtrl_READONLY,VT_BOOL) )
		 >> mol::property( mol::DispId(this,DISPID_HexCtrl_DISPLAYCOLUMNS,VT_I4) )
		 >> mol::property( mol::DispId(this,DISPID_HexCtrl_FILENAME,VT_BSTR) )
		 >> mol::property( mol::DispId(this,DISPID_HexCtrl_SHOWTOOLBAR,VT_BOOL) )
		 >> mol::property( &sizel );

	return S_OK;
}

HRESULT __stdcall HexCtrl::Save( LPSTREAM pStm,BOOL fClearDirty)
{
	pStm << mol::property( mol::DispId(this,DISPID_HexCtrl_READONLY,VT_BOOL) )
		 << mol::property( mol::DispId(this,DISPID_HexCtrl_DISPLAYCOLUMNS,VT_I4) )
		 << mol::property( mol::DispId(this,DISPID_HexCtrl_FILENAME,VT_BSTR) )
		 << mol::property( mol::DispId(this,DISPID_HexCtrl_SHOWTOOLBAR,VT_BOOL) )
		 << mol::property( &sizel );

	return S_OK;
}

HRESULT __stdcall HexCtrl::Load( IPropertyBag *pPropBag,IErrorLog *pErrorLog)
{

	pPropBag >> mol::property( _T("readonly"), mol::DispId(this,DISPID_HexCtrl_READONLY,VT_BOOL) )
			 >> mol::property( _T("displaycolumns"), mol::DispId(this,DISPID_HexCtrl_DISPLAYCOLUMNS,VT_I4) )
			 >> mol::property( _T("filename"), mol::DispId(this,DISPID_HexCtrl_FILENAME,VT_BSTR) )
			 >> mol::property( _T("showtoolbar"), mol::DispId(this,DISPID_HexCtrl_SHOWTOOLBAR,VT_BOOL) )
			 >> mol::property( _T("cs"), &sizel );

	return S_OK;
}

HRESULT __stdcall HexCtrl::Save( IPropertyBag *pPropBag,BOOL fClearDirty,BOOL fSaveAllProperties)
{
	pPropBag << mol::property( _T("readonly"), mol::DispId(this,DISPID_HexCtrl_READONLY,VT_BOOL) )
			 << mol::property( _T("displaycolumns"), mol::DispId(this,DISPID_HexCtrl_DISPLAYCOLUMNS,VT_I4) )
			 << mol::property( _T("filename"), mol::DispId(this,DISPID_HexCtrl_FILENAME,VT_BSTR) )
			 << mol::property( _T("showtoolbar"), mol::DispId(this,DISPID_HexCtrl_SHOWTOOLBAR,VT_BOOL) )
			 << mol::property( _T("cs"), &sizel );


	return S_OK;
}