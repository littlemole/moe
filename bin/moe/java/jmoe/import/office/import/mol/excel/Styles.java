package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Styles extends Com4jObject,Iterable<Com4jObject> {
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
    mol.excel.Style add(
        java.lang.String name,
        java.lang.Object basedOn);

    @DISPID(118)
    @PropGet
    int count();

    @DISPID(170)
    @PropGet
    mol.excel.Style item(
        java.lang.Object index);

    @DISPID(564)
    java.lang.Object merge(
        java.lang.Object workbook);

    @DISPID(-4)
    @PropGet
    java.util.Iterator<Com4jObject> iterator();

    @DISPID(0)
    @PropGet
    @DefaultMethod
    mol.excel.Style _Default(
        java.lang.Object index);

}