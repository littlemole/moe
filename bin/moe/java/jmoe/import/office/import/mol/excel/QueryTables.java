package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface QueryTables extends Com4jObject,Iterable<Com4jObject> {
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

    @DISPID(181)
    com4j.Com4jObject add(
        java.lang.Object connection,
        mol.excel.Range destination,
        java.lang.Object sql);

    @DISPID(170)
    com4j.Com4jObject item(
        java.lang.Object index);

    @DISPID(0)
    @PropGet
    @DefaultMethod
    com4j.Com4jObject _Default(
        java.lang.Object index);

    @DISPID(-4)
    java.util.Iterator<Com4jObject> iterator();

}
