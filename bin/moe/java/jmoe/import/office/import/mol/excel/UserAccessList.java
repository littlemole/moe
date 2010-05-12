package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface UserAccessList extends Com4jObject,Iterable<Com4jObject> {
    @DISPID(118)
    @PropGet
    int count();

    @DISPID(170)
    @PropGet
    mol.excel.UserAccess item(
        java.lang.Object index);

    @DISPID(181)
    mol.excel.UserAccess add(
        java.lang.String name,
        boolean allowEdit);

    @DISPID(2239)
    void deleteAll();

    @DISPID(0)
    @PropGet
    @DefaultMethod
    mol.excel.UserAccess _Default(
        java.lang.Object index);

    @DISPID(-4)
    @PropGet
    java.util.Iterator<Com4jObject> iterator();

}
