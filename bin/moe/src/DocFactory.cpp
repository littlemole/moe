#include "stdafx.h"
#include "FormEditor.h"
#include "widgets.h"
#include "app.h"
#include "xmlui.h"
#include "DocFactory.h"
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

DocFactory::~DocFactory() 
{
	ODBGS("~DocFactory subobj dead");
}


/////////////////////////////////////////////////////////////////////
// COM
/////////////////////////////////////////////////////////////////////
HRESULT __stdcall DocFactory::newDocument(Docs::InFiles inf, IMoeDocument** d)
{
	if (d)
		*d = 0;

	bool b = false;
	mol::punk<IMoeDocument> doc;
	switch(inf)
	{
		case Docs::PREF_TXT :
		case Docs::PREF_UTF8 :
		{
			b = newFile(&doc);
			break;
		}
		case Docs::PREF_RTF :
		{
			b = newRTFFile(&doc);
			break;
		}
		case Docs::PREF_FORM :
		{
			b = newUFSFile(&doc);
			break;
		}
	}

	if ( b && doc )
		return doc->QueryInterface( IID_IMoeDocument, (void**) d );

	return E_FAIL;
}


HRESULT __stdcall DocFactory::openDocument(Docs::InFiles inf , const mol::string& path, bool readOnly, IMoeDocument** doc)
{
	if (doc)
		*doc = 0;

	return open(-1,path,inf,readOnly,doc);
}



//////////////////////////////////////////////////////////////////////////////




bool DocFactory::newFile(IMoeDocument** doc)
{
	if ( moe()->activeObject)
		moe()->activeObject->OnDocWindowActivate(FALSE);

	mol::string p = docs()->getNewFileName(_T(".txt"));

	Editor::Instance* edit = Editor::CreateInstance( p, false, false );
	if (!edit)
		return false;

	//if ( children_.empty() )
	if ( docs()->size() == 0 )
	{
		tab()->show(SW_SHOW);
		moe()->doLayout();
	}

	mol::MdiChild* c = dynamic_cast<mol::MdiChild*>(edit);
	docs()->children_.push_back( c );
	tab()->insertItem( new mol::TabCtrl::TabCtrlItem(mol::Path::filename(p),p,(LPARAM)(HWND)(*c)) );
	tab()->select((HWND)(*c));

	progress()->show(SW_HIDE);
	if (doc)
		return edit->QueryInterface(IID_IMoeDocument,(void**)doc) == S_OK;
	return true;
}

bool DocFactory::newUFSFile(IMoeDocument** doc)
{
	if ( moe()->activeObject)
		moe()->activeObject->OnDocWindowActivate(FALSE);

	mol::string p = docs()->getNewFileName(_T(".ufs"));

	FormEditor::Instance* edit = FormEditor::CreateInstance( p );
	if (!edit)
		return false;

	if ( docs()->size() == 0 )
	{
		tab()->show(SW_SHOW);
		moe()->doLayout();
	}

	mol::MdiChild* c = dynamic_cast<mol::MdiChild*>(edit);
	docs()->children_.push_back( c  );
	tab()->insertItem( new mol::TabCtrl::TabCtrlItem( mol::Path::filename(p),p, (LPARAM)(HWND)(*c)) );
	tab()->select( (HWND)(*c) );

	progress()->show(SW_HIDE);
	if (doc)
		return edit->QueryInterface(IID_IMoeDocument,(void**)doc) == S_OK;
	return true;
}

bool DocFactory::newRTFFile(IMoeDocument** doc)
{
	if ( moe()->activeObject)
		moe()->activeObject->OnDocWindowActivate(FALSE);

	mol::string p = docs()->getNewFileName(_T(".rtf"));

	RTFEditor::Instance* edit = RTFEditor::CreateInstance( p );
	if (!edit)
		return false;

	if ( docs()->size() == 0 )
	{
		tab()->show(SW_SHOW);
		moe()->doLayout();
	}

	mol::MdiChild* c = dynamic_cast<mol::MdiChild*>(edit);
	docs()->children_.push_back( c  );
	tab()->insertItem( new mol::TabCtrl::TabCtrlItem( mol::Path::filename(p),p, (LPARAM)(HWND)(*c)) );
	tab()->select( (HWND)(*c) );

	progress()->show(SW_HIDE);
	if (doc)
		return edit->QueryInterface(IID_IMoeDocument,(void**)doc) == S_OK;
	return true;
}


bool DocFactory::openTailFile(const mol::string& fp, IMoeDocument** doc)
{

	if ( !mol::Path::exists(fp) )
		return false;

	if ( moe()->activeObject)
		moe()->activeObject->OnDocWindowActivate(FALSE);

	TailEditor::Instance* edit = TailEditor::CreateInstance( fp );
	if (!edit)
		return false;

	if ( docs()->size() )
	{
		tab()->show(SW_SHOW);
		moe()->doLayout();
	}

	mol::MdiChild* c = dynamic_cast<mol::MdiChild*>(edit);
	docs()->children_.push_back( c  );
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

HRESULT __stdcall  DocFactory::open( int index, const mol::string& p, Docs::InFiles pref, bool readOnly, IMoeDocument** doc )
{
	mol::string path = p;
	// valid path ?
	if ( path.size() < 1 )
	{
		mol::ostringstream oss;
		oss << "cancelled loading empty path " << path;
		statusBar()->status(oss.str());
		return E_FAIL;
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
		return E_FAIL;
	}

	// if first document, show tab
	if ( docs()->children_.empty() )
	{
		tab()->show(SW_SHOW);
		moe()->doLayout();
	}

	// insert document into collection
	Docs::childlist::iterator it = docs()->iterator( mol::variant(index) );
	if ( it == docs()->children_.end() )
		docs()->children_.push_back( mdi );
	else
		docs()->children_.insert( it,  mdi );

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
	return S_OK;
}



mol::MdiChild* DocFactory::openPath( const mol::string& p, Docs::InFiles pref, bool readOnly)
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

	if ( pref == Docs::PREF_TAIL )
	{
		return load<TailEditor>(path);
	}
	if ( pref == Docs::PREF_HTML )
	{
		return load<MoeHtmlWnd>(path);
	}
	
	if ( !mol::Path::exists(path) )
	{
		return false;
	}

	if ( pref == Docs::PREF_HEX )
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
	return load<Editor>(path, pref == Docs::PREF_UTF8, readOnly );
}
	

