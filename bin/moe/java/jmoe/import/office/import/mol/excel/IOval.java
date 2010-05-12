package mol.excel  ;

import com4j.*;

@IID("{0002089E-0001-0000-C000-000000000046}")
public interface IOval extends Com4jObject {
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
    boolean addIndent();

    @VTID(46)
    void addIndent(
        boolean rhs);

    @VTID(47)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object autoScaleFont();

    @VTID(48)
    void autoScaleFont(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(49)
    boolean autoSize();

    @VTID(50)
    void autoSize(
        boolean rhs);

    @VTID(51)
    java.lang.String caption();

    @VTID(52)
    void caption(
        java.lang.String rhs);

    @VTID(53)
    mol.excel.Characters characters(
        @MarshalAs(NativeType.VARIANT) java.lang.Object start,
        @MarshalAs(NativeType.VARIANT) java.lang.Object length);

    @VTID(54)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object checkSpelling(
        @MarshalAs(NativeType.VARIANT) java.lang.Object customDictionary,
        @MarshalAs(NativeType.VARIANT) java.lang.Object ignoreUppercase,
        @MarshalAs(NativeType.VARIANT) java.lang.Object alwaysSuggest,
        @MarshalAs(NativeType.VARIANT) java.lang.Object spellLang);

    @VTID(55)
    mol.excel.Font font();

    @VTID(56)
    java.lang.String formula();

    @VTID(57)
    void formula(
        java.lang.String rhs);

    @VTID(58)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object horizontalAlignment();

    @VTID(59)
    void horizontalAlignment(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(60)
    boolean lockedText();

    @VTID(61)
    void lockedText(
        boolean rhs);

    @VTID(62)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object orientation();

    @VTID(63)
    void orientation(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(64)
    java.lang.String text();

    @VTID(65)
    void text(
        java.lang.String rhs);

    @VTID(66)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object verticalAlignment();

    @VTID(67)
    void verticalAlignment(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(68)
    int readingOrder();

    @VTID(69)
    void readingOrder(
        int rhs);

    @VTID(70)
    mol.excel.Border border();

    @VTID(71)
    mol.excel.Interior interior();

    @VTID(72)
    boolean shadow();

    @VTID(73)
    void shadow(
        boolean rhs);

}
