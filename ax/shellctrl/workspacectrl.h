#ifndef _MOL_WORKSPACE_TREE_DEF_H_
#define _MOL_WORKSPACE_TREE_DEF_H_

#include "win/io/IO.h"
#include "win/io/Shell.h"
#include "win/CoCtrl.h"
#include "win/MsgMap.h"
#include "win/ole/DragDrop.h"
#include "win/ole/Ctrl.h"
#include "shellCtrl_h.h"

#include "shellCtrl_h.h"
 
#include "win/Layout.h"
#include "resource.h"


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// WorkSpaceEntry - stores Data associated with TreeItem
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
    
class WorkSpaceCtrl;
class WorkSpaceQueue;
class WorkSpaceAction;

struct WorkSpaceEntry
{
    WorkSpaceEntry(const mol::string& fn,  mol::FileInfo& fi, int index )
        : filename(fn), fileinfo(fi), iconindex(index), isParsed(false)
    {}

	mol::string		filename;
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

class WorkSpaceAction
{
public:
	virtual ~WorkSpaceAction() {};
    WorkSpaceAction(WorkSpaceCtrl* sw);
    virtual void operator() () = 0;

protected:
    WorkSpaceCtrl*  sw_;
};

///////////////////////////////////////////////////////////////////////////////

class WorkSpaceActionPath : public WorkSpaceAction
{
public:
    WorkSpaceActionPath(WorkSpaceCtrl* sw, const mol::string& path);
    virtual void operator() ();
	
protected:
	void openPath( const mol::string& path, HTREEITEM parent);
    mol::string path_;
};

///////////////////////////////////////////////////////////////////////////////

class WorkSpaceActionItem : public WorkSpaceAction
{
public:
    WorkSpaceActionItem(WorkSpaceCtrl* sw, HTREEITEM hit);
    virtual void operator() ();
protected:
    HTREEITEM hit_;
};

///////////////////////////////////////////////////////////////////////////////

class WorkSpaceActionInit : public WorkSpaceAction
{
public:
    WorkSpaceActionInit(WorkSpaceCtrl* sw);
    virtual void operator() ();

};


//////////////////////////////////////////////////////////////////
// WorkSpaceCtrl - windows explorer style
//////////////////////////////////////////////////////////////////

#define WORK_SPACE_CTRL_ON_IDATA_NOTIFY 101

class WorkSpaceCtrl: 
	public mol::AxControl<WorkSpaceCtrl,CLSID_WorkSpace,false,mol::Window,WS_CHILD|WS_CLIPSIBLINGS|WS_CLIPCHILDREN,0>,
	public mol::Dispatch<IWorkSpace>,
	public mol::CtrlConnectionPoint<WorkSpaceCtrl,_IWorkSpaceEvents>,
	public mol::ProvideClassInfo2<WorkSpaceCtrl,DIID__IWorkSpaceEvents>
{
friend class WorkSpaceActionPath;
friend class WorkSpaceActionItem;
friend class WorkSpaceActionInit;
public:
    WorkSpaceCtrl();
	virtual ~WorkSpaceCtrl();

	PERSIST_MEMBER(WorkSpaceCtrl,cx_,sizel_.cx);
	PERSIST_MEMBER(WorkSpaceCtrl,cy_,sizel_.cy);
	PERSIST_PROPERTY(WorkSpaceCtrl,1,VT_BOOL,&CLSID_NULL)
	PERSIST_PROPERTY(WorkSpaceCtrl,2,VT_BSTR,&CLSID_NULL)

	INTERFACE_MAP_START(WorkSpaceCtrl)
        INTERFACE_ENTRY(IDispatch)
        INTERFACE_ENTRY(IWorkSpace)
		INTERFACE_ENTRY(IOleObject)
		INTERFACE_ENTRY(IDataObject)
		INTERFACE_ENTRY_EX(IPersist,IPersistStreamInit)
		INTERFACE_ENTRY_EX(IPersistStream,IPersistStreamInit)
		INTERFACE_ENTRY(IPersistStreamInit)
		INTERFACE_ENTRY(IPersistStorage)
		INTERFACE_ENTRY(IPersistPropertyBag)
		INTERFACE_ENTRY(IRunnableObject)
		INTERFACE_ENTRY(IViewObject)
		INTERFACE_ENTRY(IViewObject2)
		INTERFACE_ENTRY_EX(IOleWindow,IOleInPlaceObjectWindowless)
		INTERFACE_ENTRY_EX(IOleInPlaceObject,IOleInPlaceObjectWindowless)
		//INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
		INTERFACE_ENTRY(IOleControl)
		INTERFACE_ENTRY(IConnectionPointContainer)
		INTERFACE_ENTRY(IProvideClassInfo)
		INTERFACE_ENTRY(IProvideClassInfo2)
		//INTERFACE_ENTRY(ISpecifyPropertyPages)
    INTERFACE_MAP_END()

    MSG_MAP_START(WorkSpaceCtrl,OleWndType)
		MAP_MSG( WM_CREATE,							OnCreate			)
        MAP_MSG( WM_DESTROY,						OnDestroy			)
		MAP_MSG( WM_SIZE,							OnSize				)
		//MAP_MSG( WM_SETFOCUS ,						OnFocus				)

        MAP_CMD( WORK_SPACE_CTRL_ON_IDATA_NOTIFY,	OnDataObject		)
        //MAP_CMD( SHELL_TREE_CTRL_ON_IO_NOTIFY,  	OnFileOp			)

		MAP_NOTIFY_CODE(TVN_SELCHANGED,				OnTreeSelection )
        MAP_NOTIFY_CODE(TVN_ITEMEXPANDING,			OnTreeItemExpanding )
        MAP_NOTIFY_CODE(NM_CLICK,					OnTreeClick     )
        MAP_NOTIFY_CODE(TVN_BEGINDRAG,				OnTreeBeginDrag     )
		MAP_NOTIFY_CODE(TVN_BEGINLABELEDIT,			OnTreeBeginLabelEdit)
        MAP_NOTIFY_CODE(TVN_ENDLABELEDIT,			OnTreeRename        )
        MAP_NOTIFY_CODE(TVN_KEYDOWN,				OnTreeKeyDown		)
        MAP_NOTIFY_CODE(NM_DBLCLK,					OnTreeDblClick		)
        MAP_NOTIFY_CODE(NM_RCLICK ,					OnTreeContext		)
    MSG_MAP_END()

		LRESULT virtual OnCreate				(  UINT, WPARAM, LPARAM );
	    LRESULT virtual OnDestroy				(  UINT, WPARAM, LPARAM );
		LRESULT virtual OnSize   				(  UINT, WPARAM, LPARAM );
		LRESULT virtual OnFocus   				(  UINT, WPARAM, LPARAM );

        LRESULT virtual OnDataObject			(  UINT, WPARAM, LPARAM );
       // LRESULT virtual OnFileOp				(  UINT, WPARAM, LPARAM );

		LRESULT virtual OnTreeItemExpanding		(  UINT, WPARAM, LPARAM );
		LRESULT virtual OnTreeClick 			(  UINT, WPARAM, LPARAM );
		LRESULT virtual OnTreeSelection			(  UINT, WPARAM, LPARAM );
		LRESULT virtual OnTreeBeginLabelEdit	(  UINT, WPARAM, LPARAM );
		LRESULT virtual OnTreeBeginDrag			(  UINT, WPARAM, LPARAM );
		LRESULT virtual OnTreeRename			(  UINT, WPARAM, LPARAM );
		LRESULT virtual OnTreeKeyDown			(  UINT, WPARAM, LPARAM );
        LRESULT virtual OnTreeDblClick			(  UINT, WPARAM, LPARAM );
		LRESULT virtual OnTreeContext			(  UINT, WPARAM, LPARAM );

		// COM properties

		HRESULT virtual __stdcall get_Selection		( BSTR* dirname );
		HRESULT virtual __stdcall put_Selection		( BSTR  dirname );

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
		HRESULT virtual __stdcall Add				(BSTR path);
		HRESULT virtual __stdcall Remove			(BSTR path);
		HRESULT virtual __stdcall CreateDir     	();


	virtual void initAmbientProperties( IDispatch* disp)
	{
		HIMAGELIST himl = TreeView_GetImageList(tree_,TVSIL_NORMAL);
		COLORREF col;
		mol::Variant v(bgCol_);
		if ( S_OK == mol::getDispProp(disp,DISPID_AMBIENT_BACKCOLOR,&v) )
		{
			bgCol_ = v.lVal;			
			::OleTranslateColor(bgCol_,0,&col);
			TreeView_SetBkColor(tree_,col);
			ImageList_SetBkColor(himl,CLR_NONE );
		}

		if ( S_OK == mol::getDispProp(disp,DISPID_AMBIENT_FORECOLOR,&v) )
		{
			foreCol_ = v.lVal;
			::OleTranslateColor(foreCol_,0,&col);
			TreeView_SetTextColor(tree_,col);
			TreeView_SetLineColor(tree_,col);
		}
	}

	
protected:

    virtual int treeStyle()   { return WS_CHILD|WS_VISIBLE|TVS_HASLINES|TVS_EDITLABELS|TVS_HASBUTTONS; }
    virtual int treeExStyle() { return WS_EX_ACCEPTFILES; }

	class WorkSpace : public mol::TreeCtrl 
	{
	    public:
		OUTER_THIS_IMPL(WorkSpaceCtrl,tree_);
		
		virtual int style()   { return This()->treeStyle(); }
		virtual int exstyle() { return This()->treeExStyle(); }

	} tree_;

    // init to default
	BOOL initWorkSpace           ( );

    // change selection
    BOOL displayPath ( const mol::string& path);
	BOOL displayItem ( HTREEITEM item);

    // get item entry
	WorkSpaceEntry* getItemEntry( HTREEITEM it ) { return (WorkSpaceEntry*)tree_.getLPARAM(it); }

	// get full path (shell displayname) for item
    mol::string getItemPath    ( HTREEITEM item );

	// get the ShellItem from TreeItem
	mol::Shit getShellItem ( HTREEITEM item);

    // select a child item by name/path
    HTREEITEM getChildByPath  ( HTREEITEM item, const mol::string& path);
	HTREEITEM findItemByPath  ( const mol::string& path, HTREEITEM item = TVI_ROOT );

	// add a new FolderNode with assoc. Info
	HTREEITEM addFolderNode ( mol::ShellFolder& folder, mol::Shit& item, HTREEITEM node = TVI_ROOT, int state = TVIS_EXPANDED);

	// expand a particular folder and lazy populate 
    BOOL expandFolder       ( HTREEITEM item,bool force=true, int flags = TVE_EXPAND );

    // free TreeItem
    void free(HTREEITEM it = TVI_ROOT );

	// get hit test
	HTREEITEM getHitTest();

	// get current path
	mol::string getPath();

    // Drop Target 
    class WorkSpaceCtrl_Drop: public mol::RefObj<mol::DropTargetImpl>
    {
    public : 
		WorkSpaceCtrl_Drop(WorkSpaceCtrl* t) : tree_(t) {}
		HRESULT virtual __stdcall Drop( IDataObject* pDataObject, DWORD keyState, POINTL pt , DWORD* pEffect);
		HRESULT virtual __stdcall DragEnter( IDataObject*, DWORD, POINTL, DWORD* );
		HRESULT virtual __stdcall DragOver( DWORD, POINTL, DWORD* );
		HRESULT virtual __stdcall DragLeave();
	protected:
		WorkSpaceCtrl* tree_;
    } ;

	mol::UnknownPtr<WorkSpaceCtrl_Drop> Drop;


	mol::ThreadQueue<WorkSpaceAction>			queue_;
    bool										displayFiles_;
	RECT										clientRect_;
	OLE_COLOR									bgCol_;
	OLE_COLOR									foreCol_;
	mol::Menu									treeMenu_;
};


#endif
