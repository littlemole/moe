package mol.excel  ;

import com4j.*;

@IID("{0002441D-0001-0000-C000-000000000046}")
public interface IPivotCaches extends Com4jObject,Iterable<Com4jObject> {
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
    mol.excel.PivotCache item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(12)
    @DefaultMethod
    mol.excel.PivotCache _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(13)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(14)
    mol.excel.PivotCache add(
        mol.excel.XlPivotTableSourceType sourceType,
        @MarshalAs(NativeType.VARIANT) java.lang.Object sourceData);

    @VTID(15)
    mol.excel.PivotCache create(
        mol.excel.XlPivotTableSourceType sourceType,
        @MarshalAs(NativeType.VARIANT) java.lang.Object sourceData,
        @MarshalAs(NativeType.VARIANT) java.lang.Object version);

}
