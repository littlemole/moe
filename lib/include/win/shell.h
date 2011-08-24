
#ifndef _MOL_SHELL_DEF_H_
#define _MOL_SHELL_DEF_H_

#include "win/wnd.h"
#include "ole/com.h"
#include "ole/punk.h"
#include "util/refptr.h"
#include "thread/ThreadQueue.h"
#include <Shlobj.h>
#include <Shlwapi.h>
#include <Shellapi.h>
#include <vector>

namespace mol {
namespace io {

////////////////////////////////////////////////////////////////////////////////////
//Shell stuff
////////////////////////////////////////////////////////////////////////////////////

class ShellFolder;


//! get the desktop singleton
ShellFolder& desktop();

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
// static helper for shell info
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

class ShellInfo
{
public:
	static HIMAGELIST SysImgList();
	static int Icon         ( const mol::string& path );
	static int OpenIcon     ( const mol::string& path );
    static HICON HIcon      ( const mol::string& path );
	static HICON HOpenIcon  ( const mol::string& path );
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
// Shell Item impl
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

class ShellItem
{
friend class ShellFolder;
public:
	ShellItem(LPITEMIDLIST pidl, DWORD attributes);
	~ShellItem();

	bool isFile();
	bool isDir();
	bool isPartOfFileSystem();
	bool isBrowsable();

    operator LPITEMIDLIST()  { return pidl_;	}
	operator LPCITEMIDLIST() { return pidl_;	}

private:
	LPITEMIDLIST	pidl_;
	ULONG           attributes_;
};

////////////////////////////////////////////////////////////////////////////////////
// add refcounting to this one:
////////////////////////////////////////////////////////////////////////////////////

typedef mol::RefPtr<mol::io::ShellItem> Shit; 

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
// ShellFolder impl
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

class ShellFolder
{
	friend class mol::io::ShellItem;
public:
	ShellFolder();
	ShellFolder( LPITEMIDLIST pidl, ShellFolder& parent = mol::io::desktop() );
	ShellFolder(IShellFolder* folder);
	~ShellFolder();

	Shit shellItem();

	mol::string getDisplayNameOf( LPITEMIDLIST pidl, DWORD flags = SHGDN_FORPARSING);
	Shit getSpecialFolder( int csidl);

	// prepare enumeration
	HRESULT enumObjects( HWND owner, SHCONTF flags = SHCONTF_FOLDERS | SHCONTF_NONFOLDERS |  SHCONTF_INCLUDEHIDDEN );

	// while next
	Shit next(DWORD attributes = SFGAO_FOLDER|SFGAO_STREAM|SFGAO_FILESYSTEM|SFGAO_BROWSABLE|SFGAO_FILESYSANCESTOR);

	// restart enum
	void reset();

	// get item
	Shit parseDisplayName(const mol::string& path, DWORD attributes = SFGAO_FOLDER|SFGAO_STREAM|SFGAO_FILESYSTEM|SFGAO_BROWSABLE|SFGAO_FILESYSANCESTOR);

	// get Attributes of item
	ULONG getAttributesOf( LPITEMIDLIST pidl, ULONG attributes = SFGAO_FOLDER|SFGAO_STREAM|SFGAO_FILESYSTEM|SFGAO_BROWSABLE|SFGAO_FILESYSANCESTOR );
	HICON getIcon( mol::io::Shit& it, DWORD flag = SHGFI_SMALLICON);
	int   getIconIndex( mol::io::Shit& it,DWORD flag = SHGFI_SMALLICON);
	int   getIconIndexReal( mol::io::Shit& it,DWORD flag = SHGFI_SMALLICON);
	
	// is valid
	operator bool() { return folder(); }
	
	mol::punk<IShellFolder>   folder;


	static HIMAGELIST SysImgList();

	int getFolderIcon();
    int getOpenFolderIcon();

protected:

	void release(LPITEMIDLIST pidl);

	const mol::TCHAR* getStaticFolderPath();

	// get folder from item
	IShellFolder* subFolder(LPITEMIDLIST pidl);

	mol::punk<IEnumIDList>				enumIdl_;
	mol::punk<IShellFolder>				desk_;
	mol::punk<IMalloc>					mallocer_;
	STRRET								strret_;

    static std::map<mol::string,int>	iconMap_;
};

////////////////////////////////////////////////////////////////////////////////////

Shit parseDisplayName(const mol::string& path, DWORD attributes = SFGAO_FOLDER|SFGAO_STREAM|SFGAO_FILESYSTEM|SFGAO_BROWSABLE|SFGAO_FILESYSANCESTOR);

////////////////////////////////////////////////////////////////////////////////////
// File Operations unsing windows shell (windows explorer.exe)
////////////////////////////////////////////////////////////////////////////////////

class ShellFileOp
{
public:
    ShellFileOp();
    ~ShellFileOp();

    int  copy(
			HWND hwnd, 
			const mol::string& from, 
			const mol::string& to, 
			FILEOP_FLAGS flags = FOF_NOCONFIRMATION|FOF_NOCONFIRMMKDIR|FOF_NOERRORUI);

	int  copy(
			HWND hwnd, 
			const std::vector<mol::string>& from, 
			const mol::string& to, 
			FILEOP_FLAGS flags = FOF_NOCONFIRMATION|FOF_NOCONFIRMMKDIR|FOF_NOERRORUI);

    int  remove(
			HWND hwnd, 
			const mol::string& from, 
			FILEOP_FLAGS flags =FOF_NOCONFIRMATION|FOF_NOCONFIRMMKDIR|FOF_NOERRORUI);

	int  remove(
			HWND hwnd, 
			const std::vector<mol::string>& from, 
			FILEOP_FLAGS flags =FOF_NOCONFIRMATION|FOF_NOCONFIRMMKDIR|FOF_NOERRORUI);

    int  move(
			HWND hwnd, 
			const mol::string& from, 
			const mol::string& to, 
			FILEOP_FLAGS flags =FOF_NOCONFIRMATION|FOF_NOCONFIRMMKDIR|FOF_NOERRORUI);

	int  move(
			HWND hwnd, 
			const std::vector<mol::string>& from, 
			const mol::string& to, 
			FILEOP_FLAGS flags =FOF_NOCONFIRMATION|FOF_NOCONFIRMMKDIR|FOF_NOERRORUI);

    int  rename(
			HWND hwnd, 
			const mol::string& from, 
			const mol::string& to, 
			FILEOP_FLAGS flags =FOF_NOCONFIRMATION|FOF_NOCONFIRMMKDIR|FOF_NOERRORUI);

	bool createDir( const mol::string& dirname );

    BOOL  anyOpAborted();

private:
    SHFILEOPSTRUCT sfos_;

    int  op     (UINT  op, HWND hwnd, const mol::string& from, const mol::string& to, FILEOP_FLAGS flags = FOF_NOCONFIRMATION|FOF_NOCONFIRMMKDIR|FOF_NOERRORUI);
	int  multiOp(UINT  op, HWND hwnd, const std::vector<mol::string>& from, const mol::string& to, FILEOP_FLAGS flags = FOF_NOCONFIRMATION|FOF_NOCONFIRMMKDIR|FOF_NOERRORUI);
};

////////////////////////////////////////////////////////////////////////////////////
// Try to launch new process thru windows shell (explorer.exe)
////////////////////////////////////////////////////////////////////////////////////

BOOL execute_shell( 
				   const mol::string& path, 
				   const mol::string& verb = _T("open"), 
				   int nShow = SW_SHOWNORMAL, ULONG fMask = 0 //SEE_MASK_INVOKEIDLIST);
				   );	


BOOL execute_shell_args( 
					const mol::string& path, 
					const mol::string& args, 
					const mol::string& verb = _T("open"), 
					int nShow = SW_SHOWNORMAL, ULONG fMask = SEE_MASK_FLAG_DDEWAIT | SEE_MASK_FLAG_NO_UI );//SEE_MASK_INVOKEIDLIST);


BOOL execute_shell_admin( const mol::string& path, const mol::string& args );

////////////////////////////////////////////////////////////////////////////////////
// execute a commandline w/o  cmd.exe
////////////////////////////////////////////////////////////////////////////////////

BOOL exec_cmdline( const mol::string cl );

} // end namespace mol::win::io;


class UACPipe
{
public:

	UACPipe();
	~UACPipe();
	
	HANDLE create(const mol::string& pipename );
	HANDLE open( const mol::string& pipename );

	bool connect(int milisecs = 3000);
	void disconnect();
	void close();
		
	std::string read();
	bool write( const std::string& data );

	operator bool () 
	{
		return pipe_ != INVALID_HANDLE_VALUE;
	}

private:
	HANDLE pipe_;
	static const int BUFSIZE;
};

mol::string resolveShortcut( const mol::string& link);

} // end namespace mol;

#endif