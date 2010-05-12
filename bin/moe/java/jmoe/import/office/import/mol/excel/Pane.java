package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Pane extends Com4jObject {
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
    boolean activate();

    @DISPID(486)
    @PropGet
    int index();

    @DISPID(547)
    java.lang.Object largeScroll(
        java.lang.Object down,
        java.lang.Object up,
        java.lang.Object toRight,
        java.lang.Object toLeft);

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

    @DISPID(548)
    java.lang.Object smallScroll(
        java.lang.Object down,
        java.lang.Object up,
        java.lang.Object toRight,
        java.lang.Object toLeft);

    @DISPID(1118)
    @PropGet
    mol.excel.Range visibleRange();

    @DISPID(1781)
    void scrollIntoView(
        int left,
        int top,
        int width,
        int height,
        java.lang.Object start);

    @DISPID(1776)
    int pointsToScreenPixelsX(
        int points);

    @DISPID(1777)
    int pointsToScreenPixelsY(
        int points);

}
