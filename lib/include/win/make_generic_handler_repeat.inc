#define n BOOST_PP_ITERATION()

template<
	class R,
	class T BOOST_PP_COMMA_IF(n) 
	BOOST_PP_ENUM_PARAMS(n,class P)
>
MAKE_HANDLER_NAME<
	R,
	T BOOST_PP_COMMA_IF(n) 
	BOOST_PP_ENUM_PARAMS(n,P)
>* 
make_generic_handler( 
		R  (MAKE_HANDLE_CALL_TYPE T::*memFunPtr)(BOOST_PP_ENUM_PARAMS(n,P)) BOOST_PP_COMMA_IF(n) BOOST_PP_ENUM_BINARY_PARAMS(n,P, p)  
	)
{
	return new MAKE_HANDLER_NAME<
					R,
					T BOOST_PP_COMMA_IF(n) 
					BOOST_PP_ENUM_PARAMS(n,P)>( memFunPtr BOOST_PP_COMMA_IF(n) BOOST_PP_ENUM_PARAMS(n,p) );
}


#undef n


