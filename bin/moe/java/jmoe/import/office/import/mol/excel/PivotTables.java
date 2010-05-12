package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface PivotTables extends Com4jObject,Iterable<Com4jObject> {
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
    mol.excel.PivotTable item(
        java.lang.Object index);

    @DISPID(-4)
    java.util.Iterator<Com4jObject> iterator();

    @DISPID(181)
    mol.excel.PivotTable add(
        mol.excel.PivotCache pivotCache,
        java.lang.Object tableDestination,
        java.lang.Object tableName,
        java.lang.Object readData,
        java.lang.Object defaultVersion);

}
