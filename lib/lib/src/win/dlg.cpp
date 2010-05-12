#include "win/Dlg.h"
#include "win/App.h"

namespace mol  {
namespace win  {

//////////////////////////////////////////////////////////////////////////////////

LRESULT DlgBase::wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch ( message )
	{
		case WM_INITDIALOG :
		{
			return ::CallWindowProc( defProc, hwnd, message, wParam, lParam );
		}
/*		case WM_COMMAND:
		{
			if ( wParam == 0 )
				return OnInvoke(message,wParam,lParam);
			break;
		}
		*/
	}
	return ::DefDlgProc(hwnd,message,wParam,lParam);
}

//////////////////////////////////////////////////////////////////////////////////

LRESULT CALLBACK DlgBase::windowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    try
    {
		if (message == WM_DESTROY)
		{
			mol::App().OnEndDlg(hwnd);
		}
		DlgBase* pThis = wndFromHWND<DlgBase>(hwnd);

        // if we have a valid Dlg-pointer, route to wndProc
        if (pThis)
		{
			LRESULT lr = (pThis->wndProc( hwnd, message,wParam,lParam));
			if ( message == WM_NCDESTROY )
			{
				pThis->hWnd_ = 0;
				if ( pThis->deleteOnNCDestroy_ )
					delete pThis;
			}
			return lr;
		}
    }
    catch (X )
    {
			ODBGS1("DlgBase::windowProcedure %i",::GetLastError());
            PostQuitMessage(0);
    }
    return ::DefDlgProc( hwnd, message, wParam, lParam);
}

#ifdef _WIN64
LRESULT CALLBACK Dialog::dialogProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
        if (message == WM_INITDIALOG)
        {
			Dialog* pThis = (Dialog*)lParam;
			pThis->subClass(hwnd);
            AppBase::app<AppBase>().OnCreateDlg(hwnd);
            return (BOOL)(pThis->wndProc( hwnd, message,wParam,lParam));
        }
        return FALSE;
}
#else
BOOL CALLBACK Dialog::dialogProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
        if (message == WM_INITDIALOG)
        {
			Dialog* pThis = (Dialog*)lParam;
			pThis->subClass(hwnd);
            AppBase::app<AppBase>().OnCreateDlg(hwnd);
            return (BOOL)(pThis->wndProc( hwnd, message,wParam,lParam));
        }
        return FALSE;
}
#endif

LRESULT DlgBase::endDlg(int n)
{
        return ::EndDialog(hWnd_, n);
}

//////////////////////////////////////////////////////////////////////////////////
//  subclass the def wndproc
void DlgBase::subClass()
{
        ::SetWindowLongPtr( hWnd_, GWLP_USERDATA, (LONG_PTR)this);
        defProc = (WNDPROC)(::SetWindowLongPtr( hWnd_, GWLP_WNDPROC, (LONG_PTR)(DlgBase::windowProcedure) ));
}
void DlgBase::subClass(HWND hwnd)
{
        attach(hwnd);
        subClass();
}
void DlgBase::deClass()
{
        ::SetWindowLongPtr( hWnd_, GWLP_WNDPROC, (LONG_PTR)(defProc) );
}

//////////////////////////////////////////////////////////////////////////////////

LRESULT DlgBase::sendDlgItemMsg( int id, UINT msg, WPARAM wParam, LPARAM lParam )
{
        return (::SendMessage( getDlgItem(id), msg, wParam, lParam) );
}

LRESULT DlgBase::setDlgItemText( int id, const mol::string& s )
{
        return sendDlgItemMsg(id, WM_SETTEXT, 0, (LPARAM)(s.c_str()) );
}

LRESULT DlgBase::setDlgItemFont( int id, HFONT hfont )
{
        return sendDlgItemMsg(id, WM_SETFONT, (WPARAM)hfont,  MAKELPARAM(TRUE,0) );
}

LRESULT DlgBase::setDlgButtonIcon( int id, HICON hicon )
{
        return sendDlgItemMsg(id, BM_SETIMAGE, (WPARAM)IMAGE_ICON,  (LPARAM)(hicon) );
}

LRESULT DlgBase::setDlgStaticIcon( int id, HICON hicon )
{
        return sendDlgItemMsg(id, STM_SETIMAGE, (WPARAM)IMAGE_ICON,  (LPARAM)(hicon) );
}

UINT DlgBase::getDlgItemText( int id, mol::string& s )
{
	    mol::TCHAR  buf[4096];
        if (!(::GetDlgItemText( hWnd_, id, buf, 4096) ))
                return 0;
        s = buf;
        return (UINT)s.size();
}

UINT DlgBase::getDlgItemInt( int id, int& value, BOOL bSigned)
{
	BOOL bTranslated;
	value = (int)::GetDlgItemInt( hWnd_, id, &bTranslated, bSigned);
	if ( !bTranslated )
		return 0;
	return TRUE;
}

HWND DlgBase::getDlgItem( int id ) 
{ 
	return (::GetDlgItem( hWnd_, id )); 
}

LRESULT DlgBase::setDlgItemInt( int id, int value )
{
	return ::SetDlgItemInt(hWnd_, id, value, FALSE);
}

void DlgBase::center()
{
        RECT r;
        getWindowRect(r);

        RECT s;
        ::GetWindowRect(::GetDesktopWindow(),&s);

        int x = s.right/2  - (r.right-r.left)/2;
        int y = s.bottom/2 - (r.bottom-r.top)/2;
        int w = (r.right-r.left);
        int h = (r.bottom-r.top);
        move( x, y, w, h, TRUE);
}
//////////////////////////////////////////////////////////////////////////////////

HWND Dialog::doModeless(int lpTemplate, HWND hWndParent )
{
	return ::CreateDialogParam( hinstance(), MAKEINTRESOURCE(lpTemplate), hWndParent, Dialog::dialogProcedure, (LPARAM)(this));
}

LRESULT Dialog::doModal(int lpTemplate, HWND hWndParent )
{
        return ::DialogBoxParam( hinstance(), MAKEINTRESOURCE(lpTemplate), hWndParent, Dialog::dialogProcedure,  (LPARAM)(this));
}



//////////////////////////////////////////////////////////////////////////////////


HWND MainDialog::createDlg(int lpTemplate, const mol::string& className )
{
		mol::win::WndClass& wc = wndClass();
        wc.setClassName(className);
        wc.setWndProc ( (WNDPROC)(MainDialog::windowProcedure) );
        wc.setWndExtra(DLGWINDOWEXTRA);
        wc.registerClass();
		defProc = ::DefDlgProc;

		::DialogBoxParam( mol::hinstance(),
                          MAKEINTRESOURCE(lpTemplate),
                          0,&MainDialog::dialogProcedure,
                          (LPARAM)(this) );
        return 0;
}

#ifdef _WIN64
LRESULT CALLBACK MainDialog::dialogProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
#else
BOOL CALLBACK MainDialog::dialogProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
#endif
{
        if (message == WM_INITDIALOG)
        {
                MainDialog* pThis = (MainDialog*)lParam;
                ::SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)(pThis));
				pThis->attach(hwnd);
                AppBase::app<AppBase>().OnCreateDlg(hwnd);
                return (BOOL)(pThis->wndProc( hwnd, message,wParam,lParam));
        }
        return FALSE;
}

} // endnamespace mol::win
} // endnamespace mol
