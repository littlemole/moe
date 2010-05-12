#include "win/App.h"
#include "win/Res.h"
#include "util/Str.h"
#include <Shlobj.h>
#include <fstream>

namespace mol  {


//! global mol::hinstance() - returns the process HINSTANCE
//!
//! needs a mol::App derived Object instantiated in main()

HINSTANCE hinstance()
{
	return mol::App().hinstance();
	//return mol::win::AppBase::hinstance();
}

namespace win  {

AppBase*				AppBase::app_			= 0;
	/*

HINSTANCE				AppBase::hInstance_		= 0;
HACCEL					AppBase::hAccel_		= 0;
HWND					AppBase::hWndAccel_		= 0;
HWND					AppBase::hWndMDIClient_	= 0;
std::list<HWND>         AppBase::dlgList_;
std::map<HWND,HWND>     AppBase::tabMap_;
LONG					AppBase::lockCount_     = 0;

mol::Mutex				AppBase::mutex_;
*/

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
	ODBGS1("app LOCK: ",lockCount_);
}

void AppBase::UnLock()
{
	LOCK(mutex_);
	lockCount_--;	
	ODBGS1("app UNLOCK: ",lockCount_);
}

bool AppBase::Locked()
{
	LOCK(mutex_);
	ODBGS1("app count: ",lockCount_);
	return lockCount_ > 0;
}



//! construcor 
AppBase::AppBase()
{
	if ( app_ != 0 )
		throw mol::X( _T("more than one app object is considered illegal nonsens"));

	hInstance_ = ::GetModuleHandle(0);
    hAccel_	   = 0;
    hWndAccel_ = 0;
	hWndMDIClient_ = 0;
	lockCount_ = 0;
    app_	   = this;
}

AppBase::~AppBase() 
{
}

//! load keyboard shortcuts (menu accelaterors)
HACCEL AppBase::loadAccellerator(int n, HWND hWnd)
{
    hWndAccel_     = hWnd;
    return hAccel_ = ::LoadAccelerators( hinstance(), MAKEINTRESOURCE(n) );
}

//! used by mol::hinstance
HINSTANCE AppBase::hinstance()
{
    return hInstance_;
}






//! called internally from modeless dialogs
//!
//! used to register keyword accelerator forwarding
//! from mainwindow to dialog
//! eg tab strokes

void AppBase::OnCreateDlg(HWND hWnd)
{
    dlgList_.push_back(hWnd);
}

//! unregister dialog 
void AppBase::OnEndDlg(HWND hWnd)
{
    for ( std::list<HWND>::iterator it = dlgList_.begin(); it != dlgList_.end(); it++)
    {
        if ( *it == hWnd )
        {
            dlgList_.erase(it);
            return;
        }
    }
}

void AppBase::OnCreateTab(HWND hTool, HWND hTab)
{
	tabMap_.insert(std::make_pair(hTool,hTab));
}

bool AppBase::TabToolNotify( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
    if ( tabMap_.count(hWnd) > 0 )
	{
		::SendMessage( tabMap_[hWnd],msg,wParam,lParam );
        return true;
    }
	return false;
}

//! unregister dialog 
void AppBase::OnEndTab(HWND hTool)
{
	if ( tabMap_.count(hTool) > 0 )
	{
            tabMap_.erase(hTool);
    }
}

//! set MDI Client Window
void AppBase::OnMDIClient(HWND hWnd)
{
    hWndMDIClient_ = hWnd;
}

mol::string AppBase::CreateAppPath(const mol::string& dir)
{
	mol::TCHAR buff[MAX_PATH];
	::SHGetSpecialFolderPath(0,buff,CSIDL_APPDATA,TRUE);

	mol::string path = buff;
	path += _T("\\");
	path += dir;

	DWORD fa = GetFileAttributes(path.c_str());
	if ( fa != FILE_ATTRIBUTE_DIRECTORY ) // == INVALID_FILE_ATTRIBUTES)) //FILE_ATTRIBUTE_DIRECTORY) )
	{
		BOOL r = ::CreateDirectory(path.c_str(),NULL);
		//if ( !::CreateDirectory(path.c_str(),NULL) )
          //; // throw mol::X("could not create app dir"); // might "fail but succeed" thanks to Vista Virtualization!
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
  if ( app.dlgList_.size() > 0 )
  {
    for ( std::list<HWND>::iterator it = app.dlgList_.begin(); it != app.dlgList_.end(); )
    {
      if ( ::IsWindow(*it) )
      {
        if ( ::IsDialogMessage( *it, &msg) )
        {
          return;
        }
	  }
      else
      {
         it = app.dlgList_.erase(it);
         continue;
      }
      it++;
    }
  }
  if (app.hAccel_)
  {
    if ( ::TranslateAccelerator( app.hWndAccel_, app.hAccel_, &msg ))
      return;
  }
  ::TranslateMessage(&msg);
  ::DispatchMessage(&msg);
}

//!returns the MDI client
HWND LoopBase::getMDIClient(AppBase& app)
{
  return app.hWndMDIClient_;
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
    if ( !::TranslateMDISysAccel( getMDIClient(app), &msg) )
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
