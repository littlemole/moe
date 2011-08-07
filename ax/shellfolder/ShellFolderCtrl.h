#ifndef MOL_DEF_SHELLDIR_VIEW_DEF_GUARDING_
#define MOL_DEF_SHELLDIR_VIEW_DEF_GUARDING_

#pragma once
#include "win/IO.h"
#include "win/file.h"
#include "win/CoCtrl.h"
#include "win/MsgMap.h"
#include "win/MsgHandler.h"
#include "win/msg_macro.h"
#include "ole/DragDrop.h"
#include "ole/Ctrl.h"
#include "ole/ShellFolderWnd.h"
#include "shellFolder_h.h"
#include "resource.h"

using namespace mol;
using namespace mol::io;
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



#define ShellFolderCtrl_Dispatch_DisplayFiles 1
#define ShellFolderCtrl_Dispatch_Selection 2

class ShellFolderCtrl: 
	public ax_ctrl<ShellFolderCtrl,CLSID_ShellPane,false,mol::Window,WS_CHILD|WS_CLIPSIBLINGS|WS_CLIPCHILDREN,0>,
	public Dispatch<IShellPane>,
	public ctrl_events<ShellFolderCtrl,_IShellPaneEvents>,
	public ProvideClassInfo<ShellFolderCtrl>,
	public interfaces< ShellFolderCtrl, 
				implements<
						IDispatch,
						IShellPane,
						IOleObject,
						IDataObject,
						interface_ex<IPersist,IPersistStreamInit>,
						interface_ex<IPersistStream,IPersistStreamInit>,
						IPersistStreamInit,
						IPersistStorage,
						IPersistPropertyBag,
						IRunnableObject,
						IViewObject,
						IViewObject2,
						interface_ex<IOleWindow,IOleInPlaceObjectWindowless>,
						interface_ex<IOleInPlaceObject,IOleInPlaceObjectWindowless>,
						IOleControl,
						IConnectionPointContainer,
						IProvideClassInfo> >
{
public:

    ShellFolderCtrl(void);
    ~ShellFolderCtrl();

	// COM properties

		HRESULT virtual __stdcall get_DisplayFiles	( VARIANT_BOOL* vb );
		HRESULT virtual __stdcall put_DisplayFiles	( VARIANT_BOOL vb  );

		HRESULT virtual __stdcall get_Selection		( VARIANT* dirname );
		HRESULT virtual __stdcall put_Selection		( VARIANT dirname );

		HRESULT virtual __stdcall get_HasFocus		( VARIANT_BOOL* vbHasFocus);

	// COM methods

		HRESULT virtual __stdcall Update			();
		HRESULT virtual __stdcall Cut				();
		HRESULT virtual __stdcall Copy				();
		HRESULT virtual __stdcall Paste				();
		HRESULT virtual __stdcall Rename			();
		HRESULT virtual __stdcall Delete			();
		HRESULT virtual __stdcall Properties		();
		HRESULT virtual __stdcall Execute			();
		HRESULT virtual __stdcall CreateDir     	();
		HRESULT virtual __stdcall UpDir		     	();

		HRESULT virtual __stdcall Load( LPSTREAM pStm);
		HRESULT virtual __stdcall Save( LPSTREAM pStm,BOOL fClearDirty);

		HRESULT virtual __stdcall Load( IPropertyBag *pPropBag,IErrorLog *pErrorLog);
		HRESULT virtual __stdcall Save( IPropertyBag *pPropBag,BOOL fClearDirty,BOOL fSaveAllProperties);

protected:

	void setPath(const mol::string& p);

	msg_handler( WM_CREATE,	OnCreate ) 
		LRESULT virtual OnCreate( UINT, WPARAM, LPARAM );

	msg_handler( WM_SIZE,OnSize )
		LRESULT virtual OnSize( UINT, WPARAM, LPARAM );

	msg_handler( WM_DESTROY, OnDestroy )
		LRESULT virtual OnDestroy( UINT, WPARAM, LPARAM );

	RECT					clientRect_;

    bool					displayFiles_;

	class Folder : 
		public mol::ole::ShellFolderWnd
	{
		public:
			outer_this(ShellFolderCtrl,wnd_);
			void OnUserSelect(std::vector<mol::string>& v);
			void OnPathChanged( const mol::string& p);
	};

	mol::stack_obj<Folder> wnd_;

};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////




#endif