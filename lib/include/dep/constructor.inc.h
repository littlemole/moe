

// included by resolver.h
//
// CONSTRUCTOR_ARGS_SHIFTED

#define ITER BOOST_PP_ITERATION()

// number of void arguments
#define NVOID BOOST_PP_SUB(  CONSTRUCTOR_ARGS_SHIFTED, ITER ) 

// do we have a COMMA ?
#define COMMA BOOST_PP_COMMA_IF( BOOST_PP_AND(BOOST_PP_NOT_EQUAL( ITER, 1 ),BOOST_PP_NOT_EQUAL( ITER, CONSTRUCTOR_ARGS_SHIFTED ) ) )

// generates
// ARG
#define ARGS(z, n, text) ARG(n)(BOOST_PP_CAT(arg,n))

#define VOIDS(z, n, text) ARG(BOOST_PP_ADD(ITER,n))(new mol::di::VoidArgument)

	ConstructorImpl( BOOST_PP_ENUM_SHIFTED_PARAMS(ITER, Argument* arg) ) 
		: BOOST_PP_ENUM_SHIFTED(ITER, ARGS, 0) COMMA BOOST_PP_ENUM(NVOID,VOIDS,0)
	{}


#undef VOIDS
#undef COMMA
#undef ARGS
#undef NVOID
#undef ITER
