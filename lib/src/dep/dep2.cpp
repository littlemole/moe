// dep2.cpp : Defines the entry point for the console application.
//

#include "dep/builder.h"
#include "dep/dep.h"
#include "ioc.cpp"



namespace moeTest {
void init_ctx();
}


int _tmain(int argc, wchar_t* argv[])
{
	mol::di::ContextImpl ctx;
	moeTest::init_ctx(ctx);

	ctx.get<App>()->unwrap()->run();
	
	return 0;
}
