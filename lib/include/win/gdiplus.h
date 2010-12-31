#ifndef _MOL_DEF_GUARD_GDIPLUS_DEF_GUARD_DEFINE_
#define _MOL_DEF_GUARD_GDIPLUS_DEF_GUARD_DEFINE_

#include "conf.h"

#define min std::min
#define max std::max
#include <gdiplus.h>
#undef min
#undef max

namespace mol {

class GdiPlusUser
{
public:
	GdiPlusUser();
	~GdiPlusUser();

private:
	Gdiplus::GdiplusStartupInput* gdiplusStartupInput_;
	ULONG_PTR           gdiplusToken_;
};



} // end namespace mol




#endif