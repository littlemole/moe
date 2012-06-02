#ifndef MOL_DEF_GUARD_DEFINE_SSHSHELL_PIDLMGR_DEF_GUARD
#define MOL_DEF_GUARD_DEFINE_SSHSHELL_PIDLMGR_DEF_GUARD


#include "ole/aut.h"
#include "ole/factory.h"
#include "ole/bstr.h"
#include "ole/dll.h"
#include "win/shell.h"
#include <memory>

#include "resource.h"

// {81F446C7-BCDA-44AD-A2B2-1E23C7036EA1}
//DEFINE_GUID(CLSID_SshViewNameSpace, 0x81F446C7, 0xBCDA, 0x44AD, 0xA2, 0xB2, 0x1E, 0x23, 0xC7, 0x03, 0x6E, 0xA1);
#define CLSID_CmdGrp CLSID_sshShell

#include "sshShell_h.h"

typedef enum tagSFTPPIDLTYPE
{
   PT_SFTP_ROOT = 0x00000000,
   PT_SFTP_SERVER = 0x00000001,
   PT_SFTP_DIR = 0x00000002,
   PT_SFTP_FILE = 0x00000003
}SFTPPIDLTYPE;

typedef struct tagSFTPPIDLDATA
{
   SFTPPIDLTYPE type;
   wchar_t path[1];
}SFTPPIDLDATA, FAR *LPSFTPPIDLDATA;


class PidlMgr
{
public:
   PidlMgr();
   ~PidlMgr();

   LPITEMIDLIST createSftpServer(const std::wstring& server);
   LPITEMIDLIST createSftpPath(const std::wstring& path);
   LPITEMIDLIST createSftpFile(const std::wstring& file);

   void destroy(LPITEMIDLIST pidl);

   LPITEMIDLIST getParentItem(LPITEMIDLIST pidl);
   LPITEMIDLIST getLastItem(LPCITEMIDLIST pidl);
   LPITEMIDLIST getNextItem(LPCITEMIDLIST pidl);

   LPITEMIDLIST copy(LPCITEMIDLIST pidl);
   UINT getSize(LPCITEMIDLIST pidl);

   std::wstring getSftpRoot(LPCITEMIDLIST pidl);
   std::wstring getSftpServerName(LPCITEMIDLIST pidl);
   int getSftpServerPort(LPCITEMIDLIST pidl);
   std::wstring getSftpPath(LPCITEMIDLIST pidl);
   std::wstring getSftpFilename(LPCITEMIDLIST pidl);

   void setSftpRoot(LPCITEMIDLIST pidl);
   LPCITEMIDLIST getRootPidl();

   bool isRoot(LPCITEMIDLIST pidl);
   bool isServer(LPCITEMIDLIST pidl);
   bool isPath(LPCITEMIDLIST pidl);
   bool isFile(LPCITEMIDLIST pidl);
   bool isDir(LPCITEMIDLIST pidl);
   
   std::wstring getPidlPath(LPCITEMIDLIST pidl);
   LPITEMIDLIST concat(LPCITEMIDLIST pidl1, LPCITEMIDLIST pidl2);
   bool  isEqual(LPCITEMIDLIST pidl1, LPCITEMIDLIST pidl2)  ;
private:

   LPITEMIDLIST create(SFTPPIDLTYPE type, const std::wstring& txt);
   std::wstring getData(LPCITEMIDLIST pidl);
   LPSFTPPIDLDATA getDataPointer(LPCITEMIDLIST pidl);

   LPITEMIDLIST rootPidl_;
};

typedef PidlMgr FAR *LPPIDLMGR;

PidlMgr& pidlManager();

#endif
