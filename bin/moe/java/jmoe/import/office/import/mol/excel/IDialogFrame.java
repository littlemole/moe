package mol.excel  ;

import com4j.*;

@IID("{0002088F-0001-0000-C000-000000000046}")
public interface IDialogFrame extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    void _Dummy3();

    @VTID(11)
    void _Dummy4();

    @VTID(12)
    void _Dummy5();

    @VTID(13)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object copyPicture(
        mol.excel.XlPictureAppearance appearance,
        mol.excel.XlCopyPictureFormat format);

    @VTID(14)
    void _Dummy7();

    @VTID(15)
    void _Dummy8();

    @VTID(16)
    void _Dummy9();

    @VTID(17)
    void _Dummy10();

    @VTID(18)
    double height();

    @VTID(19)
    void height(
        double rhs);

    @VTID(20)
    void _Dummy12();

    @VTID(21)
    double left();

    @VTID(22)
    void left(
        double rhs);

    @VTID(23)
    boolean locked();

    @VTID(24)
    void locked(
        boolean rhs);

    @VTID(25)
    java.lang.String name();

    @VTID(26)
    void name(
        java.lang.String rhs);

    @VTID(27)
    java.lang.String onAction();

    @VTID(28)
    void onAction(
        java.lang.String rhs);

    @VTID(29)
    void _Dummy17();

    @VTID(30)
    void _Dummy18();

    @VTID(31)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object select(
        @MarshalAs(NativeType.VARIANT) java.lang.Object replace);

    @VTID(32)
    void _Dummy20();

    @VTID(33)
    double top();

    @VTID(34)
    void top(
        double rhs);

    @VTID(35)
    void _Dummy22();

    @VTID(36)
    void _Dummy23();

    @VTID(37)
    double width();

    @VTID(38)
    void width(
        double rhs);

    @VTID(39)
    void _Dummy25();

    @VTID(40)
    mol.excel.ShapeRange shapeRange();

    @VTID(41)
    java.lang.String caption();

    @VTID(42)
    void caption(
        java.lang.String rhs);

    @VTID(43)
    mol.excel.Characters characters(
        @MarshalAs(NativeType.VARIANT) java.lang.Object start,
        @MarshalAs(NativeType.VARIANT) java.lang.Object length);

    @VTID(44)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object checkSpelling(
        @MarshalAs(NativeType.VARIANT) java.lang.Object customDictionary,
        @MarshalAs(NativeType.VARIANT) java.lang.Object ignoreUppercase,
        @MarshalAs(NativeType.VARIANT) java.lang.Object alwaysSuggest,
        @MarshalAs(NativeType.VARIANT) java.lang.Object spellLang);

    @VTID(45)
    boolean lockedText();

    @VTID(46)
    void lockedText(
        boolean rhs);

    @VTID(47)
    java.lang.String text();

    @VTID(48)
    void text(
        java.lang.String rhs);

}
