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

void ClipBoard::clear()
{
	::EmptyClipboard();
	formats_.clear();
	map_.clear();
}

void ClipBoard::setData( UINT format, HANDLE data )
{
	::SetClipboardData(format,data);
}


void ClipBoard::setAnsiText( const std::string& txt )
{
	mol::global glob(txt,GMEM_MOVEABLE);
	setData( CF_TEXT, glob );
}

void ClipBoard::setUnicodeText( const std::wstring& txt )
{
	mol::global glob(txt,GMEM_MOVEABLE);
	setData( CF_UNICODETEXT, glob );
}

void ClipBoard::setLocale( LCID id )
{
	mol::global glob((void*)&id,sizeof(LCID));
	setData( CF_LOCALE, glob );
}

void ClipBoard::setHTML(const std::string& txt )
{
	UINT format = ::RegisterClipboardFormat(ClipBoard::HTML);
	mol::global glob(txt,GMEM_MOVEABLE);
	setData( format, glob );
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
	map_.clear();

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

bool ClipBoard::setBitmap(HBITMAP hBM)
{
    ::EmptyClipboard();
    
    ::BITMAP bm;
    ::GetObject(hBM, sizeof(bm), &bm);
    
    BITMAPINFOHEADER bi;
    ::ZeroMemory(&bi, sizeof(BITMAPINFOHEADER));
    bi.biSize = sizeof(BITMAPINFOHEADER);
    bi.biWidth = bm.bmWidth;
    bi.biHeight = bm.bmHeight;
    bi.biPlanes = 1;
    bi.biBitCount = bm.bmBitsPixel;
    bi.biCompression = BI_RGB;
    if (bi.biBitCount <= 1)	// make sure bits per pixel is valid
        bi.biBitCount = 1;
    else if (bi.biBitCount <= 4)
        bi.biBitCount = 4;
    else if (bi.biBitCount <= 8)
        bi.biBitCount = 8;
    else // if greater than 8-bit, force to 24-bit
        bi.biBitCount = 24;
    
    // Get size of color table.
    SIZE_T dwColTableLen = (bi.biBitCount <= 8) ? ((SIZE_T)1 << (SIZE_T)bi.biBitCount) * sizeof(RGBQUAD) : 0;
    
    // Create a device context with palette
    HDC hDC = ::GetDC(NULL);
    HPALETTE hPal = static_cast<HPALETTE>(::GetStockObject(DEFAULT_PALETTE));
    HPALETTE hOldPal = ::SelectPalette(hDC, hPal, FALSE);
    ::RealizePalette(hDC);
    
    // Use GetDIBits to calculate the image size.
    ::GetDIBits(hDC, hBM, 0, static_cast<UINT>(bi.biHeight), NULL,
        reinterpret_cast<LPBITMAPINFO>(&bi), DIB_RGB_COLORS);
    // If the driver did not fill in the biSizeImage field, then compute it.
    // Each scan line of the image is aligned on a DWORD (32bit) boundary.
    if (0 == bi.biSizeImage)
        bi.biSizeImage = ((((bi.biWidth * bi.biBitCount) + 31) & ~31) / 8) * bi.biHeight;
    
    // Allocate memory
    HGLOBAL hDIB = ::GlobalAlloc(GMEM_MOVEABLE, sizeof(BITMAPINFOHEADER) + dwColTableLen + bi.biSizeImage);
    if (hDIB)
    {
        union tagHdr_u
        {
            LPVOID             p;
            LPBYTE             pByte;
            LPBITMAPINFOHEADER pHdr;
            LPBITMAPINFO       pInfo;
        } Hdr;
        
        Hdr.p = ::GlobalLock(hDIB);
        // Copy the header
        ::CopyMemory(Hdr.p, &bi, sizeof(BITMAPINFOHEADER));
        // Convert/copy the image bits and create the color table
        int nConv = ::GetDIBits(hDC, hBM, 0, static_cast<UINT>(bi.biHeight),
            Hdr.pByte + sizeof(BITMAPINFOHEADER) + dwColTableLen, 
            Hdr.pInfo, DIB_RGB_COLORS);
        ::GlobalUnlock(hDIB);
        if (!nConv)
        {
            ::GlobalFree(hDIB);
            hDIB = NULL;
        }
    }
    if (hDIB)
        ::SetClipboardData(CF_DIB, hDIB);
    ::CloseClipboard();
    ::SelectPalette(hDC, hOldPal, FALSE);
    ::ReleaseDC(NULL, hDC);
    return NULL != hDIB;
}



} // end namespace win
} // end namespace mol