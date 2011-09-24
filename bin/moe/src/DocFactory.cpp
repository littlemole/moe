#include "stdafx.h"
#include "FormEditor.h" // keep this one include at top ...
#include "TailEditor.h"
#include "Editor.h"
#include "Img.h"
#include "Dir3.h"
#include "Form.h"
#include "rtf.h"
#include "hex.h"
#include "html.h"
#include "ole.h"
#include "rtf.h"
#include "moe.h"
#include "xmlui.h"
#include "ribbonres.h"
#include "DocFactory.h"

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

DocFactory::~DocFactory() 
{
	ODBGS("~DocFactory subobj dead");
}


/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////


HRESULT __stdcall DocFactory::newDocument(Docs::InFiles inf, IMoeDocument** d)
{
	if (d)
		*d = 0;

	switch(inf)
	{
		case Docs::PREF_TXT :
		case Docs::PREF_UTF8 :
		{
			mol::string p = docs()->getNewFileName(_T(".txt"));
			return createFile<Editor>(p,d);
		}
		case Docs::PREF_RTF :
		{
			mol::string p = docs()->getNewFileName(_T(".rtf"));
			return createFile<RTFEditor>(p,d);
		}
		case Docs::PREF_FORM :
		{
			mol::string p = docs()->getNewFileName(_T(".ufs"));
			return createFile<FormEditor>(p,d);
		}
	}

	return E_FAIL;
}

/////////////////////////////////////////////////////////////////////

HRESULT __stdcall  DocFactory::openDocument( const mol::string& p, Docs::InFiles pref, bool readOnly, IMoeDocument** doc )
{
	mol::string path = p;

	// deactive any active object
	if ( moe()->activeObject)
		moe()->activeObject->OnDocWindowActivate(FALSE);

	// try to load and create mdi child 
	mol::MdiChild* mdi = documentFactory( path, pref, readOnly );
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

	updateUI(path,mdi);



	// deliver return value if desired
	if ( doc )
	{
		IMoeDocument* d = dynamic_cast<IMoeDocument*>(mdi);
		d->QueryInterface( IID_IMoeDocument, (void**) doc );
	}

	statusBar()->status(path);
	return S_OK;
}


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// Document from existing file factory impl
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


// file opening helpers

template<class T>
mol::MdiChild* load( const mol::string& path, bool utf8, bool readOnly )
{
	typename T::Instance* t = T::CreateInstance( path, utf8, readOnly );
	return dynamic_cast<mol::MdiChild*>(t);
}

template<class T>
mol::MdiChild* load( const mol::string& path, bool readOnly )
{
	typename T::Instance* t = T::CreateInstance( path, readOnly );
	return dynamic_cast<mol::MdiChild*>(t);
}

template<class T>
mol::MdiChild* load( const mol::string& path)
{
	typename T::Instance* t = T::CreateInstance( path );
	return dynamic_cast<mol::MdiChild*>(t);
}

/////////////////////////////////////////////////////////////////////

mol::MdiChild* handleShellPath(  const mol::string& p )
{
	mol::string path = p;
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
	return 0;
}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

mol::MdiChild* DocFactory::documentFactory( const mol::string& p, Docs::InFiles pref, bool readOnly)
{
	mol::string path = p;
	statusBar()->status(10);

	// shell link ?
	if ( mol::icmp( mol::Path::ext(path), _T(".lnk") ) == 0 )
	{
		path = mol::resolveShortcut(path);
	}

	// shell special folder stuff ?
	mol::MdiChild* ret =  handleShellPath(path);
	if ( ret )
	{
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

	// assuming text so far - sniff encoding, try to detect binaries ...
	std::stringstream is;
	mol::filestream in;
	in.open( mol::tostring(p),GENERIC_READ,FILE_SHARE_READ,0,OPEN_EXISTING);

    char buf[1024];
    if ( !in.eof() )
    {
        in.read(buf,1023);
		is.write(buf,in.gcount());
    }
	in.close();

	mol::FileEncoding e;
	DWORD cp = e.investigate(is.str());
	if ( cp == CP_WINUNICODE )
	{
		pref = Docs::PREF_TXT;
	}

	if ( e.isBinary() )
	{
		return load<Hex>(path,readOnly);
	}

	// ... so try open in text editor
	return load<Editor>(path, pref == Docs::PREF_UTF8, readOnly );
}
	
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

void DocFactory::updateUI(const mol::string& p, mol::MdiChild* c)
{
	if ( docs()->size() == 0 )
	{
		tab()->show(SW_SHOW);
		moe()->doLayout();
	}
		
	docs()->children_.push_back( c );
	tab()->insertItem( new mol::TabCtrl::TabCtrlItem(mol::Path::filename(p),p,(LPARAM)(HWND)(*c)) );
	tab()->select((HWND)(*c));

	progress()->show(SW_HIDE);

	mol::Ribbon::ribbon()->addRecentDoc(RibbonMRUItems,p);

}


	/*
	// if first document, show tab
	if ( docs()->children_.empty() )
	{
		tab()->show(SW_SHOW);
		moe()->doLayout();
	}

	// insert document into collection
	docs()->children_.push_back( mdi );

	// update child selector tab window
	tab()->insertItem( new mol::TabCtrl::TabCtrlItem( mol::Path::filename(path),path, (LPARAM)(HWND)(*mdi) ) );
	tab()->select( (HWND)(*mdi) );

	// add document to ribbon recent docs
	mol::Ribbon::ribbon()->addRecentDoc(RibbonMRUItems,path);
	*/