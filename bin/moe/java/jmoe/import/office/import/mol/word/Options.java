package mol.word  ;

import com4j.*;

@IID("{000209B7-0000-0000-C000-000000000046}")
public interface Options extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    boolean allowAccentedUppercase();

    @VTID(11)
    void allowAccentedUppercase(
        boolean prop);

    @VTID(12)
    boolean wpHelp();

    @VTID(13)
    void wpHelp(
        boolean prop);

    @VTID(14)
    boolean wpDocNavKeys();

    @VTID(15)
    void wpDocNavKeys(
        boolean prop);

    @VTID(16)
    boolean pagination();

    @VTID(17)
    void pagination(
        boolean prop);

    @VTID(18)
    boolean blueScreen();

    @VTID(19)
    void blueScreen(
        boolean prop);

    @VTID(20)
    boolean enableSound();

    @VTID(21)
    void enableSound(
        boolean prop);

    @VTID(22)
    boolean confirmConversions();

    @VTID(23)
    void confirmConversions(
        boolean prop);

    @VTID(24)
    boolean updateLinksAtOpen();

    @VTID(25)
    void updateLinksAtOpen(
        boolean prop);

    @VTID(26)
    boolean sendMailAttach();

    @VTID(27)
    void sendMailAttach(
        boolean prop);

    @VTID(28)
    mol.word.WdMeasurementUnits measurementUnit();

    @VTID(29)
    void measurementUnit(
        mol.word.WdMeasurementUnits prop);

    @VTID(30)
    int buttonFieldClicks();

    @VTID(31)
    void buttonFieldClicks(
        int prop);

    @VTID(32)
    boolean shortMenuNames();

    @VTID(33)
    void shortMenuNames(
        boolean prop);

    @VTID(34)
    boolean rtfInClipboard();

    @VTID(35)
    void rtfInClipboard(
        boolean prop);

    @VTID(36)
    boolean updateFieldsAtPrint();

    @VTID(37)
    void updateFieldsAtPrint(
        boolean prop);

    @VTID(38)
    boolean printProperties();

    @VTID(39)
    void printProperties(
        boolean prop);

    @VTID(40)
    boolean printFieldCodes();

    @VTID(41)
    void printFieldCodes(
        boolean prop);

    @VTID(42)
    boolean printComments();

    @VTID(43)
    void printComments(
        boolean prop);

    @VTID(44)
    boolean printHiddenText();

    @VTID(45)
    void printHiddenText(
        boolean prop);

    @VTID(46)
    boolean envelopeFeederInstalled();

    @VTID(47)
    boolean updateLinksAtPrint();

    @VTID(48)
    void updateLinksAtPrint(
        boolean prop);

    @VTID(49)
    boolean printBackground();

    @VTID(50)
    void printBackground(
        boolean prop);

    @VTID(51)
    boolean printDrawingObjects();

    @VTID(52)
    void printDrawingObjects(
        boolean prop);

    @VTID(53)
    java.lang.String defaultTray();

    @VTID(54)
    void defaultTray(
        java.lang.String prop);

    @VTID(55)
    int defaultTrayID();

    @VTID(56)
    void defaultTrayID(
        int prop);

    @VTID(57)
    boolean createBackup();

    @VTID(58)
    void createBackup(
        boolean prop);

    @VTID(59)
    boolean allowFastSave();

    @VTID(60)
    void allowFastSave(
        boolean prop);

    @VTID(61)
    boolean savePropertiesPrompt();

    @VTID(62)
    void savePropertiesPrompt(
        boolean prop);

    @VTID(63)
    boolean saveNormalPrompt();

    @VTID(64)
    void saveNormalPrompt(
        boolean prop);

    @VTID(65)
    int saveInterval();

    @VTID(66)
    void saveInterval(
        int prop);

    @VTID(67)
    boolean backgroundSave();

    @VTID(68)
    void backgroundSave(
        boolean prop);

    @VTID(69)
    mol.word.WdInsertedTextMark insertedTextMark();

    @VTID(70)
    void insertedTextMark(
        mol.word.WdInsertedTextMark prop);

    @VTID(71)
    mol.word.WdDeletedTextMark deletedTextMark();

    @VTID(72)
    void deletedTextMark(
        mol.word.WdDeletedTextMark prop);

    @VTID(73)
    mol.word.WdRevisedLinesMark revisedLinesMark();

    @VTID(74)
    void revisedLinesMark(
        mol.word.WdRevisedLinesMark prop);

    @VTID(75)
    mol.word.WdColorIndex insertedTextColor();

    @VTID(76)
    void insertedTextColor(
        mol.word.WdColorIndex prop);

    @VTID(77)
    mol.word.WdColorIndex deletedTextColor();

    @VTID(78)
    void deletedTextColor(
        mol.word.WdColorIndex prop);

    @VTID(79)
    mol.word.WdColorIndex revisedLinesColor();

    @VTID(80)
    void revisedLinesColor(
        mol.word.WdColorIndex prop);

    @VTID(81)
    java.lang.String defaultFilePath(
        mol.word.WdDefaultFilePath path);

    @VTID(82)
    void defaultFilePath(
        mol.word.WdDefaultFilePath path,
        java.lang.String prop);

    @VTID(83)
    boolean overtype();

    @VTID(84)
    void overtype(
        boolean prop);

    @VTID(85)
    boolean replaceSelection();

    @VTID(86)
    void replaceSelection(
        boolean prop);

    @VTID(87)
    boolean allowDragAndDrop();

    @VTID(88)
    void allowDragAndDrop(
        boolean prop);

    @VTID(89)
    boolean autoWordSelection();

    @VTID(90)
    void autoWordSelection(
        boolean prop);

    @VTID(91)
    boolean insKeyForPaste();

    @VTID(92)
    void insKeyForPaste(
        boolean prop);

    @VTID(93)
    boolean smartCutPaste();

    @VTID(94)
    void smartCutPaste(
        boolean prop);

    @VTID(95)
    boolean tabIndentKey();

    @VTID(96)
    void tabIndentKey(
        boolean prop);

    @VTID(97)
    java.lang.String pictureEditor();

    @VTID(98)
    void pictureEditor(
        java.lang.String prop);

    @VTID(99)
    boolean animateScreenMovements();

    @VTID(100)
    void animateScreenMovements(
        boolean prop);

    @VTID(101)
    boolean virusProtection();

    @VTID(102)
    void virusProtection(
        boolean prop);

    @VTID(103)
    mol.word.WdRevisedPropertiesMark revisedPropertiesMark();

    @VTID(104)
    void revisedPropertiesMark(
        mol.word.WdRevisedPropertiesMark prop);

    @VTID(105)
    mol.word.WdColorIndex revisedPropertiesColor();

    @VTID(106)
    void revisedPropertiesColor(
        mol.word.WdColorIndex prop);

    @VTID(107)
    boolean snapToGrid();

    @VTID(108)
    void snapToGrid(
        boolean prop);

    @VTID(109)
    boolean snapToShapes();

    @VTID(110)
    void snapToShapes(
        boolean prop);

    @VTID(111)
    float gridDistanceHorizontal();

    @VTID(112)
    void gridDistanceHorizontal(
        float prop);

    @VTID(113)
    float gridDistanceVertical();

    @VTID(114)
    void gridDistanceVertical(
        float prop);

    @VTID(115)
    float gridOriginHorizontal();

    @VTID(116)
    void gridOriginHorizontal(
        float prop);

    @VTID(117)
    float gridOriginVertical();

    @VTID(118)
    void gridOriginVertical(
        float prop);

    @VTID(119)
    boolean inlineConversion();

    @VTID(120)
    void inlineConversion(
        boolean prop);

    @VTID(121)
    boolean imeAutomaticControl();

    @VTID(122)
    void imeAutomaticControl(
        boolean prop);

    @VTID(123)
    boolean autoFormatApplyHeadings();

    @VTID(124)
    void autoFormatApplyHeadings(
        boolean prop);

    @VTID(125)
    boolean autoFormatApplyLists();

    @VTID(126)
    void autoFormatApplyLists(
        boolean prop);

    @VTID(127)
    boolean autoFormatApplyBulletedLists();

    @VTID(128)
    void autoFormatApplyBulletedLists(
        boolean prop);

    @VTID(129)
    boolean autoFormatApplyOtherParas();

    @VTID(130)
    void autoFormatApplyOtherParas(
        boolean prop);

    @VTID(131)
    boolean autoFormatReplaceQuotes();

    @VTID(132)
    void autoFormatReplaceQuotes(
        boolean prop);

    @VTID(133)
    boolean autoFormatReplaceSymbols();

    @VTID(134)
    void autoFormatReplaceSymbols(
        boolean prop);

    @VTID(135)
    boolean autoFormatReplaceOrdinals();

    @VTID(136)
    void autoFormatReplaceOrdinals(
        boolean prop);

    @VTID(137)
    boolean autoFormatReplaceFractions();

    @VTID(138)
    void autoFormatReplaceFractions(
        boolean prop);

    @VTID(139)
    boolean autoFormatReplacePlainTextEmphasis();

    @VTID(140)
    void autoFormatReplacePlainTextEmphasis(
        boolean prop);

    @VTID(141)
    boolean autoFormatPreserveStyles();

    @VTID(142)
    void autoFormatPreserveStyles(
        boolean prop);

    @VTID(143)
    boolean autoFormatAsYouTypeApplyHeadings();

    @VTID(144)
    void autoFormatAsYouTypeApplyHeadings(
        boolean prop);

    @VTID(145)
    boolean autoFormatAsYouTypeApplyBorders();

    @VTID(146)
    void autoFormatAsYouTypeApplyBorders(
        boolean prop);

    @VTID(147)
    boolean autoFormatAsYouTypeApplyBulletedLists();

    @VTID(148)
    void autoFormatAsYouTypeApplyBulletedLists(
        boolean prop);

    @VTID(149)
    boolean autoFormatAsYouTypeApplyNumberedLists();

    @VTID(150)
    void autoFormatAsYouTypeApplyNumberedLists(
        boolean prop);

    @VTID(151)
    boolean autoFormatAsYouTypeReplaceQuotes();

    @VTID(152)
    void autoFormatAsYouTypeReplaceQuotes(
        boolean prop);

    @VTID(153)
    boolean autoFormatAsYouTypeReplaceSymbols();

    @VTID(154)
    void autoFormatAsYouTypeReplaceSymbols(
        boolean prop);

    @VTID(155)
    boolean autoFormatAsYouTypeReplaceOrdinals();

    @VTID(156)
    void autoFormatAsYouTypeReplaceOrdinals(
        boolean prop);

    @VTID(157)
    boolean autoFormatAsYouTypeReplaceFractions();

    @VTID(158)
    void autoFormatAsYouTypeReplaceFractions(
        boolean prop);

    @VTID(159)
    boolean autoFormatAsYouTypeReplacePlainTextEmphasis();

    @VTID(160)
    void autoFormatAsYouTypeReplacePlainTextEmphasis(
        boolean prop);

    @VTID(161)
    boolean autoFormatAsYouTypeFormatListItemBeginning();

    @VTID(162)
    void autoFormatAsYouTypeFormatListItemBeginning(
        boolean prop);

    @VTID(163)
    boolean autoFormatAsYouTypeDefineStyles();

    @VTID(164)
    void autoFormatAsYouTypeDefineStyles(
        boolean prop);

    @VTID(165)
    boolean autoFormatPlainTextWordMail();

    @VTID(166)
    void autoFormatPlainTextWordMail(
        boolean prop);

    @VTID(167)
    boolean autoFormatAsYouTypeReplaceHyperlinks();

    @VTID(168)
    void autoFormatAsYouTypeReplaceHyperlinks(
        boolean prop);

    @VTID(169)
    boolean autoFormatReplaceHyperlinks();

    @VTID(170)
    void autoFormatReplaceHyperlinks(
        boolean prop);

    @VTID(171)
    mol.word.WdColorIndex defaultHighlightColorIndex();

    @VTID(172)
    void defaultHighlightColorIndex(
        mol.word.WdColorIndex prop);

    @VTID(173)
    mol.word.WdLineStyle defaultBorderLineStyle();

    @VTID(174)
    void defaultBorderLineStyle(
        mol.word.WdLineStyle prop);

    @VTID(175)
    boolean checkSpellingAsYouType();

    @VTID(176)
    void checkSpellingAsYouType(
        boolean prop);

    @VTID(177)
    boolean checkGrammarAsYouType();

    @VTID(178)
    void checkGrammarAsYouType(
        boolean prop);

    @VTID(179)
    boolean ignoreInternetAndFileAddresses();

    @VTID(180)
    void ignoreInternetAndFileAddresses(
        boolean prop);

    @VTID(181)
    boolean showReadabilityStatistics();

    @VTID(182)
    void showReadabilityStatistics(
        boolean prop);

    @VTID(183)
    boolean ignoreUppercase();

    @VTID(184)
    void ignoreUppercase(
        boolean prop);

    @VTID(185)
    boolean ignoreMixedDigits();

    @VTID(186)
    void ignoreMixedDigits(
        boolean prop);

    @VTID(187)
    boolean suggestFromMainDictionaryOnly();

    @VTID(188)
    void suggestFromMainDictionaryOnly(
        boolean prop);

    @VTID(189)
    boolean suggestSpellingCorrections();

    @VTID(190)
    void suggestSpellingCorrections(
        boolean prop);

    @VTID(191)
    mol.word.WdLineWidth defaultBorderLineWidth();

    @VTID(192)
    void defaultBorderLineWidth(
        mol.word.WdLineWidth prop);

    @VTID(193)
    boolean checkGrammarWithSpelling();

    @VTID(194)
    void checkGrammarWithSpelling(
        boolean prop);

    @VTID(195)
    mol.word.WdOpenFormat defaultOpenFormat();

    @VTID(196)
    void defaultOpenFormat(
        mol.word.WdOpenFormat prop);

    @VTID(197)
    boolean printDraft();

    @VTID(198)
    void printDraft(
        boolean prop);

    @VTID(199)
    boolean printReverse();

    @VTID(200)
    void printReverse(
        boolean prop);

    @VTID(201)
    boolean mapPaperSize();

    @VTID(202)
    void mapPaperSize(
        boolean prop);

    @VTID(203)
    boolean autoFormatAsYouTypeApplyTables();

    @VTID(204)
    void autoFormatAsYouTypeApplyTables(
        boolean prop);

    @VTID(205)
    boolean autoFormatApplyFirstIndents();

    @VTID(206)
    void autoFormatApplyFirstIndents(
        boolean prop);

    @VTID(207)
    boolean autoFormatMatchParentheses();

    @VTID(208)
    void autoFormatMatchParentheses(
        boolean prop);

    @VTID(209)
    boolean autoFormatReplaceFarEastDashes();

    @VTID(210)
    void autoFormatReplaceFarEastDashes(
        boolean prop);

    @VTID(211)
    boolean autoFormatDeleteAutoSpaces();

    @VTID(212)
    void autoFormatDeleteAutoSpaces(
        boolean prop);

    @VTID(213)
    boolean autoFormatAsYouTypeApplyFirstIndents();

    @VTID(214)
    void autoFormatAsYouTypeApplyFirstIndents(
        boolean prop);

    @VTID(215)
    boolean autoFormatAsYouTypeApplyDates();

    @VTID(216)
    void autoFormatAsYouTypeApplyDates(
        boolean prop);

    @VTID(217)
    boolean autoFormatAsYouTypeApplyClosings();

    @VTID(218)
    void autoFormatAsYouTypeApplyClosings(
        boolean prop);

    @VTID(219)
    boolean autoFormatAsYouTypeMatchParentheses();

    @VTID(220)
    void autoFormatAsYouTypeMatchParentheses(
        boolean prop);

    @VTID(221)
    boolean autoFormatAsYouTypeReplaceFarEastDashes();

    @VTID(222)
    void autoFormatAsYouTypeReplaceFarEastDashes(
        boolean prop);

    @VTID(223)
    boolean autoFormatAsYouTypeDeleteAutoSpaces();

    @VTID(224)
    void autoFormatAsYouTypeDeleteAutoSpaces(
        boolean prop);

    @VTID(225)
    boolean autoFormatAsYouTypeInsertClosings();

    @VTID(226)
    void autoFormatAsYouTypeInsertClosings(
        boolean prop);

    @VTID(227)
    boolean autoFormatAsYouTypeAutoLetterWizard();

    @VTID(228)
    void autoFormatAsYouTypeAutoLetterWizard(
        boolean prop);

    @VTID(229)
    boolean autoFormatAsYouTypeInsertOvers();

    @VTID(230)
    void autoFormatAsYouTypeInsertOvers(
        boolean prop);

    @VTID(231)
    boolean displayGridLines();

    @VTID(232)
    void displayGridLines(
        boolean prop);

    @VTID(233)
    boolean matchFuzzyCase();

    @VTID(234)
    void matchFuzzyCase(
        boolean prop);

    @VTID(235)
    boolean matchFuzzyByte();

    @VTID(236)
    void matchFuzzyByte(
        boolean prop);

    @VTID(237)
    boolean matchFuzzyHiragana();

    @VTID(238)
    void matchFuzzyHiragana(
        boolean prop);

    @VTID(239)
    boolean matchFuzzySmallKana();

    @VTID(240)
    void matchFuzzySmallKana(
        boolean prop);

    @VTID(241)
    boolean matchFuzzyDash();

    @VTID(242)
    void matchFuzzyDash(
        boolean prop);

    @VTID(243)
    boolean matchFuzzyIterationMark();

    @VTID(244)
    void matchFuzzyIterationMark(
        boolean prop);

    @VTID(245)
    boolean matchFuzzyKanji();

    @VTID(246)
    void matchFuzzyKanji(
        boolean prop);

    @VTID(247)
    boolean matchFuzzyOldKana();

    @VTID(248)
    void matchFuzzyOldKana(
        boolean prop);

    @VTID(249)
    boolean matchFuzzyProlongedSoundMark();

    @VTID(250)
    void matchFuzzyProlongedSoundMark(
        boolean prop);

    @VTID(251)
    boolean matchFuzzyDZ();

    @VTID(252)
    void matchFuzzyDZ(
        boolean prop);

    @VTID(253)
    boolean matchFuzzyBV();

    @VTID(254)
    void matchFuzzyBV(
        boolean prop);

    @VTID(255)
    boolean matchFuzzyTC();

    @VTID(256)
    void matchFuzzyTC(
        boolean prop);

    @VTID(257)
    boolean matchFuzzyHF();

    @VTID(258)
    void matchFuzzyHF(
        boolean prop);

    @VTID(259)
    boolean matchFuzzyZJ();

    @VTID(260)
    void matchFuzzyZJ(
        boolean prop);

    @VTID(261)
    boolean matchFuzzyAY();

    @VTID(262)
    void matchFuzzyAY(
        boolean prop);

    @VTID(263)
    boolean matchFuzzyKiKu();

    @VTID(264)
    void matchFuzzyKiKu(
        boolean prop);

    @VTID(265)
    boolean matchFuzzyPunctuation();

    @VTID(266)
    void matchFuzzyPunctuation(
        boolean prop);

    @VTID(267)
    boolean matchFuzzySpace();

    @VTID(268)
    void matchFuzzySpace(
        boolean prop);

    @VTID(269)
    boolean applyFarEastFontsToAscii();

    @VTID(270)
    void applyFarEastFontsToAscii(
        boolean prop);

    @VTID(271)
    boolean convertHighAnsiToFarEast();

    @VTID(272)
    void convertHighAnsiToFarEast(
        boolean prop);

    @VTID(273)
    boolean printOddPagesInAscendingOrder();

    @VTID(274)
    void printOddPagesInAscendingOrder(
        boolean prop);

    @VTID(275)
    boolean printEvenPagesInAscendingOrder();

    @VTID(276)
    void printEvenPagesInAscendingOrder(
        boolean prop);

    @VTID(277)
    mol.word.WdColorIndex defaultBorderColorIndex();

    @VTID(278)
    void defaultBorderColorIndex(
        mol.word.WdColorIndex prop);

    @VTID(279)
    boolean enableMisusedWordsDictionary();

    @VTID(280)
    void enableMisusedWordsDictionary(
        boolean prop);

    @VTID(281)
    boolean allowCombinedAuxiliaryForms();

    @VTID(282)
    void allowCombinedAuxiliaryForms(
        boolean prop);

    @VTID(283)
    boolean hangulHanjaFastConversion();

    @VTID(284)
    void hangulHanjaFastConversion(
        boolean prop);

    @VTID(285)
    boolean checkHangulEndings();

    @VTID(286)
    void checkHangulEndings(
        boolean prop);

    @VTID(287)
    boolean enableHangulHanjaRecentOrdering();

    @VTID(288)
    void enableHangulHanjaRecentOrdering(
        boolean prop);

    @VTID(289)
    mol.word.WdMultipleWordConversionsMode multipleWordConversionsMode();

    @VTID(290)
    void multipleWordConversionsMode(
        mol.word.WdMultipleWordConversionsMode prop);

    @VTID(291)
    void setWPHelpOptions(
        java.lang.Object commandKeyHelp,
        java.lang.Object docNavigationKeys,
        java.lang.Object mouseSimulation,
        java.lang.Object demoGuidance,
        java.lang.Object demoSpeed,
        java.lang.Object helpType);

    @VTID(292)
    mol.word.WdColor defaultBorderColor();

    @VTID(293)
    void defaultBorderColor(
        mol.word.WdColor prop);

    @VTID(294)
    boolean allowPixelUnits();

    @VTID(295)
    void allowPixelUnits(
        boolean prop);

    @VTID(296)
    boolean useCharacterUnit();

    @VTID(297)
    void useCharacterUnit(
        boolean prop);

    @VTID(298)
    boolean allowCompoundNounProcessing();

    @VTID(299)
    void allowCompoundNounProcessing(
        boolean prop);

    @VTID(300)
    boolean autoKeyboardSwitching();

    @VTID(301)
    void autoKeyboardSwitching(
        boolean prop);

    @VTID(302)
    mol.word.WdDocumentViewDirection documentViewDirection();

    @VTID(303)
    void documentViewDirection(
        mol.word.WdDocumentViewDirection prop);

    @VTID(304)
    mol.word.WdArabicNumeral arabicNumeral();

    @VTID(305)
    void arabicNumeral(
        mol.word.WdArabicNumeral prop);

    @VTID(306)
    mol.word.WdMonthNames monthNames();

    @VTID(307)
    void monthNames(
        mol.word.WdMonthNames prop);

    @VTID(308)
    mol.word.WdCursorMovement cursorMovement();

    @VTID(309)
    void cursorMovement(
        mol.word.WdCursorMovement prop);

    @VTID(310)
    mol.word.WdVisualSelection visualSelection();

    @VTID(311)
    void visualSelection(
        mol.word.WdVisualSelection prop);

    @VTID(312)
    boolean showDiacritics();

    @VTID(313)
    void showDiacritics(
        boolean prop);

    @VTID(314)
    boolean showControlCharacters();

    @VTID(315)
    void showControlCharacters(
        boolean prop);

    @VTID(316)
    boolean addControlCharacters();

    @VTID(317)
    void addControlCharacters(
        boolean prop);

    @VTID(318)
    boolean addBiDirectionalMarksWhenSavingTextFile();

    @VTID(319)
    void addBiDirectionalMarksWhenSavingTextFile(
        boolean prop);

    @VTID(320)
    boolean strictInitialAlefHamza();

    @VTID(321)
    void strictInitialAlefHamza(
        boolean prop);

    @VTID(322)
    boolean strictFinalYaa();

    @VTID(323)
    void strictFinalYaa(
        boolean prop);

    @VTID(324)
    mol.word.WdHebSpellStart hebrewMode();

    @VTID(325)
    void hebrewMode(
        mol.word.WdHebSpellStart prop);

    @VTID(326)
    mol.word.WdAraSpeller arabicMode();

    @VTID(327)
    void arabicMode(
        mol.word.WdAraSpeller prop);

    @VTID(328)
    boolean allowClickAndTypeMouse();

    @VTID(329)
    void allowClickAndTypeMouse(
        boolean prop);

    @VTID(330)
    boolean useGermanSpellingReform();

    @VTID(331)
    void useGermanSpellingReform(
        boolean prop);

    @VTID(332)
    mol.word.WdHighAnsiText interpretHighAnsi();

    @VTID(333)
    void interpretHighAnsi(
        mol.word.WdHighAnsiText prop);

    @VTID(334)
    boolean addHebDoubleQuote();

    @VTID(335)
    void addHebDoubleQuote(
        boolean prop);

    @VTID(336)
    boolean useDiffDiacColor();

    @VTID(337)
    void useDiffDiacColor(
        boolean prop);

    @VTID(338)
    mol.word.WdColor diacriticColorVal();

    @VTID(339)
    void diacriticColorVal(
        mol.word.WdColor prop);

    @VTID(340)
    boolean optimizeForWord97byDefault();

    @VTID(341)
    void optimizeForWord97byDefault(
        boolean prop);

    @VTID(342)
    boolean localNetworkFile();

    @VTID(343)
    void localNetworkFile(
        boolean prop);

    @VTID(344)
    boolean typeNReplace();

    @VTID(345)
    void typeNReplace(
        boolean prop);

    @VTID(346)
    boolean sequenceCheck();

    @VTID(347)
    void sequenceCheck(
        boolean prop);

    @VTID(348)
    boolean backgroundOpen();

    @VTID(349)
    void backgroundOpen(
        boolean prop);

    @VTID(350)
    boolean disableFeaturesbyDefault();

    @VTID(351)
    void disableFeaturesbyDefault(
        boolean prop);

    @VTID(352)
    boolean pasteAdjustWordSpacing();

    @VTID(353)
    void pasteAdjustWordSpacing(
        boolean prop);

    @VTID(354)
    boolean pasteAdjustParagraphSpacing();

    @VTID(355)
    void pasteAdjustParagraphSpacing(
        boolean prop);

    @VTID(356)
    boolean pasteAdjustTableFormatting();

    @VTID(357)
    void pasteAdjustTableFormatting(
        boolean prop);

    @VTID(358)
    boolean pasteSmartStyleBehavior();

    @VTID(359)
    void pasteSmartStyleBehavior(
        boolean prop);

    @VTID(360)
    boolean pasteMergeFromPPT();

    @VTID(361)
    void pasteMergeFromPPT(
        boolean prop);

    @VTID(362)
    boolean pasteMergeFromXL();

    @VTID(363)
    void pasteMergeFromXL(
        boolean prop);

    @VTID(364)
    boolean ctrlClickHyperlinkToOpen();

    @VTID(365)
    void ctrlClickHyperlinkToOpen(
        boolean prop);

    @VTID(366)
    mol.word.WdWrapTypeMerged pictureWrapType();

    @VTID(367)
    void pictureWrapType(
        mol.word.WdWrapTypeMerged prop);

    @VTID(368)
    mol.word.WdDisableFeaturesIntroducedAfter disableFeaturesIntroducedAfterbyDefault();

    @VTID(369)
    void disableFeaturesIntroducedAfterbyDefault(
        mol.word.WdDisableFeaturesIntroducedAfter prop);

    @VTID(370)
    boolean pasteSmartCutPaste();

    @VTID(371)
    void pasteSmartCutPaste(
        boolean prop);

    @VTID(372)
    boolean displayPasteOptions();

    @VTID(373)
    void displayPasteOptions(
        boolean prop);

    @VTID(374)
    boolean promptUpdateStyle();

    @VTID(375)
    void promptUpdateStyle(
        boolean prop);

    @VTID(376)
    java.lang.String defaultEPostageApp();

    @VTID(377)
    void defaultEPostageApp(
        java.lang.String prop);

    @VTID(378)
    mol.office.MsoEncoding defaultTextEncoding();

    @VTID(379)
    void defaultTextEncoding(
        mol.office.MsoEncoding prop);

    @VTID(380)
    boolean labelSmartTags();

    @VTID(381)
    void labelSmartTags(
        boolean prop);

    @VTID(382)
    boolean displaySmartTagButtons();

    @VTID(383)
    void displaySmartTagButtons(
        boolean prop);

    @VTID(384)
    boolean warnBeforeSavingPrintingSendingMarkup();

    @VTID(385)
    void warnBeforeSavingPrintingSendingMarkup(
        boolean prop);

    @VTID(386)
    boolean storeRSIDOnSave();

    @VTID(387)
    void storeRSIDOnSave(
        boolean prop);

    @VTID(388)
    boolean showFormatError();

    @VTID(389)
    void showFormatError(
        boolean prop);

    @VTID(390)
    boolean formatScanning();

    @VTID(391)
    void formatScanning(
        boolean prop);

    @VTID(392)
    boolean pasteMergeLists();

    @VTID(393)
    void pasteMergeLists(
        boolean prop);

    @VTID(394)
    boolean autoCreateNewDrawings();

    @VTID(395)
    void autoCreateNewDrawings(
        boolean prop);

    @VTID(396)
    boolean smartParaSelection();

    @VTID(397)
    void smartParaSelection(
        boolean prop);

    @VTID(398)
    mol.word.WdRevisionsBalloonPrintOrientation revisionsBalloonPrintOrientation();

    @VTID(399)
    void revisionsBalloonPrintOrientation(
        mol.word.WdRevisionsBalloonPrintOrientation prop);

    @VTID(400)
    mol.word.WdColorIndex commentsColor();

    @VTID(401)
    void commentsColor(
        mol.word.WdColorIndex prop);

    @VTID(402)
    boolean printXMLTag();

    @VTID(403)
    void printXMLTag(
        boolean prop);

    @VTID(404)
    boolean printBackgrounds();

    @VTID(405)
    void printBackgrounds(
        boolean prop);

    @VTID(406)
    boolean allowReadingMode();

    @VTID(407)
    void allowReadingMode(
        boolean prop);

    @VTID(408)
    boolean showMarkupOpenSave();

    @VTID(409)
    void showMarkupOpenSave(
        boolean prop);

    @VTID(410)
    boolean smartCursoring();

    @VTID(411)
    void smartCursoring(
        boolean prop);

    @VTID(412)
    mol.word.WdMoveToTextMark moveToTextMark();

    @VTID(413)
    void moveToTextMark(
        mol.word.WdMoveToTextMark prop);

    @VTID(414)
    mol.word.WdMoveFromTextMark moveFromTextMark();

    @VTID(415)
    void moveFromTextMark(
        mol.word.WdMoveFromTextMark prop);

    @VTID(416)
    java.lang.String bibliographyStyle();

    @VTID(417)
    void bibliographyStyle(
        java.lang.String prop);

    @VTID(418)
    java.lang.String bibliographySort();

    @VTID(419)
    void bibliographySort(
        java.lang.String prop);

    @VTID(420)
    mol.word.WdCellColor insertedCellColor();

    @VTID(421)
    void insertedCellColor(
        mol.word.WdCellColor prop);

    @VTID(422)
    mol.word.WdCellColor deletedCellColor();

    @VTID(423)
    void deletedCellColor(
        mol.word.WdCellColor prop);

    @VTID(424)
    mol.word.WdCellColor mergedCellColor();

    @VTID(425)
    void mergedCellColor(
        mol.word.WdCellColor prop);

    @VTID(426)
    mol.word.WdCellColor splitCellColor();

    @VTID(427)
    void splitCellColor(
        mol.word.WdCellColor prop);

    @VTID(428)
    boolean showSelectionFloaties();

    @VTID(429)
    void showSelectionFloaties(
        boolean prop);

    @VTID(430)
    boolean showMenuFloaties();

    @VTID(431)
    void showMenuFloaties(
        boolean prop);

    @VTID(432)
    boolean showDevTools();

    @VTID(433)
    void showDevTools(
        boolean prop);

    @VTID(434)
    boolean enableLivePreview();

    @VTID(435)
    void enableLivePreview(
        boolean prop);

    @VTID(436)
    boolean oMathAutoBuildUp();

    @VTID(437)
    void oMathAutoBuildUp(
        boolean prop);

    @VTID(438)
    boolean alwaysUseClearType();

    @VTID(439)
    void alwaysUseClearType(
        boolean prop);

    @VTID(440)
    mol.word.WdPasteOptions pasteFormatWithinDocument();

    @VTID(441)
    void pasteFormatWithinDocument(
        mol.word.WdPasteOptions prop);

    @VTID(442)
    mol.word.WdPasteOptions pasteFormatBetweenDocuments();

    @VTID(443)
    void pasteFormatBetweenDocuments(
        mol.word.WdPasteOptions prop);

    @VTID(444)
    mol.word.WdPasteOptions pasteFormatBetweenStyledDocuments();

    @VTID(445)
    void pasteFormatBetweenStyledDocuments(
        mol.word.WdPasteOptions prop);

    @VTID(446)
    mol.word.WdPasteOptions pasteFormatFromExternalSource();

    @VTID(447)
    void pasteFormatFromExternalSource(
        mol.word.WdPasteOptions prop);

    @VTID(448)
    boolean pasteOptionKeepBulletsAndNumbers();

    @VTID(449)
    void pasteOptionKeepBulletsAndNumbers(
        boolean prop);

    @VTID(450)
    boolean insKeyForOvertype();

    @VTID(451)
    void insKeyForOvertype(
        boolean prop);

    @VTID(452)
    boolean repeatWord();

    @VTID(453)
    void repeatWord(
        boolean prop);

    @VTID(454)
    mol.word.WdFrenchSpeller frenchReform();

    @VTID(455)
    void frenchReform(
        mol.word.WdFrenchSpeller prop);

    @VTID(456)
    boolean contextualSpeller();

    @VTID(457)
    void contextualSpeller(
        boolean prop);

    @VTID(458)
    mol.word.WdColorIndex moveToTextColor();

    @VTID(459)
    void moveToTextColor(
        mol.word.WdColorIndex prop);

    @VTID(460)
    mol.word.WdColorIndex moveFromTextColor();

    @VTID(461)
    void moveFromTextColor(
        mol.word.WdColorIndex prop);

    @VTID(462)
    boolean oMathCopyLF();

    @VTID(463)
    void oMathCopyLF(
        boolean prop);

    @VTID(464)
    boolean useNormalStyleForList();

    @VTID(465)
    void useNormalStyleForList(
        boolean prop);

    @VTID(466)
    boolean allowOpenInDraftView();

    @VTID(467)
    void allowOpenInDraftView(
        boolean prop);

    @VTID(468)
    boolean enableLegacyIMEMode();

    @VTID(469)
    void enableLegacyIMEMode(
        boolean prop);

    @VTID(470)
    boolean doNotPromptForConvert();

    @VTID(471)
    void doNotPromptForConvert(
        boolean prop);

    @VTID(472)
    boolean precisePositioning();

    @VTID(473)
    void precisePositioning(
        boolean prop);

}
