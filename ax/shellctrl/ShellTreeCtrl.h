#ifndef _MOL_SHELL_TREE_DEF_H_
#define _MOL_SHELL_TREE_DEF_H_

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
    
class ShellTreeCtrl;
class ShellTreeQueue;
class ShellTreeAction;

struct TreeEntry
{
	TreeEntry(const std::wstring& fn,  mol::FileInfo& fi, int index )
        : filename(fn), fileinfo(fi), iconindex(index), isParsed(false)
    {}

	std::wstring		filename;
	mol::FileInfo	fileinfo;
    int				iconindex;
    bool			isParsed;

	bool isDir()
	{
		return (fileinfo.attributes() & FILE_ATTRIBUTE_DIRECTORY) != 0;
	}
};



///////////////////////////////////////////////////////////////////////////////
// two different kind of tree actions - update the tree in backgrd thread
///////////////////////////////////////////////////////////////////////////////

class ShellTreeAction
{
public:
	virtual ~ShellTreeAction() {};
    ShellTreeAction(ShellTree* sw);
    virtual void operator() () = 0;

protected:
    ShellTree*  sw_;
};

///////////////////////////////////////////////////////////////////////////////

class ShellTreeActionPath : public ShellTreeAction
{
public:
    ShellTreeActionPath(ShellTree* sw, const std::wstring& path);
    virtual void operator() ();
	
protected:
	void openPath( const std::wstring& path, HTREEITEM parent);
    std::wstring path_;
};

///////////////////////////////////////////////////////////////////////////////

class ShellTreeActionItem : public ShellTreeAction
{
public:
    ShellTreeActionItem(ShellTree* sw, HTREEITEM hit);
    virtual void operator() ();
protected:
    HTREEITEM hit_;
};

///////////////////////////////////////////////////////////////////////////////

class ShellTreeActionInit : public ShellTreeAction
{
public:
    ShellTreeActionInit(ShellTree* sw);
    virtual void operator() ();

};

//////////////////////////////////////////////////////////////////
// ShellTreeCtrl - windows explorer style
//////////////////////////////////////////////////////////////////

//#define SHELL_TREE_CTRL_ON_IDATA_NOTIFY 101

class ShellTree: 
	public ax_ctrl<ShellTree,CLSID_ShellTree,false,mol::Window,WS_CHILD|WS_CLIPSIBLINGS|WS_CLIPCHILDREN,0>,
	public Dispatch<IShellTree>,
	public ctrl_events<ShellTree,_IShellTreeEvents>,
	public ProvideClassInfo2<ShellTree,DIID__IShellTreeEvents>,
	public interfaces< ShellTree, 
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
				IProvideClassInfo2>
		>
{
friend class ShellTreeActionPath;
friend class ShellTreeActionItem;
friend class ShellTreeActionInit;
public:
    ShellTree();
	virtual ~ShellTree();

	msg_handler( WM_CREATE, OnCreate )
		LRESULT virtual OnCreate( UINT, WPARAM, LPARAM );

	msg_handler( WM_DESTROY, OnDestroy )
	    LRESULT virtual OnDestroy( UINT, WPARAM, LPARAM );

	msg_handler( WM_SIZE, OnSize )
		LRESULT virtual OnSize( UINT, WPARAM, LPARAM );

//	cmd_handler( SHELL_TREE_CTRL_ON_IDATA_NOTIFY, OnDataObject )
        LRESULT virtual OnDataObject( IDataObject* data );

	notify_code_handler( TVN_ITEMEXPANDING, OnTreeItemExpanding )
		LRESULT virtual OnTreeItemExpanding( UINT, WPARAM, LPARAM );

	notify_code_handler( NM_CLICK, OnTreeClick )
		LRESULT virtual OnTreeClick( UINT, WPARAM, LPARAM );

	notify_code_handler( TVN_SELCHANGED, OnTreeSelection )
		LRESULT virtual OnTreeSelection( UINT, WPARAM, LPARAM );

	notify_code_handler( TVN_BEGINLABELEDIT, OnTreeBeginLabelEdit )
		LRESULT virtual OnTreeBeginLabelEdit( UINT, WPARAM, LPARAM );

	notify_code_handler( TVN_BEGINDRAG, OnTreeBeginDrag )
		LRESULT virtual OnTreeBeginDrag( UINT, WPARAM, LPARAM );

	notify_code_handler( TVN_ENDLABELEDIT, OnTreeRename )
		LRESULT virtual OnTreeRename( UINT, WPARAM, LPARAM );

	notify_code_handler( TVN_KEYDOWN, OnTreeKeyDown )
		LRESULT virtual OnTreeKeyDown( UINT, WPARAM, LPARAM );

	notify_code_handler( NM_DBLCLK, OnTreeDblClick )
        LRESULT virtual OnTreeDblClick( UINT, WPARAM, LPARAM );

	notify_code_handler( NM_RCLICK, OnTreeContext )
		LRESULT virtual OnTreeContext( UINT, WPARAM, LPARAM );

	// COM properties

	HRESULT virtual __stdcall get_DisplayFiles	( VARIANT_BOOL* vb );
	HRESULT virtual __stdcall put_DisplayFiles	( VARIANT_BOOL vb  );

	HRESULT virtual __stdcall get_Selection		( BSTR* dirname );
	HRESULT virtual __stdcall put_Selection		( BSTR  dirname );

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

	virtual void initAmbientProperties( IDispatch* disp)
	{
		HIMAGELIST himl = TreeView_GetImageList(tree_,TVSIL_NORMAL);
		COLORREF col;
		variant v(bgCol_);
		if ( S_OK == get(disp,DISPID_AMBIENT_BACKCOLOR,&v) )
		{
			bgCol_ = v.lVal;			
			::OleTranslateColor(bgCol_,0,&col);
			TreeView_SetBkColor(tree_,col);
			ImageList_SetBkColor(himl,CLR_NONE );
		}

		if ( S_OK == get(disp,DISPID_AMBIENT_FORECOLOR,&v) )
		{
			foreCol_ = v.lVal;
			::OleTranslateColor(foreCol_,0,&col);
			TreeView_SetTextColor(tree_,col);
			TreeView_SetLineColor(tree_,col);
		}
	}

protected:

    virtual int treeStyle()   { return WS_CHILD|WS_VISIBLE|TVS_HASLINES|TVS_EDITLABELS|TVS_HASBUTTONS|TVS_SHOWSELALWAYS; }
    virtual int treeExStyle() { return WS_EX_ACCEPTFILES; }

	class ShellTreeCtrl : 
		public mol::TreeCtrl
	{
	    public:

			virtual ~ShellTreeCtrl() { ODBGS("~ShellTreeCtrl"); }

			outer_this(ShellTree,tree_);
			
			virtual int style()   { return This()->treeStyle(); }
			virtual int exstyle() { return This()->treeExStyle(); }

	} tree_;

    // init to default
	BOOL initDesk           ( bool displayFiles = true);

    // change selection
    BOOL displayPath ( const std::wstring& path);
	BOOL displayItem ( HTREEITEM item);

    // get item entry
	TreeEntry* getItemEntry( HTREEITEM it ) { return (TreeEntry*)tree_.getLPARAM(it); }

	// get full path (shell displayname) for item
    std::wstring getItemPath    ( HTREEITEM item );

	// get the ShellItem from TreeItem
	Shit getShellItem ( HTREEITEM item);

    // select a child item by name/path
    HTREEITEM getChildByPath  ( HTREEITEM item, const std::wstring& path);
	HTREEITEM findItemByPath  ( const std::wstring& path, HTREEITEM item = TVI_ROOT );

	// add a new FolderNode with assoc. Info
	HTREEITEM addFolderNode ( ShellFolder& folder, Shit& item, HTREEITEM node = TVI_ROOT, int state = TVIS_EXPANDED);

	// expand a particular folder and lazy populate 
    BOOL expandFolder       ( HTREEITEM item,bool force=true, int flags = TVE_EXPAND );


    // free TreeItem
    void release(HTREEITEM it = TVI_ROOT );

	// get hit test
	HTREEITEM getHitTest();

	// get current path
	std::wstring getPath();

    // Drop Target 
    class ShellTreeCtrl_Drop: public DropTarget
    {
    public : 
		ShellTreeCtrl_Drop(ShellTree* t) : tree_(t) {}
		HRESULT virtual __stdcall Drop( IDataObject* pDataObject, DWORD keyState, POINTL pt , DWORD* pEffect);
		HRESULT virtual __stdcall DragEnter( IDataObject*, DWORD, POINTL, DWORD* );
		HRESULT virtual __stdcall DragOver( DWORD, POINTL, DWORD* );
		HRESULT virtual __stdcall DragLeave();
	protected:
		ShellTree* tree_;
    } ;

	punk<ShellTreeCtrl_Drop> Drop;

	class ThreadStartPolicy 
	{
	public:
		void operator()(){ ::CoInitialize(0); };
	};

	class ThreadShutdownPolicy 
	{
	public:
		void operator()(){ ::CoUninitialize(); };
	};

	mol::ThreadQueue<ShellTreeAction,true,ThreadStartPolicy,ThreadShutdownPolicy>			queue_;
    bool										displayFiles_;
	bool										useContext_;
	RECT										clientRect_;
	OLE_COLOR									bgCol_;
	OLE_COLOR									foreCol_;
	mol::Menu									treeMenu_;
};


#endif
