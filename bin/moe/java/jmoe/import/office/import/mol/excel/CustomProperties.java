package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface CustomProperties extends Com4jObject,Iterable<Com4jObject> {
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
    mol.excel.CustomProperty add(
        java.lang.String name,
        java.lang.Object value);

    @DISPID(118)
    @PropGet
    int count();

    @DISPID(0)
    @PropGet
    @DefaultMethod
    mol.excel.CustomProperty _Default(
        java.lang.Object index);

    @DISPID(170)
    @PropGet
    mol.excel.CustomProperty item(
        java.lang.Object index);

    @DISPID(-4)
    @PropGet
    java.util.Iterator<Com4jObject> iterator();

}