package mol.word  ;

import com4j.*;

@IID("{0002095E-0000-0000-C000-000000000046}")
public interface Range extends Com4jObject {
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
    mol.word.Range duplicate();

    @VTID(18)
    mol.word.WdStoryType storyType();

    @VTID(19)
    mol.word.Tables tables();

    @VTID(19)
    @ReturnValue(defaultPropertyThrough={mol.word.Tables.class})
    mol.word.Table tables(
        int index);

    @VTID(20)
    mol.word.Words words();

    @VTID(20)
    @ReturnValue(defaultPropertyThrough={mol.word.Words.class})
    mol.word.Range words(
        int index);

    @VTID(21)
    mol.word.Sentences sentences();

    @VTID(21)
    @ReturnValue(defaultPropertyThrough={mol.word.Sentences.class})
    mol.word.Range sentences(
        int index);

    @VTID(22)
    mol.word.Characters characters();

    @VTID(22)
    @ReturnValue(defaultPropertyThrough={mol.word.Characters.class})
    mol.word.Range characters(
        int index);

    @VTID(23)
    mol.word.Footnotes footnotes();

    @VTID(23)
    @ReturnValue(defaultPropertyThrough={mol.word.Footnotes.class})
    mol.word.Footnote footnotes(
        int index);

    @VTID(24)
    mol.word.Endnotes endnotes();

    @VTID(24)
    @ReturnValue(defaultPropertyThrough={mol.word.Endnotes.class})
    mol.word.Endnote endnotes(
        int index);

    @VTID(25)
    mol.word.Comments comments();

    @VTID(25)
    @ReturnValue(defaultPropertyThrough={mol.word.Comments.class})
    mol.word.Comment comments(
        int index);

    @VTID(26)
    mol.word.Cells cells();

    @VTID(26)
    @ReturnValue(defaultPropertyThrough={mol.word.Cells.class})
    mol.word.Cell cells(
        int index);

    @VTID(27)
    mol.word.Sections sections();

    @VTID(27)
    @ReturnValue(defaultPropertyThrough={mol.word.Sections.class})
    mol.word.Section sections(
        int index);

    @VTID(28)
    mol.word.Paragraphs paragraphs();

    @VTID(28)
    @ReturnValue(defaultPropertyThrough={mol.word.Paragraphs.class})
    mol.word.Paragraph paragraphs(
        int index);

    @VTID(29)
    mol.word.Borders borders();

    @VTID(29)
    @ReturnValue(defaultPropertyThrough={mol.word.Borders.class})
    mol.word.Border borders(
        mol.word.WdBorderType index);

    @VTID(30)
    void borders(
        mol.word.Borders prop);

    @VTID(31)
    mol.word.Shading shading();

    @VTID(32)
    mol.word.TextRetrievalMode textRetrievalMode();

    @VTID(33)
    void textRetrievalMode(
        mol.word.TextRetrievalMode prop);

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
    mol.word.ListFormat listFormat();

    @VTID(40)
    mol.word.Bookmarks bookmarks();

    @VTID(40)
    @ReturnValue(defaultPropertyThrough={mol.word.Bookmarks.class})
    mol.word.Bookmark bookmarks(
        java.lang.Object index);

    @VTID(41)
    mol.word._Application application();

    @VTID(42)
    int creator();

    @VTID(43)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(44)
    int bold();

    @VTID(45)
    void bold(
        int prop);

    @VTID(46)
    int italic();

    @VTID(47)
    void italic(
        int prop);

    @VTID(48)
    mol.word.WdUnderline underline();

    @VTID(49)
    void underline(
        mol.word.WdUnderline prop);

    @VTID(50)
    mol.word.WdEmphasisMark emphasisMark();

    @VTID(51)
    void emphasisMark(
        mol.word.WdEmphasisMark prop);

    @VTID(52)
    boolean disableCharacterSpaceGrid();

    @VTID(53)
    void disableCharacterSpaceGrid(
        boolean prop);

    @VTID(54)
    mol.word.Revisions revisions();

    @VTID(54)
    @ReturnValue(defaultPropertyThrough={mol.word.Revisions.class})
    mol.word.Revision revisions(
        int index);

    @VTID(55)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object style();

    @VTID(56)
    void style(
        java.lang.Object prop);

    @VTID(57)
    int storyLength();

    @VTID(58)
    mol.word.WdLanguageID languageID();

    @VTID(59)
    void languageID(
        mol.word.WdLanguageID prop);

    @VTID(60)
    mol.word.SynonymInfo synonymInfo();

    @VTID(61)
    mol.word.Hyperlinks hyperlinks();

    @VTID(61)
    @ReturnValue(defaultPropertyThrough={mol.word.Hyperlinks.class})
    mol.word.Hyperlink hyperlinks(
        java.lang.Object index);

    @VTID(62)
    mol.word.ListParagraphs listParagraphs();

    @VTID(62)
    @ReturnValue(defaultPropertyThrough={mol.word.ListParagraphs.class})
    mol.word.Paragraph listParagraphs(
        int index);

    @VTID(63)
    mol.word.Subdocuments subdocuments();

    @VTID(63)
    @ReturnValue(defaultPropertyThrough={mol.word.Subdocuments.class})
    mol.word.Subdocument subdocuments(
        int index);

    @VTID(64)
    boolean grammarChecked();

    @VTID(65)
    void grammarChecked(
        boolean prop);

    @VTID(66)
    boolean spellingChecked();

    @VTID(67)
    void spellingChecked(
        boolean prop);

    @VTID(68)
    mol.word.WdColorIndex highlightColorIndex();

    @VTID(69)
    void highlightColorIndex(
        mol.word.WdColorIndex prop);

    @VTID(70)
    mol.word.Columns columns();

    @VTID(70)
    @ReturnValue(defaultPropertyThrough={mol.word.Columns.class})
    mol.word.Column columns(
        int index);

    @VTID(71)
    mol.word.Rows rows();

    @VTID(71)
    @ReturnValue(defaultPropertyThrough={mol.word.Rows.class})
    mol.word.Row rows(
        int index);

    @VTID(72)
    int canEdit();

    @VTID(73)
    int canPaste();

    @VTID(74)
    boolean isEndOfRowMark();

    @VTID(75)
    int bookmarkID();

    @VTID(76)
    int previousBookmarkID();

    @VTID(77)
    mol.word.Find find();

    @VTID(78)
    mol.word.PageSetup pageSetup();

    @VTID(79)
    void pageSetup(
        mol.word.PageSetup prop);

    @VTID(80)
    mol.word.ShapeRange shapeRange();

    @VTID(80)
    @ReturnValue(defaultPropertyThrough={mol.word.ShapeRange.class})
    mol.word.Shape shapeRange(
        java.lang.Object index);

    @VTID(81)
    mol.word.WdCharacterCase _case();

    @VTID(82)
    void _case(
        mol.word.WdCharacterCase prop);

    @VTID(83)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object information(
        mol.word.WdInformation type);

    @VTID(84)
    mol.word.ReadabilityStatistics readabilityStatistics();

    @VTID(84)
    @ReturnValue(defaultPropertyThrough={mol.word.ReadabilityStatistics.class})
    mol.word.ReadabilityStatistic readabilityStatistics(
        java.lang.Object index);

    @VTID(85)
    mol.word.ProofreadingErrors grammaticalErrors();

    @VTID(85)
    @ReturnValue(defaultPropertyThrough={mol.word.ProofreadingErrors.class})
    mol.word.Range grammaticalErrors(
        int index);

    @VTID(86)
    mol.word.ProofreadingErrors spellingErrors();

    @VTID(86)
    @ReturnValue(defaultPropertyThrough={mol.word.ProofreadingErrors.class})
    mol.word.Range spellingErrors(
        int index);

    @VTID(87)
    mol.word.WdTextOrientation orientation();

    @VTID(88)
    void orientation(
        mol.word.WdTextOrientation prop);

    @VTID(89)
    mol.word.InlineShapes inlineShapes();

    @VTID(89)
    @ReturnValue(defaultPropertyThrough={mol.word.InlineShapes.class})
    mol.word.InlineShape inlineShapes(
        int index);

    @VTID(90)
    mol.word.Range nextStoryRange();

    @VTID(91)
    mol.word.WdLanguageID languageIDFarEast();

    @VTID(92)
    void languageIDFarEast(
        mol.word.WdLanguageID prop);

    @VTID(93)
    mol.word.WdLanguageID languageIDOther();

    @VTID(94)
    void languageIDOther(
        mol.word.WdLanguageID prop);

    @VTID(95)
    void select();

    @VTID(96)
    void setRange(
        int start,
        int end);

    @VTID(97)
    void collapse(
        java.lang.Object direction);

    @VTID(98)
    void insertBefore(
        java.lang.String text);

    @VTID(99)
    void insertAfter(
        java.lang.String text);

    @VTID(100)
    mol.word.Range next(
        java.lang.Object unit,
        java.lang.Object count);

    @VTID(101)
    mol.word.Range previous(
        java.lang.Object unit,
        java.lang.Object count);

    @VTID(102)
    int startOf(
        java.lang.Object unit,
        java.lang.Object extend);

    @VTID(103)
    int endOf(
        java.lang.Object unit,
        java.lang.Object extend);

    @VTID(104)
    int move(
        java.lang.Object unit,
        java.lang.Object count);

    @VTID(105)
    int moveStart(
        java.lang.Object unit,
        java.lang.Object count);

    @VTID(106)
    int moveEnd(
        java.lang.Object unit,
        java.lang.Object count);

    @VTID(107)
    int moveWhile(
        java.lang.Object cset,
        java.lang.Object count);

    @VTID(108)
    int moveStartWhile(
        java.lang.Object cset,
        java.lang.Object count);

    @VTID(109)
    int moveEndWhile(
        java.lang.Object cset,
        java.lang.Object count);

    @VTID(110)
    int moveUntil(
        java.lang.Object cset,
        java.lang.Object count);

    @VTID(111)
    int moveStartUntil(
        java.lang.Object cset,
        java.lang.Object count);

    @VTID(112)
    int moveEndUntil(
        java.lang.Object cset,
        java.lang.Object count);

    @VTID(113)
    void cut();

    @VTID(114)
    void copy();

    @VTID(115)
    void paste();

    @VTID(116)
    void insertBreak(
        java.lang.Object type);

    @VTID(117)
    void insertFile(
        java.lang.String fileName,
        java.lang.Object range,
        java.lang.Object confirmConversions,
        java.lang.Object link,
        java.lang.Object attachment);

    @VTID(118)
    boolean inStory(
        mol.word.Range range);

    @VTID(119)
    boolean inRange(
        mol.word.Range range);

    @VTID(120)
    int delete(
        java.lang.Object unit,
        java.lang.Object count);

    @VTID(121)
    void wholeStory();

    @VTID(122)
    int expand(
        java.lang.Object unit);

    @VTID(123)
    void insertParagraph();

    @VTID(124)
    void insertParagraphAfter();

    @VTID(125)
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

    @VTID(126)
    void insertDateTimeOld(
        java.lang.Object dateTimeFormat,
        java.lang.Object insertAsField,
        java.lang.Object insertAsFullWidth);

    @VTID(127)
    void insertSymbol(
        int characterNumber,
        java.lang.Object font,
        java.lang.Object unicode,
        java.lang.Object bias);

    @VTID(128)
    void insertCrossReference_2002(
        java.lang.Object referenceType,
        mol.word.WdReferenceKind referenceKind,
        java.lang.Object referenceItem,
        java.lang.Object insertAsHyperlink,
        java.lang.Object includePosition);

    @VTID(129)
    void insertCaptionXP(
        java.lang.Object label,
        java.lang.Object title,
        java.lang.Object titleAutoText,
        java.lang.Object position);

    @VTID(130)
    void copyAsPicture();

    @VTID(131)
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

    @VTID(132)
    void sortAscending();

    @VTID(133)
    void sortDescending();

    @VTID(134)
    boolean isEqual(
        mol.word.Range range);

    @VTID(135)
    float calculate();

    @VTID(136)
    mol.word.Range goTo(
        java.lang.Object what,
        java.lang.Object which,
        java.lang.Object count,
        java.lang.Object name);

    @VTID(137)
    mol.word.Range goToNext(
        mol.word.WdGoToItem what);

    @VTID(138)
    mol.word.Range goToPrevious(
        mol.word.WdGoToItem what);

    @VTID(139)
    void pasteSpecial(
        java.lang.Object iconIndex,
        java.lang.Object link,
        java.lang.Object placement,
        java.lang.Object displayAsIcon,
        java.lang.Object dataType,
        java.lang.Object iconFileName,
        java.lang.Object iconLabel);

    @VTID(140)
    void lookupNameProperties();

    @VTID(141)
    int computeStatistics(
        mol.word.WdStatistic statistic);

    @VTID(142)
    void relocate(
        int direction);

    @VTID(143)
    void checkSynonyms();

    @VTID(144)
    void subscribeTo(
        java.lang.String edition,
        java.lang.Object format);

    @VTID(145)
    void createPublisher(
        java.lang.Object edition,
        java.lang.Object containsPICT,
        java.lang.Object containsRTF,
        java.lang.Object containsText);

    @VTID(146)
    void insertAutoText();

    @VTID(147)
    void insertDatabase(
        java.lang.Object format,
        java.lang.Object style,
        java.lang.Object linkToSource,
        java.lang.Object connection,
        java.lang.Object sqlStatement,
        java.lang.Object sqlStatement1,
        java.lang.Object passwordDocument,
        java.lang.Object passwordTemplate,
        java.lang.Object writePasswordDocument,
        java.lang.Object writePasswordTemplate,
        java.lang.Object dataSource,
        java.lang.Object from,
        java.lang.Object to,
        java.lang.Object includeFields);

    @VTID(148)
    void autoFormat();

    @VTID(149)
    void checkGrammar();

    @VTID(150)
    void checkSpelling(
        java.lang.Object customDictionary,
        java.lang.Object ignoreUppercase,
        java.lang.Object alwaysSuggest,
        java.lang.Object customDictionary2,
        java.lang.Object customDictionary3,
        java.lang.Object customDictionary4,
        java.lang.Object customDictionary5,
        java.lang.Object customDictionary6,
        java.lang.Object customDictionary7,
        java.lang.Object customDictionary8,
        java.lang.Object customDictionary9,
        java.lang.Object customDictionary10);

    @VTID(151)
    mol.word.SpellingSuggestions getSpellingSuggestions(
        java.lang.Object customDictionary,
        java.lang.Object ignoreUppercase,
        java.lang.Object mainDictionary,
        java.lang.Object suggestionMode,
        java.lang.Object customDictionary2,
        java.lang.Object customDictionary3,
        java.lang.Object customDictionary4,
        java.lang.Object customDictionary5,
        java.lang.Object customDictionary6,
        java.lang.Object customDictionary7,
        java.lang.Object customDictionary8,
        java.lang.Object customDictionary9,
        java.lang.Object customDictionary10);

    @VTID(152)
    void insertParagraphBefore();

    @VTID(153)
    void nextSubdocument();

    @VTID(154)
    void previousSubdocument();

    @VTID(155)
    void convertHangulAndHanja(
        java.lang.Object conversionsMode,
        java.lang.Object fastConversion,
        java.lang.Object checkHangulEnding,
        java.lang.Object enableRecentOrdering,
        java.lang.Object customDictionary);

    @VTID(156)
    void pasteAsNestedTable();

    @VTID(157)
    void modifyEnclosure(
        java.lang.Object style,
        java.lang.Object symbol,
        java.lang.Object enclosedText);

    @VTID(158)
    void phoneticGuide(
        java.lang.String text,
        mol.word.WdPhoneticGuideAlignmentType alignment,
        int raise,
        int fontSize,
        java.lang.String fontName);

    @VTID(159)
    void insertDateTime(
        java.lang.Object dateTimeFormat,
        java.lang.Object insertAsField,
        java.lang.Object insertAsFullWidth,
        java.lang.Object dateLanguage,
        java.lang.Object calendarType);

    @VTID(160)
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
        java.lang.Object languageID);

    @VTID(161)
    void detectLanguage();

    @VTID(162)
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

    @VTID(163)
    void tcscConverter(
        mol.word.WdTCSCConverterDirection wdTCSCConverterDirection,
        boolean commonTerms,
        boolean useVariants);

    @VTID(164)
    boolean languageDetected();

    @VTID(165)
    void languageDetected(
        boolean prop);

    @VTID(166)
    float fitTextWidth();

    @VTID(167)
    void fitTextWidth(
        float prop);

    @VTID(168)
    mol.word.WdHorizontalInVerticalType horizontalInVertical();

    @VTID(169)
    void horizontalInVertical(
        mol.word.WdHorizontalInVerticalType prop);

    @VTID(170)
    mol.word.WdTwoLinesInOneType twoLinesInOne();

    @VTID(171)
    void twoLinesInOne(
        mol.word.WdTwoLinesInOneType prop);

    @VTID(172)
    boolean combineCharacters();

    @VTID(173)
    void combineCharacters(
        boolean prop);

    @VTID(174)
    int noProofing();

    @VTID(175)
    void noProofing(
        int prop);

    @VTID(176)
    mol.word.Tables topLevelTables();

    @VTID(176)
    @ReturnValue(defaultPropertyThrough={mol.word.Tables.class})
    mol.word.Table topLevelTables(
        int index);

    @VTID(177)
    mol.office.Scripts scripts();

    @VTID(177)
    @ReturnValue(defaultPropertyThrough={mol.office.Scripts.class})
    mol.office.Script scripts(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(178)
    mol.word.WdCharacterWidth characterWidth();

    @VTID(179)
    void characterWidth(
        mol.word.WdCharacterWidth prop);

    @VTID(180)
    mol.word.WdKana kana();

    @VTID(181)
    void kana(
        mol.word.WdKana prop);

    @VTID(182)
    int boldBi();

    @VTID(183)
    void boldBi(
        int prop);

    @VTID(184)
    int italicBi();

    @VTID(185)
    void italicBi(
        int prop);

    @VTID(186)
    java.lang.String id();

    @VTID(187)
    void id(
        java.lang.String prop);

    @VTID(188)
    mol.word.HTMLDivisions htmlDivisions();

    @VTID(188)
    @ReturnValue(defaultPropertyThrough={mol.word.HTMLDivisions.class})
    mol.word.HTMLDivision htmlDivisions(
        int index);

    @VTID(189)
    mol.word.SmartTags smartTags();

    @VTID(189)
    @ReturnValue(defaultPropertyThrough={mol.word.SmartTags.class})
    mol.word.SmartTag smartTags(
        java.lang.Object index);

    @VTID(190)
    boolean showAll();

    @VTID(191)
    void showAll(
        boolean prop);

    @VTID(192)
    mol.word._Document document();

    @VTID(193)
    mol.word.FootnoteOptions footnoteOptions();

    @VTID(194)
    mol.word.EndnoteOptions endnoteOptions();

    @VTID(195)
    void pasteAndFormat(
        mol.word.WdRecoveryType type);

    @VTID(196)
    void pasteExcelTable(
        boolean linkedToExcel,
        boolean wordFormatting,
        boolean rtf);

    @VTID(197)
    void pasteAppendTable();

    @VTID(198)
    mol.word.XMLNodes xmlNodes();

    @VTID(198)
    @ReturnValue(defaultPropertyThrough={mol.word.XMLNodes.class})
    mol.word.XMLNode xmlNodes(
        int index);

    @VTID(199)
    mol.word.XMLNode xmlParentNode();

    @VTID(200)
    mol.word.Editors editors();

    @VTID(200)
    @ReturnValue(defaultPropertyThrough={mol.word.Editors.class})
    mol.word.Editor editors(
        java.lang.Object index);

    @VTID(201)
    java.lang.String xml(
        boolean dataOnly);

    @VTID(202)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object enhMetaFileBits();

    @VTID(203)
    mol.word.Range goToEditableRange(
        java.lang.Object editorID);

    @VTID(204)
    void insertXML(
        java.lang.String xml,
        java.lang.Object transform);

    @VTID(205)
    void insertCaption(
        java.lang.Object label,
        java.lang.Object title,
        java.lang.Object titleAutoText,
        java.lang.Object position,
        java.lang.Object excludeLabel);

    @VTID(206)
    void insertCrossReference(
        java.lang.Object referenceType,
        mol.word.WdReferenceKind referenceKind,
        java.lang.Object referenceItem,
        java.lang.Object insertAsHyperlink,
        java.lang.Object includePosition,
        java.lang.Object separateNumbers,
        java.lang.Object separatorString);

    @VTID(207)
    mol.word.OMaths oMaths();

    @VTID(207)
    @ReturnValue(defaultPropertyThrough={mol.word.OMaths.class})
    mol.word.OMath oMaths(
        int index);

    @VTID(208)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object characterStyle();

    @VTID(209)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object paragraphStyle();

    @VTID(210)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object listStyle();

    @VTID(211)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object tableStyle();

    @VTID(212)
    mol.word.ContentControls contentControls();

    @VTID(212)
    @ReturnValue(defaultPropertyThrough={mol.word.ContentControls.class})
    mol.word.ContentControl contentControls(
        java.lang.Object index);

    @VTID(213)
    void exportFragment(
        java.lang.String fileName,
        mol.word.WdSaveFormat format);

    @VTID(214)
    java.lang.String wordOpenXML();

    @VTID(215)
    void setListLevel(
        short level);

    @VTID(216)
    void insertAlignmentTab(
        int alignment,
        int relativeTo);

    @VTID(217)
    mol.word.ContentControl parentContentControl();

    @VTID(218)
    void importFragment(
        java.lang.String fileName,
        boolean matchDestination);

    @VTID(219)
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

}
