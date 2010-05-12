package mol.excel  ;

import com4j.*;

@IID("{00020899-0001-0000-C000-000000000046}")
public interface IGroupObjects extends Com4jObject,Iterable<Com4jObject> {
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
    void _Dummy27();

    @VTID(45)
    void _Dummy28();

    @VTID(46)
    boolean addIndent();

    @VTID(47)
    void addIndent(
        boolean rhs);

    @VTID(48)
    void _Dummy30();

    @VTID(49)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object arrowHeadLength();

    @VTID(50)
    void arrowHeadLength(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(51)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object arrowHeadStyle();

    @VTID(52)
    void arrowHeadStyle(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(53)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object arrowHeadWidth();

    @VTID(54)
    void arrowHeadWidth(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(55)
    boolean autoSize();

    @VTID(56)
    void autoSize(
        boolean rhs);

    @VTID(57)
    mol.excel.Border border();

    @VTID(58)
    void _Dummy36();

    @VTID(59)
    void _Dummy37();

    @VTID(60)
    void _Dummy38();

    @VTID(61)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object checkSpelling(
        @MarshalAs(NativeType.VARIANT) java.lang.Object customDictionary,
        @MarshalAs(NativeType.VARIANT) java.lang.Object ignoreUppercase,
        @MarshalAs(NativeType.VARIANT) java.lang.Object alwaysSuggest,
        @MarshalAs(NativeType.VARIANT) java.lang.Object spellLang);

    @VTID(62)
    @DefaultMethod
    int _Default();

    @VTID(63)
    @DefaultMethod
    void _Default(
        int rhs);

    @VTID(64)
    void _Dummy41();

    @VTID(65)
    void _Dummy42();

    @VTID(66)
    void _Dummy43();

    @VTID(67)
    void _Dummy44();

    @VTID(68)
    void _Dummy45();

    @VTID(69)
    mol.excel.Font font();

    @VTID(70)
    void _Dummy47();

    @VTID(71)
    void _Dummy48();

    @VTID(72)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object horizontalAlignment();

    @VTID(73)
    void horizontalAlignment(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(74)
    void _Dummy50();

    @VTID(75)
    mol.excel.Interior interior();

    @VTID(76)
    void _Dummy52();

    @VTID(77)
    void _Dummy53();

    @VTID(78)
    void _Dummy54();

    @VTID(79)
    void _Dummy55();

    @VTID(80)
    void _Dummy56();

    @VTID(81)
    void _Dummy57();

    @VTID(82)
    void _Dummy58();

    @VTID(83)
    void _Dummy59();

    @VTID(84)
    void _Dummy60();

    @VTID(85)
    void _Dummy61();

    @VTID(86)
    void _Dummy62();

    @VTID(87)
    void _Dummy63();

    @VTID(88)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object orientation();

    @VTID(89)
    void orientation(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(90)
    void _Dummy65();

    @VTID(91)
    void _Dummy66();

    @VTID(92)
    void _Dummy67();

    @VTID(93)
    void _Dummy68();

    @VTID(94)
    boolean roundedCorners();

    @VTID(95)
    void roundedCorners(
        boolean rhs);

    @VTID(96)
    void _Dummy70();

    @VTID(97)
    boolean shadow();

    @VTID(98)
    void shadow(
        boolean rhs);

    @VTID(99)
    void _Dummy72();

    @VTID(100)
    void _Dummy73();

    @VTID(101)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject ungroup();

    @VTID(102)
    void _Dummy75();

    @VTID(103)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object verticalAlignment();

    @VTID(104)
    void verticalAlignment(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(105)
    void _Dummy77();

    @VTID(106)
    int readingOrder();

    @VTID(107)
    void readingOrder(
        int rhs);

    @VTID(108)
    int count();

    @VTID(109)
    mol.excel.GroupObject group();

    @VTID(110)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(111)
    java.util.Iterator<Com4jObject> iterator();

}
