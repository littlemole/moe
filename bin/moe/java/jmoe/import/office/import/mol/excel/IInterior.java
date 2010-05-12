package mol.excel  ;

import com4j.*;

@IID("{00020870-0001-0000-C000-000000000046}")
public interface IInterior extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object color();

    @VTID(11)
    void color(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(12)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object colorIndex();

    @VTID(13)
    void colorIndex(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(14)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object invertIfNegative();

    @VTID(15)
    void invertIfNegative(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(16)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object pattern();

    @VTID(17)
    void pattern(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(18)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object patternColor();

    @VTID(19)
    void patternColor(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(20)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object patternColorIndex();

    @VTID(21)
    void patternColorIndex(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(22)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object themeColor();

    @VTID(23)
    void themeColor(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(24)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object tintAndShade();

    @VTID(25)
    void tintAndShade(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(26)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object patternThemeColor();

    @VTID(27)
    void patternThemeColor(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(28)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object patternTintAndShade();

    @VTID(29)
    void patternTintAndShade(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(30)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject gradient();

}
