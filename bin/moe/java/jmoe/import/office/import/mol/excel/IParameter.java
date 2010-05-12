package mol.excel  ;

import com4j.*;

@IID("{0002442A-0001-0000-C000-000000000046}")
public interface IParameter extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.excel.XlParameterDataType dataType();

    @VTID(11)
    void dataType(
        mol.excel.XlParameterDataType rhs);

    @VTID(12)
    mol.excel.XlParameterType type();

    @VTID(13)
    java.lang.String promptString();

    @VTID(14)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object value();

    @VTID(15)
    mol.excel.Range sourceRange();

    @VTID(16)
    java.lang.String name();

    @VTID(17)
    void name(
        java.lang.String rhs);

    @VTID(18)
    void setParam(
        mol.excel.XlParameterType type,
        @MarshalAs(NativeType.VARIANT) java.lang.Object value);

    @VTID(19)
    boolean refreshOnChange();

    @VTID(20)
    void refreshOnChange(
        boolean rhs);

}
