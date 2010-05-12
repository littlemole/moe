package mol.excel  ;

import com4j.*;

@IID("{00020875-0001-0000-C000-000000000046}")
public interface IPivotFields extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    mol.excel.PivotTable parent();

    @VTID(10)
    int count();

    @VTID(11)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(12)
    java.util.Iterator<Com4jObject> iterator();

}
