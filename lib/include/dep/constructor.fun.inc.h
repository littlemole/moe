
#define ITER BOOST_PP_ITERATION()

#define COMMA BOOST_PP_COMMA_IF(BOOST_PP_NOT_EQUAL(ITER,1))

#define ARGS(z, n, text) ArgumentImpl< BOOST_PP_CAT(P,n) >* BOOST_PP_CAT(arg,n)


template<class T COMMA BOOST_PP_ENUM_SHIFTED_PARAMS(ITER, class P)>
Constructor* constructor( BOOST_PP_ENUM_SHIFTED(ITER, ARGS, 0 ) )
{
	return new ConstructorImpl<T,T COMMA BOOST_PP_ENUM_SHIFTED_PARAMS(ITER, P) >( BOOST_PP_ENUM_SHIFTED_PARAMS(ITER, arg) );
}



template<class I, class T  COMMA BOOST_PP_ENUM_SHIFTED_PARAMS(ITER, class P)>
Constructor* constructor( BOOST_PP_ENUM_SHIFTED(ITER, ARGS, 0 ) )
{
	return new ConstructorImpl<I,T COMMA BOOST_PP_ENUM_SHIFTED_PARAMS(ITER, P) >( BOOST_PP_ENUM_SHIFTED_PARAMS(ITER, arg) );
}

#undef ARGS
#undef ITER
#undef COMMA

