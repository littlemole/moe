#ifndef _DEF_GUARD_MOL_COLORPICKER_DLG_DEF_
#define _DEF_GUARD_MOL_COLORPICKER_DLG_DEF_

/////////////////////////////////////////////////////////////////////////////
// ColorPickerDlg dialog

#include "ole/factory.h"
#include "ole/Bstr.h"
#include "ole/punk.h"
#include "ole/aut.h"
#include "win/Dib.h"
#include "win/Dlg.h"
#include "win/DIB.h"
#include "ColorResources.h"  

#include "shellCtrl_h.h"

using namespace mol;

struct HSVType;
struct RGBType;
struct LineDesc;

struct RGBType
{
	COLORREF color() { return RGB(r,g,b); };
	HSVType toHSV();
	int r,g,b;
};

struct HSVType
{
	RGBType toRGB();
	int h,s,v;
};

struct LineDesc
{
	double x,y;
	double slope;
	double c;
};
COLORREF hex2rgb( const char* hex );
const char* rgb2hex( COLORREF col );

class ColorPickerDlg : 
	public mol::Dlg< ColorPickerDlg >
{
// Construction
friend class ColorDlg;
public:
	ColorPickerDlg();   
	ColorPickerDlg(COLORREF c);   
	ColorPickerDlg(const std::string& c);   
	~ColorPickerDlg();

	COLORREF getColor()			{ return color.color();};
	std::string getHexColor()	{ return rgb2hex(color.color()); };

	LRESULT doModal      ( HWND hWndParent, COLORREF col );
	LRESULT doModeless   ( HWND hWndParent, COLORREF col );

	msg_handler( WM_INITDIALOG, OnInitDialog )  
		LRESULT OnInitDialog(  UINT, WPARAM, LPARAM );

	cmd_handler( IDC_EDIT_BLUE, OnChangeEditBlue  )
		LRESULT OnChangeEditBlue(  UINT, WPARAM, LPARAM );

	cmd_handler( IDC_EDIT_GREEN, OnChangeEditGreen )
		LRESULT OnChangeEditGreen(  UINT, WPARAM, LPARAM );

	cmd_handler( IDC_EDIT_HUE, OnChangeEditHue )
		LRESULT OnChangeEditHue(  UINT, WPARAM, LPARAM );

	cmd_handler( IDC_EDIT_RED, OnChangeEditRed )
		LRESULT OnChangeEditRed(  UINT, WPARAM, LPARAM );

	cmd_handler( IDC_EDIT_SAT, OnChangeEditSat )
		LRESULT OnChangeEditSat( UINT, WPARAM, LPARAM );

	cmd_handler( IDC_EDIT_VAL, OnChangeEditVal )
		LRESULT OnChangeEditVal( UINT, WPARAM, LPARAM );

	cmd_handler( IDC_EDIT_HEX, OnChangeEditHex )
		LRESULT OnChangeEditHex( UINT, WPARAM, LPARAM );

    cmd_handler( IDCANCEL, OnButtonPressed )
	cmd_handler( IDOK, OnButtonPressed )
		LRESULT OnButtonPressed( UINT, WPARAM, LPARAM );

	msg_handler( WM_PAINT, OnPaint )
		LRESULT OnPaint	( UINT, WPARAM, LPARAM );

	msg_handler( WM_LBUTTONDOWN, OnLButtonDown     )
		LRESULT OnLButtonDown( UINT, WPARAM, LPARAM );

	msg_handler( WM_LBUTTONUP, OnLButtonUp       )
		LRESULT OnLButtonUp( UINT, WPARAM, LPARAM );

	msg_handler( WM_MOUSEMOVE, OnMouseMove       )
		LRESULT OnMouseMove( UINT, WPARAM, LPARAM );

	msg_handler( WM_SYSCOLORCHANGE, OnSysColorChange  )
		LRESULT OnSysColorChange( UINT, WPARAM, LPARAM );


private:
	void init(COLORREF c);

	void createBrightDIB();
	void loadMappedBitmap(HBITMAP& bitmap,UINT nIdResource,SIZE& size);

	void setDIBPalette();
	void setSpinVals();
	void setEditVals();

	void calcRects();
	void calcSlopes();
	void calcCuboid();
		
	BOOL inCircle(POINT pt);
	BOOL inBright(POINT pt);
	void trackPoint(POINT pt);

	void drawAll();
	void drawRGB(HDC dc);
	void drawHSB(HDC dc);
	void drawFilledColor(HDC dc, RECT cr, COLORREF c);
	void drawLines(HDC dc);
	void drawXorRect(HDC dc,RECT& cr);
	void drawMarkers(HDC dc);

	RGBType color;
	RGBType	oldColor;
	HSVType hsvColor;	

	mol::win::DIB brightDIB;
	HBITMAP rgbBitmap;
	HBITMAP hsbBitmap;
	HDC		memDC;

	POINT centre;
	POINT cuboid[8];
	POINT vertex;
	POINT top;
	POINT left;
	POINT right;

	int nIndex;
	int nMouseIn;
	int rgbWidth;
	int rgbHeight;
	int hsbWidth;
	int hsbHeight;
	int redLen;
	int greenLen;
	int blueLen;

	RECT brightRect;
	RECT rgbRect;
	RECT hsbRect;
	RECT currentRect;
	RECT brightMark;
	RECT oldColorRect;
	RECT newColorRect;
	RECT rects[3];

	LineDesc lines[3];

	BOOL bInMouse;
	BOOL bInitOver;
	BOOL bInDrawAll;

	BOOL isCaptured;
	HCURSOR oldCursor;
};

class ColorDlg : 
	public com_registerobj<ColorDlg,CLSID_ColorDialog>,
	public Dispatch<IColorPicker>,
	public interfaces< ColorDlg, implements< IDispatch, IColorPicker> >
{
public:
		ColorDlg()
		{
			col_ = (OLE_COLOR)RGB(255,125,75);
		}

		HRESULT virtual __stdcall put_Color( OLE_COLOR col)
		{
			col_ = col;
			return S_OK;
		}
		 
		HRESULT virtual __stdcall get_Color( OLE_COLOR* col)
		{
			if ( col )
				*col = col_;
			return S_OK;
		}

		HRESULT virtual __stdcall put_HexColor( BSTR col)
		{
			bstr b(col);
			col_ = hex2rgb(b.tostring().c_str());
			return S_OK;
		}
		HRESULT virtual __stdcall get_HexColor( BSTR* col)
		{
			if ( col )
			{
				*col = ansi2BSTR(rgb2hex(col_));
			}
			return S_OK;
		}

		//method
		HRESULT virtual __stdcall Show(HWND wnd, VARIANT_BOOL* ok)
		{
			if ( ok )
				*ok = VARIANT_FALSE;
			if ( IDOK == dlg_.doModal(wnd,col_) )
			{
				if ( ok )
				{
					*ok = VARIANT_TRUE;
					col_ = dlg_.getColor();
				}
			}
			return S_OK;
		}

protected:
	OLE_COLOR	    col_;
	ColorPickerDlg  dlg_;
};

#endif