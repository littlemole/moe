#include "StdAfx.h"
#include "Line.h"
#include "ScintillAx_dispid.h"
#include "ScintillaCtrl.h"


SciAxLine::~SciAxLine()
{
	ODBGS("~SciAxLine");
}

SciAxLine::Instance* SciAxLine::CreateInstance( ScintillAx* sci)
{
	Instance* instance = new Instance;
	instance->sci_ = sci;
	return instance;
}

void SciAxLine::dispose()
{
	sci_ = 0;
}

REFGUID SciAxLine::getCoClassID()
{
	return IID_IScintillAxLine;
}
	

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// Line Handling
//////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxLine::get_Count( long* line)
{ 
	if (!sci_)
		return E_FAIL;

	if ( line )
		*line = sci_->edit()->getLineCount();
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxLine::get_Current( long* line)
{ 
	if (!sci_)
		return E_FAIL;

	if ( line )
		*line = sci_->edit()->lineFromPos(sci_->edit()->pos());
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxLine::LineFromPos( long pos, long* line )
{
	if (!sci_)
		return E_FAIL;

	if ( line )
		*line = sci_->edit()->lineFromPos(pos);

	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxLine::PosFromLine( long line, long* pos )
{
	if (!sci_)
		return E_FAIL;

	if ( pos )
		*pos = sci_->edit()->posFromLine(line);
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxLine::LineEndPos( long line, long* pos )
{
	if (!sci_)
		return E_FAIL;

	if ( pos )
		*pos = sci_->edit()->lineEndPos(line);
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxLine::FirstVisibleLine( long* line )
{
	if (!sci_)
		return E_FAIL;

	if ( line )
		*line = sci_->edit()->getFirstVisibleLine();
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxLine::LinesOnScreen( long* lines )
{
	if (!sci_)
		return E_FAIL;

	if ( lines )
		*lines = sci_->edit()->getLinesOnScreen();

	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxLine::LineLength( long line, long* length)
{ 
	if (!sci_)
		return E_FAIL;

	if ( length )
	{
		*length = sci_->edit()->getLineLength(line);
	}
	return S_OK; 
}
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxLine::LineText( long line, BSTR* text )
{ 
	if (!sci_)
		return E_FAIL;

	if ( text )
	{
		int e,s;
		s = sci_->edit()->posFromLine(line);
		e = sci_->edit()->lineEndPos(line);
		std::string l = "";
		l = sci_->edit()->getTextRange(s,e);
		*text = ::SysAllocString(mol::fromUTF8(l).c_str());
	}
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxLine::SetLineText( long line, BSTR text )
{ 
	if (!sci_)
		return E_FAIL;

	if ( text )
	{
		if ( line <= sci_->edit()->getLineCount() )
		{
			int start = sci_->edit()->posFromLine(line);
			int end   = sci_->edit()->lineEndPos(line);
			sci_->edit()->setSel(start,end);
			sci_->edit()->replaceSel(mol::BSTR2ansi(text));
		}
	}
	return S_OK; 
}
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxLine::Goto( long line )
{ 
	if (!sci_)
		return E_FAIL;

	sci_->edit()->gotoLine(line);
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxLine::Highlite( long line )
{
	if (!sci_)
		return E_FAIL;

	sci_->edit()->highliteLine(line);
	return S_OK;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxLine::Dispose()
{
	dispose();
	return S_OK;
}