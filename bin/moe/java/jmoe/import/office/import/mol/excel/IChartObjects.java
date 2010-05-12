package mol.excel  ;

import com4j.*;

@IID("{000208D0-0001-0000-C000-000000000046}")
public interface IChartObjects extends Com4jObject,Iterable<Com4jObject> {
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
    java.lang.Object _Copy();

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
    void _Dummy25();

    @VTID(43)
    mol.excel.ShapeRange shapeRange();

    @VTID(44)
    void _Dummy27();

    @VTID(45)
    void _Dummy28();

    @VTID(46)
    boolean protectChartObject();

    @VTID(47)
    void protectChartObject(
        boolean rhs);

    @VTID(48)
    boolean roundedCorners();

    @VTID(49)
    void roundedCorners(
        boolean rhs);

    @VTID(50)
    mol.excel.Border border();

    @VTID(51)
    mol.excel.Interior interior();

    @VTID(52)
    boolean shadow();

    @VTID(53)
    void shadow(
        boolean rhs);

    @VTID(54)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object copy();

    @VTID(55)
    mol.excel.ChartObject add(
        double left,
        double top,
        double width,
        double height);

    @VTID(56)
    int count();

    @VTID(57)
    mol.excel.GroupObject group();

    @VTID(58)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(59)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(60)
    @DefaultMethod
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

}
