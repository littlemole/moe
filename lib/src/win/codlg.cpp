#include "win/CoDlg.h"
#include "win/path.h"
#include "win/app.h"
#include "win/msgloop.h"

namespace mol  {


mol::TCHAR SearchDlg::bufWhat_[1024]  = _T("");
mol::TCHAR SearchDlg::bufWhich_[1024] = _T("");

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
		//mol::win::AppBase::app<mol::win::AppBase>().OnEndDlg(hWnd_);
		mol::win::dialogs().unregisterDialog(hwnd);

    return ::CallWindowProc( oldProc, hwnd, message, wParam, lParam );
}

int SearchDlg::getSearchMsg()
{
    static int msg = ::RegisterWindowMessage(FINDMSGSTRING);
    return msg;
}

HWND SearchDlg::findText(HWND parent, DWORD flags,const mol::TCHAR* what )
{
    frp_.Flags			=	flags;;
    frp_.hwndOwner		=	parent;
    frp_.lStructSize	=	sizeof(frp_);

    if (what)
    {
		memcpy( bufWhat_,what,frp_.wFindWhatLen*sizeof(mol::TCHAR));
    }
    hWnd_ = ::FindText(&frp_);
    subClass(hWnd_);
	//mol::App().OnCreateDlg(hWnd_);
	mol::win::dialogs().registerDialog(hWnd_);
    return hWnd_;
}

HWND SearchDlg::replaceText( HWND parent, DWORD flags, const mol::TCHAR* what , const mol::TCHAR* which  )
{
    frp_.Flags			=	flags;;
    frp_.hwndOwner		=	parent;
    frp_.lStructSize	=	sizeof(frp_);

    if (what)
    {
			memcpy( bufWhat_,what,frp_.wFindWhatLen*sizeof(mol::TCHAR));
    }
    if (which)
    {
		memcpy( bufWhich_,which,frp_.wReplaceWithLen*sizeof(mol::TCHAR));
    }
	hWnd_ = ::ReplaceText(&frp_);
    subClass(hWnd_);
	//mol::App().OnCreateDlg(hWnd_);
	mol::win::dialogs().registerDialog(hWnd_);
    return hWnd_;
}

////////////////////////////////////////////////

const TCHAR filter[] = _T("All Files (*.*)\0*.*\0\0");

FilenameDlg::FilenameDlg( HWND parent)
{
    ::ZeroMemory(&of_,sizeof(of_));
    of_.lStructSize = sizeof(OPENFILENAME);
    of_.hwndOwner   = parent;
    of_.lpstrFilter = filter;
}

void FilenameDlg::setFilter(const mol::TCHAR* filter )
{
    of_.lpstrFilter = filter;
}
const mol::string FilenameDlg::fileName(int i)
{
	if ( of_.Flags & OFN_ALLOWMULTISELECT )
	{
		return filenames_[i];
	}
    return filename_;
}

void FilenameDlg::fileName(const mol::string& s)
{
	filename_ = s;
}

const mol::string FilenameDlg::ext(int i)
{
	if ( of_.Flags & OFN_ALLOWMULTISELECT )
	{
		return mol::Path::ext(filenames_[i]);
	}
    return extension_;
}

const mol::string FilenameDlg::title(int i)
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
	mol::TCHAR buf[1024];
    mol::TCHAR buf2[1024];
    buf[0]  = 0;
    buf2[0] = 0;

    of_.lpstrFile      = buf;
    of_.lpstrFileTitle = buf2;
    of_.nMaxFile	   = 1024;
    of_.nMaxFileTitle  = 1024;
    of_.Flags		   = flags;

	if ( filename_.size() > 0 )
		::memcpy( buf, filename_.c_str(), (filename_.size()+1)*sizeof(mol::TCHAR) );

    BOOL ret = ::GetOpenFileName(&of_);

	if (!ret )
		return ret;

	if ( flags & OFN_ALLOWMULTISELECT )
	{
		mol::string p = mol::string( of_.lpstrFile, of_.nFileOffset-1 );
		mol::TCHAR* c = of_.lpstrFile + of_.nFileOffset;
		mol::TCHAR* b = c;
		if ( *(c-1) != 0 )
		{
			//::MessageBox(0,buf + of_.nFileOffset,0,0);
			filenames_.push_back( p + _T("\\") + mol::string(buf + of_.nFileOffset) );
		}
		else
		while ( !( (*c == 0) && (*(c-1) == 0) ) && (int)c <= (int)of_.lpstrFile + (int)(of_.nMaxFile*sizeof(mol::TCHAR)) )
		{
			if ( *c == 0 )
			{
				mol::string s(p);
				s.append(_T("\\"));
				if ( c-b > 0 && *b)
				{
					mol::string f(b,int(c-b));
					ODBGS("OPEN FILE DIALOG:");
					ODBGS(f.c_str());
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
		extension_ = (mol::TCHAR*)(of_.lpstrFile+of_.nFileExtension);
	else
		extension_ = _T("");

	return ret;
}

BOOL FilenameDlg::dlgSave( int flags)
{
    mol::TCHAR buf[1024];
    mol::TCHAR buf2[1024];
    buf[0]  = 0;
    buf2[0] = 0;

    of_.lpstrFile       = buf;
    of_.lpstrFileTitle  = buf2;
    of_.nMaxFile	    = 1024;
    of_.nMaxFileTitle   = 1024;
    of_.Flags		    = flags;

	if ( filename_.size() > 0 )
		::memcpy( buf, filename_.c_str(), (filename_.size()+1)*sizeof(mol::TCHAR) );

    BOOL ret =::GetSaveFileName(&of_);

    if ( of_.nFileExtension != 0 )
		extension_ = mol::string( (mol::TCHAR*)(of_.lpstrFile + of_.nFileExtension) );
    else
        extension_ = _T("");

    filename_  = buf;
    filetitle_ = buf2;

    return ret;
}




} // end namespace mol
