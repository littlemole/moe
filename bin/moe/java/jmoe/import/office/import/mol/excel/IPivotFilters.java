package mol.excel  ;

import com4j.*;

@IID("{00024484-0001-0000-C000-000000000046}")
public interface IPivotFilters extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @DefaultMethod
    mol.excel.PivotFilter _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(11)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(12)
    mol.excel.PivotFilter item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(13)
    int count();

    @VTID(14)
    mol.excel.PivotFilter add(
        mol.excel.XlPivotFilterType type,
        @MarshalAs(NativeType.VARIANT) java.lang.Object dataField,
        @MarshalAs(NativeType.VARIANT) java.lang.Object value1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object value2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object order,
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object description,
        @MarshalAs(NativeType.VARIANT) java.lang.Object memberPropertyField);

}
