package mol.excel  ;

import com4j.*;

@IID("{0002442F-0001-0000-C000-000000000046}")
public interface IValidation extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    void add(
        mol.excel.XlDVType type,
        @MarshalAs(NativeType.VARIANT) java.lang.Object alertStyle,
        @MarshalAs(NativeType.VARIANT) java.lang.Object operator,
        @MarshalAs(NativeType.VARIANT) java.lang.Object formula1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object formula2);

    @VTID(11)
    int alertStyle();

    @VTID(12)
    boolean ignoreBlank();

    @VTID(13)
    void ignoreBlank(
        boolean rhs);

    @VTID(14)
    int imeMode();

    @VTID(15)
    void imeMode(
        int rhs);

    @VTID(16)
    boolean inCellDropdown();

    @VTID(17)
    void inCellDropdown(
        boolean rhs);

    @VTID(18)
    void delete();

    @VTID(19)
    java.lang.String errorMessage();

    @VTID(20)
    void errorMessage(
        java.lang.String rhs);

    @VTID(21)
    java.lang.String errorTitle();

    @VTID(22)
    void errorTitle(
        java.lang.String rhs);

    @VTID(23)
    java.lang.String inputMessage();

    @VTID(24)
    void inputMessage(
        java.lang.String rhs);

    @VTID(25)
    java.lang.String inputTitle();

    @VTID(26)
    void inputTitle(
        java.lang.String rhs);

    @VTID(27)
    java.lang.String formula1();

    @VTID(28)
    java.lang.String formula2();

    @VTID(29)
    void modify(
        @MarshalAs(NativeType.VARIANT) java.lang.Object type,
        @MarshalAs(NativeType.VARIANT) java.lang.Object alertStyle,
        @MarshalAs(NativeType.VARIANT) java.lang.Object operator,
        @MarshalAs(NativeType.VARIANT) java.lang.Object formula1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object formula2);

    @VTID(30)
    int operator();

    @VTID(31)
    boolean showError();

    @VTID(32)
    void showError(
        boolean rhs);

    @VTID(33)
    boolean showInput();

    @VTID(34)
    void showInput(
        boolean rhs);

    @VTID(35)
    int type();

    @VTID(36)
    boolean value();

}
