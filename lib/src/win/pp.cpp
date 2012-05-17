#include "win/pp.h"
#include "win/msgloop.h"

namespace mol {
namespace win {

PropPage::PropPage()
{
	deleteOnNCDestroy_ = true;
}

void PropPage::create( mol::PropSheet* ps, const mol::string& tab, int id, int flags)
{
	tab_ = tab;
	id_ =id;
	ps_ = ps;

	//::ZeroMemory(&psp_,sizeof(PROPSHEETPAGE) );
	mol::zero(psp_);
	psp_.dwSize = sizeof(PROPSHEETPAGE);
	psp_.dwFlags = flags;
	psp_.hInstance = mol::hinstance();
	psp_.pszTemplate = MAKEINTRESOURCE(id);
	psp_.pszTitle = tab.c_str();
	psp_.lParam = (LPARAM)this;
	psp_.pfnDlgProc = &PropPage::dialogProcedure;

	page_ = ::CreatePropertySheetPage(&psp_);
}

PropPage::~PropPage()
{
	//ODBGS("~PropPage");
}

void PropPage::init()
{}

void PropPage::command(int c)
{}

int PropPage::apply()
{
	return PSNRET_NOERROR;
}

void PropPage::reset()
{
}

int  PropPage::translateAccel( LPMSG msg)
{
	return PSNRET_NOERROR ;
}

LRESULT PropPage::wndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	if ( message == WM_INITDIALOG )
	{
		init();
		PropSheet_Changed( ::GetParent(hDlg), hDlg);
		return FALSE; // note: false! look into PSDK!
	}
	if ( message == WM_COMMAND )
	{
		command( LOWORD(wParam) );
	}
	if ( message == WM_NCDESTROY )
	{
		mol::win::dialogs().unregisterDialog(hDlg);
		if ( this->deleteOnNCDestroy_ )
		{
			LRESULT l = mol::win::Dialog::wndProc(hDlg, message, wParam, lParam);
			//delete this;
			return l;
		}
	}

	return mol::win::Dialog::wndProc(hDlg, message, wParam, lParam);
}

#ifdef _WIN64
#define DWL_MSGRESULT 0
LRESULT CALLBACK  PropPage::dialogProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
#else
BOOL CALLBACK  PropPage::dialogProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
#endif
{
		if ( message == WM_NOTIFY )
		{
			mol::Crack msg(message,wParam,lParam);
			if ( msg.nmhdr()->code == PSN_APPLY )
			{
				mol::win::PropPage* pThis = mol::wndFromHWND<mol::win::PropPage>(hwnd);
				int r = pThis->apply();
				::SetWindowLong(hwnd,DWL_MSGRESULT,r);
				return TRUE;
			}
			if ( msg.nmhdr()->code == PSN_RESET  )
			{
				mol::win::PropPage* pThis = mol::wndFromHWND<mol::win::PropPage>(hwnd);
				pThis->reset();
			}
			if ( msg.nmhdr()->code == PSN_TRANSLATEACCELERATOR )
			{
				mol::win::PropPage* pThis = mol::wndFromHWND<mol::win::PropPage>(hwnd);
				PSHNOTIFY * psn = (PSHNOTIFY *)lParam;
				LPMSG m = (LPMSG)(msg.propSheetNotify()->lParam);
				int r = pThis->translateAccel(m);
				::SetWindowLong(hwnd,DWL_MSGRESULT,r);
				return TRUE;
			}
		}
		if (message == WM_INITDIALOG)
		{
			PROPSHEETPAGE* psp = (PROPSHEETPAGE*)lParam;
			mol::win::PropPage* pThis = (mol::win::PropPage*)(psp->lParam);
			pThis->subClass(hwnd);
			mol::win::dialogs().registerDialog(hwnd);
			pThis->ps_->center(::GetParent(hwnd));
			return (BOOL)(pThis->wndProc( hwnd, message,wParam,lParam));
		}
		return FALSE;
}

} // end namespace win

//////////////////////////////////////////////////////////////////////////////////////////////

PropSheet::PropSheet(HWND owner, const mol::string& title, int flags )
{
	title_ = title;
	::ZeroMemory(&ph_,sizeof(ph_) );
	ph_.dwSize = sizeof(PROPSHEETHEADER);
	ph_.dwFlags = flags;
	ph_.hwndParent = owner;
	ph_.hInstance = mol::hinstance();
	ph_.pszCaption = title_.c_str();
	ph_.pfnCallback = &PropSheet::PropSheetProc;
	startPage_ = 0;
	centered_ = false;
}

HPROPSHEETPAGE PropSheet::addPage(mol::win::PropPage* page)
{
	pages_.push_back( *page );
	return *page;
}


INT_PTR PropSheet::create()
{		
	ph_.nPages = (UINT)pages_.size();
	ph_.nStartPage = startPage_;
	ph_.phpage = &(pages_.front());

	return ::PropertySheet(&ph_);
}

void PropSheet::center(HWND hwnd)
{
	if ( centered_ )
		return;

	centered_ = true;

    RECT r;
    ::GetWindowRect(hwnd,&r);

    RECT s;
    ::GetWindowRect( ::GetDesktopWindow(),&s);

    int x = s.right/2  - (r.right-r.left)/2;
    int y = s.bottom/2 - (r.bottom-r.top)/2;
    int w = (r.right-r.left);
    int h = (r.bottom-r.top);
	
	POINT p = {x,y};
	::ScreenToClient( hwnd, &p );

	::MoveWindow( hwnd, p.x, p.y, w, h, 0 );
}

int CALLBACK PropSheet::PropSheetProc( HWND hwndDlg, UINT uMsg, LPARAM lParam )
{
	if ( uMsg == PSCB_INITIALIZED )
	{
	}
	return 0;
}

} // end namespace mol