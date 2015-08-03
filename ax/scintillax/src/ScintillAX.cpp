// skeleton.cpp : Definiert den Einstiegspunkt für die Anwendung.
//

#include "stdafx.h"
#include "ScintillaCtrl.h"
#include "ScintillAxProp.h"
#include "ScintillAx_i.c"
#include "ShellCtrl/ShellCtrl_i.c"
#include "ssh/ssh_i.c"
#include "ole/Dll.h"
#include "win/res.h"
#include "SciStyle.h"
#include <sstream>

///////////////////////////////////////////////////////////////////////////////////
// scintilla control DLL impl
///////////////////////////////////////////////////////////////////////////////////



class scintillaDll : 
	public mol::Dll,
	public mol::exports_aggregable<scintillaDll,ScintillAx>,
	public mol::exports_aggregable<scintillaDll,ScintillAxProperties>,
	public mol::exports_aggregable<scintillaDll,ScintillAxSettings>,
	public mol::exports_aggregable<scintillaDll,AxStyleSets>
{
public:
	scintillaDll() : si(mol::hinstance()) // brings in scintilla lib
	{
		mol::CodePages& cp = mol::CodePages::instance();
		::load_codegen_metadata();		
	}

private:
	scintilla_init si;
};

///////////////////////////////////////////////////////////////////////////////////
// canonical DLL entry points impl
///////////////////////////////////////////////////////////////////////////////////

DLL_COCLASS_EXPORTS(scintillaDll);

