#ifndef MOL_DEF_SSH_VIEW_DEF_GUARDING_
#define MOL_DEF_SSH_VIEW_DEF_GUARDING_


#include "ole/aut.h"
#include <shlguid.h>

#include "ole/factory.h"
#include "ole/bstr.h"
#include "ole/dll.h"
#include "ole/typelib.h"
#include "win/shell.h"
#include <memory>
#include "sshShell_h.h"
#include "ShellFolder.h"
#include "resource.h"

#include "ssh/ssh.h"
#include "ssh/sftp.h"
#include "ssh/credmgr.h"
#include "ssh/scpDataTransferObj.h"


///////////////////////////////////////////////////////////////////////////////


template <> 
class mol::uuid_info<IContextMenu>
{
 public:
   static REFIID uuidof;
   typedef IContextMenu uuid_type;
};

///////////////////////////////////////////////////////////////////////////////

class moeShellDll : 
	public mol::Dll,
	public mol::exports<moeShellDll,ShellFolder>
{
public:

	virtual HRESULT __stdcall RegisterServer();
	virtual HRESULT __stdcall UnregisterServer();
	virtual BOOL __stdcall Main( HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved);

};



///////////////////////////////////////////////////////////////////////////////


#endif