#include "stdafx.h"
#include "formeditor.h"
#include "moe.h"
#include "Docs.h"
#include "xmlui.h"
#include "ribbonres.h"

using namespace mol::win;
using namespace mol::ole;
using namespace mol::io;

wchar_t FormOutFilesFilter[]   = _T("UserFormScript \0*.ufs\0\0");


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

void FormEditor::OnFileChangeNotify(mol::io::DirMon* dirmon)
{
}

void FormEditor::checkModifiedOnDisk()
{

}
//////////////////////////////////////////////////////////////////////////////
FormEditor::Instance* FormEditor::CreateInstance(const std::wstring& file)
{
	statusBar()->status(20);

	std::wstring p(file);
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

bool FormEditor::initialize(const std::wstring& p)
{
	initializeMoeChild(p);

	// hook up com event handlers
	events.Advise(oleObject);

	// prepare interface pointers
	prepareInterfaces();

	// set the filename
	props_->put_Filename(mol::bstr(p));

	// try to load form or create new
	OnReload();
	if ( !userForm )
		return false;

	// get default values from config and init scintilla
	moe()->moeConfig->InitializeEditorFromPreferences( (IMoeDocument*)this );
	props_->put_ReadOnly( VARIANT_FALSE );

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
	return ;
}

void FormEditor::OnNcDestroy()
{
	return ;
}
//////////////////////////////////////////////////////////////////////////////

void FormEditor::OnMDIActivate(WPARAM unused, HWND activated)
{
	ODBGS("Editor::OnMDIActivate");
	if ( activated == hWnd_ )
	{
		userForm->Show();
	}
	else
	{
		userForm->Hide();
	}
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


LRESULT FormEditor::OnDebugScriptGo()
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
	bool createNew = false;
	mol::bstr filename;

	// get properties from scintilla ax ctrl
	mol::punk<IScintillAxProperties> props;
	sci->get_Properties(&props);

	// set the filename
	HRESULT hr = props->get_Filename(&filename);
	if ( hr != S_OK )
		return;

	std::wstring path = mol::towstring(filename);

		// if file exists, load
	if ( !mol::Path::exists(path) )
		createNew = true;

	mol::punk<IStorage> src;
	mol::punk<IStorage> store;
	
	// load
	if ( !createNew )
	{
		// try to open storage
		hr = ::StgOpenStorage( 
					mol::towstring(path).c_str(), 
					NULL,
					STGM_READ|STGM_SHARE_EXCLUSIVE,
					0,
					0,
					&src);
	}

	// could open storage?
	if ( (hr != S_OK) || (!src))
	{
		// if load failed, we opt for create new instead
		createNew = true;
	}
	else 
	{
		// its OK to load from storage
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
				mol::wbuff buf(size);

				hr = stream->Read( buf, size*sizeof(wchar_t), &nread);
				std::wstring ws = buf.toString(size);

				mol::punk<IScintillAxText> txt;
				sci->get_Text(&txt);

				hr = txt->SetText( mol::bstr(ws) );
				hr = sci->SavePoint();
			}
		}

		src.release();
		store.release();
		userForm = UserForm::CreateInstance(path,true);
	}

	// if create new flag is set
	if ( createNew == true )
	{
		props->put_Filename(filename);
		userForm = UserForm::CreateInstance(path,true);
	}

	statusBar()->status(80);
	statusBar()->status( path );
	return;
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
	ofn.fileName(path.towstring());

	mol::punk<IScintillAxText> txt;
	sci->get_Text(&txt);


	if ( IDOK == ofn.dlgSave( OFN_OVERWRITEPROMPT ) )
	{
		if (ofn.fileName() != path.towstring())
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

			docs()->rename( this, ofn.fileName() );

			props->put_Filename( mol::bstr(ofn.fileName()) );
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
	if (S_OK == ::StgCreateDocfile(path.towstring().c_str(), STGM_READWRITE | STGM_CREATE | STGM_SHARE_EXCLUSIVE, 0, &dest))
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

