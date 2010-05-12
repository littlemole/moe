package mol.excel  ;

import com4j.*;

@IID("{00024495-0001-0000-C000-000000000046}")
public interface IColorScaleCriterion extends Com4jObject {
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
    mol.excel.FormatColor formatColor();

}
