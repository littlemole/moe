package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface PlotArea extends Com4jObject {
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

    @DISPID(112)
    java.lang.Object clearFormats();

    @DISPID(123)
    @PropGet
    double height();

    @DISPID(123)
    @PropPut
    void height(
        double rhs);

    @DISPID(129)
    @PropGet
    mol.excel.Interior interior();

    @DISPID(1663)
    @PropGet
    mol.excel.ChartFillFormat fill();

    @DISPID(127)
    @PropGet
    double left();

    @DISPID(127)
    @PropPut
    void left(
        double rhs);

    @DISPID(126)
    @PropGet
    double top();

    @DISPID(126)
    @PropPut
    void top(
        double rhs);

    @DISPID(122)
    @PropGet
    double width();

    @DISPID(122)
    @PropPut
    void width(
        double rhs);

    @DISPID(2654)
    @PropGet
    double _InsideLeft();

    @DISPID(2655)
    @PropGet
    double _InsideTop();

    @DISPID(2656)
    @PropGet
    double _InsideWidth();

    @DISPID(2657)
    @PropGet
    double _InsideHeight();

    @DISPID(1667)
    @PropGet
    double insideLeft();

    @DISPID(1667)
    @PropPut
    void insideLeft(
        double rhs);

    @DISPID(1668)
    @PropGet
    double insideTop();

    @DISPID(1668)
    @PropPut
    void insideTop(
        double rhs);

    @DISPID(1669)
    @PropGet
    double insideWidth();

    @DISPID(1669)
    @PropPut
    void insideWidth(
        double rhs);

    @DISPID(1670)
    @PropGet
    double insideHeight();

    @DISPID(1670)
    @PropPut
    void insideHeight(
        double rhs);

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
