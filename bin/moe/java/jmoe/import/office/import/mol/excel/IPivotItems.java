package mol.excel  ;

import com4j.*;

@IID("{00020877-0001-0000-C000-000000000046}")
public interface IPivotItems extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    mol.excel.PivotField parent();

    @VTID(10)
    void add(
        java.lang.String name);

    @VTID(11)
    int count();

    @VTID(12)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(13)
    java.util.Iterator<Com4jObject> iterator();

}
