#include "StdAfx.h"
#include "Selection.h"
#include "ScintillAx_dispid.h"
#include "ScintillaCtrl.h"


SciAxSelection::~SciAxSelection()
{
	ODBGS("~SciAxSelection");
}

SciAxSelection::Instance* SciAxSelection::CreateInstance( ScintillAx* sci )
{
	Instance* instance = new Instance;
	instance->sci_ = sci;
	return instance;
}

void SciAxSelection::dispose()
{
	sci_ = 0;
}

REFGUID SciAxSelection::getCoClassID()
{
	return IID_IScintillAxSelection;
}
	

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// Selection
//////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxSelection::GetSelection	( long* first, long* last)
{
	if (!sci_)
		return E_FAIL;

	if ( first && last )
	{
		*first = sci_->edit()->getSelStart();
		*last  = sci_->edit()->getSelEnd();
	}
	return S_OK;
}

HRESULT __stdcall SciAxSelection::SetSelection		( long first, long last )
{
	if (!sci_)
		return E_FAIL;

	sci_->edit()->setSel(first,last);
	return S_OK;
}

HRESULT __stdcall SciAxSelection::get_Text	( BSTR* text )
{
	if (!sci_)
		return E_FAIL;

	if ( text )
	{
		std::string txt = "";
		txt = sci_->edit()->getSelText();
		*text = ::SysAllocString(mol::fromUTF8(txt).c_str());
	}
	return S_OK;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxSelection::put_Start( long pos)
{ 
	if (!sci_)
		return E_FAIL;

	sci_->edit()->setSelStart(pos);
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxSelection::get_Start( long* pos)
{ 
	if (!sci_)
		return E_FAIL;

	if ( pos )
	{
		*pos = sci_->edit()->getSelStart();
	}
	return S_OK; 
}
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxSelection::put_End( long pos)
{ 
	if (!sci_)
		return E_FAIL;

	sci_->edit()->setSelEnd(pos);
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxSelection::get_End( long* pos)
{ 
	if (!sci_)
		return E_FAIL;

	if ( pos )
	{
		*pos = sci_->edit()->getSelEnd();
	}
	return S_OK; 
}
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxSelection::put_Text( BSTR text )
{ 
	if (!sci_)
		return E_FAIL;

	if ( text )
		sci_->edit()->replaceSel(mol::toUTF8(text));
	return S_OK; 
}


//////////////////////////////////////////////////////////////////////////////
//
// Cut Copy Paste
//
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxSelection::Cut ()
{
	if (!sci_)
		return E_FAIL;

	sci_->edit()->cut(); 
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxSelection::Copy ()
{
	if (!sci_)
		return E_FAIL;

	sci_->edit()->copy();
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxSelection::Paste ()
{
	if (!sci_)
		return E_FAIL;

	sci_->edit()->paste();
	return S_OK;
}


HRESULT __stdcall SciAxSelection::Dispose()
{
	dispose();
	return S_OK;
}