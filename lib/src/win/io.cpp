#define _SECURE_SCL 0

#include "win/io.h"
#include "win/path.h"
#include "util/istr.h"
#include "util/str.h"

#include <sstream>
#include <iomanip>


namespace mol {
namespace io {


std::multimap<mol::string,DirMon*> DirMon::monitorMap_;

DirMon::DirMon()
	:  path_(_T(""))
{		
	handle_[EVENT]  = ::CreateEvent(0,TRUE,FALSE,0);
	handle_[DIRMON] = INVALID_HANDLE_VALUE;
}

DirMon::~DirMon()
{
	cancel();
    monitorMap_.erase(path_);
}

void DirMon::watch( const mol::string& path )
{ 
	if ( (!Path::exists(path)) || (!Path::isDir(path)) )
        return;

    if ( path.size() != 0 )
	{
		for( std::multimap<mol::string,DirMon*>::iterator it = monitorMap_.begin(); it != monitorMap_.end(); it++)
		{
			if ( (*it).second == this )
			{
				monitorMap_.erase(it);
				break;
			}
		}
	}

	cancel();
	path_ = Path::addBackSlash(path);
    monitorMap_.insert(std::make_pair(path_,this));
	mol::thread( boost::bind( &DirMon::run, this) );
}

void DirMon::run()
{
	handle_[DIRMON] = ::FindFirstChangeNotificationW(	Path::wpath(path_).c_str(), 
														FALSE, 
														FILE_NOTIFY_CHANGE_DIR_NAME|
														FILE_NOTIFY_CHANGE_FILE_NAME
													);
	while ( handle_[DIRMON] != INVALID_HANDLE_VALUE )
	{
		DWORD wait = ::WaitForMultipleObjects(2,handle_,FALSE,INFINITE);
		if ( wait == WAIT_OBJECT_0 ) // EVENT got signalled
		{
			::FindCloseChangeNotification(handle_[DIRMON]);	
			::ResetEvent(handle_[EVENT]);
			::SetEvent(handle_[CANCEL]);
			handle_[DIRMON] = INVALID_HANDLE_VALUE;
			break;
		}
		// DIRMON got signalled;
        {
            LOCK(mutex_);
            events.fire((LPARAM)this);
        }
		::FindNextChangeNotification(handle_[DIRMON]);
	}
}

void DirMon::cancel()
{
    LOCK(mutex_);
	if ( handle_[DIRMON] != INVALID_HANDLE_VALUE )
	{
		::SetEvent(handle_[EVENT]);
		::WaitForSingleObject( handle_[CANCEL], INFINITE );
	}
}

void DirMon::resume()
{
	if ( Path::exists(path_) && Path::isDir(path_) )
	{
        watch(path_);
	}
	events.fire((LPARAM)this);
}

void DirMon::cancel(const mol::string& path)
{
    for( std::multimap<mol::string,DirMon*>::iterator it = monitorMap_.begin(); it != monitorMap_.end(); it++)
    {
        mol::string p( (*it).first);
        if ( p == path )
            (*it).second->cancel();
    }
}

void DirMon::resume(const mol::string& path)
{
    for( std::multimap<mol::string,DirMon*>::iterator it = monitorMap_.begin(); it != monitorMap_.end(); it++)
    {
        mol::string p( (*it).first );
        if ( p == path )
            (*it).second->resume();
    }
}


///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

} // end namespace mol::win::io;
} // end namespace mol;