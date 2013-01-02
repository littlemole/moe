#ifndef SCI_MOL_DEF_GUARD
#define SCI_MOL_DEF_GUARD

#include "sciwnd.h"
#include "ScintillAx_h.h"

///////////////////////////////////////////////////////////////////////////////////
// this is the higher level scintilla wrapper
// it adds lexer and encoding support specific 
// to this AX control

///////////////////////////////////////////////////////////////////////////////////
// syntax modes for editor
///////////////////////////////////////////////////////////////////////////////////

HDC getPrinterDC();
HDC choosePrinterDC(HWND owner, int& copies, bool& collate);

#define SCI_ANNO_ERRORSTYLE 128


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

	void print();
	void setFont(int size, const mol::string& font);

	bool showLineNumbers();
	void showLineNumbers(bool b );


	mol::string SyntaxDisplayName();
	mol::string SyntaxDisplayName(int syntax);

protected:
	virtual HWND createWindow( const mol::string& windowName, HMENU hMenu, const mol::Rect& r, HWND parent );

	SCINTILLA_SYNTAX mode_;
};


#endif
