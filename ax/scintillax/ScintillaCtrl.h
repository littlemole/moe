#ifndef MOL_DEF_SCINTILLAX_VIEW_DEF_GUARDING_
#define MOL_DEF_SCINTILLAX_VIEW_DEF_GUARDING_

#pragma once
#include "util/uni.h"
#include "win/enc.h"
#include "scieditor.h"
#include "win/MsgMap.h"
#include "ole/Ctrl.h"
#include "ole/Bstr.h"
#include "ole/Persist.h"
#include "ScintillAx_h.h"
#include "ax/ShellCtrl/ShellCtrl_h.h"
#include "include/resource.h"
#include "include/xmlui.h"

///////////////////////////////////////////////////////////////////////////////////
// Scintilla as AX Control impl
///////////////////////////////////////////////////////////////////////////////////

// font helper class
class FontDesc
{
public:
	FontDesc();
	FontDesc(const std::string& font, int size);
	FontDesc(HFONT hfont);
	const char* name();
	const char* size();
	const char* weight();
	const char* style();
    const char* decoration();

	LOGFONTA* desc()
	{
		return &m_logfont;
	}
private:
	LOGFONTA	m_logfont;
};

///////////////////////////////////////////////////////////////////////////////
// embedded scintilla editor window
///////////////////////////////////////////////////////////////////////////////

class EditWnd
	: public mol::Control< ScintillaEditor, 
						   WS_CHILD|WS_CLIPSIBLINGS|
                           WS_CLIPCHILDREN,
                           WS_EX_STATICEDGE>
{};


///////////////////////////////////////////////////////////////////////////////
// DispIds
///////////////////////////////////////////////////////////////////////////////

#define DISPID_SCI_FILENAME					1
#define DISPID_SCI_READONLY					2
#define DISPID_SCI_SYNTAX					3
#define DISPID_SCI_SYSTYPE					4
#define DISPID_SCI_ENCODING					5
#define DISPID_SCI_TABUSAGE					6
#define DISPID_SCI_TABINDENTS				7
#define DISPID_SCI_BACKSPACEUNINDENTS		8
#define DISPID_SCI_TABWIDTH					9
#define DISPID_SCI_OVERTYPE					10
#define DISPID_SCI_USECONTEXT				11
#define DISPID_SCI_WRITEBOM					69

#define DISPID_SCI_ONFILENAMECHANGED		1
#define DISPID_SCI_ONSHOWMENU				2
#define DISPID_SCI_ONPOSCHANGED				3
#define DISPID_SCI_ONCHAR					4

///////////////////////////////////////////////////////////////////////////////
// the scintilla active X control
///////////////////////////////////////////////////////////////////////////////

class ScintillAx: 
	public mol::ax_ctrl<ScintillAx,CLSID_ScintillAx,false,mol::Window,WS_CHILD|WS_CLIPSIBLINGS|WS_CLIPCHILDREN|WS_VISIBLE,0>,
	public mol::Dispatch<IScintillAx>,
	public mol::ctrl_events<ScintillAx,_IScintillAxEvents>,
	public mol::ProvideClassInfo<ScintillAx>,
	public mol::interfaces< ScintillAx,
			mol::implements<
					IDispatch,
					IScintillAx,
					IOleObject,
					IDataObject,
					mol::interface_ex<IPersist,IPersistStreamInit>,
					mol::interface_ex<IPersistStream,IPersistStreamInit>,
					IPersistStreamInit,
					IPersistStorage,
					IPersistPropertyBag,
					IRunnableObject,
					IViewObject,
					IViewObject2,
					mol::interface_ex<IOleWindow,IOleInPlaceObjectWindowless>,
					mol::interface_ex<IOleInPlaceObject,IOleInPlaceObjectWindowless>,
					IOleControl,
					IConnectionPointContainer,
					IProvideClassInfo,
					ISpecifyPropertyPages>
				>
{
public:

    ScintillAx(void);
    ~ScintillAx();

	//properties:

		HRESULT virtual __stdcall put_Filename( BSTR filename);
		HRESULT virtual __stdcall get_Filename( BSTR* filename);
		HRESULT virtual __stdcall put_ReadOnly(VARIANT_BOOL vbReadOnly);
		HRESULT virtual __stdcall get_ReadOnly( VARIANT_BOOL* vbReadOnly);
		HRESULT virtual __stdcall put_Syntax( long type);
		HRESULT virtual __stdcall get_Syntax( long* type);
		HRESULT virtual __stdcall put_SysType( long type);
		HRESULT virtual __stdcall get_SysType( long* type);
		HRESULT virtual __stdcall put_Encoding( long type);
		HRESULT virtual __stdcall get_Encoding( long* type);
		HRESULT virtual __stdcall put_TabUsage( VARIANT_BOOL vbTabUsage);
		HRESULT virtual __stdcall get_TabUsage( VARIANT_BOOL* vbTabUsage);
		HRESULT virtual __stdcall put_TabIndents( VARIANT_BOOL vbTabIndents);
		HRESULT virtual __stdcall get_TabIndents( VARIANT_BOOL* vbTabIndents);
		HRESULT virtual __stdcall put_BackSpaceUnindents( VARIANT_BOOL vbBackSpaceUnindents);
		HRESULT virtual __stdcall get_BackSpaceUnindents( VARIANT_BOOL* vbBackSpaceUnindents);
		HRESULT virtual __stdcall put_TabWidth( long width);
		HRESULT virtual __stdcall get_TabWidth( long* width);
		HRESULT virtual __stdcall put_Overtype( VARIANT_BOOL vbOvertype);
		HRESULT virtual __stdcall get_Overtype( VARIANT_BOOL* vbOvertype);
		HRESULT virtual __stdcall put_UseContext( VARIANT_BOOL vbUseContext);
		HRESULT virtual __stdcall get_UseContext( VARIANT_BOOL* vbUseContext);
		HRESULT virtual __stdcall putref_Font( IFontDisp* font);
		HRESULT virtual __stdcall put_Font( IFontDisp* font);
		HRESULT virtual __stdcall get_Font( IFontDisp** font);
		HRESULT virtual __stdcall put_WriteBOM( VARIANT_BOOL vb);
		HRESULT virtual __stdcall get_WriteBOM( VARIANT_BOOL* vb);

	//methods:

		// Load / Save

		HRESULT virtual __stdcall Load( BSTR file );
		HRESULT virtual __stdcall LoadUTF8( BSTR file );
		HRESULT virtual __stdcall Save();
		HRESULT virtual __stdcall SaveAs( BSTR filename );

		// Text Manipulation

		HRESULT virtual __stdcall SetText( BSTR text);
		HRESULT virtual __stdcall GetText( BSTR* text);
		HRESULT virtual __stdcall TextLength( long* size);
		HRESULT virtual __stdcall Append( BSTR text);
		HRESULT virtual __stdcall Insert( BSTR text, long pos );
		HRESULT virtual __stdcall Modified( VARIANT_BOOL* vbModified );

		// Position and Caret

		HRESULT virtual __stdcall SetCaretPos( long pos);
		HRESULT virtual __stdcall GetCaretPos( long* pos);

		HRESULT virtual __stdcall CharAt( long pos, BSTR* ch);
		HRESULT virtual __stdcall ScrollIntoView();
		HRESULT virtual __stdcall Scroll( long cols, long lines);

		HRESULT virtual __stdcall SetSearchPos( long pos);
		HRESULT virtual __stdcall GetSearchPos( long* pos);

		HRESULT virtual __stdcall SetAnchorPos( long pos);
		HRESULT virtual __stdcall GetAnchorPos( long* pos);

		// Line Handling
		HRESULT virtual __stdcall LineCount( long* line);
		HRESULT virtual __stdcall CurrentLine( long* line);

		HRESULT virtual __stdcall LineFromPos( long pos, long* line );
		HRESULT virtual __stdcall PosFromLine( long line, long* pos );
		HRESULT virtual __stdcall LineEndPos( long line, long* pos );

		HRESULT virtual __stdcall FirstVisibleLine( long* line);
		HRESULT virtual __stdcall LinesOnScreen( long* line);

		HRESULT virtual __stdcall LineLength( long line, long* length);
		HRESULT virtual __stdcall LineText( long line, BSTR* text );
		HRESULT virtual __stdcall SetLineText( long line, BSTR text );
		HRESULT virtual __stdcall GotoLine( long pos);

		// Selection
		HRESULT virtual __stdcall GetSelection ( long* first, long* last );
		HRESULT virtual __stdcall SetSelection ( long first, long last );
		HRESULT virtual __stdcall GetSelectionText( BSTR* text );

		HRESULT virtual __stdcall SetSelectionStart( long pos);
		HRESULT virtual __stdcall GetSelectionStart(  long* pos);
		HRESULT virtual __stdcall SetSelectionEnd( long pos);
		HRESULT virtual __stdcall GetSelectionEnd(  long* pos);

		HRESULT virtual __stdcall ReplaceSelection( BSTR text );

		// search and replace
		HRESULT virtual __stdcall Search( BSTR what, long flags, VARIANT_BOOL* vbFound);
		HRESULT virtual __stdcall Replace( BSTR what, BSTR with, long flags, VARIANT_BOOL* vbReplaced);		

		// undo / redo
		HRESULT virtual __stdcall Undo();
		HRESULT virtual __stdcall Redo();
		HRESULT virtual __stdcall SavePoint();

		// cut / copy / pasty
		HRESULT virtual __stdcall Cut();
		HRESULT virtual __stdcall Copy();
		HRESULT virtual __stdcall Paste();

		// Options
		HRESULT virtual __stdcall SetFocus();
		HRESULT virtual __stdcall ZoomIn( );
		HRESULT virtual __stdcall ZoomOut( );
		HRESULT virtual __stdcall SetIndent( long indent);
		HRESULT virtual __stdcall ConvertTabs();
		HRESULT virtual __stdcall InsertColorDialog( HWND wnd );
		HRESULT virtual __stdcall Properties();
		HRESULT virtual __stdcall SyntaxDisplayName(BSTR* syntax);
		HRESULT virtual __stdcall GetSyntaxDisplayName(long type, BSTR* syntax);

		// print
		HRESULT virtual __stdcall Print();
		HRESULT virtual __stdcall GetTextRange(long start, long end, BSTR* range);
		HRESULT virtual __stdcall GetPages( CAUUID *pPages);
    
		// new intitialization 
	    HRESULT virtual __stdcall InitNew();

		// ctrl drawing
		HRESULT OnDraw( HDC hdcDraw, LPCRECTL lprcBounds, LPCRECTL lprcMFBounds)
		{
			ODBGS("ScintillAx::OnDraw");
			edit()->redraw();
			return S_OK;
		}

		// window messages

		LRESULT virtual OnCreate(  UINT, WPARAM, LPARAM );
		LRESULT virtual OnUpdateUI (  UINT, WPARAM, LPARAM );
		LRESULT virtual OnDblClick(  UINT, WPARAM, LPARAM );
        LRESULT virtual OnChar( UINT, WPARAM, LPARAM );
		LRESULT virtual OnContext( UINT, WPARAM, LPARAM );
		//LRESULT virtual OnSize( UINT, WPARAM, LPARAM );

protected:

	mol::bstr				filename_;	
	VARIANT_BOOL			vbContext_;
	VARIANT_BOOL			vbWriteBOM_;
	VARIANT_BOOL			vbReadOnly_;

	VARIANT_BOOL			vbTabUsage_;
	VARIANT_BOOL			vbTabIndents_;
	VARIANT_BOOL			vbBackSpaceUnindents_;
	long					tabWidth_;

	VARIANT_BOOL			vbOverType_;

	SCINTILLA_SYSTYPE		eol_;
	SCINTILLA_ENCODING		enc_;
	SCINTILLA_SYNTAX        syntax_;

	mol::punk<IFontDisp>	font_;
	mol::punk<IColorPicker>	col_;

	EditWnd* edit();

	void Init();
	bool loadAdminCOM(const mol::string& p, const mol::string& ext,  bool utf8);
	bool saveAdminCOM(const mol::string& p);
	bool loadAdmin(const mol::string& p, const mol::string& ext,  bool utf8);
	bool saveAdmin(const mol::string& p);
	bool load(const mol::string& p, const mol::string& ext,  bool utf8);
	bool save(const mol::string& location);
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



#endif