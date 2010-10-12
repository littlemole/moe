// ColorPickerDlg.cpp : implementation file
//

#define _CRT_SECURE_NO_DEPRECATE 1
#include "stdafx.h"
#include "ColorPickerDlg.h"
#include <cmath>
#include <cstdio>
#include "win/Res.h"

#define IN_CIRCLE	1
#define IN_BRIGHT	2
#define IN_NOTHING	0

const int COL_RECT_WIDTH = 5;

const int RADIUS       = 100;
const double PI        = 3.14159265358;
const double BAD_SLOPE = 1000000.0;

const int RED          = 0;
const int GREEN        = 1;
const int BLUE         = 2;

double RAD2DEG(double x)		{ return ((180.0 * (x))/PI);   };
double DEG2RAD(double x)		{ return ((x) * PI)/180.0 ;    };
double TOSCALE(double x)		{ return ((x)*RADIUS)/255.0 ;  };
double SCALETOMAX(double x)		{ return (((x)*255.0)/RADIUS); };



int    Distance(POINT pt1,POINT pt2);
POINT  PointOnLine(POINT pt1,POINT p2,int len,int maxlen);
double Slope(POINT pt1,POINT pt2);
double FindC(LineDesc& l); 
POINT  Intersection(LineDesc desc1,LineDesc desc2);
double AngleFromPoint(POINT pt,POINT center);
POINT  PtFromAngle(double angle,double sat,POINT center);

COLORREF hex2rgb( const char* hex );
const char* rgb2hex( COLORREF col );


/////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////
// ColorPickerDlg dialog

ColorPickerDlg::ColorPickerDlg( )
{
	init(RGB(255,135,80));
}

ColorPickerDlg::ColorPickerDlg(COLORREF c  )
{
	init(c);
}

ColorPickerDlg::ColorPickerDlg(const std::string& c )
{
	COLORREF col = hex2rgb(c.c_str());
	init(col);
}

void ColorPickerDlg::init(COLORREF c)
{
	if ( bInitOver == TRUE )
		return;

	vertex = mol::Point( 102,108);
	top    = mol::Point( 102,9 );
	left   = mol::Point( 23,147 );
	right  = mol::Point( 181,147 );

	color.r = GetRValue(c);
	color.g = GetGValue(c);
	color.b = GetBValue(c);

	oldColor   = color;
	hsvColor   = color.toHSV();
	bInMouse   = FALSE;
	bInitOver  = FALSE;
	bInDrawAll = FALSE;
	rgbBitmap  = 0;
	hsbBitmap  = 0;
	isCaptured = FALSE;
	oldCursor  = ::LoadCursor(0, IDC_ARROW );
}

ColorPickerDlg::~ColorPickerDlg()
{
	if(rgbBitmap)
		::DeleteObject(rgbBitmap);
	if(hsbBitmap)
		::DeleteObject(hsbBitmap);
	::DeleteDC(memDC);
}


LRESULT ColorPickerDlg::doModal   ( HWND hWndParent, COLORREF col )
{
	init(col);
	return mol::win::Dialog::doModal(IDD_DIALOG_COLORS,hWndParent);
}


LRESULT ColorPickerDlg::doModeless   ( HWND hWndParent, COLORREF col )
{
	init(col);
	return (LRESULT) mol::win::Dialog::doModeless(IDD_DIALOG_COLORS,hWndParent);
}

LRESULT ColorPickerDlg::OnInitDialog( UINT msg, WPARAM wParam, LPARAM lParam )
{
	if ( bInitOver == TRUE )
		return TRUE;

	::GetWindowRect(getDlgItem(IDC_STATIC_RGB_RECT),&rgbRect);
	::GetWindowRect(getDlgItem(IDC_STATIC_HSB_RECT),&hsbRect);

	screen2Client(rgbRect);
	screen2Client(hsbRect);

	::GetWindowRect(getDlgItem(IDC_STATIC_OLD),&oldColorRect);
	::GetWindowRect(getDlgItem(IDC_STATIC_NEW),&newColorRect);

	screen2Client(oldColorRect);
	screen2Client(newColorRect);

	HDC dc = ::GetWindowDC(::GetDesktopWindow());
	SIZE bmSize;
	
//	Set Up HSB

	memDC = ::CreateCompatibleDC(dc);
	
	loadMappedBitmap(hsbBitmap,IDB_BITMAP_HSB,bmSize);
	hsbWidth = bmSize.cx;
	hsbHeight = bmSize.cy;

	::InflateRect(&hsbRect,-5,-5);
	hsbRect.top += 20;
	hsbRect.left += 10;

	POINT p = { RADIUS,RADIUS };
	centre = p;
	centre.x += hsbRect.left;
	centre.y += hsbRect.top;

	brightRect = mol::Rect(hsbRect.left+hsbWidth+20,hsbRect.top,hsbRect.left+hsbWidth+20+20,hsbRect.top + hsbHeight);
	createBrightDIB();
	calcRects();
	setDIBPalette();

//	Set Up RGB
	loadMappedBitmap(rgbBitmap,IDB_BITMAP_RGB,bmSize);
	rgbWidth = bmSize.cx;
	rgbHeight = bmSize.cy;

	::InflateRect(&rgbRect,-5,-5);
	rgbRect.top+=20;
	rgbRect.left+=2;
	POINT pt;
	pt.x = rgbRect.left;
	pt.y = rgbRect.top;

	top.x    += pt.x;
	top.y    += pt.y;
	left.x   += pt.x;
	left.y   += pt.y;
	right.x  += pt.x;
	right.y  += pt.y;
	vertex.x += pt.x;
	vertex.y += pt.y;

	redLen   = Distance(vertex,top);
	greenLen = Distance(vertex,left);
	blueLen  = Distance(vertex,right);

	calcSlopes();
	calcCuboid();

	setSpinVals();
	setEditVals();

	bInitOver = TRUE;

	::ReleaseDC(::GetDesktopWindow(),dc);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}



/////////////////////////////////////////////////////////////////////////////
// ColorPickerDlg message handlers



LRESULT    ColorPickerDlg::OnLButtonDown( UINT msg, WPARAM wParam, LPARAM lParam )
{
	if ( isCaptured )
		return ::DefWindowProc(hWnd_, msg, wParam, lParam);	

	mol::Crack mess(msg,wParam,lParam);
	POINT point = mess.lPoint();
	
	if ( ::PtInRect(&oldColorRect,point) )
	{
		isCaptured = TRUE;

		::SetCapture(*this);
		oldCursor = ::SetCursor(::LoadCursor(0,IDC_CROSS));

		return 0;
	}


	if( ::PtInRect(&hsbRect, point) )
	{
		bInMouse = FALSE;
		if(inCircle(point))
		{
			nMouseIn = IN_CIRCLE;
		}
		else
		if(inBright(point))
		{
			nMouseIn = IN_BRIGHT;
		}
		else
		{
			nMouseIn = IN_NOTHING;
		}
		if(nMouseIn)
		{
			::SetCapture(*this);
			trackPoint(point);
		}
	}
	else
		if(::PtInRect(&rgbRect,point) )
	{
		nMouseIn = IN_NOTHING;
		if(::PtInRect(&(rects[RED]),point) )
		{
			::SetCapture(*this);
			bInMouse = TRUE;
			nIndex = RED;
		}
		else
			if(::PtInRect(&(rects[GREEN]),point) )
		{
			SetCapture(*this);
			bInMouse = TRUE;
			nIndex = GREEN;
		}
		else
			if(::PtInRect(&(rects[BLUE]),point) )
		{
			SetCapture(*this);
			bInMouse = TRUE;
			nIndex = BLUE;
		}
	}
	return ::DefWindowProc(hWnd_, msg, wParam, lParam);	
}

LRESULT    ColorPickerDlg::OnLButtonUp( UINT msg, WPARAM wParam, LPARAM lParam )
{
	if ( isCaptured )
	{
		ReleaseCapture();
		::SetCursor(oldCursor);
		isCaptured = FALSE;

		mol::DC dc(*this);
		drawFilledColor(dc,newColorRect,color.color());

		return ::DefWindowProc(hWnd_, msg, wParam, lParam);	
	}
	if(GetCapture() == *this)
	{
		ReleaseCapture();
		bInMouse = FALSE;
		mol::DC dc(*this);
		drawFilledColor(dc,newColorRect,color.color());
	}
	return ::DefWindowProc(hWnd_, msg, wParam, lParam);	
}

LRESULT ColorPickerDlg::OnMouseMove( UINT msg, WPARAM wParam, LPARAM lParam )
{
	mol::Crack mess(msg,wParam,lParam);
	POINT point = mess.lPoint();

	if ( isCaptured )
	{
		::ClientToScreen(*this,&point);
		HDC hScreenDC = ::GetDC(NULL);			
		COLORREF crColor = ::GetPixel(hScreenDC,point.x,point.y);
		::ReleaseDC(NULL,hScreenDC);	

		color.r = GetRValue(crColor);
		color.g = GetGValue(crColor);
		color.b = GetBValue(crColor);
		hsvColor = color.toHSV();

		if(bInitOver)
		{
			drawAll();
		}
		mol::DC dc(*this);
		drawFilledColor(dc,oldColorRect,color.color());	
		return 0;
	}

	if(GetCapture() == *this && nMouseIn)
	{
		trackPoint(point);
	}
	else
	if(GetCapture() == *this && bInMouse)
	{
	double val;
	BOOL bChange = FALSE;
		if(nIndex == RED)
		{
			if(point.y > vertex.y)
			{
				point.y = vertex.y;
			}
			point.x = vertex.x;
			val = Distance(point,vertex);
			if(val > redLen)
			{
				val = redLen;
			}
			mol::DC dc(*this);
			drawLines(dc);
			val = (val/redLen)*255;
			color.r = (int)val;
			POINT pt;
			pt = PointOnLine(vertex,top,(color.r*redLen)/255,redLen);
			rects[RED] = mol::Rect(pt.x - COL_RECT_WIDTH ,pt.y-COL_RECT_WIDTH ,pt.x+COL_RECT_WIDTH ,pt.y+COL_RECT_WIDTH );
			calcCuboid();
			drawLines(dc);
			drawFilledColor(dc,newColorRect,color.color());
			bChange = TRUE;
		}
		else
		if(nIndex == GREEN)
		{
			if(point.x > vertex.x)
			{
				point.x = vertex.x;
			}
			point.y = rects[GREEN].top + COL_RECT_WIDTH;
			val = Distance(point,vertex);
			if(val > greenLen)
			{
				val = greenLen;
			}
			mol::DC dc (*this);
			drawFilledColor(dc,newColorRect,color.color());
			drawLines(dc);
			val = (val/greenLen)*255;
			color.g = (int)val;
			POINT pt;
			pt = PointOnLine(vertex,left,(color.g*greenLen)/255,greenLen);
			rects[GREEN] = mol::Rect(pt.x - COL_RECT_WIDTH ,pt.y-COL_RECT_WIDTH ,pt.x+COL_RECT_WIDTH ,pt.y+COL_RECT_WIDTH);
			calcCuboid();
			drawLines(dc);
			bChange = TRUE;
		}
		else
		if(nIndex == BLUE)
		{
			if(point.x < vertex.x)
			{
				point.x = vertex.x;
			}
			point.y = rects[BLUE].top + COL_RECT_WIDTH;
			val = Distance(point,vertex);
			if(val > blueLen)
			{
				val = blueLen;
			}
			mol::DC dc(*this);
			drawLines(dc);
			val = (val/blueLen)*255;
			color.b = (int)val;
			POINT pt;
			pt = PointOnLine(vertex,right,(color.b*greenLen)/255,blueLen);
			rects[BLUE] = mol::Rect(pt.x - COL_RECT_WIDTH ,pt.y-COL_RECT_WIDTH ,pt.x+COL_RECT_WIDTH ,pt.y+COL_RECT_WIDTH );
			calcCuboid();
			drawLines(dc);
			drawFilledColor(dc,newColorRect,color.color());
			bChange = TRUE;
		}
		if(bChange)
		{
			hsvColor = color.toHSV();
			setEditVals();
			mol::DC dc(*this);
			drawMarkers(dc);
			drawFilledColor(dc,newColorRect,color.color());
			calcRects();
			setDIBPalette();

			invalidateRect(&brightRect,FALSE);
			drawHSB(dc);
		}
	}
	return ::DefWindowProc(hWnd_, msg, wParam, lParam);	
}

LRESULT ColorPickerDlg::OnPaint( UINT msg, WPARAM wParam, LPARAM lParam )
{
	mol::PaintDC dc(*this); // device context for painting

	//drawFilledColor(dc,oldColorRect,oldColor.color());
	drawFilledColor(dc,newColorRect,color.color());
	drawHSB(dc);
	drawRGB(dc);
	return 0;
}

LRESULT ColorPickerDlg::OnButtonPressed( UINT msg, WPARAM wParam, LPARAM lParam )
{
	mol::Crack mess(msg,wParam,lParam);
	if ( mess.id() != IDOK )
	{
		color = oldColor;
	}
	this->endDlg(mess.id());
	return TRUE;
}

LRESULT ColorPickerDlg::OnChangeEditBlue( UINT msg, WPARAM wParam, LPARAM lParam )
{
	int b;
	getDlgItemInt(IDC_EDIT_BLUE,b);
	if( b != color.b && bInitOver)
	{
		color.b = b;
		if(color.b < 0) color.b = 0;
		if(color.b > 255) color.b = 255;
		hsvColor = color.toHSV();
		mol::DC dc(*this);
		drawFilledColor(dc,newColorRect,color.color());	
		drawAll();
	}
	return TRUE;
}

LRESULT ColorPickerDlg::OnChangeEditGreen( UINT msg, WPARAM wParam, LPARAM lParam )
{
	int g;
	getDlgItemInt(IDC_EDIT_GREEN,g);
	if(g != color.g && bInitOver)
	{
		color.g = g;
		if(color.g < 0) color.g = 0;
		if(color.g > 255) color.g = 255;
		hsvColor = color.toHSV();
		mol::DC dc(*this);
		drawFilledColor(dc,newColorRect,color.color());	
		drawAll();
	}
	return TRUE;
}


LRESULT ColorPickerDlg::OnChangeEditRed( UINT msg, WPARAM wParam, LPARAM lParam )
{
	int r;
	getDlgItemInt(IDC_EDIT_RED,r);
	if(r != color.r && bInitOver)
	{
		color.r = r;
		if(color.r < 0) color.r = 0;
		if(color.r > 255) color.r = 255;
		hsvColor = color.toHSV();
		mol::DC dc(*this);
		drawFilledColor(dc,newColorRect,color.color());
		drawAll();
	}
	return TRUE;
}

LRESULT ColorPickerDlg::OnChangeEditHue( UINT msg, WPARAM wParam, LPARAM lParam )
{
	int h;
	getDlgItemInt(IDC_EDIT_HUE,h);
	if(h != hsvColor.h && bInitOver)
	{
		hsvColor.h = h;
		if(hsvColor.h < 0) hsvColor.h = 0;
		if(hsvColor.h > 359) hsvColor.h = 359;
		color = hsvColor.toRGB();
		mol::DC dc(*this);
		drawFilledColor(dc,newColorRect,color.color());
		drawAll();
	}
	return TRUE;
}

LRESULT ColorPickerDlg::OnChangeEditSat( UINT msg, WPARAM wParam, LPARAM lParam )
{
	int s;
	getDlgItemInt(IDC_EDIT_SAT,s);
	if(s != hsvColor.s && bInitOver)
	{
		hsvColor.s = s;
		if(hsvColor.s < 0)   hsvColor.s = 0;
		if(hsvColor.s > 255) hsvColor.s = 255;
		color = hsvColor.toRGB();
		mol::DC dc(*this);
		drawFilledColor(dc,newColorRect,color.color());
		drawAll();
	}
	return TRUE;
}

LRESULT ColorPickerDlg::OnChangeEditVal( UINT msg, WPARAM wParam, LPARAM lParam )
{
	int v;
	getDlgItemInt(IDC_EDIT_VAL,v);
	if(v != hsvColor.v && bInitOver)
	{
		hsvColor.v = v;
		if(hsvColor.v < 0)   hsvColor.v = 0;
		if(hsvColor.v > 255) hsvColor.v = 255;
		color = hsvColor.toRGB();
		mol::DC dc(*this);
		drawFilledColor(dc,newColorRect,color.color());
		drawAll();
	}
	return TRUE;
}

LRESULT ColorPickerDlg::OnChangeEditHex( UINT msg, WPARAM wParam, LPARAM lParam )
{
	mol::string hex;
	getDlgItemText(IDC_EDIT_HEX,hex);
	if ( hex.size() == 0 || hex[0] != _T('#') )
	{
		setDlgItemText(IDC_EDIT_HEX, _T("#"));
	}
	else if ( hex.size() > 6 )
	{
		COLORREF col = hex2rgb(mol::tostring(hex).c_str());
		if( color.color() != col && bInitOver)
		{
			color.r = GetRValue(col);
			color.g = GetGValue(col);
			color.b = GetBValue(col);
			hsvColor = color.toHSV();

			mol::DC dc(*this);
			drawFilledColor(dc,newColorRect,color.color());
			drawAll();
		}
	}
	return TRUE;
}

LRESULT ColorPickerDlg::OnSysColorChange( UINT msg, WPARAM wParam, LPARAM lParam )
{
	SIZE size;
	loadMappedBitmap(hsbBitmap,IDB_BITMAP_HSB,size);
	loadMappedBitmap(rgbBitmap,IDB_BITMAP_RGB,size);
	return 0;
}

//helpers

void ColorPickerDlg::drawMarkers(HDC dc)
{
	
	if(currentRect.right-currentRect.left>0)
	{
		HPEN   oldPen   = 0;
		HBRUSH oldBrush = 0;
		int oldMode;
		mol::Rect cr = currentRect;

		oldPen   = (HPEN)  ::SelectObject(dc,::GetStockObject(WHITE_PEN));
		oldBrush = (HBRUSH)::SelectObject(dc,::GetStockObject(NULL_BRUSH));
		oldMode  =         ::SetROP2(dc,R2_XORPEN);

		::Rectangle(dc,cr.left,cr.top,cr.right,cr.bottom);

		HPEN pen = ::CreatePen(PS_SOLID,2,RGB(255,255,255));
		::SelectObject(dc,pen);

		::Rectangle(dc,brightMark.left,brightMark.top,brightMark.right,brightMark.bottom);

		//cleanup GDI
		::SelectObject(dc,oldPen);
		::SelectObject(dc,oldBrush);
		::SetROP2(dc,oldMode);
		::DeleteObject(pen);
	}
}

BOOL ColorPickerDlg::inCircle(POINT pt)
{
	return Distance(pt,centre) <= RADIUS;
}

BOOL ColorPickerDlg::inBright(POINT pt)
{
	RECT r = brightRect;
	::InflateRect(&r,4,0);
	return ::PtInRect(&r,pt);
}

void ColorPickerDlg::trackPoint(POINT pt)
{
	if ( isCaptured )
		return;

	if(nMouseIn == IN_CIRCLE)
	{
		mol::DC dc(*this);
		drawMarkers(dc);
		
		hsvColor.h = (int)RAD2DEG(AngleFromPoint(pt,centre));
		if(hsvColor.h < 0)
		{
			hsvColor.h += 360;
		}
		hsvColor.s = (int)SCALETOMAX(Distance(pt,centre));
		if(hsvColor.s > 255) hsvColor.s = 255;

		setDIBPalette();
		calcRects();

		invalidateRect(&brightRect,FALSE);

		drawMarkers(dc);

		color = hsvColor.toRGB();
		setEditVals();
		drawLines(dc);
		calcCuboid();
		drawRGB(dc);
	}
	else
	if(nMouseIn == IN_BRIGHT)
	{
		double d;
		d = brightRect.bottom - pt.y;
		d *= 255;
		d /= (brightRect.bottom-brightRect.top);
		if(d < 0 ) d = 0;
		if(d > 255) d = 255;
		mol::DC dc(*this);
		drawMarkers(dc);
		hsvColor.v = (int)d;
		calcRects();
		drawMarkers(dc);

		color = hsvColor.toRGB();
		setEditVals();
		drawLines(dc);
		calcCuboid();
		drawRGB(dc);
	}
}


void ColorPickerDlg::createBrightDIB()
{
	mol::win::DIB& d = brightDIB;
	d.create( brightRect.right-brightRect.left,brightRect.bottom-brightRect.top ,8);
	for(int i=0; i < d.height(); i++)
	{
		memset(d.get_line_ptr(i),i,d.width());
	}
}

void ColorPickerDlg::setDIBPalette()
{
	BYTE palette[768],*p;
	HSVType h = hsvColor;
	double d;
	d = 255.0/(brightRect.bottom-brightRect.top);
	p = palette;
	for(int i=brightRect.bottom-brightRect.top-1; i >= 0 ;i--,p+=3)
	{
		h.v = (int)((double)i * d);
		RGBType rgb = h.toRGB();
		p[0] = rgb.r;
		p[1] = rgb.g;
		p[2] = rgb.b;
	}
	brightDIB.setPalette(palette);
}

void ColorPickerDlg::calcRects()
{
	POINT pt;
	pt = PtFromAngle(hsvColor.h,hsvColor.s,centre);
	currentRect = mol::Rect(pt.x - COL_RECT_WIDTH,pt.y - COL_RECT_WIDTH,pt.x+COL_RECT_WIDTH,pt.y + COL_RECT_WIDTH);	
	
	int y;
	y = (int)(((double)hsvColor.v/255)*(brightRect.bottom-brightRect.top)); 	
	y = brightRect.bottom - y;
	brightMark = mol::Rect(brightRect.left - 2, y - 4, brightRect.right+2,y+4);
}

void ColorPickerDlg::drawHSB(HDC dc)
{
	if(hsbBitmap)
	{
		HBITMAP oldBitmap  = (HBITMAP)::SelectObject(memDC,hsbBitmap);
		::BitBlt(dc,hsbRect.left,hsbRect.top,hsbWidth,hsbHeight,memDC,0,0,SRCCOPY);

		brightDIB.bitBlt(dc,brightRect.left,brightRect.top,brightRect.right-brightRect.left,(brightRect.bottom-brightRect.top),0,0);
		drawMarkers(dc);
		::SelectObject(memDC,oldBitmap);
	}
}

void ColorPickerDlg::drawRGB(HDC dc)
{
	if(rgbBitmap)
	{
		HBITMAP oldBitmap  = (HBITMAP)::SelectObject(memDC,rgbBitmap);
		::BitBlt( dc,rgbRect.left,rgbRect.top,rgbWidth,rgbHeight,memDC,0,0,SRCCOPY);
		drawLines(dc);
		::SelectObject(memDC,oldBitmap);
	}
}

void ColorPickerDlg::drawLines(HDC dc)
{
	POINT pt[3];
	pt[0] = PointOnLine(vertex,top,(color.r*redLen)/255,redLen);
	pt[1] = PointOnLine(vertex,left,(color.g*greenLen)/255,greenLen);
	pt[2] = PointOnLine(vertex,right,(color.b*blueLen)/255,blueLen);
	COLORREF col = RGB(255,255,255);
	RECT cr;
	for(int i=0; i < 3; i++)
	{
		cr = mol::Rect(pt[i].x - COL_RECT_WIDTH ,pt[i].y-COL_RECT_WIDTH ,pt[i].x+COL_RECT_WIDTH ,pt[i].y+COL_RECT_WIDTH);
		rects[i] = cr;
		drawXorRect(dc,cr);
	}
	HPEN oldPen = 0;
	int oldMode;
	oldPen  = (HPEN)::SelectObject(dc, ::GetStockObject(WHITE_PEN));
	oldMode = ::SetROP2(dc,R2_XORPEN);
/*
Draw the following lines :
	
	1 -2 
	2 -3
	3 - 4
	4- 5
	5 -2
	5 - 6
	6-7
	7-4
*/
	::MoveToEx(dc,cuboid[1].x,cuboid[1].y,0);
	::LineTo(dc,cuboid[2].x,cuboid[2].y);
	::LineTo(dc,cuboid[3].x,cuboid[3].y);
	::LineTo(dc,cuboid[4].x,cuboid[4].y);
	::LineTo(dc,cuboid[5].x,cuboid[5].y);
	::LineTo(dc,cuboid[2].x,cuboid[2].y);

	::MoveToEx(dc,cuboid[5].x,cuboid[5].y,0);
	::LineTo(dc,cuboid[6].x,cuboid[6].y);
	::LineTo(dc,cuboid[7].x,cuboid[7].y);
	::LineTo(dc,cuboid[4].x,cuboid[4].y);

	::MoveToEx(dc,cuboid[1].x,cuboid[1].y,0);
	::LineTo(dc,cuboid[6].x,cuboid[6].y);

	::SelectObject(dc,oldPen);
	::SetROP2(dc,oldMode);

	//drawFilledColor(dc,newColorRect,color.color());
}


void ColorPickerDlg::drawXorRect(HDC dc, RECT& cr)
{
	HPEN pen,oldPen;
	HBRUSH oldBrush;
	int oldMode;

	pen = ::CreatePen(PS_SOLID,1,RGB(255,255,255));

	oldPen   = (HPEN)  ::SelectObject(dc,pen);
	oldBrush = (HBRUSH)::SelectObject(dc,::GetStockObject(NULL_BRUSH));
	oldMode  =         ::SetROP2(dc,R2_XORPEN);
	::Rectangle(dc, cr.left,cr.top,cr.right,cr.bottom);
	::SetROP2(dc,oldMode);
	::SelectObject(dc,oldPen);
	::SelectObject(dc,oldBrush);
	::DeleteObject(pen);
}

void ColorPickerDlg::calcSlopes()
{
	lines[RED].slope   = Slope(top,vertex);
	lines[GREEN].slope = Slope(left,vertex);
	lines[BLUE].slope  = Slope(right,vertex);

	int i;
	for(i=0; i < 3; i++)
	{
		lines[i].x = vertex.x;
		lines[i].y = vertex.y;
		lines[i].c = FindC(lines[i]);
	}
}


/*

  Cuboid points
   0 = vertex
   1 = Red Axis
   2 = Red Green Intersection
   3 = Green Axis
   4 = Blue Green Intersection
   5 = Blue Green Red Intersection
   6 = Red Blue Intersection
   7 = Blue Axis

  Draw the following lines :
	
	1 -2 
	2 -3
	3 - 4
	4- 5
	5 -2
	5 - 6
	6-7
	7-4
*/

void ColorPickerDlg::calcCuboid()
{
	double rLen,gLen,bLen;
	rLen = (double)(color.r*redLen)/255;
	gLen = (double)(color.g*greenLen)/255;
	bLen = (double)(color.b*blueLen)/255;
	LineDesc l[12];

	cuboid[0] = vertex;
	cuboid[1] = PointOnLine(vertex,top,(int)rLen,redLen);
	cuboid[3] = PointOnLine(vertex,left,(int)gLen,greenLen);
	cuboid[7] = PointOnLine(vertex,right,(int)bLen,blueLen);

	l[0] = lines[RED];
	l[1] = lines[GREEN];
	l[2] = lines[BLUE];

	l[3].slope = lines[GREEN].slope;
	l[3].x = cuboid[1].x;
	l[3].y = cuboid[1].y;
	l[3].c = FindC(l[3]);
	
	l[4].slope = lines[RED].slope;
	l[4].x = cuboid[3].x;
	l[4].y = cuboid[3].y;
	l[4].c = FindC(l[4]);

	l[5].slope = lines[BLUE].slope;
	l[5].x = cuboid[3].x;
	l[5].y = cuboid[3].y;
	l[5].c = FindC(l[5]);
	
	l[6].slope = lines[GREEN].slope;
	l[6].x = cuboid[7].x;
	l[6].y = cuboid[7].y;
	l[6].c = FindC(l[6]);

	l[10].slope = lines[BLUE].slope;
	l[10].x = cuboid[1].x;
	l[10].y = cuboid[1].y;
	l[10].c = FindC(l[10]);
	
	l[11].slope = lines[RED].slope;
	l[11].x = cuboid[7].x;
	l[11].y = cuboid[7].y;
	l[11].c = FindC(l[11]);

	cuboid[2] = Intersection(l[3],l[4]);
	cuboid[4] = Intersection(l[5],l[6]);
	cuboid[6] = Intersection(l[10],l[11]);

	l[7].slope = lines[RED].slope;
	l[7].x = cuboid[4].x;
	l[7].y = cuboid[4].y;
	l[7].c = FindC(l[7]);
	
	l[8].slope = lines[BLUE].slope;
	l[8].x = cuboid[2].x;
	l[8].y = cuboid[2].y;
	l[8].c = FindC(l[8]);

	cuboid[5] = Intersection(l[7],l[8]);
		
}

void ColorPickerDlg::setSpinVals()
{
	sendDlgItemMsg(IDC_SPIN_RED,  UDM_SETRANGE32,0,255);
	sendDlgItemMsg(IDC_SPIN_GREEN,UDM_SETRANGE32,0,255);
	sendDlgItemMsg(IDC_SPIN_BLUE, UDM_SETRANGE32,0,255);

	sendDlgItemMsg(IDC_SPIN_HUE,  UDM_SETRANGE32,0,360);
	sendDlgItemMsg(IDC_SPIN_SAT,  UDM_SETRANGE32,0,255);
	sendDlgItemMsg(IDC_SPIN_VAL,  UDM_SETRANGE32,0,255);
}

void ColorPickerDlg::setEditVals()
{
	sendDlgItemMsg(IDC_SPIN_RED,    UDM_SETPOS32,0,color.r);
	sendDlgItemMsg(IDC_SPIN_GREEN,  UDM_SETPOS32,0,color.g);
	sendDlgItemMsg(IDC_SPIN_BLUE,   UDM_SETPOS32,0,color.b);

	mol::string col = mol::toString(rgb2hex(color.color()));
	setDlgItemText(IDC_EDIT_HEX,col);

	sendDlgItemMsg(IDC_SPIN_HUE,    UDM_SETPOS32,0,hsvColor.h);
	sendDlgItemMsg(IDC_SPIN_SAT,    UDM_SETPOS32,0,hsvColor.s);
	sendDlgItemMsg(IDC_SPIN_VAL,    UDM_SETPOS32,0,hsvColor.v);

}


void ColorPickerDlg::drawAll()
{
	if(bInitOver && !bInDrawAll)
	{
		mol::DC dc(*this);
		drawMarkers(dc);
		drawLines(dc);
		bInDrawAll = TRUE;
		calcCuboid();
		calcRects();
		setDIBPalette();
		drawRGB(dc);
		drawHSB(dc);
		setEditVals();
		setSpinVals();
		bInDrawAll = FALSE;
	}
}


void ColorPickerDlg::drawFilledColor(HDC dc,RECT cr,COLORREF c)
{
	HBRUSH brush = ::CreateSolidBrush(c);
	::InflateRect(&cr,-8,-10);
	cr.top+=10;
	::FillRect(dc,&cr,brush);
	
	::DeleteObject(brush);
}

void ColorPickerDlg::loadMappedBitmap(HBITMAP& bitmap,UINT nIdResource,SIZE& size)
{
	HBITMAP oldBitmap;
	
	if(bitmap) ::DeleteObject(bitmap);
	
	if ( bitmap = ::LoadBitmap( mol::hinstance(),MAKEINTRESOURCE(nIdResource)) )
	{
		int width,height;
		BITMAP bmInfo;
		::GetObject(bitmap,sizeof(bmInfo),&bmInfo);	
		width = bmInfo.bmWidth;
		height = bmInfo.bmHeight;

		oldBitmap = (HBITMAP)::SelectObject(memDC,bitmap);

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
		size.cx = width;
		size.cy = height;
	}
}



double Slope(POINT pt1,POINT pt2)
{
	double x,y;
	y = pt2.y - pt1.y;
	x = pt2.x - pt1.x;
	if(x)
	{
		return y/x;
	}
	else
	{
		return BAD_SLOPE;
	}
}



POINT Intersection(LineDesc l1,LineDesc l2)
{
	//POINT pt;
	double x,y;
	if(l1.slope == l2.slope)
	{
		// Parallel lines, no intersection
		POINT p = {0,0};
		return p;
	}
	else
	if(l1.slope == BAD_SLOPE )
	{
		// First Line is vertical, eqn is x=0
		// Put x = 0 in second line eqn to get y;
		x = l1.x;
		y = l2.slope * x + l2.c;
	}
	else
	if(l2.slope == BAD_SLOPE)
	{
		// second line is vertical Equation of line is x=0;
		// Put x = 0 in first line eqn to get y;
		x = l2.x;
		y = l1.slope * l2.x + l1.c;
	}
	else
	{
		y = ((l1.c * l2.slope) - (l2.c * l1.slope))/(l2.slope - l1.slope);
		x = (y - l1.c)/l1.slope;
	}
	POINT p;
	p.x = (LONG)x;
	p.y = (LONG)y;
	return p;
}

double FindC(LineDesc& l)
{
double c;
	if(l.slope == BAD_SLOPE)
	{
		c = l.y;
	}
	else
	{
		c = l.y - l.slope * l.x;
	}
	return c;
}

POINT PointOnLine(POINT pt1,POINT pt2,int len,int maxlen )
{
double x,y,m,a,c,C,A;
double a2,c2,m2,B;	
POINT opt = pt1;
POINT pt;
	pt1.y *= -1;
	pt2.y *= -1;

	a = (double)len;

	if(pt2.x != pt1.x)
	{
		m = (double)(pt2.y - pt1.y)/(pt2.x - pt1.x);
		m2 = m*m;
		a2 = a*a;
		c = (double)pt1.y - m * (double)pt1.x;
		c2 = c*c;


		A = 1.0;
		
		x = pt1.x;

		B = 2.0 * pt1.x;

		x *= x;
		C = x - a2/(m2 + 1);
		
		x = (B + sqrt(B*B - (4.0*A*C)))/(2.0*A);
		y = m*x + c;
		pt.x = (LONG)x;
		pt.y = (LONG)y;
		if(Distance(pt,pt1) > maxlen || Distance(pt,pt2) > maxlen)
		{
			x = (B - sqrt(B*B - (4.0*A*C)))/(2.0 * A);
			y = m*x + c;
			pt.x = (LONG)x;
			pt.y = (LONG)y;
		}
	}
	else
	{
		a2 = a*a;
		y = sqrt(a2);
		x = 0;
		pt.x = (LONG)x;
		pt.y = (LONG)y;
		pt.x += pt1.x;
		pt.y += pt1.y;

		if(Distance(pt,pt1) > maxlen || Distance(pt,pt2) > maxlen)
		{
			y = -1.0 *y;
			pt.x = (LONG)x;
			pt.y = (LONG)y;
			pt.x += pt1.x;
			pt.y += pt1.y;
		}
	}
	pt.y *= -1;
	return pt;
}


int Distance(POINT pt1,POINT pt2)
{
double a;
int x,y;
	y = (pt1.y - pt2.y);
	y *= y;

	x = (pt1.x - pt2.x);
	x *= x;
	
	a = (double)x + (double)y ;
	a = sqrt(a);
	return (int)a;
}

double AngleFromPoint(POINT pt,POINT center)
{
double x,y;
	y = -1 * (pt.y - center.y);
	x = pt.x - center.x;
	if(x == 0 && y == 0)
	{
		return 0.0;
	}
	else
	{
		return atan2(y,x);
	}
}

POINT PtFromAngle(double angle,double sat,POINT center)
{
	angle = DEG2RAD(angle);
	sat = TOSCALE(sat);
double x,y;
	x = sat * cos(angle);
	y = sat * sin(angle);

POINT pt ;
    pt.x = (LONG)(x + center.x);
	pt.y = (LONG)(y);
	pt.y *= -1;
	pt.y += center.y;

	return pt;
}

RGBType HSVType::toRGB()
{
RGBType rgb;
	if(!h  && !s)
	{
		rgb.r = rgb.g = rgb.b = v;
	}
double min,max,delta,hue;
	
	max = v;
	delta = (max * s)/255.0;
	min = max - delta;

	hue = h;
	if(h > 300 || h <= 60)
	{
		rgb.r = (int)max;
		if(h > 300)
		{
			rgb.g = (int)min;
			hue = (hue - 360.0)/60.0;
			rgb.b = (int)((hue * delta - min) * -1);
		}
		else
		{
			rgb.b = (int)min;
			hue = hue / 60.0;
			rgb.g = (int)(hue * delta + min);
		}
	}
	else
	if(h > 60 && h < 180)
	{
		rgb.g = (int)max;
		if(h < 120)
		{
			rgb.b = (int)min;
			hue = (hue/60.0 - 2.0 ) * delta;
			rgb.r = (int)(min - hue);
		}
		else
		{
			rgb.r = (int)min;
			hue = (hue/60 - 2.0) * delta;
			rgb.b = (int)(min + hue);
		}
	}
	else
	{
		rgb.b = (int)max;
		if(h < 240)
		{
			rgb.r = (int)min;
			hue = (hue/60.0 - 4.0 ) * delta;
			rgb.g = (int)(min - hue);
		}
		else
		{
			rgb.g = (int)min;
			hue = (hue/60 - 4.0) * delta;
			rgb.r = (int)(min + hue);
		}
	}
	return rgb;
}


HSVType RGBType::toHSV()
{
HSVType hsv;

double min,max,delta,temp;
	min = __min(r,__min(g,b));	
	max = __max(r,__max(g,b));
	delta = max - min;
	
	hsv.v = (int)max;
	if(!delta)
	{
		hsv.h = hsv.s = 0;
	}
	else
	{
		temp = delta/max;
		hsv.s = (int)(temp*255);

		if(r == (int)max)
		{
			temp = (double)(g-b)/delta;
		}
		else
		if(g == (int)max)
		{
			temp = 2.0 + ((double)(b-r)/delta);
		}
		else
		{
			temp = 4.0 + ((double)(r-g)/delta);
		}
		temp *= 60;
		if(temp < 0)
		{
			temp+=360;
		}
		if(temp == 360)
		{
			temp = 0;
		}
		hsv.h = (int)temp;
	}
	return hsv;
}

///////////////////////////////////////////////////////////////////

const char* rgb2hex( COLORREF col )
{
    static char ret[12];
    char buf[12];

    wsprintfA(buf,"%06X",col);

    ret[0] = '#';
    (ret[1]) = (buf[4]);
    (ret[2]) = (buf[5]);
    (ret[3]) = (buf[2]);
    (ret[4]) = (buf[3]);
    (ret[5]) = (buf[0]);
    (ret[6]) = (buf[1]);
    ret[7] = 0;
    return ret;
}

COLORREF hex2rgb( const char* hex )
{
    char buf[3];
    buf[2]=0;

    int r,g,b;
    r = g = b = 0;

    buf[0] = hex[1];
    buf[1] = hex[2];
    sscanf( buf, "%x", &r );

    buf[0] = hex[3];
    buf[1] = hex[4];
    sscanf( buf, "%x", &g );

    buf[0] = hex[5];
    buf[1] = hex[6];
    sscanf( buf, "%x", &b );

    return RGB(r,g,b);
}


