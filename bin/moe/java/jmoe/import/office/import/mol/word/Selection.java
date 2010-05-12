package mol.word  ;

import com4j.*;

@IID("{00020975-0000-0000-C000-000000000046}")
public interface Selection extends Com4jObject {
    @VTID(7)
    @DefaultMethod
    java.lang.String text();

    @VTID(8)
    @DefaultMethod
    void text(
        java.lang.String prop);

    @VTID(9)
    mol.word.Range formattedText();

    @VTID(10)
    void formattedText(
        mol.word.Range prop);

    @VTID(11)
    int start();

    @VTID(12)
    void start(
        int prop);

    @VTID(13)
    int end();

    @VTID(14)
    void end(
        int prop);

    @VTID(15)
    mol.word._Font font();

    @VTID(16)
    void font(
        mol.word._Font prop);

    @VTID(17)
    mol.word.WdSelectionType type();

    @VTID(18)
    mol.word.WdStoryType storyType();

    @VTID(19)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object style();

    @VTID(20)
    void style(
        java.lang.Object prop);

    @VTID(21)
    mol.word.Tables tables();

    @VTID(21)
    @ReturnValue(defaultPropertyThrough={mol.word.Tables.class})
    mol.word.Table tables(
        int index);

    @VTID(22)
    mol.word.Words words();

    @VTID(22)
    @ReturnValue(defaultPropertyThrough={mol.word.Words.class})
    mol.word.Range words(
        int index);

    @VTID(23)
    mol.word.Sentences sentences();

    @VTID(23)
    @ReturnValue(defaultPropertyThrough={mol.word.Sentences.class})
    mol.word.Range sentences(
        int index);

    @VTID(24)
    mol.word.Characters characters();

    @VTID(24)
    @ReturnValue(defaultPropertyThrough={mol.word.Characters.class})
    mol.word.Range characters(
        int index);

    @VTID(25)
    mol.word.Footnotes footnotes();

    @VTID(25)
    @ReturnValue(defaultPropertyThrough={mol.word.Footnotes.class})
    mol.word.Footnote footnotes(
        int index);

    @VTID(26)
    mol.word.Endnotes endnotes();

    @VTID(26)
    @ReturnValue(defaultPropertyThrough={mol.word.Endnotes.class})
    mol.word.Endnote endnotes(
        int index);

    @VTID(27)
    mol.word.Comments comments();

    @VTID(27)
    @ReturnValue(defaultPropertyThrough={mol.word.Comments.class})
    mol.word.Comment comments(
        int index);

    @VTID(28)
    mol.word.Cells cells();

    @VTID(28)
    @ReturnValue(defaultPropertyThrough={mol.word.Cells.class})
    mol.word.Cell cells(
        int index);

    @VTID(29)
    mol.word.Sections sections();

    @VTID(29)
    @ReturnValue(defaultPropertyThrough={mol.word.Sections.class})
    mol.word.Section sections(
        int index);

    @VTID(30)
    mol.word.Paragraphs paragraphs();

    @VTID(30)
    @ReturnValue(defaultPropertyThrough={mol.word.Paragraphs.class})
    mol.word.Paragraph paragraphs(
        int index);

    @VTID(31)
    mol.word.Borders borders();

    @VTID(31)
    @ReturnValue(defaultPropertyThrough={mol.word.Borders.class})
    mol.word.Border borders(
        mol.word.WdBorderType index);

    @VTID(32)
    void borders(
        mol.word.Borders prop);

    @VTID(33)
    mol.word.Shading shading();

    @VTID(34)
    mol.word.Fields fields();

    @VTID(34)
    @ReturnValue(defaultPropertyThrough={mol.word.Fields.class})
    mol.word.Field fields(
        int index);

    @VTID(35)
    mol.word.FormFields formFields();

    @VTID(35)
    @ReturnValue(defaultPropertyThrough={mol.word.FormFields.class})
    mol.word.FormField formFields(
        java.lang.Object index);

    @VTID(36)
    mol.word.Frames frames();

    @VTID(36)
    @ReturnValue(defaultPropertyThrough={mol.word.Frames.class})
    mol.word.Frame frames(
        int index);

    @VTID(37)
    mol.word._ParagraphFormat paragraphFormat();

    @VTID(38)
    void paragraphFormat(
        mol.word._ParagraphFormat prop);

    @VTID(39)
    mol.word.PageSetup pageSetup();

    @VTID(40)
    void pageSetup(
        mol.word.PageSetup prop);

    @VTID(41)
    mol.word.Bookmarks bookmarks();

    @VTID(41)
    @ReturnValue(defaultPropertyThrough={mol.word.Bookmarks.class})
    mol.word.Bookmark bookmarks(
        java.lang.Object index);

    @VTID(42)
    int storyLength();

    @VTID(43)
    mol.word.WdLanguageID languageID();

    @VTID(44)
    void languageID(
        mol.word.WdLanguageID prop);

    @VTID(45)
    mol.word.WdLanguageID languageIDFarEast();

    @VTID(46)
    void languageIDFarEast(
        mol.word.WdLanguageID prop);

    @VTID(47)
    mol.word.WdLanguageID languageIDOther();

    @VTID(48)
    void languageIDOther(
        mol.word.WdLanguageID prop);

    @VTID(49)
    mol.word.Hyperlinks hyperlinks();

    @VTID(49)
    @ReturnValue(defaultPropertyThrough={mol.word.Hyperlinks.class})
    mol.word.Hyperlink hyperlinks(
        java.lang.Object index);

    @VTID(50)
    mol.word.Columns columns();

    @VTID(50)
    @ReturnValue(defaultPropertyThrough={mol.word.Columns.class})
    mol.word.Column columns(
        int index);

    @VTID(51)
    mol.word.Rows rows();

    @VTID(51)
    @ReturnValue(defaultPropertyThrough={mol.word.Rows.class})
    mol.word.Row rows(
        int index);

    @VTID(52)
    mol.word.HeaderFooter headerFooter();

    @VTID(53)
    boolean isEndOfRowMark();

    @VTID(54)
    int bookmarkID();

    @VTID(55)
    int previousBookmarkID();

    @VTID(56)
    mol.word.Find find();

    @VTID(57)
    mol.word.Range range();

    @VTID(58)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object information(
        mol.word.WdInformation type);

    @VTID(59)
    mol.word.WdSelectionFlags flags();

    @VTID(60)
    void flags(
        mol.word.WdSelectionFlags prop);

    @VTID(61)
    boolean active();

    @VTID(62)
    boolean startIsActive();

    @VTID(63)
    void startIsActive(
        boolean prop);

    @VTID(64)
    boolean ipAtEndOfLine();

    @VTID(65)
    boolean extendMode();

    @VTID(66)
    void extendMode(
        boolean prop);

    @VTID(67)
    boolean columnSelectMode();

    @VTID(68)
    void columnSelectMode(
        boolean prop);

    @VTID(69)
    mol.word.WdTextOrientation orientation();

    @VTID(70)
    void orientation(
        mol.word.WdTextOrientation prop);

    @VTID(71)
    mol.word.InlineShapes inlineShapes();

    @VTID(71)
    @ReturnValue(defaultPropertyThrough={mol.word.InlineShapes.class})
    mol.word.InlineShape inlineShapes(
        int index);

    @VTID(72)
    mol.word._Application application();

    @VTID(73)
    int creator();

    @VTID(74)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(75)
    mol.word._Document document();

    @VTID(76)
    mol.word.ShapeRange shapeRange();

    @VTID(76)
    @ReturnValue(defaultPropertyThrough={mol.word.ShapeRange.class})
    mol.word.Shape shapeRange(
        java.lang.Object index);

    @VTID(77)
    void select();

    @VTID(78)
    void setRange(
        int start,
        int end);

    @VTID(79)
    void collapse(
        java.lang.Object direction);

    @VTID(80)
    void insertBefore(
        java.lang.String text);

    @VTID(81)
    void insertAfter(
        java.lang.String text);

    @VTID(82)
    mol.word.Range next(
        java.lang.Object unit,
        java.lang.Object count);

    @VTID(83)
    mol.word.Range previous(
        java.lang.Object unit,
        java.lang.Object count);

    @VTID(84)
    int startOf(
        java.lang.Object unit,
        java.lang.Object extend);

    @VTID(85)
    int endOf(
        java.lang.Object unit,
        java.lang.Object extend);

    @VTID(86)
    int move(
        java.lang.Object unit,
        java.lang.Object count);

    @VTID(87)
    int moveStart(
        java.lang.Object unit,
        java.lang.Object count);

    @VTID(88)
    int moveEnd(
        java.lang.Object unit,
        java.lang.Object count);

    @VTID(89)
    int moveWhile(
        java.lang.Object cset,
        java.lang.Object count);

    @VTID(90)
    int moveStartWhile(
        java.lang.Object cset,
        java.lang.Object count);

    @VTID(91)
    int moveEndWhile(
        java.lang.Object cset,
        java.lang.Object count);

    @VTID(92)
    int moveUntil(
        java.lang.Object cset,
        java.lang.Object count);

    @VTID(93)
    int moveStartUntil(
        java.lang.Object cset,
        java.lang.Object count);

    @VTID(94)
    int moveEndUntil(
        java.lang.Object cset,
        java.lang.Object count);

    @VTID(95)
    void cut();

    @VTID(96)
    void copy();

    @VTID(97)
    void paste();

    @VTID(98)
    void insertBreak(
        java.lang.Object type);

    @VTID(99)
    void insertFile(
        java.lang.String fileName,
        java.lang.Object range,
        java.lang.Object confirmConversions,
        java.lang.Object link,
        java.lang.Object attachment);

    @VTID(100)
    boolean inStory(
        mol.word.Range range);

    @VTID(101)
    boolean inRange(
        mol.word.Range range);

    @VTID(102)
    int delete(
        java.lang.Object unit,
        java.lang.Object count);

    @VTID(103)
    int expand(
        java.lang.Object unit);

    @VTID(104)
    void insertParagraph();

    @VTID(105)
    void insertParagraphAfter();

    @VTID(106)
    mol.word.Table convertToTableOld(
        java.lang.Object separator,
        java.lang.Object numRows,
        java.lang.Object numColumns,
        java.lang.Object initialColumnWidth,
        java.lang.Object format,
        java.lang.Object applyBorders,
        java.lang.Object applyShading,
        java.lang.Object applyFont,
        java.lang.Object applyColor,
        java.lang.Object applyHeadingRows,
        java.lang.Object applyLastRow,
        java.lang.Object applyFirstColumn,
        java.lang.Object applyLastColumn,
        java.lang.Object autoFit);

    @VTID(107)
    void insertDateTimeOld(
        java.lang.Object dateTimeFormat,
        java.lang.Object insertAsField,
        java.lang.Object insertAsFullWidth);

    @VTID(108)
    void insertSymbol(
        int characterNumber,
        java.lang.Object font,
        java.lang.Object unicode,
        java.lang.Object bias);

    @VTID(109)
    void insertCrossReference_2002(
        java.lang.Object referenceType,
        mol.word.WdReferenceKind referenceKind,
        java.lang.Object referenceItem,
        java.lang.Object insertAsHyperlink,
        java.lang.Object includePosition);

    @VTID(110)
    void insertCaptionXP(
        java.lang.Object label,
        java.lang.Object title,
        java.lang.Object titleAutoText,
        java.lang.Object position);

    @VTID(111)
    void copyAsPicture();

    @VTID(112)
    void sortOld(
        java.lang.Object excludeHeader,
        java.lang.Object fieldNumber,
        java.lang.Object sortFieldType,
        java.lang.Object sortOrder,
        java.lang.Object fieldNumber2,
        java.lang.Object sortFieldType2,
        java.lang.Object sortOrder2,
        java.lang.Object fieldNumber3,
        java.lang.Object sortFieldType3,
        java.lang.Object sortOrder3,
        java.lang.Object sortColumn,
        java.lang.Object separator,
        java.lang.Object caseSensitive,
        java.lang.Object languageID);

    @VTID(113)
    void sortAscending();

    @VTID(114)
    void sortDescending();

    @VTID(115)
    boolean isEqual(
        mol.word.Range range);

    @VTID(116)
    float calculate();

    @VTID(117)
    mol.word.Range goTo(
        java.lang.Object what,
        java.lang.Object which,
        java.lang.Object count,
        java.lang.Object name);

    @VTID(118)
    mol.word.Range goToNext(
        mol.word.WdGoToItem what);

    @VTID(119)
    mol.word.Range goToPrevious(
        mol.word.WdGoToItem what);

    @VTID(120)
    void pasteSpecial(
        java.lang.Object iconIndex,
        java.lang.Object link,
        java.lang.Object placement,
        java.lang.Object displayAsIcon,
        java.lang.Object dataType,
        java.lang.Object iconFileName,
        java.lang.Object iconLabel);

    @VTID(121)
    mol.word.Field previousField();

    @VTID(122)
    mol.word.Field nextField();

    @VTID(123)
    void insertParagraphBefore();

    @VTID(124)
    void insertCells(
        java.lang.Object shiftCells);

    @VTID(125)
    void extend(
        java.lang.Object character);

    @VTID(126)
    void shrink();

    @VTID(127)
    int moveLeft(
        java.lang.Object unit,
        java.lang.Object count,
        java.lang.Object extend);

    @VTID(128)
    int moveRight(
        java.lang.Object unit,
        java.lang.Object count,
        java.lang.Object extend);

    @VTID(129)
    int moveUp(
        java.lang.Object unit,
        java.lang.Object count,
        java.lang.Object extend);

    @VTID(130)
    int moveDown(
        java.lang.Object unit,
        java.lang.Object count,
        java.lang.Object extend);

    @VTID(131)
    int homeKey(
        java.lang.Object unit,
        java.lang.Object extend);

    @VTID(132)
    int endKey(
        java.lang.Object unit,
        java.lang.Object extend);

    @VTID(133)
    void escapeKey();

    @VTID(134)
    void typeText(
        java.lang.String text);

    @VTID(135)
    void copyFormat();

    @VTID(136)
    void pasteFormat();

    @VTID(137)
    void typeParagraph();

    @VTID(138)
    void typeBackspace();

    @VTID(139)
    void nextSubdocument();

    @VTID(140)
    void previousSubdocument();

    @VTID(141)
    void selectColumn();

    @VTID(142)
    void selectCurrentFont();

    @VTID(143)
    void selectCurrentAlignment();

    @VTID(144)
    void selectCurrentSpacing();

    @VTID(145)
    void selectCurrentIndent();

    @VTID(146)
    void selectCurrentTabs();

    @VTID(147)
    void selectCurrentColor();

    @VTID(148)
    void createTextbox();

    @VTID(149)
    void wholeStory();

    @VTID(150)
    void selectRow();

    @VTID(151)
    void splitTable();

    @VTID(152)
    void insertRows(
        java.lang.Object numRows);

    @VTID(153)
    void insertColumns();

    @VTID(154)
    void insertFormula(
        java.lang.Object formula,
        java.lang.Object numberFormat);

    @VTID(155)
    mol.word.Revision nextRevision(
        java.lang.Object wrap);

    @VTID(156)
    mol.word.Revision previousRevision(
        java.lang.Object wrap);

    @VTID(157)
    void pasteAsNestedTable();

    @VTID(158)
    mol.word.AutoTextEntry createAutoTextEntry(
        java.lang.String name,
        java.lang.String styleName);

    @VTID(159)
    void detectLanguage();

    @VTID(160)
    void selectCell();

    @VTID(161)
    void insertRowsBelow(
        java.lang.Object numRows);

    @VTID(162)
    void insertColumnsRight();

    @VTID(163)
    void insertRowsAbove(
        java.lang.Object numRows);

    @VTID(164)
    void rtlRun();

    @VTID(165)
    void ltrRun();

    @VTID(166)
    void boldRun();

    @VTID(167)
    void italicRun();

    @VTID(168)
    void rtlPara();

    @VTID(169)
    void ltrPara();

    @VTID(170)
    void insertDateTime(
        java.lang.Object dateTimeFormat,
        java.lang.Object insertAsField,
        java.lang.Object insertAsFullWidth,
        java.lang.Object dateLanguage,
        java.lang.Object calendarType);

    @VTID(171)
    void sort2000(
        java.lang.Object excludeHeader,
        java.lang.Object fieldNumber,
        java.lang.Object sortFieldType,
        java.lang.Object sortOrder,
        java.lang.Object fieldNumber2,
        java.lang.Object sortFieldType2,
        java.lang.Object sortOrder2,
        java.lang.Object fieldNumber3,
        java.lang.Object sortFieldType3,
        java.lang.Object sortOrder3,
        java.lang.Object sortColumn,
        java.lang.Object separator,
        java.lang.Object caseSensitive,
        java.lang.Object bidiSort,
        java.lang.Object ignoreThe,
        java.lang.Object ignoreKashida,
        java.lang.Object ignoreDiacritics,
        java.lang.Object ignoreHe,
        java.lang.Object languageID);

    @VTID(172)
    mol.word.Table convertToTable(
        java.lang.Object separator,
        java.lang.Object numRows,
        java.lang.Object numColumns,
        java.lang.Object initialColumnWidth,
        java.lang.Object format,
        java.lang.Object applyBorders,
        java.lang.Object applyShading,
        java.lang.Object applyFont,
        java.lang.Object applyColor,
        java.lang.Object applyHeadingRows,
        java.lang.Object applyLastRow,
        java.lang.Object applyFirstColumn,
        java.lang.Object applyLastColumn,
        java.lang.Object autoFit,
        java.lang.Object autoFitBehavior,
        java.lang.Object defaultTableBehavior);

    @VTID(173)
    int noProofing();

    @VTID(174)
    void noProofing(
        int prop);

    @VTID(175)
    mol.word.Tables topLevelTables();

    @VTID(175)
    @ReturnValue(defaultPropertyThrough={mol.word.Tables.class})
    mol.word.Table topLevelTables(
        int index);

    @VTID(176)
    boolean languageDetected();

    @VTID(177)
    void languageDetected(
        boolean prop);

    @VTID(178)
    float fitTextWidth();

    @VTID(179)
    void fitTextWidth(
        float prop);

    @VTID(180)
    void clearFormatting();

    @VTID(181)
    void pasteAppendTable();

    @VTID(182)
    mol.word.HTMLDivisions htmlDivisions();

    @VTID(182)
    @ReturnValue(defaultPropertyThrough={mol.word.HTMLDivisions.class})
    mol.word.HTMLDivision htmlDivisions(
        int index);

    @VTID(183)
    mol.word.SmartTags smartTags();

    @VTID(183)
    @ReturnValue(defaultPropertyThrough={mol.word.SmartTags.class})
    mol.word.SmartTag smartTags(
        java.lang.Object index);

    @VTID(184)
    mol.word.ShapeRange childShapeRange();

    @VTID(184)
    @ReturnValue(defaultPropertyThrough={mol.word.ShapeRange.class})
    mol.word.Shape childShapeRange(
        java.lang.Object index);

    @VTID(185)
    boolean hasChildShapeRange();

    @VTID(186)
    mol.word.FootnoteOptions footnoteOptions();

    @VTID(187)
    mol.word.EndnoteOptions endnoteOptions();

    @VTID(188)
    void toggleCharacterCode();

    @VTID(189)
    void pasteAndFormat(
        mol.word.WdRecoveryType type);

    @VTID(190)
    void pasteExcelTable(
        boolean linkedToExcel,
        boolean wordFormatting,
        boolean rtf);

    @VTID(191)
    void shrinkDiscontiguousSelection();

    @VTID(192)
    void insertStyleSeparator();

    @VTID(193)
    void sort(
        java.lang.Object excludeHeader,
        java.lang.Object fieldNumber,
        java.lang.Object sortFieldType,
        java.lang.Object sortOrder,
        java.lang.Object fieldNumber2,
        java.lang.Object sortFieldType2,
        java.lang.Object sortOrder2,
        java.lang.Object fieldNumber3,
        java.lang.Object sortFieldType3,
        java.lang.Object sortOrder3,
        java.lang.Object sortColumn,
        java.lang.Object separator,
        java.lang.Object caseSensitive,
        java.lang.Object bidiSort,
        java.lang.Object ignoreThe,
        java.lang.Object ignoreKashida,
        java.lang.Object ignoreDiacritics,
        java.lang.Object ignoreHe,
        java.lang.Object languageID,
        java.lang.Object subFieldNumber,
        java.lang.Object subFieldNumber2,
        java.lang.Object subFieldNumber3);

    @VTID(194)
    mol.word.XMLNodes xmlNodes();

    @VTID(194)
    @ReturnValue(defaultPropertyThrough={mol.word.XMLNodes.class})
    mol.word.XMLNode xmlNodes(
        int index);

    @VTID(195)
    mol.word.XMLNode xmlParentNode();

    @VTID(196)
    mol.word.Editors editors();

    @VTID(196)
    @ReturnValue(defaultPropertyThrough={mol.word.Editors.class})
    mol.word.Editor editors(
        java.lang.Object index);

    @VTID(197)
    java.lang.String xml(
        boolean dataOnly);

    @VTID(198)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object enhMetaFileBits();

    @VTID(199)
    mol.word.Range goToEditableRange(
        java.lang.Object editorID);

    @VTID(200)
    void insertXML(
        java.lang.String xml,
        java.lang.Object transform);

    @VTID(201)
    void insertCaption(
        java.lang.Object label,
        java.lang.Object title,
        java.lang.Object titleAutoText,
        java.lang.Object position,
        java.lang.Object excludeLabel);

    @VTID(202)
    void insertCrossReference(
        java.lang.Object referenceType,
        mol.word.WdReferenceKind referenceKind,
        java.lang.Object referenceItem,
        java.lang.Object insertAsHyperlink,
        java.lang.Object includePosition,
        java.lang.Object separateNumbers,
        java.lang.Object separatorString);

    @VTID(203)
    mol.word.OMaths oMaths();

    @VTID(203)
    @ReturnValue(defaultPropertyThrough={mol.word.OMaths.class})
    mol.word.OMath oMaths(
        int index);

    @VTID(204)
    java.lang.String wordOpenXML();

    @VTID(205)
    void clearParagraphStyle();

    @VTID(206)
    void clearCharacterAllFormatting();

    @VTID(207)
    void clearCharacterStyle();

    @VTID(208)
    void clearCharacterDirectFormatting();

    @VTID(209)
    mol.word.ContentControls contentControls();

    @VTID(209)
    @ReturnValue(defaultPropertyThrough={mol.word.ContentControls.class})
    mol.word.ContentControl contentControls(
        java.lang.Object index);

    @VTID(210)
    mol.word.ContentControl parentContentControl();

    @VTID(211)
    void exportAsFixedFormat(
        java.lang.String outputFileName,
        mol.word.WdExportFormat exportFormat,
        boolean openAfterExport,
        mol.word.WdExportOptimizeFor optimizeFor,
        boolean exportCurrentPage,
        mol.word.WdExportItem item,
        boolean includeDocProps,
        boolean keepIRM,
        mol.word.WdExportCreateBookmarks createBookmarks,
        boolean docStructureTags,
        boolean bitmapMissingFonts,
        boolean useISO19005_1,
        java.lang.Object fixedFormatExtClassPtr);

    @VTID(212)
    void readingModeGrowFont();

    @VTID(213)
    void readingModeShrinkFont();

    @VTID(214)
    void clearParagraphAllFormatting();

    @VTID(215)
    void clearParagraphDirectFormatting();

    @VTID(216)
    void insertNewPage();

}
