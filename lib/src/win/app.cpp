#include "win/App.h"
#include "win/Res.h"
#include "win/mdi.h"
#include "win/msgloop.h"
#include "util/Str.h"
#include <Shlobj.h>
#include <fstream>
#include "boost/scoped_ptr.hpp"
#include "boost/shared_ptr.hpp"

namespace mol  {


//! global mol::hinstance() - returns the process HINSTANCE
//!

HINSTANCE hinstance()
{
	return mol::App().hinstance();
}

unsigned int guithread()
{ 
	return mol::win::AppBase::guithread_; 
}

namespace win  {

AppBase*				AppBase::app_			= 0;
unsigned int			AppBase::guithread_     = 0;

void AppBase::lock()
{
	return this->Lock();
}



void AppBase::unlock()
{
	return this->UnLock();
}

bool AppBase::locked()
{
	return this->Locked();
}

void AppBase::Lock()
{
	LOCK(mutex_);
	lockCount_++;
	//ODBGS1("app LOCK: ",lockCount_);
}

void AppBase::UnLock()
{
	LOCK(mutex_);
	lockCount_--;	
	//ODBGS1("app UNLOCK: ",lockCount_);
}

bool AppBase::Locked()
{
	LOCK(mutex_);
	//ODBGS1("app count: ",lockCount_);
	return lockCount_ > 0;
}



//! constructor 
AppBase::AppBase()
{
	hInstance_  = ::GetModuleHandle(0);
	lockCount_  = 0;
    app_	    = this;
	guithread_  = mol::Thread::self();
}

AppBase::~AppBase() 
{
}


//! used by mol::hinstance
HINSTANCE AppBase::hinstance()
{
    return hInstance_;
}



mol::string AppBase::CreateAppPath(const mol::string& dir)
{
	mol::TCHAR buff[MAX_PATH];
	::SHGetSpecialFolderPath(0,buff,CSIDL_APPDATA,TRUE);

	mol::string path = buff;
	path += _T("\\");
	path += dir;

	DWORD fa = GetFileAttributes(path.c_str());
	if ( fa != FILE_ATTRIBUTE_DIRECTORY ) 
	{
		BOOL r = ::CreateDirectory(path.c_str(),NULL);
		// might "fail but succeed" thanks to Vista Virtualization!
		// if ( !::CreateDirectory(path.c_str(),NULL) )
        // // throw mol::X("could not create app dir"); 
	}
    return path;
}

mol::string AppBase::UnpackAppFile(const mol::string& file, int id, bool createIf )
{
    if ( createIf == false )
    {
        DWORD fa = GetFileAttributes(file.c_str());
        if ( fa != INVALID_FILE_ATTRIBUTES )
            return file;
    }

	mol::Resource<> res(id);
	std::ofstream os;
		
	os.open(file.c_str(),std::ios::binary);
	if ( !os )
        throw mol::X( _T("could not create app file"));

	os.write(res(),res.size());
	os.close();
    return file;
}

mol::string AppBase::getModulePath()
{
	mol::TCHAR path[2048];
	::GetModuleFileName( mol::hinstance(), path, 2047 );
	path[2047] = 0;
	return path;
}

mol::string AppBase::getAppPath()
{
	mol::TCHAR path[2048];
	::GetModuleFileName( 0, path, 2047 );
	path[2047] = 0;
	return path;
}

//! basic windows msg handling
void LoopBase::doMsg(MSG& msg, AppBase& app)
{
	
	if ( msg.hwnd == NULL )
	{
		if ( (msg.message == WM_INVOKE) && (msg.wParam == 0) )
		{
			boost::shared_ptr<mol::fun::task> task( (mol::fun::task*) (msg.lParam) );
			(*task)();
			return;
		}
	}
	

	if ( dialogs().isDialogMessage(msg) )
	  return;
	if ( accelerators().translate(msg) )
	  return;

	::TranslateMessage(&msg);
	::DispatchMessage(&msg);
}

//! operator() triggers (possibly overided) message loops
int Loop::operator() ( mol::win::AppBase& app )
{
  MSG msg;
  while( ::GetMessage(&msg,0,0,0) )
  {
    doMsg( msg, app );
  }
  return (int)msg.wParam ;
}

//! MDI specific loop
int MdiLoop::operator() ( mol::win::AppBase& app )
{
  MSG msg;
  while( ::GetMessage(&msg,0,0,0) )
  {
	  if ( !::TranslateMDISysAccel( mol::win::mdiClient(), &msg) )
      doMsg( msg, app );
  }
  return (int)msg.wParam ;
}

//! for directx fun etc
int ActiveLoop::operator() ( mol::win::AppBase& app )
{
  MSG msg;
  while( true )
  {
    if (::PeekMessage( &msg, NULL,0,0,PM_REMOVE))
    {
      if ( msg.message == WM_QUIT )
        break;
      if ( msg.message != WM_PAINT )
	      doMsg( msg, app );
    }
    app.idle( msg );
  }
  return (int)msg.wParam ;
}

} // end namespace mol::win

void pumpMessages()
{
	MSG msg;
	while ( ::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) )
	{
		::DispatchMessage(&msg);
	}
}


} // endnamespace mol
