
#include "win/dde.h"

namespace mol  {

namespace win  {

////////////////////////////////////////////////////////////////////////////////////////

bool dde::bDontRespond_ = FALSE;

////////////////////////////////////////////////////////////////////////////////////////


dde_init::dde_init( HWND hwnd, WPARAM wParam, LPARAM lParam)
{
    hWnd_			= hwnd;
    hWndClient_		= (HWND)wParam;

	wchar_t buf[1024];
    buf[0]=0;
    GlobalGetAtomName(LOWORD(lParam),buf,1024);
    inApp_ = std::wstring(buf);
    GlobalGetAtomName(HIWORD(lParam),buf,1024);
    intopic_ = buf;
}

dde_init::~dde_init()
{
    if (aOutApp_)
        GlobalDeleteAtom(aOutApp_);
    if (aOutTopic_)
        GlobalDeleteAtom(aOutTopic_);
}

void dde_init::ack( const std::wstring& app, const std::wstring& topic )
{

    aOutApp_   = GlobalAddAtom(app.c_str());
    aOutTopic_ = GlobalAddAtom(topic.c_str());

    SendMessage( hWndClient_, WM_DDE_ACK, (WPARAM)hWnd_, MAKELPARAM(aOutApp_, aOutTopic_));

}

bool dde_init::dontRespond()
{
    if (bDontRespond_)
        return true;

    DWORD dwProcessID;
    GetWindowThreadProcessId( hWndClient_, &dwProcessID);
    if(GetCurrentProcessId() == dwProcessID)
        return false;

    return true;
}

const std::wstring& dde_init::app()
{
    return inApp_;
}

const std::wstring& dde_init::topic()
{
    return intopic_;
}

////////////////////////////////////////////////////////////////////////////////////////

dde_exec::dde_exec( HWND hwnd, WPARAM w, LPARAM l)
{
    cmd_		  = _T("");
    path_		  = _T("");
    cmdLine_	  = _T("");
    hWnd_		  = hwnd;
    hWndClient_   = (HWND)w;
    lParam_       = l;

    ZeroMemory(&ddeAck_, sizeof(ddeAck_));

    if ( UnpackDDElParam( WM_DDE_EXECUTE, lParam_, &uLo_, (PUINT_PTR)&hgMem_) )
		cmdLine_	= std::wstring((wchar_t*)GlobalLock(hgMem_));

    getCommandTypeFromDDEString();
    getPathFromDDEString( );
}

dde_exec::~dde_exec()
{
    GlobalUnlock(hgMem_);
}

const std::wstring& dde_exec::getCmdLine()
{
    return cmdLine_;
}

const std::wstring& dde_exec::getCmd()
{
    return cmd_;
}

const std::wstring& dde_exec::getPath()
{
    return path_;
}

void dde_exec::ack(int i)
{
    ddeAck_.fAck = i;
    LPUINT lpTemp = (LPUINT)&ddeAck_;

    PostMessage( hWndClient_, WM_DDE_ACK, (WPARAM)hWnd_,
        ReuseDDElParam(lParam_, WM_DDE_EXECUTE, WM_DDE_ACK, *lpTemp, (UINT_PTR)hgMem_));
}

void dde_exec::execute(const std::wstring& path, const std::wstring & clss, const std::wstring& verb, int mask )
{
    dde::bDontRespond_=TRUE;

    SHELLEXECUTEINFO  sei;
    ZeroMemory(&sei, sizeof(SHELLEXECUTEINFO));
    sei.cbSize = sizeof(SHELLEXECUTEINFO);

    sei.fMask = mask;//SEE_MASK_CLASSNAME;
    sei.lpFile = path.c_str();

    sei.lpClass = clss.c_str();//TEXT("folder");
    sei.hwnd = NULL;
    sei.nShow = 1;
    sei.lpVerb = verb.c_str();//TEXT("explore");
    ShellExecuteEx(&sei);

    dde::bDontRespond_=FALSE;
}


////////////////////////////////////////////////////////////////////////////////////////
// GetCommandTypeFromDDEString
////////////////////////////////////////////////////////////////////////////////////////

int dde_exec::getCommandTypeFromDDEString()
{
    cmd_ = _T("");
    size_t startPos = cmdLine_.find(_T('['));
    size_t endPos   = cmdLine_.find(_T('('));

    if ( (startPos != std::wstring::npos ) && (endPos != std::wstring::npos ))
        cmd_ = cmdLine_.substr( startPos+1, endPos-startPos-1 );

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////
//   GetPathFromDDEString()
////////////////////////////////////////////////////////////////////////////////////////

bool dde_exec::getPathFromDDEString()
{
    size_t startPos = cmdLine_.find('"');
    if ( startPos == std::wstring::npos || (startPos+1 > cmdLine_.size()) )
        return false;

    size_t endPos   = cmdLine_.find('"',startPos+1 );
    if ( endPos == std::wstring::npos || (endPos <= startPos) )
        return false;

    path_ = cmdLine_.substr(startPos+1,endPos-startPos-1);
    return true;
}

} // endnamespace mol::win
} // endnamespace mol
