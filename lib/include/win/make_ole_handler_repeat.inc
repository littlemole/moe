#define n BOOST_PP_ITERATION()

template<
		class T, 
		class I BOOST_PP_COMMA_IF(n) 
			BOOST_PP_ENUM_PARAMS(n,class P)
>
OleMsgMapHandler<
		T,
		I BOOST_PP_COMMA_IF(n) 
		BOOST_PP_ENUM_PARAMS(n,P)
>* 
make_ole_handler( 
		HRESULT  (__stdcall I::*memFunPtr)(BOOST_PP_ENUM_PARAMS(n,P) BOOST_PP_COMMA_IF(n) BOOST_PP_ENUM_BINARY_PARAMS(n,P, p) ) 
	)
{
	return new OleMsgMapHandler<
						T,
						I BOOST_PP_COMMA_IF(n) 
						BOOST_PP_ENUM_PARAMS(n,P)>( memFunPtr BOOST_PP_COMMA_IF(n) BOOST_PP_ENUM_PARAMS(n,p) );
}


#undef n


