package mol.excel  ;

import com4j.*;

@IID("{0002446C-0001-0000-C000-000000000046}")
public interface IUserAccessList extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    int count();

    @VTID(8)
    mol.excel.UserAccess item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(9)
    mol.excel.UserAccess add(
        java.lang.String name,
        boolean allowEdit);

    @VTID(10)
    void deleteAll();

    @VTID(11)
    @DefaultMethod
    mol.excel.UserAccess _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(12)
    java.util.Iterator<Com4jObject> iterator();

}
