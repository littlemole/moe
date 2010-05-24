

#include "stdafx.h"
#include "win/res.h"
#include "xmlui.h"

#include "../scieditor.h"

#include "../ScintillACtrl.h"

#include "../ScintillAxProp.h"

#include "ole/persist.h"

#include "win/layout.h"


using namespace mol;



void ScintillAxGUIBuilder::loadUI()
{

}



  // window


void ScintillAxGUIBuilder::makeUI()
{

    ScintillAx* ScintillaActiveXControl = (ScintillAx*)wnd_;
    FillLayout* layout = ScintillaActiveXControl->setLayout(new FillLayout);

    //childWindow
    EditWnd* editor = makeWindow<EditWnd>((HMENU)IDC_EDITOR_VIEW, mol::stdRect, (HWND)*ScintillaActiveXControl);
    editor->show(SW_SHOW);

    layout->add( *editor);
    editor->setUsePopUp(true);
    editor->setCodePage(CP_UTF8);
    editor->setScrollWidth(120);
    editor->setMarginWidth(1,0);
    editor->setTabWidth(4);


  init_ribbon_ui(wnd_);

  // redraw
  // ScintillaActiveXControl->show(SW_SHOW);
  // ScintillaActiveXControl->OnLayout(0,0,0);
  // ScintillaActiveXControl->redraw();
  

delete this;
}

