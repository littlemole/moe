#include "stdafx.h"
#include "proc.h"

#include "ole/dll.h"
#include "pipedprocess_i.c"

class processDll : 
	public mol::Dll,
	public mol::exports<processDll,PipedProcessAx>
{};

DLL_COCLASS_EXPORTS(processDll)

