#include "stdafx.h"
#include "formeditor.h"
#include "moe.h"
#include "Docs.h"
#include "moebar.h"
#include "xmlui.h"
#include "ole/Rib.h"
#include "win/TaskBar.h"
#include "ribbonres.h"

using namespace mol::win;
using namespace mol::ole;
using namespace mol::io;

mol::TCHAR FormOutFilesFilter[]   = _T("UserFormScript \0*.ufs\0\0");


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// Base Child
//////////////////////////////////////////////////////////////////////////////

FormEditor::FormEditor() 
{
}
//////////////////////////////////////////////////////////////////////////////

FormEditor::~FormEditor() 
{
	ODBGS("~FormEditor dead");
};

//////////////////////////////////////////////////////////////////////////////
FormEditor::Instance* FormEditor::CreateInstance(const mol::string& file)
{
	statusBar()->status(20);

	mol::string p(file);
	if ( mol::Path::exists(p) && mol::Path::isDir(p) )
		return 0;

	Instance* e = new Instance;
	e->AddRef();

	statusBar()->status(75);
	if ( !e->initialize(file) )
	{
		e->destroy();
		return 0;
	}
	statusBar()->status(100);
	return e;
}

bool FormEditor::initialize(const mol::string& p)
{
	// get client rectangle
	mol::Rect r;
	::GetClientRect(mdiParent(),&r);

	// determine window menu
	HMENU m = mol::UI().Menu(IDM_MOE);
	windowMenu_ = mol::UI().SubMenu( IDM_MOE ,IDM_VIEW_WINDOWS);

	statusBar()->status(40);

	// create the win window
	HWND hc = create(p,(HMENU)m,r,*moe());

	// hook up com event handlers
	events.Advise(oleObject);

	// show the window
	show(SW_SHOW);

	statusBar()->status(50);

	sci = oleObject;

	bool createNew = false;

	mol::punk<IScintillAxProperties> props;
	sci->get_Properties(&props);

	props->put_Filename(mol::bstr(p));

	// if file exists, load
	if ( !mol::Path::exists(p) )
		createNew = true;

	// load ?
	props->put_Filename(mol::bstr(p));

	mol::punk<IStorage> src;
	mol::punk<IStorage> store;
	
	HRESULT hr = E_FAIL;

	if ( !createNew )
	{
		hr = ::StgOpenStorage( 
					mol::towstring(p).c_str(), 
					NULL,
					STGM_READ|STGM_SHARE_EXCLUSIVE,
					0,
					0,
					&src);
	}
	if ( hr != S_OK )
	{
		createNew = true;
	}
	else 
	{
		copyStorageTemp(src,&store);
		
		mol::punk<IStream> stream;
		hr = store->OpenStream( L"CONTENT",0,STGM_READWRITE|STGM_SHARE_EXCLUSIVE,0,&stream);
		if ( hr == S_OK )
		{
			ULONG nread = 0;
			DWORD size = 0;

			hr = stream->Read( &size, sizeof(DWORD), &nread);

			if ( hr == S_OK )
			{
				wchar_t* buf = new wchar_t[size];

				hr = stream->Read( buf, size*sizeof(wchar_t), &nread);
				std::wstring ws = std::wstring( buf, size );
				delete[] buf;

				mol::punk<IScintillAxText> txt;
				sci->get_Text(&txt);

				hr = txt->SetText( mol::bstr(ws) );
				hr = sci->SavePoint();
			}
		}


		src.release();
		store.release();
		userForm = UserForm::CreateInstance(p,true);
	}
	if ( createNew == true )
	{
		props->put_Filename(mol::bstr(p));
		userForm = UserForm::CreateInstance(p,true);

	}

	statusBar()->status(80);


	// get default values from config and init scintilla

	moe()->moeConfig->InitializeEditorFromPreferences( (IMoeDocument*)this );


	props->put_ReadOnly( VARIANT_FALSE );

	if ( mol::Ribbon::ribbon()->enabled() )
	{
		props->put_UseContext(VARIANT_FALSE);
	}

	thumb = mol::taskbar()->addTab( *this,p );

	// now maximize the window
	maximize();

	return true;
}

//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
//
// OnDestroy - over and out
//
//////////////////////////////////////////////////////////////////////////////

void FormEditor::OnDestroy()
{
	if ( userForm )
	{
		userForm->Close();
		userForm.release();
	}

	mol::punk<IScintillAxProperties> props;
	HRESULT hr = sci->get_Properties(&props);
	if ( hr != S_OK )
		return ;

	mol::bstr path;
	hr = props->get_Filename(&path);
	if ( hr != S_OK )
		return ;

	docs()->Remove(mol::variant(path));
 	events.UnAdvise(oleObject);
	sci.release();
	return ;
}


//////////////////////////////////////////////////////////////////////////////

LRESULT FormEditor::OnMDIActivate(WPARAM unused, HWND activated)
{
	ODBGS("Editor::OnMDIActivate");
	if ( activated == hWnd_ )
	{
		userForm->Show();
		mol::invoke(*((Editor*)this),&Editor::OnMDIActivate,unused,activated);

	}
	else
	{
		userForm->Hide();
		BaseWindowType::wndProc( hWnd_, WM_MDIACTIVATE, (WPARAM)unused, (LPARAM)activated );
	}
//	mol::invoke(*((Editor*)this),&Editor::OnMDIActivate,unused,activated);
    return 0;
}


LRESULT FormEditor::OnExecForm()
{
	userForm->Show();
	return 0;
}


LRESULT FormEditor::OnExecScript()
{
	OnSave();

	mol::punk<IScintillAxProperties> props;
	HRESULT hr = sci->get_Properties(&props);
	if ( hr != S_OK )
		return 0;

	mol::bstr path;
	hr = props->get_Filename(&path);
	if ( hr != S_OK )
		return 0;

	mol::punk<IMoeUserForm> form;
	moe()->moeScript->ShowUserForm(path, &form );
	return 0;
}


LRESULT FormEditor::OnDebugScript()
{
	OnSave();

	mol::punk<IScintillAxProperties> props;
	HRESULT hr = sci->get_Properties(&props);
	if ( hr != S_OK )
		return 0;

	mol::bstr path;
	hr = props->get_Filename(&path);
	if ( hr != S_OK )
		return 0;

	mol::punk<IMoeUserForm> form;
	moe()->moeScript->DebugUserForm( path, &form );
	return 0;
}


//////////////////////////////////////////////////////////////////////////////

void FormEditor::OnReload()
{
	return;

	mol::punk<IScintillAxProperties> props;
	sci->get_Properties(&props);

	mol::punk<IScintillAxText> txt;
	sci->get_Text(&txt);

	//TODO FIXME

	VARIANT_BOOL vb;
	if ( S_OK != txt->get_Modified(&vb) )
		return ;

	if ( vb == VARIANT_TRUE )
	{
		mol::bstr path;
		props->get_Filename(&path);
		if ( IDYES != ::MessageBox(*this,_T("File is modified.\r\nClose without Save?"), path.toString().c_str() ,MB_YESNO|MB_ICONEXCLAMATION) )
			return ;
	}
	mol::bstr filename;
	if ( S_OK != get_FilePath(&filename) )
	{
		return ;
	}
	if ( S_OK != props->get_ReadOnly(&vb) )
	{
		return ;
	}
	long t;
	if ( S_OK != props->get_Encoding(&t) )
	{
		return ;
	}
	if ( t == SCINTILLA_ENCODING_UTF8 )
	{

		sci->LoadUTF8(filename);
		props->put_ReadOnly(vb);
		statusBar()->status( filename.toString() );
		return ;
	}
	sci->Load(filename);
	props->put_ReadOnly(vb);
	statusBar()->status( filename.toString() );
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


LRESULT FormEditor::OnSaveAs()
{
	mol::bstr p;

	if (!sci )
		return 0;

	mol::punk<IScintillAxProperties> props;
	HRESULT hr = sci->get_Properties(&props);
	if ( hr != S_OK )
		return 0;

	mol::bstr path;
	hr = props->get_Filename(&path);
	if ( hr != S_OK )
		return 0;

	mol::FilenameDlg ofn(*this);
	ofn.setFilter( FormOutFilesFilter );		
	ofn.fileName(path.toString());

	mol::punk<IScintillAxText> txt;
	sci->get_Text(&txt);


	if ( ofn.dlgSave( OFN_OVERWRITEPROMPT ) )
	{
		if ( ofn.fileName() != path.toString() )
		{
			mol::punk<IMoeDocument> doc;
			if ( (S_OK == docs()->Item(mol::variant(ofn.fileName()),&doc)) && doc )
			{
				::MessageBox(*this, _T("File already open in other editor window!"), _T("error"),MB_ICONERROR);
				return 0;
			}
		}

		mol::bstr s;
		HRESULT hr = txt->GetText(&s);

		mol::punk<IStorage> dest;
		if ( S_OK == ::StgCreateDocfile( mol::towstring( ofn.fileName()).c_str(), STGM_READWRITE|STGM_CREATE|STGM_SHARE_EXCLUSIVE,0,&dest) )
		{
			::WriteClassStg( dest, IID_IMoeUserForm );

			mol::punk<IStream> stream;
			hr = dest->CreateStream( L"CONTENT",STGM_READWRITE|STGM_CREATE|STGM_SHARE_EXCLUSIVE, 0,0, &stream );
			if ( S_OK == hr )
			{
				DWORD size = (DWORD)s.towstring().size();
				ULONG nwritten = 0;
				hr = stream->Write( &size, sizeof(DWORD), &nwritten);
				hr = stream->Write( s, size*sizeof(wchar_t), &nwritten);
				stream->Commit(STGC_DEFAULT);
			}

			hr = userForm->Save(dest,FALSE);
			hr = dest->Commit(STGC_DEFAULT);

			docs()->Rename( mol::variant(path), mol::variant(ofn.fileName()) );

			props->put_Filename( mol::bstr(ofn.fileName()) );
			//setText(ofn.fileName());
		}
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////////

LRESULT FormEditor::OnSave()
{
	mol::punk<IScintillAxProperties> props;
	sci->get_Properties(&props);

	mol::bstr path;
	HRESULT hr = props->get_Filename(&path);
	if ( hr != S_OK )
		return 0;

	mol::punk<IScintillAxText> txt;
	sci->get_Text(&txt);


	mol::bstr s;
	hr = txt->GetText(&s);

	mol::punk<IStorage> dest;
	if ( S_OK == ::StgCreateDocfile( path.toString().c_str(), STGM_READWRITE|STGM_CREATE|STGM_SHARE_EXCLUSIVE,0,&dest) )
	{
		::WriteClassStg( dest, IID_IMoeUserForm );

		mol::punk<IStream> stream;
		hr = dest->CreateStream( L"CONTENT",STGM_READWRITE|STGM_CREATE|STGM_SHARE_EXCLUSIVE, 0,0, &stream );
		if ( S_OK == hr )
		{
			DWORD size = (DWORD)s.towstring().size();
			ULONG nwritten = 0;
			hr = stream->Write( &size, sizeof(DWORD), &nwritten);
			hr = stream->Write( s, size*sizeof(wchar_t), &nwritten);

			size = 
			stream->Commit(STGC_DEFAULT);
		}
		hr = dest->Commit(STGC_DEFAULT);

		hr = userForm->Save(dest,FALSE);
		hr = sci->SavePoint();
	}
	return 0;
}

