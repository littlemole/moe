#ifndef _MOL_DEF_GUARD_TASKBAR_DEF_GUARD_DEFINE_
#define _MOL_DEF_GUARD_TASKBAR_DEF_GUARD_DEFINE_

#include "win/res.h"
#include "win/wnd.h"
#include "ole/punk.h"
#include <ShObjIdl.h>

namespace mol {

class TaskThumbnail;

namespace win {

class Taskbar;

class TaskbarWnd 
	: public mol::Frame<
					TaskbarWnd, 
					mol::Window, 
					WS_POPUP | WS_BORDER | WS_SYSMENU | WS_CAPTION, WS_EX_TOOLWINDOW | WS_EX_NOACTIVATE>
{

friend class mol::win::Taskbar;
friend class mol::TaskThumbnail;

public:

    LRESULT wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

private:

	TaskbarWnd(Taskbar* tb, HWND doc, ITaskbarList4*, bool disabled = false );
	static TaskbarWnd* Create( Taskbar * pMainDlg, HWND d,const std::wstring& title, ITaskbarList4*,bool disabled = false);

	virtual ~TaskbarWnd();
	virtual BOOL destroy();

    HBITMAP GetIconicRepresentation(int nWidth = -1, int nHeight = -1, int scale = 1);

	void enableTabs(bool b);

	void sendLivePreviewBitmap();
    void sendIconicRepresentation(int nWidth = -1, int nHeight = -1, int scale = 1);

	void cacheIconicRepresentation();
	void refreshIconDelayed();

	mol::punk<ITaskbarList4> tbl_;
	Taskbar* tb_;

	bool disabled_;
	HWND doc;
	HBITMAP hbm_cached_;
		
	void timer_callback();	
	mol::Timer timer_;
};



class Taskbar
{
friend class mol::win::TaskbarWnd;
public:

	Taskbar();
	virtual ~Taskbar();

	void init(HWND parent);

	TaskbarWnd* addTab( HWND d, const std::wstring& title, bool disabled = false );

	void renameTab( HWND d, const std::wstring& title );
	void moveTab( HWND d, HWND before );

	HWND parent() {return parent_; }
private:

	void RemoveTab(HWND hwnd);

	HWND parent_;
	std::map<HWND,TaskbarWnd*> tabs_;
	mol::punk<ITaskbarList4> tbl_;
};

} // end namespace win


class TaskThumbnail
{
public:

	TaskThumbnail()
		: wnd_(0)
	{}

	TaskThumbnail& operator=(mol::win::TaskbarWnd* w)
	{
		wnd_ = w;
		return *this;
	}

	void refreshIcon(bool delayed = false)
	{
		if ( wnd_ )
		{
			if ( delayed )
			{
				wnd_->refreshIconDelayed();
			}
			else
			{
				wnd_->cacheIconicRepresentation();
			}
		}
	}

	void destroy()
	{
		if (wnd_)
		{
			wnd_->destroy();
			wnd_ = nullptr;
		}
	}

	~TaskThumbnail()
	{
		destroy();
	}

private:

	mol::win::TaskbarWnd* wnd_;
};

mol::win::Taskbar* taskbar();

} // end namespace mol

#endif