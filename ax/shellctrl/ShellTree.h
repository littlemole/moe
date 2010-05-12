#ifndef _MOL_SHELL_TREE_DEF_H_
#define _MOL_SHELL_TREE_DEF_H_

#include "win/Ole.h"
#include "win/IO.h"
#include "win/Shell.h"
#include "win/CoCtrl.h"
#include "win/MsgMap.h"
#include "win/DragDrop.h"
#include "shellCtrl_h.h"


///////////////////////////////////////////////////////////////////////////////
    
class ShellTreeCtrl;
class ShellTreeQueue;
class ShellTreeAction;

///////////////////////////////////////////////////////////////////////////////
// TreeEntry - stores Data associated with TreeItem
///////////////////////////////////////////////////////////////////////////////

struct TreeEntry
{
    TreeEntry(const std::string& fn,  mol::FileInfo& fi, int index )
        : filename(fn), fileinfo(fi), iconindex(index), isParsed(false)
    {}

	std::string		filename;
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
    ShellTreeAction(ShellTreeCtrl* sw);
    virtual void operator() () = 0;

protected:
    ShellTreeCtrl*  sw_;
};

///////////////////////////////////////////////////////////////////////////////

class ShellTreeActionPath : public ShellTreeAction
{
public:
    ShellTreeActionPath(ShellTreeCtrl* sw, const std::string& path);
    virtual void operator() ();
protected:
    std::string path_;
};

///////////////////////////////////////////////////////////////////////////////

class ShellTreeActionItem : public ShellTreeAction
{
public:
    ShellTreeActionItem(ShellTreeCtrl* sw, HTREEITEM hit);
    virtual void operator() ();
protected:
    HTREEITEM hit_;
};

///////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
// ShellTreeCtrl - windows explorer style
//////////////////////////////////////////////////////////////////

#define SHELL_TREE_CTRL_ON_IDATA_NOTIFY 101
#define SHELL_TREE_CTRL_ON_IO_NOTIFY    201

class ShellTreeCtrl : public mol::Window
{
friend class ShellTreeActionPath;
friend class ShellTreeActionItem;

public:
    ShellTreeCtrl();
	virtual ~ShellTreeCtrl();

    MSG_MAP_START(ShellTreeCtrl,mol::Window)
		MAP_MSG( WM_CREATE,							OnCreate			)
        MAP_MSG( WM_DESTROY,						OnDestroy			)
		MAP_MSG( WM_SIZE,							OnSize				)

        MAP_CMD( SHELL_TREE_CTRL_ON_IDATA_NOTIFY,	OnDataObject		)
        MAP_CMD( SHELL_TREE_CTRL_ON_IO_NOTIFY,  	OnFileOp			)

        MAP_NOTIFY_CODE(TVN_ITEMEXPANDING,			OnTreeItemExpanding )
        MAP_NOTIFY_CODE(NM_CLICK,					OnTreeSelection     )
        MAP_NOTIFY_CODE(TVN_BEGINDRAG,				OnTreeBeginDrag     )
		MAP_NOTIFY_CODE(TVN_BEGINLABELEDIT,			OnTreeBeginLabelEdit)
        MAP_NOTIFY_CODE(TVN_ENDLABELEDIT,			OnTreeRename        )
        MAP_NOTIFY_CODE(TVN_KEYDOWN,				OnTreeKeyDown		)
        MAP_NOTIFY_CODE(NM_DBLCLK,					OnTreeDblClick		)
        MAP_NOTIFY_CODE(NM_RCLICK ,					OnContext			)
    MSG_MAP_END()

		LRESULT virtual OnCreate				(  UINT, WPARAM, LPARAM );
	    LRESULT virtual OnDestroy				(  UINT, WPARAM, LPARAM );
		LRESULT virtual OnSize   				(  UINT, WPARAM, LPARAM );

        LRESULT virtual OnDataObject			(  UINT, WPARAM, LPARAM );
        LRESULT virtual OnFileOp				(  UINT, WPARAM, LPARAM );

		LRESULT virtual OnTreeItemExpanding		(  UINT, WPARAM, LPARAM );
		LRESULT virtual OnTreeSelection			(  UINT, WPARAM, LPARAM );
		LRESULT virtual OnTreeBeginLabelEdit	(  UINT, WPARAM, LPARAM );
		LRESULT virtual OnTreeBeginDrag			(  UINT, WPARAM, LPARAM );
		LRESULT virtual OnTreeRename			(  UINT, WPARAM, LPARAM );
		LRESULT virtual OnTreeKeyDown			(  UINT, WPARAM, LPARAM );
        LRESULT virtual OnTreeDblClick			(  UINT, WPARAM, LPARAM );
		LRESULT virtual OnContext				(  UINT, WPARAM, LPARAM );

		// default handlers - this provide default handling to be mapped
        // in derived/containing class

		LRESULT virtual OnUpdate				( UINT, WPARAM, LPARAM );
		LRESULT virtual OnCut					( UINT, WPARAM, LPARAM );
		LRESULT virtual OnCopy					( UINT, WPARAM, LPARAM );
		LRESULT virtual OnPaste					( UINT, WPARAM, LPARAM );
		LRESULT virtual OnRename				( UINT, WPARAM, LPARAM );
		LRESULT virtual OnDelete				( UINT, WPARAM, LPARAM );
		LRESULT virtual OnProperties			( UINT, WPARAM, LPARAM );
		LRESULT virtual OnExecute				( UINT, WPARAM, LPARAM );
		LRESULT virtual OnRemove				( UINT, WPARAM, LPARAM );
		LRESULT virtual OnCreateDir				( UINT, WPARAM, LPARAM );

// public helper methods

public:	

	std::string getPath();
	HTREEITEM getHitTest();

	bool addFolderNode(mol::Shit& shit);
	
protected:

    virtual int treeStyle()   { return WS_CHILD|WS_VISIBLE|TVS_HASLINES|TVS_EDITLABELS|TVS_HASBUTTONS; }
    virtual int treeExStyle() { return 0; }

	class ShellTree : public mol::TreeCtrl 
	{
	    public:
		OUTER_THIS_IMPL(ShellTreeCtrl,tree_);
		
		virtual int style()   { return This()->treeStyle(); }
		virtual int exstyle() { return This()->treeExStyle(); }

	} tree_;

    // init to default
	BOOL initDesk           ( bool displayFiles = true);

    // change selection
    BOOL displayPath ( const std::string& path);
	BOOL displayItem ( HTREEITEM item);

    // get item entry
	TreeEntry* getItemEntry( HTREEITEM it ) { return (TreeEntry*)tree_.getLPARAM(it); }

	// get full path (shell displayname) for item
    std::string getItemPath    ( HTREEITEM item );

	// get the ShellItem from TreeItem
	Shit getShellItem ( HTREEITEM item);

    // select a child item by name/path
    HTREEITEM getChildByPath  ( HTREEITEM item, const std::string& path);
	HTREEITEM findItemByPath  ( const std::string& path, HTREEITEM item = TVI_ROOT );

	// add a new FolderNode with assoc. Info
	HTREEITEM addFolderNode ( ShellFolder& folder, Shit& item, HTREEITEM node = TVI_ROOT, int state = TVIS_EXPANDED);

	// expand a particular folder and lazy populate 
    BOOL expandFolder       ( HTREEITEM item,bool force=true, int flags = TVE_EXPAND );

    // free TreeItem
    void free(HTREEITEM it = TVI_ROOT );


    // Drop Target 
    class ShellTreeCtrl_Drop: public mol::StackObj<mol::DropTargetImpl>
    {
        public : OUTER_THIS_IMPL(ShellTreeCtrl,Drop);
		HRESULT virtual __stdcall Drop( IDataObject* pDataObject, DWORD keyState, POINTL pt , DWORD* pEffect);
		HRESULT virtual __stdcall DragEnter( IDataObject*, DWORD, POINTL, DWORD* );
		HRESULT virtual __stdcall DragOver( DWORD, POINTL, DWORD* );
		HRESULT virtual __stdcall DragLeave();
    } Drop;


	static mol::WinThreadQueue<ShellTreeAction>           queue_;
    bool                            displayFiles_;
	RECT							clientRect_;
};

//////////////////////////////////////////////////////////////////////////////////

 // end namespace mol
#endif
