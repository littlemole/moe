#include "win/WndClass.h"
#include "win/Wnd.h"

namespace mol {
namespace win {

mol::string WndClassGenerator::createClass()
{
	// make this one thread safe
	LOCK(cs_);
	size_t n = classNameMap_.size();
	mol::TCHAR buf[255];

	wsprintf(buf,_T("MOLWndClassGeneratorGeneratedClass%i"),n);
	mol::string s(buf);
	WndClass wc;
	wc.setClassName(buf);
	classNameMap_.insert(std::pair <mol::string,WndClass> (s,wc));
	return s;
}

WndClass& WndClassGenerator::getClass(const mol::string& name)
{
	return classNameMap_[name];
}


std::map<mol::string,WndClass>	WndClassGenerator::classNameMap_;

mol::CriticalSection WndClassGenerator::cs_;

WndClass::WndClass()
{
	setDefault();
}


WndClass::~WndClass()
{
	if ( wcex_.lpszClassName )
	{
		delete wcex_.lpszClassName;
		wcex_.lpszClassName = 0;
	}
}

WndClass::WndClass(const WndClass& wc)
{
	this->wcex_ = wc.wcex_;
	int len = _tcslen(wc.wcex_.lpszClassName)+1;
	this->wcex_.lpszClassName = new mol::TCHAR[len];
	memcpy((void*)(this->wcex_.lpszClassName), wc.wcex_.lpszClassName, len*sizeof(mol::TCHAR));
}

WndClass& WndClass::operator=(const WndClass& wc)
{
	if ( this == &wc )
	{
		return *this;
	}

	this->wcex_ = wc.wcex_;
	int len = _tcslen(wc.wcex_.lpszClassName)+1;
	this->wcex_.lpszClassName = new mol::TCHAR[len];
	memcpy((void*)(this->wcex_.lpszClassName), wc.wcex_.lpszClassName, len*sizeof(mol::TCHAR));
	return *this;
}

void WndClass::setDefault()
{
	wcex_.cbSize			 = sizeof(WNDCLASSEX);
	wcex_.style              = 0;//CS_HREDRAW | CS_VREDRAW;
	wcex_.cbClsExtra         = 0;
	wcex_.cbWndExtra         = sizeof(HANDLE);
	wcex_.hInstance          = hinstance();
	wcex_.hIcon              = ::LoadIcon( NULL, IDI_APPLICATION);
	wcex_.hCursor            = ::LoadCursor(NULL, IDC_ARROW);
	wcex_.hbrBackground      = (HBRUSH)(COLOR_WINDOW + 1) ;
	wcex_.lpszMenuName       = NULL;
	wcex_.hIconSm            = ::LoadIcon( NULL, IDI_APPLICATION);
	wcex_.lpszClassName	     = 0;
	wcex_.lpfnWndProc        = (WNDPROC) (WndProc::windowProcedure);
}

void WndClass::setWndProc( WNDPROC p)
{
    wcex_.lpfnWndProc = p;
}

void WndClass::setHinstance( HINSTANCE h)
{
    wcex_.hInstance = h;
}

void WndClass::setStyle( int s )
{
    wcex_.style	= s;
}

void WndClass::setClsExtra( int c )
{
    wcex_.cbClsExtra = c;
}


void WndClass::setWndExtra( int w )
{
    wcex_.cbWndExtra  = w;
}

void WndClass::setIcon( HICON i )
{
    wcex_.hIconSm  = i;
}

void WndClass::setCursor( HCURSOR c)
{
    wcex_.hCursor  = c;
}


void WndClass::setBackground( HBRUSH h)
{
    wcex_.hbrBackground = h;
}

void WndClass::setMenu( HMENU m)
{
    wcex_.lpszMenuName = MAKEINTRESOURCE( m ) ;
}

void WndClass::hIconSm( HICON i)
{
    wcex_.hIconSm = i;
}

void WndClass::setClassName( const mol::string& name)
{
	mol::TCHAR* buf = new mol::TCHAR[255];
	memcpy( buf , name.c_str(), name.size()*sizeof(mol::TCHAR) );
    buf[name.size()] = 0;
    wcex_.lpszClassName = buf;
}

mol::string WndClass::getClassName()
{
    return wcex_.lpszClassName;
};

bool WndClass::registerClass()
{
    static WNDCLASS wc;

    if ( !::GetClassInfo( hinstance(), wcex_.lpszClassName, &wc ))
    {
		if (! RegisterClassEx(&wcex_))
			return false;
    }
    return true;
}

HWND WndClass::getRunning()
{
    HWND hWnd = ::FindWindow( wcex_.lpszClassName, 0 );
    if ( ::IsWindow(hWnd) )
    {
        HWND other = ::GetLastActivePopup(hWnd);
        if ( ::IsWindow(other)  )
			return other;
        return hWnd;
    }
    return 0;
}

} //end namespace mol::win
} //end namespace mol
