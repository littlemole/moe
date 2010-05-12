#include "stdafx.h"
#include "molsql.h"

#include "ole/dll.h"
#include "sql_i.c"

class sqlDll : 
	public mol::Dll,
	public mol::exports<sqlDll,SQL>
{};

DLL_COCLASS_EXPORTS(sqlDll)

