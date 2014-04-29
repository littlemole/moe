#include "StdAfx.h"
#include "Annotation.h"
#include "ScintillAx_dispid.h"
#include "ScintillaCtrl.h"


SciAxAnnotation::~SciAxAnnotation()
{
	ODBGS("~SciAxAnnotation");
}

SciAxAnnotation::Instance* SciAxAnnotation::CreateInstance( ScintillAx* sci)
{
	Instance* instance = new Instance;
	instance->sci_ = sci;
	return instance;

}

void SciAxAnnotation::dispose()
{
	sci_ = 0;
}

REFGUID SciAxAnnotation::getCoClassID()
{
	return IID_IScintillAxAnnotation;
}
	


HRESULT __stdcall SciAxAnnotation::SetText( long line,  BSTR txt)
{
	if (!sci_)
		return E_FAIL;

	if ( !txt )
		return this->Clear(line);

	sci_->edit()->setAnnotation( line, mol::bstr(txt).towstring() );
	sci_->edit()->setAnnotationStyle( line, SCI_ANNO_ERRORSTYLE );
	return S_OK;
}

HRESULT __stdcall SciAxAnnotation::Clear( long line)
{
	if (!sci_)
		return E_FAIL;

	sci_->edit()->clearAnnotation(line);
	return S_OK;
}

HRESULT __stdcall SciAxAnnotation::ClearAll()
{
	if (!sci_)
		return E_FAIL;

	sci_->edit()->clearAnnotations();
	return S_OK;
}

HRESULT __stdcall SciAxAnnotation::SetStyle( long line, long style)
{
	if (!sci_)
		return E_FAIL;

	sci_->edit()->setAnnotationStyle( line, style );
	return S_OK;
}


HRESULT __stdcall SciAxAnnotation::Dispose()
{
	dispose();
	return S_OK;
}