#define _SECURE_SCL 0

#include "win/io.h"
#include "win/path.h"
#include "util/istr.h"
#include "util/str.h"

#include <sstream>
#include <iomanip>


namespace mol {
namespace io {


std::multimap<std::wstring,DirMon*> DirMon::monitorMap_;

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

void DirMon::watch( const std::wstring& path, int flags, bool subtree )
{ 
    if ( path.size() == 0 )
	{
		return;
	}

	flags_ = flags;
	subtree_ = subtree;

	path_ = path;

	if  (Path::isDir(path_)) 
	{
		path_ = Path::addBackSlash(path_);
	}

	if ( !Path::exists(path_) )
        return;

	for( std::multimap<std::wstring,DirMon*>::iterator it = monitorMap_.begin(); it != monitorMap_.end(); it++)
	{
		if ( (*it).second == this )
		{
			monitorMap_.erase(it);
			break;
		}
	}

	cancel();
    monitorMap_.insert(std::make_pair(path_,this));
	mol::thread( boost::bind( &DirMon::run, this) );
}

void DirMon::run()
{
	handle_[DIRMON] = ::FindFirstChangeNotificationW(	Path::wpath(path_).c_str(), 
														FALSE, 
														flags_
													);
	while ( handle_[DIRMON] != INVALID_HANDLE_VALUE )
	{
		DWORD wait = ::WaitForMultipleObjects(2,handle_,FALSE,INFINITE);
		if ( wait == WAIT_OBJECT_0 ) // cancel EVENT got signalled
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
            events.fire(this);
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
        watch(path_,flags_,subtree_);
	}
	events.fire(this);
}

void DirMon::cancel(const std::wstring& path)
{
    for( std::multimap<std::wstring,DirMon*>::iterator it = monitorMap_.begin(); it != monitorMap_.end(); it++)
    {
        std::wstring p( (*it).first);
        if ( p == path )
            (*it).second->cancel();
    }
}

void DirMon::resume(const std::wstring& path)
{
    for( std::multimap<std::wstring,DirMon*>::iterator it = monitorMap_.begin(); it != monitorMap_.end(); it++)
    {
        std::wstring p( (*it).first );
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