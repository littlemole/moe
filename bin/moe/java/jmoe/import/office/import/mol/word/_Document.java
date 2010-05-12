package mol.word  ;

import com4j.*;

@IID("{0002096B-0000-0000-C000-000000000046}")
public interface _Document extends Com4jObject {
    @VTID(7)
    @DefaultMethod
    java.lang.String name();

    @VTID(8)
    mol.word._Application application();

    @VTID(9)
    int creator();

    @VTID(10)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(11)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject builtInDocumentProperties();

    @VTID(12)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject customDocumentProperties();

    @VTID(13)
    java.lang.String path();

    @VTID(14)
    mol.word.Bookmarks bookmarks();

    @VTID(14)
    @ReturnValue(defaultPropertyThrough={mol.word.Bookmarks.class})
    mol.word.Bookmark bookmarks(
        java.lang.Object index);

    @VTID(15)
    mol.word.Tables tables();

    @VTID(15)
    @ReturnValue(defaultPropertyThrough={mol.word.Tables.class})
    mol.word.Table tables(
        int index);

    @VTID(16)
    mol.word.Footnotes footnotes();

    @VTID(16)
    @ReturnValue(defaultPropertyThrough={mol.word.Footnotes.class})
    mol.word.Footnote footnotes(
        int index);

    @VTID(17)
    mol.word.Endnotes endnotes();

    @VTID(17)
    @ReturnValue(defaultPropertyThrough={mol.word.Endnotes.class})
    mol.word.Endnote endnotes(
        int index);

    @VTID(18)
    mol.word.Comments comments();

    @VTID(18)
    @ReturnValue(defaultPropertyThrough={mol.word.Comments.class})
    mol.word.Comment comments(
        int index);

    @VTID(19)
    mol.word.WdDocumentType type();

    @VTID(20)
    boolean autoHyphenation();

    @VTID(21)
    void autoHyphenation(
        boolean prop);

    @VTID(22)
    boolean hyphenateCaps();

    @VTID(23)
    void hyphenateCaps(
        boolean prop);

    @VTID(24)
    int hyphenationZone();

    @VTID(25)
    void hyphenationZone(
        int prop);

    @VTID(26)
    int consecutiveHyphensLimit();

    @VTID(27)
    void consecutiveHyphensLimit(
        int prop);

    @VTID(28)
    mol.word.Sections sections();

    @VTID(28)
    @ReturnValue(defaultPropertyThrough={mol.word.Sections.class})
    mol.word.Section sections(
        int index);

    @VTID(29)
    mol.word.Paragraphs paragraphs();

    @VTID(29)
    @ReturnValue(defaultPropertyThrough={mol.word.Paragraphs.class})
    mol.word.Paragraph paragraphs(
        int index);

    @VTID(30)
    mol.word.Words words();

    @VTID(30)
    @ReturnValue(defaultPropertyThrough={mol.word.Words.class})
    mol.word.Range words(
        int index);

    @VTID(31)
    mol.word.Sentences sentences();

    @VTID(31)
    @ReturnValue(defaultPropertyThrough={mol.word.Sentences.class})
    mol.word.Range sentences(
        int index);

    @VTID(32)
    mol.word.Characters characters();

    @VTID(32)
    @ReturnValue(defaultPropertyThrough={mol.word.Characters.class})
    mol.word.Range characters(
        int index);

    @VTID(33)
    mol.word.Fields fields();

    @VTID(33)
    @ReturnValue(defaultPropertyThrough={mol.word.Fields.class})
    mol.word.Field fields(
        int index);

    @VTID(34)
    mol.word.FormFields formFields();

    @VTID(34)
    @ReturnValue(defaultPropertyThrough={mol.word.FormFields.class})
    mol.word.FormField formFields(
        java.lang.Object index);

    @VTID(35)
    mol.word.Styles styles();

    @VTID(35)
    @ReturnValue(defaultPropertyThrough={mol.word.Styles.class})
    mol.word.Style styles(
        java.lang.Object index);

    @VTID(36)
    mol.word.Frames frames();

    @VTID(36)
    @ReturnValue(defaultPropertyThrough={mol.word.Frames.class})
    mol.word.Frame frames(
        int index);

    @VTID(37)
    mol.word.TablesOfFigures tablesOfFigures();

    @VTID(37)
    @ReturnValue(defaultPropertyThrough={mol.word.TablesOfFigures.class})
    mol.word.TableOfFigures tablesOfFigures(
        int index);

    @VTID(38)
    mol.word.Variables variables();

    @VTID(38)
    @ReturnValue(defaultPropertyThrough={mol.word.Variables.class})
    mol.word.Variable variables(
        java.lang.Object index);

    @VTID(39)
    mol.word.MailMerge mailMerge();

    @VTID(40)
    mol.word.Envelope envelope();

    @VTID(41)
    java.lang.String fullName();

    @VTID(42)
    mol.word.Revisions revisions();

    @VTID(42)
    @ReturnValue(defaultPropertyThrough={mol.word.Revisions.class})
    mol.word.Revision revisions(
        int index);

    @VTID(43)
    mol.word.TablesOfContents tablesOfContents();

    @VTID(43)
    @ReturnValue(defaultPropertyThrough={mol.word.TablesOfContents.class})
    mol.word.TableOfContents tablesOfContents(
        int index);

    @VTID(44)
    mol.word.TablesOfAuthorities tablesOfAuthorities();

    @VTID(44)
    @ReturnValue(defaultPropertyThrough={mol.word.TablesOfAuthorities.class})
    mol.word.TableOfAuthorities tablesOfAuthorities(
        int index);

    @VTID(45)
    mol.word.PageSetup pageSetup();

    @VTID(46)
    void pageSetup(
        mol.word.PageSetup prop);

    @VTID(47)
    mol.word.Windows windows();

    @VTID(47)
    @ReturnValue(defaultPropertyThrough={mol.word.Windows.class})
    mol.word.Window windows(
        java.lang.Object index);

    @VTID(48)
    boolean hasRoutingSlip();

    @VTID(49)
    void hasRoutingSlip(
        boolean prop);

    @VTID(50)
    mol.word.RoutingSlip routingSlip();

    @VTID(51)
    boolean routed();

    @VTID(52)
    mol.word.TablesOfAuthoritiesCategories tablesOfAuthoritiesCategories();

    @VTID(52)
    @ReturnValue(defaultPropertyThrough={mol.word.TablesOfAuthoritiesCategories.class})
    mol.word.TableOfAuthoritiesCategory tablesOfAuthoritiesCategories(
        java.lang.Object index);

    @VTID(53)
    mol.word.Indexes indexes();

    @VTID(53)
    @ReturnValue(defaultPropertyThrough={mol.word.Indexes.class})
    mol.word.Index indexes(
        int index);

    @VTID(54)
    boolean saved();

    @VTID(55)
    void saved(
        boolean prop);

    @VTID(56)
    mol.word.Range content();

    @VTID(57)
    mol.word.Window activeWindow();

    @VTID(58)
    mol.word.WdDocumentKind kind();

    @VTID(59)
    void kind(
        mol.word.WdDocumentKind prop);

    @VTID(60)
    boolean readOnly();

    @VTID(61)
    mol.word.Subdocuments subdocuments();

    @VTID(61)
    @ReturnValue(defaultPropertyThrough={mol.word.Subdocuments.class})
    mol.word.Subdocument subdocuments(
        int index);

    @VTID(62)
    boolean isMasterDocument();

    @VTID(63)
    float defaultTabStop();

    @VTID(64)
    void defaultTabStop(
        float prop);

    @VTID(65)
    boolean embedTrueTypeFonts();

    @VTID(66)
    void embedTrueTypeFonts(
        boolean prop);

    @VTID(67)
    boolean saveFormsData();

    @VTID(68)
    void saveFormsData(
        boolean prop);

    @VTID(69)
    boolean readOnlyRecommended();

    @VTID(70)
    void readOnlyRecommended(
        boolean prop);

    @VTID(71)
    boolean saveSubsetFonts();

    @VTID(72)
    void saveSubsetFonts(
        boolean prop);

    @VTID(73)
    boolean compatibility(
        mol.word.WdCompatibility type);

    @VTID(74)
    void compatibility(
        mol.word.WdCompatibility type,
        boolean prop);

    @VTID(75)
    mol.word.StoryRanges storyRanges();

    @VTID(75)
    @ReturnValue(defaultPropertyThrough={mol.word.StoryRanges.class})
    mol.word.Range storyRanges(
        mol.word.WdStoryType index);

    @VTID(76)
    mol.office._CommandBars commandBars();

    @VTID(77)
    boolean isSubdocument();

    @VTID(78)
    int saveFormat();

    @VTID(79)
    mol.word.WdProtectionType protectionType();

    @VTID(80)
    mol.word.Hyperlinks hyperlinks();

    @VTID(80)
    @ReturnValue(defaultPropertyThrough={mol.word.Hyperlinks.class})
    mol.word.Hyperlink hyperlinks(
        java.lang.Object index);

    @VTID(81)
    mol.word.Shapes shapes();

    @VTID(81)
    @ReturnValue(defaultPropertyThrough={mol.word.Shapes.class})
    mol.word.Shape shapes(
        java.lang.Object index);

    @VTID(82)
    mol.word.ListTemplates listTemplates();

    @VTID(82)
    @ReturnValue(defaultPropertyThrough={mol.word.ListTemplates.class})
    mol.word.ListTemplate listTemplates(
        java.lang.Object index);

    @VTID(83)
    mol.word.Lists lists();

    @VTID(83)
    @ReturnValue(defaultPropertyThrough={mol.word.Lists.class})
    mol.word.List lists(
        int index);

    @VTID(84)
    boolean updateStylesOnOpen();

    @VTID(85)
    void updateStylesOnOpen(
        boolean prop);

    @VTID(86)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object attachedTemplate();

    @VTID(87)
    void attachedTemplate(
        java.lang.Object prop);

    @VTID(88)
    mol.word.InlineShapes inlineShapes();

    @VTID(88)
    @ReturnValue(defaultPropertyThrough={mol.word.InlineShapes.class})
    mol.word.InlineShape inlineShapes(
        int index);

    @VTID(89)
    mol.word.Shape background();

    @VTID(90)
    void background(
        mol.word.Shape prop);

    @VTID(91)
    boolean grammarChecked();

    @VTID(92)
    void grammarChecked(
        boolean prop);

    @VTID(93)
    boolean spellingChecked();

    @VTID(94)
    void spellingChecked(
        boolean prop);

    @VTID(95)
    boolean showGrammaticalErrors();

    @VTID(96)
    void showGrammaticalErrors(
        boolean prop);

    @VTID(97)
    boolean showSpellingErrors();

    @VTID(98)
    void showSpellingErrors(
        boolean prop);

    @VTID(99)
    mol.word.Versions versions();

    @VTID(99)
    @ReturnValue(defaultPropertyThrough={mol.word.Versions.class})
    mol.word.Version versions(
        int index);

    @VTID(100)
    boolean showSummary();

    @VTID(101)
    void showSummary(
        boolean prop);

    @VTID(102)
    mol.word.WdSummaryMode summaryViewMode();

    @VTID(103)
    void summaryViewMode(
        mol.word.WdSummaryMode prop);

    @VTID(104)
    int summaryLength();

    @VTID(105)
    void summaryLength(
        int prop);

    @VTID(106)
    boolean printFractionalWidths();

    @VTID(107)
    void printFractionalWidths(
        boolean prop);

    @VTID(108)
    boolean printPostScriptOverText();

    @VTID(109)
    void printPostScriptOverText(
        boolean prop);

    @VTID(110)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject container();

    @VTID(111)
    boolean printFormsData();

    @VTID(112)
    void printFormsData(
        boolean prop);

    @VTID(113)
    mol.word.ListParagraphs listParagraphs();

    @VTID(113)
    @ReturnValue(defaultPropertyThrough={mol.word.ListParagraphs.class})
    mol.word.Paragraph listParagraphs(
        int index);

    @VTID(114)
    void password(
        java.lang.String rhs);

    @VTID(115)
    void writePassword(
        java.lang.String rhs);

    @VTID(116)
    boolean hasPassword();

    @VTID(117)
    boolean writeReserved();

    @VTID(118)
    java.lang.String activeWritingStyle(
        java.lang.Object languageID);

    @VTID(119)
    void activeWritingStyle(
        java.lang.Object languageID,
        java.lang.String prop);

    @VTID(120)
    boolean userControl();

    @VTID(121)
    void userControl(
        boolean prop);

    @VTID(122)
    boolean hasMailer();

    @VTID(123)
    void hasMailer(
        boolean prop);

    @VTID(124)
    mol.word.Mailer mailer();

    @VTID(125)
    mol.word.ReadabilityStatistics readabilityStatistics();

    @VTID(125)
    @ReturnValue(defaultPropertyThrough={mol.word.ReadabilityStatistics.class})
    mol.word.ReadabilityStatistic readabilityStatistics(
        java.lang.Object index);

    @VTID(126)
    mol.word.ProofreadingErrors grammaticalErrors();

    @VTID(126)
    @ReturnValue(defaultPropertyThrough={mol.word.ProofreadingErrors.class})
    mol.word.Range grammaticalErrors(
        int index);

    @VTID(127)
    mol.word.ProofreadingErrors spellingErrors();

    @VTID(127)
    @ReturnValue(defaultPropertyThrough={mol.word.ProofreadingErrors.class})
    mol.word.Range spellingErrors(
        int index);

    @VTID(128)
    mol.vba._VBProject vbProject();

    @VTID(129)
    boolean formsDesign();

    @VTID(130)
    java.lang.String _CodeName();

    @VTID(131)
    void _CodeName(
        java.lang.String prop);

    @VTID(132)
    java.lang.String codeName();

    @VTID(133)
    boolean snapToGrid();

    @VTID(134)
    void snapToGrid(
        boolean prop);

    @VTID(135)
    boolean snapToShapes();

    @VTID(136)
    void snapToShapes(
        boolean prop);

    @VTID(137)
    float gridDistanceHorizontal();

    @VTID(138)
    void gridDistanceHorizontal(
        float prop);

    @VTID(139)
    float gridDistanceVertical();

    @VTID(140)
    void gridDistanceVertical(
        float prop);

    @VTID(141)
    float gridOriginHorizontal();

    @VTID(142)
    void gridOriginHorizontal(
        float prop);

    @VTID(143)
    float gridOriginVertical();

    @VTID(144)
    void gridOriginVertical(
        float prop);

    @VTID(145)
    int gridSpaceBetweenHorizontalLines();

    @VTID(146)
    void gridSpaceBetweenHorizontalLines(
        int prop);

    @VTID(147)
    int gridSpaceBetweenVerticalLines();

    @VTID(148)
    void gridSpaceBetweenVerticalLines(
        int prop);

    @VTID(149)
    boolean gridOriginFromMargin();

    @VTID(150)
    void gridOriginFromMargin(
        boolean prop);

    @VTID(151)
    boolean kerningByAlgorithm();

    @VTID(152)
    void kerningByAlgorithm(
        boolean prop);

    @VTID(153)
    mol.word.WdJustificationMode justificationMode();

    @VTID(154)
    void justificationMode(
        mol.word.WdJustificationMode prop);

    @VTID(155)
    mol.word.WdFarEastLineBreakLevel farEastLineBreakLevel();

    @VTID(156)
    void farEastLineBreakLevel(
        mol.word.WdFarEastLineBreakLevel prop);

    @VTID(157)
    java.lang.String noLineBreakBefore();

    @VTID(158)
    void noLineBreakBefore(
        java.lang.String prop);

    @VTID(159)
    java.lang.String noLineBreakAfter();

    @VTID(160)
    void noLineBreakAfter(
        java.lang.String prop);

    @VTID(161)
    boolean trackRevisions();

    @VTID(162)
    void trackRevisions(
        boolean prop);

    @VTID(163)
    boolean printRevisions();

    @VTID(164)
    void printRevisions(
        boolean prop);

    @VTID(165)
    boolean showRevisions();

    @VTID(166)
    void showRevisions(
        boolean prop);

    @VTID(167)
    void close(
        java.lang.Object saveChanges,
        java.lang.Object originalFormat,
        java.lang.Object routeDocument);

    @VTID(168)
    void saveAs2000(
        java.lang.Object fileName,
        java.lang.Object fileFormat,
        java.lang.Object lockComments,
        java.lang.Object password,
        java.lang.Object addToRecentFiles,
        java.lang.Object writePassword,
        java.lang.Object readOnlyRecommended,
        java.lang.Object embedTrueTypeFonts,
        java.lang.Object saveNativePictureFormat,
        java.lang.Object saveFormsData,
        java.lang.Object saveAsAOCELetter);

    @VTID(169)
    void repaginate();

    @VTID(170)
    void fitToPages();

    @VTID(171)
    void manualHyphenation();

    @VTID(172)
    void select();

    @VTID(173)
    void dataForm();

    @VTID(174)
    void route();

    @VTID(175)
    void save();

    @VTID(176)
    void printOutOld(
        java.lang.Object background,
        java.lang.Object append,
        java.lang.Object range,
        java.lang.Object outputFileName,
        java.lang.Object from,
        java.lang.Object to,
        java.lang.Object item,
        java.lang.Object copies,
        java.lang.Object pages,
        java.lang.Object pageType,
        java.lang.Object printToFile,
        java.lang.Object collate,
        java.lang.Object activePrinterMacGX,
        java.lang.Object manualDuplexPrint);

    @VTID(177)
    void sendMail();

    @VTID(178)
    mol.word.Range range(
        java.lang.Object start,
        java.lang.Object end);

    @VTID(179)
    void runAutoMacro(
        mol.word.WdAutoMacros which);

    @VTID(180)
    void activate();

    @VTID(181)
    void printPreview();

    @VTID(182)
    mol.word.Range goTo(
        java.lang.Object what,
        java.lang.Object which,
        java.lang.Object count,
        java.lang.Object name);

    @VTID(183)
    boolean undo(
        java.lang.Object times);

    @VTID(184)
    boolean redo(
        java.lang.Object times);

    @VTID(185)
    int computeStatistics(
        mol.word.WdStatistic statistic,
        java.lang.Object includeFootnotesAndEndnotes);

    @VTID(186)
    void makeCompatibilityDefault();

    @VTID(187)
    void protect2002(
        mol.word.WdProtectionType type,
        java.lang.Object noReset,
        java.lang.Object password);

    @VTID(188)
    void unprotect(
        java.lang.Object password);

    @VTID(189)
    void editionOptions(
        mol.word.WdEditionType type,
        mol.word.WdEditionOption option,
        java.lang.String name,
        java.lang.Object format);

    @VTID(190)
    void runLetterWizard(
        java.lang.Object letterContent,
        java.lang.Object wizardMode);

    @VTID(191)
    mol.word._LetterContent getLetterContent();

    @VTID(192)
    void setLetterContent(
        java.lang.Object letterContent);

    @VTID(193)
    void copyStylesFromTemplate(
        java.lang.String template);

    @VTID(194)
    void updateStyles();

    @VTID(195)
    void checkGrammar();

    @VTID(196)
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

    @VTID(197)
    void followHyperlink(
        java.lang.Object address,
        java.lang.Object subAddress,
        java.lang.Object newWindow,
        java.lang.Object addHistory,
        java.lang.Object extraInfo,
        java.lang.Object method,
        java.lang.Object headerInfo);

    @VTID(198)
    void addToFavorites();

    @VTID(199)
    void reload();

    @VTID(200)
    mol.word.Range autoSummarize(
        java.lang.Object length,
        java.lang.Object mode,
        java.lang.Object updateProperties);

    @VTID(201)
    void removeNumbers(
        java.lang.Object numberType);

    @VTID(202)
    void convertNumbersToText(
        java.lang.Object numberType);

    @VTID(203)
    int countNumberedItems(
        java.lang.Object numberType,
        java.lang.Object level);

    @VTID(204)
    void post();

    @VTID(205)
    void toggleFormsDesign();

    @VTID(206)
    void compare2000(
        java.lang.String name);

    @VTID(207)
    void updateSummaryProperties();

    @VTID(208)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object getCrossReferenceItems(
        java.lang.Object referenceType);

    @VTID(209)
    void autoFormat();

    @VTID(210)
    void viewCode();

    @VTID(211)
    void viewPropertyBrowser();

    @VTID(212)
    void forwardMailer();

    @VTID(213)
    void reply();

    @VTID(214)
    void replyAll();

    @VTID(215)
    void sendMailer(
        java.lang.Object fileFormat,
        java.lang.Object priority);

    @VTID(216)
    void undoClear();

    @VTID(217)
    void presentIt();

    @VTID(218)
    void sendFax(
        java.lang.String address,
        java.lang.Object subject);

    @VTID(219)
    void merge2000(
        java.lang.String fileName);

    @VTID(220)
    void closePrintPreview();

    @VTID(221)
    void checkConsistency();

    @VTID(222)
    mol.word._LetterContent createLetterContent(
        java.lang.String dateFormat,
        boolean includeHeaderFooter,
        java.lang.String pageDesign,
        mol.word.WdLetterStyle letterStyle,
        boolean letterhead,
        mol.word.WdLetterheadLocation letterheadLocation,
        float letterheadSize,
        java.lang.String recipientName,
        java.lang.String recipientAddress,
        java.lang.String salutation,
        mol.word.WdSalutationType salutationType,
        java.lang.String recipientReference,
        java.lang.String mailingInstructions,
        java.lang.String attentionLine,
        java.lang.String subject,
        java.lang.String ccList,
        java.lang.String returnAddress,
        java.lang.String senderName,
        java.lang.String closing,
        java.lang.String senderCompany,
        java.lang.String senderJobTitle,
        java.lang.String senderInitials,
        int enclosureNumber,
        java.lang.Object infoBlock,
        java.lang.Object recipientCode,
        java.lang.Object recipientGender,
        java.lang.Object returnAddressShortForm,
        java.lang.Object senderCity,
        java.lang.Object senderCode,
        java.lang.Object senderGender,
        java.lang.Object senderReference);

    @VTID(223)
    void acceptAllRevisions();

    @VTID(224)
    void rejectAllRevisions();

    @VTID(225)
    void detectLanguage();

    @VTID(226)
    void applyTheme(
        java.lang.String name);

    @VTID(227)
    void removeTheme();

    @VTID(228)
    void webPagePreview();

    @VTID(229)
    void reloadAs(
        mol.office.MsoEncoding encoding);

    @VTID(230)
    java.lang.String activeTheme();

    @VTID(231)
    java.lang.String activeThemeDisplayName();

    @VTID(232)
    mol.word.Email email();

    @VTID(233)
    mol.office.Scripts scripts();

    @VTID(233)
    @ReturnValue(defaultPropertyThrough={mol.office.Scripts.class})
    mol.office.Script scripts(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(234)
    boolean languageDetected();

    @VTID(235)
    void languageDetected(
        boolean prop);

    @VTID(236)
    mol.word.WdFarEastLineBreakLanguageID farEastLineBreakLanguage();

    @VTID(237)
    void farEastLineBreakLanguage(
        mol.word.WdFarEastLineBreakLanguageID prop);

    @VTID(238)
    mol.word.Frameset frameset();

    @VTID(239)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object clickAndTypeParagraphStyle();

    @VTID(240)
    void clickAndTypeParagraphStyle(
        java.lang.Object prop);

    @VTID(241)
    mol.office.HTMLProject htmlProject();

    @VTID(242)
    mol.word.WebOptions webOptions();

    @VTID(243)
    mol.office.MsoEncoding openEncoding();

    @VTID(244)
    mol.office.MsoEncoding saveEncoding();

    @VTID(245)
    void saveEncoding(
        mol.office.MsoEncoding prop);

    @VTID(246)
    boolean optimizeForWord97();

    @VTID(247)
    void optimizeForWord97(
        boolean prop);

    @VTID(248)
    boolean vbaSigned();

    @VTID(249)
    void printOut2000(
        java.lang.Object background,
        java.lang.Object append,
        java.lang.Object range,
        java.lang.Object outputFileName,
        java.lang.Object from,
        java.lang.Object to,
        java.lang.Object item,
        java.lang.Object copies,
        java.lang.Object pages,
        java.lang.Object pageType,
        java.lang.Object printToFile,
        java.lang.Object collate,
        java.lang.Object activePrinterMacGX,
        java.lang.Object manualDuplexPrint,
        java.lang.Object printZoomColumn,
        java.lang.Object printZoomRow,
        java.lang.Object printZoomPaperWidth,
        java.lang.Object printZoomPaperHeight);

    @VTID(250)
    void sblt(
        java.lang.String s);

    @VTID(251)
    void convertVietDoc(
        int codePageOrigin);

    @VTID(252)
    void printOut(
        java.lang.Object background,
        java.lang.Object append,
        java.lang.Object range,
        java.lang.Object outputFileName,
        java.lang.Object from,
        java.lang.Object to,
        java.lang.Object item,
        java.lang.Object copies,
        java.lang.Object pages,
        java.lang.Object pageType,
        java.lang.Object printToFile,
        java.lang.Object collate,
        java.lang.Object activePrinterMacGX,
        java.lang.Object manualDuplexPrint,
        java.lang.Object printZoomColumn,
        java.lang.Object printZoomRow,
        java.lang.Object printZoomPaperWidth,
        java.lang.Object printZoomPaperHeight);

    @VTID(253)
    mol.office.IMsoEnvelopeVB mailEnvelope();

    @VTID(254)
    boolean disableFeatures();

    @VTID(255)
    void disableFeatures(
        boolean prop);

    @VTID(256)
    boolean doNotEmbedSystemFonts();

    @VTID(257)
    void doNotEmbedSystemFonts(
        boolean prop);

    @VTID(258)
    mol.office.SignatureSet signatures();

    @VTID(258)
    @ReturnValue(defaultPropertyThrough={mol.office.SignatureSet.class})
    mol.office.Signature signatures(
        int iSig);

    @VTID(259)
    java.lang.String defaultTargetFrame();

    @VTID(260)
    void defaultTargetFrame(
        java.lang.String prop);

    @VTID(261)
    mol.word.HTMLDivisions htmlDivisions();

    @VTID(261)
    @ReturnValue(defaultPropertyThrough={mol.word.HTMLDivisions.class})
    mol.word.HTMLDivision htmlDivisions(
        int index);

    @VTID(262)
    mol.word.WdDisableFeaturesIntroducedAfter disableFeaturesIntroducedAfter();

    @VTID(263)
    void disableFeaturesIntroducedAfter(
        mol.word.WdDisableFeaturesIntroducedAfter prop);

    @VTID(264)
    boolean removePersonalInformation();

    @VTID(265)
    void removePersonalInformation(
        boolean prop);

    @VTID(266)
    mol.word.SmartTags smartTags();

    @VTID(266)
    @ReturnValue(defaultPropertyThrough={mol.word.SmartTags.class})
    mol.word.SmartTag smartTags(
        java.lang.Object index);

    @VTID(267)
    void compare2002(
        java.lang.String name,
        java.lang.Object authorName,
        java.lang.Object compareTarget,
        java.lang.Object detectFormatChanges,
        java.lang.Object ignoreAllComparisonWarnings,
        java.lang.Object addToRecentFiles);

    @VTID(268)
    void checkIn(
        boolean saveChanges,
        java.lang.Object comments,
        boolean makePublic);

    @VTID(269)
    boolean canCheckin();

    @VTID(270)
    void merge(
        java.lang.String fileName,
        java.lang.Object mergeTarget,
        java.lang.Object detectFormatChanges,
        java.lang.Object useFormattingFrom,
        java.lang.Object addToRecentFiles);

    @VTID(271)
    boolean embedSmartTags();

    @VTID(272)
    void embedSmartTags(
        boolean prop);

    @VTID(273)
    boolean smartTagsAsXMLProps();

    @VTID(274)
    void smartTagsAsXMLProps(
        boolean prop);

    @VTID(275)
    mol.office.MsoEncoding textEncoding();

    @VTID(276)
    void textEncoding(
        mol.office.MsoEncoding prop);

    @VTID(277)
    mol.word.WdLineEndingType textLineEnding();

    @VTID(278)
    void textLineEnding(
        mol.word.WdLineEndingType prop);

    @VTID(279)
    void sendForReview(
        java.lang.Object recipients,
        java.lang.Object subject,
        java.lang.Object showMessage,
        java.lang.Object includeAttachment);

    @VTID(280)
    void replyWithChanges(
        java.lang.Object showMessage);

    @VTID(281)
    void endReview();

    @VTID(282)
    mol.word.StyleSheets styleSheets();

    @VTID(282)
    @ReturnValue(defaultPropertyThrough={mol.word.StyleSheets.class})
    mol.word.StyleSheet styleSheets(
        java.lang.Object index);

    @VTID(283)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object defaultTableStyle();

    @VTID(284)
    java.lang.String passwordEncryptionProvider();

    @VTID(285)
    java.lang.String passwordEncryptionAlgorithm();

    @VTID(286)
    int passwordEncryptionKeyLength();

    @VTID(287)
    boolean passwordEncryptionFileProperties();

    @VTID(288)
    void setPasswordEncryptionOptions(
        java.lang.String passwordEncryptionProvider,
        java.lang.String passwordEncryptionAlgorithm,
        int passwordEncryptionKeyLength,
        java.lang.Object passwordEncryptionFileProperties);

    @VTID(289)
    void recheckSmartTags();

    @VTID(290)
    void removeSmartTags();

    @VTID(291)
    void setDefaultTableStyle(
        java.lang.Object style,
        boolean setInTemplate);

    @VTID(292)
    void deleteAllComments();

    @VTID(293)
    void acceptAllRevisionsShown();

    @VTID(294)
    void rejectAllRevisionsShown();

    @VTID(295)
    void deleteAllCommentsShown();

    @VTID(296)
    void resetFormFields();

    @VTID(297)
    void saveAs(
        java.lang.Object fileName,
        java.lang.Object fileFormat,
        java.lang.Object lockComments,
        java.lang.Object password,
        java.lang.Object addToRecentFiles,
        java.lang.Object writePassword,
        java.lang.Object readOnlyRecommended,
        java.lang.Object embedTrueTypeFonts,
        java.lang.Object saveNativePictureFormat,
        java.lang.Object saveFormsData,
        java.lang.Object saveAsAOCELetter,
        java.lang.Object encoding,
        java.lang.Object insertLineBreaks,
        java.lang.Object allowSubstitutions,
        java.lang.Object lineEnding,
        java.lang.Object addBiDiMarks);

    @VTID(298)
    boolean embedLinguisticData();

    @VTID(299)
    void embedLinguisticData(
        boolean prop);

    @VTID(300)
    boolean formattingShowFont();

    @VTID(301)
    void formattingShowFont(
        boolean prop);

    @VTID(302)
    boolean formattingShowClear();

    @VTID(303)
    void formattingShowClear(
        boolean prop);

    @VTID(304)
    boolean formattingShowParagraph();

    @VTID(305)
    void formattingShowParagraph(
        boolean prop);

    @VTID(306)
    boolean formattingShowNumbering();

    @VTID(307)
    void formattingShowNumbering(
        boolean prop);

    @VTID(308)
    mol.word.WdShowFilter formattingShowFilter();

    @VTID(309)
    void formattingShowFilter(
        mol.word.WdShowFilter prop);

    @VTID(310)
    void checkNewSmartTags();

    @VTID(311)
    mol.office.Permission permission();

    @VTID(311)
    @ReturnValue(defaultPropertyThrough={mol.office.Permission.class})
    mol.office.UserPermission permission(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(312)
    mol.word.XMLNodes xmlNodes();

    @VTID(312)
    @ReturnValue(defaultPropertyThrough={mol.word.XMLNodes.class})
    mol.word.XMLNode xmlNodes(
        int index);

    @VTID(313)
    mol.word.XMLSchemaReferences xmlSchemaReferences();

    @VTID(313)
    @ReturnValue(defaultPropertyThrough={mol.word.XMLSchemaReferences.class})
    mol.word.XMLSchemaReference xmlSchemaReferences(
        java.lang.Object index);

    @VTID(314)
    mol.office.SmartDocument smartDocument();

    @VTID(315)
    mol.office.SharedWorkspace sharedWorkspace();

    @VTID(316)
    mol.office.Sync sync();

    @VTID(317)
    boolean enforceStyle();

    @VTID(318)
    void enforceStyle(
        boolean prop);

    @VTID(319)
    boolean autoFormatOverride();

    @VTID(320)
    void autoFormatOverride(
        boolean prop);

    @VTID(321)
    boolean xmlSaveDataOnly();

    @VTID(322)
    void xmlSaveDataOnly(
        boolean prop);

    @VTID(323)
    boolean xmlHideNamespaces();

    @VTID(324)
    void xmlHideNamespaces(
        boolean prop);

    @VTID(325)
    boolean xmlShowAdvancedErrors();

    @VTID(326)
    void xmlShowAdvancedErrors(
        boolean prop);

    @VTID(327)
    boolean xmlUseXSLTWhenSaving();

    @VTID(328)
    void xmlUseXSLTWhenSaving(
        boolean prop);

    @VTID(329)
    java.lang.String xmlSaveThroughXSLT();

    @VTID(330)
    void xmlSaveThroughXSLT(
        java.lang.String prop);

    @VTID(331)
    mol.office.DocumentLibraryVersions documentLibraryVersions();

    @VTID(331)
    @ReturnValue(defaultPropertyThrough={mol.office.DocumentLibraryVersions.class})
    mol.office.DocumentLibraryVersion documentLibraryVersions(
        int lIndex);

    @VTID(332)
    boolean readingModeLayoutFrozen();

    @VTID(333)
    void readingModeLayoutFrozen(
        boolean prop);

    @VTID(334)
    boolean removeDateAndTime();

    @VTID(335)
    void removeDateAndTime(
        boolean prop);

    @VTID(336)
    void sendFaxOverInternet(
        java.lang.Object recipients,
        java.lang.Object subject,
        java.lang.Object showMessage);

    @VTID(337)
    void transformDocument(
        java.lang.String path,
        boolean dataOnly);

    @VTID(338)
    void protect(
        mol.word.WdProtectionType type,
        java.lang.Object noReset,
        java.lang.Object password,
        java.lang.Object useIRM,
        java.lang.Object enforceStyleLock);

    @VTID(339)
    void selectAllEditableRanges(
        java.lang.Object editorID);

    @VTID(340)
    void deleteAllEditableRanges(
        java.lang.Object editorID);

    @VTID(341)
    void deleteAllInkAnnotations();

    @VTID(342)
    void addDocumentWorkspaceHeader(
        boolean richFormat,
        java.lang.String url,
        java.lang.String title,
        java.lang.String description,
        java.lang.String id);

    @VTID(343)
    void removeDocumentWorkspaceHeader(
        java.lang.String id);

    @VTID(344)
    void compare(
        java.lang.String name,
        java.lang.Object authorName,
        java.lang.Object compareTarget,
        java.lang.Object detectFormatChanges,
        java.lang.Object ignoreAllComparisonWarnings,
        java.lang.Object addToRecentFiles,
        java.lang.Object removePersonalInformation,
        java.lang.Object removeDateAndTime);

    @VTID(345)
    void removeLockedStyles();

    @VTID(346)
    mol.word.XMLChildNodeSuggestions childNodeSuggestions();

    @VTID(346)
    @ReturnValue(defaultPropertyThrough={mol.word.XMLChildNodeSuggestions.class})
    mol.word.XMLChildNodeSuggestion childNodeSuggestions(
        java.lang.Object index);

    @VTID(347)
    mol.word.XMLNode selectSingleNode(
        java.lang.String xPath,
        java.lang.String prefixMapping,
        boolean fastSearchSkippingTextNodes);

    @VTID(348)
    mol.word.XMLNodes selectNodes(
        java.lang.String xPath,
        java.lang.String prefixMapping,
        boolean fastSearchSkippingTextNodes);

    @VTID(349)
    mol.word.XMLNodes xmlSchemaViolations();

    @VTID(349)
    @ReturnValue(defaultPropertyThrough={mol.word.XMLNodes.class})
    mol.word.XMLNode xmlSchemaViolations(
        int index);

    @VTID(350)
    int readingLayoutSizeX();

    @VTID(351)
    void readingLayoutSizeX(
        int prop);

    @VTID(352)
    int readingLayoutSizeY();

    @VTID(353)
    void readingLayoutSizeY(
        int prop);

    @VTID(354)
    mol.word.WdStyleSort styleSortMethod();

    @VTID(355)
    void styleSortMethod(
        mol.word.WdStyleSort prop);

    @VTID(356)
    mol.office.MetaProperties contentTypeProperties();

    @VTID(356)
    @ReturnValue(defaultPropertyThrough={mol.office.MetaProperties.class})
    mol.office.MetaProperty contentTypeProperties(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(357)
    boolean trackMoves();

    @VTID(358)
    void trackMoves(
        boolean prop);

    @VTID(359)
    boolean trackFormatting();

    @VTID(360)
    void trackFormatting(
        boolean prop);

    @VTID(361)
    void dummy1();

    @VTID(362)
    mol.word.OMaths oMaths();

    @VTID(362)
    @ReturnValue(defaultPropertyThrough={mol.word.OMaths.class})
    mol.word.OMath oMaths(
        int index);

    @VTID(363)
    void removeDocumentInformation(
        mol.word.WdRemoveDocInfoType removeDocInfoType);

    @VTID(364)
    void checkInWithVersion(
        boolean saveChanges,
        java.lang.Object comments,
        boolean makePublic,
        java.lang.Object versionType);

    @VTID(365)
    void dummy2();

    @VTID(366)
    void dummy3();

    @VTID(367)
    mol.office.ServerPolicy serverPolicy();

    @VTID(367)
    @ReturnValue(defaultPropertyThrough={mol.office.ServerPolicy.class})
    mol.office.PolicyItem serverPolicy(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(368)
    mol.word.ContentControls contentControls();

    @VTID(368)
    @ReturnValue(defaultPropertyThrough={mol.word.ContentControls.class})
    mol.word.ContentControl contentControls(
        java.lang.Object index);

    @VTID(369)
    mol.office.DocumentInspectors documentInspectors();

    @VTID(369)
    @ReturnValue(defaultPropertyThrough={mol.office.DocumentInspectors.class})
    mol.office.DocumentInspector documentInspectors(
        int index);

    @VTID(370)
    void lockServerFile();

    @VTID(371)
    mol.office.WorkflowTasks getWorkflowTasks();

    @VTID(371)
    @ReturnValue(defaultPropertyThrough={mol.office.WorkflowTasks.class})
    mol.office.WorkflowTask getWorkflowTasks(
        int index);

    @VTID(372)
    mol.office.WorkflowTemplates getWorkflowTemplates();

    @VTID(372)
    @ReturnValue(defaultPropertyThrough={mol.office.WorkflowTemplates.class})
    mol.office.WorkflowTemplate getWorkflowTemplates(
        int index);

    @VTID(373)
    void dummy4();

    @VTID(374)
    void addMeetingWorkspaceHeader(
        boolean skipIfAbsent,
        java.lang.String url,
        java.lang.String title,
        java.lang.String description,
        java.lang.String id);

    @VTID(375)
    mol.word.Bibliography bibliography();

    @VTID(376)
    boolean lockTheme();

    @VTID(377)
    void lockTheme(
        boolean prop);

    @VTID(378)
    boolean lockQuickStyleSet();

    @VTID(379)
    void lockQuickStyleSet(
        boolean prop);

    @VTID(380)
    java.lang.String originalDocumentTitle();

    @VTID(381)
    java.lang.String revisedDocumentTitle();

    @VTID(382)
    mol.office._CustomXMLParts customXMLParts();

    @VTID(383)
    boolean formattingShowNextLevel();

    @VTID(384)
    void formattingShowNextLevel(
        boolean prop);

    @VTID(385)
    boolean formattingShowUserStyleName();

    @VTID(386)
    void formattingShowUserStyleName(
        boolean prop);

    @VTID(387)
    void saveAsQuickStyleSet(
        java.lang.String fileName);

    @VTID(388)
    void applyQuickStyleSet(
        java.lang.String name);

    @VTID(389)
    mol.word.Research research();

    @VTID(390)
    boolean _final();

    @VTID(391)
    void _final(
        boolean prop);

    @VTID(392)
    mol.word.WdOMathBreakBin oMathBreakBin();

    @VTID(393)
    void oMathBreakBin(
        mol.word.WdOMathBreakBin prop);

    @VTID(394)
    mol.word.WdOMathBreakSub oMathBreakSub();

    @VTID(395)
    void oMathBreakSub(
        mol.word.WdOMathBreakSub prop);

    @VTID(396)
    mol.word.WdOMathJc oMathJc();

    @VTID(397)
    void oMathJc(
        mol.word.WdOMathJc prop);

    @VTID(398)
    float oMathLeftMargin();

    @VTID(399)
    void oMathLeftMargin(
        float prop);

    @VTID(400)
    float oMathRightMargin();

    @VTID(401)
    void oMathRightMargin(
        float prop);

    @VTID(402)
    float oMathWrap();

    @VTID(403)
    void oMathWrap(
        float prop);

    @VTID(404)
    boolean oMathIntSubSupLim();

    @VTID(405)
    void oMathIntSubSupLim(
        boolean prop);

    @VTID(406)
    boolean oMathNarySupSubLim();

    @VTID(407)
    void oMathNarySupSubLim(
        boolean prop);

    @VTID(408)
    boolean oMathSmallFrac();

    @VTID(409)
    void oMathSmallFrac(
        boolean prop);

    @VTID(410)
    java.lang.String wordOpenXML();

    @VTID(411)
    mol.office.OfficeTheme documentTheme();

    @VTID(412)
    void applyDocumentTheme(
        java.lang.String fileName);

    @VTID(413)
    boolean hasVBProject();

    @VTID(414)
    mol.word.ContentControls selectLinkedControls(
        mol.office.CustomXMLNode node);

    @VTID(415)
    mol.word.ContentControls selectUnlinkedControls(
        mol.office._CustomXMLPart stream);

    @VTID(416)
    mol.word.ContentControls selectContentControlsByTitle(
        java.lang.String title);

    @VTID(417)
    void exportAsFixedFormat(
        java.lang.String outputFileName,
        mol.word.WdExportFormat exportFormat,
        boolean openAfterExport,
        mol.word.WdExportOptimizeFor optimizeFor,
        mol.word.WdExportRange range,
        int from,
        int to,
        mol.word.WdExportItem item,
        boolean includeDocProps,
        boolean keepIRM,
        mol.word.WdExportCreateBookmarks createBookmarks,
        boolean docStructureTags,
        boolean bitmapMissingFonts,
        boolean useISO19005_1,
        java.lang.Object fixedFormatExtClassPtr);

    @VTID(418)
    void freezeLayout();

    @VTID(419)
    void unfreezeLayout();

    @VTID(420)
    java.lang.String oMathFontName();

    @VTID(421)
    void oMathFontName(
        java.lang.String prop);

    @VTID(422)
    void downgradeDocument();

    @VTID(423)
    java.lang.String encryptionProvider();

    @VTID(424)
    void encryptionProvider(
        java.lang.String prop);

    @VTID(425)
    boolean useMathDefaults();

    @VTID(426)
    void useMathDefaults(
        boolean prop);

    @VTID(427)
    int currentRsid();

    @VTID(428)
    void convert();

    @VTID(429)
    mol.word.ContentControls selectContentControlsByTag(
        java.lang.String tag);

}
