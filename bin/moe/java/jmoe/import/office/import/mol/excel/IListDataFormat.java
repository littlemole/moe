package mol.excel  ;

import com4j.*;

@IID("{0002447D-0001-0000-C000-000000000046}")
public interface IListDataFormat extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @DefaultMethod
    mol.excel.XlListDataType _Default();

    @VTID(11)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object choices();

    @VTID(12)
    int decimalPlaces();

    @VTID(13)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object defaultValue();

    @VTID(14)
    boolean isPercent();

    @VTID(15)
    int lcid();

    @VTID(16)
    int maxCharacters();

    @VTID(17)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object maxNumber();

    @VTID(18)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object minNumber();

    @VTID(19)
    boolean required();

    @VTID(20)
    mol.excel.XlListDataType type();

    @VTID(21)
    boolean readOnly();

    @VTID(22)
    boolean allowFillIn();

}
