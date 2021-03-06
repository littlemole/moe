#include "win/folder.h"

namespace mol {
namespace io {

FolderDlg::FolderDlg(HWND p)
: parent_(p)
{}

FolderDlg::~FolderDlg(void)
{}

bool FolderDlg::browse(const wchar_t* path, const wchar_t* title, int flags )
{
    BROWSEINFO		bi;
    LPITEMIDLIST	pidl;
	wchar_t		buf[MAX_PATH];

    // set browseinfo
    ::ZeroMemory( &bi, sizeof(bi) );
    bi.hwndOwner		= parent_;
    bi.lpszTitle		= title;
    bi.pidlRoot			= 0;
    bi.pszDisplayName	= buf;
    bi.ulFlags			= flags;

    //browse
    pidl = ::SHBrowseForFolder( &bi );
    if ( !pidl )
            return false;

    // set display name
    ispath_ = false;
    path_   = buf;

    // see if its a "hard" (local) folder in the filesystem
    if ( SHGetPathFromIDList(pidl, buf ) )
    {
            // yes -so return that
            path_   = buf;
            ispath_ = true;
    }

    // clean up - give back to the shell what is from the shell :-o
    IMalloc * imalloc = 0;
    if ( SUCCEEDED( SHGetMalloc ( &imalloc )) )
    {
        imalloc->Free ( pidl );
        imalloc->Release ( );
    }
    return true;
}

// accessors

const std::wstring& FolderDlg::getPath()
{
    return path_;
}

bool FolderDlg::isPath()
{
    return ispath_;
}


////////////////////////////////////////////////////////////////////////////////////

FolderBrowser::FolderBrowser()
{
	title_ = _T("FolderBrowser");
	text_  = _T("Browse for folder");
}

FolderBrowser::FolderBrowser(const std::wstring& text)
	:text_(text)
{
	title_ = _T("FolderBrowser");
}

FolderBrowser::FolderBrowser(const std::wstring& text, const std::wstring& title)
	: text_(text),title_(title)
{
	title_ = _T("FolderBrowser");
	text_  = _T("Browse for folder");
}

std::wstring FolderBrowser::select( HWND owner, UINT flags, mol::io::Shit& shit)
{
	mol::io::Shit si = dlg( owner, flags, shit );
	if ( si )
		return desktop().getDisplayNameOf(*si);
	return _T("");
}

mol::io::Shit FolderBrowser::dlg( HWND owner, UINT flags, mol::io::Shit& shit)
{
	::ZeroMemory(&bInfo_,sizeof(bInfo_));
	bInfo_.hwndOwner = owner;
	bInfo_.lpszTitle = text_.c_str();
	bInfo_.ulFlags   = flags;
	bInfo_.pidlRoot  = *shit;
	bInfo_.lpfn      = FolderBrowser::BrowseCallbackProc;
	bInfo_.lParam    = (LPARAM)this;

	LPITEMIDLIST pidl = ::SHBrowseForFolder(&bInfo_);
	if ( pidl )
		return mol::io::Shit(new ShellItem(pidl, desktop().getAttributesOf(pidl)));
	return mol::io::Shit();
}

int FolderBrowser::OnInit( HWND hwnd)
{
	::SendMessage(hwnd, WM_SETTEXT, 0, (LPARAM)(title_.c_str()) );
	return 0;
}

int FolderBrowser::OnIUnknown( HWND hwnd, IUnknown* punk)
{
	return 0;
}

int FolderBrowser::OnSelect( HWND hwnd, LPITEMIDLIST pidl)
{
	std::wstring p   = desktop().getDisplayNameOf(pidl);
	std::wstring ws = mol::towstring(p);
	::SendMessage(hwnd, BFFM_SETSTATUSTEXT, 0, (LPARAM)(p.c_str()) );
	return 0;
}

int FolderBrowser::OnValidateFailed( HWND hwnd, const wchar_t* path)
{
	return 1;
}

int FolderBrowser::browseProc( HWND hwnd, UINT uMsg, LPARAM lParam)
{
	switch( uMsg )
	{
		case BFFM_INITIALIZED	 : return OnInit( hwnd );
		case BFFM_IUNKNOWN		 : return OnIUnknown( hwnd, (IUnknown*)lParam );
		case BFFM_SELCHANGED	 : return OnSelect( hwnd, (LPITEMIDLIST)lParam );
		case BFFM_VALIDATEFAILED : return OnValidateFailed( hwnd, (const wchar_t*)lParam );
		default:
			return 0;
	}
}

int CALLBACK FolderBrowser::BrowseCallbackProc( HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData)
{
	FolderBrowser* fb = (FolderBrowser*)lpData;
	if ( fb )
		return fb->browseProc(hwnd, uMsg, lParam);
	return 0;
}


extern HRESULT SimpleFolderBrowser(HWND hwnd, std::wstring& directory);

std::wstring browseForFolder( HWND owner )
{
	std::wstring retval;

	HRESULT hr = SimpleFolderBrowser( owner, retval );
	if ( hr == S_OK )
		return retval;

	if ( hr == HRESULT_FROM_WIN32(ERROR_CANCELLED) )
		return retval;

	FolderBrowser fb( _T("browse filesystem to select folder"), _T("Browse for Folder"));
	retval = fb.select(owner,BIF_USENEWUI|BIF_STATUSTEXT|BIF_BROWSEINCLUDEURLS); //BIF_SHAREABLE probs on vista :O

	return retval;
}


} // end namespace mol::win::io;
} // end namespace mol;