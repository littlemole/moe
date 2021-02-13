#ifndef _MOL_DEF_GUARD_WIN_ASYNC_CALL_DEFINE_
#define _MOL_DEF_GUARD_WIN_ASYNC_CALL_DEFINE_

#include "thread/fun.h"
#include "thread/thread.h"
#include "win/app.h"
#include "win/wnd.h"

namespace mol {

namespace win {


void __stdcall async_code_block_callback(ULONG_PTR cb);

HANDLE GetThreadHandle(unsigned int id);


void run_on_gui_thread_impl(mol::fun::task* t);

} // end namespace win


/////////////////////////////////////////////////////////////////
// APC based callbacks
/////////////////////////////////////////////////////////////////

template<class B>
void run_on_gui_thread( B t)
{
	run_on_gui_thread_impl(mol::fun::make_task(t)) ;
}

/////////////////////////////////////////////////////////////////
// gui tread safe invokes
/////////////////////////////////////////////////////////////////

template<class B>
void invoke( B bound )
{
	mol::fun::task* task = mol::fun::make_task( bound );
	::PostThreadMessage( mol::guithread(), WM_INVOKE,0, (LPARAM)task );
}


/////////////////////////////////////////////////////////////////
// gui tread safe invokes - hwnd based
/////////////////////////////////////////////////////////////////

template<class T,class R>
void dispatch( T& t, R (T::*f)()  )
{
	mol::fun::task* task = mol::fun::make_task( std::bind(f,&t) );
	t.postMessage(WM_INVOKE,0,(LPARAM)task);
}

template<class T, class R, class P1>
void dispatch( T& t, R (T::*f)(P1), P1 p1 )
{
	mol::fun::task* task = mol::fun::make_task(std::bind(f,&t,p1) );
	t.postMessage(WM_INVOKE,0,(LPARAM)task);
}

template<class T, class R, class P1, class P2>
void dispatch( T& t, R (T::*f)(P1,P2), P1 p1, P2 p2  )
{
	mol::fun::task* task = mol::fun::make_task(std::bind(f,&t,p1,p2) );
	t.postMessage(WM_INVOKE,0,(LPARAM)task);
}

template<class T, class R, class P1, class P2, class P3>
void dispatch( T& t, R (T::*f)(P1,P2,P3), P1 p1, P2 p2, P3 p3 )
{
	mol::fun::task* task = mol::fun::make_task(std::bind(f,&t,p1,p2,p3) );
	t.postMessage(WM_INVOKE,0,(LPARAM)task);
}

template<class T, class R, class P1, class P2, class P3, class P4>
void dispatch( T& t, R (T::*f)(P1,P2,P3,P4), P1 p1, P2 p2, P3 p3, P4 p4  )
{
	mol::fun::task* task = mol::fun::make_task(std::bind(f,&t,p1,p2,p3,p4) );
	t.postMessage(WM_INVOKE,0,(LPARAM)task);
}



} // endnamespace mol



#endif


