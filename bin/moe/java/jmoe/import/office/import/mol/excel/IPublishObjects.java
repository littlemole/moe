package mol.excel  ;

import com4j.*;

@IID("{00024443-0001-0000-C000-000000000046}")
public interface IPublishObjects extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.excel.PublishObject add(
        mol.excel.XlSourceType sourceType,
        java.lang.String filename,
        @MarshalAs(NativeType.VARIANT) java.lang.Object sheet,
        @MarshalAs(NativeType.VARIANT) java.lang.Object source,
        @MarshalAs(NativeType.VARIANT) java.lang.Object htmlType,
        @MarshalAs(NativeType.VARIANT) java.lang.Object divID,
        @MarshalAs(NativeType.VARIANT) java.lang.Object title);

    @VTID(11)
    int count();

    @VTID(12)
    mol.excel.PublishObject item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(13)
    @DefaultMethod
    mol.excel.PublishObject _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(14)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(15)
    void delete();

    @VTID(16)
    void publish();

}
