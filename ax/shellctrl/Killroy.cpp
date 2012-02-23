// ColorPickerDlg.cpp : implementation file
//

#define _CRT_SECURE_NO_DEPRECATE 1
#include "stdafx.h"
#include "Killroy.h"
#include "win/Res.h"

class RmSession
{
public:
	RmSession()
		:dwError_(0), dwSession_(0)
	{
		::ZeroMemory(szSessionKey_,MOL_CCH_RM_SESSION_KEY+1);		
	}

	long getPidForFilename( const std::wstring& filename, IPID** pid )
	{
		if (!mol::v7::RmStartSession)
		{
			return -1;
		}

		dwError_ = mol::v7::RmStartSession(&dwSession_, 0, szSessionKey_);
		if (dwError_ != ERROR_SUCCESS) 
		{
			return -1;
		}

		PCWSTR pszFile = filename.c_str();
		dwError_ = mol::v7::RmRegisterResources(dwSession_, 1, &pszFile,0, NULL, 0, NULL);
		if (dwError_ != ERROR_SUCCESS) 
		{
			return -1;
		}

		DWORD dwReason;
		UINT nProcInfoNeeded;
		UINT nProcInfo = 1;
		mol::v7::RM_PROCESS_INFO rgpi;
		dwError_ = mol::v7::RmGetList(dwSession_, &nProcInfoNeeded, &nProcInfo, &rgpi, &dwReason);
		if (dwError_ != ERROR_SUCCESS) 
		{
			return -1;
		}

		HANDLE hProcess = ::OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, rgpi.Process.dwProcessId);
		if (hProcess) 
		{
			FILETIME ftCreate, ftExit, ftKernel, ftUser;
			if (::GetProcessTimes(hProcess, &ftCreate, &ftExit,&ftKernel, &ftUser) &&
				::CompareFileTime(&rgpi.Process.ProcessStartTime,&ftCreate) == 0) 
			{
				::CloseHandle(hProcess);

				Pid::Instance* p = Pid::CreateInstance(rgpi.Process.dwProcessId,ftCreate);
				p->QueryInterface(IID_IPID,(void**)pid);
				return rgpi.Process.dwProcessId;
			}
			::CloseHandle(hProcess);
		}
		return -1;
	}

	~RmSession()
	{
		if ( dwSession_ != 0 )
		{
			mol::v7::RmEndSession(dwSession_);
			dwSession_ = 0;
		}
	}

private:
	DWORD dwError_;
	DWORD dwSession_;
	WCHAR szSessionKey_[MOL_CCH_RM_SESSION_KEY+1];
};


HRESULT __stdcall KillRoy::FindPIDforFile( BSTR filename, IPID** pid)
{
	if ( pid == 0 )
		return E_INVALIDARG;

	std::wstring fn = mol::towstring(filename);

	RmSession rms;	
	rms.getPidForFilename(fn,pid);

	return S_OK;
}