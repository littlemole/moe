
#ifndef MOL_MOE_XML_GENERATED_RESOURCE_UIH_DEFINES_DEF_GUARD_DEFINE
#define MOL_MOE_XML_GENERATED_RESOURCE_UIH_DEFINES_DEF_GUARD_DEFINE
#include "win/res.h"
#include "win/wnd.h"



class MoeWndGUIBuilder : public mol::UIBuilder
{
  public:
    MoeWndGUIBuilder( mol::win::WndProc* wnd )
  : mol::UIBuilder(wnd)
  {}

  virtual void loadUI();
  virtual void makeUI();
  };

  class MoeWnd;

template<>
class mol::GUIBuilder<MoeWnd>
  : public MoeWndGUIBuilder
{
public:
  GUIBuilder( mol::win::WndProc* wnd )
  : MoeWndGUIBuilder(wnd)
  {}
};

extern void init_ribbon_ui(mol::win::WndProc* wnd);

MoeWnd* moe();

//childWindow
class MoeHtmlRibbon;
MoeHtmlRibbon* ribbon();

//childWindow
class MoeTreeWnd;
MoeTreeWnd* treeWnd();

//childWindow
class MoeTabControl;
MoeTabControl* tab();


//statusbar
class MoeStatusBar;
MoeStatusBar* statusBar();

//childWindow
class mol::ProgressbarCtrl;
mol::ProgressbarCtrl* progress();

class Documents;    
Documents* docs();

class Encodings;    
Encodings* codePages();

class DebugDlg;    
DebugDlg* debugDlg();
  


#endif

