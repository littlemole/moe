package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Legend extends Com4jObject {
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

    @DISPID(146)
    @PropGet
    mol.excel.Font font();

    @DISPID(173)
    com4j.Com4jObject legendEntries(
        java.lang.Object index);

    @DISPID(133)
    @PropGet
    mol.excel.XlLegendPosition position();

    @DISPID(133)
    @PropPut
    void position(
        mol.excel.XlLegendPosition rhs);

    @DISPID(103)
    @PropGet
    boolean shadow();

    @DISPID(103)
    @PropPut
    void shadow(
        boolean rhs);

    @DISPID(111)
    java.lang.Object clear();

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

    @DISPID(116)
    @PropGet
    mol.excel.ChartFormat format();

}
