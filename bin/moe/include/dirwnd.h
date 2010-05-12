#ifndef DIRLIST_IMPL_DEF_GUARD_
#define DIRLIST_IMPL_DEF_GUARD_

#include "commons.h"
#include "resource.h"

using namespace mol;

///////////////////////////////////////////////////////////////////////////////
//typedef AxWnd<&CLSID_ShellList> ShellDirList;

///////////////////////////////////////////////////////////////////////////////
class DirChild;

class DirChildImpl
	: public Frame< 
				DirChildImpl, 
				mol::AxWnd<
						DirChildImpl, 
						MdiChild,
						&CLSID_ShellList>,
				WS_BORDER|WS_CHILD|WS_CLIPSIBLINGS|
				WS_CLIPCHILDREN|WS_THICKFRAME|
				WS_SYSMENU|WS_CAPTION |
				WS_MAXIMIZEBOX|WS_MINIMIZEBOX ,
				WS_EX_MDICHILD >
{
public:

	typedef 
				mol::AxWnd<
						DirChildImpl, 
						MdiChild,
						&CLSID_ShellList>
	BASE;

	DirChildImpl(DirChild* dc);
	virtual ~DirChildImpl();

	void setIcon(int icon);

	// std windows msgs
	//msg_handler( WM_CREATE, OnCreate )
	//    LRESULT OnCreate( UINT, WPARAM, LPARAM );

	msg_handler( WM_MDIACTIVATE, OnMDIActivate )
		LRESULT OnMDIActivate( UINT, WPARAM, LPARAM );

	msg_handler( WM_DESTROY, OnDestroy )
		LRESULT OnDestroy( UINT, WPARAM, LPARAM );

	msg_handler( WM_NCDESTROY, OnNcDestroy )
		LRESULT OnNcDestroy( UINT, WPARAM, LPARAM );

	//menu commands
	cmd_handler( IDM_EDIT_UPDATE, OnEditUpdate )
		LRESULT OnEditUpdate ( UINT, WPARAM, LPARAM );

	cmd_handler( IDM_EDIT_CUT, OnEditCut )
		LRESULT OnEditCut( UINT, WPARAM, LPARAM );

	cmd_handler( IDM_EDIT_COPY, OnEditCopy ) 
		LRESULT OnEditCopy( UINT, WPARAM, LPARAM );

	cmd_handler( IDM_EDIT_PASTE, OnEditPaste )
		LRESULT OnEditPaste( UINT, WPARAM, LPARAM );

//	typedef AxWnd<&CLSID_ShellList> ShellDirList;
//	ShellDirList		dirList;

protected:

	HWND createWindow( const mol::string& windowName, int id, const mol::Rect& r, HWND parent );

	DirChild*			dirchild_;

    Icon				icon_;
    Menu				dirMenu_;
	RECT				clientRect_;		
	DWORD				cookie_;

	// directory events sink
    class DirChild_sink : public stack_obj<ShellListEvents>
    {
        public : outer_this(DirChildImpl,sink); 
		virtual HRESULT __stdcall OnListDblClick(BSTR filename);
    } sink;
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#endif