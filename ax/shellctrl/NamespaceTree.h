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
// TreeEntry - stores Data associated with TreeItem
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#define ShellTreeCtrl_Dispatch_DisplayFiles 1
#define ShellTreeCtrl_Dispatch_Selection 2
    

class NamespaceTree: 
	public ax_ctrl<NamespaceTree,CLSID_NamespaceTree,false,mol::Window,WS_CHILD|WS_CLIPSIBLINGS|WS_CLIPCHILDREN,0>,
	public Dispatch<IShellTree>,
	public ctrl_events<NamespaceTree,_IShellTreeEvents>,
	public ProvideClassInfo2<NamespaceTree,DIID__IShellTreeEvents>,
	public INameSpaceTreeControlEvents,
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

    HRESULT virtual __stdcall QueryService(REFGUID /*guidService*/, REFIID /*riid*/, void **ppv)
    {
        HRESULT hr = E_NOINTERFACE;
        *ppv = NULL;
        return hr;
    }

    // INameSpaceTreeControlEvents
    HRESULT virtual __stdcall  OnItemClick(IShellItem * psi, NSTCEHITTEST /*nstceHitTest*/, NSTCECLICKTYPE nstceClickType) 
	{ 
		HRESULT ret = S_FALSE;
		if(NSTCECT_LBUTTON && psi)
		{
			
			PWSTR psz=0;
			HRESULT hr = psi->GetDisplayName(SIGDN_DESKTOPABSOLUTEPARSING, &psz);
			//SetDlgItemText(_hdlg, IDC_NAME, SUCCEEDED(hr) ? psz : L"");
			if(hr==S_OK && psz)
			{
				std::wstring ws(psz);
				if ( ws == currentPath_.towstring() )
				{
					SFGAOF sfgaof;
					hr = psi->GetAttributes(SFGAO_FOLDER,&sfgaof);
					if (SUCCEEDED(hr))
					{
						VARIANT_BOOL vb = sfgaof & SFGAO_FOLDER ? VARIANT_TRUE : VARIANT_FALSE;
						fire(DISPID_ISHELLTREEEVENTS_ONTREEDBLCLICK,mol::variant(psz),mol::variant(vb));
					}
					ret = S_FALSE;
				}
			}
			::CoTaskMemFree(psz);
		}
		return ret;  
	}
    HRESULT virtual __stdcall  OnPropertyItemCommit(IShellItem * /*psi*/) { return S_FALSE; }
    HRESULT virtual __stdcall  OnItemStateChanging(IShellItem * /*psi*/, NSTCITEMSTATE /*nstcisMask*/, NSTCITEMSTATE /*nstcisState*/) {  return S_OK;  }
    HRESULT virtual __stdcall  OnItemStateChanged(IShellItem * /*psi*/, NSTCITEMSTATE /*nstcisMask*/, NSTCITEMSTATE /*nstcisState*/) { return S_OK; }
    HRESULT virtual __stdcall  OnSelectionChanged(IShellItemArray *psiaSelection)
    {
        IShellItem *psi;
        HRESULT hr = psiaSelection->GetItemAt(0, &psi);
        if (SUCCEEDED(hr))
        {
            IShellItem2 *psi2;
            hr = psi->QueryInterface(IID_PPV_ARGS(&psi2));
            if (SUCCEEDED(hr))
            {
				PWSTR psz;
				HRESULT hr = psi->GetDisplayName(SIGDN_DESKTOPABSOLUTEPARSING, &psz);
				//SetDlgItemText(_hdlg, IDC_NAME, SUCCEEDED(hr) ? psz : L"");
				if(hr==S_OK)
				{
					currentPath_ = psz;
					item_ = psi;
					fire(DISPID_ISHELLTREEEVENTS_ONTREESELECTION,mol::variant(currentPath_));
				}
				::CoTaskMemFree(psz);
				psi2->Release();
			}
			psi->Release();
        }
        return S_OK;
    }
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


	virtual void initAmbientProperties( IDispatch* disp)
	{

	}

protected:

	void InvokeVerb(const std::string& verb);

	mol::punk<INameSpaceTreeControl>			tree_;
	mol::punk<IShellItem>						item_;

	mol::bstr									currentPath_;
    bool										displayFiles_;
	bool										useContext_;
	RECT										clientRect_;
	mol::Menu									treeMenu_;
	DWORD										adviseCookie_;
};


#endif
