#include "thread/sync.h"
#include "thread/systhread.h"
#include <ctime>

namespace mol {

Mutex::Mutex()
{
#ifdef WIN32
	mutex_ = ::CreateMutex(NULL,FALSE,NULL);
#else
    pthread_mutex_init( &mutex_, (pthread_mutexattr_t*) 0);
#endif
}

Mutex::~Mutex()
{
#ifdef WIN32
    ::CloseHandle(mutex_);
#else
    pthread_mutex_destroy( &mutex_ );
#endif
}

void Mutex::aquire()
{
#ifdef WIN32
    ::WaitForSingleObject(mutex_, INFINITE );
#else
	mol::Sleep(1);
    pthread_mutex_lock( &mutex_ );
#endif
}

int Mutex::aquired()
{
#ifdef WIN32
    return (::WaitForSingleObject(mutex_, 0 ) != WAIT_TIMEOUT);
#else
    return (pthread_mutex_trylock( &mutex_ ) == 0);
#endif
}

void Mutex::release()
{
#ifdef WIN32
	ReleaseMutex(mutex_);
#else
    pthread_mutex_unlock(&mutex_);
#endif
}

//////////////////////////////////////////////////////////////////

Event::Event( bool a )
{
#ifdef WIN32
	hEvent_ = ::CreateEvent(NULL,!a,FALSE,NULL);
#else
    pthread_cond_init( &event_, (pthread_condattr_t*) 0);
    pthread_mutex_init( &mutex_, (pthread_mutexattr_t*) 0);
    automatic_ = a;
    active_ = false;
#endif
}

Event::~Event()
{
#ifdef WIN32
	::CloseHandle( hEvent_ );
#else
    pthread_cond_destroy( &event_ );
    pthread_mutex_destroy( &mutex_ );
#endif
}

void Event::signal()
{
#ifdef WIN32
	::SetEvent( hEvent_ );
#else
   pthread_mutex_lock( &mutex_ );
    active_ = true;
    if ( automatic_ )
            pthread_cond_signal( &event_ );
    else
            pthread_cond_broadcast( &event_ );
    pthread_mutex_unlock( &mutex_ );
#endif
}

void Event::wait()
{
#ifdef WIN32
	::WaitForSingleObject( hEvent_, INFINITE );
#else
    pthread_mutex_lock( &mutex_ );
    while ( !active_ )
            pthread_cond_wait( &event_, &mutex_ );
    if ( automatic_ )
            active_ = false;
    pthread_mutex_unlock( &mutex_ );
#endif
}

//#define __USE_POSIX199309

bool Event::wait(unsigned int ms)
{
#ifdef WIN32
	return WAIT_TIMEOUT != ::WaitForSingleObject( hEvent_, ms );
#else
    pthread_mutex_lock( &mutex_ );
    //while ( !active_ )

        //    pthread_cond_wait( &event_, &mutex_ );

	struct timespec ts;
	clock_gettime(CLOCK_REALTIME, &ts);
	ts.tv_sec += ms;

	bool ret = true;
	if ( ETIMEDOUT == pthread_cond_timedwait( &event_, &mutex_, &ts ) )
	{
		ret = false;
	}
	else
	{
		if ( automatic_ )
            active_ = false;
	}
    pthread_mutex_unlock( &mutex_ );
	return ret;
#endif
}

void Event::reset()
{
#ifdef WIN32
	::ResetEvent( hEvent_ );
#else
	pthread_mutex_lock( &mutex_ );
	active_ = false;
	pthread_mutex_unlock( &mutex_ );
#endif
}

int  Event::test()
{
#ifdef WIN32
	return ( ::WaitForSingleObject(hEvent_,0) != WAIT_TIMEOUT );
#else
    pthread_mutex_lock( &mutex_ );
    int ret = active_;
    if ( active_ && automatic_ )
            active_ = false;
    pthread_mutex_unlock( &mutex_ );
    return ret;
#endif
}

} // end namespace mol

