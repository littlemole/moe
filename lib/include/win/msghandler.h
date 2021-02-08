#ifndef _MSG_HANDLER_DEF_GUARD_DEFINE_
#define _MSG_HANDLER_DEF_GUARD_DEFINE_


#include <win/msgmap.h>

//#include <boost/preprocessor.hpp>


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

template<class ... Args>
class MsgMapHandler
{};

template<class ... Args>
class StdCallMsgMapHandler
{};

template< class ... Args>
class GenericMsgMapHandler
{};

template<class ... Args>
class GenericStdCallMsgMapHandler
{};

/////////////////////////////////////////////////////////////////
// full cracked std msg handler including MSG parameter
/////////////////////////////////////////////////////////////////
template<class R, class T>
class MsgMapHandler<R,T,mol::Crack&> : public MsgMapHandlerImpl<T>
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

/////////////////////////////////////////////////////////////////
// lresult override
/////////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////////
// LRESULT variant
/////////////////////////////////////////////////////////////////

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



template<class R, class ... Args>
class GenericMsgMapHandlerParams
{};

template<class R>
class GenericMsgMapHandlerParams<R>
{
public:
	template<class T, class F, class ... Args >
	R invoke(T* t, F f, Args&& ... args)
	{
		return (t->*f)(std::forward<Args>(args)...);
	}
};

template< class R, class P, class ... Args>
class GenericMsgMapHandlerParams<R,P,Args...> : public GenericMsgMapHandlerParams<R,Args ...>
{
public:
	typedef GenericMsgMapHandlerParams<R,Args ...> BASE;

	GenericMsgMapHandlerParams(P p, Args&& ... args)
		: arg_(std::move(p)), BASE(args...)
	{}

	template<class T, class F, class ... VArgs >
	R invoke(T* t, F f, VArgs&& ... vargs)
	{
		return BASE::invoke(t, f, vargs..., arg_);
	}

private:

	P arg_;
};

/////////////////////////////////////////////////////////////////
// main generic handler template
/////////////////////////////////////////////////////////////////

template< class R, class T, class ... Args>
class GenericMsgMapHandler<R,T,Args...>: public MsgMapHandlerImpl<T>
{
public:

	typedef R(T::*Fun)(Args...);

	GenericMsgMapHandler(Fun ptr, Args&& ... args)
		:fun_(ptr), params_(std::forward<Args>(args)...)
	{}

	LRESULT operator()(mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		T* object = (T*)This;
		params_.invoke(object, fun_);
		object->BaseWindowType::wndProc(*This, msg, wParam, lParam);
		return 0;
	}

private:

	GenericMsgMapHandlerParams<R,Args...> params_;
	Fun				fun_;
};

// LRESULT override

template< class T, class ... Args >
class GenericMsgMapHandler<LRESULT, T, Args...> : public MsgMapHandlerImpl<T>
{
public:

	typedef LRESULT(T::*Fun)(Args...);

	GenericMsgMapHandler(Fun ptr, Args&& ... args)
		:fun_(ptr), params_(std::forward<Args>(args)...)
	{}

	LRESULT operator()(mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		T* object = (T*)This;
		LRESULT result = params_.invoke(object, fun_);
		object->BaseWindowType::wndProc(*This, msg, wParam, lParam);
		return result;
	}

private:

	GenericMsgMapHandlerParams<LRESULT,Args...> params_;
	Fun				fun_;
};


/////////////////////////////////////////////////////////////////
// msg handler for embedded ole objects main template
/////////////////////////////////////////////////////////////////

template<class T,class I,class ... Args>
class OleMsgMapHandler : public MsgMapHandlerImpl<T>
{
public:

	typedef HRESULT(__stdcall I::*Fun)(Args...);

	OleMsgMapHandler(Fun ptr, Args&& ... args)
		:fun_(ptr), params_(std::forward<Args>(args)...)
	{}

	LRESULT operator()(mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		T* t = (T*)This;
		mol::punk<I> p(t->oleObject);
		if (p)
		{
			I* object = p.interface_;
			params_.invoke(object, fun_);
		}
		t->BaseWindowType::wndProc(*This, msg, wParam, lParam);
		return 0;
	}

	GenericMsgMapHandlerParams<HRESULT,Args...> params_;
	Fun				fun_;
};



#ifndef _WIN64


template< class R, class T, class ... Args>
class GenericStdCallMsgMapHandler<R, T, Args...> : public MsgMapHandlerImpl<T>
{
public:

	typedef R(__stdcall T::*Fun)(Args...);

	GenericStdCallMsgMapHandler(Fun ptr, Args&& ... args)
		:fun_(ptr), params_(std::forward<Args>(args)...)
	{}

	LRESULT operator()(mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		T* object = (T*)This;
		params_.invoke(object, fun_);
		object->BaseWindowType::wndProc(*This, msg, wParam, lParam);
		return 0;
	}

private:

	GenericMsgMapHandlerParams<R,Args...> params_;
	Fun				fun_;
};

#endif

template<class ... Args>
class MsgMapHandlerParams
{};

template<class R, class P1, class P2, class P3>
class MsgMapHandlerParams<R,P1,P2,P3>
{
public:
	template<class T, class F>
	R invoke(T* t, F f, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		return (t->*f)( (P1)msg, (P2) wParam, (P3) lParam);
	}
};

template<class R, class P1, class P2>
class MsgMapHandlerParams<R, P1, P2>
{
public:
	template<class T, class F>
	R invoke(T* t, F f, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		return (t->*f)((P1)wParam, (P2)lParam);
	}
};

template<class R, class P1>
class MsgMapHandlerParams<R, P1>
{
public:
	template<class T, class F>
	R invoke(T* t, F f, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		return (t->*f)((P1)lParam);
	}
};


template<class R>
class MsgMapHandlerParams<R>
{
public:
	template<class T, class F>
	R invoke(T* t, F f, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		return (t->*f)();
	}
};

template<class R, class T, class ... Args>
class MsgMapHandler<R, T, Args ...> : public MsgMapHandlerImpl<T>
{
public:

	typedef R( T::*Function)(Args...);

	MsgMapHandler(Function ptr)
		:ptr_(ptr)
	{}

	LRESULT operator()(mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		T* wnd = (T*)This;
		params_.invoke(wnd, ptr_, msg, wParam, lParam);
		wnd->BaseWindowType::wndProc(*This, msg, wParam, lParam);
		return 0;
	}

private:
	Function ptr_;
	MsgMapHandlerParams<R, Args...> params_;
};


template<class T, class ... Args>
class MsgMapHandler<LRESULT, T, Args ...> : public MsgMapHandlerImpl<T>
{
public:

	typedef LRESULT(T::*Function)(Args...);

	MsgMapHandler(Function ptr)
		:ptr_(ptr)
	{}

	LRESULT operator()(mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		T* wnd = (T*)This;
		LRESULT result = params_.invoke(wnd, ptr_, msg, wParam, lParam);
		//wnd->BaseWindowType::wndProc(*This, msg, wParam, lParam);
		return result;
	}

private:
	Function ptr_;
	MsgMapHandlerParams<LRESULT, Args...> params_;
};

#ifndef _WIN64

template<class R, class T, class ... Args>
class StdCallMsgMapHandler<R, T, Args ...> : public MsgMapHandlerImpl<T>
{
public:
	typedef R( __stdcall T::*Function)(Args...);

	StdCallMsgMapHandler(Function ptr)
		:ptr_(ptr)
	{}

	LRESULT operator()(mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		T* wnd = (T*)This;

		params_.invoke(wnd, ptr_, msg, wParam, lParam);
		wnd->BaseWindowType::wndProc(*This, msg, wParam, lParam);
		return 0;
	}

private:


	StdCallMsgMapHandler(const StdCallMsgMapHandler<R,T,Args...> &)
	{}

	Function ptr_;
	MsgMapHandlerParams<R, Args...> params_;
};

#endif

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
// make_handler & co functions
/////////////////////////////////////////////////////////////////


template<class R, class T, class ... Args>
MsgMapHandler<R,T,Args...>* make_handler(R(T::*memFunPtr)(Args...))
{
	return new MsgMapHandler<R, T, Args...>(memFunPtr);
}

#ifndef _WIN64

template<class R, class T, class ... Args>
StdCallMsgMapHandler<R, T, Args...>* make_handler(R(__stdcall T::*memFunPtr)(Args...))
{
	return new StdCallMsgMapHandler<R, T, Args...>(memFunPtr);
}


#endif

/////////////////////////////////////////////////////////////////

template< class R, class T, class ... Args>
GenericMsgMapHandler<R, T, Args...>* make_generic_handler(R(T::*memFunPtr)(Args...), Args&& ... args)
{
	return new GenericMsgMapHandler<R, T, Args...>(memFunPtr, std::forward<Args>(args) ... );
}

#ifndef _WIN64

template< class R, class T, class ... Args>
GenericStdCallMsgMapHandler<R, T, Args...>* make_generic_handler(R(__stdcall T::*memFunPtr)(Args...), Args&& ... args)
{
	return new GenericStdCallMsgMapHandler<R, T, Args...>(memFunPtr, std::forward<Args>(args) ...);
}

#endif

/////////////////////////////////////////////////////////////////

template< class T, class I, class ... Args>
OleMsgMapHandler<T, I, Args...>* make_ole_handler(HRESULT(__stdcall I::*memFunPtr)(Args...), Args&&... args)
{
	return new OleMsgMapHandler<T, I, Args...>(memFunPtr, std::forward<Args>(args)...);
}


/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////


template<class MFP>
int make_msg_handlers(MFP mfp)
{
	return 0;
}

template<class MFP, class ... Args>
int make_msg_handlers(MFP mfp, int msg, Args ... args)
{
	mol::IMsgMapHandler* handler = mol::make_handler(mfp);
	handler->connect_msg(msg);
	return make_msg_handlers(mfp, args...);
}

template<class MFP>
int make_cmd_handlers(MFP mfp)
{
	return 0;
}

template<class MFP, class ... Args>
int make_cmd_handlers(MFP mfp, int cmd, Args ... args)
{
	mol::IMsgMapHandler* handler = mol::make_handler(mfp);
	handler->connect_cmd(cmd);
	return make_cmd_handlers(mfp, args...);
}

#define CONCAT_(a, b) a ## b




#define handle_msg_impl(mfp,line, ...)							\
static  int CONCAT_(mol_connect_msgs,line) = []()				\
{																\
	return make_msg_handlers(mfp,__VA_ARGS__);					\
}();

#define handle_msg(mfp,...)									\
handle_msg_impl(mfp,__LINE__,__VA_ARGS__)



#define handle_msg_range_impl(mfp,i,j,line)						\
static int CONCAT_(mol_connect_msg_range,line) = []()			\
{																\
	for( UINT msg = i; msg  < j+1; msg++)						\
	{															\
		mol::IMsgMapHandler* handler = mol::make_handler(mfp);	\
		handler->connect_msg(msg);								\
	}															\
	return 0;													\
}();

#define handle_msg_range(mfp,i,j)								\
handle_msg_range_impl(mfp,i,j,__LINE)





#define handle_cmd_impl(mfp,line,...)							\
static int CONCAT_(mol_connect_cmds,line) = []()				\
{																\
	return make_cmd_handlers(mfp,__VA_ARGS__);					\
}();

#define handle_cmd(mfp,...)										\
handle_cmd_impl(mfp,__LINE__,__VA_ARGS__)



#define handle_cmd_range_impl(mfp,i,j,line)						\
static int CONCAT_(mol_connect_cmd_range,line) = []()			\
{																\
	for( UINT cmd = i; cmd  < j+1; cmd++)						\
	{															\
		mol::IMsgMapHandler* handler = mol::make_handler(mfp);	\
		handler->connect_cmd(cmd);								\
	}															\
	return 0;													\
}();

#define handle_cmd_range(mfp,i,j)								\
handle_cmd_range_impl(mfp,i,j,__LINE__)



#define handle_notify_id_impl(mfp,id,line)						\
static int CONCAT_(mol_connect_notify_id,line) = []()			\
{																\
	mol::IMsgMapHandler* handler = mol::make_handler(mfp);		\
	handler->connect_notify_id(id);								\
	return 0;													\
}();

#define handle_notify_id(mfp,id)								\
handle_notify_id_impld(mfp,id,__LINE__)



#define handle_notify_code_impl(mfp,code,line)					\
static  int CONCAT_(mol_connect_notify_code,line) = []()		\
{																\
	mol::IMsgMapHandler* handler = mol::make_handler(mfp);		\
	handler->connect_notify_code(code);							\
	return 0;													\
}();

#define handle_notify_code(mfp,code)							\
handle_notify_code_impl(mfp,code,__LINE__)





#define handle_ole_cmd_impl(clazz,cmd,mfp,line)							\
static int CONCAT_(mol_connect_ole_cmd,line) = []()						\
{																		\
	mol::IMsgMapHandler* handler = mol::make_ole_handler<clazz>(mfp);	\
	handler->connect_cmd(cmd);											\
	return 0;															\
}();

#define handle_ole_cmd(clazz,cmd,mfp)									\
handle_ole_cmd_impl(clazz,cmd,mfp,__LINE__)




} //end namespace mol

#endif

