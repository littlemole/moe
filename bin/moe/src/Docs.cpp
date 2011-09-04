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
#include "TailEditor.h"
#include "rtf.h"
#include "hex.h"
#include "html.h"
#include "ole.h"
#include "rtf.h"
#include "ribbonres.h"


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
				Ribbon::ribbon()->mode(0);
				Ribbon::ribbon()->maximize();
				moe()->doLayout();	
				moe()->redraw();
				statusBar()->status(_T(""));
			}
			return;
		}
	}
}

void Docs::rename( mol::MdiChild* mdi, const mol::string& path )
{
	// update tab window
	tab()->rename( (HWND)(*mdi), path, mol::Path::filename(path) );

	// update taskbar
	taskbar()->renameTab( ((HWND)(*mdi)), path );
}

void Docs::move( mol::MdiChild* mdi, int pos )
{
	// get index of document to be moved in tab ctrl
	int index = tab()->index((HWND)(*mdi));

	// get iter for the document where to move to
	childlist::iterator it = iterator(mol::variant(pos));

	// update the win7 taskbar document order
	taskbar()->moveTab( (HWND)(*mdi), (HWND)(**it) );
	
	// get the tab to be moved's item and clone it
	mol::TabCtrl::TabCtrlItem* c = (mol::TabCtrl::TabCtrlItem*) tab()->getTabCtrlItem(index);
	mol::TabCtrl::TabCtrlItem* nc = new mol::TabCtrl::TabCtrlItem( c->title, c->tooltip, c->lparam );

	// update the tab ctrl	(remove and reinsert)
	tab()->remove( (HWND)(*mdi) );
	tab()->insertItem(nc, pos );
	tab()->select((HWND)(*mdi));

	// update our internal document collection to match order of tab ctrl (and win7 taskbar, if any)
	remove(mdi);

	it = iterator(mol::variant(pos));
	this->children_.insert(it,mdi);

	mdi->activate();
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


HRESULT __stdcall Docs::NewRTFDocument(IMoeDocument** d)
{
	if (d)
		*d = 0;

	mol::punk<IMoeDocument> doc;
	bool b = newRTFFile(&doc);
	if (!b || !doc)
		return E_FAIL;

	if ( d )
		return doc->QueryInterface( IID_IMoeDocument, (void**) d );
	return S_OK;
}



HRESULT __stdcall Docs::OpenTailDocument(BSTR fp, IMoeDocument** d)
{
	if (d)
		*d = 0;

	if(!fp)
		return E_INVALIDARG;

	mol::punk<IMoeDocument> doc;
	bool b = openTailFile(mol::toString(fp),&doc);
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

	//(*it).first = newIndex;
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

	mol::MdiChild* c = dynamic_cast<mol::MdiChild*>(edit);
	children_.push_back( c );
	tab()->insertItem( new mol::TabCtrl::TabCtrlItem(mol::Path::filename(p),p,(LPARAM)(HWND)(*c)) );
	tab()->select((HWND)(*c));

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

	mol::MdiChild* c = dynamic_cast<mol::MdiChild*>(edit);
	children_.push_back( c  );
	tab()->insertItem( new mol::TabCtrl::TabCtrlItem( mol::Path::filename(p),p, (LPARAM)(HWND)(*c)) );
	tab()->select( (HWND)(*c) );

	progress()->show(SW_HIDE);
	if (doc)
		return edit->QueryInterface(IID_IMoeDocument,(void**)doc) == S_OK;
	return true;
}

bool Docs::newRTFFile(IMoeDocument** doc)
{
	if ( moe()->activeObject)
		moe()->activeObject->OnDocWindowActivate(FALSE);

	mol::string p = getNewFileName(_T(".rtf"));

	RTFEditor::Instance* edit = RTFEditor::CreateInstance( p );
	if (!edit)
		return false;

	if ( children_.empty() )
	{
		tab()->show(SW_SHOW);
		moe()->doLayout();
	}

	mol::MdiChild* c = dynamic_cast<mol::MdiChild*>(edit);
	children_.push_back( c  );
	tab()->insertItem( new mol::TabCtrl::TabCtrlItem( mol::Path::filename(p),p, (LPARAM)(HWND)(*c)) );
	tab()->select( (HWND)(*c) );

	progress()->show(SW_HIDE);
	if (doc)
		return edit->QueryInterface(IID_IMoeDocument,(void**)doc) == S_OK;
	return true;
}


bool Docs::openTailFile(const mol::string& fp, IMoeDocument** doc)
{

	if ( !mol::Path::exists(fp) )
		return false;

	if ( moe()->activeObject)
		moe()->activeObject->OnDocWindowActivate(FALSE);

	TailEditor::Instance* edit = TailEditor::CreateInstance( fp );
	if (!edit)
		return false;

	if ( children_.empty() )
	{
		tab()->show(SW_SHOW);
		moe()->doLayout();
	}

	mol::MdiChild* c = dynamic_cast<mol::MdiChild*>(edit);
	children_.push_back( c  );
	tab()->insertItem( new mol::TabCtrl::TabCtrlItem( mol::Path::filename(fp),fp, (LPARAM)(HWND)(*c)) );
	tab()->select( (HWND)(*c) );

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
	/*
	punk<IMoeDocument> d;
	if ( S_OK == Item(variant(bstr(path)),&d) )
	{
		//TODO:fix me
		/*if ( IDYES !=* /// ::MessageBox( *moe(), _T("close file?"), _T("file already open!"), MB_ICONEXCLAMATION); //|MB_YESNO ) )
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
	*/

	// deactive any active object
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
		children_.push_back( mdi );
	else
		children_.insert( it,  mdi );

	// update child selector tab window
	tab()->insertItem( new mol::TabCtrl::TabCtrlItem( mol::Path::filename(path),path, (LPARAM)(HWND)(*mdi) ),index);
	tab()->select( (HWND)(*mdi) );

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

	if ( pref == PREF_TAIL )
	{
		return load<TailEditor>(path);
	}
	if ( pref == PREF_HTML )
	{
		return load<MoeHtmlWnd>(path);
	}
	
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

	// rtf support
	if ( mol::icmp( ext, _T("rtf") ) == 0 && pref == Docs::PREF_RTF)
	{
		return load<RTFEditor>(path);
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
	

