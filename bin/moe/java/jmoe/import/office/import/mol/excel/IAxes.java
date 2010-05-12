package mol.excel  ;

import com4j.*;

@IID("{0002085B-0001-0000-C000-000000000046}")
public interface IAxes extends Com4jObject,Iterable<Com4jObject> {
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
    mol.excel.Axis item(
        mol.excel.XlAxisType type,
        mol.excel.XlAxisGroup axisGroup);

    @VTID(12)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(13)
    @DefaultMethod
    mol.excel.Axis _Default(
        mol.excel.XlAxisType type,
        mol.excel.XlAxisGroup axisGroup);

}
