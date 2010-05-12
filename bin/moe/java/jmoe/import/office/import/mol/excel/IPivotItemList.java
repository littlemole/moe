package mol.excel  ;

import com4j.*;

@IID("{00024468-0001-0000-C000-000000000046}")
public interface IPivotItemList extends Com4jObject,Iterable<Com4jObject> {
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
    mol.excel.PivotItem item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(12)
    @DefaultMethod
    mol.excel.PivotItem _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object field);

    @VTID(13)
    java.util.Iterator<Com4jObject> iterator();

}
