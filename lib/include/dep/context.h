#ifndef MOL_DEF_GUARD_DEFINE_DEPENDENCY_INJECTION_CTX_CONTEXT_DEF_GUARD_
#define MOL_DEF_GUARD_DEFINE_DEPENDENCY_INJECTION_CTX_CONTEXT_DEF_GUARD_

#include "api.h"

namespace mol {
namespace di  {

typedef	std::pair<Type,ComponentFactory*>		 typedFactoryEntry;
typedef	std::pair<std::string,ComponentFactory*> namedFactoryEntry;

//////////////////////////////////////////////////////////////////////////////////

class ContextImpl : public Context
{
friend class ContextBuilder;
public:

	ContextImpl( Context* ctx = 0);
	ContextImpl( const ContextImpl& rhs );
	~ContextImpl();

	ContextImpl& operator=(const ContextImpl& rhs );

	ComponentFactory*	getFactory  (const std::string& name);
	ComponentFactory*	getFactory  (const Type& type);

	void registerFactory(std::string s, ComponentFactory* c);	
	void registerFactory(const Type& t, ComponentFactory* c);

	void clear();

private:

	void copyFrom(const ContextImpl& rhs );

	Context*									ctx_;
	
	std::map<Type,ComponentFactory*>			typedObjectMap_;
	std::map<std::string,ComponentFactory*>		namedObjectMap_;
	std::list<ComponentFactory*>				killList_;
};

//////////////////////////////////////////////////////////////////////////////////

mol::di::Context& emptyContext();

//////////////////////////////////////////////////////////////////////////////////

} // end namespace mol 
} // end namespace di  


#endif 