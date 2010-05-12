#ifndef MOLE_APP_DEF
#define MOLE_APP_DEF

#include "util/uni.h"
#include "util/x.h"
#include "app.h"
#include <list>
#include <map>
#include <vector>
#include "thread/sync.h"

namespace mol  {



////////////////////////////////////////////////////////////////////////////////////////////
//! App Object Philosophy:
//
//! assure you instanciate ONE mol::App derived object in main()
//! or have one mole singleton in your DLL routines
//
////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////
//! global helper to get the windows HINSTANCE handle
//
//! assure you instanciate a mol::App derived object in main()
////////////////////////////////////////////////////////////////////////////////////////////

HINSTANCE hinstance();

////////////////////////////////////////////////////////////////////////////////////////////
//! global helper to get THAT application
//
//! THAT application to be derived from mol::App
//! usage: MyApp& myAppObjectRef = mol::app<MyApp>();
////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
T& app() 
{ 
	return T::app<T>();
}



template<class T>
int run( mol::TCHAR* lpCmdLine)
{
	T& a =  app<T>();
    return a.run(lpCmdLine);
}

////////////////////////////////////////////////////////////////////////////////////////////

namespace win  {
class LoopBase;
class DlgBase;
}

namespace ole { 
	class dll; 
}

////////////////////////////////////////////////////////////////////////////////////////////
//! App Object for Application Object-Template
//
////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////
namespace win  {

class AppBase
{

friend HINSTANCE mol::hinstance();
friend class mol::win::LoopBase;
friend class mol::win::DlgBase;
friend class mol::ole::dll;

public:
		// store hInst
        AppBase();
        virtual ~AppBase();

		// load Keaboard Accelerators for GUI Application
        HACCEL loadAccellerator(int n, HWND hWnd);

		// run the application
		virtual int run(const mol::string& cmdline)		{ return 0; };

		// message loop callback (idle time)
        virtual void idle(MSG& msg) {}

		// global reference to the one and only app
       // static AppBase& app();

		virtual mol::TCHAR* getAppId()					{ return 0; };
		virtual int getElevationStringIdentifier()		{ return 0; };

        void OnMDIClient(HWND hWnd);
        void OnCreateDlg(HWND hWnd);
        void OnEndDlg   (HWND hWnd);
		void OnCreateTab(HWND hTool, HWND hTab);
        void OnEndTab   (HWND hTool);

		bool TabToolNotify( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam );

		virtual void lock();
		virtual void unlock();
        virtual bool locked();

        mol::string CreateAppPath(const mol::string& dir);
        mol::string UnpackAppFile(const mol::string& file, int id, bool createIf=false); 

		mol::string getModulePath();
		mol::string getAppPath();

		virtual HRESULT __stdcall RegisterServer(void)		{ return S_OK; } 
		virtual HRESULT __stdcall UnregisterServer(void)	{ return S_OK; } 

		virtual HRESULT __stdcall RegisterClassObjects(int ctx, int cls) { return S_OK; } 


		//! returns the static ref to THE app object
		//!
		//! requires one mol::App derived Object instanciated in main()
		//! or singleton usage thru mol::Dll

		template<class T>
		static T& app()
		{
			static mol::CriticalSection cs_;

			if (!app_)
			{
				LOCK(cs_);
				if ( !app_ ) {
					app_ = &mol::singleton<T>();
				}
			}
			return (T&)(*app_);
		}
	
protected:

		virtual void Lock();
		virtual void UnLock();
		virtual bool Locked();
		virtual void initObjectMap() {};

        HINSTANCE hinstance();

        HACCEL				hAccel_;
        HWND				hWndAccel_;
        HWND				hWndMDIClient_;
        HINSTANCE			hInstance_;
        std::list<HWND>		dlgList_;		
		std::map<HWND,HWND>	tabMap_;
		LONG                lockCount_;
		mol::Mutex			mutex_;

        static  AppBase*	app_;
};

////////////////////////////////////////////////////////////////////////////////////////////
//! Windows Message Loop Template Class
////////////////////////////////////////////////////////////////////////////////////////////

class MsgLoop;

} // end namespace win


inline
mol::win::AppBase& App() 
{ 
	return mol::win::AppBase::app<mol::win::AppBase>(); 
};

template<class L = mol::win::MsgLoop> 
class Application : public mol::win::AppBase
{
public:
    Application() 
	{}

    ~Application() 
	{}

    virtual int run(const mol::string& cmdline) 
	{ 
		return msgLoop_(*this);	
	}

protected:
        L			msgLoop_;
};

////////////////////////////////////////////////////////////////////////////////////////////
//! Windows Message Loop Base Class
//!
//! providers for std ms handling (doMsg) 
//! and (optional) MDI Client Support
//! base classes define operator() to do
//! the work
////////////////////////////////////////////////////////////////////////////////////////////

namespace win {

class LoopBase
{
public:
        void doMsg(MSG& msg, AppBase& app);
        HWND getMDIClient(AppBase& app);
};

////////////////////////////////////////////////////////////////////////////////////////////
//! most basic std loop
////////////////////////////////////////////////////////////////////////////////////////////

class Loop : public mol::win::LoopBase
{
public:
	int operator() ( mol::win::AppBase& app );
};

////////////////////////////////////////////////////////////////////////////////////////////
//! most basic MDI loop
////////////////////////////////////////////////////////////////////////////////////////////

class MdiLoop : public mol::win::LoopBase
{
public:
	int operator() ( mol::win::AppBase& app );
};

////////////////////////////////////////////////////////////////////////////////////////////
//! most basic IDLE loop
////////////////////////////////////////////////////////////////////////////////////////////

class ActiveLoop : public mol::win::LoopBase
{
public:
	int operator() ( mol::win::AppBase& app );
};

////////////////////////////////////////////////////////////////////////////////////////////
//! handifier: an App is an TApp with an basic loop
////////////////////////////////////////////////////////////////////////////////////////////

} // end namespace win

typedef Application<mol::win::Loop>			    WindowApp;

////////////////////////////////////////////////////////////////////////////////////////////
//! handifier: a ActiveApp is an TApp with an active  loop
////////////////////////////////////////////////////////////////////////////////////////////

typedef Application<mol::win::ActiveLoop>		ActiveApp;

////////////////////////////////////////////////////////////////////////////////////////////
//! handifier: a MDIApp is an TApp with an basic MDI support loop
////////////////////////////////////////////////////////////////////////////////////////////

typedef Application<mol::win::MdiLoop>			MdiApp;

////////////////////////////////////////////////////////////////////////////////////////////
// keep UI Alive by pumping messages that have been queued
// while lengthy operations (ie enumerating slow network drive)
////////////////////////////////////////////////////////////////////////////////////////////

void pumpMessages();

////////////////////////////////////////////////////////////////////////////////////////////
																
////////////////////////////////////////////////////////////////////////////////////////////


} // end namespace mol


#define DEFINE_APP_ID(appid) \
mol::TCHAR* getAppId() \
{							 \
	static mol::TCHAR appid_[] = _T(appid); \
	return appid_;	\
};

#define DEFINE_ELEVATION_STRING_IDENTIFIER(id)  \
int getElevationStringIdentifier()				\
{												\
	return id;									\
};

#endif