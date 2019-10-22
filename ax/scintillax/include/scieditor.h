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

class ScintillaEditor : public ScintillaWnd
{

public:
	ScintillaEditor();
	~ScintillaEditor();

	SCINTILLA_SYNTAX mode();
	SCINTILLA_SYNTAX mode( SCINTILLA_SYNTAX m, int size, const std::wstring& font );

	void print();
	void setFont(int size, const std::wstring& font);

	bool showLineNumbers();
	void showLineNumbers(bool b );


	std::wstring SyntaxDisplayName();
	std::wstring SyntaxDisplayName(int syntax);

protected:
	virtual HWND createWindow( const std::wstring& windowName, HMENU hMenu, const mol::Rect& r, HWND parent );

	SCINTILLA_SYNTAX mode_;
};


#endif
