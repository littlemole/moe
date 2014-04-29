#include "win/propwnd.h"

namespace mol  {
namespace prop {

#define IDM_EDIT_DONE 101
#define IDC_PROP_EDIT 102

void AbstractProp::draw( mol::win::DCbase& dc, RECT& r, int& offset )
{
	int h = propWnd_->rowHeight();
	int o = propWnd_->borderWidth();
	int s = propWnd_->spin();

	rName_ = mol::Rect( r.left-1, r.top+offset-1,  ( (r.right * s ) - 24 )/100,  r.top+offset+h);
	rValue_ = mol::Rect( -1+( (r.right * s )-24)/100, r.top+offset-1,  2+r.right-24,  r.top+offset+h);

	dc.frameRect( rName_, propWnd_->blackBrush() );
	dc.textOut( r.left+o,r.top+offset+o,name_ );

	dc.frameRect( rValue_, propWnd_->blackBrush() );
	dc.textOut( (((r.right * s )-24)/100)+o,r.top+offset+o, getValueAsString() );

	mol::Rect rRight( 2+r.right-24, r.top+offset-1,  2+r.right,  r.top+offset+h );
	dc.fillRect( rRight, propWnd_->backgroundBrush() );

	offset += h;
}


EditProp::EditProp( const std::wstring& n, PropWindow* propWnd, const std::string& validate )
	:AbstractProp(n,propWnd)
{
	validator_ = validate;
}


void EditProp::startEdit(HWND parent)
{
	int h = propWnd_->rowHeight();
	int o = propWnd_->borderWidth();

	mol::Rect f(rValue_.left+1, rValue_.top+1, rValue_.right-1, rValue_.bottom-1);
	mol::DC dc(parent);
	dc.frameRect(f, propWnd_->backgroundBrush() );

	mol::Rect r(rValue_.left+o+1, rValue_.top+o+1, rValue_.right-rValue_.left-o-2, h-o-2);
	edit_.create((HMENU)IDC_PROP_EDIT,r,parent);

	edit_.setText(getValueAsString());
	edit_.show(SW_SHOW);
	edit_.setFocus();
}

void EditProp::stopEdit()
{
	edit_.show(SW_HIDE);
	setValueFromString( edit_.getText() );
	edit_.destroy();
}

} // end namespace prop

PropWindow::PropWindow()
{
	spin_ = 50;
	inEdit_ = 0;
	//borderWidth_ = 4;
	dragging_ = false;

	NONCLIENTMETRICS nm;
	nm.cbSize = sizeof (NONCLIENTMETRICS);

	SystemParametersInfo (SPI_GETNONCLIENTMETRICS,0,&nm,0);
	LOGFONT fl = nm.lfMenuFont;
	borderWidth_ = nm.iBorderWidth;

	font_ = ::CreateFontIndirect(&fl);

	LOGFONT logFont;
	::GetObject ( font_, sizeof(LOGFONT), &logFont );
	logFont.lfWeight = FW_BOLD;

	bfont_ = ::CreateFontIndirect(&logFont); 

	backgroundBrush_ = ::CreateSolidBrush( backgroundColor() );
}

PropWindow::~PropWindow()
{
	::DeleteObject(font_);
	::DeleteObject(bfont_);
}


LRESULT PropWindow::OnSize(UINT msg, WPARAM wParam, LPARAM lParam)
{
	int s = rowHeight_*cnt();
	setVScroll( 1,s);

	OnEditDone();
	return BaseWindowType::OnSize(msg,wParam,lParam);
}

void PropWindow::OnCreate()
{
	RECT cr;
	getClientRect(cr);

	int c = (cr.right-cr.left)/2;

	mol::DC dc(*this);

	dc.select(font_);
	TEXTMETRIC tt;
	::GetTextMetrics( dc,  &tt);

	rowHeight_ = tt.tmHeight + 2*borderWidth_;
	int y = rowHeight_*cnt();
	setVScroll( 1,y);
}

void PropWindow::OnPaint()
{
	mol::PaintDC dc(*this);
	dc.select(font_);

	RECT r;
	getClientRect(r);

	int y = 0;
	int pos = getScrollPos(SB_VERT);
	y = y - pos;

	for ( PropIter it = props_.begin(); it != props_.end(); it++)
	{
		(*it).second->draw( dc, r, y );
	}

	mol::Rect rbottom( r.left, r.top+y,r.right,r.bottom);
	dc.fillRect(rbottom,backgroundBrush_);
}


LRESULT PropWindow::OnClick(mol::Crack& msg)
{
	POINT mousepos = msg.lPoint();

	RECT r;
	getClientRect(r);
	int center = r.right*spin_/100 ;
	if ( (center-3) < mousepos.x && mousepos.x < (center+3) )
	{
		if ( !dragging_ )
		{
			dragging_ = true;
			::SetCapture(*this);			
			cur_ = ::SetCursor(::LoadCursor(0, IDC_SIZEWE));
		}
		OnEditDone();
		return 0;
	}
	
	for ( PropIter it = props_.begin(); it != props_.end(); it++)
	{
		prop::AbstractProp* p = (*it).second->hitTest(mousepos, *this);
		if ( p )
		{
			if ( inEdit_ == 0 )
			{
				p->startEdit(*this);
				inEdit_ = p;					
			}
			else
			{
				if ( inEdit_ != p )
				{
					OnEditDone();
					p->startEdit(*this);
					inEdit_ = p;	
				}
			}
			return 0;
		}
	}

	OnEditDone();
	return 0;
}

LRESULT PropWindow::OnUp(mol::Crack& msg)
{
	if ( !dragging_ )
	{
		return 0;
	}

	dragging_ = false;

	::ReleaseCapture();
	::SetCursor(cur_);

	POINT pt = msg.lPoint();

	RECT r;
	getClientRect(r);
	int w = (r.right-r.left);
	spin_ = (pt.x*100)/w;
	invalidate();

	return 0;
}

void PropWindow::OnEditDone()
{
	if ( inEdit_ != 0 )
	{
		inEdit_->stopEdit();
		inEdit_ = 0;
		invalidate();
	}
}

prop::Category& PropWindow::category(const std::wstring& cat)
{
	if ( props_.count(cat) == 0 )
	{
		props_.insert(std::make_pair(cat,new prop::Category( this, cat) ));
	}

	return *((prop::Category*)props_[cat]);
}

void PropWindow::add( prop::AbstractProp* prop)
{
	props_.insert( std::make_pair(prop->name(),prop) );
}


int PropWindow::cnt()
{
	int c = 0;
	for ( PropIter it = props_.begin(); it != props_.end(); it++)
	{
		c += (*it).second->cnt();
	}
	return c;
}

int PropWindow::spin()
{
	return spin_;
}

int PropWindow::rowHeight()
{
	return rowHeight_;
}

int PropWindow::borderWidth()
{
	return borderWidth_;
}

prop::AbstractProp* PropWindow::inEdit()
{
	return inEdit_;
}

COLORREF PropWindow::backgroundColor()
{
	return RGB(242,242,242);
}

HBRUSH PropWindow::backgroundBrush()
{
	return backgroundBrush_;
}

HBRUSH PropWindow::blackBrush()
{
	return (HBRUSH)::GetStockObject(BLACK_BRUSH);
}

prop::Category& PropWindow::addVBProperty( const std::wstring& cat, const std::wstring& n, VARIANT_BOOL& t)
{
	static std::string empty("");
	prop::Category& c = category(cat);
	c.add( new prop::VariantBoolProp(n,this,t,empty)  );
	return c;
}

prop::Category& PropWindow::addProperty( const std::wstring& cat, const std::wstring& n, mol::bstr& t)
{
	static std::string empty("");
	prop::Category& c = category(cat);
	c.add( new prop::Prop<mol::bstr>(n,this,t,empty)  );
	return c;
}

prop::Category& PropWindow::addProperty( const std::wstring& cat, const std::wstring& n, mol::bstr& t, const std::string& v)
{
	static std::string empty("");
	prop::Category& c = category(cat);
	c.add( new prop::Prop<mol::bstr>(n,this,t,v)  );
	return c;
}


namespace prop {

Category::Category( PropWindow* propWnd, const std::wstring& n)
	: AbstractProp (n, propWnd)
{
	w_ = 32;
	collapsed_ = false;
}

void Category::draw( mol::win::DCbase& dc, RECT& r, int& offset )
{

	int h = propWnd_->rowHeight();
	int o = propWnd_->borderWidth();
	int s = propWnd_->spin();

	int total_h =  (h) * ( (int)props_.size() +1 );

	if ( collapsed_)
	{
		total_h = h;
	}

	rMarker_  = mol::Rect( r.left-1, r.top+offset,  r.left-1+w_, r.top+offset+total_h);

	mol::Rect tmp (rMarker_);
	tmp.bottom = r.bottom;
	dc.fillRect( tmp, propWnd_->backgroundBrush() );

	dc.select( propWnd_->bfont() );
	rName_ = mol::Rect( r.left-1, r.top+offset,  r.right+2,  r.top+offset+h);
	dc.fillRect( rName_,propWnd_->backgroundBrush());
		
	COLORREF col = dc.setBkColor(propWnd_->backgroundColor());
	dc.textOut( r.left+o+24,r.top+offset+o,name_ );
	dc.setBkColor(col);

	dc.select( propWnd_->font() );

	int x = r.left+o;
	int y = r.top+(h/2)-3+offset;
	mol::Rect navRect( x, y, x+9, y+9 );
	dc.fillRect( navRect, (HBRUSH)::GetStockObject(WHITE_BRUSH) );
	dc.frameRect( navRect, propWnd_->blackBrush() );

	POINT pt =  { x+2 , y + 4 };
	::MoveToEx( dc, pt.x, pt.y, NULL );
	pt.x = x + 7;
	LineTo( dc, pt.x,pt.y );

	if ( !collapsed_)
	{
		POINT pt =  { x +4 , y+2 };
		::MoveToEx( dc, pt.x, pt.y, NULL );
		pt.y = y + 7;
		LineTo( dc, pt.x,pt.y );
	}


	offset += h;
	mol::Rect childRect( r.left + w_, r.top, r.right, r.bottom);

	if ( !collapsed_ )
	{
		for ( std::map<std::wstring,AbstractProp*>::iterator it = props_.begin(); it != props_.end(); it++)
		{
			(*it).second->draw( dc, childRect, offset );
		}
	}

}


AbstractProp* Category::hitTest( POINT& pos, HWND parent )
{
	if ( !collapsed_ )
	{
		for ( std::map<std::wstring,AbstractProp*>::iterator it = props_.begin(); it != props_.end(); it++)
		{
			AbstractProp* p = (*it).second->hitTest(pos, parent);
			if ( p )
				return p;
		}
	}

	if ( ::PtInRect(&rMarker_,pos) )
	{
		collapsed_ = !collapsed_;
		::InvalidateRect(parent,0,TRUE);
		return 0;
	}
	if ( ::PtInRect(&rName_,pos) ) 
	{
		collapsed_ = !collapsed_;
		::InvalidateRect(parent,0,TRUE);
		return 0;
	}

	return 0;
}

} // end namespace prop
} // end namespace mol

