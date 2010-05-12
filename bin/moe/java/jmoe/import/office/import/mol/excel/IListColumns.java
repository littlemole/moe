package mol.excel  ;

import com4j.*;

@IID("{00024472-0001-0000-C000-000000000046}")
public interface IListColumns extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.excel.ListColumn add(
        @MarshalAs(NativeType.VARIANT) java.lang.Object position);

    @VTID(11)
    @DefaultMethod
    mol.excel.ListColumn _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(12)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(13)
    mol.excel.ListColumn item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(14)
    int count();

}
