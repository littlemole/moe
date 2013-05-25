#include "stdafx.h"
#include "netserver.h"
#include "nettype.h"
#include "netobj.h"
#include "net_i.c"

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

class NetApp : 

	public mol::local_server<mol::win::Loop>,

	public mol::exports< NetApp, NetServer>,

	public mol::exports< 
					NetApp, 
					NetType, 
					mol::ole::ComCreatePolicy<
									NetApp,
									mol::ole::AggregationPolicyNonAggregable<
													NetType,
													mol::com_obj<NetType> 
												> > >,
	public mol::exports< 
					NetApp, 
					NetObject, 
					mol::ole::ComCreatePolicy<
									NetApp,
									mol::ole::AggregationPolicyNonAggregable<
													NetObject,
													mol::com_obj<NetObject> 
												>  > >
{
public:

	NetApp() {};
};



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
//	::MessageBoxA(0,"startup",".NET",0);

	::CoInitialize(0); // STA for Win32 UI technolgies ...

    try
    {
		{		
			mol::run<NetApp>(lpCmdLine);	
		}

    }
    catch (mol::X& x)
    {
        ::MessageBoxA(0,x.what(),"error",0);
        return 1;
    }
	::CoUninitialize();
    return 0;
}

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////





