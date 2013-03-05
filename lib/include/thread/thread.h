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



///////////////////////////////////////////////////////////////////////////////

#endif
