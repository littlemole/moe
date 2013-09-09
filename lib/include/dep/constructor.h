#ifndef MOL_DEF_GUARD_DEFINE_DEPENDENCY_INJECTION_CTX_CREATORS_DEF_GUARD_
#define MOL_DEF_GUARD_DEFINE_DEPENDENCY_INJECTION_CTX_CREATORS_DEF_GUARD_

#include "argument.h"


#include <boost/preprocessor.hpp>


namespace mol {
namespace di  {


template<class T>
class Creator : public Constructor
{
public:

	virtual T* resolve(Context* cx) = 0;

	static T* create( Context* ctx, Constructor* constructor)
	{
		Creator<T>* creator = static_cast<Creator<T>*>(constructor);
		return creator->resolve(ctx);
	}
};

template<class T>
class ConstructorImpl;

template<class T>
class ConstructorArgumentList;

template<class I, class T, class P>
class ConstructorArgumentList<I(T,P)>
{
public:

	ConstructorArgumentList(P arg)
		: arg_(arg)
	{}
	
	bool can_resolve(mol::di::Context* ctx) 
	{
		return arg_->can_resolve(ctx);
	}

	template<class ... VArgs>
	I* resolve( mol::di::Context* ctx, VArgs & ... args)
	{
		I* i =  new T( args...,  *( (Component<typename P::Type>*)( arg_->resolve(ctx)) )->unwrap() );
		return i;
	}

	template<class ... VArgs>
	Constructor* clone( VArgs& ... args)
	{
		return new ConstructorImpl<I(T,VArgs...,P)>(args...,arg_->clone());
	}

private:
	boost::scoped_ptr<mol::di::Argument> arg_;
};

template<class I, class T, class P, class ... Args>
class ConstructorArgumentList<I(T,P,Args...)> : public ConstructorArgumentList<I(T,Args...)>
{
public:
	
	typedef ConstructorArgumentList<I(T,Args...)> BASE;

	ConstructorArgumentList(P arg, Args ... args)
		: BASE(args...),  arg_(arg)
	{}

	bool can_resolve(mol::di::Context* ctx) 
	{
		return arg_->can_resolve(ctx) && BASE::can_resolve(ctx);
	}

	template<class ... VArgs>
	I* resolve( mol::di::Context* ctx, VArgs & ... args)
	{
		return BASE::resolve( ctx, args..., *( (Component<typename P::Type>*)( arg_->resolve(ctx)) )->unwrap() );
	}

	template<class ... VArgs>
	Constructor* clone( VArgs& ... args)
	{
		return BASE::clone(args..., arg_);
	}

private:
	boost::scoped_ptr<mol::di::Argument> arg_;
};


template<class I, class T, class P>
class ConstructorImpl<I(T,P)> : public Creator<I> 
{
public:

	ConstructorArgumentList<I(T,P)> arguments;

	ConstructorImpl(P arg) 
		: arguments(arg) 
	{} 

	~ConstructorImpl() 
	{}

	virtual bool can_resolve(mol::di::Context* ctx) 
	{
		return arguments.can_resolve(ctx);
	}

	virtual I* resolve(mol::di::Context* ctx)
	{
		return arguments.resolve(ctx);
	}

	virtual Constructor* clone()
	{
		return arguments.clone();
	}


private:
	
	ConstructorImpl& operator=(const ConstructorImpl& rhs)
	{
		return *this;
	}

	ConstructorImpl( const ConstructorImpl& rhs ) 
	{}

};


template<class I, class T, class P, class ... Args>
class ConstructorImpl<I(T,P,Args...)> : public Creator<I> 
{
public:

	ConstructorArgumentList<I(T,P,Args...)> arguments;

	ConstructorImpl(P arg, Args ... args) 
		: arguments(arg,args...) 
	{} 

	~ConstructorImpl() 
	{}

	virtual bool can_resolve(mol::di::Context* ctx) 
	{
		return arguments.can_resolve(ctx);
	}

	virtual I* resolve(mol::di::Context* ctx)
	{
		return arguments.resolve(ctx);
	}

	virtual Constructor* clone()
	{
		return arguments.clone();
	}


private:
	
	ConstructorImpl& operator=(const ConstructorImpl& rhs)
	{
		return *this;
	}

	ConstructorImpl( const ConstructorImpl& rhs ) 
	{}

};


template<class I, class T>
class ConstructorImpl<I(T)> : public Creator<I>
{
public:
	ConstructorImpl() {}
	~ConstructorImpl() {}

	virtual bool can_resolve(mol::di::Context* ctx) 
	{
		return true;
	}

	virtual I* resolve(mol::di::Context* ctx)
	{
		I* i =  new T;
		return i;
	}

	virtual Constructor* clone()
	{
		return new ConstructorImpl<I(T)>;
	}

private:

	
	ConstructorImpl& operator=(const ConstructorImpl& rhs)
	{
		return *this;
	}

	ConstructorImpl( const ConstructorImpl& rhs ) 
	{}
};

/*
template<class I, class T, class P>
class ConstructorImpl<I(T,P*)> : public Creator<I>
{
public:
	ConstructorImpl(mol::di::Argument* arg) : arg_(arg) {}
	~ConstructorImpl() {}

	virtual bool can_resolve(mol::di::Context* ctx) 
	{
		return arg_->can_resolve(ctx);
	}

	virtual I* resolve(mol::di::Context* ctx)
	{
		I* i =  new T( *((Component<P::Type>*)(arg_->resolve(ctx)))->unwrap() );
		return i;
	}
	virtual Constructor* clone()
	{
		return new ConstructorImpl<I(T,P*)>(arg_->clone());
	}

private:

	ConstructorImpl& operator=(const ConstructorImpl& rhs)
	{
		return *this;
	}

	ConstructorImpl( const ConstructorImpl& rhs ) 
	{}

protected:
	boost::scoped_ptr<mol::di::Argument> arg_;
};
*/
/*
template<class T >
Constructor* constructor( )
{
	return new ConstructorImpl<T(T)>(  );
}
*/

template<class I, class T, class ... Args >
Constructor* constructor( Args ... args )
{
	return new mol::di::ConstructorImpl<I(T,Args...)>(args...);
}

/*
template<class T , class P, class ... Args>
Constructor* constructor( P* p, Args ... args )
{
	return new ConstructorImpl<T(T,P*,Args...)>( p,args ... );
}
*/

/*
template<class I, class T , class P>
Constructor* constructor( P* p )
{
	return new ConstructorImpl<I(T,P)>( p );
}


template<class I, class T , class P, class P2>
Constructor* constructor( P* p, P2* p2 )
{
	return new ConstructorImpl<I(T,P,P2)>( p, p2 );
}



template<class I, class T , class P, class P2, class P3>
Constructor* constructor( P* p, P2* p2, P3* p3 )
{
	return new ConstructorImpl<I(T,P,P2,P3)>( p, p2 ,p3);
}
*/
/*
template<class I, class T , class P, class ... Args>
Constructor* constructor( P* p, Args ... args )
{
	return new ConstructorImpl<I(T,P*,Args...)>( p, args ... );
}
*/

} // end namespace di
} // end namespace mol
 
/*
#define CONSTRUCTOR_ARGS 20
#define CONSTRUCTOR_ARGS_SHIFTED BOOST_PP_ADD(CONSTRUCTOR_ARGS,1)

#include "resolver.h"

namespace mol {
namespace di  {
namespace old  {
#define ARG(n) BOOST_PP_CAT(BOOST_PP_CAT(arg,n),_)
	
#define PARAMS(z, n, text) BOOST_PP_CAT(BOOST_PP_CAT(arg,n),_.get())

#define RESOLVERS(z, n, text) BOOST_PP_CAT(BOOST_PP_CAT(arg,n),_)->can_resolve(ctx) BOOST_PP_IF(BOOST_PP_EQUAL(CONSTRUCTOR_ARGS,n), , &&  )

#define CLONES(z, n, text) BOOST_PP_CAT(BOOST_PP_CAT(arg,n),_)->clone() BOOST_PP_COMMA_IF(BOOST_PP_EQUAL(CONSTRUCTOR_ARGS_SHIFTED,n))

#define ARGUMENTS(z, n, text) boost::scoped_ptr<mol::di::Argument> BOOST_PP_CAT(BOOST_PP_CAT(arg,n),_;)


template<class I, class T, BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS(CONSTRUCTOR_ARGS_SHIFTED, class P, = void BOOST_PP_INTERCEPT)>
class ConstructorImpl : public Creator<I>
{
public:

#define BOOST_PP_ITERATION_LIMITS (1, CONSTRUCTOR_ARGS_SHIFTED)
#define BOOST_PP_FILENAME_1       "constructor.inc.h"
#include BOOST_PP_ITERATE()

	~ConstructorImpl() 
	{}

	virtual bool can_resolve(mol::di::Context* ctx) 
	{
		return BOOST_PP_REPEAT_FROM_TO(1,CONSTRUCTOR_ARGS_SHIFTED,RESOLVERS,0);
	}

	virtual I* resolve(mol::di::Context* ctx)
	{
		I* i =  Resolver<BOOST_PP_ENUM_SHIFTED_PARAMS(CONSTRUCTOR_ARGS_SHIFTED, P)>::resolve<I,T>(ctx,BOOST_PP_ENUM_SHIFTED(CONSTRUCTOR_ARGS_SHIFTED, PARAMS, 0));
		return i;
	}

	virtual Constructor* clone()
	{
		return new ConstructorImpl<I,T,BOOST_PP_ENUM_SHIFTED_PARAMS(CONSTRUCTOR_ARGS_SHIFTED,P)>( 
				BOOST_PP_ENUM_SHIFTED(CONSTRUCTOR_ARGS_SHIFTED, CLONES, 0)
			);
	}

private:

	
	ConstructorImpl& operator=(const ConstructorImpl& rhs)
	{
		return *this;
	}

	ConstructorImpl( const ConstructorImpl& rhs ) 
	{}

	BOOST_PP_REPEAT_FROM_TO(1,CONSTRUCTOR_ARGS_SHIFTED, ARGUMENTS, 0)
};

/*
#define BOOST_PP_ITERATION_LIMITS (1, CONSTRUCTOR_ARGS_SHIFTED)
#define BOOST_PP_FILENAME_1       "constructor.fun.inc.h"
#include BOOST_PP_ITERATE()
* /

#undef PARAMS
#undef ARGUMENTS
#undef RESOLVERS
#undef CLONES
#undef ARG


} // end namespace mol 
} // end namespace di  


#undef CONSTRUCTOR_ARGS_SHIFTED
#undef CONSTRUCTOR_ARGS
*/

#endif
