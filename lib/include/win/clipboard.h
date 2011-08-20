#ifndef _MOL_DEF_GUARD_DEFINE_WIN_MOL_CLIB_BOARD_DEFINE_
#define _MOL_DEF_GUARD_DEFINE_WIN_MOL_CLIB_BOARD_DEFINE_

#include "win/wnd.h"
#include <string>
#include <iostream>
#include <Windows.h>
#include <vector>
#include <map>

namespace mol {
namespace win {

class ClipBoard
{
public:

	class Entry
	{
		public:
			Entry();
			Entry(UINT f, const std::wstring& t);

			UINT format ;
			std::wstring title;
	};

	ClipBoard( HWND hWnd = 0);
	~ClipBoard();

	const std::vector<Entry>& formats();
	UINT format( const std::wstring& key );

	std::string getAnsiText( UINT format );
	std::wstring getUnicodeText( UINT format );

	LCID getLocale(UINT format = CF_LOCALE);
	std::string getHTMLfragment();
	std::string getHTML();


	static const wchar_t* BITMAP;
	static const wchar_t* DIB;
	static const wchar_t* DIB5;
	static const wchar_t* DSPEMF;
	static const wchar_t* DSPMF;
	static const wchar_t* UNICODE_TEXT;
	static const wchar_t* EMF;
	static const wchar_t* HDROP;
	static const wchar_t* LOCALE;
	static const wchar_t* MF;
	static const wchar_t* TEXT;
	static const wchar_t* OEM;
	static const wchar_t* HTML;
	static const wchar_t* TEXT_HTML;
	static const wchar_t* CSV;
	static const wchar_t* RTF;

private:

	void enumClipboard();

	HWND hWnd_;
	std::vector<Entry> formats_;
	std::map<std::wstring,UINT> map_;
};



} // end namespace win
} // end namespace mol

#endif