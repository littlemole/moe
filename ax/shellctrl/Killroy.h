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
	Pid();

	void dispose();

	typedef mol::com_instance<Pid> Instance;
	static Instance* CreateInstance(long pid, FILETIME ft);

	virtual HRESULT __stdcall get_PID(long* pid);
	virtual HRESULT __stdcall get_Name(BSTR* path);
	virtual HRESULT __stdcall TerminateProcess(VARIANT_BOOL *ok);

protected:

	FILETIME ft_;
	long	pid_;
};


class Pids :
	public Dispatch<IPIDS>,
	public interfaces< Pids, implements< IDispatch, IPIDS> >
{
public:
	typedef mol::com_instance<Pids> Instance;
	static Instance* CreateInstance();

	~Pids();
	void dispose();

	Pids* add(IPID* pid);

	virtual HRESULT __stdcall Item( VARIANT i,  IPID** docItem);
	virtual HRESULT __stdcall get_Count(long* cnt);

private:
	std::vector<IPID*> pids_;
};

class KillRoy : 
	public com_registerobj<KillRoy,CLSID_KillRoy>,
	public Dispatch<IKillRoy>,
	public interfaces< KillRoy, implements< IDispatch, IKillRoy> >
{
public:
	KillRoy()
	{}

    virtual HRESULT __stdcall FindPIDSforFile( BSTR filename, IPIDS** pid);
};

#endif