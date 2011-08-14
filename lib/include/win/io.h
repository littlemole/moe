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

	void watch( const mol::string& path, int flags = FILE_NOTIFY_CHANGE_DIR_NAME | FILE_NOTIFY_CHANGE_FILE_NAME, bool subtree = true );
	virtual void run();
	void cancel();
    void resume();

	mol::events::Event<DirMon*> events;

	const mol::string& path() { return path_; }

    static void cancel(const mol::string& path);
    static void resume(const mol::string& path);

private:
	mol::string                     path_;
	HANDLE		                    handle_[3];
	enum		                    EHANDLE { EVENT, DIRMON, CANCEL };
    mol::Mutex				        mutex_;
	int								flags_;
	bool							subtree_;

    static std::multimap<mol::string,DirMon*> monitorMap_;
};





} // end namespace mol::win::io;
} // end namespace mol;

#endif