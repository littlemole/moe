#ifndef MOL_DEF_GUARD_DEFINE_DEPENDENCY_INJECTION_CTX_CONS_DEF_GUARD_
#define MOL_DEF_GUARD_DEFINE_DEPENDENCY_INJECTION_CTX_CONS_DEF_GUARD_

#include "argument.h"

#include <boost/preprocessor.hpp>

namespace mol {
namespace di  {

#define CONSTRUCTOR_ARGS 20
#define CONSTRUCTOR_ARGS_SHIFTED BOOST_PP_ADD(CONSTRUCTOR_ARGS,1)

#define PARAM(z, n, text) Param<BOOST_PP_CAT(P,n)>::get( BOOST_PP_CAT(arg,n)->resolve()->object() )


template<BOOST_PP_ENUM_SHIFTED_PARAMS(CONSTRUCTOR_ARGS_SHIFTED, class P)>
class Resolver
{
public:

	template<class I, class T>
	static boost::any resolve( BOOST_PP_ENUM_SHIFTED_PARAMS(CONSTRUCTOR_ARGS_SHIFTED, mol::di::Argument* arg) )
	{
		return
			boost::any(
				(I*)
				new T(
					BOOST_PP_ENUM_SHIFTED(CONSTRUCTOR_ARGS_SHIFTED, param, 0)
				));
	}
};


#define BOOST_PP_ITERATION_LIMITS (1, CONSTRUCTOR_ARGS)
#define BOOST_PP_FILENAME_1       "cons.inc.h"
#include BOOST_PP_ITERATE()

#undef PARAM


}
}

#endif