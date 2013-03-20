#ifndef _MOL_SHELL_NAMESPACETREE_DEF_H_
#define _MOL_SHELL_NAMESPACETREE_DEF_H_

#include "win/IO.h"
#include "win/file.h"
#include "win/CoCtrl.h"
#include "ole/DragDrop.h"
#include "ole/Ctrl.h"
#include "ole/punk.h"
#include "ole/persist.h"
#include "shellCtrl_h.h"
#include "win/Layout.h"
#include "win/msghandler.h"
#include "win/msg_macro.h"
#include "resource.h"
#include "shellctrl_dispid.h"
using namespace mol;
using namespace mol::io;

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// NamespaceTree Control Wrapper
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
    

class NamespaceTree: 
	public ax_ctrl<NamespaceTree,CLSID_NamespaceTree,false,mol::Window,WS_CHILD|WS_CLIPSIBLINGS|WS_CLIPCHILDREN,0>,
	public Dispatch<IShellTree>,
	public ctrl_events<NamespaceTree,_IShellTreeEvents>,
	public ProvideClassInfo2<NamespaceTree,DIID__IShellTreeEvents>,
	public INameSpaceTreeControlEvents,
	public INameSpaceTreeControlCustomDraw,
	public IServiceProvider,
	public interfaces< NamespaceTree, 
			 implements<
				IDispatch,
				IShellTree,
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
				IProvideClassInfo,
				IProvideClassInfo2,
				IServiceProvider,
				//INameSpaceTreeControlCustomDraw,
				INameSpaceTreeControlEvents>
		>
{
public:
    NamespaceTree();
	virtual ~NamespaceTree();

	msg_handler( WM_CREATE, OnCreate )
		LRESULT virtual OnCreate( UINT, WPARAM, LPARAM );

	msg_handler( WM_DESTROY, OnDestroy )
	    LRESULT virtual OnDestroy( UINT, WPARAM, LPARAM );

	msg_handler( WM_SIZE, OnSize )
		LRESULT virtual OnSize( UINT, WPARAM, LPARAM );

	// COM properties

	HRESULT virtual __stdcall get_DisplayFiles	( VARIANT_BOOL* vb );
	HRESULT virtual __stdcall put_DisplayFiles		( VARIANT_BOOL vb );

	HRESULT virtual __stdcall get_Selection		( BSTR* dirname );

	HRESULT virtual __stdcall get_HasFocus		( VARIANT_BOOL* vbHasFocus);

	HRESULT virtual __stdcall get_UseContext	( VARIANT_BOOL* vb );
	HRESULT virtual __stdcall put_UseContext	( VARIANT_BOOL vb  );

	// COM methods

	HRESULT virtual __stdcall Update			();
	HRESULT virtual __stdcall Cut				();
	HRESULT virtual __stdcall Copy				();
	HRESULT virtual __stdcall Paste				();
	HRESULT virtual __stdcall Rename			();
	HRESULT virtual __stdcall Delete			();
	HRESULT virtual __stdcall Properties		();
	HRESULT virtual __stdcall Execute			();
	HRESULT virtual __stdcall AddFolder			(BSTR folder);
	HRESULT virtual __stdcall RemoveFolder		(BSTR folder);
	HRESULT virtual __stdcall CreateDir     	();
	HRESULT virtual __stdcall IsDir	     		(BSTR path,VARIANT_BOOL* vb);

	HRESULT virtual __stdcall Load( LPSTREAM pStm);
	HRESULT virtual __stdcall Save( LPSTREAM pStm,BOOL fClearDirty);

	HRESULT virtual __stdcall Load( IPropertyBag *pPropBag,IErrorLog *pErrorLog);
	HRESULT virtual __stdcall Save( IPropertyBag *pPropBag,BOOL fClearDirty,BOOL fSaveAllProperties);

	HRESULT virtual __stdcall put_ForeColor( BSTR fPath);
	HRESULT virtual __stdcall get_ForeColor(  BSTR* fPath);
	HRESULT virtual __stdcall put_BackColor( BSTR fPath);
	HRESULT virtual __stdcall get_BackColor(  BSTR* fPath);

    HRESULT virtual __stdcall QueryService(REFGUID /*guidService*/, REFIID riid, void **ppv);

    // INameSpaceTreeControlEvents
    HRESULT virtual __stdcall  OnItemClick(IShellItem * psi, NSTCEHITTEST nstceHitTest, NSTCECLICKTYPE nstceClickType); 
    HRESULT virtual __stdcall  OnPropertyItemCommit(IShellItem * /*psi*/) { return S_FALSE; }
    HRESULT virtual __stdcall  OnItemStateChanging(IShellItem * /*psi*/, NSTCITEMSTATE /*nstcisMask*/, NSTCITEMSTATE /*nstcisState*/) {  return S_OK;  }
    HRESULT virtual __stdcall  OnItemStateChanged(IShellItem * /*psi*/, NSTCITEMSTATE /*nstcisMask*/, NSTCITEMSTATE /*nstcisState*/) { return S_OK; }
    HRESULT virtual __stdcall  OnSelectionChanged(IShellItemArray *psiaSelection);
    HRESULT virtual __stdcall  OnKeyboardInput(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/)  { return S_FALSE; }
    HRESULT virtual __stdcall  OnBeforeExpand(IShellItem * /*psi*/) { return S_OK; }
    HRESULT virtual __stdcall  OnAfterExpand(IShellItem * /*psi*/) { return S_OK; }
    HRESULT virtual __stdcall  OnBeginLabelEdit(IShellItem * /*psi*/) { return S_OK; }
    HRESULT virtual __stdcall  OnEndLabelEdit(IShellItem * /*psi*/) { return S_OK; }
    HRESULT virtual __stdcall  OnGetToolTip(IShellItem * /*psi*/, LPWSTR /*pszTip*/, int /*cchTip*/) { return E_NOTIMPL; }
    HRESULT virtual __stdcall  OnBeforeItemDelete(IShellItem * /*psi*/) { return E_NOTIMPL; }
    HRESULT virtual __stdcall  OnItemAdded(IShellItem * /*psi*/, BOOL /*fIsRoot*/) { return E_NOTIMPL; }
    HRESULT virtual __stdcall  OnItemDeleted(IShellItem * /*psi*/, BOOL /*fIsRoot*/) { return E_NOTIMPL; }
    HRESULT virtual __stdcall  OnBeforeContextMenu(IShellItem * /*psi*/, REFIID /*riid*/, void **ppv) {  *ppv = NULL; return E_NOTIMPL; }
    HRESULT virtual __stdcall  OnAfterContextMenu(IShellItem * /*psi*/, IContextMenu * /*pcmIn*/, REFIID /*riid*/, void **ppv) { *ppv = NULL; return E_NOTIMPL; }
    HRESULT virtual __stdcall  OnBeforeStateImageChange(IShellItem * /*psi*/) { return S_OK; }
    HRESULT virtual __stdcall  OnGetDefaultIconIndex(IShellItem * /*psi*/, int * /*piDefaultIcon*/, int * /*piOpenIcon*/) { return E_NOTIMPL; }

	 HRESULT virtual __stdcall  PrePaint( HDC hdc, RECT *prc, LRESULT *plres)
	 {
		 ::FillRect(hdc,prc,bgBrush_);
		 *plres = CDRF_DOERASE | CDRF_NOTIFYITEMDRAW;
		 return S_OK;
	 }

	 HRESULT virtual __stdcall PostPaint( HDC hdc, RECT *prc) 
	 {
		 return S_OK;
	 }
        
     HRESULT virtual __stdcall  ItemPrePaint( HDC hdc, RECT *prc, NSTCCUSTOMDRAW *pnstccdItem, COLORREF *pclrText, COLORREF *pclrTextBk, LRESULT *plres)
	 {
		 *plres = CDRF_DODEFAULT;
		 *pclrText = foreCol_;
		 *pclrTextBk = bgCol_;
		 return S_OK;
	 }
        
     HRESULT virtual __stdcall ItemPostPaint( HDC hdc, RECT *prc, NSTCCUSTOMDRAW *pnstccdItem) 
	 {
		 return S_OK;
	 }


	virtual void initAmbientProperties( IDispatch* disp)
	{

	}

protected:

	void InvokeVerb(const std::string& verb);

	mol::punk<INameSpaceTreeControl>			tree_;
	mol::punk<IShellItem>						currentItem_;

	mol::bstr									currentPath_;
    bool										displayFiles_;
	bool										useContext_;
	RECT										clientRect_;
	mol::Menu									treeMenu_;
	DWORD										adviseCookie_;

	OLE_COLOR									bgCol_;
	OLE_COLOR									foreCol_;
	HBRUSH										bgBrush_;

	DWORD										lastClickTime_;
	DWORD										doubleClickTimeout_;
};


#endif
