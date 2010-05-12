#include "stdafx.h"
#include "WorkSpaceCtrl.h"
#include "win/ole/Img.h"
#include "win/ole/Bstr.h"
#include "win/ole/enum.h"
#include "util/Str.h"
#include <sstream>

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// Actions for queued WorkSpaceActions in worker thread
///////////////////////////////////////////////////////////////////////

WorkSpaceAction::WorkSpaceAction(WorkSpaceCtrl* sw)
:sw_(sw)
{}


///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// WorkSpaceActionPath opens a given path
///////////////////////////////////////////////////////////////////////

WorkSpaceActionPath::WorkSpaceActionPath(WorkSpaceCtrl* sw, const mol::string& path)
:WorkSpaceAction(sw),path_(path)
{}

///////////////////////////////////////////////////////////////////////
// this is called recursivly, starts with parent == TVI_ROOT
///////////////////////////////////////////////////////////////////////

void WorkSpaceActionPath::openPath( const mol::string& path, HTREEITEM parent)
{
	if ( path.size() == 0 )
		return ;

	mol::Path root(path);
	root.stripToRoot();

    HTREEITEM i = sw_->tree_.getChildItem( parent );
    while ( i )
    {
		mol::string t = sw_->tree_.getItemText(i);
		if ( t.size() > 0 )
		{
			mol::Path p(t);
			p.removeBackSlash();
			if ( root == p.fullpath() )
			{
				sw_->expandFolder(i,true);
				TreeView_Select(sw_->tree_,i,TVGN_CARET);	
				TreeView_EnsureVisible(sw_->tree_,i);

				mol::Path sub(path);
				sub.stripRoot();
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

void WorkSpaceActionPath::operator() ()
{
	mol::Path path(path_);
	if ( path.isDir() )
		path.removeBackSlash();

	//path.stripToRoot();

    HTREEITEM i = sw_->tree_.getChildItem( TVI_ROOT );
	//i = sw_->tree_.getNextItem(i);
    i = sw_->tree_.getChildItem( i );
    while ( i )
    {
		WorkSpaceEntry* entry = sw_->getItemEntry(i);
		if ( entry )
		{
			mol::Path p(entry->filename);
			p.removeBackSlash();


			if ( path.isSubpath(p) )

			//if ( path == p.fullpath() )
			{
				sw_->expandFolder(i,true);
				TreeView_Select(sw_->tree_,i,TVGN_CARET);	
				TreeView_EnsureVisible(sw_->tree_,i);

				mol::Path sub(path_);
				sub.stripRoot();
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


WorkSpaceActionItem::WorkSpaceActionItem(WorkSpaceCtrl* sw, HTREEITEM hit)
:WorkSpaceAction(sw),hit_(hit)
{}

///////////////////////////////////////////////////////////////////////
// executed from worker thread, updates tree calling openPath()
///////////////////////////////////////////////////////////////////////

void WorkSpaceActionItem::operator() ()
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


WorkSpaceActionInit::WorkSpaceActionInit(WorkSpaceCtrl* sw)
:WorkSpaceAction(sw)
{}

///////////////////////////////////////////////////////////////////////
// executed from worker thread, updates tree calling openPath()
///////////////////////////////////////////////////////////////////////

void WorkSpaceActionInit::operator() ()
{
	sw_->initWorkSpace();
    return;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// WorkSpace
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////

WorkSpaceCtrl::WorkSpaceCtrl() 
{
	sizel_.cx = 200;
	sizel_.cy = 400;
	bgCol_    = RGB(255,255,255);
	foreCol_  = RGB(0,0,0);
	mol::PixeltoHIMETRIC(&sizel_);
}

///////////////////////////////////////////////////////////////////////

WorkSpaceCtrl::~WorkSpaceCtrl()	
{
	// free tree items + and associated data
    free(); 
	//this->tree_.destroy();
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

LRESULT WorkSpaceCtrl::OnDestroy(UINT msg, WPARAM wParam, LPARAM lParam)
{
	::RevokeDragDrop(*this);
	
    return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// OnCreate - init child Windows and UI
//
//////////////////////////////////////////////////////////////////////////////

LRESULT WorkSpaceCtrl::OnCreate(UINT msg, WPARAM wParam, LPARAM lParam)
{
	treeMenu_.load(IDM_WORK_SPACE);
	getClientRect(clientRect_);
	tree_.create( 1, clientRect_,*this);
    //initDesk();

	COLORREF col;
	HIMAGELIST himl = TreeView_GetImageList(tree_,TVSIL_NORMAL);

	::OleTranslateColor(bgCol_,0,&col);
	TreeView_SetBkColor(tree_,col);
	ImageList_SetBkColor(himl,col);

	::OleTranslateColor(foreCol_,0,&col);
	TreeView_SetTextColor(tree_,col);
	TreeView_SetLineColor(tree_,col);

	Drop = new WorkSpaceCtrl_Drop(this);
	::RegisterDragDrop(*this,Drop);

	queue_.push( new WorkSpaceActionInit(this));
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// OnSize - resize child tree ctrl
//
//////////////////////////////////////////////////////////////////////////////

LRESULT WorkSpaceCtrl::OnSize(UINT msg, WPARAM wParam, LPARAM lParam)
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
// Focus Events
//
//////////////////////////////////////////////////////////////////////////////

LRESULT WorkSpaceCtrl::OnFocus(UINT msg, WPARAM wParam, LPARAM lParam)
{
	if ( site_)
	{
		mol::UnknownPtr<IOleControlSite> iocs(site_);
		if ( iocs )
			iocs->OnFocus(TRUE);
	}
	this->tree_.setFocus();
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

LRESULT WorkSpaceCtrl::OnTreeKeyDown(UINT msg, WPARAM wParam, LPARAM lParam)
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

LRESULT WorkSpaceCtrl::OnTreeContext(UINT msg, WPARAM wParam, LPARAM lParam)
{
	mol::Crack message(msg,wParam,lParam);

	// prepare context menue
	mol::Menu m(treeMenu_.getSubMenu(0));
	m.enableItem(IDM_TREE_REMOVE);

	// get selection, if we have a hittest update selection beforehand
	HTREEITEM hit = getHitTest();
	mol::Path path = getPath();
	// check if to display a context menu
	if ( !hit )
		return 0;

	m.enableItem(IDM_TREE_RENAME);
	m.enableItem(IDM_TREE_DELETE);
	m.enableItem(IDM_TREE_OPEN);
	m.disableItem(IDM_TREE_REMOVE);
	m.enableItem(IDM_TREE_CUT);
	m.enableItem(IDM_TREE_COPY);
	m.enableItem(IDM_TREE_PASTE);
	if ( !hit || path.isRoot() )
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
	if ( path.isRoot() )
	{
		m.enableItem(IDM_TREE_CUT);
		m.enableItem(IDM_TREE_COPY);	
		m.disableItem(IDM_TREE_DELETE);
		m.disableItem(IDM_TREE_RENAME);
		m.disableItem(IDM_TREE_REMOVE);			
	}
	// disable hide option if path is not mounted UNC share
	if ( path.isRoot() && (path.isUNC()) )
	{
		m.enableItem(IDM_TREE_REMOVE);
	}
	LRESULT res = returnContext(m);
	//tree_.setFocus();
	switch (res)
	{
		case IDM_TREE_OPEN :
		{
			this->Fire(3,mol::Variant(path));
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
			mol::Bstr bstr(path);
			this->Remove(bstr);
			break;
		}
		case ID_CONTEXT_ADD  :
		{
			mol::Bstr bstr(path);
			this->Remove(bstr);
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

LRESULT WorkSpaceCtrl::OnTreeItemExpanding(UINT msg, WPARAM wParam, LPARAM lParam)
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

LRESULT WorkSpaceCtrl::OnTreeDblClick(UINT msg, WPARAM wParam, LPARAM lParam)
{
	mol::Crack message(msg,wParam,lParam);
    HTREEITEM hit = getHitTest();
	if ( hit )
	{
		mol::string p = this->getPath();
		this->Fire(2,mol::Variant(p));
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// Tree selection changed 
//
//////////////////////////////////////////////////////////////////////////////

LRESULT WorkSpaceCtrl::OnTreeClick(UINT msg, WPARAM wParam, LPARAM lParam)
{
	this->inplaceActivate();
	this->uiActivate();
	return 0;
}

LRESULT WorkSpaceCtrl::OnTreeSelection(UINT msg, WPARAM wParam, LPARAM lParam)
{
	this->Fire( 1, mol::Variant(getPath()) );
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// Begin LabelEdit
//
//////////////////////////////////////////////////////////////////////////////

LRESULT WorkSpaceCtrl::OnTreeBeginLabelEdit(UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// Begin Drag Drop from Tree
//
//////////////////////////////////////////////////////////////////////////////

LRESULT WorkSpaceCtrl::OnTreeBeginDrag(UINT msg, WPARAM wParam, LPARAM lParam)
{
    mol::Crack message(msg,wParam,lParam);
   	HTREEITEM hti = message.nmtreeview()->itemNew.hItem;

	mol::Path path(getItemPath(hti));
	if ( !path.isDir() && !path.exists() )
		return 0;
    
	HIMAGELIST himl = TreeView_CreateDragImage( tree_, hti ); 

	mol::ImageList::beginDrag(*this,himl);
	mol::ImageList::enterDrag(*this);

	std::vector<mol::string> v;
	v.push_back(path);

	mol::UnknownPtr<IDropSource> drop = new mol::DropSource;
	mol::UnknownPtr<IDataObject> ido  = new mol::ShellDataObject(*this,WORK_SPACE_CTRL_ON_IDATA_NOTIFY,v);

	DWORD effect;
	HRESULT r = ::DoDragDrop(ido,drop,DROPEFFECT_COPY|DROPEFFECT_MOVE ,&effect);

	mol::ImageList::drop(*this);
	TreeView_SelectDropTarget(tree_, NULL); 

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////
// DataObject notifies of cut operation, update tree
/////////////////////////////////////////////////////////////////////////////////

LRESULT WorkSpaceCtrl::OnDataObject(UINT msg, WPARAM wParam, LPARAM lParam)
{
    IDataObject* data = (IDataObject*)lParam;
	std::vector<mol::string> v = mol::vectorFromDataObject(data);

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

//////////////////////////////////////////////////////////////////////////////
//
// Rename a Tree View Ctrl
//
//////////////////////////////////////////////////////////////////////////////

LRESULT WorkSpaceCtrl::OnTreeRename(UINT msg, WPARAM wParam, LPARAM lParam)
{
	mol::Crack message(msg,wParam,lParam);
	if ( message.treeViewDispInfo()->item.pszText )
	{
		HTREEITEM hit = this->tree_.getParentItem(message.treeViewDispInfo()->item.hItem);

		mol::Path pFrom(getItemPath(message.treeViewDispInfo()->item.hItem));
		mol::Path pTo(pFrom.pathname());
		pTo.append(message.treeViewDispInfo()->item.pszText);

		mol::ShellFileOp sfo;
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

mol::string WorkSpaceCtrl::getPath()
{
	HTREEITEM hit = tree_.getSelection();
	return getItemPath(hit);
}

///////////////////////////////////////////////////////////////////////
// check for mouse hit test
///////////////////////////////////////////////////////////////////////

HTREEITEM WorkSpaceCtrl::getHitTest()
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

void WorkSpaceCtrl::free(HTREEITEM it )
{
	while (HTREEITEM i = tree_.getChildItem(it))
	{
        free(i);
	}
	if ( it != TVI_ROOT )
	{
		WorkSpaceEntry* entry = getItemEntry(it);
		if ( entry ) 
			delete entry;
	}
	tree_.deleteNode(it);
}

///////////////////////////////////////////////////////////////////////
// display specific path
///////////////////////////////////////////////////////////////////////

BOOL WorkSpaceCtrl::displayPath(const mol::string& path)
{
	mol::Path p(path);
	if (!p.isDir())
		return FALSE;

	if ( path == mol::string(_T("")) )
		return FALSE;

	queue_.push( new WorkSpaceActionPath(this,path));

    return TRUE;
}

///////////////////////////////////////////////////////////////////////
// display specific tree item
///////////////////////////////////////////////////////////////////////

BOOL WorkSpaceCtrl::displayItem(HTREEITEM item)
{
    queue_.push( new WorkSpaceActionItem(this,item));
    return TRUE;
}


///////////////////////////////////////////////////////////////////////

mol::string WorkSpaceCtrl::getItemPath( HTREEITEM item )
{
	WorkSpaceEntry* entry = getItemEntry(item);
	if (entry)
		return entry->filename;
	return _T("");
}

///////////////////////////////////////////////////////////////////////

HTREEITEM WorkSpaceCtrl::getChildByPath( HTREEITEM item, const mol::string& path)
{
    HTREEITEM i = tree_.getChildItem( item );
    while ( i )
    {
			WorkSpaceEntry* entry = getItemEntry(i);
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

HTREEITEM WorkSpaceCtrl::findItemByPath( const mol::string& path, HTREEITEM parent)
{
	if ( path.size() == 0 )
		return 0;

    HTREEITEM i = tree_.getChildItem( parent );
    while ( i )
    {
		WorkSpaceEntry* entry = getItemEntry(i);
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

mol::Shit WorkSpaceCtrl::getShellItem(HTREEITEM it )
{
	return mol::desktop().parseDisplayName( getItemPath(it) );
}

///////////////////////////////////////////////////////////////////////
// actually add a Folder Node given info, retrieves icon
///////////////////////////////////////////////////////////////////////

HTREEITEM WorkSpaceCtrl::addFolderNode( mol::ShellFolder& folder, mol::Shit& it, HTREEITEM parent, int state)
{
    int			iImage   = 0;
    int			iIconSet = 0;

	mol::string name = folder.getDisplayNameOf(*it,SHGDN_INFOLDER);// | SHGDN_FORPARSING);
	mol::Path   path(folder.getDisplayNameOf(*it));
	if ( path.isUNC() )
		name = path.filename();

	iImage   = folder.getIconIndex(it);
	iIconSet = folder.getIconIndex(it,SHGFI_OPENICON);

	mol::FileInfo fi;
	WorkSpaceEntry* entry = new WorkSpaceEntry( path,fi,iImage);
	return tree_.addIconNodeParam( name, (LPARAM)entry, parent, iImage, iIconSet, state );
}

///////////////////////////////////////////////////////////////////////
// expand folder is called internally from background thread
///////////////////////////////////////////////////////////////////////

BOOL WorkSpaceCtrl::expandFolder( HTREEITEM item,bool force, int flags )
{
    WorkSpaceEntry* entry = getItemEntry(item);
    if ( entry->isParsed && !force)
    {
        if ( tree_.getItemState(item,TVIS_EXPANDED) == TVIS_EXPANDED )
            return TRUE;
        return tree_.expand( item, flags);
    }

	HTREEITEM it = tree_.getChildItem(item);
    if ( tree_.getItemText(it) == _T("") )
	{
        free(it);
	}

    mol::string path = entry->filename;

	mol::ShellFolder& desk = mol::desktop();

	std::vector<mol::string> files;
	std::vector<mol::string> dirs;

	std::map<mol::string, mol::Shit> filesMap;
	std::map<mol::string, mol::Shit> dirsMap;
		
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
					mol::string name = folder.getDisplayNameOf(*it);
					//if ( it->isPartOfFileSystem() )
					{
						dirs.push_back(name);
						dirsMap[name] = it;
					}
				}
				else
				if (displayFiles_)
				{
					mol::string name = folder.getDisplayNameOf(*it);
					files.push_back(name);
					filesMap[name] = it;
				}
			}
		}

        // deletions
        HTREEITEM it = tree_.getChildItem(item);
        while (it)
        {
            WorkSpaceEntry* entry = getItemEntry(it);
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
		for ( std::vector<mol::string>::iterator iter = dirs.begin(); iter != dirs.end(); iter++ )
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
            tree_.addNode(_T(""),hItem);
		}

		for ( std::vector<mol::string>::iterator iter = files.begin(); iter != files.end(); iter++ )
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
	return 0;
}

///////////////////////////////////////////////////////////////////////
// init tree to default desktop display
///////////////////////////////////////////////////////////////////////

BOOL WorkSpaceCtrl::initWorkSpace ()
{
	free();

	tree_.setImageList( mol::ShellFolder::SysImgList() );

	HTREEITEM hParent=0;
	mol::ShellFolder& desk = mol::desktop();

	mol::Shit drives = desk.getSpecialFolder(CSIDL_DRIVES);
	int drivesIcon = desk.getIconIndex( drives );
	mol::FileInfo fi;
	WorkSpaceEntry* entry = new WorkSpaceEntry(desk.getDisplayNameOf(*drives),fi,drivesIcon);
    entry->isParsed=true;
	hParent = tree_.addIconNodeParam( _T("Desktop"), (LPARAM)entry, 0, drivesIcon,drivesIcon );

	return TRUE;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////
// COM Properties and members
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// selection
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall WorkSpaceCtrl::get_Selection		( BSTR* dirname )
{
	*dirname = mol::ansi2BSTR(mol::tostring(getPath()));
	return S_OK;
}

HRESULT __stdcall WorkSpaceCtrl::put_Selection		( BSTR  dirname )
{
	mol::Bstr bstr(dirname);
	displayPath(bstr.toString());
	return S_OK;
}


HRESULT __stdcall WorkSpaceCtrl::get_HasFocus( VARIANT_BOOL* vbHasFocus)
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
// Remove file / path
///////////////////////////////////////////////////////////////////////

HRESULT WorkSpaceCtrl::Remove(BSTR path)
{
	HTREEITEM hit = this->findItemByPath( mol::Bstr(path).toString() );
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
	return S_OK;
}
///////////////////////////////////////////////////////////////////////
// add folder - file
///////////////////////////////////////////////////////////////////////

HRESULT WorkSpaceCtrl::Add(BSTR path)
{
	mol::Bstr bstr(path);
	mol::Shit shit = mol::desktop().parseDisplayName(bstr.toString());

	if ( shit->isDir() )
	{
		HTREEITEM hItem = addFolderNode( mol::desktop(), shit, TVI_ROOT,0 );
		tree_.addNode( _T(""),hItem);
	}
	else
	{
		HTREEITEM hItem = this->addFolderNode( mol::desktop(), shit, TVI_ROOT,0 );
	}

	return S_OK;
}


//////////////////////////////////////////////////////////////////////////////
//
// Update focused dir
//
//////////////////////////////////////////////////////////////////////////////

HRESULT WorkSpaceCtrl::Update()
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

HRESULT WorkSpaceCtrl::Cut ()
{
	HTREEITEM hit = tree_.getSelection();
	if ( hit )
	{
		tree_.setItemState(hit,TVIS_CUT,TVIS_CUT);
		std::vector<mol::string> v;
		v.push_back(getItemPath(hit));
		mol::UnknownPtr<IDataObject> ido = new mol::ShellDataObject(*this,WORK_SPACE_CTRL_ON_IDATA_NOTIFY, v,true);        
		HRESULT r = ::OleSetClipboard(ido);
	}
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////
//
// Copy selected tree item
//
//////////////////////////////////////////////////////////////////////////////

HRESULT WorkSpaceCtrl::Copy ()
{
	HTREEITEM hit = tree_.getSelection();
	if ( hit )
	{
		tree_.setItemState(hit,TVIS_CUT,0);
		std::vector<mol::string> v;
		v.push_back(getItemPath(hit));
		mol::UnknownPtr<IDataObject> ido = new mol::ShellDataObject(*this,WORK_SPACE_CTRL_ON_IDATA_NOTIFY,v);
		HRESULT r = ::OleSetClipboard(ido);
	}
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////
//
// Paste into tree view
//
//////////////////////////////////////////////////////////////////////////////

HRESULT WorkSpaceCtrl::Paste ()
{
	mol::UnknownPtr<IDataObject> ido;
	::OleGetClipboard(&ido);
	if ( !ido )
		return E_FAIL;

	std::vector<mol::string> v = vectorFromDataObject(ido);
	if ( v.size() < 1 )
		return E_FAIL;

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
				mol::ShellFileOp sfo;
				sfo.copy(*this,v,path,FOF_ALLOWUNDO);
				this->Update();
			}
			else if (dw & DROPEFFECT_MOVE )
			{
				mol::ShellFileOp sfo;
				sfo.move(*this,v,path,FOF_ALLOWUNDO);
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

HRESULT WorkSpaceCtrl::Rename()
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

HRESULT WorkSpaceCtrl::Delete()
{
	HTREEITEM hit = tree_.getSelection();
	if ( hit )
	{
		mol::Path p = getItemPath(hit);
		mol::ShellFileOp sfo;
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

HRESULT WorkSpaceCtrl::Properties()
{
	HTREEITEM hit = tree_.getSelection();
	if ( hit )
	{
		mol::ExecuteShell(getPath(),_T("properties"),1,SEE_MASK_INVOKEIDLIST);
	}
	return S_OK;
}


//////////////////////////////////////////////////////////////////////////////
//
// shellexecute selected tree or dir item
//
//////////////////////////////////////////////////////////////////////////////

HRESULT WorkSpaceCtrl::Execute()
{
	HTREEITEM hit = tree_.getSelection();
	if ( hit )
	{
		mol::ExecuteShell(getPath());
	}
	return S_OK;
}
//////////////////////////////////////////////////////////////////////////////
HRESULT WorkSpaceCtrl::CreateDir()
{
	mol::string tmp = _T("newDir_");	
	int i = 0;
	while(true)
	{
		mol::Path path(getPath());
		mol::stringstream oss;
		oss << tmp << i;
		path.append(oss.str());
		if ( !::CreateDirectory(path.c_str(),0) )
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

///////////////////////////////////////////////////////////////////////
// Drag Drop Implementation
///////////////////////////////////////////////////////////////////////


HRESULT __stdcall WorkSpaceCtrl::WorkSpaceCtrl_Drop::Drop( IDataObject* pDataObject, DWORD keyState, POINTL pt , DWORD* pEffect)
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
		WorkSpaceEntry* entry = (WorkSpaceEntry*)(tree_->tree_.getLPARAM(tvht.hItem));
		mol::Path path = entry->filename;
		
		if ( path.isDir() )
		{
			std::vector<mol::string> v = mol::vectorFromDataObject(pDataObject);
			*pEffect &= (DROPEFFECT_COPY|DROPEFFECT_MOVE);
			if ( (*pEffect & DROPEFFECT_MOVE ) && (keyState & MK_CONTROL) )
			{
				mol::ShellFileOp sfo;
				sfo.move(*tree_,v,path,FOF_ALLOWUNDO);
				tree_->displayItem(tvht.hItem);
			}
			else if ( *pEffect & DROPEFFECT_COPY )
			{
				mol::ShellFileOp sfo;
				sfo.copy(*tree_,v,path,FOF_ALLOWUNDO);
				tree_->displayItem(tvht.hItem);
			}
            mol::FormatEtcDropEffect        de;
			mol::StgMedium sm(*pEffect, GHND|GMEM_SHARE);
            pDataObject->SetData( &de, &sm, TRUE );
		}
	}
	*pEffect = DROPEFFECT_NONE;
	return S_OK;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT  __stdcall WorkSpaceCtrl::WorkSpaceCtrl_Drop::DragEnter( IDataObject* , DWORD key, POINTL , DWORD* pEffect )
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

HRESULT __stdcall WorkSpaceCtrl::WorkSpaceCtrl_Drop::DragOver( DWORD key, POINTL pt, DWORD* pEffect )
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

HRESULT  __stdcall WorkSpaceCtrl::WorkSpaceCtrl_Drop::DragLeave()
{
	mol::ImageList::leaveDrag(*tree_);
	TreeView_SelectDropTarget(tree_->tree_, NULL); 
    return S_OK;
}



//} // end namespace mol

