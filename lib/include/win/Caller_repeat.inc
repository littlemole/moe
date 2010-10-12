
#define n BOOST_PP_ITERATION()

#define MY_CALLER_PARAM(z,c,unused) t->Param##c BOOST_PP_COMMA_IF( BOOST_PP_SUB(BOOST_PP_SUB(n,1),c) )


template<
	CALLER_RETURN_CLASS class T BOOST_PP_COMMA_IF(n) BOOST_PP_ENUM_PARAMS(n,class P)
>
class Caller<CALLER_RETURN_TYPE,T BOOST_PP_COMMA_IF(n) BOOST_PP_ENUM_PARAMS(n,P)>
{
public:
	static void invoke(T* t)
	{
		CALLER_RETURN_POLICY ( 
			((t->object)->*(t->func))(
				
				BOOST_PP_REPEAT(n,MY_CALLER_PARAM,~)
			) 
		);
	}
};

#undef MY_CALLER_PARAM
#undef n