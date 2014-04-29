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

		bool  browse( const wchar_t* path  = 0,
                      const wchar_t* title = 0,
                      int flags = BIF_NONEWFOLDERBUTTON|BIF_NEWDIALOGSTYLE );

        const std::wstring& getPath();
        bool  isPath();

private:
        HWND				parent_;
        std::wstring			path_;
        bool				ispath_;
};

////////////////////////////////////////////////////////////////////////////////////
// ex version :)
////////////////////////////////////////////////////////////////////////////////////

class FolderBrowser
{
public:
	FolderBrowser();
	FolderBrowser(const std::wstring& text);
	FolderBrowser(const std::wstring& text, const std::wstring& title);

	std::wstring select( HWND owner, 
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
	virtual int OnValidateFailed( HWND hwnd, const wchar_t* path);

	virtual int browseProc( HWND hwnd, UINT uMsg, LPARAM lParam);

private:

	static int CALLBACK BrowseCallbackProc( HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData);

	std::wstring		text_;
	std::wstring		title_;
	BROWSEINFO		bInfo_;
};

// handifier to call std XP or Vista style folder browser
extern std::wstring browseForFolder( HWND owner );

} // end namespace mol::win::io;
} // end namespace mol;

#endif