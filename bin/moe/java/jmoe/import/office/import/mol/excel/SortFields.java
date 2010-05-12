package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface SortFields extends Com4jObject,Iterable<Com4jObject> {
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
    mol.excel.SortField add(
        mol.excel.Range key,
        java.lang.Object sortOn,
        java.lang.Object order,
        java.lang.Object customOrder,
        java.lang.Object dataOption);

    @DISPID(170)
    @PropGet
    mol.excel.SortField item(
        java.lang.Object index);

    @DISPID(118)
    @PropGet
    int count();

    @DISPID(111)
    void clear();

    @DISPID(0)
    @PropGet
    @DefaultMethod
    mol.excel.SortField _Default(
        java.lang.Object index);

    @DISPID(-4)
    @PropGet
    java.util.Iterator<Com4jObject> iterator();

}
