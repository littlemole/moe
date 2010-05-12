#ifndef MOL_FOLDER_DEF_GUARD_DEFINE_
#define MOL_FOLDER_DEF_GUARD_DEFINE_

#pragma once

#include "util/uni.h"
#include "win/shell.h"

namespace mol {
namespace io {

////////////////////////////////////////////////////////////////////////////////////
// Browse for folder dialog
////////////////////////////////////////////////////////////////////////////////////

class FolderDlg
{
public:
        FolderDlg(HWND parent = ::GetDesktopWindow() );
        virtual ~FolderDlg(void);

		bool  browse( const mol::TCHAR* path  = 0,
                      const mol::TCHAR* title = 0,
                      int flags = BIF_NONEWFOLDERBUTTON|BIF_NEWDIALOGSTYLE );

        const mol::string& getPath();
        bool  isPath();

private:
        HWND				parent_;
        mol::string			path_;
        bool				ispath_;
};

////////////////////////////////////////////////////////////////////////////////////
// ex version :)
////////////////////////////////////////////////////////////////////////////////////

class FolderBrowser
{
public:
	FolderBrowser();
	FolderBrowser(const mol::string& text);
	FolderBrowser(const mol::string& text, const mol::string& title);

	mol::string select( HWND owner, 
			  UINT flags = BIF_NEWDIALOGSTYLE|
              BIF_RETURNFSANCESTORS|BIF_SHAREABLE, 
			  mol::io::Shit& shit = desktop().shellItem()
			);

	Shit dlg( HWND owner, 
			  UINT flags = BIF_NEWDIALOGSTYLE|
              BIF_RETURNFSANCESTORS|BIF_SHAREABLE, 
              mol::io::Shit& shit = desktop().shellItem()
			);

protected:
	virtual int OnInit( HWND hwnd);
	virtual int OnIUnknown( HWND hwnd, IUnknown* punk);
	virtual int OnSelect( HWND hwnd, LPITEMIDLIST pidl);
	virtual int OnValidateFailed( HWND hwnd, const mol::TCHAR* path);

	virtual int browseProc( HWND hwnd, UINT uMsg, LPARAM lParam);

private:

	static int CALLBACK BrowseCallbackProc( HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData);

	mol::string		text_;
	mol::string		title_;
	BROWSEINFO		bInfo_;
};

// handifier to call std XP or Vista style folder browser
extern mol::string browseForFolder( HWND owner );

} // end namespace mol::win::io;
} // end namespace mol;

#endif