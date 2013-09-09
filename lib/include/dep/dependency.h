#ifndef MOL_DEF_GUARD_DEFINE_DEPENDENCY_INJECTION_CTX_DEP_DEF_GUARD_
#define MOL_DEF_GUARD_DEFINE_DEPENDENCY_INJECTION_CTX_DEP_DEF_GUARD_

#include "argument.h"

namespace mol {
namespace di  {


//////////////////////////////////////////////////////////////////////////////////

class Dependency
{
public:

	virtual ~Dependency() {}

	virtual bool can_resolve(Context* cx) = 0;
	virtual void resolve( Context* cx, Comp* target ) = 0;
	virtual Dependency* clone() = 0;
};


//////////////////////////////////////////////////////////////////////////////////

template<class T, class I>
class DependencyImpl : public Dependency
{
public:

	typedef typename I T::*Member;

	DependencyImpl(Member m)
		:member_(m)
	{}

	~DependencyImpl()
	{
	}

	virtual bool can_resolve(mol::di::Context* ctx)
	{
		return ctx->getFactory<I>() != 0;
	}

	virtual void resolve( mol::di::Context* ctx, Comp* target )
	{
		component_ = ctx->get<Traits<I>::Base>();
		T* t = Traits<T*>::cast(target);
		(t->*member_) = Traits<I>::cast(component_.get());
	}

	virtual Dependency* clone()
	{
		return new DependencyImpl<T,I>(member_);
	}

protected:

	DependencyImpl( const DependencyImpl& rhs )
	{}

	DependencyImpl& operator=( const DependencyImpl& rhs )
	{
		return *this;
	}

	Member member_;

	boost::shared_ptr< mol::di::Component< typename mol::di::Traits<I>::Base > > component_;	
};

//////////////////////////////////////////////////////////////////////////////////

template<class T, class I>
class SetterDependencyImpl : public Dependency
{
public:

	typedef typename void (T::*Setter)(I*);

	SetterDependencyImpl(Setter s)
		:setter_(s)
	{}

	~SetterDependencyImpl()
	{}

	virtual bool can_resolve(mol::di::Context* ctx)
	{
		return ctx->getFactory<I>() != 0;
	}

	virtual void resolve( mol::di::Context* ctx, Comp* target )
	{
		component_ = ctx->get<Traits<I>::Base>();
		T* t = Traits<T*>::cast(target);
		(t->*setter_)( Traits<I>::cast(component_.get()));
	}

	virtual Dependency* clone()
	{
		return new SetterDependencyImpl<T,I>(setter_);
	}

protected:

	SetterDependencyImpl( const SetterDependencyImpl& rhs )
	{}

	SetterDependencyImpl& operator=( const SetterDependencyImpl& rhs )
	{
		return *this;
	}


	mol::di::Context& ctx_;
	Setter setter_;

	boost::shared_ptr< mol::di::Component<typename Traits<I>::Base> > component_;	
};

//////////////////////////////////////////////////////////////////////////////////

template<class T, class E>
class EventDependencyImpl : public Dependency
{
public:

	EventDependencyImpl()
	{}

	~EventDependencyImpl()
	{}

	virtual bool can_resolve(mol::di::Context* ctx)
	{
		return ctx->getFactory<E>() != 0;
	}

	virtual void resolve( mol::di::Context* ctx, Comp* target )
	{
		component_ = ctx->get<E>();
		IAction* action = Traits<E*>::cast(component_.get());
		action->registerAction(actionController<T>());
	}

	virtual Dependency* clone()
	{
		return new EventDependencyImpl<T,E>();
	}

protected:

	EventDependencyImpl( const EventDependencyImpl& rhs )
	{}

	EventDependencyImpl& operator=( const EventDependencyImpl& rhs )
	{
		return *this;
	}

	boost::shared_ptr< mol::di::Component<E> > component_;
	
};

//////////////////////////////////////////////////////////////////////////////////

template<class T, class I>
class NamedDependencyImpl : public Dependency
{
public:

	typedef typename I T::*Member;

	NamedDependencyImpl( const std::string& name, Member m)
		: member_(m), name_(name)
	{}

	~NamedDependencyImpl()
	{}

	virtual bool can_resolve(mol::di::Context* ctx)
	{
		return ctx->getFactory(name_) != 0;
	}

	virtual void resolve( mol::di::Context* ctx, Comp* target )
	{
		component_ = ctx->get<Traits<T>::Base>(name_);
		T* t = Traits<T*>::cast(target);
		(t->*member_) = Traits<I>::cast(component_.get());
	}

	virtual Dependency* clone()
	{
		return new NamedDependencyImpl<T,Traits<I>::Base>(name_,member_);
	}

private:


	NamedDependencyImpl( const NamedDependencyImpl& rhs )
	{}

	NamedDependencyImpl& operator=( const NamedDependencyImpl& rhs )
	{
		return *this;
	}

	Member member_;
	std::string name_;

	boost::shared_ptr< mol::di::Component<T> > component_;
};

//////////////////////////////////////////////////////////////////////////////////

template<class T, class I>
class NamedSetterDependencyImpl : public Dependency
{
public:

	typedef typename void (T::*Setter)(I*);

	NamedSetterDependencyImpl(const std::string& name, Setter s)
		: setter_(s), name_(name)
	{}

	~NamedSetterDependencyImpl()
	{}

	virtual bool can_resolve(mol::di::Context* ctx)
	{
		return ctx->getFactory(name_) != 0;
	}

	virtual void resolve( mol::di::Context* ctx, Comp* target )
	{
		component_ = ctx->get<Traits<I>::Base>(name_);
		T* t = Traits<T*>::cast(target);
		(t->*setter_)( Traits<I>::cast(component_.get()) );
	}

	virtual Dependency* clone()
	{
		return new NamedSetterDependencyImpl<T,I>(name_,setter_);
	}

private:


	NamedSetterDependencyImpl( const NamedSetterDependencyImpl& rhs )
	{}

	NamedSetterDependencyImpl& operator=( const NamedSetterDependencyImpl& rhs )
	{
		return *this;
	}

	Setter setter_;
	std::string name_;

	boost::shared_ptr< mol::di::Component<typename Traits<I>::Base> > component_;	
};

//////////////////////////////////////////////////////////////////////////////////

template<class T, class I>
class ValueDependencyImpl : public Dependency
{
public:

	typedef typename I T::*Member;

	ValueDependencyImpl(Argument* arg, Member m)
		:member_(m),arg_(arg)
	{}

	~ValueDependencyImpl()
	{
		delete arg_;
	}

	virtual bool can_resolve(mol::di::Context* ctx)
	{
		return true;
	}

	virtual void resolve( mol::di::Context* ctx, Comp* target )
	{
		T* t = Traits<T*>::cast(target);
		(t->*member_) = Traits<I>::cast(arg_->resolve(ctx));
	}

	virtual Dependency* clone()
	{
		return new ValueDependencyImpl<T,I>(arg_->clone(),member_);
	}

private:


	ValueDependencyImpl( const ValueDependencyImpl& rhs )
	{}

	ValueDependencyImpl& operator=( const ValueDependencyImpl& rhs )
	{
		return *this;
	}

	Argument* arg_;
	Member member_;
	
};

//////////////////////////////////////////////////////////////////////////////////

template<class T, class I>
class SetterValueDependencyImpl : public Dependency
{
public:

	typedef void (T::*Setter)(I*);

	SetterValueDependencyImpl(Argument* arg, Setter s)
		:setter_(s),arg_(arg)
	{}

	~SetterValueDependencyImpl()
	{
		delete arg_;
	}

	virtual bool can_resolve(mol::di::Context* ctx)
	{
		return true;
	}

	virtual void resolve( mol::di::Context* ctx, Comp* target )
	{
		T* t = Traits<T*>::cast(target);
		(t->*setter_)( Traits<I>::cast(arg_->resolve()) );
	}

	virtual Dependency* clone()
	{
		return new SetterValueDependencyImpl<T,I>(arg_->clone(),setter_);
	}

private:


	SetterValueDependencyImpl( const SetterValueDependencyImpl& rhs )
	{}

	SetterValueDependencyImpl& operator=( const SetterValueDependencyImpl& rhs )
	{
		return *this;
	}

	Argument* arg_;
	Setter setter_;
	
};

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////


template<class I, class T>
Dependency* dependency( I T::*Member )
{
	return new DependencyImpl<T,I>(Member);
}

template<class I, class T>
Dependency* dependency( const std::string& name, I T::*Member )
{
	return new NamedDependencyImpl<T,I>( name,Member);
}


template<class I, class T>
Dependency* dependency(I T::*Member, Argument* arg )
{
	return new ValueDependencyImpl<T,I>(arg,Member);
}

template<class T, class I>
Dependency* dependency( void (T::*Setter)(I*) )
{
	return new SetterDependencyImpl<T,I>( Setter);
}

template<class T, class I>
Dependency* dependency( const std::string& name, void (T::*Setter)(I*) )
{
	return new NamedSetterDependencyImpl<T,I>( name,Setter);
}


template<class T, class I>
Dependency* dependency(void (T::*Setter)(I*), Argument* arg )
{
	return new SetterValueDependencyImpl<T,I>(arg,Setter);
}

//////////////////////////////////////////////////////////////////////////////////

template<class T, class E>
Dependency* handler()
{
	return new EventDependencyImpl<T,E>;
}

//////////////////////////////////////////////////////////////////////////////////

} // end namespace mol 
} // end namespace di  

#endif

