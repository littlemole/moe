
#include "thread/systhread.h"
#include "util/x.h"

namespace mol {

mol::CriticalSection Thread::cs_map_;

Thread::MapType& Thread::map()
{
	static MapType type;
	return type;
}

//´initialize the Thread - set StartFunc-Pointer
Thread::Thread()
	: tfp_( &Thread::threadFunction ),
	  hThread_(0),
	  start_(false),
	  done_(false)
{
}

// call detach() if you don't want your thread to die
Thread::~Thread()
{
	ODBGS("~Thread died");
}

unsigned int Thread::self()
{
#ifdef WIN32
	return ::GetCurrentThreadId();
#else
	return (unsigned int)pthread_self();
#endif
}

THREAD_HANDLE Thread::handle(int id)
{
	LOCK(cs_map_);
	if ( map().count(id) > 0 )
	{
		return map()[id]->hThread_;
	}
	return 0;
}

bool Thread::stop(int id)
{
	LOCK(cs_map_);
	if ( map().count(id) > 0 )
	{
		map()[id]->stop_.signal();
		return true;
	}
	return false;
}

void Thread::wait(int id)
{
	mol::THREAD_HANDLE h = Thread::handle(id);
	if ( !h )
		return;

#ifdef WIN32

    DWORD status = (DWORD)NULL;

	::WaitForSingleObject(h, INFINITE);

#else

    void* status = 0;
    pthread_join(h,&status);

#endif

}


bool Thread::wait(int id, int ms)
{
	mol::THREAD_HANDLE h = Thread::handle(id);
	if ( !h )
		return false;

#ifdef WIN32

    DWORD status = (DWORD)NULL;

	if ( WAIT_TIMEOUT == ::WaitForSingleObject(h, ms) )
		return false;

	return true;

#else

	mol::Thread* t = 0;
	{
		LOCK(cs_map_);
		t = map()[id];
		void* status = 0;
		if ( map()[id]->done_.wait(ms) )
		{
	         pthread_join(h,&status);
		}
	}

#endif
        return true;
}

bool Thread::stopped()
{
	int id = mol::Thread::self();
	LOCK(cs_map_);
	if ( map().count(id) > 0 )
	{
		if ( map()[id]->stop_.test() )
			return true;
	}
	return false;
}


void Thread::terminate(int id)
{
	LOCK(cs_map_);
	if ( map().count(id) > 0 )
	{
		map()[id]->kill();
		map().erase(id);
	}
}

// start a thread - the thread will call the function
// encapsulated in mol::Call c
//int Thread::start( mol::threading::CallBase* c )

int Thread::start( mol::fun::task* c )
{
	start_.reset();
	task_ = c;
	
#ifdef WIN32

	hThread_ = (HANDLE) _beginthreadex(NULL,0,tfp_,this,0,&threadID_ );

#else
	pthread_attr_t attributes;
	pthread_attr_init(&attributes);
	
	pthread_create(&hThread_,&attributes,tfp_,this);// == 0 )
	
	pthread_attr_destroy(&attributes);
#endif

	start_.wait();
	return threadID_;
}

void Thread::detach()
{
#ifdef WIN32
	::CloseHandle(hThread_);
#else
    pthread_detach(hThread_);
#endif
}

void Thread::kill()
{
	if ( hThread_ )
	{

#ifdef WIN32
        ::TerminateThread(hThread_,0);
		::CloseHandle(hThread_);
#else
        pthread_cancel(hThread_);
        pthread_detach(hThread_);
#endif
	}
	hThread_ = 0;
}

////////////////////////////////////////////////////////
// the actual thread function implementation
////////////////////////////////////////////////////////

THREAD_RET_VAL MOL_THREAD_CALL_TYPE Thread::threadFunction(void* t)
{
    Thread* thread = (Thread*) t;
	thread->threadID_ = mol::Thread::self();
	{
		LOCK(cs_map_);
		map()[thread->threadID_] = thread;
	}

	thread->start_.signal();
	ThreadCallType* task = (ThreadCallType*)(thread->task_);
	(*task)();

	mol::Sleep(1); //cygwin will deadlock w/o this
	{
		LOCK(cs_map_);
		map()[thread->threadID_]->detach();
		map().erase(thread->threadID_);
	}

	thread->done_.signal();
	delete thread;
	delete task;

    return (THREAD_RET_VAL) 0;
}

////////////////////////////////////////////////////////
// Sleep Impl
////////////////////////////////////////////////////////

void Sleep(int delay)
{
#ifdef WIN32
	::SleepEx(delay,TRUE);
#else
	timeval timeout = { (delay/1000) , ((delay*1000)%1000000) };
	select( 0, (fd_set*)NULL,(fd_set*)NULL,(fd_set*)NULL,&timeout);
#endif
}

}// end namespace mol
