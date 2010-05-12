#include "StdAfx.h"
#include "ole.h"
#include "moe.h"
#include "xmlui.h"
#include "ole/Rib.h"
#include "MoeBar.h"

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

using namespace mol::io;

OleChild::OleChild( ) 
{
	eraseBackground_ = 1;
    wndClass().setIcon(moe()->icon); 
	wndClass().hIconSm(moe()->icon); 
}

//////////////////////////////////////////////////////////////////////////////

OleChild::~OleChild() 
{
	ODBGS("~OleChild dies");
};


OleChild::Instance* OleChild::CreateInstance( const mol::string& dir )
{
	Instance* doc = 0;

	if ( dir.size() < 1 )
		return doc;

	mol::string p(dir);
	if ( !mol::Path::exists(p) )
        return doc;

	if ( mol::Path::isDir(p) )
		return doc;
	
	doc = new Instance;

	statusBar()->status(20);

	doc->AddRef();
	if (!doc->openFile(p))
	{
		doc->destroy();
		doc->Release();
		return 0;
	}

	doc->maximize();
	doc->OnLayout(0,0,0);	
	return doc;
}

OleChild::Instance* OleChild::CreateInstance( const mol::string& dir, CLSID& clsid )
{
	Instance* doc = 0;

	if ( dir.size() < 1 )
		return doc;

	mol::string p(dir);
	doc = new Instance;

	doc->AddRef();
	doc->create(p,0 ,Rect(0,0,500,500),*moe());
	doc->show(SW_SHOW);
	doc->newObjectFromStorage(clsid);

	doc->maximize();
	doc->OnLayout(0,0,0);	
    return doc;
}

//////////////////////////////////////////////////////////////////////////////

void OleChild::OnDestroy()
{

	mol::variant v(filename_);
	docs()->Remove(v);
}


void OleChild::OnNcDestroy()
{
	
	::CoDisconnectObject(((IDoc*)this),0);
	((IDoc*)this)->Release();
}


LRESULT OleChild::OnMDIActivate(WPARAM unused, HWND activated)
{
	ODBGS("OleChild::OnMDIActivate");

	if ( mol::Ribbon::ribbon()->enabled() )
	{
		if ( activated == *this )
		{
			statusBar()->status( filename_ );
			tab()->select( filename_ );
			Ribbon::ribbon()->mode(0);
			mol::Ribbon::ribbon()->minimize();

			// delay this or OLE embedded WORD will complaint in some cases
			mol::invoke<OleChild,LRESULT,WPARAM,HWND>( *this, &OleChild::OnMDIActivateLater,unused, activated);	
			return 0;
		}
	}
	BaseWindowType::wndProc( hWnd_, WM_MDIACTIVATE, (WPARAM)unused, (LPARAM)activated );
    return 0;
}

LRESULT OleChild::OnMDIActivateLater(WPARAM unused, HWND activated)
{
	BaseWindowType::wndProc( hWnd_, WM_MDIACTIVATE, (WPARAM)unused, (LPARAM)activated );
    return 0;
}

//////////////////////////////////////////////////////////////////////////////
//
// COM section
//
//////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////

HRESULT __stdcall OleChild::get_Filename( BSTR* filename)
{
	if ( !filename )
		return E_INVALIDARG;

	*filename = 0;
	
	mol::string title = this->getText();
	//title = mol::Path::filename(title);
	*filename = ::SysAllocString( mol::towstring(title).c_str() );
	
	return S_OK;
}

/////////////////////////////////////////////////////////////////////
HRESULT __stdcall OleChild::get_Path( BSTR* path)
{
	if ( !path )
		return E_INVALIDARG;

	*path = 0;
	
	mol::string title = this->getText();

	mol::string tmp(mol::Path::parentDir(title));

	*path = ::SysAllocString( mol::towstring(tmp).c_str() );

	return S_OK;
}


/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////

HRESULT __stdcall OleChild::get_Type(  long* type)
{
	if ( type )
	{
		*type = XMOE_DOCTYPE_OLE;
	}
	return S_OK;
}


HRESULT __stdcall  OleChild::Close()
{

	postMessage(WM_CLOSE,0,0);
	return S_OK;
}

HRESULT __stdcall  OleChild::Activate()
{
	activate();
	return S_OK;
}

bool OleChild::openFile( const mol::string& path )
{
    CLSID					clsid; 

	filename_ = path;
	mol::bstr bstrFile(path);

	statusBar()->status(20);

	// determine window menu
	windowMenu_ = mol::UI().SubMenu( IDM_MOE ,IDM_VIEW_WINDOWS);

	create(path,0 /* IDM_MOE_DIR*/ ,Rect(0,0,500,500),*moe());
	show(SW_SHOW);

	// prepare bind ctx
	punk<IBindCtx> ctx;
	::CreateBindCtx(0,&ctx);

	statusBar()->status(30);

	//TEST
	
	if ( mol::Path::ext(path) != _T(".xml" ) )
	if ( this->loadObjectFromMoniker(path))
	{
		return true;
	}

	//TEST

	// check for structured storage
	if ( S_OK == ::StgIsStorageFile(bstrFile) )
	{
		// bind corresponding COM server if avail
		punk<IPersistStorage>	stg;
		punk<IMoniker>			moniker;
		HRESULT hr = ::CreateFileMoniker(bstrFile, &moniker);
		if ( hr == S_OK )
		{
			hr = moniker->BindToObject(ctx, NULL, IID_IPersistStorage, (void**)&stg);
			if ( hr == S_OK )
			{
				// get classid for bound server
				hr = stg->GetClassID(&clsid);
				if (hr == S_OK)
				{
					statusBar()->status(40);
					moniker.release();
					stg.release();

					// open the structured storage
					mol::Storage			store;
					if ( !store.open(path,STGM_TRANSACTED | STGM_READ | STGM_SHARE_EXCLUSIVE ) )
						return false;
					
					statusBar()->status(45);
					return loadObjectFromStorage(clsid,store);
				}
			}
		}
		moniker.release();
    }
/*
	if ( mol::Path::ext(path) != _T(".xml" ) )
	if ( this->loadObjectFromMoniker(path))
	{
		return true;
	}
*/

	//else check if we can bind to IPersistFile
/*
	punk<IPersistFile> pf;
	hr = moniker->BindToObject(ctx, NULL, IID_IPersistFile, (void**)&pf);
	if ( hr == S_OK )
	{
		// retrieve class id
		hr = pf->GetClassID(&clsid);
		if ( hr == S_OK )
		{
			moniker.release();
			pf.release();


			return loadObjectFromPersistFile(clsid,path);
		}
	}
*/

	// something unknown - instantiate webbrowser control
	// and let it display whatever possible

	return loadObjectFromShell(path);
}

HRESULT __stdcall OleChild::IOleClientSite_SaveObject( )
{ 
	statusBar()->status(10);

	// have we loaded from tmp file 
	if ( !tmpFile_.empty())
	{
		punk<IPersistFile> pf(oleObject);
		if(pf)
		{
			std::wstring ws(mol::towstring(filename_));
			statusBar()->status(20);
			HRESULT hr = pf->Save( ws.c_str(), FALSE );
			statusBar()->status(80);
			if ( hr == S_OK )
			{
				hr = pf->SaveCompleted(ws.c_str());
				statusBar()->status( filename_ + _T(" saved") );
				return hr;
			}
		}
		else
		{
			bool save = false;
			{
				mol::filestream tmp1(mol::tostring(tmpFile_));
				mol::filestream tmp2(mol::tostring(filename_));
				FileInfo& f1 = tmp1.fileInfo();
				FileInfo& f2 = tmp2.fileInfo();
				if ( f1.ftLastWriteTime.dwLowDateTime > f2.ftLastWriteTime.dwLowDateTime )
					save = true;
			}
			
			if ( save )
			{
				mol::io::ShellFileOp sfo;
				if ( 0 == sfo.copy(0,tmpFile_,filename_,FOF_SILENT|FOF_NOCONFIRMATION|FOF_NOCONFIRMMKDIR|FOF_NOERRORUI))
				{
					statusBar()->status( filename_ + _T(" saved") );
					return S_OK;
				}
			}
		}
		statusBar()->status( mol::string( _T("Error saving ")) + filename_ );
		return E_FAIL;
	}

	// check for structured storage
	punk<IPersistStorage> ps(oleObject);
	if (!ps)
	{
		statusBar()->status( mol::string(_T("Error saving ")) + filename_ );
		return E_FAIL;
	}

	statusBar()->status(20);

	mol::Storage store;
	HRESULT hr;
	if (store.open(this->filename_,STGM_READWRITE|STGM_SHARE_EXCLUSIVE|STGM_TRANSACTED))
	{
		statusBar()->status(30);

		CLSID clsid;
		hr = ps->GetClassID(&clsid);
		if ( hr != S_OK )
		{
			statusBar()->status( mol::string(_T("Error saving ")) + filename_ );
			return hr;
		}

		hr = store->SetClass(clsid);
		if ( hr != S_OK )
		{
			statusBar()->status( mol::string(_T("Error saving ")) + filename_ );
			return hr;
		}

		statusBar()->status(40);

		hr = ps->Save(store,FALSE);
		if ( hr != S_OK )
		{
			statusBar()->status( mol::string(_T("Error saving ")) + filename_ );
			return hr;
		}

		statusBar()->status(90);

		hr = ps->SaveCompleted(store);
		if ( hr != S_OK )
		{
			statusBar()->status( mol::string(_T("Error saving ")) + filename_ );
			return hr;
		}

		statusBar()->status(100);

		hr = store->Commit(0);
		if ( hr != S_OK )
		{
			statusBar()->status( mol::string( _T("Error saving ")) + filename_ );
			return hr;
		}

	}
	statusBar()->status( mol::string(_T("saved file ")) + filename_ );
	return 	S_OK ;
}

void OleChild::OnLoadProgress(int n)
{
	// on loadprogress is called from base class during loading
	// steps are expected from 1 .. 6 
	statusBar()->status(40+(n*10));
}