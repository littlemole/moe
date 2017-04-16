//#include "StdAfx.h"
#include "ole/ShellFolderWnd.h"
#include "win/shell.h"
#include "ole/dataobj.h"

namespace mol  {
namespace ole  {

ShellFolderWnd::ShellFolderWnd(void)
{
}

ShellFolderWnd::~ShellFolderWnd(void)
{
}

void ShellFolderWnd::dispose()
{
	if ( sv_ )
	{
		if ( layout_)
			layout_->remove(viewWnd_);

		HRESULT hr = sv_->DestroyViewWindow();
		sv_.release();
	}
	
}

LRESULT ShellFolderWnd::wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if ( message == WM_CREATE )
	{
		//path(_T("F:\\"));


	}
	if ( message == WM_DESTROY )
	{
		dispose();
	}
	if ( message == WM_SIZE )
	{
		mol::Rect clientRect_ = mol::Rect(0,0,0,0);

		// get new width and height
		clientRect_.right  = LOWORD (lParam) ;
		clientRect_.bottom = HIWORD (lParam) ;

		//::MoveWindow( viewWnd_,clientRect_.left, clientRect_.top, clientRect_.right, clientRect_.bottom, TRUE);	
		::SetWindowPos( viewWnd_, NULL, 0,0, clientRect_.right, clientRect_.bottom,SWP_NOZORDER|SWP_DRAWFRAME|SWP_FRAMECHANGED|SWP_NOACTIVATE|SWP_NOOWNERZORDER|SWP_NOMOVE|SWP_NOCOPYBITS);
		::RedrawWindow( viewWnd_,NULL,NULL,RDW_FRAME|RDW_INVALIDATE|RDW_UPDATENOW|RDW_ALLCHILDREN|RDW_INTERNALPAINT);
	}
	return mol::Window::wndProc(hwnd,message,wParam,lParam);
}

std::vector<std::wstring> ShellFolderWnd::selected()
{
	mol::punk<IDataObject> dao;
	HRESULT hr = sv_->GetItemObject(SVGIO_SELECTION,IID_IDataObject ,(void**)&dao);
	if(hr == S_OK )
	{
		return mol::vectorFromDataObject(dao);
	}
	return std::vector<std::wstring>();
}

bool ShellFolderWnd::displayFiles()					
{ 
	return displayFiles_; 
}

void ShellFolderWnd::displayFiles(bool b)			
{ 
	displayFiles_ = b; 
}

void ShellFolderWnd::path( const std::wstring& p)	
{ 
	path_ = p; 
	showPath(p);
}

std::wstring ShellFolderWnd::path()		
{ 
	return path_; 
};

bool ShellFolderWnd::hasFocus()						
{ 
	return ::GetFocus() == viewWnd_; 
}

void ShellFolderWnd::refresh() 
{
	if ( !sv_)
		return;

	sv_->Refresh();
}

void ShellFolderWnd::cut()
{
	if ( !sv_)
		return;

	HRESULT hr;

	mol::punk<IDataObject> dao;
	hr = sv_->GetItemObject(SVGIO_SELECTION,IID_IDataObject ,(void**)&dao);
	if(hr == S_OK )
	{
		std::vector<std::wstring> v = mol::vectorFromDataObject(dao);
		if ( !v.empty() )
		{
			mol::punk<IDataObject> ido = new mol::ShellDataObj(v,true);
			hr = ::OleSetClipboard(ido);					

			if ( hr == S_OK )
			{
				mol::punk<IShellFolderView> sfw(sv_);
				
				if ( sfw)
				{
					hr = sfw->SetClipboard(TRUE);
				}

			}
		}
	}
}



void ShellFolderWnd::copy()
{
	if ( !sv_)
		return;

	mol::punk<IDataObject> dao;
	HRESULT hr = sv_->GetItemObject(SVGIO_SELECTION,IID_IDataObject ,(void**)&dao);
	if(hr == S_OK )
	{
		std::vector<std::wstring> v = mol::vectorFromDataObject(dao);
		if ( !v.empty() )
		{
			mol::punk<IDataObject> ido = new mol::ShellDataObj(v,false);
			HRESULT r = ::OleSetClipboard(ido);					
		}
	}
}




void ShellFolderWnd::paste()
{
	if ( !sv_)
		return;

	mol::punk<IDataObject> dao;
	HRESULT hr = sv_->GetItemObject(SVGIO_SELECTION,IID_IDataObject ,(void**)&dao);
	std::vector<std::wstring> v;
	if(hr == S_OK )
	{
		v = mol::vectorFromDataObject(dao);
	}

	std::wstring path;
	if ( v.size() == 1 )
		path = v[0];
	else
		path = path_;

	mol::format_etc_pref_dropeffect	fe;
	STGMEDIUM					sm;

	mol::punk<IDataObject> ido;
	::OleGetClipboard(&ido);
	if (!ido)
		return ;

	v.clear();
	v = mol::vectorFromDataObject(ido);

	if ( v.size() < 1 )
		return ;

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
		mol::io::ShellFileOp sfo;
		sfo.copy(*this,v,path,FOF_ALLOWUNDO);
	}
	else if (*d & DROPEFFECT_MOVE )
	{
		mol::io::ShellFileOp sfo;
		sfo.move(*this,v,path,FOF_ALLOWUNDO);
	}
	mol::format_etc_dropeffect fede;
	mol::StgMedium stgm(*d, GHND|GMEM_SHARE);
	ido->SetData(&fede,&stgm,TRUE);
	
}

void ShellFolderWnd::rename()
{
	if ( !sv_)
		return;

	mol::punk<IDataObject> dao;
	HRESULT hr = sv_->GetItemObject(SVGIO_SELECTION,IID_IDataObject ,(void**)&dao);
	if(hr == S_OK )
	{
		std::vector<std::wstring> v = mol::vectorFromDataObject(dao);
		if ( !v.empty())
		{
			mol::io::Shit it;
			mol::io::ShellFolder& sf =  mol::io::desktop();
			it = sf.parseDisplayName(v[0]);
			if ( !it )
				return;
			HRESULT hr = sv_->SelectItem(*it,SVSI_EDIT);
		}
	}
}


void ShellFolderWnd::erase()
{
	if ( !sv_)
		return;

	mol::punk<IDataObject> dao;
	HRESULT hr = sv_->GetItemObject(SVGIO_SELECTION,IID_IDataObject ,(void**)&dao);
	if(hr == S_OK )
	{
		std::vector<std::wstring> v = mol::vectorFromDataObject(dao);
		if ( !v.empty())
		{
			mol::io::ShellFileOp sfo;
			sfo.remove(*this,v,FOF_ALLOWUNDO);
		}
	}
}

void ShellFolderWnd::execute()
{
	if ( !sv_)
		return;

	mol::punk<IDataObject> dao;
	HRESULT hr = sv_->GetItemObject(SVGIO_SELECTION,IID_IDataObject ,(void**)&dao);
	if(hr == S_OK )
	{
		std::vector<std::wstring> v = mol::vectorFromDataObject(dao);
		if ( !v.empty())
		{
			mol::io::execute_shell( v[0] );		
		}
	}
}

void ShellFolderWnd::properties()
{
	if ( !sv_)
		return;

	mol::punk<IDataObject> dao;
	HRESULT hr = sv_->GetItemObject(SVGIO_SELECTION,IID_IDataObject ,(void**)&dao);
	if(hr == S_OK )
	{
		std::vector<std::wstring> v = mol::vectorFromDataObject(dao);
		if ( !v.empty() )
		{
			mol::io::execute_shell( v[0], _T("properties"),1,SEE_MASK_INVOKEIDLIST );		
		}
	}
}


void ShellFolderWnd::newdir()
{
	if ( !sv_)
		return;

	mol::punk<IDataObject> dao;
	HRESULT hr = sv_->GetItemObject(SVGIO_SELECTION,IID_IDataObject ,(void**)&dao);
	if(hr == S_OK )
	{
		std::vector<std::wstring> v = mol::vectorFromDataObject(dao);
		if ( !v.empty())
		{
			std::wstring tmp = _T("newDir_");	
			int i = 0;
			while(true)
			{
				std::wstring p(path_);
				std::wstringstream oss;
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
				this->update();
				return;
			}	
		}
	}
}

void ShellFolderWnd::updir()
{
	std::wstring p(path_);
	std::wstring parent (mol::Path::parentDir(p));
	parent = mol::Path::addBackSlash(parent);
	if ( mol::Path::isDir(parent) )
	{
		path_ = parent;
		showPath(path_);
	}
}


HRESULT __stdcall ShellFolderWnd::GetWindow( HWND *phwnd)
{
	if ( ::IsWindow(*this) )
	{
		*phwnd = *this;
		return S_OK;
	}
	return E_FAIL;
}

HRESULT __stdcall ShellFolderWnd::ContextSensitiveHelp( BOOL fEnterMode)
{
	return S_OK;
}


HRESULT __stdcall ShellFolderWnd::InsertMenusSB(  HMENU hmenuShared, LPOLEMENUGROUPWIDTHS lpMenuWidths)
{
	
	
	return S_OK ;
}

HRESULT __stdcall ShellFolderWnd::SetMenuSB( HMENU hmenuShared, HOLEMENU holemenuRes, HWND hwndActiveObject)
{
	return S_OK;
}

HRESULT __stdcall ShellFolderWnd::RemoveMenusSB( HMENU hmenuShared)
{
	return S_OK;
}

HRESULT __stdcall ShellFolderWnd::SetStatusTextSB( LPCWSTR pszStatusText)
{
	return S_OK;
}

HRESULT __stdcall ShellFolderWnd::EnableModelessSB( BOOL fEnable)
{
	return S_OK;
}

HRESULT __stdcall ShellFolderWnd::TranslateAcceleratorSB( MSG *pmsg,WORD wID)
{
	return S_OK;
}

HRESULT __stdcall ShellFolderWnd::BrowseObject( PCUIDLIST_RELATIVE pidl,UINT wFlags)
{
	//std::wstring s =	mol::io::desktop().getDisplayNameOf((LPITEMIDLIST)pidl);

	return S_OK;
}

HRESULT __stdcall ShellFolderWnd::GetViewStateStream( DWORD grfMode,IStream **ppStrm)
{
	return E_NOTIMPL;
}

HRESULT __stdcall ShellFolderWnd::GetControlWindow( UINT id, HWND *phwnd)
{
	*phwnd = NULL;
	return S_OK;
}

HRESULT __stdcall ShellFolderWnd::SendControlMsg( UINT id, UINT uMsg,  WPARAM wParam, LPARAM lParam, LRESULT *pret)
{
	return E_NOTIMPL;
}

HRESULT __stdcall ShellFolderWnd::QueryActiveShellView( IShellView **ppshv)
{
	return E_NOTIMPL;
}

HRESULT __stdcall ShellFolderWnd::OnViewWindowActive( IShellView *pshv)
{
	return S_OK;
}

HRESULT __stdcall ShellFolderWnd::SetToolbarItems( LPTBBUTTONSB lpButtons, UINT nButtons, UINT uFlags)
{
	return E_NOTIMPL;
}

HRESULT  ShellFolderWnd::QueryService( REFGUID guidService, REFIID riid, void **ppv)
{
	if ( ::IsEqualIID( riid, IID_IShellBrowser ) )
	{
		mol::punk<IShellBrowser> sb(this);
		return sb->QueryInterface(riid, ppv);
	}
	if ( ::IsEqualIID( riid, IID_ICommDlgBrowser ) )
	{
		mol::punk<ICommDlgBrowser> db(this);
		return db->QueryInterface(riid, ppv);
	}
	if ( ::IsEqualIID( riid, IID_IContextMenuSite ) )
	{
		//ODBGS("ASKED FOR IID_IContextMenuSite");
	}
	
	return E_NOINTERFACE;
}


HRESULT __stdcall ShellFolderWnd::DoContextMenuPopup( IUnknown *punkContextMenu, UINT fFlags, POINT pt)
{

	return S_OK;
}

HRESULT __stdcall ShellFolderWnd::IncludeObject( IShellView *ppshv, LPCITEMIDLIST pidl )
{
	return S_OK;
}

HRESULT __stdcall ShellFolderWnd::OnDefaultCommand( IShellView *ppshv)
{
	mol::punk<IDataObject> dao;
	HRESULT hr = ppshv->GetItemObject(SVGIO_SELECTION,IID_IDataObject ,(void**)&dao);
	if(hr == S_OK )
	{
		std::vector<std::wstring> v = mol::vectorFromDataObject(dao);
		for ( size_t i = 0; i < v.size(); i++)
		{
			//ODBGS(v[i].c_str());
		}
		if ( !v.empty() )
		{
			if ( mol::Path::isDir(v[0]) )
			{
				path_ = v[0];
				this->showPath(path_);
				this->OnPathChanged( path_ );
			}
			else
			{
				this->OnUserSelect( v );
			}
		}
		else 
		{
		}
	}

	return S_OK;
}



HRESULT __stdcall ShellFolderWnd::OnStateChange(IShellView *ppshv, ULONG uChange)
{
	return S_OK;
}


HRESULT __stdcall ShellFolderWnd::GetDefaultMenuText( IShellView *pshv, WCHAR *pszText, int cchMax)
{
	std::wstring s(L"open with moe");
	wcscpy(pszText,s.c_str());
	return S_OK;
}

HRESULT __stdcall ShellFolderWnd::GetViewFlags( DWORD *pdwFlags )
{
	*pdwFlags =0;
	return S_OK;
}

HRESULT __stdcall ShellFolderWnd::Notify( IShellView *pshv, DWORD dwNotifyType)
{
	return S_OK;
}

bool ShellFolderWnd::showPath( const std::wstring& path)
{
	mol::io::Shit it;
	mol::io::ShellFolder& sf =  mol::io::desktop();

	it = sf.parseDisplayName(path);
	if ( !it )
		return false;

	mol::io::ShellFolder f(*it);
	if ( !f )
		return false;

	HRESULT hr = E_FAIL;
	if ( sv_ )
	{
		hr = sv_->DestroyViewWindow();
		sv_.release();
	}

	SFV_CREATE sc;
	::ZeroMemory(&sc,sizeof(sc));
	sc.cbSize   = sizeof(sc);
	sc.psfvcb   = NULL;
	sc.pshf     = f.folder;
	sc.psvOuter = NULL;

	hr = f.folder->CreateViewObject(*this,IID_IShellView,(void**)&sv_);
	if ( hr != S_OK )
		return false;

	FOLDERSETTINGS fs;
	::ZeroMemory(&fs,sizeof(fs));
	fs.fFlags   = 0;
	fs.ViewMode = FVM_DETAILS ;

	mol::punk<IShellBrowser> sb(this);
	if ( !sb )
		return false;

	RECT r ;
	getClientRect(r);
	hr = sv_->CreateViewWindow( 0, &fs, sb, &r, &viewWnd_ );
	if ( hr != S_OK )
		return false;

	hr = sv_->UIActivate(SVUIA_INPLACEACTIVATE);
	if ( hr != S_OK )
		return false;

	return true;
}

} // end namespace ole  
} // end namespace mol 