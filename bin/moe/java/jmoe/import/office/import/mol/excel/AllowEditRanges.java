package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface AllowEditRanges extends Com4jObject,Iterable<Com4jObject> {
    @DISPID(118)
    @PropGet
    int count();

    @DISPID(170)
    @PropGet
    mol.excel.AllowEditRange item(
        java.lang.Object index);

    @DISPID(181)
    mol.excel.AllowEditRange add(
        java.lang.String title,
        mol.excel.Range range,
        java.lang.Object password);

    @DISPID(0)
    @PropGet
    @DefaultMethod
    mol.excel.AllowEditRange _Default(
        java.lang.Object index);

    @DISPID(-4)
    @PropGet
    java.util.Iterator<Com4jObject> iterator();

}
