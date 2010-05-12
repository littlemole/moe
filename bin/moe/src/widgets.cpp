#include "stdafx.h"
#include "widgets.h"
#include "app.h"
#include "xmlui.h"
#include "MoeBar.h"


using namespace mol::io;
 
std::string engineFromPath(const std::string& path)
{
	mol::string engine = mol::engineFromExtension(mol::Path::ext(mol::toString(path)));
	if ( engine == _T("") )
	{
		if ( mol::Path::ext(mol::toString(path)) == _T(".cs") )
			engine = _T("cs");
		else
			engine = _T("");
	}
	return mol::tostring(engine);
}


/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////



void MoeStatusBar::status(int i)
{
	progress()->show(SW_SHOW);
	progress()->setPos(i);
}

void MoeStatusBar::status( const mol::string& txt )
{
	progress()->show(SW_HIDE);
	setText(txt);
}

/////////////////////////////////////////////////////////////////////////////////////////////

void Script::eval(  const mol::string& engine, const mol::string& script )
{
	ODBGS("Script::eval()\r\n");
	this->AddRef();
	init(engine);
	addNamedObject((IXmoe*)(moe()),_T("moe"));
	runScript(script);
	//close();
	this->Release();
}

void Script::debug(  const mol::string& engine, const mol::string& script )
{
	ODBGS("Script::eval()\r\n");
	this->AddRef();
	init(engine);
	addNamedObject((IXmoe*)(moe()),_T("moe"));
	debugScript(script);
	//close();
	this->Release();
}
void Script::call(  const mol::string& engine, const mol::string& func, const mol::string& script )
{
	this->AddRef();
	init(engine);
	addNamedObject((IXmoe*)moe(),_T("moe"));
	runScript(script);
	ScriptHost::call(func);
	close();
	this->Release();
}




/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

UrlBox::UrlBox()
{

}

UrlBox::~UrlBox()
{

}

void UrlBox::go( const std::string location )
{
	for ( std::list<std::string>::iterator it = history_.begin(); it != history_.end(); it ++ )
	{
		if ( (*it) == location )
		{
			history_.erase(it);
			break;
		}
	}

    history_.push_front(location);
	if ( history_.size() > 32 )
		history_.pop_back();

	updateGUI();
}


void UrlBox::updateGUI()
{
    clear();
    int s = (int)history_.size();
    if ( s == 0 )
	{
		setText( _T("http://") );
        return;    
	}

	std::list<std::string>::iterator it = history_.begin();
	setText( mol::toString((*it)) );
    editBox().setSelection( (int)(*it).size(), (int)(*it).size() );

    for ( int i = 0; i < s; i++ )
    {
		addString( mol::toString((*it)) );
        it++;
    }
}


HRESULT __stdcall UrlBox::Load( LPSTREAM pStm)
{
	DWORD c = 0;
	ULONG len;

	history_.clear();

	HRESULT hr = pStm->Read( (void*)&c, sizeof(DWORD), &len );
	if ( hr != S_OK )
		return hr;

	for ( DWORD i = 0; i < c; i++ )
	{
		DWORD s = 0;

		HRESULT hr = pStm->Read( (void*)&s, sizeof(DWORD), &len );
		if ( hr != S_OK )
			return hr;

		char* sz = new char[s];

		hr = pStm->Read( (void*)sz, s, &len );
		if ( hr != S_OK )
			return hr;

		history_.push_back( std::string( sz, len ) );

		delete[] sz;
	}
	return S_OK;
}

HRESULT __stdcall UrlBox::Save( LPSTREAM pStm,BOOL fClearDirty)
{
	DWORD c = (DWORD)history_.size();
	ULONG len;
	HRESULT hr = pStm->Write( (void*)&c, sizeof(DWORD), &len );
	if ( hr != S_OK )
		return hr;

	for ( std::list<std::string>::iterator it = history_.begin(); it != history_.end(); it++ )
	{
		DWORD s = (DWORD)(*it).size();

		HRESULT hr = pStm->Write( (void*)&s, sizeof(DWORD), &len );
		if ( hr != S_OK )
			return hr;

		hr = pStm->Write( (void*)(*it).c_str(), s, &len );
		if ( hr != S_OK )
			return hr;
	}
	return S_OK;
}

HRESULT __stdcall UrlBox::GetSizeMax( ULARGE_INTEGER *pCbSize)
{
	unsigned long long uli = (*pCbSize).QuadPart;

	unsigned long long s = sizeof(DWORD) * ( history_.size() + 1 );
	uli += s;

	for ( std::list<std::string>::iterator it = history_.begin(); it != history_.end(); it++ )
	{
		s = (unsigned long long)((*it).size());
		uli += s;
	}
	(*pCbSize).QuadPart = uli;
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////
//
//
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////


InfoDlg::InfoDlg(  )
{
	icon_.load(IDI_MOE,64,64);
}

//////////////////////////////////////////////////////////////////////////////

LRESULT InfoDlg::wndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
    {
		case WM_INITDIALOG:
		{
			setDlgButtonIcon(IDOK,icon_);
			return FALSE; // note: false! look into PSDK!
		}
        case WM_COMMAND:
		{
			if (LOWORD(wParam) == IDOK )
			{
                endDlg(LOWORD(wParam));
				return FALSE;
			}
			if (LOWORD(wParam) == IDCANCEL )
			{
                endDlg(LOWORD(wParam));
				return FALSE;
			}
		}
    }
	return mol::win::Dialog::wndProc(hDlg, message, wParam, lParam);
}

/////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
//
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////


UrlDlg::UrlDlg(  )
{
}

//////////////////////////////////////////////////////////////////////////////

LRESULT UrlDlg::wndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	static mol::Menu menu( mol::bookmarks().getMenu() ); 
	static HANDLE imgFavs = ::LoadImage( mol::hinstance(), MAKEINTRESOURCE(IDB_MOE_FAV),IMAGE_BITMAP,0,0,LR_LOADTRANSPARENT| LR_LOADMAP3DCOLORS ) ;
	static HANDLE imgGo   = ::LoadImage( mol::hinstance(), MAKEINTRESOURCE(IDB_MOE_GO),IMAGE_BITMAP,0,0,LR_LOADTRANSPARENT| LR_LOADMAP3DCOLORS ) ;
	switch (message)
    {
		case WM_INITDIALOG:
		{
			sendDlgItemMsg( IDC_BUTTON_BOOKMARK, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP,  (LPARAM)(imgFavs) );
			sendDlgItemMsg( IDOK, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP,  (LPARAM)(imgGo) );			
			urlBox_.subClass( getDlgItem(IDC_EDIT_URL) );
			urlBox_.updateGUI();
			
			return FALSE; // note: false! look into PSDK!
		}
        case WM_COMMAND:
		{
			if (LOWORD(wParam) == IDC_BUTTON_BOOKMARK )
			{				
				RECT r;
				::GetWindowRect(getDlgItem(IDC_BUTTON_BOOKMARK),&r);
				int id = menu.returnTrackPopup( getDlgItem(IDC_BUTTON_BOOKMARK),r.left+15,r.top+15);
				
				mol::Bookmark& bm = mol::bookmarks().getBookmarkFromMenuId(id);
				if ( !bm.url.empty() )
				{
					urlBox_.setText(bm.url);
				}
				return FALSE;
			}
			if (LOWORD(wParam) == IDOK )
			{
				int sel = urlBox_.getCurSel();
				// check wether user select from last-urls-list or enter a new one
				if ( sel == CB_ERR ) //no selection
				{
					// user typed new url into edit-field of combobox
					url = urlBox_.getText();
				}
				else
				{
					//user has chosen the url from the combobox-dropdownlist
					url = urlBox_.getString(sel);
				}
				if (url.size()>0)
				{
					urlBox_.go( mol::tostring(url));
				}
                endDlg(LOWORD(wParam));
				return FALSE;
			}
			if (LOWORD(wParam) == IDCANCEL )
			{
                endDlg(LOWORD(wParam));
				return FALSE;
			}
		}
    }
	return mol::win::Dialog::wndProc(hDlg, message, wParam, lParam);
}

HRESULT __stdcall UrlDlg::Load( LPSTREAM pStm)
{
	return urlBox_.Load(pStm);
}

HRESULT __stdcall UrlDlg::Save( LPSTREAM pStm,BOOL fClearDirty)
{
	return urlBox_.Save(pStm,fClearDirty);
}

HRESULT __stdcall UrlDlg::GetSizeMax( ULARGE_INTEGER *pCbSize)
{
	return urlBox_.GetSizeMax(pCbSize);
}
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

TabDlg::TabDlg(  )
{
}

//////////////////////////////////////////////////////////////////////////////

LRESULT TabDlg::wndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
    {
		case WM_INITDIALOG:
		{
			setDlgItemInt(IDC_EDIT_TAB,width);
			if ( usetabs )
				sendDlgItemMsg(IDC_CHECK_USETABS,BM_SETCHECK,BST_CHECKED,0);
			if ( tabindents )
				sendDlgItemMsg(IDC_CHECK_TABINDENTS,BM_SETCHECK,BST_CHECKED,0);
			if ( backspaceunindents  )
				sendDlgItemMsg(IDC_CHECK_BACKSPACEUNINDENTS,BM_SETCHECK,BST_CHECKED,0);

			return FALSE; // note: false! look into PSDK!
		}
        case WM_COMMAND:
		{
			if (LOWORD(wParam) == IDOK )
			{
                getDlgItemInt(IDC_EDIT_TAB,width);
				if ( BST_CHECKED == sendDlgItemMsg(IDC_CHECK_USETABS,BM_GETCHECK,0,0) )
					usetabs = true;
				else
					usetabs = false;

				if ( BST_CHECKED == sendDlgItemMsg(IDC_CHECK_TABINDENTS,BM_GETCHECK,0,0) )
					tabindents = true;
				else
					tabindents = false;

				if ( BST_CHECKED == sendDlgItemMsg(IDC_CHECK_BACKSPACEUNINDENTS,BM_GETCHECK,0,0) )
					backspaceunindents = true;
				else
					backspaceunindents = false;

				endDlg(LOWORD(wParam));
				return FALSE;
			}
			if (LOWORD(wParam) == IDCANCEL )
			{
				endDlg(LOWORD(wParam));
				return FALSE;
			}
		}
    }
	return mol::win::Dialog::wndProc(hDlg, message, wParam, lParam);
}

mol::string findFile(const mol::string& f)
{
	if ( mol::Path::exists(f) )
		return f;

	mol::string modulePath = mol::Path::pathname(binPath());
	mol::string configPath = mol::Path::pathname(prefPath());

	//modulePath = mol::Path::addBackSlash(modulePath);
	//configPath = mol::Path::addBackSlash(configPath);


	configPath.append(f);
	if ( mol::Path::exists(configPath) )
		return configPath;

	modulePath.append(f);
	if ( mol::Path::exists(modulePath) )
		return modulePath;

	return _T("");
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////
//
// Drag & Drop_ Support 
//
//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall MoeDrop::Drop( IDataObject* pDataObject, DWORD keyState, POINTL pt , DWORD* pEffect)
{
	std::vector<mol::string> v;
    v = vectorFromDataObject(pDataObject);
	ImageList::drop(*moe());
	for ( unsigned int i = 0; i < v.size(); i++ )
	{
		bool result = ::docs()->open(0,v[i],Docs::PREF_TXT,false,0);
		statusBar()->status(v[i]);
		if (!result)
		{
			::MessageBox(*moe(),v[i].c_str(),_T("failed to load"),MB_ICONERROR);
			return S_FALSE;
		}
	}
	*pEffect = DROPEFFECT_NONE;
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////
// Com EVENT interface sink implementations
//////////////////////////////////////////////////////////////////////////////


HRESULT  __stdcall MoeDrop::DragEnter( IDataObject* , DWORD , POINTL , DWORD* pEffect )
{
	ImageList::enterDrag(*moe());
    return S_OK;
}

HRESULT __stdcall MoeDrop::DragOver( DWORD, POINTL, DWORD* pEffect )
{
	ImageList::doDrag(*moe());
	*pEffect &= DROPEFFECT_COPY;
    return S_OK;
}


HRESULT  __stdcall MoeDrop::DragLeave()
{
	ImageList::leaveDrag(*moe());
    return S_OK;
}

//////////////////////////////////////////////////////////////////////////////
// .NET compiler event sink
//////////////////////////////////////////////////////////////////////////////


HRESULT __stdcall CompilerSink::ErrorMsg(BSTR error)
{
	::MessageBox( *(moe()),bstr(error).toString().c_str(),_T("error:"),0);
	statusBar()->status(_T(".NET compiler error"));
	return S_OK;
}


HRESULT __stdcall CompilerSink::Success()
{
	statusBar()->status( _T(".NET compilation success"));
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////
// tree events sink
//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall TreeWndSink::OnTreeSelection(BSTR filename)
{
	return moe()->IOleInPlaceFrame_SetStatusText(filename);
}

HRESULT __stdcall TreeWndSink::OnTreeDblClick(BSTR filename)
{
	mol::string p(mol::toString(filename));
	if ( !mol::Path::exists(p) || mol::Path::isDir(p) )
		return S_OK;
	punk<IShellTree> tree(treeWnd()->oleObject);
	if ( tree )
	{
		bool result = ::docs()->open(0,mol::toString(filename),Docs::PREF_TXT,false,0);
		statusBar()->status(mol::toString(filename));
		if (!result)
		{
			statusBar()->status( mol::string(_T("failed to load ")) + mol::toString(filename));
			return S_FALSE;
		}
	}
	return S_OK;
}

HRESULT __stdcall TreeWndSink::OnTreeOpen(BSTR filename)
{
	punk<IShellTree> tree(treeWnd()->oleObject);
	if ( tree )
	{
		mol::string fn = mol::toString((wchar_t*)filename);
		if ( mol::Path::isDir( fn) )
		{
			statusBar()->status(fn);
			bool result = ::docs()->open(0,fn,Docs::PREF_TXT,false,0);

			if (!result)
			{
				statusBar()->status( mol::string(_T("failed to load ")) + fn);
				return S_OK;
			}
			return S_OK;
		}
		mol::FilenameDlg dlg(*moe());
		dlg.setFilter( InFilesFilter );	
		dlg.fileName(fn);
		if ( !dlg.dlgOpen(OFN_ALLOWMULTISELECT | OFN_EXPLORER) )
			return S_OK;

		int s = dlg.selections();
		int p = dlg.index();
		for ( int i = 0; i < s; i++ )
		{
			mol::string f = dlg.fileName(i);
			statusBar()->status(f);


			bool result = ::docs()->open(0,f,(Docs::InFiles)(p-1 >=0 ? p-1 :0),false,0);

			if (!result)
			{
				statusBar()->status( mol::string(_T("failed to load ")) + f);
				return S_OK;
			}
		}
	}
	return S_OK;
}
