#ifndef MOL_DEF_GUARD_DEFINE_DEPENDENCY_INJECTION_ARGUMENT_DEF_GUARD_
#define MOL_DEF_GUARD_DEFINE_DEPENDENCY_INJECTION_ARGUMENT_DEF_GUARD_

#include "api.h"

namespace mol {
namespace di  {


//////////////////////////////////////////////////////////////////////////////////

class Argument
{
public:
	virtual ~Argument() {}

	virtual bool can_resolve(Context* cx) = 0;
	virtual Comp*    resolve(Context* cx) = 0;
	virtual Argument*  clone() = 0;
};

//////////////////////////////////////////////////////////////////////////////////

template<class T>
class ArgumentImpl : public Argument
{
public:

	typedef T Type;

	ArgumentImpl() 
	{}
	
	~ArgumentImpl() 
	{}

	virtual bool can_resolve(mol::di::Context* ctx)
	{
		return ctx->getFactory<Traits<T>::Base>() != 0;
	}

	virtual Comp* resolve(mol::di::Context* ctx)
	{
		component_ = ctx->get<Traits<T>::Base>();
		return component_.get();
	}

	virtual Argument* clone()
	{
		return new ArgumentImpl<Traits<T>::Base>;
	}

protected:


	ArgumentImpl( const ArgumentImpl& rhs )
	{}

	ArgumentImpl& operator=( const ArgumentImpl& rhs )
	{
		return *this;
	}

	boost::shared_ptr< mol::di::Component<typename Traits<T>::Base> > component_;
};

//////////////////////////////////////////////////////////////////////////////////

template<class T>
class NamedArgumentImpl : public ArgumentImpl<T>
{
public:

	typedef T Type;


	NamedArgumentImpl(const std::string& name)
		:  name_(name)
	{}
	
	~NamedArgumentImpl() 
	{}

	
	virtual bool can_resolve(mol::di::Context* ctx)
	{
		return ctx->getFactory(name_) != 0;
	}

	virtual Comp* resolve(mol::di::Context* ctx)
	{
		component_ = ctx->get<Traits<T>::Base>(name_);
		return component_.get();
	}

	virtual Argument* clone()
	{
		return new NamedArgumentImpl<T>(name_);
	}

private:


	NamedArgumentImpl( const NamedArgumentImpl& rhs )
	{}

	NamedArgumentImpl& operator=( const NamedArgumentImpl& rhs )
	{
		return *this;
	}

	std::string name_;
};

//////////////////////////////////////////////////////////////////////////////////

template<>
class ArgumentImpl<void> : public Argument
{
public:

	typedef void Type;


	ArgumentImpl() 
	{}
	
	~ArgumentImpl() 
	{}

	virtual bool can_resolve(mol::di::Context* ctx)
	{
		return true;
	}

	virtual Comp* resolve(mol::di::Context* ctx)
	{
		return 0;
	}

	virtual Argument* clone()
	{
		return new ArgumentImpl<void>;
	}

protected:

	ArgumentImpl( const ArgumentImpl& rhs )
	{}


	ArgumentImpl& operator=( const ArgumentImpl& rhs )
	{
		return *this;
	}
};

//////////////////////////////////////////////////////////////////////////////////

typedef ArgumentImpl<void> VoidArgument;

//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////


template<class T>
ArgumentImpl<T>* arg( )
{
	return new ArgumentImpl<T>;
}


template<class T>
NamedArgumentImpl<T>* arg(  const std::string& name)
{
	return new NamedArgumentImpl<T>(name);
}


} // end namespace mol 
} // end namespace di  

#endif