// win.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "win.h"


// main window app entry point
int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	return 
		mol::run<MyApp>(lpCmdLine);
}

// app constructor - creates window
MyApp::MyApp()
{
	mainWnd_.create( _T("Hello molib"), (HMENU)IDC_WIN );
	mainWnd_.show(SW_SHOW);
}


// event handlers

void MyWnd::OnCreate()
{
	// create the child button
	butt_.create( _T("Hello Butt"),(HMENU)IDC_BUTT,mol::Rect(100,100,100,100),*this);
}

void MyWnd::OnPaint()
{
	mol::string s(_T("Hello molib!"));

	mol::PaintDC dc(*this);		
	dc.select(::GetStockObject(DEFAULT_GUI_FONT));
	::TextOut(dc,30,30,s.c_str(),s.size());
}

void MyWnd::OnDestroy()
{
	// trigger application shutdown
	::PostQuitMessage(0);
}

void MyWnd::OnClick()
{
	//::MessageBox(*this,_T("clicked"),_T("button:"),0);
	dlg_.doModal(IDD_ABOUTBOX,*this);
}

void MyWnd::OnExit()
{
	// proceed by destroying window
	destroy();
}

void MyWnd::OnAbout()
{
	::MessageBox(*this,_T("demo"),_T("about:"),0);
}





// help dialog

LRESULT MyDlg::wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
			 
		case WM_INITDIALOG  : 
		{
			return FALSE;
		}
			

		case WM_COMMAND :
		{
			switch(wParam)
			{
				case IDOK :
				{
					::MessageBox(*this,_T("demo"),_T("about:"),0);
					endDlg(0);
					return TRUE;
				}
				case IDCANCEL :
				{
					endDlg(0);
					return TRUE;
				}
			}
		}
	}
	return BaseWindowType::wndProc(hwnd,message,wParam,lParam);
}
