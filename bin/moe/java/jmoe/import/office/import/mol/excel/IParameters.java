package mol.excel  ;

import com4j.*;

@IID("{0002442B-0001-0000-C000-000000000046}")
public interface IParameters extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.excel.Parameter add(
        java.lang.String name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object iDataType);

    @VTID(11)
    int count();

    @VTID(12)
    mol.excel.Parameter item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(13)
    @DefaultMethod
    mol.excel.Parameter _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(14)
    void delete();

    @VTID(15)
    java.util.Iterator<Com4jObject> iterator();

}
