#ifndef _MOL_SYS_THREAD_DEF_
#define _MOL_SYS_THREAD_DEF_


#include "conf.h"
#include "thread/fun.h"
#include "thread/sync.h"

#include <map>


namespace mol {

///////////////////////////////////////////////////////////////////////////////
// Sleep impl
///////////////////////////////////////////////////////////////////////////////

void Sleep(int delay);


////////////////////////////////////////////////////////////
// Thread Impl class
////////////////////////////////////////////////////////////

class Thread 
{
public:
    Thread ( );
	~Thread();

	int start( mol::fun::task* obj);

	static unsigned int self();
	static bool stop(int id);
	static void wait(int id);
	static bool wait(int id, int ms);
	static bool stopped();
	static THREAD_HANDLE handle(int id);
	static void terminate(int id);

	static int threads() { LOCK(cs_map_); return (int)map().size(); }

	static inline int call( mol::fun::task* fc) 
	{
		return (new mol::Thread)->start(fc);
	}

protected:

    void  detach();
    void  kill();

	typedef mol::fun::task ThreadCallType;

	typedef THREAD_RET_VAL 
		(MOL_THREAD_CALL_TYPE *threadFunctionPointer)(void* t);

    threadFunctionPointer        tfp_;

    THREAD_HANDLE                hThread_;
    unsigned int				 threadID_;
	mol::Event                   start_;
	mol::Event                   stop_;
	mol::Event                   done_;
	mol::fun::task*				 task_;

	typedef std::map<int,mol::Thread*>   MapType;

	static MapType& map();

	static THREAD_RET_VAL MOL_THREAD_CALL_TYPE threadFunction(void* t);
	static mol::CriticalSection cs_map_;
};


										


} // end namespace mol

#endif
