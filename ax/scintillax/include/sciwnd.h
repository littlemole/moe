#ifndef _MOL_SCINTILLA_DEF_
#define _MOL_SCINTILLA_DEF_

#include "util/uni.h"
#include "win/Ctrl.h"

#include "scintilla/Scintilla.h"
#include "scintilla/Platform.h"
#include "scintilla/SciLexer.h"

///////////////////////////////////////////////////////////////////////////////////
// this is the most basic scintilla wrapper
// just a thin border around scintilla
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////
// bring in Scintilla libs
///////////////////////////////////////////////////////////////////////////////////

class scintilla_init
{
public:
	scintilla_init(HINSTANCE hinst)
	{
#ifdef STATIC_BUILD
		Scintilla_LinkLexers();		
#endif
		Scintilla_RegisterClasses(hinst);
	}
	~scintilla_init()
	{
//#ifdef STATIC_BUILD
		Scintilla_ReleaseResources();
//#endif
	}
};

// for printing
//struct RangeToFormat {
//    SurfaceID hdc;        // The HDC (device context) we print to
//    SurfaceID hdcTarget;  // The HDC we use for measuring (may be same as hdc)
//    PRectangle rc;        // Rectangle in which to print
//    PRectangle rcPage;    // Physically printable page size
//    CharacterRange chrg;  // Range of characters to print
//};

///////////////////////////////////////////////////////////////////////////////////
// this is the most basic scintilla wrapper
// just a thin border around scintilla adapted for molib
///////////////////////////////////////////////////////////////////////////////////

extern const wchar_t scintilla[];

class ScintillaWnd : public mol::win::CtrlClass<scintilla>
{
public:

	ScintillaWnd()
	{
		nextSearchPos_=0;
		searchOptions_=FR_DOWN;
		highlight_= 0;
	}

	~ScintillaWnd()
	{
	}

	virtual void init()
	{

	};

	int printPage ( bool bDraw, Sci_RangeToFormat *pfr)
	{
		return sendMessage( SCI_FORMATRANGE, (WPARAM)bDraw , (LPARAM)pfr );		
	}

	void getnextSearchPos_(int i )
	{
		nextSearchPos_ = i;
	}

	bool search( const std::string& what, int options)
	{

        Sci_TextToFind ft;
        Sci_CharacterRange chrg;

        if ( nextSearchPos_ != 0 )
            if ( (searchOptions_ & FR_DOWN) != ( options & FR_DOWN ) )
            {
                if ( (options & FR_DOWN) == 0 )
                {
                    nextSearchPos_-=2;
                }
                else
                {
                    nextSearchPos_+=2;
                }
            }

        searchOptions_ = options;
        chrg.cpMin = nextSearchPos_;
        chrg.cpMax = getLength();

        if ( 0 == (options & FR_DOWN) )
        {
			int len = getLength();

            if ( nextSearchPos_ == 0 )
                chrg.cpMin = len-nextSearchPos_;//
            chrg.cpMax = 0;
        }

        ft.lpstrText = (char*)(what.c_str());
        ft.chrg = chrg;

		int r = findText(options,&ft);

		if ( r == -1 )
        {
            chrg.cpMin=0;
            chrg.cpMax=0;
            nextSearchPos_ =0;
			//setSel(0,0);
            return false;
        }

        chrg.cpMin = r;
        chrg.cpMax = r + (long)what.size();

        if ( 0 == (options & FR_DOWN) )
            nextSearchPos_ =r-1;
        else
            nextSearchPos_ =chrg.cpMax+1;

		setSel( chrg.cpMin, chrg.cpMax );
        return true;
	}


	bool replace( const std::string& what, const std::string& whith, int options)
	{
        Sci_TextToFind ft;		
		Sci_CharacterRange chrg;

        if ( nextSearchPos_ != 0 )
            if ( (searchOptions_ & FR_DOWN) != ( options & FR_DOWN ) )
            {
                if ( (options & FR_DOWN) == 0 )
                {
                   // nextSearchPos_-=2;
                }
                else
                {
                   // nextSearchPos_+=2;
                }
            }

        searchOptions_ = options;
        chrg.cpMin = nextSearchPos_;
        chrg.cpMax = this->getLength();

        if ( !(options & FR_DOWN) )
        {
			int len = this->getLength();

            if ( nextSearchPos_ == 0 )
                chrg.cpMin = len-nextSearchPos_;//
            chrg.cpMax = 0;
        }

        ft.lpstrText = (char*)(what.c_str());
        ft.chrg = chrg;

		int r = this->findText(options,&ft);
	
		if ( r == -1 )
        {
            chrg.cpMin=0;
            chrg.cpMax=0;
            nextSearchPos_ =0;
			setSel(0,0);
            return false;
        }

        chrg.cpMin = r;
        chrg.cpMax = r + (long)what.size();

        if ( !(options & FR_DOWN) )
            nextSearchPos_ =r-1;
        else
            nextSearchPos_ = r + (long)whith.size();//chrg.cpMax;//+1;

		setSel( chrg.cpMin, chrg.cpMax );
		replaceSel(mol::tostring(whith));
		chrg.cpMax = chrg.cpMin + (long)whith.size();
		setSel( chrg.cpMin, chrg.cpMax );

        return true;
	}

	std::string get_Text()
	{
		std::string txt;
		int len = getLength();
		mol::cbuff buf(len+1);
		int lr = sendMessage( SCI_GETTEXT, (WPARAM)len+1 , (LPARAM)(char*)buf );	
		return buf.toString(lr);
	}

	int getSelTextLen()
	{
		return sendMessage( SCI_GETSELTEXT, (WPARAM)0, (LPARAM)0 );		
	}

	std::string getSelText()
	{
		std::string txt;
		int len = getSelTextLen();

		mol::cbuff buf(len+1);
		int lr = sendMessage( SCI_GETSELTEXT, (WPARAM)len , (LPARAM)(char*)buf );	
		return buf.toString(lr);
	}

	std::string getLine(int line)
	{
		std::string txt;
		int len = sendMessage( SCI_GETLINE, (WPARAM)0 , (LPARAM)0 );	
		mol::cbuff buf(len+1);
		int lr = sendMessage( SCI_GETLINE, (WPARAM)len , (LPARAM)(char*)buf );		
		return buf.toString(lr);
	}

	int insertText(const std::string& txt, int p = -1)
	{
		if ( p == -1 )
			p = pos();
		int pos = p + (int)txt.size();
		sendMessage( SCI_INSERTTEXT, (WPARAM)p, (LPARAM)txt.c_str() );		
		this->setSel(pos,pos);
		return TRUE;
	}

	int replaceSel(const std::string& txt)
	{
		return sendMessage( SCI_REPLACESEL, (WPARAM)0 , (LPARAM)(txt.c_str()) );		
	}

	int setSel(int anchorPos, int currentPos)
	{
		return sendMessage( SCI_SETSEL, (WPARAM)anchorPos , (LPARAM)currentPos );		
	}

	int getSelStart()
	{
		return sendMessage( SCI_GETSELECTIONSTART, (WPARAM)0 , (LPARAM)0 );		
	}

	void setSelStart(int pos)
	{
		sendMessage( SCI_SETSELECTIONSTART, (WPARAM)pos , (LPARAM)0 );		
	}

	void setSelEnd(int pos)
	{
		sendMessage( SCI_SETSELECTIONEND, (WPARAM)pos , (LPARAM)0 );		
	}

	int getSelEnd()
	{
		return sendMessage( SCI_GETSELECTIONEND, (WPARAM)0 , (LPARAM)0 );		
	}

	int getModified()
	{
		return sendMessage( SCI_GETMODIFY, (WPARAM)0 , (LPARAM)0 );		
	}

	int setReadOnly(bool b)
	{
		return sendMessage( SCI_SETREADONLY, (WPARAM)b , (LPARAM)0 );		
	}

	int getReadOnly(bool b)
	{
		return sendMessage( SCI_GETREADONLY, (WPARAM)0 , (LPARAM)0 );		
	}

	int setText(const std::string& txt)
	{
		return  sendMessage( SCI_SETTEXT, (WPARAM)0, (LPARAM)(txt.c_str()) );		
	}

	int setText(const char* c)
	{
		return  sendMessage( SCI_SETTEXT, (WPARAM)0, (LPARAM)(c) );		
	}


	int setText(const char* c, int size)
	{
		sendMessage( SCI_SETTEXT, (WPARAM)0, (LPARAM)("") );	
		return  sendMessage( SCI_ADDTEXT, (WPARAM)size, (LPARAM)(c) );		
	}

	int getText(char* c, int size)
	{
		return  sendMessage( SCI_GETTEXT, (WPARAM)size, (LPARAM)c );	
	}

	std::string getTextRange(int start, int end)
	{
		Sci_TextRange tr;
		tr.chrg.cpMin = start;
		tr.chrg.cpMax = end;
		tr.lpstrText = new char [(end-start+1)*2];
		sendMessage( SCI_GETTEXTRANGE, (WPARAM)0, (LPARAM)&tr );	
		std::string ret = tr.lpstrText;
		delete tr.lpstrText;
		return ret;
	}

	int appendText(const std::string& txt)
	{
		return  sendMessage( SCI_APPENDTEXT, (WPARAM)txt.size(), (LPARAM)(txt.c_str()) );		
	}

	int setStyleBits(int bits)
	{
		return  sendMessage( SCI_SETSTYLEBITS, (WPARAM)bits, (LPARAM)0 );		
	}

	int getLength()
	{
		return sendMessage( SCI_GETLENGTH, (WPARAM)0 , (LPARAM)0 );
	}

	int getCharAt(int pos)
	{
		return sendMessage( SCI_GETCHARAT, (WPARAM)pos , (LPARAM)0 );
	}

	int getLineLength(int line)
	{
		return sendMessage( SCI_LINELENGTH, (WPARAM)line , (LPARAM)0 );
	}

	int getLineCount()
	{
		return sendMessage( SCI_GETLINECOUNT, (WPARAM)0 , (LPARAM)0 );
	}

	int getFirstVisibleLine()
	{
		return sendMessage( SCI_GETFIRSTVISIBLELINE, (WPARAM)0 , (LPARAM)0 );
	}

	int getLinesOnScreen()
	{
		return sendMessage( SCI_LINESONSCREEN, (WPARAM)0 , (LPARAM)0 );
	}

	int gotoLine(int line)
	{
		return sendMessage( SCI_GOTOLINE, (WPARAM)line , (LPARAM)0 );
	}

	int lineFromPos(int pos)
	{
		return sendMessage( SCI_LINEFROMPOSITION, (WPARAM)pos , (LPARAM)0 );
	}

	int lineEndPos(int line)
	{
		return sendMessage( SCI_GETLINEENDPOSITION, (WPARAM)line , (LPARAM)0 );
	}

	int posFromLine(int line)
	{
		return sendMessage( SCI_POSITIONFROMLINE, (WPARAM)line , (LPARAM)0 );
	}

	int pos()
	{
		return sendMessage( SCI_GETCURRENTPOS, (WPARAM)0 , (LPARAM)0 );
	}

	void pos(int pos)
	{
		sendMessage( SCI_SETCURRENTPOS, (WPARAM)pos , (LPARAM)0 );
	}

	int anchor()
	{
		return sendMessage( SCI_GETANCHOR, (WPARAM)0 , (LPARAM)0 );
	}

	void anchor(int pos)
	{
		sendMessage( SCI_SETANCHOR, (WPARAM)pos , (LPARAM)0 );
	}

	int findText(int searchFlags, Sci_TextToFind *ttf)
	{
		return sendMessage( SCI_FINDTEXT, (WPARAM)searchFlags , (LPARAM)ttf );
	}

	int setSavePoint()
	{
		return sendMessage( SCI_SETSAVEPOINT, (WPARAM)0 , (LPARAM)0 );
	}

	int cut()
	{
		return sendMessage( SCI_CUT, (WPARAM)0 , (LPARAM)0 );
	}

	int copy()
	{
		return sendMessage( SCI_COPY, (WPARAM)0 , (LPARAM)0 );
	}

	int paste()
	{
		return sendMessage( SCI_PASTE, (WPARAM)0 , (LPARAM)0 );
	}

	int undo()
	{
		return sendMessage( SCI_UNDO, (WPARAM)0 , (LPARAM)0 );
	}

	int redo()
	{
		return sendMessage( SCI_REDO, (WPARAM)0 , (LPARAM)0 );
	}

	int styleClearAll()
	{
		return sendMessage( SCI_STYLECLEARALL, (WPARAM)0 , (LPARAM)0 );
	}

	int styleSetFont(int style, const std::string& font)
	{
		return sendMessage( SCI_STYLESETFONT, (WPARAM)style , (LPARAM)(font.c_str()) );
	}

	int styleSetSize(int style, int size)
	{
		return sendMessage( SCI_STYLESETSIZE, (WPARAM)style , (LPARAM)size );
	}

	int styleSetBold(int style, bool bold)
	{
		return sendMessage( SCI_STYLESETBOLD, (WPARAM)style , (LPARAM)bold );
	}

	int styleSetItalic(int style, bool bold)
	{
		return sendMessage( SCI_STYLESETITALIC, (WPARAM)style , (LPARAM)bold );
	}

	int styleSetUnderline(int style, bool bold)
	{
		return sendMessage( SCI_STYLESETUNDERLINE, (WPARAM)style , (LPARAM)bold );
	}

	int styleSetFore(int style, int col)
	{
		if (style == STYLE_LINENUMBER)
		{
			setCaretForeCol(col);
			sendMessage(SCI_SETSELBACK, (WPARAM)(1), (LPARAM)(col));
		}
		return sendMessage( SCI_STYLESETFORE, (WPARAM)style , (LPARAM)col );
	}

	int styleSetBack(int style, int col)
	{
		if (style == STYLE_LINENUMBER)
		{
			sendMessage(SCI_SETSELFORE, (WPARAM)(1), (LPARAM)(col));
		}
		return sendMessage( SCI_STYLESETBACK, (WPARAM)style , (LPARAM)col );
	}

	int styleSetEolFilled(int style, bool filled)
	{
		return sendMessage( SCI_STYLESETEOLFILLED, (WPARAM)style , (LPARAM)filled );
	}

	int styleSetCharacterSet(int style, int set)
	{
		return sendMessage( SCI_STYLESETCHARACTERSET, (WPARAM)style , (LPARAM)set );
	}


	int setCaretForeCol(int col)
	{
		return sendMessage(SCI_SETCARETFORE, (WPARAM)col, (LPARAM)col);
	}

	int setCodePage(int cp)
	{
		return sendMessage( SCI_SETCODEPAGE, (WPARAM)cp , (LPARAM)0 );
	}

	int getCodePage()
	{
		return sendMessage( SCI_GETCODEPAGE, (WPARAM)0 , (LPARAM)0 );
	}

	int getTabWidth()
	{
		return sendMessage( SCI_GETTABWIDTH, (WPARAM)0 , (LPARAM)0 );
	}

	int setTabWidth(int w)
	{
		return sendMessage( SCI_SETTABWIDTH, (WPARAM)w , (LPARAM)0 );
	}

	int setUseTabs(bool b)
	{
		return sendMessage( SCI_SETUSETABS, (WPARAM)b , (LPARAM)0 );
	}

	int getUseTabs()
	{
		return sendMessage( SCI_GETUSETABS, (WPARAM)0 , (LPARAM)0 );
	}

	int setLexer(int lexer)
	{
		return sendMessage( SCI_SETLEXER, (WPARAM)lexer , (LPARAM)0 );
	}

	int getLexer()
	{
		return sendMessage( SCI_GETLEXER, (WPARAM)0 , (LPARAM)0 );
	}

	int colorize(int start, int end = -1)
	{
		return sendMessage( SCI_COLOURISE, (WPARAM)start , (LPARAM)end );
	}

	int setKeywords(int keySet, const std::string& keyList )
	{
		return sendMessage( SCI_SETKEYWORDS, (WPARAM)keySet , (LPARAM)(keyList.c_str()) );
	}

	int setMarginType(int margin, int type)
	{
		return sendMessage( SCI_SETMARGINTYPEN, (WPARAM)margin , (LPARAM)(type) );
	}

	int getMarginType(int margin )
	{
		return sendMessage( SCI_GETMARGINTYPEN, (WPARAM)margin , (LPARAM)(0) );
	}

	int setMarginWidth(int margin, int w)
	{
		return sendMessage( SCI_SETMARGINWIDTHN, (WPARAM)margin , (LPARAM)(w) );
	}

	int getMarginWidth(int margin )
	{
		return sendMessage( SCI_SETMARGINWIDTHN, (WPARAM)margin , (LPARAM)(0) );
	}

	int setMarginStyle(int margin) 
	{
		 sendMessage(SCI_SETMARGINTYPEN, margin, SC_MARGIN_FORE);
		return sendMessage(SCI_SETMARGINTYPEN, margin, SC_MARGIN_BACK);
	}

	int setOvertype(bool b)
	{
		return sendMessage( SCI_SETOVERTYPE, (WPARAM)b , (LPARAM)(0) );
	}

	int getOvertype()
	{
		return sendMessage( SCI_GETOVERTYPE, (WPARAM)0 , (LPARAM)(0) );
	}

	int lineScroll(int col, int line)
	{
		return sendMessage( SCI_LINESCROLL, (WPARAM)col , (LPARAM)(line) );
	}

	int scrollCaret()
	{
		return sendMessage( SCI_SCROLLCARET, (WPARAM)0 , (LPARAM)(0) );
	}

	int getCaretWidth()
	{
		return sendMessage( SCI_SETCARETWIDTH, (WPARAM)0 , (LPARAM)(0) );
	}

	int setCaretWidth(int w )
	{
		return sendMessage( SCI_GETCARETWIDTH, (WPARAM)w , (LPARAM)(0) );
	}

	int getFocus()
	{
		return sendMessage( SCI_GETFOCUS, (WPARAM)0 , (LPARAM)(0) );
	}

	int getScrollWidth()
	{
		return sendMessage( SCI_GETSCROLLWIDTH, (WPARAM)0 , (LPARAM)(0) );
	}

	int setScrollWidth(int w)
	{
		return sendMessage( SCI_SETSCROLLWIDTH, (WPARAM)w , (LPARAM)(0) );
	}

	int setUsePopUp(bool b)
	{
		return sendMessage( SCI_USEPOPUP, (WPARAM)b , (LPARAM)(0) );
	}

	int setIndent(int w)
	{
		return postMessage( SCI_SETINDENT, (WPARAM)w , (LPARAM)(0) );
	}

	int getIndent()
	{
		return sendMessage( SCI_GETINDENT, (WPARAM)0 , (LPARAM)(0) );
	}

	int setLineIndent(int l,int w)
	{
		return sendMessage( SCI_SETLINEINDENTATION, (WPARAM)l , (LPARAM)(w) );
	}

	int getLineIndent(int l)
	{
		return sendMessage( SCI_GETLINEINDENTATION, (WPARAM)l , (LPARAM)(0) );
	}

	int setTabIndents(bool b)
	{
		return sendMessage( SCI_SETTABINDENTS, (WPARAM)b , (LPARAM)(0) );
	}

	int getTabIndents()
	{
		return sendMessage( SCI_GETTABINDENTS, (WPARAM)0 , (LPARAM)(0) );
	}

	int setBackSpaceUnindents(bool b)
	{
		return sendMessage( SCI_SETBACKSPACEUNINDENTS, (WPARAM)b , (LPARAM)(0) );
	}

	int getBackSpaceUnindents()
	{
		return sendMessage( SCI_GETBACKSPACEUNINDENTS, (WPARAM)0 , (LPARAM)(0) );
	}

	int setViewEol(bool b)
	{
		return sendMessage( SCI_SETVIEWEOL, (WPARAM)b , (LPARAM)(0) );
	}

	int getViewEol()
	{
		return sendMessage( SCI_GETVIEWEOL, (WPARAM)0 , (LPARAM)(0) );
	}

	int setEolMode(int mode)
	{
		return sendMessage( SCI_SETEOLMODE, (WPARAM)mode , (LPARAM)(0) );
	}

	int getEolMode()
	{
		return sendMessage( SCI_GETEOLMODE, (WPARAM)0 , (LPARAM)(0) );
	}

	int convertEol(int mode)
	{
		return sendMessage( SCI_CONVERTEOLS, (WPARAM)mode , (LPARAM)(0) );
	}

	int braceHighlight(int pos1, int pos2)
	{
		return sendMessage( SCI_BRACEHIGHLIGHT, (WPARAM)pos1 , (LPARAM)(pos2) );
	}

	int braceMatch(int pos)
	{
		return sendMessage( SCI_BRACEMATCH, (WPARAM)pos , (LPARAM)(0) );
	}

	int setZoom(int zoom)
	{
		return sendMessage( SCI_SETZOOM, (WPARAM)zoom , (LPARAM)(0) );
	}

	int getZoom()
	{
		return sendMessage( SCI_GETZOOM, (WPARAM)0 , (LPARAM)(0) );
	}

	void zoomIn()
	{
		sendMessage( SCI_ZOOMIN, (WPARAM)0 , (LPARAM)(0) );
	}

	void zoomOut()
	{
		sendMessage( SCI_ZOOMOUT, (WPARAM)0 , (LPARAM)(0) );
	}

	void setAnnotation( int i, const std::wstring& str )
	{
		std::string tmp = mol::tostring(str);
		sendMessage( SCI_ANNOTATIONSETTEXT, (WPARAM)i , (LPARAM)(tmp.c_str()) );
	}

	void setAnnotationStyle( int i, int style )
	{
		sendMessage( SCI_ANNOTATIONSETSTYLE, (WPARAM)i , (LPARAM)(style) );
	}

	void clearAnnotation( int i )
	{
		sendMessage( SCI_ANNOTATIONSETTEXT, (WPARAM)i , (LPARAM)(0) );
	}

	void clearAnnotations()
	{
		sendMessage( SCI_ANNOTATIONCLEARALL, (WPARAM)0 , (LPARAM)(0) );
	}

	void showAnnotations(int style)
	{
		sendMessage( SCI_ANNOTATIONSETVISIBLE, (WPARAM)style , (LPARAM)(0) );
	}

	void clearAllMarkers()
	{
		sendMessage( SCI_MARKERDELETEALL, (WPARAM)-1 , (LPARAM)(0) );
	}

	void setMarker(int line, int num = 2)
	{
		LRESULT markerhandle = sendMessage( SCI_MARKERADD, (WPARAM)line , (LPARAM)(num) );
		markers_.insert(markerhandle);
	}

	void removeMarker(int line, int num = 2)
	{
		for( std::set<LRESULT>::iterator it = markers_.begin(); it != markers_.end(); it++)
		{
			LRESULT markerhandler = (*it);
			int l = sendMessage( SCI_MARKERLINEFROMHANDLE, (WPARAM)markerhandler , (LPARAM)(0) );
			if ( l == line )
			{				
				markers_.erase(markerhandler);
				sendMessage( SCI_MARKERDELETEHANDLE, (WPARAM)markerhandler , (LPARAM)(0) );
				return;
			}
		}
	}

	std::set<int> getMarkers()
	{
		std::set<int> lines;
		for( std::set<LRESULT>::iterator it = markers_.begin(); it != markers_.end(); it++)
		{
			LRESULT markerhandler = (*it);
			int line = sendMessage( SCI_MARKERLINEFROMHANDLE, (WPARAM)markerhandler , (LPARAM)(0) );
			int pos = posFromLine(line);
			lines.insert(pos);
		}
		return lines;
	}

	bool hasMarker(int line, int mask = 0x04)
	{
		int val = sendMessage( SCI_MARKERGET, (WPARAM)(line), (LPARAM)(0) );
		if ( mask & val )
		{
			return true;
		}
		return false;
	}

	bool toggleMarker(int line )
	{
		bool b = hasMarker(line);
		if (!b)
		{
			setMarker(line);
			return b;
		}
		removeMarker(line);
		return !b;
	}

	void useMarkers(bool b)
	{
		if ( b )
		{
			
			LRESULT fore = sendMessage(SCI_STYLEGETFORE, (WPARAM)STYLE_DEFAULT, (LPARAM)0);
			LRESULT back = sendMessage(SCI_STYLEGETBACK, (WPARAM)STYLE_DEFAULT, (LPARAM)0);
		
			sendMessage( SCI_SETMARGINWIDTHN, (WPARAM)(2), (LPARAM)(16) );
			sendMessage( SCI_SETMARGINSENSITIVEN, (WPARAM)(2), (LPARAM)(true) );
			sendMessage( SCI_MARKERDEFINE, (WPARAM)(2), (LPARAM)(SC_MARK_CIRCLE) );

			sendMessage( SCI_SETMARGINMASKN, (WPARAM)(1), (LPARAM)(0) );
			sendMessage(SCI_SETMARGINMASKN, (WPARAM)(2),  (LPARAM)(~SC_MASK_FOLDERS) );
			//sendMessage( SCI_MARKERSETBACK, (WPARAM)(2), (LPARAM)(back) );
			//sendMessage(SCI_MARKERSETFORE, (WPARAM)(2), (LPARAM)(fore));
			//sendMessage(SCI_SETFOLDMARGINCOLOUR, (WPARAM)1, (LPARAM)(fore));
			//sendMessage(SCI_SETFOLDMARGINHICOLOUR, (WPARAM)1, (LPARAM)(back));

		//	sendMessage(SCI_SETMARGINTYPEN, (WPARAM)(2) ,(LPARAM)(SC_MARGIN_BACK));
		//	sendMessage(SCI_SETMARGINTYPEN, (WPARAM)(2), (LPARAM)(SC_MARGIN_FORE));
			setCaretForeCol(fore);
			return;
		}
		sendMessage( SCI_SETMARGINWIDTHN, (WPARAM)(2), (LPARAM)(0) );
		sendMessage( SCI_SETMARGINSENSITIVEN, (WPARAM)(2), (LPARAM)(false) );
	}

	void highliteLine( int line )
	{
		if ( highlight_ != 0 )
		{
			sendMessage( SCI_MARKERDELETEHANDLE, (WPARAM)highlight_ , (LPARAM)(0) );
			highlight_ = 0;
		}

		if ( line == -1 )
		{
			return;
		}

		sendMessage( SCI_MARKERDEFINE, (WPARAM)(1), (LPARAM)(SC_MARK_BACKGROUND) );
		sendMessage( SCI_MARKERSETBACK, (WPARAM)(1), (LPARAM)(RGB(255,245,199)) );
		highlight_ = sendMessage( SCI_MARKERADD, (WPARAM)line , (LPARAM)(1) );
	}


	void setStyle(int style, COLORREF fore, COLORREF back=0, int size=0, const char* font=0) 
	{
		styleSetFore(style, fore);
		if (back)
			styleSetBack(style, back);
		if (size >= 1)
			styleSetSize(style,size);
		if (font) 
			styleSetFont(style,font);
	}

	int searchPos()
	{
		return nextSearchPos_;
	}

	bool searchPos(unsigned int pos)
	{
		if ( pos <= (unsigned int)this->getLength() )
		{
			nextSearchPos_ = pos;
			return true;
		}
		return false;
	}

	int searchOptions()
	{
		return searchOptions_;
	}

	bool searchOptions( int options)
	{
		searchOptions_ = options;
		return true;
	}


private:
	int						nextSearchPos_;
    int						searchOptions_;
	LRESULT					highlight_;
	std::set<LRESULT>		markers_;
};


#endif