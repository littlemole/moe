#ifndef MOL_DEF_GUARD_DEFINE_DEPENDENCY_INJECTION_CTX_FACTORY_CONTAINER_DEF_GUARD_
#define MOL_DEF_GUARD_DEFINE_DEPENDENCY_INJECTION_CTX_FACTORY_CONTAINER_DEF_GUARD_

#include "factory.h"

namespace mol {
namespace di  {


template<class C, class T>
class ContainerSingletonComponentFactoryImpl : public AbstractComponentFactoryImpl< C >
{
public:

	ContainerSingletonComponentFactoryImpl(Constructor* c)
		: AbstractComponentFactoryImpl<C>(c)
	{
	}

	ContainerSingletonComponentFactoryImpl(Constructor* c, const Dependencies& deps)
		: AbstractComponentFactoryImpl<C>(c,deps)
	{}

	~ContainerSingletonComponentFactoryImpl()
	{
		foreach( list_, [] (Argument* arg) {
			delete arg;
		});

		list_.clear();
	}


	virtual ContainerSingletonComponentFactoryImpl<C,T>* add(Argument* a)
	{
		list_.push_back(a);
		return this;
	}

	virtual typename mol::di::Component<C>::Ptr component(mol::di::Context* ctx)
	{
		return component_;
	}

	virtual bool can_resolve(mol::di::Context* ctx)
	{
		if ( constructor_ && !constructor_->can_resolve(ctx) )
			return false;

		return loop_if( list_, [ctx](Argument* arg) {
			return !arg->can_resolve(ctx);
		});
	}

	virtual void resolve(mol::di::Context* ctx)
	{
		mol::di::Component<C>* ct = new mol::di::Component<C>(ctx,constructor_->clone(), dependencies_ );
		component_ = make_comp(ct);

		foreach( list_, [ctx,ct](Argument* arg) {
			ct->unwrap()->push_back( Traits<T>::cast(arg->resolve(ctx)) );
		});
	}

	virtual ComponentFactory* clone()
	{
		return new ContainerSingletonComponentFactoryImpl<C,T>( constructor_->clone(), dependencies_ );
	}
protected:


	ContainerSingletonComponentFactoryImpl( const ContainerSingletonComponentFactoryImpl& rhs )
		: AbstractComponentFactoryImpl<C>(0)
	{}

	ContainerSingletonComponentFactoryImpl& operator=( const ContainerSingletonComponentFactoryImpl& rhs )
	{
		return *this;
	}

	std::list<Argument*> list_;
	boost::shared_ptr< mol::di::Component<C> > component_;
};


template<class T>
class ListSingletonComponentFactoryImpl : public ContainerSingletonComponentFactoryImpl<std::list<T>,T>
{
public:
	ListSingletonComponentFactoryImpl(Constructor* c)
		: ContainerSingletonComponentFactoryImpl<std::list<T>,T>(c)
	{}
};


template<class T>
class VectorSingletonComponentFactoryImpl : public ContainerSingletonComponentFactoryImpl<std::vector<T>,T>
{
public:
	VectorSingletonComponentFactoryImpl(Constructor* c)
		: ContainerSingletonComponentFactoryImpl<std::vector<T>,T>(c)
	{}
};


template<class K,class V>
class MapSingletonComponentFactoryImpl : public AbstractComponentFactoryImpl< std::map<K,V> >
{
public:

	MapSingletonComponentFactoryImpl(Constructor* c)
		: AbstractComponentFactoryImpl< std::map<K,V> >(c)
	{
	}

	MapSingletonComponentFactoryImpl(Constructor* c, const Dependencies& deps)
		: AbstractComponentFactoryImpl< std::map<K,V> >(c,deps)
	{}

	~MapSingletonComponentFactoryImpl()
	{
		foreach( keys_,  [](Argument* arg) {
			delete arg;
		});

		foreach( list_,  [](Argument* arg) {
			delete arg;
		});

		keys_.clear();
		list_.clear();	
	}


	virtual MapSingletonComponentFactoryImpl<K,V>* add(Argument* k, Argument* v)
	{
		keys_.push_back(k);
		list_.push_back(v);
		return this;
	}

	virtual typename mol::di::Component< std::map<K,V> >::Ptr component(mol::di::Context* ctx)
	{
		return component_;
	}

	virtual bool can_resolve(mol::di::Context* ctx)
	{
		if ( constructor_ && !constructor_->can_resolve(ctx) )
			return false;

		if ( !loop_if( 
					list_, 
					[ctx](Argument* arg) {
						return !arg->can_resolve(ctx);
					}))
		{
			return false;
		}
		
		return loop_if( keys_, [ctx]( Argument* arg ) {
			return !arg->can_resolve(ctx);
		});

	}

	virtual void resolve(mol::di::Context* ctx)
	{
		Component< std::map<K,V> >* mapComponent = new Component< std::map<K,V> >(ctx,constructor_->clone(), dependencies_);
		component_ = make_comp(mapComponent);

		std::list<Argument*>::iterator key = keys_.begin();

		foreach( list_, [ctx,mapComponent,&key] ( Argument* arg ) {

			(*mapComponent)->insert( 
				std::make_pair( 
					Traits<K>::cast((*key)->resolve(ctx)), 
					Traits<V>::cast(arg->resolve(ctx)) 
					) 
				);
			key++;
		});

	}

	virtual ComponentFactory* clone()
	{
		return new MapSingletonComponentFactoryImpl<K,V>( constructor_->clone(), dependencies_ );
	}

protected:


	MapSingletonComponentFactoryImpl( const MapSingletonComponentFactoryImpl& rhs )
		: AbstractComponentFactoryImpl<T>(0)
	{}

	MapSingletonComponentFactoryImpl& operator=( const MapSingletonComponentFactoryImpl& rhs )
	{
		return *this;
	}

	std::list<Argument*> keys_;
	std::list<Argument*> list_;
	boost::shared_ptr< mol::di::Component< std::map<K,V> > > component_;
};


} // end namespace mol 
} // end namespace di  


#endif
