

#include "stdafx.h"
#include "win/res.h"
#include "xmlui.h"

#include "app.h"

#include "dir3.h"

#include "scpdir.h"

#include "editor.h"

#include "taileditor.h"

#include "hex.h"

#include "html2.h"

#include "img.h"

#include "ole.h"

#include "form2.h"

#include "rtf.h"

#include "Docs.h"

#include "MoeBar.h"

#include "mtree.h"

#include "win/msghandler.h"


using namespace mol;



void MoeWndGUIBuilder::loadUI()
{
    MoeWnd* moe = (MoeWnd*)wnd_;

    makeMainWindow( moe, _T("moe"), (HMENU)0, stdRect, IDW_MOE );

}



  // window


void MoeWndGUIBuilder::makeUI()
{

    MoeWnd* moe = (MoeWnd*)wnd_;
    BorderLayout* layout = moe->setLayout(new BorderLayout);

    //childWindow
    MoeHtmlRibbon* ribbon = makeWindow<MoeHtmlRibbon>((HMENU)ID_MOE_HTML_RIBBON, mol::Rect(0,0,160,133), (HWND)*moe);
    ribbon->show(SW_SHOW);

    layout->add( *ribbon, BorderLayout::NORTH );

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

  layout->add(moe->mdiClient(),BorderLayout::FILL);


    // drag n drop    
    ::RegisterDragDrop(*moe,moe->moeDrop.get());
    

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
    MoeHtmlRibbon* ribbon() { return mol::UI().Wnd<MoeHtmlRibbon>(ID_MOE_HTML_RIBBON); }

//childWindow
    MoeTreeWnd* treeWnd() { return mol::UI().Wnd<MoeTreeWnd>(IDW_TREE_VIEW); }

//childWindow
    MoeTabControl* tab() { return mol::UI().Wnd<MoeTabControl>(IDW_TAB_CTRL); }

//statusbar
    MoeStatusBar* statusBar() { return mol::UI().Wnd<MoeStatusBar>(IDW_STATUS); }

//childWindow
    mol::ProgressbarCtrl* progress() { return mol::UI().Wnd<mol::ProgressbarCtrl>(IDW_PROGRESS_BAR); }
Documents* docs()
{
  return &mol::singleton<Documents>();
}
Encodings* codePages()
{
  return &mol::singleton<Encodings>();
}
DebugDlg* debugDlg()
{
  return &mol::singleton<DebugDlg>();
}
