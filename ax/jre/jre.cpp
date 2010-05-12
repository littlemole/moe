#include "stdafx.h"
#include "jreserver.h"


//#include "ole/dll.h"

#include "jre_i.c"



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

//	HRESULT hr;
    try
    {
		// handle registry command line switches

		JREApp jreApp(hInstance);

/*
		// handle registry command line switches
		if ( _stricmp(mol::tostring(lpCmdLine).c_str(),"/regserver") == 0 )
		{
			//::DebugBreak(); 
			ODBGS("registering JRE");
			jreApp.RegisterServer();
			return 0;
		}
		if ( _stricmp(mol::tostring(lpCmdLine).c_str(),"/unregserver") == 0 )
		{
			jreApp.UnregisterServer();
			return 0;
		}

        // embedding
		if ( _stricmp(mol::tostring(lpCmdLine).c_str(),"-Embedding") == 0 )
		{
			// create & register Class Object
			jreApp.RegisterClassObjects(CLSCTX_LOCAL_SERVER );
			//jreApp.jre().createJVM(false);
			jreApp.run();			
			return 0;
		}

        // automation
		if ( _stricmp(mol::tostring(lpCmdLine).c_str(),"-Automation") == 0 )
		{
			// create & register Class Object
			jreApp.RegisterClassObjects(CLSCTX_LOCAL_SERVER );
			//jreApp.jre().createJVM(false);
			jreApp.run();			
			return 0;
		}

		jreApp.RegisterClassObjects(CLSCTX_LOCAL_SERVER );
		//jreApp.jre().createJVM(false);

*/
		jreApp.run(lpCmdLine);	

    }
    catch (mol::X& x)
    {
        ::MessageBox(0,x.what(),_T("error"),0);
        return 1;
    }
    return 0;
}

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////





