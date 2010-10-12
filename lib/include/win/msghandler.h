#ifndef _MSG_HANDLER_DEF_GUARD_DEFINE_
#define _MSG_HANDLER_DEF_GUARD_DEFINE_


#include <win/msgmap.h>

#include <boost/preprocessor.hpp>


/////////////////////////////////////////////////////////////////

namespace mol {

template<class T>
class MsgMapHandlerImpl : public IMsgMapHandler 
{
public:
	void virtual connect_cmd( int id )
	{
		mol::msgMap<T>().addCmdHandler( id, this );						
	}

	void virtual connect_msg( int id )    
	{
		mol::msgMap<T>().addMsgHandler( id, this );						
	}

	void virtual connect_notify_id( int id ) 
	{
		mol::msgMap<T>().addNotifyIdHandler( id, this );						
	}

	void virtual connect_notify_code( int id ) 
	{
		mol::msgMap<T>().addNotifyCodeHandler( id, this );						
	}

};
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
// MSG Handler Main template
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

template<class R,class T,class N1=void, class N2=void, class N3=void>
class MsgMapHandler : public MsgMapHandlerImpl<T>
{
public:

	typedef R (T::*Function)(N1,N2,N3);

	MsgMapHandler( Function ptr )
		:ptr_(ptr)
	{}

	LRESULT operator()( mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		T* wnd = (T*)This;
		N1 n1 = (N1)msg;
		N2 n2 = (N2)wParam;
		N3 n3 = (N3)lParam;
		(wnd->*ptr_)(n1,n2,n3);
		wnd->BaseWindowType::wndProc( *This, msg, wParam, lParam);
		return 0;
	}

private:
	Function ptr_;
};

// LRESULT specialization
template<class T,class N1, class N2, class N3>
class MsgMapHandler<T,N1,N2,N3,LRESULT> : public MsgMapHandlerImpl<T>
{
public:

	typedef LRESULT (T::*Function)(N1,N2,N3);

	MsgMapHandler( Function ptr )
		:ptr_(ptr)
	{}

	LRESULT operator()( mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		T* wnd = (T*)This;
		N1 n1 = (N1)msg;
		N2 n2 = (N2)wParam;
		N3 n3 = (N3)lParam;
		LRESULT lr = (LRESULT)((wnd->*ptr_)(n1,n2,n3));
		return lr;
	}

private:
	Function ptr_;
};


// __stdcall support
#ifndef _WIN64

template<class R,class T,class N1=void, class N2=void, class N3=void>
class StdCallMsgMapHandler : public MsgMapHandlerImpl<T>
{
public:

	typedef R (__stdcall T::*Function)(N1,N2,N3);

	StdCallMsgMapHandler( Function ptr )
		:ptr_(ptr)
	{}

	LRESULT operator()( mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		T* wnd = (T*)This;
		N1 n1 = (N1)msg;
		N2 n2 = (N2)wParam;
		N3 n3 = (N3)lParam;
		(wnd->*ptr_)(n1,n2,n3);
		wnd->BaseWindowType::wndProc( *This, msg, wParam, lParam);
		return 0;
	}

private:
	Function ptr_;
};


#endif

/////////////////////////////////////////////////////////////////
// specific specializations
/////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////
// full std msg handler including MSG parameter
/////////////////////////////////////////////////////////////////

template<class T>
class MsgMapHandler<LRESULT,T,UINT,WPARAM,LPARAM> : public MsgMapHandlerImpl<T>
{
public:

	typedef LRESULT (T::*Function)(UINT,WPARAM,LPARAM);

	MsgMapHandler( Function ptr )
		:ptr_(ptr)
	{}

	LRESULT operator()( mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		T* wnd = (T*)This;
		return (wnd->*ptr_)(msg,wParam,lParam);
	}

private:
	Function ptr_;
};

/////////////////////////////////////////////////////////////////
// full cracked std msg handler including MSG parameter
/////////////////////////////////////////////////////////////////
template<class T, class R>
class MsgMapHandler<R,T,mol::Crack&,void,void> : public MsgMapHandlerImpl<T>
{
public:

	typedef R (T::*Function)(mol::Crack&);

	MsgMapHandler( Function ptr )
		:ptr_(ptr)
	{}

	R operator()( mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		T* wnd = (T*)This;
		mol::Crack crack(msg,wParam,lParam);
		(wnd->*ptr_)(crack);
		wnd->BaseWindowType::wndProc( *This, msg, wParam, lParam);
		return 0;
	}

private:
	Function ptr_;
};

// lresult override
template<class T>
class MsgMapHandler<LRESULT,T,mol::Crack&,void,void> : public MsgMapHandlerImpl<T>
{
public:

	typedef LRESULT (T::*Function)(mol::Crack&);

	MsgMapHandler( Function ptr )
		:ptr_(ptr)
	{}

	LRESULT operator()( mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		T* wnd = (T*)This;
		mol::Crack crack(msg,wParam,lParam);
		return (wnd->*ptr_)(crack);
	}

private:
	Function ptr_;
};

/////////////////////////////////////////////////////////////////
// simple std msg handler w/o MSG parameter
/////////////////////////////////////////////////////////////////


template<class T>
class MsgMapHandler<LRESULT,T,WPARAM,LPARAM,void> : public MsgMapHandlerImpl<T>
{
public:

	typedef LRESULT (T::*Function)(WPARAM,LPARAM);

	MsgMapHandler( Function ptr )
		:ptr_(ptr)
	{}

	LRESULT operator()( mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		T* wnd = (T*)This;
		return (wnd->*ptr_)(wParam,lParam);
	}

private:
	Function ptr_;
};

/////////////////////////////////////////////////////////////////
// cmd msg handler extended version 
/////////////////////////////////////////////////////////////////

template<class T,class R>
class MsgMapHandler<R,T,int,int,HWND> : public MsgMapHandlerImpl<T>
{
public:

	typedef R (T::*Function)(int,int,HWND);

	MsgMapHandler( Function ptr )
		:ptr_(ptr)
	{}

	LRESULT operator()( mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		T* wnd = (T*)This;
		mol::Crack Msg(msg,wParam,lParam);
		int hi = Msg.hi();
		int lo = Msg.lo();
		(wnd->*ptr_)( hi, lo , (HWND)lParam);
		wnd->BaseWindowType::wndProc( *This, msg, wParam, lParam);
		return 0;
	}

private:
	Function ptr_;
};

// LRESULT variant

template<class T>
class MsgMapHandler<LRESULT,T,int,int,HWND> : public MsgMapHandlerImpl<T>
{
public:

	typedef LRESULT (T::*Function)(int,int,HWND);

	MsgMapHandler( Function ptr )
		:ptr_(ptr)
	{}

	LRESULT operator()( mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		T* wnd = (T*)This;
		mol::Crack Msg(msg,wParam,lParam);
		int hi = Msg.hi();
		int lo = Msg.lo();
		return (wnd->*ptr_)( hi, lo , (HWND)lParam);
	}

private:
	Function ptr_;
};


/////////////////////////////////////////////////////////////////
// generic handlers - allows to bind parameters at def time
/////////////////////////////////////////////////////////////////

#define GENERIC_HANDLER_SIZE 4
#define GENERIC_PARAM(z,n,unused) Param##n(p##n) BOOST_PP_COMMA_IF(BOOST_PP_SUB(BOOST_PP_SUB(GENERIC_HANDLER_SIZE,1),n))
#define GENERIC_PARAM_DECL(z,n,unused) P##n Param##n; 

/////////////////////////////////////////////////////////////////
// main generic handler template
/////////////////////////////////////////////////////////////////

template<class R, 
		 class T, 
		 BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(GENERIC_HANDLER_SIZE,class P,void)
>
class GenericMsgMapHandler : public MsgMapHandlerImpl<T>
{
public:

	typedef R (T::*Fun)(BOOST_PP_ENUM_PARAMS(GENERIC_HANDLER_SIZE,P));
	
	GenericMsgMapHandler( Fun ptr, BOOST_PP_ENUM_BINARY_PARAMS(GENERIC_HANDLER_SIZE,P,p) )
		:func(ptr),BOOST_PP_REPEAT(GENERIC_HANDLER_SIZE,GENERIC_PARAM,~)
	{}

	LRESULT operator()( mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		object = (T*)This;
		(object->*func)( BOOST_PP_ENUM_PARAMS(GENERIC_HANDLER_SIZE,Param) );
		object->BaseWindowType::wndProc( *This, msg, wParam, lParam);
		return 0;
	}

	BOOST_PP_REPEAT(GENERIC_HANDLER_SIZE,GENERIC_PARAM_DECL,~)

	Fun				func;
};


/////////////////////////////////////////////////////////////////
// generic handler template with LRESULT specialization
/////////////////////////////////////////////////////////////////


template<class T, 
		 BOOST_PP_ENUM_PARAMS(GENERIC_HANDLER_SIZE,class P)
>
class GenericMsgMapHandler<LRESULT,T,BOOST_PP_ENUM_PARAMS(GENERIC_HANDLER_SIZE,P)> 
	: public MsgMapHandlerImpl<T>
{
public:

	typedef LRESULT (T::*Fun)(BOOST_PP_ENUM_PARAMS(GENERIC_HANDLER_SIZE,P));

	GenericMsgMapHandler( Fun ptr, BOOST_PP_ENUM_BINARY_PARAMS(GENERIC_HANDLER_SIZE,P,p) )
		:func(ptr),BOOST_PP_REPEAT(GENERIC_HANDLER_SIZE,GENERIC_PARAM,~)
	{}

	LRESULT operator()( mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		T* object = (T*)This;
		LRESULT lr = (object->*func)( BOOST_PP_ENUM_PARAMS(GENERIC_HANDLER_SIZE,Param) );
		object->BaseWindowType::wndProc( *This, msg, wParam, lParam);
		return lr;
	}

	BOOST_PP_REPEAT(GENERIC_HANDLER_SIZE,GENERIC_PARAM_DECL,~)

	Fun				func;
};



/////////////////////////////////////////////////////////////////
// Generic __stdcall support
/////////////////////////////////////////////////////////////////

#ifndef _WIN64

template<class R, 
		 class T, 
		 BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(GENERIC_HANDLER_SIZE,class P,void)
>
class GenericStdCallMsgMapHandler : public MsgMapHandlerImpl<T>
{
public:

	typedef R (__stdcall T::*Fun)( BOOST_PP_ENUM_PARAMS(GENERIC_HANDLER_SIZE,P) );
	
	GenericStdCallMsgMapHandler( Fun ptr, BOOST_PP_ENUM_BINARY_PARAMS(GENERIC_HANDLER_SIZE,P,p) )
		:func(ptr),BOOST_PP_REPEAT(GENERIC_HANDLER_SIZE,GENERIC_PARAM,~)
	{}

	LRESULT operator()( mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		T* object = (T*)This;
		(object->*func)( BOOST_PP_ENUM_PARAMS(GENERIC_HANDLER_SIZE,Param) );
		object->BaseWindowType::wndProc( *This, msg, wParam, lParam);
		return 0;
	}

	BOOST_PP_REPEAT(GENERIC_HANDLER_SIZE,GENERIC_PARAM_DECL,~)

	Fun				func;
};

#endif 


/////////////////////////////////////////////////////////////////
// msg handler for embedded ole objects main template
/////////////////////////////////////////////////////////////////

template<	 class T, 
			 class I,
			 BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(GENERIC_HANDLER_SIZE,class P,void)
>
class OleMsgMapHandler : public MsgMapHandlerImpl<T>
{
public:

	typedef HRESULT (__stdcall I::*Fun)(BOOST_PP_ENUM_PARAMS(GENERIC_HANDLER_SIZE,P));
	
	OleMsgMapHandler( Fun ptr, BOOST_PP_ENUM_BINARY_PARAMS(GENERIC_HANDLER_SIZE,P,p) )
		:func(ptr), BOOST_PP_REPEAT(GENERIC_HANDLER_SIZE,GENERIC_PARAM,~)
	{}

	LRESULT operator()( mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		T* t = (T*)This;
		mol::punk<I> p(t->oleObject);
		if ( p )
		{
			I* object = p.interface_;
			(object->*func)( BOOST_PP_ENUM_PARAMS(GENERIC_HANDLER_SIZE,Param) );
		}
		t->BaseWindowType::wndProc( *This, msg, wParam, lParam);
		return 0;
	}

	BOOST_PP_REPEAT(GENERIC_HANDLER_SIZE,GENERIC_PARAM_DECL,~)

	Fun				func;
};


/////////////////////////////////////////////////////////////////
// code gen
/////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
// generate specializations for less then 3 params
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

#define MSG_HANDLER_SIZE 3

#define  MSGHANDLER_PARAMS_2 P0 param0 = (P0)wParam; P1 param1 = (P1)lParam;
#define  MSGHANDLER_PARAMS_1 P0 param0 = (P0)lParam;
#define  MSGHANDLER_PARAMS_0 

#define MSGHANDLER_CLASS_NAME MsgMapHandler
#define MSGHANDLER_CALL_TYPE


// specializations for less then 3 params
#define MSGHANDLER_RET_TYPE R
#define MSGHANDLER_RET_CLASS class R,
#define MSGHANDLER_RET_VALUE 
#define MSGHANDLER_RETURN return 0
#define MSGHANDLER_BASE_CALL wnd->BaseWindowType::wndProc( *This, msg, wParam, lParam)

#define BOOST_PP_ITERATION_LIMITS (0, MSG_HANDLER_SIZE-1)
#define BOOST_PP_FILENAME_1       "win/MsgMapHandler_repeat.inc"
#include BOOST_PP_ITERATE()

// cleanup 
#undef MSGHANDLER_RET_TYPE 
#undef MSGHANDLER_RET_CLASS
#undef MSGHANDLER_RET_VALUE
#undef MSGHANDLER_RETURN 
#undef MSGHANDLER_BASE_CALL

// specializations for less then 3 params, LRESULT retvalue
#define MSGHANDLER_RET_TYPE LRESULT
#define MSGHANDLER_RET_CLASS 
#define MSGHANDLER_RET_VALUE LRESULT retval = 
#define MSGHANDLER_RETURN return (LRESULT)retval
#define MSGHANDLER_BASE_CALL

#define BOOST_PP_ITERATION_LIMITS (0, MSG_HANDLER_SIZE-1)
#define BOOST_PP_FILENAME_1       "win/MsgMapHandler_repeat.inc"
#include BOOST_PP_ITERATE()

// cleanup 
#undef MSGHANDLER_RET_TYPE 
#undef MSGHANDLER_RET_CLASS
#undef MSGHANDLER_RET_VALUE
#undef MSGHANDLER_RETURN 
#undef MSGHANDLER_BASE_CALL
#undef MSGHANDLER_CLASS_NAME
#undef MSGHANDLER_CALL_TYPE

#ifndef _WIN64

// specializations for less then 3 params __stdcall signature
#define MSGHANDLER_CLASS_NAME StdCallMsgMapHandler
#define MSGHANDLER_CALL_TYPE __stdcall
#define MSGHANDLER_RET_TYPE HRESULT
#define MSGHANDLER_RET_CLASS 
#define MSGHANDLER_RET_VALUE  
#define MSGHANDLER_RETURN return 0
#define MSGHANDLER_BASE_CALL wnd->BaseWindowType::wndProc( *This, msg, wParam, lParam)

#define BOOST_PP_ITERATION_LIMITS (0, MSG_HANDLER_SIZE-1)
#define BOOST_PP_FILENAME_1       "win/MsgMapHandler_repeat.inc"
#include BOOST_PP_ITERATE()

#endif


// cleanup 
#undef MSGHANDLER_CLASS_NAME
#undef MSGHANDLER_RET_TYPE 
#undef MSGHANDLER_RET_CLASS
#undef MSGHANDLER_RET_VALUE
#undef MSGHANDLER_RETURN 
#undef MSGHANDLER_BASE_CALL
#undef MSGHANDLER_CALL_TYPE

/////////////////////////////////////////////////////////////////
// generic specializations
/////////////////////////////////////////////////////////////////

#undef GENERIC_PARAM
#define GENERIC_PARAM(z,c,unused) Param##c(p##c) BOOST_PP_COMMA_IF(BOOST_PP_SUB(BOOST_PP_SUB(n,1),c))


// generic handler for arbitary mem functions
#define GENERICHANDLER_CLASS_NAME GenericMsgMapHandler
#define GENERICHANDLER_CALL_TYPE 
#define GENERICHANDLER_RETURN_CLASS class R,
#define GENERICHANDLER_RETURN_TYPE R
#define GENERICHANDLER_RETURN_DECL
#define GENERICHANDLER_RETURN_POLICY return 0
#define GENERICHANDLER_BASE_CALL object->BaseWindowType::wndProc( *This, msg, wParam, lParam)


#define BOOST_PP_ITERATION_LIMITS (0, GENERIC_HANDLER_SIZE-1)
#define BOOST_PP_FILENAME_1       "win/GenericMsgMapHandler_repeat.inc"
#include BOOST_PP_ITERATE()

#undef GENERICHANDLER_CLASS_NAME
#undef GENERICHANDLER_RETURN_CLASS
#undef GENERICHANDLER_RETURN_TYPE
#undef GENERICHANDLER_RETURN_POLICY
#undef GENERICHANDLER_RETURN_DECL
#undef GENERICHANDLER_CALL_TYPE
#undef GENERICHANDLER_BASE_CALL 

// specialization for LRESULT return type
#define GENERICHANDLER_CLASS_NAME GenericMsgMapHandler
#define GENERICHANDLER_CALL_TYPE 
#define GENERICHANDLER_RETURN_CLASS 
#define GENERICHANDLER_RETURN_DECL LRESULT lr = 
#define GENERICHANDLER_RETURN_TYPE LRESULT
#define GENERICHANDLER_RETURN_POLICY return lr
#define GENERICHANDLER_BASE_CALL

#define BOOST_PP_ITERATION_LIMITS (0, GENERIC_HANDLER_SIZE-1)
#define BOOST_PP_FILENAME_1       "win/GenericMsgMapHandler_repeat.inc"
#include BOOST_PP_ITERATE()

#undef GENERICHANDLER_CLASS_NAME
#undef GENERICHANDLER_RETURN_CLASS
#undef GENERICHANDLER_RETURN_TYPE
#undef GENERICHANDLER_RETURN_POLICY
#undef GENERICHANDLER_RETURN_DECL
#undef GENERICHANDLER_CALL_TYPE
#undef GENERICHANDLER_BASE_CALL 

#ifndef _WIN64

// speczialization for __stdcall mem functions
#define GENERICHANDLER_CLASS_NAME GenericStdCallMsgMapHandler
#define GENERICHANDLER_CALL_TYPE __stdcall
#define GENERICHANDLER_RETURN_CLASS class R,
#define GENERICHANDLER_RETURN_TYPE R
#define GENERICHANDLER_RETURN_DECL 
#define GENERICHANDLER_RETURN_POLICY return 0
#define GENERICHANDLER_BASE_CALL object->BaseWindowType::wndProc( *This, msg, wParam, lParam)


#define BOOST_PP_ITERATION_LIMITS (0, GENERIC_HANDLER_SIZE-1)
#define BOOST_PP_FILENAME_1       "win/GenericMsgMapHandler_repeat.inc"
#include BOOST_PP_ITERATE()

#endif

// speczialization for embedded Ole object interface handler

#define BOOST_PP_ITERATION_LIMITS (0, GENERIC_HANDLER_SIZE-1)
#undef BOOST_PP_FILENAME_1
#define BOOST_PP_FILENAME_1       "win/OleMsgMapHandler_repeat.inc"
#include BOOST_PP_ITERATE()


// cleanup

#undef BOOST_PP_ITERATION_LIMITS
#undef BOOST_PP_FILENAME_1
#undef GENERIC_PARAM
#undef GENERIC_PARAM_DECL

#undef GENERICHANDLER_CLASS_NAME
#undef GENERICHANDLER_RETURN_CLASS
#undef GENERICHANDLER_RETURN_TYPE
#undef GENERICHANDLER_RETURN_POLICY
#undef GENERICHANDLER_RETURN_DECL
#undef GENERICHANDLER_CALL_TYPE
#undef GENERICHANDLER_BASE_CALL 

#undef GENERIC_HANDLER_SIZE

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
// make_handler & co functions
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

#define MAKE_HANDLER_NAME MsgMapHandler
#define MAKE_HANDLE_CALL_TYPE

#define BOOST_PP_ITERATION_LIMITS (0, MSG_HANDLER_SIZE)
#define BOOST_PP_FILENAME_1       "win/make_handler_repeat.inc"
#include BOOST_PP_ITERATE()

#undef MAKE_HANDLER_NAME 
#undef MAKE_HANDLE_CALL_TYPE

/////////////////////////////////////////////////////////////////

#ifndef _WIN64

#define MAKE_HANDLER_NAME StdCallMsgMapHandler
#define MAKE_HANDLE_CALL_TYPE __stdcall

#define BOOST_PP_ITERATION_LIMITS (0, MSG_HANDLER_SIZE)
#define BOOST_PP_FILENAME_1       "win/make_handler_repeat.inc"
#include BOOST_PP_ITERATE()

#undef MAKE_HANDLER_NAME 
#undef MAKE_HANDLE_CALL_TYPE


#endif


/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

#define MAKE_HANDLER_NAME GenericMsgMapHandler
#define MAKE_HANDLE_CALL_TYPE 

#define BOOST_PP_ITERATION_LIMITS (0, MSG_HANDLER_SIZE)
#define BOOST_PP_FILENAME_1       "win/make_generic_handler_repeat.inc"
#include BOOST_PP_ITERATE()

#undef MAKE_HANDLER_NAME 
#undef MAKE_HANDLE_CALL_TYPE


#ifndef _WIN64

#define MAKE_HANDLER_NAME GenericStdCallMsgMapHandler
#define MAKE_HANDLE_CALL_TYPE __stdcall

#define BOOST_PP_ITERATION_LIMITS (0, MSG_HANDLER_SIZE)
#define BOOST_PP_FILENAME_1       "win/make_generic_handler_repeat.inc"
#include BOOST_PP_ITERATE()

#undef MAKE_HANDLER_NAME 
#undef MAKE_HANDLE_CALL_TYPE

#endif


/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////


#define BOOST_PP_ITERATION_LIMITS (0, MSG_HANDLER_SIZE)
#define BOOST_PP_FILENAME_1       "win/make_ole_handler_repeat.inc"
#include BOOST_PP_ITERATE()


/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////


} //end namespace mol

#endif

