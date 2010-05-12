package mol.excel  ;

import com4j.*;

@IID("{000208A1-0001-0000-C000-000000000046}")
public interface IArcs extends Com4jObject,Iterable<Com4jObject> {
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
    void _Dummy12();

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
    void _Dummy15();

    @VTID(27)
    java.lang.String onAction();

    @VTID(28)
    void onAction(
        java.lang.String rhs);

    @VTID(29)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object placement();

    @VTID(30)
    void placement(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(31)
    boolean printObject();

    @VTID(32)
    void printObject(
        boolean rhs);

    @VTID(33)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object select(
        @MarshalAs(NativeType.VARIANT) java.lang.Object replace);

    @VTID(34)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object sendToBack();

    @VTID(35)
    double top();

    @VTID(36)
    void top(
        double rhs);

    @VTID(37)
    void _Dummy22();

    @VTID(38)
    boolean visible();

    @VTID(39)
    void visible(
        boolean rhs);

    @VTID(40)
    double width();

    @VTID(41)
    void width(
        double rhs);

    @VTID(42)
    int zOrder();

    @VTID(43)
    mol.excel.ShapeRange shapeRange();

    @VTID(44)
    boolean addIndent();

    @VTID(45)
    void addIndent(
        boolean rhs);

    @VTID(46)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object autoScaleFont();

    @VTID(47)
    void autoScaleFont(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(48)
    boolean autoSize();

    @VTID(49)
    void autoSize(
        boolean rhs);

    @VTID(50)
    java.lang.String caption();

    @VTID(51)
    void caption(
        java.lang.String rhs);

    @VTID(52)
    mol.excel.Characters characters(
        @MarshalAs(NativeType.VARIANT) java.lang.Object start,
        @MarshalAs(NativeType.VARIANT) java.lang.Object length);

    @VTID(53)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object checkSpelling(
        @MarshalAs(NativeType.VARIANT) java.lang.Object customDictionary,
        @MarshalAs(NativeType.VARIANT) java.lang.Object ignoreUppercase,
        @MarshalAs(NativeType.VARIANT) java.lang.Object alwaysSuggest,
        @MarshalAs(NativeType.VARIANT) java.lang.Object spellLang);

    @VTID(54)
    mol.excel.Font font();

    @VTID(55)
    java.lang.String formula();

    @VTID(56)
    void formula(
        java.lang.String rhs);

    @VTID(57)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object horizontalAlignment();

    @VTID(58)
    void horizontalAlignment(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(59)
    boolean lockedText();

    @VTID(60)
    void lockedText(
        boolean rhs);

    @VTID(61)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object orientation();

    @VTID(62)
    void orientation(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(63)
    java.lang.String text();

    @VTID(64)
    void text(
        java.lang.String rhs);

    @VTID(65)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object verticalAlignment();

    @VTID(66)
    void verticalAlignment(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(67)
    int readingOrder();

    @VTID(68)
    void readingOrder(
        int rhs);

    @VTID(69)
    mol.excel.Border border();

    @VTID(70)
    mol.excel.Interior interior();

    @VTID(71)
    void _Dummy43();

    @VTID(72)
    mol.excel.Arc add(
        double x1,
        double y1,
        double x2,
        double y2);

    @VTID(73)
    int count();

    @VTID(74)
    mol.excel.GroupObject group();

    @VTID(75)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(76)
    java.util.Iterator<Com4jObject> iterator();

}
