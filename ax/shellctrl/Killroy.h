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


class KillRoy : 
	public com_registerobj<KillRoy,CLSID_KillRoy>,
	public Dispatch<IKillRoy>,
	public interfaces< KillRoy, implements< IDispatch, IKillRoy> >
{
public:
		KillRoy()
		{
		}

        virtual HRESULT __stdcall FindPIDforFile( BSTR filename, LONG *pid);
        
        virtual HRESULT __stdcall TerminateProcess( LONG pid, VARIANT_BOOL *ok)
		{

			return S_OK;
		}

protected:
};

#endif