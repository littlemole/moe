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

#ifdef _WIN32
#ifdef _WIN64
#define locked_comp_ex(target,value,comparand) InterlockedCompareExchange64( (volatile LONGLONG*)(target),(LONGLONG)(value),(LONGLONG)(comparand) ) 
#else
#define locked_comp_ex(target,value,comparand) InterlockedCompareExchange( (volatile LONG*)(target),(LONG)(value),(LONG)(comparand) ) 
#endif
#else
#define locked_comp_ex(target,value,comparand) __sync_val_compare_and_swap(target,comparand,value)
#endif

template<class T>
class Singleton
{
public:

	static T& instance() 
	{
		if ( t_ == 0 )
		{
			T* n = new T;
			LONG_PTR tmp = locked_comp_ex(&t_,n,0);
			if ( tmp == 0 )
			{
				atexit(&Singleton<T>::killSingleton);
			}
			else
			{
				delete n;
			}
		}
		return *(T*)t_;
	}
	/*
	static T& instance() 
	{
		long tmp = ::InterlockedCompareExchange ((volatile LONG*) &t_, (LONG)0,(LONG)0);
		if ( tmp == 0 )
		{
			T* n = new T;
			tmp = ::InterlockedCompareExchange( (volatile LONG*) &t_,(LONG)n,(LONG)0);
			if ( tmp == 0 )
			{
				atexit(&Singleton<T>::killSingleton);
				tmp = (long)n;
			}
			else
			{
				delete n;
			}
		}

		return *(T*)tmp;
	}
	*/
private:

	static void killSingleton()
	{
		if (t_)
		{
			delete t_;
			t_ = 0;
		}
	}

	static volatile T* t_;	
};

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
template<class T>
volatile T* Singleton<T>::t_ = 0;


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

template<class T>
T& singleton()
{
	return Singleton<T>::instance();
}


} // end namespace mol

#endif

