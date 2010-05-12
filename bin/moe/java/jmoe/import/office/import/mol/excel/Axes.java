package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Axes extends Com4jObject,Iterable<Com4jObject> {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(118)
    @PropGet
    int count();

    @DISPID(170)
    mol.excel.Axis item(
        mol.excel.XlAxisType type,
        mol.excel.XlAxisGroup axisGroup);

    @DISPID(-4)
    java.util.Iterator<Com4jObject> iterator();

    @DISPID(0)
    @DefaultMethod
    mol.excel.Axis _Default(
        mol.excel.XlAxisType type,
        mol.excel.XlAxisGroup axisGroup);

}
