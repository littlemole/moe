package mol.excel  ;

import com4j.*;

@IID("{00024452-0001-0000-C000-000000000046}")
public interface ICustomProperties extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.excel.CustomProperty add(
        java.lang.String name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object value);

    @VTID(11)
    int count();

    @VTID(12)
    @DefaultMethod
    mol.excel.CustomProperty _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(13)
    mol.excel.CustomProperty item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(14)
    java.util.Iterator<Com4jObject> iterator();

}