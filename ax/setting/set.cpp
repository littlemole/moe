#include "stdafx.h"
#include "set.h"
#include "win/Res.h"
#include "win/wnd.h"
#include "ole/typelib.h"
#include "util/str.h"
#include <sstream>


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

Setting::Setting(void)	
{
	bDirty_ = FALSE;
	parent_ = 0;

	vbChildrenAllowed_ = VARIANT_TRUE;
	vbKeyReadOnly_     = VARIANT_FALSE;
	vbValueReadOnly_   = VARIANT_FALSE;
}

//////////////////////////////////////////////////////////////////////////////

Setting::~Setting()
{
	this->Clear();
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


HRESULT __stdcall Setting::get_Key	( BSTR* key )
{
	if ( key )
	{
		*key = ::SysAllocString(key_);
	}
	return S_OK;
}

HRESULT __stdcall Setting::put_Key	( BSTR key  )
{
	key_ = key;
	this->setDirty(TRUE);
	return S_OK;
}

HRESULT __stdcall Setting::get_Value	( BSTR* value )
{
	if ( value )
	{
		*value = ::SysAllocString(val_);
	}
	return S_OK;
}

HRESULT __stdcall Setting::put_Value	( BSTR value )
{
	this->Clear();
	val_ = value;
	this->setDirty(TRUE);
	return S_OK;
}

HRESULT __stdcall Setting::get_Parent ( ISetting** parent )
{
	if ( !parent )
		return E_POINTER;

	*parent = 0;
	if ( parent_ )
	{
		return parent_->QueryInterface(IID_ISetting,(void**)parent);
	}
	return S_OK;
}

HRESULT __stdcall Setting::put_Parent ( ISetting* parent )
{
	if ( parent )
	{
		parent_ = parent;
	}
	else
		parent_ = 0;
	this->setDirty(TRUE);
	return S_OK;
}

HRESULT __stdcall Setting::get_ChildrenAllowed ( VARIANT_BOOL* vb )
{
	if ( !vb )
		return E_POINTER;

	*vb = vbChildrenAllowed_;
	return S_OK;
}

HRESULT __stdcall Setting::put_ChildrenAllowed ( VARIANT_BOOL vb )
{
	this->setDirty(TRUE);
	vbChildrenAllowed_ = vb;
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////
HRESULT __stdcall Setting::get_KeyReadOnly ( VARIANT_BOOL* vb )
{
	if ( !vb )
		return E_POINTER;

	*vb = vbKeyReadOnly_;
	return S_OK;
}

HRESULT __stdcall Setting::put_KeyReadOnly ( VARIANT_BOOL vb )
{
	this->setDirty(TRUE);
	vbKeyReadOnly_ = vb;
	return S_FALSE;
}

//////////////////////////////////////////////////////////////////////////////
HRESULT __stdcall Setting::get_ValueReadOnly ( VARIANT_BOOL* vb )
{
	if ( !vb )
		return E_POINTER;

	*vb = vbValueReadOnly_;
	return S_OK;
}

HRESULT __stdcall Setting::put_ValueReadOnly ( VARIANT_BOOL vb )
{
	this->setDirty(TRUE);
	vbValueReadOnly_ = vb;
	return S_FALSE;
}

//////////////////////////////////////////////////////////////////////////////
HRESULT __stdcall Setting::get_IsDirty ( VARIANT_BOOL* vb )
{
	if ( !vb )
		return E_POINTER;

	*vb = bDirty_ ? VARIANT_TRUE : VARIANT_FALSE;

	if ( bDirty_ )
		return S_OK;

	if (entries_.size() > 0 )
	{
		for( std::list<ISetting*>::iterator it = entries_.begin(); it != entries_.end(); it++)
		{
			(*it)->get_IsDirty(vb);
			if ( *vb == VARIANT_TRUE )
				return S_OK;
		}
	}
	return S_OK;
}

HRESULT __stdcall Setting::put_IsDirty ( VARIANT_BOOL vb )
{
	bDirty_ = vb == VARIANT_TRUE ? true : false;
	return S_OK;
}
//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall  Setting::_NewEnum(IEnumVARIANT** newEnum)
{
	punk<com_obj<enum_variant> > ev = new com_obj<enum_variant>;
	for ( std::list<ISetting*>::iterator it = entries_.begin(); it != entries_.end(); it++ )
	{
		punk<IDispatch> disp(*it);
		ev->add(variant(disp));
	}
	return ev->QueryInterface(IID_IEnumVARIANT,(void**)newEnum);
}

HRESULT __stdcall  Setting::Count( long* cnt)
{
	if ( cnt )
		*cnt = (long)entries_.size();
	return S_OK;
}

HRESULT __stdcall  Setting::Item( VARIANT index, ISetting** item)
{
	variant v(index);
	if ( !item )
		return E_POINTER;
	*item = 0;
	if ( v.vt == VT_BSTR )
	{
		if ( v.bstrVal )
		{
			for ( std::list<ISetting*>::iterator it = entries_.begin(); it != entries_.end(); it++ )
			{
				bstr key;
				if ( S_OK == (*it)->get_Key(&key) )
				{
					if ( key )
					{
						if ( _wcsicmp( key.bstr_, v.bstrVal) == 0 )
						{
							return (*it)->QueryInterface(IID_ISetting,(void**)item);
						}
					}
				}
			}
		}
		return S_FALSE;
	}
	v.changeType(VT_INT);
	std::list<ISetting*>::iterator it = entries_.begin();
	for ( int i = 0; i < v.intVal; i++ )
	{
		if ( it == entries_.end() )
			break;
		it++;
	}
	if ( it != entries_.end() )
	{
		return (*it)->QueryInterface(IID_ISetting,(void**)item);
	}
	return S_FALSE;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall Setting::Root(ISetting** root)
{
	if ( !root )
		return E_POINTER;

	*root = 0;
	if ( parent_ )
	{
		punk<ISetting> set(parent_);
		if ( set )
		{
			while(true)
			{
				punk<ISetting> p;
				HRESULT hr = set->get_Parent(&p);
				if ( (hr != S_OK) || ( !p ) )
				{
					return set->QueryInterface(IID_ISetting,(void**)root);
				}
				set = p;
			}
		}
	}
	return S_FALSE;
}

//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall Setting::KeyName(BSTR* keyname)
{
	if (!keyname)
		return E_POINTER;

	if (!parent_)
	{
		std::wostringstream woss;
		if ( key_.bstr_ )
			woss << L"[" << key_.bstr_ << L"]";
		*keyname = ::SysAllocString(woss.str().c_str());
		return S_OK;
	}

	bstr b;
	if ( S_OK == parent_->KeyName(&b) )
	{
		if ( b.bstr_ )
		{
			std::wostringstream woss;
			woss << b.bstr_ << L"[" << key_.bstr_ << L"]";
			*keyname = ::SysAllocString(woss.str().c_str());
			return S_OK;
		}
	}
	std::wostringstream woss;
	if ( key_.bstr_ )
		woss << L"[" << key_.bstr_ << L"]";
	*keyname = ::SysAllocString(woss.str().c_str());
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall Setting::Add(ISetting* set)
{
	if ( !set )
		return E_POINTER;

	set->AddRef();
	set->Remove();
	entries_.push_back(set);
	set->put_Parent(this);
	this->setDirty(TRUE);
	return S_OK;
}

HRESULT  __stdcall Setting::New(BSTR key, BSTR value, ISetting** set)
{
	if ( S_OK == ::CoCreateInstance(CLSID_Setting,0,CLSCTX_INPROC,IID_ISetting,(void**)set) )
	{
		(*set)->put_Key(key);
		(*set)->put_Value(value);
		return Add(*set);
	}
	return E_FAIL;
}

HRESULT __stdcall Setting::Remove()
{
	if ( parent_ )
	{
		long len;
		if ( S_OK == parent_->Count(&len) )
		{
			for ( long i = 0; i < len; i++ )
			{
				punk<ISetting> set;
				if ( S_OK == parent_->Item(variant(i),&set) )
				{
					if ( set )
					{
						if ( (ISetting*)set == (ISetting*)this )
						{
							HRESULT hr = parent_->RemoveItem(variant(i));
							parent_ = 0;
							return hr;
						}
					}
				}
			}
		}
		parent_ = 0;
	}
	return S_OK;
}


HRESULT __stdcall Setting::RemoveItem( VARIANT index)
{
	this->setDirty(TRUE);
	variant v(index);
	if ( v.vt == VT_BSTR )
	{
		if ( v.bstrVal )
		{
			for ( std::list<ISetting*>::iterator it = entries_.begin(); it != entries_.end(); it++ )
			{
				bstr key;
				if ( S_OK == (*it)->get_Key(&key) )
				{
					if ( key )
					{
						if ( _wcsicmp( key.bstr_, v.bstrVal) == 0 )
						{
							(*it)->put_Parent(0);
							(*it)->Release();
							entries_.erase(it);
							return S_OK;
						}
					}
				}
			}
		}
		return S_FALSE;
	}
	v.changeType(VT_INT);
	std::list<ISetting*>::iterator it = entries_.begin();
	for ( int i = 0; i < v.intVal; i++ )
	{
		if ( it == entries_.end() )
			break;
		it++;
	}
	if ( it != entries_.end() )
	{
		(*it)->put_Parent(0);
		(*it)->Release();
		entries_.erase(it);
		return S_OK;
	}
	return S_FALSE;
}

HRESULT __stdcall Setting::Clear()
{
	for ( std::list<ISetting*>::iterator it = entries_.begin(); it != entries_.end(); it++ )
	{
		(*it)->Release();
	}
	entries_.clear();
	this->setDirty(TRUE);
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall Setting::Load( BSTR filename)
{
	this->Clear();

	std::string file = BSTR2ansi(filename);
    std::ifstream in(file.c_str());
    if (in)
    {
        char bufKey[1024];
        while( in.getline(bufKey,1024) )
        {
            std::string key = mol::trim(bufKey);
            if ( key != "" )
            {
				punk<ISetting> set;
				if ( S_OK == getKey(mol::ansi2wstring(key),&set) )
                if ( set )
                {
                    char bufVal[1024];
                    std::string val = "";
                    while( in.getline(bufVal,1024) )
                    {
                        std::string tmp(bufVal);// = mol::trim(bufVal);
                        if ( tmp.size() == 0 )
                        {
                            if ( in.peek() == '[' )
                                break;
                        }
                        val += tmp;
                        val += "\n";
                    }
                    if ( val != "" )
						set->put_Value(bstr(val));
                        //getValue(val,ce);
                }
				
            }
        }
        in.close();
    }
	this->setDirty(FALSE);
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall Setting::Save( BSTR filename)
{
	std::string file = BSTR2ansi(filename);
    std::ofstream ofs(file.c_str());
    if (ofs)
    {
		saveWalker(this,ofs);
	}
	this->setDirty(FALSE);
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall Setting::Clone( ISetting** clone)
{
	if ( S_OK == ::CoCreateInstance(CLSID_Setting, 0, CLSCTX_INPROC, IID_ISetting, (void**)clone) )
	{
		if ( *clone )
		{
			HRESULT hr;
			hr = (*clone)->put_Key(key_);
			hr = (*clone)->put_Value(val_);
			hr = (*clone)->put_ValueReadOnly(vbValueReadOnly_);
			hr = (*clone)->put_KeyReadOnly(vbKeyReadOnly_);
			hr = (*clone)->put_ChildrenAllowed(vbChildrenAllowed_);
			for ( std::list<ISetting*>::iterator it = entries_.begin(); it != entries_.end(); it++ )
			{
				punk<ISetting> set;
				if ( S_OK == (*it)->Clone(&set) )
				{
					(*clone)->Add(set);
				}
			}
		}
	}

	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// IStorage
//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall Setting::Save(	 IStorage * pStgSave, BOOL fSameAsLoad )
{
	punk<IStream> stream;
	if ( S_OK == pStgSave->CreateStream( L"CONTENT", STGM_CREATE|STGM_READWRITE|STGM_SHARE_EXCLUSIVE,0,0,&stream) )
	{
		if ( S_OK == ::WriteClassStm(stream,CLSID_Setting) )
		{
			if ( S_OK == this->Save(stream,TRUE) )
			{
				int i = 0;
				for ( std::list<ISetting*>::iterator it = entries_.begin(); it != entries_.end(); it++ )
				{
					std::wostringstream woss;
					woss << L"child_" << i;
					punk<IStorage> store;
					if ( S_OK == pStgSave->CreateStorage( woss.str().c_str(),STGM_CREATE|STGM_READWRITE|STGM_SHARE_EXCLUSIVE,0,0,&store) )
					{
						if ( store )
						{
							if ( S_OK == ::WriteClassStg(store,CLSID_Setting) )
							{
								punk<IPersistStorage> ps(*it);
								if ( ps )
									ps->Save(store,FALSE);
							}
						}
					}
					i++;
				}
			}
		}
	}
	this->setDirty(FALSE);
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall Setting::Load(IStorage * pStgLoad)
{
	punk<IStream> stream;
	if ( S_OK == pStgLoad->OpenStream(L"CONTENT", 0,STGM_READ|STGM_SHARE_EXCLUSIVE,0,&stream) )
	{
		CLSID clsid;
		if ( S_OK == ::ReadClassStm(stream,&clsid) )
		{
			if ( ::IsEqualGUID( clsid, CLSID_Setting ) )
			{
				if ( S_OK == this->Load(stream) )
				{
					int i = 0;
					std::wostringstream woss;
					woss << L"child_" << i;
					std::wstring childname = woss.str();
					punk<IStorage> store;
					while ( S_OK == pStgLoad->OpenStorage(childname.c_str(), 0, STGM_READ|STGM_SHARE_EXCLUSIVE,0,0,&store) )
					{
						if ( store )
						{
							if ( S_OK == ::ReadClassStg(store,&clsid) )
							{
								if ( ::IsEqualCLSID( clsid, CLSID_Setting ) )
								{
									punk<ISetting> set;
									if ( S_OK == ::CoCreateInstance(CLSID_Setting,0,CLSCTX_INPROC,IID_ISetting,(void**)&set) )
									{
										if ( set )
										{
											punk<IPersistStorage> ps(set);
											if ( ps )
											{
												if ( S_OK == ps->Load(store) )
												{
													this->Add(set);
												}
											}
										}
									}// create set
								} // equals CLSID_Setting
							}
						}
						i++;
						std::wostringstream woss;
						woss << L"child_" << i;
						childname = woss.str();
					} // end while open storage
				} // persist stream load
			}// equals CLSID_Setting
		} // read class stream
	} // open content stream
	this->setDirty(FALSE);
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// IPropertyPage
//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall Setting::GetPages( CAUUID *pPages )
{
	if ( !pPages )
		return E_POINTER;
	pPages->cElems = 1;
	pPages->pElems = (GUID*)::CoTaskMemAlloc(sizeof(GUID));
	pPages->pElems[0] = CLSID_SettingProperties;
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall Setting::Load( LPSTREAM pStm)
{
	pStm >> mol::property( mol::DispId(this,DISPID_SETTING_KEY,VT_BSTR) )
		 >> mol::property( mol::DispId(this,DISPID_SETTING_VALUE,VT_BSTR) )
		 >> mol::property( mol::DispId(this,DISPID_SETTING_CHILDREN_ALLOWED,VT_BOOL) )
		 >> mol::property( mol::DispId(this,DISPID_SETTING_KEY_READONLY,VT_BOOL) )
		 >> mol::property( mol::DispId(this,DISPID_SETTING_VALUE_READONLY,VT_BOOL) );
	return S_OK;
}

HRESULT __stdcall Setting::Save( LPSTREAM pStm,BOOL fClearDirty)
{
	pStm << mol::property( mol::DispId(this,DISPID_SETTING_KEY,VT_BSTR) )
		 << mol::property( mol::DispId(this,DISPID_SETTING_VALUE,VT_BSTR) )
		 << mol::property( mol::DispId(this,DISPID_SETTING_CHILDREN_ALLOWED,VT_BOOL) )
		 << mol::property( mol::DispId(this,DISPID_SETTING_KEY_READONLY,VT_BOOL) )
		 << mol::property( mol::DispId(this,DISPID_SETTING_VALUE_READONLY,VT_BOOL) );
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////
// Key helpers
//////////////////////////////////////////////////////////////////////////////

HRESULT Setting::makeKey(std::wstring key, ISetting* parent, ISetting** newKey)
{
	punk<ISetting> set;
	if ( S_OK == parent->Item(variant(key),&set) )
	{
		if ( set )
		{
			return set->QueryInterface(IID_ISetting,(void**)newKey);
		}
	}
	if ( S_OK == parent->New( bstr(key), L"", &set ) )
	{
		if ( set )
		{
			return set->QueryInterface(IID_ISetting,(void**)newKey);
		}
	}
	return E_FAIL;
}

///////////////////////////////////////////////////////////////////////////////

std::wstring Setting::getSingleKey(const std::wstring& key, size_t pos)
{
    size_t pstart = key.find(L"[",pos);
    if ( pstart != std::wstring::npos )
    {
        size_t pend = key.find(L"]",pstart);
        if ( pend != std::wstring::npos )
        {
            return key.substr(pstart+1,pend-pstart-1);
        }            
    }
    return L"";
}

///////////////////////////////////////////////////////////////////////////////

HRESULT Setting::getKey(const std::wstring& key, ISetting** newKey)
{
	punk<ISetting> set;
    size_t pos = 0;
    std::wstring k = getSingleKey(key,pos);
    if ( k != L"" )
    {   
		if ( S_OK == makeKey( k, this, &set ) )
		{
	        pos += k.size()+1;
	        if ( set )
		    {
				set->QueryInterface(IID_ISetting,(void**)newKey);
				while ( (k=getSingleKey(key,pos)) != L"" )
				{
					punk<ISetting> s;
					if ( S_OK == makeKey( k, set, &s ) )
					{
						if ( s )
						{
							(*newKey)->Release();
							s->QueryInterface(IID_ISetting,(void**)newKey);
							set = s;
							pos+= k.size()+1;
						}
					}
				}
			}
		}
	}
    return S_OK;
}

///////////////////////////////////////////////////////////////////////////////
// save helper
///////////////////////////////////////////////////////////////////////////////

void Setting::saveWalker(ISetting* set, std::ofstream& ofs )
{
	HRESULT hr;

	bstr key;
	bstr val;
	long l;

	hr = set->KeyName(&key);
	ofs << key.tostring() << std::endl;

	hr = set->Count(&l);
	if ( l == 0 )
	{
		hr = set->get_Value(&val);
		ofs << val.tostring() << std::endl;
		return;
	}
	ofs << std::endl;
	for ( long i = 0; i < l; i++ )
	{
		punk<ISetting> s;
		if ( S_OK == set->Item(variant(i),&s) )
		{
			if ( s )
				saveWalker(s,ofs);
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Setting Property Page
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// COM Methods
///////////////////////////////////////////////////////////////////////////////

HRESULT SettingProperties::Apply( void)
{
	for ( size_t i = 0; i < objects_.size(); i++ )
	{	
		punk<ISetting> set(objects_[i]);
		if ( set )
		{
			if ( S_OK == set->Clear() )
			{
				bstr key;
				if ( S_OK == clone_->get_Key(&key) )
				{
					if ( S_OK != set->put_Key(key) )
						continue;
				}

				bstr val;
				if ( S_OK == clone_->get_Value(&val) )
				{
					if ( S_OK != set->put_Value(val) )
						continue;
				}
				long l;
				if ( S_OK == clone_->Count(&l) )
				{
					for ( long i = 0; i < l; i++ )
					{
						punk<ISetting> s;
						if ( S_OK == clone_->Item(variant(i),&s) )
						{
							punk<ISetting> c;
							if ( S_OK == s->Clone(&c) )
								if ( S_OK != set->Add(c) )
									continue;
						}
					}
				}
			}
		}
	}
	bDirty_ = FALSE;
	return S_OK;
}

///////////////////////////////////////////////////////////////////////////////
// Message Handlers
///////////////////////////////////////////////////////////////////////////////

LRESULT SettingProperties::OnInitDialog(UINT msg, WPARAM wParam, LPARAM lParam)
{
	tree_.attach(getDlgItem(IDC_TREE_PROP));
	if ( objects_.size() > 0 )
	{
		variant var;
		punk<ISetting> set(objects_[0]);
		clone_.release();
		if ( S_OK == set->Clone(&clone_) )
		if ( clone_ )
		{
			bstr key;
			if ( S_OK == clone_->get_Key(&key)  )
			{
				mol::string k(_T(""));
				if ( key )
					k = mol::toString(key);
				if ( k == _T("") )
					k = _T("Properties");
				HTREEITEM root = tree_.addNodeParam(k,(LPARAM)(ISetting*)clone_);
				long l;
				if ( S_OK == clone_->Count(&l) )
				{
					for ( long i = 0; i < l; i++ )
					{
						punk<ISetting> s;
						if ( S_OK == clone_->Item(variant(i),&s) )
						{
							if ( s )
								initWalker(root,s);
						}
					}
				}							
			}
		}
	}
	return FALSE; // note: false! look into PSDK!
}

LRESULT SettingProperties::OnDblClick(UINT msg, WPARAM wParam, LPARAM lParam)
{
	mol::Crack message(msg,wParam,lParam);
	if ( message.nmhdr()->code == NM_DBLCLK )
	{
		HTREEITEM hit = tree_.getSelection();
		ISetting* set = (ISetting*)tree_.getLPARAM(hit);
		if ( set )
		{
			punk<ISetting> parent;
			if ( S_OK == set->get_Parent(&parent) )
			{
				if (!parent)
					return 0;
			}
			long c;
			if ( S_OK == set->Count(&c) )
			{
				if ( c > 0 )
					return 0;
			}

			VARIANT_BOOL vb;
			if ( S_OK == set->get_ValueReadOnly(&vb) )
			{
				if ( vb == VARIANT_FALSE )
				{
					this->editValue(hit);
				}
			}
		}
	}
	return 0;
}

LRESULT SettingProperties::OnContext(UINT msg, WPARAM wParam, LPARAM lParam)
{
	TVHITTESTINFO& thi = tree_.hitTest();
	if ( thi.hItem )
		tree_.setSelection(thi.hItem);

	HTREEITEM hit    = tree_.getSelection();
	HTREEITEM parent = tree_.getParentItem(hit);
	ISetting* set    = (ISetting*)tree_.getLPARAM(hit);

	VARIANT_BOOL vbKeyReadOnly;
	VARIANT_BOOL vbValueReadOnly;
	VARIANT_BOOL vbChildrenAllowed;
	if ( S_OK != set->get_KeyReadOnly(&vbKeyReadOnly) )
		return 0;
	if ( S_OK != set->get_ValueReadOnly(&vbValueReadOnly) )
		return 0;
	if ( S_OK != set->get_ChildrenAllowed(&vbChildrenAllowed) )
		return 0;

	long c;
	if ( S_OK != set->Count(&c) )
		return 0;

	mol::Menu menu;
	menu.load(IDM_MENU_CONTEXT);
	mol::Menu m(menu.getSubMenu(0));

	if ( c > 0 )
	{
		m.disableItem(IDM_EDIT);
	}

	if ( parent == 0 )
	{
		m.disableItem(IDM_EDIT);
		m.disableItem(IDM_DELETE);
	}

	if ( vbKeyReadOnly == VARIANT_TRUE )
	{
		m.disableItem(IDM_DELETE);
	}

	if ( vbValueReadOnly == VARIANT_TRUE )
	{
		m.disableItem(IDM_EDIT);
	}

	if ( vbChildrenAllowed == VARIANT_FALSE  )
	{
		m.disableItem(IDM_NEW);
	}

	switch (this->returnContext(m))
	{
		case IDM_EDIT:
		{
			this->editValue(hit);
			break;
		}
		case IDM_DELETE:
		{
			if ( set )
			{
				HRESULT hr = set->Remove();
				tree_.deleteNode(hit);
				this->setDirty();
			} 
			break;
		}
		case IDM_NEW:
		{
			KeyDialog dlg;
			dlg.key = _T("new key");
			if ( IDOK == dlg.doModal(IDD_DIALOG_KEY,*this) )
			{
				punk<ISetting> s;
				if ( S_OK == set->New(bstr(dlg.key),bstr(""),&s) )
				{
					if ( s )
					{
						tree_.addNodeParam(dlg.key,(LPARAM)(ISetting*)s,hit);
						this->setDirty();
						return 0;
					}
				}
			}
			break;
		}
	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
// Helpers
///////////////////////////////////////////////////////////////////////////////

bool SettingProperties::editValue(HTREEITEM hit)
{
	ISetting* set = (ISetting*)tree_.getLPARAM(hit);
	if  (!set)
		return false;

	bstr key;
	bstr val;
	set->KeyName(&key);
	set->get_Value(&val);

	ValueDialog dlg;

	dlg.value = mol::unix2dos( val.toString() );
	dlg.title = key.toString();

	if ( IDOK == dlg.doModal(IDD_DIALOG_VALUE,*this) )
	{
		if ( S_OK == set->put_Value(bstr(dlg.value)) )
		{
			bstr k;
			set->get_Key(&k);
			HTREEITEM parent = tree_.getParentItem(hit);
			tree_.deleteNode(hit);
			tree_.addNodeParam( k.toString(), (LPARAM)(ISetting*)set,parent);
			this->setDirty();
			return true;
		}
	}
	return false;
}

///////////////////////////////////////////////////////////

void SettingProperties::initWalker(HTREEITEM parent, ISetting* set)
{
	HRESULT hr;

	bstr key;
	bstr val;
	long l;

	HTREEITEM item;

	hr = set->get_Key(&key);
	if ( hr == S_OK )
	{
		item = tree_.addNodeParam(key.toString(),(LPARAM)(ISetting*)set,parent,0);
	}

	hr = set->Count(&l);
	if ( l == 0 )
	{
		return;
	}

	for ( long i = 0; i < l; i++ )
	{
		punk<ISetting> s;
		if ( S_OK == set->Item(variant(i),&s) )
		{
			if ( s )
				initWalker(item,s);
		}
	}
}

///////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////
// Dialogs
///////////////////////////////////////////////////////////

LRESULT ValueDialog::wndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_INITDIALOG:
		{
			edit_.attach(getDlgItem(IDC_EDIT_VAL));
			edit_.setText(value);
			edit_.setFocus();
			setText(title);
			return FALSE; // note: false! look into PSDK!
		}
		case WM_COMMAND :
		{
			if ( LOWORD(wParam) == IDOK )
			{
				value = edit_.getText();
				endDlg(IDOK);
				return 0;
			}
			if ( LOWORD(wParam) == IDCANCEL )
			{
				endDlg(IDCANCEL);
				return 0;
			}
		}
	}
	return mol::win::Dialog::wndProc(hDlg, message, wParam, lParam);
}

///////////////////////////////////////////////////////////

LRESULT KeyDialog::wndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_INITDIALOG:
		{
			edit_.attach(getDlgItem(IDC_EDIT_KEY));
			edit_.setText(key);
			return FALSE; // note: false! look into PSDK!
		}
		case WM_COMMAND :
		{
			if ( LOWORD(wParam) == IDOK )
			{
				key = edit_.getText();
				endDlg(IDOK);
				return 0;
			}
			if ( LOWORD(wParam) == IDCANCEL )
			{
				endDlg(IDCANCEL);
				return 0;
			}
		}
	}
	return mol::win::Dialog::wndProc(hDlg, message, wParam, lParam);
}

