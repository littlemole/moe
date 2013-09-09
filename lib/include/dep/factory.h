#ifndef MOL_DEF_GUARD_DEFINE_DEPENDENCY_INJECTION_CTX_FACTORY_DEF_GUARD_
#define MOL_DEF_GUARD_DEFINE_DEPENDENCY_INJECTION_CTX_FACTORY_DEF_GUARD_

#include "dependency.h"
#include "constructor.h"

namespace mol {
namespace di  {

//////////////////////////////////////////////////////////////////////////////////


template<class T>
typename mol::di::Component<T>::Ptr make_comp( mol::di::Component<T>* c )
{
	return typename mol::di::Component<T>::Ptr( c );
}


template<class T>
typename mol::di::Component<T>::Ptr create_comp( 
	mol::di::Context* ctx, 
	Constructor* c, 
	const Dependencies& deps )
{
	return make_comp(new Component<T>( ctx, c, deps));
	//return typename mol::di::Component<T>::Ptr( new Component<T>( ctx, c, deps) );
}


//////////////////////////////////////////////////////////////////////////////////

template<class T>
class AbstractComponentFactoryImpl : public Factory<T>
{
public:

	AbstractComponentFactoryImpl(Constructor* c)
		: constructor_(c)
	{}


	AbstractComponentFactoryImpl(Constructor* c, const Dependencies& deps)
		: dependencies_(deps),constructor_(c)
	{}

	~AbstractComponentFactoryImpl()	
	{}


	virtual ComponentFactory* depends(Dependency* d)
	{
		dependencies_.add( d );
		return this;
	}

	virtual bool can_resolve(mol::di::Context* ctx)
	{
		return true;
	}

	virtual void resolve(mol::di::Context* ctx)
	{}

protected:

	AbstractComponentFactoryImpl( const AbstractComponentFactoryImpl& rhs )
	{}

	AbstractComponentFactoryImpl& operator=( const AbstractComponentFactoryImpl& rhs )
	{
		return *this;
	}

	Dependencies dependencies_;
	boost::scoped_ptr<Constructor> constructor_;
};

//////////////////////////////////////////////////////////////////////////////////

template<class T>
class ComponentFactoryImpl : public AbstractComponentFactoryImpl<T>
{
public:

	ComponentFactoryImpl(Constructor* c)
		: AbstractComponentFactoryImpl<T>(c)
	{}

	ComponentFactoryImpl(Constructor* c, const Dependencies& deps)
		: AbstractComponentFactoryImpl<T>(c,deps)
	{}

	virtual typename mol::di::Component<T>::Ptr component(mol::di::Context* ctx)
	{
		return create_comp<T>(ctx,constructor_->clone(), dependencies_);
	}

	virtual ComponentFactory* clone()
	{
		return new ComponentFactoryImpl( constructor_->clone(), dependencies_ );
	}

private:

	ComponentFactoryImpl( const ComponentFactoryImpl& rhs )
		: AbstractComponentFactoryImpl<T>(0)
	{}

	ComponentFactoryImpl& operator=( const ComponentFactoryImpl& rhs )
	{
		return *this;
	}
};

//////////////////////////////////////////////////////////////////////////////////

template<class T>
class SingletonComponentFactoryImpl : public AbstractComponentFactoryImpl<T>
{
public:

	SingletonComponentFactoryImpl(Constructor* c)
		: AbstractComponentFactoryImpl<T>(c)
	{}


	SingletonComponentFactoryImpl(Constructor* c, const Dependencies& deps, typename mol::di::Component<T>::Ptr comp)
		: AbstractComponentFactoryImpl<T>(c,deps),component_(comp)
	{}

	~SingletonComponentFactoryImpl()
	{}

	virtual typename mol::di::Component<T>::Ptr component(mol::di::Context* ctx)
	{
		return component_;
	}

	virtual bool can_resolve(mol::di::Context* ctx)
	{
		if ( constructor_ && !constructor_->can_resolve(ctx) )
			return false;

		return dependencies_.can_resolve(ctx);
	}

	virtual void resolve(mol::di::Context* ctx)
	{
		if ( !component_ )
		{
			component_ =  create_comp<T>(ctx,constructor_->clone(), dependencies_);
		}
		else {
			throw mol::di::ContextEx("singleton constructed twice");
		}
	}


	virtual ComponentFactory* clone()
	{
		return new SingletonComponentFactoryImpl( constructor_->clone(), dependencies_ , component_);
	}

protected:


	SingletonComponentFactoryImpl( const SingletonComponentFactoryImpl& rhs )
		: AbstractComponentFactoryImpl<T>(0)
	{}

	SingletonComponentFactoryImpl& operator=( const SingletonComponentFactoryImpl& rhs )
	{
		return *this;
	}

	typename mol::di::Component<T>::Ptr component_;
};

//////////////////////////////////////////////////////////////////////////////////

} // end namespace mol 
} // end namespace di  


#endif
