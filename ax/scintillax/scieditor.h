#ifndef SCI_MOL_DEF_GUARD
#define SCI_MOL_DEF_GUARD

#include "sciwnd.h"
#include "ScintillAx_h.h"

///////////////////////////////////////////////////////////////////////////////////
// this is the higher level scintilla wrapper
// it adds lexer and encoding support specific 
// to this AX control
///////////////////////////////////////////////////////////////////////////////////
/*
	enum SCINTILLA_SYNTAX {
		SCINTILLA_SYNTAX_PLAIN  = 0,
		SCINTILLA_SYNTAX_HTML   = 1,
		SCINTILLA_SYNTAX_CSS    = 2,
		SCINTILLA_SYNTAX_VB     = 3,
		SCINTILLA_SYNTAX_JS     = 4,
		SCINTILLA_SYNTAX_SQL    = 5,
		SCINTILLA_SYNTAX_SHELL  = 6,
		SCINTILLA_SYNTAX_PERL   = 7,
		SCINTILLA_SYNTAX_CPP    = 8,
		SCINTILLA_SYNTAX_JAVA   = 9,
		SCINTILLA_SYNTAX_CSHARP = 10
	};
*/
///////////////////////////////////////////////////////////////////////////////////
// syntax modes for editor
///////////////////////////////////////////////////////////////////////////////////

HDC getPrinterDC();
HDC choosePrinterDC(HWND owner, int& copies, bool& collate);

class ScEdMode 
{
public:
	ScEdMode() : modes(SCINTILLA_SYNTAX_PLAIN),size(10),font("Courier New") {}

	void init ( const mol::string& path, const mol::string& ext );
	//enum MODES { PLAIN, HTML, PERL, CPP, JAVA, JS, VB, CSS, SHELL, SQL, CSHARP } modes;
	SCINTILLA_SYNTAX modes;
	int size;
	std::string font;

	static const std::string htmlKeyWords;
	static const std::string jsKeyWords;
	static const std::string vbsKeyWords;
	static const std::string phpKeyWords;
	static const std::string perlKeyWords;
	static const std::string cppKeyWords;
	static const std::string javaKeywords;
	static const std::string css1Keywords;
	static const std::string css2Keywords;
    static const std::string sqlKeywords;
	static const std::string csharpKeywords;

	static const COLORREF black;
	static const COLORREF white;
	static const COLORREF red;
	static const COLORREF offWhite;
	static const COLORREF offGrey;
	static const COLORREF green;
	static const COLORREF lightGreen;
	static const COLORREF darkGreen;
	static const COLORREF darkblue;
	static const COLORREF blue;
	static const COLORREF lightblue;
	static const COLORREF grey;
	static const COLORREF orange;
	static const COLORREF brown;

	void init(Scintilla* sced);
private:
	void initPlain(Scintilla* sced);
	void initHtml(Scintilla* sced);
	void initPerl(Scintilla* sced);
	void initCpp(Scintilla* sced);
	void initJava(Scintilla* sced);
	void initJs(Scintilla* sced);
	void initVb(Scintilla* sced);
    void initShell(Scintilla* sced);
    void initSql(Scintilla* sced);
	void initCss(Scintilla* sced);
	void initCsharp(Scintilla* sced);
};

///////////////////////////////////////////////////////////////////////////////////
// scintilla with pre-defined lexers
///////////////////////////////////////////////////////////////////////////////////

class ScintillaEditor : public Scintilla
{

public:
	ScintillaEditor();
	~ScintillaEditor();

	SCINTILLA_SYNTAX mode();
	SCINTILLA_SYNTAX mode( SCINTILLA_SYNTAX m, int size, const mol::string& font );
	SCINTILLA_SYNTAX mode( const mol::string& path, const mol::string& ext );

	void print();

	void setFont(int size, const mol::string& font);

	mol::string SyntaxDisplayName();
	mol::string SyntaxDisplayName(int syntax);
protected:
	virtual void init();
	virtual HWND createWindow( const mol::string& windowName, HMENU hMenu, const mol::Rect& r, HWND parent );

	ScEdMode	mod_;
};


#endif
