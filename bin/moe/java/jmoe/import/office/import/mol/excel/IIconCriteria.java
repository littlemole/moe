package mol.excel  ;

import com4j.*;

@IID("{00024498-0001-0000-C000-000000000046}")
public interface IIconCriteria extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    int count();

    @VTID(8)
    @DefaultMethod
    mol.excel.IconCriterion _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(9)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(10)
    mol.excel.IconCriterion item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

}
