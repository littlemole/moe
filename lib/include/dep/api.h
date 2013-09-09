#ifndef MOL_DEF_GUARD_DEFINE_DEPENDENCY_INJECTION_CTX_API_DEF_GUARD_
#define MOL_DEF_GUARD_DEFINE_DEPENDENCY_INJECTION_CTX_API_DEF_GUARD_

///////////////////////////////////////////////////////////

#include <stdlib.h>
#include <crtdbg.h>

#include <string>
#include <vector>
#include <list>
#include <map>
#include <sstream>
#include <iostream>

#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>

#include "type.h"

//////////////////////////////////////////////////////////////////////////////////

namespace mol {
namespace di  {

//////////////////////////////////////////////////////////////////////////////////

class Dependency;
class Comp;
class ComponentFactory;
class Context;

//////////////////////////////////////////////////////////////////////////////////

class Constructor
{
public:
	virtual ~Constructor() {}

	virtual bool can_resolve(Context* cx) = 0;	
	virtual Constructor* clone() = 0;
};


//////////////////////////////////////////////////////////////////////////////////

class Comp
{
public:
	virtual ~Comp() 
	{}
};

//////////////////////////////////////////////////////////////////////////////////

class Dependencies
{
public:

	Dependencies();
	~Dependencies();

	Dependencies( const Dependencies& rhs );
	Dependencies& operator=( const Dependencies& rhs );

	bool can_resolve(Context* cx);
	void resolve(Context* cx,Comp* target);

	Dependencies* clone();

	void add(Dependency* d);

private:

	void clear();

	std::list<Dependency*> dependencies_;
};



//////////////////////////////////////////////////////////////////////////////////



class ComponentFactory 
{
public:
	virtual ~ComponentFactory() {}

	virtual bool can_resolve(Context* cx) = 0;
	virtual void resolve(Context* cx) = 0;
	virtual ComponentFactory* depends(Dependency* d) = 0;

	virtual ComponentFactory* clone() = 0;
};


//////////////////////////////////////////////////////////////////////////////////

template<class T>
class Component : public Comp
{
public:

	typedef boost::shared_ptr< mol::di::Component<T> > Ptr;

	Component()
		: t_(0),constructor_(0)
	{}

	Component(Context* ctx, Constructor* con, const Dependencies& dep)
		: t_(Creator<T>::create(ctx,con)),
		  constructor_(con),
		  dependencies_(dep)
	{
		dependencies_.resolve(ctx,this);
	}

	~Component()
	{}

	virtual T* unwrap()	
	{
		return t_.get();
	}

	T* operator->() 
	{
		return this->unwrap();
	}

protected:

	Component( const Component& rhs )
	{}

	Component& operator=( const Component& rhs )
	{
		return *this;
	}

	boost::scoped_ptr<T> t_;
	boost::scoped_ptr<Constructor> constructor_;
	Dependencies dependencies_;
};

//////////////////////////////////////////////////////////////////////////////////

template<>
class Component<mol::di::Context> : public Comp
{
public:

	typedef boost::shared_ptr< mol::di::Component<mol::di::Context> > Ptr;

	Component()
		: t_(0)
	{}

	Component(Context* ctx, Constructor* con, const Dependencies& dep)
		: t_(ctx)
	{
		delete con;
	}

	~Component()
	{}

	virtual mol::di::Context* unwrap()	
	{
		return t_;
	}

	mol::di::Context* operator->() 
	{
		return this->unwrap();
	}

protected:

	Component( const Component& rhs )
	{}

	Component& operator=( const Component& rhs )
	{
		return *this;
	}

	mol::di::Context* t_;
};


//////////////////////////////////////////////////////////////////////////////////

template<class T>
class Factory : public ComponentFactory
{
public:

	virtual typename mol::di::Component<T>::Ptr component(mol::di::Context* ctx) = 0;
};

//////////////////////////////////////////////////////////////////////////////////


template<class T>
class Traits
{
public:

	typedef T Base;

	typedef T& RefType;

	static T& cast( mol::di::Comp* c )
	{
		return *( static_cast<mol::di::Component<T>*>(c)->unwrap() );
	}

};

template<class T>
class Traits<T*>
{
public:

	typedef T Base;

	typedef T& RefType;

	static T* cast( mol::di::Comp* c )
	{
		return static_cast<mol::di::Component<T>*>(c)->unwrap();
	}

};

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

class Context
{
public:

	virtual ~Context()
	{}

	virtual void clear() = 0;

	virtual ComponentFactory*	getFactory  (const std::string& name) = 0;
	virtual ComponentFactory*	getFactory  (const Type& type) = 0;

	virtual void registerFactory(std::string s, ComponentFactory* c) = 0;	
	virtual void registerFactory(const Type& t, ComponentFactory* c) = 0;

	template<class T>
	typename mol::di::Component<T>::Ptr get(const std::string& name)
	{
		ComponentFactory* factory = getFactory(name);
		if (!factory)
			throw ContextEx("comp does not exist");

		Factory<T>* f = (Factory<T>*)factory;
		return f->component(this);
	}

	template<class T>
	typename mol::di::Component<T>::Ptr get()
	{
		ComponentFactory* factory = getFactory<T>();
		if (!factory)
			throw ContextEx("comp does not exist");

		Factory<T>* f = static_cast<Factory<T>*>(factory);
		return f->component(this);
	}

	template<class T>
	ComponentFactory* getFactory()
	{
		Type type(typeid(Traits<T>::Base));
		return getFactory(type);
	}	
};

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////


} // end namespace mol 
} // end namespace di  

//////////////////////////////////////////////////////////////////////////////////
#endif 