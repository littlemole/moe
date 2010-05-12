package mol.word  ;

import com4j.*;

@IID("{00020962-0000-0000-C000-000000000046}")
public interface Window extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word.Pane activePane();

    @VTID(11)
    mol.word._Document document();

    @VTID(12)
    mol.word.Panes panes();

    @VTID(12)
    @ReturnValue(defaultPropertyThrough={mol.word.Panes.class})
    mol.word.Pane panes(
        int index);

    @VTID(13)
    mol.word.Selection selection();

    @VTID(14)
    int left();

    @VTID(15)
    void left(
        int prop);

    @VTID(16)
    int top();

    @VTID(17)
    void top(
        int prop);

    @VTID(18)
    int width();

    @VTID(19)
    void width(
        int prop);

    @VTID(20)
    int height();

    @VTID(21)
    void height(
        int prop);

    @VTID(22)
    boolean split();

    @VTID(23)
    void split(
        boolean prop);

    @VTID(24)
    int splitVertical();

    @VTID(25)
    void splitVertical(
        int prop);

    @VTID(26)
    @DefaultMethod
    java.lang.String caption();

    @VTID(27)
    @DefaultMethod
    void caption(
        java.lang.String prop);

    @VTID(28)
    mol.word.WdWindowState windowState();

    @VTID(29)
    void windowState(
        mol.word.WdWindowState prop);

    @VTID(30)
    boolean displayRulers();

    @VTID(31)
    void displayRulers(
        boolean prop);

    @VTID(32)
    boolean displayVerticalRuler();

    @VTID(33)
    void displayVerticalRuler(
        boolean prop);

    @VTID(34)
    mol.word.View view();

    @VTID(35)
    mol.word.WdWindowType type();

    @VTID(36)
    mol.word.Window next();

    @VTID(37)
    mol.word.Window previous();

    @VTID(38)
    int windowNumber();

    @VTID(39)
    boolean displayVerticalScrollBar();

    @VTID(40)
    void displayVerticalScrollBar(
        boolean prop);

    @VTID(41)
    boolean displayHorizontalScrollBar();

    @VTID(42)
    void displayHorizontalScrollBar(
        boolean prop);

    @VTID(43)
    float styleAreaWidth();

    @VTID(44)
    void styleAreaWidth(
        float prop);

    @VTID(45)
    boolean displayScreenTips();

    @VTID(46)
    void displayScreenTips(
        boolean prop);

    @VTID(47)
    int horizontalPercentScrolled();

    @VTID(48)
    void horizontalPercentScrolled(
        int prop);

    @VTID(49)
    int verticalPercentScrolled();

    @VTID(50)
    void verticalPercentScrolled(
        int prop);

    @VTID(51)
    boolean documentMap();

    @VTID(52)
    void documentMap(
        boolean prop);

    @VTID(53)
    boolean active();

    @VTID(54)
    int documentMapPercentWidth();

    @VTID(55)
    void documentMapPercentWidth(
        int prop);

    @VTID(56)
    int index();

    @VTID(57)
    mol.word.WdIMEMode imeMode();

    @VTID(58)
    void imeMode(
        mol.word.WdIMEMode prop);

    @VTID(59)
    void activate();

    @VTID(60)
    void close(
        java.lang.Object saveChanges,
        java.lang.Object routeDocument);

    @VTID(61)
    void largeScroll(
        java.lang.Object down,
        java.lang.Object up,
        java.lang.Object toRight,
        java.lang.Object toLeft);

    @VTID(62)
    void smallScroll(
        java.lang.Object down,
        java.lang.Object up,
        java.lang.Object toRight,
        java.lang.Object toLeft);

    @VTID(63)
    mol.word.Window newWindow();

    @VTID(64)
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

    @VTID(65)
    void pageScroll(
        java.lang.Object down,
        java.lang.Object up);

    @VTID(66)
    void setFocus();

    @VTID(67)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject rangeFromPoint(
        int x,
        int y);

    @VTID(68)
    void scrollIntoView(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject obj,
        java.lang.Object start);

    @VTID(69)
    void getPoint(
        Holder<Integer> screenPixelsLeft,
        Holder<Integer> screenPixelsTop,
        Holder<Integer> screenPixelsWidth,
        Holder<Integer> screenPixelsHeight,
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject obj);

    @VTID(70)
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

    @VTID(71)
    int usableWidth();

    @VTID(72)
    int usableHeight();

    @VTID(73)
    boolean envelopeVisible();

    @VTID(74)
    void envelopeVisible(
        boolean prop);

    @VTID(75)
    boolean displayRightRuler();

    @VTID(76)
    void displayRightRuler(
        boolean prop);

    @VTID(77)
    boolean displayLeftScrollBar();

    @VTID(78)
    void displayLeftScrollBar(
        boolean prop);

    @VTID(79)
    boolean visible();

    @VTID(80)
    void visible(
        boolean prop);

    @VTID(81)
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

    @VTID(82)
    void toggleShowAllReviewers();

    @VTID(83)
    boolean thumbnails();

    @VTID(84)
    void thumbnails(
        boolean prop);

    @VTID(85)
    mol.word.WdShowSourceDocuments showSourceDocuments();

    @VTID(86)
    void showSourceDocuments(
        mol.word.WdShowSourceDocuments prop);

    @VTID(87)
    void toggleRibbon();

}
