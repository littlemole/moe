#define n BOOST_PP_ITERATION()

#define MSGHANDLER_PARAMS(x) BOOST_PP_CAT(MSGHANDLER_PARAMS_,x)

template<
    MSGHANDLER_RET_CLASS
	class T BOOST_PP_COMMA_IF(n) 
	BOOST_PP_ENUM_PARAMS(n,class P) 
>
class MSGHANDLER_CLASS_NAME<
			MSGHANDLER_RET_TYPE,
			T BOOST_PP_COMMA_IF(n) 
			BOOST_PP_ENUM_PARAMS(n,P)
> 
	: public MsgMapHandlerImpl<T>
{
public:

	typedef MSGHANDLER_RET_TYPE (MSGHANDLER_CALL_TYPE T::*Function)(BOOST_PP_ENUM_PARAMS(n,P));

	MSGHANDLER_CLASS_NAME( Function ptr )
		:ptr_(ptr)
	{}

	LRESULT operator()( mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		T* wnd = (T*)This;
		MSGHANDLER_PARAMS(n);
		MSGHANDLER_RET_VALUE ((wnd->*ptr_)( BOOST_PP_ENUM_PARAMS(n,param) ));
		MSGHANDLER_BASE_CALL;
		MSGHANDLER_RETURN;
	}

private:
	Function ptr_;
};


#undef n