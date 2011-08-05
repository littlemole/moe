#include "stdafx.h"
#include "ShellTreeCtrl.h"
#include "ShellCtrl_Dispid.h"
#include "ole/Img.h"
#include "ole/Bstr.h"
#include "ole/enum.h"
#include "util/Str.h"
#include "thread/events.h"
#include <sstream>

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// Actions for queued ShellTreeActions in worker thread
///////////////////////////////////////////////////////////////////////

ShellTreeAction::ShellTreeAction(ShellTree* sw)
:sw_(sw)
{}


///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// ShellTreeActionPath opens a given path
///////////////////////////////////////////////////////////////////////

ShellTreeActionPath::ShellTreeActionPath(ShellTree* sw, const mol::string& path)
:ShellTreeAction(sw),path_(path)
{}

///////////////////////////////////////////////////////////////////////
// this is called recursivly, starts with parent == TVI_ROOT
///////////////////////////////////////////////////////////////////////

void ShellTreeActionPath::openPath( const mol::string& p, HTREEITEM parent)
{
	if ( p.size() == 0 )
		return ;

	mol::string root(p);
	root = mol::Path::stripToRoot(root);

    HTREEITEM i = sw_->tree_.getChildItem( parent );
    while ( i )
    {
		mol::string t = sw_->tree_.getItemText(i);
		if ( t.size() > 0 )
		{
			//mol::string p(t);
			t = mol::Path::removeBackSlash(t);
			if ( root == t )
			{
				sw_->expandFolder(i,true);
				TreeView_Select(sw_->tree_,i,TVGN_CARET);	
				TreeView_EnsureVisible(sw_->tree_,i);

				mol::string sub = mol::Path::stripRoot(p);
				if ( sub == p )
					return;

				openPath(sub,i);
				return;
			}
		}
		i = sw_->tree_.getNextItem(i);
    }
}

///////////////////////////////////////////////////////////////////////
// executed from worker thread, updates tree calling openPath()
///////////////////////////////////////////////////////////////////////

void ShellTreeActionPath::operator() ()
{
	mol::string p(path_);
	if ( mol::Path::isDir(p) )
		p = mol::Path::removeBackSlash(p);

	p = mol::Path::stripToRoot(p);

    HTREEITEM i = sw_->tree_.getChildItem( TVI_ROOT );
	i = sw_->tree_.getChildItem( i );
	sw_->expandFolder(i,true);

	//i = sw_->tree_.getNextItem(i);
	//i = sw_->tree_.getChildItem( i );
    //
	i = sw_->tree_.getChildItem( i );
	//sw_->expandFolder(i,true);
    while ( i )
    {
		TreeEntry* entry = sw_->getItemEntry(i);
		if ( entry )
		{
			mol::string tmp(entry->filename);
			//tmp = mol::Path::removeBackSlash(tmp);
			if ( p == tmp )
			{
				sw_->expandFolder(i,true);
				TreeView_Select(sw_->tree_,i,TVGN_CARET);	
				TreeView_EnsureVisible(sw_->tree_,i);

				mol::string sub = mol::Path::stripRoot(path_);
				if ( sub == path_ )
					return;

				openPath(sub,i);
				return;
			}
		}
		i = sw_->tree_.getNextItem(i);
    }
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// open specified tree item in background
///////////////////////////////////////////////////////////////////////


ShellTreeActionItem::ShellTreeActionItem(ShellTree* sw, HTREEITEM hit)
:ShellTreeAction(sw),hit_(hit)
{}

///////////////////////////////////////////////////////////////////////
// executed from worker thread, updates tree calling openPath()
///////////////////////////////////////////////////////////////////////

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
// init tree in background
///////////////////////////////////////////////////////////////////////


ShellTreeActionInit::ShellTreeActionInit(ShellTree* sw)
:ShellTreeAction(sw)
{}

///////////////////////////////////////////////////////////////////////
// executed from worker thread, updates tree calling openPath()
///////////////////////////////////////////////////////////////////////

void ShellTreeActionInit::operator() ()
{
	sw_->initDesk();
    return;
}
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// ShellTree
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////

ShellTree::ShellTree() 
{
	sizel.cx = 200;
	sizel.cy = 400;
	bgCol_    = RGB(255,255,255);
	foreCol_  = RGB(0,0,0);
	mol::ole::PixeltoHIMETRIC(&sizel);
	eraseBackground_ = 1;
	useContext_ = true;
}

///////////////////////////////////////////////////////////////////////

ShellTree::~ShellTree()	
{
	// free tree items + and associated data
    release(); 
	ODBGS("~ShellTree");
}
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// Windows Message Handlers
///////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//
// OnDestroy - over and out
//
//////////////////////////////////////////////////////////////////////////////

LRESULT ShellTree::OnDestroy(UINT msg, WPARAM wParam, LPARAM lParam)
{
	::RevokeDragDrop(*this);
	queue_.cancel();
    return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// OnCreate - init child Windows and UI
//
//////////////////////////////////////////////////////////////////////////////

LRESULT ShellTree::OnCreate(UINT msg, WPARAM wParam, LPARAM lParam)
{
	treeMenu_.load(IDM_TREE_DIR);
	getClientRect(clientRect_);
	tree_.create( (HMENU)1, clientRect_,*this);

	COLORREF col;
	HIMAGELIST himl = TreeView_GetImageList(tree_,TVSIL_NORMAL);

	::OleTranslateColor(bgCol_,0,&col);
	TreeView_SetBkColor(tree_,col);
	ImageList_SetBkColor(himl,col);

	::OleTranslateColor(foreCol_,0,&col);
	TreeView_SetTextColor(tree_,col);
	TreeView_SetLineColor(tree_,col);

	Drop = new ShellTreeCtrl_Drop(this);
	::RegisterDragDrop(*this,Drop);

	queue_.push( new ShellTreeActionInit(this));
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// OnSize - resize child tree ctrl
//
//////////////////////////////////////////////////////////////////////////////

LRESULT ShellTree::OnSize(UINT msg, WPARAM wParam, LPARAM lParam)
{
	getClientRect(clientRect_);
		
	// get new width and height
	clientRect_.right  = LOWORD (lParam) ;
	clientRect_.bottom = HIWORD (lParam) ;

	tree_.move(clientRect_);
	return 0;
}
//////////////////////////////////////////////////////////////////////////////
//
// Events from Tree View Ctrl
//
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//
// Key pressed events
//
//////////////////////////////////////////////////////////////////////////////

LRESULT ShellTree::OnTreeKeyDown(UINT msg, WPARAM wParam, LPARAM lParam)
{
	mol::Crack message(msg,wParam,lParam);
	WORD wd = message.keydown()->wVKey;
	if (GetAsyncKeyState(VK_CONTROL) < 0) 
	{
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
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// Context Menue
//
//////////////////////////////////////////////////////////////////////////////

LRESULT ShellTree::OnTreeContext(UINT msg, WPARAM wParam, LPARAM lParam)
{
	mol::Crack message(msg,wParam,lParam);

	// get selection, if we have a hittest update selection beforehand
	HTREEITEM hit = getHitTest();
	mol::string p = getPath();
	// check if to display a context menu
	if ( !hit )
		return 0;

	if ( !useContext_ )
	{
		mol::variant v(p);
		fire(DISPID_ISHELLTREEEVENTS_ONCONTEXTMENU,v);
		return 0;
	}

	// prepare context menue
	mol::Menu m(treeMenu_.getSubMenu(0));
	m.enableItem(IDM_TREE_REMOVE);



	m.enableItem(IDM_TREE_RENAME);
	m.enableItem(IDM_TREE_DELETE);
	m.enableItem(IDM_TREE_OPEN);
	m.disableItem(IDM_TREE_REMOVE);
	m.enableItem(IDM_TREE_CUT);
	m.enableItem(IDM_TREE_COPY);
	m.enableItem(IDM_TREE_PASTE);
	if ( !hit || mol::Path::isRoot(p) )
	{
		m.enableItem(IDM_TREE_CUT);
		m.enableItem(IDM_TREE_COPY);	
		m.disableItem(IDM_TREE_DELETE);
		//m.enableItem(IDM_TREE_REMOVE);
	}
	if ( !hit )
	{
		m.enableItem(IDM_TREE_CUT);
		m.enableItem(IDM_TREE_COPY);	
		m.disableItem(IDM_TREE_DELETE);
		m.disableItem(IDM_TREE_RENAME);
		m.disableItem(IDM_TREE_OPEN);
		m.disableItem(IDM_TREE_REMOVE);		
	}
	if ( mol::Path::isRoot(p) )
	{
		m.enableItem(IDM_TREE_CUT);
		m.enableItem(IDM_TREE_COPY);	
		m.disableItem(IDM_TREE_DELETE);
		m.disableItem(IDM_TREE_RENAME);
		m.disableItem(IDM_TREE_REMOVE);			
	}
	// disable hide option if path is not mounted UNC share
	if ( mol::Path::isRoot(p) && ( mol::Path::isUNC(p)) )
	{
		m.enableItem(IDM_TREE_REMOVE);
	}
	LRESULT res = returnContext(m);
	//tree_.setFocus();
	switch (res)
	{
		case IDM_TREE_OPEN :
		{
			this->fire(3,variant(p)); 
			break;
		}
		case IDM_TREE_UPDATE :
		{
			this->Update();
			break;
		}
		case IDM_TREE_NEWDIR :
		{
			this->CreateDir();
			break;
		}
		case IDM_TREE_RENAME:
		{
			this->Rename();
			break;
		}
		case IDM_TREE_DELETE :
		{
			this->Delete();
			break;
		}
		case IDM_TREE_CUT :
		{
			this->Cut();
			break;
		}
		case IDM_TREE_COPY :
		{
			this->Copy();
			break;
		}
		case IDM_TREE_PASTE :
		{
			this->Paste();
			break;
		}
		case IDM_TREE_EXECUTE :
		{
			this->Execute();
			break;
		}
		case IDM_TREE_PROPERTIES :
		{
			this->Properties();
			break;
		}
		case IDM_TREE_REMOVE :
		{
			bstr b(p);
			this->RemoveFolder(b);
			break;
		}
	}	
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// Tree item expanding - lazy populate
//
//////////////////////////////////////////////////////////////////////////////

LRESULT ShellTree::OnTreeItemExpanding(UINT msg, WPARAM wParam, LPARAM lParam)
{
	mol::Crack message(msg,wParam,lParam);
    if ( !(message.nmtreeview()->itemNew.state & TVIS_EXPANDED) )
    {
        displayItem(message.nmtreeview()->itemNew.hItem);
    }
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// Tree item dblClick
//
//////////////////////////////////////////////////////////////////////////////

LRESULT ShellTree::OnTreeDblClick(UINT msg, WPARAM wParam, LPARAM lParam)
{
	mol::Crack message(msg,wParam,lParam);
    HTREEITEM hit = getHitTest();
	if ( hit )
	{
		mol::string p = this->getPath();
		this->fire(2,variant(p));
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// Tree selection changed 
//
//////////////////////////////////////////////////////////////////////////////

LRESULT ShellTree::OnTreeClick(UINT msg, WPARAM wParam, LPARAM lParam)
{
	this->inplaceActivate();
	this->uiActivate();
	return 0;
}

LRESULT ShellTree::OnTreeSelection(UINT msg, WPARAM wParam, LPARAM lParam)
{
	this->fire( 1, variant(getPath()) );
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// Begin LabelEdit
//
//////////////////////////////////////////////////////////////////////////////

LRESULT ShellTree::OnTreeBeginLabelEdit(UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// Begin Drag Drop from Tree
//
//////////////////////////////////////////////////////////////////////////////

LRESULT ShellTree::OnTreeBeginDrag(UINT msg, WPARAM wParam, LPARAM lParam)
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

LRESULT ShellTree::OnDataObject(IDataObject* data)
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

LRESULT ShellTree::OnTreeRename(UINT msg, WPARAM wParam, LPARAM lParam)
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

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// implementation
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// Get selected path
///////////////////////////////////////////////////////////////////////

mol::string ShellTree::getPath()
{
	HTREEITEM hit = tree_.getSelection();
	return getItemPath(hit);
}

///////////////////////////////////////////////////////////////////////
// check for mouse hit test
///////////////////////////////////////////////////////////////////////

HTREEITEM ShellTree::getHitTest()
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
// Free all Tree items and assoc info
///////////////////////////////////////////////////////////////////////

void ShellTree::release(HTREEITEM it )
{
	while (HTREEITEM i = tree_.getChildItem(it))
	{
        release(i);
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
// display specific path
///////////////////////////////////////////////////////////////////////

BOOL ShellTree::displayPath(const mol::string& p)
{
	if (!mol::Path::isDir(p))
		return FALSE;

	if ( p == mol::string(_T("")) )
		return FALSE;

	queue_.push( new ShellTreeActionPath(this,p));

    return TRUE;
}

///////////////////////////////////////////////////////////////////////
// display specific tree item
///////////////////////////////////////////////////////////////////////

BOOL ShellTree::displayItem(HTREEITEM item)
{
    queue_.push( new ShellTreeActionItem(this,item));
    return TRUE;
}


///////////////////////////////////////////////////////////////////////

mol::string ShellTree::getItemPath( HTREEITEM item )
{
	TreeEntry* entry = getItemEntry(item);
	if (entry)
		return entry->filename;
	return _T("");
}

///////////////////////////////////////////////////////////////////////

HTREEITEM ShellTree::getChildByPath( HTREEITEM item, const mol::string& p)
{
    HTREEITEM i = tree_.getChildItem( item );
    while ( i )
    {
			TreeEntry* entry = getItemEntry(i);
			if ( entry )
			{
				mol::string tmp(entry->filename);
				if ( p == tmp )
					break;
				i = tree_.getNextItem(i);
			}
    } 
    return i;
}

///////////////////////////////////////////////////////////////////////

HTREEITEM ShellTree::findItemByPath( const mol::string& p, HTREEITEM parent)
{
	if ( p.size() == 0 )
		return 0;

    HTREEITEM i = tree_.getChildItem( parent );
    while ( i )
    {
		TreeEntry* entry = getItemEntry(i);
		if ( entry )
		{
			mol::string tmp(entry->filename);
			tmp = mol::Path::removeBackSlash(tmp);
			if ( p == tmp )
				break;
			HTREEITEM hit = findItemByPath(p,i);
			if ( hit )
				return hit;
		}
		i = tree_.getNextItem(i);
    }
    return i;
}

///////////////////////////////////////////////////////////////////////

Shit ShellTree::getShellItem(HTREEITEM it )
{
	return desktop().parseDisplayName( getItemPath(it) );
}

///////////////////////////////////////////////////////////////////////
// actually add a Folder Node given info, retrieves icon
///////////////////////////////////////////////////////////////////////

HTREEITEM ShellTree::addFolderNode( ShellFolder& folder, Shit& it, HTREEITEM parent, int state)
{
    int			iImage   = 0;
    int			iIconSet = 0;

	mol::string name = folder.getDisplayNameOf(*it,SHGDN_INFOLDER);// | SHGDN_FORPARSING);
	mol::string p(folder.getDisplayNameOf(*it));
	if ( mol::Path::isUNC(p) )
		name = mol::Path::filename(p);

	iImage   = folder.getIconIndex(it);
	iIconSet = folder.getIconIndex(it,SHGFI_OPENICON);

	mol::FileInfo fi;
	TreeEntry* entry = new TreeEntry( p,fi,iImage);
	return tree_.addIconNodeParam( name, (LPARAM)entry, parent, iImage, iIconSet, state );
}

///////////////////////////////////////////////////////////////////////
// expand folder is called internally from background thread
///////////////////////////////////////////////////////////////////////

BOOL ShellTree::expandFolder( HTREEITEM item, bool force, int flags )
{
	HTREEITEM it = tree_.getChildItem(item);

	if (it)
    if ( tree_.getItemText(it) == _T("") )
	{
        release(it);
	}

    TreeEntry* entry = getItemEntry(item);
	if ( !entry )
		return FALSE;

    if ( entry->isParsed && !force)
    {
        if ( tree_.getItemState(item,TVIS_EXPANDED) == TVIS_EXPANDED )
            return TRUE;
        return tree_.expand( item, flags);
    }



    mol::string p = entry->filename;

	ShellFolder& desk = desktop();

	std::vector<mol::string> files;
	std::vector<mol::string> dirs;

	std::map<mol::string, Shit> filesMap;
	std::map<mol::string, Shit> dirsMap;
		
	Shit shit;
	shit = desk.parseDisplayName(p);
	if ( shit )
	{
		ShellFolder folder( *shit,desk );
		if ( folder )
		{
			HRESULT hr = folder.enumObjects(0);
			while( Shit it = folder.next() )
			{
				mol::string name = folder.getDisplayNameOf(*it);
				if ( it->isDir() && mol::Path::isDir(name) )
				{
					//if ( it->isPartOfFileSystem() )
					{
						dirs.push_back(name);
						dirsMap[name] = it;
					}
				}
				else
				if (displayFiles_ && mol::Path::exists(name) )
				{
					mol::string name = folder.getDisplayNameOf(*it);
					files.push_back(name);
					filesMap[name] = it;
				}
				else if ( mol::Path::isUNC(name) ) 
				{
						dirs.push_back(name);
						dirsMap[name] = it;
				}
			}
		}
		
		tree_.setRedraw(false);

        // deletions
        HTREEITEM it = tree_.getChildItem(item);
        while (it)
        {
            TreeEntry* entry = getItemEntry(it);
            //path p(entry->filename);
            if ( filesMap.count(entry->filename) == 0 &&
                 dirsMap.count(entry->filename) == 0 )
            {
                release(it);        
                it = tree_.getChildItem(item);
                continue;
            }
            it = tree_.getNextItem(it);
        }

		std::sort( files.begin(), files.end() );
		std::sort( dirs.begin(), dirs.end()   );


		for ( std::vector<mol::string>::iterator iter = dirs.begin(); iter != dirs.end(); iter++ )
		{
            //already there?
			mol::string p(*iter);
            HTREEITEM hit = getChildByPath(item,*iter);
            if ( hit )
			{
				tree_.setItemState(hit,0,TVIS_CUT);
                continue;
			}
			Shit& it = dirsMap[*iter];
			HTREEITEM hItem = addFolderNode( folder, it, item, 0 );
            tree_.addNode(_T(""),hItem);
		}

		for ( std::vector<mol::string>::iterator iter = files.begin(); iter != files.end(); iter++ )
		{
            //already there?
            mol::string p(*iter);
            HTREEITEM hit = getChildByPath(item,*iter);
            if ( hit )
			{
				tree_.setItemState(hit,0,TVIS_CUT);
                continue;
			}
			Shit& it = filesMap[*iter];
			HTREEITEM hItem = addFolderNode( folder, it, item, 0 );
		}
        tree_.setRedraw(true);
        entry->isParsed = true;
	}
    if ( tree_.getItemState(item,TVIS_EXPANDED) == TVIS_EXPANDED )
        return TRUE;
    return tree_.expand( item, flags);
	return 0;
}

///////////////////////////////////////////////////////////////////////
// init tree to default desktop display
///////////////////////////////////////////////////////////////////////

BOOL ShellTree::initDesk (bool displayFiles)
{
    displayFiles_ = displayFiles;
	release();

	tree_.setImageList( ShellFolder::SysImgList() );

	HTREEITEM hParent=0;
	mol::FileInfo fi;
	ShellFolder& desk = desktop();

	/*
	HTREEITEM hParent=0;
	Shit mydoc = desk.getSpecialFolder(CSIDL_PERSONAL);
	// this is "::{450d8fba-ad25-11d0-98a8-0800361b1103}"
	
	mol::FileInfo fi;
	if ( mydoc )
	{
        int myIcon = desk.getIconIndex( mydoc );
		TreeEntry* entry = new TreeEntry(desk.getDisplayNameOf(*mydoc),fi,myIcon);
		HTREEITEM hParent = tree_.addIconNodeParam( _T("Docs"), (LPARAM)entry, 0, myIcon,myIcon,0 );
		tree_.addNode(_T(""),hParent);
	}
*/
	Shit drives = desk.getSpecialFolder(CSIDL_DRIVES);
	//int drivesIcon = getFolderIcon()
	int drivesIcon = 0;//desk.getIconIndexReal( drives );

	LPITEMIDLIST pidl = NULL;
	//HRESULT hr = SHGetFolderLocation(NULL, CSIDL_DRIVES, NULL, 0, &pidl);
	HRESULT hr = SHGetFolderLocation(NULL, CSIDL_DRIVES, NULL, 0, &pidl);

	if (SUCCEEDED(hr))                    
	{
		SHFILEINFO sfi = {0};
		DWORD_PTR hr = SHGetFileInfo((LPCTSTR)pidl,
                        -1,
                        &sfi,
                        sizeof(sfi),
                        SHGFI_PIDL | SHGFI_ICON|SHGFI_SMALLICON|SHGFI_SYSICONINDEX);
            
		if (SUCCEEDED(hr))
		{
			drivesIcon = sfi.iIcon;
			
		}
	}
	
	TreeEntry* entry = new TreeEntry(desk.getDisplayNameOf(pidl),fi,drivesIcon);

	DWORD len = 256;
	mol::TCHAR buf[256];
	BOOL b = ::GetComputerName( buf, &len );
	
	//TreeEntry* entry = new TreeEntry(desk.getDisplayNameOf(*drives),fi,drivesIcon);
	
    entry->isParsed=true;
	hParent = tree_.addIconNodeParam( mol::string(buf,len), (LPARAM)entry, 0, drivesIcon,drivesIcon );

	//ShellFolder folder(*drives,desk );
	//ShellFolder folder(pidl,desk );
	desk.enumObjects(0,SHCONTF_FOLDERS|SHCONTF_NAVIGATION_ENUM);
	while( Shit it = desk.next() )
	{
		//if ( it->isDir() && it->isPartOfFileSystem() )
		{
			//if ( folder.getDisplayNameOf(*it).substr(0,2) != _T("::") )
			{
				HTREEITEM hItem = addFolderNode ( desk, it, hParent, 0 );
				tree_.addNode( _T(""), hItem,0 );
			}
		} 
	}
	ILFree(pidl);
	return TRUE;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////
// COM Properties and members
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// displayfiles
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ShellTree::get_DisplayFiles	( VARIANT_BOOL* vb )
{
	if ( vb )
	{
		if ( displayFiles_ )
			*vb = VARIANT_TRUE;
		else
			*vb = VARIANT_FALSE;
	}
	return S_OK;
}

HRESULT __stdcall ShellTree::put_DisplayFiles	( VARIANT_BOOL vb  )
{
	if ( S_OK != OnRequestEdit( 1 ) )
		return S_FALSE;

	if ( vb == VARIANT_TRUE )
		displayFiles_ = true;
	else
		displayFiles_ = false;

	this->OnChanged(1);
	return S_OK;
}
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ShellTree::get_UseContext	( VARIANT_BOOL* vb )
{
	if ( vb )
	{
		if ( useContext_ )
			*vb = VARIANT_TRUE;
		else
			*vb = VARIANT_FALSE;
	}
	return S_OK;
}

HRESULT __stdcall ShellTree::put_UseContext	( VARIANT_BOOL vb  )
{
	if ( S_OK != OnRequestEdit( 15 ) )
		return S_FALSE;

	if ( vb == VARIANT_TRUE )
		useContext_ = true;
	else
		useContext_ = false;

	this->OnChanged(51);
	return S_OK;
}

///////////////////////////////////////////////////////////////////////
// selection
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ShellTree::get_Selection		( BSTR* dirname )
{
	*dirname = ansi2BSTR(mol::tostring(getPath()));
	return S_OK;
}

HRESULT __stdcall ShellTree::put_Selection		( BSTR  dirname )
{
	bstr b(dirname);
	displayPath(b.toString());
	return S_OK;
}


HRESULT __stdcall ShellTree::get_HasFocus( VARIANT_BOOL* vbHasFocus)
{
	if ( vbHasFocus )
	{
		if ( tree_.hasFocus() )
		{
			*vbHasFocus = VARIANT_TRUE;
		}
		else
		{
			*vbHasFocus = VARIANT_FALSE;
		}
	}
	return S_OK;
}

///////////////////////////////////////////////////////////////////////
// Remove network folder
///////////////////////////////////////////////////////////////////////

HRESULT ShellTree::RemoveFolder(BSTR dirname)
{
	HTREEITEM hit = tree_.getSelection();
	if ( hit )
	{
		mol::string p = getItemPath(hit);
		if ( !mol::Path::isRoot(p) )
        {
		    HTREEITEM parent = tree_.getParentItem(hit);
		    release(hit);
		    displayItem(parent);
        }
	}
	return S_OK;
}

///////////////////////////////////////////////////////////////////////
// add network folder
///////////////////////////////////////////////////////////////////////

HRESULT ShellTree::AddFolder(BSTR dirname)
{
	bstr b(dirname);
	Shit shit = desktop().parseDisplayName(b.toString());

    HTREEITEM hItem = addFolderNode( desktop(), shit, TVI_ROOT,0 );
    tree_.addNode( _T(""),hItem);

	return S_OK;
}


//////////////////////////////////////////////////////////////////////////////
//
// Update focused dir
//
//////////////////////////////////////////////////////////////////////////////

HRESULT ShellTree::Update()
{
	HTREEITEM hit = tree_.getSelection();
	if ( hit )
	{   
		displayItem(hit);
	}
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////
//
// Cut selected tree item
//
//////////////////////////////////////////////////////////////////////////////

HRESULT ShellTree::Cut ()
{
	HTREEITEM hit = tree_.getSelection();
	if ( hit )
	{
		tree_.setItemState(hit,TVIS_CUT,TVIS_CUT);
		std::vector<mol::string> v;
		v.push_back(getItemPath(hit));
		punk<IDataObject> ido = new ShellDataObj( mol::events::event_handler( &ShellTree::OnDataObject,this), v,true);        
		HRESULT r = ::OleSetClipboard(ido);
	}
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////
//
// Copy selected tree item
//
//////////////////////////////////////////////////////////////////////////////

HRESULT ShellTree::Copy ()
{
	HTREEITEM hit = tree_.getSelection();
	if ( hit )
	{
		tree_.setItemState(hit,TVIS_CUT,0);
		std::vector<mol::string> v;
		v.push_back(getItemPath(hit));
		punk<IDataObject> ido = new ShellDataObj( mol::events::event_handler( &ShellTree::OnDataObject,this), v);        
		HRESULT r = ::OleSetClipboard(ido);
	}
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////
//
// Paste into tree view
//
//////////////////////////////////////////////////////////////////////////////

HRESULT ShellTree::Paste ()
{
	punk<IDataObject> ido;
	::OleGetClipboard(&ido);
	if ( !ido )
		return E_FAIL;

	std::vector<mol::string> v = vectorFromDataObject(ido);
	if ( v.size() < 1 )
		return E_FAIL;

	HTREEITEM hit = tree_.getSelection();
	if ( hit )
	{
		mol::string p = getItemPath(hit);
		if ( mol::Path::isDir(p) )
		{
			DWORD  dw = DROPEFFECT_COPY;
			format_etc_pref_dropeffect	 fe;
            format_etc_dropeffect        de;
			STGMEDIUM					 sm;

			if ( S_OK == ido->GetData( &fe, &sm ) )
			{
				if ( sm.tymed == TYMED_HGLOBAL )
					mol::global::get(sm.hGlobal,dw);
			}
			if (dw & DROPEFFECT_COPY )
			{
				ShellFileOp sfo;
				sfo.copy(*this,v,p,FOF_ALLOWUNDO);
				this->Update();
			}
			else if (dw & DROPEFFECT_MOVE )
			{
				ShellFileOp sfo;
				sfo.move(*this,v,p,FOF_ALLOWUNDO);
				this->Update();
			}
            ido->SetData( &de, &sm, FALSE );
		}
	}
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////
//
// rename selected tree or dir item
//
//////////////////////////////////////////////////////////////////////////////

HRESULT ShellTree::Rename()
{
	HTREEITEM hit = tree_.getSelection();
	if ( hit )
		tree_.editLabel(hit);
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////
//
// delete selected tree or dir item
//
//////////////////////////////////////////////////////////////////////////////

HRESULT ShellTree::Delete()
{
	HTREEITEM hit = tree_.getSelection();
	if ( hit )
	{
		mol::string p = getItemPath(hit);
		if ( mol::Path::isRoot(p) ) {
			return S_FALSE;
		}
		ShellFileOp sfo;
		sfo.remove(*this,p,FOF_ALLOWUNDO);
		HTREEITEM parent = tree_.getParentItem(hit);
		this->displayItem(parent);
	}
	return S_OK;
}


//////////////////////////////////////////////////////////////////////////////
//
// properties of selected tree or dir item
//
//////////////////////////////////////////////////////////////////////////////

HRESULT ShellTree::Properties()
{
	HTREEITEM hit = tree_.getSelection();
	if ( hit )
	{
		execute_shell(getPath(),_T("properties"),1,SEE_MASK_INVOKEIDLIST);
	}
	return S_OK;
}


//////////////////////////////////////////////////////////////////////////////
//
// shellexecute selected tree or dir item
//
//////////////////////////////////////////////////////////////////////////////

HRESULT ShellTree::Execute()
{
	HTREEITEM hit = tree_.getSelection();
	if ( hit )
	{
		execute_shell(getPath());
	}
	return S_OK;
}
//////////////////////////////////////////////////////////////////////////////
HRESULT ShellTree::CreateDir()
{
	mol::string tmp = _T("newDir_");	
	int i = 0;
	while(true)
	{
		mol::string p(getPath());
		mol::stringstream oss;
		oss << tmp << i;
		p = mol::Path::append(p,oss.str());
		if ( !::CreateDirectory(p.c_str(),0) )
		{
			if ( ::GetLastError() == ERROR_ALREADY_EXISTS )
			{
				i++;
				continue;
			}
		}
		this->Update();
		return 0;
	}
	return S_OK;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////


HRESULT __stdcall ShellTree::Load( LPSTREAM pStm)
{
	pStm >> mol::property( mol::DispId(this,ShellTreeCtrl_Dispatch_DisplayFiles,VT_BOOL) )
		 >> mol::property( mol::DispId(this,ShellTreeCtrl_Dispatch_Selection,VT_BSTR) )
		 >> mol::property( &sizel );

	/*
	mol::Rect r = this->posRect_;
	r.right = r.left + sizel.cx;
	r.bottom = r.top + sizel.cy;

	this->setRects(r,r);
	*/
	return S_OK;
}

HRESULT __stdcall ShellTree::Save( LPSTREAM pStm,BOOL fClearDirty)
{
	pStm << mol::property( mol::DispId(this,ShellTreeCtrl_Dispatch_DisplayFiles,VT_BOOL) )
		 << mol::property( mol::DispId(this,ShellTreeCtrl_Dispatch_Selection,VT_BSTR) )
		 << mol::property( &sizel );

	//pStm->Commit(STGC_DEFAULT);
	return S_OK;
}

HRESULT __stdcall ShellTree::Load( IPropertyBag *pPropBag,IErrorLog *pErrorLog)
{
	
	pPropBag >> mol::property( _T("displayfiles"), mol::DispId(this,ShellTreeCtrl_Dispatch_DisplayFiles,VT_BOOL) )
			 >> mol::property( _T("selection"), mol::DispId(this,ShellTreeCtrl_Dispatch_Selection,VT_BSTR) )
			 >> mol::property( _T("cs"), &sizel );

	/*mol::Rect r = this->posRect_;
	r.right = r.left + sizel.cx;
	r.bottom = r.top + sizel.cy;

	this->setRects(r,r);
	*/
	return S_OK;
}

HRESULT __stdcall ShellTree::Save( IPropertyBag *pPropBag,BOOL fClearDirty,BOOL fSaveAllProperties)
{
	
	pPropBag << mol::property( _T("displayfiles"), mol::DispId(this,ShellTreeCtrl_Dispatch_DisplayFiles,VT_BOOL) )
			 << mol::property( _T("selection"), mol::DispId(this,ShellTreeCtrl_Dispatch_Selection,VT_BSTR) )
			 << mol::property( _T("cs"), &sizel );

	return S_OK;
}



///////////////////////////////////////////////////////////////////////
// Drag Drop Implementation
///////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//
// User drops - 
//
//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ShellTree::ShellTreeCtrl_Drop::Drop( IDataObject* pDataObject, DWORD keyState, POINTL pt , DWORD* pEffect)
{
	RECT r;
	TVHITTESTINFO tvht;

	mol::ImageList::drop(tree_->tree_);
	TreeView_SelectDropTarget(tree_->tree_, NULL); 

    ::GetWindowRect(*tree_,&r);
	tvht.pt.x = pt.x-r.left; 
    tvht.pt.y = pt.y-r.top; 

	tvht = tree_->tree_.hitTest(tvht.pt);

	if ( tvht.hItem != NULL )
	{             
		TreeEntry* entry = (TreeEntry*)(tree_->tree_.getLPARAM(tvht.hItem));
		mol::string p = entry->filename;
		
		if ( mol::Path::isDir(p) )
		{
			std::vector<mol::string> v = vectorFromDataObject(pDataObject);
			*pEffect &= (DROPEFFECT_COPY|DROPEFFECT_MOVE);
			if ( (*pEffect & DROPEFFECT_MOVE ) && (keyState & MK_CONTROL) )
			{
				ShellFileOp sfo;
				sfo.move(*tree_,v,p,FOF_ALLOWUNDO);
				tree_->displayItem(tvht.hItem);
			}
			else if ( *pEffect & DROPEFFECT_COPY )
			{
				ShellFileOp sfo;
				sfo.copy(*tree_,v,p,FOF_ALLOWUNDO);
				tree_->displayItem(tvht.hItem);
			}
            format_etc_dropeffect        de;
			StgMedium sm(*pEffect, GHND|GMEM_SHARE);
            pDataObject->SetData( &de, &sm, TRUE );
		}
	}
	*pEffect = DROPEFFECT_NONE;
	return S_OK;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT  __stdcall ShellTree::ShellTreeCtrl_Drop::DragEnter( IDataObject* , DWORD key, POINTL , DWORD* pEffect )
{
	*pEffect &= (DROPEFFECT_COPY|DROPEFFECT_MOVE);
	if ( key & MK_CONTROL )
		*pEffect = DROPEFFECT_MOVE;
	else
		*pEffect = DROPEFFECT_COPY;
	mol::ImageList::enterDrag(*tree_);
    return S_OK;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ShellTree::ShellTreeCtrl_Drop::DragOver( DWORD key, POINTL pt, DWORD* pEffect )
{
    RECT r;
    HTREEITEM htiTarget;  // handle to target item 
    TVHITTESTINFO tvht;  // hit test information 

	mol::ImageList::doDrag(*tree_);

    ::GetWindowRect(*tree_,&r);      
    tvht.pt.x = pt.x-r.left; 
    tvht.pt.y = pt.y-r.top; 
    
    if ((htiTarget = TreeView_HitTest(tree_->tree_, &tvht)) != NULL) 
    {             			
		mol::ImageList::leaveDrag(*tree_);
        tree_->update();
        TreeView_SelectDropTarget(tree_->tree_, htiTarget);
		mol::ImageList::enterDrag(*tree_);
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

HRESULT  __stdcall ShellTree::ShellTreeCtrl_Drop::DragLeave()
{
	mol::ImageList::leaveDrag(*tree_);
	TreeView_SelectDropTarget(tree_->tree_, NULL); 
    return S_OK;
}



//} // end namespace mol

