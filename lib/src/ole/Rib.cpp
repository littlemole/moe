#include "ole/Rib.h"
#include "win/shell.h"
#include <uiribbonpropertyhelpers.h>


namespace mol
{

namespace Ribbon
{

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
	return E_NOTIMPL;
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

/*
void Ribbon::updateRecentDocs(int id)
{
	if (!ribbon )
		return;

	mol::Ribbon::handler(id)->items(recentDocs_);
}
*/
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