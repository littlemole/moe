package mol.excel  ;

import com4j.*;

@IID("{00020853-0001-0000-C000-000000000046}")
public interface IStyles extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.excel.Style add(
        java.lang.String name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object basedOn);

    @VTID(11)
    int count();

    @VTID(12)
    mol.excel.Style item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(13)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object merge(
        @MarshalAs(NativeType.VARIANT) java.lang.Object workbook);

    @VTID(14)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(15)
    @DefaultMethod
    mol.excel.Style _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

}
