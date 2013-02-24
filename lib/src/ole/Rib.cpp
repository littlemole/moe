#include "ole/Rib.h"
#include "ole/com.h"
#include "win/shell.h"
#include <Shobjidl.h>
#include <ObjectArray.h>
#include <initguid.h>
#include <strsafe.h>


#define TWIPS_PER_POINT 20 // For setting font size in CHARFORMAT2.

DEFINE_GUID(IID_molIApplicationDocumentLists,0x3c594f9fL,0x9f30, 0x47a1, 0x97, 0x9a, 0xc9,0xe8,0x3d,0x3d,0x0a,0x06);


namespace mol
{

namespace ole
{

typedef enum MOLAPPDOCLISTTYPE
{	
	ADLT_RECENT	    = 0,
	ADLT_FREQUENT	= ( ADLT_RECENT + 1 ) 
} 	
MOLAPPDOCLISTTYPE;


class molIApplicationDocumentLists : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE SetAppID( LPCWSTR pszAppID) = 0;        
    virtual HRESULT STDMETHODCALLTYPE GetList( MOLAPPDOCLISTTYPE listtype, UINT cItemsDesired, REFIID riid, void **ppv) = 0;        
};

} // end namespace ole

template <> 
class uuid_info<mol::ole::molIApplicationDocumentLists>
{
 public:
   static REFIID uuidof; 
   typedef mol::ole::molIApplicationDocumentLists uuid_type;
};

REFIID uuid_info<mol::ole::molIApplicationDocumentLists>::uuidof = IID_molIApplicationDocumentLists;

namespace Ribbon
{

/////////////////////////////////////////////////////////////////////////////////////////////
// prop variants
/////////////////////////////////////////////////////////////////////////////////////////////

inline HRESULT InitPropVariantFromUInt32( ULONG ulVal,  PROPVARIANT *ppropvar)
{
    ppropvar->vt = VT_UI4;
    ppropvar->ulVal = ulVal;
    return S_OK;
}

inline HRESULT InitPropVariantFromString( PCWSTR psz,  PROPVARIANT *ppropvar)
{
    ppropvar->vt = VT_LPWSTR;
    HRESULT hr = SHStrDupW(psz, &ppropvar->pwszVal);
    if (FAILED(hr))
    {
        PropVariantInit(ppropvar);
    }
    return hr;
}

inline HRESULT InitPropVariantFromDecimal(const DECIMAL& decValue, PROPVARIANT* pPropVar)
{
    pPropVar->decVal = decValue;
    pPropVar->vt = VT_DECIMAL;
    return S_OK;
}

inline HRESULT InitPropVariantFromInterface(IUnknown* pUnk,  PROPVARIANT* pPropVar)
{
    pPropVar->vt = VT_UNKNOWN;
    pPropVar->punkVal = pUnk;
    if (pUnk)
    {
        pUnk->AddRef();
    }
    return S_OK;
}

inline HRESULT PropVariantToIUnknownArrayAlloc(REFPROPVARIANT propvarIn, SAFEARRAY** ppsa)
{
    return ::SafeArrayCopy(propvarIn.parray, ppsa);
}


template<class I>
HRESULT PropVariantToInterface(REFPROPVARIANT propvarIn, I** ppObj)
{
    *ppObj = NULL;
    if (propvarIn.punkVal)
    {
        return propvarIn.punkVal->QueryInterface( mol::uuidof<I>(), (void**)ppObj);
    }
    return S_OK;
}

inline HRESULT InitPropVariantFromBoolean( BOOL fVal, PROPVARIANT *ppropvar)
{
    ppropvar->vt = VT_BOOL;
    ppropvar->boolVal = fVal ? VARIANT_TRUE : VARIANT_FALSE;
    return S_OK;
}

HRESULT InitPropVariantFromIUnknownArray( SAFEARRAY* psa,  PROPVARIANT* pPropVar)
{
   HRESULT hr = ::SafeArrayCopy(psa, &pPropVar->parray);
    if (SUCCEEDED(hr))
    {
        pPropVar->vt = VT_ARRAY|VT_UNKNOWN;
    }
    return hr;
}

/////////////////////////////////////////////////////////////////////////////////////////////
// Prop Variant RIIA helper
/////////////////////////////////////////////////////////////////////////////////////////////

class PropVariant : public PROPVARIANT
{
public:

	PropVariant()
	{
		::PropVariantInit(this);

	}
	~PropVariant()
	{
		::PropVariantClear(this);
	}

	unsigned int intValue()
	{
		return this->uintVal;
	}

	unsigned long longValue()
	{
		return this->lVal;
	}

	double doubleValue()
	{
		return this->dblVal;
	}

	DECIMAL decimalValue()
	{
		return this->decVal;
	}

	mol::string stringValue()
	{
		switch(this->vt)
		{
			case VT_LPWSTR :
			{
				std::wstring ws(this->pwszVal);
				return ws;
			}
			case VT_BSTR :
			{
				mol::bstr bs(this->bstrVal);
				return bs.toString();
			}
		}
		return _T("");
	}


	template<class I>
	HRESULT QueryInterface(I** ppObj)
	{
		*ppObj = NULL;
		if (this->punkVal)
		{
			return this->punkVal->QueryInterface( mol::uuidof<I>(), (void**)ppObj);
		}
		return S_OK;
	}

	void safeArrayValue( SAFEARRAY** ppsa)
	{
		::SafeArrayCopy(this->parray, ppsa);
	}

	void initFromLong( ULONG ulVal )
	{
		this->vt = VT_UI4;
		this->ulVal = ulVal;
	}

	void initFromString( const mol::string& str )
	{
		this->vt = VT_LPWSTR;
		HRESULT hr = ::SHStrDupW( str.c_str(), &(this->pwszVal) );
		if (FAILED(hr))
		{
			PropVariantInit(this);
		}
	}


	void initFromDecimal( DECIMAL decVal )
	{
		this->vt = VT_DECIMAL;
		this->decVal = decVal;
	}

	void initFromInterface( IUnknown* pObj )
	{
		this->vt = VT_UNKNOWN;
		this->punkVal = pObj;
		if ( pObj )
		{
			pObj->AddRef();
		}
	}


	void initFromBoolean( bool b )
	{
		this->vt = VT_BOOL;
		this->boolVal = b ? VARIANT_TRUE : VARIANT_FALSE;
	}

	void initFromArray( SAFEARRAY* psa)
    {
		HRESULT hr = ::SafeArrayCopy( psa, &(this->parray) );
		if (SUCCEEDED(hr))
		{
			this->vt = VT_ARRAY|VT_UNKNOWN;
		}	 
	}

};

/////////////////////////////////////////////////////////////////////////////////////////////
// Convert IPropertyStore to CHARFORMAT2 
/////////////////////////////////////////////////////////////////////////////////////////////

void GetCharFormat2FromIPropertyStore( IPropertyStore* pPropStore, CHARFORMAT2 *pCharFormat)
{
    ZeroMemory(pCharFormat, sizeof(*pCharFormat));
    pCharFormat->cbSize = sizeof(CHARFORMAT2);
    
	{
		// Get bold value
	    PropVariant propVar;
		if ( S_OK == pPropStore->GetValue(UI_PKEY_FontProperties_Bold, &propVar) )
		{
			ULONG uValue = propVar.longValue();
			if ((UI_FONTPROPERTIES) uValue != UI_FONTPROPERTIES_NOTAVAILABLE)
			{
				pCharFormat->dwMask |= CFM_BOLD;
				pCharFormat->dwEffects |= ((UI_FONTPROPERTIES) uValue == UI_FONTPROPERTIES_SET) ? CFE_BOLD : 0;
			}
		}
	}

	{
		// Get italic value
	    PropVariant propVar;
		if ( S_OK == pPropStore->GetValue(UI_PKEY_FontProperties_Italic, &propVar) ) 
		{
			ULONG uValue = propVar.longValue();
			if ((UI_FONTPROPERTIES) uValue != UI_FONTPROPERTIES_NOTAVAILABLE)
			{
				pCharFormat->dwMask |= CFM_ITALIC;
				pCharFormat->dwEffects |= ((UI_FONTPROPERTIES) uValue == UI_FONTPROPERTIES_SET) ? CFE_ITALIC : 0;
			}
		}
	}

	{
		// Get underline value
	    PropVariant propVar;
		if (SUCCEEDED(pPropStore->GetValue(UI_PKEY_FontProperties_Underline, &propVar)))
		{
			ULONG uValue = propVar.longValue();
			if ((UI_FONTUNDERLINE) uValue != UI_FONTUNDERLINE_NOTAVAILABLE)
			{
				pCharFormat->dwMask |= CFM_UNDERLINE;
				pCharFormat->dwEffects |= ((UI_FONTUNDERLINE) uValue == UI_FONTUNDERLINE_SET) ? CFE_UNDERLINE : 0;
			}
		}
	}

	{
		// Get strikethrough value
		PropVariant propVar;
		if ( S_OK == pPropStore->GetValue(UI_PKEY_FontProperties_Strikethrough, &propVar) )
		{
			ULONG uValue = propVar.longValue();
			if ((UI_FONTPROPERTIES) uValue != UI_FONTPROPERTIES_NOTAVAILABLE)
			{
				pCharFormat->dwMask |= CFM_STRIKEOUT;
				pCharFormat->dwEffects |= ((UI_FONTPROPERTIES) uValue == UI_FONTPROPERTIES_SET) ? CFE_STRIKEOUT : 0;
			}
		}    
	}

	{
		// Get vertical positioning 
		PropVariant propVar;
		if ( S_OK == pPropStore->GetValue(UI_PKEY_FontProperties_VerticalPositioning, &propVar ) )
		{
			ULONG uValue = propVar.longValue();
			UI_FONTVERTICALPOSITION uVerticalPosition = (UI_FONTVERTICALPOSITION) uValue;
			if ((uVerticalPosition != UI_FONTVERTICALPOSITION_NOTAVAILABLE))
			{
				pCharFormat->dwMask |= (CFM_SUPERSCRIPT | CFM_SUBSCRIPT);
				if (uVerticalPosition != UI_FONTVERTICALPOSITION_NOTSET)
				{
					pCharFormat->dwEffects |= (uVerticalPosition == UI_FONTVERTICALPOSITION_SUPERSCRIPT) ? CFE_SUPERSCRIPT : CFE_SUBSCRIPT;
				}
			}
		}
	}

	{
		// Get font family 
		PropVariant propVar;
		if ( S_OK == pPropStore->GetValue(UI_PKEY_FontProperties_Family, &propVar) )
		{
			
			mol::string family = propVar.stringValue();
			if ( family != _T("") )
			{
				StringCchCopyW(pCharFormat->szFaceName, ARRAYSIZE(pCharFormat->szFaceName), family.c_str() );
				pCharFormat->dwMask |= CFM_FACE;
			}			
		}
	}

	{
		// Get font size
		PropVariant propVar;
		if ( S_OK == pPropStore->GetValue(UI_PKEY_FontProperties_Size, &propVar ) )
		{
			DECIMAL decSize = propVar.decimalValue();
			DOUBLE dSize;
			VarR8FromDec(&decSize, &dSize);
			// Zero is used as "Not Available" value.
			if (dSize > 0)
			{
				pCharFormat->dwMask |= CFM_SIZE;
				// Set the height as twips.
				pCharFormat->yHeight = (LONG)(dSize * TWIPS_PER_POINT);
			}
		}
	}

	{
		// Get font foreground color
		PropVariant propVar;
		if ( S_OK == pPropStore->GetValue(UI_PKEY_FontProperties_ForegroundColorType, &propVar ) )
		{
			ULONG uValue = propVar.longValue();
			if (UI_SWATCHCOLORTYPE_AUTOMATIC == (UI_SWATCHCOLORTYPE)uValue)
			{
				// The color type is automatic, so set the corresponding members in CharFormat2 variable.
				pCharFormat->dwMask |= CFM_COLOR;
				pCharFormat->dwEffects |= CFE_AUTOCOLOR;
			}
		}
	}

	{
		// Get font foreground color 
		PropVariant propVar;
		if (S_OK == pPropStore->GetValue(UI_PKEY_FontProperties_ForegroundColor, &propVar) )
		{
			ULONG uValue = propVar.longValue();
			pCharFormat->dwMask |= CFM_COLOR;
			pCharFormat->crTextColor = (COLORREF)uValue;
		}
	}

	{
		// Get background color type value
		PropVariant propVar;
		if ( S_OK == pPropStore->GetValue(UI_PKEY_FontProperties_BackgroundColorType, &propVar) )
		{
			ULONG uValue =propVar.longValue();
			if (UI_SWATCHCOLORTYPE_NOCOLOR == (UI_SWATCHCOLORTYPE)uValue)
			{
				// The color type is no color, so set the corresponding members in CharFormat2 variable.
				pCharFormat->dwMask |= CFM_BACKCOLOR;
				pCharFormat->dwEffects |= CFE_AUTOBACKCOLOR;
			}
		}
	}

	{
		// Get the background color 
		PropVariant propVar;
		if ( S_OK == pPropStore->GetValue(UI_PKEY_FontProperties_BackgroundColor, &propVar) )
		{
			ULONG uValue = propVar.longValue();
			pCharFormat->dwMask |= CFM_BACKCOLOR;
			pCharFormat->crBackColor = (COLORREF)uValue;
		}
	}
}


/////////////////////////////////////////////////////////////////////////////////////////////
// Convert from CHARFORMAT2 to IPropertyStore so it can be passed to the font control.
/////////////////////////////////////////////////////////////////////////////////////////////

void GetIPropStoreFromCharFormat2(const __in CHARFORMAT2* pCharFormat, __in IPropertyStore *pPropStore)
{
    
	{
		PropVariant propVar;
		if (pCharFormat->dwMask & CFM_BOLD)
		{
			// Set the bold value to UI_FONTPROPERTIES_SET or UI_FONTPROPERTIES_NOTSET.
			propVar.initFromLong((pCharFormat->dwEffects & CFE_BOLD) ? UI_FONTPROPERTIES_SET : UI_FONTPROPERTIES_NOTSET);
		}
		else
		{
			propVar.initFromLong(UI_FONTPROPERTIES_NOTAVAILABLE);
		}
		pPropStore->SetValue(UI_PKEY_FontProperties_Bold, propVar);
	}

	{
		PropVariant propVar;
		if (pCharFormat->dwMask & CFM_ITALIC)
		{
			// Set the italic value to UI_FONTPROPERTIES_SET or UI_FONTPROPERTIES_NOTSET.
			propVar.initFromLong((pCharFormat->dwEffects & CFE_ITALIC)?UI_FONTPROPERTIES_SET:UI_FONTPROPERTIES_NOTSET);
		}
		else
		{
			propVar.initFromLong(UI_FONTPROPERTIES_NOTAVAILABLE);
		}
		pPropStore->SetValue(UI_PKEY_FontProperties_Italic, propVar);
	}

	{
		PropVariant propVar;
		if (pCharFormat->dwMask & CFM_UNDERLINE)
		{
			// Set the underline value to UI_FONTUNDERLINE_SET or UI_FONTUNDERLINE_NOTSET.
			propVar.initFromLong((pCharFormat->dwEffects & CFE_UNDERLINE) ? UI_FONTUNDERLINE_SET : UI_FONTUNDERLINE_NOTSET);
		}
		else
		{
			propVar.initFromLong(UI_FONTUNDERLINE_NOTAVAILABLE);
		}
		pPropStore->SetValue(UI_PKEY_FontProperties_Underline, propVar);
	}
    
	{
		PropVariant propVar;
		if (pCharFormat->dwMask & CFM_STRIKEOUT)
		{
			// Set the strikethrough value to UI_FONTPROPERTIES_SET or UI_FONTPROPERTIES_NOTSET.
			propVar.initFromLong((pCharFormat->dwEffects & CFE_STRIKEOUT) ? UI_FONTPROPERTIES_SET : UI_FONTPROPERTIES_NOTSET);
		}
		else
		{
			propVar.initFromLong(UI_FONTPROPERTIES_NOTAVAILABLE);
		}
		pPropStore->SetValue(UI_PKEY_FontProperties_Strikethrough, propVar);
	}

	{
		PropVariant propVar;

		if (pCharFormat->dwMask & CFE_SUBSCRIPT)
		{
			if ((pCharFormat->dwMask & CFM_SUBSCRIPT) && (pCharFormat->dwEffects & CFE_SUBSCRIPT))
			{
				propVar.initFromLong(UI_FONTVERTICALPOSITION_SUBSCRIPT);
			}
			else if (pCharFormat->dwEffects & CFE_SUPERSCRIPT)
			{
				propVar.initFromLong(UI_FONTVERTICALPOSITION_SUPERSCRIPT);
			}
		}
		else if (pCharFormat->dwMask & CFM_OFFSET)
		{
			if (pCharFormat->yOffset > 0)
			{
				propVar.initFromLong(UI_FONTVERTICALPOSITION_SUPERSCRIPT);
			}
			else if (pCharFormat->yOffset < 0)
			{
				propVar.initFromLong(UI_FONTVERTICALPOSITION_SUBSCRIPT);
			}
			else
			{
				propVar.initFromLong(UI_FONTVERTICALPOSITION_NOTAVAILABLE);
			}

		}
		pPropStore->SetValue(UI_PKEY_FontProperties_VerticalPositioning, propVar);
	}

	{
		PropVariant propVar;
		if (pCharFormat->dwMask & CFM_FACE)
		{
			// Set the font family value to the font name.
			propVar.initFromString(  mol::toString(pCharFormat->szFaceName) );
		}
		else
		{
			// Font family name is not available so set it to blank string.
			propVar.initFromString(  _T("") );
		}
		pPropStore->SetValue(UI_PKEY_FontProperties_Family, propVar);
	}

	{
		PropVariant propVar;
		DECIMAL decSize;
		if (pCharFormat->dwMask & CFM_SIZE)
		{
			// Font size value is available so get the font size.
			VarDecFromR8((DOUBLE)pCharFormat->yHeight / TWIPS_PER_POINT, &decSize);
		}
		else
		{
			// The font size is not available so set it to zero.
			VarDecFromI4(0, &decSize);
		}
		// Set UI_PKEY_FontProperties_Size value in property store.
		propVar.initFromDecimal(decSize);
		pPropStore->SetValue(UI_PKEY_FontProperties_Size, propVar);
	}	

	{
		
		if ((pCharFormat->dwMask & CFM_COLOR) && !(pCharFormat->dwEffects & CFE_AUTOCOLOR))
		{
			{
				PropVariant propVar;
				// There is a color value so set the type to UI_SWATCHCOLORTYPE_RGB in property store.
				propVar.initFromLong(UI_SWATCHCOLORTYPE_RGB);
				pPropStore->SetValue(UI_PKEY_FontProperties_ForegroundColorType, propVar);
			}

			PropVariant propVar;
			// Set the color value in property store.
			propVar.initFromLong(pCharFormat->crTextColor);
			pPropStore->SetValue(UI_PKEY_FontProperties_ForegroundColor, propVar);
		}
		else if ((pCharFormat->dwMask & CFM_COLOR) && (pCharFormat->dwEffects & CFE_AUTOCOLOR))
		{
			PropVariant propVar;
			// The color is automatic color so set the type to UI_SWATCHCOLORTYPE_AUTOMATIC in property store.
			propVar.initFromLong(UI_SWATCHCOLORTYPE_AUTOMATIC);

			pPropStore->SetValue(UI_PKEY_FontProperties_ForegroundColorType, propVar);
		}
	}

	{
		
		if ((pCharFormat->dwMask & CFM_BACKCOLOR) && !(pCharFormat->dwEffects & CFE_AUTOBACKCOLOR))
		{
			{
				PropVariant propVar;
				// There is a color value so set the type to UI_SWATCHCOLORTYPE_RGB in property store.
				propVar.initFromLong(UI_SWATCHCOLORTYPE_RGB);
				pPropStore->SetValue(UI_PKEY_FontProperties_BackgroundColorType, propVar);
			}
        
			PropVariant propVar;
			// Set the color value in property store.
			propVar.initFromLong(pCharFormat->crBackColor);
			pPropStore->SetValue(UI_PKEY_FontProperties_BackgroundColor, propVar);
		}
		else
		{
			PropVariant propVar;
			// There is no color so set the type to UI_SWATCHCOLORTYPE_NOCOLOR in property store.
			propVar.initFromLong(UI_SWATCHCOLORTYPE_NOCOLOR);
			pPropStore->SetValue(UI_PKEY_FontProperties_BackgroundColorType, propVar);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////
// Proprety Set Impl
/////////////////////////////////////////////////////

PropertySet::PropertySet()
    : 
    categoryId_(UI_COLLECTION_INVALIDINDEX),
    commandId_(-1),
    commandType_(UI_COMMANDTYPE_UNKNOWN),
	pinned_(false)

{}

PropertySet::~PropertySet()
{
}

void PropertySet::InitializeCommandProperties(int categoryId, int commandId, UI_COMMANDTYPE commandType)
{
    categoryId_ = categoryId;
    commandId_ = commandId;
    commandType_ = commandType;
}

void PropertySet::InitializeItemProperties(IUIImage *image, __in PCWSTR label, int categoryId)
{
    pimgItem_ = image;
	label_ = mol::toString(label);
    categoryId_ = categoryId;
}

void PropertySet::InitializeCategoryProperties( PCWSTR label, int categoryId)
{
	label_ = mol::toString(label);
    categoryId_ = categoryId;
}

void PropertySet::InitializeRecentItem( PCWSTR label, bool pinned)
{
	label_ = mol::toString(label);
    pinned_ = pinned;
}

HRESULT __stdcall PropertySet::GetValue( REFPROPERTYKEY key, PROPVARIANT *ppropvar)
{
    if (key == UI_PKEY_ItemImage)
    {
        if (pimgItem_)
        {
			return InitPropVariantFromInterface( pimgItem_, ppropvar);
        }
        return S_FALSE;
    }
    else if (key == UI_PKEY_Label)
    {
		return InitPropVariantFromString(mol::towstring(label_).c_str(), ppropvar);
    }
    else if (key == UI_PKEY_CategoryId)
    {
		return InitPropVariantFromUInt32(categoryId_, ppropvar);
    }
    else if (key == UI_PKEY_CommandId)
    {
        if(commandId_ != -1)
        {
			return InitPropVariantFromUInt32(commandId_, ppropvar);
        }
        return S_FALSE;
    }
    else if (key == UI_PKEY_CommandType)
    {
		return InitPropVariantFromUInt32( commandType_, ppropvar);
    }
	else if (key == UI_PKEY_Pinned)
    {
		return InitPropVariantFromUInt32( pinned_, ppropvar);
    }
    return E_FAIL;
}

PropertySet::Instance* PropertySet::CreateInstance()
{
	PropertySet::Instance* ins = new PropertySet::Instance;
    return ins;
}

/////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////
// Handler Base Impl
/////////////////////////////////////////////////////

HandlerBase::HandlerBase()
	: index_(0),
	  label_(_T("")),
	  value_(_T("")),
	  bValue_(false),
	  enabled_(true),
	  decimalPlaces_(0),
	  decimal_(0)
{}

HandlerBase::~HandlerBase()
{
}

void HandlerBase::callback(int id)
{
}

HRESULT __stdcall HandlerBase::Execute( UINT nCmdID, UI_EXECUTIONVERB verb, const PROPERTYKEY* key, const PROPVARIANT* ppropvarValue, IUISimplePropertySet* pCommandExecutionProperties)
{
	if ( nCmdID == id_ )
	{
		if ( verb == UI_EXECUTIONVERB_EXECUTE )
		{
	        if (key && *key == UI_PKEY_SelectedItem)
			{
				index_ = 0;
				if ( ppropvarValue )
				{
					if ( ppropvarValue->intVal > 0 && ppropvarValue->intVal < (int)items_.size() )
						index_ = ppropvarValue->intVal;

					if ( ppropvarValue->intVal > 0 && ppropvarValue->intVal < (int)recent_items_.size() )
						index_ = ppropvarValue->intVal;

					if ( items_.size() > 0 )
					{
						value_ = items_[index_];
					}
					if ( recent_items_.size() > 0)
					{
						value_ = recent_items_[index_].first;
					}
				}				
			}
	        else if (key && *key == UI_PKEY_BooleanValue)
			{
				VARIANT_BOOL vb = ppropvarValue->boolVal;
				bValue_ = vb == VARIANT_TRUE ? true : false;
			}
	        else if (key && *key == UI_PKEY_StringValue)
			{
				value_ = mol::bstr(ppropvarValue->bstrVal).toString();
			}				
	        else if (key && *key == UI_PKEY_Label)
			{
				label_ = mol::bstr(ppropvarValue->bstrVal).toString();
			}

	        else if (key && *key == UI_PKEY_DecimalValue)
			{
				decimal_ = *((VARIANT*)(ppropvarValue));
			}
	        else if (key && *key == UI_PKEY_DecimalPlaces)
			{
				decimalPlaces_ = ppropvarValue->intVal;
			}
			else if ( key && (*key == UI_PKEY_RecentItems) && ppropvarValue && ppropvarValue->parray )
			{
				recent_items_.clear();
				int iFileCount = 0;
				LONG iCurrentFile = 0;
				HRESULT hr = E_FAIL;

				SAFEARRAY* psa = 0;
				hr = PropVariantToIUnknownArrayAlloc( *ppropvarValue, &psa );
				if ( hr == S_OK )
				{
					mol::SFAccess<IUnknown*> sfa(psa);
					
					for ( long i = 0; i < sfa.size(); i++ )
					{
						mol::punk<IUISimplePropertySet> prop(sfa[i]);
						if (!prop)
							continue;

						PropVariant pv;
						hr = prop->GetValue(UI_PKEY_Label,&pv);
						if ( hr == S_OK )
						{
							mol::bstr label(pv.bstrVal);
							bool pinned = false;
							PropVariant pinv;
							hr = prop->GetValue(UI_PKEY_Pinned,&pinv);
							if ( hr == S_OK )
							{
								pinned = pinv.boolVal == VARIANT_TRUE ? true : false;
								recent_items_.push_back( std::make_pair(label.toString(), pinned) );
							}
						}
					}
				}

			}
			else if (key && *key == UI_PKEY_FontProperties)
			{
				HRESULT hr = E_POINTER;
				if (pCommandExecutionProperties != NULL)
				{
				  // Get the changed properties.
				  PropVariant varValues;
				  hr = pCommandExecutionProperties->GetValue(UI_PKEY_FontProperties_ChangedProperties, &varValues);
				  if (SUCCEEDED(hr))
				  {
					mol::punk<IPropertyStore> store;
					hr = varValues.QueryInterface(&store);					
					if (SUCCEEDED(hr))
					{
						::ZeroMemory(&charFormat_,sizeof(charFormat_));
						charFormat_.cbSize = sizeof(CHARFORMAT2);
						GetCharFormat2FromIPropertyStore(store,&charFormat_);
					}
				  }
				}
			}
			this->callback(nCmdID);
		}

	}
	return S_OK;
}

HRESULT __stdcall HandlerBase::UpdateProperty( UINT nCmdID, REFPROPERTYKEY key, const PROPVARIANT* ppropvarCurrentValue, PROPVARIANT* ppropvarNewValue)
{
	HRESULT hr = E_FAIL;
    if (key == UI_PKEY_ItemsSource)
	{
		mol::punk<IUICollection> col(ppropvarCurrentValue->punkVal);
		if (!col)
		{
			return E_FAIL;
		}
		col->Clear();

		if ( items_.size() == 0 )
			return S_FALSE;

		for ( size_t i = 0; i < items_.size(); i++ ) 
		{
			PropertySet* pItem = PropertySet::CreateInstance();
			if (!pItem)
			{
				return E_FAIL;
			}

			pItem->InitializeItemProperties(NULL, mol::towstring(items_[i]).c_str(), UI_COLLECTION_INVALIDINDEX);
			col->Add(pItem);
		}

		return S_OK;
	}
	else if (key == UI_PKEY_Categories)
	{
		hr = S_FALSE;
		return hr;
	}
	else if (key == UI_PKEY_SelectedItem)
	{
		hr = InitPropVariantFromUInt32( index_, ppropvarNewValue);
		return hr;
	}
	else if (key == UI_PKEY_StringValue)
	{      
		hr = InitPropVariantFromString( mol::bstr(value_), ppropvarNewValue);
		return hr;
	}
	else if (key == UI_PKEY_Enabled)
	{
		hr = InitPropVariantFromBoolean( enabled_, ppropvarNewValue);
		return hr;
	}
	else if (key == UI_PKEY_BooleanValue)
	{
		hr = InitPropVariantFromBoolean( bValue_, ppropvarNewValue);
		return hr;
	}
	else if (key == UI_PKEY_Minimized)
	{
		hr = InitPropVariantFromBoolean( minimized_, ppropvarNewValue);
		return hr;
	}
    else if ( key == UI_PKEY_Label )
	{
		hr = InitPropVariantFromString( mol::bstr(label_), ppropvarNewValue);
		return hr;
	}
	else if (key == UI_PKEY_DecimalValue)
	{
		hr = InitPropVariantFromDecimal(  decimal_.decVal, ppropvarNewValue);
		return hr;
	}
    else if (key == UI_PKEY_DecimalPlaces)
	{
		hr = InitPropVariantFromUInt32(  decimalPlaces_, ppropvarNewValue);
		return hr;
	}
    else if ( key == UI_PKEY_RecentItems )
	{

		int iFileCount = (int)(recent_items_.size());
		LONG iCurrentFile = 0;
		HRESULT hr = E_FAIL;

		mol::ArrayBound ab(iFileCount);
		mol::SafeArray<VT_UNKNOWN> sa(ab);

		{
			mol::SFAccess<IUnknown*> sfa(sa);

			for ( int i = 0; i < iFileCount; i++ )
			{
				mol::string currentFile = recent_items_[i].first;
				PropertySet* pItem = PropertySet::CreateInstance();
				if (!pItem)
				{
					return E_FAIL;
				}
				pItem->InitializeRecentItem( 
							mol::towstring(currentFile).c_str(), 
							recent_items_[i].second
						);

				hr = pItem->QueryInterface(
								mol::uuidof<IUnknown>(), 
								(void**)(&sfa[i])
							);
			}
		}

		hr = InitPropVariantFromIUnknownArray( sa, ppropvarNewValue);
		return hr;
	}
	else if (key == UI_PKEY_FontProperties)
	{
		hr = E_POINTER;
		if (ppropvarCurrentValue != NULL)
		{
			hr = E_POINTER;
			// Get the font values for the selected text in the font control.
			mol::punk<IPropertyStore> pValues;
			hr = PropVariantToInterface( *ppropvarCurrentValue, &pValues);
			if (SUCCEEDED(hr))
			{
				GetIPropStoreFromCharFormat2(&charFormat_, pValues);
				hr = InitPropVariantFromInterface(pValues, ppropvarNewValue);
			}
		}
	}
	return E_NOTIMPL;
}

CHARFORMAT2& HandlerBase::font()
{
	return charFormat_;
}

std::vector<mol::string> HandlerBase::items()
{
	return items_;
}

std::vector<std::pair<mol::string,bool> > HandlerBase::recent_items()
{
	return recent_items_;
}

void HandlerBase::items( const std::vector<mol::string>& items, int index )
{
	index_ = index;
	items_ = items;
	ribbon()->update(id_);
}

void HandlerBase::recent_item( std::pair<mol::string,bool>& item)
{
	
	for ( size_t i = 0; i < recent_items_.size(); i++ )
	{
		if ( recent_items_[i].first == item.first )
			return;
	}
	
	if ( recent_items_.size() > 9 )
	{
		std::vector<std::pair<mol::string,bool> > tmp;
		std::vector<std::pair<mol::string,bool> >::iterator it = recent_items_.begin();
		bool f = false;
		for ( size_t i = 0; i < 9; i++ )
		{
			if ( !f && recent_items_[i].second == false )
			{
				f = true;
				continue;
			}
			tmp.push_back( recent_items_[i] );
		}	
		if ( f  )
			tmp.push_back( recent_items_[9] );

		recent_items_.swap(tmp);
	}

	recent_items_.push_back(item);
	ribbon()->update(id_);
}

int HandlerBase::cmd()			
{ 
	return id_; 
}

int HandlerBase::decimalPlaces()			
{ 
	return decimalPlaces_; 
}

mol::variant HandlerBase::decimal()
{
	return decimal_; 
}

mol::string HandlerBase::value() 
{ 
	return value_; 
}

mol::string HandlerBase::label() 
{ 
	return label_; 
}

bool HandlerBase::enabled()		
{ 
	return enabled_; 
}

int HandlerBase::index()			
{ 
	return index_; 
}

bool HandlerBase::checked()		
{ 
	return bValue_; 
}

bool HandlerBase::minimized()		
{ 
	return minimized_; 
}

void HandlerBase::decimalPlaces(int i)			
{ 
	decimalPlaces_ = i; 
	ribbon()->update(id_);
}

void HandlerBase::decimal(mol::variant& v)
{
	decimal_ = v;
	ribbon()->update(id_);
}

void HandlerBase::minimize(bool b) 
{ 
	minimized_ = b; 
	ribbon()->update(id_);
}

void HandlerBase::checked(bool b) 
{ 
	bValue_ = b; 
	ribbon()->update(id_);
}

void HandlerBase::select(int index)
{
	index_ = index;
	value_ = items_[index];
	ribbon()->update(id_);
}

void HandlerBase::value( const mol::string& v)
{
	value_ = v;
	ribbon()->update(id_);
}

void HandlerBase::label( const mol::string& l)
{
	label_ = l;
	ribbon()->update(id_);
}

void HandlerBase::bValue( bool b)
{
	bValue_ = b;
	ribbon()->update(id_);
}

void HandlerBase::check( bool b)
{
	bValue_ = b;
	ribbon()->update(id_);
}

void HandlerBase::enable( bool b)
{
	enabled_ = b;
	ribbon()->update(id_);
}


/////////////////////////////////////////////////////
// Handler Registry Impl
/////////////////////////////////////////////////////

void HandlerRegistry::dispose()
{
	for ( std::map<int,HandlerBase*>::iterator it = registry_.begin(); it != registry_.end(); it++ )
	{
		(*it).second->Release();
	}
	registry_.clear();
}

/////////////////////////////////////////////////////
// RibbonCommand Impl
/////////////////////////////////////////////////////


RibbonCommand::RibbonCommand(HWND wnd, int i, int c)
	: wnd_(wnd),rid_(i), cid_(c)
{
	mol::Ribbon::registry()->RegisterHandler(i,this,&RibbonCommand::handler);
}

RibbonCommand::~RibbonCommand()
{}

void RibbonCommand::handler(int id)
{
	command(cid_);
}

void RibbonCommand::notify(int id, int code)
{
	NMTOOLBAR tb;
	::ZeroMemory(&tb,sizeof(tb));

	tb.hdr.idFrom = id;
	tb.hdr.code = code;
	tb.iItem = id;
	::SendMessage(wnd_,WM_NOTIFY,id,(LPARAM)&tb);
}


void RibbonCommand::command(int id)
{
	::PostMessage(wnd_,WM_COMMAND,id,0);
}



RibbonNotify::RibbonNotify(HWND wnd, int i, int c, int n)
	: RibbonCommand(wnd,i,c), nid_(n)
{}

RibbonNotify::~RibbonNotify()
{}

void RibbonNotify::handler(int id)
{
	notify(cid_,nid_);
}



/////////////////////////////////////////////////////
// Ribbon Impl
/////////////////////////////////////////////////////

Ribbon::Ribbon() 
{}

Ribbon::~Ribbon() 
{
}


HRESULT __stdcall  Ribbon::OnViewChanged(UINT32 nViewID, UI_VIEWTYPE typeID, IUnknown* pView, UI_VIEWVERB verb, INT32 uReasonCode)
{
    HRESULT hr = E_FAIL;
    switch (verb)
    {
	    case UI_VIEWVERB_SIZE:
			::InvalidateRect(wnd_, NULL, TRUE);
			mol::win::WndProc* w = mol::wndFromHWND<mol::win::WndProc>(wnd_);
			if ( w )
			{
				w->OnLayout(0,0,0);
			}
			hr = S_OK;
        break;
    }
    return hr;
}

HRESULT __stdcall   Ribbon::OnCreateUICommand(UINT32 nCmdID, UI_COMMANDTYPE typeID, IUICommandHandler** ppCommandHandler)
{
	HandlerBase* h = handler(nCmdID);
	if ( h == 0 )
		return E_NOTIMPL;

	return h->QueryInterface( mol::uuidof<IUICommandHandler>(), (void**)ppCommandHandler);
}

HRESULT __stdcall   Ribbon::OnDestroyUICommand(UINT32 commandId, UI_COMMANDTYPE typeID, IUICommandHandler* pCommandHandler)
{
    return E_NOTIMPL;
}


void Ribbon::dispose()
{
}


bool Ribbon::tearDown()
{

	if ( !ribbon )
		return false;

	// protect our instance from being released to early
	// but get rid off the ribbon
	mol::punk<IUIApplication> ui(this);
	ribbon->Destroy();
	ribbon.release();
	
	return true;
}

struct HSVType
{
	int h,s,v;
};

HSVType toHSV(int r, int g, int b)
{
HSVType hsv;

double min,max,delta,temp;
	min = std::min(r,std::min(g,b));	
	max = std::max(r,std::max(g,b));
	delta = max - min;
	
	hsv.v = (int)max;
	if(!delta)
	{
		hsv.h = hsv.s = 0;
	}
	else
	{
		temp = delta/max;
		hsv.s = (int)(temp*255);

		if(r == (int)max)
		{
			temp = (double)(g-b)/delta;
		}
		else
		if(g == (int)max)
		{
			temp = 2.0 + ((double)(b-r)/delta);
		}
		else
		{
			temp = 4.0 + ((double)(r-g)/delta);
		}
		temp *= 60;
		if(temp < 0)
		{
			temp+=360;
		}
		if(temp == 360)
		{
			temp = 0;
		}
		hsv.h = (int)temp;
	}
	return hsv;
}

void Ribbon::setColor( COLORREF fore, COLORREF back, COLORREF text)
{
	HSVType hsv = toHSV( GetRValue(back),GetGValue(back),GetBValue(back) ); 
	UI_HSBCOLOR BackgroundColor = UI_HSB(hsv.h, hsv.s, hsv.v);

	hsv = toHSV( GetRValue(fore),GetGValue(fore),GetBValue(fore) );
	UI_HSBCOLOR ForegroundColor = UI_HSB(hsv.h, hsv.s, hsv.v);

	hsv = toHSV( GetRValue(text),GetGValue(text),GetBValue(text) );
	UI_HSBCOLOR textColor = UI_HSB(hsv.h, hsv.s, hsv.v);

	setColorHSV(ForegroundColor,BackgroundColor,textColor);
}

void Ribbon::setColorHSV( UI_HSBCOLOR foreGround, UI_HSBCOLOR backGround, UI_HSBCOLOR text)
{
	if(!ribbon)
		return;

	mol::punk<IPropertyStore> spPropertyStore;

    if (S_OK != ribbon->QueryInterface(&spPropertyStore) )
		return;

	PROPVARIANT propvarHighlight;
    PROPVARIANT propvarBackground;
    PROPVARIANT propvarText;
 
    InitPropVariantFromUInt32(backGround, &propvarBackground);
    InitPropVariantFromUInt32(text, &propvarText);
	InitPropVariantFromUInt32(foreGround, &propvarHighlight);
 
    spPropertyStore->SetValue(UI_PKEY_GlobalBackgroundColor, propvarBackground);
	spPropertyStore->SetValue(UI_PKEY_GlobalHighlightColor, propvarHighlight);
    spPropertyStore->SetValue(UI_PKEY_GlobalTextColor, propvarText);
 
    spPropertyStore->Commit();
}

void Ribbon::setDefaultColor()
{

    DWORD col = GetSysColor(COLOR_MENU);
	HSVType hsv = toHSV( GetRValue(col),GetGValue(col),GetBValue(col) );
	UI_HSBCOLOR BackgroundColor = UI_HSB(hsv.h, hsv.s, hsv.v);


	col = GetSysColor(COLOR_MENUTEXT);
	hsv = toHSV( GetRValue(col),GetGValue(col),GetBValue(col) );
	UI_HSBCOLOR ForegroundColor = UI_HSB(hsv.h, hsv.s, hsv.v);

	col = GetSysColor(COLOR_WINDOW);
	hsv = toHSV( GetRValue(col),GetGValue(col),GetBValue(col) );
	UI_HSBCOLOR HighlightColor = UI_HSB(hsv.h, hsv.s, hsv.v);

	setColorHSV(HighlightColor,BackgroundColor,ForegroundColor);
}



void Ribbon::updateRecentDocs(int id)
{
	if (!ribbon )
		return;

	mol::punk<mol::ole::molIApplicationDocumentLists> appDocLists;
	HRESULT hr = appDocLists.createObject(CLSID_ApplicationDocumentLists);
	if ( hr != S_OK )
		return;

	mol::punk<IObjectArray> objects; 
	hr = appDocLists->GetList( mol::ole::ADLT_RECENT, 10, IID_IObjectArray,(void**)&objects);

	if ( hr != S_OK || !objects )
		return;

	unsigned int cnt = 0;
	hr = objects->GetCount(&cnt);
	for ( unsigned int i = 0; i < cnt; i++) 
	{
		mol::punk<IUnknown> unk;
		hr = objects->GetAt(i,IID_IUnknown,(void**)(&unk));
		if ( hr != S_OK ) 
			break;

		mol::punk<IShellItem> shit(unk);
		if ( !shit )
			continue;

		wchar_t* buf = 0;
		hr = shit->GetDisplayName(SIGDN_FILESYSPATH,&buf);
		if ( hr != S_OK )
			continue;

		mol::string path(buf);
		::CoTaskMemFree(buf);
		mol::Ribbon::ribbon()->addRecentDoc(id,path);
	}
}

void Ribbon::addRecentDoc( int id, const mol::string& path)
{
	if (!ribbon )
		return;

	mol::Ribbon::handler(id)->recent_item( std::make_pair(path,false) );
}


bool Ribbon::show(HWND hwnd)
{
	if ( ribbon )
		return false;

	wnd_ = hwnd;

    HRESULT hr = E_FAIL;
	
	hr = ribbon.createObject(CLSID_UIRibbonFramework);
	if (FAILED(hr))
		return false;

	mol::punk<IUIApplication> p(this);
    if (!p)
        return false;

    hr = ribbon->Initialize(wnd_, p);
    if (FAILED(hr))
        return false;

	hr = ribbon->LoadUI(::GetModuleHandle(0), L"APPLICATION_RIBBON");
    if (FAILED(hr))
        return false;
	
	setDefaultColor();
    return true;
}


void Ribbon::update(int id, UI_INVALIDATIONS what)
{
	if ( !ribbon )
		return;

	HRESULT hr = ribbon->InvalidateUICommand(id, what,0);
}

void Ribbon::flush()
{
	if ( !ribbon )
		return;

	HRESULT hr = ribbon->FlushPendingInvalidations();
}

bool Ribbon::load(IStorage* s)
{
	if (!ribbon )
		return false;

	// load ribbon state
	punk<IStream> stream;
	HRESULT hr =s->OpenStream( L"Ribbon", NULL, STGM_DIRECT|STGM_SHARE_EXCLUSIVE,0,&stream);
	if ( !stream || (hr != S_OK) )
	{
		return false;
	}

	mol::punk<IUIRibbon> rib;
	hr = mol::Ribbon::ribbon()->ribbon->GetView(0,mol::uuidof<IUIRibbon>(),(void**)&rib);
	if ( hr != S_OK )
	{
		return false;
	}

	hr = rib->LoadSettingsFromStream(stream);
	if ( hr != S_OK )
	{
		return false;
	}

	return true;
}

bool Ribbon::save(IStorage* storage)
{
	if (!ribbon )
		return false;

	HRESULT hr;
	mol::punk<IStream> s;
	hr = storage->CreateStream( L"Ribbon", STGM_CREATE|STGM_READWRITE|STGM_SHARE_EXCLUSIVE, 0,0,&s);
	if ( (hr != S_OK) || !s)
		return false;

	mol::punk<IUIRibbon> rib;
	hr = mol::Ribbon::ribbon()->ribbon->GetView(0,mol::uuidof<IUIRibbon>(),(void**)&rib);
	if ( hr != S_OK )
		return false;

	hr = rib->SaveSettingsToStream(s);
	if ( hr != S_OK )
		return false;

	return true;
}


UINT Ribbon::height()
{
	UINT ribbonHeight = 0;
	if (ribbon)
	{
		mol::punk<IUIRibbon> pRibbon;    
		ribbon->GetView(0, mol::uuidof<IUIRibbon>(), (void**)(&pRibbon));
		if ( pRibbon )
			pRibbon->GetHeight(&ribbonHeight);    
	}
	return ribbonHeight;
}

bool Ribbon::enabled()
{
	return ribbon.interface_ != 0;
}

void Ribbon::mode(int i)
{
	if (!ribbon )
		return;

	ribbon->SetModes(UI_MAKEAPPMODE(0)|UI_MAKEAPPMODE(i) );
}

void Ribbon::minimize()
{
    if ( !ribbon )
		return;

	mol::punk<IUIRibbon> rib;
	ribbon->GetView( 0, mol::uuidof<IUIRibbon>(), (void**)&rib);

	if (!rib)
		return;

	mol::punk<IPropertyStore> pPropertyStore(rib);
	if ( !pPropertyStore)
		return;

    PROPVARIANT propvar;
    PropVariantInit(&propvar);
	InitPropVariantFromBoolean(true, &propvar);
	HRESULT hr = pPropertyStore->SetValue(UI_PKEY_Minimized, propvar);
	if ( hr != S_OK )
		return;

    pPropertyStore->Commit();
}

void Ribbon::maximize()
{
    if ( !ribbon )
		return;

	mol::punk<IUIRibbon> rib;
	ribbon->GetView( 0, mol::uuidof<IUIRibbon>(), (void**)&rib);

	if (!rib)
		return;

	mol::punk<IPropertyStore> pPropertyStore(rib);
	if ( !pPropertyStore)
		return;

    PROPVARIANT propvar;
    PropVariantInit(&propvar);
	InitPropVariantFromBoolean(false, &propvar);
    HRESULT hr = pPropertyStore->SetValue(UI_PKEY_Minimized, propvar);
	if ( hr != S_OK )
		return;

    pPropertyStore->Commit();
}

bool Ribbon::showContextualUI(int id, int x, int y)
{
	if ( !ribbon )
		return false;

	mol::punk<IUIContextualUI> pContextualUI;
	if (S_OK == ribbon->GetView( id, mol::uuidof<IUIContextualUI>(), (void**)&pContextualUI))		
	{
		HRESULT hr = pContextualUI->ShowAtLocation(x, y);
		return hr == S_OK;
	}
	return false;
}


} // end namespace Ribbon
} // end namespace mol