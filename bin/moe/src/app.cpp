#include "stdafx.h"
#include "app.h"
#include "widgets.h"
#include <regex>
#include "win/v7.h"
#include "mtree.h"
#include "resource.h"
#include "moe_dispid.h"

#include "moe_i.c"
#include "ax/scintillax/scintillax_i.c"
#include "ax/shellctrl/shellctrl_i.c"
#include "ax/setting/setting_i.c"
#include "ax/ssh/ssh_i.c"



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

class moeEditorCliType : public moeCliType
{
public:

	virtual bool open(IDispatch* docs, IDispatch* dialogs, std::string p)
	{
		if ( p.substr(0,4) == "moe:" ) 
		{
			p = p.substr(4);
			if ( mol::Path::isDir(mol::towstring(p)) )
			{
				mol::disp_invoke(docs, DISPID_IMOEDOCUMENTCOLLECTION_OPENDIR , mol::variant(p) );
			}
			else
			{
				mol::disp_invoke(docs, DISPID_IMOEDOCUMENTCOLLECTION_OPEN, mol::variant(p) );
			}
			return true;
		}
		return false;
	}
};

class moeDefaultCliType : public moeCliType
{
public:

	virtual bool open(IDispatch* docs, IDispatch* dialogs, std::string p)
	{
		p = resolvePath(p);
		if ( p.empty() )
			return true;

		if ( mol::Path::isDir(mol::towstring(p)) )
		{
			mol::disp_invoke(docs, DISPID_IMOEDOCUMENTCOLLECTION_OPENDIR, mol::variant(p) );
		}
		else
		{
			mol::disp_invoke(docs, DISPID_IMOEDOCUMENTCOLLECTION_OPEN, mol::variant(p) );
		}
		return true;
	}
};

class moeOpenCliType : public moeCliType
{
public:

	virtual bool open(IDispatch* docs, IDispatch* dialogs, std::string p)
	{
		if ( p.substr(0,9) == "moe-open:" ) 
		{
			mol::disp_invoke(dialogs, DISPID_IMOEDIALOGS_OPEN, mol::variant(p.substr(9)) );					
			return true;
		}
		return false;
	}
};


class moeBinCliType : public moeCliType
{
public:

	virtual bool open(IDispatch* docs, IDispatch* dialogs, std::string p)
	{
		if ( p.substr(0,8) == "moe-bin:" ) 
		{
			p = p.substr(8);
			mol::disp_invoke(docs, DISPID_IMOEDOCUMENTCOLLECTION_OPENHEXEDITOR, mol::variant(p), mol::variant(true) );					
			return true;
		}
		return false;
	}
};


class moeHtmlCliType : public moeCliType
{
public:

	virtual bool open(IDispatch* docs, IDispatch* dialogs, std::string p)
	{
		if ( p.substr(0,9) == "moe-html:" ) 
		{
			p = p.substr(9);
			mol::disp_invoke(docs, DISPID_IMOEDOCUMENTCOLLECTION_OPENHTMLFRAME, mol::variant(p) );					
			return true;
		}
		return false;
	}
};



class moeDirCliType : public moeCliType
{
public:

	virtual bool open(IDispatch* docs, IDispatch* dialogs, std::string p)
	{
		if ( p.substr(0,8) == "moe-dir:" ) 
		{
			p = p.substr(8);
			if ( !mol::Path::isDir(mol::towstring(p)) )
			{
				p = mol::tostring(mol::Path::parentDir(mol::towstring(p)));
			}
			mol::disp_invoke(docs, DISPID_IMOEDOCUMENTCOLLECTION_OPENDIR, mol::variant(p) );					
			return true;
		}
		return false;
	}
};



class moeTailCliType : public moeCliType
{
public:

	virtual bool open(IDispatch* docs, IDispatch* dialogs, std::string p)
	{
		if ( p.substr(0,9) == "moe-tail:" ) 
		{
			p = p.substr(9);
			mol::disp_invoke(docs, DISPID_IMOEDOCUMENTCOLLECTION_OPENTAILDOCUMENT, mol::variant(p) );					
			return true;
		}
		return false;
	}
};



class moeHexCliType : public moeCliType
{
public:

	virtual bool open(IDispatch* docs, IDispatch* dialogs, std::string p)
	{
		if ( p.substr(0,8) == "moe-hex:" ) 
		{
			p = p.substr(8);
			mol::disp_invoke(docs, DISPID_IMOEDOCUMENTCOLLECTION_OPENHEXEDITOR, mol::variant(p), mol::variant(true) );					
			return true;
		}
		return false;
	}
};



class moeRtfCliType : public moeCliType
{
public:

	virtual bool open(IDispatch* docs, IDispatch* dialogs, std::string p)
	{
		if ( p.substr(0,8) == "moe-rtf:" ) 
		{
			p = p.substr(8);
			mol::disp_invoke(docs, DISPID_IMOEDOCUMENTCOLLECTION_OPENRTFDOCUMENT, mol::variant(p) );					
			return true;
		}
		return false;
	}
};




class moeSshCliType : public moeCliType
{
public:

	virtual bool open(IDispatch* docs, IDispatch* dialogs, std::string p)
	{
		if ( p.substr(0,8) == "moe-ssh:" ) 
		{
			p = p.substr(4);
			mol::disp_invoke(docs, DISPID_IMOEDOCUMENTCOLLECTION_OPEN, mol::variant(p) );					
			return true;
		}
		return false;
	}
};


MoeApp::MoeApp()
{
	// unlock embedded IE restrictions
	mol::v7::unlockInternetExplorer();

	// CLI support
	moeCliTypes.push_back( new moeEditorCliType );
	moeCliTypes.push_back( new moeOpenCliType );
	moeCliTypes.push_back( new moeBinCliType );
	moeCliTypes.push_back( new moeHtmlCliType );
	moeCliTypes.push_back( new moeDirCliType );
	moeCliTypes.push_back( new moeTailCliType );
	moeCliTypes.push_back( new moeHexCliType );
	moeCliTypes.push_back( new moeRtfCliType );
	moeCliTypes.push_back( new moeSshCliType );
	moeCliTypes.push_back( new moeDefaultCliType );

	log().level(LOGINFO);

	std::wstring appPath = CreateAppPath(_T("moe"));
	std::wstring logPath = appPath + _T("\\moe.log");
	log().add( new FileAppender(mol::tostring(logPath)) );

}

MoeApp::~MoeApp()
{
	//moeConsole().shutdown();
	mol::purge(moeCliTypes);
	ODBGS(">>>>>>>>>>>>>>>>>>>>>>> ~MoeApp <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<");
}

void load_resources()
{
	using namespace mol;

	UI().addCmd(IDM_TAB, _T("TAB"));
	UI().addCmd(IDM_TAB_CLOSETAB, _T("Close"));
	UI().addCmd(IDM_TAB_CLOSEALLBUTTHIS, _T("Close Others"));
	UI().addCmd(IDM_TAB_RELOADTAB, _T("Reload"));
	UI().addCmd(IDM_TAB_SAVETAB, _T("Save"));
	UI().addCmd(IDM_TAB_DIRTAB, _T("Directory"));
	UI().addCmd(IDM_VIEW_CLOSE, _T("Close"));
	UI().addCmd(IDM_VIEW_CLOSEALL, _T("Close All"));
	UI().addCmd(IDM_FILE_SAVE, _T("Save"));

	/*
	UI().addMenu(IDM_MENU_TAB);

	UI().addSubMenu(IDM_MENU_TAB, IDM_MENU_TAB, IDM_TAB);
	UI().addMenuItem(IDM_MENU_TAB, IDM_TAB, IDM_VIEW_CLOSE, IDB_TOOLBAR, IDM_VIEW_CLOSE, false, true);
	UI().addMenuItem(IDM_MENU_TAB, IDM_TAB, IDM_TAB_CLOSEALLBUTTHIS, IDB_TOOLBAR, IDM_TAB_CLOSEALLBUTTHIS, false, true);
	UI().addMenuSeparator(IDM_MENU_TAB, IDM_TAB);
	UI().addMenuItem(IDM_MENU_TAB, IDM_TAB, IDM_TAB_RELOADTAB, IDB_TOOLBAR, IDM_TAB_RELOADTAB, false, true);
	UI().addMenuItem(IDM_MENU_TAB, IDM_TAB, IDM_FILE_SAVE, IDB_TOOLBAR, IDM_FILE_SAVE, false, true);
	UI().addMenuSeparator(IDM_MENU_TAB, IDM_TAB);
	UI().addMenuItem(IDM_MENU_TAB, IDM_TAB, IDM_TAB_DIRTAB, IDB_TOOLBAR, IDM_TAB_DIRTAB, false, true);
	*/
	//foreach bitmap - loads and registers bitmap
	  // optionally associate cmds to toolbar icons on bitmap

	UI().addBmp(IDB_MOE_FAV);

	UI().addBmp(IDB_MOE_GO);

	UI().addBmp(IDB_DEBUG_GO);

	UI().addBmp(IDB_DEBUG_PAUSE);

	UI().addBmp(IDB_DEBUG_QUIT);

	UI().addBmp(IDB_DEBUG_STEPIN);

	UI().addBmp(IDB_DEBUG_STEPOVER);

	UI().addBmp(IDB_DEBUG_STEPOUT);
	/*
	UI().addBmp(IDB_TOOLBAR);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_FILE_NEW);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_FILE_OPEN);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_FILE_OPEN_FOLDER);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_FILE_SAVE);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_FILE_SAVE_AS);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_FILE_PRINT);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_FILE_EXIT);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_EDIT_UNDO);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_EDIT_REDO);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_EDIT_CUT);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_EDIT_COPY);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_EDIT_PASTE);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_EDIT_FIND);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_EDIT_REPLACE);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_EDIT_EXECUTESCRIPT);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_MODE_EXECUTEFORM);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_USER_SCRIPT);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_USER_BATCH);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_USER_FORM);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_USER_SHORTCUT);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_EDIT_COLOR);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_MODE_EOL);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_MODE_LANGUAGE);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_MODE_SETTINGS);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_MODE_PREFERENCES);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_MODE_EDITSETTINGS);
	UI().addBmpCmd(IDB_TOOLBAR, -1);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_TAB_CLOSEALLBUTTHIS);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_VIEW_MAXIMIZE);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_VIEW_MINIMIZE);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_VIEW_CASCADE);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_VIEW_TILE);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_VIEW_NEXT);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_TAB_RELOADTAB);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_TAB_DIRTAB);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_VIEW_WINDOWS);
	UI().addBmpCmd(IDB_TOOLBAR, -1);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_HELP_ABOUT);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_VIEW_CLOSE);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_VIEW_CLOSEALL);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_FILE_OPEN_HTML);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_VIEW_TOOLBARS);
	UI().addBmpCmd(IDB_TOOLBAR, -1);
	UI().addBmpCmd(IDB_TOOLBAR, -1);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_EDIT_DEBUG);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_EDIT_DEBUG_QUIT);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_EDIT_DEBUG_STEPIN);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_EDIT_DEBUG_STEPOUT);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_EDIT_DEBUG_STEPOVER);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_EDIT_DEBUG_STOP);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_EDIT_DEBUG_GO);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_FILE_NEW_RTF);
	UI().addBmpCmd(IDB_TOOLBAR, IDM_EDIT_PASTEAS);
*/
}

// embedded moe 
int MoeApp::runEmbedded(const std::wstring& cmdline)
{
	// load the generated metadata
	//::load_codegen_metadata();
	load_resources();
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

int MoeApp::runStandalone(const std::wstring& cmdline)
{
	//check if moe is running
	mol::punk<IDispatch> m = getActiveInstance<IDispatch>(CLSID_Application);

	if ( m )
	{
		// found running moe instance
		// pass any commandline parameters thru

		openDocsFromCommandLine( m, cmdline );
		return 0;		
	}

	// load the generated metadata
	//::load_codegen_metadata();
	load_resources();


	MoeWnd::Instance* moe = MoeWnd::CreateInstance();

	// open any filepaths passed via command line using IDispatch
	mol::punk<IDispatch> disp(moe);
	openDocsFromCommandLine(disp,cmdline);

	// bring moe to front
	mol::punk<IMoeView> view;
	HRESULT hr = moe->get_View(&view);
	if ( hr == S_OK )
	{
		view->Show();
	}
	view.release();

	return local_server<MoeLoop>::runStandalone(cmdline);
}



void MoeApp::openDocsFromCommandLine( IDispatch* moe, std::wstring cmdline )
{
	std::string cl = mol::toUTF8(cmdline);

	mol::variant v;
	HRESULT hr = mol::get( moe, DISPID_IMOE_DOCUMENTS, &v);
	if ( hr != S_OK )
		return;

	mol::punk<IDispatch> dispDoc(v.pdispVal);
	if (!dispDoc )
		return;

	mol::variant dialogs;
	hr = mol::get( moe, DISPID_IMOE_DIALOGS, &dialogs);
	if ( hr != S_OK )
		return;

	mol::variant view;
	hr = mol::get( moe, DISPID_IMOE_VIEW, &view);
	if ( hr != S_OK )
		return;

	mol::disp_invoke( view.pdispVal, DISPID_IMOEVIEW_SHOW );

	::CoAllowSetForegroundWindow(moe,0);

	std::regex rgxp("(\"([^\"]*)\")|([^ ]+)");
	std::smatch m;
	std::string::const_iterator searchStart( cl.cbegin() );
	while ( regex_search( searchStart, cl.cend(), m, rgxp ) )
	{
		std::string s = m[2];
		if ( s == "" )
		{
			s = m[3];
		}

		openMoeDocument(dispDoc,dialogs.pdispVal,s);	

 		searchStart += m.position() + m.length();	
	}
}


void MoeApp::openMoeDocument(IDispatch* docs, IDispatch* dialogs,const std::string& s) 
{
	for( size_t i = 0; i < moeCliTypes.size(); i++)
	{
		moeCliType* t = moeCliTypes[i];
		if ( t->open(docs,dialogs,s) )
		{
			return;
		}
	}
}


/////////////////////////////////////////////////////////////////////////
// initialize  extensions helper
/////////////////////////////////////////////////////////////////////////
/*
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
*/
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

	// early init codepages
	const mol::CodePages& cp = mol::CodePages::instance();

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
