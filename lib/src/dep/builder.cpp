
#include <crtdbg.h>
#include "dep/builder.h"

namespace mol {
namespace di  {

///////////////////////////////////////////////////////////

class ComponentFactoryRegistratorImpl : public ComponentFactoryRegistrator
{
public:

	ComponentFactoryRegistratorImpl(mol::di::Context& ctx,const Type& t,ComponentFactory* c);
	virtual ~ComponentFactoryRegistratorImpl();

	virtual bool canResolve();
	virtual void registerComponentFactory();
	virtual void clear();

private:
	mol::di::Context& ctx_;
	ComponentFactory* cf_;
	Type t_;
};

///////////////////////////////////////////////////////////

class NamedComponentFactoryRegistratorImpl : public ComponentFactoryRegistrator
{
public:

	NamedComponentFactoryRegistratorImpl(mol::di::Context& ctx,const std::string& n,ComponentFactory* c);
	virtual ~NamedComponentFactoryRegistratorImpl();

	virtual bool canResolve();
	virtual void registerComponentFactory();
	virtual void clear();

private:
	mol::di::Context& ctx_;
	ComponentFactory* cf_;
	std::string name_;
};

///////////////////////////////////////////////////////////

ComponentFactoryRegistratorImpl::ComponentFactoryRegistratorImpl(mol::di::Context& ctx, const Type& t,ComponentFactory* c)
	:ctx_(ctx),cf_(c),t_(t)
{}

ComponentFactoryRegistratorImpl::~ComponentFactoryRegistratorImpl()
{}

bool ComponentFactoryRegistratorImpl::canResolve()
{
	return cf_->can_resolve(&ctx_);
}

void ComponentFactoryRegistratorImpl::registerComponentFactory()
{
	ctx_.registerFactory(t_,cf_);
	delete this;
}

void ComponentFactoryRegistratorImpl::clear()
{
	delete cf_;
	delete this;
}


///////////////////////////////////////////////////////////



NamedComponentFactoryRegistratorImpl::NamedComponentFactoryRegistratorImpl(mol::di::Context& ctx, const std::string& n,ComponentFactory* c)
	:ctx_(ctx),cf_(c),name_(n)
{}

NamedComponentFactoryRegistratorImpl::~NamedComponentFactoryRegistratorImpl()
{}


bool NamedComponentFactoryRegistratorImpl::canResolve()
{
	return cf_->can_resolve(&ctx_);
}

void NamedComponentFactoryRegistratorImpl::registerComponentFactory()
{
	ctx_.registerFactory(name_,cf_);
	delete this;
}

void NamedComponentFactoryRegistratorImpl::clear()
{
	delete cf_;
	delete this;
}


///////////////////////////////////////////////////////////

ContextBuilder::~ContextBuilder()
{
	clear();
}

void ContextBuilder::clear()
{
	foreach( registration_, [](ComponentFactoryRegistrator* registrator) {

		registrator->clear();
	});


	registration_.clear();
	names_.clear();
	types_.clear();
}

void ContextBuilder::resolve()
{
	try 
	{
		bool go = true;
		while(go)
		{
			go = false;

			auto it = std::find_if( 
						registration_.begin(),
						registration_.end(), 
						[this] (ComponentFactoryRegistrator* registrator) -> bool {

							if ( registrator->canResolve() )
							{
								registrator->registerComponentFactory();
								return true;
							}
							return false;
						}
			);

			if ( it != registration_.end() )
			{
				go = true;
				registration_.erase(it);
			}

			if (registration_.size()>0 && !go)
			{
				throw ContextBuilderEx("context did not fully resolve");
			}
		}
	}
	catch( ContextBuilderEx& ex )
	{
		std::cerr << "error resolving context" << std::endl << ex.msg() << std::endl;
		exit(0);
	}

}

ComponentFactory* ContextBuilder::registerFactory(const std::string& name,  ComponentFactory* factory)
{
	names_.insert( std::make_pair(name,factory) );
	registration_.push_back(new NamedComponentFactoryRegistratorImpl(ctx_,name,factory));
	return factory;
}

ComponentFactory* ContextBuilder::registerFactory(const Type& type,  ComponentFactory* factory)
{
	types_.insert( std::make_pair(type,factory) );
	registration_.push_back(new ComponentFactoryRegistratorImpl(ctx_,type,factory));
	return factory;
}


} // end namespace mol 
} // end namespace di  