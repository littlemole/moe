package mol.excel  ;

import com4j.*;

@IID("{0002084D-0001-0000-C000-000000000046}")
public interface IFont extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object background();

    @VTID(11)
    void background(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(12)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object bold();

    @VTID(13)
    void bold(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(14)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object color();

    @VTID(15)
    void color(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(16)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object colorIndex();

    @VTID(17)
    void colorIndex(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(18)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object fontStyle();

    @VTID(19)
    void fontStyle(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(20)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object italic();

    @VTID(21)
    void italic(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(22)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object name();

    @VTID(23)
    void name(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(24)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object outlineFont();

    @VTID(25)
    void outlineFont(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(26)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object shadow();

    @VTID(27)
    void shadow(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(28)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object size();

    @VTID(29)
    void size(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(30)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object strikethrough();

    @VTID(31)
    void strikethrough(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(32)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object subscript();

    @VTID(33)
    void subscript(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(34)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object superscript();

    @VTID(35)
    void superscript(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(36)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object underline();

    @VTID(37)
    void underline(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(38)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object themeColor();

    @VTID(39)
    void themeColor(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(40)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object tintAndShade();

    @VTID(41)
    void tintAndShade(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(42)
    mol.excel.XlThemeFont themeFont();

    @VTID(43)
    void themeFont(
        mol.excel.XlThemeFont rhs);

}
