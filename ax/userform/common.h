#ifndef USERFORM_COMMON_DEF_GUARD_
#define USERFORM_COMMON_DEF_GUARD_

#include <set>
#include <fstream>
#include <sstream>

// mol libs
#include "util/istr.h"
#include "win/app.h"
#include "win/wnd.h"
#include "win/res.h"
#include "win/dlg.h"
#include "win/enc.h"
#include "win/coctrl.h"
#include "win/core.h"
#include "win/path.h"
#include "win/file.h"
#include "win/msgloop.h"
#include "win/msghandler.h"
#include "win/msg_macro.h"
#include "win/clipboard.h"
#include "ole/aut.h"
#include "ole/obj.h"
#include "win/async.h"
#include "ole/punk.h"
#include "ole/bstr.h"
#include "ole/persist.h"
#include "ole/variant.h"
#include "ole/factory.h"
#include "ole/img.h"
#include "ole/cp.h"
#include "ole/enum.h"
#include "ole/SimpleHost.h"

#include <memory>
#include <functional>

#include "userform_h.h"

#include "resource.h"


///////////////////////////////////////////////////////////////////////////////

std::wstring findFile(const std::wstring& f);

#endif