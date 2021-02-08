#include "StdAfx.h"
#include "ole.h"
#include "moe.h"
#include "docs.h"
#include "MoeBar.h"
//#include "xmlui.h"

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


OleChild::Instance* OleChild::CreateInstance( const std::wstring& p )
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

OleChild::Instance* OleChild::CreateInstance( const std::wstring& p, CLSID& clsid )
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

handle_msg(&OleChild::OnDestroy,WM_DESTROY)
void OleChild::OnDestroy()
{
}


//disabled
//handle_msg(&OleChild::OnPaint, WM_PAINT)
void OleChild::OnPaint()
{
	mol::PaintDC dc(*this);
	thumb.refreshIcon();
}

handle_msg(&OleChild::OnNcDestroy, WM_NCDESTROY)
void OleChild::OnNcDestroy()
{
	// excel specific: don't do this in OnDestroy or garbage layout
	// when excel doc is last document
	docs()->remove(this);
	thumb.destroy();
	IMoeDocument* doc = (IMoeDocument*)this;	
	::CoDisconnectObject( doc,0);
	doc->Release();	
}


handle_msg(&OleChild::OnMDIActivate, WM_MDIACTIVATE)
void OleChild::OnMDIActivate(WPARAM unused, HWND activated)
{
	ODBGS("OleChild::OnMDIActivate");

	std::wstring filename = getText();
	statusBar()->status( filename );
	tab()->select( *this );

	if ( activated == *this )
	{
		//ribbon()->setAppMode("Img");
		::ShowWindow(*ribbon(), SW_HIDE);
	}
	else 
	{
		::ShowWindow(*ribbon(), SW_SHOW);
		//		mol::Ribbon::ribbon()->maximize();
	}
}

handle_cmd(&OleChild::OnSave, IDM_FILE_SAVE)
void OleChild::OnSave()
{
	if (oleObject)
		return;

	IOleClientSite_SaveObject();
}

handle_cmd(&OleChild::OnSaveAs, IDM_FILE_SAVE_AS)
void OleChild::OnSaveAs()
{
	if (oleObject)
		return;

	oleTargetExec(OLECMDID_SAVECOPYAS, OLECMDEXECOPT_PROMPTUSER);
}

handle_cmd(&OleChild::OnPrint, IDM_FILE_PRINT)
void OleChild::OnPrint()
{
	if (oleObject)
		return;

	oleTargetExec(OLECMDID_PRINT, OLECMDEXECOPT_PROMPTUSER);
}

handle_cmd(&OleChild::OnCut, IDM_EDIT_CUT)
void OleChild::OnCut()
{
	if (oleObject)
		return;

	oleTargetExec(OLECMDID_CUT, OLECMDEXECOPT_PROMPTUSER);
}

handle_cmd(&OleChild::OnCopy, IDM_EDIT_COPY)
void OleChild::OnCopy()
{
	if (oleObject)
		return;

	oleTargetExec(OLECMDID_COPY, OLECMDEXECOPT_PROMPTUSER);
}

handle_cmd(&OleChild::OnPaste, IDM_EDIT_PASTE)
void OleChild::OnPaste()
{
	if (oleObject)
		return;

	oleTargetExec(OLECMDID_PASTE, OLECMDEXECOPT_PROMPTUSER);
}

handle_cmd(&OleChild::OnUndo, IDM_EDIT_UNDO)
void OleChild::OnUndo()
{
	if (oleObject)
		return;

	oleTargetExec(OLECMDID_UNDO, OLECMDEXECOPT_PROMPTUSER);
}

handle_cmd(&OleChild::OnRedo, IDM_EDIT_REDO)
void OleChild::OnRedo()
{
	if (oleObject)
		return;

	oleTargetExec(OLECMDID_REDO, OLECMDEXECOPT_PROMPTUSER);
}


handle_cmd(&OleChild::OnCloseAll, IDM_VIEW_CLOSEALL)



//////////////////////////////////////////////////////////////////////////////
//
// impl
//
//////////////////////////////////////////////////////////////////////////////

void OleChild::load(const std::wstring& p, CLSID& clsid)
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

bool OleChild::openFile( const std::wstring& path )
{
    CLSID					clsid; 

	filename_ = path;
	mol::bstr bstrFile(path);

	statusBar()->status(20);

	// determine window menu
	windowMenu_ = mol::UI().SubMenu( IDM_MOE ,IDM_VIEW_WINDOWS);

	create(path,  0 /*(HMENU)IDM_MOE*/ ,mol::Rect(0,0,500,500),*moe());
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

	// special ppt hack. it doesn't work :-(
	/*
	std::wstring ext = mol::Path::ext(filename_);
	if (ext == L".pptx" || ext == L".pptm")
	{
		mol::punk<IDispatch> disp(oleObject);
		if (disp)
		{
			//mol::io::ShellFileOp fo;
			//fo.remove(*this, filename_);
			const int dispid_saveas = 0x000007f4;
			mol::disp_invoke(disp, dispid_saveas, mol::variant(filename_), mol::variant(25), mol::variant(-2));
			statusBar()->status(80);
			statusBar()->status(std::wstring(_T("saved file ")) + filename_);
			return 	S_OK;
		}
		statusBar()->status(std::wstring(_T("Error saving ")) + filename_);
		return E_FAIL;
	}
	*/

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
		statusBar()->status( std::wstring( _T("Error saving ")) + filename_ );
		return E_FAIL;
	}

	// check for structured storage
	mol::punk<IPersistStorage> ps(oleObject);
	if (!ps)
	{
		statusBar()->status( std::wstring(_T("Error saving ")) + filename_ );
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
			statusBar()->status( std::wstring(_T("Error saving ")) + filename_ );
			return hr;
		}

		hr = store->SetClass(clsid);
		if ( hr != S_OK )
		{
			statusBar()->status( std::wstring(_T("Error saving ")) + filename_ );
			return hr;
		}

		statusBar()->status(40);

		hr = ps->Save(store,FALSE);
		if ( hr != S_OK )
		{
			statusBar()->status( std::wstring(_T("Error saving ")) + filename_ );
			return hr;
		}

		statusBar()->status(90);

		hr = ps->SaveCompleted(store);
		if ( hr != S_OK )
		{
			statusBar()->status( std::wstring(_T("Error saving ")) + filename_ );
			return hr;
		}

		statusBar()->status(100);

		hr = store->Commit(0);
		if ( hr != S_OK )
		{
			statusBar()->status( std::wstring( _T("Error saving ")) + filename_ );
			return hr;
		}

	}
	statusBar()->status( std::wstring(_T("saved file ")) + filename_ );
	return 	S_OK ;
}

void OleChild::OnLoadProgress(int n)
{
	// on loadprogress is called from base class during loading
	// steps are expected from 1 .. 6 
	statusBar()->status(40+(n*10));
}