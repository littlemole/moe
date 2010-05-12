package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Window extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(304)
    java.lang.Object activate();

    @DISPID(1115)
    java.lang.Object activateNext();

    @DISPID(1116)
    java.lang.Object activatePrevious();

    @DISPID(305)
    @PropGet
    mol.excel.Range activeCell();

    @DISPID(183)
    @PropGet
    mol.excel._Chart activeChart();

    @DISPID(642)
    @PropGet
    mol.excel.Pane activePane();

    @DISPID(307)
    @PropGet
    com4j.Com4jObject activeSheet();

    @DISPID(139)
    @PropGet
    java.lang.Object caption();

    @DISPID(139)
    @PropPut
    void caption(
        java.lang.Object rhs);

    @DISPID(277)
    boolean close(
        java.lang.Object saveChanges,
        java.lang.Object filename,
        java.lang.Object routeWorkbook);

    @DISPID(644)
    @PropGet
    boolean displayFormulas();

    @DISPID(644)
    @PropPut
    void displayFormulas(
        boolean rhs);

    @DISPID(645)
    @PropGet
    boolean displayGridlines();

    @DISPID(645)
    @PropPut
    void displayGridlines(
        boolean rhs);

    @DISPID(646)
    @PropGet
    boolean displayHeadings();

    @DISPID(646)
    @PropPut
    void displayHeadings(
        boolean rhs);

    @DISPID(921)
    @PropGet
    boolean displayHorizontalScrollBar();

    @DISPID(921)
    @PropPut
    void displayHorizontalScrollBar(
        boolean rhs);

    @DISPID(647)
    @PropGet
    boolean displayOutline();

    @DISPID(647)
    @PropPut
    void displayOutline(
        boolean rhs);

    @DISPID(648)
    @PropGet
    boolean _DisplayRightToLeft();

    @DISPID(648)
    @PropPut
    void _DisplayRightToLeft(
        boolean rhs);

    @DISPID(922)
    @PropGet
    boolean displayVerticalScrollBar();

    @DISPID(922)
    @PropPut
    void displayVerticalScrollBar(
        boolean rhs);

    @DISPID(923)
    @PropGet
    boolean displayWorkbookTabs();

    @DISPID(923)
    @PropPut
    void displayWorkbookTabs(
        boolean rhs);

    @DISPID(649)
    @PropGet
    boolean displayZeros();

    @DISPID(649)
    @PropPut
    void displayZeros(
        boolean rhs);

    @DISPID(1192)
    @PropGet
    boolean enableResize();

    @DISPID(1192)
    @PropPut
    void enableResize(
        boolean rhs);

    @DISPID(650)
    @PropGet
    boolean freezePanes();

    @DISPID(650)
    @PropPut
    void freezePanes(
        boolean rhs);

    @DISPID(651)
    @PropGet
    int gridlineColor();

    @DISPID(651)
    @PropPut
    void gridlineColor(
        int rhs);

    @DISPID(652)
    @PropGet
    mol.excel.XlColorIndex gridlineColorIndex();

    @DISPID(652)
    @PropPut
    void gridlineColorIndex(
        mol.excel.XlColorIndex rhs);

    @DISPID(123)
    @PropGet
    double height();

    @DISPID(123)
    @PropPut
    void height(
        double rhs);

    @DISPID(486)
    @PropGet
    int index();

    @DISPID(547)
    java.lang.Object largeScroll(
        java.lang.Object down,
        java.lang.Object up,
        java.lang.Object toRight,
        java.lang.Object toLeft);

    @DISPID(127)
    @PropGet
    double left();

    @DISPID(127)
    @PropPut
    void left(
        double rhs);

    @DISPID(280)
    mol.excel.Window newWindow();

    @DISPID(623)
    @PropGet
    java.lang.String onWindow();

    @DISPID(623)
    @PropPut
    void onWindow(
        java.lang.String rhs);

    @DISPID(653)
    @PropGet
    mol.excel.Panes panes();

    @DISPID(1772)
    java.lang.Object _PrintOut(
        java.lang.Object from,
        java.lang.Object to,
        java.lang.Object copies,
        java.lang.Object preview,
        java.lang.Object activePrinter,
        java.lang.Object printToFile,
        java.lang.Object collate,
        java.lang.Object prToFileName);

    @DISPID(281)
    java.lang.Object printPreview(
        java.lang.Object enableChanges);

    @DISPID(1189)
    @PropGet
    mol.excel.Range rangeSelection();

    @DISPID(654)
    @PropGet
    int scrollColumn();

    @DISPID(654)
    @PropPut
    void scrollColumn(
        int rhs);

    @DISPID(655)
    @PropGet
    int scrollRow();

    @DISPID(655)
    @PropPut
    void scrollRow(
        int rhs);

    @DISPID(662)
    java.lang.Object scrollWorkbookTabs(
        java.lang.Object sheets,
        java.lang.Object position);

    @DISPID(656)
    @PropGet
    mol.excel.Sheets selectedSheets();

    @DISPID(147)
    @PropGet
    com4j.Com4jObject selection();

    @DISPID(548)
    java.lang.Object smallScroll(
        java.lang.Object down,
        java.lang.Object up,
        java.lang.Object toRight,
        java.lang.Object toLeft);

    @DISPID(657)
    @PropGet
    boolean split();

    @DISPID(657)
    @PropPut
    void split(
        boolean rhs);

    @DISPID(658)
    @PropGet
    int splitColumn();

    @DISPID(658)
    @PropPut
    void splitColumn(
        int rhs);

    @DISPID(659)
    @PropGet
    double splitHorizontal();

    @DISPID(659)
    @PropPut
    void splitHorizontal(
        double rhs);

    @DISPID(660)
    @PropGet
    int splitRow();

    @DISPID(660)
    @PropPut
    void splitRow(
        int rhs);

    @DISPID(661)
    @PropGet
    double splitVertical();

    @DISPID(661)
    @PropPut
    void splitVertical(
        double rhs);

    @DISPID(673)
    @PropGet
    double tabRatio();

    @DISPID(673)
    @PropPut
    void tabRatio(
        double rhs);

    @DISPID(126)
    @PropGet
    double top();

    @DISPID(126)
    @PropPut
    void top(
        double rhs);

    @DISPID(108)
    @PropGet
    mol.excel.XlWindowType type();

    @DISPID(389)
    @PropGet
    double usableHeight();

    @DISPID(390)
    @PropGet
    double usableWidth();

    @DISPID(558)
    @PropGet
    boolean visible();

    @DISPID(558)
    @PropPut
    void visible(
        boolean rhs);

    @DISPID(1118)
    @PropGet
    mol.excel.Range visibleRange();

    @DISPID(122)
    @PropGet
    double width();

    @DISPID(122)
    @PropPut
    void width(
        double rhs);

    @DISPID(1119)
    @PropGet
    int windowNumber();

    @DISPID(396)
    @PropGet
    mol.excel.XlWindowState windowState();

    @DISPID(396)
    @PropPut
    void windowState(
        mol.excel.XlWindowState rhs);

    @DISPID(663)
    @PropGet
    java.lang.Object zoom();

    @DISPID(663)
    @PropPut
    void zoom(
        java.lang.Object rhs);

    @DISPID(1194)
    @PropGet
    mol.excel.XlWindowView view();

    @DISPID(1194)
    @PropPut
    void view(
        mol.excel.XlWindowView rhs);

    @DISPID(1774)
    @PropGet
    boolean displayRightToLeft();

    @DISPID(1774)
    @PropPut
    void displayRightToLeft(
        boolean rhs);

    @DISPID(1776)
    int pointsToScreenPixelsX(
        int points);

    @DISPID(1777)
    int pointsToScreenPixelsY(
        int points);

    @DISPID(1778)
    com4j.Com4jObject rangeFromPoint(
        int x,
        int y);

    @DISPID(1781)
    void scrollIntoView(
        int left,
        int top,
        int width,
        int height,
        java.lang.Object start);

    @DISPID(2368)
    @PropGet
    mol.excel.SheetViews sheetViews();

    @DISPID(2369)
    @PropGet
    com4j.Com4jObject activeSheetView();

    @DISPID(2361)
    java.lang.Object printOut(
        java.lang.Object from,
        java.lang.Object to,
        java.lang.Object copies,
        java.lang.Object preview,
        java.lang.Object activePrinter,
        java.lang.Object printToFile,
        java.lang.Object collate,
        java.lang.Object prToFileName);

    @DISPID(2370)
    @PropGet
    boolean displayRuler();

    @DISPID(2370)
    @PropPut
    void displayRuler(
        boolean rhs);

    @DISPID(2371)
    @PropGet
    boolean autoFilterDateGrouping();

    @DISPID(2371)
    @PropPut
    void autoFilterDateGrouping(
        boolean rhs);

    @DISPID(2372)
    @PropGet
    boolean displayWhitespace();

    @DISPID(2372)
    @PropPut
    void displayWhitespace(
        boolean rhs);

}
