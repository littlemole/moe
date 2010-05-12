#include "win/Core.h"

namespace mol  {


const Rect stdRect  = Rect( CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT );

void* dllFunc( const mol::string& dll, const mol::string& f )
{
	HMODULE handle = ::GetModuleHandle( dll.c_str() );
	if (!handle )
	{
		handle = ::LoadLibrary( dll.c_str() );
	}
	return dllFunc( handle, f );
}


void* dllFunc( HMODULE module, const mol::string& f )
{
	if ( module )
	{
		std::string fun = mol::tostring(f);
		return ::GetProcAddress( module, fun.c_str() );
	}
	return 0;
}

bool OS::has_uac()
{
	SUPPORTED_OSTYPE SO = version();

	if ( SO == WIN7 )
		return true;
	if ( SO == WINVISTA )
		return true;

	return false;
}

SUPPORTED_OSTYPE OS::version() 
{
    OSVERSIONINFO osvi;

	::ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

	::GetVersionEx(&osvi);

	DWORD major = osvi.dwMajorVersion;
	DWORD minor = osvi.dwMinorVersion;

	if ( major > 6 )
		return WIN7;

	if ( (major == 6) && (minor>0) )
		return WIN7;

	if ( (major == 6) && (minor==0) )
		return WINVISTA;

	if ( (major == 5) && (minor>0) )
		return WINXP;

	if ( (major == 5) && (minor==0) )
		return WIN2K;

	return UNSUPPORTED;
}


} // endnamespace mol
