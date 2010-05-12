package mol.excel  ;

import com4j.*;

@IID("{00024499-0001-0000-C000-000000000046}")
public interface IIconCriterion extends Com4jObject {
    @VTID(7)
    int index();

    @VTID(8)
    mol.excel.XlConditionValueTypes type();

    @VTID(9)
    void type(
        mol.excel.XlConditionValueTypes rhs);

    @VTID(10)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object value();

    @VTID(11)
    void value(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(12)
    int operator();

    @VTID(13)
    void operator(
        int rhs);

}
