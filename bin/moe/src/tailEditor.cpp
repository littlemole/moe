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

mol::TCHAR TailOutFilesFilter[]   = _T("File \0*.*\0\0");


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
	mol::invoke( boost::bind( &TailEditor::checkModifiedOnDisk, this ) );
}

void TailEditor::checkModifiedOnDisk( )
{
	mol::bstr path;
	props_->get_Filename(&path);

	ODBGS(path.toString());

	static mol::CriticalSection cs;
	LOCK(cs);

	unsigned long long size = mol::File::size(path.toString());

	ODBGS1("size",size);
	ODBGS1("size_",size_);
	if ( size > size_ )
	{
		append(path.toString(),size);
	}
	else if ( size < size_ )
	{
		OnReload();
	}
}
//////////////////////////////////////////////////////////////////////////////
TailEditor::Instance* TailEditor::CreateInstance(const mol::string& file)
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


bool TailEditor::initialize(const mol::string& p)
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
		FILE_NOTIFY_CHANGE_SIZE,
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

	mol::string fp(mol::toString(filename));
	size_ = mol::File::size(fp);

	sci->Load(filename);

	position_->put_Anchor(size_);
	position_->put_Caret(size_);
	position_->ScrollIntoView();

	statusBar()->status(filename.toString());
	
}

void TailEditor::append(const mol::string& path,unsigned long long size)
{
	if ( !sci )
		return;



	mol::filestream fs;
	if (!fs.open(mol::tostring(path),GENERIC_READ,FILE_SHARE_READ,0,OPEN_EXISTING) )
		return;

	fs.seek(size_);

	std::string buf = fs.readAll();
	fs.close();

	ODBGS(buf);

	mol::bstr tmp(buf);
	text_->Append(tmp);

	position_->put_Anchor(size_);
	position_->put_Caret(size_);
	position_->ScrollIntoView();

	size_ = size;

	this->redraw();
}