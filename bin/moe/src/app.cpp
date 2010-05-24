#include "stdafx.h"


#include "app.h"
#include "util/regex.h"
#include "ax/scintillax/scintillax_i.c"
#include "ax/shellctrl/shellctrl_i.c"
#include "ax/shellfolder/shellfolder_i.c"
#include "ax/setting/setting_i.c"
#include "moe_i.c"
#include "xmlui.h"



//! Moe specific MDO loop override
int MoeLoop::operator() ( mol::win::AppBase& app )
{
  MSG msg;
  while( ::GetMessage(&msg,0,0,0) )
  {
		// check ioleactive obj accel here
		if ( 
			 moe() && 
			 moe()->activeObject &&
			 moe()->activeObject->TranslateAccelerator(&msg) == S_OK 
			)
			continue;

		if ( !::TranslateMDISysAccel( getMDIClient(app), &msg) )
			doMsg( msg, app );
  }
  return (int)msg.wParam ;
}


MoeApp::MoeApp()
{
	// do not enable extensions by default
	enableExtensions_ = false;

	// call this only if avail (naked IE6 on win2k will not have this)
	const DWORD SET_FEATURE_ON_PROCESS = 0x00000002;
	typedef HRESULT  (__stdcall *CoInternetSetFeatureEnabledImpl)( mol::ie::INTERNETFEATURELIST FeatureEntry, DWORD dwFlags, BOOL fEnable );
	CoInternetSetFeatureEnabledImpl impl = (CoInternetSetFeatureEnabledImpl)mol::dllFunc( _T("urlmon.dll"), _T("CoInternetSetFeatureEnabled"));
	if ( impl )
		impl(mol::ie::FEATURE_LOCALMACHINE_LOCKDOWN, SET_FEATURE_ON_PROCESS, FALSE); 
}

MoeApp::~MoeApp()
{
	ODBGS(">>>>>>>>>>>>>>>>>>>>>>> ~MoeApp <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<");
}

// we override run as we check for extensions before running

int MoeApp::run(const mol::string& cmdline)
{
	// enable extension libs loading ?
	if ( _tcsicmp(cmdline.c_str(), _T("/enable")) == 0 )
	{
		ODBGS("enable extensions");
		enableExtensions_ = true;
	}

	// load GTK and .NET dlls dynamically
	init_extensions_if();

	// std local server startup
	return local_server<MoeLoop>::run(cmdline);
}

// embedded moe currenlty uses default impl

int MoeApp::runEmbedded(const mol::string& cmdline)
{
	::load_codegen_metadata();
	return local_server<MoeLoop>::runEmbedded(cmdline);
}


int MoeApp::runStandalone(const mol::string& cmdline)
{
	//check if moe is running
	mol::punk<IDispatch> m = getActiveInstance<IDispatch>(CLSID_Application);

	if ( m )
	{
		// found running moe instance
		// pass any commandline parameters thru

		openDocsFromCommandLine( m, cmdline );
		mol::disp_invoke(m, 28 );
		return 0;
		
	}

	// standalone

	::load_codegen_metadata();

	ODBGS("MoeApp::createMainWindow()");

	MoeWnd::Instance*			moe = MoeWnd::CreateInstance();

	ODBGS("MoeApp::createMainWindow() end");

	std::string c = mol::tostring(mol::trim(cmdline));
	mol::RegExp rgxp("(\"([^\"]*)\")|([^ ]+)");

	mol::punk<IDispatch> disp(moe);
	openDocsFromCommandLine(disp,cmdline);

	mol::punk<IMoeView> view;
	HRESULT hr = moe->get_View(&view);
	if ( hr == S_OK )
	{
		view->Show();
	}
	view.release();

	return local_server<MoeLoop>::runStandalone(cmdline);
}

// in standalone mode, we first check for a running instance and hand over
// control if any, shutting down afterwards. if we are the only instance
// we finally create the main window instance and check the commandline 
// for files to be opened (explorer integration)
// 

// lesson learned: in regfree com we cannot marshal our own interfaces
// because we havent registered them to COM
// however COM always knows how to marshal IDispatch, which we utilize :-)

void MoeApp::openDocsFromCommandLine( IDispatch* m, mol::string cmdline )
{
	std::string cl = mol::tostring(cmdline);

	mol::RegExp rgxp("(\"([^\"]*)\")|([^ ]+)");
	while ( rgxp.nextMatch( cl ) )
	{
		std::string s = rgxp.subString( cl, 2 );
		if ( s == "" )
		{
			s = rgxp.subString( cl, 3 );
		}

		if ( s.substr(0,4) == "moe:" ) 
		{
			s = s.substr(4);
			if ( mol::Path::isDir(mol::toString(s)) )
			{
				mol::disp_invoke(m, 22, mol::variant(s) );
			}
			else
			{
				mol::disp_invoke(m, 20, mol::variant(s) );
			}
		}
		else if ( s.substr(0,9) == "moe-utf8:" ) 
		{
			s = s.substr(9);
			mol::disp_invoke(m, 21, mol::variant(s) );					
		}
		else if ( s.substr(0,8) == "moe-bin:" ) 
		{
			s = s.substr(8);
			mol::disp_invoke(m, 23, mol::variant(s), mol::variant(true) );					
		}
		else if ( s.substr(0,9) == "moe-html:" ) 
		{
			s = s.substr(9);
			mol::disp_invoke(m, 24, mol::variant(s) );					
		}
		else if ( s.substr(0,8) == "moe-dir:" ) 
		{
			s = s.substr(8);
			if ( !mol::Path::isDir(mol::toString(s)) )
			{
				s = mol::tostring(mol::Path::parentDir(mol::toString(s)));
			}
			mol::disp_invoke(m, 22, mol::variant(s) );					
		}
		else
		{
			if ( mol::Path::isDir(mol::toString(s)) )
			{
				mol::disp_invoke(m, 22, mol::variant(s) );
			}
			else
			{
				mol::disp_invoke(m, 20, mol::variant(s) );
			}
		}
	}
}

/////////////////////////////////////////////////////////////////////////
// initialize  extensions helper
/////////////////////////////////////////////////////////////////////////

void MoeApp::init_extensions_if( )
{
	// .NET

	//NET().start(enableExtensions_);

	// GTK

	if (!enableExtensions_)
		return;

	typedef void (*dynamic_gtk_init)( int , char** );
	dynamic_gtk_init gtk_init = (dynamic_gtk_init)mol::dllFunc( _T("libgtk-win32-2.0-0.dll"), _T("gtk_init"));
	if ( gtk_init )
	{
		gtk_init(0,0);
		ODBGS("GTK+ 2.0 initialized\r\n");
	}

	typedef void (*dynamic_g_thread_init)(void *vtable);
	dynamic_g_thread_init gthread_init = (dynamic_g_thread_init)mol::dllFunc( _T("libgthread-2.0-0.dll"), _T("g_thread_init"));
	if ( gthread_init )
	{
		gthread_init((void*)0);
		ODBGS("GTK+ 2.0 threads initialized\r\n");
	}

}
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
	//::DebugBreak();

	ODBGS(">>>>>>>>>>>>>>>> ENTER MAIN <<<<<<<<<<<<<<<<<<<<<<<<");
	ODBGS("moe startup");
	ODBGS(lpCmdLine);

	int result = 0;
	try {
		result = mol::run<MoeApp>(lpCmdLine);
    }
    catch (mol::X& x)
    {
		ODBGS("<<<<<<<<<<<<<<<< EXCEPTION >>>>>>>>>>>>>>>>>>>>>>>>>>");
        ODBGS(x.what());
		ODBGS(">>>>>>>>>>>>>>>> EXCEPTION <<<<<<<<<<<<<<<<<<<<<<<<");
        return 0;
    }

	ODBGS("moe shutdown");
	ODBGS("<<<<<<<<<<<<<<<< LEAVE MAIN >>>>>>>>>>>>>>>>>>>>>>>>>>");
    return result;
}
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////
