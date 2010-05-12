package mol.excel  ;

import com4j.*;

@IID("{0002444A-0001-0000-C000-000000000046}")
public interface IPivotLayout extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject columnFields(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(11)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject dataFields(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(12)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject pageFields(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(13)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject rowFields(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(14)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject hiddenFields(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(15)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject visibleFields(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(16)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject pivotFields(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(17)
    mol.excel.CubeFields cubeFields();

    @VTID(17)
    @ReturnValue(defaultPropertyThrough={mol.excel.CubeFields.class})
    mol.excel.CubeField cubeFields(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(18)
    mol.excel.PivotCache pivotCache();

    @VTID(19)
    mol.excel.PivotTable pivotTable();

    @VTID(20)
    java.lang.String innerDetail();

    @VTID(21)
    void innerDetail(
        java.lang.String rhs);

    @VTID(22)
    void addFields(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rowFields,
        @MarshalAs(NativeType.VARIANT) java.lang.Object columnFields,
        @MarshalAs(NativeType.VARIANT) java.lang.Object pageFields,
        @MarshalAs(NativeType.VARIANT) java.lang.Object appendField);

}
