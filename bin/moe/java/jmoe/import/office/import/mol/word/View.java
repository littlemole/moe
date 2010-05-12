package mol.word  ;

import com4j.*;

@IID("{000209A5-0000-0000-C000-000000000046}")
public interface View extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @DefaultMethod
    mol.word.WdViewType type();

    @VTID(11)
    @DefaultMethod
    void type(
        mol.word.WdViewType prop);

    @VTID(12)
    boolean fullScreen();

    @VTID(13)
    void fullScreen(
        boolean prop);

    @VTID(14)
    boolean draft();

    @VTID(15)
    void draft(
        boolean prop);

    @VTID(16)
    boolean showAll();

    @VTID(17)
    void showAll(
        boolean prop);

    @VTID(18)
    boolean showFieldCodes();

    @VTID(19)
    void showFieldCodes(
        boolean prop);

    @VTID(20)
    boolean mailMergeDataView();

    @VTID(21)
    void mailMergeDataView(
        boolean prop);

    @VTID(22)
    boolean magnifier();

    @VTID(23)
    void magnifier(
        boolean prop);

    @VTID(24)
    boolean showFirstLineOnly();

    @VTID(25)
    void showFirstLineOnly(
        boolean prop);

    @VTID(26)
    boolean showFormat();

    @VTID(27)
    void showFormat(
        boolean prop);

    @VTID(28)
    mol.word.Zoom zoom();

    @VTID(29)
    boolean showObjectAnchors();

    @VTID(30)
    void showObjectAnchors(
        boolean prop);

    @VTID(31)
    boolean showTextBoundaries();

    @VTID(32)
    void showTextBoundaries(
        boolean prop);

    @VTID(33)
    boolean showHighlight();

    @VTID(34)
    void showHighlight(
        boolean prop);

    @VTID(35)
    boolean showDrawings();

    @VTID(36)
    void showDrawings(
        boolean prop);

    @VTID(37)
    boolean showTabs();

    @VTID(38)
    void showTabs(
        boolean prop);

    @VTID(39)
    boolean showSpaces();

    @VTID(40)
    void showSpaces(
        boolean prop);

    @VTID(41)
    boolean showParagraphs();

    @VTID(42)
    void showParagraphs(
        boolean prop);

    @VTID(43)
    boolean showHyphens();

    @VTID(44)
    void showHyphens(
        boolean prop);

    @VTID(45)
    boolean showHiddenText();

    @VTID(46)
    void showHiddenText(
        boolean prop);

    @VTID(47)
    boolean wrapToWindow();

    @VTID(48)
    void wrapToWindow(
        boolean prop);

    @VTID(49)
    boolean showPicturePlaceHolders();

    @VTID(50)
    void showPicturePlaceHolders(
        boolean prop);

    @VTID(51)
    boolean showBookmarks();

    @VTID(52)
    void showBookmarks(
        boolean prop);

    @VTID(53)
    mol.word.WdFieldShading fieldShading();

    @VTID(54)
    void fieldShading(
        mol.word.WdFieldShading prop);

    @VTID(55)
    boolean showAnimation();

    @VTID(56)
    void showAnimation(
        boolean prop);

    @VTID(57)
    boolean tableGridlines();

    @VTID(58)
    void tableGridlines(
        boolean prop);

    @VTID(59)
    int enlargeFontsLessThan();

    @VTID(60)
    void enlargeFontsLessThan(
        int prop);

    @VTID(61)
    boolean showMainTextLayer();

    @VTID(62)
    void showMainTextLayer(
        boolean prop);

    @VTID(63)
    mol.word.WdSeekView seekView();

    @VTID(64)
    void seekView(
        mol.word.WdSeekView prop);

    @VTID(65)
    mol.word.WdSpecialPane splitSpecial();

    @VTID(66)
    void splitSpecial(
        mol.word.WdSpecialPane prop);

    @VTID(67)
    int browseToWindow();

    @VTID(68)
    void browseToWindow(
        int prop);

    @VTID(69)
    boolean showOptionalBreaks();

    @VTID(70)
    void showOptionalBreaks(
        boolean prop);

    @VTID(71)
    void collapseOutline(
        java.lang.Object range);

    @VTID(72)
    void expandOutline(
        java.lang.Object range);

    @VTID(73)
    void showAllHeadings();

    @VTID(74)
    void showHeading(
        int level);

    @VTID(75)
    void previousHeaderFooter();

    @VTID(76)
    void nextHeaderFooter();

    @VTID(77)
    boolean displayPageBoundaries();

    @VTID(78)
    void displayPageBoundaries(
        boolean prop);

    @VTID(79)
    boolean displaySmartTags();

    @VTID(80)
    void displaySmartTags(
        boolean prop);

    @VTID(81)
    boolean showRevisionsAndComments();

    @VTID(82)
    void showRevisionsAndComments(
        boolean prop);

    @VTID(83)
    boolean showComments();

    @VTID(84)
    void showComments(
        boolean prop);

    @VTID(85)
    boolean showInsertionsAndDeletions();

    @VTID(86)
    void showInsertionsAndDeletions(
        boolean prop);

    @VTID(87)
    boolean showFormatChanges();

    @VTID(88)
    void showFormatChanges(
        boolean prop);

    @VTID(89)
    mol.word.WdRevisionsView revisionsView();

    @VTID(90)
    void revisionsView(
        mol.word.WdRevisionsView prop);

    @VTID(91)
    mol.word.WdRevisionsMode revisionsMode();

    @VTID(92)
    void revisionsMode(
        mol.word.WdRevisionsMode prop);

    @VTID(93)
    float revisionsBalloonWidth();

    @VTID(94)
    void revisionsBalloonWidth(
        float prop);

    @VTID(95)
    mol.word.WdRevisionsBalloonWidthType revisionsBalloonWidthType();

    @VTID(96)
    void revisionsBalloonWidthType(
        mol.word.WdRevisionsBalloonWidthType prop);

    @VTID(97)
    mol.word.WdRevisionsBalloonMargin revisionsBalloonSide();

    @VTID(98)
    void revisionsBalloonSide(
        mol.word.WdRevisionsBalloonMargin prop);

    @VTID(99)
    mol.word.Reviewers reviewers();

    @VTID(99)
    @ReturnValue(defaultPropertyThrough={mol.word.Reviewers.class})
    mol.word.Reviewer reviewers(
        java.lang.Object index);

    @VTID(100)
    boolean revisionsBalloonShowConnectingLines();

    @VTID(101)
    void revisionsBalloonShowConnectingLines(
        boolean prop);

    @VTID(102)
    boolean readingLayout();

    @VTID(103)
    void readingLayout(
        boolean prop);

    @VTID(104)
    int showXMLMarkup();

    @VTID(105)
    void showXMLMarkup(
        int prop);

    @VTID(106)
    int shadeEditableRanges();

    @VTID(107)
    void shadeEditableRanges(
        int prop);

    @VTID(108)
    boolean showInkAnnotations();

    @VTID(109)
    void showInkAnnotations(
        boolean prop);

    @VTID(110)
    boolean displayBackgrounds();

    @VTID(111)
    void displayBackgrounds(
        boolean prop);

    @VTID(112)
    boolean readingLayoutActualView();

    @VTID(113)
    void readingLayoutActualView(
        boolean prop);

    @VTID(114)
    boolean readingLayoutAllowMultiplePages();

    @VTID(115)
    void readingLayoutAllowMultiplePages(
        boolean prop);

    @VTID(116)
    boolean readingLayoutAllowEditing();

    @VTID(117)
    void readingLayoutAllowEditing(
        boolean prop);

    @VTID(118)
    mol.word.WdReadingLayoutMargin readingLayoutTruncateMargins();

    @VTID(119)
    void readingLayoutTruncateMargins(
        mol.word.WdReadingLayoutMargin prop);

    @VTID(120)
    boolean showMarkupAreaHighlight();

    @VTID(121)
    void showMarkupAreaHighlight(
        boolean prop);

    @VTID(122)
    boolean panning();

    @VTID(123)
    void panning(
        boolean prop);

    @VTID(124)
    boolean showCropMarks();

    @VTID(125)
    void showCropMarks(
        boolean prop);

    @VTID(126)
    mol.word.WdRevisionsMode markupMode();

    @VTID(127)
    void markupMode(
        mol.word.WdRevisionsMode prop);

}
