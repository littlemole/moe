#include "StdAfx.h"
#include "scieditor.h"
#include <richedit.h>
#include "util/Str.h"
#include "util/iStr.h"
#include "win/path.h"
#include <winspool.h>

const mol::TCHAR scintilla[] = _T("Scintilla");


ScintillaEditor::ScintillaEditor()
{
	mode_ = SCINTILLA_SYNTAX_PLAIN;
}

ScintillaEditor::~ScintillaEditor()
{}

SCINTILLA_SYNTAX ScintillaEditor::mode() 
{ 
	return mode_;
}


SCINTILLA_SYNTAX ScintillaEditor::mode( SCINTILLA_SYNTAX m, int s, const mol::string& f  ) 
{ 
    SCINTILLA_SYNTAX ret = mode_;
	mode_ = m;
	
	return ret; 
}



HWND ScintillaEditor::createWindow( const mol::string& windowName, HMENU hMenu, const mol::Rect& r, HWND parent )
{
    hWnd_ = ::CreateWindowEx ( exstyle(),wndClassName().c_str(),
                               windowName.c_str(), style(),
                               r.left, r.top, r.right, r.bottom,
							   parent, (HMENU)hMenu, mol::hinstance(),(PVOID)this );
    subClass();
    this->OnCtrlCreated();
    return hWnd_;
}

void ScintillaEditor::print()
{
	static DOCINFO di = { sizeof(DOCINFO), _T("mol scintilla print job") };
	BOOL bSuccess = TRUE;
	HDC hdcPrinter;
	int xPage,yPage;

	//hdcPrinter = getPrinterDC();
	int copies = 0;
	bool collate = false;
	hdcPrinter = choosePrinterDC(*this,copies,collate);
	if ( NULL == hdcPrinter )
		return;

	int copies1 = collate ? 1 : copies ;
	int copies2 = collate ? copies : 1 ;
	for ( int  i = 0; i < copies1; i++ )
	{
		xPage = ::GetDeviceCaps( hdcPrinter, HORZRES );
		yPage = ::GetDeviceCaps( hdcPrinter, VERTRES );

		RangeToFormat rtf;
		rtf.hdc = hdcPrinter;
		rtf.hdcTarget = hdcPrinter;
		rtf.chrg.cpMin = 0;
		rtf.chrg.cpMax = this->getLength();
		rtf.rc.left = 0;
		rtf.rc.top = 0;
		rtf.rc.right = xPage-1;
		rtf.rc.bottom = yPage-1;
		rtf.rcPage = rtf.rc;
		rtf.rc.left += 130;
		rtf.rc.top  += 130;
		rtf.rc.right -= 260;
		rtf.rc.bottom -=260;

		if ( ::StartDoc( hdcPrinter, &di ) )
		{
			while ( rtf.chrg.cpMin < rtf.chrg.cpMax )
			{
				if ( ::StartPage( hdcPrinter ) > 0 )
				{
					RangeToFormat r = rtf;

					for ( int j = 0; j < copies2; j++ )
					{
						rtf.chrg.cpMin = this->printPage(true,&r);
					}
					if ( ::EndPage(hdcPrinter) <= 0 )
						break;
				}
			}
			::EndDoc(hdcPrinter);
		}
	}
	::DeleteDC(hdcPrinter);
}

HDC getPrinterDC()
{
	DWORD dwNeeded, dwReturned;
	HDC hdc;
	PRINTER_INFO_5* pinfo5;

	if ( ::GetVersion() & 0x80000000 ) // win98
	{
		::EnumPrinters(PRINTER_ENUM_DEFAULT,NULL,5,NULL,0,&dwNeeded,&dwReturned);
		pinfo5 = (PRINTER_INFO_5*)malloc(dwNeeded);
		::EnumPrinters(PRINTER_ENUM_DEFAULT,NULL,5,(PBYTE)pinfo5,dwNeeded,&dwNeeded,&dwReturned);
		hdc = ::CreateDC( 0, pinfo5->pPrinterName,0,0);
		free(pinfo5);
	}
	else
	{
		DWORD len = 256;
		mol::TCHAR buf[256];
		::GetDefaultPrinter(buf,&len);
		hdc = ::CreateDC( 0, buf,0,0);
	}
	return hdc;
}

class PrinterDlg : public PRINTDLG
{
public:

	PrinterDlg(HWND owner)
	{
		// Initialize PRINTDLG
		ZeroMemory((PRINTDLG*)(this), sizeof(PRINTDLG));
		lStructSize = sizeof(PRINTDLG);
		hwndOwner = owner;
		hDevMode = NULL;     // Don't forget to free or store hDevMode
		hDevNames = NULL;     // Don't forget to free or store hDevNames
		Flags = PD_USEDEVMODECOPIESANDCOLLATE | PD_RETURNDC | PD_NOPAGENUMS | PD_NOSELECTION;
		nCopies = 1;
		nFromPage = 0xFFFF;
		nToPage = 0xFFFF;
		nMinPage = 1;
		nMaxPage = 0xFFFF;
	}

	~PrinterDlg()
	{
		if (hDevMode) 
		{
			::GlobalFree(hDevMode);
			hDevMode = 0;
		}
		if (hDevNames)
		{
			::GlobalFree(hDevNames);
			hDevNames = 0;
		}
	}

	bool show()
	{
		return PrintDlg(this) == TRUE;
	}

private:

};

HDC choosePrinterDC(HWND owner, int& copies, bool& collate)
{

	PrinterDlg dlg(owner);
	if (dlg.show())
	{
		return dlg.hDC;
	}
	return 0;
	/*
	PRINTDLG pd;

	// Initialize PRINTDLG
	ZeroMemory(&pd, sizeof(pd));
	pd.lStructSize = sizeof(pd);
	pd.hwndOwner   = owner;
	pd.hDevMode    = NULL;     // Don't forget to free or store hDevMode
	pd.hDevNames   = NULL;     // Don't forget to free or store hDevNames
	pd.Flags       = PD_USEDEVMODECOPIESANDCOLLATE | PD_RETURNDC |PD_NOPAGENUMS|PD_NOSELECTION; 
	pd.nCopies     = 1;
	pd.nFromPage   = 0xFFFF; 
	pd.nToPage     = 0xFFFF; 
	pd.nMinPage    = 1; 
	pd.nMaxPage    = 0xFFFF; 

	copies = 0;
	collate = false;
	if (PrintDlg(&pd)==TRUE) 
	{
		collate = (pd.Flags & PD_COLLATE) != 0;
		copies  = pd.nCopies;
		return pd.hDC;
	}
	return 0;
	*/
}

void ScintillaEditor::setFont(int size, const mol::string& font)
{
	setStyle(STYLE_DEFAULT, RGB(0,0,0),  RGB(0xff,0xff,0xff), size, mol::tostring(font).c_str() );	
}


mol::string ScintillaEditor::SyntaxDisplayName()
{
	return SyntaxDisplayName(mode_);//mod_.modes);
}

bool ScintillaEditor::showLineNumbers()
{
	int w = sendMessage( SCI_GETMARGINWIDTHN, (WPARAM)0 , (LPARAM)0 );
	return w != 0;
}

void ScintillaEditor::showLineNumbers(bool b)
{
	if ( b == false )
	{
		sendMessage( SCI_SETMARGINWIDTHN, (WPARAM)(0), (LPARAM)(0) );
		sendMessage( SCI_SETMARGINWIDTHN, (WPARAM)(1), (LPARAM)(0) );
		return;
	}

	int lines = getLineCount();
	std::ostringstream oss;
	oss << "_" << lines;

	int w = sendMessage( SCI_TEXTWIDTH, (WPARAM)STYLE_LINENUMBER, (LPARAM)(oss.str().c_str()) );
	sendMessage( SCI_SETMARGINWIDTHN, (WPARAM)(0), (LPARAM)(w) );
	sendMessage( SCI_SETMARGINWIDTHN, (WPARAM)(1), (LPARAM)(4) );
}



mol::string ScintillaEditor::SyntaxDisplayName(int syntax)
{
	switch ( syntax )
	{
		case SCINTILLA_SYNTAX_HTML:
			return _T("html");
		case SCINTILLA_SYNTAX_PERL:
			return _T("perl");
		case SCINTILLA_SYNTAX_CPP:
			return _T("cpp");
		case SCINTILLA_SYNTAX_JAVA:
			return _T("java");
		case SCINTILLA_SYNTAX_JS:
			return _T("js");
		case SCINTILLA_SYNTAX_VB:
			return _T("vb");
		case SCINTILLA_SYNTAX_CSS:
			return _T("css");
		case SCINTILLA_SYNTAX_SQL:
			return _T("sql");
		case SCINTILLA_SYNTAX_SHELL:
			return _T("shell");
		case SCINTILLA_SYNTAX_CSHARP:
			return _T("c#");
	}
	return _T("txt");
}
