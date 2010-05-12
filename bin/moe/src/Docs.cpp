#include "stdafx.h"
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

using namespace mol::io;
 
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

HRESULT __stdcall  Docs::Count( long* cnt)
{
	if ( cnt )
	{
		*cnt = (long)children_.size();
	}
	return S_OK;
}


HRESULT __stdcall  Docs::Item( VARIANT index, IDoc** item)
{
	if ( !item )
		return E_INVALIDARG;

	childlist::iterator& it = iterator(index);
	if ( it == children_.end() )
		return S_FALSE;

	IDoc* doc = dynamic_cast<IDoc*>((*it).second);

	HRESULT hr = doc->QueryInterface( IID_IDoc, (void**)item);
	return hr == S_OK ? S_OK : S_FALSE;
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
		moe()->IOleInPlaceFrame_SetBorderSpace(0);
		moe()->doLayout();	
		statusBar()->status(_T(""));
	}
	return S_OK;
}


HRESULT __stdcall Docs::Rename(VARIANT index, VARIANT newIndex )
{
	childlist::iterator it = iterator(index);
	if ( it == children_.end() )
		return S_FALSE;

	(*it).first = newIndex;

	// update tab window
	tab()->rename( mol::valueOf(mol::variant(index)), mol::valueOf(mol::variant(newIndex)), mol::Path::filename(mol::valueOf(mol::variant(newIndex))) );
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

mol::string Docs::getNewFileName()
{
	int i = 1;
	while (i<999)
	{
		mol::ostringstream oss;
		oss << _T("NewFile") << i << _T(".txt");

		punk<IDoc> doc;
		if ( S_FALSE == Item( variant(bstr(oss.str())), &doc ) )
		{
			return oss.str();
		}
		i++;
	}
	return _T("NewFile.txt");
}


bool Docs::newFile(IDoc** doc)
{
	if ( moe()->activeObject)
		moe()->activeObject->OnDocWindowActivate(FALSE);

	mol::string fn = getNewFileName();
	Editor::Instance* edit = Editor::CreateInstance( fn, false, false );
	if (!edit)
		return false;

	if ( children_.empty() )
	{
		tab()->show(SW_SHOW);
		moe()->doLayout();
	}

	children_.push_back( std::make_pair( mol::variant(fn), dynamic_cast<mol::MdiChild*>(edit)) );
	tab()->insertItem( mol::Path::filename(fn),fn,0);
	tab()->select(fn);


	progress()->show(SW_HIDE);
	if (doc)
		return edit->QueryInterface(IID_IDoc,(void**)doc) == S_OK;
	return true;
}

//////////////////////////////////////////////////////////////////////////////
// load a path, create MDI child
//////////////////////////////////////////////////////////////////////////////

bool Docs::open( int index, const mol::string& path, InFiles pref, bool readOnly, IDoc** doc )
{
	mol::MdiChild* mdi = openPath( path, pref, readOnly );
	if (!mdi)
		return false;

	if ( children_.empty() )
	{
		tab()->show(SW_SHOW);
		moe()->doLayout();
	}


	childlist::iterator it = iterator( mol::variant(index) );
	if ( it == children_.end() )
		children_.push_back( std::make_pair(mol::variant(path), mdi) );
	else
		children_.insert( it, std::make_pair(mol::variant(path), mdi) );

	if ( doc )
	{
		IDoc* d = dynamic_cast<IDoc*>(mdi);
		d->QueryInterface( IID_IDoc, (void**) doc );
	}

	tab()->insertItem( mol::Path::filename(path),path,index);

	tab()->select(path);

	mol::Ribbon::ribbon()->addRecentDoc(RibbonMRUItems,path);

	return true;
}

mol::MdiChild* Docs::openPath( const mol::string& path, InFiles pref, bool readOnly)
{
	statusBar()->status(10);
	if ( path.size() < 1 )
	{
		return false;
	}

	// already open?
	punk<IDoc> d;
	if ( S_OK == Item(variant(bstr(path)),&d) )
	{
		if ( IDYES != ::MessageBox( *moe(), _T("close file?"), _T("file already open!"), MB_ICONEXCLAMATION|MB_YESNO ) )
		{
			return false;
		}
 
		if (d)
		{
			d->Close();
			d.release();
		}
		else
			return false;
	}

	// if path is directory, create dir view
	if ( mol::Path::isDir(path) )
	{
		return openPathDir(path);
	}			

	if ( pref == PREF_HTML )
		return openPathHtml(path);

	
	if ( !mol::Path::exists(path) )
	{
		return false;
	}

	if ( pref == PREF_HEX )
		return openPathHex(path,readOnly);


	// if path is file, check filextension
	mol::string ext = mol::Path::ext(path);
    if ( ext.size() > 0 )
	    if ( ext[0] == _T('.') )
		    ext = ext.substr(1);

	// pdf support
	if ( mol::icmp( ext,  _T("pdf") ) == 0 )
	{
		return openPathHtml(path);
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
		return openPathOle(path);
	}

    // is image?
	if ( mol::icmp( ext,  _T("gif"))== 0   ||
		 mol::icmp( ext,  _T("jpg")) == 0  ||
		 mol::icmp( ext,  _T("jpeg"))== 0  ||
		 mol::icmp( ext,  _T("ico"))== 0  ||
		 mol::icmp( ext,  _T("bmp"))== 0   
		)
    {
		return openPathImg(path);
    }

	// ... so try open in text editor
	if ( pref == PREF_UTF8 )
		return openPathUTF8(path,readOnly);
	else
		return openPathText(path,readOnly);
}
	
mol::MdiChild* Docs::openPathText( const mol::string& path, bool readOnly )
{
	// ... so try open in text editor
	if ( moe()->activeObject)
		moe()->activeObject->OnDocWindowActivate(FALSE);

	Editor::Instance* edit = Editor::CreateInstance( path, false, readOnly );
	return dynamic_cast<mol::MdiChild*>(edit);
}
	
	
mol::MdiChild* Docs::openPathUTF8( const mol::string& path, bool readOnly )
{
	// ... so try open in text editor
	if ( moe()->activeObject)
		moe()->activeObject->OnDocWindowActivate(FALSE);

	Editor::Instance* edit = Editor::CreateInstance( path, true, readOnly );
	return dynamic_cast<mol::MdiChild*>(edit);
}

mol::MdiChild* Docs::openPathHex( const mol::string& path, bool readOnly )
{
	// open html
	if ( moe()->activeObject)
		moe()->activeObject->OnDocWindowActivate(FALSE);

	// open in hexedit
	Hex::Instance* hexer = Hex::CreateInstance( path, readOnly );
	return dynamic_cast<mol::MdiChild*>(hexer);
}

mol::MdiChild* Docs::openPathHtml( const mol::string& path)
{
	// open html
	if ( moe()->activeObject)
		moe()->activeObject->OnDocWindowActivate(FALSE);

	MoeHtmlWnd::Instance* html = MoeHtmlWnd::CreateInstance(path);
	return dynamic_cast<mol::MdiChild*>(html);
}


mol::MdiChild* Docs::openPathOle( const mol::string& path )
{
	// open html
	if ( moe()->activeObject)
		moe()->activeObject->OnDocWindowActivate(FALSE);

	OleChild::Instance* oc = OleChild::CreateInstance(path);
	return dynamic_cast<mol::MdiChild*>(oc);
}



mol::MdiChild* Docs::openPathImg( const mol::string& path )
{
	// open html
	if ( moe()->activeObject)
		moe()->activeObject->OnDocWindowActivate(FALSE);

	ImgViewer::Instance* iv = ImgViewer::CreateInstance(path);
    return dynamic_cast<mol::MdiChild*>(iv);
}



mol::MdiChild* Docs::openPathDir( const mol::string& path )
{
	// open html
	if ( moe()->activeObject)
		moe()->activeObject->OnDocWindowActivate(FALSE);

	DirChild::Instance* dc = DirChild::CreateInstance(path);
	return dynamic_cast<mol::MdiChild*>(dc);
}