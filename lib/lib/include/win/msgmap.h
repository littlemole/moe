#ifndef _MSG_MAP_DEF_GUARD_DEFINE_
#define _MSG_MAP_DEF_GUARD_DEFINE_

#include <win/Core.h>
#include <map>
#include <commctrl.h>
#include <Richedit.h>
#include <commdlg.h>
#include "thread/func.h"
#include "thread/invoke.h"
#include "thread/call.h"

namespace mol {

namespace win {
class WndProc;
} //end namespace;

///////////////////////////////////////////////////////////////////
// msg craking
///////////////////////////////////////////////////////////////////

class Crack
{
public:
        Crack( UINT msg, WPARAM wParam, LPARAM lParam)
                : msg_(msg), wParam_(wParam), lParam_(lParam)
        {}

        UINT   msg()	{ return msg_;		}
        WPARAM wparam() { return wParam_;	}
        LPARAM lparam() { return lParam_;	}

        WORD   lo()		{ return LOWORD(wParam_);	}
        WORD   hi()		{ return HIWORD(wParam_);	}
        WORD   id()		{ return lo();				}
        WORD   event()  { return hi();				}

        LPNMHDR         nmhdr()		        { return (LPNMHDR)         lParam_;	}
		LPNMTVDISPINFO  treeViewDispInfo()  { return (LPNMTVDISPINFO)  lParam_; }
        LPNMTREEVIEW    nmtreeview()        { return (NMTREEVIEW*)     lParam_;	}
		LPNMTOOLBAR     nmtoolbar()			{ return (NMTOOLBAR*)	   lParam_; }
        MSGFILTER*      msgfilter()         { return (MSGFILTER*)      lParam_;	}
        FINDREPLACE*    findreplace()       { return (FINDREPLACE*)    lParam_;	}
        TV_KEYDOWN*  /*NMTVKEYDOWN* */    keydown()	        { return (TV_KEYDOWN*) /* (NMTVKEYDOWN*) */   lParam_;	}
        NMLISTVIEW*     listview()          { return (NMLISTVIEW*)     lParam_;	}
		NMLVDISPINFO*   listviewDispInfo()  { return (NMLVDISPINFO*)   lParam_;	}
		NMITEMACTIVATE* listActivate()      { return (NMITEMACTIVATE*) lParam_;	}
        NMTTDISPINFO*   toolTipDispInfo()   { return (NMTTDISPINFO*)   lParam_; }
		NMOBJECTNOTIFY* notifyObject()		{ return (NMOBJECTNOTIFY*) lParam_; }
		POINT wPoint()
		{
			return mol::Point( LOWORD(wParam_),HIWORD(wParam_));
		}

		POINT lPoint()
		{
			return mol::Point( LOWORD(lParam_),HIWORD(lParam_));
		}

private:
        UINT    msg_;
        WPARAM	wParam_;
        LPARAM	lParam_;
};

/////////////////////////////////////////////////////////////////
// Msg Map implementation template
/////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////

class IMsgMapHandler
{
public:
	LRESULT virtual operator()( mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam) = 0;

	void virtual connect_msg( int did )		  = 0;
	void virtual connect_cmd( int id )		  = 0;
	void virtual connect_notify_id( int id )  = 0;
	void virtual connect_notify_code( int id ) = 0;
};

/////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
// MSG Handler Main template
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

template<class T,class N1, class N2, class N3, class R>
class MsgMapHandler : public IMsgMapHandler
{
public:
	typedef typename T::BaseWindowType BaseWindowType;
	typedef typename mol::Signature<T,R,N1,N2,N3,void,void,void>::Function Function;

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

private:
	Function ptr_;
};

/////////////////////////////////////////////////////////////////
// specializations
/////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////
// full std msg handler including MSG parameter
/////////////////////////////////////////////////////////////////

template<class T>
class MsgMapHandler<T,UINT,WPARAM,LPARAM,LRESULT> : public IMsgMapHandler
{
public:
	typedef typename mol::Signature<T,LRESULT,UINT,WPARAM,LPARAM,void,void,void>::Function Function;

	MsgMapHandler( Function ptr )
		:ptr_(ptr)
	{}

	LRESULT operator()( mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		T* wnd = (T*)This;
		return (wnd->*ptr_)(msg,wParam,lParam);
	}

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
private:
	Function ptr_;
};

/////////////////////////////////////////////////////////////////
// full cracked std msg handler including MSG parameter
/////////////////////////////////////////////////////////////////
template<class T, class R>
class MsgMapHandler<T,mol::Crack&,void,void,R> : public IMsgMapHandler
{
public:
	typedef typename mol::Signature<T,R,mol::Crack&,void,void,void,void,void>::Function Function;

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
private:
	Function ptr_;
};

template<class T>
class MsgMapHandler<T,mol::Crack&,void,void,LRESULT> : public IMsgMapHandler
{
public:
	typedef typename mol::Signature<T,LRESULT,mol::Crack&,void,void,void,void,void>::Function Function;

	MsgMapHandler( Function ptr )
		:ptr_(ptr)
	{}

	LRESULT operator()( mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		T* wnd = (T*)This;
		mol::Crack crack(msg,wParam,lParam);
		return (wnd->*ptr_)(crack);
	}

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
private:
	Function ptr_;
};
/////////////////////////////////////////////////////////////////
// simple std msg handler w/o MSG parameter
/////////////////////////////////////////////////////////////////


template<class T>
class MsgMapHandler<T,WPARAM,LPARAM,void,LRESULT> : public IMsgMapHandler
{
public:
	typedef typename mol::Signature<T,LRESULT,WPARAM,LPARAM,void,void,void,void>::Function Function;

	MsgMapHandler( Function ptr )
		:ptr_(ptr)
	{}

	LRESULT operator()( mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		T* wnd = (T*)This;
		return (wnd->*ptr_)(wParam,lParam);
	}

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
private:
	Function ptr_;
};

/////////////////////////////////////////////////////////////////
// cmd msg handler extended version 
/////////////////////////////////////////////////////////////////

template<class T>
class MsgMapHandler<T,int,int,HWND,LRESULT> : public IMsgMapHandler
{
public:
	typedef typename mol::Signature<T,LRESULT,int,int,HWND,void,void,void>::Function Function;

	MsgMapHandler( Function ptr )
		:ptr_(ptr)
	{}

	LRESULT operator()( mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		T* wnd = (T*)This;
		mol::Crack Msg(msg,wParam,lParam);
		int hi = Msg.hi();
		int lo = Msg.lo();
		//T::BaseWindowType::wndProc( *This, msg, wParam, lParam);
		return (wnd->*ptr_)( hi, lo , (HWND)lParam);
	}

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
private:
	Function ptr_;
};


template<class T,class R>
class MsgMapHandler<T,int,int,HWND,R> : public IMsgMapHandler
{
public:
	typedef typename T::BaseWindowType BaseWindowType;
	typedef typename mol::Signature<T,R,int,int,HWND,void,void,void>::Function Function;

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
private:
	Function ptr_;
};

/////////////////////////////////////////////////////////////////
// two parameters. 
// param 1 gets mapped to wParam, 
// param 2 gets mapped to lParam, 
/////////////////////////////////////////////////////////////////

template<class T,class N1, class N2, class R>
class MsgMapHandler<T,N1,N2,void,R> : public IMsgMapHandler
{
public:

	typedef typename T::BaseWindowType BaseWindowType;
	typedef typename mol::Signature<T,R,N1,N2,void,void,void,void>::Function Function;

	MsgMapHandler( Function ptr )
		:ptr_(ptr)
	{}

	LRESULT operator()( mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		T* wnd = (T*)This;
		N1 n1 = (N1)wParam;
		N2 n2 = (N2)lParam;
		(wnd->*ptr_)(n1,n2);
		wnd->BaseWindowType::wndProc( *This, msg, wParam, lParam);
		return 0;
	}

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
private:
	Function ptr_;
};


/////////////////////////////////////////////////////////////////
// one parameters. 
// param 1 gets mapped to lParam, 
/////////////////////////////////////////////////////////////////

template<class T,class N, class R>
class MsgMapHandler<T,N,void,void,R> : public IMsgMapHandler
{
public:
	typedef typename T::BaseWindowType BaseWindowType;
	typedef typename mol::Signature<T,R,N,void,void,void,void,void>::Function Function;

	MsgMapHandler( Function ptr )
		:ptr_(ptr)
	{}

	LRESULT operator()( mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		T* wnd = (T*)This;
		N n = (N)lParam;
		(wnd->*ptr_)(n);
		wnd->BaseWindowType::wndProc( *This, msg, wParam, lParam);
		return 0;
	}

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
private:
	Function ptr_;
};



/////////////////////////////////////////////////////////////////
// no parameters. 
/////////////////////////////////////////////////////////////////

template<class T, class R>
class MsgMapHandler<T,void,void,void,R> : public IMsgMapHandler
{
public:
	typedef typename T::BaseWindowType BaseWindowType;
	typedef typename mol::Signature<T,R,void,void,void,void,void,void>::Function Function;

	MsgMapHandler( Function ptr )
		:ptr_(ptr)
	{}

	LRESULT operator()( mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		T* wnd = (T*)This;
		(wnd->*ptr_)();
		wnd->BaseWindowType::wndProc( *This, msg, wParam, lParam);
		return 0;
	}

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
private:
	Function ptr_;
};

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
// LRESULT overrides. if return is LRESULT, we return it instead of 0
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////


template<class T,class N1, class N2, class N3>
class MsgMapHandler<T,N1,N2,N3,LRESULT> : public IMsgMapHandler
{
public:
	typedef typename mol::Signature<T,LRESULT,N1,N2,N3,void,void,void>::Function Function;

	MsgMapHandler( Function ptr )
		:ptr_(ptr)
	{}

	LRESULT operator()( mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		T* wnd = (T*)This;
		N1 n1 = (N1)msg;
		N2 n2 = (N2)wParam;
		N3 n3 = (N3)lParam;
		return (wnd->*ptr_)(n1,n2,n3);
	}

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
private:
	Function ptr_;
};

/////////////////////////////////////////////////////////////////

template<class T,class N1, class N2>
class MsgMapHandler<T,N1,N2,void,LRESULT> : public IMsgMapHandler
{
public:
	typedef typename mol::Signature<T,LRESULT,N1,N2,void,void,void,void>::Function Function;

	MsgMapHandler( Function ptr )
		:ptr_(ptr)
	{}

	LRESULT operator()( mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		T* wnd = (T*)This;
		N1 n1 = (N1)wParam;
		N2 n2 = (N2)lParam;
		return (wnd->*ptr_)(n1,n2);
	}

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
private:
	Function ptr_;
};

/////////////////////////////////////////////////////////////////

template<class T,class N>
class MsgMapHandler<T,N,void,void,LRESULT> : public IMsgMapHandler
{
public:
	typedef typename mol::Signature<T,LRESULT,N,void,void,void,void,void>::Function  Function;

	MsgMapHandler( Function ptr )
		:ptr_(ptr)
	{}

	LRESULT operator()( mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		T* wnd = (T*)This;
		N n = (N)lParam;
		return (wnd->*ptr_)(n);
	}

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
private:
	Function ptr_;
};

/////////////////////////////////////////////////////////////////

template<class T>
class MsgMapHandler<T,void,void,void,LRESULT> : public IMsgMapHandler
{
public:
	typedef typename mol::Signature<T,LRESULT,void,void,void,void,void,void>::Function Function;

	MsgMapHandler( Function ptr )
		:ptr_(ptr)
	{}

	LRESULT operator()( mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		T* wnd = (T*)This;
		return (wnd->*ptr_)();
	}

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
private:
	Function ptr_;
};

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
// make MsgMapHandler functions
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

template<class T,class N1, class N2, class N3, class R>
MsgMapHandler<T,N1, N2,N3,R>* make_handler( R  (T::*memFunPtr)(N1, N2, N3) )
{
	return new MsgMapHandler<T,N1,N2,N3,R>(memFunPtr);
}


template<class T,class N1, class N2, class R>
MsgMapHandler<T,N1, N2,void,R>* make_handler( R  (T::*memFunPtr)(N1, N2) )
{
	return new MsgMapHandler<T,N1,N2,void,R>(memFunPtr);
}


template<class T,class N, class R>
MsgMapHandler<T,N,void,void,R>* make_handler( R  (T::*memFunPtr)(N) )
{
	return new MsgMapHandler<T,N,void,void,R>(memFunPtr);
}



template<class T, class R>
MsgMapHandler<T,void,void,void,R>* make_handler( R  (T::*memFunPtr)() )
{
	return new MsgMapHandler<T,void,void,void,R>(memFunPtr);
}

/////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

#ifndef _WIN64


template<class T,class N1, class N2, class N3, class R>
class StdCallMsgMapHandler : public IMsgMapHandler
{
public:
	typedef typename T::BaseWindowType BaseWindowType;
	typedef typename mol::StdCallSignature<T,R,N1,N2,N3,void,void,void>::Function Function;

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
private:
	Function ptr_;
};



template<class T,class N1, class N2, class R>
class StdCallMsgMapHandler<T,N1,N2,void,R> : public IMsgMapHandler
{
public:
	typedef typename T::BaseWindowType BaseWindowType;
	typedef typename mol::StdCallSignature<T,R,N1,N2,void,void,void,void>::Function Function;

	StdCallMsgMapHandler( Function ptr )
		:ptr_(ptr)
	{}

	LRESULT operator()( mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		T* wnd = (T*)This;
		N1 n1 = (N1)msg;
		N2 n2 = (N2)wParam;
		(wnd->*ptr_)(n1,n2);
		wnd->BaseWindowType::wndProc( *This, msg, wParam, lParam);
		return 0;
	}


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
private:
	Function ptr_;
};



template<class T,class N1, class R>
class StdCallMsgMapHandler<T,N1,void,void,R> : public IMsgMapHandler
{
public:
	typedef typename T::BaseWindowType BaseWindowType;
	typedef typename mol::StdCallSignature<T,R,N1,void,void,void,void,void>::Function Function;

	StdCallMsgMapHandler( Function ptr )
		:ptr_(ptr)
	{}

	LRESULT operator()( mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		T* wnd = (T*)This;
		N1 n1 = (N1)msg;
		(wnd->*ptr_)(n1);
		wnd->BaseWindowType::wndProc( *This, msg, wParam, lParam);
		return 0;
	}


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
private:
	Function ptr_;
};




template<class T, class R>
class StdCallMsgMapHandler<T,void,void,void,R> : public IMsgMapHandler
{
public:
	typedef typename T::BaseWindowType BaseWindowType;
	typedef typename mol::StdCallSignature<T,R,void,void,void,void,void,void>::Function Function;

	StdCallMsgMapHandler( Function ptr )
		:ptr_(ptr)
	{}

	LRESULT operator()( mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		T* wnd = (T*)This;
		(wnd->*ptr_)();
		wnd->BaseWindowType::wndProc( *This, msg, wParam, lParam);
		return 0;
	}


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
private:
	Function ptr_;
};


template<class T,class N1, class N2, class N3, class R>
StdCallMsgMapHandler<T,N1, N2,N3, R>* make_handler( R  (__stdcall T::*memFunPtr)(N1, N2, N3) )
{
	return new StdCallMsgMapHandler<T,N1,N2,N3,R>(memFunPtr);
}

template<class T,class N1, class N2, class R>
StdCallMsgMapHandler<T,N1, N2,void,R>* make_handler( R  (__stdcall T::*memFunPtr)(N1, N2) )
{
	return new StdCallMsgMapHandler<T,N1,N2,void,R>(memFunPtr);
}


template<class T,class N, class R>
StdCallMsgMapHandler<T,N,void,void,R>* make_handler( R  (__stdcall T::*memFunPtr)(N) )
{
	return new StdCallMsgMapHandler<T,N,void,void,R>(memFunPtr);
}



template<class T, class R>
StdCallMsgMapHandler<T,void,void,void,R>* make_handler( R  (__stdcall T::*memFunPtr)() )
{
	return new StdCallMsgMapHandler<T,void,void,void,R>(memFunPtr);
}

#endif

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

template<class T, 
		 class R  = void, 
		 class P1 = void, 
		 class P2 = void, 
		 class P3 = void, 
		 class P4 = void, 
		 class P5 = void, 
		 class P6 = void
>
class GenericMsgMapHandler : public IMsgMapHandler
{
public:
	typedef typename T::BaseWindowType BaseWindowType;
	typedef typename mol::Signature<T,R,P1,P2,P3,P4,P5,P6>::Function	Fun;

	typedef mol::threading::StackDeletePolicy				DeletePolicy;
	typedef GenericMsgMapHandler<T,R,P1,P2,P3,P4,P5,P6>		ThisType;
	typedef mol::threading::Func<T,R,P1,P2,P3,P4,P5,P6>		FuncType;
	typedef T												ObjectType;
	typedef R												RetType;
	
	typedef mol::threading::Param<P1> 						Param1Type;
	typedef mol::threading::Param<P2> 						Param2Type;
	typedef mol::threading::Param<P3> 						Param3Type;
	typedef mol::threading::Param<P4> 						Param4Type;
	typedef mol::threading::Param<P5> 						Param5Type;
	typedef mol::threading::Param<P6> 						Param6Type;

	GenericMsgMapHandler( Fun ptr )
		:func(ptr)
	{}

	GenericMsgMapHandler( Fun ptr, typename Param1Type::Type p1 )
		:func(ptr),Param1(p1)
	{}

	GenericMsgMapHandler( Fun ptr, typename Param1Type::Type p1,typename Param2Type::Type p2 )
		:func(ptr),Param1(p1),Param2(p2)
	{}

	GenericMsgMapHandler( Fun ptr, typename Param1Type::Type p1,typename Param2Type::Type p2,typename Param3Type::Type p3 )
		:func(ptr),Param1(p1),Param2(p2),Param3(p3)
	{}

	LRESULT operator()( mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		object = (T*)This;
		mol::threading::InvokePolicy<T,R,P1,P2,P3,P4,P5,P6>::invoke(this);
		object->BaseWindowType::wndProc( *This, msg, wParam, lParam);
		return 0;
	}


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

	Param1Type Param1;
	Param2Type Param2;
	Param3Type Param3;
	Param4Type Param4;
	Param5Type Param5;
	Param6Type Param6;

	mol::threading::ReturnTypeTraits<R>	Retval;

	///////////////////////////////////////////////////////////////////////////////

	T*				object;
	FuncType		func;
};

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

template<class T, 
		 class P1, 
		 class P2, 
		 class P3, 
		 class P4, 
		 class P5, 
		 class P6
>
class GenericMsgMapHandler<T,LRESULT,P1,P2,P3,P4,P5,P6> : public IMsgMapHandler
{
public:
	typedef typename T::BaseWindowType BaseWindowType;
	typedef typename mol::Signature<T,LRESULT,P1,P2,P3,P4,P5,P6>::Function	Fun;

	typedef mol::threading::StackDeletePolicy						DeletePolicy;
	typedef GenericMsgMapHandler<T,LRESULT,P1,P2,P3,P4,P5,P6>		ThisType;
	typedef T														ObjectType;
	typedef LRESULT													RetType;
	
	typedef mol::threading::Param<P1> 						Param1Type;
	typedef mol::threading::Param<P2> 						Param2Type;
	typedef mol::threading::Param<P3> 						Param3Type;
	typedef mol::threading::Param<P4> 						Param4Type;
	typedef mol::threading::Param<P5> 						Param5Type;
	typedef mol::threading::Param<P6> 						Param6Type;

	GenericMsgMapHandler( Fun ptr )
		:func(ptr)
	{}

	GenericMsgMapHandler( Fun ptr, typename Param1Type::Type p1 )
		:func(ptr),Param1(p1)
	{}

	GenericMsgMapHandler( Fun ptr, typename Param1Type::Type p1,typename Param2Type::Type p2 )
		:func(ptr),Param1(p1),Param2(p2)
	{}

	GenericMsgMapHandler( Fun ptr, typename Param1Type::Type p1,typename Param2Type::Type p2,typename Param3Type::Type p3 )
		:func(ptr),Param1(p1),Param2(p2),Param3(p3)
	{}

	LRESULT operator()( mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		object = (T*)This;
		mol::threading::InvokePolicy<T,LRESULT,P1,P2,P3,P4,P5,P6>::invoke(this);
		object->BaseWindowType::wndProc( *This, msg, wParam, lParam);
		return Retval.Retval;
	}


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

	Param1Type Param1;
	Param2Type Param2;
	Param3Type Param3;
	Param4Type Param4;
	Param5Type Param5;
	Param6Type Param6;

	mol::threading::ReturnTypeTraits<LRESULT>	Retval;

	///////////////////////////////////////////////////////////////////////////////

	T*				object;
	Fun				func;
};


/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

#ifndef _WIN64


template<class T, 
		 class R  = void, 
		 class P1 = void, 
		 class P2 = void, 
		 class P3 = void, 
		 class P4 = void, 
		 class P5 = void, 
		 class P6 = void
>
class GenericStdCallMsgMapHandler : public IMsgMapHandler
{
public:
	typedef typename T::BaseWindowType BaseWindowType;
	typedef mol::threading::Func<T,R,P1,P2,P3,P4,P5,P6,mol::STDCALL>		Fun;

	typedef mol::threading::StackDeletePolicy				DeletePolicy;
	typedef GenericStdCallMsgMapHandler<T,R,P1,P2,P3,P4,P5,P6>		ThisType;
	typedef mol::threading::Func<T,R,P1,P2,P3,P4,P5,P6,mol::STDCALL>		FuncType;
	typedef T												ObjectType;
	typedef R												RetType;
	
	typedef mol::threading::Param<P1> 						Param1Type;
	typedef mol::threading::Param<P2> 						Param2Type;
	typedef mol::threading::Param<P3> 						Param3Type;
	typedef mol::threading::Param<P4> 						Param4Type;
	typedef mol::threading::Param<P5> 						Param5Type;
	typedef mol::threading::Param<P6> 						Param6Type;

	GenericStdCallMsgMapHandler( Fun ptr )
		:func(ptr)
	{}

	GenericStdCallMsgMapHandler( Fun ptr, typename Param1Type::Type p1 )
		:func(ptr),Param1(p1)
	{}

	GenericStdCallMsgMapHandler( Fun ptr, typename Param1Type::Type p1,typename Param2Type::Type p2 )
		:func(ptr),Param1(p1),Param2(p2)
	{}

	GenericStdCallMsgMapHandler( Fun ptr, typename Param1Type::Type p1,typename Param2Type::Type p2,typename Param3Type::Type p3 )
		:func(ptr),Param1(p1),Param2(p2),Param3(p3)
	{}

	LRESULT operator()( mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		object = (T*)This;
		mol::threading::InvokePolicy<T,R,P1,P2,P3,P4,P5,P6>::invoke(this);
		object->BaseWindowType::wndProc( *This, msg, wParam, lParam);
		return 0;
	}


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

	Param1Type Param1;
	Param2Type Param2;
	Param3Type Param3;
	Param4Type Param4;
	Param5Type Param5;
	Param6Type Param6;

	mol::threading::ReturnTypeTraits<R>	Retval;

	///////////////////////////////////////////////////////////////////////////////

	T*				object;
	FuncType			func;
};

#endif 
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

template<class T, 
		 class R , 
		 class P1
>
GenericMsgMapHandler<T,R,P1>* make_generic_handler( R  (T::*memFunPtr)(P1), P1 p1 )
{
	return new GenericMsgMapHandler<T,R,P1>(memFunPtr,p1);
}

#ifndef _WIN64
		 
template<class T, 
		 class R , 
		 class P1
>
GenericStdCallMsgMapHandler<T,R,P1>* make_generic_handler( R  (__stdcall T::*memFunPtr)(P1), P1 p1 )
{
	return new GenericStdCallMsgMapHandler<T,R,P1>(memFunPtr,p1);
}

#endif
/////////////////////////////////////////////////////////////////

template<class T, 
		 class R, 
		 class P1, 
		 class P2
>
GenericMsgMapHandler<T,R,P1,P2>* make_generic_handler( R  (T::*memFunPtr)(P1,P2), P1 p1, P2 p2 )
{
	return new GenericMsgMapHandler<T,R,P1,P2>(memFunPtr,p1,p2);
}

#ifndef _WIN64

template<class T, 
		 class R, 
		 class P1, 
		 class P2
>
GenericStdCallMsgMapHandler<T,R,P1,P2>* make_generic_handler( R  (__stdcall T::*memFunPtr)(P1,P2), P1 p1, P2 p2 )
{
	return new GenericStdCallMsgMapHandler<T,R,P1,P2>(memFunPtr,p1,p2);
}

#endif
/////////////////////////////////////////////////////////////////

template<class T, 
		 class R, 
		 class P1, 
		 class P2, 
		 class P3, 
		 class P4, 
		 class P5, 
		 class P6
>
GenericMsgMapHandler<T,R,P1,P2,P3,P4,P5,P6>* make_generic_handler( R  (T::*memFunPtr)(P1,P2,P3,P4,P5,P6), P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6 )
{
	return new GenericMsgMapHandler<T,R,P1,P2,P3,P4,P5,P6>(memFunPtr,p1,p2,p3,p4,p5,p6);
}

#ifndef _WIN64

template<class T, 
		 class R, 
		 class P1, 
		 class P2, 
		 class P3, 
		 class P4, 
		 class P5, 
		 class P6
>
GenericStdCallMsgMapHandler<T,R,P1,P2,P3,P4,P5,P6>* make_generic_handler( R  (__stdcall T::*memFunPtr)(P1,P2,P3,P4,P5,P6), P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6 )
{
	return new GenericStdCallMsgMapHandler<T,R,P1,P2,P3,P4,P5,P6>(memFunPtr,p1,p2,p3,p4,p5,p6);
}

#endif
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

template<	 class T, 
			 class I,
			 class P1 = void, 
			 class P2 = void, 
			 class P3 = void, 
			 class P4 = void, 
			 class P5 = void, 
			 class P6 = void,
			 class CALLTYPE = mol::STDCALL
>
class OleMsgMapHandler : public IMsgMapHandler
{
public:
	typedef typename T::BaseWindowType BaseWindowType;
	typedef mol::threading::Func<I,HRESULT,P1,P2,P3,P4,P5,P6,CALLTYPE>		Fun;

	typedef mol::threading::StackDeletePolicy						DeletePolicy;
	typedef GenericMsgMapHandler<I,HRESULT,P1,P2,P3,P4,P5,P6>		ThisType;
	typedef mol::threading::Func<I,HRESULT,P1,P2,P3,P4,P5,P6,CALLTYPE>		FuncType;
	typedef I														ObjectType;
	typedef HRESULT													RetType;
	
	typedef mol::threading::Param<P1> 								Param1Type;
	typedef mol::threading::Param<P2> 								Param2Type;
	typedef mol::threading::Param<P3> 								Param3Type;
	typedef mol::threading::Param<P4> 								Param4Type;
	typedef mol::threading::Param<P5> 								Param5Type;
	typedef mol::threading::Param<P6> 								Param6Type;

	OleMsgMapHandler( Fun ptr )
		:func(ptr)
	{}

	OleMsgMapHandler( Fun ptr, typename Param1Type::Type p1 )
		:func(ptr),Param1(p1)
	{}

	OleMsgMapHandler( Fun ptr, typename Param1Type::Type p1,typename Param2Type::Type p2 )
		:func(ptr),Param1(p1),Param2(p2)
	{}

	OleMsgMapHandler( Fun ptr, typename Param1Type::Type p1,typename Param2Type::Type p2,typename Param3Type::Type p3 )
		:func(ptr),Param1(p1),Param2(p2),Param3(p3)
	{}

	LRESULT operator()( mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		T* t = (T*)This;
		mol::punk<I> p(t->oleObject);
		if ( p )
		{
			object = p.interface_;
			mol::threading::InvokePolicy<I,HRESULT,P1,P2,P3,P4,P5,P6>::invoke(this);
			object = 0;
		}
		t->BaseWindowType::wndProc( *This, msg, wParam, lParam);
		return 0;
	}


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

	Param1Type Param1;
	Param2Type Param2;
	Param3Type Param3;
	Param4Type Param4;
	Param5Type Param5;
	Param6Type Param6;

	mol::threading::ReturnTypeTraits<HRESULT>	Retval;

	///////////////////////////////////////////////////////////////////////////////

	I*				object;
	FuncType		func;
};



/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

template<class T, 
		 class I 
>
OleMsgMapHandler<T,I>* make_ole_handler( HRESULT  (__stdcall I::*memFunPtr)() )
{
	return new OleMsgMapHandler<T,I>(memFunPtr);
}

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

template<class T, 
		 class I , 
		 class P1
>
OleMsgMapHandler<T,I,P1>* make_ole_handler( HRESULT  (__stdcall I::*memFunPtr)(P1), P1 p1 )
{
	return new OleMsgMapHandler<T,I,P1>(memFunPtr);
}

/////////////////////////////////////////////////////////////////

template<class T, 
		 class I, 
		 class P1, 
		 class P2
>
OleMsgMapHandler<T,I,P1,P2>* make_ole_handler( HRESULT  (__stdcall I::*memFunPtr)(P1,P2), P1 p1, P2 p2 )
{
	return new OleMsgMapHandler<T,I,P1,P2>(memFunPtr);
}

/////////////////////////////////////////////////////////////////

template<class T, 
		 class I, 
		 class P1, 
		 class P2, 
		 class P3, 
		 class P4, 
		 class P5, 
		 class P6
>
OleMsgMapHandler<T,I,P1,P2,P3,P4,P5,P6>* make_ole_handler( HRESULT  (__stdcall I::*memFunPtr)(P1,P2,P3,P4,P5,P6), P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6 )
{
	return new OleMsgMapHandler<T,I,P1,P2,P3,P4,P5,P6>(memFunPtr,p1,p2,p3,p4,p5,p6);
}

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////


template <class WND,class BASE>
class MsgMap
{
public:

	virtual ~MsgMap()
	{
		mol::clear(msgMap_);
		mol::clear(cmdMap_);
		mol::clear(notifyCodeMap_);
		mol::clear(notifyIdMap_);
	}

    LRESULT call( WND* wnd, UINT msg, WPARAM wParam, LPARAM lParam )
    {
		// NOTIFICATION MSG by CMD?
        if ( msg == WM_NOTIFY )
        {
            LPNMHDR pnmhdr = (LPNMHDR) lParam;
			if ( pnmhdr)
            if ( notifyIdMap_.count((UINT)(pnmhdr->idFrom)) > 0 )
            {
				IMsgMapHandler* handler = notifyIdMap_[(UINT)(pnmhdr->idFrom)];
				return (*handler)( wnd, msg, wParam, lParam );
            } 
        }
		// NOTIFICATION MSG by ID?
        if ( msg == WM_NOTIFY )
        {
            LPNMHDR pnmhdr = (LPNMHDR) lParam;
			if ( pnmhdr)
            if ( notifyCodeMap_.count((UINT)(pnmhdr->code)) > 0 )
            {
                IMsgMapHandler* handler = notifyCodeMap_[(UINT)(pnmhdr->code)];
				return (*handler)( wnd, msg, wParam, lParam );
            } 
        }

		// COMMAND MSG?
		//if ( HIWORD(wParam) <= 1 )
        if ( msg == WM_COMMAND )
        {
            if ( cmdMap_.count(LOWORD(wParam)) > 0 )
            {
                IMsgMapHandler* handler = cmdMap_[LOWORD(wParam)];
				return (*handler)( wnd, msg, wParam, lParam );
            }
        }

		// ALL OTHER WINDOWS MSGS
        if ( msgMap_.count(msg) > 0 )
        {
            IMsgMapHandler* handler = msgMap_[msg];
			return (*handler)( wnd, msg, wParam, lParam );

        }
		// route through base class
		else 
		{
			BASE* b = static_cast<BASE*>(wnd);
            return b->BASE::wndProc( *wnd, msg, wParam, lParam );
		}
    }

	LRESULT callIf( WND* wnd, UINT msg, WPARAM wParam, LPARAM lParam, bool& handled )
    {
		handled = true;
		// NOTIFICATION MSG identified by Ctrl ID?
        if ( msg == WM_NOTIFY )
        {
            LPNMHDR pnmhdr = (LPNMHDR) lParam;
			if ( pnmhdr)
            if ( notifyIdMap_.count((UINT)(pnmhdr->idFrom)) > 0 )
            {
				IMsgMapHandler* handler = notifyIdMap_[(UINT)(pnmhdr->idFrom)];
				return (*handler)( wnd, msg, wParam, lParam );
            } 
        }
		// NOTIFICATION MSG by Notify Code?
        if ( msg == WM_NOTIFY )
        {
            LPNMHDR pnmhdr = (LPNMHDR) lParam;
			if ( pnmhdr)
            if ( notifyCodeMap_.count((UINT)(pnmhdr->code)) > 0 )
            {
				IMsgMapHandler* handler = notifyCodeMap_[(UINT)(pnmhdr->code)];
				return (*handler)( wnd, msg, wParam, lParam );
            } 
        }

		// COMMAND MSG?
		//if ( HIWORD(wParam) <= 1 )
        if ( msg == WM_COMMAND )
        {
            if ( cmdMap_.count(LOWORD(wParam)) > 0 )
            {
				IMsgMapHandler* handler = cmdMap_[LOWORD(wParam)];
				return (*handler)( wnd, msg, wParam, lParam );
            }
        }

		// ALL OTHER WINDOWS MSGS
        if ( msgMap_.count(msg) > 0 )
        {
			IMsgMapHandler* handler = msgMap_[msg];
			return (*handler)( wnd, msg, wParam, lParam );
        }
		handled = false;
		return 0;
    }

    void addMsgHandler(UINT i, IMsgMapHandler* fp)
    {
		msgMap_.insert(std::make_pair(i, fp));
    }

    void addCmdHandler(UINT i, IMsgMapHandler* fp)
    {
        cmdMap_.insert(std::make_pair(i, fp));
    }

    void addNotifyIdHandler(UINT i, IMsgMapHandler* fp)
    {
		notifyIdMap_.insert(std::make_pair(i, fp));
    }

	void addNotifyCodeHandler(UINT i, IMsgMapHandler* fp)
    {
		notifyCodeMap_.insert(std::make_pair(i, fp));
    }

protected:

    std::map<UINT,IMsgMapHandler*>	msgMap_;
    std::map<UINT,IMsgMapHandler*>	cmdMap_;
    std::map<UINT,IMsgMapHandler*>	notifyCodeMap_;
	std::map<UINT,IMsgMapHandler*>	notifyIdMap_;

};




/////////////////////////////////////////////////////////////////

template<class T>
MsgMap<T,typename T::BaseWindowType>& msgMap()
{
	return mol::singleton<MsgMap<T,typename T::BaseWindowType>>();
}


///////////////////////////////////////////////////////////////////
// msg handling 'attributes' for member functions
///////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////
// handle a windows message
///////////////////////////////////////////////////////////////////

#define msg_handler(cmd,mfp)													\
class MsgHandler##cmd##mfp##__	 												\
{																				\
public:																			\
																				\
	MsgHandler##cmd##mfp##__ ()													\
	{																			\
		static int i = init();													\
	}																			\
																				\
	static int init()															\
	{																			\
		mol::msgMap<ThisWindowType>()											\
			.addMsgHandler(														\
					cmd,														\
					make_handler(&ThisWindowType::##mfp ));						\
		return 0;																\
	}																			\
																				\
} msg_handler_##cmd##_##mfp ;											


#define msg_handler1(cmd,mfp,p1)												\
class MsgHandler##cmd##mfp##__	 												\
{																				\
public:																			\
																				\
	MsgHandler##cmd##mfp##__ ()													\
	{																			\
		static int i = init();													\
	}																			\
																				\
	static int init()															\
	{																			\
		mol::msgMap<ThisWindowType>()											\
			.addMsgHandler(														\
					cmd,														\
					make_generic_handler(&ThisWindowType::##mfp,p1 ));			\
		return 0;																\
	}																			\
																				\
} msg_handler_##cmd##_##mfp ;	



#define msg_handler2(cmd,mfp,p1,p2)											\
class MsgHandler##cmd##mfp##__	 												\
{																				\
public:																			\
																				\
	MsgHandler##cmd##mfp##__ ()													\
	{																			\
		static int i = init();													\
	}																			\
																				\
	static int init()															\
	{																			\
		mol::msgMap<ThisWindowType>()											\
			.addMsgHandler(														\
					cmd,														\
					make_generic_handler(&ThisWindowType::##mfp,p1,p2 ));		\
		return 0;																\
	}																			\
																				\
} msg_handler_##cmd##_##mfp ;	


///////////////////////////////////////////////////////////////////
// handle a WM_COMMAND message
///////////////////////////////////////////////////////////////////

#define cmd_handler(cmd,mfp)													\
class CmdHandler##cmd##mfp##__	 												\
{																				\
public:																			\
																				\
	CmdHandler##cmd##mfp##__ ()													\
	{																			\
		static int i = init();													\
	}																			\
																				\
	static int init()															\
	{																			\
		mol::msgMap<ThisWindowType>()											\
			.addCmdHandler(														\
					cmd,														\
					make_handler(&ThisWindowType::##mfp) );						\
		return 0;																\
	}																			\
																				\
} cmd_handler_##cmd##_##mfp ;	


#define cmd_handler1(cmd,mfp,p1)												\
class CmdHandler##cmd##mfp##__	 												\
{																				\
public:																			\
																				\
	CmdHandler##cmd##mfp##__ ()													\
	{																			\
		static int i = init();													\
	}																			\
																				\
	static int init()															\
	{																			\
		mol::msgMap<ThisWindowType>()											\
			.addCmdHandler(														\
					cmd,														\
					make_generic_handler(&ThisWindowType::##mfp,p1) );			\
		return 0;																\
	}																			\
																				\
} cmd_handler_##cmd##_##mfp ;	




#define cmd_handler2(cmd,mfp,p1,p2)												\
class CmdHandler##cmd##mfp##__	 												\
{																				\
public:																			\
																				\
	CmdHandler##cmd##mfp##__ ()													\
	{																			\
		static int i = init();													\
	}																			\
																				\
	static int init()															\
	{																			\
		mol::msgMap<ThisWindowType>()											\
			.addCmdHandler(														\
					cmd,														\
					make_generic_handler(&ThisWindowType::##mfp,p1,p2) );		\
		return 0;																\
	}																			\
																				\
} cmd_handler_##cmd##_##mfp ;

///////////////////////////////////////////////////////////////////
// handle a WM_COMMAND message and pass to corresponding method
// assumes a simple Method with no argumens
///////////////////////////////////////////////////////////////////

#define cmd_mem_handler(cmd,mfp)												\
	cmd_handler(cmd,On##mfp##cmd)												\
	LRESULT virtual On##mfp##cmd( UINT, WPARAM, LPARAM)							\
	{																			\
		mfp##();																\
		return 0;																\
	}

#define cmd_mem_handler1(cmd,mfp,p1)											\
	cmd_handler(cmd,On##mfp##cmd)												\
	LRESULT virtual On##mfp##cmd( UINT, WPARAM, LPARAM)							\
	{																			\
		mfp##(p1);																\
		return 0;																\
	}

#define cmd_mem_handler2(cmd,mfp,p1,p2)											\
	cmd_handler(cmd,On##mfp##cmd)												\
	LRESULT virtual On##mfp##cmd( UINT, WPARAM, LPARAM)							\
	{																			\
		mfp##(p1,p2);															\
		return 0;																\
	}

///////////////////////////////////////////////////////////////////
// handle several WM_COMMAND_MESSAGES
///////////////////////////////////////////////////////////////////


#define cmd_range_handler(i,j,mfp)													\
class CmdRangeHandler##i_##j##_##mfp##__	 										\
{																					\
public:																				\
																					\
	CmdRangeHandler##i_##j##_##mfp##__ ()											\
	{																				\
		static int x = init();														\
	}																				\
																					\
	static int init()																\
	{																				\
	    for ( UINT cmd = i; cmd < j+1; cmd++ )										\
        {																			\
			mol::msgMap<ThisWindowType>()											\
			.addCmdHandler(															\
					cmd, 															\
					make_handler(&ThisWindowType::##mfp) );							\
		}																			\
		return 0;																	\
	}																				\
																					\
} cmd_range_handler_##i##_##j##_##mfp ;	



#define make_cmd_range_handler(W,i,j,mfp)									\
	    for ( UINT cmd = i; cmd < j+1; cmd++ )								\
        {																	\
			mol::msgMap<W>()												\
				.addCmdHandler(												\
					cmd, 													\
					make_handler(&W::##mfp) );								\
		}



#define make_command_range_handler(W,i,j,mfp)								\
	    for ( UINT cmd = i; cmd < j+1; cmd++ )								\
        {																	\
			mol::msgMap<W>()												\
				.addCmdHandler(												\
					cmd, 													\
					make_handler(&W::##mfp) );								\
		}

///////////////////////////////////////////////////////////////////
// handle WM_Notify Message by Ctrl Id
///////////////////////////////////////////////////////////////////

#define notify_handler(cid,mfp)														\
class NotifyHandler##cid##mfp##__	 												\
{																					\
public:																				\
																					\
	NotifyHandler##cid##mfp##__ ()													\
	{																				\
		static int i = init();														\
	}																				\
																					\
	static int init()																\
	{																				\
		mol::msgMap<ThisWindowType>()												\
			.addNotifyIdHandler(													\
					cid,															\
					make_handler(&ThisWindowType::##mfp) );							\
		return 0;																	\
	}																				\
																					\
} notify_handler_##cid##_##mfp ;	



///////////////////////////////////////////////////////////////////
// handle WM_Notify Message by Notify Code
///////////////////////////////////////////////////////////////////

#define notify_code_handler(cmd,mfp)													\
class NotifyCodeHandler##cmd##mfp##__	 												\
{																						\
public:																					\
																						\
	NotifyCodeHandler##cmd##mfp##__ ()													\
	{																					\
		static int i = init();															\
	}																					\
																						\
	static int init()																	\
	{																					\
		mol::msgMap<ThisWindowType>()													\
			.addNotifyCodeHandler(														\
					cmd,																\
					make_handler(&ThisWindowType::##mfp) );								\
		return 0;																		\
	}																					\
																						\
} notify_code_handler_##cmd##_##mfp ;	


///////////////////////////////////////////////////////////////////
// handle WM_Notify Message by Ctrl id range
///////////////////////////////////////////////////////////////////

#define notify_range_handler(i,j,mfp)										\
class NotifyRangeHandler##i_##j##_##mfp##__	 								\
{																			\
public:																		\
																			\
	NotifyRangeHandler##i_##j##_##mfp##__ ()								\
	{																		\
		static int x = init();												\
	}																		\
																			\
	static int init()														\
	{																		\
	    for ( UINT cmd = i; cmd < j+1; cmd++ )								\
        {																	\
			mol::msgMap<ThisWindowType>()									\
			.addNotifyHandler(												\
					cmd, 													\
					make_handler(&ThisWindowType::##mfp) );					\
		}																	\
		return 0;															\
	}																		\
																			\
} notify_range_handler_##i##_##j##_##mfp ;	


#define make_notify_range_handler(W,i,j,mfp)								\
	    for ( UINT cmd = i; cmd < j+1; cmd++ )								\
        {																	\
			mol::msgMap<W>()												\
				.addNotifyHandler(											\
					cmd, 													\
					make_handler(&W::##mfp) );								\
		}


#define make_notification_range_handler(W,i,j,mfp)							\
	    for ( UINT cmd = i; cmd < j+1; cmd++ )								\
        {																	\
			mol::msgMap<W>()												\
				.addNotifyHandler(											\
					cmd, 													\
					make_handler(&W::##mfp) );								\
		}

/////////////////////////////////////////////////////////////////
// auto insert CMD handler whitch forwards to a embedded OLE object
// calling specified interface and calling the specified Method
// the methods signature has to be HRESULT virtual __stdcall foo();
/////////////////////////////////////////////////////////////////

#define ole_cmd_handler(cmd,iface,method)										\
class OleCmdHandler##cmd##iface##method##__	 									\
{																				\
public:																			\
																				\
	OleCmdHandler##cmd##iface##method##__ ()									\
	{																			\
		static int i = init();													\
	}																			\
																				\
	static int init()															\
	{																			\
		mol::msgMap<ThisWindowType>()											\
			.addCmdHandler(														\
					cmd,														\
					make_ole_handler<ThisWindowType,iface>(&iface::##method) );	\
		return 0;																\
	}																			\
																				\
} ole_cmd_handler_##cmd##iface##_##method ;	


/*
/////////////////////////////////////////////////////////////////
// insert MSG_MAP to class Def 
/////////////////////////////////////////////////////////////////

#define MSG_MAP(wnd,base)	\
	typedef wnd  ThisWindowType; \
    typedef base BaseWindowType; \
    LRESULT virtual wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) \
    { \
            return msgMap().call(this,message,wParam,lParam); \
    } \
	static mol::MsgMap<wnd,wnd::BaseWindowType>& msgMap() \
    { \
            static mol::MsgMap<wnd,wnd::BaseWindowType> theMsgMap; \
            return theMsgMap; \
    } \

*/

} //end namespace mol

#endif