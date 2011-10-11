#ifndef MOL_DEF_TREECTRL_VIEW_DEF_GUARDING_
#define MOL_DEF_TREECTRL_VIEW_DEF_GUARDING_

#include "win/IO.h"
#include "win/file.h"
#include "win/CoCtrl.h"
#include "win/MsgMap.h"
#include "win/MsgHandler.h"
#include "win/msg_macro.h"
#include "ole/DragDrop.h"
#include "ole/Ctrl.h"
#include "treeCtrl_h.h"
#include "resource.h"

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

class TreeCtrl;

class TreeElement : 
	public mol::Dispatch<ITreeElement>,
	public mol::interfaces< TreeElement, 
				mol::implements<
				                IDispatch,
								ITreeElement,
								IProvideClassInfo>
						   >
{
public:

    TreeElement(void);
    ~TreeElement();

	virtual void dispose() {}

	typedef mol::com_obj<TreeElement> Instance;
	static Instance* CreateInstance(TreeCtrl* tc,BSTR txt, VARIANT value, HTREEITEM hit);


		HRESULT virtual __stdcall put_Label( BSTR txt);
		HRESULT virtual __stdcall get_Label( BSTR* txt);
		HRESULT virtual __stdcall put_Value( VARIANT v);
		HRESULT virtual __stdcall get_Value( VARIANT* v);
		HRESULT virtual __stdcall get_Count(long* cnt);
		HRESULT virtual __stdcall Element(long index, ITreeElement** el );
		HRESULT virtual __stdcall Add( ITreeElement* el );
		HRESULT virtual __stdcall Remove( long index );
		HRESULT virtual __stdcall Clear( );

		HRESULT virtual __stdcall Load( LPSTREAM pStm);
		HRESULT virtual __stdcall Save( LPSTREAM pStm,BOOL fClearDirty);

		HRESULT virtual __stdcall Load( IPropertyBag *pPropBag,IErrorLog *pErrorLog);
		HRESULT virtual __stdcall Save( IPropertyBag *pPropBag,BOOL fClearDirty,BOOL fSaveAllProperties);



private:

	HTREEITEM item_;
	TreeCtrl* tc_;
	mol::bstr label_;
	mol::variant value_;
	std::vector< ITreeElement* > children_;
};



///////////////////////////////////////////////////////////////////////////////


class TreeCtrl: 
	public mol::ax_ctrl<TreeCtrl,CLSID_TreeControl,false,mol::Window,WS_CHILD|WS_CLIPSIBLINGS|WS_CLIPCHILDREN,0>,
	public mol::Dispatch<ITreeCtrl>,
	public mol::ctrl_events<TreeCtrl,_ITreeCtrlEvents>,
	public mol::ProvideClassInfo<TreeCtrl>,
	public mol::interfaces< TreeCtrl, 
				mol::implements<
						IDispatch,
						ITreeCtrl,
						IOleObject,
						IDataObject,
						mol::interface_ex<IPersist,IPersistStreamInit>,
						mol::interface_ex<IPersistStream,IPersistStreamInit>,
						IPersistStreamInit,
						IPersistStorage,
						IPersistPropertyBag,
						IRunnableObject,
						IViewObject,
						IViewObject2,
						mol::interface_ex<IOleWindow,IOleInPlaceObjectWindowless>,
						mol::interface_ex<IOleInPlaceObject,IOleInPlaceObjectWindowless>,
						IOleControl,
						IConnectionPointContainer,
						IProvideClassInfo> >
{
public:

    TreeCtrl(void);
    ~TreeCtrl();

	// COM properties

		HRESULT virtual __stdcall get_Root( ITreeElement** el);
		HRESULT virtual __stdcall Create( ITreeElement* parent,BSTR txt, VARIANT value, ITreeElement** el);
		HRESULT virtual __stdcall Clear();
		HRESULT virtual __stdcall ScrollIntoView(ITreeElement* el);

	// COM methods

		HRESULT virtual __stdcall Load( LPSTREAM pStm);
		HRESULT virtual __stdcall Save( LPSTREAM pStm,BOOL fClearDirty);

		HRESULT virtual __stdcall Load( IPropertyBag *pPropBag,IErrorLog *pErrorLog);
		HRESULT virtual __stdcall Save( IPropertyBag *pPropBag,BOOL fClearDirty,BOOL fSaveAllProperties);

	mol::Control<mol::TreeCtrl,WS_CHILD|WS_VISIBLE|TVS_HASLINES|TVS_HASBUTTONS|TVS_SHOWSELALWAYS|TVS_LINESATROOT,0>			tree_;

	HTREEITEM TreeCtrl::treeItemFromElement(HTREEITEM parent, ITreeElement* el);

protected:

	msg_handler( WM_CREATE,	OnCreate ) 
		LRESULT virtual OnCreate( UINT, WPARAM, LPARAM );

	msg_handler( WM_SIZE,OnSize )
		LRESULT virtual OnSize( UINT, WPARAM, LPARAM );

	msg_handler( WM_DESTROY, OnDestroy )
		LRESULT virtual OnDestroy( UINT, WPARAM, LPARAM );

	notify_code_handler( TVN_ITEMEXPANDING, OnTreeItemExpanding )
		LRESULT virtual OnTreeItemExpanding( UINT, WPARAM, LPARAM );

	notify_code_handler( NM_CLICK, OnTreeClick )
		LRESULT virtual OnTreeClick( UINT, WPARAM, LPARAM );

	notify_code_handler( TVN_SELCHANGED, OnTreeSelection )
		LRESULT virtual OnTreeSelection( UINT, WPARAM, LPARAM );

	//notify_code_handler( TVN_BEGINLABELEDIT, OnTreeBeginLabelEdit )
	//	LRESULT virtual OnTreeBeginLabelEdit( UINT, WPARAM, LPARAM );

	//notify_code_handler( TVN_BEGINDRAG, OnTreeBeginDrag )
	//	LRESULT virtual OnTreeBeginDrag( UINT, WPARAM, LPARAM );

	//notify_code_handler( TVN_ENDLABELEDIT, OnTreeRename )
	//	LRESULT virtual OnTreeRename( UINT, WPARAM, LPARAM );

	//notify_code_handler( TVN_KEYDOWN, OnTreeKeyDown )
	//	LRESULT virtual OnTreeKeyDown( UINT, WPARAM, LPARAM );

	notify_code_handler( NM_DBLCLK, OnTreeDblClick )
        LRESULT virtual OnTreeDblClick( UINT, WPARAM, LPARAM );

	notify_code_handler( NM_RCLICK, OnTreeContext )
		LRESULT virtual OnTreeContext( UINT, WPARAM, LPARAM );



	RECT					clientRect_;

	mol::punk<ITreeElement> root_;

};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////




#endif