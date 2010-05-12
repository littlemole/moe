#ifndef MOL_ASYNC_DEF_GUARD_DEF_
#define MOL_ASYNC_DEF_GUARD_DEF_

//#include "thread/fun.h"
#include "thread/call.h"
#include "thread/systhread.h"

namespace mol {

///////////////////////////////////////////////////////////////////////
// for each num of params (0..6), define
// - thread on member-func with return function on separate obj
// - thread on member-func with return function on same obj
// - thread on member-func with c return function 
// - thread on member-func w/o return function
// - c-stlye thread  w/o return function
// - c-stlye thread  w/ c return function
// - c-stlye thread  w/ member return function
//
// happy repition sake convenience-functions
///////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////
// thread member Calls w/o params
///////////////////////////////////////////////////////////////////////

// thread with return function on separate obj

template<class T, class TR, class R, class F>
int thread( T& obj, R (T::*f)() ,TR& retObj,F r)
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,T,TR,R>(&obj, f, &retObj, r) );
}

// thread with return function on same obj

template<class T, class R, class F>
int thread( T& obj, R (T::*f)(), F r)
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,T,T,R>(&obj, f, &obj, r) );
}

// thread with c return function 

template<class T, class R>
int thread( T& obj, 
				R (T::*f)(),
				void (*r)(R) )
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,T,void,R>(&obj, f, 0, r) );
}

// thread w/o return function

template<class T, class R>
int thread( T& obj, 
				R (T::*f)() )
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,T,T,R>(&obj, f) );
}

///////////////////////////////////////////////////////////////////////////
// c-stlye thread  w/o params
///////////////////////////////////////////////////////////////////////////

// c-stlye thread  w/o return function

template<class R>
int thread( R (*f)() )
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,void,void,R>(0,f) );
}

// c-stlye thread  w/ c return function

template<class R, class F>
int thread( R (*f)() , F r)
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,void,void,R>(0,f,0, r) );
}

// c-stlye thread  w/ member return function

template<class R, class TR, class F>
int thread( R (*f)() , TR& tr, F r)
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,void,TR,R>( 0, f, &tr, r ) );
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////
// async member Calls w/ 1 param
///////////////////////////////////////////////////////////////////////

// thread with return function on separate obj

template<class T, class TR, class R, class P1, class F>
int thread( T& obj, 
				R (T::*f)(P1), 
				typename mol::threading::Func<T,R,P1>::Param1Type p1, 
				TR& retObj,
				F r )
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,T,TR,R,P1>(&obj, f, p1, &retObj, r) );
}

// thread with return function on same obj

template<class T, class R, class P1, class F>
int thread( T& obj, 
				R (T::*f)(P1), 
				typename mol::threading::Func<T,R,P1>::Param1Type p1, 
				F r )
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,T,T,R,P1>(&obj, f, p1,&obj, r) );
}

// thread with c return function 

template<class T, class R, class P1>
int thread( T& obj, 
				R (T::*f)(P1),
				typename mol::threading::Func<T,R,P1>::Param1Type p1, 
				void (*r)(R) )
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,T,void,R,P1>(&obj, f, p1, 0 , r) );
}

// thread w/o return function

template<class T, class R, class P1>
int thread( T& obj, 
				R (T::*f)(P1),
				typename mol::threading::Func<T,R,P1>::Param1Type p1  )
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,T,T,R,P1>(&obj, f, p1) );
}

///////////////////////////////////////////////////////////////////////////
// c-stlye thread  w/ 1 params
///////////////////////////////////////////////////////////////////////////

// c-stlye thread  w/o return function

template<class R, class P1>
int thread( R (*f)(P1),
				typename mol::threading::Func<void,R,P1>::Param1Type p1 )
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,void,void,R,P1>(0, f, p1) );
}

// c-stlye thread  w/ c return function

template<class R, class P1, class F>
int thread( R (*f)(P1) ,
				typename mol::threading::Func<void,R,P1>::Param1Type p1,
				F r)
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,void,void,R,P1>(0, f, p1,0, r) );
}

// c-stlye thread  w/ member return function

template<class R,class P1, class TR,  class F>
int thread( R (*f)(P1), 
				typename mol::threading::Func<void,R,P1>::Param1Type p1,
				TR& tr, F r)
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,void,TR,R,P1>( 0, f, p1, &tr, r) );
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////
// async member Calls w/ 2 param
///////////////////////////////////////////////////////////////////////

// thread with return function on separate obj

template<class T, class TR, class R, class P1, class P2, class F>
int thread( T& obj, 
				R (T::*f)(P1,P2), 
				typename mol::threading::Func<T,R,P1,P2>::Param1Type p1, 
				typename mol::threading::Func<T,R,P1,P2>::Param2Type p2, 
				TR& retObj,
				F r )
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,T,TR,R,P1,P2>(&obj, f, p1,p2, &retObj, r) );
}

// thread with return function on same obj

template<class T, class R, class P1, class P2, class F>
int thread( T& obj, 
				R (T::*f)(P1,P2), 
				typename mol::threading::Func<T,R,P1,P2>::Param1Type p1, 
				typename mol::threading::Func<T,R,P1,P2>::Param2Type p2, 
				F r )
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,T,T,R,P1,P2>(&obj, f, p1,p2, &obj, r) );
}

// thread with c return function 

template<class T, class R, class P1, class P2>
int thread( T& obj, 
				R (T::*f)(P1,P2),
				typename mol::threading::Func<T,R,P1,P2>::Param1Type p1, 
				typename mol::threading::Func<T,R,P1,P2>::Param2Type p2, 
				void (*r)(R) )
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,T,void,R,P1,P2>(&obj, f, p1,p2, 0, r) );
}

// thread w/o return function

template<class T, class R, class P1, class P2>
int thread( T& obj, 
				R (T::*f)(P1,P2),
				typename mol::threading::Func<T,R,P1,P2>::Param1Type p1,
				typename mol::threading::Func<T,R,P1,P2>::Param2Type p2  )
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,T,T,R,P1,P2>(&obj, f, p1,p2) );
}

///////////////////////////////////////////////////////////////////////////
// c-stlye thread  w/ 2 params
///////////////////////////////////////////////////////////////////////////

// c-stlye thread  w/o return function

template<class R, class P1, class P2>
int thread( R (*f)(P1,P2),
				typename mol::threading::Func<void,R,P1,P2>::Param1Type p1,
				typename mol::threading::Func<void,R,P1,P2>::Param2Type p2 )
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,void,void,R,P1,P2>(0,  f, p1,p2) );
}

// c-stlye thread  w/ c return function

template<class R, class P1, class P2, class F>
int thread( R (*f)(P1,P2),
				typename mol::threading::Func<void,R,P1,P2>::Param1Type p1,
				typename mol::threading::Func<void,R,P1,P2>::Param2Type p2,
				F r)
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,void,void,R,P1,P2>(0,  f, p1,p2,0, r) );
}

// c-stlye thread  w/ member return function

template<class R, class TR, class P1, class P2, class F>
int thread( R (*f)(P1,P2), 
				typename mol::threading::Func<void,R,P1,P2>::Param1Type p1,
				typename mol::threading::Func<void,R,P1,P2>::Param2Type p2,
				TR& tr, 
				F r)
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,void,TR,R,P1,P2>(0, f, p1,p2, &tr, r) );
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////
// async member Calls w/ 3 param
///////////////////////////////////////////////////////////////////////

// thread with return function on separate obj

template<class T, class TR, class R, class P1, class P2, class P3, class F>
int thread( T& obj, 
				R (T::*f)(P1,P2,P3),
				typename mol::threading::Func<T,R,P1,P2,P3>::Param1Type p1, 
				typename mol::threading::Func<T,R,P1,P2,P3>::Param2Type p2, 
				typename mol::threading::Func<T,R,P1,P2,P3>::Param3Type p3, 
				TR& retObj,
				F r )
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,T,TR,R,P1,P2,P3>(&obj, f, p1,p2,p3, &retObj, r) );
}

// thread with return function on same obj

template<class T, class R, class P1, class P2, class P3, class F>
int thread( T& obj, 
				R (T::*f)(P1,P2,P3), 
				typename mol::threading::Func<T,R,P1,P2,P3>::Param1Type p1, 
				typename mol::threading::Func<T,R,P1,P2,P3>::Param2Type p2, 
				typename mol::threading::Func<T,R,P1,P2,P3>::Param3Type p3, 
				F r )
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,T,T,R,P1,P2,P3>(&obj, f, p1,p2,p3, &obj, r) );

}

// thread with c return function 

template<class T, class R, class P1, class P2, class P3>
int thread( T& obj, 
				R (T::*f)(P1,P2,P3),
				typename mol::threading::Func<T,R,P1,P2,P3>::Param1Type p1, 
				typename mol::threading::Func<T,R,P1,P2,P3>::Param2Type p2, 
				typename mol::threading::Func<T,R,P1,P2,P3>::Param3Type p3, 
				void (*r)(R) )
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,T,void,R,P1,P2,P3>(&obj, f, p1,p2,p3, 0, r) );

}

// thread w/o return function

template<class T, class R, class P1, class P2, class P3>
int thread( T& obj, 
				R (T::*f)(P1,P2,P3),
				typename mol::threading::Func<T,R,P1,P2,P3>::Param1Type p1,
				typename mol::threading::Func<T,R,P1,P2,P3>::Param2Type p2,
				typename mol::threading::Func<T,R,P1,P2,P3>::Param3Type p3  )
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,T,T,R,P1,P2,P3>(&obj, f, p1,p2,p3) );

}

///////////////////////////////////////////////////////////////////////////
// c-stlye thread  w/ 3 params
///////////////////////////////////////////////////////////////////////////

// c-stlye thread  w/o return function

template<class R, class P1, class P2, class P3>
int thread( R (*f)(P1,P2,P3),
				typename mol::threading::Func<void,R,P1,P2,P3>::Param1Type p1,
				typename mol::threading::Func<void,R,P1,P2,P3>::Param2Type p2,
				typename mol::threading::Func<void,R,P1,P2,P3>::Param3Type p3 )
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,void,void,R,P1,P2,P3>( 0, f, p1,p2,p3) );

}

// c-stlye thread  w/ c return function

template<class R, class P1, class P2, class P3, class F>
int thread( R (*f)(P1,P2,P3),
				typename mol::threading::Func<void,R,P1,P2,P3>::Param1Type p1,
				typename mol::threading::Func<void,R,P1,P2,P3>::Param2Type p2,
				typename mol::threading::Func<void,R,P1,P2,P3>::Param3Type p3,
				F r)
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,void,void,R,P1,P2,P3>( 0, f, p1,p2,p3, 0, r) );

}

// c-stlye thread  w/ member return function

template<class R, class TR, class P1, class P2, class P3, class F>
int thread( R (*f)(P1,P2,P3), 
				typename mol::threading::Func<void,R,P1,P2,P3>::Param1Type p1,
				typename mol::threading::Func<void,R,P1,P2,P3>::Param2Type p2,
				typename mol::threading::Func<void,R,P1,P2,P3>::Param3Type p3,
				TR& tr, 
				F r)
{
	//typedef typename mol::Call<mol::threading::HeapDeletePolicy,void,TR,R,P1,P2,P3> AsyncType;
	//AsyncType* call = new AsyncType(0, f, p1,p2, p3,&tr, r);
	//mol::asyncThread( call );
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,void,TR,R,P1,P2,P3>(0, f, p1,p2,p3, &tr, r) );

}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////






///////////////////////////////////////////////////////////////////////
// async member Calls w/ 4 params
///////////////////////////////////////////////////////////////////////

// thread with return function on separate obj

template<class T, class TR, class R, class P1, class P2, class P3, class P4, class F>
int thread( T& obj, 
				R (T::*f)(P1,P2,P3,P4), 
				typename mol::threading::Func<T,R,P1,P2,P3,P4>::Param1Type p1, 
				typename mol::threading::Func<T,R,P1,P2,P3,P4>::Param2Type p2, 
				typename mol::threading::Func<T,R,P1,P2,P3,P4>::Param3Type p3, 
				typename mol::threading::Func<T,R,P1,P2,P3,P4>::Param4Type p4, 
				TR& retObj,
				F r )
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,T,TR,R,P1,P2,P3,P4>(&obj, f, p1,p2,p3,p4, &retObj, r) );

}

// thread with return function on same obj

template<class T, class R, class P1, class P2, class P3, class P4, class F>
int thread( T& obj, 
				R (T::*f)(P1,P2,P3,P4), 
				typename mol::threading::Func<T,R,P1,P2,P3,P4>::Param1Type p1, 
				typename mol::threading::Func<T,R,P1,P2,P3,P4>::Param2Type p2, 
				typename mol::threading::Func<T,R,P1,P2,P3,P4>::Param3Type p3, 
				typename mol::threading::Func<T,R,P1,P2,P3,P4>::Param4Type p4, 
				F r )
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,T,T,R,P1,P2,P3,P4>(&obj, f, p1,p2,p3,p4, &obj, r) );
}

// thread with c return function 

template<class T, class R, class P1, class P2, class P3, class P4>
int thread( T& obj, 
				R (T::*f)(P1,P2,P3,P4),
				typename mol::threading::Func<T,R,P1,P2,P3,P4>::Param1Type p1, 
				typename mol::threading::Func<T,R,P1,P2,P3,P4>::Param2Type p2, 
				typename mol::threading::Func<T,R,P1,P2,P3,P4>::Param3Type p3, 
				typename mol::threading::Func<T,R,P1,P2,P3,P4>::Param4Type p4, 
				void (*r)(R))
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,T,void,R,P1,P2,P3,P4>(&obj, f, p1,p2,p3,p4, 0, r) );
}

// thread w/o return function

template<class T, class R, class P1, class P2, class P3, class P4>
int thread( T& obj, 
				R (T::*f)(P1,P2,P3,P4),
				typename mol::threading::Func<T,R,P1,P2,P3,P4>::Param1Type p1,
				typename mol::threading::Func<T,R,P1,P2,P3,P4>::Param2Type p2,
				typename mol::threading::Func<T,R,P1,P2,P3,P4>::Param3Type p3,
				typename mol::threading::Func<T,R,P1,P2,P3,P4>::Param4Type p4  )
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,T,T,R,P1,P2,P3,P4>(&obj, f, p1,p2,p3,p4) );
}

///////////////////////////////////////////////////////////////////////////
// c-stlye thread  w/ 4 params
///////////////////////////////////////////////////////////////////////////

// c-stlye thread  w/o return function

template<class R, class P1, class P2, class P3, class P4>
int thread( R (*f)(P1,P2,P3,P4),
				typename mol::threading::Func<void,R,P1,P2,P3,P4>::Param1Type p1,
				typename mol::threading::Func<void,R,P1,P2,P3,P4>::Param2Type p2,
				typename mol::threading::Func<void,R,P1,P2,P3,P4>::Param3Type p3,
				typename mol::threading::Func<void,R,P1,P2,P3,P4>::Param4Type p4 )
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,void,void,R,P1,P2,P3,P4>(0, f, p1,p2,p3,p4) );
}

// c-stlye thread  w/ c return function

template<class R, class P1, class P2, class P3, class P4, class F>
int thread( R (*f)(P1,P2,P3,P4) ,
				typename mol::threading::Func<void,R,P1,P2,P3,P4>::Param1Type p1,
				typename mol::threading::Func<void,R,P1,P2,P3,P4>::Param2Type p2,
				typename mol::threading::Func<void,R,P1,P2,P3,P4>::Param3Type p3,
				typename mol::threading::Func<void,R,P1,P2,P3,P4>::Param4Type p4,
				F r)
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,void,void,R,P1,P2,P3,P4>( 0, f, p1,p2,p3,p4,0, r) );
}

// c-stlye thread  w/ member return function

template<class R, class TR, class P1, class P2, class P3, class P4, class F>
int thread( R (*f)(P1,P2,P3,P4), 
				typename mol::threading::Func<void,R,P1,P2,P3,P4>::Param1Type p1,
				typename mol::threading::Func<void,R,P1,P2,P3,P4>::Param2Type p2,
				typename mol::threading::Func<void,R,P1,P2,P3,P4>::Param3Type p3,
				typename mol::threading::Func<void,R,P1,P2,P3,P4>::Param4Type p4,
				TR& tr, 
				F r)
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,void,TR,R,P1,P2,P3,P4>(0, f, p1,p2,p3,p4, &tr, r) );
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// async member Calls w/ 5 params
///////////////////////////////////////////////////////////////////////

// thread with return function on separate obj

template<class T, class TR, class R, class P1, class P2, class P3, class P4, class P5, class F>
int thread( T& obj, 
				R (T::*f)(P1,P2,P3,P4,P5), 
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5>::Param1Type p1, 
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5>::Param2Type p2, 
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5>::Param3Type p3, 
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5>::Param4Type p4, 
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5>::Param5Type p5, 
				TR& retObj,
				F r )
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,T,TR,R,P1,P2,P3,P4,P5>(&obj, f, p1,p2,p3,p4,p5, &retObj, r) );
}

// thread with return function on same obj

template<class T, class R, class P1, class P2, class P3, class P4, class P5, class F>
int thread( T& obj, 
				R (T::*f)(P1,P2,P3,P4,P5), 
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5>::Param1Type p1, 
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5>::Param2Type p2, 
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5>::Param3Type p3, 
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5>::Param4Type p4, 
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5>::Param5Type p5, 
				F r )
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,T,T,R,P1,P2,P3,P4,P5>(&obj, f, p1,p2,p3,p4,p5, &obj, r) );
}

// thread with c return function 

template<class T, class R, class P1, class P2, class P3, class P4, class P5>
int thread( T& obj, 
				R (T::*f)(P1,P2,P3,P4,P5),
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5>::Param1Type p1, 
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5>::Param2Type p2, 
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5>::Param3Type p3, 
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5>::Param4Type p4, 
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5>::Param5Type p5, 
				void (*r)(R))
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,T,void,R,P1,P2,P3,P4,P5>(&obj, f, p1,p2,p3,p4,p5, 0, r) );
}

// thread w/o return function

template<class T, class R, class P1, class P2, class P3, class P4, class P5>
int thread( T& obj, 
				R (T::*f)(P1,P2,P3,P4,P5),
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5>::Param1Type p1,
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5>::Param2Type p2,
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5>::Param3Type p3,
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5>::Param4Type p4,
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5>::Param5Type p5  )
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,T,T,R,P1,P2,P3,P4,P5>(&obj, f, p1,p2,p3,p4,p5) );
}

///////////////////////////////////////////////////////////////////////////
// c-stlye thread  w/ 5 params
///////////////////////////////////////////////////////////////////////////

// c-stlye thread  w/o return function

template<class R, class P1, class P2, class P3, class P4, class P5>
int thread( R (*f)(P1,P2,P3,P4,P5),
				typename mol::threading::Func<void,R,P1,P2,P3,P4,P5>::Param1Type p1,
				typename mol::threading::Func<void,R,P1,P2,P3,P4,P5>::Param2Type p2,
				typename mol::threading::Func<void,R,P1,P2,P3,P4,P5>::Param3Type p3,
				typename mol::threading::Func<void,R,P1,P2,P3,P4,P5>::Param4Type p4,
				typename mol::threading::Func<void,R,P1,P2,P3,P4,P5>::Param5Type p5 )
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,void,void,R,P1,P2,P3,P4,P5>(0, f, p1,p2,p3,p4,p5) );
}

// c-stlye thread  w/ c return function

template<class R, class P1, class P2, class P3, class P4, class P5,class F>
int thread( R (*f)(P1,P2,P3,P4,P5),
				typename mol::threading::Func<void,R,P1,P2,P3,P4,P5>::Param1Type p1,
				typename mol::threading::Func<void,R,P1,P2,P3,P4,P5>::Param2Type p2,
				typename mol::threading::Func<void,R,P1,P2,P3,P4,P5>::Param3Type p3,
				typename mol::threading::Func<void,R,P1,P2,P3,P4,P5>::Param4Type p4,
				typename mol::threading::Func<void,R,P1,P2,P3,P4,P5>::Param5Type p5,
				F r)
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,void,void,R,P1,P2,P3,P4,P5>( 0, f, p1,p2,p3,p4,p5,0, r) );
}

// c-stlye thread  w/ member return function

template<class R, class TR, class P1, class P2, class P3, class P4, class P5, class F>
int thread( R (*f)(P1,P2,P3,P4,P5), 
				typename mol::threading::Func<void,R,P1,P2,P3,P4,P5>::Param1Type p1,
				typename mol::threading::Func<void,R,P1,P2,P3,P4,P5>::Param2Type p2,
				typename mol::threading::Func<void,R,P1,P2,P3,P4,P5>::Param3Type p3,
				typename mol::threading::Func<void,R,P1,P2,P3,P4,P5>::Param4Type p4,
				typename mol::threading::Func<void,R,P1,P2,P3,P4,P5>::Param5Type p5,
				TR& tr, 
				F r)
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,void,TR,R,P1,P2,P3,P4,P5>( 0, f, p1,p2,p3,p4,p5, &tr, r) );
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////
// async member Calls w/ 6 params
///////////////////////////////////////////////////////////////////////

// thread with return function on separate obj

template<class T, class TR, class R, class P1, class P2, class P3, class P4, class P5, class P6, class F>
int thread( T& obj, 
				R (T::*f)(P1,P2,P3,P4,P5), 
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5,P6>::Param1Type p1, 
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5,P6>::Param2Type p2, 
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5,P6>::Param3Type p3, 
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5,P6>::Param4Type p4, 
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5,P6>::Param5Type p5, 
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5,P6>::Param6Type p6, 
				TR& retObj,
				F r )
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,T,TR,R,P1,P2,P3,P4,P5,P6>(&obj, f, p1,p2,p3,p4,p5,p6, &retObj, r) );
}

// thread with return function on same obj

template<class T, class R, class P1, class P2, class P3, class P4, class P5, class P6, class F>
int thread( T& obj, 
				R (T::*f)(P1,P2,P3,P4,P5), 
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5,P6>::Param1Type p1, 
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5,P6>::Param2Type p2, 
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5,P6>::Param3Type p3, 
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5,P6>::Param4Type p4, 
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5,P6>::Param5Type p5, 
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5,P6>::Param6Type p6, 
				F r )
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,T,T,R,P1,P2,P3,P4,P5,P6>(&obj, f, p1,p2,p3,p4,p5,p6, &obj, r) );
}

// thread with c return function 

template<class T, class R, class P1, class P2, class P3, class P4, class P5, class P6>
int thread( T& obj, 
				R (T::*f)(P1,P2,P3,P4,P5),
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5,P6>::Param1Type p1, 
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5,P6>::Param2Type p2, 
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5,P6>::Param3Type p3, 
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5,P6>::Param4Type p4, 
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5,P6>::Param5Type p5, 
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5,P6>::Param6Type p6, 
				void (*r)(R) )
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,T,void,R,P1,P2,P3,P4,P5,P6>(&obj, f, p1,p2,p3,p4,p5,p6, 0, r) );
}

// thread w/o return function

template<class T, class R, class P1, class P2, class P3, class P4, class P5, class P6>
int thread( T& obj, 
				R (T::*f)(P1,P2,P3,P4,P5),
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5,P6>::Param1Type p1,
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5,P6>::Param2Type p2,
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5,P6>::Param3Type p3,
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5,P6>::Param4Type p4,
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5,P6>::Param5Type p5,
				typename mol::threading::Func<T,R,P1,P2,P3,P4,P5,P6>::Param6Type p6  )
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,T,T,R,P1,P2,P3,P4,P5,P6>(&obj, f, p1,p2,p3,p4,p5,p6) );
}

///////////////////////////////////////////////////////////////////////////
// c-stlye thread  w/ 6 params
///////////////////////////////////////////////////////////////////////////

// c-stlye thread  w/o return function

template<class R, class P1, class P2, class P3, class P4, class P5, class P6>
int thread( R (*f)(P1,P2,P3,P4,P5),
				typename mol::threading::Func<void,R,P1,P2,P3,P4,P5,P6>::Param1Type p1,
				typename mol::threading::Func<void,R,P1,P2,P3,P4,P5,P6>::Param2Type p2,
				typename mol::threading::Func<void,R,P1,P2,P3,P4,P5,P6>::Param3Type p3,
				typename mol::threading::Func<void,R,P1,P2,P3,P4,P5,P6>::Param4Type p4,
				typename mol::threading::Func<void,R,P1,P2,P3,P4,P5,P6>::Param5Type p5,
				typename mol::threading::Func<void,R,P1,P2,P3,P4,P5,P6>::Param6Type p6  )
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,void,void,R,P1,P2,P3,P4,P5,P6>( 0, f, p1,p2,p3,p4,p5,p6) );
}

// c-stlye thread  w/ c return function

template<class R, class P1, class P2, class P3, class P4, class P5, class P6, class F>
int thread( R (*f)(P1,P2,P3,P4,P5),
				typename mol::threading::Func<void,R,P1,P2,P3,P4,P5,P6>::Param1Type p1,
				typename mol::threading::Func<void,R,P1,P2,P3,P4,P5,P6>::Param2Type p2,
				typename mol::threading::Func<void,R,P1,P2,P3,P4,P5,P6>::Param3Type p3,
				typename mol::threading::Func<void,R,P1,P2,P3,P4,P5,P6>::Param4Type p4,
				typename mol::threading::Func<void,R,P1,P2,P3,P4,P5,P6>::Param5Type p5,
				typename mol::threading::Func<void,R,P1,P2,P3,P4,P5,P6>::Param6Type p6,
				F r)
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,void,void,R,P1,P2,P3,P4,P5,P6>( 0, f, p1,p2,p3,p4,p5,p6,0, r) );
}

// c-stlye thread  w/ member return function

template<class R, class TR, class P1, class P2, class P3, class P4, class P5, class P6, class F>
int thread( R (*f)(P1,P2,P3,P4,P5) , 
				typename mol::threading::Func<void,R,P1,P2,P3,P4,P5,P6>::Param1Type p1,
				typename mol::threading::Func<void,R,P1,P2,P3,P4,P5,P6>::Param2Type p2,
				typename mol::threading::Func<void,R,P1,P2,P3,P4,P5,P6>::Param3Type p3,
				typename mol::threading::Func<void,R,P1,P2,P3,P4,P5,P6>::Param4Type p4,
				typename mol::threading::Func<void,R,P1,P2,P3,P4,P5,P6>::Param5Type p5,
				typename mol::threading::Func<void,R,P1,P2,P3,P4,P5,P6>::Param6Type p6,
				TR& tr, 
				F r)
{
	return (new mol::Thread)->start( new mol::Call<mol::threading::HeapDeletePolicy,void,TR,R,P1,P2,P3,P4,P5,P6>( 0, f, p1,p2,p3,p4,p5,p6, &tr, r) );
}

} // end namspace mol


#endif
