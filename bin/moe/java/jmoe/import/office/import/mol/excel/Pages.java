package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Pages extends Com4jObject,Iterable<Com4jObject> {
    @DISPID(170)
    @PropGet
    mol.excel.Page item(
        java.lang.Object index);

    @DISPID(0)
    @PropGet
    @DefaultMethod
    mol.excel.Page _Default(
        java.lang.Object index);

    @DISPID(118)
    @PropGet
    int count();

    @DISPID(-4)
    @PropGet
    java.util.Iterator<Com4jObject> iterator();

}
