package mol.excel  ;

import com4j.*;

@IID("{00024421-0001-0000-C000-000000000046}")
public interface ICalculatedItems extends Com4jObject,Iterable<Com4jObject> {
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
    mol.excel.PivotItem _Add(
        java.lang.String name,
        java.lang.String formula);

    @VTID(12)
    mol.excel.PivotItem item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(13)
    @DefaultMethod
    mol.excel.PivotItem _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object field);

    @VTID(14)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(15)
    mol.excel.PivotItem add(
        java.lang.String name,
        java.lang.String formula,
        @MarshalAs(NativeType.VARIANT) java.lang.Object useStandardFormula);

}
