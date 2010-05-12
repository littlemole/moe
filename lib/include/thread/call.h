#ifndef MOL_DEF_GUARD_CALL_GUARD_H
#define MOL_DEF_GUARD_CALL_GUARD_H

#include "thread/invoke.h"

namespace mol {

namespace threading {

///////////////////////////////////////////////////////////////////////////////
// basic Stack / Heap Policies
///////////////////////////////////////////////////////////////////////////////

struct StackDeletePolicy
{
    template<class T>
    static void release( T* t)
    {}
};

struct HeapDeletePolicy
{
    template<class T>
    static void release( T* t)
    {
		delete t;
    }
};

///////////////////////////////////////////////////////////////////////////////
// Generate ReturnFunction Type from object and thread func return type
///////////////////////////////////////////////////////////////////////////////
 
template<class T,class R>
class RetFuncTypeTraits
{
public:
	typedef typename mol::threading::Func<T,void,R> RetFuncType;
};

template<class T>
class RetFuncTypeTraits<T,void>
{
public:
	typedef typename mol::threading::Func<T,void> RetFuncType;
};

template<class R>
class RetFuncTypeTraits<void,R>
{
public:
	typedef typename mol::threading::Func<void,void,R> RetFuncType;
};

template<>
class RetFuncTypeTraits<void,void>
{
public:
	typedef mol::threading::Func<void,void,void> RetFuncType;
};

///////////////////////////////////////////////////////////////////////////////

struct EmptyType
{
};

///////////////////////////////////////////////////////////////////////////////

template<class T>
class Param
{
public:
	typedef T Type;

	Param() {}
	Param(T t) : Value(t) {}

	T Value;
};

template<>
class Param<void>
{
public:
	typedef EmptyType Type;

	EmptyType Value;
};

///////////////////////////////////////////////////////////////////////////////
// Base - or what is a call ? something callable.
///////////////////////////////////////////////////////////////////////////////

class CallBase
{
public:
	virtual ~CallBase() {};
	virtual void operator()() = 0;
};

} // end namespace threading

///////////////////////////////////////////////////////////////////////////////
// Call Wrapper for calls with 6 param
///////////////////////////////////////////////////////////////////////////////

template<
		 class D  = mol::threading::HeapDeletePolicy,
		 class T  = void, 
		 class TR = void, 
		 class R  = void, 
		 class P1 = void, 
		 class P2 = void, 
		 class P3 = void, 
		 class P4 = void, 
		 class P5 = void, 
		 class P6 = void
>
class Call : public mol::threading::CallBase 
{
public:
	typedef Call<D,T,TR,R,P1,P2,P3,P4,P5,P6>				ThisType;
	typedef T												ObjectType;
	typedef mol::threading::Func<T,R,P1,P2,P3,P4,P5,P6>		FuncType;
	typedef TR												RetObjectType;
	typedef typename mol::threading::
			RetFuncTypeTraits<TR,R>::RetFuncType 			RetFuncType;	
	typedef R												RetType;
	typedef mol::threading::Param<P1> 						Param1Type;
	typedef mol::threading::Param<P2> 						Param2Type;
	typedef mol::threading::Param<P3> 						Param3Type;
	typedef mol::threading::Param<P4> 						Param4Type;
	typedef mol::threading::Param<P5> 						Param5Type;
	typedef mol::threading::Param<P6> 						Param6Type;
	typedef D												DeletePolicy;

	///////////////////////////////////////////////////////////////////////////////

	Call( T* t, FuncType f, typename Param1Type::Type p1, typename Param2Type::Type p2, typename Param3Type::Type p3, typename Param4Type::Type p4, typename Param5Type::Type p5, typename Param6Type::Type p6, TR* tr, RetFuncType r )
		: object(t), func(f), retObj(tr), retFunc(0), Param1(p1), Param2(p2), Param3(p3), Param4(p4), Param5(p5), Param6(p6)
	{		
		retFunc = new RetFuncType(r);
	}

	Call( T* t, FuncType f, typename Param1Type::Type p1, typename Param2Type::Type p2, typename Param3Type::Type p3, typename Param4Type::Type p4, typename Param5Type::Type p5,typename  Param6Type::Type p6)
		: object(t), func(f), retObj(0), retFunc(0), Param1(p1), Param2(p2), Param3(p3), Param4(p4), Param5(p5), Param6(p6)
	{}

	///////////////////////////////////////////////////////////////////////////////

	Call( T* t, FuncType f, typename Param1Type::Type p1,typename  Param2Type::Type p2, typename Param3Type::Type p3, typename Param4Type::Type p4, typename Param5Type::Type p5, TR* tr, RetFuncType r )
		: object(t), func(f), retObj(tr), retFunc(0), Param1(p1), Param2(p2), Param3(p3), Param4(p4), Param5(p5)
	{		
		retFunc = new RetFuncType(r);
	}

	Call( T* t, FuncType f, typename Param1Type::Type p1, typename Param2Type::Type p2, typename Param3Type::Type p3, typename Param4Type::Type p4, typename Param5Type::Type p5)
		: object(t), func(f), retObj(0), retFunc(0), Param1(p1), Param2(p2), Param3(p3), Param4(p4), Param5(p5)
	{}

	///////////////////////////////////////////////////////////////////////////////

	Call( T* t, FuncType f, typename Param1Type::Type p1, typename Param2Type::Type p2, typename Param3Type::Type p3, typename Param4Type::Type p4, TR* tr, RetFuncType r )
		: object(t), func(f), retObj(tr), retFunc(0), Param1(p1), Param2(p2), Param3(p3), Param4(p4)
	{		
		retFunc = new RetFuncType(r);
	}

	Call( T* t, FuncType f,typename  Param1Type::Type p1,typename  Param2Type::Type p2,typename  Param3Type::Type p3,typename  Param4Type::Type p4)
		: object(t), func(f), retObj(0), retFunc(0), Param1(p1), Param2(p2), Param3(p3), Param4(p4)
	{}

	///////////////////////////////////////////////////////////////////////////////

	Call( T* t, FuncType f, typename Param1Type::Type p1,typename  Param2Type::Type p2, typename Param3Type::Type p3, TR* tr, RetFuncType r )
		: object(t), func(f), retObj(tr), retFunc(0), Param1(p1), Param2(p2), Param3(p3)
	{		
		retFunc = new RetFuncType(r);
	}

	Call( T* t, FuncType f, typename Param1Type::Type p1, typename Param2Type::Type p2,typename  Param3Type::Type p3)
		: object(t), func(f), retObj(0), retFunc(0), Param1(p1), Param2(p2), Param3(p3)
	{}

	///////////////////////////////////////////////////////////////////////////////

	Call( T* t, FuncType f, typename Param1Type::Type p1,typename  Param2Type::Type p2, TR* tr, RetFuncType r )
		: object(t), func(f), retObj(tr), retFunc(0), Param1(p1), Param2(p2)
	{		
		retFunc = new RetFuncType(r);
	}

	Call( T* t, FuncType f, typename Param1Type::Type p1,typename  Param2Type::Type p2)
		: object(t), func(f), retObj(0), retFunc(0), Param1(p1), Param2(p2)
	{}

	///////////////////////////////////////////////////////////////////////////////

	Call( T* t, FuncType f, typename Param1Type::Type p1, TR* tr, RetFuncType r )
		: object(t), func(f), retObj(tr), retFunc(0), Param1(p1)
	{		
		retFunc = new RetFuncType(r);
	}

	Call( T* t, FuncType f, typename Param1Type::Type p1)
		: object(t), func(f), retObj(0), retFunc(0), Param1(p1)
	{}

	Call( T* t, FuncType f, TR* tr, RetFuncType r )
		: object(t), func(f), retObj(tr), retFunc(0)
	{		
		retFunc = new RetFuncType(r);
	}

	Call( T* t, FuncType f)
		: object(t), func(f), retObj(0), retFunc(0)
	{}

	///////////////////////////////////////////////////////////////////////////////

	virtual void operator()()
	{
		mol::threading::InvokePolicy<T,R,P1,P2,P3,P4,P5,P6>::invoke(this);
		mol::threading::InvokePolicy<TR,R,P1,P2,P3,P4,P5,P6>::callback(this);
		DeletePolicy::release(this);
	}

	///////////////////////////////////////////////////////////////////////////////

	Param1Type Param1;
	Param2Type Param2;
	Param3Type Param3;
	Param4Type Param4;
	Param5Type Param5;
	Param6Type Param6;

	mol::threading::ReturnTypeTraits<R>	Retval;

	///////////////////////////////////////////////////////////////////////////////

	T*				object;
	FuncType		func;
    TR*             retObj;
	RetFuncType*	retFunc;
};

///////////////////////////////////////////////////////////////////////////////

} // end namespace mol

#endif
