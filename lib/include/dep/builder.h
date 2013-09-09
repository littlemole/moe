#ifndef MOL_DEF_GUARD_DEFINE_DEPENDENCY_INJECTION_CTX_BUILDER_DEF_GUARD_
#define MOL_DEF_GUARD_DEFINE_DEPENDENCY_INJECTION_CTX_BUILDER_DEF_GUARD_

#include "container.h"
#include "values.h"
#include "context.h"

namespace mol {
namespace di  {


///////////////////////////////////////////////////////////

class ComponentFactoryRegistrator
{
public:

	virtual ~ComponentFactoryRegistrator()
	{}

	virtual bool canResolve() = 0;
	virtual void registerComponentFactory() = 0;
	virtual void clear() = 0;
};



///////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////

class ContextBuilder
{
public:

	explicit ContextBuilder(Context& ctx) : ctx_(ctx) {}
	~ContextBuilder();

	void clear();

	// named factories

	template<class T>
	ComponentFactory* addFactory(const std::string& name )
	{
		return registerFactory<ComponentFactoryImpl<T> >(name,mol::di::constructor<T,T>());
	}


	template<class I, class T>
	ComponentFactory* addFactory(const std::string& name )
	{
		return registerFactory<ComponentFactoryImpl<I> >(name,mol::di::constructor<I,T>());
	}


	template<class T>
	ComponentFactory* addFactory( const std::string& name, Constructor* constructor )
	{
		return registerFactory<ComponentFactoryImpl<T> >(name,constructor);
	}

	// typed factories

	template<class T>
	ComponentFactory* addFactory( Constructor* constructor )
	{
		Type type(typeid(T));
		return registerFactory<ComponentFactoryImpl<T> >(type,constructor);
	}

	
	template<class I,class T>
	ComponentFactory* addFactory()
	{
		Type type(typeid(I));
		return registerFactory<ComponentFactoryImpl<I> >(type,mol::di::constructor<I,T>());
	}

	
	template<class I>
	ComponentFactory* addFactory()
	{
		Type type(typeid(I));
		return registerFactory<ComponentFactoryImpl<I> >(type,mol::di::constructor<I,I>());
	}

	// named singletons


	template<class T>
	ComponentFactory* addSingleton(const std::string& name )
	{
		return registerFactory<SingletonComponentFactoryImpl<T> >(name,mol::di::constructor<T,T>());
	}	
	
	

	template<class I, class C>
	ComponentFactory* addSingleton(const std::string& name )
	{
		return registerFactory<SingletonComponentFactoryImpl<I> >(name,name,mol::di::constructor<I,C>());
	}


	template<class T>
	ComponentFactory* addSingleton(const std::string& name,Constructor* constructor )
	{
		return registerFactory<SingletonComponentFactoryImpl<T> >(name,constructor);
	}

	// typed singletons

	template<class I, class C>
	ComponentFactory* addSingleton()
	{
		Type type(typeid(I));
		return registerFactory<SingletonComponentFactoryImpl<I> >(type,mol::di::constructor<I,C>());
	}
	

	template<class I>
	ComponentFactory* addSingleton()
	{
		Type type(typeid(I));
		return registerFactory<SingletonComponentFactoryImpl<I> >(type,mol::di::constructor<I,I>());
	}
	

	template<class T>
	ComponentFactory* addSingleton(Constructor* constructor )
	{
		Type type(typeid(typename T));
		return registerFactory<SingletonComponentFactoryImpl<T> >(type,constructor);
	}

	// simple

	template<class T>
	void addValue(const std::string& name,const std::string& value )
	{
		registerFactory(name,parse<T>::string(value));
	}

	template<class T>
	void addValue(const std::string& name,const T& value )
	{
		registerFactory(name,value);
	}

	template<class T>
	ListSingletonComponentFactoryImpl<T>* addList(const std::string& name)
	{
		return static_cast<ListSingletonComponentFactoryImpl<T>*>(registerFactory<ListSingletonComponentFactoryImpl<T> >(name,mol::di::constructor<std::list<T>,std::list<T> >()));
	}


	template<class T>
	VectorSingletonComponentFactoryImpl<T>* addVector(const std::string& name)
	{
		return static_cast<VectorSingletonComponentFactoryImpl<T>*>(registerFactory<VectorSingletonComponentFactoryImpl<T> >(name,mol::di::constructor<std::vector<T>,std::vector<T> >()));
	}

	template<class K, class V>
	MapSingletonComponentFactoryImpl<K,V>* addMap(const std::string& name)
	{
		return static_cast<MapSingletonComponentFactoryImpl<K,V>*>(registerFactory<MapSingletonComponentFactoryImpl<K,V> >(name,mol::di::constructor<std::map<K,V>,std::map<K,V> >()));
	}

	void resolve();

private:

	ContextBuilder(const ContextBuilder& rhs)
		:ctx_(rhs.ctx_)
	{}

	ContextBuilder& operator=(const ContextBuilder& rhs)
	{
		return *this;
	}

	template<class F>
	ComponentFactory* registerFactory( const std::string& name, Constructor* constructor )
	{
		if ( names_.count(name) > 0 )
		{
			std::ostringstream oss;
			oss << "context builder error: object " << name << " already registered!" << std::endl;
			throw ContextBuilderEx(oss.str());
		}
		ComponentFactory* factory = new F(constructor);
		return registerFactory(name,factory);
	}



	template<class F>
	ComponentFactory* registerFactory( const Type& ti, Constructor* constructor )
	{
		if ( types_.count(ti) > 0 )
		{
			std::ostringstream oss;
			oss << "context builder error: object  already registered!" << std::endl;
			throw ContextBuilderEx(oss.str());
		}
		ComponentFactory* factory = new F(constructor);
		return registerFactory(ti,factory);
	}


	template<class T>
	ComponentFactory* registerFactory( const std::string& name,const T& value)
	{
		if ( names_.count(name) > 0 )
		{
			std::ostringstream oss;
			oss << "context builder error: object " << name << " already registered!" << std::endl;
			throw ContextBuilderEx(oss.str());
		}
		ComponentFactory* factory = new ValueComponentFactoryImpl<T>(name,value);
		return registerFactory(name,factory);
	}

	ComponentFactory* registerFactory(const std::string& name,  ComponentFactory* factory);
	ComponentFactory* registerFactory(const Type& type,  ComponentFactory* factory);



	std::map<std::string,ComponentFactory*>			names_;
	std::map<Type,ComponentFactory*>				types_;

	std::list<ComponentFactoryRegistrator*>			registration_;
	Context& ctx_;
};


///////////////////////////////////////////////////////////

} // end namespace mol 
} // end namespace di  

///////////////////////////////////////////////////////////

#endif 