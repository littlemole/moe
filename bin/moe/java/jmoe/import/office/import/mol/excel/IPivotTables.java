package mol.excel  ;

import com4j.*;

@IID("{00020873-0001-0000-C000-000000000046}")
public interface IPivotTables extends Com4jObject,Iterable<Com4jObject> {
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
    mol.excel.PivotTable item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(12)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(13)
    mol.excel.PivotTable add(
        mol.excel.PivotCache pivotCache,
        @MarshalAs(NativeType.VARIANT) java.lang.Object tableDestination,
        @MarshalAs(NativeType.VARIANT) java.lang.Object tableName,
        @MarshalAs(NativeType.VARIANT) java.lang.Object readData,
        @MarshalAs(NativeType.VARIANT) java.lang.Object defaultVersion);

}
