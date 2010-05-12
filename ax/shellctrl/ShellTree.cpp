#include "win/ShellTree.h"
#include "win/Img.h"
#include "util/Str.h"
#include <sstream>



///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

ShellTreeAction::ShellTreeAction(ShellTreeCtrl* sw)
:sw_(sw)
{}

///////////////////////////////////////////////////////////////////////

ShellTreeActionPath::ShellTreeActionPath(ShellTreeCtrl* sw, const std::string& path)
:ShellTreeAction(sw),path_(path)
{

}

///////////////////////////////////////////////////////////////////////

void ShellTreeActionPath::operator() ()
{
	mol::Path path(path_);
	if ( path.isDir() )
		path.removeBackSlash();

	HTREEITEM hit = sw_->findItemByPath(path);
	if ( !hit )
		 return;

    sw_->expandFolder(hit,true);
	TreeView_Select(sw_->tree_,hit,TVGN_CARET);	
	TreeView_EnsureVisible(sw_->tree_,hit);

	return;
}

///////////////////////////////////////////////////////////////////////

ShellTreeActionItem::ShellTreeActionItem(ShellTreeCtrl* sw, HTREEITEM hit)
:ShellTreeAction(sw),hit_(hit)
{}

void ShellTreeActionItem::operator() ()
{
	if (! sw_->tree_.getLPARAM(hit_))
		return;

    sw_->expandFolder(hit_,true);
	TreeView_Select(sw_->tree_,hit_,TVGN_CARET);	
	TreeView_EnsureVisible(sw_->tree_,hit_);
    return;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

mol::WinThreadQueue<ShellTreeAction> ShellTreeCtrl::queue_;

///////////////////////////////////////////////////////////////////////

ShellTreeCtrl::ShellTreeCtrl() 
{
}

///////////////////////////////////////////////////////////////////////

ShellTreeCtrl::~ShellTreeCtrl()	
{ 
    free(); 
}


///////////////////////////////////////////////////////////////////////
// ShellTree
///////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
//
// OnDestroy - over and out
//
//////////////////////////////////////////////////////////////////////////////

LRESULT ShellTreeCtrl::OnDestroy(UINT msg, WPARAM wParam, LPARAM lParam)
{
    mol::IO::unSubscribe(*this);
	::RevokeDragDrop(*this);
    return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// OnCreate - init child Windows and UI
//
//////////////////////////////////////////////////////////////////////////////

LRESULT ShellTreeCtrl::OnCreate(UINT msg, WPARAM wParam, LPARAM lParam)
{
	getClientRect(clientRect_);
	tree_.create( 1, clientRect_,*this);
    initDesk();
	::RegisterDragDrop(*this,&Drop);
    mol::IO::subscribe(*this,SHELL_TREE_CTRL_ON_IO_NOTIFY);
	return 0;
}

LRESULT ShellTreeCtrl::OnSize(UINT msg, WPARAM wParam, LPARAM lParam)
{
	getClientRect(clientRect_);
		
	// get new width and height
	clientRect_.right  = LOWORD (lParam) ;
	clientRect_.bottom = HIWORD (lParam) ;

	tree_.move(clientRect_);
	return 0;
}
//////////////////////////////////////////////////////////////////////////////


LRESULT ShellTreeCtrl::OnFileOp(UINT msg, WPARAM wParam, LPARAM lParam)
{
    mol::IO* io = (mol::IO*)lParam;
    if (!io)
        return 0;

	if ( io->Done() )
	{
		mol::Path to   = io->To();
		mol::Path from = io->From(0);

		from = from.parentDir();

		if ( to.isDir() )
		    displayPath(to);		
		if ( from.isDir() )
		    displayPath(from);		
	}
    return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// Key pressed events
//
//////////////////////////////////////////////////////////////////////////////

LRESULT ShellTreeCtrl::OnTreeKeyDown(UINT msg, WPARAM wParam, LPARAM lParam)
{
	mol::Crack message(msg,wParam,lParam);
	WORD wd = message.keydown()->wVKey;
	if (GetAsyncKeyState(VK_CONTROL) < 0) 
	{
		if ( wd == 0x43 ) // C
		{
			OnCopy(msg,wParam,lParam);
			return 1;
		}
		if ( wd == 0x58 ) // X
		{
			OnCut(msg,wParam,lParam);
			return 1;
		}
		if ( wd == 0x56 ) // V
		{
			OnPaste(msg,wParam,lParam);
			return 1;
		}
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////////

LRESULT ShellTreeCtrl::OnContext(UINT msg, WPARAM wParam, LPARAM lParam)
{
    return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// Events from Tree View Ctrl
//
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//
// Tree item expanding - lazy populate
//
//////////////////////////////////////////////////////////////////////////////

LRESULT ShellTreeCtrl::OnTreeItemExpanding(UINT msg, WPARAM wParam, LPARAM lParam)
{
	mol::Crack message(msg,wParam,lParam);
    if ( !(message.nmtreeview()->itemNew.state & TVIS_EXPANDED) )
    {
        displayItem(message.nmtreeview()->itemNew.hItem);
    }
	return 0;
}

LRESULT ShellTreeCtrl::OnTreeDblClick(UINT msg, WPARAM wParam, LPARAM lParam)
{
	mol::Crack message(msg,wParam,lParam);
    HTREEITEM hit = getHitTest();
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// Tree selection changed 
//
//////////////////////////////////////////////////////////////////////////////

LRESULT ShellTreeCtrl::OnTreeSelection(UINT msg, WPARAM wParam, LPARAM lParam)
{
	//::SendMessage(getParent(),msg,wParam,lParam);
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// Begin Drag Drop from Tree
//
//////////////////////////////////////////////////////////////////////////////

LRESULT ShellTreeCtrl::OnTreeBeginLabelEdit(UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}

LRESULT ShellTreeCtrl::OnTreeBeginDrag(UINT msg, WPARAM wParam, LPARAM lParam)
{
    mol::Crack message(msg,wParam,lParam);
   	HTREEITEM hti = message.nmtreeview()->itemNew.hItem;

	mol::Path path(getItemPath(hti));
	if ( !path.isDir() && !path.exists() )
		return 0;
	//beginDrag( hti );
    
	HIMAGELIST himl = TreeView_CreateDragImage( tree_, hti ); 

	mol::ImageList::beginDrag(*this,himl);
	mol::ImageList::enterDrag(*this);

	std::vector<std::string> v;
	v.push_back(path);

	mol::UnknownPtr<IDropSource> drop = new DropSource;
	mol::UnknownPtr<IDataObject> ido  = new ShellDataObject(*this,SHELL_TREE_CTRL_ON_IDATA_NOTIFY,v);

	DWORD effect;
	HRESULT r = ::DoDragDrop(ido,drop,DROPEFFECT_COPY|DROPEFFECT_MOVE ,&effect);

	mol::ImageList::drop(*this);
	TreeView_SelectDropTarget(tree_, NULL); 

    return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// Rename a Tree View Ctrl
//
//////////////////////////////////////////////////////////////////////////////

LRESULT ShellTreeCtrl::OnTreeRename(UINT msg, WPARAM wParam, LPARAM lParam)
{
	mol::Crack message(msg,wParam,lParam);
	if ( message.treeViewDispInfo()->item.pszText )
	{
		mol::Path pFrom(getItemPath(message.treeViewDispInfo()->item.hItem));
		mol::Path pTo(pFrom.pathname());
		pTo.append(message.treeViewDispInfo()->item.pszText);

		mol::RenameFile rf(pFrom,pTo,false );
		rf.execute();
		return TRUE;
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// Update focused dir
//
//////////////////////////////////////////////////////////////////////////////

LRESULT ShellTreeCtrl::OnUpdate(UINT msg, WPARAM wParam, LPARAM lParam)
{
	HTREEITEM hit = tree_.getSelection();
	if ( hit )
	{   
		displayItem(hit);
	}
	return true;
}

//////////////////////////////////////////////////////////////////////////////
//
// Cut selected tree item
//
//////////////////////////////////////////////////////////////////////////////

LRESULT ShellTreeCtrl::OnCut (UINT msg, WPARAM wParam, LPARAM lParam)
{
	HTREEITEM hit = tree_.getSelection();
	if ( hit )
	{
		tree_.setItemState(hit,TVIS_CUT,TVIS_CUT);
		std::vector<std::string> v;
		v.push_back(getItemPath(hit));
		mol::UnknownPtr<IDataObject> ido = new ShellDataObject(*this,SHELL_TREE_CTRL_ON_IDATA_NOTIFY, v,true);        
		HRESULT r = ::OleSetClipboard(ido);
	}
	return true;
}

//////////////////////////////////////////////////////////////////////////////
//
// Copy selected tree item
//
//////////////////////////////////////////////////////////////////////////////

LRESULT ShellTreeCtrl::OnCopy (UINT msg, WPARAM wParam, LPARAM lParam)
{
	HTREEITEM hit = tree_.getSelection();
	if ( hit )
	{
		tree_.setItemState(hit,TVIS_CUT,0);
		std::vector<std::string> v;
		v.push_back(getItemPath(hit));
		mol::UnknownPtr<IDataObject> ido = new ShellDataObject(*this,SHELL_TREE_CTRL_ON_IDATA_NOTIFY,v);
		HRESULT r = ::OleSetClipboard(ido);
	}
	return true;
}

//////////////////////////////////////////////////////////////////////////////
//
// Paste into tree view
//
//////////////////////////////////////////////////////////////////////////////

LRESULT ShellTreeCtrl::OnPaste (UINT msg, WPARAM wParam, LPARAM lParam)
{
	mol::UnknownPtr<IDataObject> ido;
	::OleGetClipboard(&ido);
	if ( !ido )
		return false;

	std::vector<std::string> v = vectorFromDataObject(ido);
	if ( v.size() < 1 )
		return false;

	HTREEITEM hit = tree_.getSelection();
	if ( hit )
	{
		mol::Path path = getItemPath(hit);
		if ( path.isDir() )
		{
			DWORD  dw = DROPEFFECT_COPY;
			mol::FormatEtcPrefDropEffect	fe;
            mol::FormatEtcDropEffect        de;
			STGMEDIUM						sm;

			if ( S_OK == ido->GetData( &fe, &sm ) )
			{
				if ( sm.tymed == TYMED_HGLOBAL )
					mol::get(sm.hGlobal,dw);
			}
			if (dw & DROPEFFECT_COPY )
			{

				mol::CopyFiles cf(v,path, false );
				cf.execute();
			}
			else if (dw & DROPEFFECT_MOVE )
			{
				mol::MoveFiles mf(v,path, false );
				mf.execute();
			}
            ido->SetData( &de, &sm, FALSE );
		}
	}
	return true;
}

//////////////////////////////////////////////////////////////////////////////
//
// rename selected tree or dir item
//
//////////////////////////////////////////////////////////////////////////////

LRESULT ShellTreeCtrl::OnRename(UINT msg, WPARAM wParam, LPARAM lParam)
{
	HTREEITEM hit = tree_.getSelection();
	if ( hit )
		tree_.editLabel(hit);
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// delete selected tree or dir item
//
//////////////////////////////////////////////////////////////////////////////

LRESULT ShellTreeCtrl::OnDelete(UINT msg, WPARAM wParam, LPARAM lParam)
{
	HTREEITEM hit = tree_.getSelection();
	if ( hit )
	{
		mol::Path path = getItemPath(hit);
		std::string s = getItemPath(hit);
		mol::DeleteFile df(s);
		df.execute();
	}
	return 0;
}


//////////////////////////////////////////////////////////////////////////////
//
// properties of selected tree or dir item
//
//////////////////////////////////////////////////////////////////////////////

LRESULT ShellTreeCtrl::OnProperties(UINT msg, WPARAM wParam, LPARAM lParam)
{
	HTREEITEM hit = tree_.getSelection();
	std::string s  = (getItemPath(hit));

	mol::ExecuteShell(s,"properties");

/*	SHELLEXECUTEINFO sei;
	ZeroMemory(&sei,sizeof(sei));
	sei.cbSize = sizeof(sei);
	sei.lpVerb = "properties";
	sei.lpFile = s.c_str();
	sei.nShow  = SW_SHOWNORMAL;
    sei.fMask  = SEE_MASK_INVOKEIDLIST; 

	::ShellExecuteEx(&sei);
*/
	return 0;
}


//////////////////////////////////////////////////////////////////////////////
//
// shellexecute selected tree or dir item
//
//////////////////////////////////////////////////////////////////////////////

LRESULT ShellTreeCtrl::OnExecute(UINT msg, WPARAM wParam, LPARAM lParam)
{
	HTREEITEM hit = tree_.getSelection();
	std::string s  = (getItemPath(hit));

	mol::ExecuteShell(s);

/*	SHELLEXECUTEINFO sei;
	ZeroMemory(&sei,sizeof(sei));
	sei.cbSize = sizeof(sei);
	sei.lpVerb = "open";
	sei.lpFile = s.c_str();
	sei.nShow  = SW_SHOWNORMAL;
    sei.fMask  = SEE_MASK_INVOKEIDLIST; 

	::ShellExecuteEx(&sei);
*/
	return 0;
}
//////////////////////////////////////////////////////////////////////////////
LRESULT ShellTreeCtrl::OnCreateDir(UINT msg, WPARAM wParam, LPARAM lParam)
{
	if ( wParam )
	{
		mol::Path path((char*)wParam);
		if (! ::CreateDirectory(path.c_str(),0) )
		{
			::MessageBox(0,path.c_str(),"error creating dir",0);
		}
		return 0;
	}
	std::string tmp = "newDir_";	
	int i = 0;
	while(true)
	{
		mol::Path path(getPath());
		std::stringstream oss;
		oss << tmp << i;
		path.append(oss.str());
		if ( ::CreateDirectory(path.c_str(),0) )
		{
			return 0;
		}
		i++;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

LRESULT ShellTreeCtrl::OnRemove(UINT msg, WPARAM wParam, LPARAM lParam)
{
	HTREEITEM hit = tree_.getSelection();
	if ( hit )
	{
        mol::Path p = getItemPath(hit);
        if ( !p.isRoot() )
        {
		    HTREEITEM parent = tree_.getParentItem(hit);
		    free(hit);
		    displayItem(parent);
        }
	}
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////

LRESULT ShellTreeCtrl::OnDataObject(UINT msg, WPARAM wParam, LPARAM lParam)
{
    IDataObject* data = (IDataObject*)lParam;
	std::vector<std::string> v = vectorFromDataObject(data);

	if ( v.size() == 0 )
		return 0;
	mol::Path path(v[0]);
	path = path.parentDir();
	if ( path.isDir() )
	{
		HTREEITEM it = findItemByPath(path);
		if ( it )
			displayItem(it);
	}
	tree_.invalidateRect(0,TRUE);
	tree_.update();
    return 0;
}
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////

std::string ShellTreeCtrl::getPath()
{
	HTREEITEM hit = tree_.getSelection();
	return getItemPath(hit);
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HTREEITEM ShellTreeCtrl::getHitTest()
{
	HTREEITEM hit = tree_.getSelection();
    TVHITTESTINFO& tvti = tree_.hitTest();
    if ( tvti.hItem )
	{   
		tree_.setSelection(tvti.hItem);		
		return tvti.hItem;
	}	
	return 0;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

bool ShellTreeCtrl::addFolderNode(mol::Shit& shit)
{
    HTREEITEM hItem = addFolderNode( mol::desktop(), shit, TVI_ROOT,0 );
    tree_.addNode("",hItem);
	return true;
}

///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// helpers
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////

void ShellTreeCtrl::free(HTREEITEM it )
{
	while (HTREEITEM i = tree_.getChildItem(it))
	{
        free(i);
	}
	if ( it != TVI_ROOT )
	{
		TreeEntry* entry = getItemEntry(it);
		if ( entry ) 
			delete entry;
	}
	tree_.deleteNode(it);
}

///////////////////////////////////////////////////////////////////////

BOOL ShellTreeCtrl::displayPath(const std::string& path)
{
	mol::Path p(path);
	if (!p.isDir())
		return FALSE;

	if ( path == std::string("") )
		return FALSE;

    queue_.push( new ShellTreeActionPath(this,path));
    return TRUE;
}

///////////////////////////////////////////////////////////////////////

BOOL ShellTreeCtrl::displayItem(HTREEITEM item)
{
    queue_.push( new ShellTreeActionItem(this,item));
    return TRUE;
}

///////////////////////////////////////////////////////////////////////

BOOL ShellTreeCtrl::expandFolder( HTREEITEM item,bool force, int flags )
{
    TreeEntry* entry = getItemEntry(item);
    if ( entry->isParsed && !force)
    {
        if ( tree_.getItemState(item,TVIS_EXPANDED) == TVIS_EXPANDED )
            return TRUE;
        return tree_.expand( item, flags);
    }

	HTREEITEM it = tree_.getChildItem(item);
    if ( tree_.getItemText(it) == "" )
	{
        free(it);
	}

    std::string path = entry->filename;

	mol::ShellFolder& desk = mol::desktop();

	std::vector<std::string> files;
	std::vector<std::string> dirs;

	std::map<std::string, mol::Shit> filesMap;
	std::map<std::string, mol::Shit> dirsMap;
		
	mol::Shit shit;
	shit = desk.parseDisplayName(path);
	if ( shit )
	{
		mol::ShellFolder folder( *shit,desk );
		if ( folder )
		{
			HRESULT hr = folder.enumObjects(0);
			while( mol::Shit it = folder.next() )
			{
				if ( it->isDir())
				{
					std::string name = folder.getDisplayNameOf(*it);
					//if ( it->isPartOfFileSystem() )
					{
						dirs.push_back(name);
						dirsMap[name] = it;
					}
				}
				else
				if (displayFiles_)
				{
					std::string name = folder.getDisplayNameOf(*it);
					files.push_back(name);
					filesMap[name] = it;
				}
			}
		}

        // deletions
        HTREEITEM it = tree_.getChildItem(item);
        while (it)
        {
            TreeEntry* entry = getItemEntry(it);
            mol::Path p(entry->filename);
            if ( filesMap.count(entry->filename) == 0 &&
                 dirsMap.count(entry->filename) == 0 )
            {
                free(it);        
                it = tree_.getChildItem(item);
                continue;
            }
            it = tree_.getNextItem(it);
        }

		std::sort( files.begin(), files.end() );
		std::sort( dirs.begin(), dirs.end()   );

        tree_.setRedraw(false);
		for ( std::vector<std::string>::iterator iter = dirs.begin(); iter != dirs.end(); iter++ )
		{
            //already there?
            mol::Path p(*iter);
            HTREEITEM hit = getChildByPath(item,*iter);
            if ( hit )
			{
				tree_.setItemState(hit,0,TVIS_CUT);
                continue;
			}
			mol::Shit& it = dirsMap[*iter];
			HTREEITEM hItem = addFolderNode( folder, it, item, 0 );
            tree_.addNode("",hItem);
		}

		for ( std::vector<std::string>::iterator iter = files.begin(); iter != files.end(); iter++ )
		{
            //already there?
            mol::Path p(*iter);
            HTREEITEM hit = getChildByPath(item,*iter);
            if ( hit )
			{
				tree_.setItemState(hit,0,TVIS_CUT);
                continue;
			}
			mol::Shit& it = filesMap[*iter];
			HTREEITEM hItem = addFolderNode( folder, it, item, 0 );
		}
        tree_.setRedraw(true);
        entry->isParsed = true;
	}
    if ( tree_.getItemState(item,TVIS_EXPANDED) == TVIS_EXPANDED )
        return TRUE;
    return tree_.expand( item, flags);
}

///////////////////////////////////////////////////////////////////////

HTREEITEM ShellTreeCtrl::addFolderNode( ShellFolder& folder, Shit& it, HTREEITEM parent, int state)
{
    int			iImage   = 0;
    int			iIconSet = 0;

	std::string name = folder.getDisplayNameOf(*it,SHGDN_INFOLDER);// | SHGDN_FORPARSING);
	mol::Path   path(folder.getDisplayNameOf(*it));
	if ( path.isUNC() )
		name = path.filename();

	iImage   = folder.getIconIndex(it);
	iIconSet = folder.getIconIndex(it,SHGFI_OPENICON);

	mol::FileInfo fi;
	TreeEntry* entry = new TreeEntry( path,fi,iImage);
	return tree_.addIconNodeParam( name, (LPARAM)entry, parent, iImage, iIconSet, state );
}

///////////////////////////////////////////////////////////////////////

std::string ShellTreeCtrl::getItemPath( HTREEITEM item )
{
	TreeEntry* entry = getItemEntry(item);
	if (entry)
		return entry->filename;
	return "";
}

///////////////////////////////////////////////////////////////////////

HTREEITEM ShellTreeCtrl::getChildByPath( HTREEITEM item, const std::string& path)
{
    HTREEITEM i = tree_.getChildItem( item );
    while ( i )
    {
			TreeEntry* entry = getItemEntry(i);
			if ( entry )
			{
				mol::Path p(entry->filename);
				if ( path == p.fullpath() )
					break;
				i = tree_.getNextItem(i);
			}
    } 
    return i;
}

///////////////////////////////////////////////////////////////////////

HTREEITEM ShellTreeCtrl::findItemByPath( const std::string& path, HTREEITEM parent)
{
	if ( path.size() == 0 )
		return 0;

    HTREEITEM i = tree_.getChildItem( parent );
    while ( i )
    {
		TreeEntry* entry = getItemEntry(i);
		if ( entry )
		{
			mol::Path p(entry->filename);
			p.removeBackSlash();
			if ( path == p.fullpath() )
				break;
			HTREEITEM hit = findItemByPath(path,i);
			if ( hit )
				return hit;
		}
		i = tree_.getNextItem(i);
    }
    return i;
}

///////////////////////////////////////////////////////////////////////

Shit ShellTreeCtrl::getShellItem(HTREEITEM it )
{
	return desktop().parseDisplayName( getItemPath(it) );
}

///////////////////////////////////////////////////////////////////////

BOOL ShellTreeCtrl::initDesk (bool displayFiles)
{
    displayFiles_ = displayFiles;
	free();
	tree_.setImageList( mol::ShellFolder::SysImgList() );

	HTREEITEM hParent=0;
    mol::ShellFolder& desk = desktop();
    Shit mydoc = desk.getSpecialFolder(CSIDL_PERSONAL);
	// this is "::{450d8fba-ad25-11d0-98a8-0800361b1103}"
	
	mol::FileInfo fi;
	if ( mydoc )
	{
        int myIcon = desk.getIconIndex( mydoc );
		TreeEntry* entry = new TreeEntry(desk.getDisplayNameOf(*mydoc),fi,myIcon);
		HTREEITEM hParent = tree_.addIconNodeParam( "Docs", (LPARAM)entry, 0, myIcon,myIcon,0 );
		tree_.addNode("",hParent);
	}

	Shit drives = desk.getSpecialFolder(CSIDL_DRIVES);
	int drivesIcon = desk.getIconIndex( drives );
	TreeEntry* entry = new TreeEntry(desk.getDisplayNameOf(*drives),fi,drivesIcon);
    entry->isParsed=true;
	hParent = tree_.addIconNodeParam( "Desktop", (LPARAM)entry, 0, drivesIcon,drivesIcon );

	ShellFolder folder(*drives,desk );
	folder.enumObjects(0);
	while( mol::Shit it = folder.next() )
	{
		if ( it->isDir() && it->isPartOfFileSystem() )
		{
			HTREEITEM hItem = addFolderNode ( folder, it, hParent, 0 );
			tree_.addNode( "", hItem,0 );
		} 
	}

	return TRUE;
}




//////////////////////////////////////////////////////////////////////////////
//
// Drag & Drop Support Interface - Constructor
//
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//
// User drops - 
//
//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ShellTreeCtrl::ShellTreeCtrl_Drop::Drop( IDataObject* pDataObject, DWORD keyState, POINTL pt , DWORD* pEffect)
{
	RECT r;
	TVHITTESTINFO tvht;
	HTREEITEM htiTarget;  

	mol::ImageList::drop(*This());
	TreeView_SelectDropTarget(This()->tree_, NULL); 

    ::GetWindowRect(*This(),&r);
	tvht.pt.x = pt.x-r.left; 
    tvht.pt.y = pt.y-r.top; 

	if ((htiTarget = TreeView_HitTest(This()->tree_, &tvht) ) != NULL) 
	{             
		mol::Path path = This()->getItemPath(htiTarget);
		if ( path.isDir() )
		{
			std::vector<std::string> v = vectorFromDataObject(pDataObject);
			*pEffect &= (DROPEFFECT_COPY|DROPEFFECT_MOVE);
			if ( (*pEffect & DROPEFFECT_MOVE ) && (keyState & MK_CONTROL) )
			{
				mol::MoveFiles mf(v,path, false );
				mf.execute();
			}
			else if ( *pEffect & DROPEFFECT_COPY )
			{
				mol::CopyFiles cf(v,path, false );
				cf.execute();
			}
            mol::FormatEtcDropEffect        de;
			STGMEDIUM						sm;
            sm.tymed = TYMED_HGLOBAL;
            sm.pUnkForRelease = NULL;
            mol::Global glob;
            glob.alloc(sizeof(DWORD));
            mol::set(glob,*pEffect);
            sm.hGlobal = glob;
            glob.detach();
            pDataObject->SetData( &de, &sm, FALSE );
		}
	}
	*pEffect = DROPEFFECT_NONE;
	return S_OK;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////


HRESULT  __stdcall ShellTreeCtrl::ShellTreeCtrl_Drop::DragEnter( IDataObject* , DWORD key, POINTL , DWORD* pEffect )
{
    ODBGS("ShellTree::ShellTree_Drop::DragEnter");
	*pEffect &= (DROPEFFECT_COPY|DROPEFFECT_MOVE);
	if ( key & MK_CONTROL )
		*pEffect = DROPEFFECT_MOVE;
	else
		*pEffect = DROPEFFECT_COPY;
	mol::ImageList::enterDrag(*This());
    return S_OK;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ShellTreeCtrl::ShellTreeCtrl_Drop::DragOver( DWORD key, POINTL pt, DWORD* pEffect )
{
    //ODBGS("ShellTree::ShellTree_Drop::DragOver");

    RECT r;
    HTREEITEM htiTarget;  // handle to target item 
    TVHITTESTINFO tvht;  // hit test information 

	mol::ImageList::doDrag(*This());

    ::GetWindowRect(*This(),&r);      
    tvht.pt.x = pt.x-r.left; 
    tvht.pt.y = pt.y-r.top; 
    
    if ((htiTarget = TreeView_HitTest(This()->tree_, &tvht)) != NULL) 
    {             			
		mol::ImageList::leaveDrag(*This());
        This()->update();
        TreeView_SelectDropTarget(This()->tree_, htiTarget);
		mol::ImageList::enterDrag(*This());
    }  

	*pEffect &= (DROPEFFECT_COPY|DROPEFFECT_MOVE);
	if ( key & MK_CONTROL )
		*pEffect = DROPEFFECT_MOVE;
	else
		*pEffect = DROPEFFECT_COPY;
    return S_OK;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT  __stdcall ShellTreeCtrl::ShellTreeCtrl_Drop::DragLeave()
{
    ODBGS("ShellTree::ShellTree_Drop::DragLeave");
	mol::ImageList::leaveDrag(*This());
	TreeView_SelectDropTarget(This()->tree_, NULL); 
    return S_OK;
}

