package mol.excel  ;

import com4j.*;

@IID("{00024494-0001-0000-C000-000000000046}")
public interface IColorScaleCriteria extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    int count();

    @VTID(8)
    @DefaultMethod
    mol.excel.ColorScaleCriterion _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(9)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(10)
    mol.excel.ColorScaleCriterion item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

}
