#include "win/shell.h"
#include "win/path.h"
#include "util/uni.h"

#include <IntShCut.h>

namespace mol {
namespace io {

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

HIMAGELIST ShellInfo::SysImgList()
{
    HIMAGELIST hIml = 0;
    SHFILEINFO shInfo;
    hIml = (HIMAGELIST)SHGetFileInfo(_T("C:\\"),0,&shInfo, sizeof(shInfo),SHGFI_SYSICONINDEX|SHGFI_SMALLICON );
    if (!hIml)
            throw X(_T("retrieve sysimagelist failed!"));
	return hIml;
}

int ShellInfo::Icon( const std::wstring& path )
{
	SHFILEINFO  shInfo;
    SHGetFileInfo( path.c_str(),0,&shInfo,sizeof(shInfo),SHGFI_ICON|SHGFI_SMALLICON);
    ::DestroyIcon(shInfo.hIcon);
	return shInfo.iIcon;
}

int ShellInfo::OpenIcon  ( const std::wstring& path )
{
	SHFILEINFO  shInfo;
    SHGetFileInfo( path.c_str(),0,&shInfo,sizeof(shInfo),SHGFI_ICON|SHGFI_OPENICON| SHGFI_SMALLICON);
    ::DestroyIcon(shInfo.hIcon);
	return shInfo.iIcon;
}	

HICON ShellInfo::HIcon  ( const std::wstring& path )
{
	SHFILEINFO  shInfo;
    SHGetFileInfo( path.c_str(),0,&shInfo,sizeof(shInfo),SHGFI_ICON|SHGFI_SMALLICON);
	return shInfo.hIcon;
}

HICON ShellInfo::HOpenIcon  ( const std::wstring& path )
{
	SHFILEINFO  shInfo;
    SHGetFileInfo( path.c_str(),0,&shInfo,sizeof(shInfo),SHGFI_ICON|SHGFI_OPENICON| SHGFI_SMALLICON);
	return shInfo.hIcon;
}	

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

ShellItem::ShellItem(LPITEMIDLIST p, DWORD a)
	:pidl_(p), attributes_(a)
{}

ShellItem::~ShellItem()
{
    desktop().release(pidl_);
    pidl_ = 0;
}

bool ShellItem::isDir()
{
	return (attributes_ & SFGAO_FOLDER) != 0;;
}

bool ShellItem::isFile()
{
	return (attributes_ & SFGAO_STREAM) != 0;
}

bool ShellItem::isPartOfFileSystem()
{
	return (attributes_ & SFGAO_FILESYSANCESTOR) != 0; //SFGAO_FILESYSTEM) != 0;
}

bool ShellItem::isBrowsable()
{
	return (attributes_ & SFGAO_BROWSABLE) != 0;
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

ShellFolder::ShellFolder() 
{
	::SHGetMalloc(&mallocer_);
	::SHGetDesktopFolder(&folder);
}

ShellFolder::ShellFolder(IShellFolder* f) 
{
	::SHGetMalloc(&mallocer_);
	folder = f;
}

ShellFolder::ShellFolder( LPITEMIDLIST pidl, ShellFolder& sf) 
{
	::SHGetMalloc(&mallocer_);
    //folder = desktop().subFolder(pidl);
	folder = sf.subFolder(pidl);
}

ShellFolder::~ShellFolder()
{
}

Shit ShellFolder::shellItem()
{
	mol::punk<IPersistFolder2> pf2(folder);
	if ( pf2 )
	{
		LPITEMIDLIST pidl;
		if ( S_OK == pf2->GetCurFolder(&pidl) )
			return Shit(new ShellItem(pidl,getAttributesOf(pidl)));
	}
	return Shit();
}


std::wstring ShellFolder::getDisplayNameOf(LPITEMIDLIST pidl, DWORD flags)
{
	if ( S_OK == folder->GetDisplayNameOf(pidl, flags, &strret_) )
	{
		wchar_t buf[MAX_PATH];
		StrRetToBuf(&strret_,pidl,buf,MAX_PATH);
		return std::wstring(buf);
	}
	return _T("");
}

IShellFolder* ShellFolder::subFolder(LPITEMIDLIST pidl) 
{
	IShellFolder* pFolder = 0;
	HRESULT hr = folder->BindToObject(pidl, NULL, IID_IShellFolder, (LPVOID *) &pFolder);
	if ( hr == S_OK )
		return pFolder;
	return 0;
}

HRESULT ShellFolder::enumObjects(HWND owner, SHCONTF flags  )
{
	return folder->EnumObjects( owner, flags, &enumIdl_);
}

Shit ShellFolder::next(DWORD attributes)
{ 
	ULONG fetched;
	LPITEMIDLIST pidl = 0;

	if ( enumIdl_ )
	if ( S_OK == enumIdl_->Next(1,&pidl,&fetched) )
		if ( fetched == 1 )
		{
			ShellItem* it = new ShellItem(pidl,getAttributesOf(pidl,attributes));
			return Shit(it);
		}
	return Shit();
}

ULONG ShellFolder::getAttributesOf( LPITEMIDLIST pidl, ULONG attributes )
{
	if ( S_OK == folder->GetAttributesOf( 1, (LPCITEMIDLIST *)&pidl, &attributes ) )
		return attributes;
	return 0;
}

void ShellFolder::reset()
{
	enumIdl_->Reset();
}

void ShellFolder::release(LPITEMIDLIST pidl )
{
	if ( pidl )
		mallocer_->Free(pidl);
}

Shit ShellFolder::parseDisplayName(const std::wstring& path, DWORD attributes)
{
	std::wstring ws = mol::towstring(path);

	LPITEMIDLIST pidl = 0;
	ULONG ulong = 0;
	// first param hwnd
	if ( S_OK == folder->ParseDisplayName( 0, NULL, (LPOLESTR)(ws.c_str()), &ulong, &pidl, &attributes) )
	{
		ShellItem* it = new ShellItem(pidl,getAttributesOf(pidl,attributes));
		return Shit(it);
	}
	return Shit();
}


Shit parseDisplayName(const std::wstring& path, DWORD attributes)
{
	ShellFolder	desk;
	std::wstring ws(mol::towstring(path));
	LPITEMIDLIST pidl = 0;
	ULONG ulong = 0;
	// first param hwnd
	if ( S_OK == desk.folder->ParseDisplayName( 0, NULL, (LPOLESTR)(ws.c_str()), &ulong, &pidl, &attributes) )
	{
		ShellItem* it = new ShellItem(pidl,desk.getAttributesOf(pidl,attributes));
		return Shit(it);
	}
	return Shit();
}

HIMAGELIST ShellFolder::SysImgList()
{
    HIMAGELIST hIml = 0;
    SHFILEINFO shInfo;
	if ( !hIml )
	{
		hIml = (HIMAGELIST)SHGetFileInfo(_T("C:\\"),0,&shInfo, sizeof(shInfo),SHGFI_SYSICONINDEX|SHGFI_SMALLICON );
		if (!hIml)
			throw X( _T("retrieve sysimagelist failed!") );
	}
	return hIml;
}

HICON ShellFolder::getIcon( mol::io::Shit& it, DWORD flag)
{
	std::wstring path = getDisplayNameOf(*it);
	DWORD attributes = 0;
	SHFILEINFO  shInfo;
	if (( it->attributes_ & SFGAO_FOLDER ) == SFGAO_FOLDER )
		attributes = FILE_ATTRIBUTE_DIRECTORY;
	else
	if (( it->attributes_ & SFGAO_STREAM ) == SFGAO_STREAM )
		attributes = FILE_ATTRIBUTE_NORMAL;
	else
		attributes = FILE_ATTRIBUTE_DEVICE;

	::SHGetFileInfo( path.c_str(),attributes,&shInfo,sizeof(shInfo), //SHGFI_ICON|SHGFI_SMALLICON);
		SHGFI_USEFILEATTRIBUTES|SHGFI_ICON|flag);//|SHGFI_TYPENAME)SHGFI_PIDL|
	return shInfo.hIcon;
}

const wchar_t* ShellFolder::getStaticFolderPath()
{
	static wchar_t buf[MAX_PATH+1];
	static UINT ui = GetWindowsDirectory(buf,MAX_PATH);
    return buf;
}

int ShellFolder::getFolderIcon()
{
    const wchar_t* path = getStaticFolderPath();
    DWORD attributes = FILE_ATTRIBUTE_DIRECTORY;
    SHFILEINFO  shInfo;
    ::ZeroMemory(&shInfo,sizeof(SHFILEINFO));
	DWORD_PTR ret = ::SHGetFileInfo( path,attributes,&shInfo,sizeof(shInfo), //SHGFI_ICON|SHGFI_SMALLICON);
		SHGFI_USEFILEATTRIBUTES|SHGFI_SYSICONINDEX|SHGFI_TYPENAME);//SHGFI_SYSICONINDEX|SHGFI_TYPENAME|flag);//|SHGFI_TYPENAME)SHGFI_PIDL
	::DestroyIcon(shInfo.hIcon);
	return shInfo.iIcon;
}
 
int ShellFolder::getOpenFolderIcon()
{
    const wchar_t* path = getStaticFolderPath();
    DWORD attributes = FILE_ATTRIBUTE_DIRECTORY;
    SHFILEINFO  shInfo;
    ::ZeroMemory(&shInfo,sizeof(SHFILEINFO));
	DWORD_PTR ret = ::SHGetFileInfo( path,attributes,&shInfo,sizeof(shInfo), //SHGFI_ICON|SHGFI_SMALLICON);
		SHGFI_USEFILEATTRIBUTES|SHGFI_SYSICONINDEX|SHGFI_TYPENAME|SHGFI_OPENICON);//SHGFI_SYSICONINDEX|SHGFI_TYPENAME|flag);//|SHGFI_TYPENAME)SHGFI_PIDL
	::DestroyIcon(shInfo.hIcon);
	return shInfo.iIcon;
}

std::map<std::wstring,int> ShellFolder::iconMap_;

int ShellFolder::getIconIndex( mol::io::Shit& it, DWORD flag )
{
    static int ifolder     = getFolderIcon();
    static int iopenfolder = getOpenFolderIcon();

    std::wstring path = getDisplayNameOf(*it);
	std::wstring p = path;
	DWORD attributes = 0;
	SHFILEINFO  shInfo;
    ::ZeroMemory(&shInfo,sizeof(SHFILEINFO));

	if ( mol::Path::isDir(path) )
    {
		if (!Path::isRoot(path))
        {
            if ( flag & SHGFI_OPENICON )
                return iopenfolder;
            return ifolder;
        }
		attributes = FILE_ATTRIBUTE_DIRECTORY;
    }
	else
	if ( mol::Path::exists(path) ) //( it->attributes_ & SFGAO_STREAM ) == SFGAO_STREAM )
    {
		p = Path::ext(p);
		attributes = FILE_ATTRIBUTE_NORMAL;
    }
	else
	if (path.size()>4 && path.substr(0,5) == L"ssh:/" )
	{
		if (path == L"ssh:/" || path == L"ssh://" )
		{
			mol::io::Shit net = mol::io::desktop().getSpecialFolder(CSIDL_NETWORK);
			DWORD_PTR ret = ::SHGetFileInfo( (LPCWSTR)(LPITEMIDLIST)(*net),0,&shInfo,sizeof(shInfo), SHGFI_SYSICONINDEX|SHGFI_TYPENAME|SHGFI_PIDL );
			::DestroyIcon(shInfo.hIcon);
			return shInfo.iIcon;
		}
		size_t pos = path.find(L"/",6);
		if ( pos == std::wstring::npos || pos == path.size()-1 )
		{
			mol::io::Shit net = mol::io::desktop().getSpecialFolder(CSIDL_DRIVES);
			DWORD_PTR ret = ::SHGetFileInfo( (LPCWSTR)(LPITEMIDLIST)(*net),0,&shInfo,sizeof(shInfo), SHGFI_SYSICONINDEX|SHGFI_TYPENAME|SHGFI_PIDL );
			::DestroyIcon(shInfo.hIcon);
			return shInfo.iIcon;
		}
		if( it->isDir() ) 
		{
			if ( flag & SHGFI_OPENICON )
                return iopenfolder;
			return ifolder;
		}

		attributes = FILE_ATTRIBUTE_NORMAL;
	}
	else
	if( path.size()>1 && path.substr(0,2) == _T("::") )
	{
		attributes = FILE_ATTRIBUTE_NORMAL;
	}
	else
    {
		//p = _T("C:\\");
		attributes = FILE_ATTRIBUTE_DEVICE;
    }

    if ( iconMap_.count(p) > 0 )
    {
        return iconMap_[p];
    }

	DWORD_PTR ret = ::SHGetFileInfo( p.c_str(),attributes,&shInfo,sizeof(shInfo), //SHGFI_ICON|SHGFI_SMALLICON);
		SHGFI_USEFILEATTRIBUTES|SHGFI_SYSICONINDEX|SHGFI_TYPENAME|flag);//SHGFI_SYSICONINDEX|SHGFI_TYPENAME|flag);//|SHGFI_TYPENAME)SHGFI_PIDL

	if (  (shInfo.hIcon == 0) ) // (ret != 0) ) //&&)
	{
		return getIconIndexReal(it,flag);
	}

	::DestroyIcon(shInfo.hIcon);
    iconMap_[p] = shInfo.iIcon;
	return shInfo.iIcon;
}

int ShellFolder::getIconIndexReal( mol::io::Shit& it, DWORD flag )
{
    std::wstring path = getDisplayNameOf(*it);
	std::wstring p = path;
	SHFILEINFO  shInfo;
    ::ZeroMemory(&shInfo,sizeof(SHFILEINFO));

	if ( path.substr(0,2) == _T("::") )
	{
		DWORD_PTR ret = ::SHGetFileInfo( (LPCWSTR)(LPITEMIDLIST)(*it),0,&shInfo,sizeof(shInfo), SHGFI_SYSICONINDEX|SHGFI_TYPENAME|SHGFI_PIDL );
	}
	else 
	{
		DWORD_PTR ret = ::SHGetFileInfo( p.c_str(),0,&shInfo,sizeof(shInfo), SHGFI_SYSICONINDEX|SHGFI_SMALLICON|SHGFI_TYPENAME);
		//SHGFI_ICON|SHGFI_SMALLICON|SHGFI_SYSICONINDEX|SHGFI_TYPENAME|flag);//SHGFI_SYSICONINDEX|SHGFI_TYPENAME|flag);//|SHGFI_TYPENAME)SHGFI_PIDL
	}
	


	::DestroyIcon(shInfo.hIcon);
    iconMap_[p] = shInfo.iIcon;
	return shInfo.iIcon;
}


Shit ShellFolder::getSpecialFolder( int csidl)
{
	LPITEMIDLIST pidl = 0;
	::SHGetSpecialFolderLocation(0,csidl,&pidl);
	return Shit(new ShellItem(pidl, getAttributesOf(pidl) ));
}
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

ShellFileOp::ShellFileOp() 
{}

ShellFileOp::~ShellFileOp() 
{}

int  ShellFileOp::copy(HWND hwnd, const std::wstring& from, const std::wstring& to, FILEOP_FLAGS flags )
{
    return op(FO_COPY, hwnd, from, to, flags);
}

int  ShellFileOp::copy(HWND hwnd, const std::vector<std::wstring>& from, const std::wstring& to, FILEOP_FLAGS flags )
{
    return multiOp(FO_COPY, hwnd, from, to, flags);
}

int  ShellFileOp::remove(HWND hwnd, const std::wstring& from, FILEOP_FLAGS flags )
{
	std::wstring to(_T(""));
    return op(FO_DELETE, hwnd, from, to, flags);
}

int  ShellFileOp::remove(HWND hwnd, const std::vector<std::wstring>& from, FILEOP_FLAGS flags )
{
	std::wstring to(_T(""));
    return multiOp(FO_DELETE, hwnd, from, to, flags);
}

int  ShellFileOp::move(HWND hwnd, const std::wstring& from, const std::wstring& to, FILEOP_FLAGS flags )
{
    return op(FO_MOVE, hwnd, from, to, flags);
}

int  ShellFileOp::move(HWND hwnd, const std::vector<std::wstring>& from, const std::wstring& to, FILEOP_FLAGS flags )
{
    return multiOp(FO_MOVE, hwnd, from, to, flags);
}

int  ShellFileOp::rename(HWND hwnd, const std::wstring& from, const std::wstring& to, FILEOP_FLAGS flags)
{
    return op(FO_RENAME, hwnd, from, to, flags);
}

bool ShellFileOp::createDir( const std::wstring& dirname )
{
	return ::CreateDirectoryW(Path::wpath(dirname).c_str(),0) == TRUE;
}

BOOL  ShellFileOp::anyOpAborted()
{
    return sfos_.fAnyOperationsAborted;
}

int  ShellFileOp::op(UINT  op, HWND hwnd, const std::wstring& from, const std::wstring& to, FILEOP_FLAGS flags)
{
    ::ZeroMemory(&sfos_,sizeof(sfos_));

	mol::wbuff f(from.size()+2);
	mol::wbuff t(to.size()+2);

	memcpy(f,from.c_str(),(from.size()+1)*sizeof(wchar_t));
    memcpy(t,to.c_str()  ,(to.size()+1)*sizeof(wchar_t));

    f[from.size()+1] = 0;
    t[to.size()+1]   = 0;

    sfos_.hwnd   = hwnd;
    sfos_.wFunc  = op;
    sfos_.pFrom  = f;
    sfos_.pTo    = t;
    sfos_.fFlags = flags;
	sfos_.lpszProgressTitle = _T("huhu?");

    int  ret = SHFileOperation(&sfos_);
    return ret;
}

int  ShellFileOp::multiOp(UINT  op, HWND hwnd, const std::vector<std::wstring>& from, const std::wstring& to, FILEOP_FLAGS flags)
{
    ::ZeroMemory(&sfos_,sizeof(sfos_));

	size_t s = 0;
	for ( size_t i = 0; i < from.size(); i++ )
	{
		s += from[i].size()+1;
	}

	mol::wbuff f(s+1);
	mol::wbuff t(to.size()+2);

	size_t c = 0;
	for ( size_t i = 0; i < from.size(); i++ )
	{
		memcpy(f+c,from[i].c_str(),(from[i].size()+1)*sizeof(wchar_t));
		c += from[i].size()+1;
	}
    memcpy(t,to.c_str()  ,(to.size()+1)*sizeof(wchar_t));

    f[s]             = 0;
    t[to.size()+1]   = 0;

    sfos_.hwnd   = hwnd;
    sfos_.wFunc  = op;
    sfos_.pFrom  = f;
    sfos_.pTo    = t;
    sfos_.fFlags = flags;
	sfos_.lpszProgressTitle = 0;

    int  ret = SHFileOperation(&sfos_);
    return ret;
}


BOOL execute_shell( const std::wstring& path, const std::wstring& verb, int nShow, ULONG fMask )
{
	SHELLEXECUTEINFO sei;
	ZeroMemory(&sei,sizeof(sei));
	sei.cbSize = sizeof(sei);
	sei.lpVerb = verb.c_str();
	sei.lpFile = path.c_str();
	sei.nShow  = nShow;
    sei.fMask  = fMask; 

	return ::ShellExecuteEx(&sei);
}

BOOL exec_cmdline( const std::wstring cl )
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );

    // Start the child process. 
    if( !CreateProcess( NULL,   // No module name (use command line). 
		(wchar_t*)(cl.c_str()),			// Command line. 
        NULL,             // Process handle not inheritable. 
        NULL,             // Thread handle not inheritable. 
        FALSE,            // Set handle inheritance to FALSE. 
		CREATE_NO_WINDOW,                // No creation flags. 
        NULL,             // Use parent's environment block. 
        NULL,             // Use parent's starting directory. 
        &si,              // Pointer to STARTUPINFO structure.
        &pi )             // Pointer to PROCESS_INFORMATION structure.
    ) 
    {
        cry();
        return FALSE;
    }

    // Close process and thread handles. 
    CloseHandle( pi.hProcess );
    CloseHandle( pi.hThread );

	return TRUE;
}


BOOL execute_shell_admin( const std::wstring& path, const std::wstring& args )
{
	return execute_shell_args( path, args, _T("runas") );
}

BOOL execute_shell_args( const std::wstring& path, const std::wstring& args, const std::wstring& verb, int nShow, ULONG fMask )//SEE_MASK_INVOKEIDLIST);
{
    SHELLEXECUTEINFO   sei;
    ZeroMemory ( &sei, sizeof(sei) );

    sei.cbSize          = sizeof(SHELLEXECUTEINFOW);
    //sei.hwnd            = hWnd;
    sei.fMask           = SEE_MASK_FLAG_DDEWAIT | SEE_MASK_FLAG_NO_UI;// | SEE_MASK_NOCLOSEPROCESS;
    sei.lpVerb          = verb.c_str();
	sei.lpFile          = path.c_str();
	sei.lpParameters    = args.c_str();
    sei.nShow           = nShow;
	sei.hProcess        = 0;

    if ( ! ShellExecuteEx ( &sei ) )
    {
		cry();
        return FALSE;
    }
    return TRUE;
}


ShellFolder& desktop()
{
	return mol::singleton<mol::io::ShellFolder>();
}

} // end namespace mol::win::io;

const int UACPipe::BUFSIZE = 1024*128;

UACPipe::UACPipe()
	:pipe_(INVALID_HANDLE_VALUE)
{}


UACPipe::~UACPipe()
{
	close();
}

HANDLE UACPipe::create(const std::wstring& pipename )
{
    pipe_ = CreateNamedPipe( 
      pipename.c_str(),             // pipe name 
      PIPE_ACCESS_DUPLEX,			// read/write access 
      PIPE_TYPE_BYTE |				// message type pipe 
      PIPE_READMODE_BYTE |			// message-read mode 
      PIPE_WAIT,					// blocking mode 
      PIPE_UNLIMITED_INSTANCES,		// max. instances  
      BUFSIZE,						// output buffer size 
      BUFSIZE,						// input buffer size 
      0,							// client time-out 
      NULL);						// default security attribute 

	return pipe_;
}

HANDLE UACPipe::open( const std::wstring& pipename )
{
	const int BUFSIZE = 4096;

	if (!::WaitNamedPipe(pipename.c_str(), 20000)) 
	{ 
		return INVALID_HANDLE_VALUE;
	}

	// Try to open named pipe; wait for it, if necessary. 
 
	while (1) 
	{ 
		pipe_ = ::CreateFile( 
			pipename.c_str(),   // pipe name 
			GENERIC_READ |  // read and write access 
			GENERIC_WRITE, 
			0,              // no sharing 
			NULL,           // default security attributes
			OPEN_EXISTING,  // opens existing pipe 
			0,              // default attributes 
			NULL);          // no template file 
 
		// all OK ? 
		if (pipe_ != INVALID_HANDLE_VALUE) 
			return pipe_; 
 
		// Exit if an error other than ERROR_PIPE_BUSY occurs. 
 
		if (::GetLastError() != ERROR_PIPE_BUSY) 
		{
			return INVALID_HANDLE_VALUE;
		}
 
		 // All pipe instances are busy, so wait for 20 seconds. 	 
		if (!::WaitNamedPipe(pipename.c_str(), 20000)) 
		{ 
			return INVALID_HANDLE_VALUE;
		} 
	} 
 
	// never get here
	return pipe_;
}

bool UACPipe::connect(int milisecs)
{
	return  ::ConnectNamedPipe(pipe_, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED); 
}


std::string UACPipe::read()
{
	// Read client requests from the pipe. 
	char buf[BUFSIZE];
	DWORD cbBytesRead = 0; 

	std::ostringstream oss;
	while(1)
	{
		BOOL b = ::ReadFile( 
			 pipe_,        // handle to pipe 
			 buf,    // buffer to receive data 
			 BUFSIZE, // size of buffer 
			 &cbBytesRead, // number of bytes read 
			 NULL);        // not overlapped I/O 

		if ( !b )
		{
			//cry();
			break;
		}

		if ( cbBytesRead == 0 )
			break;

		oss.write( buf, cbBytesRead );
		if ( cbBytesRead < BUFSIZE )
			break;
	}
	return oss.str();
}

bool UACPipe::write( const std::string& data )
{
	DWORD cbWritten = 0;
	size_t cnt = 0;

	while ( (data.size() - cnt) > BUFSIZE )
	{
		BOOL b = ::WriteFile( 
					pipe_,                  // pipe handle 
					data.c_str()+cnt,       // message 
					BUFSIZE,			    // message length 
					&cbWritten,             // bytes written 
					NULL);                  // not overlapped 
		if (!b) 
		{
		    //cry();
		    return false;
		}
		cnt += cbWritten;
	}

	if ( (data.size() - cnt + cbWritten) > 0 )
	{
		BOOL b = ::WriteFile( 
					pipe_,                 // pipe handle 
					data.c_str()+cnt,       // message 
					(DWORD)(data.size()-cnt),	   // message length 
					&cbWritten,            // bytes written 
					NULL);                 // not overlapped 
		if (!b) 
		{
			//cry();
			return false;
		}
	}
	cnt += cbWritten;
	return true;
}

void UACPipe::disconnect()
{
	::DisconnectNamedPipe(pipe_); 
}

void UACPipe::close()
{
	if ( pipe_ != INVALID_HANDLE_VALUE )
		::CloseHandle(pipe_);
	pipe_ = INVALID_HANDLE_VALUE;
}


std::wstring resolveShortcut( const std::wstring& link)
{
    HRESULT hr = E_FAIL;

	wchar_t szPath[MAX_PATH];
    WIN32_FIND_DATA wfd;    

	mol::punk<IShellLink> ipShellLink;
	ipShellLink.createObject(CLSID_ShellLink);

	if ( !ipShellLink )
		return _T("");

	mol::punk<IPersistFile> ipPersistFile(ipShellLink);
	if (!ipPersistFile)
		return _T("");

	hr = ipPersistFile->Load( mol::towstring(link).c_str(), STGM_READ); 
	if ( hr != S_OK )
		return _T("");

    hr = ipShellLink->Resolve(NULL, SLR_UPDATE); 
	if ( hr != S_OK )
		return _T("");

    hr = ipShellLink->GetPath(szPath, MAX_PATH, &wfd, SLGP_RAWPATH); 
	if ( hr != S_OK )
		return _T("");

	return std::wstring(szPath);
}

std::wstring resolveInternetShortcut( const std::wstring& link)
{
    HRESULT hr = E_FAIL;

	mol::punk<IUniformResourceLocator> url;
	url.createObject(CLSID_InternetShortcut);
	if ( !url )
		return _T("");

	mol::punk<IPersistFile> pf(url);
	if ( !pf )
		return _T("");

	hr = pf->Load(link.c_str(),0);
	if ( hr != S_OK )
		return _T("");	

	mol::CoStrBuf purl;
	hr = url->GetURL(&purl);
	if ( hr != S_OK )
		return _T("");

	return mol::towstring(purl);
}

} // end namespace mol;


