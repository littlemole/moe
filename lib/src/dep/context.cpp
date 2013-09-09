#include <crtdbg.h>
#include "dep/context.h"
#include "dep/factory.h"

namespace mol {
namespace di  {

ContextImpl::ContextImpl( Context* ctx)
	: ctx_(ctx)
{
	registerFactory(
		type<Context>(), 
		new mol::di::ComponentFactoryImpl<mol::di::Context>(
			mol::di::constructor<mol::di::Context,mol::di::ContextImpl>()
		) 
	);
}

ContextImpl::~ContextImpl()
{
	clear();
}

ContextImpl::ContextImpl( const ContextImpl& rhs )
{
	copyFrom(rhs);
}


ContextImpl& ContextImpl::operator=(const ContextImpl& rhs )
{
	if ( this == &rhs )
		return *this;

	clear();
	copyFrom(rhs);

	return *this;
}

void ContextImpl::copyFrom(const ContextImpl& rhs )
{
	//foreach( rhs.typedObjectMap_, [this]( const std::pair<Type,ComponentFactory*>& tuple ) 
	foreach( rhs.typedObjectMap_, [this]( const typedFactoryEntry& tuple ) 
	{
		Type type = tuple.first;
		ComponentFactory* factory = tuple.second->clone();

		this->typedObjectMap_.insert( typedFactoryEntry( type, factory ) );
		this->killList_.push_front(factory);

	});

	//foreach( rhs.namedObjectMap_, [this]( const std::pair<std::string,ComponentFactory*>& tuple ) 
	foreach( rhs.namedObjectMap_, [this]( const namedFactoryEntry& tuple ) 
	{
		std::string name = tuple.first;
		ComponentFactory* factory = tuple.second->clone();

		this->namedObjectMap_.insert( namedFactoryEntry( name, factory ) );
		this->killList_.push_front(factory);
	});

	ctx_ = rhs.ctx_;
}

void ContextImpl::clear()
{
	foreach(killList_, [](ComponentFactory* f)
	{ 
		delete f; 
	});

	killList_.clear();
	namedObjectMap_.clear();
	typedObjectMap_.clear();
}


ComponentFactory*	ContextImpl::getFactory  (const Type& type)
{
	if ( typedObjectMap_.count(type) == 0 )
	{
		if ( ctx_ )
		{
			return ctx_->getFactory(type);
		}
		return 0;
	}

	return typedObjectMap_[type];
}


ComponentFactory* ContextImpl::getFactory(const std::string& name)
{
	if ( namedObjectMap_.count(name) == 0 )
	{
		if ( ctx_ )
		{
			return ctx_->getFactory(name);
		}
		return 0;
	}

	return namedObjectMap_[name];
}

	

void ContextImpl::registerFactory(std::string s, ComponentFactory* c)
{
	c->resolve(this);
	killList_.push_front(c);
	namedObjectMap_.insert( namedFactoryEntry( s,c ));
}
	
void ContextImpl::registerFactory(const Type& t, ComponentFactory* c)
{
	c->resolve(this);
	killList_.push_front(c);
	typedObjectMap_.insert( typedFactoryEntry( t,c ));
}


Context& emptyContext()
{
	static ContextImpl ctx;
	return ctx;
}

/////////////////////////////////////////////////////////////////////////////////

Dependencies::Dependencies()
{}

Dependencies::~Dependencies()
{
	clear();
}


Dependencies::Dependencies( const Dependencies& rhs )
{
	foreach( rhs.dependencies_, [this](Dependency* dep) 
	{
		this->dependencies_.push_back(dep->clone());
	});

}

Dependencies& Dependencies::operator=( const Dependencies& rhs )
{
	if ( this == &rhs )
	{
		return *this;
	}

	clear();

	foreach( rhs.dependencies_, [this](Dependency* dep) 
	{
		this->dependencies_.push_back( dep->clone() );
	});

	return *this;
}

bool Dependencies::can_resolve(mol::di::Context* ctx)
{
	return loop_if( 
				dependencies_, 
				[ctx](Dependency* dep) -> bool { 
					return !dep->can_resolve(ctx); 
				});
}


void Dependencies::resolve(mol::di::Context* ctx,Comp* target)
{
	foreach( dependencies_, [ctx,target](Dependency* d) 
	{
		d->resolve(ctx,target);
	});

}

Dependencies* Dependencies::clone()
{
	Dependencies* d = new Dependencies;

	foreach(dependencies_, [d](Dependency* dep)
	{
		d->dependencies_.push_back( dep->clone() );
	});

	return d;
}

void Dependencies::add(Dependency* d)
{
	dependencies_.push_back(d);
}


void Dependencies::clear()
{
	foreach( 
		dependencies_, 
		[](Dependency* dep) 
		{ 
			delete dep; 
		} 
	);
	dependencies_.clear();
}


} // end namespace mol 
} // end namespace di  

