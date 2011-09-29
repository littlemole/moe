#ifndef _COMMON_DLG_DEF_
#define _COMMON_DLG_DEF_

#include "conf.h"
#include "win/Ctrl.h"
#include <commdlg.h>

#define WM_SEARCH_MSG mol::SearchDlg::getSearchMsg()

namespace mol  {


class SearchDlg : public mol::win::Ctrl
{
public:
        SearchDlg( );
		HWND findText( HWND parent, DWORD flags = FR_DOWN, const mol::TCHAR* what = 0 );
		HWND replaceText( HWND parent, DWORD flags = FR_DOWN, const mol::TCHAR* what = 0, const mol::TCHAR* which = 0 );
        static int getSearchMsg();
        virtual LRESULT wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
        const mol::string& wndClass() { static mol::string c(_T("")); return c; }
        HWND virtual createWindow( const mol::string& windowName, HMENU id, const Rect& r, HWND parent ) { return 0; };
        FINDREPLACE frp_;
		static mol::TCHAR bufWhich_[];
		static mol::TCHAR bufWhat_[];
};

class FilenameDlg
{
public:
        FilenameDlg( HWND parent );

        void setFilter( const mol::TCHAR* filter );

        const mol::string fileName( int i = 0);
		void  fileName(const mol::string& s);
        const mol::string ext( int i = 0);
        const mol::string title( int i = 0);

		int  selections();

        int  index();
		void index(int i);

        BOOL  dlgOpen( int flags = OFN_HIDEREADONLY );
        BOOL  dlgSave( int flags = OFN_HIDEREADONLY );

		bool readOnly();

		virtual void OnCustomize() {};
		virtual void OnInit() {};
		virtual void OnDestroy() {};
		virtual LRESULT OnMsg(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam);

protected:

		HWND dlg_;
		std::vector<mol::string> filenames_;

        mol::string			filename_;
        mol::string			extension_;
        mol::string			filetitle_;
        OPENFILENAME		of_;

		static UINT_PTR __stdcall hook(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam);
};



} // endnamespace mol

#endif;
