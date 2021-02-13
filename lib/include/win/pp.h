#ifndef _MOL_DEF_GUARD_MOE_PROP_PAGE_DEF_GUARD_DEFINE_
#define _MOL_DEF_GUARD_MOE_PROP_PAGE_DEF_GUARD_DEFINE_

#include "win/dlg.h"
//#include "ole/propertypage.h"
#include <Prsht.h>

namespace mol
{


/////////////////////////////////////////////////////////////////////
// Property Sheets
/////////////////////////////////////////////////////////////////////

class PropSheet;

namespace win {

class PropPage : public mol::win::Dialog
{
friend class mol::PropSheet;
public:

	typedef PropPage BaseWindowType;
	~PropPage();

	virtual void init();
	virtual void reset();
	virtual void command(int c);
	virtual int apply();
	virtual int translateAccel( LPMSG msg);

	mol::PropSheet* ps() { return ps_; }

	LRESULT wndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

#ifdef _WIN64
	static LRESULT CALLBACK dialogProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
#else
	static BOOL CALLBACK dialogProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
#endif

	operator HPROPSHEETPAGE () { return page_; };

protected:

	void create( mol::PropSheet* ps, const std::wstring& tab, int id, int flags = PSP_DEFAULT|PSP_USETITLE);
	PropPage();

	std::wstring tab_;
	int id_;

	PROPSHEETPAGE psp_;
	HPROPSHEETPAGE page_;

	mol::PropSheet* ps_;

private:
	virtual LRESULT doModal( int lpTemplate, HWND hWndParent ) { return 0; };
    virtual HWND doModeless( int lpTemplate, HWND hWndParent ) { return 0; };
};

} // end namespace win





} // end namespace mol


#endif