#ifndef MOL_DEF_GUARD_DEFINE_DEPENDENCY_INJECTION_CTX_COMPONENT_VALUES_DEF_GUARD_
#define MOL_DEF_GUARD_DEFINE_DEPENDENCY_INJECTION_CTX_COMPONENT_VALUES_DEF_GUARD_

#include "factory.h"

namespace mol {
namespace di  {



//////////////////////////////////////////////////////////////////////////////////


template<class T>
class ValueComponentImpl : public Component<T>
{
public:

	ValueComponentImpl(const std::string& name, const T& value )
		: name_(name), value_(value)
	{}

	~ValueComponentImpl()
	{}

	virtual T* unwrap()	
	{
		return &value_;
	}

	virtual void destroy()
	{
		delete this;
	}

private:

	ValueComponentImpl( const ValueComponentImpl& rhs )
	{}

	ValueComponentImpl& operator=( const ValueComponentImpl& rhs )
	{
		return *this;
	}

	std::string name_;
	T value_;
};


template<class T>
class ValueComponentFactoryImpl : public AbstractComponentFactoryImpl<T>
{
public:

	ValueComponentFactoryImpl(const std::string& name,const T& value)
		:AbstractComponentFactoryImpl<T>(0), name_(name), value_(value)
	{}


	virtual typename mol::di::Component<T>::Ptr component(mol::di::Context* ctx)
	{
		return make_comp(new ValueComponentImpl<T>(name_,value_));
	}

	virtual ComponentFactory* clone()
	{
		return new ValueComponentFactoryImpl(name_, value_ );
	}


private:


	ValueComponentFactoryImpl( const ValueComponentFactoryImpl& rhs )
		:AbstractComponentFactoryImpl<T>(0)
	{}

	ValueComponentFactoryImpl& operator=( const ValueComponentFactoryImpl& rhs )
	{
		return *this;
	}

	std::string name_;
	T value_;
};



template<class T>
class ValueArgumentImpl : public ArgumentImpl<T>
{
public:

	ValueArgumentImpl(const T& value)
	{
		name_ = "";
		value_ = value;
	}
	
	ValueArgumentImpl(const std::string& name, const T& value)
		:  name_(name), value_(value)
	{
	}

	~ValueArgumentImpl() 
	{}
	
	virtual bool can_resolve(mol::di::Context* ctx)
	{
		return true;
	}

	virtual Comp* resolve(mol::di::Context* ctx)
	{
		component_ = make_comp(new ValueComponentImpl<T>( name_, value_ ));
		return component_.get();
	}

	virtual Argument* clone()
	{
		return new ValueArgumentImpl<T>(name_,value_);
	}

private:


	ValueArgumentImpl( const ValueArgumentImpl& rhs )
	{}

	ValueArgumentImpl& operator=( const ValueArgumentImpl& rhs )
	{
		return *this;
	}

	Dependencies dependencies_;
	std::string name_;
	T value_;
};


template<class T>
ValueArgumentImpl<T>* value(const std::string& value)
{
	return new ValueArgumentImpl<T>(parse<T>::string(value));
}


template<class T>
ValueArgumentImpl<T>* value(const T& value)
{
	return new ValueArgumentImpl<T>(value);
}


} // end namespace mol 
} // end namespace di  

#endif
