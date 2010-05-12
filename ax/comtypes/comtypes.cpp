#include "stdafx.h"
#include "types.h"

#include "ole/dll.h"
#include "comtypes_i.c"

class comTypesDll : 
	public mol::Dll,
	public mol::exports<comTypesDll,Type2XML>
{};

DLL_COCLASS_EXPORTS(comTypesDll)

