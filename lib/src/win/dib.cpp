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


/*
#define BIG_DISTANCE 10000000L

#define DIST(r1,g1,b1,r2,g2,b2)                             \
	    (long) (3L*(long)((r1)-(r2))*(long)((r1)-(r2)) +    \
		4L*(long)((g1)-(g2))*(long)((g1)-(g2)) +            \
		2L*(long)((b1)-(b2))*(long)((b1)-(b2)))

#ifdef WIN32
#define molMAX max
#else
#define molMAX std::max
#endif

#ifdef __MINGW32__
#undef molMAX  
#include <algorithm>
#define molMAX std::max
#endif

namespace mol {
namespace win {

static unsigned char masktable[] = { 0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01 };

DIB::DIB(HANDLE hDib,int nBits)
{
	m_pVoid = NULL;
	m_pLinePtr = NULL;
	m_bUseGamma=FALSE;
	width=height=0;
	if(hDib)
	{
		CreateFromHandle(hDib,nBits);
	}
}

DIB::~DIB()
{
	DestroyDIB();
}

void DIB::DestroyDIB()
{
	if(m_pVoid) free(m_pVoid);
	m_pVoid = NULL;
	if(m_pLinePtr) free(m_pLinePtr);
	m_pLinePtr = NULL;
}


BOOL DIB::Create(int width,int height,int bits)
{
	DestroyDIB();

    BITMAPINFOHEADER bmInfo;	
	memset(&bmInfo,0,sizeof(BITMAPINFOHEADER));
	bmInfo.biSize = sizeof(BITMAPINFOHEADER);
	bmInfo.biWidth = width;
	bmInfo.biHeight = height;
	bmInfo.biPlanes = 1;
	bmInfo.biBitCount = bits;
	bmInfo.biCompression = BI_RGB;
	return Create(bmInfo);
}

BOOL DIB::Create(BITMAPINFOHEADER& bmInfo)
{
	bytes = (bmInfo.biBitCount*bmInfo.biWidth)>>3;
	height = bmInfo.biHeight;
	width = bmInfo.biWidth;
	while(bytes%4) bytes++;

	int size;
	size = sizeof(BITMAPINFOHEADER) + sizeof(RGBQUAD)*GetPaletteSize(bmInfo) + bytes*height;
	m_pVoid = (void *)malloc(size);
	if(!m_pVoid) return FALSE;

	m_pInfo = (PBITMAPINFO )m_pVoid;
	memcpy((void *)&m_pInfo->bmiHeader,(void *)&bmInfo,sizeof(BITMAPINFOHEADER));
	m_pRGB = (RGBQUAD *)((unsigned char *)m_pVoid + sizeof(BITMAPINFOHEADER)) ;
	m_pBits = (unsigned char *)(m_pVoid) + sizeof(BITMAPINFOHEADER) + sizeof(RGBQUAD)*GetPaletteSize();

    int i;
    BYTE **ptr;
	m_pLinePtr = (BYTE **)malloc(sizeof(BYTE *)*height);
	if(!m_pLinePtr) return FALSE;
	for(i=0,ptr=m_pLinePtr; i < height; i++,ptr++)
	{
		*ptr = m_pBits + (height-i-1)*bytes;
	}
	m_nFlags = 0;
	return TRUE;
}

BOOL DIB::Load(UINT nIdResource)
{
	bitmap = 0;
	HBITMAP oldBitmap = 0;
			
	if ( bitmap = ::LoadBitmap( mol::hinstance(),MAKEINTRESOURCE(nIdResource)) )
	{
		mol::DC dc(::GetDesktopWindow());
		mol::DC memDC(::CreateCompatibleDC(dc));

		int width,height;
		BITMAP bmInfo;
		::GetObject(bitmap,sizeof(bmInfo),&bmInfo);	
		width = bmInfo.bmWidth;
		height = bmInfo.bmHeight;

		oldBitmap = (HBITMAP)::SelectObject(memDC,bitmap);

		COLORREF colorWindow = ::GetSysColor(COLOR_3DFACE);
		COLORREF sourceColor = ::GetPixel(memDC,1,1);

		int i,j;
		for(i=0; i < height; i++)
		{
			for(j=0; j < width; j++)
			{
				COLORREF c = ::GetPixel(memDC,j,i);
				if ( ::GetPixel(memDC,j,i) == sourceColor )
				{
					::SetPixel(memDC,j,i,colorWindow);
				}
			}
		}
		::SelectObject(memDC,oldBitmap);
		return TRUE;
	}
	return FALSE;
}

void DIB::SetPalette(unsigned char *palette)
{
    int i,size;
    RGBQUAD *rgb;
	if(!palette) return;
	size = GetPaletteSize();
	for(i=0,rgb = m_pRGB; i < size; i++,rgb++,palette+=3)
	{
		if(m_bUseGamma)
		{
			rgb->rgbRed = Gamma[palette[0]];
			rgb->rgbGreen = Gamma[palette[1]];
			rgb->rgbBlue = Gamma[palette[2]];
		}
		else
		{
			rgb->rgbRed = palette[0];
			rgb->rgbGreen = palette[1];
			rgb->rgbBlue = palette[2];
		}
		rgb->rgbReserved = (BYTE)0;
	}
}

void DIB::SetPalette(RGBQUAD *pRGB)
{
    int size;
	if(!pRGB) 
        return;
	size = GetPaletteSize();
	memcpy(m_pRGB,pRGB,size*sizeof(RGBQUAD));
}


int DIB::GetPaletteSize()
{
	return GetPaletteSize(m_pInfo->bmiHeader);
}


int DIB::GetPaletteSize(BITMAPINFOHEADER& bmInfo)
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


void DIB::SetPixel(int x,int y,COLORREF color)
{
    unsigned char *ptr;
	assert(x >= 0 && y >=0);
	assert(x < width && y < height);

	ptr = (unsigned char *)m_pLinePtr[y];
	ptr += x*3;
	*ptr++ = (unsigned char)GetBValue(color);
	*ptr++ = (unsigned char)GetGValue(color);
	*ptr++ = (unsigned char)GetRValue(color);
}

void DIB::SetPixel8(int x,int y,unsigned char color)
{
    unsigned char *ptr,*aptr;
	assert(x >= 0 && y >=0);
	assert(x < width && y < height);

	ptr = GetLinePtr(y);
	aptr = ptr;
	ptr += x;
	*ptr = color;
}


COLORREF DIB::GetPixel(int x,int y)
{
    unsigned char *ptr;
    COLORREF color;
	assert(x >= 0 && y >=0);
	assert(x < width && y < height);

    ptr = GetLinePtr(y);
	ptr += (x*3);
	color = RGB(*(ptr+2),*(ptr+1),*ptr);
	return color;
}

HBITMAP DIB::GetBitmap()//HDC dc)
{
	return bitmap;

//	HBITMAP hBitmap;
//	assert(m_pVoid != NULL);
/*	hBitmap = CreateDIBitmap (dc,
				             (PBITMAPINFOHEADER)m_pInfo,
				             CBM_INIT,
				             (const void *)m_pBits,
				             m_pInfo,
				             DIB_RGB_COLORS);

	if (hBitmap == NULL) 
        return NULL;
	return hBitmap;
	* /
}


void DIB::CopyLine(int source,int dest)
{
    unsigned char *src,*dst;
	assert(source <= height && source >= 0);
	assert(dest <= height && dest >= 0);
	if(source == dest) return;
	src = GetLinePtr(source);
	dst = GetLinePtr(dest);
	memcpy(dst,src,bytes);
}

void DIB::InitDIB(COLORREF color)
{
    int i,j;
    unsigned char *ptr;
	
	if(m_pInfo->bmiHeader.biBitCount == 24)
	{
		unsigned char col[3];
		col[0]=GetBValue(color);
		col[1]=GetGValue(color);
		col[2]=GetRValue(color);
		for(i=0,ptr = m_pBits; i < height; i++)
		{
			ptr = m_pBits + i*bytes;
			for(j=0; j < width ; j++,ptr+=3)
			{
				memcpy(ptr,col,3);
			}
		}
	}
	else
	{
		for(i=0,ptr = m_pBits; i < height; i++,ptr+=bytes)
		{
			memset(ptr,(BYTE)color,bytes);
		}
	}
}


void DIB::BitBlt(HDC hDest,int nXDest,int nYDest,int nWidth,int nHeight,int xSrc,int ySrc)
{
	SetDIBitsToDevice(hDest,nXDest,nYDest,nWidth,nHeight,xSrc,Height()-ySrc-nHeight,0,Height(),m_pBits,m_pInfo,DIB_RGB_COLORS);
}

void DIB::StretchBlt(HDC hDest,int nXDest,int nYDest,int nDWidth,int nDHeight,int xSrc,int ySrc,int  nSWidth,int nSHeight)
{
	int err;
	err = StretchDIBits(hDest,nXDest,nYDest,nDWidth,nDHeight,xSrc,ySrc,nSWidth,nSHeight,m_pBits,(CONST BITMAPINFO * )&m_pInfo->bmiHeader,DIB_RGB_COLORS,SRCCOPY);
}

void DIB::ExpandBlt(int nXDest,int nYDest,int xRatio,int yRatio,DIB& dibSrc,int xSrc,int ySrc,int  nSWidth,int nSHeight)
{
	SetPalette(dibSrc.m_pRGB);

	nSWidth = xSrc+nSWidth > dibSrc.width ? dibSrc.width-xSrc : nSWidth;
	nSHeight = ySrc+nSHeight > dibSrc.height? dibSrc.height-ySrc : nSHeight;

	Expand(nXDest,nYDest,xRatio,yRatio,dibSrc,xSrc,ySrc,nSWidth,nSHeight);
}

void DIB::Expand(int nXDest,int nYDest,int xRatio,int yRatio,DIB& dibSrc,int xSrc,int ySrc,int  nSWidth,int nSHeight)
{
    int xNum,yNum,xErr,yErr;	
    int nDWidth,nDHeight;
    	
	nDWidth = nSWidth*xRatio;
	nDHeight = nSHeight*yRatio;

	nDWidth = nXDest+nDWidth > width ? width-nXDest : nDWidth ; 
	nDHeight = nYDest+nDHeight > height ? height-nYDest : nDHeight;

	xNum = nDWidth/xRatio;
	yNum = nDHeight/yRatio;
	xErr = nDWidth%xRatio;
	yErr = nDHeight%yRatio;

    unsigned char *buffer,*srcPtr,*destPtr,*ptr;
    int i,j,k;
    	
	buffer = (unsigned char *)malloc(nDWidth+20);
	if(!buffer) return;

	for(i=0; i < yNum; i++,ySrc++)
	{
		srcPtr = dibSrc.GetLinePtr(ySrc) + xSrc;
		ptr = buffer;
		for(j=0; j < xNum; j++,ptr+=xRatio)
		{
			memset(ptr,*(srcPtr+j),xRatio);
			k=*(srcPtr+j);
		}
		memset(ptr,(unsigned char)k,xErr);
		for(j=0; j < yRatio ; j++,nYDest++)
		{
			destPtr = GetLinePtr(nYDest) + nXDest;
			memcpy(destPtr,buffer,nDWidth);		
		}
	}
	for(j=0; j < yErr; j++,nYDest++)
	{
		destPtr = GetLinePtr(nYDest) + nXDest;
		memcpy(destPtr,buffer,nDWidth);		
	}
	free(buffer);
}

void DIB::StretchBlt(int nXDest,int nYDest,int nDWidth,int nDHeight,DIB& dibSrc,int xSrc,int ySrc,int  nSWidth,int nSHeight)
{
	SetPalette(dibSrc.m_pRGB);
	nDWidth = nXDest+nDWidth > width ? width-nXDest : nDWidth ; 
	nDHeight = nYDest+nDHeight > height ? height-nYDest : nDHeight;

	nSWidth = xSrc+nSWidth > dibSrc.width ? dibSrc.width-xSrc : nSWidth;
	nSHeight = ySrc+nSHeight > dibSrc.height? dibSrc.height-ySrc : nSHeight;

    int xDiv,yDiv;
    int xMod,yMod;

	xDiv = nDWidth/nSWidth;
	xMod = nDWidth%nSWidth;

	yDiv = nDHeight/nSHeight;
	yMod = nDHeight%nSHeight;

	if(!xMod && !yMod && xDiv > 0 && yDiv > 0)
	{
		ExpandBlt(nXDest,nYDest,xDiv,yDiv,dibSrc,xSrc,ySrc,nSWidth,nSHeight);
		return;
	}

    unsigned char *tempPtr,*srcPix,*destPix,*q;
    tempPtr = (unsigned char *)malloc(nDWidth+20);

    int i,j,k,l,x,y,m;
    int xErr,yErr;
	for(i=yErr=m=0; i < nSHeight; i++)
	{
		srcPix = dibSrc.GetLinePtr(i+ySrc) + xSrc;
		q = tempPtr;
		for(j=l=xErr=0; j < nSWidth; j++,srcPix++)
		{
			k = xDiv;
			xErr += xMod;
			if(xErr >= nSWidth)
			{
				k++;
				xErr%=nSWidth;
			}
			x=0;
			while(l < nDWidth &&  x < k)
			{
				*q++ = *srcPix;
				l++;
				x++;
			}
		}
		while(l < nDWidth)
		{
			*q++=*srcPix;
			l++;
		}
		k= yDiv;
		yErr += yMod;
		if(yErr >= nSHeight)
		{
			k++;
			yErr%=nSHeight;
		}
		y=0;
		while(m < nDHeight && y < k)
		{
			destPix = GetLinePtr(m+nYDest) + nXDest;
			memcpy(destPix,tempPtr,nDWidth);
			m++;
			y++;
		}
	}
	while(m < nDHeight )
	{
		destPix = GetLinePtr(m+nYDest) + nXDest;
		memcpy(destPix,tempPtr,nDWidth);
		m++;
	}
	free(tempPtr);
}

void DIB::BitBlt(int nXDest,int nYDest,int nWidth,int nHeight,DIB& dibSrc,int nSrcX,int nSrcY,BYTE *colors)
{
	SetPalette(dibSrc.m_pRGB);
	if(nXDest < 0)
	{
		nSrcX -= nXDest;
		nWidth += nXDest;
		nXDest=0;
	}
	if(nYDest < 0)
	{
		nSrcY -= nYDest;
		nHeight += nYDest;
		nYDest=0;
	}
	if(nSrcX < 0)
	{
		nXDest -= nSrcX;
		nWidth += nSrcX;
		nSrcX=0;
	}
	if(nSrcY < 0)
	{
		nYDest -= nSrcY;
		nHeight += nSrcY;
		nSrcY=0;
	}
	nWidth = nXDest+nWidth > width ? width-nXDest : nWidth ; 
	nHeight = nYDest+nHeight > height ? height-nYDest : nHeight;

	nWidth  = nSrcX+nWidth > dibSrc.width ? dibSrc.width-nSrcX : nWidth;
	nHeight = nSrcY+nHeight > dibSrc.height? dibSrc.height-nSrcY : nHeight;

	nWidth  = std::max(0,nWidth);
	nHeight = std::max(0,nHeight);
    int i,k,l,j;
    unsigned char *srcPtr,*destPtr;
	if(!colors)
	{
		for(i=0,k=nSrcY,l=nYDest; i < nHeight; i++,k++,l++)
		{
			if(k < 0 || l < 0)
			{
				continue;
			}
			else
			{
				srcPtr = dibSrc.GetLinePtr(k);
				destPtr = GetLinePtr(l);
				memcpy(destPtr+nXDest,srcPtr+nSrcX,nWidth);
			}
		}
	}
	else
	{
		for(i=0,k=nSrcY,l=nYDest; i < nHeight; i++,k++,l++)
		{
			if(k < 0 || l < 0)
			{
				continue;
			}
			else
			{
				srcPtr = dibSrc.GetLinePtr(k)+nXDest;
				destPtr = GetLinePtr(l)+nSrcX;
				for(j=0; j < nWidth; j++,srcPtr++,destPtr++)
				{
					if(colors[*srcPtr]) *destPtr=*srcPtr;
				}
			}
		}
	}
}

unsigned char *DIB::GetLinePtr(int line)
{
	return m_pLinePtr[line];
}
	
BOOL DIB::CopyDIB(DIB& DIB)
{
	if(Create(DIB.m_pInfo->bmiHeader))
	{
		SetPalette(DIB.m_pRGB);
		memcpy(m_pBits,DIB.m_pBits,height*bytes);
		return TRUE;
	}
	return FALSE;
}

void DIB::ReplaceColor(unsigned char oldColor,unsigned char newColor)
{
int i,j;
unsigned char *ptr;	
	for(i=0; i < height; i++)
	{
		ptr = GetLinePtr(i);
		for(j=0; j < width; j++)
		{
			if(ptr[j] == oldColor) ptr[j] = newColor;
		}
	}
}


DIB& DIB::operator=(DIB& DIB)
{
	CopyDIB(DIB);
	return *this;
}

HANDLE DIB::GetDIBits(int nStartX,int nStartY,int nCx,int nCy)
{
	if(nStartX == -1)
	{
		nStartX = nStartY=0;
		nCx = width;
		nCy = height;
		DIB DIB;
		DIB.Create(nCx,nCy,8);
		DIB.BitBlt(0,0,nCx,nCy,*this,0,0);
		DIB.SetPalette(m_pRGB);
		return DIB.DIBHandle();
	}
	return DIBHandle();
}

DWORD DIB::GetDIBSize()
{
	return sizeof(BITMAPINFOHEADER) + sizeof(RGBQUAD)*GetPaletteSize() + bytes*height;
}

HANDLE DIB::DIBHandle()
{
    int nSize;
    HANDLE hMem;
	nSize = sizeof(BITMAPINFOHEADER) + sizeof(RGBQUAD)*GetPaletteSize() + bytes*height;
	hMem = GlobalAlloc(GMEM_DDESHARE | GMEM_MOVEABLE,nSize);
	if(hMem  == NULL) 
        return NULL;

    UCHAR *lpVoid,*pBits;
    LPBITMAPINFOHEADER pHead;
    RGBQUAD *pRgb;
	lpVoid = (UCHAR *)GlobalLock(hMem);
	pHead = (LPBITMAPINFOHEADER )lpVoid;

	memcpy(pHead,&m_pInfo->bmiHeader,sizeof(BITMAPINFOHEADER));
	pRgb = (RGBQUAD *)(lpVoid + sizeof(BITMAPINFOHEADER) );
	memcpy(pRgb,m_pRGB,sizeof(RGBQUAD)*GetPaletteSize());
	pBits = lpVoid + sizeof(BITMAPINFOHEADER) + sizeof(RGBQUAD)*GetPaletteSize();
	memcpy(pBits,m_pBits,height*bytes);
	GlobalUnlock(lpVoid);

	return hMem;
}

BOOL DIB::CreateFromHandle(HANDLE hMem,int bits)
{
	DestroyDIB();
    UCHAR *lpVoid,*pBits;
    LPBITMAPINFOHEADER pHead;
    RGBQUAD *pRgb;
	lpVoid = (UCHAR *)GlobalLock(hMem);
	pHead = (LPBITMAPINFOHEADER )lpVoid;
	width = pHead->biWidth;
	height = pHead->biHeight;
	m_nBits = pHead->biBitCount;

	if( pHead->biCompression != BI_RGB) 
	{
		GlobalUnlock(lpVoid);
		return FALSE;
	}
	if(pHead->biBitCount >= 15)
	{
		if(pHead->biBitCount != 24) 
		{
			GlobalUnlock(lpVoid);
			return FALSE;
		}
	}
	if(!Create(*pHead))
	{
		GlobalUnlock(lpVoid);
		return FALSE;
	}
	pRgb = (RGBQUAD *)(lpVoid + sizeof(BITMAPINFOHEADER) );
	memcpy(m_pRGB,pRgb,sizeof(RGBQUAD)*GetPaletteSize());
	pBits = lpVoid + sizeof(BITMAPINFOHEADER) + sizeof(RGBQUAD)*GetPaletteSize();
	memcpy(m_pBits,pBits,height*bytes);
	GlobalUnlock(lpVoid);
	return TRUE;
}

void DIB::UseGamma(float fg,BOOL bUse)
{
	m_bUseGamma = bUse;
	m_fOldGamma = m_fGamma;
	m_fGamma = fg;
	CreateGammaCurve();
}


void DIB::CreateGammaCurve()
{
    int i;
	for(i=0;i<256;++i)
	{
	    Gamma[i]=(int)(255 * pow((float)((double)i/255),(float)m_fGamma) + (double)0.5);
	}
}



void DIB::GetPixel(UINT x,UINT y,int& pixel)
{
	assert(x < (UINT)Width());
	assert(y < (UINT)Height());
	if(x >= (UINT)Width()) return;
	if(y >= (UINT)Height()) return;
	pixel=(GetLinePtr(y))[x];
}

BOOL DIB::Make8Bit(DIB& DIB)
{
    int nBits;	
	assert(Width() == DIB.Width());
	assert(Height() == DIB.Height());
	nBits = DIB.GetBitCount();
	switch(nBits)
	{
	case 1:
		return SwitchFromOne(DIB);
		break;
	case 4:
		return SwitchFromFour(DIB);
		break;
	case 8:
		return SwitchPalette(DIB);
		break;
	case 24:
		return SwitchFrom24(DIB);
		break;
	default:
		return FALSE;
	}
	return FALSE;
}

BOOL DIB::SwitchFromOne(DIB& DIB)
{
    int i,j,w,h;
    unsigned char *sPtr,*dPtr;
    unsigned char cols[2];
	w = Width();
	h = Height();
	memset(CachePtr,0,sizeof(CachePtr));
	cols[0]=ClosestColor(DIB.m_pRGB);
	cols[1]=ClosestColor(DIB.m_pRGB+1);
	for(i=0; i < h; i++)
	{
		dPtr = GetLinePtr(i);
		sPtr = DIB.GetLinePtr(i);
		for(j=0 ; j < w; j++,dPtr++)
		{
			if(!(sPtr[j>>3] & masktable[j&7])) *dPtr = cols[0];
			else *dPtr = cols[1];
		}
	}
	return TRUE;
}

BOOL DIB::SwitchFromFour(DIB& DIB)
{
    int i,n,j,w,h;
    unsigned char *sPtr,*dPtr;
    unsigned char cols[16];
	w = Width();
	h = Height();
	memset(CachePtr,0,sizeof(CachePtr));
	for(i=0; i < 16; i++)
	{
		cols[i]=ClosestColor(DIB.m_pRGB+i);
	}
	for(i=0; i < h; i++)
	{
		dPtr = GetLinePtr(i);
		sPtr = DIB.GetLinePtr(i);
		for(j=0 ; j < w; j++,dPtr++)
		{
			if(!(j&1)) n = (*sPtr & 0xf0)>>4;
			else 
			{
				n = *sPtr & 0x0f;
				sPtr++;
			}
			*dPtr = cols[n];
		}
	}
	return TRUE;
}

BOOL DIB::SwitchPalette(DIB& DIB)
{
    int i,j,w,h;
    unsigned char *sPtr,*dPtr;
    unsigned char cols[256];
	w = Width();
	h = Height();
	memset(CachePtr,0,sizeof(CachePtr));
	for(i=0; i < 256; i++)
	{
		cols[i]=ClosestColor(DIB.m_pRGB+i);
	}
	for(i=0; i < h; i++)
	{
		dPtr = GetLinePtr(i);
		sPtr = DIB.GetLinePtr(i);
		for(j=0 ; j < w; j++,sPtr++,dPtr++)
		{
			*dPtr = cols[*sPtr];
		}
	}
	return TRUE;
}


int DIB::ClosestColor(RGBQUAD *pRgb)
{
    unsigned int dist=BIG_DISTANCE,i,d,c;
    RGBQUAD *pQuad=m_pRGB;
    unsigned int pSize=GetPaletteSize();
	for(i=0; i < pSize;i++)
	{
		if(CachePtr[i])
		{
			if(!memcmp((void *)&CacheQuad[i],(void *)pRgb,3)) 
			{
				return i;
			}
		}
	}
	for(i=0; i < pSize; i++,pQuad++)
	{
		d = Distance(*pRgb,*pQuad);
		if(!d) 
		{
			CacheQuad[i]=*pRgb;
			CachePtr[i]=1;
			return i;
		}		
		if(dist > d) 
		{
			c = i;
			dist = d;
		}
	}
	CacheQuad[c]=*pRgb;
	CachePtr[c]=1;
	return c;
}

unsigned int DIB::Distance(RGBQUAD& rgb1,RGBQUAD& rgb2)
{
    unsigned int d;
	d =  3*(unsigned)((rgb1.rgbRed)-(rgb2.rgbRed))*(unsigned)((rgb1.rgbRed)-(rgb2.rgbRed));
	d += 4*(unsigned)((rgb1.rgbGreen)-(rgb2.rgbGreen))*(unsigned)((rgb1.rgbGreen)-(rgb2.rgbGreen)) ;
	d += 2*(unsigned)((rgb1.rgbBlue)-(rgb2.rgbBlue))*(unsigned)((rgb1.rgbBlue)-(rgb2.rgbBlue));
	return d;
}

BOOL DIB::OpenDIB(mol::string& csFileName)
{
	if(OpenBMP(csFileName)) 
        return TRUE;
	return FALSE;
}



BOOL DIB::SaveDIB(mol::string& csFileName,BitmapType type)
{
	switch(type)
	{
	case BMP:
			return SaveBMP(csFileName);
	default:
			return FALSE;
	}
	return FALSE;
}

BOOL DIB::SaveBMP(mol::string& location)
{
	BITMAPFILEHEADER bFile;

	std::ofstream of;
	of.open(location.c_str(),std::ios::binary);
	if ( !of.good() )
	{
		return FALSE;
	}

	::ZeroMemory(&bFile,sizeof(bFile));
	memcpy((void *)&bFile.bfType,"BM",2);

	bFile.bfSize = GetDIBSize() + sizeof(bFile);
	bFile.bfOffBits = sizeof(BITMAPINFOHEADER) + GetPaletteSize()*sizeof(RGBQUAD) + sizeof(BITMAPFILEHEADER);

	of.write((char*)&bFile,sizeof(bFile));
	of.write((char*)m_pVoid,GetDIBSize());
	of.close();

	return TRUE;
}

BOOL DIB::OpenBMP(mol::string& path)
{
	BITMAPFILEHEADER bFile;
	BITMAPINFOHEADER head;

	std::ifstream in;
	in.open( path.c_str(), std::ios::binary );

    mol::string s;
    if ( in.good() )
    {
		unsigned int toRead = sizeof(bFile);
		in.read( (char*)&bFile, toRead);
		if ( (in.gcount() != toRead) || (memcmp((void *)&bFile.bfType,"BM",2)) )
		{
			in.close();
			return FALSE;
		}
		toRead = sizeof(head);
		in.read( (char*)&head,toRead);
		if(!Create(head))
		{
			in.close();
			return FALSE;
		}

		in.read((char*)m_pRGB,sizeof(RGBQUAD)*GetPaletteSize());
		in.seekg(bFile.bfOffBits,std::ios_base::beg);
		in.read((char*)m_pBits,height*bytes);
		in.close();

		return TRUE;
	}
	return FALSE;
}


int DIB::CountColors()
{
	assert(GetBitCount()==8);
    BYTE colors[256],*ptr;
    int nNum=0,i,j,w,d;
	w = Width();
	d = Height();
	memset(colors,0,256);
	for(i=0; i < d; i++)
	{
		ptr = GetLinePtr(i);
		for(j=0; j < w; j++,ptr++)
		{
			if(!colors[*ptr])
			{
				colors[*ptr]=1;
				nNum++;
			}
		}
	}
	return nNum;
}

int DIB::EnumColors(BYTE *array)
{
	assert(GetBitCount()==8);
    BYTE *ptr;
    int nNum=0,i,j,w,d;
	w = Width();
	d = Height();
	memset(array,0,256);
	for(i=0; i < d; i++)
	{
		ptr = GetLinePtr(i);
		for(j=0; j < w; j++,ptr++)
		{
			if(!array[*ptr])
			{
				array[*ptr]=1;
				nNum++;
			}
		}
	}
	return nNum;
}

COLORREF DIB::PaletteColor(int nIndex)
{
	assert(nIndex < 256);
    RGBQUAD *pRGB= m_pRGB+nIndex;
	return RGB(pRGB->rgbRed,pRGB->rgbGreen,pRGB->rgbBlue);
}

BOOL DIB::SwitchFrom24(DIB& DIB)
{
    int i,j,w,h,c;
    unsigned char *sPtr,*dPtr;
    BYTE *index_ptr=NULL;
    RGBQUAD rgb;
	w = Width();
	h = Height();
	index_ptr = (BYTE *)malloc(0x7FFF+1);
	if(!index_ptr) return FALSE;
	memset(CachePtr,0,sizeof(CachePtr));
	for(i=0; i <= 0x7FFF; i++)
	{
		rgb.rgbRed = (((i & 0x7C00)>>10) << 3) | 0x07;
		rgb.rgbGreen = (((i & 0x3e0)>>5) << 3) | 0x07;
		rgb.rgbBlue = ((i & 0x1F)<<3) | 0x07;
		index_ptr[i] = ClosestColor(&rgb);
	}
	for(i=0; i < h; i++)
	{
		dPtr = GetLinePtr(i);
		sPtr = DIB.GetLinePtr(i);
		for(j=0 ; j < w; j++,dPtr++,sPtr+=3)
		{
			c = (*sPtr >> 3) | ((*(sPtr+1) >> 3) << 5) | ((*(sPtr+2) >> 3) << 10);
			*dPtr = index_ptr[c];
		}
	}
	free(index_ptr);
	return TRUE;
}
*/

} // end namespace mol::win
} // end namespace mol

