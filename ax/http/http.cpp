#include "stdafx.h"
#include "httpAx.h"
#include "ole/dll.h"
#include "http_i.c"

class httpDll : 
	public mol::Dll,
	public mol::exports<httpDll,Http>

{
public:
//	DEFINE_APP_ID("{C7C1B932-871E-4374-B96E-88A4A09262E1}");
//	DEFINE_ELEVATION_STRING_IDENTIFIER(IDC_DISPLAYNAME);
};

DLL_COCLASS_EXPORTS(httpDll)

