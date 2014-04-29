
#include "util/x.h"

#ifdef _WIN32
#ifdef _DEBUG



void _cry()
{
	int er = GetLastError();
        LPVOID lpMsgBuf;
        ::FormatMessage(
                FORMAT_MESSAGE_ALLOCATE_BUFFER |
                FORMAT_MESSAGE_FROM_SYSTEM |
                FORMAT_MESSAGE_IGNORE_INSERTS,
                NULL,
                GetLastError(),
                MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
				(wchar_t*) &lpMsgBuf,
                0,
                NULL
        );
		wchar_t  buf[32];
		wsprintf(buf,_T("err: %i"),er);
		::MessageBox(NULL, (wchar_t*)lpMsgBuf, buf, MB_OK | MB_ICONINFORMATION);
        ::LocalFree( lpMsgBuf );
}
#else
void _cry() {};

#endif
#endif

namespace mol {
#ifdef _WIN32

std::wstring WinErrorString(unsigned long err)
{
    if ( err == 0 )
        err = GetLastError();

    LPVOID lpMsgBuf;
    ::FormatMessage(
            FORMAT_MESSAGE_ALLOCATE_BUFFER |
            FORMAT_MESSAGE_FROM_SYSTEM |
            FORMAT_MESSAGE_IGNORE_INSERTS,
            NULL,
            err,
            MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
            (LPTSTR) &lpMsgBuf,
            0,
            NULL
    );
    //::MessageBox( NULL, (LPCTSTR)lpMsgBuf, "Error", MB_OK | MB_ICONINFORMATION );
	std::wstring tmp((wchar_t*)lpMsgBuf);
    ::LocalFree( lpMsgBuf );
    return tmp;
}
#endif


} // end namespace mol
