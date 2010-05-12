package mol.excel  ;

import com4j.*;

@IID("{000244A3-0001-0000-C000-000000000046}")
public interface IPages extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.excel.Page item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(8)
    @DefaultMethod
    mol.excel.Page _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(9)
    int count();

    @VTID(10)
    java.util.Iterator<Com4jObject> iterator();

}
