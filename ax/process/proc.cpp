#include "stdafx.h"
#include "proc.h"

using namespace mol;


bool PipedProcessAx::init(const std::wstring& p)
{
	//shutdown();

	pProcess_.async(vbAsync_ == VARIANT_TRUE ? true : false );

	if (!pProcess_.create(p))
		return false;

	return true;
}

void PipedProcessAx::shutdown()
{
	pProcess_.close();
	
	if ( cookie_dispEvent_ )
	{
		GIT git;
		git.revokeInterface(cookie_dispEvent_);
		cookie_dispEvent_ = 0;
	}
}

HRESULT __stdcall PipedProcessAx::get_Async(VARIANT_BOOL* vb)
{
	if ( !vb)
		return E_INVALIDARG;

	*vb = vbAsync_;
	return S_OK;
}

HRESULT __stdcall PipedProcessAx::put_Async(VARIANT_BOOL  vb)
{
	vbAsync_ = vb;
	return S_OK;
}

HRESULT __stdcall PipedProcessAx::get_readyState(long* state)
{
	if ( !state)
		return E_INVALIDARG;

	*state = pProcess_.readyState();

	return S_OK;
}


HRESULT __stdcall PipedProcessAx::get_Eof( VARIANT_BOOL* vb)
{
	if ( !vb)
		return E_INVALIDARG;

	if ( pProcess_.eof() )
	{
		*vb = VARIANT_TRUE;
		return S_OK;
	}
	*vb = VARIANT_FALSE;
	return S_OK;
}

HRESULT __stdcall PipedProcessAx::get_ErrEof( VARIANT_BOOL* vb)
{
	if ( !vb)
		return E_INVALIDARG;

	if ( pProcess_.err_eof() ) 
	{
		*vb = VARIANT_TRUE;
		return S_OK;
	}
	*vb = VARIANT_FALSE;
	return S_OK;
}

HRESULT __stdcall PipedProcessAx::Create( BSTR cmdline,  VARIANT_BOOL* vbSuccess)
{
	if ( !vbSuccess)
		return E_INVALIDARG;

	*vbSuccess = VARIANT_FALSE;

	bool b = init( bstr(cmdline).towstring() );
	if (b)
		*vbSuccess = VARIANT_TRUE;

	return S_OK;
}

HRESULT __stdcall PipedProcessAx::Write( BSTR s, VARIANT_BOOL* vbSuccess)
{
	if ( !vbSuccess)
		return E_INVALIDARG;


	*vbSuccess = VARIANT_TRUE;

	if ( s == 0 )
		return S_OK;

	bstr tmp(s);

	if ( tmp.tostring() == "" )
		return S_OK;

	pProcess_.writeLine( tmp.tostring() );
	return S_OK;
}

HRESULT __stdcall PipedProcessAx::CloseOut()
{
	pProcess_.closeWrite();
	return S_OK;
}

HRESULT __stdcall PipedProcessAx::ReadLine(BSTR* line)
{
	if ( !line )
		return E_INVALIDARG;

	if ( pProcess_.eof() )
		return S_OK;

	std::string l = pProcess_.readLine();

	*line = ::SysAllocString(mol::towstring(l).c_str());

	return S_OK;
}

HRESULT __stdcall PipedProcessAx::ReadErrLine(BSTR* line )
{
	if ( !line )
		return E_INVALIDARG;

	if ( pProcess_.err_eof() )
		return S_OK;

	std::string l = pProcess_.readErrLine();

	*line = ::SysAllocString(mol::towstring(l).c_str());

	return S_OK;
}



HRESULT __stdcall PipedProcessAx::Close()
{
	shutdown();
	return S_OK;
}

HRESULT __stdcall PipedProcessAx::Terminate()
{
	pProcess_.terminate();
	shutdown();
	return S_OK;
}

HRESULT __stdcall PipedProcessAx::put_onComplete(IDispatch* disp)
{
	GIT git;
	if ( cookie_dispEvent_ )
	{
		git.revokeInterface(cookie_dispEvent_);
	}
	git.registerInterface(disp,&cookie_dispEvent_);
	return S_OK;
}

void PipedProcessAx::onDone()
{
	//mol::com_init ci;

	this->fire(1);
	if ( cookie_dispEvent_ )
	{
		punk<IDispatch>  disp;
		GIT git;
		git.getInterface(cookie_dispEvent_,&disp);
		disp_invoke(disp,DISPID_VALUE);
	}
}