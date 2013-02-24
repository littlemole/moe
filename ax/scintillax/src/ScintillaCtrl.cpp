#include "stdafx.h"
#include "ScintillaCtrl.h"
#include "win/path.h"
#include "win/shell.h"
#include "win/pp.h"
#include "util/istr.h"
#include <sstream>
#include <fstream>
#include "msstkppg.h"
#include "io/io_h.h"

#include "Properties.h"
#include "Selection.h"
#include "Position.h"
#include "Text.h"
#include "Markers.h"
#include "Annotation.h"
#include "Line.h"

#include "tcp/sockets.h"
#include "ssh/ssh.h"
#include "ssh/scp.h"
#include "ssh/sftp.h"

#include "../ssh/ssh_h.h"

#include "ScintillAx_dispid.h"

void init_ribbon_ui(mol::win::WndProc*)
{}

class UACex
{
};

class Elevator
{
public:

	Elevator(const mol::string& executor)
		:executor_(executor)
	{
	}

	std::string read(const mol::string& file, const mol::string& pipename)
	{
		mol::UACPipe pipe;
		pipe.create( pipename );

		if ( !pipe )
		{
			ODBGS("create pipe failed!");
			throw UACex();
		}

		mol::ostringstream oss_args;
		oss_args 
			<< _T("read")
			<< _T(" ") 
			<< pipename
			<< _T(" \"") 
			<< file
			<< _T("\"");

		BOOL r = mol::io::execute_shell_args( executor_, oss_args.str(), _T("runas"), SW_HIDE );

		if ( !r )
		{
			ODBGS("mol::io::execute_shell_args failed!");
			throw UACex();
		}

		if ( !pipe.connect() ) 
		{
			ODBGS("pipe connect failed!");
			throw UACex();
		}

		std::string data = pipe.read();

		ODBGS1("data read: ", (int)data.size());

		pipe.disconnect();
		pipe.close();

		return data;
	}

	bool write(const mol::string& file, const mol::string& pipename, const std::string& data)
	{
		mol::UACPipe pipe;
		pipe.create( pipename );
		if ( !pipe )
		{
			ODBGS("create pipe failed!");
			throw UACex();
		}

		mol::ostringstream oss_args;
		oss_args 
			<< _T("write")
			<< _T(" ") 
			<< pipename
			<< _T(" \"") 
			<< file
			<< _T("\"");

		BOOL r = mol::io::execute_shell_args( executor_, oss_args.str(), _T("runas"), SW_HIDE );

		if ( !r )
		{
			ODBGS("mol::io::execute_shell_args failed!");
			throw UACex();
		}

		if ( !pipe.connect() ) 
		{
			ODBGS("pipe connect failed!");
			throw UACex();
		}

		if (!pipe.write( data ))
		{
			ODBGS("pipe write failed!");
		}

		std::string s = pipe.read();

		pipe.disconnect();
		pipe.close();
		return true;
	}

private:
	mol::string executor_;
};

//////////////////////////////////////////////////////////////////////////////
// c'tor, d'tor
//////////////////////////////////////////////////////////////////////////////
FontDesc::FontDesc()
{
	::ZeroMemory((void*)&m_logfont,sizeof(LOGFONT));
}

FontDesc::FontDesc(const std::string& font, int size)
{
	strncpy(m_logfont.lfFaceName,font.c_str(),32);
	m_logfont.lfHeight = size;
}

FontDesc::FontDesc(HFONT hfont)
{
	::ZeroMemory((void*)&m_logfont,sizeof(LOGFONT));
	::GetObject(hfont,sizeof(LOGFONT),(void*)&m_logfont);
}

const char* FontDesc::name()
{
	return m_logfont.lfFaceName;
}

const char* FontDesc::size()
{
	int h = -1 * (m_logfont.lfHeight);
	static char buf[64];
	wsprintfA(buf,"%i",h);
	return buf;
}
const char* FontDesc::weight()
{
	static char buf[64];
	wsprintfA(buf,"%i",m_logfont.lfWeight);
	return buf;
}

const char* FontDesc::style()
{
	if ( m_logfont.lfItalic == TRUE )
		return "italic";
	return "normal";
}

const char* FontDesc::decoration()
{
	if ( m_logfont.lfUnderline == TRUE )
		return "underline";
	if ( m_logfont.lfStrikeOut  == TRUE )
		return "line-through";

	return "normal";
}

///////////////////////////////////////////////////////////////////////////////
// Scintilla Control
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////

ScintillAx::ScintillAx(void)	
{
	Init();
}

void ScintillAx::Init() 
{
	eraseBackground_ = 1;
	sizel.cx = 300;
	sizel.cy = 200;
	mol::ole::PixeltoHIMETRIC(&sizel);

	props_ = SciAxProperties::CreateInstance(this);
	text_  = SciAxText::CreateInstance(this);
	pos_   = SciAxPosition::CreateInstance(this);
	selection_ = SciAxSelection::CreateInstance(this);
	line_ = SciAxLine::CreateInstance(this);
	annotation_ = SciAxAnnotation::CreateInstance(this);
	markers_ = SciAxMarkers::CreateInstance(this);

	setDirty(FALSE);
}

HRESULT __stdcall ScintillAx::InitNew() 
{
	Init();
	mol::PersistStream<ScintillAx>::InitNew();
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////

ScintillAx::~ScintillAx()
{
	ODBGS("~ScintillAx");
}

void ScintillAx::disposeObject(IUnknown* unk)
{
	mol::punk<IScintillAxDispose> dispose(unk);

	if ( dispose )
		dispose->Dispose();
}

void ScintillAx::dispose()  
{
	ODBGS("dispose ScintillAx");
	disposeObject(props_);
	disposeObject(text_);
	disposeObject(pos_);
	disposeObject(selection_);
	disposeObject(line_);
	disposeObject(annotation_);
	disposeObject(markers_);

	props_.release();
	text_.release();
	pos_.release();
	selection_.release();
	line_.release();
	annotation_.release();
	markers_.release();

	HWND hwnd = this->getOleWindow();
	if ( hwnd && ::IsWindow(hwnd) )
		this->Close(OLECLOSE_NOSAVE);
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

EditWnd* ScintillAx::edit()
{
	return childWindow<EditWnd>(IDC_EDITOR_VIEW);
}


//////////////////////////////////////////////////////////////////////////////
// Windows Message handlers
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
// OnCreate
//////////////////////////////////////////////////////////////////////////////

LRESULT ScintillAx::OnCreate(UINT msg, WPARAM wParam, LPARAM lParam)
{
	make_ui(this);

	mol::bstr filename;
	HRESULT hr = props_->get_Filename(&filename);
	if ( hr == S_OK )
	{
		this->Load(filename);
	}

	col_.createObject(CLSID_ColorDialog);



	if ( edit() )
	{
		ODBGS("setting scintilla persist props");

		VARIANT_BOOL vb;
		LONG w = 4;

		props_->get_TabWidth(&w);
		edit()->setTabWidth( w );

		props_->get_TabUsage(&vb);
		edit()->setUseTabs(  vb == VARIANT_TRUE ? true : false );

		props_->get_TabIndents(&vb);
		edit()->setTabIndents( vb == VARIANT_TRUE ? true : false );

		props_->get_BackSpaceUnindents( &vb );
		edit()->setBackSpaceUnindents( vb == VARIANT_TRUE ? true : false );

		props_->get_UseContext(&vb);
		edit()->setUsePopUp( vb == VARIANT_TRUE ? true : false );

		props_->get_ReadOnly(&vb);
		edit()->setReadOnly( vb == VARIANT_TRUE ? true : false );

		props_->get_Overtype(&vb);
		edit()->setOvertype( vb == VARIANT_TRUE ? true : false );
				
		//this->put_Font(font_);
		//this->put_Syntax(syntax_);				

		edit()->setCodePage(SC_CP_UTF8);
	}

	return 0;
}

/*
LRESULT ScintillAx::OnSize(UINT msg, WPARAM wParam, LPARAM lParam)
{
	mol::Rect clientRect(0,0,0,0);
	clientRect.right = LOWORD(lParam);
	clientRect.bottom = HIWORD(lParam);
	edit()->move(clientRect);
		
	return 0;
}
*/
//////////////////////////////////////////////////////////////////////////////
// On Pos Changed
//////////////////////////////////////////////////////////////////////////////

LRESULT ScintillAx::OnUpdateUI(UINT msg, WPARAM wParam, LPARAM lParam)
{
	mol::Crack mess(msg,wParam,lParam);
	if ( mess.nmhdr()->code == SCN_UPDATEUI )
	{
		int pos = edit()->pos();
		int line = edit()->lineFromPos(pos);
		//int tmp = line+1;
		this->fire(DISPID_ISCINTILLAXEVENTS_ONPOSCHANGE,line);

		if ( line > 0 )
		{
			int indent = edit()->getLineIndent(line-1);
			edit()->setIndent(indent);
		}
		if ( edit()->pos() > 0 )
		{
			char c = edit()->getCharAt(edit()->pos()-1);
			if ( c == '{' || c == '(' || c == ')' || c == '}' )
			{
				int start = edit()->braceMatch(		edit()->pos()-1 );
				if ( start != -1 )
				{
					edit()->braceHighlight(start,		edit()->pos()-1);
				}
			}
			else
				edit()->braceHighlight(-1,-1);
		}
		if ( edit()->showLineNumbers() )
			edit()->showLineNumbers(true);	
	}
    return 0;
}

LRESULT ScintillAx::OnContext(UINT msg, WPARAM wParam, LPARAM lParam)
{
	VARIANT_BOOL vb = VARIANT_TRUE;
	mol::variant v(vb);
	this->fire(2,v);
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
// On Char entered
//////////////////////////////////////////////////////////////////////////////

LRESULT ScintillAx::OnChar(UINT msg, WPARAM wParam, LPARAM lParam)
{
	mol::Crack mess(msg,wParam,lParam);
	if ( mess.nmhdr()->code == SCN_CHARADDED )
	{
		SCNotification* sciNotify = (SCNotification*)lParam;
		char c = (char)(sciNotify->ch);
		char tmp[] = { c, '\0' };

		this->fire(DISPID_ISCINTILLAXEVENTS_ONCHAR,mol::bstr(tmp));
	}
	annotation_->ClearAll();
	edit()->highliteLine(-1);
    return 0;
}

LRESULT ScintillAx::OnDblClick(UINT msg, WPARAM wParam, LPARAM lParam)
{
	this->uiActivate();
	annotation_->ClearAll();
	edit()->highliteLine(-1);
	return 0;
}

LRESULT ScintillAx::OnMarginClick(UINT msg, WPARAM wParam, LPARAM lParam)
{
	SCNotification* sciNotify = (SCNotification*)lParam;
	int pos = sciNotify->position;
	int line = edit()->lineFromPos(pos);
	edit()->highliteLine(-1);
	this->fire(DISPID_ISCINTILLAXEVENTS_ONMARKER,line);
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// COM Methods
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
// Load / Save
//////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::Load( BSTR file )
{
	if (!file)
		return S_FALSE;

	mol::string p(mol::toString(file));
	bool isSSH = p.substr(0,6) == _T("ssh://") || p.substr(0,10) == _T("moe-ssh://");
	if ( mol::Path::exists(p) || isSSH )
	{
		if ( !mol::Path::isDir(p) || isSSH )
		{
			mol::string ext = mol::Path::ext(p);
			if ( ext.size() > 0 )
				if ( ext[0] == '.' )
					ext = ext.substr(1);


			if ( mol::icmp( ext, _T("gif")) != 0 &&
				 mol::icmp( ext, _T("jpg")) != 0 &&
				 mol::icmp( ext, _T("jpeg")) != 0 &&
				 mol::icmp( ext, _T("bmp")) != 0 )
			{
				if ( load( p,ext, false ) )
				{
					props_->put_Filename(file);
					this->SavePoint();
					return S_OK; 
				}
			}
		}
	}
	return S_FALSE; 
}



///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::LoadEncoding( BSTR file, long enc )
{ 
	if (file)
	{
		mol::string p(mol::toString(file));
		bool isSSH = p.substr(0,6) == _T("ssh://") || p.substr(0,10) == _T("moe-ssh://");
		if ( mol::Path::exists(p) || isSSH )
		{
			if ( !mol::Path::isDir(p) || isSSH )
			{
				mol::string ext = mol::Path::ext(p);
				if ( ext.size() > 0 )
					if ( ext[0] == _T('.') )
						ext = ext.substr(1);

				if ( mol::icmp( ext, _T("gif")) != 0 &&
					 mol::icmp( ext, _T("jpg")) != 0 &&
					 mol::icmp( ext, _T("jpeg")) != 0 &&
					 mol::icmp( ext, _T("bmp")) != 0 )
				{
					if ( load(p, ext, enc ) )
					{
						//props_->put_Encoding(enc); //dont!
						props_->put_Filename(file);
						this->SavePoint();
						return S_OK; 
					}
				}
			}
		}
	}
	return S_FALSE; 
}
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::Save()
{ 
	mol::bstr filename;
	props_->get_Filename(&filename);
	if ( !this->save(filename.toString()) )
		return S_FALSE;
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::SaveAs( BSTR filename )
{ 
	mol::bstr old;
	props_->get_Filename(&old);

	props_->put_Filename(filename);
	if ( S_OK == this->Save() )
	{
		return S_OK;
	}
	props_->put_Filename(old);
	return S_FALSE;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// undo / redo
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::Undo()
{ 
	edit()->undo();
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::Redo()
{ 
	edit()->redo();
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::SavePoint()
{ 
	edit()->setSavePoint();
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::get_Text( IScintillAxText** txt )
{
	return text_->QueryInterface( IID_IScintillAxText, (void**)txt);
}

HRESULT __stdcall ScintillAx::get_Properties( IScintillAxProperties** props )
{
	return ((IScintillAxProperties*)props_)->QueryInterface( IID_IScintillAxProperties, (void**)props);
}

HRESULT __stdcall ScintillAx::get_Position( IScintillAxPosition** pos )
{
	return pos_->QueryInterface( IID_IScintillAxPosition, (void**)pos);
}

HRESULT __stdcall ScintillAx::get_Selection( IScintillAxSelection** sel )
{
	return selection_->QueryInterface( IID_IScintillAxSelection, (void**)sel);
}

HRESULT __stdcall ScintillAx::get_Line( IScintillAxLine** line )
{
	return line_->QueryInterface( IID_IScintillAxLine, (void**)line);
}

HRESULT __stdcall ScintillAx::get_Annotation( IScintillAxAnnotation** anno )
{
	return annotation_->QueryInterface( IID_IScintillAxAnnotation, (void**)anno);
}

HRESULT __stdcall ScintillAx::get_Markers( IScintillAxMarkers** markers )
{
	return markers_->QueryInterface( IID_IScintillAxMarkers, (void**)markers);
}



///////////////////////////////////////////////////////////////////////
//options
///////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::SetFocus()
{ 
	edit()->setFocus();
	return S_OK; 
}

HRESULT __stdcall ScintillAx::ZoomIn()
{ 
	edit()->zoomIn();
	return S_OK; 
}

HRESULT __stdcall ScintillAx::ZoomOut()
{ 
	edit()->zoomOut();
	return S_OK; 
}

HRESULT __stdcall ScintillAx::GetPages( CAUUID *pPages)
{
	if ( !pPages )
		return E_POINTER;
	pPages->cElems = 2;
	pPages->pElems = (GUID*)::CoTaskMemAlloc(sizeof(GUID)*2);
	pPages->pElems[0] = CLSID_ScintillAxProperties;
	pPages->pElems[1] = CLSID_ScintillAxSettings;

	return S_OK;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// print
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::Print(  )
{ 
	edit()->print();
	return S_OK;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::ShowProperties()
{
	mol::bstr filename;
	props_->get_Filename(&filename);

	LPUNKNOWN punks[] = { (IUnknown*)(IScintillAx*)this, (IUnknown*)(IScintillAx*)this };
	CLSID pages[]     = { CLSID_ScintillAxProperties,CLSID_ScintillAxSettings };

	::OleCreatePropertyFrame(*this,100,100,filename.towstring().c_str(),2,punks,2,pages,0,0,0);

	return S_OK;
}

HRESULT __stdcall ScintillAx::InsertColorDialog(  )
{
	if ( !col_ ) 
		return S_OK;

	VARIANT_BOOL vb = VARIANT_FALSE;
	if ( S_OK != col_->Show( &vb) )
		return S_OK;

	if ( vb != VARIANT_TRUE )
		return S_OK;

	mol::punk<IScintillAx> guard(this);

	mol::bstr hex;
	if ( S_OK != col_->get_HexColor(&hex) || hex.bstr_ == 0)
		return S_OK;

	long pos;
	if ( S_OK != pos_->get_Caret(&pos) )
		return S_OK;

	if ( S_OK == text_->Insert(hex,pos) )
		return S_OK;
	return S_OK;
}


HRESULT ScintillAx::OnDraw( HDC hdcDraw, LPCRECTL lprcBounds, LPCRECTL lprcMFBounds)
{
	ODBGS("ScintillAx::OnDraw");
	edit()->redraw();
	return S_OK;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
// end COM section
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
//
// helpers save / close
//
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//
// save as admin using named pipe executor prw.exe
//
//////////////////////////////////////////////////////////////////////////////

bool ScintillAx::saveAdmin(const mol::string& location)
{
	mol::string pipename( _T("\\\\.\\pipe\\mol_moe_prw_writer_pipe") );

	mol::string ex = mol::Path::pathname(mol::App().getModulePath());
	ex = ex + _T("\\") + _T("prw.exe");

	Elevator elevator( ex );

	std::ostringstream oss;

	std::string txt = edit()->get_Text();
	long enc;
	props_->get_Encoding(&enc);
	long eol;
	props_->get_SysType(&eol);

	VARIANT_BOOL vb;
	props_->get_WriteBOM(&vb);

	if ( enc == SCINTILLA_ENCODING_UTF16 )
	{
		txt = std::string( (char*) mol::fromUTF8(txt).c_str(), sizeof(wchar_t)*txt.size() );
		if ( vb == VARIANT_TRUE  )
		{
			oss.write((const char*)mol::FileEncoding::UTF16LE_BOM,2);
		}
		if ( eol == SCINTILLA_SYSTYPE_UNIX )
		{
			txt = mol::dos2unix(txt);
		}
	}
	else
	if ( enc == SCINTILLA_ENCODING_UTF8 )
	{
		oss.write((const char*)mol::FileEncoding::UTF8_BOM,3);
		if ( eol == SCINTILLA_SYSTYPE_UNIX )
		{
			txt = mol::toUTF8(mol::dos2unix(mol::fromUTF8(txt)));
		}
	}
	else
	//if ( enc == SCINTILLA_ENCODING_ANSI )
	{
		txt = mol::toUTF8(txt,enc);
		if ( eol == SCINTILLA_SYSTYPE_UNIX )
		{
			txt = mol::dos2unix(txt);
		}
	}
	
	oss.write( txt.c_str(), txt.size() );
	
	bool ret = false;
	
	try 
	{
		ret = elevator.write(location,pipename,oss.str());
	}
	catch(...)
	{
		return false;
	}

	if ( ret )
	{
		edit()->setSavePoint();
		setDirty(FALSE);
	}
	return ret;
}

//////////////////////////////////////////////////////////////////////////////
//
// save using COM elevation moniker
//
//////////////////////////////////////////////////////////////////////////////
/*
bool ScintillAx::saveAdminCOM(const mol::string& location)
{
	mol::punk<IUnknown> unk;

	HRESULT hr = mol::CreateObjectAdmin( this->getOleWindow(), mol::bstr("IO.File"), &unk);
	if ( hr != S_OK )
		return false;

	mol::punk<IFile> file(unk);
	if ( !file )
		return false;

	VARIANT_BOOL vb = VARIANT_FALSE;

	hr = file->Create( mol::bstr(location), &vb );
	if ( hr != S_OK )
		return false;

	long e;
	props_->get_Encoding(&e);

	long eol;
	props_->get_SysType(&eol);

	long enc = CP_ACP;
	switch ( e )
	{
		case SCINTILLA_ENCODING_UTF16 :
		{
			enc = CP_WINUNICODE;
			break;
		}
		case SCINTILLA_ENCODING_UTF8 :
		{
			enc = CP_UTF8;
			break;
		}
		default :
		{
			enc = e;
			break;
		}
	}
	hr = file->put_Encoding(enc);
	if ( hr != S_OK )
		return false;

	hr = file->put_EoL(eol);
	if ( hr != S_OK )
		return false;

	props_->get_WriteBOM(&vb);
	hr = file->put_UseBOM(vb);
	if ( hr != S_OK )
		return false;

	std::string txt = edit()->get_Text();
	mol::bstr btxt(txt);
	long written = 0;
	hr = file->WriteText( btxt,&written );

	if ( hr != S_OK )
		return false;			

	file->Close();
	edit()->setSavePoint();
	setDirty(FALSE);
	return true;
}
*/
//////////////////////////////////////////////////////////////////////////////
//
// save file impl
//
//////////////////////////////////////////////////////////////////////////////

bool ScintillAx::saveSSH(const mol::string& location)
{
	mol::Uri uri(mol::toUTF8(location));
	std::string host = uri.getHost();
	int port = uri.getPort();
	std::string p = uri.getPath();

	long e;
	props_->get_Encoding(&e);

	long eol;
	props_->get_SysType(&eol);

	VARIANT_BOOL vb;
	props_->get_WriteBOM(&vb);

	std::ostringstream of;
	switch ( e )
	{
		case SCINTILLA_ENCODING_UTF16 :
		{
			std::string u;
			u = edit()->get_Text();

			std::wstring ws = mol::fromUTF8(u);	
			if ( vb == VARIANT_TRUE )
				of.write((const char*)mol::FileEncoding::UTF16LE_BOM,2);

			of.write( (char*)(ws.c_str()), ws.size()*2 );
			break;
		}
		case SCINTILLA_ENCODING_UTF8 :
		{
			std::string u;
			u = edit()->get_Text();

			if ( eol == SCINTILLA_SYSTYPE_UNIX )
				u = mol::dos2unix(u);

			if ( vb == VARIANT_TRUE )
				of.write((const char*)mol::FileEncoding::UTF8_BOM,3);

			of.write( (char*)(u.c_str()), u.size() );
			break;
		}
		default :
		{
			std::string u;
			u = edit()->get_Text();
			if ( eol == SCINTILLA_SYSTYPE_UNIX )
				u = mol::dos2unix(u);

			std::string s = mol::tostring(mol::fromUTF8(u,e),e);				
			of.write( (char*)(s.c_str()), s.size() );
			break;
		}
	}

	std::string content = of.str();

	if ( !host.empty() && !location.empty() )
	{

			mol::punk<ISSH> ssh;
			HRESULT hr = ssh.createObject(CLSID_SSH);
			if (hr!=S_OK)
				return false;

			::CoAllowSetForegroundWindow(ssh,0);

			mol::punk<ISSHConnection> conn;
			hr = ssh->Connect( mol::bstr(mol::fromUTF8(uri.getHost())),uri.getPort(),&conn);
			if (hr!=S_OK)
				return false;

			mol::punk<ISCP> scp;
			hr = conn->get_SCP(&scp);
			if (hr!=S_OK)
				return false;

			mol::ArrayBound ab((long)content.size());
			mol::SafeArray<VT_I1> sa(ab);
			{
				mol::SFAccess<BYTE> sf(sa);
				memcpy(sf(),content.data(),content.size());
			}
			hr = scp->PutFile(sa,mol::bstr(p));
			if (hr!=S_OK)
				return false;

			edit()->setSavePoint();
			setDirty(FALSE);
			return true;
	}
    return false;
}



bool ScintillAx::save(const mol::string& location)
{
	if ( !location.empty() )
	{
		if ( location.substr(0,6) == _T("ssh://") || location.substr(0,10) == _T("moe-ssh://") ) 
		{
			return saveSSH(location);
		}
		std::ofstream of;
		of.open(location.c_str(),std::ios::binary);
		if ( !of.good() )
		{
			DWORD error = ::GetLastError();
			mol::string error_str = mol::WinErrorString(error);
			ODBGS1("error ",error);
			ODBGS(error_str.c_str());

			if ( error == 5 ) // access denied
			{
				//if ( this->saveAdminCOM(location) )
					//return true;
				if ( mol::OS::has_uac() )
				{
					return this->saveAdmin(location);
				}
			}
			return false;
		}


		long e;
		props_->get_Encoding(&e);

		long eol;
		props_->get_SysType(&eol);

		VARIANT_BOOL vb;
		props_->get_WriteBOM(&vb);

		switch ( e )
		{
			case SCINTILLA_ENCODING_UTF16 :
			{
				std::string u;
				u = edit()->get_Text();

				std::wstring ws = mol::fromUTF8(u);	
				if ( vb == VARIANT_TRUE )
					of.write((const char*)mol::FileEncoding::UTF16LE_BOM,2);

				of.write( (char*)(ws.c_str()), ws.size()*2 );
				break;
			}
			case SCINTILLA_ENCODING_UTF8 :
			{
				std::string u;
				u = edit()->get_Text();

				if ( eol == SCINTILLA_SYSTYPE_UNIX )
					u = mol::dos2unix(u);

				if ( vb == VARIANT_TRUE )
					of.write((const char*)mol::FileEncoding::UTF8_BOM,3);

				of.write( (char*)(u.c_str()), u.size() );
				break;
			}
			default :
			{
				std::string u;
				u = edit()->get_Text();
				if ( eol == SCINTILLA_SYSTYPE_UNIX )
					u = mol::dos2unix(u);

				std::string s = mol::tostring(mol::fromUTF8(u,e),e);				
				of.write( (char*)(s.c_str()), s.size() );
				break;
			}
		}

		of.close();
		edit()->setSavePoint();
		setDirty(FALSE);
		return true;
	}
    return false;
}

//////////////////////////////////////////////////////////////////////////////
//
// load as admin using named pipe executor (prw.exe)
//
//////////////////////////////////////////////////////////////////////////////

/*
bool ScintillAx::loadAdmin(const mol::string& p, const mol::string& ext,  long enc)
{
	edit()->setText("");

	mol::string pipename( _T("\\\\.\\pipe\\mol_moe_prw_reader_pipe") );

	mol::string ex = mol::Path::pathname(mol::App().getModulePath());
	ex = ex + _T("\\") + _T("prw.exe");

	Elevator elevator( ex );	

	std::string data;
	try
	{
		data = elevator.read(p,pipename);
	}
	catch(...)
	{
		return false;
	}

	mol::FileEncoding fe;
	DWORD cp = fe.investigate(data);

	long e;
	long eol;

	switch(cp)
	{
		case CP_UTF8:
		{
			e = SCINTILLA_ENCODING_UTF8;
			break;
		}
		case CP_WINUNICODE:
		{
			e = SCINTILLA_ENCODING_UTF16;
			break;
		}
		default:
		{
			e = cp;
			break;
		}
	}

	eol = (SCINTILLA_SYSTYPE)(fe.eolMode());

	props_->put_SysType(eol);
	props_->put_Encoding(enc);

	if ( fe.isBinary() )
	{
		if ( IDCANCEL == ::MessageBox(*this,_T("this looks like a BINARY\r\nopen anyway?"),mol::toString(p).c_str(),MB_OKCANCEL|MB_ICONQUESTION ) )
			return false;
	}

	if ( enc == SCINTILLA_ENCODING_UTF8 )
	{
		props_->put_Encoding(enc);
		edit()->setCodePage(SC_CP_UTF8);

		std::string s2(data);
		if ( data.substr(0,3) == std::string((char*)mol::FileEncoding::UTF8_BOM,3) )
			s2 = std::string( data.c_str()+3, data.size()-3);

		edit()->appendText(s2);
	}
	else
	switch ( enc )
	{
		case SCINTILLA_ENCODING_UTF16 :
		{
			// jump over BOM
			props_->put_Encoding(SCINTILLA_ENCODING_UTF16);
			std::string s2(data);
			if ( data.substr(0,2) == std::string((char*)mol::FileEncoding::UTF16LE_BOM,2) )
				s2 = std::string( data.data()+2, data.size()-2);

			// it really is a UCS-2 string, so cast to wchar_t (WIN32)
			std::wstring ws((wchar_t*)(s2.data()),s2.size()/sizeof(wchar_t));

			// now convert UTF16-LE to UTF-8
			std::string u = mol::toUTF8(ws);
			edit()->setCodePage(SC_CP_UTF8);

			u = mol::unix2dos(u);
			edit()->setText(u);
			break;
		}
		case SCINTILLA_ENCODING_UTF8 :
		{
			props_->put_Encoding(SCINTILLA_ENCODING_UTF8);
			edit()->setCodePage(SC_CP_UTF8);

			std::string s2;
			if ( data.substr(0,3) == std::string((char*)mol::FileEncoding::UTF8_BOM,3) )
				s2 = std::string(data.c_str()+3,data.size()-3);
			else
				s2 = data;

			s2 = mol::unix2dos(s2);
			edit()->setText(s2);
			break;
		}
		default:
		{
			props_->put_Encoding(enc);
			edit()->setCodePage(SC_CP_UTF8);

			std::string s2(mol::toUTF8(data,enc));
			s2 = mol::unix2dos(s2);
			edit()->setText(s2);			
			break;
		}
	}	
	edit()->mode(p,ext);
	edit()->setSavePoint();
	setDirty(FALSE);
	return true;
}
*/


std::string ScintillAx::loadAdmin(const mol::string& p)
{
	mol::string pipename( _T("\\\\.\\pipe\\mol_moe_prw_reader_pipe") );

	mol::string ex = mol::Path::pathname(mol::App().getModulePath());
	ex = ex + _T("\\") + _T("prw.exe");

	Elevator elevator( ex );	

	std::string data = elevator.read(p,pipename);
	return data;
}
//////////////////////////////////////////////////////////////////////////////
//
// load file as admin using COM elevation moniker
//
//////////////////////////////////////////////////////////////////////////////
/*
bool ScintillAx::loadAdminCOM(const mol::string& p, const mol::string& ext,  long enc)
{
	mol::punk<IUnknown> unk;

	HRESULT hr = mol::CreateObjectAdmin( this->getOleWindow(), mol::bstr("IO.File"), &unk);
	if ( hr != S_OK )
		return false;

	mol::punk<IFile> file(unk);
	if ( !file )
		return false;

	VARIANT_BOOL vb = VARIANT_FALSE;

	hr = file->Open( mol::bstr(p), &vb );
	if ( hr != S_OK )
		return false;

	mol::bstr content;
	hr = file->ReadText(&content);
	if ( hr != S_OK )
		return false;

	long e=0;
	hr = file->get_Encoding(&e);
	if ( hr != S_OK )
		return false;

	switch(e)
	{
		case CP_UTF8:
		{
			enc = SCINTILLA_ENCODING_UTF8;
			break;
		}
		case CP_WINUNICODE:
		{
			enc = SCINTILLA_ENCODING_UTF16;
			break;
		}
		default:
		{
			//e = enc;
			break;
		}
	}
	long eol=0;
	hr = file->get_EoL(&eol);
	if ( hr != S_OK )
		return false;

	props_->put_Encoding(enc);
	props_->put_SysType(eol);

	file->Close();

	edit()->setCodePage(SC_CP_UTF8);
	edit()->setText("");
	edit()->appendText(content.tostring());
	edit()->mode(p,ext);
	edit()->setSavePoint();
	setDirty(FALSE);
	return true;
}
*/
//////////////////////////////////////////////////////////////////////////////
//
// load file
//
//////////////////////////////////////////////////////////////////////////////

SCINTILLA_SYNTAX guess ( const mol::string& p, const mol::string& ext )
{
	//mol::ci_string cis(ext.c_str());
	mol::string p2(mol::toString(p));

	if ( mol::icmp( ext, _T("htm")) == 0 ||
		 mol::icmp( ext, _T("html")) == 0 ||
		 mol::icmp( ext, _T("jsp")) == 0 ||
		 mol::icmp( ext, _T("php")) == 0 ||
		 mol::icmp( ext, _T("shtml")) == 0 ||
		 mol::icmp( ext, _T("mhtml")) == 0 ||
		 mol::icmp( ext, _T("mc")) == 0 ||
		 mol::icmp( ext, _T("htm")) == 0 ||
		 mol::icmp( mol::Path::filename(p2), _T("autohandler")) == 0 ||
		 mol::icmp( mol::Path::filename(p2), _T("dhandler"))  == 0
		)
	{
		return SCINTILLA_SYNTAX_HTML;
	}
	if ( mol::icmp( ext, _T("h"))  == 0||
		 mol::icmp( ext, _T("hpp"))  == 0||
		 mol::icmp( ext, _T("c"))  == 0||
		 mol::icmp( ext, _T("cpp"))  == 0||
		 mol::icmp( ext, _T("cxx")) == 0 
	    )
	{
		return SCINTILLA_SYNTAX_CPP;
	}
	if ( mol::icmp( ext, _T("java") ) == 0 )
	{
		return SCINTILLA_SYNTAX_JAVA;
	}
	if ( mol::icmp( ext, _T("cs")  ) == 0 )
	{
		return SCINTILLA_SYNTAX_CSHARP;
	}
	if ( mol::icmp( ext, _T("pl")) == 0 ||
		 mol::icmp( ext, _T("pm")) == 0 ||
		 mol::icmp( ext, _T("cgi")) == 0 ||
		 mol::icmp( ext, _T("pls")) == 0 
		)
	{
		return SCINTILLA_SYNTAX_PERL;
	}
	if ( mol::icmp( ext, _T("js") ) == 0 )
	{
		return SCINTILLA_SYNTAX_JS;
	}
	if ( mol::icmp( ext, _T("css") ) == 0 )
	{
		return SCINTILLA_SYNTAX_CSS;
	}

	if ( mol::icmp( ext, _T("bas"))  == 0||
		 mol::icmp( ext, _T("vbs"))  == 0
		 )
	{
		return SCINTILLA_SYNTAX_VB;
	}
    if ( mol::icmp( ext, _T("sh") )  == 0)
    {
        return SCINTILLA_SYNTAX_SHELL;
    }
    if ( mol::icmp( ext, _T("sql") ) == 0 )
    {
        return SCINTILLA_SYNTAX_SQL;
    }
	return SCINTILLA_SYNTAX_PLAIN;
}

/////////////////////////////////////////////////////////////////////

bool ScintillAx::openSSH(const mol::string& path,const mol::string& ext, long enc)
{
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
				return 0;

			mol::punk<ISFTP> sftp;
			hr = conn->get_SFTP(&sftp);
			if (hr!=S_OK)
				return 0;


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
				return 0;
			}

			mol::punk<ISCP> scp;
			hr = conn->get_SCP(&scp);
			if (hr!=S_OK)
				return 0;

			SAFEARRAY* sa;

			hr = scp->GetFile( mol::bstr(mol::fromUTF8(p)),&sa);
			if (hr!=S_OK)
				return 0;

			std::string content;
			{
				mol::SFAccess<BYTE> sf(sa);
				content = std::string ((char*)sf(),sf.size());
			}
			::SafeArrayDestroy(sa);

			mol::FileEncoding fe;
			int e = fe.investigate(content);

			std::string utf8_bytes = fe.convertToUTF8( content, e );

			if ( fe.isBinary() )
			{
				if ( IDCANCEL == ::MessageBox(*this,_T("this looks like a BINARY\r\nopen anyway?"),mol::toString(p).c_str(),MB_OKCANCEL|MB_ICONQUESTION ) )
					return false;
			}

			props_->put_SysType(  fe.eolMode() );
			props_->put_Encoding( fe.codePage() );
			props_->put_WriteBOM( fe.hasBOM() ? VARIANT_TRUE : VARIANT_FALSE );

			edit()->setText(utf8_bytes);
			props_->put_Syntax(guess(mol::toString(p),ext));
			edit()->setSavePoint();
			setDirty(FALSE);
			return true;			
	}
	return false;
}



bool ScintillAx::load(const mol::string& p, const mol::string& ext,  long enc)
{
	edit()->clearAnnotations();

	if ( p.substr(0,6) == _T("ssh://") || p.substr(0,10) == _T("moe-ssh://") ) 
	{
		return openSSH(p,ext,enc);
	}

	std::stringstream is;
	
	edit()->setText("");
	edit()->setCodePage(SC_CP_UTF8);

    std::string s;
	mol::filestream in;
	in.open( mol::tostring(p),GENERIC_READ,FILE_SHARE_READ|FILE_SHARE_WRITE|FILE_SHARE_DELETE,0,OPEN_EXISTING);

    if ( !in.good() )
	{
		DWORD error = ::GetLastError();
		mol::string error_str = mol::WinErrorString(error);
		ODBGS1("error ",error);
		ODBGS(error_str.c_str());

		if ( error == 5 ) // access denied
		{
			//if ( this->loadAdminCOM(p,ext,utf8) )
				//return true;
			if ( mol::OS::has_uac() )
			{
				try {
					s = this->loadAdmin(p);
				}
				catch(...)
				{
					return false;
				}
			}
		}
	}
	else
	{
		s = in.readAll();
	}
	in.close();

	mol::FileEncoding fe;
	DWORD cp = fe.investigate(s);
	if ( cp == CP_WINUNICODE )
	{
		enc = CP_WINUNICODE;
	}
	if ( cp == CP_UTF8 )
	{
		enc = CP_UTF8;
	}
	std::string utf8_bytes = fe.convertToUTF8( s, enc );

	if ( fe.isBinary() )
	{
		if ( IDCANCEL == ::MessageBox(*this,_T("this looks like a BINARY\r\nopen anyway?"),mol::toString(p).c_str(),MB_OKCANCEL|MB_ICONQUESTION ) )
			return false;
	}

	props_->put_SysType(  fe.eolMode() );
	props_->put_Encoding( enc );
	props_->put_WriteBOM( fe.hasBOM() ? VARIANT_TRUE : VARIANT_FALSE );

	edit()->setText(mol::unix2dos(utf8_bytes));
	props_->put_Syntax(guess(p,ext));

	edit()->setSavePoint();
	setDirty(FALSE);
	return true;
}

HRESULT __stdcall ScintillAx::Load( LPSTREAM pStm)
{
	mol::punk<IPersistStream> s(props_);
	if ( s )
	{
		HRESULT hr =  s->Load(pStm);
		pStm >> mol::property( &sizel );
		return hr;
	}
	return E_FAIL;
}

HRESULT __stdcall ScintillAx::Save( LPSTREAM pStm,BOOL fClearDirty)
{
	mol::punk<IPersistStream> s(props_);
	if ( s )
	{
		HRESULT hr =  s->Save(pStm,fClearDirty);
		pStm << mol::property( &sizel );
		return hr;
	}
	return E_FAIL;
}


HRESULT __stdcall ScintillAx::Load( IPropertyBag *pPropBag,IErrorLog *pErrorLog)
{
	mol::punk<IPersistPropertyBag> p(props_);
	if ( p )
	{
		HRESULT hr =  p->Load(pPropBag,pErrorLog);
		pPropBag >> mol::property( _T("cs"), &sizel );
		return hr;
	}
	return E_FAIL;
}

HRESULT __stdcall ScintillAx::Save( IPropertyBag *pPropBag,BOOL fClearDirty,BOOL fSaveAllProperties)
{
	mol::punk<IPersistPropertyBag> p(props_);
	if ( p )
	{
		HRESULT hr =  p->Save(pPropBag,fClearDirty,fSaveAllProperties);
		pPropBag >> mol::property( _T("cs"), &sizel );
		return hr;
	}
	return E_FAIL;
}



/*

COLORREF hex2rgb( const char* hex )
{
    char buf[3];
    buf[2]=0;

    int r,g,b;
    r = g = b = 0;

    buf[0] = hex[1];
    buf[1] = hex[2];
    sscanf( buf, "%x", &r );

    buf[0] = hex[3];
    buf[1] = hex[4];
    sscanf( buf, "%x", &g );

    buf[0] = hex[5];
    buf[1] = hex[6];
    sscanf( buf, "%x", &b );

    return RGB(r,g,b);
}
*/



HRESULT  __stdcall ScintillAx::Apply(IScintillAxStyleSet * styleSet)
{
	if(!styleSet)
		return E_INVALIDARG;

	long lexer = SCLEX_NULL;

	HRESULT hr = styleSet->get_Id(&lexer);
	if ( hr !=S_OK)
	{
		edit()->setLexer(SCLEX_NULL);
		edit()->colorize(0);
		return S_OK;
	}

	edit()->setLexer(lexer);
	edit()->setStyleBits(7);
	/*
	edit()->setStyle(STYLE_DEFAULT,RGB(0,0,0),RGB(0xFF,0xFF,0xFF),10, "Courier New");
	edit()->styleSetBold(STYLE_DEFAULT,false);
	edit()->styleSetItalic(STYLE_DEFAULT,false);
	edit()->styleSetEolFilled(STYLE_DEFAULT,false);
	*/

	//edit()->styleClearAll();

	long cnt = 0;

	hr = styleSet->CountKeyWords(&cnt);
	if ( hr != S_OK  )
	{
		edit()->colorize(0);
		return hr;
	}

	for ( long i = 0; i < cnt; i++)
	{
		mol::bstr keywords;
		hr = styleSet->GetKeyWord(i,&keywords);
		if(hr==S_OK)
		{
			edit()->setKeywords(i,keywords.tostring());
		}
	}

	hr = styleSet->get_Count(&cnt);
	if ( hr !=S_OK)
	{
		edit()->colorize(0);
		return S_OK;
	}

	for( long i = 0; i < cnt; i++)
	{
		mol::punk<IScintillAxStyle> style;
		hr = styleSet->Item(mol::variant(i),&style);
		if(hr==S_OK)
		{
			long id = STYLE_DEFAULT;

			hr = style->get_Id(&id);
			if(hr !=S_OK)
			{
				continue;
			}

			VARIANT_BOOL vb = VARIANT_FALSE;

			hr = style->get_Bold(&vb);
			if(hr ==S_OK )
			{
				edit()->styleSetBold(id,vb == VARIANT_TRUE);
			}
			hr = style->get_Italic(&vb);
			if(hr ==S_OK )
			{
				edit()->styleSetItalic(id,vb == VARIANT_TRUE);
			}
			hr = style->get_Eol(&vb);
			if(hr ==S_OK )
			{
				edit()->styleSetEolFilled(id,vb == VARIANT_TRUE);
			}
			mol::bstr font;
			hr = style->get_Fontname(&font);
			if(hr ==S_OK && font.bstr_)
			{
				edit()->styleSetFont(id,font.tostring());
			}
			else
			{
				edit()->styleSetFont(id,"Courier New");
			}

			long size;
			hr = style->get_Fontsize(&size);
			if(hr ==S_OK && size)
			{
				edit()->styleSetSize(id,size);
			}
			mol::bstr back;
			hr = style->get_Backcolor(&back);
			if(hr ==S_OK && back.bstr_)
			{
				edit()->styleSetBack(id,mol::hex2rgb(back.toString()));
			}
			mol::bstr fore;
			hr = style->get_Forecolor(&fore);
			if(hr ==S_OK && fore.bstr_)
			{
				edit()->styleSetFore(id,mol::hex2rgb(fore.toString()));
			}

			if(i==0)
			{
				edit()->styleClearAll();
			}
		}
	}

	edit()->setStyle(SCI_ANNO_ERRORSTYLE,RGB(0xFF, 0, 0),RGB(0xE2, 0xE2, 0xE2));
	edit()->showAnnotations(2);
	edit()->colorize(0);

	return S_OK;
}

