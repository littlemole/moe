#include "stdafx.h"
#include "jreserver.h"


//#include "ole/dll.h"

#include "jre_i.c"
//#include "../../lib/src/java/java_i.c"


/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
// main entry point of moe app
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	ODBGS("JRE startup");
	ODBGS(lpCmdLine);

	//::DebugBreak();
	//::MessageBoxA(0,"startup","JRE",0);
	::CoInitializeEx(0,COINIT_MULTITHREADED);

    try
    {
		//CoInitialize(0);
		mol::run<JREApp>(lpCmdLine);	
    }
    catch (mol::X& x)
    {
        ::MessageBoxA(0,x.what(),"error",0);
		::CoUninitialize();
        return 1;
    }
	::CoUninitialize();
    return 0;
}

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////





