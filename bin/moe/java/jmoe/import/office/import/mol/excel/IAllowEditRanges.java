package mol.excel  ;

import com4j.*;

@IID("{0002446A-0001-0000-C000-000000000046}")
public interface IAllowEditRanges extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    int count();

    @VTID(8)
    mol.excel.AllowEditRange item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(9)
    mol.excel.AllowEditRange add(
        java.lang.String title,
        mol.excel.Range range,
        @MarshalAs(NativeType.VARIANT) java.lang.Object password);

    @VTID(10)
    @DefaultMethod
    mol.excel.AllowEditRange _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(11)
    java.util.Iterator<Com4jObject> iterator();

}
