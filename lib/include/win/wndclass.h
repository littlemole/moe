#ifndef MOL_WNDCLASS_DEF_
#define MOL_WNDCLASS_DEF_

#include "win/app.h"
#include "thread/Sync.h"
#include <map>

namespace mol {
namespace win {

/////////////////////////////////////////////////////////////////
// WNDCLASS encapsulation
/////////////////////////////////////////////////////////////////

class WndClass
{
public:
    WndClass();
	~WndClass();
	WndClass(const WndClass& wc);

    void setDefault();
    void setHinstance( HINSTANCE h);
    void setWndProc( WNDPROC p);
    void setClassName( const mol::string& name);
    mol::string getClassName();
    void setStyle( int s );
    void setMenu( HMENU m);
    void setIcon( HICON i );
    void hIconSm( HICON i);
    void setCursor( HCURSOR c);
    void setBackground( HBRUSH h);
    void setClsExtra( int c );
    void setWndExtra( int w );
    bool registerClass();
    HWND getRunning();

	WndClass& operator=(const WndClass& wc);
private:
    WNDCLASSEX	wcex_;
};

/////////////////////////////////////////////////////////////////
//auto-generate wnd-classes
/////////////////////////////////////////////////////////////////

class WndClassGenerator
{
public:
    static mol::string createClass();
    static WndClass& getClass(const mol::string& name);

private:
    static std::map<mol::string,WndClass>	classNameMap_;
    static mol::CriticalSection cs_;
};

template<class T>
class windowclass : public T
{
public:
	virtual mol::win::WndClass& wndClass()				
	{																	
		static mol::string wc = mol::win::WndClassGenerator::createClass();	
		return mol::win::WndClassGenerator::getClass(wc);					
	}
};

} //end namespace mol::win
} //end namespace mol

#endif
