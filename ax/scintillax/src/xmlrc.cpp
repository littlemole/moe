

#include "stdafx.h"
#include "win/res.h"
#include "xmlui.h"

#include "../scieditor.h"

#include "../ScintillACtrl.h"

#include "../ScintillAxProp.h"

#include "ole/persist.h"

#include "win/layout.h"


using namespace mol;




extern "C" void load_codegen_metadata()
{
  ODBGS("load_codegen_metadata()");
  // prepare commands - associates a title string for each command identifier
  
  
  //foreach bitmap - loads and registers bitmap
  // optionally associate cmds to toolbar icons on bitmap
  

  // menus

  mol::ole::properties<ScintillAx>().add(mol::ole::make_property("filename", DISPID_SCI_FILENAME, VT_BSTR, &CLSID_NULL));

  mol::ole::properties<ScintillAx>().add(mol::ole::make_property("readonly", DISPID_SCI_READONLY, VT_BOOL, &CLSID_NULL));

  mol::ole::properties<ScintillAx>().add(mol::ole::make_property("syntax", DISPID_SCI_SYNTAX, VT_I4, &CLSID_NULL));

  mol::ole::properties<ScintillAx>().add(mol::ole::make_property("encoding", DISPID_SCI_ENCODING, VT_I4, &CLSID_NULL));

  mol::ole::properties<ScintillAx>().add(mol::ole::make_property("tabusage", DISPID_SCI_TABUSAGE, VT_BOOL, &CLSID_NULL));

  mol::ole::properties<ScintillAx>().add(mol::ole::make_property("tabindents", DISPID_SCI_TABINDENTS, VT_BOOL, &CLSID_NULL));

  mol::ole::properties<ScintillAx>().add(mol::ole::make_property("backspaceunindents", DISPID_SCI_BACKSPACEUNINDENTS, VT_BOOL, &CLSID_NULL));

  mol::ole::properties<ScintillAx>().add(mol::ole::make_property("tabwidth", DISPID_SCI_TABWIDTH, VT_I4, &CLSID_NULL));

  mol::ole::properties<ScintillAx>().add(mol::ole::make_property("overtype", DISPID_SCI_OVERTYPE, VT_BOOL, &CLSID_NULL));

  mol::ole::properties<ScintillAx>().add(mol::ole::make_property("usecontext", DISPID_SCI_USECONTEXT, VT_BOOL, &CLSID_NULL));

  mol::ole::properties<ScintillAx>().add(mol::ole::make_property("font", DISPID_FONT, VT_FONT, &CLSID_NULL));

  mol::ole::properties<ScintillAx>().add(mol::ole::make_property( &ScintillAx::sizel,"cs"));

mol::msgMap<ScintillAx>().addMsgHandler( WM_CREATE, make_handler(&ScintillAx::OnCreate) );

mol::msgMap<ScintillAx>().addMsgHandler( WM_CONTEXTMENU, make_handler(&ScintillAx::OnContext) );

mol::msgMap<ScintillAx>().addNotifyCodeHandler( SCN_UPDATEUI, make_handler(&ScintillAx::OnUpdateUI) );

mol::msgMap<ScintillAx>().addNotifyCodeHandler( SCN_CHARADDED, make_handler(&ScintillAx::OnChar) );

mol::msgMap<ScintillAx>().addNotifyCodeHandler( SCN_DOUBLECLICK, make_handler(&ScintillAx::OnDblClick) );

mol::msgMap<ScintillAxProperties>().addMsgHandler( WM_INITDIALOG, make_handler(&ScintillAxProperties::OnInitDialog) );

mol::msgMap<ScintillAxProperties>().addCmdHandler( IDC_RADIO_UNIX, make_handler(&ScintillAxProperties::OnDirty) );

mol::msgMap<ScintillAxProperties>().addCmdHandler( IDC_RADIO_WIN32, make_handler(&ScintillAxProperties::OnDirty) );

mol::msgMap<ScintillAxProperties>().addCmdHandler( IDC_COMBO_ENCODING, make_handler(&ScintillAxProperties::OnDirty) );

mol::msgMap<ScintillAxProperties>().addCmdHandler( IDC_CHECK_USETABS, make_handler(&ScintillAxProperties::OnDirty) );

mol::msgMap<ScintillAxProperties>().addCmdHandler( IDC_CHECK_TABINDENTS, make_handler(&ScintillAxProperties::OnDirty) );

mol::msgMap<ScintillAxProperties>().addCmdHandler( IDC_EDIT_TABWIDTH, make_handler(&ScintillAxProperties::OnDirty) );

mol::msgMap<ScintillAxProperties>().addCmdHandler( IDC_CHECK_BACKSPACEUNINDENTS, make_handler(&ScintillAxProperties::OnDirty) );

mol::msgMap<ScintillAxProperties>().addCmdHandler( IDC_CHECK_WRITEBOM, make_handler(&ScintillAxProperties::OnDirty) );

mol::msgMap<ScintillAxProperties>().addCmdHandler( IDC_CONVERT_BUTTON, make_handler(&ScintillAxProperties::OnConvert) );


}

