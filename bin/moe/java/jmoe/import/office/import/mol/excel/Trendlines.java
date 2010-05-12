package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Trendlines extends Com4jObject,Iterable<Com4jObject> {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(181)
    mol.excel.Trendline add(
        mol.excel.XlTrendlineType type,
        java.lang.Object order,
        java.lang.Object period,
        java.lang.Object forward,
        java.lang.Object backward,
        java.lang.Object intercept,
        java.lang.Object displayEquation,
        java.lang.Object displayRSquared,
        java.lang.Object name);

    @DISPID(118)
    @PropGet
    int count();

    @DISPID(170)
    mol.excel.Trendline item(
        java.lang.Object index);

    @DISPID(-4)
    java.util.Iterator<Com4jObject> iterator();

    @DISPID(0)
    @DefaultMethod
    mol.excel.Trendline _Default(
        java.lang.Object index);

}
