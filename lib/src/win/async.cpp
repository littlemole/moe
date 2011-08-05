#include "win/async.h"
#include "win/app.h"
#include "util/X.h"
#include "boost/scoped_ptr.hpp"
#include "boost/shared_ptr.hpp"


namespace mol {
namespace win {

void __stdcall async_code_block_callback(ULONG_PTR cb)
{
	mol::fun::task* task = (mol::fun::task*)cb;

	(*task)();

	delete task;
}

HANDLE GetThreadHandle(unsigned int id) 
{
	HANDLE t = NULL;
	HANDLE handle = NULL;

	t = ::OpenThread(THREAD_ALL_ACCESS,FALSE,id);

	::DuplicateHandle(
		GetCurrentProcess(),
		t,
		GetCurrentProcess(),
		&handle,
		0,
		FALSE,
		DUPLICATE_SAME_ACCESS
	);
		
	::CloseHandle(t);
	return handle;
}

void run_on_gui_thread_impl(mol::fun::task* task)
{
	HANDLE handle = ::GetCurrentThread();

	bool alreadyOnGuiThread = mol::guithread() == mol::Thread::self();
	if ( !alreadyOnGuiThread ) 
	{
		handle = mol::win::GetThreadHandle(mol::guithread());
	}

	::QueueUserAPC( 
		&mol::win::async_code_block_callback, 
		handle,
		(ULONG_PTR)(task) 
	);

	if ( !alreadyOnGuiThread ) 
	{
		::CloseHandle(handle);
	}
}

} //end namespace mol::win




} // endnamespace mol



