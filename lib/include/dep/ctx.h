#ifndef MOL_DEF_GUARD_DEFINE_DEPENDENCY_INJECTION_CTX_CTX_DEF_GUARD_
#define MOL_DEF_GUARD_DEFINE_DEPENDENCY_INJECTION_CTX_CTX_DEF_GUARD_

#include "api.h"
#include "context.h"

namespace mol {
namespace di  {
	
	/*
template<class T>
class Ctx
{
public:

	Ctx()
	{
		component_ = mol::di::context().getComponent<T>();
	}


	Ctx(const Comp& rhs)
	{
		component_ = rhs_.component_;
	}

	explicit Ctx(const std::string& name)
	{
		component_ = mol::di::context().getComponent<T>(name);
	}

	explicit Ctx(Comp* c)
		: component_(c)
	{
	}


	explicit Ctx(const mol::di::Component<T>* c)
		:component_(c)
	{}

	~Ctx()
	{
	}

	Ctx& operator=( const Ctx& rhs )
	{
		if ( this == &rhs )
			return *this;

		component_ = rhs.component;
		return *this;
	}

	T* operator->()
	{
		if (!component_)
			return 0;

		return component_->unwrap();
	}


	T& operator*()
	{
		if (!component_)
			throw ContextEx("no such component");

		return *component_->unwrap();
	}

	bool operator!() const
	{
		return component_;
	}

	typename mol::di::Component<T>::Ptr component()
	{
		return component_;
	}

private:

	typename mol::di::Component<T>::Ptr component_;
};


*/

} // end namespace mol 
} // end namespace di  


#endif 