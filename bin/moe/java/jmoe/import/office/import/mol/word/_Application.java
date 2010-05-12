package mol.word  ;

import com4j.*;

@IID("{00020970-0000-0000-C000-000000000046}")
public interface _Application extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @DefaultMethod
    java.lang.String name();

    @VTID(11)
    mol.word.Documents documents();

    @VTID(11)
    @ReturnValue(defaultPropertyThrough={mol.word.Documents.class})
    mol.word._Document documents(
        java.lang.Object index);

    @VTID(12)
    mol.word.Windows windows();

    @VTID(12)
    @ReturnValue(defaultPropertyThrough={mol.word.Windows.class})
    mol.word.Window windows(
        java.lang.Object index);

    @VTID(13)
    mol.word._Document activeDocument();

    @VTID(14)
    mol.word.Window activeWindow();

    @VTID(15)
    mol.word.Selection selection();

    @VTID(16)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject wordBasic();

    @VTID(17)
    mol.word.RecentFiles recentFiles();

    @VTID(17)
    @ReturnValue(defaultPropertyThrough={mol.word.RecentFiles.class})
    mol.word.RecentFile recentFiles(
        int index);

    @VTID(18)
    mol.word.Template normalTemplate();

    @VTID(19)
    mol.word.System system();

    @VTID(20)
    mol.word.AutoCorrect autoCorrect();

    @VTID(21)
    mol.word.FontNames fontNames();

    @VTID(21)
    @ReturnValue(defaultPropertyThrough={mol.word.FontNames.class})
    java.lang.String fontNames(
        int index);

    @VTID(22)
    mol.word.FontNames landscapeFontNames();

    @VTID(22)
    @ReturnValue(defaultPropertyThrough={mol.word.FontNames.class})
    java.lang.String landscapeFontNames(
        int index);

    @VTID(23)
    mol.word.FontNames portraitFontNames();

    @VTID(23)
    @ReturnValue(defaultPropertyThrough={mol.word.FontNames.class})
    java.lang.String portraitFontNames(
        int index);

    @VTID(24)
    mol.word.Languages languages();

    @VTID(24)
    @ReturnValue(defaultPropertyThrough={mol.word.Languages.class})
    mol.word.Language languages(
        java.lang.Object index);

    @VTID(25)
    mol.office.Assistant assistant();

    @VTID(26)
    mol.word.Browser browser();

    @VTID(27)
    mol.word.FileConverters fileConverters();

    @VTID(27)
    @ReturnValue(defaultPropertyThrough={mol.word.FileConverters.class})
    mol.word.FileConverter fileConverters(
        java.lang.Object index);

    @VTID(28)
    mol.word.MailingLabel mailingLabel();

    @VTID(29)
    mol.word.Dialogs dialogs();

    @VTID(29)
    @ReturnValue(defaultPropertyThrough={mol.word.Dialogs.class})
    mol.word.Dialog dialogs(
        mol.word.WdWordDialog index);

    @VTID(30)
    mol.word.CaptionLabels captionLabels();

    @VTID(30)
    @ReturnValue(defaultPropertyThrough={mol.word.CaptionLabels.class})
    mol.word.CaptionLabel captionLabels(
        java.lang.Object index);

    @VTID(31)
    mol.word.AutoCaptions autoCaptions();

    @VTID(31)
    @ReturnValue(defaultPropertyThrough={mol.word.AutoCaptions.class})
    mol.word.AutoCaption autoCaptions(
        java.lang.Object index);

    @VTID(32)
    mol.word.AddIns addIns();

    @VTID(32)
    @ReturnValue(defaultPropertyThrough={mol.word.AddIns.class})
    mol.word.AddIn addIns(
        java.lang.Object index);

    @VTID(33)
    boolean visible();

    @VTID(34)
    void visible(
        boolean prop);

    @VTID(35)
    java.lang.String version();

    @VTID(36)
    boolean screenUpdating();

    @VTID(37)
    void screenUpdating(
        boolean prop);

    @VTID(38)
    boolean printPreview();

    @VTID(39)
    void printPreview(
        boolean prop);

    @VTID(40)
    mol.word.Tasks tasks();

    @VTID(40)
    @ReturnValue(defaultPropertyThrough={mol.word.Tasks.class})
    mol.word.Task tasks(
        java.lang.Object index);

    @VTID(41)
    boolean displayStatusBar();

    @VTID(42)
    void displayStatusBar(
        boolean prop);

    @VTID(43)
    boolean specialMode();

    @VTID(44)
    int usableWidth();

    @VTID(45)
    int usableHeight();

    @VTID(46)
    boolean mathCoprocessorAvailable();

    @VTID(47)
    boolean mouseAvailable();

    @VTID(48)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object international(
        mol.word.WdInternationalIndex index);

    @VTID(49)
    java.lang.String build();

    @VTID(50)
    boolean capsLock();

    @VTID(51)
    boolean numLock();

    @VTID(52)
    java.lang.String userName();

    @VTID(53)
    void userName(
        java.lang.String prop);

    @VTID(54)
    java.lang.String userInitials();

    @VTID(55)
    void userInitials(
        java.lang.String prop);

    @VTID(56)
    java.lang.String userAddress();

    @VTID(57)
    void userAddress(
        java.lang.String prop);

    @VTID(58)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject macroContainer();

    @VTID(59)
    boolean displayRecentFiles();

    @VTID(60)
    void displayRecentFiles(
        boolean prop);

    @VTID(61)
    mol.office._CommandBars commandBars();

    @VTID(62)
    mol.word.SynonymInfo synonymInfo(
        java.lang.String word,
        java.lang.Object languageID);

    @VTID(63)
    mol.vba.VBE vbe();

    @VTID(64)
    java.lang.String defaultSaveFormat();

    @VTID(65)
    void defaultSaveFormat(
        java.lang.String prop);

    @VTID(66)
    mol.word.ListGalleries listGalleries();

    @VTID(66)
    @ReturnValue(defaultPropertyThrough={mol.word.ListGalleries.class})
    mol.word.ListGallery listGalleries(
        mol.word.WdListGalleryType index);

    @VTID(67)
    java.lang.String activePrinter();

    @VTID(68)
    void activePrinter(
        java.lang.String prop);

    @VTID(69)
    mol.word.Templates templates();

    @VTID(69)
    @ReturnValue(defaultPropertyThrough={mol.word.Templates.class})
    mol.word.Template templates(
        java.lang.Object index);

    @VTID(70)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject customizationContext();

    @VTID(71)
    void customizationContext(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject prop);

    @VTID(72)
    mol.word.KeyBindings keyBindings();

    @VTID(72)
    @ReturnValue(defaultPropertyThrough={mol.word.KeyBindings.class})
    mol.word.KeyBinding keyBindings(
        int index);

    @VTID(73)
    mol.word.KeysBoundTo keysBoundTo(
        mol.word.WdKeyCategory keyCategory,
        java.lang.String command,
        java.lang.Object commandParameter);

    @VTID(74)
    mol.word.KeyBinding findKey(
        int keyCode,
        java.lang.Object keyCode2);

    @VTID(75)
    java.lang.String caption();

    @VTID(76)
    void caption(
        java.lang.String prop);

    @VTID(77)
    java.lang.String path();

    @VTID(78)
    boolean displayScrollBars();

    @VTID(79)
    void displayScrollBars(
        boolean prop);

    @VTID(80)
    java.lang.String startupPath();

    @VTID(81)
    void startupPath(
        java.lang.String prop);

    @VTID(82)
    int backgroundSavingStatus();

    @VTID(83)
    int backgroundPrintingStatus();

    @VTID(84)
    int left();

    @VTID(85)
    void left(
        int prop);

    @VTID(86)
    int top();

    @VTID(87)
    void top(
        int prop);

    @VTID(88)
    int width();

    @VTID(89)
    void width(
        int prop);

    @VTID(90)
    int height();

    @VTID(91)
    void height(
        int prop);

    @VTID(92)
    mol.word.WdWindowState windowState();

    @VTID(93)
    void windowState(
        mol.word.WdWindowState prop);

    @VTID(94)
    boolean displayAutoCompleteTips();

    @VTID(95)
    void displayAutoCompleteTips(
        boolean prop);

    @VTID(96)
    mol.word.Options options();

    @VTID(97)
    mol.word.WdAlertLevel displayAlerts();

    @VTID(98)
    void displayAlerts(
        mol.word.WdAlertLevel prop);

    @VTID(99)
    mol.word.Dictionaries customDictionaries();

    @VTID(99)
    @ReturnValue(defaultPropertyThrough={mol.word.Dictionaries.class})
    mol.word.Dictionary customDictionaries(
        java.lang.Object index);

    @VTID(100)
    java.lang.String pathSeparator();

    @VTID(101)
    void statusBar(
        java.lang.String rhs);

    @VTID(102)
    boolean mapiAvailable();

    @VTID(103)
    boolean displayScreenTips();

    @VTID(104)
    void displayScreenTips(
        boolean prop);

    @VTID(105)
    mol.word.WdEnableCancelKey enableCancelKey();

    @VTID(106)
    void enableCancelKey(
        mol.word.WdEnableCancelKey prop);

    @VTID(107)
    boolean userControl();

    @VTID(108)
    mol.office.FileSearch fileSearch();

    @VTID(109)
    mol.word.WdMailSystem mailSystem();

    @VTID(110)
    java.lang.String defaultTableSeparator();

    @VTID(111)
    void defaultTableSeparator(
        java.lang.String prop);

    @VTID(112)
    boolean showVisualBasicEditor();

    @VTID(113)
    void showVisualBasicEditor(
        boolean prop);

    @VTID(114)
    java.lang.String browseExtraFileTypes();

    @VTID(115)
    void browseExtraFileTypes(
        java.lang.String prop);

    @VTID(116)
    boolean isObjectValid(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject object);

    @VTID(117)
    mol.word.HangulHanjaConversionDictionaries hangulHanjaDictionaries();

    @VTID(117)
    @ReturnValue(defaultPropertyThrough={mol.word.HangulHanjaConversionDictionaries.class})
    mol.word.Dictionary hangulHanjaDictionaries(
        java.lang.Object index);

    @VTID(118)
    mol.word.MailMessage mailMessage();

    @VTID(119)
    boolean focusInMailHeader();

    @VTID(120)
    void quit(
        java.lang.Object saveChanges,
        java.lang.Object originalFormat,
        java.lang.Object routeDocument);

    @VTID(121)
    void screenRefresh();

    @VTID(122)
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
        java.lang.Object fileName,
        java.lang.Object activePrinterMacGX,
        java.lang.Object manualDuplexPrint);

    @VTID(123)
    void lookupNameProperties(
        java.lang.String name);

    @VTID(124)
    void substituteFont(
        java.lang.String unavailableFont,
        java.lang.String substituteFont);

    @VTID(125)
    boolean repeat(
        java.lang.Object times);

    @VTID(126)
    void ddeExecute(
        int channel,
        java.lang.String command);

    @VTID(127)
    int ddeInitiate(
        java.lang.String app,
        java.lang.String topic);

    @VTID(128)
    void ddePoke(
        int channel,
        java.lang.String item,
        java.lang.String data);

    @VTID(129)
    java.lang.String ddeRequest(
        int channel,
        java.lang.String item);

    @VTID(130)
    void ddeTerminate(
        int channel);

    @VTID(131)
    void ddeTerminateAll();

    @VTID(132)
    int buildKeyCode(
        mol.word.WdKey arg1,
        java.lang.Object arg2,
        java.lang.Object arg3,
        java.lang.Object arg4);

    @VTID(133)
    java.lang.String keyString(
        int keyCode,
        java.lang.Object keyCode2);

    @VTID(134)
    void organizerCopy(
        java.lang.String source,
        java.lang.String destination,
        java.lang.String name,
        mol.word.WdOrganizerObject object);

    @VTID(135)
    void organizerDelete(
        java.lang.String source,
        java.lang.String name,
        mol.word.WdOrganizerObject object);

    @VTID(136)
    void organizerRename(
        java.lang.String source,
        java.lang.String name,
        java.lang.String newName,
        mol.word.WdOrganizerObject object);

        @VTID(138)
        java.lang.String getAddress(
            java.lang.Object name,
            java.lang.Object addressProperties,
            java.lang.Object useAutoText,
            java.lang.Object displaySelectDialog,
            java.lang.Object selectDialog,
            java.lang.Object checkNamesDialog,
            java.lang.Object recentAddressesChoice,
            java.lang.Object updateRecentAddresses);

        @VTID(139)
        boolean checkGrammar(
            java.lang.String string);

        @VTID(140)
        boolean checkSpelling(
            java.lang.String word,
            java.lang.Object customDictionary,
            java.lang.Object ignoreUppercase,
            java.lang.Object mainDictionary,
            java.lang.Object customDictionary2,
            java.lang.Object customDictionary3,
            java.lang.Object customDictionary4,
            java.lang.Object customDictionary5,
            java.lang.Object customDictionary6,
            java.lang.Object customDictionary7,
            java.lang.Object customDictionary8,
            java.lang.Object customDictionary9,
            java.lang.Object customDictionary10);

        @VTID(141)
        void resetIgnoreAll();

        @VTID(142)
        mol.word.SpellingSuggestions getSpellingSuggestions(
            java.lang.String word,
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

        @VTID(143)
        void goBack();

        @VTID(144)
        void help(
            java.lang.Object helpType);

        @VTID(145)
        void automaticChange();

        @VTID(146)
        void showMe();

        @VTID(147)
        void helpTool();

        @VTID(148)
        mol.word.Window newWindow();

        @VTID(149)
        void listCommands(
            boolean listAllCommands);

        @VTID(150)
        void showClipboard();

        @VTID(151)
        void onTime(
            java.lang.Object when,
            java.lang.String name,
            java.lang.Object tolerance);

        @VTID(152)
        void nextLetter();

        @VTID(153)
        short mountVolume(
            java.lang.String zone,
            java.lang.String server,
            java.lang.String volume,
            java.lang.Object user,
            java.lang.Object userPassword,
            java.lang.Object volumePassword);

        @VTID(154)
        java.lang.String cleanString(
            java.lang.String string);

        @VTID(155)
        void sendFax();

        @VTID(156)
        void changeFileOpenDirectory(
            java.lang.String path);

        @VTID(157)
        void runOld(
            java.lang.String macroName);

        @VTID(158)
        void goForward();

        @VTID(159)
        void move(
            int left,
            int top);

        @VTID(160)
        void resize(
            int width,
            int height);

        @VTID(161)
        float inchesToPoints(
            float inches);

        @VTID(162)
        float centimetersToPoints(
            float centimeters);

        @VTID(163)
        float millimetersToPoints(
            float millimeters);

        @VTID(164)
        float picasToPoints(
            float picas);

        @VTID(165)
        float linesToPoints(
            float lines);

        @VTID(166)
        float pointsToInches(
            float points);

        @VTID(167)
        float pointsToCentimeters(
            float points);

        @VTID(168)
        float pointsToMillimeters(
            float points);

        @VTID(169)
        float pointsToPicas(
            float points);

        @VTID(170)
        float pointsToLines(
            float points);

        @VTID(171)
        void activate();

        @VTID(172)
        float pointsToPixels(
            float points,
            java.lang.Object fVertical);

        @VTID(173)
        float pixelsToPoints(
            float pixels,
            java.lang.Object fVertical);

        @VTID(174)
        void keyboardLatin();

        @VTID(175)
        void keyboardBidi();

        @VTID(176)
        void toggleKeyboard();

        @VTID(177)
        int keyboard(
            int langId);

        @VTID(178)
        java.lang.String productCode();

        @VTID(179)
        mol.word.DefaultWebOptions defaultWebOptions();

        @VTID(180)
        void discussionSupport(
            java.lang.Object range,
            java.lang.Object cid,
            java.lang.Object piCSE);

        @VTID(181)
        void setDefaultTheme(
            java.lang.String name,
            mol.word.WdDocumentMedium documentType);

        @VTID(182)
        java.lang.String getDefaultTheme(
            mol.word.WdDocumentMedium documentType);

        @VTID(183)
        mol.word.EmailOptions emailOptions();

        @VTID(184)
        mol.office.MsoLanguageID language();

        @VTID(185)
        mol.office.COMAddIns comAddIns();

        @VTID(185)
        @ReturnValue(defaultPropertyThrough={mol.office.COMAddIns.class})
        mol.office.COMAddIn comAddIns(
            java.lang.Object index);

        @VTID(186)
        boolean checkLanguage();

        @VTID(187)
        void checkLanguage(
            boolean prop);

        @VTID(188)
        mol.office.LanguageSettings languageSettings();

        @VTID(189)
        boolean dummy1();

        @VTID(190)
        mol.office.AnswerWizard answerWizard();

        @VTID(191)
        mol.office.MsoFeatureInstall featureInstall();

        @VTID(192)
        void featureInstall(
            mol.office.MsoFeatureInstall prop);

        @VTID(193)
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
            java.lang.Object fileName,
            java.lang.Object activePrinterMacGX,
            java.lang.Object manualDuplexPrint,
            java.lang.Object printZoomColumn,
            java.lang.Object printZoomRow,
            java.lang.Object printZoomPaperWidth,
            java.lang.Object printZoomPaperHeight);

        @VTID(194)
        @ReturnValue(type=NativeType.VARIANT)
        java.lang.Object run(
            java.lang.String macroName,
            java.lang.Object varg1,
            java.lang.Object varg2,
            java.lang.Object varg3,
            java.lang.Object varg4,
            java.lang.Object varg5,
            java.lang.Object varg6,
            java.lang.Object varg7,
            java.lang.Object varg8,
            java.lang.Object varg9,
            java.lang.Object varg10,
            java.lang.Object varg11,
            java.lang.Object varg12,
            java.lang.Object varg13,
            java.lang.Object varg14,
            java.lang.Object varg15,
            java.lang.Object varg16,
            java.lang.Object varg17,
            java.lang.Object varg18,
            java.lang.Object varg19,
            java.lang.Object varg20,
            java.lang.Object varg21,
            java.lang.Object varg22,
            java.lang.Object varg23,
            java.lang.Object varg24,
            java.lang.Object varg25,
            java.lang.Object varg26,
            java.lang.Object varg27,
            java.lang.Object varg28,
            java.lang.Object varg29,
            java.lang.Object varg30);

        @VTID(195)
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
            java.lang.Object fileName,
            java.lang.Object activePrinterMacGX,
            java.lang.Object manualDuplexPrint,
            java.lang.Object printZoomColumn,
            java.lang.Object printZoomRow,
            java.lang.Object printZoomPaperWidth,
            java.lang.Object printZoomPaperHeight);

        @VTID(196)
        mol.office.MsoAutomationSecurity automationSecurity();

        @VTID(197)
        void automationSecurity(
            mol.office.MsoAutomationSecurity prop);

        @VTID(198)
        mol.office.FileDialog fileDialog(
            mol.office.MsoFileDialogType fileDialogType);

        @VTID(199)
        java.lang.String emailTemplate();

        @VTID(200)
        void emailTemplate(
            java.lang.String prop);

        @VTID(201)
        boolean showWindowsInTaskbar();

        @VTID(202)
        void showWindowsInTaskbar(
            boolean prop);

        @VTID(203)
        mol.office.NewFile newDocument();

        @VTID(204)
        boolean showStartupDialog();

        @VTID(205)
        void showStartupDialog(
            boolean prop);

        @VTID(206)
        mol.word.AutoCorrect autoCorrectEmail();

        @VTID(207)
        mol.word.TaskPanes taskPanes();

        @VTID(207)
        @ReturnValue(defaultPropertyThrough={mol.word.TaskPanes.class})
        mol.word.TaskPane taskPanes(
            mol.word.WdTaskPanes index);

        @VTID(208)
        boolean defaultLegalBlackline();

        @VTID(209)
        void defaultLegalBlackline(
            boolean prop);

        @VTID(210)
        boolean dummy2();

        @VTID(211)
        mol.word.SmartTagRecognizers smartTagRecognizers();

        @VTID(211)
        @ReturnValue(defaultPropertyThrough={mol.word.SmartTagRecognizers.class})
        mol.word.SmartTagRecognizer smartTagRecognizers(
            java.lang.Object index);

        @VTID(212)
        mol.word.SmartTagTypes smartTagTypes();

        @VTID(212)
        @ReturnValue(defaultPropertyThrough={mol.word.SmartTagTypes.class})
        mol.word.SmartTagType smartTagTypes(
            java.lang.Object index);

        @VTID(213)
        mol.word.XMLNamespaces xmlNamespaces();

        @VTID(213)
        @ReturnValue(defaultPropertyThrough={mol.word.XMLNamespaces.class})
        mol.word.XMLNamespace xmlNamespaces(
            java.lang.Object index);

        @VTID(214)
        void putFocusInMailHeader();

        @VTID(215)
        boolean arbitraryXMLSupportAvailable();

        @VTID(216)
        java.lang.String buildFull();

        @VTID(217)
        java.lang.String buildFeatureCrew();

        @VTID(218)
        void loadMasterList(
            java.lang.String fileName);

        @VTID(219)
        mol.word._Document compareDocuments(
            mol.word._Document originalDocument,
            mol.word._Document revisedDocument,
            mol.word.WdCompareDestination destination,
            mol.word.WdGranularity granularity,
            boolean compareFormatting,
            boolean compareCaseChanges,
            boolean compareWhitespace,
            boolean compareTables,
            boolean compareHeaders,
            boolean compareFootnotes,
            boolean compareTextboxes,
            boolean compareFields,
            boolean compareComments,
            boolean compareMoves,
            java.lang.String revisedAuthor,
            boolean ignoreAllComparisonWarnings);

        @VTID(220)
        mol.word._Document mergeDocuments(
            mol.word._Document originalDocument,
            mol.word._Document revisedDocument,
            mol.word.WdCompareDestination destination,
            mol.word.WdGranularity granularity,
            boolean compareFormatting,
            boolean compareCaseChanges,
            boolean compareWhitespace,
            boolean compareTables,
            boolean compareHeaders,
            boolean compareFootnotes,
            boolean compareTextboxes,
            boolean compareFields,
            boolean compareComments,
            boolean compareMoves,
            java.lang.String originalAuthor,
            java.lang.String revisedAuthor,
            mol.word.WdMergeFormatFrom formatFrom);

        @VTID(221)
        mol.word.Bibliography bibliography();

        @VTID(222)
        boolean showStylePreviews();

        @VTID(223)
        void showStylePreviews(
            boolean prop);

        @VTID(224)
        boolean restrictLinkedStyles();

        @VTID(225)
        void restrictLinkedStyles(
            boolean prop);

        @VTID(226)
        mol.word.OMathAutoCorrect oMathAutoCorrect();

        @VTID(227)
        boolean displayDocumentInformationPanel();

        @VTID(228)
        void displayDocumentInformationPanel(
            boolean prop);

        @VTID(229)
        mol.office.IAssistance assistance();

        @VTID(230)
        boolean openAttachmentsInFullScreen();

        @VTID(231)
        void openAttachmentsInFullScreen(
            boolean prop);

        @VTID(232)
        int activeEncryptionSession();

        @VTID(233)
        boolean dontResetInsertionPointProperties();

        @VTID(234)
        void dontResetInsertionPointProperties(
            boolean prop);

    }
