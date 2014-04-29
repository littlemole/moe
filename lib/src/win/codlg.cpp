#include "win/CoDlg.h"
#include "win/path.h"
#include "win/app.h"
#include "win/msgloop.h"

namespace mol  {


wchar_t SearchDlg::bufWhat_[1024]  = _T("");
wchar_t SearchDlg::bufWhich_[1024] = _T("");

SearchDlg::SearchDlg()
{
    frp_.lpstrFindWhat	  =	bufWhat_;
	frp_.lpstrReplaceWith =	bufWhich_;
    frp_.Flags			  =	FR_DOWN;
    frp_.wFindWhatLen	  =	sizeof(bufWhat_);
	frp_.wReplaceWithLen  = sizeof(bufWhich_);
    frp_.lStructSize	  =	sizeof(FINDREPLACE);
    getSearchMsg();
}

LRESULT SearchDlg::wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    if ( message == WM_DESTROY )
		mol::win::dialogs().unregisterDialog(hwnd);

    return ::CallWindowProc( oldProc, hwnd, message, wParam, lParam );
}

int SearchDlg::getSearchMsg()
{
    static int msg = ::RegisterWindowMessage(FINDMSGSTRING);
    return msg;
}

HWND SearchDlg::findText(HWND parent, DWORD flags,const wchar_t* what )
{
    frp_.Flags			=	flags;;
    frp_.hwndOwner		=	parent;
    frp_.lStructSize	=	sizeof(frp_);

    if (what)
    {
		memcpy( bufWhat_,what,frp_.wFindWhatLen*sizeof(wchar_t));
    }
    hWnd_ = ::FindText(&frp_);
    subClass(hWnd_);
	mol::win::dialogs().registerDialog(hWnd_);
    return hWnd_;
}

HWND SearchDlg::replaceText( HWND parent, DWORD flags, const wchar_t* what , const wchar_t* which  )
{
    frp_.Flags			=	flags;;
    frp_.hwndOwner		=	parent;
    frp_.lStructSize	=	sizeof(frp_);

    if (what)
    {
			memcpy( bufWhat_,what,frp_.wFindWhatLen*sizeof(wchar_t));
    }
    if (which)
    {
		memcpy( bufWhich_,which,frp_.wReplaceWithLen*sizeof(wchar_t));
    }
	hWnd_ = ::ReplaceText(&frp_);
    subClass(hWnd_);
	mol::win::dialogs().registerDialog(hWnd_);
    return hWnd_;
}

////////////////////////////////////////////////

const wchar_t filter[] = _T("All Files (*.*)\0*.*\0\0");

FilenameDlg::FilenameDlg( HWND parent)
{
    ::ZeroMemory(&of_,sizeof(of_));
    of_.lStructSize = sizeof(OPENFILENAME);
    of_.hwndOwner   = parent;
    of_.lpstrFilter = filter;
	dlg_ = 0;
}

void FilenameDlg::setFilter(const wchar_t* filter )
{
    of_.lpstrFilter = filter;
}
const std::wstring FilenameDlg::fileName(int i)
{
	if ( of_.Flags & OFN_ALLOWMULTISELECT )
	{
		return filenames_[i];
	}
    return filename_;
}

void FilenameDlg::fileName(const std::wstring& s)
{
	filename_ = s;
}

const std::wstring FilenameDlg::ext(int i)
{
	if ( of_.Flags & OFN_ALLOWMULTISELECT )
	{
		return mol::Path::ext(filenames_[i]);
	}
    return extension_;
}

const std::wstring FilenameDlg::title(int i)
{
	if ( of_.Flags & OFN_ALLOWMULTISELECT )
	{
		return mol::Path::filename(filenames_[i]);
	}
    return filetitle_;
}

int FilenameDlg::index()
{
    return of_.nFilterIndex;
}

void FilenameDlg::index(int i)
{
    of_.nFilterIndex = i;
}

int FilenameDlg::selections()
{
	if ( of_.Flags & OFN_ALLOWMULTISELECT )
	{
		return (int)filenames_.size();
	}
	return 1;
}

bool FilenameDlg::readOnly()
{
	return (of_.Flags & OFN_READONLY) != 0;
}

BOOL FilenameDlg::dlgOpen( int flags)
{
	wchar_t buf[1024];
    wchar_t buf2[1024];
    buf[0]  = 0;
    buf2[0] = 0;

	this->OnCustomize();

    of_.lpstrFile      = buf;
    of_.lpstrFileTitle = buf2;
    of_.nMaxFile	   = 1024;
    of_.nMaxFileTitle  = 1024;
    of_.Flags		   = flags;
	of_.lCustData      = (LPARAM)this;

	if ( filename_.size() > 0 )
		::memcpy( buf, filename_.c_str(), (filename_.size()+1)*sizeof(wchar_t) );

    BOOL ret = ::GetOpenFileName(&of_);

	if (!ret )
		return ret;

	if ( flags & OFN_ALLOWMULTISELECT )
	{
		std::wstring p = std::wstring( of_.lpstrFile, of_.nFileOffset-1 );
		wchar_t* c = of_.lpstrFile + of_.nFileOffset;
		wchar_t* b = c;
		if ( *(c-1) != 0 )
		{
			filenames_.push_back( p + _T("\\") + std::wstring(buf + of_.nFileOffset) );
		}
		else
		while ( !( (*c == 0) && (*(c-1) == 0) ) && (int)c <= (int)of_.lpstrFile + (int)(of_.nMaxFile*sizeof(wchar_t)) )
		{
			if ( *c == 0 )
			{
				std::wstring s(p);
				s.append(_T("\\"));
				if ( c-b > 0 && *b)
				{
					std::wstring f(b,int(c-b));
					s.append(f);
					filenames_.push_back( s );
				}
				b = c+1;
			}
			c++;
		}
		return ret;
	}

	filename_  = buf;
	filetitle_ = buf2;
	if ( of_.nFileExtension != 0 )
		extension_ = (wchar_t*)(of_.lpstrFile+of_.nFileExtension);
	else
		extension_ = _T("");

	return ret;
}

BOOL FilenameDlg::dlgSave( int flags)
{
    wchar_t buf[1024];
    wchar_t buf2[1024];
    buf[0]  = 0;
    buf2[0] = 0;

	this->OnCustomize();


    of_.lpstrFile       = buf;
    of_.lpstrFileTitle  = buf2;
    of_.nMaxFile	    = 1024;
    of_.nMaxFileTitle   = 1024;
    of_.Flags		    = flags;
	of_.lCustData       = (LPARAM)this;

	if ( filename_.size() > 0 )
		::memcpy( buf, filename_.c_str(), (filename_.size()+1)*sizeof(wchar_t) );

    BOOL ret =::GetSaveFileName(&of_);

    if ( of_.nFileExtension != 0 )
		extension_ = std::wstring( (wchar_t*)(of_.lpstrFile + of_.nFileExtension) );
    else
        extension_ = _T("");

    filename_  = buf;
    filetitle_ = buf2;

    return ret;
}

LRESULT FilenameDlg::OnMsg(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	dlg_ = hDlg;
	mol::Crack message(msg,wParam,lParam);
	switch(msg)
	{
		case WM_NOTIFY :
		{
			if ( message.nmhdr()->code == CDN_INITDONE )
			{
				this->OnInit();
				break;
			}
		}
		case WM_DESTROY :
		{
				this->OnDestroy();
				break;
		}
	}
	return 0;
}

UINT_PTR __stdcall FilenameDlg::hook(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (msg == WM_NOTIFY && lParam )
	{
		OFNOTIFY* ofn = (OFNOTIFY*)lParam;
		if ( ofn->lpOFN && ofn->lpOFN->lCustData )
		{
			return ((FilenameDlg*)(ofn->lpOFN->lCustData))->OnMsg(hDlg,msg,wParam,lParam);
		}
	}
	return 0;
}



} // end namespace mol
