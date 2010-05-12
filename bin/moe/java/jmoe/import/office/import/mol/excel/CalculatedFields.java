package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface CalculatedFields extends Com4jObject,Iterable<Com4jObject> {
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

    @DISPID(2085)
    mol.excel.PivotField _Add(
        java.lang.String name,
        java.lang.String formula);

    @DISPID(170)
    mol.excel.PivotField item(
        java.lang.Object index);

    @DISPID(0)
    @PropGet
    @DefaultMethod
    mol.excel.PivotField _Default(
        java.lang.Object field);

    @DISPID(-4)
    java.util.Iterator<Com4jObject> iterator();

    @DISPID(181)
    mol.excel.PivotField add(
        java.lang.String name,
        java.lang.String formula,
        java.lang.Object useStandardFormula);

}
