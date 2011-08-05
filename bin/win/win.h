#pragma once

#include "util/util.h"

#include "win/app.h"
#include "win/wnd.h"
#include "win/dlg.h"
#include "win/ctrl.h"

#include "win/msgmap.h"
#include "win/msghandler.h"
#include "win/msg_macro.h"

#include "resource.h"

// the help dialog
class MyDlg : public mol::Dlg<MyDlg>
{
public:

	MyDlg()	 {}
	~MyDlg() {}

	LRESULT wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
};


// a custom window ISA (toplevel) MainFrame of type (default) Window
class MyWnd : public mol::MainFrame<MyWnd,mol::Window>
{
public:

	MyWnd()  {}
	~MyWnd() {}


	msg_handler(WM_CREATE,OnCreate)
	void OnCreate();

	msg_handler(WM_PAINT,OnPaint)
	void OnPaint();

	msg_handler(WM_DESTROY,OnDestroy)
	void OnDestroy();

	cmd_handler(IDC_BUTT,OnClick)
	void OnClick();

	cmd_handler(IDM_ABOUT,OnAbout)
	void OnAbout();

	cmd_handler(IDM_EXIT,OnExit)
	void OnExit();

private:
	mol::Button butt_;
	MyDlg dlg_;
};


class MyApp : public mol::WindowApp
{
public:

	MyApp();

	~MyApp()
	{}

	MyWnd mainWnd_;
};
