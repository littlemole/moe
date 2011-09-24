#include "stdafx.h"
#include "Docs.h"
#include "MoeBar.h"
#include "Moe.h"
#include "xmlui.h"
#include "DocFactory.h"

using namespace mol;

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////


Docs::Instance* Docs::CreateInstance()
{
	Instance* d = new Instance;
	d->AddRef();
	return d;
}

Docs::Docs() 
{
	factory_ = new DocFactory;
}

Docs::~Docs() 
{
	delete factory_;
	ODBGS("~DOCS subobj dead");
}

/////////////////////////////////////////////////////////////////////
// impl
/////////////////////////////////////////////////////////////////////

bool Docs::open( const mol::string& dir, InFiles pref, bool readOnly, IMoeDocument** doc  )
{
	return factory_->openDocument(dir,pref,readOnly,doc) == S_OK;
}

/////////////////////////////////////////////////////////////////////

void Docs::remove( mol::MdiChild* mdi )
{
	for ( childlist::iterator it = children_.begin(); it != children_.end(); it++)
	{
		if ( *it == mdi ) 
		{
			children_.erase(it);

			// update tab window
			tab()->remove( (HWND)(*mdi) );
			if ( children_.empty() )
			{
				tab()->show(SW_HIDE);

				// assure any border space reserved for embedded clients gets resetted. greetings to MS Excel!
				mol::punk<IOleInPlaceFrame> frame;
				if ( moe()->axFrameSite )
				{
					HRESULT hr = moe()->axFrameSite->QueryInterface(IID_IOleInPlaceFrame,(void**)&frame);
					if (hr == S_OK && frame)
					{
						frame->SetBorderSpace(0);
					}
				}
				mol::Ribbon::ribbon()->mode(0);
				mol::Ribbon::ribbon()->maximize();
				moe()->doLayout();	
				moe()->redraw();
				statusBar()->status(_T(""));
			}
			return;
		}
	}
}

/////////////////////////////////////////////////////////////////////

void Docs::rename( mol::MdiChild* mdi, const mol::string& path )
{
	// update tab window
	tab()->rename( (HWND)(*mdi), path, mol::Path::filename(path) );

	// update taskbar
	mol::taskbar()->renameTab( ((HWND)(*mdi)), path );
}

/////////////////////////////////////////////////////////////////////

void Docs::erase(mol::MdiChild* mdi)
{
	for ( childlist::iterator it = children_.begin(); it != children_.end(); it++)
	{
		if ( *it == mdi ) 
		{
			children_.erase(it);
			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////

void Docs::insert(mol::MdiChild* mdiPos,mol::MdiChild* mdi)
{
	for ( childlist::iterator it = children_.begin(); it != children_.end(); it++)
	{
		if ( *it == mdiPos ) 
		{
			this->children_.insert(it,mdi);
			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////

void Docs::move( mol::MdiChild* mdi, int pos )
{
	mol::TabCtrl::TabCtrlItem* c = (mol::TabCtrl::TabCtrlItem*) tab()->getTabCtrlItem(pos);
	HWND w = (HWND)(c->lparam);

	tab()->move(*mdi,w);

	childlist::iterator it = iterator(mol::variant(pos));
	mol::MdiChild* posMdi = *it;

	erase(mdi);
	insert(posMdi,mdi);

	mdi->activate();
	tab()->select((HWND)(*mdi));
}

/////////////////////////////////////////////////////////////////////
// COM
/////////////////////////////////////////////////////////////////////

HRESULT __stdcall  Docs::_NewEnum(IEnumVARIANT** newEnum)
{
	punk<com_obj<enum_variant> > ev = new com_obj<enum_variant>;
	for ( childlist::iterator it = children_.begin(); it != children_.end(); it++)
	{
		mol::variant v( (IDispatch*) (*it) );
		ev->add(v);
	}
	return ev->QueryInterface(IID_IEnumVARIANT,(void**)newEnum);
}

HRESULT __stdcall  Docs::get_Count( long* cnt)
{
	if ( cnt )
	{
		*cnt = (long)children_.size();
	}
	return S_OK;
}


HRESULT __stdcall  Docs::Item( VARIANT index, IMoeDocument** item)
{
	if ( !item )
		return E_INVALIDARG;

	*item = 0;

	childlist::iterator& it = iterator(index);
	if ( it == children_.end() )
		return S_FALSE;

	IMoeDocument* doc = dynamic_cast<IMoeDocument*>((*it));

	HRESULT hr = doc->QueryInterface( IID_IMoeDocument, (void**)item);
	return hr == S_OK ? S_OK : S_FALSE;
}

HRESULT __stdcall Docs::get_ActiveDoc( IMoeDocument** d )
{
	if (!d)
		return E_INVALIDARG;

	*d = 0;

	HWND wnd = moe()->getActive();
	mol::MdiChild* mc = mol::wndFromHWND<mol::MdiChild>(wnd);
	if ( mc )
	{
		IMoeDocument* doc = dynamic_cast<IMoeDocument*>(mc);
		if ( doc )
		{
			return doc->QueryInterface( IID_IMoeDocument, (void**) d );
		}
	}
	return E_FAIL;
}

HRESULT __stdcall Docs::Activate( VARIANT i)
{

	childlist::iterator it = iterator(i);
	if ( it == children_.end() )
		return S_FALSE;

	(*it)->activate();

	return S_OK;

	/*
	mol::punk<IMoeDocument> d;
	HRESULT hr = Item(i,&d);
	if ( hr != S_OK )
		return hr;

	if (!d)
		return E_FAIL;

	mol::punk<IMoeDocumentView> view;
	hr = d->get_View(&view);
	if ( hr != S_OK )
		return hr;

	if (!view)
		return E_FAIL;

	return view->Activate();
	*/
}

HRESULT __stdcall Docs::New(IMoeDocument** d)
{
	return factory_->newDocument(Docs::PREF_UTF8,d);	
}


HRESULT __stdcall Docs::NewUserForm(IMoeDocument** d)
{
	return factory_->newDocument(Docs::PREF_FORM,d);
}


HRESULT __stdcall Docs::NewRTFDocument(IMoeDocument** d)
{
	return factory_->newDocument(Docs::PREF_RTF,d);
}


HRESULT __stdcall Docs::OpenTailDocument(BSTR fp, IMoeDocument** d)
{
	return factory_->openDocument(mol::toString(fp),Docs::PREF_TAIL,false,d);
}

HRESULT __stdcall Docs::Open( BSTR fPath, IMoeDocument** d)
{
	return factory_->openDocument(mol::toString(fPath),Docs::PREF_TXT,false,d);
}


HRESULT __stdcall Docs::OpenRTFDocument( BSTR fPath, IMoeDocument** d)
{
	return factory_->openDocument(mol::toString(fPath),Docs::PREF_RTF,false,d);
}

HRESULT __stdcall Docs::OpenUTF8( BSTR fPath, IMoeDocument** d)
{
	return factory_->openDocument(mol::toString(fPath),Docs::PREF_UTF8,false,d);
}

HRESULT __stdcall Docs::OpenDir(BSTR dir,  IMoeDocument** d)
{
	return factory_->openDocument(mol::toString(dir),Docs::PREF_TXT,false,d);
}

HRESULT __stdcall Docs::OpenHexEditor(  BSTR f, VARIANT_BOOL vbReadOnly, IMoeDocument** d)
{
	return factory_->openDocument(mol::toString(f),Docs::PREF_HEX,false,d);
}

HRESULT __stdcall Docs::OpenHtmlFrame(  BSTR f,  IMoeDocument** d)
{
	return factory_->openDocument(mol::toString(f),Docs::PREF_HTML,false,d);
}

HRESULT __stdcall Docs::OpenUserForm(  BSTR pathname, IMoeDocument** d )
{
	return factory_->openDocument(mol::toString(pathname),Docs::PREF_FORM,false,d);
}

HRESULT __stdcall Docs::SaveAll()
{
	statusBar()->status(_T("saving all open documents ..."));

	/*
	long cnt = 0;
	HRESULT hr = docs()->get_Count(&cnt);
	if (hr != S_OK )
		return hr;
		*/

	for ( int i = 0; i < size(); i++ )
	{
		punk<IMoeDocument> doc;
		if ( S_OK == docs()->Item(variant(i),&doc) && doc )
		{
			long t;
			if ( doc->get_Type(&t) == S_OK )
			{
				if ( t == MOE_DOCTYPE_DOC || t == MOE_DOCTYPE_FORM )
				{
					doc->Save();
				}
			}
		}
	}
	return S_OK;
}

HRESULT __stdcall Docs::CloseAll()
{
	for ( childlist::iterator it = children_.begin(); it != children_.end(); it++ )
	{
		(*it)->postMessage(WM_CLOSE,0,0);
	}

	return S_OK;
}

HRESULT __stdcall Docs::Remove( VARIANT index )
{
	childlist::iterator& it = iterator(index);
	if ( it == children_.end() )
		return S_FALSE;

	remove(*it);
	return S_OK;
}


HRESULT __stdcall Docs::Rename(VARIANT index, VARIANT newIndex )
{
	if ( newIndex.vt != VT_BSTR )
		return S_FALSE;

	childlist::iterator it = iterator(index);
	if ( it == children_.end() )
		return S_FALSE;

	mol::string newTitle =  mol::valueOf(mol::variant(newIndex));
	rename(*it,newTitle);
	return S_OK;
}


HRESULT __stdcall Docs::Move( VARIANT what, VARIANT to )
{
	
	childlist::iterator it = iterator(what);
	if ( it == children_.end() )
		return S_FALSE;


	childlist::iterator jt = iterator(to);
	if ( jt == children_.end() )
		return S_FALSE;

	if ( it == jt )
		return S_FALSE;

	int pos = key2index(to);
	if ( pos == -1  )
		return S_FALSE;

	move(*it,pos);
	return S_OK;
}

/////////////////////////////////////////////////////////////////////
// helpers
/////////////////////////////////////////////////////////////////////

int Docs::key2index( VARIANT& index )
{
	childlist::iterator it = children_.begin();
	int c = 0;
	
	if ( (index.vt == VT_BSTR) && (index.bstrVal) )
	{
		for ( it; it != children_.end(); it++ )
		{
			IMoeDocument* doc = dynamic_cast<IMoeDocument*>(*it);
			if ( doc )
			{
				mol::bstr path;
				HRESULT hr = doc->get_FilePath(&path);
				int h = _wcsicmp( path.bstr_, index.bstrVal );
				if ( h == 0)
				{				
					return c;
				}
			}
			c++;
		}
	}
	
	c = 0;
	variant i(index);
	i.changeType( VT_INT );
	if ( i.vt != VT_INT )
		return -1;

	if ( i.intVal > (int)children_.size()-1 )
		return -1;
	return i.intVal;
}

/////////////////////////////////////////////////////////////////////

Docs::childlist::iterator Docs::iterator(VARIANT& index)
{
	int pos = key2index(index);
	if ( pos == -1 )
		return children_.end();

	childlist::iterator it = children_.begin();

	for ( int i = 0; i < pos; i++ )
		it++;

	return it;
}

/////////////////////////////////////////////////////////////////////

Docs::childlist::iterator Docs::iterator(mol::MdiChild* mdi)
{
	for ( childlist::iterator it = children_.begin(); it != children_.end(); it++)
	{
		if ( *it == mdi ) 
		{
			return it;
		}
	}
	return children_.end();
}
//////////////////////////////////////////////////////////////////////////////

mol::string Docs::getNewFileName(const mol::string& ext)
{
	mol::TCHAR buf[MAX_PATH];
	::SHGetSpecialFolderPath( *moe(), buf, CSIDL_MYDOCUMENTS, TRUE );

	mol::string p(buf);
	p = mol::Path::addBackSlash(p);

	int i = 1;
	while (i<999)
	{
		mol::ostringstream oss;
		oss << p << _T("NewFile") << i << ext;

		mol::string f = oss.str();

		if ( !mol::Path::exists(f) && key2index(mol::variant(f)) == -1 )
		{
			punk<IMoeDocument> doc;
			if ( S_FALSE == Item( variant(bstr(f)), &doc ) )
			{
				return f;
			}
		}
		i++;
	}
	return p + _T("NewFile.txt");
}