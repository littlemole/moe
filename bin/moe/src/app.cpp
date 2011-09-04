#include "stdafx.h"
#include "app.h"
#include "util/regex.h"
#include "thread/sync.h"
#include "xmlui.h"
#include "moe_dispid.h"

#include "moe_i.c"
#include "ax/scintillax/scintillax_i.c"
#include "ax/shellctrl/shellctrl_i.c"
#include "ax/shellfolder/shellfolder_i.c"
#include "ax/setting/setting_i.c"

/*
#define min std::min
#define max std::max
#include <gdiplus.h>
*/

//! Moe specific MDI message loop override
int MoeLoop::operator() ( mol::win::AppBase& app )
{
  MSG msg;

  while(true)
  {
  	    DWORD r = ::MsgWaitForMultipleObjectsEx(0,0,INFINITE,QS_ALLINPUT,MWMO_INPUTAVAILABLE|MWMO_ALERTABLE);
		if ( r == WAIT_IO_COMPLETION ) 
		{
			continue;
		}

		if (!::GetMessage(&msg,0,0,0)) 
		{
			break;
        }

		// check ioleactive obj accel here
		if ( 
				moe() && 
				moe()->activeObject &&
				moe()->activeObject->TranslateAccelerator(&msg) == S_OK 
			)
			continue;

		if (!::TranslateMDISysAccel( mol::win::mdiClient(), &msg) )
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

// embedded moe 
int MoeApp::runEmbedded(const mol::string& cmdline)
{
	::load_codegen_metadata();
	return local_server<MoeLoop>::runEmbedded(cmdline);
}

// in standalone mode, we first check for a running instance and hand over
// control if any, shutting down afterwards. if we are the only instance
// we finally create the main window instance and check the commandline 
// for files to be opened (explorer integration)
// 

// lesson learned: in regfree com we cannot marshal our own interfaces
// because we havent registered them to COM
// however COM always knows how to marshal IDispatch, which we utilize :-)

int MoeApp::runStandalone(const mol::string& cmdline)
{
	//check if moe is running
	mol::punk<IDispatch> m = getActiveInstance<IDispatch>(CLSID_Application);

	if ( m )
	{
		// found running moe instance
		// pass any commandline parameters thru

		openDocsFromCommandLine( m, cmdline );
		//mol::disp_invoke(m, 28 );
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


std::string resolvePath(const std::string& p)
{
	if ( mol::Path::exists(mol::toString(p)) )
	{
		return p;
	}

	std::ostringstream oss;
	for ( size_t i = 0; i < p.size(); i++ ) 
	{
		if ( p[i] == '/' )
			oss << '\\';
		else
			oss << p[i];
	}

	std::vector<std::string> v = mol::split( oss.str(), "\\" );

	std::vector<std::string> v2;
	if ( !v.empty() )
		v2.push_back(v[0]);

	for ( size_t i = 1; i < v.size(); i++ )
	{
		if ( i < v.size()-1 && v[i+1] == ".." )
		{
			continue;
		}
		if ( v[i] == ".." )
		{
			continue;
		}

		if ( v[i] == "." ) 
		{
			continue;
		}
		if ( v[i] == "" ) 
		{
			continue;
		}

		v2.push_back(v[i]);
	}

	std::ostringstream oss2;
	if ( !v2.empty() )
	{
		oss2 << v2[0];
	}
	for ( size_t i = 1; i < v2.size(); i++ )
	{
		oss2 << "\\" << v2[i];
	}

	std::string s = oss2.str();

	const std::string cygdrive("\\cygdrive\\");

	size_t pos = s.find(cygdrive);
	if ( pos == 0 )
	{
		return s.substr(cygdrive.size(),1) + ":\\" + s.substr(cygdrive.size()+2);
	}

	if ( mol::Path::exists(mol::toString(s)) )
	{
		return s;
	}

	char buf[MAX_PATH];
	::GetCurrentDirectoryA(MAX_PATH,buf);

	std::ostringstream oss3;
	oss3 << buf << "\\" << s;

	std::string path = oss3.str();
	if ( mol::Path::exists(mol::toString(path)) )
	{
		return path;
	}
	return "";
}

void MoeApp::openDocsFromCommandLine( IDispatch* moe, mol::string cmdline )
{
	std::string cl = mol::tostring(cmdline);

	mol::variant v;
	HRESULT hr = mol::get( moe, DISPID_IMOE_DOCUMENTS, &v);
	if ( hr != S_OK )
		return;

	mol::punk<IDispatch> m(v.pdispVal);
	if (!m )
		return;

	::CoAllowSetForegroundWindow(moe,0);

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
				mol::disp_invoke(m, DISPID_IMOEDOCUMENTCOLLECTION_OPENDIR , mol::variant(s) );
			}
			else
			{
				mol::disp_invoke(m, DISPID_IMOEDOCUMENTCOLLECTION_OPEN, mol::variant(s) );
			}
		}
		else if ( s.substr(0,9) == "moe-utf8:" ) 
		{
			s = s.substr(9);
			mol::disp_invoke(m, DISPID_IMOEDOCUMENTCOLLECTION_OPENUTF8, mol::variant(s) );					
		}
		else if ( s.substr(0,8) == "moe-bin:" ) 
		{
			s = s.substr(8);
			mol::disp_invoke(m, DISPID_IMOEDOCUMENTCOLLECTION_OPENHEXEDITOR, mol::variant(s), mol::variant(true) );					
		}
		else if ( s.substr(0,9) == "moe-html:" ) 
		{
			s = s.substr(9);
			mol::disp_invoke(m, DISPID_IMOEDOCUMENTCOLLECTION_OPENHTMLFRAME, mol::variant(s) );					
		}
		else if ( s.substr(0,8) == "moe-dir:" ) 
		{
			s = s.substr(8);
			if ( !mol::Path::isDir(mol::toString(s)) )
			{
				s = mol::tostring(mol::Path::parentDir(mol::toString(s)));
			}
			mol::disp_invoke(m, DISPID_IMOEDOCUMENTCOLLECTION_OPENDIR, mol::variant(s) );					
		}
		else if ( s.substr(0,9) == "moe-tail:" ) 
		{
			s = s.substr(9);
			mol::disp_invoke(m, DISPID_IMOEDOCUMENTCOLLECTION_OPENTAILDOCUMENT, mol::variant(s) );					
		}
		else
		{
			s = resolvePath(s);
			if ( s.empty() )
				continue;

			if ( mol::Path::isDir(mol::toString(s)) )
			{
				mol::disp_invoke(m, DISPID_IMOEDOCUMENTCOLLECTION_OPENDIR, mol::variant(s) );
			}
			else
			{
				mol::disp_invoke(m, DISPID_IMOEDOCUMENTCOLLECTION_OPEN, mol::variant(s) );
			}
		}
	}

	mol::variant view;
	hr = mol::get( moe, DISPID_IMOE_VIEW, &view);
	if ( hr != S_OK )
		return;

	mol::disp_invoke( view.pdispVal, DISPID_IMOEVIEW_SHOW );
}

/////////////////////////////////////////////////////////////////////////
// initialize  extensions helper
/////////////////////////////////////////////////////////////////////////

void MoeApp::init_extensions_if( )
{

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
