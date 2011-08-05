#include "StdAfx.h"
#include "Position.h"
#include "ScintillAx_dispid.h"
#include "ScintillaCtrl.h"

SciAxPosition::~SciAxPosition()
{
	ODBGS("~SciAxPosition");
}

SciAxPosition::Instance* SciAxPosition::CreateInstance( ScintillAx* sci )
{
	Instance* instance = new Instance;
	instance->sci_ = sci;
	return instance;
}

void SciAxPosition::dispose()
{
	sci_ = 0;
}

REFGUID SciAxPosition::getCoClassID()
{
	return IID_IScintillAxPosition;
}
	

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// Position and Caret
//////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxPosition::put_Caret( long pos)
{
	if (!sci_)
		return E_FAIL;

	sci_->edit()->pos(pos);
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxPosition::get_Caret( long* pos)
{
	if (!sci_)
		return E_FAIL;

	if ( pos )
	{
		*pos = 0;
		if ( sci_->edit() )
			*pos = sci_->edit()->pos();
	}
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxPosition::CharAt( long pos, BSTR* ch)
{ 
	if (!sci_)
		return E_FAIL;

	if ( ch )
	{
		char buf[2];
		buf[0] = (char)sci_->edit()->getCharAt(pos);
		buf[1] = 0;
		*ch = ::SysAllocString(mol::fromUTF8(buf).c_str());	
	}
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxPosition::Scroll( long cols, long lines )
{ 
	if (!sci_)
		return E_FAIL;

	sci_->edit()->lineScroll(cols,lines);
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxPosition::ScrollIntoView()
{
	if (!sci_)
		return E_FAIL;

	sci_->edit()->scrollCaret();
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxPosition::put_SearchPos( long pos)
{ 
	if (!sci_)
		return E_FAIL;

	sci_->edit()->searchPos(pos);
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxPosition::get_SearchPos( long* pos)
{
	if (!sci_)
		return E_FAIL;

	if ( pos )
	{
		*pos = sci_->edit()->searchPos();
	}
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxPosition::put_Anchor( long pos)
{ 
	if (!sci_)
		return E_FAIL;

	sci_->edit()->anchor(pos);
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxPosition::get_Anchor( long* pos)
{ 
	if (!sci_)
		return E_FAIL;

	if ( pos )
	{
		*pos = sci_->edit()->anchor();
	}
	return S_OK; 
}


HRESULT __stdcall SciAxPosition::Dispose()
{
	dispose();
	return S_OK;
}