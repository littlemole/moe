#include "StdAfx.h"
#include "ole.h"
#include "moe.h"
#include "xmlui.h"
#include "ole/Rib.h"
#include "MoeBar.h"
#include "win/TaskBar.h"

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


OleChild::Instance* OleChild::CreateInstance( const mol::string& p )
{
	Instance* doc = 0;

	if ( p.size() < 1 )
		return doc;

	if ( !mol::Path::exists(p) )
        return doc;

	if ( mol::Path::isDir(p) )
		return doc;
	
	doc = new Instance;
	doc->filename_ = p;
	statusBar()->status(20);

	doc->AddRef();
	if (!doc->openFile(p))
	{
		doc->destroy();
		doc->Release();
		return 0;
	}

	doc->maximize();
	statusBar()->status(100);
	doc->OnLayout(0,0,0);	

	doc->thumb = mol::taskbar()->addTab( *doc,p );

	return doc;
}

OleChild::Instance* OleChild::CreateInstance( const mol::string& p, CLSID& clsid )
{
	Instance* doc = 0;

	if ( p.size() < 1 )
		return doc;

	doc = new Instance;
	doc->AddRef();
	doc->load(p,clsid);
    return doc;
}



//////////////////////////////////////////////////////////////////////////////

void OleChild::OnDestroy()
{
}


void OleChild::OnPaint()
{
	mol::PaintDC dc(*this);
	thumb.refreshIcon();
}

void OleChild::OnNcDestroy()
{
	// excel specific: don't do this in OnDestroy or garbage layout
	// when excel doc is last document
	docs()->remove(this);

	IMoeDocument* doc = (IMoeDocument*)this;	
	::CoDisconnectObject( doc,0);
	doc->Release();
}


void OleChild::OnMDIActivate(WPARAM unused, HWND activated)
{
	ODBGS("OleChild::OnMDIActivate");

	mol::string filename = getText();
	statusBar()->status( filename );
	tab()->select( *this );

	if ( activated == *this )
	{
		mol::Ribbon::ribbon()->mode(0);
		mol::Ribbon::ribbon()->minimize();
	}
	else 
	{
		mol::Ribbon::ribbon()->maximize();
	}
}

//////////////////////////////////////////////////////////////////////////////
//
// impl
//
//////////////////////////////////////////////////////////////////////////////

void OleChild::load(const mol::string& p, CLSID& clsid)
{
	filename_ = p;

	statusBar()->status(30);
	hWnd_ = create(p,0 ,mol::Rect(0,0,500,500),*moe());

	show(SW_SHOW);
	statusBar()->status(50);

	newObjectFromStorage(clsid);
	statusBar()->status(80);

	maximize();
	statusBar()->status(100);

	OnLayout(0,0,0);	

	thumb = mol::taskbar()->addTab( *this,p );

}

bool OleChild::openFile( const mol::string& path )
{
    CLSID					clsid; 

	filename_ = path;
	mol::bstr bstrFile(path);

	statusBar()->status(20);

	// determine window menu
	windowMenu_ = mol::UI().SubMenu( IDM_MOE ,IDM_VIEW_WINDOWS);

	create(path, 0 ,mol::Rect(0,0,500,500),*moe());
	show(SW_SHOW);

	// prepare bind ctx
	mol::punk<IBindCtx> ctx;
	::CreateBindCtx(0,&ctx);

	statusBar()->status(30);

	if ( mol::Path::ext(path) != _T(".xml" ) )
	if ( this->loadObjectFromMoniker(path))
	{
		return true;
	}

	// check for structured storage
	if ( S_OK == ::StgIsStorageFile(bstrFile) )
	{
		// bind corresponding COM server if avail
		mol::punk<IPersistStorage>	stg;
		mol::punk<IMoniker>			moniker;
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
		mol::punk<IPersistFile> pf(oleObject);
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
				mol::FileInfo& f1 = tmp1.fileInfo();
				mol::FileInfo& f2 = tmp2.fileInfo();
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
	mol::punk<IPersistStorage> ps(oleObject);
	if (!ps)
	{
		statusBar()->status( mol::string(_T("Error saving ")) + filename_ );
		return E_FAIL;
	}

	statusBar()->status(20);

	mol::Storage store;
	HRESULT hr;
	if (store.open(filename_,STGM_READWRITE|STGM_SHARE_EXCLUSIVE|STGM_TRANSACTED))
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