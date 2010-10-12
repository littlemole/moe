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
make_handler( 
		R  (MAKE_HANDLE_CALL_TYPE T::*memFunPtr)(BOOST_PP_ENUM_PARAMS(n,P) ) 
	)
{
	return new MAKE_HANDLER_NAME<
						R,
						T BOOST_PP_COMMA_IF(n) 
						BOOST_PP_ENUM_PARAMS(n,P)>( memFunPtr );
}


#undef n


