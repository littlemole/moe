#include "stdafx.h"
#include "FormEditor.h" // keep this one include at top ...
#include "TailEditor.h"
#include "Editor.h"
#include "Img.h"
#include "Dir3.h"
#include "ScpDir.h"
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

#include "tcp/sockets.h"
#include "ssh/ssh.h"
#include "ssh/scp.h"
#include "ssh/sftp.h"

#include "../../ax/ssh/ssh_h.h"




// file opening helpers

template<class T>
mol::MdiChild* load( const mol::string& path, long enc, bool readOnly )
{
	typename T::Instance* t = T::CreateInstance( path, enc, readOnly );
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

class WaitCursor
{
public:
	WaitCursor()
	{
		cursor_ = ::SetCursor(::LoadCursor(NULL, IDC_WAIT));
	}

	~WaitCursor()
	{
		 ::SetCursor(cursor_);
	}

private:
	HCURSOR cursor_;
};

/////////////////////////////////////////////////////////////////////

class MoeEditorDocumentFactory : public IMoeDocumentFactory
{
public:

	MoeEditorDocumentFactory(long enc, bool readOnly);
	virtual ~MoeEditorDocumentFactory();
	virtual mol::MdiChild* openDocument( const mol::string& dir);

private:
	long enc_;
	bool readOnly_;
};


MoeEditorDocumentFactory::MoeEditorDocumentFactory(long enc, bool readOnly) 
	: enc_(enc), readOnly_(readOnly)
{}

MoeEditorDocumentFactory::~MoeEditorDocumentFactory()
{}

mol::MdiChild* MoeEditorDocumentFactory::openDocument( const mol::string& path)
{
	Editor::Instance* t = Editor::CreateInstance( path, enc_, readOnly_ );
	return dynamic_cast<mol::MdiChild*>(t);
}

/////////////////////////////////////////////////////////////////////

class MoeTailEditorDocumentFactory : public IMoeDocumentFactory
{
public:

	MoeTailEditorDocumentFactory(long enc) : enc_(enc) {}
	virtual ~MoeTailEditorDocumentFactory() {}
	virtual mol::MdiChild* openDocument( const mol::string& path)
	{
		TailEditor::Instance* t = TailEditor::CreateInstance( path );
		return dynamic_cast<mol::MdiChild*>(t);
	}

private:
	long enc_;
};

class MoeSShEditorDocumentFactory : public IMoeDocumentFactory
{
public:

	MoeSShEditorDocumentFactory();
	virtual ~MoeSShEditorDocumentFactory();
	virtual mol::MdiChild* openDocument( const mol::string& dir);

private:
};


class MoeRTFEditorDocumentFactory : public IMoeDocumentFactory
{
public:

	MoeRTFEditorDocumentFactory();
	virtual ~MoeRTFEditorDocumentFactory();
	virtual mol::MdiChild* openDocument( const mol::string& dir);

private:
};

class MoeDirDocumentFactory : public IMoeDocumentFactory
{
public:

	virtual mol::MdiChild* openDocument( const mol::string& dir);

private:

};



class MoeScpDirDocumentFactory : public IMoeDocumentFactory
{
public:

	virtual mol::MdiChild* openDocument( const mol::string& dir);

private:

};


class MoeImageFactory : public IMoeDocumentFactory
{
public:

	virtual mol::MdiChild* openDocument( const mol::string& dir);

private:

};



class MoeHtmlFactory : public IMoeDocumentFactory
{
public:

	virtual mol::MdiChild* openDocument( const mol::string& dir);

private:

};



class MoeFormFactory : public IMoeDocumentFactory
{
public:

	virtual mol::MdiChild* openDocument( const mol::string& dir);

private:

};



class MoeHexFactory : public IMoeDocumentFactory
{
public:

	virtual mol::MdiChild* openDocument( const mol::string& dir);

private:

};



class MoeOleFactory : public IMoeDocumentFactory
{
public:

	virtual mol::MdiChild* openDocument( const mol::string& dir);

private:

};

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


IMoeDocumentFactory* handleShellPath2(  const mol::string& p )
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
		//TODO : FIXME
		return 0;//new MoeDirDocumentFactory;
	}
	return 0;
}

/*
IMoeDocumentFactory* MoeDocumentFactory::getOpenDocumentFactory( const mol::string& p, MOE_DOCTYPE type, long enc, bool readOnly)
{
	mol::string path = p;
	statusBar()->status(10);

	// shell link ?
	if ( mol::icmp( mol::Path::ext(path), _T(".lnk") ) == 0 )
	{
		path = mol::resolveShortcut(path);
	}

	// shell url ?
	if ( mol::icmp( mol::Path::ext(path), _T(".url") ) == 0 )
	{
		mol::string url = mol::resolveInternetShortcut(path);
		if ( url.empty() )
			return 0;

		if ( url.substr(0,6) == _T("ssh://") || url.substr(0,10) == _T("moe-ssh://") )
		{
			return new MoeSShEditorDocumentFactory;
			//return openSSH( url, type, enc, readOnly );
		}

		return new MoeHtmlFactory;
		//return load<MoeHtmlWnd>(url);
	}	

	// shell special folder stuff ?
	IMoeDocumentFactory* ret =  handleShellPath2(path);
	if ( ret )
	{
		return ret;
	}

	// if path is directory, create dir view
	if ( mol::Path::isDir(path) )
	{
		return new MoeDirDocumentFactory;
	}

	if ( type == MOE_DOCTYPE_TAIL )
	{
		return new MoeTailEditorDocumentFactory(enc);
	}

	if ( type == MOE_DOCTYPE_HTML )
	{
		return new MoeHtmlFactory;
	}
	
	if ( !mol::Path::exists(path) )
	{
		if ( path.substr(0,6) == _T("ssh://") || path.substr(0,10) == _T("moe-ssh://") )
		{
			return new MoeSShEditorDocumentFactory;
		}
		return 0;
	}

	if ( type == MOE_DOCTYPE_HEX )
		return new MoeHexFactory;


	// if path is file, check filextension
	mol::string ext = mol::Path::ext(path);
    if ( ext.size() > 0 )
	    if ( ext[0] == _T('.') )
		    ext = ext.substr(1);

	// pdf support
	if ( mol::icmp( ext,  _T("pdf") ) == 0 )
	{
		return new MoeHtmlFactory;
	}

	// form20 support
	if ( mol::icmp( ext,  _T("ufs") ) == 0 )
	{
		return new MoeFormFactory;
	}

	// rtf support
	if ( mol::icmp( ext, _T("rtf") ) == 0 && type == MOE_DOCTYPE_RTF)
	{
		return new MoeRTFEditorDocumentFactory;
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
		return new MoeOleFactory;
	}

    // is image?
	if ( mol::icmp( ext,  _T("gif"))== 0   ||
		 mol::icmp( ext,  _T("jpg")) == 0  ||
		 mol::icmp( ext,  _T("jpeg"))== 0  ||
		 mol::icmp( ext,  _T("ico"))== 0  ||
		 mol::icmp( ext,  _T("bmp"))== 0   
		)
    {
		return new MoeImageFactory;
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

	std::string sniff = is.str();

	mol::FileEncoding e;
	DWORD cp = e.investigate(sniff);
	if ( cp == CP_WINUNICODE )
	{
		enc = CP_WINUNICODE;
	}
	if ( cp == CP_UTF8 )
	{
		enc = CP_UTF8;
	}

	if ( e.isBinary() )
	{
		return new MoeHexFactory;
	}

	// ... so try open in text editor
	return new MoeEditorDocumentFactory(enc,readOnly);
}

*/

/////////////////////////////////////////////////////////////////////

DocFactory::~DocFactory() 
{
	ODBGS("~DocFactory subobj dead");
}


/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////


HRESULT __stdcall DocFactory::newDocument(MOE_DOCTYPE typ, IMoeDocument** d)
{
	if (d)
		*d = 0;

	switch(typ)
	{
		case MOE_DOCTYPE_DOC :
		{
			mol::string p = docs()->getNewFileName(_T(".txt"));
			return createFile<Editor>(p,d);
		}
		case MOE_DOCTYPE_RTF :
		{
			mol::string p = docs()->getNewFileName(_T(".rtf"));
			return createFile<RTFEditor>(p,d);
		}
		case MOE_DOCTYPE_FORM :
		{
			mol::string p = docs()->getNewFileName(_T(".ufs"));
			return createFile<FormEditor>(p,d);
		}
	}

	return E_FAIL;
}

/////////////////////////////////////////////////////////////////////

HRESULT __stdcall  DocFactory::openDocument( const mol::string& p, MOE_DOCTYPE typ, long enc, bool readOnly, IMoeDocument** doc )
{
	mol::string path = p;

	// deactive any active object
	if ( moe()->activeObject)
		moe()->activeObject->OnDocWindowActivate(FALSE);

	// try to load and create mdi child 
	mol::MdiChild* mdi = documentFactory( path, typ, enc,readOnly );
	if (!mdi)
	{
		// failed to load
		if ( moe()->activeObject)
			moe()->activeObject->OnDocWindowActivate(TRUE);

		mol::punk<IErrorInfo> ei;
		if ( S_OK == ::GetErrorInfo(0,&ei) )
		{
			mol::bstr desc;
			HRESULT hr = ei->GetDescription(&desc);

			mol::bstr src;
			hr = ei->GetSource(&src);

			mol::ostringstream oss;
			oss << _T(" failed to load ") << path << _T(" ") << desc;
			statusBar()->status( oss.str() );
		}
		else
		{
			mol::ostringstream oss;
			oss << _T(" failed to load ") << path;
			statusBar()->status( oss.str() );
		}
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



/////////////////////////////////////////////////////////////////////


class ComSSHErr
{};

/////////////////////////////////////////////////////////////////////



mol::MdiChild* DocFactory::openSSH(const mol::string& path,MOE_DOCTYPE type, long enc, bool readOnly)
{
	WaitCursor wc;

	mol::Uri uri(mol::toUTF8(path));
	std::string host = uri.getHost();
	int port = uri.getPort();
	std::string p = uri.getPath();

	if ( !host.empty() && !path.empty() )
	{
			mol::punk<ISSH> ssh;
			HRESULT hr = ssh.createObject(CLSID_SSH);
			if (hr!=S_OK)
				return 0;

			::CoAllowSetForegroundWindow(ssh,0);

			mol::punk<ISSHConnection> conn;
			hr = ssh->Connect( mol::bstr(mol::fromUTF8(uri.getHost())),uri.getPort(),&conn);
			if (hr!=S_OK)
			{
				return 0;
			}

			mol::punk<ISFTP> sftp;
			hr = conn->get_SFTP(&sftp);
			if (hr!=S_OK)
				return 0;

			mol::ostringstream oss2;
			oss2 << _T("retrieving: ") << mol::fromUTF8(host) << _T(":") << port;
			statusBar()->status(oss2.str());

			mol::punk<IRemoteFile> rf;
			hr = sftp->Stat( mol::bstr(mol::fromUTF8(p)), &rf);
			if (hr!=S_OK)
				return 0;

			VARIANT_BOOL vb;
			hr = rf->get_IsDir(&vb);
			if (hr!=S_OK)
				return 0;

			if ( vb == VARIANT_TRUE )
			{
				return load<ScpDirChild>(path);
			}

			return load<Editor>(path,enc,readOnly);
	}
	return 0;
}



mol::MdiChild* DocFactory::documentFactory( const mol::string& p,MOE_DOCTYPE type, long enc, bool readOnly)
{
	mol::string path = p;
	statusBar()->status(10);

	// shell link ?
	if ( mol::icmp( mol::Path::ext(path), _T(".lnk") ) == 0 )
	{
		path = mol::resolveShortcut(path);
	}

	// shell url ?
	if ( mol::icmp( mol::Path::ext(path), _T(".url") ) == 0 )
	{
		mol::string url = mol::resolveInternetShortcut(path);
		if ( url.empty() )
			return 0;

		if ( url.substr(0,6) == _T("ssh://") || url.substr(0,10) == _T("moe-ssh://") )
		{
			return openSSH( url, type, enc, readOnly );
		}

		return load<MoeHtmlWnd>(url);
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

	if ( type == MOE_DOCTYPE_TAIL )
	{
		return load<TailEditor>(path);
	}
	if ( type == MOE_DOCTYPE_HTML )
	{
		return load<MoeHtmlWnd>(path);
	}
	
	if ( !mol::Path::exists(path) )
	{
		if ( path.substr(0,6) == _T("ssh://") || path.substr(0,10) == _T("moe-ssh://") )
		{
			return openSSH( path, type, enc, readOnly );
		}
	}

	if ( type == MOE_DOCTYPE_HEX )
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
	if ( mol::icmp( ext, _T("rtf") ) == 0 && type == MOE_DOCTYPE_RTF)
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

	std::string sniff = is.str();

	mol::FileEncoding e;
	DWORD cp = e.investigate(sniff);
	if ( cp == CP_WINUNICODE )
	{
		enc = CP_WINUNICODE;
	}
	if ( cp == CP_UTF8 )
	{
		enc = CP_UTF8;
	}

	if ( e.isBinary() )
	{
		return load<Hex>(path,readOnly);
	}

	// ... so try open in text editor
	return load<Editor>(path, enc, readOnly );
}
	
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

void DocFactory::updateUI(const mol::string& p, mol::MdiChild* c)
{
	if ( docs()->size() == 0 )
	{
		tab()->show(SW_SHOW);
		//moe()->doLayout();
	}
		
	docs()->children_.push_back( c );
	tab()->insertItem( new mol::TabCtrl::TabCtrlItem(mol::Path::filename(p),p,(LPARAM)(HWND)(*c)) );
	tab()->select((HWND)(*c));

	progress()->show(SW_HIDE);

	mol::Ribbon::ribbon()->addRecentDoc(RibbonMRUItems,p);
	moe()->doLayout();
	moe()->redraw();
}
