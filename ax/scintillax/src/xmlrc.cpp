

#include "stdafx.h"
#include "win/res.h"
#include "xmlui.h"

#include "../scieditor.h"

#include "../ScintillACtrl.h"

#include "../ScintillAxProp.h"

#include "ole/persist.h"

#include "win/layout.h"

#include "win/msghandler.h"


using namespace mol;




extern "C" void load_codegen_metadata()
{
  ODBGS("load_codegen_metadata()");
  // prepare commands - associates a title string for each command identifier
  
  
  //foreach bitmap - loads and registers bitmap
  // optionally associate cmds to toolbar icons on bitmap
  

  // menus

mol::msgMap<ScintillAx>().addMsgHandler( WM_CREATE, make_handler(&ScintillAx::OnCreate) );

mol::msgMap<ScintillAx>().addMsgHandler( WM_CONTEXTMENU, make_handler(&ScintillAx::OnContext) );

mol::msgMap<ScintillAx>().addNotifyCodeHandler( SCN_UPDATEUI, make_handler(&ScintillAx::OnUpdateUI) );

mol::msgMap<ScintillAx>().addNotifyCodeHandler( SCN_CHARADDED, make_handler(&ScintillAx::OnChar) );

mol::msgMap<ScintillAx>().addNotifyCodeHandler( SCN_DOUBLECLICK, make_handler(&ScintillAx::OnDblClick) );

mol::msgMap<ScintillAx>().addNotifyCodeHandler( SCN_MARGINCLICK, make_handler(&ScintillAx::OnMarginClick) );

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



HRESULT __stdcall ScintillAx::Load( LPSTREAM pStm)
{
    pStm

  << mol::property( mol::DispId(this,DISPID_SCI_FILENAME,VT_BSTR) )

  << mol::property( mol::DispId(this,DISPID_SCI_READONLY,VT_BOOL) )

  << mol::property( mol::DispId(this,DISPID_SCI_SYNTAX,VT_I4) )

  << mol::property( mol::DispId(this,DISPID_SCI_ENCODING,VT_I4) )

  << mol::property( mol::DispId(this,DISPID_SCI_TABUSAGE,VT_BOOL) )

  << mol::property( mol::DispId(this,DISPID_SCI_TABINDENTS,VT_BOOL) )

  << mol::property( mol::DispId(this,DISPID_SCI_BACKSPACEUNINDENTS,VT_BOOL) )

  << mol::property( mol::DispId(this,DISPID_SCI_TABWIDTH,VT_I4) )

  << mol::property( mol::DispId(this,DISPID_SCI_OVERTYPE,VT_BOOL) )

  << mol::property( mol::DispId(this,DISPID_SCI_USECONTEXT,VT_BOOL) )

  << mol::property( mol::DispId(this,DISPID_FONT,VT_FONT) )

  << mol::property( &sizel )
;
  return S_OK;
  }


HRESULT __stdcall ScintillAx::Save( LPSTREAM pStm,BOOL fClearDirty )
{
    pStm

  >> mol::property( mol::DispId(this,DISPID_SCI_FILENAME,VT_BSTR) )

  >> mol::property( mol::DispId(this,DISPID_SCI_READONLY,VT_BOOL) )

  >> mol::property( mol::DispId(this,DISPID_SCI_SYNTAX,VT_I4) )

  >> mol::property( mol::DispId(this,DISPID_SCI_ENCODING,VT_I4) )

  >> mol::property( mol::DispId(this,DISPID_SCI_TABUSAGE,VT_BOOL) )

  >> mol::property( mol::DispId(this,DISPID_SCI_TABINDENTS,VT_BOOL) )

  >> mol::property( mol::DispId(this,DISPID_SCI_BACKSPACEUNINDENTS,VT_BOOL) )

  >> mol::property( mol::DispId(this,DISPID_SCI_TABWIDTH,VT_I4) )

  >> mol::property( mol::DispId(this,DISPID_SCI_OVERTYPE,VT_BOOL) )

  >> mol::property( mol::DispId(this,DISPID_SCI_USECONTEXT,VT_BOOL) )

  >> mol::property( mol::DispId(this,DISPID_FONT,VT_FONT) )

  >> mol::property( &sizel )
;
  return S_OK;
  }



HRESULT __stdcall ScintillAx::Load( IPropertyBag *pPropBag,IErrorLog *pErrorLog)
{
    pPropBag

  << mol::property( _T("DISPID_SCI_FILENAME"), mol::DispId(this,DISPID_SCI_FILENAME,VT_BSTR) )

  << mol::property( _T("DISPID_SCI_READONLY"), mol::DispId(this,DISPID_SCI_READONLY,VT_BOOL) )

  << mol::property( _T("DISPID_SCI_SYNTAX"), mol::DispId(this,DISPID_SCI_SYNTAX,VT_I4) )

  << mol::property( _T("DISPID_SCI_ENCODING"), mol::DispId(this,DISPID_SCI_ENCODING,VT_I4) )

  << mol::property( _T("DISPID_SCI_TABUSAGE"), mol::DispId(this,DISPID_SCI_TABUSAGE,VT_BOOL) )

  << mol::property( _T("DISPID_SCI_TABINDENTS"), mol::DispId(this,DISPID_SCI_TABINDENTS,VT_BOOL) )

  << mol::property( _T("DISPID_SCI_BACKSPACEUNINDENTS"), mol::DispId(this,DISPID_SCI_BACKSPACEUNINDENTS,VT_BOOL) )

  << mol::property( _T("DISPID_SCI_TABWIDTH"), mol::DispId(this,DISPID_SCI_TABWIDTH,VT_I4) )

  << mol::property( _T("DISPID_SCI_OVERTYPE"), mol::DispId(this,DISPID_SCI_OVERTYPE,VT_BOOL) )

  << mol::property( _T("DISPID_SCI_USECONTEXT"), mol::DispId(this,DISPID_SCI_USECONTEXT,VT_BOOL) )

  << mol::property( _T("DISPID_FONT"), mol::DispId(this,DISPID_FONT,VT_FONT) )

  << mol::property( _T("sizel"), &sizel )
;
return S_OK;
}


HRESULT __stdcall ScintillAx::Save( IPropertyBag *pPropBag,BOOL fClearDirty,BOOL fSaveAllProperties)
{
    pPropBag

  >> mol::property( _T("DISPID_SCI_FILENAME"), mol::DispId(this,DISPID_SCI_FILENAME,VT_BSTR) )

  >> mol::property( _T("DISPID_SCI_READONLY"), mol::DispId(this,DISPID_SCI_READONLY,VT_BOOL) )

  >> mol::property( _T("DISPID_SCI_SYNTAX"), mol::DispId(this,DISPID_SCI_SYNTAX,VT_I4) )

  >> mol::property( _T("DISPID_SCI_ENCODING"), mol::DispId(this,DISPID_SCI_ENCODING,VT_I4) )

  >> mol::property( _T("DISPID_SCI_TABUSAGE"), mol::DispId(this,DISPID_SCI_TABUSAGE,VT_BOOL) )

  >> mol::property( _T("DISPID_SCI_TABINDENTS"), mol::DispId(this,DISPID_SCI_TABINDENTS,VT_BOOL) )

  >> mol::property( _T("DISPID_SCI_BACKSPACEUNINDENTS"), mol::DispId(this,DISPID_SCI_BACKSPACEUNINDENTS,VT_BOOL) )

  >> mol::property( _T("DISPID_SCI_TABWIDTH"), mol::DispId(this,DISPID_SCI_TABWIDTH,VT_I4) )

  >> mol::property( _T("DISPID_SCI_OVERTYPE"), mol::DispId(this,DISPID_SCI_OVERTYPE,VT_BOOL) )

  >> mol::property( _T("DISPID_SCI_USECONTEXT"), mol::DispId(this,DISPID_SCI_USECONTEXT,VT_BOOL) )

  >> mol::property( _T("DISPID_FONT"), mol::DispId(this,DISPID_FONT,VT_FONT) )

  >> mol::property( _T("sizel"), &sizel )
;
return S_OK;
}

