#ifndef MOL_ASYNC_DEF_GUARD_DEF_
#define MOL_ASYNC_DEF_GUARD_DEF_

#include "thread/systhread.h"

namespace mol {




template<class B>
inline int thread( B bound )
{
	return mol::Thread::call( new Task<B>(bound) );
}

template<class B, class CB>
inline int thread( B bound, CB cb )
{
	return mol::Thread::call( 
		new mol::TaskCallback<B,CB>( 
			new Task<B>(bound), 
			cb 
		)
	);
}

} // end namspace mol



/*
///////////////////////////////////////////////////////////////////////////////
// create Call/CallBack objects
///////////////////////////////////////////////////////////////////////////////

#define thread_callback( CB , C ) \
	boost::bind( CB, C, _1)


#define make_threaded_call( f, ... ) \
	mol::fun::make_task( boost::bind( f, __VA_ARGS__ ));

#define make_threaded_callback( f, cb, ... ) \
	mol::fun::make_task_callback( boost::bind( f, __VA_ARGS__ ) , cb );

*/
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// call any function on a separate thread
///////////////////////////////////////////////////////////////////////////////
/*
#define threaded_fun( f, ... )					    \
	mol::Thread::call(								\
		mol::fun::make_task(						\
			boost::bind( f, __VA_ARGS__ ) 			\
			)										\
		);	

*/

///////////////////////////////////////////////////////////////////////////////
// call a function on separate thread and provide retval via callback
///////////////////////////////////////////////////////////////////////////////
/*
#define threaded_callback( f, cb, ... )				\
	mol::Thread::call(								\
		mol::fun::thread_prepare_callback(			\
			boost::bind( f, __VA_ARGS__ ) ,			\
			cb )									\
		);											\


*/
///////////////////////////////////////////////////////////////////////////////
// call a function on separate thread and provide retval via callback on
// object member
///////////////////////////////////////////////////////////////////////////////
/*

#define threaded_obj_callback( f, cb, obj, ... )	\
	mol::Thread::call(								\
		mol::fun::thread_prepare_callback(			\
			boost::bind( f, __VA_ARGS__ ) ,			\
			boost::bind( cb, obj, _1) )				\
		);											\

*/

///////////////////////////////////////////////////////////////////////////////
// call a memeber function on separate thread and provide retval via callback on
// other object's member
///////////////////////////////////////////////////////////////////////////////
/*

#define threaded_mem_callback_mem(f, obj, cb, target, ...)	\
	mol::Thread::call(								\
		mol::fun::thread_prepare_callback(			\
			boost::bind( f,obj, __VA_ARGS__ ) ,		\
			boost::bind( cb, target, _1) )			\
		);											\

*/

///////////////////////////////////////////////////////////////////////////////
// call a memeber function on separate thread and provide retval via callback on
// same object member
///////////////////////////////////////////////////////////////////////////////
/*

#define threaded_mem_callback( f, cb, obj, ... )	\
	mol::Thread::call(								\
		mol::fun::thread_prepare_callback(			\
			boost::bind( f,obj,__VA_ARGS__ ) ,		\
			boost::bind( cb, obj, _1) )				\
		);											\


		*/
///////////////////////////////////////////////////////////////////////////////

#endif
