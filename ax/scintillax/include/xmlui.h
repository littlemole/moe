
#ifndef MOL_MOE_XML_GENERATED_RESOURCE_UIH_DEFINES_DEF_GUARD_DEFINE
#define MOL_MOE_XML_GENERATED_RESOURCE_UIH_DEFINES_DEF_GUARD_DEFINE
#include "win/res.h"
#include "win/wnd.h"



class ScintillAxGUIBuilder : public mol::UIBuilder
{
  public:
    ScintillAxGUIBuilder( mol::win::WndProc* wnd )
  : mol::UIBuilder(wnd)
  {}

  virtual void loadUI();
  virtual void makeUI();
  };

  class ScintillAx;

template<>
class mol::GUIBuilder<ScintillAx>
  : public ScintillAxGUIBuilder
{
public:
  GUIBuilder( mol::win::WndProc* wnd )
  : ScintillAxGUIBuilder(wnd)
  {}
};

extern void init_ribbon_ui(mol::win::WndProc* wnd);

  


#endif

