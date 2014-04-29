#ifndef _MOL_DEF_GUARD_MOE_PROP_PAGE_DEF_GUARD_DEFINE_
#define _MOL_DEF_GUARD_MOE_PROP_PAGE_DEF_GUARD_DEFINE_

#include "win/dlg.h"
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

class PropSheet
{
public:

	typedef PropSheet BaseWindowType;

	PropSheet( HWND owner, const std::wstring& title, int flags = PSH_NOCONTEXTHELP|PSH_PROPTITLE|PSH_USEPSTARTPAGE|PSH_NOAPPLYNOW|PSH_USECALLBACK );

	template<class T>
	void addPage(  const std::wstring& tab, int id )
	{
		mol::win::PropPage* page = new T;
		page->create(this,tab,id);
		addPage(page);
	}

	template<class T>
	void addPage(  const std::wstring& tab, REFCLSID clsid ,  int id)
	{
		mol::ole::OlePropPage* page = new T;
		page->create(this,tab,clsid,id);
		addPage(page);
	}

	INT_PTR create();

	static int CALLBACK PropSheetProc( HWND hwndDlg, UINT uMsg, LPARAM lParam );

	void center(HWND hwnd);
protected:

	HPROPSHEETPAGE addPage( mol::win::PropPage* page);

	bool centered_;
	int startPage_;
	int	nPages_;
	std::vector<HPROPSHEETPAGE> pages_;
	PROPSHEETHEADER ph_;
	std::wstring title_;
};




} // end namespace mol


#endif