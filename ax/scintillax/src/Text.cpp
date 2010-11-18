#include "StdAfx.h"
#include "Text.h"
#include "ScintillAx_dispid.h"
#include "ScintillaCtrl.h"


SciAxText::~SciAxText()
{
	ODBGS("~SciAxText");
}

SciAxText::Instance* SciAxText::CreateInstance( ScintillAx* sci )
{
	Instance* instance = new Instance;
	instance->sci_ = sci;
	return instance;
}

void SciAxText::dispose()
{
	sci_ = 0;
}

REFGUID SciAxText::getCoClassID()
{
	return IID_IScintillAxText;
}
	

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// Text Manipulation
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
HRESULT __stdcall SciAxText::put_Value( BSTR text)
{ 
	return this->SetText(text);
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxText::get_Value( BSTR* text)
{
	return this->GetText(text);
}

HRESULT __stdcall SciAxText::SetText( BSTR text)
{ 
	if (!sci_)
		return E_FAIL;

	std::string utf8 = "";
	if ( text )
		utf8 = mol::wstring2utf8(text);
	sci_->edit()->setText(utf8);
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxText::GetText( BSTR* text)
{
	if (!sci_)
		return E_FAIL;

	if ( text )
	{
		int s = sci_->edit()->getLength();
		char* c = new char[s+1];
		sci_->edit()->getText(c,s+1);
		c[s] = 0;
		*text = ::SysAllocString(mol::utf82wstring(c).c_str());
	}
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxText::get_Length( long* size)
{ 
	if (!sci_)
		return E_FAIL;

	if ( size )
	{
		*size = sci_->edit()->getLength();
	}
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxText::Append( BSTR text)
{
	if (!sci_)
		return E_FAIL;

	if ( text )
	{
		sci_->edit()->appendText(mol::wstring2utf8(text));
	}
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxText::Insert( BSTR text, long pos )
{ 
	if (!sci_)
		return E_FAIL;

	if ( text && sci_->edit() )
		sci_->edit()->insertText(mol::wstring2utf8(text), pos );
	return S_OK; 
}


///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxText::get_Modified( VARIANT_BOOL* vbModified )
{ 
	if (!sci_)
		return E_FAIL;

	if ( vbModified )
	{
		if ( sci_->edit()->getModified() )
			*vbModified = VARIANT_TRUE;
		else
			*vbModified = VARIANT_FALSE;
	}
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// search / replace
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxText::Search( BSTR what, long flags, VARIANT_BOOL* vbFound)
{ 
	if (!sci_)
		return E_FAIL;

	bool b = sci_->edit()->search(mol::tostring(what),flags);
	if ( vbFound )
		if ( b )
			*vbFound = VARIANT_TRUE;
		else
			*vbFound = VARIANT_FALSE;

	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxText::Replace( BSTR what, BSTR with, long flags, VARIANT_BOOL* vbReplaced)
{ 
	if (!sci_)
		return E_FAIL;

	bool b = sci_->edit()->replace(mol::tostring(what),mol::tostring(with),flags);
	if ( vbReplaced )
		if ( b )
			*vbReplaced = VARIANT_TRUE;
		else
			*vbReplaced = VARIANT_FALSE;

	return S_OK; 
}

HRESULT __stdcall SciAxText::GetTextRange(long start, long end, BSTR* range)
{
	if (!sci_)
		return E_FAIL;

	std::string s = sci_->edit()->getTextRange(start,end);
	if ( range )
		*range = ::SysAllocString(mol::utf82wstring(s).c_str());
	return S_OK;
}

HRESULT __stdcall SciAxText::Dispose()
{
	dispose();
	return S_OK;
}