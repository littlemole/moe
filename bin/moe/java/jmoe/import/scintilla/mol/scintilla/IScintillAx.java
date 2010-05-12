package mol.scintilla  ;

import com4j.*;

/**
 * ScintillAX Interface - Text Editor AX Component
 */
@IID("{1120EC6A-130F-440E-9B1D-F02D505FB5BC}")
public interface IScintillAx extends Com4jObject {
        /**
         * Get/Set Filename
         */
        @VTID(10)
        void filename(
            java.lang.String fname);

        /**
         * Get/Set Filename
         */
        @VTID(11)
        java.lang.String filename();

        /**
         * Set/Get ReadOnly Mode
         */
        @VTID(12)
        void readOnly(
            boolean vbReadOnly);

        /**
         * Set/Get ReadOnly Mode
         */
        @VTID(13)
        boolean readOnly();

        /**
         * Get/Set Coloring Syntax
         */
        @VTID(14)
        void syntax(
            int typ);

        /**
         * Get/Set Coloring Syntax
         */
        @VTID(15)
        int syntax();

        /**
         * get/Set SysTypec (UNIX/Win32)
         */
        @VTID(16)
        void sysType(
            int typ);

        /**
         * get/Set SysTypec (UNIX/Win32)
         */
        @VTID(17)
        int sysType();

        /**
         * Set/Get Encoding (UTF-8,Ansi,...)
         */
        @VTID(18)
        void encoding(
            int typ);

        /**
         * Set/Get Encoding (UTF-8,Ansi,...)
         */
        @VTID(19)
        int encoding();

        /**
         * Set/Get Usage of Tabulator chars, setting to false converts tabs to spaces
         */
        @VTID(20)
        void tabUsage(
            boolean vbTabUsage);

        /**
         * Set/Get Usage of Tabulator chars, setting to false converts tabs to spaces
         */
        @VTID(21)
        boolean tabUsage();

        /**
         * Set/Get whether Tabulator indents
         */
        @VTID(22)
        void tabIndents(
            boolean vbTabIndents);

        /**
         * Set/Get whether Tabulator indents
         */
        @VTID(23)
        boolean tabIndents();

        /**
         * Get/Set whether BackSpace unindents
         */
        @VTID(24)
        void backSpaceUnindents(
            boolean vbBackSpaceIndents);

        /**
         * Get/Set whether BackSpace unindents
         */
        @VTID(25)
        boolean backSpaceUnindents();

        /**
         * get/Set Tabulator width
         */
        @VTID(26)
        void tabWidth(
            int w);

        /**
         * get/Set Tabulator width
         */
        @VTID(27)
        int tabWidth();

        /**
         * GetSet Overtype mode
         */
        @VTID(28)
        void overtype(
            boolean over_type);

        /**
         * GetSet Overtype mode
         */
        @VTID(29)
        boolean overtype();

        /**
         * Get/Set Use Context Menue
         */
        @VTID(30)
        void useContext(
            boolean useMenu);

        /**
         * Get/Set Use Context Menue
         */
        @VTID(31)
        boolean useContext();

        /**
         * Load File form disk
         */
        @VTID(32)
        void load(
            java.lang.String fname);

        /**
         * Load File from disk - Force UTF8
         */
        @VTID(33)
        void loadUTF8(
            java.lang.String fname);

        /**
         * Save File to disk
         */
        @VTID(34)
        void save();

        /**
         * Save As - save File to disk to path
         */
        @VTID(35)
        void saveAs(
            java.lang.String fname);

        /**
         * Set whole document Text
         */
        @VTID(36)
        void setText(
            java.lang.String txt);

        /**
         * Get whole document Text
         */
        @VTID(37)
        java.lang.String getText();

        /**
         * returns whole document's Text Length
         */
        @VTID(38)
        int textLength();

        /**
         * Append Text to document
         */
        @VTID(39)
        void append(
            java.lang.String txt);

        /**
         * Insert Text to document at specific position
         */
        @VTID(40)
        void insert(
            java.lang.String txt,
            int p);

        /**
         * Get Modified flag
         */
        @VTID(41)
        boolean modified();

        /**
         * Set Caret Position
         */
        @VTID(42)
        void setCaretPos(
            int p);

        /**
         * Get Caret Position
         */
        @VTID(43)
        int getCaretPos();

        /**
         * Character At
         */
        @VTID(44)
        java.lang.String charAt(
            int p);

        /**
         * Scroll by cols / lines
         */
        @VTID(45)
        void scroll(
            int cCols,
            int cLines);

        /**
         * Scroll into View
         */
        @VTID(46)
        void scrollIntoView();

        /**
         * Set current Search Position
         */
        @VTID(47)
        void setSearchPos(
            int p);

        /**
         * Get current SearchPosition
         */
        @VTID(48)
        int getSearchPos();

        /**
         * Set Anchor Position
         */
        @VTID(49)
        void setAnchorPos(
            int p);

        /**
         * Get Anchor Position
         */
        @VTID(50)
        int getAnchorPos();

        /**
         * Get Line Count
         */
        @VTID(51)
        int lineCount();

        /**
         * Current line
         */
        @VTID(52)
        int currentLine();

        /**
         * Line from position
         */
        @VTID(53)
        int lineFromPos(
            int p);

        /**
         * pos for line
         */
        @VTID(54)
        int posFromLine(
            int l);

        /**
         * endpos for line
         */
        @VTID(55)
        int lineEndPos(
            int l);

        /**
         * First Visible Line
         */
        @VTID(56)
        int firstVisibleLine();

        /**
         * Visible Lines Count
         */
        @VTID(57)
        int linesOnScreen();

        /**
         * Line Length
         */
        @VTID(58)
        int lineLength(
            int l);

        /**
         * Get Line Text
         */
        @VTID(59)
        java.lang.String lineText(
            int l);

        /**
         * Set Line Text
         */
        @VTID(60)
        void setLineText(
            int l,
            java.lang.String txt);

        /**
         * Line
         */
        @VTID(61)
        void gotoLine(
            int l);

        /**
         * Get current selection
         */
        @VTID(62)
        void getSelection(
            Holder<Integer> pFirst,
            Holder<Integer> pLast);

        /**
         * Set current selection
         */
        @VTID(63)
        void setSelection(
            int pFirst,
            int pLast);

        /**
         * Get current selection Text
         */
        @VTID(64)
        java.lang.String getSelectionText();

        /**
         * Set Selection Start
         */
        @VTID(65)
        void setSelectionStart(
            int p);

        /**
         * Get Selection Start
         */
        @VTID(66)
        int getSelectionStart();

        /**
         * Set Selection End
         */
        @VTID(67)
        void setSelectionEnd(
            int p);

        /**
         * Get Selection End
         */
        @VTID(68)
        int getSelectionEnd();

        /**
         * Replace current selection
         */
        @VTID(69)
        void replaceSelection(
            java.lang.String txt);

        /**
         * Search in page
         */
        @VTID(70)
        boolean search(
            java.lang.String sWhat,
            int lFlags);

        /**
         * Replace in page
         */
        @VTID(71)
        boolean replace(
            java.lang.String sWhat,
            java.lang.String w,
            int lFlags);

        /**
         * Undo
         */
        @VTID(72)
        void undo();

        /**
         * Redo
         */
        @VTID(73)
        void redo();

        /**
         * Set SavePoint
         */
        @VTID(74)
        void savePoint();

        /**
         * Cut current selection
         */
        @VTID(75)
        void cut();

        /**
         * Copy current selection
         */
        @VTID(76)
        void copy();

        /**
         * Paste current selection
         */
        @VTID(77)
        void paste();

        /**
         * Set Focus
         */
        @VTID(78)
        void setFocus();

        /**
         * Zoom in
         */
        @VTID(79)
        void zoomIn();

        /**
         * Zoom out
         */
        @VTID(80)
        void zoomOut();

        /**
         * Set Indent
         */
        @VTID(81)
        void setIndent(
            int i);

        /**
         * Convert Tabs
         */
        @VTID(82)
        void convertTabs();

        /**
         * Print
         */
        @VTID(83)
        void print();

        /**
         * Get Text Range
         */
        @VTID(84)
        java.lang.String getTextRange(
            int pStart,
            int pEnd);

        /**
         * Show Properties
         */
        @VTID(85)
        void properties();

        /**
         * Syntax
         */
        @VTID(86)
        java.lang.String syntaxDisplayName();

        /**
         * SyntaxDisplayName
         */
        @VTID(87)
        java.lang.String getSyntaxDisplayName(
            int type);

        /**
         * Show the Insert Color Dialog
         */
        @VTID(88)
        void insertColorDialog();

        /**
         * Set WriteBOM
         */
        @VTID(89)
        void writeBOM(
            boolean vb);

        /**
         * Set WriteBOM
         */
        @VTID(90)
        boolean writeBOM();

    }
