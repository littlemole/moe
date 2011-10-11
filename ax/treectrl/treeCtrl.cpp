#include "stdafx.h"
#include "TreeCtrl.h"
#include "ole/Bstr.h"
#include "ole/enum.h"
#include "ole/Img.h"
#include "util/str.h"
#include "treectrl_dispid.h"
#include <sstream>


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

TreeElement::TreeElement()
{
	item_ = 0;
}

TreeElement::~TreeElement()
{
	for ( std::vector< ITreeElement* >::iterator it = children_.begin(); it != children_.end(); it++)
	{
		(*it)->Release();
	}
}

TreeElement::Instance* TreeElement::CreateInstance(TreeCtrl* tc,BSTR txt, VARIANT value, HTREEITEM hit)
{
	Instance* te = new Instance;
	te->AddRef();
	te->tc_ = tc;
	te->label_ = txt;
	te->value_ = value;
	te->item_ = hit;
	return te;
}

HRESULT __stdcall TreeElement::put_Label( BSTR txt)
{
	if (!txt)
		return E_INVALIDARG;

	label_ = txt;
	return S_OK;
}

HRESULT __stdcall TreeElement::get_Label( BSTR* txt)
{
	if (!txt)
		return E_INVALIDARG;

	*txt = ::SysAllocString(label_.bstr_);
	return S_OK;
}

HRESULT __stdcall TreeElement::put_Value( VARIANT v)
{
	value_ = v;
	return S_OK;
}

HRESULT __stdcall TreeElement::get_Value( VARIANT* v)
{
	if (!v)
		return E_INVALIDARG;

	return ::VariantCopy(v,&value_);
}

HRESULT __stdcall TreeElement::get_Count(long* cnt)
{
	return S_OK;
}

HRESULT __stdcall TreeElement::Element(long index, ITreeElement** el )
{
	if ( index < 0 )
		return E_INVALIDARG;

	int size = (int) children_.size();

	if ( size < 1 )
		return E_UNEXPECTED;

	if ( index > size-1 )
		return E_INVALIDARG;

	ITreeElement*& e = children_[index];
	return e->QueryInterface( IID_ITreeElement, (void**)el );
}

HRESULT __stdcall TreeElement::Add( ITreeElement* el )
{
	if ( !el )
		return E_INVALIDARG;

	children_.push_back(el);

	return S_OK;
}


HRESULT __stdcall TreeElement::Remove( long index )
{
	long i = 0;
	HTREEITEM hit = tc_->tree_.getChildItem(item_);
	for ( std::vector< ITreeElement* >::iterator it = children_.begin(); it != children_.end(); it++)
	{
		if ( i == index )
		{
			(*it)->Release();
			children_.erase(it);
			tc_->tree_.deleteNode(hit);
			return S_OK;
		}
		i++;
		hit = tc_->tree_.getNextItem(hit);
	}
	return S_FALSE;
}

HRESULT __stdcall TreeElement::Clear()
{
	for ( std::vector< ITreeElement* >::iterator it = children_.begin(); it != children_.end(); it++)
	{
		(*it)->Clear();
	}
	HTREEITEM hit = tc_->tree_.getChildItem(item_);
	while(hit)
	{
		tc_->tree_.deleteNode(hit);
		hit = tc_->tree_.getNextItem(hit);
	}

	for ( std::vector< ITreeElement* >::iterator it = children_.begin(); it != children_.end(); it++)
	{
		::CoDisconnectObject( (IUnknown*)(*it),0);
		(*it)->Release();
	}
	children_.clear();
	return S_FALSE;
}

HRESULT __stdcall TreeElement::Load( LPSTREAM pStm)
{
	return S_OK;
}

HRESULT __stdcall TreeElement::Save( LPSTREAM pStm,BOOL fClearDirty)
{
	return S_OK;
}

HRESULT __stdcall TreeElement::Load( IPropertyBag *pPropBag,IErrorLog *pErrorLog)
{
	return S_OK;
}

HRESULT __stdcall TreeElement::Save( IPropertyBag *pPropBag,BOOL fClearDirty,BOOL fSaveAllProperties)
{
	return S_OK;
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

TreeCtrl::TreeCtrl(void)	
{
	eraseBackground_ = 1;

	sizel.cx = 300;
	sizel.cy = 200;
	mol::ole::PixeltoHIMETRIC(&sizel);
}

//////////////////////////////////////////////////////////////////////////////

TreeCtrl::~TreeCtrl()
{
	
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//
// OnDestroy - over and out
//
//////////////////////////////////////////////////////////////////////////////

LRESULT TreeCtrl::OnDestroy(UINT msg, WPARAM wParam, LPARAM lParam)
{
	root_->Clear();

	::CoDisconnectObject( (IUnknown*)(root_.interface_),0);
	root_.release();
    return 0;
}
//////////////////////////////////////////////////////////////////////////////

LRESULT TreeCtrl::OnCreate(UINT msg, WPARAM wParam, LPARAM lParam)
{
    RECT clientRect;
	getClientRect(clientRect);
	tree_.create(0,clientRect,*this);
	tree_.show(SW_SHOW);

	mol::variant v;
	root_ = TreeElement::CreateInstance(this,mol::bstr("ROOT"),v,TVI_ROOT);
	root_->Release();

	return 0;
}

LRESULT TreeCtrl::OnSize(UINT msg, WPARAM wParam, LPARAM lParam)
{
	getClientRect(clientRect_);
		
	// get new width and height
	clientRect_.right  = LOWORD (lParam) ;
	clientRect_.bottom = HIWORD (lParam) ;

	tree_.move(clientRect_);
	return 0;
}












/*

LRESULT TreeCtrl::OnTreeKeyDown(UINT msg, WPARAM wParam, LPARAM lParam)
{
	mol::Crack message(msg,wParam,lParam);
	WORD wd = message.keydown()->wVKey;
	if (GetAsyncKeyState(VK_CONTROL) < 0) 
	{
		/*
		if ( wd == 0x43 ) // C
		{
			Copy();
			return 1;
		}
		if ( wd == 0x58 ) // X
		{
			Cut();
			return 1;
		}
		if ( wd == 0x56 ) // V
		{
			Paste();
			return 1;
		}
		* /
	}
	return 0;
}
*/
//////////////////////////////////////////////////////////////////////////////
//
// Context Menue
//
//////////////////////////////////////////////////////////////////////////////

LRESULT TreeCtrl::OnTreeContext(UINT msg, WPARAM wParam, LPARAM lParam)
{
	mol::Crack message(msg,wParam,lParam);

	HTREEITEM hit = tree_.getSelection();
    TVHITTESTINFO& tvti = tree_.hitTest();
    if ( tvti.hItem )
		hit = tvti.hItem;

	tree_.setSelection(hit);		

	ITreeElement* el = (ITreeElement*)tree_.getLPARAM(hit);
	fire(DISPID_ITREECTRLEVENTS_ONTREERIGHTCLICK,mol::variant(el));

	return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// Tree item expanding - lazy populate
//
//////////////////////////////////////////////////////////////////////////////

LRESULT TreeCtrl::OnTreeItemExpanding(UINT msg, WPARAM wParam, LPARAM lParam)
{
	mol::Crack message(msg,wParam,lParam);
    if ( !(message.nmtreeview()->itemNew.state & TVIS_EXPANDED) )
    {
        return 0;
    }
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// Tree item dblClick
//
//////////////////////////////////////////////////////////////////////////////

LRESULT TreeCtrl::OnTreeDblClick(UINT msg, WPARAM wParam, LPARAM lParam)
{
	LRESULT r = 0;
	mol::Crack message(msg,wParam,lParam);
	
	HTREEITEM root = TreeView_GetRoot(((HWND)tree_));

    TVHITTESTINFO& tvti = tree_.hitTest();
    if ( !tvti.hItem )
		return 1;

	HTREEITEM hit = tvti.hItem;
	if ( hit == root )
		r = 1;

	ITreeElement* el = (ITreeElement*)tree_.getLPARAM(hit);
	fire(DISPID_ITREECTRLEVENTS_ONTREEDBLCLICK,mol::variant());

	return r;
}

//////////////////////////////////////////////////////////////////////////////
//
// Tree selection changed 
//
//////////////////////////////////////////////////////////////////////////////

LRESULT TreeCtrl::OnTreeClick(UINT msg, WPARAM wParam, LPARAM lParam)
{
	this->inplaceActivate();
	this->uiActivate();
	return 0;
}

LRESULT TreeCtrl::OnTreeSelection(UINT msg, WPARAM wParam, LPARAM lParam)
{
	LRESULT r = 0;
	mol::Crack message(msg,wParam,lParam);

	HTREEITEM hit = message.nmtreeview()->itemNew.hItem;
	if (!hit)
		return 0;

	ITreeElement* el = (ITreeElement*)tree_.getLPARAM(hit);
	this->fire( DISPID_ITREECTRLEVENTS_ONTREECLICK, mol::variant(el) );
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// Begin LabelEdit
//
//////////////////////////////////////////////////////////////////////////////
/*
LRESULT TreeCtrl::OnTreeBeginLabelEdit(UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// Begin Drag Drop from Tree
//
//////////////////////////////////////////////////////////////////////////////

LRESULT TreeCtrl::OnTreeBeginDrag(UINT msg, WPARAM wParam, LPARAM lParam)
{
	mol::Crack message(msg,wParam,lParam);
   	HTREEITEM hti = message.nmtreeview()->itemNew.hItem;

	mol::string p(getItemPath(hti));
	if ( !mol::Path::isDir(p) && !mol::Path::exists(p) )
		return 0;

	if ( mol::Path::isRoot(p) )
		return 0;
    
	HIMAGELIST himl = TreeView_CreateDragImage( tree_, hti ); 

	mol::ImageList::beginDrag(*this,himl);
	mol::ImageList::enterDrag(*this);

	std::vector<mol::string> v;
	v.push_back(p);

	punk<IDropSource> drop = new DropSrc;
	punk<IDataObject> ido  = new ShellDataObj( mol::events::event_handler( &ShellTree::OnDataObject,this),v);

	DWORD effect;
	HRESULT r = ::DoDragDrop(ido,drop,DROPEFFECT_COPY|DROPEFFECT_MOVE ,&effect);

	mol::ImageList::drop(*this);
	TreeView_SelectDropTarget(tree_, NULL); 

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////
// DataObject notifies of cut operation, update tree
/////////////////////////////////////////////////////////////////////////////////

LRESULT TreeCtrl::OnDataObject(IDataObject* data)
{
//    IDataObject* data = (IDataObject*)lParam;
	std::vector<mol::string> v = vectorFromDataObject(data);

	if ( v.size() == 0 )
		return 0;
	mol::string p(v[0]);
	p = mol::Path::parentDir(p);
	
	if ( mol::Path::isDir(p) )
	{
		HTREEITEM it = findItemByPath(p);
		if ( it )
			displayItem(it);
	}
	
	tree_.invalidateRect(0,TRUE);
	tree_.update();
    return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// Rename a Tree View Ctrl
//
//////////////////////////////////////////////////////////////////////////////

LRESULT TreeCtrl::OnTreeRename(UINT msg, WPARAM wParam, LPARAM lParam)
{
	mol::Crack message(msg,wParam,lParam);
	if ( message.treeViewDispInfo()->item.pszText )
	{
		HTREEITEM hit = this->tree_.getParentItem(message.treeViewDispInfo()->item.hItem);

		mol::string pFrom(getItemPath(message.treeViewDispInfo()->item.hItem));
		mol::string pTo( mol::Path::pathname(pFrom) );
		pTo = mol::Path::append(pTo, message.treeViewDispInfo()->item.pszText);

		ShellFileOp sfo;
		if ( 0 == sfo.rename(*this,pFrom,pTo,FOF_ALLOWUNDO) )
		{
			displayItem( hit );
			return TRUE;
		}
	}
	return 0;
}

*/






//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall TreeCtrl::get_Root( ITreeElement** el)
{
	if (!el)
		return E_INVALIDARG;

	return root_.queryInterface(el);
}


HTREEITEM TreeCtrl::treeItemFromElement(HTREEITEM parent, ITreeElement* el)
{
	if ( el == root_.interface_ )
		return TVI_ROOT;

	HTREEITEM hit = tree_.getChildItem(parent);
	while(hit)
	{
		ITreeElement* e = (ITreeElement*)tree_.getLPARAM(hit);
		if ( e == el )
			return hit;

		HTREEITEM item = treeItemFromElement(hit,el);
		if ( item )
			return item;
		hit = tree_.getNextItem(hit);
	}
	return 0;
}

HRESULT __stdcall TreeCtrl::Create( ITreeElement* parent, BSTR txt, VARIANT value, ITreeElement** el)
{
	HTREEITEM hit = tree_.addNodeParam( mol::toString(txt), (LPARAM)0,treeItemFromElement(TVI_ROOT,parent));
	TreeElement::Instance* instance = TreeElement::CreateInstance(this,txt,value,hit);
	tree_.setLPARAM( hit, (LPARAM)instance);

	HRESULT hr = instance->QueryInterface(IID_ITreeElement,(void**)el);
	if ( hr != S_OK )
		return hr;

	hr = parent->Add(*el);
	return hr;
}

HRESULT __stdcall TreeCtrl::Clear()
{
	long cnt = 0;
	for ( long i = cnt-1; cnt >= 0; cnt--)
	{
		root_->Remove(i);
	}
	return S_OK;
}

HRESULT __stdcall TreeCtrl::ScrollIntoView(ITreeElement* el)
{

	return S_OK;
}


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
//
//////////////////////////////////////////////////////////////////////////////




HRESULT __stdcall TreeCtrl::Load( LPSTREAM pStm)
{
	/*pStm >> mol::property( mol::DispId(this,ShellFolderCtrl_Dispatch_DisplayFiles,VT_BOOL) )
		 >> mol::property( mol::DispId(this,ShellFolderCtrl_Dispatch_Selection,VT_BSTR) )
		 >> mol::property( &sizel );
		 */
	return S_OK;
}

HRESULT __stdcall TreeCtrl::Save( LPSTREAM pStm,BOOL fClearDirty)
{
	/*
	pStm << mol::property( mol::DispId(this,ShellFolderCtrl_Dispatch_DisplayFiles,VT_BOOL) )
		 << mol::property( mol::DispId(this,ShellFolderCtrl_Dispatch_Selection,VT_BSTR) )
		 << mol::property( &sizel );
		 */
	return S_OK;
}

HRESULT __stdcall TreeCtrl::Load( IPropertyBag *pPropBag,IErrorLog *pErrorLog)
{
	/*
	pPropBag >> mol::property( _T("displayfiles"), mol::DispId(this,ShellFolderCtrl_Dispatch_DisplayFiles,VT_BOOL) )
			 >> mol::property( _T("selection"), mol::DispId(this,ShellFolderCtrl_Dispatch_Selection,VT_BSTR) )
			 >> mol::property( _T("cs"), &sizel );
			 */
	return S_OK;
}

HRESULT __stdcall TreeCtrl::Save( IPropertyBag *pPropBag,BOOL fClearDirty,BOOL fSaveAllProperties)
{
	/*
	pPropBag << mol::property( _T("displayfiles"), mol::DispId(this,ShellFolderCtrl_Dispatch_DisplayFiles,VT_BOOL) )
			 << mol::property( _T("sSelection"), mol::DispId(this,ShellFolderCtrl_Dispatch_Selection,VT_BSTR) )
			 << mol::property( _T("cs"), &sizel );
			 */
	return S_OK;
}

