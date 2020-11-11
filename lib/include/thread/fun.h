#ifndef MOL_DEF_GUARD_FUN_THREAD_DEFINE_GUARD_DEFINE_
#define MOL_DEF_GUARD_FUN_THREAD_DEFINE_GUARD_DEFINE_

#include <functional>
#include <any>

//#include <boost/type_traits.hpp>
#include <iostream>


namespace mol {
namespace fun {

///////////////////////////////////////////////////////////////////
// call - a call to any function with bound parameters
// interface
//
///////////////////////////////////////////////////////////////////


class task
{
	public:

		task() {}
		virtual ~task() {  }

		virtual void operator()()		= 0;

		virtual mol::fun::task* clone() = 0;

		virtual std::any retval()     = 0;


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
class Task : public mol::fun::task
{
public:

	Task(B b)
		: bound(b)
	{}

	virtual ~Task()	{}

	virtual void operator()()
	{
		result.invoke(bound);
	}

	virtual mol::fun::task* clone()
	{
		return new Task<B>(bound);
	}

	virtual std::any retval()
	{
		return std::any(result.value);
	}

	//typedef typename B::result_type ResultType;
	using ResultType = decltype(std::declval<B>()());
	fun::Invoker<ResultType> result;
	B	bound;
};


///////////////////////////////////////////////////////////////////
// Call with Callback Impl
///////////////////////////////////////////////////////////////////

template<class C,class CB>
class TaskCallback : public mol::fun::task
{
public:

	TaskCallback( Task<C>* task, CB callback)
		: task_(task), callback_(callback)
	{}

	virtual ~TaskCallback()
	{
		delete task_;
	}

	virtual void operator()()
	{
		task_->result.invoke(task_->bound);
		task_->result.callback(callback_);
	}

	virtual mol::fun::task* clone()
	{
		return new TaskCallback<C,CB>( (Task<C>*)(task_->clone()),callback_);
	}

	virtual void invoke()
	{
	}

	virtual void callback()
	{
	}

	virtual std::any retval()
	{
		return std::any((task_->result.value));
	}


private:

	Task<C>* task_;
	CB callback_;
};

///////////////////////////////////////////////////////////////////
// inline factory helpers
///////////////////////////////////////////////////////////////////

namespace fun {

template<class B>
inline Task<B>* make_task( B bound )
{
	return new Task<B>(bound);
}


template<class B,class CB>
inline TaskCallback<B,CB>* make_task_callback( B bound, CB cb )
{
	return new TaskCallback<B,CB>(make_task(bound),cb);
}


template<class T,class C>
T& unwrap(C* task)
{
	return std::any_cast<T>(task->retval());
}

} // end namespace fun
} // end namespace mol

#endif
