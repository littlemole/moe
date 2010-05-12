package mol.excel  ;

import com4j.*;

@IID("{00020888-0001-0000-C000-000000000046}")
public interface IListBoxes extends Com4jObject,Iterable<Com4jObject> {
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
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object addItem(
        @MarshalAs(NativeType.VARIANT) java.lang.Object text,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(45)
    boolean display3DShading();

    @VTID(46)
    void display3DShading(
        boolean rhs);

    @VTID(47)
    @DefaultMethod
    int _Default();

    @VTID(48)
    @DefaultMethod
    void _Default(
        int rhs);

    @VTID(49)
    java.lang.String linkedCell();

    @VTID(50)
    void linkedCell(
        java.lang.String rhs);

    @VTID(51)
    void _Dummy31();

    @VTID(52)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object list(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(53)
    void list(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(54)
    void _Dummy33();

    @VTID(55)
    java.lang.String listFillRange();

    @VTID(56)
    void listFillRange(
        java.lang.String rhs);

    @VTID(57)
    int listIndex();

    @VTID(58)
    void listIndex(
        int rhs);

    @VTID(59)
    int multiSelect();

    @VTID(60)
    void multiSelect(
        int rhs);

    @VTID(61)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object removeAllItems();

    @VTID(62)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object removeItem(
        int index,
        @MarshalAs(NativeType.VARIANT) java.lang.Object count);

    @VTID(63)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object selected(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(64)
    void selected(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(65)
    int value();

    @VTID(66)
    void value(
        int rhs);

    @VTID(67)
    mol.excel.ListBox add(
        double left,
        double top,
        double width,
        double height);

    @VTID(68)
    int count();

    @VTID(69)
    mol.excel.GroupObject group();

    @VTID(70)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(71)
    java.util.Iterator<Com4jObject> iterator();

}