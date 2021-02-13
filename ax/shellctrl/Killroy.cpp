// ColorPickerDlg.cpp : implementation file
//

#define _CRT_SECURE_NO_DEPRECATE 1
#include "stdafx.h"
#include "Killroy.h"
#include "win/Res.h"
#include "RestartManager.h"

class RmSession
{
public:
	RmSession()
		:dwError_(0), dwSession_(0)
	{
		::ZeroMemory(szSessionKey_,MOL_CCH_RM_SESSION_KEY+1);		
	}

	long getPidForFilename( const std::wstring& filename, IPIDS** pid )
	{
		mol::punk<Pids> pids = Pids::CreateInstance();
		pids.queryInterface(pid);

		dwError_ = ::RmStartSession(&dwSession_, 0, szSessionKey_);
		if (dwError_ != ERROR_SUCCESS) 
		{
			return -1;
		}

		PCWSTR pszFile = filename.c_str();
		dwError_ = ::RmRegisterResources(dwSession_, 1, &pszFile,0, NULL, 0, NULL);
		if (dwError_ != ERROR_SUCCESS) 
		{
			return -1;
		}

		DWORD dwReason;
		UINT nProcInfoNeeded = 10;
		UINT nProcInfo = 10;
		RM_PROCESS_INFO rgpi[10];
		dwError_ = ::RmGetList(dwSession_, &nProcInfoNeeded, &nProcInfo, rgpi, &dwReason);
		if (dwError_ != ERROR_SUCCESS) 
		{
			return -1;
		}

		for (UINT i = 0; i < nProcInfo; i++)
		{

			HANDLE hProcess = ::OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, rgpi[i].Process.dwProcessId);
			if (hProcess)
			{
				FILETIME ftCreate, ftExit, ftKernel, ftUser;
				if (::GetProcessTimes(hProcess, &ftCreate, &ftExit, &ftKernel, &ftUser) &&
					::CompareFileTime(&rgpi[i].Process.ProcessStartTime, &ftCreate) == 0)
				{
					::CloseHandle(hProcess);

					Pid::Instance* p = Pid::CreateInstance(rgpi[i].Process.dwProcessId, ftCreate);
					pids->add(p);
				}
				::CloseHandle(hProcess);
			}
		}
		return 1;
	}

	~RmSession()
	{
		if ( dwSession_ != 0 )
		{
			::RmEndSession(dwSession_);
			dwSession_ = 0;
		}
	}

private:
	DWORD dwError_;
	DWORD dwSession_;
	WCHAR szSessionKey_[MOL_CCH_RM_SESSION_KEY+1];
};


HRESULT __stdcall KillRoy::FindPIDSforFile( BSTR filename, IPIDS** pid)
{
	if ( pid == 0 )
		return E_INVALIDARG;

	std::wstring fn = mol::towstring(filename);

	RmSession rms;	
	rms.getPidForFilename(fn,pid);

	return S_OK;
}


Pids::~Pids() {

	for (auto it = pids_.begin(); it != pids_.end(); it++)
	{
		(*it)->Release();
	}
}

void Pids::dispose() {}

Pids::Instance* Pids::CreateInstance()
{
	Instance* instance = new Instance();
	return instance;
}

Pids* Pids::add(IPID* pid)
{
	pids_.push_back(pid);
	pid->AddRef();
	return this;
}

HRESULT __stdcall Pids::Item(VARIANT i, IPID** docItem) 
{
	mol::variant v(i);
	v.changeType(VT_UI4);
	return pids_[v.uintVal]->QueryInterface(IID_IPID, (void**)(docItem));
}

HRESULT __stdcall Pids::get_Count(long* cnt)
{
	*cnt = (long)pids_.size();
	return S_OK;
}


Pid::Pid()
{
}

void Pid::dispose() {}

Pid::Instance* Pid::CreateInstance(long pid, FILETIME ft)
{
	Instance* instance = new Instance();
	instance->pid_ = pid;
	instance->ft_ = ft;
	return instance;
}

HRESULT __stdcall Pid::get_PID(long* pid)
{
	if (!pid)
		return E_INVALIDARG;
	*pid = pid_;
	return S_OK;
}

HRESULT __stdcall Pid::get_Name(BSTR* path)
{
	if (!path)
		return E_INVALIDARG;

	*path = 0;

	WCHAR sz[MAX_PATH];
	DWORD cch = MAX_PATH;

	HANDLE hProcess = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, pid_);
	if (hProcess)
	{
		FILETIME ftCreate, ftExit, ftKernel, ftUser;
		if (GetProcessTimes(hProcess, &ftCreate, &ftExit, &ftKernel, &ftUser)
			&& CompareFileTime(&ft_, &ftCreate) == 0)
		{
			if (::QueryFullProcessImageName(hProcess, 0, sz, &cch) && cch <= MAX_PATH)
			{
				*path = ::SysAllocString(sz);
			}
		}
		::CloseHandle(hProcess);
	}
	return S_OK;
}

HRESULT __stdcall Pid::TerminateProcess(VARIANT_BOOL *ok)
{
	if (ok)
		*ok = VARIANT_FALSE;

	HANDLE hProcess = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION | PROCESS_TERMINATE, FALSE, pid_);
	if (hProcess)
	{
		FILETIME ftCreate, ftExit, ftKernel, ftUser;
		if (GetProcessTimes(hProcess, &ftCreate, &ftExit, &ftKernel, &ftUser)
			&& CompareFileTime(&ft_, &ftCreate) == 0)
		{
			::TerminateProcess(hProcess, 0);
		}
		::CloseHandle(hProcess);
	}

	return S_OK;
}
