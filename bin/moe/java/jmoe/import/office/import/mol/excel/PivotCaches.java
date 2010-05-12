package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface PivotCaches extends Com4jObject,Iterable<Com4jObject> {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(118)
    @PropGet
    int count();

    @DISPID(170)
    mol.excel.PivotCache item(
        java.lang.Object index);

    @DISPID(0)
    @PropGet
    @DefaultMethod
    mol.excel.PivotCache _Default(
        java.lang.Object index);

    @DISPID(-4)
    java.util.Iterator<Com4jObject> iterator();

    @DISPID(181)
    mol.excel.PivotCache add(
        mol.excel.XlPivotTableSourceType sourceType,
        java.lang.Object sourceData);

    @DISPID(1896)
    mol.excel.PivotCache create(
        mol.excel.XlPivotTableSourceType sourceType,
        java.lang.Object sourceData,
        java.lang.Object version);

}
