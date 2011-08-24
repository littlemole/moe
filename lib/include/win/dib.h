#pragma once
#ifndef _MOL_COLOR_DLG_PICKER_DEF_GUARD_
#define _MOL_COLOR_DLG_PICKER_DEF_GUARD_

#include "util/uni.h"

namespace mol {
namespace win {


class DIB 
{
public:

	DIB();
	~DIB();

	bool create(int w,int h,int bits=24);
	void setPalette(unsigned char *palette);
	void bitBlt(HDC hDest,int nXDest,int nYDest,int nWidth,int nHeight,int xSrc,int ySrc);

	int width()  { return width_; }
	int height() { return height_; }

	unsigned char *get_line_ptr(int line);

private:

	int getPaletteSize(BITMAPINFOHEADER& bmInfo);
	int getPaletteSize();
	void destroy();

	unsigned char *pbits_;
	PBITMAPINFO    pinfo_;
	RGBQUAD       *pRGB_;
	void		  *pvoid_; 
	BYTE		 **plineptr_;

	int height_,bytes_,width_,nBits_;
	int nFlags_;
};

} // end namespace mol::win
} // end namespace mol

#endif;