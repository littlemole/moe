#include "win/gdiplus.h"

#include "win/app.h"
#include "win/mdi.h"
#include "win/res.h"
#include "win/dlg.h"
#include "win/codlg.h"
#include "win/coctrl.h"
#include "win/core.h"
#include "win/layout.h"
#include "win/shell.h"
#include "win/folder.h"
#include "win/path.h"
#include "win/file.h"



namespace mol {

GdiPlusUser::GdiPlusUser()
{
	gdiplusStartupInput_ = new Gdiplus::GdiplusStartupInput();
	Gdiplus::GdiplusStartup(&gdiplusToken_, gdiplusStartupInput_, NULL);	
}

GdiPlusUser::~GdiPlusUser()
{
	Gdiplus::GdiplusShutdown(gdiplusToken_);
	delete gdiplusStartupInput_;
}

} // end namespace mol


