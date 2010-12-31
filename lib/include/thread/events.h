#ifndef _MOL_DEF_GUARD_DEFINE_EVENTS_DEF_GUARD_DEF_
#define _MOL_DEF_GUARD_DEFINE_EVENTS_DEF_GUARD_DEF_

#include <vector>
#include <list>

#include "boost/function.hpp"
#include "boost/bind.hpp"
#include "boost/any.hpp"
#include <boost/type_traits.hpp>
#include <iostream>
#include "util/signature.h"
#include "util/util.h"

template<class P1,class P2, class P3, class P4>
class EventHandler4
{
	public:	virtual void fire( P1 p1, P2 p2, P3 p3, P4 p4 ) = 0;
};

template<class P1,class P2, class P3>
class EventHandler3
{
	public:	virtual void fire( P1 p1, P2 p2, P3 p3 ) = 0;
};

template<class P1,class P2>
class EventHandler2
{
	public:	virtual void fire( P1 p1, P2 p2 ) = 0;
};

template<class P1>
class EventHandler1
{
	public:	virtual void fire( P1 p1 ) = 0;
};

class EventHandler0
{
	public:	virtual void fire( ) = 0;
};

template<class R, class T,class P1 = void ,class P2 = void , class P3 = void, class P4 = void>
class EventHandler : public EventHandler4<P1,P2,P3,P4>
{
public:

	typedef R ( T::*Function)(P1,P2,P3,P4);

	template<class T>
	EventHandler( Function f, T* t )
		: fun_(f), t_ (t)
	{}

	virtual void fire( P1 p1, P2 p2, P3 p3, P4 p4 )
	{
		(t_->*fun_)(p1,p2,p3,p4);
	}

	Function fun_;
	T* t_;
};


template<class R, class P1  ,class P2, class P3, class P4 >
class EventHandler<R,void,P1,P2,P3,P4> : public EventHandler4<P1,P2,P3,P4>
{
public:

	typedef R ( *Function)(P1,P2,P3,P4);

	template<class T>
	EventHandler( Function f)
		: fun_(f)
	{}

	virtual void fire( P1 p1, P2 p2, P3 p3, P4 p4 )
	{
		(*fun_)(p1,p2,p3,p4);
	}

	Function fun_;
};

template<class R, class T,class P1,class P2,class P3>
class EventHandler<R,T,P1,P2,P3,void> : public EventHandler3<P1,P2,P3>
{
public:

	typedef R ( T::*Function)(P1,P2,P3);

	template<class T>
	EventHandler( Function f, T* t )
		: fun_(f), t_ (t)
	{}

	virtual void fire( P1 p1, P2 p2, P3 p3 )
	{
		(t_->*fun_)(p1,p2,p3);
	}

	Function fun_;
	T* t_;
};


template<class R, class P1,class P2,class P3>
class EventHandler<R,void,P1,P2,P3,void> : public EventHandler3<P1,P2,P3>
{
public:

	typedef R ( *Function)(P1,P2,P3);

	template<class T>
	EventHandler( Function f)
		: fun_(f)
	{}

	virtual void fire( P1 p1, P2 p2, P3 p3 )
	{
		(*fun_)(p1,p2,p3);
	}

	Function fun_;
};

template<class R, class T,class P1,class P2>
class EventHandler<R,T,P1,P2,void,void> : public EventHandler2<P1,P2>
{
public:

	typedef R ( T::*Function)(P1,P2);

	template<class T>
	EventHandler( Function f, T* t )
		: fun_(f), t_ (t)
	{}

	virtual void fire( P1 p1, P2 p2 )
	{
		(t_->*fun_)(p1,p2);
	}

	Function fun_;
	T* t_;
};

template<class R,class P1,class P2>
class EventHandler<R,void,P1,P2,void,void> : public EventHandler2<P1,P2>
{
public:

	typedef R ( *Function)(P1,P2);

	template<class T>
	EventHandler( Function f )
		: fun_(f)
	{}

	virtual void fire( P1 p1, P2 p2 )
	{
		(t_->*fun_)(p1,p2);
	}

	Function fun_;
};

template<class R, class T,class P1>
class EventHandler<R,T,P1,void,void,void> : public EventHandler1<P1>
{
public:

	typedef R ( T::*Function)(P1);

	template<class T>
	EventHandler( Function f, T* t )
		: fun_(f), t_ (t)
	{}

	virtual void fire( P1 p1 )
	{
		(t_->*fun_)(p1);
	}

	Function fun_;
	T* t_;
};

template<class R, class P1>
class EventHandler<R,void,P1,void,void,void> : public EventHandler1<P1>
{
public:

	typedef R ( *Function)(P1);

	template<class T>
	EventHandler( Function f )
		: fun_(f)
	{}

	virtual void fire( P1 p1 )
	{
		(*fun_)(p1);
	}

	Function fun_;
};


template<class R, class T>
class EventHandler<R,T,void,void,void,void> : public EventHandler0
{
public:

	typedef R ( T::*Function)();

	template<class T>
	EventHandler( Function f, T* t )
		: fun_(f), t_ (t)
	{}

	virtual void fire(  )
	{
		(t_->*fun_)();
	}

	Function fun_;
	T* t_;
};


template<class R>
class EventHandler<R,void,void,void,void,void> : public EventHandler0
{
public:

	typedef R ( *Function)();

	template<class T>
	EventHandler( Function f )
		: fun_(f)
	{}

	virtual void fire(  )
	{
		(*fun_)();
	}

	Function fun_;
};

template<class R, class T,class P1,class P2, class P3, class P4>
EventHandler<R,T,P1,P2,P3,P4>* event_handler( R ( T::*f)(P1,P2,P3,P4) , T* t )
{
	return new EventHandler<R,T,P1,P2,P3,P4>(f,t);
}


template<class R, class P1,class P2, class P3, class P4>
EventHandler<R,void,P1,P2,P3,P4>* event_handler( R ( *f)(P1,P2,P3,P4)  )
{
	return new EventHandler<R,void,P1,P2,P3,P4>(f);
}

template<class R, class T,class P1,class P2, class P3>
EventHandler<R,T,P1,P2,P3>* event_handler( R ( T::*f)(P1,P2,P3) , T* t )
{
	return new EventHandler<R,T,P1,P2,P3>(f,t);
}


template<class R, class P1,class P2, class P3>
EventHandler<R,void,P1,P2,P3>* event_handler( R ( *f)(P1,P2,P3)  )
{
	return new EventHandler<R,void,P1,P2,P3>(f);
}

template<class R, class T,class P1,class P2>
EventHandler<R,T,P1,P2>* event_handler( R ( T::*f)(P1,P2) , T* t )
{
	return new EventHandler<R,T,P1,P2>(f,t);
}

template<class R, class P1,class P2>
EventHandler<R,void,P1,P2>* event_handler( R ( *f)(P1,P2) )
{
	return new EventHandler<R,void,P1,P2>(f);
}


template<class R, class T,class P1>
EventHandler<R,T,P1>* event_handler( R ( T::*f)(P1) , T* t )
{
	return new EventHandler<R,T,P1>(f,t);
}


template<class R, class P1>
EventHandler<R,void,P1>* event_handler( R ( *f)(P1)  )
{
	return new EventHandler<R,void,P1>(f);
}

template<class R, class T>
EventHandler<R,T>* event_handler( R ( T::*f)() , T* t )
{
	return new EventHandler<R,T>(f,t);
}

template<class R>
EventHandler<R,void>* event_handler( R ( *f)() )
{
	return new EventHandler<R,void>(f);
}

template<class P1 = void, class P2 = void, class P3 = void, class P4 = void>
class Event
{
public:
	Event()
	{}

	~Event()
	{
		clear();
	}

	Event& operator+=( EventHandler4<P1,P2,P3,P4>* handler )
	{
		events.push_back( handler );
		return *this;
	}

	Event& operator=( EventHandler4<P1,P2,P3,P4>* handler )
	{
		clear();
		events.push_back( handler );
		return *this;
	}

	void clear()
	{
		mol::purge(events);
		events.clear();
	}

	void fire( P1 p1, P2 p2, P3 p3, P4 p4)
	{
		for ( std::list<EventHandler4<P1,P2,P3,P4>*>::iterator it = events.begin(); it != events.end(); it++ )
		{
			EventHandler4<P1,P2,P3,P4>* e = (*it);
			e->fire(p1,p2,p3,p4);
		}
	}

	std::list< EventHandler4<P1,P2,P3,P4>* > events;
};

template<class P1, class P2, class P3>
class Event<P1,P2,P3>
{
public:
	Event()
	{}

	~Event()
	{
		clear();
	}

	Event& operator+=( EventHandler3<P1,P2,P3>* handler )
	{
		events.push_back( handler );
		return *this;
	}

	Event& operator=( EventHandler3<P1,P2,P3>* handler )
	{
		clear();
		events.push_back( handler );
		return *this;
	}

	void clear()
	{
		mol::purge(events);
		events.clear();
	}

	void fire( P1 p1, P2 p2, P3 p3)
	{
		for ( std::list<EventHandler3<P1,P2,P3>*>::iterator it = events.begin(); it != events.end(); it++ )
		{
			EventHandler3<P1,P2,P3>* e = (*it);
			e->fire(p1,p2,p3);
		}
	}

	std::list< EventHandler3<P1,P2,P3>* > events;
};


template<class P1, class P2>
class Event<P1,P2>
{
public:
	Event()
	{}

	~Event()
	{
		clear();
	}

	Event& operator+=( EventHandler2<P1,P2>* handler )
	{
		events.push_back( handler );
		return *this;
	}

	Event& operator=( EventHandler2<P1,P2>* handler )
	{
		clear();
		events.push_back( handler );
		return *this;
	}

	void clear()
	{
		mol::purge(events);
		events.clear();
	}

	void fire( P1 p1, P2 p2)
	{
		for ( std::list<EventHandler2<P1,P2>*>::iterator it = events.begin(); it != events.end(); it++ )
		{
			EventHandler2<P1,P2>* e = (*it);
			e->fire(p1,p2);
		}
	}

	std::list< EventHandler2<P1,P2>* > events;
};

template<class P1>
class Event<P1,void,void,void>
{
public:
	Event()
	{}

	~Event()
	{
		clear();
	}

	Event& operator+=( EventHandler1<P1>* handler )
	{
		events.push_back( handler );
		return *this;
	}

	Event& operator=( EventHandler1<P1>* handler )
	{
		clear();
		events.push_back( handler );
		return *this;
	}

	void clear()
	{
		mol::purge(events);
		events.clear();
	}

	void fire( P1 p1)
	{
		for ( std::list<EventHandler1<P1>*>::iterator 
				it  = events.begin(); 
				it != events.end(); 
				it ++ )
		{
			(*it)->fire(p1);
		}
	}

	std::list< EventHandler1<P1>* > events;
};


template<>
class Event<void,void,void,void>
{
public:
	Event()
	{}

	~Event()
	{
		clear();
	}

	Event& operator+=( EventHandler0* handler )
	{
		events.push_back( handler );
		return *this;
	}

	Event& operator=( EventHandler0* handler )
	{
		clear();
		events.push_back( handler );
		return *this;
	}

	void clear()
	{
		mol::purge(events);
		events.clear();
	}

	void fire( )
	{
		for ( std::list<EventHandler0*>::iterator 
				it  = events.begin(); 
				it != events.end(); 
				it ++ )
		{
			(*it)->fire();
		}
	}

	std::list< EventHandler0* > events;
};


template<class F>
class event
{
public:
};


template<class R,class P1,class P2,class P3,class P4>
class event<R(P1,P2,P3,P4)> : public Event<P1,P2,P3,P4> {};


template<class R,class P1,class P2,class P3>
class event<R(P1,P2,P3)> : public Event<P1,P2,P3> {};


template<class R,class P1,class P2>
class event<R(P1,P2)> : public Event<P1,P2> {};

template<class R,class P1>
class event<R(P1)> : public Event<P1> {};

template<class R>
class event<R()> : public Event<> {};

#endif
