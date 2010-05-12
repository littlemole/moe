package mol.excel  ;

import com4j.*;

@IID("{00020898-0001-0000-C000-000000000046}")
public interface IGroupObject extends Com4jObject {
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
    void _Dummy27();

    @VTID(46)
    void _Dummy28();

    @VTID(47)
    boolean addIndent();

    @VTID(48)
    void addIndent(
        boolean rhs);

    @VTID(49)
    void _Dummy30();

    @VTID(50)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object arrowHeadLength();

    @VTID(51)
    void arrowHeadLength(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(52)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object arrowHeadStyle();

    @VTID(53)
    void arrowHeadStyle(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(54)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object arrowHeadWidth();

    @VTID(55)
    void arrowHeadWidth(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(56)
    boolean autoSize();

    @VTID(57)
    void autoSize(
        boolean rhs);

    @VTID(58)
    mol.excel.Border border();

    @VTID(59)
    void _Dummy36();

    @VTID(60)
    void _Dummy37();

    @VTID(61)
    void _Dummy38();

    @VTID(62)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object checkSpelling(
        @MarshalAs(NativeType.VARIANT) java.lang.Object customDictionary,
        @MarshalAs(NativeType.VARIANT) java.lang.Object ignoreUppercase,
        @MarshalAs(NativeType.VARIANT) java.lang.Object alwaysSuggest,
        @MarshalAs(NativeType.VARIANT) java.lang.Object spellLang);

    @VTID(63)
    @DefaultMethod
    int _Default();

    @VTID(64)
    @DefaultMethod
    void _Default(
        int rhs);

    @VTID(65)
    void _Dummy41();

    @VTID(66)
    void _Dummy42();

    @VTID(67)
    void _Dummy43();

    @VTID(68)
    void _Dummy44();

    @VTID(69)
    void _Dummy45();

    @VTID(70)
    mol.excel.Font font();

    @VTID(71)
    void _Dummy47();

    @VTID(72)
    void _Dummy48();

    @VTID(73)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object horizontalAlignment();

    @VTID(74)
    void horizontalAlignment(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(75)
    void _Dummy50();

    @VTID(76)
    mol.excel.Interior interior();

    @VTID(77)
    void _Dummy52();

    @VTID(78)
    void _Dummy53();

    @VTID(79)
    void _Dummy54();

    @VTID(80)
    void _Dummy55();

    @VTID(81)
    void _Dummy56();

    @VTID(82)
    void _Dummy57();

    @VTID(83)
    void _Dummy58();

    @VTID(84)
    void _Dummy59();

    @VTID(85)
    void _Dummy60();

    @VTID(86)
    void _Dummy61();

    @VTID(87)
    void _Dummy62();

    @VTID(88)
    void _Dummy63();

    @VTID(89)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object orientation();

    @VTID(90)
    void orientation(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(91)
    void _Dummy65();

    @VTID(92)
    void _Dummy66();

    @VTID(93)
    void _Dummy67();

    @VTID(94)
    void _Dummy68();

    @VTID(95)
    boolean roundedCorners();

    @VTID(96)
    void roundedCorners(
        boolean rhs);

    @VTID(97)
    void _Dummy70();

    @VTID(98)
    boolean shadow();

    @VTID(99)
    void shadow(
        boolean rhs);

    @VTID(100)
    void _Dummy72();

    @VTID(101)
    void _Dummy73();

    @VTID(102)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject ungroup();

    @VTID(103)
    void _Dummy75();

    @VTID(104)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object verticalAlignment();

    @VTID(105)
    void verticalAlignment(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(106)
    void _Dummy77();

    @VTID(107)
    int readingOrder();

    @VTID(108)
    void readingOrder(
        int rhs);

}
