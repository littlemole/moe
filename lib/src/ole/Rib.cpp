#include "ole/Rib.h"
#include "ole/com.h"
#include "win/shell.h"
#include <uiribbonpropertyhelpers.h>
#include <Shobjidl.h>
#include <ObjectArray.h>
#include <initguid.h>
//#include "PropertyStore.h"
#include <UIRibbonPropertyHelpers.h>
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


// Convert from IPropertyStore to CHARFORMAT2 so it can be used formatting text.
void GetCharFormat2FromIPropertyStore(__in IPropertyStore* pPropStore, __out CHARFORMAT2 *pCharFormat)
{
    // Initialize the output parameter.
    ZeroMemory(pCharFormat, sizeof(*pCharFormat));
    pCharFormat->cbSize = sizeof(CHARFORMAT2);
    
    PROPVARIANT propvar;
    PropVariantInit(&propvar);
    UINT uValue;

    // Get the bold value from the property store.
    if (SUCCEEDED(pPropStore->GetValue(UI_PKEY_FontProperties_Bold, &propvar)))
    {
        UIPropertyToUInt32(UI_PKEY_FontProperties_Bold, propvar, &uValue);
        if ((UI_FONTPROPERTIES) uValue != UI_FONTPROPERTIES_NOTAVAILABLE)
        {
            // There is a value assigned, so set the corresponding members in CharFormat2 variable.
            pCharFormat->dwMask |= CFM_BOLD;
            pCharFormat->dwEffects |= ((UI_FONTPROPERTIES) uValue == UI_FONTPROPERTIES_SET) ? CFE_BOLD : 0;
        }
    }
    PropVariantClear(&propvar);

    // Get the italic value from the property store.
    if (SUCCEEDED(pPropStore->GetValue(UI_PKEY_FontProperties_Italic, &propvar)))
    {
        UIPropertyToUInt32(UI_PKEY_FontProperties_Italic, propvar, &uValue);
        if ((UI_FONTPROPERTIES) uValue != UI_FONTPROPERTIES_NOTAVAILABLE)
        {
            // There is a value assigned, so set the corresponding members in CharFormat2 variable.
            pCharFormat->dwMask |= CFM_ITALIC;
            pCharFormat->dwEffects |= ((UI_FONTPROPERTIES) uValue == UI_FONTPROPERTIES_SET) ? CFE_ITALIC : 0;
        }
    }
    PropVariantClear(&propvar);

    // Get the underline value from the property store.
    if (SUCCEEDED(pPropStore->GetValue(UI_PKEY_FontProperties_Underline, &propvar)))
    {
        UIPropertyToUInt32(UI_PKEY_FontProperties_Underline, propvar, &uValue);
        if ((UI_FONTUNDERLINE) uValue != UI_FONTUNDERLINE_NOTAVAILABLE)
        {
            // There is a value assigned, so set the corresponding members in CharFormat2 variable.
            pCharFormat->dwMask |= CFM_UNDERLINE;
            pCharFormat->dwEffects |= ((UI_FONTUNDERLINE) uValue == UI_FONTUNDERLINE_SET) ? CFE_UNDERLINE : 0;
        }
    }
    PropVariantClear(&propvar);

    // Get the strikethrough value from the property store.
    if (SUCCEEDED(pPropStore->GetValue(UI_PKEY_FontProperties_Strikethrough, &propvar)))
    {
        UIPropertyToUInt32(UI_PKEY_FontProperties_Strikethrough, propvar, &uValue);
        if ((UI_FONTPROPERTIES) uValue != UI_FONTPROPERTIES_NOTAVAILABLE)
        {
            // There is a value assigned, so set the corresponding members in CharFormat2 variable.
            pCharFormat->dwMask |= CFM_STRIKEOUT;
            pCharFormat->dwEffects |= ((UI_FONTPROPERTIES) uValue == UI_FONTPROPERTIES_SET) ? CFE_STRIKEOUT : 0;
        }
    }    
    PropVariantClear(&propvar);

    // Get the vertical positioning value from the property store.
    if (SUCCEEDED(pPropStore->GetValue(UI_PKEY_FontProperties_VerticalPositioning, &propvar)))
    {
        UIPropertyToUInt32(UI_PKEY_FontProperties_VerticalPositioning, propvar, &uValue);
        UI_FONTVERTICALPOSITION uVerticalPosition = (UI_FONTVERTICALPOSITION) uValue;
        if ((uVerticalPosition != UI_FONTVERTICALPOSITION_NOTAVAILABLE))
        {
            // There is a value assigned, so set the corresponding members in CharFormat2 variable.
            pCharFormat->dwMask |= (CFM_SUPERSCRIPT | CFM_SUBSCRIPT);
            if (uVerticalPosition != UI_FONTVERTICALPOSITION_NOTSET)
            {
                pCharFormat->dwEffects |= (uVerticalPosition == UI_FONTVERTICALPOSITION_SUPERSCRIPT) ? CFE_SUPERSCRIPT : CFE_SUBSCRIPT;
            }
        }
    }
    PropVariantClear(&propvar);

    // Get the font family value from the property store.
    if (SUCCEEDED(pPropStore->GetValue(UI_PKEY_FontProperties_Family, &propvar)))
    {
        // Get the string for the font family.
        PWSTR pszFamily;
        UIPropertyToStringAlloc(UI_PKEY_FontProperties_Family, propvar, &pszFamily);
        // Blank string is used as "Not Available" value.
        if (lstrcmp(pszFamily, L"")) 
        {
            // There is a value assigned, so set the corresponding members in CharFormat2 variable.
            // Copy the string for font family.
            StringCchCopyW(pCharFormat->szFaceName, ARRAYSIZE(pCharFormat->szFaceName), pszFamily);
            pCharFormat->dwMask |= CFM_FACE;
        }
        // Free the allocated string.
        CoTaskMemFree(pszFamily);
    }
    PropVariantClear(&propvar);

    // Get the font size value from the property store.
    if (SUCCEEDED(pPropStore->GetValue(UI_PKEY_FontProperties_Size, &propvar)))
    {
        // Get the decimal font size value.
        DECIMAL decSize;
        UIPropertyToDecimal(UI_PKEY_FontProperties_Size, propvar, &decSize);
        DOUBLE dSize;
        VarR8FromDec(&decSize, &dSize);
        // Zero is used as "Not Available" value.
        if (dSize > 0)
        {
            // There is a value assigned, so set the corresponding members in CharFormat2 variable.
            pCharFormat->dwMask |= CFM_SIZE;
            // Set the height as twips.
            pCharFormat->yHeight = (LONG)(dSize * TWIPS_PER_POINT);
        }
    }
    PropVariantClear(&propvar);

    // Get the foreground color type value from the property store.
    if (SUCCEEDED(pPropStore->GetValue(UI_PKEY_FontProperties_ForegroundColorType, &propvar)))
    {
        UIPropertyToUInt32(UI_PKEY_FontProperties_ForegroundColorType, propvar, &uValue);
        if (UI_SWATCHCOLORTYPE_AUTOMATIC == (UI_SWATCHCOLORTYPE)uValue)
        {
            // The color type is automatic, so set the corresponding members in CharFormat2 variable.
            pCharFormat->dwMask |= CFM_COLOR;
            pCharFormat->dwEffects |= CFE_AUTOCOLOR;
        }
    }
    PropVariantClear(&propvar);

    // Get the foreground color value from the property store.
    if (SUCCEEDED(pPropStore->GetValue(UI_PKEY_FontProperties_ForegroundColor, &propvar)))
    {
        // A font color is specified so set the corresponding members in CharFormat2 variable.
        UIPropertyToUInt32(UI_PKEY_FontProperties_ForegroundColor, propvar, &uValue);
        pCharFormat->dwMask |= CFM_COLOR;
        pCharFormat->crTextColor = (COLORREF)uValue;
    }
    PropVariantClear(&propvar);

    // Get the background color type value from the property store.
    if (SUCCEEDED(pPropStore->GetValue(UI_PKEY_FontProperties_BackgroundColorType, &propvar)))
    {
        UIPropertyToUInt32(UI_PKEY_FontProperties_BackgroundColorType, propvar, &uValue);
        if (UI_SWATCHCOLORTYPE_NOCOLOR == (UI_SWATCHCOLORTYPE)uValue)
        {
            // The color type is no color, so set the corresponding members in CharFormat2 variable.
            pCharFormat->dwMask |= CFM_BACKCOLOR;
            pCharFormat->dwEffects |= CFE_AUTOBACKCOLOR;
        }
    }
    PropVariantClear(&propvar);

    // Get the background color value from the property store.
    if (SUCCEEDED(pPropStore->GetValue(UI_PKEY_FontProperties_BackgroundColor, &propvar)))
    {
        // A color is specified so set the corresponding members in CharFormat2 variable.
        UIPropertyToUInt32(UI_PKEY_FontProperties_BackgroundColor, propvar, &uValue);
        pCharFormat->dwMask |= CFM_BACKCOLOR;
        pCharFormat->crBackColor = (COLORREF)uValue;
    }
    PropVariantClear(&propvar);
}

// Convert from CHARFORMAT2 to IPropertyStore so it can be passed to the font control.
void GetIPropStoreFromCharFormat2(const __in CHARFORMAT2* pCharFormat, __in IPropertyStore *pPropStore)
{
    PROPVARIANT propvar;
    PropVariantInit(&propvar);
    
    if (pCharFormat->dwMask & CFM_BOLD)
    {
        // Set the bold value to UI_FONTPROPERTIES_SET or UI_FONTPROPERTIES_NOTSET.
        UIInitPropertyFromUInt32(UI_PKEY_FontProperties_Bold, (pCharFormat->dwEffects & CFE_BOLD) ? UI_FONTPROPERTIES_SET : UI_FONTPROPERTIES_NOTSET, &propvar);
    }
    else
    {
        // The bold value is not available so set it to UI_FONTPROPERTIES_NOTAVAILABLE.
        UIInitPropertyFromUInt32(UI_PKEY_FontProperties_Bold, UI_FONTPROPERTIES_NOTAVAILABLE, &propvar);
    }
    // Set UI_PKEY_FontProperties_Bold value in property store.
    pPropStore->SetValue(UI_PKEY_FontProperties_Bold, propvar);
    PropVariantClear(&propvar);

    if (pCharFormat->dwMask & CFM_ITALIC)
    {
        // Set the italic value to UI_FONTPROPERTIES_SET or UI_FONTPROPERTIES_NOTSET.
        UIInitPropertyFromUInt32(UI_PKEY_FontProperties_Italic, (pCharFormat->dwEffects & CFE_ITALIC)?UI_FONTPROPERTIES_SET:UI_FONTPROPERTIES_NOTSET, &propvar);
    }
    else
    {
        // The italic value is not available so set it to UI_FONTPROPERTIES_NOTAVAILABLE.
        UIInitPropertyFromUInt32(UI_PKEY_FontProperties_Italic, UI_FONTPROPERTIES_NOTAVAILABLE, &propvar);
    }
    // Set UI_PKEY_FontProperties_Italic value in property store.
    pPropStore->SetValue(UI_PKEY_FontProperties_Italic, propvar);
    PropVariantClear(&propvar);

    if (pCharFormat->dwMask & CFM_UNDERLINE)
    {
        // Set the underline value to UI_FONTUNDERLINE_SET or UI_FONTUNDERLINE_NOTSET.
        UIInitPropertyFromUInt32(UI_PKEY_FontProperties_Underline, (pCharFormat->dwEffects & CFE_UNDERLINE) ? UI_FONTUNDERLINE_SET : UI_FONTUNDERLINE_NOTSET, &propvar);
    }
    else
    {
        // The underline value is not available so set it to UI_FONTUNDERLINE_NOTAVAILABLE.
        UIInitPropertyFromUInt32(UI_PKEY_FontProperties_Underline, UI_FONTUNDERLINE_NOTAVAILABLE, &propvar);
    }
    // Set UI_PKEY_FontProperties_Underline value in property store.
    pPropStore->SetValue(UI_PKEY_FontProperties_Underline, propvar);
    PropVariantClear(&propvar);
    
    if (pCharFormat->dwMask & CFM_STRIKEOUT)
    {
        // Set the strikethrough value to UI_FONTPROPERTIES_SET or UI_FONTPROPERTIES_NOTSET.
        UIInitPropertyFromUInt32(UI_PKEY_FontProperties_Strikethrough, (pCharFormat->dwEffects & CFE_STRIKEOUT) ? UI_FONTPROPERTIES_SET : UI_FONTPROPERTIES_NOTSET, &propvar);
    }
    else
    {
        // The strikethrough value is not available so set it to UI_FONTPROPERTIES_NOTAVAILABLE.
        UIInitPropertyFromUInt32(UI_PKEY_FontProperties_Strikethrough, UI_FONTPROPERTIES_NOTAVAILABLE, &propvar);
    }
    // Set UI_PKEY_FontProperties_Strikethrough value in property store.
    pPropStore->SetValue(UI_PKEY_FontProperties_Strikethrough, propvar);
    PropVariantClear(&propvar);

    if (pCharFormat->dwMask & CFE_SUBSCRIPT)
    {
        if ((pCharFormat->dwMask & CFM_SUBSCRIPT) && (pCharFormat->dwEffects & CFE_SUBSCRIPT))
        {
            // Set the vertical positioning value to UI_FONTVERTICALPOSITION_SUBSCRIPT.
            UIInitPropertyFromUInt32(UI_PKEY_FontProperties_VerticalPositioning, UI_FONTVERTICALPOSITION_SUBSCRIPT, &propvar);
        }
        else if (pCharFormat->dwEffects & CFE_SUPERSCRIPT)
        {
            // Set the vertical positioning value to UI_FONTVERTICALPOSITION_SUPERSCRIPT.
            UIInitPropertyFromUInt32(UI_PKEY_FontProperties_VerticalPositioning, UI_FONTVERTICALPOSITION_SUPERSCRIPT, &propvar);
        }
    }
    else if (pCharFormat->dwMask & CFM_OFFSET)
    {
        if (pCharFormat->yOffset > 0)
        {
            // Set the vertical positioning value to UI_FONTVERTICALPOSITION_SUPERSCRIPT.
            UIInitPropertyFromUInt32(UI_PKEY_FontProperties_VerticalPositioning, UI_FONTVERTICALPOSITION_SUPERSCRIPT, &propvar);
        }
        else if (pCharFormat->yOffset < 0)
        {
            // Set the vertical positioning value to UI_FONTVERTICALPOSITION_SUBSCRIPT.
            UIInitPropertyFromUInt32(UI_PKEY_FontProperties_VerticalPositioning, UI_FONTVERTICALPOSITION_SUBSCRIPT, &propvar);
        }
        else
        {
            // The value is not available so set the vertical positioning value to UI_FONTVERTICALPOSITION_NOTAVAILABLE.
            UIInitPropertyFromUInt32(UI_PKEY_FontProperties_VerticalPositioning, UI_FONTVERTICALPOSITION_NOTAVAILABLE, &propvar);
        }

    }
    // Set UI_PKEY_FontProperties_VerticalPositioning value in property store.
    pPropStore->SetValue(UI_PKEY_FontProperties_VerticalPositioning, propvar);
    PropVariantClear(&propvar);

    if (pCharFormat->dwMask & CFM_FACE)
    {
        // Set the font family value to the font name.
        UIInitPropertyFromString(UI_PKEY_FontProperties_Family, pCharFormat->szFaceName, &propvar);
    }
    else
    {
        // Font family name is not available so set it to blank string.
        UIInitPropertyFromString(UI_PKEY_FontProperties_Family, L"", &propvar);
    }
    // Set UI_PKEY_FontProperties_Family value in property store.
    pPropStore->SetValue(UI_PKEY_FontProperties_Family, propvar);
    PropVariantClear(&propvar);

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
    UIInitPropertyFromDecimal(UI_PKEY_FontProperties_Size, decSize, &propvar); 
    pPropStore->SetValue(UI_PKEY_FontProperties_Size, propvar);
    PropVariantClear(&propvar);

    if ((pCharFormat->dwMask & CFM_COLOR) && !(pCharFormat->dwEffects & CFE_AUTOCOLOR))
    {
        // There is a color value so set the type to UI_SWATCHCOLORTYPE_RGB in property store.
        UIInitPropertyFromUInt32(UI_PKEY_FontProperties_ForegroundColorType, UI_SWATCHCOLORTYPE_RGB, &propvar);
        pPropStore->SetValue(UI_PKEY_FontProperties_ForegroundColorType, propvar);
        PropVariantClear(&propvar);
        
        // Set the color value in property store.
        UIInitPropertyFromUInt32(UI_PKEY_FontProperties_ForegroundColor, pCharFormat->crTextColor, &propvar);
        pPropStore->SetValue(UI_PKEY_FontProperties_ForegroundColor, propvar);
    }
    else if ((pCharFormat->dwMask & CFM_COLOR) && (pCharFormat->dwEffects & CFE_AUTOCOLOR))
    {
        // The color is automatic color so set the type to UI_SWATCHCOLORTYPE_AUTOMATIC in property store.
        UIInitPropertyFromUInt32(UI_PKEY_FontProperties_ForegroundColorType, UI_SWATCHCOLORTYPE_AUTOMATIC, &propvar);
        pPropStore->SetValue(UI_PKEY_FontProperties_ForegroundColorType, propvar);
    }
    PropVariantClear(&propvar);

    if ((pCharFormat->dwMask & CFM_BACKCOLOR) && !(pCharFormat->dwEffects & CFE_AUTOBACKCOLOR))
    {
        // There is a color value so set the type to UI_SWATCHCOLORTYPE_RGB in property store.
        UIInitPropertyFromUInt32(UI_PKEY_FontProperties_BackgroundColorType, UI_SWATCHCOLORTYPE_RGB, &propvar);
        pPropStore->SetValue(UI_PKEY_FontProperties_BackgroundColorType, propvar);
        PropVariantClear(&propvar);
        
        // Set the color value in property store.
        UIInitPropertyFromUInt32(UI_PKEY_FontProperties_BackgroundColor, pCharFormat->crBackColor, &propvar);
        pPropStore->SetValue(UI_PKEY_FontProperties_BackgroundColor, propvar);
    }
    else
    {
        // There is no color so set the type to UI_SWATCHCOLORTYPE_NOCOLOR in property store.
        UIInitPropertyFromUInt32(UI_PKEY_FontProperties_BackgroundColorType, UI_SWATCHCOLORTYPE_NOCOLOR, &propvar);
        pPropStore->SetValue(UI_PKEY_FontProperties_BackgroundColorType, propvar);
    }
}

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
	ODBGS("~PropertySet()");
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
            return UIInitPropertyFromImage(UI_PKEY_ItemImage, pimgItem_, ppropvar);
        }
        return S_FALSE;
    }
    else if (key == UI_PKEY_Label)
    {
		return UIInitPropertyFromString(UI_PKEY_Label, mol::towstring(label_).c_str(), ppropvar);
    }
    else if (key == UI_PKEY_CategoryId)
    {
        return UIInitPropertyFromUInt32(UI_PKEY_CategoryId, categoryId_, ppropvar);
    }
    else if (key == UI_PKEY_CommandId)
    {
        if(commandId_ != -1)
        {
            return UIInitPropertyFromUInt32(UI_PKEY_CommandId, commandId_, ppropvar);
        }
        return S_FALSE;
    }
    else if (key == UI_PKEY_CommandType)
    {
        return UIInitPropertyFromUInt32(UI_PKEY_CommandType, commandType_, ppropvar);
    }
	else if (key == UI_PKEY_Pinned)
    {
        return UIInitPropertyFromBoolean(UI_PKEY_Pinned, pinned_, ppropvar);
    }
    return E_FAIL;
}

PropertySet::Instance* PropertySet::CreateInstance()
{
	PropertySet::Instance* ins = new PropertySet::Instance;
    return ins;
}


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
	ODBGS("~HandlerBase()");
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
				hr = UIPropertyToIUnknownArrayAlloc( UI_PKEY_RecentItems, *ppropvarValue, &psa );
				if ( hr == S_OK )
				{
					mol::SFAccess<IUnknown*> sfa(psa);
					
					for ( long i = 0; i < sfa.size(); i++ )
					{
						mol::punk<IUISimplePropertySet> prop(sfa[i]);
						if (!prop)
							continue;

						PROPVARIANT pv;
						hr = prop->GetValue(UI_PKEY_Label,&pv);
						if ( hr == S_OK )
						{
							mol::bstr label(pv.bstrVal);
							bool pinned = false;
							hr = prop->GetValue(UI_PKEY_Pinned,&pv);
							if ( hr == S_OK )
							{
								pinned = pv.boolVal == VARIANT_TRUE ? true : false;
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
				  PROPVARIANT varValues;
				  hr = pCommandExecutionProperties->GetValue(UI_PKEY_FontProperties_ChangedProperties, &varValues);
				  if (SUCCEEDED(hr))
				  {
					IPropertyStore *store = 0;
					hr = UIPropertyToInterface(UI_PKEY_FontProperties, varValues, &store);
					if (SUCCEEDED(hr))
					{
						::ZeroMemory(&charFormat_,sizeof(charFormat_));
						charFormat_.cbSize = sizeof(CHARFORMAT2);
						GetCharFormat2FromIPropertyStore(store,&charFormat_);

						hr = store->Release();
					}
					PropVariantClear(&varValues);
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
		hr = UIInitPropertyFromUInt32(UI_PKEY_SelectedItem, index_, ppropvarNewValue);
		return hr;
	}
	else if (key == UI_PKEY_StringValue)
	{      
		hr = UIInitPropertyFromString(UI_PKEY_StringValue, mol::bstr(value_), ppropvarNewValue);
		return hr;
	}
	else if (key == UI_PKEY_Enabled)
	{
		hr = UIInitPropertyFromBoolean(UI_PKEY_Enabled, enabled_, ppropvarNewValue);
		return hr;
	}
	else if (key == UI_PKEY_BooleanValue)
	{
		hr = UIInitPropertyFromBoolean(UI_PKEY_BooleanValue, bValue_, ppropvarNewValue);
		return hr;
	}
	else if (key == UI_PKEY_Minimized)
	{
		hr = UIInitPropertyFromBoolean(UI_PKEY_Minimized, minimized_, ppropvarNewValue);
		return hr;
	}
    else if ( key == UI_PKEY_Label )
	{
		hr = UIInitPropertyFromString(UI_PKEY_Label, mol::bstr(label_), ppropvarNewValue);
		return hr;
	}
	else if (key == UI_PKEY_DecimalValue)
	{
		hr = UIInitPropertyFromDecimal( UI_PKEY_DecimalValue, decimal_.decVal, ppropvarNewValue);
		return hr;
	}
    else if (key == UI_PKEY_DecimalPlaces)
	{
		hr = UIInitPropertyFromUInt32( UI_PKEY_DecimalPlaces, decimalPlaces_, ppropvarNewValue);
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

		hr = UIInitPropertyFromIUnknownArray(UI_PKEY_RecentItems, sa, ppropvarNewValue);
		return hr;
	}
	else if (key == UI_PKEY_FontProperties)
	{
		hr = E_POINTER;
		if (ppropvarCurrentValue != NULL)
		{
			hr = E_POINTER;
			// Get the font values for the selected text in the font control.
			IPropertyStore *pValues;
			hr = UIPropertyToInterface(UI_PKEY_FontProperties, *ppropvarCurrentValue, &pValues);
			if (SUCCEEDED(hr))
			{
				//IPropertyStore* pps = 0;
				GetIPropStoreFromCharFormat2(&charFormat_, pValues);
				// Provide the new values to the font control.
				//if ( pps )
				{
					hr = UIInitPropertyFromInterface(UI_PKEY_FontProperties, pValues, ppropvarNewValue);
					//pps->Release();
				}
				pValues->Release();
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
	ODBGS("HandlerRegistry::dispose()");
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
	ODBGS("~Ribbon()");
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
	ODBGS("dispose Ribbon");
}


bool Ribbon::tearDown()
{
	ODBGS("Ribbon::tearDown()");

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

void Ribbon::setColor( UI_HSBCOLOR foreGround, UI_HSBCOLOR backGround)
{
	mol::punk<IPropertyStore> spPropertyStore;

    if (S_OK != ribbon->QueryInterface(&spPropertyStore) )
		return;

    PROPVARIANT propvarBackground;
    PROPVARIANT propvarText;
 
    InitPropVariantFromUInt32(backGround, &propvarBackground);
    InitPropVariantFromUInt32(foreGround, &propvarText);
 
    spPropertyStore->SetValue(UI_PKEY_GlobalBackgroundColor, propvarBackground);
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

	setColor(ForegroundColor,BackgroundColor);
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

	ODBGS("try initialize Ribbon");
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

	hr = ribbon->LoadUI(GetModuleHandle(NULL), L"APPLICATION_RIBBON");
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
    UIInitPropertyFromBoolean(UI_PKEY_Minimized, true, &propvar);
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
    UIInitPropertyFromBoolean(UI_PKEY_Minimized, false, &propvar);
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