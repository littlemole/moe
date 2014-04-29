#include "ole/img.h"
#include "ole/stream.h"
#include "util/istr.h"
#include <olectl.h>
#include <sstream>

#define HIMETRIC_INCH   2540    // HIMETRIC units per inch

namespace mol {


////////////////////////////////////////////////////////////////
// Picture implementation
//

Picture::Picture()
{
}

Picture::~Picture()
{
}

HRESULT Picture::copy(IPicture** pic)
{
	if (!pic )
		return E_POINTER;

	return pPicture_->QueryInterface(IID_IPicture,(void**)pic);
}

HRESULT Picture::copy(IPictureDisp** pic)
{
	if (!pic )
		return E_POINTER;

	return pPicture_->QueryInterface(IID_IPictureDisp,(void**)pic);
}

//////////////////
// Load from resource. Looks for "IMAGE" type.
//

BOOL Picture::load( UINT nIDRes)
{
	mol::img_resource img;
    if (! img.load(nIDRes) )
        return FALSE;

	mol::global glob;
	std::string s = mol::tostring(img());

	Stream pStream(s.c_str(), s.size() );
	if (! pStream  )
        return FALSE;
    return load(pStream);
}

//////////////////
// Load from path name.
//
BOOL Picture::load(const std::wstring& pathName)
{
//	mol::cistring filename(mol::tostring(pathName).c_str());

//    if ( filename.substr(0,7) == "http://")
//        return loadUrl(pathName.c_str());

    HANDLE hFile = ::CreateFile( pathName.c_str(),
                                 FILE_READ_DATA,
                                 FILE_SHARE_READ,
                                 NULL,
                                 OPEN_EXISTING,
                                 FILE_ATTRIBUTE_NORMAL,
                                 NULL );
    if ( !hFile )
        return FALSE;

    DWORD len = ::GetFileSize( hFile, NULL); // only 32-bit of the actual file size is retained
    if ( (len == 0 ) || (len > 10000000) )
        return FALSE;

	mol::global glob;
    if ( !glob.alloc(len) )
    {
        ::CloseHandle(hFile);
        return FALSE;
    }

    char* lpBuffer = (char*)glob.lock();
    DWORD dwBytesRead = 0;

    while ( ::ReadFile(hFile, lpBuffer, 4096, &dwBytesRead, NULL) )
    {
        lpBuffer += dwBytesRead;
        if (dwBytesRead == 0)
            break;
        dwBytesRead = 0;
    }

    ::CloseHandle(hFile);
    glob.unLock();

	Stream pStream(glob);

    if ( !pStream )
        return FALSE;

	glob.detach();

    // create memory file and load it
    return load(pStream);
}

// Load from URL
//
/*
BOOL Picture::loadUrl(LPCTSTR url)
{
    std::string bin;

    Inet inet;
    inet.open();

    mol::Get get(inet);
    bin = get(url);

    inet.close();

    if (bin.size() == 0 || bin.size() > 1000000)
        return FALSE;

    mol::Global glob;
//	mol::UnknownPtr<IStream> pStream;
//	Stream::create( &pStream, bin.c_str(), bin.size()); 
	mol::Stream pStream( bin.c_str(), bin.size()); 
	if (! pStream)
        return FALSE;

    return load(pStream);
}
*/

//////////////////
// Load from stream (IStream). This is the one that really does it: call
// OleLoadPicture to do the work.
//
BOOL Picture::load(IStream* pstm)
{
    pPicture_.release();

	LARGE_INTEGER li; 
	li.QuadPart = 0; 
	HRESULT hr = pstm->Seek(li, STREAM_SEEK_SET, NULL); 
	if ( hr != S_OK )
		return FALSE;

    hr = OleLoadPicture(pstm, 0, FALSE, IID_IPicture, (void**)&pPicture_);
    return hr == S_OK;
}

//////////////////
// Render to device context. Covert to HIMETRIC for IPicture.
//
// prcMFBounds : NULL if dc is not a metafile dc
//
BOOL Picture::render(HDC dc, RECT* rc, LPCRECT prcMFBounds) 
{
    if (!pPicture_)
        return FALSE;

    if ( !rc || (rc->right == rc->left && rc->bottom == rc->top) )
    {
        SIZE sz = getSize(dc);
        rc->right = sz.cx;
        rc->bottom = sz.cy;
    }

    long hmWidth,hmHeight; // HIMETRIC units
    getOleSize(hmWidth, hmHeight);

    pPicture_->Render( dc, rc->left, rc->top,
        rc->right - rc->left, rc->bottom - rc->top,
        0, hmHeight, hmWidth, -hmHeight, prcMFBounds);
    return TRUE;
}

//////////////////
// Get image size in pixels. Converts from HIMETRIC to device coords.
//
SIZE Picture::getSize(HDC dc) 
{
    SIZE sz = {0,0};

    if (!pPicture_)
        return sz;

    LONG hmWidth, hmHeight; // HIMETRIC units
    pPicture_->get_Width(&hmWidth);
    pPicture_->get_Height(&hmHeight);

    sz.cx = hmWidth;
    sz.cy = hmHeight;

    if ( dc == NULL )
    {
        HDC dcscreen = ::GetWindowDC(NULL);
        setHIMETRICtoDP(dcscreen,&sz); // convert to pixels
    }
    else
    {
        setHIMETRICtoDP(dc,&sz);
    }
    return sz;
}


void Picture::setHIMETRICtoDP(HDC hdc, SIZE* sz) const
{
    int nMapMode;
    if ( (nMapMode = ::GetMapMode(hdc)) < MM_ISOTROPIC && nMapMode != MM_TEXT)
    {
        // when using a constrained map mode, map against physical inch

        ::SetMapMode(hdc,MM_HIMETRIC);
        POINT pt;
        pt.x = sz->cx;
        pt.y = sz->cy;
        ::LPtoDP(hdc,&pt,1);
        sz->cx = pt.x;
        sz->cy = pt.y;
        ::SetMapMode(hdc, nMapMode);
    }
    else
    {
        // map against logical inch for non-constrained mapping modes
        int cxPerInch, cyPerInch;
        cxPerInch = ::GetDeviceCaps(hdc,LOGPIXELSX);
        cyPerInch = ::GetDeviceCaps(hdc,LOGPIXELSY);
        sz->cx = MulDiv(sz->cx, cxPerInch, HIMETRIC_INCH);
        sz->cy = MulDiv(sz->cy, cyPerInch, HIMETRIC_INCH);
    }
    POINT pt;
    pt.x = sz->cx;
    pt.y = sz->cy;
    ::DPtoLP(hdc,&pt,1);
    sz->cx = pt.x;
    sz->cy = pt.y;
}



} // end namespace mol
