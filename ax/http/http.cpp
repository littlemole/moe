#include "stdafx.h"
//#include "http.h"

#include "http_i.c"

class ioDll : 
	public mol::Dll,
	public mol::exports<ioDll,PathObj>,
	public mol::exports<ioDll,DirObj>,
	public mol::exports<ioDll,FileObj>

{
public:
//	DEFINE_APP_ID("{C7C1B932-871E-4374-B96E-88A4A09262E1}");
//	DEFINE_ELEVATION_STRING_IDENTIFIER(IDC_DISPLAYNAME);
};

DLL_COCLASS_EXPORTS(ioDll)

