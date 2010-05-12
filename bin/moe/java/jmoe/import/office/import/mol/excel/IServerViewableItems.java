package mol.excel  ;

import com4j.*;

@IID("{000244A4-0001-0000-C000-000000000046}")
public interface IServerViewableItems extends Com4jObject,Iterable<Com4jObject> {
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
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject add(
        @MarshalAs(NativeType.VARIANT) java.lang.Object obj);

    @VTID(12)
    void delete(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(13)
    void deleteAll();

    @VTID(14)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(15)
    @DefaultMethod
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(16)
    java.util.Iterator<Com4jObject> iterator();

}
