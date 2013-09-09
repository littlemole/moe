#ifndef MOL_DEF_GUARD_DEFINE_DEPENDENCY_INJECTION_CTX_RESOLVER_DEF_GUARD_
#define MOL_DEF_GUARD_DEFINE_DEPENDENCY_INJECTION_CTX_RESOLVER_DEF_GUARD_


// included by constructor.h
// preprocessor arguments: 
// 
// CONSTRUCTOR_ARGS
// CONSTRUCTOR_ARGS_SHIFTED

namespace mol {
namespace di  {


// Macro to generate PARAM - passed to every constructor argument
#define PARAM(z, n, text) Traits<BOOST_PP_CAT(P,n)>::cast( (BOOST_PP_CAT(arg,n)->resolve(ctx) ))

// main template.
// generates 
//
// template<class P1, ... class P[N]>
// class Resolver { ... }
//
// with [N] = CONSTRUCTOR_ARGS_SHIFTED

template<BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS(CONSTRUCTOR_ARGS_SHIFTED, class P, = void BOOST_PP_INTERCEPT)>
class Resolver
{
public:

	// single static resolve method
	// generates
	//
	// template<class I, class T>
	// static I* resolve( mol::di::Context* ctx, mol::di::Argument1* arg, ... mold::di::Argument[N]) ) { ... }
	//
	// with [N] = CONSTRUCTOR_ARGS_SHIFTED

	template<class I, class T>
	static I* resolve( mol::di::Context* ctx, BOOST_PP_ENUM_SHIFTED_PARAMS(CONSTRUCTOR_ARGS_SHIFTED, mol::di::Argument* arg) )
	{
		// a new instance of T as a T* using plain old new with the constructor( Traits<P1)>::cast(arg1->resolve(ctx)), ... Traits<P[N])>::cast(arg[N]->resolve(ctx)) )
		// 
		return
				(I*)
				new T(
					BOOST_PP_ENUM_SHIFTED(CONSTRUCTOR_ARGS_SHIFTED, PARAM, 0)
				);
	}

};

// generate constructor template specializations
//
// template<class P1, ... P[N]>
// class Resolver {}
//
// with [N] = CONSTRUCTOR_ARGS				!!! ( the main template uses CONSTRUCTOR_ARGS_SHIFTED )

#define BOOST_PP_ITERATION_LIMITS (1, CONSTRUCTOR_ARGS)
#define BOOST_PP_FILENAME_1       "cons.inc.h"
#include BOOST_PP_ITERATE()

#undef PARAM


}
}

#endif
