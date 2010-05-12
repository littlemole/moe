#include "stdafx.h"
#include "ScintillaCtrl.h"
#include "win/path.h"
#include "win/shell.h"
#include "util/istr.h"
#include <sstream>
#include <fstream>
#include "msstkppg.h"
#include "../io/io_h.h"

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
			<< _T(" ") 
			<< file;

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

		ODBGS1("data read: ", data.size());

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
			<< _T(" ") 
			<< file;

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

	FONTDESC fd;
	::ZeroMemory(&fd,sizeof(fd));
	fd.cbSizeofstruct = sizeof(fd);
	fd.cySize.int64 = 10 * 10000;
	fd.lpstrName = L"Courier New";
	::OleCreateFontIndirect(&fd,IID_IFontDisp,(void**)&font_);	

	enc_  = SCINTILLA_ENCODING_ANSI;
	eol_  = SCINTILLA_SYSTYPE_UNIX;
	vbContext_  = VARIANT_TRUE;		
	vbWriteBOM_ = VARIANT_FALSE;
	vbReadOnly_ = VARIANT_FALSE;

	vbTabUsage_			  = VARIANT_TRUE;
	vbTabIndents_		  = VARIANT_TRUE;
	vbBackSpaceUnindents_ = VARIANT_TRUE;
	tabWidth_ = 4;

	vbContext_ = VARIANT_TRUE;
	vbOverType_   = VARIANT_FALSE;

	syntax_ = SCINTILLA_SYNTAX_PLAIN;

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

	if ( this->filename_.bstr_ )
		this->Load(this->filename_);

	col_.createObject(CLSID_ColorDialog);

	if ( edit() )
	{
		ODBGS("setting scintilla persist props");

		edit()->setTabWidth( tabWidth_ );
		edit()->setUseTabs(  vbTabUsage_ == VARIANT_TRUE ? true : false );
		edit()->setTabIndents( vbTabIndents_ == VARIANT_TRUE ? true : false );
		edit()->setBackSpaceUnindents( vbBackSpaceUnindents_ == VARIANT_TRUE ? true : false );

		edit()->setUsePopUp( vbContext_ == VARIANT_TRUE ? true : false );
		edit()->setReadOnly( vbReadOnly_ == VARIANT_TRUE ? true : false );
		edit()->setOvertype( vbOverType_ == VARIANT_TRUE ? true : false );
				
		//this->put_Font(font_);
		//this->put_Syntax(syntax_);				
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
		this->fire(DISPID_SCI_ONPOSCHANGED,line);

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

		this->fire(DISPID_SCI_ONCHAR,mol::bstr(tmp));

	}
    return 0;
}

LRESULT ScintillAx::OnDblClick(UINT msg, WPARAM wParam, LPARAM lParam)
{
	this->uiActivate();
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// COM interfaces
///////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// Properties
//////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::put_Filename( BSTR filename)
{ 
	if ( S_OK != OnRequestEdit( DISPID_SCI_FILENAME ) )
		return S_FALSE;

	filename_ = filename;

	this->OnChanged(DISPID_SCI_FILENAME);

	mol::string p( mol::toString(filename));

	this->fire( DISPID_SCI_ONFILENAMECHANGED,
				mol::bstr( mol::Path::filename(p)),
				filename_ );
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::get_Filename( BSTR* filename)
{ 
	if ( filename )
		*filename = ::SysAllocString(this->filename_.bstr_);
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::get_ReadOnly	( VARIANT_BOOL* vb )
{
	if ( vb )
	{
		if ( edit() ) 
		{
			bool b = false;
			edit()->getReadOnly(b);
			if ( b )
				vbReadOnly_ = VARIANT_TRUE;
			else
				vbReadOnly_ = VARIANT_FALSE;
		}

		*vb = vbReadOnly_;
	}
	return S_OK;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::put_ReadOnly	( VARIANT_BOOL vb  )
{
	if ( S_OK != OnRequestEdit(DISPID_SCI_READONLY) )
		return S_FALSE;

	vbReadOnly_ = vb;

	if ( edit() ) 
	{
		if ( vb == VARIANT_TRUE )
			edit()->setReadOnly(true);
		else
			edit()->setReadOnly(false);
	}

	this->OnChanged(DISPID_SCI_READONLY);
	return S_OK;
}
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::put_Syntax( long type)
{ 
	if ( S_OK != OnRequestEdit(DISPID_SCI_SYNTAX) )
		return S_FALSE;

	syntax_ = (SCINTILLA_SYNTAX)type;
	if ( edit() ) 
	{
		mol::punk<IFont> font(font_);
		mol::bstr fname;
		font->get_Name(&fname);
		CY cy;
		font->get_Size(&cy);

		long l = 1.0f * (cy.Hi) + cy.Lo/ULONG_MAX;
		edit()->mode( syntax_,l,fname.toString());		
		edit()->invalidateRect(0,TRUE);
		edit()->update();
	}

	this->OnChanged(DISPID_SCI_SYNTAX);
	this->fire(5,type);

	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::get_Syntax( long* type)
{ 
	if ( type )
	{
		if ( edit() )
		{
			syntax_ = edit()->mode();
		}
		*type = (long)syntax_;
	}
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::put_SysType( long type)
{ 
	if ( S_OK != OnRequestEdit(DISPID_SCI_SYSTYPE) )
		return S_FALSE;

	if ( type == 0 )
		this->eol_ = SCINTILLA_SYSTYPE_UNIX;
	else
		this->eol_ = SCINTILLA_SYSTYPE_WIN32;

	this->OnChanged(DISPID_SCI_SYSTYPE);
	this->fire(6,type);
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::get_SysType( long* type)
{ 
	if ( type )
	{
		if ( this->eol_ == SCINTILLA_SYSTYPE_UNIX )
			*type = SCINTILLA_SYSTYPE_UNIX;
		else
			*type = SCINTILLA_SYSTYPE_WIN32;
	}
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::put_Encoding( long type)
{ 
	if ( type >= 0 && type <= 2 )
	{
		if ( S_OK != OnRequestEdit(DISPID_SCI_ENCODING) )
			return S_FALSE;
		this->enc_ = (SCINTILLA_ENCODING)type;
		this->OnChanged(DISPID_SCI_ENCODING);
		if ( type == SCINTILLA_ENCODING_UTF16 )
			this->put_WriteBOM(VARIANT_TRUE);
		else
			this->put_WriteBOM(VARIANT_FALSE);
		this->fire(7,type);
	}
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::get_Encoding( long* type)
{ 
	if ( type )
		*type = this->enc_;
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::put_TabUsage( VARIANT_BOOL vbTabUsage)
{ 
	if ( S_OK != OnRequestEdit(DISPID_SCI_TABUSAGE) )
		return S_FALSE;

	vbTabUsage_ = vbTabUsage;

	if ( edit() )
	{
		if ( vbTabUsage == VARIANT_TRUE )
			edit()->setUseTabs(true);
		else
			edit()->setUseTabs(false);
	}
	this->OnChanged(DISPID_SCI_TABUSAGE);

	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::get_TabUsage( VARIANT_BOOL* vbTabUsage)
{ 
	if ( vbTabUsage )
	{
		if ( edit() )
		{
			bool b = false;
			b = edit()->getUseTabs() != 0;
			if ( b )
				vbTabUsage_ = VARIANT_TRUE;
			else
				vbTabUsage_ = VARIANT_FALSE;
		}

		*vbTabUsage = vbTabUsage_;
	}
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::put_TabIndents( VARIANT_BOOL vbTabIndents)
{ 
	if ( S_OK != OnRequestEdit(DISPID_SCI_TABINDENTS) )
		return S_FALSE;

	vbTabIndents_ = vbTabIndents;

	if ( edit() )
	{
		if ( vbTabIndents == VARIANT_TRUE )
			edit()->setTabIndents(true);
		else
			edit()->setTabIndents(false);
	}

	this->OnChanged(DISPID_SCI_TABINDENTS);

	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::get_TabIndents( VARIANT_BOOL* vbTabIndents)
{ 
	if ( vbTabIndents )
	{
		if ( edit() )
		{
			bool b = false;
			b = edit()->getTabIndents() != 0;
			if ( b )
				vbTabIndents_ = VARIANT_TRUE;
			else
				vbTabIndents_ = VARIANT_FALSE;
		}

		*vbTabIndents = vbTabIndents_;
	}
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::put_BackSpaceUnindents( VARIANT_BOOL vbBackSpaceUnindents)
{ 
	if ( S_OK != OnRequestEdit(DISPID_SCI_BACKSPACEUNINDENTS) )
		return S_FALSE;

	vbBackSpaceUnindents_ = vbBackSpaceUnindents;

	if ( edit() )
	{
		if ( vbBackSpaceUnindents == VARIANT_TRUE )
			edit()->setBackSpaceUnindents(true);
		else
			edit()->setBackSpaceUnindents(false);
	}

	this->OnChanged(DISPID_SCI_BACKSPACEUNINDENTS);
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::get_BackSpaceUnindents( VARIANT_BOOL* vbBackSpaceUnindents)
{ 
	if ( vbBackSpaceUnindents )
	{
		if ( edit() )
		{
			bool b = false;
			b = edit()->getBackSpaceUnindents() != 0;
			if ( b )
				*vbBackSpaceUnindents = VARIANT_TRUE;
			else
				*vbBackSpaceUnindents = VARIANT_FALSE;
		}

		*vbBackSpaceUnindents = vbBackSpaceUnindents_;
	}
	return S_OK; 
}
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::put_TabWidth( long width)
{ 
	if ( S_OK != OnRequestEdit(DISPID_SCI_TABWIDTH) )
		return S_FALSE;

	tabWidth_ = width;

	if ( edit() )
	{
		edit()->setTabWidth(width);
	}
	this->OnChanged(DISPID_SCI_TABWIDTH);
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::get_TabWidth( long* width)
{ 	
	if ( edit() )
		tabWidth_ = edit()->getTabWidth();

	*width = tabWidth_;
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::put_Overtype( VARIANT_BOOL vbOvertype)
{ 
	if ( S_OK != OnRequestEdit(DISPID_SCI_OVERTYPE) )
		return S_FALSE;

	vbOverType_ = vbOvertype;

	if ( edit() )
	{
		if ( vbOvertype == VARIANT_TRUE )
			edit()->setOvertype(true);
		else
			edit()->setOvertype(false);
	}
	this->OnChanged(DISPID_SCI_OVERTYPE);
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::get_Overtype( VARIANT_BOOL* vbOvertype)
{ 
	if ( vbOvertype )
	{
		if ( edit() )
		{
			bool b = false;
			b = edit()->getOvertype() != 0;
			if ( b )
				*vbOvertype = VARIANT_TRUE;
			else
				*vbOvertype = VARIANT_FALSE;
		}

		*vbOvertype = vbOverType_;
	}
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::put_UseContext(VARIANT_BOOL vbContext)
{ 
	if ( S_OK != OnRequestEdit(DISPID_SCI_USECONTEXT) )
		return S_FALSE;

	vbContext_ = vbContext;

	if ( edit() )
	{
		if ( vbContext == VARIANT_TRUE )
			edit()->setUsePopUp(true);
		else
			edit()->setUsePopUp(false);
	}

	this->OnChanged(DISPID_SCI_USECONTEXT);
	return S_OK; 
}

HRESULT __stdcall ScintillAx::get_UseContext(VARIANT_BOOL* vbContext)
{ 
	if ( vbContext )
	{
		*vbContext = vbContext_;
	}
	return S_OK; 
}

HRESULT __stdcall ScintillAx::putref_Font( IFontDisp* font)
{
	if ( S_OK != OnRequestEdit(DISPID_FONT) )
		return S_FALSE;

	if ( !font )
		return S_FALSE;


	font_ = font;

	if ( !edit() )
	{
		return S_OK; 
	}

	mol::punk<IFont> f(font_);
	if ( f )
	{
		mol::bstr fname;
		CY cy;
		if ( S_OK == f->get_Name(&fname) )
			if ( S_OK == f->get_Size(&cy) )
			{
				edit()->mode(edit()->mode(),cy.int64/10000,fname.toString());				
				edit()->invalidateRect(0,TRUE);
				edit()->colorize(0);
				this->OnChanged(DISPID_FONT);
				this->setDirty(TRUE);
			}
	}
	return S_OK; 
}

HRESULT __stdcall ScintillAx::put_Font( IFontDisp* font)
{
	if ( S_OK != OnRequestEdit(DISPID_FONT) )
		return S_FALSE;

	if ( !font )
		return S_FALSE;

	mol::punk<IFont> f(font);	
	if ( f )
	{
		font_.release();
		mol::punk<IFont> clone;
		f->Clone(&clone);
		clone.queryInterface(IID_IFontDisp,(void**)&font_);

		if ( !edit() )
		{
			return S_OK; 
		}

		mol::bstr fname;
		CY cy;
		if ( S_OK == f->get_Name(&fname) )
			if ( S_OK == f->get_Size(&cy) )
			{
				edit()->mode(edit()->mode(),cy.int64/10000,fname.toString());				
				edit()->invalidateRect(0,TRUE);
				edit()->colorize(0);
				this->setDirty(TRUE);
				this->OnChanged(DISPID_FONT);
			}
	}
	return S_OK; 
}

HRESULT __stdcall ScintillAx::get_Font( IFontDisp** font)
{
	if ( font && font_ )
	{
		return font_.queryInterface( IID_IFontDisp,(void**)font);
	}
	return S_OK;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

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
	if ( S_OK != OnRequestEdit(DISPID_SCI_FILENAME) )
		return S_FALSE;

	if (!file)
		return S_FALSE;

	mol::string p(mol::toString(file));
	if ( mol::Path::exists(p) )
	{
		if ( !mol::Path::isDir(p) )
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
					this->put_Filename(file);
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

HRESULT __stdcall ScintillAx::LoadUTF8( BSTR file )
{ 
	if (file)
	{
		mol::string p(mol::toString(file));
		if ( mol::Path::exists(p) )
		{
			if ( !mol::Path::isDir(p) )
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
					if ( load(p, ext, true ) )
					{
						this->put_Encoding(SCINTILLA_ENCODING_UTF8);

						this->put_Filename(file);
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
	if ( !this->save(filename_.toString()) )
		return S_FALSE;
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::SaveAs( BSTR filename )
{ 
	if ( S_OK != OnRequestEdit(DISPID_SCI_FILENAME) )
		return S_FALSE;

	mol::bstr old(filename_);

	this->put_Filename(filename);
	if ( S_OK == this->Save() )
	{
		return S_OK;
	}
	this->put_Filename(old);
	return S_FALSE;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// Text Manipulation
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::SetText( BSTR text)
{ 
	std::string utf8 = "";
	if ( text )
		utf8 = mol::wstring2utf8(text);
	edit()->setText(utf8);
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::GetText( BSTR* text)
{
	if ( text )
	{
		int s = edit()->getLength();
		char* c = new char[s+1];
		edit()->getText(c,s+1);
		c[s] = 0;
		*text = ::SysAllocString(mol::utf82wstring(c).c_str());
	}
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::TextLength( long* size)
{ 
	if ( size )
	{
		*size = edit()->getLength();
	}
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::Append( BSTR text)
{
	if ( text )
	{
		edit()->appendText(mol::wstring2utf8(text));
	}
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::Insert( BSTR text, long pos )
{ 
	if ( text && edit() )
		edit()->insertText(mol::wstring2utf8(text), pos );
	return S_OK; 
}


///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::Modified( VARIANT_BOOL* vbModified )
{ 
	if ( vbModified )
	{
		if ( edit()->getModified() )
			*vbModified = VARIANT_TRUE;
		else
			*vbModified = VARIANT_FALSE;
	}
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// Position and Caret
//////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::SetCaretPos( long pos)
{
	edit()->pos(pos);
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::GetCaretPos( long* pos)
{ 
	if ( pos )
	{
		*pos = 0;
		if ( edit() )
			*pos = edit()->pos();
	}
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::CharAt( long pos, BSTR* ch)
{ 
	if ( ch )
	{
		char buf[2];
		buf[0] = (char)edit()->getCharAt(pos);
		buf[1] = 0;
		*ch = ::SysAllocString(mol::utf82wstring(buf).c_str());	
	}
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::Scroll( long cols, long lines )
{ 
	edit()->lineScroll(cols,lines);
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::ScrollIntoView()
{ 
	edit()->scrollCaret();
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::SetSearchPos( long pos)
{ 
	edit()->searchPos(pos);
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::GetSearchPos( long* pos)
{ 
	if ( pos )
	{
		*pos = edit()->searchPos();
	}
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::SetAnchorPos( long pos)
{ 
	edit()->anchor(pos);
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::GetAnchorPos( long* pos)
{ 
	if ( pos )
	{
		*pos = edit()->anchor();
	}
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// Line Handling
//////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::LineCount( long* line)
{ 
	if ( line )
		*line = edit()->getLineCount();
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::CurrentLine( long* line)
{ 
	if ( line )
		*line = edit()->lineFromPos(edit()->pos());
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::LineFromPos( long pos, long* line )
{
	if ( line )
		*line = edit()->lineFromPos(pos);

	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::PosFromLine( long line, long* pos )
{
	if ( pos )
		*pos = edit()->posFromLine(line);
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::LineEndPos( long line, long* pos )
{
	if ( pos )
		*pos = edit()->lineEndPos(line);
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::FirstVisibleLine( long* line )
{
	if ( line )
		*line = edit()->getFirstVisibleLine();
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::LinesOnScreen( long* lines )
{
	if ( lines )
		*lines = edit()->getLinesOnScreen();

	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::LineLength( long line, long* length)
{ 
	if ( length )
	{
		*length = edit()->getLineLength(line);
	}
	return S_OK; 
}
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::LineText( long line, BSTR* text )
{ 
	if ( text )
	{
		int e,s;
		s = edit()->posFromLine(line);
		e = edit()->lineEndPos(line);
		std::string l = "";
		l = edit()->getTextRange(s,e);
		*text = ::SysAllocString(mol::utf82wstring(l).c_str());
	}
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::SetLineText( long line, BSTR text )
{ 
	if ( text )
	{
		if ( line <= edit()->getLineCount() )
		{
			int start = edit()->posFromLine(line);
			int end   = edit()->lineEndPos(line);
			edit()->setSel(start,end);
			edit()->replaceSel(mol::BSTR2ansi(text));
		}
	}
	return S_OK; 
}
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::GotoLine( long line )
{ 
	edit()->gotoLine(line);
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// Selection
//////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::GetSelection	( long* first, long* last)
{
	if ( first && last )
	{
		*first = edit()->getSelStart();
		*last  = edit()->getSelEnd();
	}
	return S_OK;
}

HRESULT __stdcall ScintillAx::SetSelection		( long first, long last )
{
	edit()->setSel(first,last);
	return S_OK;
}

HRESULT __stdcall ScintillAx::GetSelectionText	( BSTR* text )
{
	if ( text )
	{
		std::string txt = "";
		txt = edit()->getSelText();
		*text = mol::ansi2BSTR(txt);
	}
	return S_OK;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::SetSelectionStart( long pos)
{ 
	edit()->setSelStart(pos);
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::GetSelectionStart( long* pos)
{ 
	if ( pos )
	{
		*pos = edit()->getSelStart();
	}
	return S_OK; 
}
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::SetSelectionEnd( long pos)
{ 
	edit()->setSelEnd(pos);
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::GetSelectionEnd( long* pos)
{ 
	if ( pos )
	{
		*pos = edit()->getSelEnd();
	}
	return S_OK; 
}
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::ReplaceSelection( BSTR text )
{ 
	if ( text )
		edit()->replaceSel(mol::wstring2utf8(text));
	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// search / replace
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::Search( BSTR what, long flags, VARIANT_BOOL* vbFound)
{ 
	bool b = edit()->search(mol::tostring(what),flags);
	if ( vbFound )
		if ( b )
			*vbFound = VARIANT_TRUE;
		else
			*vbFound = VARIANT_FALSE;

	return S_OK; 
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::Replace( BSTR what, BSTR with, long flags, VARIANT_BOOL* vbReplaced)
{ 
	bool b = edit()->replace(mol::tostring(what),mol::tostring(with),flags);
	if ( vbReplaced )
		if ( b )
			*vbReplaced = VARIANT_TRUE;
		else
			*vbReplaced = VARIANT_FALSE;

	return S_OK; 
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

//////////////////////////////////////////////////////////////////////////////
//
// Cut Copy Paste
//
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::Cut ()
{
	edit()->cut(); 
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::Copy ()
{
	edit()->copy();
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::Paste ()
{
	edit()->paste();
	return S_OK;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

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

HRESULT __stdcall ScintillAx::SetIndent(long i)
{ 
	edit()->setIndent(i);
	return S_OK; 
}

HRESULT __stdcall ScintillAx::ConvertTabs()
{ 
	std::string what = "\t";
	std::string with = "";
	int n = edit()->getTabWidth();
    for ( int i = 0; i < n; i++ )
        with +=" ";
	std::string utf8what(mol::ansi2utf8(what));
	std::string utf8with(mol::ansi2utf8(with));

    int c = 0;
	while ( edit()->replace( mol::tostring(utf8what), mol::tostring(utf8with), FR_REPLACEALL ) )
    {
        c++;
    }
	mol::ostringstream oss;
	oss << c << _T(" replaces");
	::MessageBox( *this,oss.str().c_str(),_T("replace result:"),MB_APPLMODAL);

	return S_OK; 
}

HRESULT __stdcall ScintillAx::GetPages( CAUUID *pPages)
{
	if ( !pPages )
		return E_POINTER;
	pPages->cElems = 2;
	pPages->pElems = (GUID*)::CoTaskMemAlloc(sizeof(GUID)*2);
	pPages->pElems[0] = CLSID_ScintillAxProperties;
	pPages->pElems[1] = CLSID_StockFontPage;

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


HRESULT __stdcall ScintillAx::GetTextRange(long start, long end, BSTR* range)
{
	std::string s = edit()->getTextRange(start,end);
	if ( range )
		*range = ::SysAllocString(mol::utf82wstring(s).c_str());
	return S_OK;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

HRESULT __stdcall ScintillAx::Properties()
{
	LPUNKNOWN punks[] = { (IUnknown*)(IScintillAx*)this };
	CLSID pages[]     = { CLSID_ScintillAxProperties };

	::OleCreatePropertyFrame(*this,100,100,filename_.towstring().c_str(),1,punks,1,pages,0,0,0);

	return S_OK;
}

HRESULT __stdcall ScintillAx::SyntaxDisplayName(BSTR* syntax)
{
	if (!syntax)
		return E_INVALIDARG;

	*syntax = ::SysAllocString( mol::towstring(edit()->SyntaxDisplayName()).c_str() );
	return S_OK;
}

HRESULT __stdcall ScintillAx::GetSyntaxDisplayName(long type, BSTR* syntax)
{
	if (!syntax)
		return E_INVALIDARG;

	*syntax = ::SysAllocString( mol::towstring(edit()->SyntaxDisplayName(type)).c_str() );
	return S_OK;
}

HRESULT __stdcall ScintillAx::InsertColorDialog( HWND wnd )
{
	if ( !col_ ) 
		return S_OK;

	VARIANT_BOOL vb = VARIANT_FALSE;
	if ( S_OK != col_->Show(wnd,&vb) )
		return S_OK;

	if ( vb != VARIANT_TRUE )
		return S_OK;

	mol::punk<IScintillAx> guard(this);

	mol::bstr hex;
	if ( S_OK != col_->get_HexColor(&hex) || hex.bstr_ == 0)
		return S_OK;

	long pos;
	if ( S_OK != GetCaretPos(&pos) )
		return S_OK;

	if ( S_OK == Insert(hex,pos) )
		return S_OK;
	return S_OK;
}

HRESULT __stdcall ScintillAx::put_WriteBOM( VARIANT_BOOL vb)
{
	if ( S_OK != OnRequestEdit(DISPID_SCI_WRITEBOM) )
		return S_FALSE;

	vbWriteBOM_ = vb;

	this->OnChanged(DISPID_SCI_WRITEBOM);

	return S_OK;
}

HRESULT __stdcall ScintillAx::get_WriteBOM( VARIANT_BOOL* vb)
{
	if ( !vb)
		return E_INVALIDARG;

	*vb = vbWriteBOM_;

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
	if ( this->enc_ == SCINTILLA_ENCODING_UTF16 )
	{
		txt = std::string( (char*) mol::utf82wstring(txt).c_str(), sizeof(wchar_t)*txt.size() );
		if ( this->vbWriteBOM_ == VARIANT_TRUE  )
		{
			oss.write((const char*)mol::FileEncoding::UTF16LE_BOM,2);
		}
		if ( this->eol_ == SCINTILLA_SYSTYPE_UNIX )
		{
			txt = mol::dos2unix(txt);
		}
	}
	if ( this->enc_ == SCINTILLA_ENCODING_ANSI )
	{
		txt = mol::utf82ansi(txt);
		if ( this->eol_ == SCINTILLA_SYSTYPE_UNIX )
		{
			txt = mol::dos2unix(txt);
		}
	}
	if ( this->enc_ == SCINTILLA_ENCODING_UTF8 )
	{
		oss.write((const char*)mol::FileEncoding::UTF8_BOM,3);
		if ( this->eol_ == SCINTILLA_SYSTYPE_UNIX )
		{
			txt = mol::wstring2utf8(mol::dos2unix(mol::utf82wstring(txt)));
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

	long enc = CP_ACP;
	switch ( enc_ )
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
			enc = CP_ACP;
			break;
		}
	}
	hr = file->put_Encoding(enc);
	if ( hr != S_OK )
		return false;

	hr = file->put_EoL(eol_);
	if ( hr != S_OK )
		return false;

	hr = file->put_UseBOM(vbWriteBOM_);
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

//////////////////////////////////////////////////////////////////////////////
//
// save file impl
//
//////////////////////////////////////////////////////////////////////////////

bool ScintillAx::save(const mol::string& location)
{
	if ( location.size() > 0 )
	{
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

		switch ( enc_ )
		{
			case SCINTILLA_ENCODING_UTF16 :
			{
				std::string u;
				u = edit()->get_Text();
				std::wstring ws = mol::utf82wstring(u);	
				if ( vbWriteBOM_ == VARIANT_TRUE )
					of.write((const char*)mol::FileEncoding::UTF16LE_BOM,2);
				of.write( (char*)(ws.c_str()), ws.size()*2 );
				break;
			}
			case SCINTILLA_ENCODING_UTF8 :
			{
				std::string u;
				u = edit()->get_Text();
				if ( eol_ == SCINTILLA_SYSTYPE_UNIX )
					u = mol::dos2unix(u);
				if ( vbWriteBOM_ == VARIANT_TRUE )
					of.write((const char*)mol::FileEncoding::UTF8_BOM,3);
				of.write( (char*)(u.c_str()), u.size() );
				break;
			}
			default :
			{
				std::string u;
				u = edit()->get_Text();
				if ( eol_ == SCINTILLA_SYSTYPE_UNIX )
					u = mol::dos2unix(u);
				std::string s = mol::utf82ansi(u);				
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

bool ScintillAx::loadAdmin(const mol::string& p, const mol::string& ext,  bool utf8)
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

	mol::FileEncoding e;
	DWORD cp = e.investigate(data);

	switch(cp)
	{
		case CP_UTF8:
		{
			enc_ = SCINTILLA_ENCODING_UTF8;
			break;
		}
		case CP_WINUNICODE:
		{
			enc_ = SCINTILLA_ENCODING_UTF16;
			break;
		}
		default:
		{
			enc_ = SCINTILLA_ENCODING_ANSI;
			break;
		}
	}

	eol_ = (SCINTILLA_SYSTYPE)(e.eolMode());

	if ( e.isBinary() )
	{
		if ( IDCANCEL == ::MessageBox(*this,_T("this looks like a BINARY\r\nopen anyway?"),mol::toString(p).c_str(),MB_OKCANCEL|MB_ICONQUESTION ) )
			return false;
	}

	//std::string title(p);
	if ( utf8 )
	{
		this->put_Encoding(SCINTILLA_ENCODING_UTF8);
		edit()->setCodePage(SC_CP_UTF8);
		std::string s2(data);
		if ( data.substr(0,3) == std::string((char*)mol::FileEncoding::UTF8_BOM,3) )
			s2 = std::string( data.c_str()+3, data.size()-3);

		edit()->appendText(s2);
	}
	else
	switch ( enc_ )
	{
		case SCINTILLA_ENCODING_UTF16 :
		{
			// jump over BOM
			this->put_Encoding(SCINTILLA_ENCODING_UTF16);
			std::string s2(data);
			if ( data.substr(0,2) == std::string((char*)mol::FileEncoding::UTF16LE_BOM,2) )
				s2 = std::string( data.data()+2, data.size()-2);
			// it really is a UCS-2 string, so cast to wchar_t (WIN32)
			std::wstring ws((wchar_t*)(s2.data()),s2.size()/sizeof(wchar_t));
			// now convert UTF16-LE to UTF-8
			std::string u = mol::wstring2utf8(ws);
			edit()->setCodePage(SC_CP_UTF8);
			u = mol::unix2dos(u);
			edit()->setText(u);
			break;
		}
		case SCINTILLA_ENCODING_UTF8 :
		{
			this->put_Encoding(SCINTILLA_ENCODING_UTF8);
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
			this->put_Encoding(SCINTILLA_ENCODING_ANSI);
			edit()->setCodePage(SC_CP_UTF8);
			std::string s2(mol::ansi2utf8(data));
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

//////////////////////////////////////////////////////////////////////////////
//
// load file as admin using COM elevation moniker
//
//////////////////////////////////////////////////////////////////////////////

bool ScintillAx::loadAdminCOM(const mol::string& p, const mol::string& ext,  bool utf8)
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

	long enc=0;
	hr = file->get_Encoding(&enc);
	if ( hr != S_OK )
		return false;

	switch(enc)
	{
		case CP_UTF8:
		{
			enc_ = SCINTILLA_ENCODING_UTF8;
			break;
		}
		case CP_WINUNICODE:
		{
			enc_ = SCINTILLA_ENCODING_UTF16;
			break;
		}
		default:
		{
			enc_ = SCINTILLA_ENCODING_ANSI;
			break;
		}
	}
	long eol=0;
	hr = file->get_EoL(&eol);
	if ( hr != S_OK )
		return false;
	eol_ = (SCINTILLA_SYSTYPE)(eol);

	file->Close();
	if ( utf8 )
	{
		enc_= (SCINTILLA_ENCODING_UTF8);
	}

	this->put_Encoding(enc_);
	edit()->setCodePage(SC_CP_UTF8);
	edit()->setText("");
	edit()->appendText(content.tostring());
	edit()->mode(p,ext);
	edit()->setSavePoint();
	setDirty(FALSE);
	return true;
}

//////////////////////////////////////////////////////////////////////////////
//
// load file
//
//////////////////////////////////////////////////////////////////////////////

bool ScintillAx::load(const mol::string& p, const mol::string& ext,  bool utf8)
{
	//filename_ = p;

	std::stringstream is;
	std::ifstream in;
	in.open( p.c_str(), std::ios::binary );

    std::string s;
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
				return this->loadAdmin(p,ext,utf8);
			}
		}
		return false;
	}

	edit()->setText("");
    char buf[1024];
    if ( !in.eof() )
    {
        in.read(buf,1023);
		is.write(buf,in.gcount());
    }
	s = is.str();
	mol::FileEncoding e;
	DWORD cp = e.investigate(s);

	switch(cp)
	{
		case CP_UTF8:
		{
			enc_ = SCINTILLA_ENCODING_UTF8;
			break;
		}
		case CP_WINUNICODE:
		{
			enc_ = SCINTILLA_ENCODING_UTF16;
			break;
		}
		default:
		{
			enc_ = SCINTILLA_ENCODING_ANSI;
			break;
		}
	}

	eol_ = (SCINTILLA_SYSTYPE)(e.eolMode());

	if ( e.isBinary() )
	{
		if ( IDCANCEL == ::MessageBox(*this,_T("this looks like a BINARY\r\nopen anyway?"),mol::toString(p).c_str(),MB_OKCANCEL|MB_ICONQUESTION ) )
			return false;
	}
	if ( in.gcount() == 1023)
    while ( !in.eof() )
    {
        in.read(buf,1023);
		is.write(buf,in.gcount());
    }

    in.close();
	s = is.str();

	//std::string title(p);
	if ( utf8 )
	{
		this->put_Encoding(SCINTILLA_ENCODING_UTF8);
		edit()->setCodePage(SC_CP_UTF8);
		std::string s2(s);
		if ( s.substr(0,3) == std::string((char*)mol::FileEncoding::UTF8_BOM,3) )
			s2 = std::string(s.c_str()+3,s.size()-3);

		edit()->appendText(s2);
	}
	else
	switch ( enc_ )
	{
		case SCINTILLA_ENCODING_UTF16 :
		{
			// jump over BOM
			this->put_Encoding(SCINTILLA_ENCODING_UTF16);
			std::string s2(s);
			if ( s.substr(0,2) == std::string((char*)mol::FileEncoding::UTF16LE_BOM,2) )
				s2 = std::string(s.data()+2,s.size()-2);
			// it really is a UCS-2 string, so cast to wchar_t (WIN32)
			std::wstring ws((wchar_t*)(s2.data()),s2.size()/sizeof(wchar_t));
			// now convert UTF16-LE to UTF-8
			std::string u = mol::wstring2utf8(ws);
			edit()->setCodePage(SC_CP_UTF8);
			u = mol::unix2dos(u);
			edit()->setText(u);
			break;
		}
		case SCINTILLA_ENCODING_UTF8 :
		{
			this->put_Encoding(SCINTILLA_ENCODING_UTF8);
			edit()->setCodePage(SC_CP_UTF8);
			std::string s2;
			if ( s.substr(0,3) == std::string((char*)mol::FileEncoding::UTF8_BOM,3) )
				s2 = std::string(s.c_str()+3,s.size()-3);
			else
				s2 = s;

			s2 = mol::unix2dos(s2);
			edit()->setText(s2);
			break;
		}
		default:
		{
			this->put_Encoding(SCINTILLA_ENCODING_ANSI);
			edit()->setCodePage(SC_CP_UTF8);
			std::string s2(mol::ansi2utf8(s));
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
