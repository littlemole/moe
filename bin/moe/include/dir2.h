#ifndef DIRLIST_DEF_GUARD_
#define DIRLIST_DEF_GUARD_

#include "shared.h"
#include "ole/ShellFolderWnd.h"
#include "resource.h"

using namespace mol;

///////////////////////////////////////////////////////////////////////////////

class DirChild 
: 
//	public MdiChildFrame<DirChild,MdiChild>,

	public mol::Frame<
			DirChild,
			MdiChild,
			WS_BORDER|WS_CHILD|WS_CLIPSIBLINGS|
			WS_CLIPCHILDREN|WS_THICKFRAME|
			WS_SYSMENU|WS_CAPTION |
			WS_MAXIMIZEBOX|WS_MINIMIZEBOX ,
			WS_EX_MDICHILD| WS_EX_CLIENTEDGE >,

	public ProvideClassInfo<DirChild>,
	public mol::Dispatch<IDoc>,
	public interfaces< DirChild, 
			implements< IDispatch, IDoc, IProvideClassInfo> >
{
public:

	DirChild();
	virtual ~DirChild();

	typedef mol::stack_obj<DirChild> Instance;

	static Instance* CreateInstance( const mol::string& p );

	void OnCreate();
	LRESULT OnSize(UINT msg, WPARAM wParam, LPARAM lParam);
	void OnMDIActivate(HWND activated);
    void OnClose();
	void OnDestroy();
	void OnNcDestroy();

public:

	/////////////////////////////////////////////////////////////////////
	// COM
	/////////////////////////////////////////////////////////////////////

	virtual HRESULT __stdcall get_Filename( BSTR* filename);
	virtual HRESULT __stdcall get_Path( BSTR* dirpath);
	virtual HRESULT __stdcall get_Type( long* type);
	virtual HRESULT __stdcall Close();
	virtual HRESULT __stdcall Activate();

	class Folder : public mol::ole::ShellFolderWnd
	{
		public:
			void OnUserSelect(std::vector<mol::string>& v);
	};

	mol::stack_obj<Folder> oleObject;


	virtual void dispose() {}

	void refresh();
	void cut();
	void copy();
	void paste();
	void rename();
	void erase();
	void execute();
	void updir();
	void newdir();
	void properties();


	static REFGUID getCoClassID()
	{
		return IID_IDoc;
	}

	/////////////////////////////////////////////////////////////////////
	virtual HRESULT __stdcall get_Top( long* top)
	{
		if ( top )
		{
			RECT r;
			getWindowRect(r);
			mol::Point p(r.left,r.top);
			::ScreenToClient( mdiClient(), &p);
			*top = p.y;
		}
		return S_OK;
	}

	virtual HRESULT __stdcall put_Top( long top)
	{
		RECT r;
		getWindowRect(r);
		int w = r.right-r.left;
		int h = r.bottom-r.top;

		mol::Point p(r.left,r.top);
		::ScreenToClient(mdiClient(), &p);

		p.y = top;
		h  += top-p.y;

		move(p.x,p.y,w,h);
		return S_OK;
	}
	/////////////////////////////////////////////////////////////////////
	virtual HRESULT __stdcall get_Left( long* left)
	{
		if ( left )
		{
			RECT r;
			getWindowRect(r);
			mol::Point p(r.left,r.top);
			::ScreenToClient(mdiClient(), &p);
			*left = p.x;
		}
		return S_OK;
	}

	virtual HRESULT __stdcall put_Left( long left)
	{
		RECT r;
		getWindowRect(r);
		int w = r.right-r.left;
		int h = r.bottom-r.top;

		mol::Point p(r.left,r.top);
		::ScreenToClient(mdiClient(), &p);

		p.x = left;
		w += left-p.x;

		move(p.x,p.y,w,h);
		return S_OK;
	}

	/////////////////////////////////////////////////////////////////////
	virtual HRESULT __stdcall get_Width( long* width)
	{
		if ( width )
		{
			RECT r;
			getWindowRect(r);
			*width = r.right -r.left;
		}
		return S_OK;
	}

	virtual HRESULT __stdcall put_Width( long width)
	{
		RECT r;
		getWindowRect(r);
		int w = width;
		int h = r.bottom-r.top;

		mol::Point p(r.left,r.top);
		::ScreenToClient(mdiClient(), &p);

		move(p.x, p.y, w, h);
		return S_OK;
	}
	/////////////////////////////////////////////////////////////////////
	virtual HRESULT __stdcall get_Height( long* height)
	{
		if ( height )
		{
			RECT r;
			getWindowRect(r);
			*height = r.bottom -r.top;
		}
		return S_OK;
	}

	virtual HRESULT __stdcall put_Height( long height)
	{
		RECT r;
		getWindowRect(r);
		int w = r.right-r.left;
		int h = height;

		mol::Point p(r.left,r.top);
		::ScreenToClient(mdiClient(), &p);

		move(p.x, p.y, w, h);
		return S_OK;
	}


	/////////////////////////////////////////////////////////////////////
	virtual HRESULT __stdcall get_App( IXmoe** m);

	/////////////////////////////////////////////////////////////////////
	virtual HRESULT __stdcall get_Document( IDispatch** doc)
	{
		if ( doc )
		{
			*doc = NULL;
			return oleObject.QueryInterface(IID_IDispatch, (void**) doc);
		}
		return E_NOINTERFACE;
	}

	/////////////////////////////////////////////////////////////////////
	virtual HRESULT __stdcall  Show()
	{
		show(SW_SHOW);
		return S_OK;
	}

	virtual HRESULT __stdcall  Hide()
	{
		show(SW_HIDE);
		return S_OK;
	}

	/////////////////////////////////////////////////////////////////////
	virtual HRESULT __stdcall  Minimize()
	{
		show(SW_MINIMIZE);
		return S_OK;
	}

	virtual HRESULT __stdcall  Maximize()
	{
		show(SW_MAXIMIZE);
		return S_OK;
	}

	virtual HRESULT __stdcall  Restore()
	{
		show(SW_RESTORE);
		return S_OK;
	}


private:

	bool initialize(const mol::string& p);

	mol::string path_;

	HRESULT queryInterface(REFIID riid, void **ppv)
	{
		return ((IDoc*)this)->QueryInterface(riid,ppv);
	}
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#endif