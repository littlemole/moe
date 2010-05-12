package mol.excel  ;

import com4j.*;

@IID("{0002086F-0001-0000-C000-000000000046}")
public interface IDrawingObjects extends Com4jObject,Iterable<Com4jObject> {
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
    java.lang.Object accelerator();

    @VTID(45)
    void accelerator(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(46)
    void _Dummy28();

    @VTID(47)
    boolean addIndent();

    @VTID(48)
    void addIndent(
        boolean rhs);

    @VTID(49)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object addItem(
        @MarshalAs(NativeType.VARIANT) java.lang.Object text,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

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
    boolean cancelButton();

    @VTID(60)
    void cancelButton(
        boolean rhs);

    @VTID(61)
    java.lang.String caption();

    @VTID(62)
    void caption(
        java.lang.String rhs);

    @VTID(63)
    mol.excel.Characters characters(
        @MarshalAs(NativeType.VARIANT) java.lang.Object start,
        @MarshalAs(NativeType.VARIANT) java.lang.Object length);

    @VTID(64)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object checkSpelling(
        @MarshalAs(NativeType.VARIANT) java.lang.Object customDictionary,
        @MarshalAs(NativeType.VARIANT) java.lang.Object ignoreUppercase,
        @MarshalAs(NativeType.VARIANT) java.lang.Object alwaysSuggest,
        @MarshalAs(NativeType.VARIANT) java.lang.Object spellLang);

    @VTID(65)
    @DefaultMethod
    int _Default();

    @VTID(66)
    @DefaultMethod
    void _Default(
        int rhs);

    @VTID(67)
    boolean defaultButton();

    @VTID(68)
    void defaultButton(
        boolean rhs);

    @VTID(69)
    boolean dismissButton();

    @VTID(70)
    void dismissButton(
        boolean rhs);

    @VTID(71)
    boolean display3DShading();

    @VTID(72)
    void display3DShading(
        boolean rhs);

    @VTID(73)
    boolean displayVerticalScrollBar();

    @VTID(74)
    void displayVerticalScrollBar(
        boolean rhs);

    @VTID(75)
    int dropDownLines();

    @VTID(76)
    void dropDownLines(
        int rhs);

    @VTID(77)
    mol.excel.Font font();

    @VTID(78)
    void _Dummy47();

    @VTID(79)
    boolean helpButton();

    @VTID(80)
    void helpButton(
        boolean rhs);

    @VTID(81)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object horizontalAlignment();

    @VTID(82)
    void horizontalAlignment(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(83)
    int inputType();

    @VTID(84)
    void inputType(
        int rhs);

    @VTID(85)
    mol.excel.Interior interior();

    @VTID(86)
    int largeChange();

    @VTID(87)
    void largeChange(
        int rhs);

    @VTID(88)
    java.lang.String linkedCell();

    @VTID(89)
    void linkedCell(
        java.lang.String rhs);

    @VTID(90)
    void _Dummy54();

    @VTID(91)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object list(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(92)
    void _Dummy56();

    @VTID(93)
    java.lang.String listFillRange();

    @VTID(94)
    void listFillRange(
        java.lang.String rhs);

    @VTID(95)
    int listIndex();

    @VTID(96)
    void listIndex(
        int rhs);

    @VTID(97)
    boolean lockedText();

    @VTID(98)
    void lockedText(
        boolean rhs);

    @VTID(99)
    int max();

    @VTID(100)
    void max(
        int rhs);

    @VTID(101)
    int min();

    @VTID(102)
    void min(
        int rhs);

    @VTID(103)
    boolean multiLine();

    @VTID(104)
    void multiLine(
        boolean rhs);

    @VTID(105)
    boolean multiSelect();

    @VTID(106)
    void multiSelect(
        boolean rhs);

    @VTID(107)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object orientation();

    @VTID(108)
    void orientation(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(109)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object phoneticAccelerator();

    @VTID(110)
    void phoneticAccelerator(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(111)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object removeAllItems();

    @VTID(112)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object removeItem(
        int index,
        @MarshalAs(NativeType.VARIANT) java.lang.Object count);

    @VTID(113)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object reshape(
        int vertex,
        @MarshalAs(NativeType.VARIANT) java.lang.Object insert,
        @MarshalAs(NativeType.VARIANT) java.lang.Object left,
        @MarshalAs(NativeType.VARIANT) java.lang.Object top);

    @VTID(114)
    boolean roundedCorners();

    @VTID(115)
    void roundedCorners(
        boolean rhs);

    @VTID(116)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object selected(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(117)
    boolean shadow();

    @VTID(118)
    void shadow(
        boolean rhs);

    @VTID(119)
    int smallChange();

    @VTID(120)
    void smallChange(
        int rhs);

    @VTID(121)
    java.lang.String text();

    @VTID(122)
    void text(
        java.lang.String rhs);

    @VTID(123)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject ungroup();

    @VTID(124)
    int value();

    @VTID(125)
    void value(
        int rhs);

    @VTID(126)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object verticalAlignment();

    @VTID(127)
    void verticalAlignment(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(128)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object vertices(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index2);

    @VTID(129)
    int readingOrder();

    @VTID(130)
    void readingOrder(
        int rhs);

    @VTID(131)
    int count();

    @VTID(132)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(133)
    mol.excel.GroupObject group();

    @VTID(134)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object linkCombo(
        @MarshalAs(NativeType.VARIANT) java.lang.Object link);

    @VTID(135)
    java.util.Iterator<Com4jObject> iterator();

}
