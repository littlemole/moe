#ifndef _MOL_DEF_GUARD_WIN_ASYNC_CALL_DEFINE_
#define _MOL_DEF_GUARD_WIN_ASYNC_CALL_DEFINE_

#include "thread/fun.h"
#include "thread/thread.h"

namespace mol {

namespace win {

/////////////////////////////////////////////////////////////////
// APC based callbacks
/////////////////////////////////////////////////////////////////

	/*
class AsyncCodeBlockBase
{
public:
	AsyncCodeBlockBase() 
	{
	}

	virtual	~AsyncCodeBlockBase() 
	{
	}

	virtual void operator()() {

	}
};

template<class T, class P1 = void, class P2 = void, class P3 = void, class P4 = void, class P5 = void, class P6 = void >
class AsyncCodeBlock : public AsyncCodeBlockBase
{
public:
	AsyncCodeBlock( const T& t, P1 p1, P2 p2, P3 p3, P4 p4,P5 p5, P6 p6) 
		: t_(t), p1_(p1), p2_(p2), p3_(p3), p4_(p4), p5_(p5), p6_(p6)
	{
	}

	virtual void operator()() {
		t_(p1_,p2_,p3_,p4_,p5_,p6_);
	}

private:

	const T& t_;
	P1 p1_;
	P2 p2_;
	P3 p3_;
	P4 p4_;
	P5 p5_;
	P6 p6_;
};

template<class T, class P1, class P2, class P3, class P4, class P5 >
class AsyncCodeBlock<T,P1,P2,P3,P4,P5,void> : public AsyncCodeBlockBase
{
public:
	AsyncCodeBlock( const T& t, P1 p1, P2 p2, P3 p3, P4 p4, P5 p5) 
		: t_(t), p1_(p1), p2_(p2), p3_(p3), p4_(p4), p5_(p5)
	{
	}

	virtual void operator()() {
		t_(p1_,p2_,p3_,p4_,p5_);
	}

private:

	const T& t_;
	P1 p1_;
	P2 p2_;
	P3 p3_;
	P4 p4_;
	P5 p5_;
};

template<class T, class P1, class P2, class P3, class P4>
class AsyncCodeBlock<T,P1,P2,P3,P4,void,void> : public AsyncCodeBlockBase
{
public:
	AsyncCodeBlock( const T& t, P1 p1, P2 p2, P3 p3, P4 p4) 
		: t_(t), p1_(p1), p2_(p2), p3_(p3), p4_(p4)
	{
	}

	virtual void operator()() {
		t_(p1_,p2_,p3_,p4_);
	}

private:

	const T& t_;
	P1 p1_;
	P2 p2_;
	P3 p3_;
	P4 p4_;
};

template<class T, class P1, class P2, class P3>
class AsyncCodeBlock<T,P1,P2,P3,void,void,void> : public AsyncCodeBlockBase
{
public:
	AsyncCodeBlock( const T& t, P1 p1, P2 p2, P3 p3) 
		: t_(t), p1_(p1), p2_(p2), p3_(p3)
	{
	}

	virtual void operator()() {
		t_(p1_,p2_,p3_);
	}

private:

	const T& t_;
	P1 p1_;
	P2 p2_;
	P3 p3_;
};

template<class T, class P1, class P2>
class AsyncCodeBlock<T,P1,P2,void,void,void,void> : public AsyncCodeBlockBase
{
public:
	AsyncCodeBlock( const T& t, P1 p1, P2 p2) 
		: t_(t), p1_(p1), p2_(p2)
	{
	}

	virtual void operator()() {
		t_(p1_,p2_);
	}

private:

	const T& t_;
	P1 p1_;
	P2 p2_;
};

template<class T, class P1>
class AsyncCodeBlock<T,P1,void,void,void,void,void> : public AsyncCodeBlockBase
{
public:
	AsyncCodeBlock( const T& t, P1 p1) 
		: t_(t), p1_(p1)
	{
	}

	virtual void operator()() {
		t_(p1_);
	}

private:

	const T& t_;
	P1 p1_;
};


template<class T>
class AsyncCodeBlock<T,void,void,void,void,void,void> : public AsyncCodeBlockBase
{
public:
	AsyncCodeBlock( const T& t) 
		: t_(t)
	{
	}

	virtual void operator()() {
		t_();
	}

private:

	const T& t_;
};


template<class T, class P1,  class P2,  class P3,  class P4, class P5, class P6> 
AsyncCodeBlockBase* async_code_block(const T& t, P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6) 
{
	return new AsyncCodeBlock<T,P1,P2,P3,P4,P5,P6>(t,p1,p2,p3,p4,p5,p6);
}

template<class T, class P1,  class P2,  class P3,  class P4, class P5> 
AsyncCodeBlockBase* async_code_block(const T& t, P1 p1, P2 p2, P3 p3, P4 p4, P5 p5) 
{
	return new AsyncCodeBlock<T,P1,P2,P3,P4,P5>(t,p1,p2,p3,p4,p5);
}

template<class T, class P1,  class P2,  class P3,  class P4> 
AsyncCodeBlockBase* async_code_block(const T& t, P1 p1, P2 p2, P3 p3, P4 p4) 
{
	return new AsyncCodeBlock<T,P1,P2,P3,P4>(t,p1,p2,p3,p4);
}

template<class T, class P1,  class P2,  class P3> 
AsyncCodeBlockBase* async_code_block(const T& t, P1 p1, P2 p2, P3 p3) 
{
	return new AsyncCodeBlock<T,P1,P2,P3>(t,p1,p2,p3);
}

template<class T, class P1,  class P2> 
AsyncCodeBlockBase* async_code_block(const T& t, P1 p1, P2 p2) 
{
	return new AsyncCodeBlock<T,P1,P2>(t,p1,p2);
}

template<class T, class P1> 
AsyncCodeBlockBase* async_code_block(const T& t, P1 p1) 
{
	return new AsyncCodeBlock<T,P1>(t,p1);
}

template<class T> 
AsyncCodeBlockBase* async_code_block(const T& t) 
{
	return new AsyncCodeBlock<T>(t);
}

*/

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
	run_on_gui_thread_impl(new AsyncCodeBlock<T>(t)) ;
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
	mol::fun::task* task = mol::fun::make_task( boost::bind(f,&t) );
	t.postMessage(WM_INVOKE,0,(LPARAM)task);
}

template<class T, class R, class P1>
void dispatch( T& t, R (T::*f)(P1), P1 p1 )
{
	mol::fun::task* task = mol::fun::make_task( boost::bind(f,&t,p1) );	
	t.postMessage(WM_INVOKE,0,(LPARAM)task);
}

template<class T, class R, class P1, class P2>
void dispatch( T& t, R (T::*f)(P1,P2), P1 p1, P2 p2  )
{
	mol::fun::task* task = mol::fun::make_task( boost::bind(f,&t,p1,p2) );
	t.postMessage(WM_INVOKE,0,(LPARAM)task);
}

template<class T, class R, class P1, class P2, class P3>
void dispatch( T& t, R (T::*f)(P1,P2,P3), P1 p1, P2 p2, P3 p3 )
{
	mol::fun::task* task = mol::fun::make_task( boost::bind(f,&t,p1,p2,p3) );
	t.postMessage(WM_INVOKE,0,(LPARAM)task);
}

template<class T, class R, class P1, class P2, class P3, class P4>
void dispatch( T& t, R (T::*f)(P1,P2,P3,P4), P1 p1, P2 p2, P3 p3, P4 p4  )
{
	mol::fun::task* task = mol::fun::make_task( boost::bind(f,&t,p1,p2,p3,p4) );
	t.postMessage(WM_INVOKE,0,(LPARAM)task);
}



} // endnamespace mol



#endif


