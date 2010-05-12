package mol.excel  ;

import com4j.*;

@IID("{000208BB-0001-0000-C000-000000000046}")
public interface ILegendEntries extends Com4jObject,Iterable<Com4jObject> {
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
    mol.excel.LegendEntry item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(12)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(13)
    @DefaultMethod
    mol.excel.LegendEntry _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

}
