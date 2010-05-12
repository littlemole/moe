package mol.excel  ;

import com4j.*;

@IID("{000208A2-0001-0000-C000-000000000046}")
public interface _IOLEObject extends Com4jObject {
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
    mol.excel.Border border();

    @VTID(46)
    mol.excel.Interior interior();

    @VTID(47)
    boolean shadow();

    @VTID(48)
    void shadow(
        boolean rhs);

    @VTID(49)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object activate();

    @VTID(50)
    boolean autoLoad();

    @VTID(51)
    void autoLoad(
        boolean rhs);

    @VTID(52)
    boolean autoUpdate();

    @VTID(53)
    void autoUpdate(
        boolean rhs);

    @VTID(54)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject object();

    @VTID(55)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object oleType();

    @VTID(56)
    java.lang.String sourceName();

    @VTID(57)
    void sourceName(
        java.lang.String rhs);

    @VTID(58)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object update();

    @VTID(59)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object verb(
        mol.excel.XlOLEVerb verb);

    @VTID(60)
    java.lang.String linkedCell();

    @VTID(61)
    void linkedCell(
        java.lang.String rhs);

    @VTID(62)
    java.lang.String listFillRange();

    @VTID(63)
    void listFillRange(
        java.lang.String rhs);

    @VTID(64)
    java.lang.String progID();

    @VTID(65)
    java.lang.String altHTML();

    @VTID(66)
    void altHTML(
        java.lang.String rhs);

}
