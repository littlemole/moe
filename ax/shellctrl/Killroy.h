#ifndef _DEF_GUARD_MOL_KILLROY_DLG_DEF_
#define _DEF_GUARD_MOL_KILLROY_DLG_DEF_

/////////////////////////////////////////////////////////////////////////////
// ColorPickerDlg dialog

#include "ole/factory.h"
#include "ole/Bstr.h"
#include "ole/punk.h"
#include "ole/aut.h"
#include "win/Dlg.h"
#include "win/DIB.h"
#include "win/msghandler.h"
#include "win/msg_macro.h"
#include "win/v7.h"
#include "ColorResources.h"  

#include "shellCtrl_h.h"

using namespace mol;

class Pid : 
	public Dispatch<IPID>,
	public interfaces< Pid, implements< IDispatch, IPID> >
{
public:
		Pid()
		{
		}

		void dispose() {}

		typedef mol::com_instance<Pid> Instance;
		static Instance* CreateInstance(long pid, FILETIME ft)
		{
			Instance* instance = new Instance();
			instance->pid_ = pid;
			instance->ft_ = ft;
			return instance;
		}

        virtual HRESULT __stdcall get_PID( long* pid)
		{
			if (!pid)
				return E_INVALIDARG;
			*pid = pid_;
			return S_OK;
		}
        
        virtual HRESULT __stdcall get_Name( BSTR* path)
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
				if (   GetProcessTimes(hProcess, &ftCreate, &ftExit,&ftKernel, &ftUser) 
					&& CompareFileTime(&ft_, &ftCreate) == 0) 
				{
					if ( ::QueryFullProcessImageName(hProcess, 0, sz, &cch) && cch <= MAX_PATH) 
					{
						*path = ::SysAllocString(sz);
					}
				}
				::CloseHandle(hProcess);
			}			
			return S_OK;
		}

        virtual HRESULT __stdcall TerminateProcess( VARIANT_BOOL *ok)
		{
			if ( ok )
				*ok = VARIANT_FALSE;

			HANDLE hProcess = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION|PROCESS_TERMINATE, FALSE, pid_);
		    if (hProcess) 
			{
				FILETIME ftCreate, ftExit, ftKernel, ftUser;
				if (   GetProcessTimes(hProcess, &ftCreate, &ftExit,&ftKernel, &ftUser) 
					&& CompareFileTime(&ft_, &ftCreate) == 0) 
				{
					::TerminateProcess(hProcess,0);
				}
				::CloseHandle(hProcess);
			}	
			
			return S_OK;
		}

protected:

	FILETIME ft_;
	long	pid_;
};

class KillRoy : 
	public com_registerobj<KillRoy,CLSID_KillRoy>,
	public Dispatch<IKillRoy>,
	public interfaces< KillRoy, implements< IDispatch, IKillRoy> >
{
public:
		KillRoy()
		{
		}

        virtual HRESULT __stdcall FindPIDforFile( BSTR filename, IPID** pid);
        

protected:
};

#endif