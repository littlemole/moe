package mol.excel  ;

import com4j.*;

@IID("{000208B3-0001-0000-C000-000000000046}")
public interface IDataLabels extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.lang.String name();

    @VTID(11)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object select();

    @VTID(12)
    mol.excel.Border border();

    @VTID(13)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object delete();

    @VTID(14)
    mol.excel.Interior interior();

    @VTID(15)
    mol.excel.ChartFillFormat fill();

    @VTID(16)
    void _Dummy9();

    @VTID(17)
    void _Dummy10();

    @VTID(18)
    mol.excel.Font font();

    @VTID(19)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object horizontalAlignment();

    @VTID(20)
    void horizontalAlignment(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(21)
    void _Dummy13();

    @VTID(22)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object orientation();

    @VTID(23)
    void orientation(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(24)
    boolean shadow();

    @VTID(25)
    void shadow(
        boolean rhs);

    @VTID(26)
    void _Dummy16();

    @VTID(27)
    void _Dummy17();

    @VTID(28)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object verticalAlignment();

    @VTID(29)
    void verticalAlignment(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(30)
    int readingOrder();

    @VTID(31)
    void readingOrder(
        int rhs);

    @VTID(32)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object autoScaleFont();

    @VTID(33)
    void autoScaleFont(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(34)
    boolean autoText();

    @VTID(35)
    void autoText(
        boolean rhs);

    @VTID(36)
    java.lang.String numberFormat();

    @VTID(37)
    void numberFormat(
        java.lang.String rhs);

    @VTID(38)
    boolean numberFormatLinked();

    @VTID(39)
    void numberFormatLinked(
        boolean rhs);

    @VTID(40)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object numberFormatLocal();

    @VTID(41)
    void numberFormatLocal(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(42)
    boolean showLegendKey();

    @VTID(43)
    void showLegendKey(
        boolean rhs);

    @VTID(44)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object type();

    @VTID(45)
    void type(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(46)
    mol.excel.XlDataLabelPosition position();

    @VTID(47)
    void position(
        mol.excel.XlDataLabelPosition rhs);

    @VTID(48)
    boolean showSeriesName();

    @VTID(49)
    void showSeriesName(
        boolean rhs);

    @VTID(50)
    boolean showCategoryName();

    @VTID(51)
    void showCategoryName(
        boolean rhs);

    @VTID(52)
    boolean showValue();

    @VTID(53)
    void showValue(
        boolean rhs);

    @VTID(54)
    boolean showPercentage();

    @VTID(55)
    void showPercentage(
        boolean rhs);

    @VTID(56)
    boolean showBubbleSize();

    @VTID(57)
    void showBubbleSize(
        boolean rhs);

    @VTID(58)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object separator();

    @VTID(59)
    void separator(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(60)
    int count();

    @VTID(61)
    mol.excel.DataLabel item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(62)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(63)
    @DefaultMethod
    mol.excel.DataLabel _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(64)
    mol.excel.ChartFormat format();

}
