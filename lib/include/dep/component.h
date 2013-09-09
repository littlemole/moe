#ifndef MOL_DEF_GUARD_DEFINE_DEPENDENCY_INJECTION_CTX_COMPONENT_DEF_GUARD_
#define MOL_DEF_GUARD_DEFINE_DEPENDENCY_INJECTION_CTX_COMPONENT_DEF_GUARD_

#include "api.h"

namespace mol {
namespace di  {

	/*
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
		return t_.get();
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
		return t_;
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


template<class T>
class Factory : public ComponentFactory
{
public:

	virtual typename mol::di::Component<T>::Ptr component(mol::di::Context* ctx) = 0;
};


template<class T>
typename mol::di::Component<T>::Ptr make_comp( mol::di::Context* ctx, Constructor* c, const Dependencies& deps )
{
	return typename mol::di::Component<T>::Ptr( new Component<T>( ctx, c, deps) );
}


template<class T>
typename mol::di::Component<T>::Ptr make_comp( mol::di::Component<T>* c )
{
	return typename mol::di::Component<T>::Ptr( c );
}

*/

} // end namespace mol 
} // end namespace di  

#endif
