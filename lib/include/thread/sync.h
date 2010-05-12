#ifndef _MOL_SYNC_DEF_
#define _MOL_SYNC_DEF_

#include "conf.h"

namespace mol {

///////////////////////////////////////////////////////////////////////////////
// interface for mutexes and critical sections
///////////////////////////////////////////////////////////////////////////////

class IMutex
{
public:
    virtual ~IMutex() {};
    virtual void aquire()  =0;
    virtual void release() =0;
};

///////////////////////////////////////////////////////////////////////////////
// full kernel mutex_
///////////////////////////////////////////////////////////////////////////////

class Mutex  : public IMutex
{
public:
    Mutex();
    virtual ~Mutex();
    virtual void aquire();
    virtual int  aquired();
    virtual void release();
private:
    MUTEX_HANDLE                mutex_;
};

///////////////////////////////////////////////////////////////////////////////
// lock it
///////////////////////////////////////////////////////////////////////////////

class Lock
{
public:
    Lock(IMutex& m) : mutex_(m) { mutex_.aquire(); } ;
    ~Lock() { mutex_.release(); };
private:
    IMutex& mutex_;
};

///////////////////////////////////////////////////////////////////////////////
// user space cs_
///////////////////////////////////////////////////////////////////////////////

#ifdef WIN32

class CriticalSection : public IMutex
{
public:
    CriticalSection  ()			{ ::InitializeCriticalSection(&cs_); }
    ~CriticalSection ()			{ ::DeleteCriticalSection(&cs_); }
    void aquire()				{ ::EnterCriticalSection(&cs_); }
    void release()				{ ::LeaveCriticalSection(&cs_); }
private:
	CRITICAL_SECTION	cs_;
};

#else
typedef Mutex CriticalSection;
#endif

///////////////////////////////////////////////////////////////////////////////
// lock it quickly
///////////////////////////////////////////////////////////////////////////////

#define LOCK(imutex) mol::Lock mol_lock_##__LINE__(imutex);

///////////////////////////////////////////////////////////////////////////////
// Kernel Events
///////////////////////////////////////////////////////////////////////////////

class Event
{
public:
    Event( bool a = true );
    ~Event();

    void signal();
    void wait();
	bool wait(unsigned int ms);
    void reset();
    int  test();

    int operator()() { return test(); }
private:
#ifdef WIN32
    HANDLE						   hEvent_;
#else
    pthread_cond_t                 event_;
    pthread_mutex_t                mutex_;
    bool                           automatic_;
    bool                           active_;
#endif

};

///////////////////////////////////////////////////////////////////////////////
// Singleton
///////////////////////////////////////////////////////////////////////////////

template<class T>
class Singleton
{
public:

	static T& instance() 
	{
		LOCK(mutex());
		if (!t_)
		{
			t_ = new T;
			atexit(&Singleton<T>::killSingleton);
		}
		return *t_;
	}
private:

	static void killSingleton()
	{
		LOCK(mutex());
		if (t_)
		{
			delete t_;
			t_ = 0;
		}
	}

	static mol::IMutex& mutex()
	{
		static mol::CriticalSection cs_;
		return cs_;
	}
	static T* t_;	
};

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
template<class T>
T* Singleton<T>::t_ = 0;


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

template<class T>
T& singleton()
{
	return Singleton<T>::instance();
}

#define SINGLETON(T) friend mol::Singleton<T>; 
#define STACKSINGLETON(T) friend mol::Singleton<T>; friend mol::stack_obj<T>;
#define COMSINGLETON(T) friend mol::ComSingleton<T>;
#define NONCREATABLECOMSINGLETON(T) friend mol::NonCreatableCOMSingleton<T>; friend mol::com_obj<T>;

} // end namespace mol

#endif

