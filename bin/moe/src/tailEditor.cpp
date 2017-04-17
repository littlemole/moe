#include "stdafx.h"
#include "taileditor.h"
#include "moe.h"
#include "Docs.h"
#include "moebar.h"
#include "xmlui.h"
#include "ribbonres.h"

using namespace mol::win;
using namespace mol::ole;
using namespace mol::io;

wchar_t TailOutFilesFilter[]   = _T("File \0*.*\0\0");


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// Base Child
//////////////////////////////////////////////////////////////////////////////

TailEditor::TailEditor() 
{
	size_ = 0;
}
//////////////////////////////////////////////////////////////////////////////

TailEditor::~TailEditor() 
{
	ODBGS("~TailEditor dead");
};

void TailEditor::OnFileChangeNotify(mol::io::DirMon* dirmon)
{
	::Sleep(1000);
	mol::invoke( std::bind( &TailEditor::checkModifiedOnDisk, this ) );
}

void TailEditor::checkModifiedOnDisk( )
{
	mol::bstr path;
	props_->get_Filename(&path);

	ODBGS(path.towstring());

	static mol::CriticalSection cs;
	LOCK(cs);

	unsigned long long size = mol::File::size(path.towstring());

	ODBGS1("size",(int)size);
	ODBGS1("size_",(int)size_);
	if ( size > size_ )
	{
		append(path.towstring(), size);
	}
	else if ( size < size_ )
	{
		size_ = 0;
		OnReload();
	}
}


LRESULT TailEditor::OnClose()
{
	this->destroy();
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
TailEditor::Instance* TailEditor::CreateInstance(const std::wstring& file)
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


bool TailEditor::initialize(const std::wstring& p)
{
	initializeMoeChild(p);

	// hook up com event handlers
	events.Advise(oleObject);

	// prepare interface pointers
	prepareInterfaces();

	// set the filename
	props_->put_Filename(mol::bstr(p));

	// try to load or create new
	OnReload();

	// get default values from config and init scintilla

	moe()->moeConfig->InitializeEditorFromPreferences( (IMoeDocument*)this );

	// monitor file changes
	monitor_.events += mol::events::event_handler( &TailEditor::OnFileChangeNotify, this );
	monitor_.watch( 
		mol::Path::parentDir(p), 
		FILE_NOTIFY_CHANGE_SIZE|FILE_NOTIFY_CHANGE_LAST_WRITE,
		false
	);
	return true;
}

//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////

void TailEditor::OnReload()
{
	if ( !sci )
		return;

	mol::bstr filename;
	if ( S_OK != get_FilePath(&filename) )
	{
		return ;
	}

	std::wstring fp(mol::towstring(filename));
	props_->put_ReadOnly(VARIANT_FALSE);
	sci->Load(filename);
	props_->put_ReadOnly(VARIANT_TRUE);

	position_->put_Anchor((long)size_);
	position_->put_Caret((long)size_);
	position_->ScrollIntoView();

	LONG len = 0;
	text_->get_Length(&len);
	size_ = len;
	statusBar()->status(filename.towstring());
	
}

void TailEditor::append(const std::wstring& path,unsigned long long size)
{
	if ( !sci )
		return;

	mol::filestream fs;
	if (!fs.open(mol::tostring(path),GENERIC_READ,FILE_SHARE_READ,0,OPEN_EXISTING) )
		return;

	int s = (int)size_;

	VARIANT_BOOL vb;
	HRESULT hr = props_->get_WriteBOM(&vb);
	if ( hr == S_OK && vb == VARIANT_TRUE )
	{
		long e;
		hr = props_->get_Encoding(&e);
		if ( hr == S_OK )
		{
			if ( e = CP_WINUNICODE ) {
				s += 3;
			}
			if ( e = CP_UTF8 ) {
				s += 2;
			}
		}
	}

	fs.seek(s);

	std::string buf = fs.readAll();
	fs.close();

	ODBGS(buf);

	props_->put_ReadOnly(VARIANT_FALSE);
	mol::bstr tmp(buf);
	text_->Append(tmp);
	props_->put_ReadOnly(VARIANT_TRUE);

	LONG len = 0;
	text_->get_Length(&len);

	position_->put_Anchor((long)len);
	position_->put_Caret((long)len);
	position_->ScrollIntoView();

	size_ = size;

	this->redraw();
}