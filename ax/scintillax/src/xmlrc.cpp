
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

mol::msgMap<ScintillAxSettings>().addMsgHandler( WM_INITDIALOG, make_handler(&ScintillAxSettings::OnInitDialog) );

mol::msgMap<ScintillAxSettings>().addCmdHandler( IDC_RADIO_UNIX, make_handler(&ScintillAxSettings::OnDirty) );

mol::msgMap<ScintillAxSettings>().addCmdHandler( IDC_RADIO_WIN32, make_handler(&ScintillAxSettings::OnDirty) );

mol::msgMap<ScintillAxSettings>().addCmdHandler( IDC_COMBO_ENCODING, make_handler(&ScintillAxSettings::OnDirty) );

mol::msgMap<ScintillAxSettings>().addCmdHandler( IDC_CHECK_USETABS, make_handler(&ScintillAxSettings::OnDirty) );

mol::msgMap<ScintillAxSettings>().addCmdHandler( IDC_CHECK_TABINDENTS, make_handler(&ScintillAxSettings::OnDirty) );

mol::msgMap<ScintillAxSettings>().addCmdHandler( IDC_EDIT_TABWIDTH, make_handler(&ScintillAxSettings::OnDirty) );

mol::msgMap<ScintillAxSettings>().addCmdHandler( IDC_CHECK_BACKSPACEUNINDENTS, make_handler(&ScintillAxSettings::OnDirty) );

mol::msgMap<ScintillAxSettings>().addCmdHandler( IDC_CHECK_WRITEBOM, make_handler(&ScintillAxSettings::OnDirty) );


}

