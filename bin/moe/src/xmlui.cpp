

#include "stdafx.h"
#include "win/res.h"
#include "xmlui.h"

#include "app.h"

#include "dir3.h"

#include "editor.h"

#include "formeditor.h"

#include "hex.h"

#include "html.h"

#include "img.h"

#include "ole.h"

#include "form.h"

#include "rtf.h"

#include "Docs.h"

#include "MoeBar.h"

#include "tree.h"

#include "win/msghandler.h"


using namespace mol;



void MoeWndGUIBuilder::loadUI()
{
    MoeWnd* moe = (MoeWnd*)wnd_;

    makeMainWindow( moe, _T("moe"), (HMENU)IDM_SMALL_MENU, stdRect, IDW_MOE );

}



  // window


void MoeWndGUIBuilder::makeUI()
{

    MoeWnd* moe = (MoeWnd*)wnd_;
    BorderLayout* layout = moe->setLayout(new BorderLayout);

    //childWindow
    MoeTreeWnd* treeWnd = makeWindow<MoeTreeWnd>((HMENU)IDW_TREE_VIEW, mol::Rect(0,0,160,200), (HWND)*moe);
    treeWnd->show(SW_SHOW);

    layout->add( *treeWnd, BorderLayout::WEST );

    //childWindow
    MoeTabControl* tab = makeWindow<MoeTabControl>((HMENU)IDW_TAB_CTRL, mol::Rect(0,0,160,26), (HWND)*moe);
    tab->show(SW_HIDE);

    layout->add( *tab, BorderLayout::SOUTH );

    //statusbar
    MoeStatusBar* statusBar = makeWindow<MoeStatusBar>((HMENU)IDW_STATUS, stdRect, (HWND)*moe);
    statusBar->show(SW_SHOW);

    layout->addStatusBar( statusBar );
    statusBar->setText(_T(""));

    //childWindow
    mol::ProgressbarCtrl* progress = makeWindow<mol::ProgressbarCtrl>((HMENU)IDW_PROGRESS_BAR, mol::Rect(3,7,300,12), (HWND)*statusBar);
    progress->show(SW_SHOW);
    progress->setColor(RGB(175,175,175));
    progress->setBkColor(RGB(222,222,222));
    progress->setRange(0,100);
    progress->setPos(10);

    //reBar
    MoeBar* reBar = makeWindow < MoeBar>((HMENU)IDW_REBAR, mol::Rect(0,0,200,300), (HWND)*moe);

    //toolBar
    MoeToolBar* fileBar = makeWindow<MoeToolBar>((HMENU)IDC_TOOLBARS_FILEBAR, Rect(0,0,90,24), (HWND)*reBar);
    fileBar->setBmp( IDB_TOOLBAR, 43, 16,16  );
    fileBar->setButtonSize( 16,16  );
    fileBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_FILE_NEW),IDM_FILE_NEW , mol::UI().CmdString(IDM_FILE_NEW),TBSTATE_ENABLED,BTNS_BUTTON );
    fileBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_FILE_OPEN),IDM_FILE_OPEN , mol::UI().CmdString(IDM_FILE_OPEN),TBSTATE_ENABLED,BTNS_BUTTON );
    fileBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_FILE_SAVE),IDM_FILE_SAVE , mol::UI().CmdString(IDM_FILE_SAVE),TBSTATE_ENABLED,BTNS_BUTTON );
    fileBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_FILE_SAVE_AS),IDM_FILE_SAVE_AS , mol::UI().CmdString(IDM_FILE_SAVE_AS),TBSTATE_ENABLED,BTNS_BUTTON );
    fileBar->addButtons();
    fileBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_VIEW_DIRVIEW),IDM_VIEW_DIRVIEW , mol::UI().CmdString(IDM_VIEW_DIRVIEW),TBSTATE_ENABLED,BTNS_BUTTON );
    fileBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_FILE_OPEN_FOLDER),IDM_FILE_OPEN_FOLDER , mol::UI().CmdString(IDM_FILE_OPEN_FOLDER),TBSTATE_ENABLED,BTNS_BUTTON );
    fileBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_FILE_PRINT),IDM_FILE_PRINT , mol::UI().CmdString(IDM_FILE_PRINT),TBSTATE_ENABLED,BTNS_BUTTON );
    fileBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_FILE_EXIT),IDM_FILE_EXIT , mol::UI().CmdString(IDM_FILE_EXIT),TBSTATE_ENABLED,BTNS_BUTTON );
    reBar->addBar( *fileBar, IDC_TOOLBARS_FILEBAR, 90  );

    //toolBar
    MoeToolBar* editBar = makeWindow<MoeToolBar>((HMENU)IDC_TOOLBARS_EDITBAR, Rect(0,0,32,24), (HWND)*reBar);
    editBar->setBmp( IDB_TOOLBAR, 43, 16,16  );
    editBar->setButtonSize( 16,16  );
    editBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_EDIT_UNDO),IDM_EDIT_UNDO , mol::UI().CmdString(IDM_EDIT_UNDO),TBSTATE_ENABLED,BTNS_BUTTON );
    editBar->addButtons();
    editBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_EDIT_REDO),IDM_EDIT_REDO , mol::UI().CmdString(IDM_EDIT_REDO),TBSTATE_ENABLED,BTNS_BUTTON );
    editBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_EDIT_CUT),IDM_EDIT_CUT , mol::UI().CmdString(IDM_EDIT_CUT),TBSTATE_ENABLED,BTNS_BUTTON );
    editBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_EDIT_COPY),IDM_EDIT_COPY , mol::UI().CmdString(IDM_EDIT_COPY),TBSTATE_ENABLED,BTNS_BUTTON );
    editBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_EDIT_PASTE),IDM_EDIT_PASTE , mol::UI().CmdString(IDM_EDIT_PASTE),TBSTATE_ENABLED,BTNS_BUTTON );
    editBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_EDIT_FIND),IDM_EDIT_FIND , mol::UI().CmdString(IDM_EDIT_FIND),TBSTATE_ENABLED,BTNS_BUTTON );
    editBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_EDIT_REPLACE),IDM_EDIT_REPLACE , mol::UI().CmdString(IDM_EDIT_REPLACE),TBSTATE_ENABLED,BTNS_BUTTON );
    reBar->addBar( *editBar, IDC_TOOLBARS_EDITBAR, 32  );

    //toolBar
    MoeToolBar* toolsBar = makeWindow<MoeToolBar>((HMENU)IDC_TOOLBARS_TOOLBAR, Rect(0,0,32,24), (HWND)*reBar);
    toolsBar->setBmp( IDB_TOOLBAR, 43, 16,16  );
    toolsBar->setButtonSize( 16,16  );
    toolsBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_EDIT_COLOR),IDM_EDIT_COLOR , mol::UI().CmdString(IDM_EDIT_COLOR),TBSTATE_ENABLED,BTNS_BUTTON );
    toolsBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_EDIT_EXECUTESCRIPT),IDM_EDIT_EXECUTESCRIPT , mol::UI().CmdString(IDM_EDIT_EXECUTESCRIPT),TBSTATE_ENABLED,BTNS_BUTTON );
    toolsBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_USER_SHORTCUT),IDM_USER_SHORTCUT , mol::UI().CmdString(IDM_USER_SHORTCUT),TBSTATE_ENABLED,BTNS_DROPDOWN );
    toolsBar->addButtons();
    toolsBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_MODE_EXECUTEFORM),IDM_MODE_EXECUTEFORM , mol::UI().CmdString(IDM_MODE_EXECUTEFORM),TBSTATE_ENABLED,BTNS_BUTTON );
    toolsBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_USER_SCRIPT),IDM_USER_SCRIPT , mol::UI().CmdString(IDM_USER_SCRIPT),TBSTATE_ENABLED,BTNS_DROPDOWN );
    toolsBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_USER_BATCH),IDM_USER_BATCH , mol::UI().CmdString(IDM_USER_BATCH),TBSTATE_ENABLED,BTNS_DROPDOWN );
    toolsBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_USER_FORM),IDM_USER_FORM , mol::UI().CmdString(IDM_USER_FORM),TBSTATE_ENABLED,BTNS_DROPDOWN );
    reBar->addBar( *toolsBar, IDC_TOOLBARS_TOOLBAR, 32  );

    //toolBar
    MoeToolBar* settingsBar = makeWindow<MoeToolBar>((HMENU)IDC_TOOLBARS_SETTINGBAR, Rect(0,0,64,24), (HWND)*reBar);
    settingsBar->setBmp( IDB_TOOLBAR, 43, 16,16  );
    settingsBar->setButtonSize( 16,16  );
    settingsBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_MODE_EOL),IDM_MODE_EOL , mol::UI().CmdString(IDM_MODE_EOL),TBSTATE_ENABLED,BTNS_DROPDOWN );
    settingsBar->addButtons();
    settingsBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_MODE_LANGUAGE),IDM_MODE_LANGUAGE , mol::UI().CmdString(IDM_MODE_LANGUAGE),TBSTATE_ENABLED,BTNS_DROPDOWN );
    settingsBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_MODE_SETTINGS),IDM_MODE_SETTINGS , mol::UI().CmdString(IDM_MODE_SETTINGS),TBSTATE_ENABLED,BTNS_BUTTON );
    settingsBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_MODE_PREFERENCES),IDM_MODE_PREFERENCES , mol::UI().CmdString(IDM_MODE_PREFERENCES),TBSTATE_ENABLED,BTNS_BUTTON );
    settingsBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_MODE_EDITSETTINGS),IDM_MODE_EDITSETTINGS , mol::UI().CmdString(IDM_MODE_EDITSETTINGS),TBSTATE_ENABLED,BTNS_BUTTON );
    reBar->addBar( *settingsBar, IDC_TOOLBARS_SETTINGBAR, 64  );
    reBar->showBar(IDC_TOOLBARS_SETTINGBAR,false);

    //toolBar
    MoeToolBar* viewBar = makeWindow<MoeToolBar>((HMENU)IDC_TOOLBARS_VIEWBAR, Rect(0,0,64,24), (HWND)*reBar);
    viewBar->setBmp( IDB_TOOLBAR, 43, 16,16  );
    viewBar->setButtonSize( 16,16  );
    viewBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_VIEW_MAXIMIZE),IDM_VIEW_MAXIMIZE , mol::UI().CmdString(IDM_VIEW_MAXIMIZE),TBSTATE_ENABLED,BTNS_BUTTON );
    viewBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_VIEW_MINIMIZE),IDM_VIEW_MINIMIZE , mol::UI().CmdString(IDM_VIEW_MINIMIZE),TBSTATE_ENABLED,BTNS_BUTTON );
    viewBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_VIEW_CASCADE),IDM_VIEW_CASCADE , mol::UI().CmdString(IDM_VIEW_CASCADE),TBSTATE_ENABLED,BTNS_BUTTON );
    viewBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_VIEW_TILE),IDM_VIEW_TILE , mol::UI().CmdString(IDM_VIEW_TILE),TBSTATE_ENABLED,BTNS_BUTTON );
    viewBar->addButtons();
    viewBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_VIEW_NEXT),IDM_VIEW_NEXT , mol::UI().CmdString(IDM_VIEW_NEXT),TBSTATE_ENABLED,BTNS_BUTTON );
    viewBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_VIEW_CLOSE),IDM_VIEW_CLOSE , mol::UI().CmdString(IDM_VIEW_CLOSE),TBSTATE_ENABLED,BTNS_BUTTON );
    reBar->addBar( *viewBar, IDC_TOOLBARS_VIEWBAR, 64  );
    reBar->showBar(IDC_TOOLBARS_VIEWBAR,false);

    //toolBar
    MoeToolBar* userBar = makeWindow<MoeToolBar>((HMENU)IDC_TOOLBARS_USERBAR, Rect(0,0,100,24), (HWND)*reBar);
    userBar->setBmp( IDB_TOOLBAR, 43, 16,16  );
    userBar->setButtonSize( 16,16  );
    userBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_HELP_ABOUT),IDM_HELP_ABOUT , mol::UI().CmdString(IDM_HELP_ABOUT),TBSTATE_ENABLED,BTNS_BUTTON );
    userBar->addButtons();
    userBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_FILE_NEW),IDM_FILE_NEW , mol::UI().CmdString(IDM_FILE_NEW),TBSTATE_ENABLED,BTNS_BUTTON );
    userBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_FILE_OPEN),IDM_FILE_OPEN , mol::UI().CmdString(IDM_FILE_OPEN),TBSTATE_ENABLED,BTNS_BUTTON );
    userBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_FILE_SAVE_AS),IDM_FILE_SAVE_AS , mol::UI().CmdString(IDM_FILE_SAVE_AS),TBSTATE_ENABLED,BTNS_BUTTON );
    userBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_VIEW_DIRVIEW),IDM_VIEW_DIRVIEW , mol::UI().CmdString(IDM_VIEW_DIRVIEW),TBSTATE_ENABLED,BTNS_BUTTON );
    userBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_FILE_OPEN_FOLDER),IDM_FILE_OPEN_FOLDER , mol::UI().CmdString(IDM_FILE_OPEN_FOLDER),TBSTATE_ENABLED,BTNS_BUTTON );
    userBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_FILE_SAVE),IDM_FILE_SAVE , mol::UI().CmdString(IDM_FILE_SAVE),TBSTATE_ENABLED,BTNS_BUTTON );
    userBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_FILE_PRINT),IDM_FILE_PRINT , mol::UI().CmdString(IDM_FILE_PRINT),TBSTATE_ENABLED,BTNS_BUTTON );
    userBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_FILE_EXIT),IDM_FILE_EXIT , mol::UI().CmdString(IDM_FILE_EXIT),TBSTATE_ENABLED,BTNS_BUTTON );
    userBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_EDIT_UNDO),IDM_EDIT_UNDO , mol::UI().CmdString(IDM_EDIT_UNDO),TBSTATE_ENABLED,BTNS_BUTTON );
    userBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_EDIT_REDO),IDM_EDIT_REDO , mol::UI().CmdString(IDM_EDIT_REDO),TBSTATE_ENABLED,BTNS_BUTTON );
    userBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_EDIT_CUT),IDM_EDIT_CUT , mol::UI().CmdString(IDM_EDIT_CUT),TBSTATE_ENABLED,BTNS_BUTTON );
    userBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_EDIT_COPY),IDM_EDIT_COPY , mol::UI().CmdString(IDM_EDIT_COPY),TBSTATE_ENABLED,BTNS_BUTTON );
    userBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_EDIT_PASTE),IDM_EDIT_PASTE , mol::UI().CmdString(IDM_EDIT_PASTE),TBSTATE_ENABLED,BTNS_BUTTON );
    userBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_EDIT_FIND),IDM_EDIT_FIND , mol::UI().CmdString(IDM_EDIT_FIND),TBSTATE_ENABLED,BTNS_BUTTON );
    userBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_EDIT_REPLACE),IDM_EDIT_REPLACE , mol::UI().CmdString(IDM_EDIT_REPLACE),TBSTATE_ENABLED,BTNS_BUTTON );
    userBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_EDIT_COLOR),IDM_EDIT_COLOR , mol::UI().CmdString(IDM_EDIT_COLOR),TBSTATE_ENABLED,BTNS_BUTTON );
    userBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_EDIT_EXECUTESCRIPT),IDM_EDIT_EXECUTESCRIPT , mol::UI().CmdString(IDM_EDIT_EXECUTESCRIPT),TBSTATE_ENABLED,BTNS_BUTTON );
    userBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_MODE_EXECUTEFORM),IDM_MODE_EXECUTEFORM , mol::UI().CmdString(IDM_MODE_EXECUTEFORM),TBSTATE_ENABLED,BTNS_BUTTON );
    userBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_USER_SCRIPT),IDM_USER_SCRIPT , mol::UI().CmdString(IDM_USER_SCRIPT),TBSTATE_ENABLED,BTNS_DROPDOWN );
    userBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_USER_BATCH),IDM_USER_BATCH , mol::UI().CmdString(IDM_USER_BATCH),TBSTATE_ENABLED,BTNS_DROPDOWN );
    userBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_USER_FORM),IDM_USER_FORM , mol::UI().CmdString(IDM_USER_FORM),TBSTATE_ENABLED,BTNS_DROPDOWN );
    userBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_USER_SHORTCUT),IDM_USER_SHORTCUT , mol::UI().CmdString(IDM_USER_SHORTCUT),TBSTATE_ENABLED,BTNS_DROPDOWN );
    userBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_SETTINGS_MODE),IDM_SETTINGS_MODE , mol::UI().CmdString(IDM_SETTINGS_MODE),TBSTATE_ENABLED,BTNS_BUTTON );
    userBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_MODE_LANGUAGE),IDM_MODE_LANGUAGE , mol::UI().CmdString(IDM_MODE_LANGUAGE),TBSTATE_ENABLED,BTNS_BUTTON );
    userBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_MODE_SETTINGS),IDM_MODE_SETTINGS , mol::UI().CmdString(IDM_MODE_SETTINGS),TBSTATE_ENABLED,BTNS_BUTTON );
    userBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_MODE_PREFERENCES),IDM_MODE_PREFERENCES , mol::UI().CmdString(IDM_MODE_PREFERENCES),TBSTATE_ENABLED,BTNS_BUTTON );
    userBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_MODE_EDITSETTINGS),IDM_MODE_EDITSETTINGS , mol::UI().CmdString(IDM_MODE_EDITSETTINGS),TBSTATE_ENABLED,BTNS_BUTTON );
    userBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_VIEW_MAXIMIZE),IDM_VIEW_MAXIMIZE , mol::UI().CmdString(IDM_VIEW_MAXIMIZE),TBSTATE_ENABLED,BTNS_BUTTON );
    userBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_VIEW_MINIMIZE),IDM_VIEW_MINIMIZE , mol::UI().CmdString(IDM_VIEW_MINIMIZE),TBSTATE_ENABLED,BTNS_BUTTON );
    userBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_VIEW_CASCADE),IDM_VIEW_CASCADE , mol::UI().CmdString(IDM_VIEW_CASCADE),TBSTATE_ENABLED,BTNS_BUTTON );
    userBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_VIEW_TILE),IDM_VIEW_TILE , mol::UI().CmdString(IDM_VIEW_TILE),TBSTATE_ENABLED,BTNS_BUTTON );
    userBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_VIEW_NEXT),IDM_VIEW_NEXT , mol::UI().CmdString(IDM_VIEW_NEXT),TBSTATE_ENABLED,BTNS_BUTTON );
    userBar->addButton( mol::UI().BitmapCmdIndex(IDB_TOOLBAR,IDM_VIEW_CLOSE),IDM_VIEW_CLOSE , mol::UI().CmdString(IDM_VIEW_CLOSE),TBSTATE_ENABLED,BTNS_BUTTON );
    reBar->addBar( *userBar, IDC_TOOLBARS_USERBAR, 100  );
    reBar->showBar(IDC_TOOLBARS_USERBAR,false);

    //bar

    //rebar bar
    MoeComboBox* syntax = makeWindow < MoeComboBox>((HMENU)IDW_SYNTAX_BOX, Rect(0,0,44,240), (HWND)*moe);
    syntax->show(SW_SHOW);
    reBar->addBar( *syntax, IDW_SYNTAX_BOX, 44  );
    syntax->addString(_T("txt"));
    syntax->addString(_T("html"));
    syntax->addString(_T("css"));
    syntax->addString(_T("vb"));
    syntax->addString(_T("js"));
    syntax->addString(_T("sql"));
    syntax->addString(_T("shell"));
    syntax->addString(_T("perl"));
    syntax->addString(_T("c++"));
    syntax->addString(_T("java"));
    syntax->addString(_T("c#"));
    syntax->setCurSel(0);
    reBar->show(SW_SHOW);

    layout->addRebar( reBar );

  layout->add(moe->mdiClient(),BorderLayout::FILL);


    // drag n drop    
    ::RegisterDragDrop(*moe,moeDropTarget());
    

  // keybord shortcuts (accellerators)
  mol::win::accelerators().load(IDA_MOE,*moe);

    // hook up ole container menus for OLE embedding
    moe->setWindowMenu(mol::UI().SubMenu(IDM_MOE,IDM_VIEW_WINDOWS));
    moe->addFileMenu(mol::UI().SubMenu(IDM_MOE, IDM_FILE), mol::UI().CmdString(IDM_FILE) );
    moe->addWindowMenu(mol::UI().SubMenu(IDM_MOE, IDM_VIEW), mol::UI().CmdString(IDM_VIEW) );
    moe->addOlExecHandler( OLECMDID_NEW, IDM_FILE_NEW );
    moe->addOlExecHandler( OLECMDID_OPEN, IDM_FILE_OPEN );
    moe->addOlExecHandler( OLECMDID_SAVE, IDM_FILE_SAVE );
    moe->addOlExecHandler( OLECMDID_SAVEAS, IDM_FILE_SAVE_AS );
    moe->addOlExecHandler( OLECMDID_PRINT, IDM_FILE_PRINT );


  init_ribbon_ui(wnd_);

  // redraw
  // moe->show(SW_SHOW);
  // moe->OnLayout(0,0,0);
  // moe->redraw();
  

delete this;
}

    MoeWnd* moe() { return mol::UI().Wnd<MoeWnd>(IDW_MOE); }

//childWindow
    MoeTreeWnd* treeWnd() { return mol::UI().Wnd<MoeTreeWnd>(IDW_TREE_VIEW); }

//childWindow
    MoeTabControl* tab() { return mol::UI().Wnd<MoeTabControl>(IDW_TAB_CTRL); }

//statusbar
    MoeStatusBar* statusBar() { return mol::UI().Wnd<MoeStatusBar>(IDW_STATUS); }

//childWindow
    mol::ProgressbarCtrl* progress() { return mol::UI().Wnd<mol::ProgressbarCtrl>(IDW_PROGRESS_BAR); }

//reBar
    MoeBar* reBar() { return mol::UI().Wnd<MoeBar>(IDW_REBAR); }


//toolBar
    MoeToolBar* fileBar() { return mol::UI().Wnd<MoeToolBar>(IDC_TOOLBARS_FILEBAR); }


//toolBar
    MoeToolBar* editBar() { return mol::UI().Wnd<MoeToolBar>(IDC_TOOLBARS_EDITBAR); }


//toolBar
    MoeToolBar* toolsBar() { return mol::UI().Wnd<MoeToolBar>(IDC_TOOLBARS_TOOLBAR); }


//toolBar
    MoeToolBar* settingsBar() { return mol::UI().Wnd<MoeToolBar>(IDC_TOOLBARS_SETTINGBAR); }


//toolBar
    MoeToolBar* viewBar() { return mol::UI().Wnd<MoeToolBar>(IDC_TOOLBARS_VIEWBAR); }


//toolBar
    MoeToolBar* userBar() { return mol::UI().Wnd<MoeToolBar>(IDC_TOOLBARS_USERBAR); }


//bar

//rebar bar
    MoeComboBox* syntax() { return mol::UI().Wnd<MoeComboBox>(IDW_SYNTAX_BOX); }
Documents* docs()
{
  return &mol::singleton<Documents>();
}
TreeWndSink* treeWndSink()
{
  return &mol::singleton<TreeWndSink>();
}
MoeDrop* moeDropTarget()
{
  return &mol::singleton<MoeDrop>();
}
mol::SearchDlg* searchDlg()
{
  return &mol::singleton<mol::SearchDlg>();
}
UrlDlg* urlDlg()
{
  return &mol::singleton<UrlDlg>();
}
DebugDlg* debugDlg()
{
  return &mol::singleton<DebugDlg>();
}
ISetting* config()
{
  return mol::comSingleton<ISetting,&CLSID_Setting>();
}
Script* scriptlet()
  {
  return mol::nonCreatableCOMSingleton<Script,IActiveScriptSite>();
}

const mol::string& appPath()
  {
  static const mol::string appPath_ = mol::app<AppBase>().CreateAppPath(_T("moe"));
  return appPath_;
}

const mol::string& prefPath()
  {
  static const mol::string prefPath_ = appPath() + _T("\\xpref.xmo");
  return prefPath_;
}

const mol::string& binPath()
  {
  static const mol::string binPath_ = mol::app<AppBase>().getModulePath();
  return binPath_;
}
