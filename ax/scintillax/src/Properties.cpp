#include "StdAfx.h"
#include "Properties.h"
#include "ScintillAx_dispid.h"
#include "ScintillaCtrl.h"

SciAxProperties::SciAxProperties()
{
	FONTDESC fd;
	::ZeroMemory(&fd,sizeof(fd));
	fd.cbSizeofstruct = sizeof(fd);
	fd.cySize.int64 = 10 * 10000;
	fd.lpstrName = L"Courier New";

	enc_  = SCINTILLA_ENCODING_ANSI;
	eol_  = SCINTILLA_SYSTYPE_UNIX;
	vbContext_  = VARIANT_TRUE;		
	vbWriteBOM_ = VARIANT_FALSE;
	vbReadOnly_ = VARIANT_FALSE;

	vbTabUsage_			  = VARIANT_TRUE;
	vbTabIndents_		  = VARIANT_TRUE;
	vbBackSpaceUnindents_ = VARIANT_TRUE;
	tabWidth_ = 4;

	vbContext_ = VARIANT_TRUE;
	vbOverType_   = VARIANT_FALSE;

	syntax_ = SCINTILLA_SYNTAX_PLAIN;

}

SciAxProperties::~SciAxProperties()
{
	ODBGS("~SciAxProperties");

}

SciAxProperties::Instance* SciAxProperties::CreateInstance( ScintillAx* sci)
{
	Instance* instance = new Instance;
	instance->sci_ = sci;
	return instance;
}

void SciAxProperties::dispose()
{
	sci_ = 0;
}

REFGUID SciAxProperties::getCoClassID()
{
	return IID_IScintillAxProperties;
}
	

///////////////////////////////////////////////////////////////////////////////
// COM interfaces
///////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// Properties
//////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxProperties::put_Filename( BSTR filename)
{ 
	filename_ = filename;

	std::wstring p( mol::towstring(filename));

	if ( sci_ )
	{
		sci_->fire( DISPID_ISCINTILLAXEVENTS_ONFILENAMECHANGED,
				mol::bstr( mol::Path::filename(p)),
				filename_ );
	}
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxProperties::get_Filename( BSTR* filename)
{ 
	if ( filename )
		*filename = ::SysAllocString(this->filename_.bstr_);
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxProperties::get_ReadOnly	( VARIANT_BOOL* vb )
{
	if (!sci_)
		return E_FAIL;

	if ( vb )
	{
		if ( sci_->edit() ) 
		{
			bool b = false;
			sci_->edit()->getReadOnly(b);
			if ( b )
				vbReadOnly_ = VARIANT_TRUE;
			else
				vbReadOnly_ = VARIANT_FALSE;
		}

		*vb = vbReadOnly_;
	}
	return S_OK;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxProperties::put_ReadOnly	( VARIANT_BOOL vb  )
{
	if (!sci_)
		return E_FAIL;

	vbReadOnly_ = vb;

	if ( sci_->edit() ) 
	{
		if ( vb == VARIANT_TRUE )
			sci_->edit()->setReadOnly(true);
		else
			sci_->edit()->setReadOnly(false);
	}

	return S_OK;
}
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxProperties::put_Syntax( long type)
{ 
	if (!sci_)
		return E_FAIL;

	sci_->edit()->mode((SCINTILLA_SYNTAX)type,10,_T("Courier New"));

	if (!styleSets_) 
	{
		styleSets_.createObject(CLSID_ScintillAxStyleSets);
		mol::punk<IPersistStreamInit> psi(styleSets_);
		if ( psi )
		{
			psi->InitNew();
		}
	}

	mol::punk<IScintillAxStyleSet> set;
	styleSets_->Item( mol::variant(type), &set);
	if ( set )
	{
		sci_->Apply(set);
	}

	sci_->fire(DISPID_ISCINTILLAXEVENTS_ONSYNTAX,type);

	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxProperties::get_Syntax( long* type)
{ 
	if (!sci_)
		return E_FAIL;

	if ( type )
	{
		if ( sci_->edit() )
		{
			syntax_ = sci_->edit()->mode();
		}
		*type = (long)syntax_;
	}
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxProperties::put_SysType( long type)
{ 
	if (!sci_)
		return E_FAIL;

	if ( type == 0 )
		this->eol_ = SCINTILLA_SYSTYPE_UNIX;
	else
		this->eol_ = SCINTILLA_SYSTYPE_WIN32;

	sci_->fire(DISPID_ISCINTILLAXEVENTS_ONSYSTEM,type);
	return S_OK; 
} 

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxProperties::get_SysType( long* type)
{ 
	if ( type )
	{
		if ( this->eol_ == SCINTILLA_SYSTYPE_UNIX )
			*type = SCINTILLA_SYSTYPE_UNIX;
		else
			*type = SCINTILLA_SYSTYPE_WIN32;
	}
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxProperties::put_Encoding( long type)
{ 
	if (!sci_)
		return E_FAIL;

	this->enc_ = type;	

	if ( type == SCINTILLA_ENCODING_UTF16 )
		this->put_WriteBOM(VARIANT_TRUE);
	else
		this->put_WriteBOM(VARIANT_FALSE);

	sci_->fire(DISPID_ISCINTILLAXEVENTS_ONENCODING,type);
	
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxProperties::get_Encoding( long* type)
{ 
	if ( type )
		*type = this->enc_;
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxProperties::put_TabUsage( VARIANT_BOOL vbTabUsage)
{ 
	if (!sci_)
		return E_FAIL;

	vbTabUsage_ = vbTabUsage;

	if ( sci_->edit() )
	{
		if ( vbTabUsage == VARIANT_TRUE )
			sci_->edit()->setUseTabs(true);
		else
			sci_->edit()->setUseTabs(false);

		sci_->fire(DISPID_ISCINTILLAXEVENTS_ONTABUSAGE, vbTabUsage_);
	}

	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxProperties::get_TabUsage( VARIANT_BOOL* vbTabUsage)
{ 
	if (!sci_)
		return E_FAIL;

	if ( vbTabUsage )
	{
		if ( sci_->edit() )
		{
			bool b = false;
			b = sci_->edit()->getUseTabs() != 0;
			if ( b )
				vbTabUsage_ = VARIANT_TRUE;
			else
				vbTabUsage_ = VARIANT_FALSE;
		}

		*vbTabUsage = vbTabUsage_;
	}
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxProperties::put_TabIndents( VARIANT_BOOL vbTabIndents)
{ 
	if (!sci_)
		return E_FAIL;

	vbTabIndents_ = vbTabIndents;

	if ( sci_->edit() )
	{
		if ( vbTabIndents == VARIANT_TRUE )
			sci_->edit()->setTabIndents(true);
		else
			sci_->edit()->setTabIndents(false);

		sci_->fire(DISPID_ISCINTILLAXEVENTS_ONTABINDENTS, vbTabIndents_);
	}

	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxProperties::get_TabIndents( VARIANT_BOOL* vbTabIndents)
{ 
	if (!sci_)
		return E_FAIL;

	if ( vbTabIndents )
	{
		if ( sci_->edit() )
		{
			bool b = false;
			b = sci_->edit()->getTabIndents() != 0;
			if ( b )
				vbTabIndents_ = VARIANT_TRUE;
			else
				vbTabIndents_ = VARIANT_FALSE;
		}

		*vbTabIndents = vbTabIndents_;
	}
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxProperties::put_BackSpaceUnindents( VARIANT_BOOL vbBackSpaceUnindents)
{ 
	if (!sci_)
		return E_FAIL;

	vbBackSpaceUnindents_ = vbBackSpaceUnindents;

	if ( sci_->edit() )
	{
		if ( vbBackSpaceUnindents == VARIANT_TRUE )
			sci_->edit()->setBackSpaceUnindents(true);
		else
			sci_->edit()->setBackSpaceUnindents(false);

		sci_->fire(DISPID_ISCINTILLAXEVENTS_ONBACKSPACEUNINDENTS, vbBackSpaceUnindents_);
	}

	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxProperties::get_BackSpaceUnindents( VARIANT_BOOL* vbBackSpaceUnindents)
{ 
	if (!sci_)
		return E_FAIL;

	if ( vbBackSpaceUnindents )
	{
		if ( sci_->edit() )
		{
			bool b = false;
			b = sci_->edit()->getBackSpaceUnindents() != 0;
			if ( b )
				*vbBackSpaceUnindents = VARIANT_TRUE;
			else
				*vbBackSpaceUnindents = VARIANT_FALSE;
		}

		*vbBackSpaceUnindents = vbBackSpaceUnindents_;
	}
	return S_OK; 
}
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxProperties::put_TabWidth( long width)
{ 
	if (!sci_)
		return E_FAIL;

	tabWidth_ = width;

	if ( sci_->edit() )
	{
		sci_->edit()->setTabWidth(width);

		sci_->fire(DISPID_ISCINTILLAXEVENTS_ONTABWIDTH, tabWidth_);
	}
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxProperties::get_TabWidth( long* width)
{ 	
	if ( sci_->edit() )
		tabWidth_ = (long)sci_->edit()->getTabWidth();

	*width = tabWidth_;
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxProperties::put_Overtype( VARIANT_BOOL vbOvertype)
{ 
	if (!sci_)
		return E_FAIL;

	vbOverType_ = vbOvertype;

	if ( sci_->edit() )
	{
		if ( vbOvertype == VARIANT_TRUE )
			sci_->edit()->setOvertype(true);
		else
			sci_->edit()->setOvertype(false);
	}
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxProperties::get_Overtype( VARIANT_BOOL* vbOvertype)
{ 
	if (!sci_)
		return E_FAIL;

	if ( vbOvertype )
	{
		if ( sci_->edit() )
		{
			bool b = false;
			b = sci_->edit()->getOvertype() != 0;
			if ( b )
				*vbOvertype = VARIANT_TRUE;
			else
				*vbOvertype = VARIANT_FALSE;
		}

		*vbOvertype = vbOverType_;
	}
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxProperties::put_UseContext(VARIANT_BOOL vbContext)
{ 
	if (!sci_)
		return E_FAIL;

	vbContext_ = vbContext;

	if ( sci_->edit() )
	{
		if ( vbContext == VARIANT_TRUE )
			sci_->edit()->setUsePopUp(true);
		else
			sci_->edit()->setUsePopUp(false);
	}

	return S_OK; 
}

HRESULT __stdcall SciAxProperties::get_UseContext(VARIANT_BOOL* vbContext)
{ 
	if ( vbContext )
	{
		*vbContext = vbContext_;
	}
	return S_OK; 
}


HRESULT __stdcall SciAxProperties::put_WriteBOM( VARIANT_BOOL vb)
{
	vbWriteBOM_ = vb;
	sci_->fire(DISPID_ISCINTILLAXEVENTS_ONWRITEBOM, vbWriteBOM_);
	return S_OK;
}

HRESULT __stdcall SciAxProperties::get_WriteBOM( VARIANT_BOOL* vb)
{
	if ( !vb)
		return E_INVALIDARG;

	*vb = vbWriteBOM_;

	return S_OK;
}


HRESULT __stdcall SciAxProperties::SyntaxDisplayName(BSTR* syntax)
{
	if (!syntax)
		return E_INVALIDARG;

	if (!sci_)
		return E_FAIL;

	*syntax = ::SysAllocString( mol::towstring(sci_->edit()->SyntaxDisplayName()).c_str() );
	return S_OK;
}

HRESULT __stdcall SciAxProperties::GetSyntaxDisplayName(long type, BSTR* syntax)
{
	if (!syntax)
		return E_INVALIDARG;

	if (!sci_)
		return E_FAIL;


	*syntax = ::SysAllocString( mol::towstring(sci_->edit()->SyntaxDisplayName(type)).c_str() );
	return S_OK;
}

HRESULT __stdcall SciAxProperties::SetIndent(long i)
{ 
	if (!sci_)
		return E_FAIL;

	sci_->edit()->setIndent(i);
	return S_OK; 
}

HRESULT __stdcall SciAxProperties::ConvertTabs()
{ 
	if (!sci_)
		return E_FAIL;

	std::string what = "\t";
	std::string with = "";
	int n = (int)sci_->edit()->getTabWidth();
    for ( int i = 0; i < n; i++ )
        with +=" ";
	std::string utf8what(mol::toUTF8(what));
	std::string utf8with(mol::toUTF8(with));

    int c = 0;
	while ( sci_->edit()->replace( mol::tostring(utf8what), mol::tostring(utf8with), FR_DOWN|FR_REPLACEALL ) )
    {
        c++;
    }
	std::wostringstream oss;
	oss << c << _T(" replaces");
	::MessageBox( *sci_,oss.str().c_str(),_T("replace result:"),MB_APPLMODAL);

	return S_OK; 
}



///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall SciAxProperties::put_ShowLineNumbers(VARIANT_BOOL useLineNums)
{
	if (!sci_)
		return E_FAIL;

	bool b = useLineNums == VARIANT_TRUE ? true : false;
	sci_->edit()->showLineNumbers(b);

	sci_->fire(DISPID_ISCINTILLAXEVENTS_ONSHOWLINENUMBERS, useLineNums);

	return S_OK;
}

HRESULT __stdcall SciAxProperties::get_ShowLineNumbers(VARIANT_BOOL* useLineNums)
{
	if ( !useLineNums )
		return E_INVALIDARG;

	if (!sci_)
		return E_FAIL;

	bool b = sci_->edit()->showLineNumbers();
	*useLineNums = b == true ? VARIANT_TRUE :VARIANT_FALSE;
	return S_OK;
}

HRESULT __stdcall SciAxProperties::GetClassID( CLSID *pClassID) 
{ 
	*pClassID = IID_IScintillAxProperties; 
	return S_OK; 
};

HRESULT __stdcall SciAxProperties::IsDirty( ) 
{ 
	return S_OK; 
}

HRESULT __stdcall SciAxProperties::GetSizeMax( ULARGE_INTEGER* ui ) 
{ 
	return E_NOTIMPL;
}


HRESULT __stdcall SciAxProperties::Dispose()
{
	dispose();
	return S_OK;
}

HRESULT  __stdcall SciAxProperties::put_StyleSets( IScintillAxStyleSets* styles)
{
	if (!styles)
		return E_INVALIDARG;

	styleSets_ = styles;
	return S_OK;
}

HRESULT  __stdcall SciAxProperties::get_StyleSets( IScintillAxStyleSets** styles)
{
	if (!styles)
		return E_INVALIDARG;

	return styleSets_.queryInterface(styles);
}

HRESULT __stdcall  SciAxProperties::InitNew()
{
	mol::punk<IPersistStreamInit> psi(styleSets_);
	if ( psi)
	{
		return psi->InitNew();
	}
	return S_OK;
}