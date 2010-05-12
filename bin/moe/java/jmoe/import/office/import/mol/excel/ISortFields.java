package mol.excel  ;

import com4j.*;

@IID("{000244AA-0001-0000-C000-000000000046}")
public interface ISortFields extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.excel.SortField add(
        mol.excel.Range key,
        @MarshalAs(NativeType.VARIANT) java.lang.Object sortOn,
        @MarshalAs(NativeType.VARIANT) java.lang.Object order,
        @MarshalAs(NativeType.VARIANT) java.lang.Object customOrder,
        @MarshalAs(NativeType.VARIANT) java.lang.Object dataOption);

    @VTID(11)
    mol.excel.SortField item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(12)
    int count();

    @VTID(13)
    void clear();

    @VTID(14)
    @DefaultMethod
    mol.excel.SortField _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(15)
    java.util.Iterator<Com4jObject> iterator();

}
