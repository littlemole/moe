package mol.excel  ;

import com4j.*;

@IID("{00020887-0001-0000-C000-000000000046}")
public interface IListBox extends Com4jObject {
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
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object addItem(
        @MarshalAs(NativeType.VARIANT) java.lang.Object text,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(46)
    boolean display3DShading();

    @VTID(47)
    void display3DShading(
        boolean rhs);

    @VTID(48)
    @DefaultMethod
    int _Default();

    @VTID(49)
    @DefaultMethod
    void _Default(
        int rhs);

    @VTID(50)
    java.lang.String linkedCell();

    @VTID(51)
    void linkedCell(
        java.lang.String rhs);

    @VTID(52)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object linkedObject();

    @VTID(53)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object list(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(54)
    void list(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(55)
    int listCount();

    @VTID(56)
    java.lang.String listFillRange();

    @VTID(57)
    void listFillRange(
        java.lang.String rhs);

    @VTID(58)
    int listIndex();

    @VTID(59)
    void listIndex(
        int rhs);

    @VTID(60)
    int multiSelect();

    @VTID(61)
    void multiSelect(
        int rhs);

    @VTID(62)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object removeAllItems();

    @VTID(63)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object removeItem(
        int index,
        @MarshalAs(NativeType.VARIANT) java.lang.Object count);

    @VTID(64)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object selected(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(65)
    void selected(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(66)
    int value();

    @VTID(67)
    void value(
        int rhs);

}
