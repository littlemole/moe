#include "win/layout.h"
#include "util/str.h"
#include "util/util.h"
#include "ole/Rib.h"

namespace mol {
namespace win {


unsigned int Widget::widgets()
{
	return (unsigned int)widgets_.size();
}

Widget* Widget::widget(unsigned int index)
{
	if ( !(widgets_.size() > index) )
	{
		return 0;
	}
	return widgets_[index];
}

void Widget::remove(HWND w)
{
	for ( std::vector<Widget*>::iterator it = widgets_.begin(); it != widgets_.end(); it++ )
	{
		if ( (*it)->wnd == w )
		{
			widgets_.erase(it);
			break;
		}
	}
}

} // end namespace mol::win

LayoutMgr::LayoutMgr()
:toolbar_(0),statusbar_(0),rebar_(0),hasRibbon_(false)
{}

LayoutMgr::~LayoutMgr()
{
	mol::purge(widgets_);
}

void LayoutMgr::hasRibbon(bool rib )
{
	hasRibbon_ = rib;
}

mol::Rect LayoutMgr::availClientRect(mol::Rect& r)
{
	mol::Rect clientRect_ = r;

	RECT rrb;
	RECT rtb;

	if ( mol::Ribbon::ribbon()->enabled() && hasRibbon_)
	{
		clientRect_.top           += (mol::Ribbon::ribbon()->height());   
		clientRect_.bottom        -= (mol::Ribbon::ribbon()->height());                    
	}
	else{

	if ( rebar_ && rebar_->isVisible() )
	{
		rebar_->getWindowRect(rrb);
		clientRect_.top           += (rrb.bottom-rrb.top+0);                    //shrink for rebar
		clientRect_.bottom        -= (rrb.bottom-rrb.top+0);                    //shrink for rebar
		rebar_->postMessage(WM_SIZE,0,MAKELPARAM(r.right,r.bottom));	
	}

	if ( toolbar_ && toolbar_->isVisible() )
	{
		toolbar_->getWindowRect(rtb);
		clientRect_.top           += (rtb.bottom-rtb.top)+0;                    //shrink for toolbar
		clientRect_.bottom        -= (rtb.bottom-rtb.top)+0;                    //shrink for toolbar
		toolbar_->sendMessage(WM_SIZE,0,MAKELPARAM(r.right,r.bottom));
	}
	}
	if ( statusbar_ && statusbar_->isVisible() )
	{
		clientRect_.bottom        -= statusbar_->getHeight();              //shrink for statusbar
		statusbar_->sendMessage(WM_SIZE,0,MAKELPARAM(r.right,r.bottom));
	}

	return clientRect_;
}

mol::Rect LayoutMgr::availBorderRect(mol::Rect& r)
{
	mol::Rect clientRect_ = r;

	RECT rrb;
	RECT rtb;

	if ( mol::Ribbon::ribbon()->enabled() && hasRibbon_ )
	{
		clientRect_.top           += (mol::Ribbon::ribbon()->height());   
	}
	else{

	if ( rebar_ && rebar_->isVisible() )
	{
		rebar_->getWindowRect(rrb);
		clientRect_.top           += (rrb.bottom-rrb.top+0);                    //shrink for rebar
	}

	if ( toolbar_ && toolbar_->isVisible() )
	{
		toolbar_->getWindowRect(rtb);
		clientRect_.top           += (rtb.bottom-rtb.top+0);                    //shrink for toolbar
	}

	}

	if ( statusbar_ && statusbar_->isVisible() )
	{
		clientRect_.bottom        -= statusbar_->getHeight();              //shrink for statusbar
	}

	return clientRect_;
}


LRESULT LayoutMgr::OnSize( UINT msg, WPARAM wParam, LPARAM lParam)
{
	if ( wParam == SIZE_MINIMIZED )
		return 0;

	mol::Rect clientRect_ = mol::Rect(0,0,0,0);

	// get new width and height
	clientRect_.right  = LOWORD (lParam) ;
	clientRect_.bottom = HIWORD (lParam) ;

	clientRect_ = availClientRect(clientRect_);

	layout(clientRect_);

	return 0;
}

void LayoutMgr::resize(WPARAM wParam, LPARAM lParam)
{
	if ( rebar_ )
	{
		rebar_->postMessage(WM_SIZE,wParam,lParam);	
	}

	if ( toolbar_ )
	{
		toolbar_->sendMessage(WM_SIZE,wParam,lParam);
	}

	if ( statusbar_ )
	{
		statusbar_->sendMessage(WM_SIZE,wParam,lParam);
	}
}

void LayoutMgr::layout( mol::Rect& r )
{
	for ( std::vector<Widget*>::iterator it = widgets_.begin(); it != widgets_.end(); it++ )
	{
		if ( ::IsWindow((*it)->wnd) )
			if ( !::IsWindowVisible((*it)->wnd) )
				continue;
		(*it)->layout(r);
	}
}

void LayoutMgr::addToolBar( mol::ToolBar* tb )
{
	toolbar_ = tb;
}
void LayoutMgr::addRebar( mol::ReBar* rb )
{
	rebar_ = rb;
}
void LayoutMgr::addStatusBar( mol::StatusBar* sb )
{
	statusbar_ = sb;
}

BorderLayout::BorderLayoutWidget::BorderLayoutWidget( HWND w, BORDER b, mol::Rect p)
: border(b)
{
	wnd = w;
	padding = p;
}

void BorderLayout::BorderLayoutWidget::layout( mol::Rect& r ) 
{
	mol::Rect retRect(r);
	mol::Rect destRect(r);
	mol::Rect clientRect;

	::GetWindowRect(wnd,&clientRect);

	switch ( border )
	{
		case FILL:
		{
			destRect.left += padding.left;
			destRect.top += padding.top;
			destRect.right -= (padding.left+padding.right);
			destRect.bottom -= (padding.top+padding.bottom);
			break;
		}
		case NORTH:
		{
			destRect.left += padding.left;
			destRect.top += padding.top;
			destRect.right -= (padding.left+padding.right);

			destRect.bottom = clientRect.bottom-clientRect.top;

			r.top += destRect.bottom+padding.bottom+padding.top;
			r.bottom -= (destRect.bottom+padding.bottom+padding.top);
			break;
		}
		case EAST:
		{

			destRect.left = r.left+r.right-(clientRect.right-clientRect.left)-padding.right;
			destRect.right = clientRect.right-clientRect.left;
			destRect.top += padding.top;
			destRect.bottom -= (padding.top+padding.bottom);

			r.right += destRect.left-padding.left;

			break;
		}
		case SOUTH:
		{
			destRect.top = r.top+r.bottom-(clientRect.bottom-clientRect.top)-padding.bottom;
			destRect.bottom = clientRect.bottom-clientRect.top;
			destRect.left += padding.left;
			destRect.right -= (padding.left+padding.right);

			r.bottom -= (destRect.bottom);
			break;
		}
		case WEST:
		{
			destRect.left += padding.left;
			destRect.top += padding.top;
			destRect.bottom  -= (padding.top+padding.bottom);

			destRect.right = clientRect.right-clientRect.left;

			r.left += destRect.right+padding.right+padding.left;
			r.right -= (destRect.right+padding.right+padding.left);
			break;
		}
	}
	::MoveWindow(wnd,destRect.left,destRect.top,destRect.right,destRect.bottom,TRUE);
	::InvalidateRect(wnd,0,TRUE);
}

void BorderLayout::add( HWND w, BORDER b, mol::Rect padding )
{
	widgets_.push_back( new BorderLayoutWidget(w,b,padding) );
}

RowLayout::RowLayoutWidget::RowLayoutWidget( HWND w, STYLE s, mol::Rect p)
: style(s)
{
	wnd = w;
	padding = p;
}

void RowLayout::RowLayoutWidget::layout( mol::Rect& r ) 
{
	if ( style == FILL )
	{
		mol::Rect destRect(r);
		destRect.left += padding.left;
		destRect.top += padding.top;

		destRect.right -= (padding.left+padding.right);
		destRect.bottom -= (padding.top+padding.bottom);

		::MoveWindow(wnd,destRect.left,destRect.top,destRect.right,destRect.bottom,TRUE);
	}
	else
	{
		mol::Rect rect;
		::GetWindowRect(wnd,&rect);
		mol::Rect destRect(r);

		destRect.right = rect.right-rect.left;
		destRect.bottom = rect.bottom-rect.top;

		destRect.left += padding.left;
		destRect.top += padding.top;

		destRect.right -= (padding.left+padding.right);
		destRect.bottom -= (padding.top+padding.bottom);

		if ( rect.right-rect.left > r.right )
		{
		}
		else
		{
			int w = (r.right-(rect.right-rect.left))/2;
			destRect.left += w;
			
		}
		if ( rect.bottom-rect.top > r.bottom )
		{
		}
		else
		{
			int h = (r.bottom-(rect.bottom-rect.top))/2;
			destRect.top += h;					
		}
		::MoveWindow(wnd,destRect.left,destRect.top,destRect.right,destRect.bottom,TRUE);
	}
	::InvalidateRect(wnd,0,TRUE);
}

void RowLayout::add( HWND w, STYLE s, mol::Rect padding  )
{
	widgets_.push_back( new RowLayoutWidget(w,s,padding) );
}

void RowLayout::layout( mol::Rect& r )
{
	mol::Rect destRect(r);
	int w = 0;
	int h = 0;
	int s = 0;

	for ( std::vector<Widget*>::iterator it = widgets_.begin(); it != widgets_.end(); it++ )
	{
		if ( ::IsWindow((*it)->wnd) )
			if ( !::IsWindowVisible((*it)->wnd) )
				continue;
		s++;
	}

	switch( type )
	{
		case HORIZONTAL :
		{
			w = (int)((r.right) / widgets_.size());												
			break;
		}
		case VERTICAL :
		{
			h = (int)((r.bottom) / widgets_.size());												
			break;
		}
	}
	int i = 0;
	for ( std::vector<Widget*>::iterator it = widgets_.begin(); it != widgets_.end(); it++ )
	{
		if ( ::IsWindow((*it)->wnd) )
			if ( !::IsWindowVisible((*it)->wnd) )
				continue;

		destRect = r;
		destRect.left += i*w;
		destRect.top += i*h;
		if ( w )
			destRect.right = w;

		if ( h )
			destRect.bottom = h;

		destRect.left += padding.left;
		destRect.top += padding.top;

		destRect.right -= (padding.left+padding.right);
		destRect.bottom -= (padding.top+padding.bottom);

		(*it)->layout(destRect);
		i++;
	}
}

FillLayout::FillLayoutWidget::FillLayoutWidget( HWND w, mol::Rect p)
: BorderLayoutWidget(w,mol::BorderLayout::FILL,p)
{
}

void FillLayout::FillLayoutWidget::layout( mol::Rect& r ) 
{
	mol::Rect retRect(r);
	mol::Rect destRect(r);
	mol::Rect clientRect;

	::GetWindowRect(wnd,&clientRect);

	destRect.left += padding.left;
	destRect.top += padding.top;
	destRect.right -= (padding.left+padding.right);
	destRect.bottom -= (padding.top+padding.bottom);

	::MoveWindow(wnd,destRect.left,destRect.top,destRect.right,destRect.bottom,TRUE);
	::InvalidateRect(wnd,0,TRUE);
}

void FillLayout::layout( mol::Rect& r )
{
	for ( std::vector<Widget*>::iterator it = widgets_.begin(); it != widgets_.end(); it++ )
	{
		(*it)->layout(r);
	}
}
void FillLayout::add( HWND w,  mol::Rect padding)
{
	widgets_.push_back( new FillLayoutWidget(w,padding) );
}


} // end namespace mol