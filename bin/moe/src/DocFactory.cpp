#include "stdafx.h"
#include "TailEditor.h"
#include "Editor.h"
#include "Img.h"
#include "Dir3.h"
#include "ScpDir.h"
#include "Form2.h"
#include "rtf.h"
#include "hex.h"
#include "html2.h"
#include "ole.h"
#include "rtf.h"
#include "moe.h"
#include "DocFactory.h"
#include "Docs.h"
#include "tcp/sockets.h"
#include "ssh/ssh.h"
#include "ssh/scp.h"
#include "ssh/sftp.h"

#include "../../ax/ssh/ssh_h.h"




// file opening helpers

template<class T>
mol::MdiChild* load( const std::wstring& path, long enc, bool readOnly )
{
	typename T::Instance* t = T::CreateInstance( path, enc, readOnly );
	return dynamic_cast<mol::MdiChild*>(t);
}

template<class T>
mol::MdiChild* load( const std::wstring& path, bool readOnly )
{
	typename T::Instance* t = T::CreateInstance( path, readOnly );
	return dynamic_cast<mol::MdiChild*>(t);
}

template<class T>
mol::MdiChild* load( const std::wstring& path)
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
	virtual mol::MdiChild* openDocument( const std::wstring& dir);

private:
	long enc_;
	bool readOnly_;
};


MoeEditorDocumentFactory::MoeEditorDocumentFactory(long enc, bool readOnly) 
	: enc_(enc), readOnly_(readOnly)
{}

MoeEditorDocumentFactory::~MoeEditorDocumentFactory()
{}

mol::MdiChild* MoeEditorDocumentFactory::openDocument( const std::wstring& path)
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
	virtual mol::MdiChild* openDocument( const std::wstring& path)
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

	MoeSShEditorDocumentFactory() {};
	virtual ~MoeSShEditorDocumentFactory() {};
	virtual mol::MdiChild* openDocument( const std::wstring& path)
	{
		Editor::Instance* t = Editor::CreateInstance( path );
		return dynamic_cast<mol::MdiChild*>(t);
	}

};


class MoeRTFEditorDocumentFactory : public IMoeDocumentFactory
{
public:

	MoeRTFEditorDocumentFactory() {};
	virtual ~MoeRTFEditorDocumentFactory() {};
	virtual mol::MdiChild* openDocument( const std::wstring& path)
	{
		RTFEditor::Instance* t = RTFEditor::CreateInstance( path );
		return dynamic_cast<mol::MdiChild*>(t);
	}

private:
};

class MoeDirDocumentFactory : public IMoeDocumentFactory
{
public:

	virtual mol::MdiChild* openDocument( const std::wstring& path)
	{
		DirChild::Instance* t = DirChild::CreateInstance( path );
		return dynamic_cast<mol::MdiChild*>(t);
	}
private:

};



class MoeScpDirDocumentFactory : public IMoeDocumentFactory
{
public:

	MoeScpDirDocumentFactory(ISSHConnection* conn)
		:conn_(conn)
	{}

	virtual mol::MdiChild* openDocument( const std::wstring& path)
	{
		ScpDirChild::Instance* t = ScpDirChild::CreateInstance( conn_, path  );
		return dynamic_cast<mol::MdiChild*>(t);
	}

private:
	mol::punk<ISSHConnection> conn_;
};


class MoeImageFactory : public IMoeDocumentFactory
{
public:

	virtual mol::MdiChild* openDocument( const std::wstring& path)
	{
		ImgViewer::Instance* t = ImgViewer::CreateInstance( path );
		return dynamic_cast<mol::MdiChild*>(t);
	}

private:

};



class MoeHtmlFactory : public IMoeDocumentFactory
{
public:

	virtual mol::MdiChild* openDocument( const std::wstring& path)
	{
		MoeHtml2Wnd::Instance* t = MoeHtml2Wnd::CreateInstance( path );
		return dynamic_cast<mol::MdiChild*>(t);
	}

private:

};


class MoeHexFactory : public IMoeDocumentFactory
{
public:

	MoeHexFactory(bool readOnly) 
		: readOnly_(readOnly)
	{}

	~MoeHexFactory()
	{}

	virtual mol::MdiChild* openDocument( const std::wstring& path)
	{
		Hex::Instance* t = Hex::CreateInstance(path,readOnly_);
		return dynamic_cast<mol::MdiChild*>(t);
	}

private:
	bool readOnly_;
};



class MoeOleFactory : public IMoeDocumentFactory
{
public:

	virtual mol::MdiChild* openDocument( const std::wstring& path)
	{
		OleChild::Instance* t = OleChild::CreateInstance( path );
		return dynamic_cast<mol::MdiChild*>(t);
	}

private:

};

/////////////////////////////////////////////////////////////////////


IMoeDocumentFactory* handleShellPath(  const std::wstring& p )
{
	std::wstring path = p;
	if ( path.size() > 1 && path.substr(0,2) == _T("::") ) 
	{
		std::wostringstream oss;
		oss << _T("shell:") << path;
		path = oss.str();
	}
	if ( path.size() > 2 && path.substr(0,3) == _T(":::") ) 
	{
		std::wostringstream oss;
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
		return new MoeDirDocumentFactory;
	}
	return 0;
}

IMoeDocumentFactory* openSSHfactory(const std::wstring& path)
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

			std::wostringstream oss2;
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
				return new MoeScpDirDocumentFactory(conn);
			}

			return new MoeSShEditorDocumentFactory;
	}
	return 0;
}



IMoeDocumentFactory* MoeDocumentFactory::getOpenDocumentFactory( const std::wstring& p, MOE_DOCTYPE type, long enc, bool readOnly)
{
	std::wstring path = p;
	statusBar()->status(10);

	// shell link ?
	if ( mol::icmp( mol::Path::ext(path), _T(".lnk") ) == 0 )
	{
		path = mol::resolveShortcut(path);
	}

	// shell url ?
	if ( mol::icmp( mol::Path::ext(path), _T(".url") ) == 0 )
	{
		std::wstring url = mol::resolveInternetShortcut(path);
		if ( url.empty() )
			return 0;

		if ( url.substr(0,6) == _T("ssh://") || url.substr(0,10) == _T("moe-ssh://") )
		{
			return openSSHfactory(url);
		}

		return new MoeHtmlFactory;
	}	

	// shell special folder stuff ?
	IMoeDocumentFactory* ret =  handleShellPath(path);
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
			return openSSHfactory(path);
		}
		//logger(LOGINFO) << "path does not exist : " << mol::tostring(path);
		return 0;
	}

	if ( type == MOE_DOCTYPE_HEX )
		return new MoeHexFactory(readOnly);


	// if path is file, check filextension
	std::wstring ext = mol::Path::ext(path);
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
		//return new MoeFormFactory;
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

	// ... so try open in text editor
	return new MoeEditorDocumentFactory(enc,readOnly);
}



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
			std::wstring p = docs()->getNewFileName(_T(".txt"));
			return createFile<Editor>(p,d);
		}
		case MOE_DOCTYPE_RTF :
		{
			std::wstring p = docs()->getNewFileName(_T(".rtf"));
			return createFile<RTFEditor>(p,d);
		}
		case MOE_DOCTYPE_FORM :
		{
			//std::wstring p = docs()->getNewFileName(_T(".ufs"));
			//return createFile<FormEditor>(p,d);
		}
	}

	return E_FAIL;
}

/////////////////////////////////////////////////////////////////////

HRESULT __stdcall  DocFactory::openDocument( const std::wstring& p, MOE_DOCTYPE typ, long enc, bool readOnly, IMoeDocument** doc )
{
	std::wstring path = p;

	// deactive any active object
	if ( moe()->activeObject)
		moe()->activeObject->OnDocWindowActivate(FALSE);

	std::unique_ptr<IMoeDocumentFactory> factory(MoeDocumentFactory::getOpenDocumentFactory(p,typ,enc,readOnly));
	if(!factory)
		return E_FAIL;

	// try to load and create mdi child 
	mol::MdiChild* mdi = factory->openDocument( path );
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

			std::wostringstream oss;
			oss << _T(" failed to load ") << mol::towstring(path) << _T(" ") << desc.towstring();

			std::wstring str = oss.str();
			statusBar()->status( str );
		}
		else
		{
			std::wostringstream oss;
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
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

void DocFactory::updateUI(const std::wstring& p, mol::MdiChild* c)
{
	if ( docs()->size() == 0 )
	{
		tab()->show(SW_SHOW);
	}
		
	docs()->children_.push_back( c );
	tab()->insertItem( new mol::TabCtrl::TabCtrlItem(mol::Path::filename(p),p,(LPARAM)(HWND)(*c)) );
	tab()->select((HWND)(*c));

	progress()->show(SW_HIDE);

	//mol::Ribbon::ribbon()->addRecentDoc(RibbonMRUItems,p);
	moe()->doLayout();
	moe()->redraw();
}
