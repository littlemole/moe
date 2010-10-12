#include "stdafx.h"
#include "ShellListCtrl.h"
#include "ole/Bstr.h"
#include "ole/enum.h"
#include "ole/Img.h"
#include "util/str.h"

#include <sstream>


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

void DirQueueAction::operator()()
{
	dirlist->run(path);
}

///////////////////////////////////////////////////////////////////////////////

ShellListCtrl::ShellListCtrl(void)	
{
	sortDir_ = 1;
    bCancel_ = FALSE;
	displayFiles_ = true;
	sharedMenu_ = 0;
	eraseBackground_ = 1;

	sizel.cx = 300;
	sizel.cy = 200;
	bgCol_    = RGB(255,255,255);
	foreCol_  = RGB(0,0,0);
	mol::ole::PixeltoHIMETRIC(&sizel);
}

//////////////////////////////////////////////////////////////////////////////

ShellListCtrl::~ShellListCtrl()
{
	queue_.clear();
    clear();	

}


void ShellListCtrl::run( const mol::string& uri )
{
    path_ = uri;

	clear();

    std::vector<mol::string> files;
    std::vector<mol::string> dirs;

    std::map<mol::string, DirListEntry*> filesMap;
	std::map<mol::string, DirListEntry*> dirsMap;

	//mol::string p( mol::toString(path_));
    //p.addBackSlash();

	Shit shit = parseDisplayName(path_);
	if ( !shit )
		return;
    
	if ( shit->isPartOfFileSystem() )//>isDir() )
    {
		//path_ = p;
        const char* entry = 0;
        ShellFolder& desk = desktop();
        ShellFolder sf(*shit);

        sf.enumObjects(0);
        while( Shit it = sf.next() )
        {
			mol::string tmp = sf.getDisplayNameOf(*it);
//			file f(tmp);
            int i = sf.getIconIndex(it);
            mol::string filename = sf.getDisplayNameOf(*it,SHGDN_INFOLDER | SHGDN_FORPARSING);

			if ( filename.substr(0,3) == _T("::{") )
				continue;

			mol::filestream fs;
			if ( it->isDir() && mol::Path::isDir(tmp) )
			{			
				if ( fs.open( mol::tostring(tmp), 
							  FILE_GENERIC_READ,//,FILE_LIST_DIRECTORY,
							  FILE_SHARE_READ|FILE_SHARE_WRITE|FILE_SHARE_DELETE,
							  0,OPEN_EXISTING,FILE_FLAG_BACKUP_SEMANTICS ) 
					)
                //if (f.open(FILE_LIST_DIRECTORY,FILE_FLAG_BACKUP_SEMANTICS,FILE_SHARE_READ|FILE_SHARE_DELETE))
                {
					mol::FileInfo fi = fs.fileInfo();
                   // file_info& fi = f.fileInfo();
                    DirListEntry* dle = new DirListEntry( tmp, fi, i );
                    dirs.push_back(tmp);
                    dirsMap[tmp] = dle;
                }
                continue;
			}
			if ( fs.open( mol::tostring(tmp), 
						  FILE_GENERIC_READ,
						  FILE_SHARE_READ|FILE_SHARE_DELETE|FILE_SHARE_WRITE,
						  0,OPEN_EXISTING ) 
				)
			{
				mol::FileInfo& fi = fs.fileInfo();
				DirListEntry* de = new DirListEntry( tmp, fi,i);
				files.push_back(tmp);
				filesMap[tmp] = de;
			}
        }

		std::sort( files.begin(), files.end() );
		std::sort( dirs.begin(), dirs.end()   );

        int index = 0;
        list_.setRedraw(false);
		for ( std::vector<mol::string>::iterator iter = dirs.begin(); iter != dirs.end(); iter++ )
		{
			mol::string p(*iter);
            std::vector<mol::string> entries;
            DirListEntry* entry = dirsMap[*iter];
			entries.push_back(mol::Path::filename(p));
            entries.push_back(_T("directory"));
            entries.push_back(entry->fileinfo.lastWritten());
            list_.insertItem(entries,index,0,entry->iconindex,(LPARAM)entry);
            index++;
		}

		if ( displayFiles_ )
		for ( std::vector<mol::string>::iterator iter = files.begin(); iter != files.end(); iter++ )
		{
			mol::string p(*iter);
            std::vector<mol::string> entries;
            DirListEntry* entry = filesMap[*iter];
            entries.push_back(mol::Path::filename(p));
            entries.push_back(entry->fileinfo.fileSize());
            entries.push_back(entry->fileinfo.lastWritten());
            list_.insertItem(entries,index,0,entry->iconindex,(LPARAM)entry);
            index++;
		}
        list_.setRedraw(true);
	}
	sortDir_ = 1;
	sortCol_ = 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// OnDestroy - over and out
//
//////////////////////////////////////////////////////////////////////////////

LRESULT ShellListCtrl::OnDestroy(UINT msg, WPARAM wParam, LPARAM lParam)
{
    dirMon_.events.unSubscribe(*this);
	dirMon_.cancel();
	queue_.cancel();
	::RevokeDragDrop(*this);
    return 0;
}
//////////////////////////////////////////////////////////////////////////////

LRESULT ShellListCtrl::OnCreate(UINT msg, WPARAM wParam, LPARAM lParam)
{
	listMenu_.load(IDM_LIST_DIR);

    RECT clientRect;
	getClientRect(clientRect);
    int w = clientRect.right-200;
    int w3 = w/3;
	list_.create((HMENU)1,clientRect,*this);
	list_.show(SW_SHOW);

    ListView_SetImageList(list_,ShellFolder::SysImgList(),LVSIL_SMALL);
    list_.insertColumn( _T("filename"), 0, w3*2 );
    list_.insertColumn( _T("size"), w3/2 );
    list_.insertColumn( _T("modified"), w3/2 );

	
	Drop = new ShellListCtrl_Drop(this);
	::RegisterDragDrop(*this,Drop);
    dirMon_.events.subscribe(*this,SHELL_LIST_CTRL_ID_DIRMON);

	return 0;
}

LRESULT ShellListCtrl::OnSize(UINT msg, WPARAM wParam, LPARAM lParam)
{
	getClientRect(clientRect_);
		
	// get new width and height
	clientRect_.right  = LOWORD (lParam) ;
	clientRect_.bottom = HIWORD (lParam) ;

	list_.move(clientRect_);
	return 0;
}
//////////////////////////////////////////////////////////////////////////////

LRESULT ShellListCtrl::OnColumn(UINT msg, WPARAM wParam, LPARAM lParam)
{
	mol::Crack message(msg,wParam,lParam);
	sort(message.listview()->iSubItem);
	return 0;
}

//////////////////////////////////////////////////////////////////////////////

LRESULT ShellListCtrl::OnClick(UINT msg, WPARAM wParam, LPARAM lParam)
{
	this->uiActivate();
	return 0;
}

//////////////////////////////////////////////////////////////////////////////

LRESULT ShellListCtrl::OnDblClick(UINT msg, WPARAM wParam, LPARAM lParam)
{
	mol::Crack message(msg,wParam,lParam);
	int it = message.listActivate()->iItem;
	DirListEntry* entry = getItemEntry(it);
	if ( entry )
	{
		mol::string p(entry->filename);
		if ( mol::Path::isDir(p) )
		{
			setPath(p);
		}        
		else
		{
			this->fire(2,mol::bstr(p));
		}
	}
	return 0;
}


//////////////////////////////////////////////////////////////////////////////
//
// Keys
//
//////////////////////////////////////////////////////////////////////////////

LRESULT ShellListCtrl::OnKeyDown(UINT msg, WPARAM wParam, LPARAM lParam)
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
		if ( wd == VK_RETURN )
		{

		}
	}
	return 0;
}



//////////////////////////////////////////////////////////////////////////////

LRESULT ShellListCtrl::OnBeginLabelEdit(UINT msg, WPARAM wParam, LPARAM lParam)
{
	// FALSE to allow ... see psdk
	return FALSE;
}

LRESULT ShellListCtrl::OnEndRename(UINT msg, WPARAM wParam, LPARAM lParam)
{
	mol::Crack message(msg,wParam,lParam);
	if ( message.listviewDispInfo()->item.pszText)
	{
		mol::string pFrom( getItemPath(message.listviewDispInfo()->item.iItem) );
		mol::string pTo  ( mol::Path::pathname(pFrom) );
		pTo = mol::Path::append( pTo, message.listviewDispInfo()->item.pszText);

		ShellFileOp sfo;
		sfo.rename(*this,pFrom,pTo,FOF_ALLOWUNDO);
	}	
	return 0;
}



//////////////////////////////////////////////////////////////////////////////

LRESULT ShellListCtrl::OnBeginDrag(UINT msg, WPARAM wParam, LPARAM lParam)
{
	std::vector<mol::string> v = selectionPaths();
	std::vector<int> vi        = selectionIndexes();

	//beginDrag( vi );      
	POINT pt = {0,0};;
	
	HIMAGELIST hi = 0;
	if ( vi.size() > 0 )
	{
        hi = ListView_CreateDragImage( list_, vi[0], &pt );

		for ( unsigned int i = 1; i < vi.size(); i++ )
		{
			HIMAGELIST h  = ListView_CreateDragImage( list_, vi[i], &pt );
			HIMAGELIST hh = ImageList_Merge(hi,0,h,0,0,20*i);
			ImageList_Destroy(hi);
			ImageList_Destroy(h);
			hi = hh;
		}
	}
	mol::ImageList::beginDrag(*this,hi);
	
	punk<IDropSource> drop = new DropSrc;
	punk<IDataObject> ido = new ShellDataObj(v);
	DWORD effect;
	HRESULT r = ::DoDragDrop(ido,drop,DROPEFFECT_COPY|DROPEFFECT_MOVE,&effect);
	if ( r != S_OK )
	{
		ODBGS("DoDragDrop Failed");
	}	
	drop();
	return 0;
}

//////////////////////////////////////////////////////////////////////////////

LRESULT ShellListCtrl::OnContext(UINT msg, WPARAM wParam, LPARAM lParam)
{
	mol::Crack message(msg,wParam,lParam);

	// prepare context menue
	mol::Menu m(listMenu_.getSubMenu(0));

	// get selection, if we have a hittest update selection beforehand
	int hit = this->list_.hitTest(LVHT_TOLEFT|LVHT_ONITEM);
	mol::string p ;
	if ( hit != -1 )
	{
		p = this->getItemPath(hit);
	}
	else
		p = getPath();
	// check if to display a context menu
	//if ( hit!=-1 )
	//	return 0;

	mol::string selection = _T("");
	std::vector<mol::string> v = selectionPaths();
	if ( v.size() > 0 )
	{
		selection = v[0];
	}

	m.enableItem(IDM_LIST_ENTERDIR);
	m.enableItem(IDM_LIST_RENAME);
	m.enableItem(IDM_LIST_DELETE);
	m.enableItem(IDM_LIST_OPEN);
	m.enableItem(IDM_LIST_CUT);
	m.enableItem(IDM_LIST_COPY);
	m.enableItem(IDM_LIST_PASTE);
	m.enableItem(IDM_LIST_PROPERTIES);
	m.enableItem(IDM_LIST_EXECUTE);
	if ( hit==-1 )
	{
		m.disableItem(IDM_LIST_ENTERDIR);
		m.disableItem(IDM_LIST_DELETE);
		m.disableItem(IDM_LIST_RENAME);
		m.disableItem(IDM_LIST_OPEN);
		m.disableItem(IDM_LIST_CUT);
		m.disableItem(IDM_LIST_COPY);
		//m.disableItem(IDM_LIST_PASTE);
		m.disableItem(IDM_LIST_PROPERTIES);
		m.disableItem(IDM_LIST_EXECUTE);
	}
	if ( !mol::Path::isDir(selection) )
		m.disableItem(IDM_LIST_ENTERDIR);

	if ( mol::Path::isRoot(selection) )
	{
		m.disableItem(IDM_LIST_DELETE);
		m.disableItem(IDM_LIST_CUT);
		m.disableItem(IDM_LIST_COPY);
	}

	LRESULT res = returnContext(m);
	switch (res)
	{
		case IDM_LIST_OPEN :
		{
			this->fire(3,variant(p)); 
			break;
		}
		case IDM_LIST_UPDATE :
		{
			this->Update();
			break;
		}
		case IDM_LIST_NEWDIR :
		{
			this->CreateDir();
			break;
		}
		case IDM_LIST_RENAME:
		{
			this->Rename();
			break;
		}
		case IDM_LIST_DELETE :
		{
			this->Delete();
			break;
		}
		case IDM_LIST_CUT :
		{
			this->Cut();
			break;
		}
		case IDM_LIST_COPY :
		{
			this->Copy();
			break;
		}
		case IDM_LIST_PASTE :
		{
			this->Paste();
			break;
		}
		case IDM_LIST_EXECUTE :
		{
			this->Execute();
			break;
		}
		case IDM_LIST_PROPERTIES :
		{
			this->Properties();
			break;
		}
		case IDM_LIST_UPDIR :
		{
			this->UpDir();
			break;
		}
		case IDM_LIST_ENTERDIR :
		{
			std::vector<mol::string> v = selectionPaths();
			if ( v.size() == 1 )
			{
				mol::string tmp(v[0]);
				if ( mol::Path::isDir(tmp) )
				{
					setPath(tmp);
					return true;
				}
			}
			break;
		}
	}	
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
//
//
//////////////////////////////////////////////////////////////////////////////

LRESULT ShellListCtrl::OnDirMon(UINT msg, WPARAM wParam, LPARAM lParam)
{
	refresh();
    return 0;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// Up Dir
//
//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ShellListCtrl::UpDir()
{
	mol::string p(getPath());
	mol::string parent (mol::Path::parentDir(p));
	parent = mol::Path::addBackSlash(parent);
	if ( mol::Path::isDir(parent) )
	{
		setPath(parent);
		return true;
	}
	return false;
}

//////////////////////////////////////////////////////////////////////////////
//
// Update focused dir
//
//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ShellListCtrl::Update()
{
	refresh();
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ShellListCtrl::CreateDir()
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

//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ShellListCtrl::Rename()
{
	int index = -1;
	std::vector<int> v = selectionIndexes();
	if ( v.size() > 0 )
	{
		list_.editLabel(v[0]);
		return S_OK;
	}
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////
//
// delete selected tree or dir item
//
//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ShellListCtrl::Delete()
{
	std::vector<mol::string> v = selectionPaths();
	if ( v.size() > 0 )
	{
		ShellFileOp sfo;
		sfo.remove(*this,v,FOF_ALLOWUNDO);
	}
	return S_OK;
}

HRESULT __stdcall ShellListCtrl::Properties()
{
	std::vector<mol::string> v = selectionPaths();

	if ( v.size() > 0 )
	{
		execute_shell( v[0], _T("properties"),1,SEE_MASK_INVOKEIDLIST );		
	}
	return S_OK;
}

HRESULT __stdcall ShellListCtrl::Execute()
{
	std::vector<mol::string> v = selectionPaths();

	if ( v.size() > 0 )
	{
		execute_shell( v[0] );		
	}
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////
//
// open selected dir
//
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ShellListCtrl::Cut ()
{
	list_.setItemState(-1, 0, LVIS_CUT );
	int index = -1;
	std::vector<mol::string> v;
	while ( (index = list_.getNextItem(index)) != -1 )
	{
		list_.setItemState(index, LVIS_CUT, LVIS_CUT );
		v.push_back( getItemPath(index) );
	}
	if ( v.size() > 0 )
	{
		punk<IDataObject> ido = new ShellDataObj(v,true);
		HRESULT r = ::OleSetClipboard(ido);		
	}
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ShellListCtrl::Copy ()
{
	list_.setItemState(-1, 0, LVIS_CUT );
	int index = -1;
	std::vector<mol::string> v = selectionPaths();
	if ( v.size() > 0 )
	{
		punk<IDataObject> ido = new ShellDataObj(v);
		HRESULT r = ::OleSetClipboard(ido);			
	}
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ShellListCtrl::Paste ()
{
	std::vector<mol::string> v = selectionPaths();
	if ( v.size() > 1 )
		return S_OK;

	mol::string path;
	if ( v.size() == 1 )
		path = v[0];
	else
		path = getPath();

	format_etc_pref_dropeffect	fe;
	STGMEDIUM					sm;

	punk<IDataObject> ido;
	::OleGetClipboard(&ido);
	if (!ido)
		return S_OK;

	v.clear();
	v = vectorFromDataObject(ido);

	if ( v.size() < 1 )
		return S_OK;

	DWORD  dw = DROPEFFECT_COPY;
	DWORD* d = &dw;

	if ( S_OK == ido->GetData( &fe, &sm ) )
	{
		if ( sm.tymed == TYMED_HGLOBAL )
		{
			mol::global glob;
			glob.attach(sm.hGlobal);
	
			*d = *((DWORD*)glob.lock());
	
			glob.unLock();
			glob.detach();
		}
	}
	
	if (*d & DROPEFFECT_COPY )
	{
		ShellFileOp sfo;
		sfo.copy(*this,v,path,FOF_ALLOWUNDO);
	}
	else if (*d & DROPEFFECT_MOVE )
	{
		ShellFileOp sfo;
		sfo.move(*this,v,path,FOF_ALLOWUNDO);
	}
	format_etc_dropeffect fede;
	StgMedium stgm(*d, GHND|GMEM_SHARE);
	ido->SetData(&fede,&stgm,TRUE);

	return S_OK;
}
/*
void ShellListCtrl::createInplaceMenu() 
{
	OLEMENUGROUPWIDTHS widths;
	for(int i= 0; i < 6; i++)
		widths.width[i] = 0;

	HMENU menu = ::CreateMenu();
	HRESULT hr = frame_->InsertMenus(menu,&widths);
	if ( hr != S_OK )
		return;

	int pos = widths.width[0];
	//Edit Menu
	HMENU sub = oleMenu_.getSubMenu(0);
	::InsertMenu(menu,(UINT)pos,MF_BYPOSITION|MF_POPUP,(UINT_PTR)sub,"Edit");
	widths.width[1] = 1;
	pos += widths.width[1];
	//Object
	pos += widths.width[2];
	pos += widths.width[3];
	//Help
	pos += widths.width[4];
//	sub = oleMenu_.getSubMenu(1);
//	::InsertMenu(menu,(UINT)pos,MF_BYPOSITION|MF_POPUP,(UINT_PTR)sub,"Help");
//	widths.width[5] = 1;

	sharedMenu_ = menu;
	holemenu_ = ::OleCreateMenuDescriptor(menu,&widths);
	frame_->SetMenu(menu,holemenu_,*this);
}

void ShellListCtrl::removeInplaceMenu() 
{
	if ( sharedMenu_ == NULL )
		return;

	frame_->SetMenu(0,0,0);
	::OleDestroyMenuDescriptor(holemenu_);
	holemenu_ = 0;

	int c = ::GetMenuItemCount(sharedMenu_);
	for ( int i = c; i>=0; i--)
	{
		HMENU tmp = ::GetSubMenu(sharedMenu_,i);
		for ( int j = 0; j < ::GetMenuItemCount(oleMenu_); j++ )
		{
			HMENU known = oleMenu_.getSubMenu(j);
			if ( known == tmp )
			{
				::RemoveMenu(sharedMenu_,i,MF_BYPOSITION);
				break;
			}
		}
	}
	frame_->RemoveMenus(sharedMenu_);
	::DestroyMenu(sharedMenu_);
	sharedMenu_ = 0;
}
*/
//////////////////////////////////////////////////////////////////////////////

void ShellListCtrl::clear()
{
    for ( int i = 0; i < list_.getItemCount(); i++ )
    {
		DirListEntry* entry = getItemEntry(i);
        delete entry;
    }
	list_.deleteAllItems();
}

//////////////////////////////////////////////////////////////////////////////

void ShellListCtrl::refresh()
{
	mol::string p(path_);

	if ( !mol::Path::exists(p) ) 
	{
		p = mol::Path::parentDir(p);

		while ( !mol::Path::exists(p) ) {
			p = mol::Path::parentDir(p);
			if ( p == _T("") )
				break;
		}
	}

	return setPath(p);
}

//////////////////////////////////////////////////////////////////////////////

int ShellListCtrl::getItemByPath(const mol::string& path)
{
    int i = -1;
    while ( (i = list_.getNextItem(i,LVNI_ALL)) != -1 )
    {
        DirListEntry* entry = getItemEntry(i);
        if ( entry->filename == path )
            return i;
        list_.getNextItem(i,LVNI_ALL);
    }
    return i;
}

//////////////////////////////////////////////////////////////////////////////

DirListEntry* ShellListCtrl::getItemEntry(int i )
{
	int x = list_.getItemCount();
	if ( (i == -1) || (i < list_.getItemCount()) )
	{
		return (DirListEntry*)list_.getItemLPARAM(i);
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////////

mol::string ShellListCtrl::getItemPath(int i)
{
	DirListEntry* entry = getItemEntry(i);
	if ( entry )
		return entry->filename;
	return _T("");
}

//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////

std::vector<mol::string> ShellListCtrl::selectionPaths()
{
	int index = -1;
	std::vector<mol::string> v;
	while ( (index = list_.getNextItem(index)) != -1 )
	{
		v.push_back( getItemPath(index) );
	}
    return v;
}

//////////////////////////////////////////////////////////////////////////////

std::vector<int> ShellListCtrl::selectionIndexes()
{
	int index = -1;
	std::vector<int> v;
	while ( (index = list_.getNextItem(index)) != -1 )
	{
		v.push_back(index);
	}
    return v;
}

//////////////////////////////////////////////////////////////////////////////

std::vector<DirListEntry*> ShellListCtrl::selectionEntries()
{
	int index = -1;
	std::vector<DirListEntry*> v;
	while ( (index = list_.getNextItem(index)) != -1 )
	{
		v.push_back( getItemEntry(index));
	}
    return v;
}

//////////////////////////////////////////////////////////////////////////////

bool  ShellListCtrl::doHitTest()
{
	int i = list_.hitTest();
	if ( i != -1 )
	{
		list_.setItemState(-1, 0, LVIS_CUT  );
		list_.setItemState(-1, 0, LVIS_SELECTED  );
		list_.setItemState( i, LVIS_SELECTED , LVIS_SELECTED );
		return true;
	}
	return false;
}

//////////////////////////////////////////////////////////////////////////////

void ShellListCtrl::setPath(const mol::string& p)  
{ 
	setText(p); 
    pathEvent.fire((LPARAM)p.c_str());    
	dirMon_.watch(p); 
	queue_.push(new DirQueueAction(p,this));
	this->fire(1,p);
	this->fire(4,p);
}

//////////////////////////////////////////////////////////////////////////////

mol::string ShellListCtrl::getPath()
{
    return path_;
}

//////////////////////////////////////////////////////////////////////////////

BOOL ShellListCtrl::sort(int c)
{
	sortDir_ *= -1;
    sortCol_  = c;
    return ListView_SortItems( list_, CompareFunc, (LPARAM)this );
}

//////////////////////////////////////////////////////////////////////////////

int CALLBACK ShellListCtrl::CompareFunc(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
    ShellListCtrl* pThis = (ShellListCtrl*)lParamSort;
    if ( pThis )
        return pThis->compare(lParam1, lParam2);
    return 0;
}
//////////////////////////////////////////////////////////////////////////////

int ShellListCtrl::compare(LPARAM lParam1, LPARAM lParam2)
{
    DirListEntry* de1 = (DirListEntry*)lParam1;
    DirListEntry* de2 = (DirListEntry*)lParam2;
    if ( !de1 || !de2)
        return -1*sortDir_;

    if (de1->isDir() && !de2->isDir() )
        return -1;

    if (!de1->isDir() && de2->isDir() )
        return 1;

    if ( sortCol_ == 0 )
    {
		std::string s1(mol::tostring(de1->filename) );
		std::string s2(mol::tostring(de2->filename) );
        return _stricmp( s1.c_str(), s2.c_str() )*sortDir_;
        // p1 before p2
    }
    else if ( sortCol_ == 1 )
    {
        if ( de1->fileinfo.fileSizeHigh() < de2->fileinfo.fileSizeHigh() )
            return -1*sortDir_;
        if ( de1->fileinfo.fileSizeHigh() > de2->fileinfo.fileSizeHigh() )
            return 1*sortDir_;
        if ( de1->fileinfo.fileSizeLow() < de2->fileinfo.fileSizeLow() )
            return -1*sortDir_;
        if ( de1->fileinfo.fileSizeLow() > de2->fileinfo.fileSizeLow() )
            return 1*sortDir_;
        return 0;
    }
    else if ( sortCol_ == 2 )
    {
        if ( de1->fileinfo.lastWriteTime().dwHighDateTime  < de2->fileinfo.lastWriteTime().dwHighDateTime  )
            return -1*sortDir_;
        if ( de1->fileinfo.lastWriteTime().dwHighDateTime  > de2->fileinfo.lastWriteTime().dwHighDateTime  )
            return 1*sortDir_;
        if ( de1->fileinfo.lastWriteTime().dwLowDateTime  < de2->fileinfo.lastWriteTime().dwLowDateTime  )
            return -1*sortDir_;
        if ( de1->fileinfo.lastWriteTime().dwLowDateTime  > de2->fileinfo.lastWriteTime().dwLowDateTime  )
            return 1*sortDir_;
        return 0;
    }
    return -1*sortDir_;
}

//////////////////////////////////////////////////////////////////////////////
//
// User drops - 
//
//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ShellListCtrl::ShellListCtrl_Drop::Drop( IDataObject* pDataObject, DWORD keyState, POINTL pt , DWORD* pEffect)
{
	mol::string p;
	mol::ImageList::drop(*list_);

	int i = list_->list_.hitTest();
	if ( i != -1 )
		p = list_->getItemPath(i);

	if ( (p == _T("") ) || (!mol::Path::isDir(p)) )
		p = list_->getPath();

	std::vector<mol::string> v;
	v = vectorFromDataObject(pDataObject);

	if ( ((*pEffect) & DROPEFFECT_MOVE ) && (keyState & MK_CONTROL) )
	{
		ShellFileOp sfo;
		sfo.move(*list_,v,p,FOF_ALLOWUNDO);
	}
	else if ( (*pEffect) & DROPEFFECT_COPY )
	{
		ShellFileOp sfo;
		sfo.copy(*list_,v,p,FOF_ALLOWUNDO);
	}

	format_etc_dropeffect fede;
	StgMedium sm(*pEffect, GHND|GMEM_SHARE);
	pDataObject->SetData(&fede,&sm,TRUE);

	*pEffect = DROPEFFECT_NONE;
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////

HRESULT  __stdcall ShellListCtrl::ShellListCtrl_Drop::DragEnter( IDataObject* , DWORD key , POINTL , DWORD* pEffect )
{
	(*pEffect) &= (DROPEFFECT_COPY|DROPEFFECT_MOVE);
	if ( key & MK_CONTROL )
		*pEffect = DROPEFFECT_MOVE;
	else
		*pEffect = DROPEFFECT_COPY;
	mol::ImageList::enterDrag(*list_);
    return S_OK;
}

//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ShellListCtrl::ShellListCtrl_Drop::DragOver( DWORD key, POINTL, DWORD* pEffect )
{
	list_->setFocus();
	mol::ImageList::doDrag(*list_);

	int i = list_->list_.hitTest();
	if ( i != -1 )
	{
		mol::ImageList::leaveDrag(*list_);
		list_->list_.setItemState(-1,0);
		list_->list_.setItemState(i,LVIS_SELECTED);
		list_->update();
		mol::ImageList::enterDrag(*list_);			
	}
	(*pEffect) &= (DROPEFFECT_COPY|DROPEFFECT_MOVE);
	if ( key & MK_CONTROL )
		*pEffect = DROPEFFECT_MOVE;
	else
		*pEffect = DROPEFFECT_COPY;
    return S_OK;
}

//////////////////////////////////////////////////////////////////////////////

HRESULT  __stdcall ShellListCtrl::ShellListCtrl_Drop::DragLeave()
{
	mol::ImageList::leaveDrag(*list_);
    return S_OK;
}
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// selection
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ShellListCtrl::get_Selection		( VARIANT* dirname )
{
	if ( dirname )
	{
		::VariantClear(dirname);
		
		dirname->vt = VT_BSTR;
		dirname->bstrVal = ansi2BSTR(mol::tostring(getPath()));
	}
	return S_OK;
}

HRESULT __stdcall ShellListCtrl::put_Selection		( VARIANT  dirname )
{
	if ( S_OK != OnRequestEdit(2) )
		return S_FALSE;

	if ( dirname.vt == VT_BSTR )
	{
		bstr b(dirname.bstrVal);
		if ( (b.tostring() == "")  || 
			 (b.tostring() == "/") ||
			 (b.tostring() == "\\") )
		{
			b = _T("::{20D04FE0-3AEA-1069-A2D8-08002B30309D}");
		}
		setPath(b.toString());
		this->OnChanged(2);
	}
	return S_OK;
}

///////////////////////////////////////////////////////////////////////
// displayfiles
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ShellListCtrl::get_DisplayFiles	( VARIANT_BOOL* vb )
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

HRESULT __stdcall ShellListCtrl::put_DisplayFiles	( VARIANT_BOOL vb  )
{
	if ( S_OK != OnRequestEdit(1) )
		return S_FALSE;

	if ( vb == VARIANT_TRUE )
		displayFiles_ = true;
	else
		displayFiles_ = false;

	this->OnChanged(1);
	return S_OK;
}

HRESULT __stdcall ShellListCtrl::get_HasFocus( VARIANT_BOOL* vbHasFocus)
{
	if ( vbHasFocus )
	{
		if ( list_.hasFocus() )
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

HRESULT __stdcall ShellListCtrl::Load( LPSTREAM pStm)
{
	pStm >> mol::property( mol::DispId(this,ShellListCtrl_Dispatch_DisplayFiles,VT_BSTR) )
		 >> mol::property( mol::DispId(this,ShellListCtrl_Dispatch_Selection,VT_BSTR) )
		 >> mol::property( &sizel );

	return S_OK;
}

HRESULT __stdcall ShellListCtrl::Save( LPSTREAM pStm,BOOL fClearDirty)
{
	pStm << mol::property( mol::DispId(this,ShellListCtrl_Dispatch_DisplayFiles,VT_BSTR) )
		 << mol::property( mol::DispId(this,ShellListCtrl_Dispatch_Selection,VT_BSTR) )
		 << mol::property( &sizel );

	return S_OK;
}

HRESULT __stdcall ShellListCtrl::Load( IPropertyBag *pPropBag,IErrorLog *pErrorLog)
{
	pPropBag >> mol::property( _T("displayfiles"), mol::DispId(this,ShellListCtrl_Dispatch_DisplayFiles,VT_BSTR) )
			 >> mol::property( _T("selection"), mol::DispId(this,ShellListCtrl_Dispatch_Selection,VT_BSTR) )
			 >> mol::property( _T("cs"), &sizel );

	return S_OK;
}

HRESULT __stdcall ShellListCtrl::Save( IPropertyBag *pPropBag,BOOL fClearDirty,BOOL fSaveAllProperties)
{
	pPropBag << mol::property( _T("displayfiles"), mol::DispId(this,ShellListCtrl_Dispatch_DisplayFiles,VT_BSTR) )
			 << mol::property( _T("selection"), mol::DispId(this,ShellListCtrl_Dispatch_Selection,VT_BSTR) )
			 << mol::property( _T("cs"), &sizel );

	return S_OK;
}