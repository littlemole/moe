package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface RecentFiles extends Com4jObject,Iterable<Com4jObject> {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(1423)
    @PropGet
    int maximum();

    @DISPID(1423)
    @PropPut
    void maximum(
        int rhs);

    @DISPID(118)
    @PropGet
    int count();

    @DISPID(170)
    @PropGet
    mol.excel.RecentFile item(
        int index);

    @DISPID(0)
    @PropGet
    @DefaultMethod
    mol.excel.RecentFile _Default(
        int index);

    @DISPID(181)
    mol.excel.RecentFile add(
        java.lang.String name);

    @DISPID(-4)
    @PropGet
    java.util.Iterator<Com4jObject> iterator();

}
