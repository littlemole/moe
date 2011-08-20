#include "win/clipboard.h"
#include "util/util.h"
#include "util/str.h"

namespace mol 
{

namespace win 
{

const wchar_t* ClipBoard::BITMAP  = L"Bitmap";
const wchar_t* ClipBoard::DIB  = L"Device Independent Bitmap";
const wchar_t* ClipBoard::DIB5  = L"Device Independent Bitmap (V5)";
const wchar_t* ClipBoard::DSPEMF  = L"DSP Enhanced Metafile";
const wchar_t* ClipBoard::DSPMF  = L"DSP Metafile Picture";
const wchar_t* ClipBoard::UNICODE_TEXT  = L"Unicode Text";
const wchar_t* ClipBoard::EMF  = L"Enhanced Metafile";
const wchar_t* ClipBoard::HDROP  = L"Shell Dropfiles List";
const wchar_t* ClipBoard::LOCALE  = L"Locale";
const wchar_t* ClipBoard::MF  = L"Metafile Picture";
const wchar_t* ClipBoard::TEXT  = L"Ansi Text";
const wchar_t* ClipBoard::OEM  = L"OEM Text";
const wchar_t* ClipBoard::HTML  = L"HTML Format";
const wchar_t* ClipBoard::TEXT_HTML  = L"text/html";
const wchar_t* ClipBoard::CSV  = L"Csv";
const wchar_t* ClipBoard::RTF  = L"Rich Text Format";


ClipBoard::Entry::Entry()
	:format(0),title(L"")
{}


ClipBoard::Entry::Entry(UINT f, const std::wstring& t)
	:format(f),title(t)
{}


ClipBoard::ClipBoard( HWND hWnd )
	:hWnd_(hWnd)
{
	::OpenClipboard(hWnd_);
	enumClipboard();
}

ClipBoard::~ClipBoard()
{
	::CloseClipboard();
}

const std::vector<ClipBoard::Entry>& ClipBoard::formats()
{
	return formats_;
}

UINT ClipBoard::format( const std::wstring& key )
{
	if ( map_.count(key) > 0 ) 
	{
		return map_[key];
	}
	return 0;
}


std::string ClipBoard::getAnsiText( UINT format )
{
	std::string ret;
	HGLOBAL glob = ::GetClipboardData(format); 
	if (glob != NULL) 
	{ 
		char* ptr = (char*)::GlobalLock(glob); 
		if (ptr) 
		{ 
			size_t len = ::GlobalSize(glob);
			ret = std::string(ptr,len);
			::GlobalUnlock(glob); 
		}
	}
	return ret;
}

std::wstring ClipBoard::getUnicodeText( UINT format )
{
	std::wstring ret;
	HGLOBAL glob = ::GetClipboardData(format); 
	if (glob != NULL) 
	{ 
		wchar_t* ptr = (wchar_t*)::GlobalLock(glob); 
		if (ptr) 
		{ 
			size_t len = ::GlobalSize(glob);
			ret = std::wstring(ptr,len/sizeof(wchar_t));
			::GlobalUnlock(glob); 
		}
	}
	return ret;
}

LCID ClipBoard::getLocale(UINT format )
{
	LCID lcid = 0;
	HGLOBAL glob = ::GetClipboardData(format); 
	if (glob != NULL) 
	{ 
		LCID* ptr = (LCID*)::GlobalLock(glob); 
		if ( ptr)
		{
			lcid = *ptr;
			::GlobalUnlock(glob); 
		}
	}
	return lcid;
}

std::string ClipBoard::getHTMLfragment() 
{
	std::string html = getAnsiText( format(ClipBoard::HTML) );
	const char* start = "<!--StartFragment-->";
	const char* end = "<!--EndFragment-->";

	std::vector<std::string> v = split(html,start);
	if ( v.size() > 1 )
	{
		v = split(v[1],end);
		if ( v.size() > 0 )
		{
			return v[0];
		}
		return v[1];
	}
	else if ( v.size() > 0 )
	{
		return v[0];
	}
	return html;
}

std::string ClipBoard::getHTML() 
{
	std::string html = getAnsiText( format(ClipBoard::HTML) );
	const char* start = "<html";

	std::vector<std::string> v = split(html,start);
	if ( v.size() > 1 )
	{
		std::string ret(start);
		return ret + v[1];
	}
	else if ( v.size() > 0 )
	{
		return v[0];
	}
	return html;
}

void ClipBoard::enumClipboard()
{
	UINT format = 0;
	formats_.clear();

	format = ::EnumClipboardFormats(format);
	while( format ) 
	{
		switch (format )
		{
			case 2 :
			{
				formats_.push_back( ClipBoard::Entry(format, ClipBoard::BITMAP) );
				map_.insert( std::make_pair( std::wstring(ClipBoard::BITMAP),format) );
				break;
			}
			case 8 :
			{
				formats_.push_back( ClipBoard::Entry(format, ClipBoard::DIB) );
				map_.insert( std::make_pair( std::wstring(ClipBoard::DIB),format) );
				break;
			}
			case 17 :
			{
				formats_.push_back( ClipBoard::Entry(format, ClipBoard::DIB5) );
				map_.insert( std::make_pair( std::wstring(ClipBoard::DIB5),format) );
				break;
			}
			case 0x008E :
			{
				formats_.push_back( ClipBoard::Entry(format, ClipBoard::EMF) );
				map_.insert( std::make_pair( std::wstring(ClipBoard::EMF),format) );
				break;
			}
			case 0x0083 :
			{
				formats_.push_back( ClipBoard::Entry(format, ClipBoard::DSPMF) );
				map_.insert( std::make_pair( std::wstring(ClipBoard::DSPMF),format) );
				break;
			}
			case 13 :
			{
				formats_.push_back( ClipBoard::Entry(format, ClipBoard::UNICODE_TEXT) );
				map_.insert( std::make_pair( std::wstring(ClipBoard::UNICODE_TEXT),format) );
				break;
			}
			case 14 :
			{
				formats_.push_back( ClipBoard::Entry(format, ClipBoard::EMF) );
				map_.insert( std::make_pair( std::wstring(ClipBoard::EMF),format) );
				break;
			}
			case 15 :
			{
				formats_.push_back( ClipBoard::Entry(format, ClipBoard::HDROP) );
				map_.insert( std::make_pair( std::wstring(ClipBoard::HDROP),format) );
				break;
			}
			case 16 :
			{
				formats_.push_back( ClipBoard::Entry(format, ClipBoard::LOCALE) );
				map_.insert( std::make_pair( std::wstring(ClipBoard::LOCALE),format) );
				break;
			}
			case 3 :
			{
				formats_.push_back( ClipBoard::Entry(format, ClipBoard::MF) );
				map_.insert( std::make_pair( std::wstring(ClipBoard::MF),format) );
				break;
			}
			case 7 :
			{
				formats_.push_back( ClipBoard::Entry(format, ClipBoard::OEM) );
				map_.insert( std::make_pair( std::wstring(ClipBoard::OEM),format) );
				break;
			}
			case 1 :
			{
				formats_.push_back( ClipBoard::Entry(format, ClipBoard::TEXT) );
				map_.insert( std::make_pair( std::wstring(ClipBoard::TEXT),format) );
				break;
			}

			default:
			{
				wchar_t buf[MAX_PATH];
				int c = ::GetClipboardFormatNameW( format, buf, MAX_PATH );

				if ( c > 0 ) 
				{
					std::wstring title(buf,c);
					formats_.push_back( ClipBoard::Entry(format, title) );
					map_.insert( std::make_pair( title,format) );
				}
			}
		}
		format = ::EnumClipboardFormats(format);
	}
}


} // end namespace win
} // end namespace mol