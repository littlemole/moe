#include "win/DIB.h"
#include "math.h"
#include "win/app.h"
#include "win/res.h"
#include <assert.h>
#include <fstream>


namespace mol {
namespace win {

DIB::DIB()
	: pvoid_(0),
	  plineptr_(0),
	  width_(0),
	  height_(0)
{}

DIB::~DIB()
{
	destroy();
}

void DIB::bitBlt(HDC hDest,int nXDest,int nYDest,int nWidth,int nHeight,int xSrc,int ySrc)
{
	::SetDIBitsToDevice(hDest,nXDest,nYDest,nWidth,nHeight,xSrc,height()-ySrc-nHeight,0,height(),pbits_,pinfo_,DIB_RGB_COLORS);
}


bool DIB::create(int w,int h,int bits)
{
	destroy();

	width_ = w;
	height_ = h;

	BITMAPINFOHEADER bmInfo;	
	memset(&bmInfo,0,sizeof(BITMAPINFOHEADER));
	bmInfo.biSize = sizeof(BITMAPINFOHEADER);
	bmInfo.biWidth = width_;
	bmInfo.biHeight = height_;
	bmInfo.biPlanes = 1;
	bmInfo.biBitCount = bits;
	bmInfo.biCompression = BI_RGB;

	bytes_ = (bmInfo.biBitCount*bmInfo.biWidth)>>3;
	while(bytes_%4) bytes_++;

	int size;
	size = sizeof(BITMAPINFOHEADER) + sizeof(RGBQUAD) * getPaletteSize(bmInfo) + bytes_*height_;

	pvoid_ = (void *)malloc(size);
	if( !pvoid_ ) 
		return false;

	pinfo_ = (PBITMAPINFO )pvoid_;
	memcpy((void *)&pinfo_->bmiHeader,(void *)&bmInfo,sizeof(BITMAPINFOHEADER));

	pRGB_  = (RGBQUAD *)((unsigned char *)pvoid_ + sizeof(BITMAPINFOHEADER)) ;
	pbits_ = (unsigned char *)(pvoid_) + sizeof(BITMAPINFOHEADER) + sizeof(RGBQUAD) * getPaletteSize();

	int i;
	BYTE **ptr;
	
	plineptr_ = (BYTE **)malloc(sizeof(BYTE *)*height_);
	if ( !plineptr_ ) 
		return false;

	for( i = 0, ptr = plineptr_; i < height_; i++, ptr++ )
	{
		*ptr = pbits_ + (height_-i-1)*bytes_;
	}
	nFlags_ = 0;
	return true;

}

unsigned char * DIB::get_line_ptr(int line)
{
	return plineptr_[line];
}


void DIB::setPalette(unsigned char *palette)
{
	int i,size;
	RGBQUAD *rgb;

	if( !palette ) 
		return;

	size = getPaletteSize();
	for( i=0, rgb = pRGB_; i < size; i++, rgb++, palette+=3 )
	{
		rgb->rgbRed = palette[0];
		rgb->rgbGreen = palette[1];
		rgb->rgbBlue = palette[2];
		rgb->rgbReserved = (BYTE)0;
	}
}


int DIB::getPaletteSize(BITMAPINFOHEADER& bmInfo)
{
	switch(bmInfo.biBitCount)
	{
	case 1:
			return 2;
	case 4:
			return 16;
	case 8:
			return 256;
	default:
			return 0;
	}
}

int DIB::getPaletteSize()
{
	return getPaletteSize(pinfo_->bmiHeader);
}

void DIB::destroy()
{
	if(pvoid_) 
		free(pvoid_);

	pvoid_ = 0;
	if(plineptr_) 
		free(plineptr_);

	plineptr_ = 0;
}


} // end namespace mol::win
} // end namespace mol

