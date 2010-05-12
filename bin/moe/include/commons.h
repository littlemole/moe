#ifndef MOE_COMMONS_DEF_GUARD_DEFINE_
#define MOE_COMMONS_DEF_GUARD_DEFINE_

#include <set>
#include <fstream>
#include <sstream>

// mol libs
#include "util/istr.h"

#include "win/app.h"
#include "win/mdi.h"
#include "win/res.h"
#include "win/dlg.h"
#include "win/codlg.h"
#include "win/coctrl.h"
#include "win/core.h"
#include "win/layout.h"
#include "win/shell.h"
#include "win/folder.h"
#include "win/path.h"
#include "win/file.h"

#include "ole/aut.h"
#include "ole/obj.h"
#include "ole/host.h"
#include "ole/punk.h"
#include "ole/bstr.h"
#include "ole/persist.h"
#include "ole/variant.h"
#include "ole/factory.h"
#include "ole/dragdrop.h"
#include "ole/scripting.h"
#include "ole/ie.h"
#include "ole/bookmark.h"
#include "ole/img.h"

#include "xml/html.h"

#include <mshtml.h>

// ax impl
#include "ax/setting/setting_h.h"
#include "ax/shellctrl/ShellListEvents.h"
#include "ax/shellfolder/ShellFolderEvents.h"
#include "ax/shellctrl/ShellTreeEvents.h"
#include "ax/shellctrl/HexCtrlEvents.h"
#include "ax/ScintillAx/ScintillaxEvents.h"

// moe idl
#include "moe_h.h"

// .NET JIT support

#include "../net/JIT/JIT_tlh.h"

#include "resource.h"

#endif
