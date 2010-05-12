package mol.excel  ;

import com4j.*;

@IID("{00024429-0001-0000-C000-000000000046}")
public interface IQueryTables extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    int count();

    @VTID(11)
    com4j.Com4jObject add(
        @MarshalAs(NativeType.VARIANT) java.lang.Object connection,
        mol.excel.Range destination,
        @MarshalAs(NativeType.VARIANT) java.lang.Object sql);

    @VTID(12)
    com4j.Com4jObject item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(13)
    @DefaultMethod
    com4j.Com4jObject _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(14)
    java.util.Iterator<Com4jObject> iterator();

}
