#ifndef _MOL_DEF_GUARD_VISTA_AND_WINSEVEN_APIS_DEF_GUARD
#define _MOL_DEF_GUARD_VISTA_AND_WINSEVEN_APIS_DEF_GUARD

#include "win/wnd.h"
#include <shobjidl.h>

// MOL_RM_SESSION_KEY_LEN - size in bytes of binary session key
#define MOL_RM_SESSION_KEY_LEN  sizeof(GUID)
// MOL_CCH_RM_SESSION_KEY - character count of text-encoded session key
#define MOL_CCH_RM_SESSION_KEY  MOL_RM_SESSION_KEY_LEN*2
// MOL_CCH_RM_MAX_APP_NAME - maximum character count of application friendly name
#define MOL_CCH_RM_MAX_APP_NAME 255
// MOL_CCH_RM_MAX_SVC_NAME - maximum character count of service short name
#define MOL_CCH_RM_MAX_SVC_NAME 63 

namespace mol {
namespace v7  {


int msgbox( HWND parent, const std::wstring& txt, const std::wstring& title, const std::wstring& detail, int idIcon );

///////////////////////////////////////////////////////////////////////////////////////////////


void editFileExtensions(const std::wstring& app);

///////////////////////////////////////////////////////////////////////////////////////////////

void unlockInternetExplorer();

///////////////////////////////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////////////////////////////


} // end namespace v7
} // end namespace mol

#endif