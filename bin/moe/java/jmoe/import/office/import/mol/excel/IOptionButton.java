package mol.excel  ;

import com4j.*;

@IID("{00020881-0001-0000-C000-000000000046}")
public interface IOptionButton extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.excel.Range bottomRightCell();

    @VTID(11)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object bringToFront();

    @VTID(12)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object copy();

    @VTID(13)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object copyPicture(
        mol.excel.XlPictureAppearance appearance,
        mol.excel.XlCopyPictureFormat format);

    @VTID(14)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object cut();

    @VTID(15)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object delete();

    @VTID(16)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject duplicate();

    @VTID(17)
    boolean enabled();

    @VTID(18)
    void enabled(
        boolean rhs);

    @VTID(19)
    double height();

    @VTID(20)
    void height(
        double rhs);

    @VTID(21)
    int index();

    @VTID(22)
    double left();

    @VTID(23)
    void left(
        double rhs);

    @VTID(24)
    boolean locked();

    @VTID(25)
    void locked(
        boolean rhs);

    @VTID(26)
    java.lang.String name();

    @VTID(27)
    void name(
        java.lang.String rhs);

    @VTID(28)
    java.lang.String onAction();

    @VTID(29)
    void onAction(
        java.lang.String rhs);

    @VTID(30)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object placement();

    @VTID(31)
    void placement(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(32)
    boolean printObject();

    @VTID(33)
    void printObject(
        boolean rhs);

    @VTID(34)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object select(
        @MarshalAs(NativeType.VARIANT) java.lang.Object replace);

    @VTID(35)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object sendToBack();

    @VTID(36)
    double top();

    @VTID(37)
    void top(
        double rhs);

    @VTID(38)
    mol.excel.Range topLeftCell();

    @VTID(39)
    boolean visible();

    @VTID(40)
    void visible(
        boolean rhs);

    @VTID(41)
    double width();

    @VTID(42)
    void width(
        double rhs);

    @VTID(43)
    int zOrder();

    @VTID(44)
    mol.excel.ShapeRange shapeRange();

    @VTID(45)
    java.lang.String caption();

    @VTID(46)
    void caption(
        java.lang.String rhs);

    @VTID(47)
    mol.excel.Characters characters(
        @MarshalAs(NativeType.VARIANT) java.lang.Object start,
        @MarshalAs(NativeType.VARIANT) java.lang.Object length);

    @VTID(48)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object checkSpelling(
        @MarshalAs(NativeType.VARIANT) java.lang.Object customDictionary,
        @MarshalAs(NativeType.VARIANT) java.lang.Object ignoreUppercase,
        @MarshalAs(NativeType.VARIANT) java.lang.Object alwaysSuggest,
        @MarshalAs(NativeType.VARIANT) java.lang.Object spellLang);

    @VTID(49)
    boolean lockedText();

    @VTID(50)
    void lockedText(
        boolean rhs);

    @VTID(51)
    java.lang.String text();

    @VTID(52)
    void text(
        java.lang.String rhs);

    @VTID(53)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object accelerator();

    @VTID(54)
    void accelerator(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(55)
    mol.excel.Border border();

    @VTID(56)
    @DefaultMethod
    int _Default();

    @VTID(57)
    @DefaultMethod
    void _Default(
        int rhs);

    @VTID(58)
    boolean display3DShading();

    @VTID(59)
    void display3DShading(
        boolean rhs);

    @VTID(60)
    mol.excel.Interior interior();

    @VTID(61)
    java.lang.String linkedCell();

    @VTID(62)
    void linkedCell(
        java.lang.String rhs);

    @VTID(63)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object phoneticAccelerator();

    @VTID(64)
    void phoneticAccelerator(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(65)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object value();

    @VTID(66)
    void value(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(67)
    mol.excel.GroupBox groupBox();

}
