
// included by resolver.h
// arguments:
// CONSTRUCTOR_ARGS_SHIFTED


#define ITER BOOST_PP_ITERATION()

// specialization- generates 
//
// template<class P1, ... class P[N]>
// class Resolver { ... }
//
// with [N] = ITER


template<BOOST_PP_ENUM_SHIFTED_PARAMS(ITER, class P)>
class Resolver<BOOST_PP_ENUM_SHIFTED_PARAMS(ITER, P)>
{
public:

	template<class I, class T>
	static I* resolve( mol::di::Context* ctx, BOOST_PP_ENUM_SHIFTED_PARAMS(CONSTRUCTOR_ARGS_SHIFTED, mol::di::Argument* arg) )
	{
		return
				(I*)
				new T(
					BOOST_PP_ENUM_SHIFTED(ITER, PARAM, 0)
				);
	}
};


#undef ITER
