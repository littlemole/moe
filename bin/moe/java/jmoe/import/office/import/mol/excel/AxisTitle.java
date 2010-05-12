package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface AxisTitle extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(110)
    @PropGet
    java.lang.String name();

    @DISPID(235)
    java.lang.Object select();

    @DISPID(128)
    @PropGet
    mol.excel.Border border();

    @DISPID(117)
    java.lang.Object delete();

    @DISPID(129)
    @PropGet
    mol.excel.Interior interior();

    @DISPID(1663)
    @PropGet
    mol.excel.ChartFillFormat fill();

    @DISPID(139)
    @PropGet
    java.lang.String caption();

    @DISPID(139)
    @PropPut
    void caption(
        java.lang.String rhs);

    @DISPID(603)
    @PropGet
    mol.excel.Characters characters(
        java.lang.Object start,
        java.lang.Object length);

    @DISPID(146)
    @PropGet
    mol.excel.Font font();

    @DISPID(136)
    @PropGet
    java.lang.Object horizontalAlignment();

    @DISPID(136)
    @PropPut
    void horizontalAlignment(
        java.lang.Object rhs);

    @DISPID(127)
    @PropGet
    double left();

    @DISPID(127)
    @PropPut
    void left(
        double rhs);

    @DISPID(134)
    @PropGet
    java.lang.Object orientation();

    @DISPID(134)
    @PropPut
    void orientation(
        java.lang.Object rhs);

    @DISPID(103)
    @PropGet
    boolean shadow();

    @DISPID(103)
    @PropPut
    void shadow(
        boolean rhs);

    @DISPID(138)
    @PropGet
    java.lang.String text();

    @DISPID(138)
    @PropPut
    void text(
        java.lang.String rhs);

    @DISPID(126)
    @PropGet
    double top();

    @DISPID(126)
    @PropPut
    void top(
        double rhs);

    @DISPID(137)
    @PropGet
    java.lang.Object verticalAlignment();

    @DISPID(137)
    @PropPut
    void verticalAlignment(
        java.lang.Object rhs);

    @DISPID(975)
    @PropGet
    int readingOrder();

    @DISPID(975)
    @PropPut
    void readingOrder(
        int rhs);

    @DISPID(1525)
    @PropGet
    java.lang.Object autoScaleFont();

    @DISPID(1525)
    @PropPut
    void autoScaleFont(
        java.lang.Object rhs);

    @DISPID(2648)
    @PropGet
    boolean includeInLayout();

    @DISPID(2648)
    @PropPut
    void includeInLayout(
        boolean rhs);

    @DISPID(133)
    @PropGet
    mol.excel.XlChartElementPosition position();

    @DISPID(133)
    @PropPut
    void position(
        mol.excel.XlChartElementPosition rhs);

    @DISPID(116)
    @PropGet
    mol.excel.ChartFormat format();

}
