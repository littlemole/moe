#ifndef MOLD_DEF_Picture
#define MOLD_DEF_Picture

#include "util/uni.h"
#include "ole/com.h"
#include "ole/punk.h"
#include "win/res.h"
#include <ocidl.h>

namespace mol {

class Picture
{
public:
    Picture();
    ~Picture();

    // Load frm resource
    BOOL load(UINT nIDRes);

    // load from file or http
    BOOL load(const mol::string& pathName);

    // load from stream
    BOOL load(IStream* pstm);

    // render to device context
    BOOL render(HDC dc, RECT* rc, LPCRECT prcMFBounds=NULL) ;

    // get size
    SIZE getSize(HDC dc=NULL) ;

    operator bool() { return pPicture_(); }

	HRESULT copy(IPicture** pic);
	HRESULT copy(IPictureDisp** pic);

protected:

    //BOOL loadUrl(LPCTSTR pszPathName);

    void setHIMETRICtoDP(HDC hdc, SIZE* sz) const;
    void getOleSize( OLE_XSIZE_HIMETRIC& cx, OLE_YSIZE_HIMETRIC& cy) const
    {
        cx = cy = 0;
        const IPicture* cip = (const IPicture*)pPicture_;
        const_cast<Picture*>(this)->hr_ = ((IPicture*)cip)->get_Width(&cx);
        const_cast<Picture*>(this)->hr_ = ((IPicture*)cip)->get_Height(&cy);
    }

    punk<IPicture>			pPicture_;
    HRESULT			            hr_;
};



} // end namespace mol

#endif
