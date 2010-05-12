package mol.excel  ;

import com4j.*;

@IID("{000208A3-0001-0000-C000-000000000046}")
public interface IOLEObjects extends Com4jObject,Iterable<Com4jObject> {
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
    mol.excel.Border border();

    @VTID(45)
    mol.excel.Interior interior();

    @VTID(46)
    boolean shadow();

    @VTID(47)
    void shadow(
        boolean rhs);

    @VTID(48)
    void _Dummy30();

    @VTID(49)
    boolean autoLoad();

    @VTID(50)
    void autoLoad(
        boolean rhs);

    @VTID(51)
    void _Dummy32();

    @VTID(52)
    void _Dummy33();

    @VTID(53)
    void _Dummy34();

    @VTID(54)
    java.lang.String sourceName();

    @VTID(55)
    void sourceName(
        java.lang.String rhs);

    @VTID(56)
    void _Dummy36();

    @VTID(57)
    void _Dummy37();

    @VTID(58)
    void _Dummy38();

    @VTID(59)
    void _Dummy39();

    @VTID(60)
    void _Dummy40();

    @VTID(61)
    void _Dummy41();

    @VTID(62)
    com4j.Com4jObject add(
        @MarshalAs(NativeType.VARIANT) java.lang.Object classType,
        @MarshalAs(NativeType.VARIANT) java.lang.Object filename,
        @MarshalAs(NativeType.VARIANT) java.lang.Object link,
        @MarshalAs(NativeType.VARIANT) java.lang.Object displayAsIcon,
        @MarshalAs(NativeType.VARIANT) java.lang.Object iconFileName,
        @MarshalAs(NativeType.VARIANT) java.lang.Object iconIndex,
        @MarshalAs(NativeType.VARIANT) java.lang.Object iconLabel,
        @MarshalAs(NativeType.VARIANT) java.lang.Object left,
        @MarshalAs(NativeType.VARIANT) java.lang.Object top,
        @MarshalAs(NativeType.VARIANT) java.lang.Object width,
        @MarshalAs(NativeType.VARIANT) java.lang.Object height);

    @VTID(63)
    int count();

    @VTID(64)
    mol.excel.GroupObject group();

    @VTID(65)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(66)
    java.util.Iterator<Com4jObject> iterator();

}