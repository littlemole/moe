#define n BOOST_PP_ITERATION()

template<
         class T, 
         class I BOOST_PP_COMMA_IF(n) 
         BOOST_PP_ENUM_PARAMS(n,class P)
>
class OleMsgMapHandler<T,I BOOST_PP_COMMA_IF(n) BOOST_PP_ENUM_PARAMS(n,P)> 
	: public MsgMapHandlerImpl<T>
{
public:

	typedef HRESULT (__stdcall I::*Fun)(BOOST_PP_ENUM_PARAMS(n,P));
		
	OleMsgMapHandler( Fun ptr BOOST_PP_COMMA_IF(n) BOOST_PP_ENUM_BINARY_PARAMS(n,P,p) )
		:func(ptr) BOOST_PP_COMMA_IF(n) BOOST_PP_REPEAT(n,GENERIC_PARAM,~)
	{}

	LRESULT operator()( mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		T* t = (T*)This;
		mol::punk<I> p(t->oleObject);
		if ( p )
		{
			I* object = p.interface_;
			(object->*func)( BOOST_PP_ENUM_PARAMS(n,Param) );
		}
		t->BaseWindowType::wndProc( *This, msg, wParam, lParam);
		return 0;
	}	

	BOOST_PP_REPEAT(n,GENERIC_PARAM_DECL,~)

	Fun				func;
};


#undef n