package mol.excel  ;

import com4j.*;

@IID("{00020884-0001-0000-C000-000000000046}")
public interface IEditBoxes extends Com4jObject,Iterable<Com4jObject> {
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
    java.lang.String caption();

    @VTID(45)
    void caption(
        java.lang.String rhs);

    @VTID(46)
    mol.excel.Characters characters(
        @MarshalAs(NativeType.VARIANT) java.lang.Object start,
        @MarshalAs(NativeType.VARIANT) java.lang.Object length);

    @VTID(47)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object checkSpelling(
        @MarshalAs(NativeType.VARIANT) java.lang.Object customDictionary,
        @MarshalAs(NativeType.VARIANT) java.lang.Object ignoreUppercase,
        @MarshalAs(NativeType.VARIANT) java.lang.Object alwaysSuggest,
        @MarshalAs(NativeType.VARIANT) java.lang.Object spellLang);

    @VTID(48)
    boolean lockedText();

    @VTID(49)
    void lockedText(
        boolean rhs);

    @VTID(50)
    java.lang.String text();

    @VTID(51)
    void text(
        java.lang.String rhs);

    @VTID(52)
    boolean displayVerticalScrollBar();

    @VTID(53)
    void displayVerticalScrollBar(
        boolean rhs);

    @VTID(54)
    int inputType();

    @VTID(55)
    void inputType(
        int rhs);

    @VTID(56)
    void _Dummy34();

    @VTID(57)
    boolean multiLine();

    @VTID(58)
    void multiLine(
        boolean rhs);

    @VTID(59)
    boolean passwordEdit();

    @VTID(60)
    void passwordEdit(
        boolean rhs);

    @VTID(61)
    mol.excel.EditBox add(
        double left,
        double top,
        double width,
        double height);

    @VTID(62)
    int count();

    @VTID(63)
    mol.excel.GroupObject group();

    @VTID(64)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(65)
    java.util.Iterator<Com4jObject> iterator();

}
