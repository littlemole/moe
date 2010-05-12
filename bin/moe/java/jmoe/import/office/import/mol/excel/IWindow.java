package mol.excel  ;

import com4j.*;

@IID("{00020893-0001-0000-C000-000000000046}")
public interface IWindow extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object activate();

    @VTID(11)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object activateNext();

    @VTID(12)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object activatePrevious();

    @VTID(13)
    mol.excel.Range activeCell();

    @VTID(14)
    mol.excel._Chart activeChart();

    @VTID(15)
    mol.excel.Pane activePane();

    @VTID(16)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject activeSheet();

    @VTID(17)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object caption();

    @VTID(18)
    void caption(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(19)
    boolean close(
        @MarshalAs(NativeType.VARIANT) java.lang.Object saveChanges,
        @MarshalAs(NativeType.VARIANT) java.lang.Object filename,
        @MarshalAs(NativeType.VARIANT) java.lang.Object routeWorkbook);

    @VTID(20)
    boolean displayFormulas();

    @VTID(21)
    void displayFormulas(
        boolean rhs);

    @VTID(22)
    boolean displayGridlines();

    @VTID(23)
    void displayGridlines(
        boolean rhs);

    @VTID(24)
    boolean displayHeadings();

    @VTID(25)
    void displayHeadings(
        boolean rhs);

    @VTID(26)
    boolean displayHorizontalScrollBar();

    @VTID(27)
    void displayHorizontalScrollBar(
        boolean rhs);

    @VTID(28)
    boolean displayOutline();

    @VTID(29)
    void displayOutline(
        boolean rhs);

    @VTID(30)
    boolean _DisplayRightToLeft();

    @VTID(31)
    void _DisplayRightToLeft(
        boolean rhs);

    @VTID(32)
    boolean displayVerticalScrollBar();

    @VTID(33)
    void displayVerticalScrollBar(
        boolean rhs);

    @VTID(34)
    boolean displayWorkbookTabs();

    @VTID(35)
    void displayWorkbookTabs(
        boolean rhs);

    @VTID(36)
    boolean displayZeros();

    @VTID(37)
    void displayZeros(
        boolean rhs);

    @VTID(38)
    boolean enableResize();

    @VTID(39)
    void enableResize(
        boolean rhs);

    @VTID(40)
    boolean freezePanes();

    @VTID(41)
    void freezePanes(
        boolean rhs);

    @VTID(42)
    int gridlineColor();

    @VTID(43)
    void gridlineColor(
        int rhs);

    @VTID(44)
    mol.excel.XlColorIndex gridlineColorIndex();

    @VTID(45)
    void gridlineColorIndex(
        mol.excel.XlColorIndex rhs);

    @VTID(46)
    double height();

    @VTID(47)
    void height(
        double rhs);

    @VTID(48)
    int index();

    @VTID(49)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object largeScroll(
        @MarshalAs(NativeType.VARIANT) java.lang.Object down,
        @MarshalAs(NativeType.VARIANT) java.lang.Object up,
        @MarshalAs(NativeType.VARIANT) java.lang.Object toRight,
        @MarshalAs(NativeType.VARIANT) java.lang.Object toLeft);

    @VTID(50)
    double left();

    @VTID(51)
    void left(
        double rhs);

    @VTID(52)
    mol.excel.Window newWindow();

    @VTID(53)
    java.lang.String onWindow();

    @VTID(54)
    void onWindow(
        java.lang.String rhs);

    @VTID(55)
    mol.excel.Panes panes();

    @VTID(56)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object _PrintOut(
        @MarshalAs(NativeType.VARIANT) java.lang.Object from,
        @MarshalAs(NativeType.VARIANT) java.lang.Object to,
        @MarshalAs(NativeType.VARIANT) java.lang.Object copies,
        @MarshalAs(NativeType.VARIANT) java.lang.Object preview,
        @MarshalAs(NativeType.VARIANT) java.lang.Object activePrinter,
        @MarshalAs(NativeType.VARIANT) java.lang.Object printToFile,
        @MarshalAs(NativeType.VARIANT) java.lang.Object collate,
        @MarshalAs(NativeType.VARIANT) java.lang.Object prToFileName);

    @VTID(57)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object printPreview(
        @MarshalAs(NativeType.VARIANT) java.lang.Object enableChanges);

    @VTID(58)
    mol.excel.Range rangeSelection();

    @VTID(59)
    int scrollColumn();

    @VTID(60)
    void scrollColumn(
        int rhs);

    @VTID(61)
    int scrollRow();

    @VTID(62)
    void scrollRow(
        int rhs);

    @VTID(63)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object scrollWorkbookTabs(
        @MarshalAs(NativeType.VARIANT) java.lang.Object sheets,
        @MarshalAs(NativeType.VARIANT) java.lang.Object position);

    @VTID(64)
    mol.excel.Sheets selectedSheets();

    @VTID(64)
    @ReturnValue(type=NativeType.Dispatch,defaultPropertyThrough={mol.excel.Sheets.class})
    com4j.Com4jObject selectedSheets(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(65)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject selection();

    @VTID(66)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object smallScroll(
        @MarshalAs(NativeType.VARIANT) java.lang.Object down,
        @MarshalAs(NativeType.VARIANT) java.lang.Object up,
        @MarshalAs(NativeType.VARIANT) java.lang.Object toRight,
        @MarshalAs(NativeType.VARIANT) java.lang.Object toLeft);

    @VTID(67)
    boolean split();

    @VTID(68)
    void split(
        boolean rhs);

    @VTID(69)
    int splitColumn();

    @VTID(70)
    void splitColumn(
        int rhs);

    @VTID(71)
    double splitHorizontal();

    @VTID(72)
    void splitHorizontal(
        double rhs);

    @VTID(73)
    int splitRow();

    @VTID(74)
    void splitRow(
        int rhs);

    @VTID(75)
    double splitVertical();

    @VTID(76)
    void splitVertical(
        double rhs);

    @VTID(77)
    double tabRatio();

    @VTID(78)
    void tabRatio(
        double rhs);

    @VTID(79)
    double top();

    @VTID(80)
    void top(
        double rhs);

    @VTID(81)
    mol.excel.XlWindowType type();

    @VTID(82)
    double usableHeight();

    @VTID(83)
    double usableWidth();

    @VTID(84)
    boolean visible();

    @VTID(85)
    void visible(
        boolean rhs);

    @VTID(86)
    mol.excel.Range visibleRange();

    @VTID(87)
    double width();

    @VTID(88)
    void width(
        double rhs);

    @VTID(89)
    int windowNumber();

    @VTID(90)
    mol.excel.XlWindowState windowState();

    @VTID(91)
    void windowState(
        mol.excel.XlWindowState rhs);

    @VTID(92)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object zoom();

    @VTID(93)
    void zoom(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(94)
    mol.excel.XlWindowView view();

    @VTID(95)
    void view(
        mol.excel.XlWindowView rhs);

    @VTID(96)
    boolean displayRightToLeft();

    @VTID(97)
    void displayRightToLeft(
        boolean rhs);

    @VTID(98)
    int pointsToScreenPixelsX(
        int points);

    @VTID(99)
    int pointsToScreenPixelsY(
        int points);

    @VTID(100)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject rangeFromPoint(
        int x,
        int y);

    @VTID(101)
    void scrollIntoView(
        int left,
        int top,
        int width,
        int height,
        @MarshalAs(NativeType.VARIANT) java.lang.Object start);

    @VTID(102)
    mol.excel.SheetViews sheetViews();

    @VTID(103)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject activeSheetView();

    @VTID(104)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object printOut(
        @MarshalAs(NativeType.VARIANT) java.lang.Object from,
        @MarshalAs(NativeType.VARIANT) java.lang.Object to,
        @MarshalAs(NativeType.VARIANT) java.lang.Object copies,
        @MarshalAs(NativeType.VARIANT) java.lang.Object preview,
        @MarshalAs(NativeType.VARIANT) java.lang.Object activePrinter,
        @MarshalAs(NativeType.VARIANT) java.lang.Object printToFile,
        @MarshalAs(NativeType.VARIANT) java.lang.Object collate,
        @MarshalAs(NativeType.VARIANT) java.lang.Object prToFileName);

    @VTID(105)
    boolean displayRuler();

    @VTID(106)
    void displayRuler(
        boolean rhs);

    @VTID(107)
    boolean autoFilterDateGrouping();

    @VTID(108)
    void autoFilterDateGrouping(
        boolean rhs);

    @VTID(109)
    boolean displayWhitespace();

    @VTID(110)
    void displayWhitespace(
        boolean rhs);

}
