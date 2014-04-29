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
    void setClassName( const std::wstring& name);
    std::wstring getClassName();
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
	template<class T>
    static std::wstring createClass()
	{
		std::wostringstream oss;
		oss << _T("MOLWC_");
		oss << mol::towstring(typeid(T).name());

		std::wstring cn = oss.str();
		if ( classNameMap_.count(cn) != 0 ) 
		{
			return cn;
		}

		WndClass wc;
		wc.setClassName(cn);
		classNameMap_.insert(std::make_pair(cn,wc));
		return cn;
	}
    static WndClass& getClass(const std::wstring& name);

private:
    static std::map<std::wstring,WndClass>	classNameMap_;
};

template<class T>
class windowclass : public T
{
public:
	virtual mol::win::WndClass& wndClass()				
	{																	
		static std::wstring wc = mol::win::WndClassGenerator::createClass<T>();	
		return mol::win::WndClassGenerator::getClass(wc);					
	}
};

} //end namespace mol::win
} //end namespace mol

#endif
