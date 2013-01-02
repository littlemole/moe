
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


//reBar
class MoeBar;
MoeBar* reBar();



//toolBar
class MoeToolBar;
MoeToolBar* fileBar();



//toolBar
class MoeToolBar;
MoeToolBar* editBar();



//toolBar
class MoeToolBar;
MoeToolBar* toolsBar();



//toolBar
class MoeToolBar;
MoeToolBar* settingsBar();



//toolBar
class MoeToolBar;
MoeToolBar* viewBar();



//toolBar
class MoeToolBar;
MoeToolBar* userBar();


//bar


//rebar bar
class MoeComboBox;
MoeComboBox* syntax();

class Documents;    
Documents* docs();

class TreeWndSink;    
TreeWndSink* treeWndSink();

class MoeDrop;    
MoeDrop* moeDropTarget();

namespace mol {

class SearchDlg;    

}
mol::SearchDlg* searchDlg();

class UrlDlg;    
UrlDlg* urlDlg();

class DebugDlg;    
DebugDlg* debugDlg();

struct ISetting;
ISetting* config();

struct IScintillAxStyleSets;
IScintillAxStyleSets* styles();

class Script;    
Script* scriptlet();

const mol::string& appPath();

const mol::string& prefPath();

const mol::string& binPath();
  


#endif

