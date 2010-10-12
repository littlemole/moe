#ifndef MOL_THREADQUEUE_DEF_GUARD_H_DEFINE_
#define MOL_THREADQUEUE_DEF_GUARD_H_DEFINE_

#pragma warning( disable: 4355)
//#include "thread/systhread.h"
#include "thread/thread.h"
#include "thread/sync.h"
#include <list>
#include "util/util.h"

namespace mol {

namespace threading {

class ThreadStartPolicy 
{
public:
	void operator()(){};
};

class ThreadShutdownPolicy 
{
public:
	void operator()(){};
};


} // end namespace threading

template<class T, bool Synchronize = true, class P=mol::threading::ThreadStartPolicy, class PS=mol::threading::ThreadShutdownPolicy >
class ThreadQueue 
{
friend class mol::Thread;
public:
    ThreadQueue()
		:go_(false),cancel_(false)
	{
		thread_ = threaded_fun_call( &mol::ThreadQueue<T,Synchronize,P,PS>::worker, this);
	}

    ~ThreadQueue()
	{
		if ( thread_ )
			cancel();

		ODBGS("~ThreadQueue");
	}

    void    push(T* action)
	{
		LOCK(mutex_);
		queue_.push_back(action);
		cancel_.reset();
		go_.signal();
	}

    void cancel()
	{
		cancel_.signal();
		go_.signal();
		mol::Sleep(1);
		mol::Thread::wait(thread_);
		thread_ = 0;
		clear();
	}

	bool cancelled()
	{
		return cancel_.test() != 0;
	}

	void worker()
	{
		P p;
		p();
		while( !cancel_.test())
		{
			go_.wait();
			if ( cancel_.test() )
			{
				PS ps;
				ps();
				ODBGS("~ThreadQueue::Thread");
				return;
			}

			T* t = pop();
			if ( t )
			{
				delete t;
			}
		}
		PS ps;
		ps();
		ODBGS("~ThreadQueue::Thread");
	}

    unsigned int size()
	{
		LOCK(mutex_);
		return (int)queue_.size();
	}

    void clear()
	{
		LOCK(mutex_);
		mol::purge(queue_);
		queue_.clear();
	}

protected:

    T* pop ()
	{
		T* t = 0;
		{
			LOCK(mutex_);
			if ( queue_.size() == 0 )
			{
				go_.reset();
				return 0;
			}

			t = queue_.front();
			queue_.pop_front();
		
			if ( Synchronize && queue_.empty() )
				go_.reset();
		}

		(*t)();

		{
			LOCK(mutex_);
			if ( !Synchronize && queue_.empty() )
				go_.reset();
		}

		return t;
	}

    mol::Event					go_;
	mol::Event					cancel_;
    mol::Mutex				    mutex_;
	std::list<T*>				queue_;
	int							thread_;
};

} // end namespace mol

#endif

