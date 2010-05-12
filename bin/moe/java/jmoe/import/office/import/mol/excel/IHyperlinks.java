package mol.excel  ;

import com4j.*;

@IID("{00024430-0001-0000-C000-000000000046}")
public interface IHyperlinks extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject add(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject anchor,
        java.lang.String address,
        @MarshalAs(NativeType.VARIANT) java.lang.Object subAddress,
        @MarshalAs(NativeType.VARIANT) java.lang.Object screenTip,
        @MarshalAs(NativeType.VARIANT) java.lang.Object textToDisplay);

    @VTID(11)
    int count();

    @VTID(12)
    mol.excel.Hyperlink item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(13)
    @DefaultMethod
    mol.excel.Hyperlink _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(14)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(15)
    void delete();

}
