#ifndef MOL_IO_DEF_GUARD_DEF_
#define MOL_IO_DEF_GUARD_DEF_

#pragma once

#include "util/uni.h"
#include "util/istr.h"
#include "win/shell.h"
#include "thread/events.h"

namespace mol {
namespace io {


///////////////////////////////////////////////////////////////////////
// Directory Monitor (threaded)
///////////////////////////////////////////////////////////////////////


class DirMon
{
public:
	DirMon();
	virtual ~DirMon();

	void watch( const std::wstring& path, int flags = FILE_NOTIFY_CHANGE_DIR_NAME | FILE_NOTIFY_CHANGE_FILE_NAME, bool subtree = true );
	virtual void run();
	void cancel();
    void resume();

	mol::events::Event<DirMon*> events;

	const std::wstring& path() { return path_; }

    static void cancel(const std::wstring& path);
    static void resume(const std::wstring& path);

private:
	std::wstring                     path_;
	HANDLE		                    handle_[3];
	enum		                    EHANDLE { EVENT, DIRMON, CANCEL };
    mol::Mutex				        mutex_;
	int								flags_;
	bool							subtree_;

    static std::multimap<std::wstring,DirMon*> monitorMap_;
};





} // end namespace mol::win::io;
} // end namespace mol;

#endif