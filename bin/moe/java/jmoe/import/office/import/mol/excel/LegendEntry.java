package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface LegendEntry extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(117)
    java.lang.Object delete();

    @DISPID(146)
    @PropGet
    mol.excel.Font font();

    @DISPID(486)
    @PropGet
    int index();

    @DISPID(174)
    @PropGet
    mol.excel.LegendKey legendKey();

    @DISPID(235)
    java.lang.Object select();

    @DISPID(1525)
    @PropGet
    java.lang.Object autoScaleFont();

    @DISPID(1525)
    @PropPut
    void autoScaleFont(
        java.lang.Object rhs);

    @DISPID(127)
    @PropGet
    double left();

    @DISPID(126)
    @PropGet
    double top();

    @DISPID(122)
    @PropGet
    double width();

    @DISPID(123)
    @PropGet
    double height();

    @DISPID(116)
    @PropGet
    mol.excel.ChartFormat format();

}
