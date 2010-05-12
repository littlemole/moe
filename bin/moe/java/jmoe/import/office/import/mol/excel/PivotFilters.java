package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface PivotFilters extends Com4jObject,Iterable<Com4jObject> {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(0)
    @PropGet
    @DefaultMethod
    mol.excel.PivotFilter _Default(
        java.lang.Object index);

    @DISPID(-4)
    @PropGet
    java.util.Iterator<Com4jObject> iterator();

    @DISPID(170)
    @PropGet
    mol.excel.PivotFilter item(
        java.lang.Object index);

    @DISPID(118)
    @PropGet
    int count();

    @DISPID(181)
    mol.excel.PivotFilter add(
        mol.excel.XlPivotFilterType type,
        java.lang.Object dataField,
        java.lang.Object value1,
        java.lang.Object value2,
        java.lang.Object order,
        java.lang.Object name,
        java.lang.Object description,
        java.lang.Object memberPropertyField);

}
