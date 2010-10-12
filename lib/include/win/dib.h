#pragma once
#ifndef _MOL_COLOR_DLG_PICKER_DEF_GUARD_
#define _MOL_COLOR_DLG_PICKER_DEF_GUARD_

#include "util/uni.h"

namespace mol {
namespace win {

/*
class DIB 
{
public:
	enum BitmapType
	{
		BMP,
		GIF,
		TIFF
	};

	DIB( HANDLE hDib = NULL, int nBits = 8);
	virtual ~DIB();
	
	DIB& operator=(DIB& DIB);

	BOOL Load(UINT nIdResource);
	BOOL CreateFromHandle(HANDLE hDib,int nBits);
	BOOL Create(int width,int height,int bits=24);
	BOOL Create(BITMAPINFOHEADER& bmInfo);
	BOOL CopyDIB(DIB& DIB);
	BOOL OpenDIB(mol::string& fileName);
	BOOL SaveDIB(mol::string& fileName,BitmapType type);

	void InitDIB(COLORREF color);
	void DestroyDIB();

	BOOL IsValid() { return (m_pVoid && Width() && Height());};


	void	 BitBlt(HDC hDest,int nXDest,int nYDest,int nWidth,int nHeight,int xSrc,int ySrc);
	void	 BitBlt(int nXDest,int nYDest,int nWidth,int nHeight,DIB& dibSrc,int nSrcX,int nSrcY,BYTE *colors=NULL);
	void	 StretchBlt(HDC hDest,int nXDest,int nYDest,int nDWidth,int nDHeight,int xSrc,int ySrc,int  nSWidth,int nSHeight);
	void	 StretchBlt(int nXDest,int nYDest,int nDWidth,int nDHeight,DIB& dibSrc,int xSrc,int ySrc,int  nSWidth,int nSHeight);
	void     ExpandBlt(int nXDest,int nYDest,int xRatio,int yRatio,DIB& dibSrc,int xSrc,int ySrc,int  nSWidth,int nSHeight);


	void     SetPixel(int x,int y,COLORREF color);
	void     SetPixel8(int x,int y,unsigned char color);
	COLORREF GetPixel(int x,int y);
	void     GetPixel(UINT x,UINT y,int& pixel);

	int		 Height() { return height ; };
	int		 Width()  { return width ; };
	LPBITMAPINFO GetBitmapInfo() { return m_pInfo;};
	HBITMAP  GetBitmap();//HDC dc);
	DWORD    GetDIBSize();
	HANDLE   GetDIBits(int nStartX=-1,int nStartY=-1,int nCx=-1,int nCy=-1);

	int      GetPaletteSize(BITMAPINFOHEADER& bmInfo);
	int      GetPaletteSize();
	int      GetBitCount() {return m_pInfo->bmiHeader.biBitCount;};

	void     SetPalette(unsigned char *palette);
	void     SetPalette(RGBQUAD *pRGB);
	COLORREF PaletteColor(int index);

	int      CountColors();
	int      EnumColors(BYTE *colors);	
	int      ClosestColor(RGBQUAD *pRgb);
	void     ReplaceColor(unsigned char oldColor,unsigned char newColor);	
	void     UseGamma(float fg,BOOL bUse=TRUE);
	void     SetFlags(int flag) { m_nFlags = flag; };

	void	 CopyLine(int source,int dest);
	unsigned char *GetLinePtr(int line);	

	BOOL Make8Bit(DIB& DIB);
	BOOL SwitchFromOne(DIB& DIB);
	BOOL SwitchFromFour(DIB& DIB);
	BOOL SwitchFrom24(DIB& DIB);
	BOOL SwitchPalette(DIB& DIB);

	static unsigned int Distance(RGBQUAD& rgb1,RGBQUAD& rgb2);

protected :
	HANDLE DIBHandle();
	BOOL OpenBMP(mol::string& csFileName);
	BOOL OpenGIF(mol::string& csFileName);
	BOOL OpenTIFF(mol::string& csFileName);
	BOOL SaveBMP(mol::string& csFileName);
	BOOL SaveGIF(mol::string& csFileName);
	BOOL SaveTIFF(mol::string& csFileName);
	void Expand(int nXDest,int nYDest,int xRatio,int yRatio,DIB& dibSrc,int xSrc,int ySrc,int  nSWidth,int nSHeight);
	void CreateGammaCurve();
	
	unsigned char *m_pBits;
	PBITMAPINFO    m_pInfo;
	RGBQUAD       *m_pRGB;
	void		  *m_pVoid; 
	BYTE		 **m_pLinePtr;

	int height,bytes,width,m_nBits;
	int m_nFlags;

	BOOL  m_bUseGamma;
	float m_fGamma;
	float m_fOldGamma;

	unsigned char Gamma[256];
	RGBQUAD CacheQuad[256];
	char CachePtr[256];
	HBITMAP bitmap;
};
*/


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