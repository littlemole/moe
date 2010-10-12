#ifndef MOL_DEF_GUARD_FUN_THREAD_DEFINE_GUARD_DEFINE_
#define MOL_DEF_GUARD_FUN_THREAD_DEFINE_GUARD_DEFINE_

#include "boost/function.hpp"
#include "boost/bind.hpp"
#include "boost/any.hpp"
#include <boost/type_traits.hpp>
#include <iostream>


namespace mol {
namespace fun {

///////////////////////////////////////////////////////////////////
// call - a call to any function with bound parameters
// interface
//
///////////////////////////////////////////////////////////////////


class call
{
	public:

		call() {}
		virtual ~call() { std::cout << "~call" << std::endl; }

		virtual void operator()()		= 0;

		virtual mol::fun::call* clone() = 0;

		virtual boost::any retval() = 0;


};


///////////////////////////////////////////////////////////////////
// Invoker
///////////////////////////////////////////////////////////////////

template<class T>
class Invoker
{
	public:

		T value;

		template<class B>
		void invoke(B bound) 
		{
			value = bound();
		}

		template<class CB>
		void callback(CB cb) 
		{
			cb(value);
		}
};

template<>
class Invoker<void>
{
public:

	const void* value;

	Invoker()
		:value(0)
	{}

	template<class B>
	void invoke(B bound) 
	{
		bound();
	}

	template<class CB>
	void callback(CB cb) 
	{
		cb();
	}
};


} // end namespace fun

///////////////////////////////////////////////////////////////////
// Call Impl
///////////////////////////////////////////////////////////////////

template<class B>
class Call : public mol::fun::call
{
public:

	Call(B b)
		: bound(b)
	{}

	virtual ~Call()	{}

	virtual void operator()()
	{
		result.invoke(bound);
	}

	virtual mol::fun::call* clone()
	{
		return new Call<B>(bound);
	}

	virtual boost::any retval()
	{
		return boost::any(result.value);
	}

	typedef typename B::result_type ResultType;
	fun::Invoker<ResultType> result;
	B	bound;
};


///////////////////////////////////////////////////////////////////
// Call with Callback Impl
///////////////////////////////////////////////////////////////////

template<class C,class CB>
class BackCall : public mol::fun::call
{
public:

	BackCall( Call<C>* call, CB callback)
		: call_(call), callback_(callback)
	{}

	virtual ~BackCall()
	{
		delete call_;
	}

	virtual void operator()()
	{
		call_->result.invoke(call_->bound);
		call_->result.callback(callback_);
	}

	virtual mol::fun::call* clone()
	{
		return new BackCall<C,CB>( (Call<C>*)(call_->clone()),callback_);
	}

	virtual void invoke()
	{
	}

	virtual void callback()
	{
	}

	virtual boost::any retval()
	{
		return boost::any((call_->result.value));
	}


private:

	Call<C>* call_;
	CB callback_;
};

///////////////////////////////////////////////////////////////////
// inline factory helpers
///////////////////////////////////////////////////////////////////

namespace fun {

template<class B>
inline Call<B>* thread_prepare_call( B bound )
{
	return new Call<B>(bound);
}


template<class B,class CB>
inline BackCall<B,CB>* thread_prepare_callback( B bound, CB cb )
{
	return new BackCall<B,CB>(prepare_call(bound),cb);
}


template<class T,class C>
T& unwrap(C* call)
{
	return boost::any_cast<T>(call->retval());
}

} // end namespace fun
} // end namespace mol

#endif
