#ifndef MOL_PLATFORM_CONFIG_DEF_GUARD_DEF_
#define MOL_PLATFORM_CONFIG_DEF_GUARD_DEF_



/////////////////////////////////////////////////////
// std includes for all platforms
/////////////////////////////////////////////////////

#include <sys/types.h>
#include <locale>

/////////////////////////////////////////////////////
// windows
/////////////////////////////////////////////////////
#ifdef _WIN32
#pragma warning( disable : 4355) // this pointer used in c'tor init list
#pragma warning( disable : 4250) // 
#endif

#ifdef _WIN32

#define NOMINMAX // use c++ even on win32
/*
// minimum windows target version
#define WINVER  _WIN32_WINNT_WIN2K
#define _WIN32_WINDOWS _WIN32_WINNT_WIN2K
//#define _WIN32_WINNT 0x0400 
#define _WIN32_WINNT _WIN32_WINNT_WIN2K
//#define _WIN32_IE 0x0501
#define _WIN32_IE _WIN32_IE_IE60 //SP2
*/


// minimum windows target version
#define WINVER  _WIN32_WINNT_WINXP
#define _WIN32_WINDOWS _WIN32_WINNT_WINXP
//#define _WIN32_WINNT 0x0400 
#define _WIN32_WINNT _WIN32_WINNT_WINXP
//#define _WIN32_IE 0x0501
#define _WIN32_IE _WIN32_IE_IE80 //SP2




// main windows headers

#define NO_WINDOWS_LEAN_AND_MEAN

#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <process.h>

namespace mol {

// win32 thread types
typedef HANDLE THREAD_HANDLE;
typedef unsigned int THREAD_RET_VAL;
typedef HANDLE MUTEX_HANDLE;

#define MOL_THREAD_CALL_TYPE __stdcall

}

#else

/////////////////////////////////////////////////////
//! for Non-Win32 Systems, assume POSIX
/////////////////////////////////////////////////////

// std POSIX includes for molib
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <errno.h>

// make SOCKET type avail under POSIX
typedef int SOCKET;
typedef int COLORREF;
typedef unsigned long DWORD;
typedef char BYTE;
typedef unsigned short WORD;
typedef long* LONG_PTR;
#define RGB(r,g,b)      ((COLORREF)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))

// make win32 Socket Constants avail under POSIX
#define WSAEMSGSIZE EMSGSIZE
#define SOCKET_ERROR   -1
//#define INADDR_NONE	   -1
#define INVALID_SOCKET 0
#define SD_RECEIVE     0
#define SD_SEND		   1
#define SD_BOTH        2

namespace mol {

// POSIX THREAD TYPES
typedef pthread_t THREAD_HANDLE;
typedef void* THREAD_RET_VAL;
typedef pthread_mutex_t MUTEX_HANDLE;

}

#define MOL_THREAD_CALL_TYPE

//#define closesocket(s) close(s)

namespace mol {

inline void closesocket(SOCKET s)
{
  close(s);
}

}

#endif

#ifdef __CYGWIN__
namespace std {
typedef std::basic_string <wchar_t> wstring;
typedef std::basic_ostringstream <wchar_t> wostringstream;
};
#endif


/////////////////////////////////////////////////////
// platform specific
/////////////////////////////////////////////////////

#ifdef _MSC_VER

namespace mol {

inline int __cdecl memicmp( const void * a,  const void * b, size_t s)
{
	return _memicmp(a,b,s);
}

inline int __cdecl stricmp( const char* a,  const char * b)
{
	return _stricmp(a,b);
}

inline int __cdecl wcstricmp( const wchar_t* a,  const wchar_t * b)
{
	return _wcsicmp(a,b);
}

}

#else

#include <cstring>

namespace mol {

inline int memicmp( const void * a,  const void * b, size_t s)
{
	return ::strncasecmp((const char*)a,(const char*)b,s);
}

inline int stricmp( const char* a,  const char * b)
{
	return ::strcasecmp(a,b);
}


inline int wcstricmp( const wchar_t* a,  const wchar_t * b)
{
#ifndef __CYGWIN__
	return wcscasecmp(a,b);
#else

	int n = std::min(wcslen(a), wcslen(b) );
	for( int i = 0; i < n; i++)
	{
		if ( towupper(a[i]) == towupper(b[i]) )
			continue;
		if ( towupper(a[i]) < towupper(b[i]) )
			return -1;
		return 1;
	}
	return 0;
#endif
}

}

#endif


#endif




