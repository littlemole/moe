#ifndef DIALOG_DEF_
#define DIALOG_DEF_

#include "conf.h"
#include "win/Wnd.h"

namespace mol  {

namespace win  {

//////////////////////////////////////////////////////////////////////
// Dialog Base Class
//////////////////////////////////////////////////////////////////////

class DlgBase : public WndProc
{
public:
		typedef DlgBase BaseWindowType;

        virtual ~DlgBase() {};

        virtual LRESULT endDlg(int n);
		
		void center();  

        //dlgItem funcs
        LRESULT sendDlgItemMsg  ( int id, UINT msg, WPARAM wParam, LPARAM lParam );
		LRESULT setDlgItemText  ( int id, const mol::string& s );
        LRESULT setDlgItemInt   ( int id, int val );
        LRESULT setDlgItemFont  ( int id, HFONT hfont );
        LRESULT setDlgButtonIcon( int id, HICON hicon );
		LRESULT setDlgButtonImg ( int id, HBITMAP bitmap );
        LRESULT setDlgStaticIcon( int id, HICON hicon );
		

        UINT getDlgItemText( int id, mol::string& s );
		UINT getDlgItemInt ( int id, int& value, BOOL bSigned = TRUE);
		bool getDlgItemChecked( int id );
		void setDlgItemChecked( int id );
        HWND getDlgItem    ( int id );

        //default ctrl handling: pass back to windows
        virtual LRESULT wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

protected:

        //  subclass the def wndproc
        virtual void subClass();
        virtual void subClass(HWND hwnd);
        virtual void deClass();

		// wndproc
		static LRESULT CALLBACK windowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

        // remember default wndproc
        WNDPROC	defProc;

private:
        //disable that
        HWND virtual createWindow( const mol::string& windowName, HMENU hMenu=0,const Rect& r=stdRect , HWND parent=0 ) { return 0;};
};

//////////////////////////////////////////////////////////////////////
// modal and modeless dialogs
//////////////////////////////////////////////////////////////////////

class Dialog : public DlgBase
{
public:
        virtual ~Dialog() {};

        //creation modal dlg
        virtual LRESULT doModal( int lpTemplate, HWND hWndParent );
		// creation modeless dlg
        virtual HWND doModeless( int lpTemplate, HWND hWndParent );
  
        // dialog & wndproc procedure support

#ifdef _WIN64
        static LRESULT CALLBACK dialogProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
#else
        static BOOL CALLBACK dialogProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
#endif

};

//////////////////////////////////////////////////////////////////////
// main dialog instead of window
//////////////////////////////////////////////////////////////////////

class MainDialog : public mol::win::windowclass<mol::win::DlgBase>
{
public:
		//WINDOWCLASS

	    // create a main Dlg from template
        virtual HWND createDlg(int lpTemplate, const mol::string& className );

        // dialog procedure support
#ifdef _WIN64
        static LRESULT CALLBACK dialogProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
#else
		static BOOL CALLBACK dialogProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
#endif

};

} // endnamespace mol::win

//////////////////////////////////////////////////////////////////////
// add MsgMap Support
//////////////////////////////////////////////////////////////////////

template<class W, class B = mol::win::Dialog>
class Dlg : public B
{
public:
	typedef W  ThisWindowType;														
    typedef B  BaseWindowType;		

    LRESULT virtual wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)		
    {																					
            return msgMap<ThisWindowType>().call((W*)(this),message,wParam,lParam);							
    }	
};

template<class T>
class MainDlg : public mol::Dlg< T, mol::win::MainDialog >
{};


} // endnamespace mol

#endif
