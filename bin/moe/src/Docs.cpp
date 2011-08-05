#include "stdafx.h"
#include "FormEditor.h"
#include "widgets.h"
#include "app.h"
#include "xmlui.h"
#include "Docs.h"
#include "MoeBar.h"
#include "Img.h"
#include "Dir3.h"
#include "Form.h"
#include "Editor.h"
#include "hex.h"
#include "html.h"
#include "ole.h"
#include "ribbonres.h"
#include "ole/Rib.h"


/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////



Docs::Instance* Docs::CreateInstance()
{
	Instance* d = new Instance;
	d->AddRef();
	return d;
}

Docs::~Docs() 
{
	ODBGS("~DOCS subobj dead");
}

/////////////////////////////////////////////////////////////////////

mol::MdiChild* Docs::child( const mol::string& path)
{
	childlist::iterator& it = iterator(mol::variant(path));
	if ( it == children_.end() )
		return 0;

	mol::MdiChild* mdi = dynamic_cast<mol::MdiChild*>((*it).second);

	return mdi;
}


/////////////////////////////////////////////////////////////////////

HRESULT __stdcall  Docs::_NewEnum(IEnumVARIANT** newEnum)
{
	punk<com_obj<enum_variant> > ev = new com_obj<enum_variant>;
	for ( childlist::iterator it = children_.begin(); it != children_.end(); it++)
	{
		mol::variant v( (IDispatch*) (*it).second );
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

	IMoeDocument* doc = dynamic_cast<IMoeDocument*>((*it).second);

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
}

HRESULT __stdcall Docs::New(IMoeDocument** d)
{
	if (d)
		*d = 0;

	mol::punk<IMoeDocument> doc;
	bool b = newFile(&doc);
	if (!b || !doc)
		return E_FAIL;

	if ( d )
		return doc->QueryInterface( IID_IMoeDocument, (void**) d );
	return S_OK;
}


HRESULT __stdcall Docs::NewUserForm(IMoeDocument** d)
{
	if (d)
		*d = 0;

	mol::punk<IMoeDocument> doc;
	bool b = newUFSFile(&doc);
	if (!b || !doc)
		return E_FAIL;

	if ( d )
		return doc->QueryInterface( IID_IMoeDocument, (void**) d );
	return S_OK;
}

HRESULT __stdcall Docs::Open( BSTR fPath, IMoeDocument** d)
{
	if (d)
		*d = 0;

	mol::punk<IMoeDocument> doc;
	open(-1, mol::bstr(fPath).toString(), Docs::PREF_TXT, false,&doc);

	if ( !doc )
		return E_FAIL;

	if (d )
		return doc->QueryInterface( IID_IMoeDocument, (void**) d );

	return S_OK;
}

HRESULT __stdcall Docs::OpenUTF8( BSTR fPath, IMoeDocument** d)
{
	if (d)
		*d = 0;

	mol::punk<IMoeDocument> doc;
	open(-1, mol::bstr(fPath).toString(), Docs::PREF_UTF8, false,&doc);

	if ( !doc )
		return E_FAIL;

	if ( d )
		return doc->QueryInterface( IID_IMoeDocument, (void**) d );	
	return S_OK;
}

HRESULT __stdcall Docs::OpenDir(BSTR dir,  IMoeDocument** d)
{
	if (d)
		*d = 0;

	mol::punk<IMoeDocument> doc;
	open(-1, mol::bstr(dir).toString(), Docs::PREF_TXT, false,&doc);

	if ( !doc )
		return E_FAIL;

	if ( d )
		return doc->QueryInterface( IID_IMoeDocument, (void**) d );

	return S_OK;
}

HRESULT __stdcall Docs::OpenHexEditor(  BSTR f, VARIANT_BOOL vbReadOnly, IMoeDocument** d)
{
	if (d)
		*d = 0;

	mol::punk<IMoeDocument> doc;
	open(-1, mol::bstr(f).toString(), Docs::PREF_HEX, vbReadOnly == VARIANT_TRUE ? true : false,&doc);

	if ( !doc )
		return E_FAIL;

	if(d)
		return doc->QueryInterface( IID_IMoeDocument, (void**) d );
	return S_OK;
}

HRESULT __stdcall Docs::OpenHtmlFrame(  BSTR f,  IMoeDocument** d)
{
	if (d)
		*d = 0;

	mol::punk<IMoeDocument> doc;
	open(-1, mol::bstr(f).toString(), Docs::PREF_HTML, false,&doc);

	if ( !doc )
		return E_FAIL;

	if ( d )
		return doc->QueryInterface( IID_IMoeDocument, (void**) d );

	return S_OK;
}

HRESULT __stdcall Docs::OpenUserForm(  BSTR pathname, IMoeDocument** d )
{
	if (d)
		*d = 0;

	mol::punk<IMoeDocument> doc;
	open(-1, mol::bstr(pathname).toString(), Docs::PREF_FORM, false,&doc);

	if ( !doc )
		return E_FAIL;

	if ( d )
		return doc->QueryInterface( IID_IMoeDocument, (void**) d );

	return S_OK;
}

HRESULT __stdcall Docs::SaveAll()
{
	statusBar()->status(_T("saving all open documents ..."));

	long cnt = 0;
	HRESULT hr = docs()->get_Count(&cnt);
	if (hr != S_OK )
		return hr;

	for ( int i = 0; i < cnt; i++ )
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
		(*it).second->postMessage(WM_CLOSE,0,0);
	}

	return S_OK;
}

HRESULT __stdcall Docs::Remove( VARIANT index )
{
	childlist::iterator& it = iterator(index);
	if ( it == children_.end() )
		return S_FALSE;

	children_.erase(it);

	// update tab window
	tab()->remove( mol::variant(index).toString() );
	if ( children_.empty() )
	{
		tab()->show(SW_HIDE);
		Ribbon::ribbon()->mode(0);
		Ribbon::ribbon()->maximize();
//		moe()->IOleInPlaceFrame_SetActiveObject(0,0);
//		moe()->IOleInPlaceFrame_SetBorderSpace(0);
		//implicit in above: moe()->doLayout();	
//		moe()->redraw();
		statusBar()->status(_T(""));
	}
	return S_OK;
}


HRESULT __stdcall Docs::Rename(VARIANT index, VARIANT newIndex )
{
	if ( newIndex.vt != VT_BSTR )
		return S_FALSE;

	childlist::iterator it = iterator(index);
	if ( it == children_.end() )
		return S_FALSE;

	(*it).first = newIndex;
	mol::string newTitle =  mol::valueOf(mol::variant(newIndex));

	// update tab window
	tab()->rename( mol::valueOf(mol::variant(index)), newTitle, mol::Path::filename(newTitle) );

	// update taskbar
	taskbar()->renameTab( ((HWND)(*it).second), newTitle );
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

	mol::variant   key( (*it).first );
	mol::MdiChild* val( (*it).second );

	children_.erase(it);

	jt = iterator(to);
	if ( jt == children_.end() )
		return S_FALSE;

	mol::MdiChild* mc( (*jt).second );
	taskbar()->moveTab( (HWND)(*val), (HWND)(*mc) );

	tab()->remove( key.toString() );
	children_.insert(jt,std::make_pair( what, val) );

	// update tab window
	int index = tab()->index(mol::variant(to).toString());
	tab()->insertItem( mol::Path::filename( key.toString() ), key.toString(), index );
	tab()->select(key.toString());
	val->activate();


	return S_OK;
}

/////////////////////////////////////////////////////////////////////

int Docs::key2index( VARIANT& index )
{
	childlist::iterator it = children_.begin();
	int c = 0;
	if ( (index.vt == VT_BSTR) && (index.bstrVal) )
	{
		for ( it; it != children_.end(); it++ )
		{
			variant key = (*it).first;
			key.changeType(VT_BSTR);
			if ( key.bstrVal )
			{
				int hr = _wcsicmp( key.bstrVal, index.bstrVal );
				if ( hr == 0)
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

		if ( !mol::Path::exists(f) )
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


bool Docs::newFile(IMoeDocument** doc)
{
	if ( moe()->activeObject)
		moe()->activeObject->OnDocWindowActivate(FALSE);

	mol::string p = getNewFileName(_T(".txt"));

	Editor::Instance* edit = Editor::CreateInstance( p, false, false );
	if (!edit)
		return false;

	if ( children_.empty() )
	{
		tab()->show(SW_SHOW);
		moe()->doLayout();
	}

	children_.push_back( std::make_pair( mol::variant(p), dynamic_cast<mol::MdiChild*>(edit)) );
	tab()->insertItem( mol::Path::filename(p),p);//,0);
	tab()->select(p);

	progress()->show(SW_HIDE);
	if (doc)
		return edit->QueryInterface(IID_IMoeDocument,(void**)doc) == S_OK;
	return true;
}

bool Docs::newUFSFile(IMoeDocument** doc)
{
	if ( moe()->activeObject)
		moe()->activeObject->OnDocWindowActivate(FALSE);

	mol::string p = getNewFileName(_T(".ufs"));

	FormEditor::Instance* edit = FormEditor::CreateInstance( p );
	if (!edit)
		return false;

	if ( children_.empty() )
	{
		tab()->show(SW_SHOW);
		moe()->doLayout();
	}

	children_.push_back( std::make_pair( mol::variant(p), dynamic_cast<mol::MdiChild*>(edit)) );
	tab()->insertItem( mol::Path::filename(p),p);//,0);
	tab()->select(p);


	progress()->show(SW_HIDE);
	if (doc)
		return edit->QueryInterface(IID_IMoeDocument,(void**)doc) == S_OK;
	return true;
}


//////////////////////////////////////////////////////////////////////////////
// load a path, create MDI child
//////////////////////////////////////////////////////////////////////////////

bool Docs::open( int index, const mol::string& p, InFiles pref, bool readOnly, IMoeDocument** doc )
{
	mol::string path = p;
	// valid path ?
	if ( path.size() < 1 )
	{
		mol::ostringstream oss;
		oss << "cancelled loading empty path " << path;
		statusBar()->status(oss.str());
		return false;
	}

	// shell stuff ?
	if ( path.size() > 1 && path.substr(0,2) == _T("::") ) 
	{
		mol::ostringstream oss;
		oss << _T("shell:") << path;
		path = oss.str();
	}
	if ( path.size() > 2 && path.substr(0,3) == _T(":::") ) 
	{
		mol::ostringstream oss;
		oss << _T("shell") << path;
		path = oss.str();
	}

	// shell link ?
	if ( mol::icmp( mol::Path::ext(path), _T(".lnk") ) == 0 )
	{
		path = mol::resolveShortcut(path);
	}


	// already open?
	punk<IMoeDocument> d;
	if ( S_OK == Item(variant(bstr(path)),&d) )
	{
		//TODO:fix me
		/*if ( IDYES !=*/// ::MessageBox( *moe(), _T("close file?"), _T("file already open!"), MB_ICONEXCLAMATION); //|MB_YESNO ) )
		{
			mol::ostringstream oss;
			oss << "file already open!" << path;
			statusBar()->status(oss.str());
			if (d)
			{
				mol::punk<IMoeDocumentView> view;
				HRESULT hr = d->get_View(&view);
				view->Activate();
				view.release();

				if (doc)
				{
					d->QueryInterface( IID_IMoeDocument, (void**) doc );
				}
			}

			return true;
		}

		return false;
	}

	// inactive any active object
	if ( moe()->activeObject)
		moe()->activeObject->OnDocWindowActivate(FALSE);

	// try to load and create mdi child 
	mol::MdiChild* mdi = openPath( path, pref, readOnly );
	if (!mdi)
	{
		// failed to load
		if ( moe()->activeObject)
			moe()->activeObject->OnDocWindowActivate(TRUE);

		mol::ostringstream oss;
		oss << _T(" failed to load ") << path;
		statusBar()->status( oss.str() );
		return false;
	}

	// if first document, show tab
	if ( children_.empty() )
	{
		tab()->show(SW_SHOW);
		moe()->doLayout();
	}

	// insert document into collection
	childlist::iterator it = iterator( mol::variant(index) );
	if ( it == children_.end() )
		children_.push_back( std::make_pair(mol::variant(path), mdi) );
	else
		children_.insert( it, std::make_pair(mol::variant(path), mdi) );

	// update child selector tab window
	tab()->insertItem( mol::Path::filename(path),path,index);
	tab()->select(path);

	// add document to ribbon recent docs
	mol::Ribbon::ribbon()->addRecentDoc(RibbonMRUItems,path);

	// deliver return value if desired
	if ( doc )
	{
		IMoeDocument* d = dynamic_cast<IMoeDocument*>(mdi);
		d->QueryInterface( IID_IMoeDocument, (void**) doc );
	}

	statusBar()->status(path);
	return true;
}



mol::MdiChild* Docs::openPath( const mol::string& p, InFiles pref, bool readOnly)
{
	mol::string path = p;
	statusBar()->status(10);

	// shell stuff ?
	if ( path.size() > 2 && path.substr(0,8) == _T("shell:::") ) 
	{
		// control panel ...
		if ( path == _T("shell:::{26EE0668-A00A-44D7-9371-BEB064C98683}") )
		{
			mol::io::execute_shell(path);
			return 0;
		}
		mol::MdiChild* ret = load<DirChild>(path);		
		return ret;
	}


	// if path is directory, create dir view
	if ( mol::Path::isDir(path) )
	{
		return load<DirChild>(path);
	}			

	if ( pref == PREF_HTML )
		return load<MoeHtmlWnd>(path);

	
	if ( !mol::Path::exists(path) )
	{
		return false;
	}

	if ( pref == PREF_HEX )
		return load<Hex>(path,readOnly);


	// if path is file, check filextension
	mol::string ext = mol::Path::ext(path);
    if ( ext.size() > 0 )
	    if ( ext[0] == _T('.') )
		    ext = ext.substr(1);

	// pdf support
	if ( mol::icmp( ext,  _T("pdf") ) == 0 )
	{
		return load<MoeHtmlWnd>(path);
	}

	// form20 support
	if ( mol::icmp( ext,  _T("ufs") ) == 0 )
	{
		return load<FormEditor>(path);
	}

	// office support
	if ( (S_OK == ::StgIsStorageFile(mol::bstr(path)) ) ||
		 (
			mol::icmp( ext,  _T("xlsx")) == 0  ||
			mol::icmp( ext,  _T("docx")) == 0  ||
			mol::icmp( ext,  _T("pptx")) == 0  ||
			mol::icmp( ext,  _T("xlsm")) == 0  ||
			mol::icmp( ext,  _T("docm")) == 0  ||
			mol::icmp( ext,  _T("pptm")) == 0  
		 )
	   )
	{
		return load<OleChild>(path);
	}

    // is image?
	if ( mol::icmp( ext,  _T("gif"))== 0   ||
		 mol::icmp( ext,  _T("jpg")) == 0  ||
		 mol::icmp( ext,  _T("jpeg"))== 0  ||
		 mol::icmp( ext,  _T("ico"))== 0  ||
		 mol::icmp( ext,  _T("bmp"))== 0   
		)
    {
		return load<ImgViewer>(path);
    }

	// ... so try open in text editor
	return load<Editor>(path, pref == PREF_UTF8, readOnly );
}
	

