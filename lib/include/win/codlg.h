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
		HWND findText( HWND parent, DWORD flags = FR_DOWN, const wchar_t* what = 0 );
		HWND replaceText( HWND parent, DWORD flags = FR_DOWN, const wchar_t* what = 0, const wchar_t* which = 0 );
        static int getSearchMsg();
        virtual LRESULT wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
        const std::wstring& wndClass() { static std::wstring c(_T("")); return c; }
        HWND virtual createWindow( const std::wstring& windowName, HMENU id, const Rect& r, HWND parent ) { return 0; };
        FINDREPLACE frp_;
		static wchar_t bufWhich_[];
		static wchar_t bufWhat_[];
};

class FilenameDlg
{
public:
        FilenameDlg( HWND parent );

        void setFilter( const wchar_t* filter );

        const std::wstring fileName( int i = 0);
		void  fileName(const std::wstring& s);
        const std::wstring ext( int i = 0);
        const std::wstring title( int i = 0);

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
		std::vector<std::wstring> filenames_;

        std::wstring			filename_;
        std::wstring			extension_;
        std::wstring			filetitle_;
        OPENFILENAME		of_;

		static UINT_PTR __stdcall hook(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam);
};



} // endnamespace mol

#endif;
